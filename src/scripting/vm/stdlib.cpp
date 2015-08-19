#include "scripting/vm/stdlib.h"

#include "scripting/vm/types.h"
#include "scripting/vm/engine.h"
#include "scripting/vm/context.h"
#include <cassert>

//TODO: Test
namespace scripting
{
struct ExceptionData
{
    ExcType type;
    String error;
};

Ref exceptionCopy(Context *ctx, NativeObject *self);
void exceptionDestroy(Context *ctx, NativeObject *self);
Ref exceptionGetMember(Context *ctx, NativeObject *self, Value *key);
void exceptionSetMember(Context *ctx, NativeObject *self, Value *key, Value *value);

static const NativeObjectFuncs exceptionFuncs =
{.copy = exceptionCopy,
 .destroy = exceptionDestroy,
 .getMember = exceptionGetMember,
 .setMember = exceptionSetMember};

struct StdlibExtension
{
    NativeObject *exceptionClass;
};

StdlibExtension *getStdlib(Engine *engine)
{
    return (StdlibExtension *)engine->getExtension("__stdlib").data;
}

Ref newException(Context *ctx, const List<Ref>& args)
{
    if (args.getCount() == 3)
    {
        ctx->throwException(createException(ctx, ExcType::ValueError, "Exception.__new__ accepts 3 arguments."));
    }

    RefManager *refMgr = ctx->getEngine()->getRefMgr();

    Value *selfHead = refMgr->translate(args[0]);

    if (not isInstance(ctx, (Value *)selfHead, (Value *)getStdlib(ctx->getEngine())->exceptionClass))
    {
        ctx->throwException(createException(ctx, ExcType::TypeError, "First argument of Exception.__new__ must be an Exception."));
    }

    Value *type = refMgr->translate(args[1]);

    if (type->type != ValueType::String)
    {
        ctx->throwException(createException(ctx, ExcType::TypeError, "Exception type must be a string."));
    }

    String typeStr = ((StringValue *)type)->value;

    Value *error = refMgr->translate(args[2]);

    if (error->type != ValueType::String)
    {
        ctx->throwException(createException(ctx, ExcType::TypeError, "Exception error must be a string."));
    }

    String errorStr = ((StringValue *)error)->value;

    ExcType typeEnum;

    if (typeStr == "value")
    {
        typeEnum = ExcType::ValueError;
    } else if (typeStr == "type")
    {
        typeEnum = ExcType::TypeError;
    } else if (typeStr == "key")
    {
        typeEnum = ExcType::KeyError;
    } else if (typeStr == "index")
    {
        typeEnum = ExcType::IndexError;
    } else
    {
        ctx->throwException(createException(ctx, ExcType::ValueError, "Exception type is invalid."));
    }

    return createException(ctx, typeEnum, errorStr);
}

Ref exceptionCopy(Context *ctx, NativeObject *self)
{
    ExceptionData *data = (ExceptionData *)self->data;

    if (data == NULL)
    {
        return ctx->getEngine()->getRefMgr()->createNativeObject(exceptionFuncs, NULL, self->typeID);
    } else
    {
        ExceptionData *newData = NEW(ExceptionData);
        *newData = *data;

        return ctx->getEngine()->getRefMgr()->createNativeObject(exceptionFuncs, newData, self->typeID);
    }
}

void exceptionDestroy(Context *ctx, NativeObject *self)
{
    DELETE(ExceptionData, self->data);
}

Ref exceptionGetMember(Context *ctx, NativeObject *self, Value *key)
{
    RefManager *refMgr = ctx->getEngine()->getRefMgr();

    ExceptionData *data = (ExceptionData *)self->data;

    if (key->type != ValueType::String)
    {
        ctx->throwException(createException(ctx, ExcType::TypeError, "Member type must be string."));

        assert(false);
    }

    String keyStr = ((StringValue *)key)->value;

    if (keyStr == "__name__")
    {
        return refMgr->createString("Exception");
    } else if (keyStr == "__new__")
    {
        return refMgr->createNativeFunction(newException);
    } else if (keyStr == "__typeID__")
    {
        return refMgr->createInt(self->typeID);
    } else if (self->data != NULL) //NULL if it is a uninstanced Exception.
    {
        if (keyStr == "__class__")
        {
            return refMgr->createCopy(ctx, (Value *)getStdlib(ctx->getEngine())->exceptionClass);
        } else if (keyStr == "type")
        {
            switch (data->type)
            {
            case ExcType::ValueError:
            {
                return refMgr->createString("value");
            }
            case ExcType::TypeError:
            {
                return refMgr->createString("type");
            }
            case ExcType::KeyError:
            {
                return refMgr->createString("key");
            }
            case ExcType::IndexError:
            {
                return refMgr->createString("index");
            }
            }
        } else if (keyStr == "error")
        {
            return refMgr->createString(data->error);
        }
    }

    ctx->throwException(createException(ctx, ExcType::KeyError, "Unknown member."));

    assert(false);
}

void exceptionSetMember(Context *ctx, NativeObject *self, Value *key, Value *value)
{
    ctx->throwException(createException(ctx, ExcType::KeyError, "Exceptions are immutable."));

    assert(false);
}

Ref createException(Context *ctx, ExcType type, const String& error)
{
    RefManager *refMgr = ctx->getEngine()->getRefMgr();

    ExceptionData *excData = NEW(ExceptionData);

    excData->type = type;
    excData->error = error;

    return refMgr->createNativeObject(exceptionFuncs, excData, getStdlib(ctx->getEngine())->exceptionClass->typeID);
}

void stdLibDestroy(Engine *engine, NativeObject *self)
{
    Context *context = NEW(Context, engine);

    engine->getRefMgr()->destroy(context, getStdlib(engine)->exceptionClass->head.ref);

    DELETE(Context, context);
}

Ref scriptIsInstance(Context *ctx, const List<Ref>& args)
{
    if (args.getCount() != 2)
    {
        ctx->throwException(createException(ctx, ExcType::ValueError, "isInstance takes 2 arguments."));
    }

    RefManager *refMgr = ctx->getEngine()->getRefMgr();

    return refMgr->createBoolean(isInstance(ctx, refMgr->translate(args[0]), refMgr->translate(args[1])));
}

Ref createTypeID(Context *ctx, const List<Ref>& args)
{
    if (args.getCount() != 0)
    {
        ctx->throwException(createException(ctx, ExcType::ValueError, "createTypeID takes 0 arguments."));
    }

    return ctx->getEngine()->getRefMgr()->createInt(ctx->getEngine()->createNewTypeID());
}

Ref classNew(Context *ctx, const List<Ref>& args)
{
    RefManager *refMgr = ctx->getEngine()->getRefMgr();

    if (args.getCount() < 1)
    {
        ctx->throwException(createException(ctx, ExcType::ValueError, "__new__ takes at least 1 argument."));
    }

    Value *class_ = refMgr->translate(args[1]);

    Ref __base__ = refMgr->createString("__base__");
    Value *base = refMgr->translate(getMember(ctx, class_, refMgr->translate(__base__)));
    refMgr->destroy(ctx, __base__);

    Ref __typeID__ = refMgr->createString("__typeID__");
    Value *typeID = refMgr->translate(getMember(ctx, class_, refMgr->translate(__typeID__)));
    refMgr->destroy(ctx, __typeID__);

    if (base->type != ValueType::Object)
    {
        ctx->throwException(createException(ctx, ExcType::TypeError, "Class base must be an object."));
    }

    if (typeID->type != ValueType::Int)
    {
        ctx->throwException(createException(ctx, ExcType::TypeError, "Class tyoe ID must be an integer."));
    }

    Ref result = refMgr->createObject();
    Value *resultHead = refMgr->translate(result);
    HashMap<String, Ref> resultMembers = ((ObjectValue *)resultHead)->members;

    resultMembers.append(((ObjectValue *)base)->members);
    resultMembers.set("__typeID__", refMgr->createInt(((IntValue *)typeID)->value));

    int entry = resultMembers.findEntry("__init__");

    if (entry != -1)
    {
        callMethod(ctx, resultHead, "__init__", List<Ref>(args.getCount(), args.getData()+1));
    } else
    {
        if (args.getCount() != 1)
        {
            ctx->throwException(createException(ctx, ExcType::ValueError, "__new__ takes 1 argument."));
        }
    }

    return result;
}

Ref createClass(Context *ctx, const List<Ref>& args)
{
    if (args.getCount() != 1)
    {
        ctx->throwException(createException(ctx, ExcType::ValueError, "createClass takes 1 arguments."));
    }

    RefManager *refMgr = ctx->getEngine()->getRefMgr();

    Value *base = refMgr->translate(args[1]);

    if (base->type != ValueType::Object)
    {
        ctx->throwException(createException(ctx, ExcType::ValueError, "base must be an object."));
    }

    Ref result = refMgr->createObject();

    HashMap<String, Ref> resultMembers = ((ObjectValue *)refMgr->translate(result))->members;

    resultMembers.set("__base__", args[1]);
    resultMembers.set("__new__", refMgr->createNativeFunction(classNew));
    resultMembers.set("__typeID__", refMgr->createInt(ctx->getEngine()->createNewTypeID()));
    resultMembers.set("__call__", refMgr->createNativeFunction(classNew));

    return result;
}

void *initStdlib(Engine *engine, void *data)
{
    RefManager *refMgr = engine->getRefMgr();

    StdlibExtension *ext = NEW(StdlibExtension);

    Ref exc = refMgr->createNativeObject(exceptionFuncs, NULL, engine->createNewTypeID());
    ext->exceptionClass = (NativeObject *)refMgr->translate(exc);

    Ref stdlib = refMgr->createObject();
    HashMap<String, Ref> values = ((ObjectValue *)refMgr->translate(stdlib))->members;

    values.set("Exception", exc);
    //TODO: This can be implemented as function isInstance(a, b) {return a.__typeID__ == b.__typeID__}
    values.set("isInstance", refMgr->createNativeFunction(scriptIsInstance));
    values.set("createTypeID", refMgr->createNativeFunction(createTypeID));
    values.set("createClass", refMgr->createNativeFunction(createClass));

    engine->getGlobalVars().set("std", stdlib);

    return ext;
}

void deinitStdlib(Engine *engine, void *data)
{
    DELETE(StdlibExtension, data);
}

void registerStdlib(Engine *engine)
{
    Extension ext;

    ext.init = initStdlib;
    ext.deinit = deinitStdlib;

    engine->addExtension("__stdlib", ext);
}
}

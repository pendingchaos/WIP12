#include "scripting/vm/stdlib.h"

#include "scripting/vm/types.h"
#include "scripting/vm/engine.h"
#include "scripting/vm/context.h"
#include <cassert>

//TODO: Use the builtin exception type.
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

void *initStdlib(Engine *engine, void *data)
{
    RefManager *refMgr = engine->getRefMgr();

    StdlibExtension *ext = NEW(StdlibExtension);

    Ref exc = refMgr->createNativeObject(exceptionFuncs, NULL, engine->createNewTypeID());
    ext->exceptionClass = (NativeObject *)refMgr->translate(exc);

    Ref stdlib = refMgr->createObject();
    HashMap<String, Ref> values = ((ObjectValue *)refMgr->translate(stdlib))->members;

    values.set("Exception", exc);

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

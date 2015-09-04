#include "scripting/vm/engine.h"

#include "scripting/vm/context.h"
#include <stdint.h>

namespace scripting
{
Value *classNew(Context *ctx, const List<Value *>& args)
{
    if (args.getCount() < 1)
    {
        ctx->throwException(createException(ExcType::ValueError, "__new__/__call__ takes at least 1 argument."));
    }

    Value *class_ = args[0];

    Value *__base__ = createString("__base__");
    Value *base = getMember(ctx, class_, __base__);
    destroy(ctx, __base__);

    Value *__typeID__ = createString("__typeID__");
    Value *typeID = getMember(ctx, class_, __typeID__);
    destroy(ctx, __typeID__);

    if (base->type != ValueType::Object)
    {
        ctx->throwException(createException(ExcType::TypeError, "Class base must be an object."));
    }

    if (typeID->type != ValueType::Int)
    {
        ctx->throwException(createException(ExcType::TypeError, "Class type ID must be an integer."));
    }

    Value *resultHead = createObject();
    HashMap<String, Value *> resultMembers = ((ObjectValue *)resultHead)->members;

    resultMembers.append(((ObjectValue *)base)->members);
    resultMembers.set("__classTypeID__", createInt(((IntValue *)typeID)->value));

    int entry = resultMembers.findEntry("__init__");

    if (entry != -1)
    {
        callMethod(ctx, resultHead, "__init__", List<Value *>(args.getCount(), args.getData()+1));
    } else
    {
        if (args.getCount() != 1)
        {
            ctx->throwException(createException(ExcType::ValueError, "__new__/__call__ takes 1 argument."));
        }
    }

    return resultHead;
}

Value *createClass(Context *ctx, const List<Value *>& args)
{
    if (args.getCount() != 1)
    {
        ctx->throwException(createException(ExcType::ValueError, "__classify takes 1 arguments."));
    }

    Value *base = args[0];

    if (base->type != ValueType::Object)
    {
        ctx->throwException(createException(ExcType::ValueError, "base must be an object."));
    }

    Value *result = createObject();

    HashMap<String, Value *>& resultMembers = ((ObjectValue *)result)->members;

    resultMembers.set("__base__", createCopy(ctx, args[0]));
    resultMembers.set("__new__", createNativeFunction(classNew));
    resultMembers.set("__typeID__", createInt(ctx->getEngine()->createNewTypeID()));
    resultMembers.set("__call__", createNativeFunction(classNew));

    return result;
}

Engine::Engine() : debugOutput(true), nextTypeID(LONG_LONG_MIN)
{
    globalVars.set("__classify", createNativeFunction(createClass));
}

Engine::~Engine()
{
    Context *context = NEW(Context, this);

    for (size_t i = 0; i < globalVars.getEntryCount(); ++i)
    {
        destroy(context, globalVars.getValue(i));
    }

    DELETE(context);

    for (size_t i = 0; i < extensions.getEntryCount(); ++i)
    {
        extensions.getValue(i).deinit(this, extensions.getValue(i).data);
    }
}

void Engine::addExtension(const String& name, const Extension& extension)
{
    Extension result = extension;

    result.data = result.init(this, result.data);

    extensions.set(name, result);
}
}

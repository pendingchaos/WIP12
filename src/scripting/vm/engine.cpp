#include "scripting/vm/engine.h"

#include "scripting/vm/context.h"
#include <stdint.h>
#include <iostream>
namespace scripting
{
Value *classNew(Context *ctx, const List<Value *>& args)
{
    if (args.getCount() < 1)
    {
        ctx->throwException(createException(ExcType::ValueError, "__new__/__call__ takes at least 1 argument."));
    }

    Value *class_ = args[0];

    StringValue __base__;
    __base__.head.type = ValueType::StringType;
    __base__.value = "__base__";
    Value *base = getMember(ctx, class_, (Value *)&__base__);

    StringValue __typeID__;
    __typeID__.head.type = ValueType::StringType;
    __typeID__.value = "__typeID__";
    Value *typeID = getMember(ctx, class_, (Value *)&__typeID__);

    if (base->type != ValueType::Object)
    {
        ctx->throwException(createException(ExcType::TypeError, "Class base must be an object."));
    }

    if (typeID->type != ValueType::Int)
    {
        ctx->throwException(createException(ExcType::TypeError, "Class type ID must be an integer."));
    }

    Value *resultHead = createObject();
    HashMap<String, Value *>& resultMembers = ((ObjectValue *)resultHead)->members;
    HashMap<String, Value *>& baseMembers = ((ObjectValue *)base)->members;

    for (size_t i = 0; i < baseMembers.getEntryCount(); ++i)
    {
        resultMembers.set(baseMembers.getKey(i), createCopy(ctx, baseMembers.getValue(i)));
    }

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

    destroy(ctx, typeID);
    destroy(ctx, base);

    return resultHead;
}

Value *createClass(Context *ctx, const List<Value *>& args)
{
    if (args.getCount() != 1)
    {
        ctx->throwException(createException(ExcType::ValueError, "__classify takes 1 argument."));
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

Engine::Engine() : debugOutput(false), nextTypeID(LONG_LONG_MIN)
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

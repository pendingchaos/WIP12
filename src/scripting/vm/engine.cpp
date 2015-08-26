#include "scripting/vm/engine.h"

#include "scripting/vm/context.h"
#include <stdint.h>

namespace scripting
{
Ref classNew(Context *ctx, const List<Ref>& args)
{
    RefManager *refMgr = ctx->getEngine()->getRefMgr();

    if (args.getCount() < 1)
    {
        ctx->throwException(refMgr->createException(ExcType::ValueError, "__new__/__call__ takes at least 1 argument."));
    }

    Value *class_ = refMgr->translate(args[0]);

    Ref __base__ = refMgr->createString("__base__");
    Value *base = refMgr->translate(getMember(ctx, class_, refMgr->translate(__base__)));
    refMgr->destroy(ctx, __base__);

    Ref __typeID__ = refMgr->createString("__typeID__");
    Value *typeID = refMgr->translate(getMember(ctx, class_, refMgr->translate(__typeID__)));
    refMgr->destroy(ctx, __typeID__);

    if (base->type != ValueType::Object)
    {
        ctx->throwException(refMgr->createException(ExcType::TypeError, "Class base must be an object."));
    }

    if (typeID->type != ValueType::Int)
    {
        ctx->throwException(refMgr->createException(ExcType::TypeError, "Class type ID must be an integer."));
    }

    Ref result = refMgr->createObject();
    Value *resultHead = refMgr->translate(result);
    HashMap<String, Ref> resultMembers = ((ObjectValue *)resultHead)->members;

    resultMembers.append(((ObjectValue *)base)->members);
    resultMembers.set("__classTypeID__", refMgr->createInt(((IntValue *)typeID)->value));

    int entry = resultMembers.findEntry("__init__");

    if (entry != -1)
    {
        callMethod(ctx, resultHead, "__init__", List<Ref>(args.getCount(), args.getData()+1));
    } else
    {
        if (args.getCount() != 1)
        {
            ctx->throwException(refMgr->createException(ExcType::ValueError, "__new__/__call__ takes 1 argument."));
        }
    }

    return result;
}

Ref createClass(Context *ctx, const List<Ref>& args)
{
    RefManager *refMgr = ctx->getEngine()->getRefMgr();

    if (args.getCount() != 1)
    {
        ctx->throwException(refMgr->createException(ExcType::ValueError, "__classify takes 1 arguments."));
    }

    Value *base = refMgr->translate(args[0]);

    if (base->type != ValueType::Object)
    {
        ctx->throwException(refMgr->createException(ExcType::ValueError, "base must be an object."));
    }

    Ref result = refMgr->createObject();

    HashMap<String, Ref>& resultMembers = ((ObjectValue *)refMgr->translate(result))->members;

    resultMembers.set("__base__", refMgr->createCopy(ctx, args[0]));
    resultMembers.set("__new__", refMgr->createNativeFunction(classNew));
    resultMembers.set("__typeID__", refMgr->createInt(ctx->getEngine()->createNewTypeID()));
    resultMembers.set("__call__", refMgr->createNativeFunction(classNew));

    return result;
}

Engine::Engine() : debugOutput(true), nextTypeID(LONG_LONG_MIN)
{
    globalVars.set("__classify", refMgr.createNativeFunction(createClass));
}

Engine::~Engine()
{
    Context *context = NEW(Context, this);

    for (size_t i = 0; i < globalVars.getEntryCount(); ++i)
    {
        refMgr.destroy(context, globalVars.getValue(i));
    }

    DELETE(Context, context);

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

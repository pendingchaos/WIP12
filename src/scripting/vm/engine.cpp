#include "scripting/vm/engine.h"

#include "scripting/vm/context.h"
#include <stdint.h>

namespace scripting
{
Engine::Engine() : debugOutput(true), nextTypeID(LONG_LONG_MIN)
{
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

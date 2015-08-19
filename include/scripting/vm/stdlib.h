#ifndef SCRIPTING_STDLIB_H
#define SCRIPTING_STDLIB_H

#include "scripting/vm/types.h"

namespace scripting
{
    class Engine;
    class RefManager;

    void registerStdlib(Engine *engine);
    Ref createException(Context *ctx, ExcType type, const String& error);
}

#endif // SCRIPTING_STDLIB_H

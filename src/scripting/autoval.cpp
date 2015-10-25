#include "scripting/autoval.h"

#include "scripting/vm/context.h"

//TODO: Use the current context if possible.
AutoVal::~AutoVal()
{
    scripting::Context ctx(scriptEngine);
    scripting::destroy(&ctx, val);
}

AutoVal& AutoVal::operator = (const AutoVal& other)
{
    return *this = other.val;
}

AutoVal& AutoVal::operator = (const scripting::Value& other)
{
    scripting::Context ctx(scriptEngine);
    scripting::destroy(&ctx, val);

    val = scripting::createCopy(other);

    return *this;
}

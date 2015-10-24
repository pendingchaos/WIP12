#include "scripting/autoval.h"

#include "scripting/vm/context.h"

//TODO: Use the current context if possible.
AutoVal::~AutoVal()
{
    static uint8_t ctx[sizeof(scripting::Context)];
    new ((scripting::Context *)ctx) scripting::Context(scriptEngine);
    scripting::destroy((scripting::Context *)ctx, val);
    ((scripting::Context *)ctx)->~Context();
}

AutoVal& AutoVal::operator = (const AutoVal& other)
{
    return *this = other.val;
}

AutoVal& AutoVal::operator = (const scripting::Value& other)
{
    static uint8_t ctx[sizeof(scripting::Context)];
    new ((scripting::Context *)ctx) scripting::Context(scriptEngine);
    scripting::destroy((scripting::Context *)ctx, val);
    ((scripting::Context *)ctx)->~Context();

    val = scripting::createCopy(other);

    return *this;
}

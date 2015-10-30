#ifndef AUTOVAL_H
#define AUTOVAL_H

#include "scripting/vm/types.h"
#include "globals.h"

class AutoVal
{
    public:
        AutoVal() : val(scripting::createNil()) {}
        AutoVal(const AutoVal& other) : val(scripting::createCopy(other.val)) {}
        AutoVal(const scripting::Value& other) : val(scripting::createCopy(other)) {}
        ~AutoVal();

        AutoVal& operator = (const AutoVal& other);
        AutoVal& operator = (const scripting::Value& other);

        bool operator == (const scripting::Value& other) const
        {
            return val == other;
        }

        bool operator == (const AutoVal& other) const
        {
            return val == other.val;
        }

        bool operator != (const scripting::Value& other) const
        {
            return val != other;
        }

        bool operator != (const AutoVal& other) const
        {
            return val != other.val;
        }

        scripting::Value& getVal()
        {
            return val;
        }

        const scripting::Value& getVal() const
        {
            return val;
        }
    private:
        scripting::Value val;
};

#endif // AUTOVAL_H

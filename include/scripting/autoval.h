#ifndef AUTOVAL_H
#define AUTOVAL_H

#include "scripting/vm/types.h"
#include "globals.h"

class AutoVal
{
    public:
        inline AutoVal() : val(scripting::createNil()) {}
        inline AutoVal(const AutoVal& other) : val(scripting::createCopy(other.val)) {}
        inline AutoVal(const scripting::Value& other) : val(scripting::createCopy(other)) {}
        ~AutoVal();

        AutoVal& operator = (const AutoVal& other);
        AutoVal& operator = (const scripting::Value& other);

        inline bool operator == (const scripting::Value& other) const
        {
            return val == other;
        }

        inline bool operator == (const AutoVal& other) const
        {
            return val == other.val;
        }

        inline bool operator != (const scripting::Value& other) const
        {
            return val != other;
        }

        inline bool operator != (const AutoVal& other) const
        {
            return val != other.val;
        }

        inline scripting::Value& getVal()
        {
            return val;
        }

        inline const scripting::Value& getVal() const
        {
            return val;
        }
    private:
        scripting::Value val;
};

#endif // AUTOVAL_H

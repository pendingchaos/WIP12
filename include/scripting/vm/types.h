#ifndef SCRIPTING_TYPES_H
#define SCRIPTING_TYPES_H

#include "containers/hashmap.h"
#include "containers/string.h"
#include "containers/list.h"
#include "containers/resizabledata.h"
#include "scripting/vm/bytecode.h"

#include <stdint.h>

namespace scripting
{
struct Value;
class RefManager;
class Context;

enum class ExcType
{
    ValueError,
    TypeError,
    KeyError,
    IndexError
};

struct NativeObject;

struct NativeObjectFuncs
{
    void (*destroy)(Context *ctx, const Value& self);
    Value (*getMember)(Context *ctx, const Value& self, const Value& key);
    void (*setMember)(Context *ctx, const Value& self, const Value& key, const Value& value);
};

enum class ValueType
{
    Int,
    Float,
    Boolean,
    Nil,
    Function,
    Object,
    StringType,
    NativeFunction,
    NativeObject,
    Exception
};

struct Value
{
    ValueType type;
    union
    {
        void *p;
        int64_t i;
        double f;
        bool b;
        Value (*func)(Context *ctx, const List<Value>& args);
        uint8_t s[sizeof(Str)];
    };

    bool operator == (const Value& other) const;

    inline bool operator != (const Value& other) const
    {
        return not (*this == other);
    }

    inline Str getStr() const
    {
        return *(Str *)s;
    }
};

struct FunctionData
{
    inline FunctionData() {}
    inline FunctionData(const Bytecode& bytecode_) : bytecode(bytecode_) {}

    Bytecode bytecode;
};

struct ObjectData
{
    inline ObjectData() : refCount(1) {}

    HashMap<Str, Value> members;
    uint64_t refCount;
};

struct ExceptionData
{
    inline ExceptionData(ExcType type_, Str error_) : type(type_), error(error_) {}

    ExcType type;
    Str error;
};

struct NativeObjectData
{
    inline NativeObjectData(NativeObjectFuncs funcs_,
                            void *data_,
                            int64_t typeID_) : funcs(funcs_),
                                               typeID(typeID_),
                                               refCount(1),
                                               data(data_) {}

    NativeObjectFuncs funcs;
    int64_t typeID;
    uint64_t refCount;
    void *data;
};

Value createInt(int64_t value);
Value createFloat(double value);
Value createBoolean(bool value);
Value createNil();
Value createFunction(const Bytecode& bytecode);
Value createObject();
Value createReference(Value *value);
Value createString(const Str& value);
Value createNativeFunction(Value (*func)(Context *ctx, const List<Value>& args));
Value createException(ExcType type, Str error);
Value createNativeObject(const NativeObjectFuncs& funcs, void *data, int64_t typeID);
Value createCopy(Context *context, const Value& value);
void destroy(Context *context, const Value& value);
}

#endif // SCRIPTING_TYPES_H

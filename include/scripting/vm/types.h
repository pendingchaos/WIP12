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

class Ref
{
    friend RefManager;

    public:
        inline bool operator == (const Ref& ref) const
        {
            return ref.index == index and ref.generation == generation;
        }

        inline bool operator != (const Ref& ref) const
        {
            return not (*this == ref);
        }
    private:
        uint64_t index : 22;
        uint64_t generation : 42;
};

struct NativeObject;

struct NativeObjectFuncs
{
    Ref (*copy)(Context *ctx, NativeObject *self);
    void (*destroy)(Context *ctx, NativeObject *self);
    Ref (*getMember)(Context *ctx, NativeObject *self, Value *key);
    void (*setMember)(Context *ctx, NativeObject *self, Value *key, Value *value);
};

class RefManager
{
    public:
        static const size_t maxInstances = 100000;

        RefManager() : next(0)
        {
            for (size_t i = 0; i < maxInstances-1; ++i)
            {
                instances[i].next = i + 1;
                instances[i].generation = 0;
            }

            instances[maxInstances-1].next = -1;
        }

        Ref createInt(int64_t value);
        Ref createFloat(double value);
        Ref createBoolean(bool value);
        Ref createNil();
        Ref createFunction(Bytecode& bytecode);
        Ref createObject();
        Ref createReference(const Ref& value);
        Ref createString(const String& value);
        Ref createList(const List<Ref>& value);
        Ref createNativeFunction(Ref (*func)(Context *ctx, const List<Ref>& args));
        Ref createException(ExcType type, String error);
        Ref createNativeObject(const NativeObjectFuncs& funcs, void *data, uint64_t typeID);
        Ref createCopy(Context *context, const Ref& ref);
        Ref createCopy(Context *context, Value *value);

        void copyRef(Context *context, const Ref& dest, const Ref& src);

        inline Value *translate(const Ref& ref) const
        {
            return instances[ref.index].value;
        }

        inline bool valid(const Ref& ref) const
        {
            return ref.index < maxInstances ?
                   (instances[ref.index].generation == ref.generation)
                   : false;
        }

        void destroy(Context *context, const Ref& ref);
    private:
        Ref create(Value *value) const;
        void destroy(Context *context, Value *value);

        struct Instance
        {
            Value *value;
            uint64_t generation : 42;
            int64_t next : 23;
        };

        mutable Instance instances[maxInstances];
        mutable int64_t next : 23;
};

enum class ValueType
{
    Int,
    Float,
    Boolean,
    Nil,
    Function,
    Object,
    Reference,
    String,
    List,
    NativeFunction,
    NativeObject,
    Exception
};

struct Value
{
    ValueType type;
    Ref ref;
};

struct IntValue
{
    Value head;
    int64_t value;
};

struct FloatValue
{
    Value head;
    double value;
};

struct BooleanValue
{
    Value head;
    bool value;
};

struct NilValue
{
    Value head;
};

struct FunctionValue
{
    FunctionValue() {}
    FunctionValue(Bytecode& bytecode_) : bytecode(bytecode_) {}

    Value head;
    Bytecode bytecode;
};

struct ObjectValue
{
    Value head;
    HashMap<String, Ref> members;
    uint64_t refCount;
};

struct ReferenceValue
{
    Value head;
    Ref value;
};

struct StringValue
{
    Value head;
    String value;
};

struct ListValue
{
    Value head;
    List<Ref> value;
};

struct NativeFunction
{
    Value head;
    Ref (*func)(Context *ctx, const List<Ref>& args);
};

struct ExceptionValue
{
    Value head;
    ExcType type;
    String error;
};

struct NativeObject
{
    Value head;
    NativeObjectFuncs funcs;
    int64_t typeID;
    uint64_t refCount;
    void *data;
};
}

#endif // SCRIPTING_TYPES_H

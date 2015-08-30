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
    Value *(*copy)(Context *ctx, NativeObject *self);
    void (*destroy)(Context *ctx, NativeObject *self);
    Value *(*getMember)(Context *ctx, NativeObject *self, Value *key);
    void (*setMember)(Context *ctx, NativeObject *self, Value *key, Value *value);
};

Value *createInt(int64_t value);
Value *createFloat(double value);
Value *createBoolean(bool value);
Value *createNil();
Value *createFunction(Bytecode& bytecode);
Value *createObject();
Value *createReference(Value *value);
Value *createString(const String& value);
Value *createList(const List<Value *>& value);
Value *createNativeFunction(Value *(*func)(Context *ctx, const List<Value *>& args));
Value *createException(ExcType type, String error);
Value *createNativeObject(const NativeObjectFuncs& funcs, void *data, uint64_t typeID);
Value *createCopy(Context *context, const Value *value);
void destroy(Context *context, Value *value);

enum class ValueType
{
    Int,
    Float,
    Boolean,
    Nil,
    Function,
    Object,
    String,
    List,
    NativeFunction,
    NativeObject,
    Exception
};

struct Value
{
    ValueType type;
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
    HashMap<String, Value *> members;
    uint64_t refCount;
};

struct StringValue
{
    Value head;
    String value;
};

struct ListValue
{
    Value head;
    //TODO: Reference count this.
    List<Value *> value;
};

struct NativeFunction
{
    Value head;
    Value *(*func)(Context *ctx, const List<Value *>& args);
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

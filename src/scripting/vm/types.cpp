#include "scripting/vm/types.h"

#include "scripting/vm/context.h"
#include <assert.h>
#include "memory.h"

namespace scripting
{
Value *createInt(int64_t num)
{
    IntValue *value = NEW(IntValue);

    value->head.type = ValueType::Int;
    value->value = num;

    return (Value *)value;
}

Value *createFloat(double num)
{
    FloatValue *value = NEW(FloatValue);

    value->head.type = ValueType::Float;
    value->value = num;

    return (Value *)value;
}

Value *createBoolean(bool b)
{
    BooleanValue *value = NEW(BooleanValue);

    value->head.type = ValueType::Boolean;
    value->value = b;

    return (Value *)value;
}

Value *createNil()
{
    NilValue *value = NEW(NilValue);

    value->head.type = ValueType::Nil;

    return (Value *)value;
}

Value *createFunction(Bytecode& bytecode)
{
    FunctionValue *value = NEW(FunctionValue, bytecode);

    value->head.type = ValueType::Function;

    return (Value *)value;
}

Value *createObject()
{
    ObjectValue *value = NEW(ObjectValue);

    value->head.type = ValueType::Object;
    value->refCount = 1;

    return (Value *)value;
}

Value *createString(const String& str)
{
    StringValue *value = NEW(StringValue);

    value->head.type = ValueType::String;
    value->value = str;

    return (Value *)value;
}

Value *createList(const List<Value *>& values)
{
    ListValue *value = NEW(ListValue);

    value->head.type = ValueType::List;
    value->value = values;

    return (Value *)value;
}

Value *createNativeFunction(Value *(*func)(Context *ctx, const List<Value *>& args))
{
    NativeFunction *value = NEW(NativeFunction);

    value->head.type = ValueType::NativeFunction;
    value->func = func;

    return (Value *)value;
}

Value *createException(ExcType type, String error)
{
    ExceptionValue *value = NEW(ExceptionValue);

    value->head.type = ValueType::Exception;
    value->type = type;
    value->error = error;

    return (Value *)value;
}

Value *createNativeObject(const NativeObjectFuncs& funcs, void *data, uint64_t typeID)
{
    NativeObject *value = NEW(NativeObject);

    value->head.type = ValueType::NativeObject;
    value->funcs = funcs;
    value->data = data;
    value->typeID = typeID;
    value->refCount = 1;

    return (Value *)value;
}

Value *createCopy(Context *context, const Value *value)
{
    switch (value->type)
    {
    case ValueType::Int:
    {
        return createInt(((IntValue *)value)->value);
    }
    case ValueType::Float:
    {
        return createFloat(((FloatValue *)value)->value);
    }
    case ValueType::Boolean:
    {
        return createBoolean(((BooleanValue *)value)->value);
    }
    case ValueType::Nil:
    {
        return createNil();
    }
    case ValueType::Function:
    {
        return createFunction(((FunctionValue *)value)->bytecode);
    }
    case ValueType::Object:
    {
        ObjectValue *obj = NEW(ObjectValue, *(ObjectValue *)value);

        ++obj->refCount;

        return (Value *)obj;
    }
    case ValueType::String:
    {
        return createString(((StringValue *)value)->value);
    }
    case ValueType::List:
    {
        return createList(((ListValue *)value)->value);
    }
    case ValueType::NativeFunction:
    {
        return createNativeFunction(((NativeFunction *)value)->func);
    }
    case ValueType::NativeObject:
    {
        NativeObject *obj = NEW(NativeObject, *(NativeObject *)value);

        ++obj->refCount;

        return (Value *)obj;
    }
    case ValueType::Exception:
    {
        ExceptionValue *exc = (ExceptionValue *)value;

        return createException(exc->type, exc->error);
    }
    }

    assert(false);

    return createNil();
}

void destroy(Context *context, Value *value)
{
    switch (value->type)
    {
    case ValueType::Int:
    {
        DELETE(IntValue, value);
        break;
    }
    case ValueType::Float:
    {
        DELETE(FloatValue, value);
        break;
    }
    case ValueType::Boolean:
    {
        DELETE(BooleanValue, value);
        break;
    }
    case ValueType::Nil:
    {
        DELETE(NilValue, value);
        break;
    }
    case ValueType::Function:
    {
        DELETE(FunctionValue, value);
        break;
    }
    case ValueType::Object:
    {
        ObjectValue *obj = (ObjectValue *)value;

        --obj->refCount;

        if (obj->refCount == 0)
        {
            HashMap<String, Value *> members = ((ObjectValue *)value)->members;

            if (members.findEntry("__del__") != -1)
            {
                callMethod(context, value, "__del__", List<Value *>());
            }

            for (size_t i = 0; i < members.getEntryCount(); ++i)
            {
                destroy(context, members.getValue(i));
            }

            DELETE(ObjectValue, value);
        }
        break;
    }
    case ValueType::String:
    {
        DELETE(StringValue, value);
        break;
    }
    case ValueType::List:
    {
        List<Value *> list = ((ListValue *)value)->value;

        for (size_t i = 0; i < list.getCount(); ++i)
        {
            destroy(context, list[i]);
        }

        DELETE(ListValue, value);
        break;
    }
    case ValueType::NativeFunction:
    {
        DELETE(NativeFunction, value);
        break;
    }
    case ValueType::NativeObject:
    {
        NativeObject *obj = (NativeObject *)value;

        --obj->refCount;

        if (obj->refCount == 0)
        {
            if (obj->funcs.destroy != NULL)
            {
                obj->funcs.destroy(context, obj);
            }

            DELETE(NativeObject, value);
        }
        break;
    }
    case ValueType::Exception:
    {
        DELETE(ExceptionValue, value);
        break;
    }
    }
}
}

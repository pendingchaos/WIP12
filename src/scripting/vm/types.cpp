#include "scripting/vm/types.h"

#include "scripting/vm/context.h"
#include <assert.h>
#include "memory.h"

namespace scripting
{
Ref RefManager::createInt(int64_t num)
{
    IntValue *value = NEW(IntValue);

    value->head.type = ValueType::Int;
    value->value = num;

    return create((Value *)value);
}

Ref RefManager::createFloat(double num)
{
    FloatValue *value = NEW(FloatValue);

    value->head.type = ValueType::Float;
    value->value = num;

    return create((Value *)value);
}

Ref RefManager::createBoolean(bool b)
{
    BooleanValue *value = NEW(BooleanValue);

    value->head.type = ValueType::Boolean;
    value->value = b;

    return create((Value *)value);
}

Ref RefManager::createNil()
{
    NilValue *value = NEW(NilValue);

    value->head.type = ValueType::Nil;

    return create((Value *)value);
}

Ref RefManager::createFunction(Bytecode& bytecode)
{
    FunctionValue *value = NEW(FunctionValue, bytecode);

    value->head.type = ValueType::Function;

    return create((Value *)value);
}

Ref RefManager::createObject()
{
    ObjectValue *value = NEW(ObjectValue);

    value->head.type = ValueType::Object;

    return create((Value *)value);
}

Ref RefManager::createReference(const Ref& ref)
{
    ReferenceValue *value = NEW(ReferenceValue);

    value->head.type = ValueType::Reference;
    value->value = ref;

    return create((Value *)value);
}

Ref RefManager::createString(const String& str)
{
    StringValue *value = NEW(StringValue);

    value->head.type = ValueType::String;
    value->value = str;

    return create((Value *)value);
}

Ref RefManager::createList(const List<Ref>& values)
{
    ListValue *value = NEW(ListValue);

    value->head.type = ValueType::List;
    value->value = values;

    return create((Value *)value);
}

Ref RefManager::createNativeFunction(Ref (*func)(Context *ctx, const List<Ref>& args))
{
    NativeFunction *value = NEW(NativeFunction);

    value->head.type = ValueType::NativeFunction;
    value->func = func;

    return create((Value *)value);
}

Ref RefManager::createException(ExcType type, String error)
{
    ExceptionValue *value = NEW(ExceptionValue);

    value->head.type = ValueType::Exception;
    value->type = type;
    value->error = error;

    return create((Value *)value);
}

Ref RefManager::createNativeObject(const NativeObjectFuncs& funcs, void *data, uint64_t typeID)
{
    NativeObject *value = NEW(NativeObject);

    value->head.type = ValueType::NativeObject;
    value->funcs = funcs;
    value->data = data;
    value->typeID = typeID;

    return create((Value *)value);
}

Ref RefManager::createCopy(Context *context, const Ref& ref)
{
    Value *head = translate(ref);

    return createCopy(context, head);
}

Ref RefManager::createCopy(Context *context, Value *value)
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
        Ref objRef = createObject();

        ObjectValue *obj = (ObjectValue *)translate(objRef);
        HashMap<String, Ref> members = ((ObjectValue *)value)->members;

        for (size_t i = 0; i < members.getEntryCount(); ++i)
        {
            obj->members.set(members.getKey(i), createCopy(context, members.getValue(i)));
        }

        return objRef;
    }
    case ValueType::Reference:
    {
        return createReference(((ReferenceValue *)value)->value);
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
        NativeObject *obj = (NativeObject *)value;

        if (obj->funcs.copy != NULL)
        {
            return obj->funcs.copy(context, obj);
        } else
        {
            context->throwException(createException(ExcType::ValueError, "Native object is not copyable."));
        }
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

void RefManager::destroy(Context *context, Value *value)
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
        HashMap<String, Ref> members = ((ObjectValue *)value)->members;

        if (members.findEntry("__del__") != -1)
        {
            callMethod(context, value, "__del__", List<Ref>());
        }

        for (size_t i = 0; i < members.getEntryCount(); ++i)
        {
            destroy(context, members.getValue(i));
        }

        DELETE(ObjectValue, value);
        break;
    }
    case ValueType::Reference:
    {
        DELETE(ReferenceValue, value);
        break;
    }
    case ValueType::String:
    {
        DELETE(StringValue, value);
        break;
    }
    case ValueType::List:
    {
        List<Ref> list = ((ListValue *)value)->value;

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

        if (obj->funcs.destroy != NULL)
        {
            obj->funcs.destroy(context, obj);
        }

        DELETE(NativeObject, value);
        break;
    }
    case ValueType::Exception:
    {
        DELETE(ExceptionValue, value);
        break;
    }
    }
}

void RefManager::destroy(Context *context, const Ref& ref)
{
    if (not valid(ref))
    {
        return;
    }

    Value *head = translate(ref);

    destroy(context, head);

    instances[ref.index].next = next;
    ++instances[ref.index].generation;
    next = ref.index;
}

void RefManager::copyRef(Context *context, const Ref& dest, const Ref& src)
{
    Value *old = translate(dest);
    Value *head = translate(src);

    switch (head->type)
    {
    case ValueType::Int:
    {
        IntValue *value = NEW(IntValue);

        value->value = ((IntValue *)head)->value;

        instances[dest.index].value = (Value *)value;
        break;
    }
    case ValueType::Float:
    {
        FloatValue *value = NEW(FloatValue);

        value->value = ((FloatValue *)head)->value;

        instances[dest.index].value = (Value *)value;
        break;
    }
    case ValueType::Boolean:
    {
        BooleanValue *value = NEW(BooleanValue);

        value->value = ((BooleanValue *)head)->value;

        instances[dest.index].value = (Value *)value;
        break;
    }
    case ValueType::Nil:
    {
        instances[dest.index].value = (Value *)NEW(NilValue);
        break;
    }
    case ValueType::Function:
    {
        instances[dest.index].value = (Value *)NEW(FunctionValue, ((FunctionValue *)head)->bytecode);
        break;
    }
    case ValueType::Object:
    {
        ObjectValue *value = NEW(ObjectValue);

        HashMap<String, Ref> members = ((ObjectValue *)head)->members;

        for (size_t i = 0; i < members.getEntryCount(); ++i)
        {
            value->members.set(members.getKey(i), createCopy(context, translate(members.getValue(i))));
        }

        instances[dest.index].value = (Value *)value;
        break;
    }
    case ValueType::Reference:
    {
        ReferenceValue *value = NEW(ReferenceValue);

        value->value = ((ReferenceValue *)head)->value;

        instances[dest.index].value = (Value *)value;
        break;
    }
    case ValueType::String:
    {
        StringValue *value = NEW(StringValue);

        value->value = ((StringValue *)head)->value;

        instances[dest.index].value = (Value *)value;
        break;
    }
    case ValueType::List:
    {
        ListValue *value = NEW(ListValue);

        value->value = ((ListValue *)head)->value;

        instances[dest.index].value = (Value *)value;
        break;
    }
    case ValueType::NativeFunction:
    {
        NativeFunction *value = NEW(NativeFunction);

        value->func = ((NativeFunction *)head)->func;

        instances[dest.index].value = (Value *)value;
        break;
    }
    case ValueType::NativeObject:
    {
        //TODO
        break;
    }
    case ValueType::Exception:
    {
        ExceptionValue *value = NEW(ExceptionValue);

        value->error = ((ExceptionValue *)head)->error;
        value->type = ((ExceptionValue *)head)->type;

        instances[dest.index].value = (Value *)value;
        break;
    }
    }

    instances[dest.index].value->type = head->type;

    destroy(context, old);
}

//TODO: Use per-type pools.
Ref RefManager::create(Value *value) const
{
    assert(next != -1); //TODO: Have a fallback.
    assert(instances[next].generation+1 < ((uint64_t)1 << 42));

    uint64_t index = next;
    instances[next].value = value;
    uint64_t generation = instances[next].generation;
    next = instances[next].next;

    Ref ref;

    ref.index = index;
    ref.generation = generation;

    value->ref = ref;

    return ref;
}
}

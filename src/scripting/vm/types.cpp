#include "scripting/vm/types.h"

#include "scripting/vm/context.h"
#include <SDL2/SDL_assert.h>
#include "memory.h"

namespace scripting
{
//TODO: Improve this.
bool Value::operator == (const Value& other) const
{
    if (type == ValueType::Object and other.type == ValueType::Object)
    {
        return p == other.p;
    } else if (type == ValueType::NativeObject and other.type == ValueType::NativeObject)
    {
        return p == other.p;
    } else if (type == ValueType::StringType and other.type == ValueType::StringType)
    {
        return getStr() == other.getStr();
    } else if (type == ValueType::Float and other.type == ValueType::Float)
    {
        return f == other.f;
    } else if (type == ValueType::Int and other.type == ValueType::Int)
    {
        return i == other.i;
    } else if (type == ValueType::Float and other.type == ValueType::Int)
    {
        return f == other.i;
    } else if (type == ValueType::Int and other.type == ValueType::Float)
    {
        return i == other.f;
    } else if (type == ValueType::Boolean and other.type == ValueType::Boolean)
    {
        return b == other.b;
    } else if (type == ValueType::Nil and other.type == ValueType::Nil)
    {
        return true;
    } else if (type == ValueType::Function and other.type == ValueType::Function)
    {
        return ((FunctionData *)p)->bytecode.data == ((FunctionData *)p)->bytecode.data;
    } else if (type == ValueType::NativeFunction and other.type == ValueType::NativeFunction)
    {
        return func == other.func;
    } else if (type == ValueType::Exception and other.type == ValueType::Exception)
    {
        ExceptionData exc = *(ExceptionData *)p;
        ExceptionData otherExc = *(ExceptionData *)other.p;

        return exc.type == otherExc.type and exc.error == otherExc.error;
    } else
    {
        return false;
    }
}

Value createInt(int64_t num)
{
    Value v;
    v.type = ValueType::Int;
    v.i = num;
    return v;
}

Value createFloat(double num)
{
    Value v;
    v.type = ValueType::Float;
    v.f = num;
    return v;
}

Value createBoolean(bool b)
{
    Value v;
    v.type = ValueType::Boolean;
    v.b = b;
    return v;
}

Value createNil()
{
    Value v;
    v.type = ValueType::Nil;
    return v;
}

Value createFunction(const Bytecode& bytecode)
{
    Value v;
    v.type = ValueType::Function;
    v.p = (void *)NEW(FunctionData, bytecode);
    return v;
}

Value createObject()
{
    Value v;
    v.type = ValueType::Object;
    v.p = (void *)NEW(ObjectData);
    return v;
}

Value createString(const Str& str)
{
    Value v;
    v.type = ValueType::StringType;
    new ((Str *)v.s) Str(str);
    return v;
}

Value createNativeFunction(Value (*func)(Context *ctx, const List<Value>& args))
{
    Value v;
    v.type = ValueType::NativeFunction;
    v.func = func;
    return v;
}

Value createException(ExcType type, Str error)
{
    Value v;
    v.type = ValueType::Exception;
    v.p = (void *)NEW(ExceptionData, type, error);
    return v;
}

Value createNativeObject(const NativeObjectFuncs& funcs, void *data, int64_t typeID)
{
    Value v;
    v.type = ValueType::NativeObject;
    v.p = (void *)NEW(NativeObjectData, funcs, data, typeID);
    return v;
}

Value createCopy(const Value& value)
{
    switch (value.type)
    {
    case ValueType::Int:
    {
        return createInt(value.i);
    }
    case ValueType::Float:
    {
        return createFloat(value.f);
    }
    case ValueType::Boolean:
    {
        return createBoolean(value.b);
    }
    case ValueType::Nil:
    {
        return createNil();
    }
    case ValueType::Function:
    {
        return createFunction(((FunctionData *)value.p)->bytecode);
    }
    case ValueType::Object:
    {
        ++(((ObjectData *)value.p)->refCount);
        return value;
    }
    case ValueType::StringType:
    {
        return createString(value.getStr());
    }
    case ValueType::NativeFunction:
    {
        return createNativeFunction(value.func);
    }
    case ValueType::NativeObject:
    {
        ++(((NativeObjectData *)value.p)->refCount);
        return value;
    }
    case ValueType::Exception:
    {
        ExceptionData *exc = (ExceptionData *)value.p;
        return createException(exc->type, exc->error);
    }
    }

    SDL_assert_release(false);

    return createNil();
}

void destroy(Context *context, const Value& value)
{
    switch (value.type)
    {
    case ValueType::Int:
    case ValueType::Float:
    case ValueType::Boolean:
    case ValueType::Nil:
    case ValueType::NativeFunction:
    {
        break;
    }
    case ValueType::Function:
    {
        DELETE((FunctionData *)value.p);
        break;
    }
    case ValueType::Object:
    {
        ObjectData *obj = (ObjectData *)value.p;

        --obj->refCount;

        if (obj->refCount == 0)
        {
            obj->refCount = 1; //Hack

            HashMap<Str, Value> members = ((ObjectData *)value.p)->members;

            auto pos = members.find("__del__");
            if (pos != members.end())
            {
                destroy(context, callMethod(context, value, "__del__", List<Value>()));
            }

            for (auto kv : members)
            {
                destroy(context, kv.second);
            }

            DELETE(obj);
        }
        break;
    }
    case ValueType::StringType:
    {
        ((const Str *)value.s)->~Str();
        break;
    }
    case ValueType::NativeObject:
    {
        NativeObjectData *obj = (NativeObjectData *)value.p;

        --obj->refCount;

        if (obj->refCount == 0)
        {
            obj->refCount = 1; //Hack

            if (obj->funcs.destroy != NULL)
            {
                obj->funcs.destroy(context, value);
            }

            DELETE(obj);
        }
        break;
    }
    case ValueType::Exception:
    {
        DELETE((ExceptionData *)value.p);
        break;
    }
    default:
    {
        SDL_assert_release(false); //TODO: This triggered once.
    }
    }
}
}

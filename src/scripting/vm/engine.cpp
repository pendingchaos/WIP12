#include "scripting/vm/engine.h"

#include "scripting/vm/context.h"
#include <stdint.h>
#include <SDL2/SDL_assert.h>
#include <cmath>
#include <iostream>

namespace scripting
{
static Value classNew(Context *ctx, const List<Value>& args)
{
    if (args.getCount() < 1)
    {
        ctx->throwException(createException(ExcType::ValueError, "__new__/__call__ takes at least 1 argument."));
    }

    Value class_ = args[0];

    StringData __base__;
    Value __base__Val;
    __base__Val.type = ValueType::StringType;
    __base__Val.p = &__base__;
    __base__.value = "__base__";
    Value base = getMember(ctx, class_, __base__Val);

    StringData __typeID__;
    Value __typeID__Val;
    __typeID__Val.type = ValueType::StringType;
    __typeID__Val.p = &__typeID__;
    __typeID__.value = "__typeID__";
    Value typeID = getMember(ctx, class_, __typeID__Val);

    if (base.type != ValueType::Object)
    {
        ctx->throwException(createException(ExcType::TypeError, "Class base must be an object."));
    }

    if (typeID.type != ValueType::Int)
    {
        ctx->throwException(createException(ExcType::TypeError, "Class type ID must be an integer."));
    }

    Value resultHead = createObject();
    HashMap<String, Value>& resultMembers = ((ObjectData *)resultHead.p)->members;
    HashMap<String, Value>& baseMembers = ((ObjectData *)base.p)->members;

    for (auto kv : baseMembers)
    {
        resultMembers.set(kv.first, createCopy(ctx, kv.second));
    }

    resultMembers.set("__classTypeID__", createInt(typeID.i));

    auto pos = resultMembers.find("__init__");
    if (pos != resultMembers.end())
    {
        destroy(ctx, callMethod(ctx, resultHead, "__init__", List<Value>(args.getCount()-1, args.getData()+1)));
    } else
    {
        if (args.getCount() != 1)
        {
            ctx->throwException(createException(ExcType::ValueError, "__new__/__call__ takes 1 argument."));
        }
    }

    destroy(ctx, typeID);
    destroy(ctx, base);

    return resultHead;
}

static Value createClass(Context *ctx, const List<Value>& args)
{
    if (args.getCount() != 1)
    {
        ctx->throwException(createException(ExcType::ValueError, "__classify takes 1 argument."));
    }

    Value base = args[0];

    if (base.type != ValueType::Object)
    {
        ctx->throwException(createException(ExcType::ValueError, "base must be an object."));
    }

    Value result = createObject();

    HashMap<String, Value>& resultMembers = ((ObjectData *)result.p)->members;

    resultMembers.set("__base__", createCopy(ctx, args[0]));
    resultMembers.set("__new__", createNativeFunction(classNew));
    resultMembers.set("__typeID__", createInt(ctx->getEngine()->createNewTypeID()));
    resultMembers.set("__call__", createNativeFunction(classNew));

    return result;
}

static Value methodCall(Context *ctx, const List<Value>& args)
{
    if (args.getCount() < 1)
    {
        ctx->throwException(createException(ExcType::ValueError, "Method call requires at least 1 argument."));
    }

    if (args[0].type != ValueType::Object)
    {
        ctx->throwException(createException(ExcType::TypeError, "Method call requires (method) object as first parameter."));
    }

    HashMap<String, Value>& members = ((ObjectData *)args[0].p)->members;

    Value func;
    Value obj;

    try
    {
        func = members.get("__func__");
        obj = members.get("__obj__");
    } catch (LookupException& e)
    {
        ctx->throwException(createException(ExcType::ValueError, "Invalid method object."));

        SDL_assert_release(false);
    }

    List<Value> args2;
    args2.append(obj);
    args2.append(args.getCount()-1, args.getData()+1);

    return call(ctx, func, args2);
}

static Value createMethod(Context *ctx, const List<Value>& args)
{
    if (args.getCount() != 2)
    {
        ctx->throwException(createException(ExcType::ValueError, "__methodify takes 2 argument."));
    }

    Value result = createObject();

    HashMap<String, Value>& resultMembers = ((ObjectData *)result.p)->members;

    resultMembers.set("__func__", createCopy(ctx, args[0]));
    resultMembers.set("__obj__", createCopy(ctx, args[1]));
    resultMembers.set("__call__", createNativeFunction(methodCall));

    return result;
}

static double asNumber(Context *ctx, const Value& value)
{
    switch (value.type)
    {
    case ValueType::Float:
    {
        return value.f;
    }
    case ValueType::Int:
    {
        return value.i;
    }
    default:
    {
        ctx->throwException(createException(ExcType::TypeError, "Value is not convertable to float."));
    }
    }

    SDL_assert_release(false);
}

static Value mathAbs(Context *ctx, const List<Value>& args)
{
    if (args.getCount() != 1)
    {
        ctx->throwException(createException(ExcType::ValueError, "abs takes only one argument."));
    }

    switch (args[0].type)
    {
    case ValueType::Float:
    {
        return createFloat(std::abs(args[0].f));
    }
    case ValueType::Int:
    {
        return createInt(std::llabs(args[0].i));
    }
    default:
    {
        ctx->throwException(createException(ExcType::TypeError, "Value is not convertable to float."));
    }
    }

    SDL_assert_release(false);
}

template <double (*F)(double)>
struct mathFunc1
{
    static Value f(Context *ctx, const List<Value>& args)
    {
        if (args.getCount() != 1)
        {
            ctx->throwException(createException(ExcType::ValueError, "Function takes only one argument."));
        }

        return createFloat(F(asNumber(ctx, args[0])));
    }
};

template <double (*F)(double, double)>
struct mathFunc2
{
    static Value f(Context *ctx, const List<Value>& args)
    {
        if (args.getCount() != 2)
        {
            ctx->throwException(createException(ExcType::ValueError, "Function takes only one argument."));
        }

        return createFloat(F(asNumber(ctx, args[0]), asNumber(ctx, args[1])));
    }
};

static double mathMin(double a, double b)
{
    return std::min(a, b);
}

static double mathMax(double a, double b)
{
    return std::max(a, b);
}

static Value isNil(Context *ctx, const List<Value>& args)
{
    if (args.getCount() != 1)
    {
        ctx->throwException(createException(ExcType::ValueError, "isNil takes one argument."));
    }

    return createBoolean(args[0].type == ValueType::Nil);
}

static Value print(Context *ctx, const List<Value>& args)
{
    for (size_t i = 0; i < args.getCount(); ++i)
    {
        Value val = args[i];

        switch (val.type)
        {
        case ValueType::StringType:
        {
            std::cout << ((StringData *)val.p)->value.getData() << ' ';
            break;
        }
        case ValueType::Int:
        {
            std::cout << val.i << ' ';
            break;
        }
        case ValueType::Float:
        {
            std::cout << val.f << ' ';
            break;
        }
        case ValueType::Boolean:
        {
            std::cout << (val.b ? "true" : "false") << ' ';
            break;
        }
        case ValueType::Nil:
        {
            std::cout << "nil ";
            break;
        }
        case ValueType::Function:
        {
            std::cout << "<function> ";
            break;
        }
        case ValueType::Object:
        {
            std::cout << "<object> ";
            break;
        }
        case ValueType::NativeFunction:
        {
            std::cout << "<native function> ";
            break;
        }
        case ValueType::NativeObject:
        {
            std::cout << "<native object> ";
            break;
        }
        case ValueType::Exception:
        {
            std::cout << "<exception> ";
            break;
        }
        }
    }

    std::cout << std::endl;

    return createNil();
}

Engine::Engine() : nextTypeID(LONG_LONG_MIN)
{
    globalVars.set("__classify", createNativeFunction(createClass));
    globalVars.set("__methodify", createNativeFunction(createMethod));
    globalVars.set("abs", createNativeFunction(mathAbs));
    globalVars.set("exp", createNativeFunction(mathFunc1<std::exp>::f));
    globalVars.set("exp2", createNativeFunction(mathFunc1<std::exp2>::f));
    globalVars.set("expm1", createNativeFunction(mathFunc1<std::expm1>::f));
    globalVars.set("log", createNativeFunction(mathFunc1<std::log>::f));
    globalVars.set("log10", createNativeFunction(mathFunc1<std::log10>::f));
    globalVars.set("log2", createNativeFunction(mathFunc1<std::log2>::f));
    globalVars.set("log1p", createNativeFunction(mathFunc1<std::log1p>::f));
    globalVars.set("pow", createNativeFunction(mathFunc2<std::pow>::f));
    globalVars.set("sqrt", createNativeFunction(mathFunc1<std::sqrt>::f));
    globalVars.set("cbrt", createNativeFunction(mathFunc1<std::cbrt>::f));
    globalVars.set("hypot", createNativeFunction(mathFunc2<std::hypot>::f));
    globalVars.set("sin", createNativeFunction(mathFunc1<std::sin>::f));
    globalVars.set("cos", createNativeFunction(mathFunc1<std::cos>::f));
    globalVars.set("tan", createNativeFunction(mathFunc1<std::tan>::f));
    globalVars.set("asin", createNativeFunction(mathFunc1<std::asin>::f));
    globalVars.set("acos", createNativeFunction(mathFunc1<std::acos>::f));
    globalVars.set("atan", createNativeFunction(mathFunc1<std::atan>::f));
    globalVars.set("atan2", createNativeFunction(mathFunc2<std::atan2>::f));
    globalVars.set("sinh", createNativeFunction(mathFunc1<std::sinh>::f));
    globalVars.set("cosh", createNativeFunction(mathFunc1<std::cosh>::f));
    globalVars.set("tanh", createNativeFunction(mathFunc1<std::tanh>::f));
    globalVars.set("asinh", createNativeFunction(mathFunc1<std::asinh>::f));
    globalVars.set("acosh", createNativeFunction(mathFunc1<std::acosh>::f));
    globalVars.set("atanh", createNativeFunction(mathFunc1<std::atanh>::f));
    globalVars.set("erf", createNativeFunction(mathFunc1<std::erf>::f));
    globalVars.set("erfc", createNativeFunction(mathFunc1<std::erfc>::f));
    globalVars.set("lgamma", createNativeFunction(mathFunc1<std::lgamma>::f));
    globalVars.set("ceil", createNativeFunction(mathFunc1<std::ceil>::f));
    globalVars.set("floor", createNativeFunction(mathFunc1<std::floor>::f));
    globalVars.set("trunc", createNativeFunction(mathFunc1<std::trunc>::f));
    globalVars.set("round", createNativeFunction(mathFunc1<std::round>::f));
    globalVars.set("max", createNativeFunction(mathFunc2<mathMax>::f));
    globalVars.set("min", createNativeFunction(mathFunc2<mathMin>::f));
    globalVars.set("HUGE_VAL", createFloat(HUGE_VAL));
    globalVars.set("INF", createFloat(INFINITY));
    globalVars.set("NAN", createFloat(NAN));
    globalVars.set("PI", createFloat(M_PI));

    globalVars.set("isNil", createNativeFunction(isNil));
    globalVars.set("print", createNativeFunction(print));
}

Engine::~Engine()
{
    Context *context = NEW(Context, this);

    for (auto kv : globalVars)
    {
        destroy(context, kv.second);
    }

    DELETE(context);

    for (auto kv : extensions)
    {
        kv.second.deinit(this, kv.second.data);
    }
}

void Engine::addExtension(const String& name, const Extension& extension)
{
    Extension result = extension;

    result.data = result.init(this, result.data);

    extensions.set(name, result);
}
}

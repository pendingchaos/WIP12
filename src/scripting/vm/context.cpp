#include "scripting/vm/context.h"

#include "scripting/vm/engine.h"
#include "logging.h"

#include <cmath>
#include <SDL2/SDL_assert.h>

namespace scripting
{
Context::Context(Engine *engine_) : engine(engine_), callStackSize(0), exception(createNil()) {}

Context::~Context()
{
    while (callStackSize != 0)
    {
        popCallstack();
    }

    reset();

    destroy(this, exception);
}

void Context::reset()
{
    for (size_t i = 0; i < callStackSize; ++i)
    {
        CallstackEntry& entry = callStack[i];

        for (auto stack : entry.stacks)
        {
            for (auto value : stack)
            {
                destroy(this, value);
            }
        }

        entry.stacks.clear();

        for (auto kv : entry.variables)
        {
            destroy(this, kv.second);
        }

        entry.variables.clear();
    }

    callStackSize = 0;
}

#define USE_COMPUTED_GOTO

#ifdef USE_COMPUTED_GOTO
#define BEGIN {BREAK
#define END } end:;
#define BREAK goto* offset >= bytecode.data.getSize() ?\
                    &&end :\
                    dispatchTable[bytecode.getUInt8(offset++)];
#define CASE(name) name:
#else
#define BEGIN while (offset < bytecode.data.getSize()){Opcode opcode = bytecode.getOpcode(offset++); switch (opcode) {
#define END }}
#define BREAK break;
#define CASE(name) case Opcode::name:
#endif

Value Context::_run(const Bytecode& bytecode, List<Value> args)
{
#ifdef USE_COMPUTED_GOTO
static void *dispatchTable[] = {&&PushInt, &&PushFloat, &&PushBoolean, &&PushNil, &&PushFunc,
                                &&PushObject, &&PushString, &&PushException, &&StackPop,
                                &&StackDup, &&LoadVar, &&StoreVar, &&GetMember, &&SetMember,
                                &&Add, &&Subtract, &&Multiply, &&Divide, &&Modulo,
                                &&BoolAnd, &&BoolOr, &&BoolNot, &&BitAnd, &&BitOr, &&BitNot,
                                &&BitXOr, &&LeftShift, &&RightShift, &&Less, &&Greater, &&Equal,
                                &&NotEqual, &&LessEqual, &&GreaterEqual, &&Call, &&Return,
                                &&GetArgCount, &&GetArg, &&JumpIf, &&Jump, &&Try, &&EndTry,
                                &&Throw, &&GetException};
#endif

    CallstackEntry& callstackEntry = callStack[callStackSize-1];
    size_t& offset = callstackEntry.offset;
    List<Value> *stack = &callstackEntry.stacks[0];

    BEGIN
        CASE(PushInt)
        {
            stack->append(createInt(bytecode.getInt64(offset)));
            offset += 8;
            BREAK
        }
        CASE(PushFloat)
        {
            stack->append(createFloat(bytecode.getDouble(offset)));
            offset += 8;
            BREAK
        }
        CASE(PushBoolean)
        {
            stack->append(createBoolean(bytecode.getBoolean(offset)));
            offset += 1;
            BREAK
        }
        CASE(PushNil)
        {
            stack->append(createNil());
            BREAK
        }
        CASE(PushFunc)
        {
            size_t size = bytecode.getUInt32(offset);
            offset += 4;

            ResizableData data = bytecode.getData(offset, size);
            offset += size;

            Bytecode code(data);

            stack->append(createFunction(code));
            BREAK
        }
        CASE(PushObject)
        {
            stack->append(createObject());
            BREAK
        }
        CASE(PushString)
        {
            size_t length = bytecode.getUInt32(offset);
            offset += 4;

            ResizableData data = bytecode.getData(offset, length);
            offset += length;

            stack->append(createString(String(length, (const char *)data.getData())));
            BREAK
        }
        CASE(PushException)
        {
            ExcType type = (ExcType)bytecode.getUInt8(offset);
            offset += 1;

            size_t length = bytecode.getUInt32(offset);
            offset += 4;

            ResizableData data = bytecode.getData(offset, length);
            offset += length;

            stack->append(createException(type, String(length, (const char *)data.getData())));
            BREAK
        }
        CASE(StackPop)
        {
            destroy(this, popStack(*stack));
            BREAK
        }
        CASE(StackDup)
        {
            Value value = popStack(*stack);

            stack->append(createCopy(this, value));
            stack->append(value);
            BREAK
        }
        CASE(LoadVar)
        {
            Value nameVal = popStack(*stack);

            if (nameVal.type != ValueType::StringType)
            {
                destroy(this, nameVal);

                throwException(createException(ExcType::TypeError, "Variable name must be String."));
                BREAK
            }

            String name = ((StringData *)nameVal.p)->value;

            bool found = false;

            for (ptrdiff_t i = 0; i < (ptrdiff_t)callStackSize; ++i)
            {
                HashMap<String, Value>& vars = callStack[i].variables;

                auto pos = vars.find(name);
                if (pos != vars.end())
                {
                    stack->append(createCopy(this, pos->second));
                    found = true;
                    BREAK
                }
            }

            if (not found)
            {
                HashMap<String, Value>& vars = engine->getGlobalVars();

                auto pos = vars.find(name);

                if (pos != vars.end())
                {
                    stack->append(createCopy(this, pos->second));
                } else
                {
                    throwException(createException(ExcType::KeyError, String::format("No such variable '%s'.", name.getData())));
                }
            }

            destroy(this, nameVal);
            BREAK
        }
        CASE(StoreVar)
        {
            Value nameVal = popStack(*stack);

            if (nameVal.type != ValueType::StringType)
            {
                destroy(this, nameVal);

                throwException(createException(ExcType::TypeError, "Variable name must be String."));
                BREAK
            }

            Value value = popStack(*stack);

            String name = ((StringData *)nameVal.p)->value;
            bool found = false;

            for (ptrdiff_t i = callStackSize-1; i >= 0; --i)
            {
                HashMap<String, Value>& vars = callStack[i].variables;

                auto pos = vars.find(name);

                if (pos != vars.end())
                {
                    destroy(this, pos->second);
                    vars.set(name, value);

                    found = true;
                    BREAK
                }
            }

            if (not found)
            {
                HashMap<String, Value>& vars = engine->getGlobalVars();

                auto pos = vars.find(name);

                if (pos != vars.end())
                {
                    destroy(this, pos->second);
                    vars.set(name, value);
                } else
                {
                    callstackEntry.variables.set(name, value);
                }
            }

            destroy(this, nameVal);
            BREAK
        }
        CASE(GetMember)
        {
            Value key = popStack(*stack);
            Value value = popStack(*stack);

            stack->append(getMember(this,
                                    value,
                                    key));

            destroy(this, value);
            destroy(this, key);
            BREAK
        }
        CASE(SetMember)
        {
            Value value = popStack(*stack);
            Value key = popStack(*stack);
            Value newValue = popStack(*stack);

            setMember(this,
                      value,
                      key,
                      newValue);

            stack->append(value);

            destroy(this, newValue);
            destroy(this, key);
            BREAK
        }

        #define ARITHMATIC_OP(iop, fop, funcName) Value aVal = popStack(*stack);\
Value bVal = popStack(*stack);\
\
if (aVal.type == ValueType::Object or aVal.type == ValueType::NativeObject or\
    bVal.type == ValueType::Object or bVal.type == ValueType::NativeObject)\
{\
    List<Value> args;\
    args.append(bVal);\
    stack->append(callMethod(this, aVal, funcName, args));\
} else if ((aVal.type == ValueType::Float or bVal.type == ValueType::Float) and (aVal.type == ValueType::Int or bVal.type == ValueType::Int))\
{\
    double a = aVal.type == ValueType::Float ? aVal.f : aVal.i;\
    double b = bVal.type == ValueType::Float ? bVal.f : bVal.i;\
    \
    stack->append(createFloat(fop));\
} else if (aVal.type == ValueType::Int and bVal.type == ValueType::Int)\
{\
    int64_t a = aVal.i;\
    int64_t b = bVal.i;\
    \
    stack->append(createInt(iop));\
} else if (aVal.type == ValueType::Float and bVal.type == ValueType::Float)\
{\
    double a = aVal.f;\
    double b = bVal.f;\
    \
    stack->append(createFloat(fop));\
} else\
{\
    throwException(createException(ExcType::TypeError, "Invalid operand types for " STR(iop)));\
}\
\
destroy(this, aVal);\
destroy(this, bVal);\
\
BREAK

        CASE(Add)
        {
            ARITHMATIC_OP(a + b, a + b, "__add__")
        }
        CASE(Subtract)
        {
            ARITHMATIC_OP(a - b, a - b, "__sub__")
        }
        CASE(Multiply)
        {
            ARITHMATIC_OP(a * b, a * b, "__mul__")
        }
        CASE(Divide)
        {
            ARITHMATIC_OP(a / b, a / b, "__div__")
        }
        CASE(Modulo)
        {
            ARITHMATIC_OP(a % b, std::fmod(a, b), "__mod__")
        }

#undef ARITHMATIC_OP

#define TYPED_OP(type_, typeMem, createFunc, op, funcName) Value aVal = popStack(*stack);\
Value bVal = popStack(*stack);\
\
if (aVal.type == ValueType::Object or aVal.type == ValueType::NativeObject)\
{\
    List<Value> args;\
    args.append(bVal);\
    stack->append(callMethod(this, aVal, funcName, args));\
} else if (aVal.type != type_ or bVal.type != type_)\
{\
    throwException(createException(ExcType::TypeError, "Invalid operand types for " STR(op)));\
} else\
{\
    stack->append(createFunc(aVal.typeMem op bVal.typeMem));\
}\
\
destroy(this, aVal);\
destroy(this, bVal);\
\
BREAK

        CASE(BoolAnd)
        {
            TYPED_OP(ValueType::Boolean, b, createBoolean, and, "__bland__")
        }
        CASE(BoolOr)
        {
            TYPED_OP(ValueType::Boolean, b, createBoolean, or, "__blor__")
        }
        CASE(BoolNot)
        {
            Value val = popStack(*stack);

            if (val.type == ValueType::Object or val.type == ValueType::NativeObject)
            {
                stack->append(callMethod(this, val, "__blnot__", List<Value>()));
            } else if (val.type == ValueType::Boolean)
            {
                stack->append(createBoolean(not val.b));
            } else
            {
                throwException(createException(ExcType::TypeError, "Invalid operand type for not. Must be Boolean."));
            }

            destroy(this, val);
            BREAK
        }
        CASE(BitAnd)
        {
            TYPED_OP(ValueType::Int, i, createInt, &, "__btand__")
        }
        CASE(BitOr)
        {
            TYPED_OP(ValueType::Int, i, createInt, |, "__btor__")
        }
        CASE(BitXOr)
        {
            TYPED_OP(ValueType::Int, i, createInt, ^, "__btxor__")
        }

#undef TYPED_OP

#define SHIFT_OP(op, funcName) Value aVal = popStack(*stack);\
Value bVal = popStack(*stack);\
\
if (aVal.type == ValueType::Object or aVal.type == ValueType::NativeObject)\
{\
    List<Value> args;\
    args.append(bVal);\
    stack->append(callMethod(this, aVal, funcName, args));\
} else if (aVal.type != ValueType::Int or bVal.type != ValueType::Int)\
{\
    throwException(createException(ExcType::TypeError, "Invalid operand types for " STR(op)));\
} else\
{\
    if (aVal.i < 0)\
    {\
        throwException(createException(ExcType::ValueError, "Operand of shift can not be negative."));\
    }\
    \
    if (bVal.i < 0)\
    {\
        throwException(createException(ExcType::ValueError, "Operand of shift can not be negative."));\
    }\
    uint64_t result = aVal.i op bVal.i;\
    stack->append(createInt(result));\
}\
\
destroy(this, aVal);\
destroy(this, bVal);\
\
BREAK

        CASE(LeftShift)
        {
            SHIFT_OP(<<, "__shl__")
        }
        CASE(RightShift)
        {
            SHIFT_OP(>>, "__shr__")
        }
        CASE(BitNot)
        {
            Value val = popStack(*stack);

            if (val.type == ValueType::Object or val.type == ValueType::NativeObject)
            {
                stack->append(callMethod(this, val, "__btnot__", List<Value>()));
            } else if (val.type == ValueType::Int)
            {
                stack->append(createInt(~val.i));
            } else
            {
                throwException(createException(ExcType::TypeError, "Invalid operand type. Must be Int."));
            }

            destroy(this, val);
            BREAK
        }

//TODO: Boolean == and !=.
        #define COMPARE_OP(op, funcName) Value aVal = popStack(*stack);\
Value bVal = popStack(*stack);\
\
if (aVal.type == ValueType::Object or aVal.type == ValueType::NativeObject or aVal.type == ValueType::StringType)\
{\
    List<Value> args;\
    args.append(bVal);\
    stack->append(callMethod(this, aVal, funcName, args));\
} else if ((aVal.type == ValueType::Float or bVal.type == ValueType::Float) and (aVal.type == ValueType::Int or bVal.type == ValueType::Int))\
{\
    double a = aVal.type == ValueType::Float ? aVal.f : aVal.i;\
    double b = bVal.type == ValueType::Float ? bVal.f : bVal.i;\
    \
    stack->append(createBoolean(a op b));\
} else if (aVal.type == ValueType::Int and bVal.type == ValueType::Int)\
{\
    int64_t a = aVal.i;\
    int64_t b = bVal.i;\
    \
    stack->append(createBoolean(a op b));\
} else if (aVal.type == ValueType::Float and bVal.type == ValueType::Float)\
{\
    double a = aVal.f;\
    double b = bVal.f;\
    \
    stack->append(createBoolean(a op b));\
} else\
{\
    stack->append(createBoolean(false));\
}\
\
destroy(this, bVal);\
destroy(this, aVal);\
\
BREAK

        CASE(Less)
        {
            COMPARE_OP(<, "__less__")
        }
        CASE(Greater)
        {
            COMPARE_OP(>, "__grtr__")
        }
        CASE(Equal)
        {
            COMPARE_OP(==, "__eq__")
        }
        CASE(NotEqual)
        {
            COMPARE_OP(!=, "__neq__")
        }
        CASE(LessEqual)
        {
            COMPARE_OP(<=, "__leq__")
        }
        CASE(GreaterEqual)
        {
            COMPARE_OP(>=, "__geq__")
        }

#undef COMPARE_OP

        CASE(Call)
        {
            Value val = popStack(*stack);
            Value argCountVal = popStack(*stack);

            if (argCountVal.type != ValueType::Int)
            {
                throwException(createException(ExcType::TypeError, "Arguments count must be an integer."));
            }

            int64_t argCount = argCountVal.i;

            if (argCount < 0)
            {
                throwException(createException(ExcType::ValueError, "Argument count must not be negative."));
            }

            List<Value> args;

            for (int64_t i = 0; i < argCount; ++i)
            {
                args.append(popStack(*stack));
            }

            stack->append(call(this, val, args));

            for (auto arg : args)
            {
                destroy(this, arg);
            }

            destroy(this, argCountVal);
            destroy(this, val);
            BREAK
        }
        CASE(Return)
        {
            return popStack(*stack);
        }
        CASE(GetArgCount)
        {
            stack->append(createInt(args.getCount()));
            BREAK
        }
        CASE(GetArg)
        {
            Value val = popStack(*stack);

            size_t index = toIndex(this, val);

            if (index >= args.getCount())
            {
                throwException(createException(ExcType::IndexError, "Arg index is out of bounds."));
            }

            stack->append(createCopy(this, args[index]));

            destroy(this, val);
            BREAK
        }
        CASE(JumpIf)
        {
            Value val = popStack(*stack);

            if (val.type != ValueType::Boolean)
            {
                throwException(createException(ExcType::TypeError, "Jump condition is not a Boolean."));
            }

            int32_t success = bytecode.getInt32(offset);
            offset += 4;

            int32_t failure = bytecode.getInt32(offset);
            offset += 4;

            if (val.b)
            {
                offset += success;
            } else
            {
                offset += failure;
            }

            destroy(this, val);
            BREAK
        }
        CASE(Jump)
        {
            int32_t by = bytecode.getInt32(offset);
            offset += 4;

            offset += by;
            BREAK
        }
        CASE(Try)
        {
            int32_t by = bytecode.getInt32(offset);
            offset += 4;

            callstackEntry.stacks.append(List<Value>());
            callstackEntry.catchBlocks.append(offset + by);

            stack = &callstackEntry.stacks[callstackEntry.stacks.getCount()-1];
            BREAK
        }
        CASE(EndTry)
        {
            if (callstackEntry.stacks.getCount() > 1)
            {
                callstackEntry.catchBlocks.remove(callstackEntry.catchBlocks.getCount()-1);
                callstackEntry.stacks.remove(callstackEntry.stacks.getCount()-1);

                stack = &callstackEntry.stacks[callstackEntry.stacks.getCount()-1];
            } else
            {
                THROW(CallstackBoundsException)
            }
            BREAK
        }
        CASE(Throw)
        {
            throwException(popStack(*stack));
            BREAK
        }
        CASE(GetException)
        {
            stack->append(createCopy(this, exception));
            BREAK
        }
    END

    return createNil();
}

Value Context::run(const Bytecode& bytecode, List<Value> args)
{
    if (callStackSize == SCRIPTING_MAX_CALLSTACK_SIZE)
    {
        THROW(CallstackBoundsException)
    }

    callStack[callStackSize++] = CallstackEntry(bytecode);
    CallstackEntry& callstackEntry = callStack[callStackSize-1];

    callstackEntry.stacks.append(List<Value>());

    //This may not be safe.
    if (!setjmp(jumpBuf))
    {
        Value result = _run(bytecode, args);

        popCallstack();

        return result;
    } else
    {
        CallstackEntry *entry = nullptr;

        for (size_t i = 0; i < callStackSize; ++i)
        {
            List<size_t> catchBlocks = callStack[i].catchBlocks;

            if (catchBlocks.getCount() > 0)
            {
                entry = &callStack[i];
                break;

            }
        }

        if (entry != nullptr)
        {
            size_t offset = entry->catchBlocks[entry->catchBlocks.getCount()-1];

            entry->catchBlocks.remove(entry->catchBlocks.getCount()-1);

            List<Value>& stack = entry->stacks[entry->stacks.getCount()-1];

            for (auto value : stack)
            {
                destroy(this, value);
            }

            entry->stacks.remove(entry->stacks.getCount()-1);
            entry->offset = offset;

            Value result = _run(entry->bytecode, List<Value>());

            destroy(this, exception);
            exception = createNil();

            return result;
        }

        Value exc = exception;

        exception = createNil();

        THROW(UnhandledExcException, this, exc);
    }
}

void Context::popCallstack()
{
    if (callStackSize == 0)
    {
        THROW(BoundsException);
    }

    CallstackEntry& callstackEntry = callStack[callStackSize-1];

    for (auto stack : callstackEntry.stacks)
    {
        for (auto value : stack)
        {
            destroy(this, value);
        }
    }

    callstackEntry.stacks.clear();

    for (auto kv : callstackEntry.variables)
    {
        destroy(this, kv.second);
    }

    callstackEntry.variables.clear();

    --callStackSize;
}

void Context::throwException(Value exc)
{
    if (callStackSize > 0)
    {
        destroy(this, exception);
        exception = exc;

        longjmp(jumpBuf, 1);
    } else
    {
        THROW(UnhandledExcException, this, exc);
    }
}

Value Context::popStack(List<Value>& stack)
{
    if (stack.getCount() == 0)
    {
        THROW(StackBoundsException);
    } else
    {
        Value result = stack[stack.getCount() - 1];
        stack.remove(stack.getCount() - 1);

        return result;
    }
}

UnhandledExcException::UnhandledExcException(const char *file_,
                                             size_t line_,
                                             const char *function_,
                                             Context *ctx_,
                                             const Value& exception_)
 : ExecutionException(file_, line_, function_),
   ctx(ctx_),
   exception(exception_) {}

UnhandledExcException::UnhandledExcException(const UnhandledExcException& other)
 : ExecutionException(other.getFile(),
                      other.getLine(),
                      other.getFunction()),
   ctx(other.ctx),
   exception(createCopy(ctx, other.exception)) {}

UnhandledExcException::~UnhandledExcException()
{
    destroy(ctx, exception);
}

size_t toIndex(Context *ctx, const Value& value)
{
    if (value.type == ValueType::Int)
    {
        if (value.i < 0)
        {
            ctx->throwException(createException(ExcType::ValueError, "Index should not be below zero."));
        } else
        {
            return value.i;
        }
    } else if (value.type == ValueType::Float)
    {
        if ((size_t)value.f < 0)
        {
            ctx->throwException(createException(ExcType::ValueError, "Index should not be below zero."));
        } else
        {
            return (size_t)value.f;
        }
    } else
    {
        ctx->throwException(createException(ExcType::TypeError, "Invalid index type."));
    }

    SDL_assert_release(false);
}

static Value strEqual(Context *ctx, const List<Value>& args)
{
    if (args.getCount() != 2)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::__eq__ takes two arguments."));
    }

    if (args[0].type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::__eq__ takes a string as the first argument."));
    }

    if (args[1].type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::__eq__ takes a string as the second argument."));
    }

    return createBoolean(((StringData *)args[0].p)->value == ((StringData *)args[1].p)->value);
}

static Value strNotEqual(Context *ctx, const List<Value>& args)
{
    if (args.getCount() != 2)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::__neq__ takes two arguments."));
    }

    if (args[0].type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::__neq__ takes a string as the first argument."));
    }

    if (args[1].type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::__neq__ takes a string as the second argument."));
    }

    return createBoolean(((StringData *)args[0].p)->value != ((StringData *)args[1].p)->value);
}

static Value strAppend(Context *ctx, const List<Value>& args)
{
    if (args.getCount() != 2)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::append takes two arguments."));
    }

    if (args[0].type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::append takes a string as the first argument."));
    }

    if (args[1].type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::append takes a string as the second argument."));
    }

    return createString(((StringData *)args[0].p)->value.append(((StringData *)args[1].p)->value));
}

static Value strInsert(Context *ctx, const List<Value>& args)
{
    if (args.getCount() != 3)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::insert takes three arguments."));
    }

    if (args[0].type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::insert takes a string as the first argument."));
    }

    if (args[1].type != ValueType::Int or args[1].type != ValueType::Float)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::insert takes a integer or float as the second argument."));
    }

    if (args[2].type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::insert takes a string as the third argument."));
    }

    String str = ((StringData *)args[0].p)->value;
    size_t start = toIndex(ctx, args[1]);
    String toInsert = ((StringData *)args[2].p)->value;

    if (start > str.getLength())
    {
        ctx->throwException(createException(ExcType::ValueError, "Invalid start for string insertion."));
    }

    str.insert(start, toInsert);
    return createNil();
}

static Value strRemove(Context *ctx, const List<Value>& args)
{
    if (args.getCount() != 3)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::remove takes three arguments."));
    }

    if (args[0].type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::remove takes a string as the first argument."));
    }

    if (args[1].type != ValueType::Int and args[1].type != ValueType::Float)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::remove takes a integer or float as the second argument."));
    }

    if (args[2].type != ValueType::Int and args[2].type != ValueType::Float)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::remove takes a integer or float as the third argument."));
    }

    String str = ((StringData *)args[0].p)->value;
    size_t start = toIndex(ctx, args[1]);
    size_t count = toIndex(ctx, args[2]);

    if (start+count > str.getLength())
    {
        ctx->throwException(createException(ExcType::ValueError, "Invalid start and count for string removal."));
    }

    str.remove(start, count);
    return createNil();
}

static Value strClear(Context *ctx, const List<Value>& args)
{
    if (args.getCount() != 1)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::clear takes one argument."));
    }

    if (args[0].type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::clear takes a string as the first argument."));
    }

    ((StringData *)args[0].p)->value.clear();

    return createNil();
}

static Value strResize(Context *ctx, const List<Value>& args)
{
    if (args.getCount() != 2)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::resize takes two arguments."));
    }

    if (args[0].type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::resize takes a string as the first argument."));
    }

    if (args[1].type != ValueType::Int and args[1].type != ValueType::Float)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::resize takes a integer or float as the second argument."));
    }

    ((StringData *)args[0].p)->value.resize(toIndex(ctx, args[1]));

    return createNil();
}

static Value strFind(Context *ctx, const List<Value>& args)
{
    if (args.getCount() != 2)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::find takes two arguments."));
    }

    if (args[0].type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::find takes a string as the first argument."));
    }

    if (args[1].type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::find takes a string as the second argument."));
    }

    return createInt(((StringData *)args[0].p)->value.find(((StringData *)args[1].p)->value));
}

static Value strSubStr(Context *ctx, const List<Value>& args)
{
    if (args.getCount() != 3)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::subStr takes three arguments."));
    }

    if (args[0].type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::subStr takes a string as the first argument."));
    }

    if (args[1].type != ValueType::Int and args[1].type != ValueType::Float)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::subStr takes a integer or float as the second argument."));
    }

    if (args[2].type != ValueType::Int and args[2].type != ValueType::Float)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::subStr takes a integer or float as the third argument."));
    }

    String str = ((StringData *)args[0].p)->value;
    size_t offset = toIndex(ctx, args[1]);
    size_t length = toIndex(ctx, args[2]);

    if (offset+length > str.getLength())
    {
        ctx->throwException(createException(ExcType::ValueError, "Invalid start or count for String::subStr"));
    }

    return createString(str.subStr(offset, length));
}

static Value strCopy(Context *ctx, const List<Value>& args)
{
    if (args.getCount() != 1)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::copy takes one argument."));
    }

    if (args[0].type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::copy takes a string as the first argument."));
    }

    return createString(((StringData *)args[0].p)->value.copy());
}

static Value strCopyFrom(Context *ctx, const List<Value>& args)
{
    if (args.getCount() != 2)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::copyFrom takes two arguments."));
    }

    if (args[0].type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::copyFrom takes a string as the first argument."));
    }

    if (args[1].type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::copyFrom takes a string as the second argument."));
    }

    ((StringData *)args[0].p)->value.copyFrom(((StringData *)args[1].p)->value);

    return createNil();
}

static Value strFormat(Context *ctx, const List<Value>& args)
{
    if (args.getCount() < 1)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::format takes at least one argument."));
    }

    if (args[0].type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::format takes a string as the first argument."));
    }

    String formatStr = ((StringData *)args[0].p)->value;
    String result;
    size_t argIndex = 1;

    for (size_t i = 0; i < formatStr.getLength(); ++i)
    {
        char c = formatStr[i];

        if (c == '%')
        {
            if (i+1 == formatStr.getLength())
            {
                ctx->throwException(createException(ExcType::ValueError, "Unable to get the rest of the format thingy."));
            }

            char type = formatStr[++i];

            if (type == '%')
            {
                result.append(c);
            } else if (type == 'v')
            {
                if (argIndex >= args.getCount())
                {
                    ctx->throwException(createException(ExcType::ValueError, "Unable to get argument for format thingy."));
                }

                Value v = args[argIndex++];

                switch (v.type)
                {
                case ValueType::Int:
                {
                    result.append(String::formatValue((long long int)v.i));
                    break;
                }
                case ValueType::Float:
                {
                    result.append(String::format("%.2f", v.f));
                    break;
                }
                case ValueType::Boolean:
                {
                    result.append(v.b ? "true" : "false");
                    break;
                }
                case ValueType::Nil:
                {
                    result.append("nil");
                    break;
                }
                case ValueType::Function:
                {
                    result.append("<function>");
                    break;
                }
                case ValueType::Object:
                {
                    result.append("<object>");
                    break;
                }
                case ValueType::StringType:
                {
                    result.append(((StringData *)v.p)->value);
                    break;
                }
                case ValueType::NativeFunction:
                {
                    result.append("<native function>");
                    break;
                }
                case ValueType::NativeObject:
                {
                    result.append("<native object>");
                    break;
                }
                case ValueType::Exception:
                {
                    result.append("<exception>");
                    break;
                }
                }
            } else
            {
                result.append(c);
                --i;
            }
        } else
        {
            result.append(c);
        }
    }

    return createString(result);
}

Value getMember(Context *ctx, const Value& val, const Value& key)
{
    switch (val.type)
    {
    case ValueType::Object:
    {
        if (key.type != ValueType::StringType)
        {
            ctx->throwException(createException(ExcType::TypeError, "Member name must be String."));
        }

        const HashMap<String, Value>& members = ((ObjectData *)val.p)->members;

        String keyStr = ((StringData *)key.p)->value;
        auto pos = members.find(keyStr);

        if (pos == members.end())
        {
            ctx->throwException(createException(ExcType::KeyError, String::format("Unknown member: '%s'", keyStr.getData())));
        }

        return createCopy(ctx, pos->second);
    }
    case ValueType::StringType:
    {
        if (key.type == ValueType::Int or key.type == ValueType::Float)
        {
            String str = ((StringData *)val.p)->value;

            size_t index = toIndex(ctx, key);

            if (index >= str.getLength())
            {
                ctx->throwException(createException(ExcType::IndexError, "String index is out of bounds."));
            }

            return createString(String(str[index]));
        } else if (key.type == ValueType::StringType)
        {
            String keyStr = ((StringData *)key.p)->value;

            if (keyStr == "__eq__")
            {
                return createNativeFunction(strEqual);
            } else if (keyStr == "__neq__")
            {
                return createNativeFunction(strNotEqual);
            } else if (keyStr == "length")
            {
                return createInt(((StringData *)val.p)->value.getLength());
            } else if (keyStr == "append")
            {
                return createNativeFunction(strAppend);
            } else if (keyStr == "insert")
            {
                return createNativeFunction(strInsert);
            } else if (keyStr == "remove")
            {
                return createNativeFunction(strRemove);
            } else if (keyStr == "clear")
            {
                return createNativeFunction(strClear);
            } else if (keyStr == "resize")
            {
                return createNativeFunction(strResize);
            } else if (keyStr == "find")
            {
                return createNativeFunction(strFind);
            } else if (keyStr == "subStr")
            {
                return createNativeFunction(strSubStr);
            } else if (keyStr == "copy")
            {
                return createNativeFunction(strCopy);
            } else if (keyStr == "copyFrom")
            {
                return createNativeFunction(strCopyFrom);
            } else if (keyStr == "format")
            {
                return createNativeFunction(strFormat);
            } else
            {
                ctx->throwException(createException(ExcType::KeyError, "Unknown member for String."));
            }
        } else
        {
            ctx->throwException(createException(ExcType::KeyError, "Unknown member for String."));
        }
    }
    case ValueType::NativeObject:
    {
        NativeObjectData *obj = (NativeObjectData *)val.p;
        return obj->funcs.getMember(ctx, val, key);
    }
    case ValueType::Exception:
    {
        if (key.type != ValueType::StringType)
        {
            ctx->throwException(createException(ExcType::TypeError, "Member name must be String."));
        }

        String name = ((StringData *)key.p)->value;
        ExceptionData *exc = (ExceptionData *)val.p;

        if (name == "type")
        {
            switch (exc->type)
            {
            case ExcType::ValueError:
            {
                return createString("value");
            }
            case ExcType::TypeError:
            {
                return createString("type");
            }
            case ExcType::KeyError:
            {
                return createString("key");
            }
            case ExcType::IndexError:
            {
                return createString("index");
            }
            }
        } else if (name == "error")
        {
            return createString(exc->error);
        } else
        {
            ctx->throwException(createException(ExcType::KeyError, "Unknown member for Exception."));
        }
    }
    default:
    {
        ctx->throwException(createException(ExcType::TypeError, "Type does not have members."));
    }
    }

    SDL_assert_release(false);
}

void setMember(Context *ctx, const Value& dest, const Value& key, const Value& value)
{
    switch (dest.type)
    {
    case ValueType::Object:
    {
        if (key.type != ValueType::StringType)
        {
            ctx->throwException(createException(ExcType::TypeError, "Member names must be String."));
        }

        HashMap<String, Value>& members = ((ObjectData *)dest.p)->members;

        String name = ((StringData *)key.p)->value;

        auto pos = members.find(name);
        if (pos != members.end())
        {
            destroy(ctx, pos->second);
        }

        members.set(name, createCopy(ctx, value));
        return;
    }
    case ValueType::StringType:
    {
        if (value.type != ValueType::StringType)
        {
            ctx->throwException(createException(ExcType::TypeError, "A string's character can only be set as a String."));
        } else
        {
            if (((StringData *)value.p)->value.getLength() != 1)
            {
                ctx->throwException(createException(ExcType::ValueError, "String must of length 1."));
            }
        }

        String str = ((StringData *)dest.p)->value;

        size_t index = toIndex(ctx, key);

        if (index >= str.getLength())
        {
            ctx->throwException(createException(ExcType::IndexError, "String index is out of bounds."));
        }

        str[index] = ((StringData *)value.p)->value[0];
        return;
    }
    case ValueType::NativeObject:
    {
        NativeObjectData *obj = (NativeObjectData *)dest.p;
        obj->funcs.setMember(ctx, dest, key, value);
        return;
    }
    default:
    {
        ctx->throwException(createException(ExcType::TypeError, "Type does not have members."));
    }
    }

    SDL_assert_release(false);
}

Value call(Context *ctx, const Value& value, const List<Value>& args)
{
    switch (value.type)
    {
    case ValueType::Function:
    {
        return ctx->run(((FunctionData *)value.p)->bytecode, args);
    }
    case ValueType::NativeFunction:
    {
        return value.func(ctx, args);
    }
    case ValueType::Object:
    case ValueType::NativeObject:
    {
        return callMethod(ctx, value, "__call__", args);
    }
    default:
    {
        ctx->throwException(createException(ExcType::TypeError, "Type is not callable."));
    }
    }

    SDL_assert_release(false);
}

Value callMethod(Context *ctx, const Value& obj, const String& methName, const List<Value>& args)
{
    List<Value> args_;

    args_.append(obj);
    args_.append(args);

    Value nameHead = createString(methName);

    Value funcHead = getMember(ctx, obj, nameHead);

    Value result = call(ctx, funcHead, args_);

    destroy(ctx, funcHead);
    destroy(ctx, nameHead);

    return result;
}

bool isInstance(Context *ctx, const Value& obj, const Value& type)
{
    if (obj.type != type.type)
    {
        return false;
    }

    if (obj.type == ValueType::NativeObject and type.type == ValueType::NativeObject)
    {
        return ((NativeObjectData *)obj.p)->typeID == ((NativeObjectData *)type.p)->typeID;
    } else if (obj.type == ValueType::Object)
    {
        HashMap<String, Value> objMembers = ((ObjectData *)obj.p)->members;
        HashMap<String, Value> typeMembers = ((ObjectData *)type.p)->members;

        auto pos1 = objMembers.find("__classTypeID__");
        auto pos2 = typeMembers.find("__typeID__");

        if (pos1 == objMembers.end() or pos2 == typeMembers.end())
        {
            return false;
        }

        const Value& id1 = pos1->second;
        const Value& id2 = pos2->second;

        if (id1.type != ValueType::Int or id2.type != ValueType::Int)
        {
            ctx->throwException(createException(ExcType::TypeError, "Type IDs must be integers."));
        }

        return id1.i == id2.i;
    } else
    {
        return false;
    }
}
}

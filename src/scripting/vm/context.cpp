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
            for (size_t i = 0; i < stack.size; ++i)
            {
                destroy(this, stack.values[i]);
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
    Stack *stack = &callstackEntry.stacks[0];

    BEGIN
        CASE(PushInt)
        {
            if (stack->size == SCRIPTING_MAX_STACK_SIZE)
            {
                THROW(StackBoundsException);
            }
            stack->values[stack->size++] = createInt(bytecode.getInt64(offset));
            offset += 8;
            BREAK
        }
        CASE(PushFloat)
        {
            if (stack->size == SCRIPTING_MAX_STACK_SIZE)
            {
                THROW(StackBoundsException);
            }
            stack->values[stack->size++] = createFloat(bytecode.getDouble(offset));
            offset += 8;
            BREAK
        }
        CASE(PushBoolean)
        {
            if (stack->size == SCRIPTING_MAX_STACK_SIZE)
            {
                THROW(StackBoundsException);
            }
            stack->values[stack->size++] = createBoolean(bytecode.getBoolean(offset));
            offset += 1;
            BREAK
        }
        CASE(PushNil)
        {
            if (stack->size == SCRIPTING_MAX_STACK_SIZE)
            {
                THROW(StackBoundsException);
            }
            stack->values[stack->size++] = createNil();
            BREAK
        }
        CASE(PushFunc)
        {
            if (stack->size == SCRIPTING_MAX_STACK_SIZE)
            {
                THROW(StackBoundsException);
            }

            size_t size = bytecode.getUInt32(offset);
            offset += 4;

            //In {} because so destructors are ran when using a computed goto.
            {
                ResizableData data = bytecode.getData(offset, size);
                offset += size;

                Bytecode code(data);
                code.strings = bytecode.strings;

                stack->values[stack->size++] = createFunction(code);
            }
            BREAK
        }
        CASE(PushObject)
        {
            if (stack->size == SCRIPTING_MAX_STACK_SIZE)
            {
                THROW(StackBoundsException);
            }

            stack->values[stack->size++] = createObject();
            BREAK
        }
        CASE(PushString)
        {
            if (stack->size == SCRIPTING_MAX_STACK_SIZE)
            {
                THROW(StackBoundsException);
            }

            size_t index = bytecode.getUInt32(offset);
            offset += 4;

            if (index >= bytecode.strings.getCount())
            {
                stack->values[stack->size++] = createString("");
            } else
            {
                stack->values[stack->size++] = createString(bytecode.strings[index]);
            }
            BREAK
        }
        CASE(PushException)
        {
            if (stack->size == SCRIPTING_MAX_STACK_SIZE)
            {
                THROW(StackBoundsException);
            }

            ExcType type = (ExcType)bytecode.getUInt8(offset);
            offset += 1;

            size_t length = bytecode.getUInt32(offset);
            offset += 4;

            //In {} because so destructors are ran when using a computed goto.
            {
                ResizableData data = bytecode.getData(offset, length);
                offset += length;

                stack->values[stack->size++] = createException(type, Str(length, (const char *)data.getData()));
            }
            BREAK
        }
        CASE(StackPop)
        {
            destroy(this, popStack(*stack));
            BREAK
        }
        CASE(StackDup)
        {
            if (stack->size == SCRIPTING_MAX_STACK_SIZE)
            {
                THROW(StackBoundsException);
            }

            Value value = popStack(*stack);

            stack->values[stack->size++] = createCopy(this, value);
            stack->values[stack->size++] = value;
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

            //In {} because so destructors are ran when using a computed goto.
            {
                Str name = nameVal.getStr();

                bool found = false;

                for (ptrdiff_t i = 0; i < (ptrdiff_t)callStackSize; ++i)
                {
                    HashMap<Str, Value>& vars = callStack[i].variables;

                    auto pos = vars.find(name);
                    if (pos != vars.end())
                    {
                        stack->values[stack->size++] = createCopy(this, pos->second);
                        found = true;
                        BREAK
                    }
                }

                if (not found)
                {
                    HashMap<Str, Value>& vars = engine->getGlobalVars();

                    auto pos = vars.find(name);

                    if (pos != vars.end())
                    {
                        stack->values[stack->size++] = createCopy(this, pos->second);
                    } else
                    {
                        throwException(createException(ExcType::KeyError, Str::format("No such variable '%s'.", name.getData())));
                    }
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

            //In {} because so destructors are ran when using a computed goto.
            {
                Str name = nameVal.getStr();
                bool found = false;

                for (ptrdiff_t i = callStackSize-1; i >= 0; --i)
                {
                    HashMap<Str, Value>& vars = callStack[i].variables;

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
                    HashMap<Str, Value>& vars = engine->getGlobalVars();

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
            }
            BREAK
        }
        CASE(GetMember)
        {
            Value key = popStack(*stack);
            Value value = popStack(*stack);

            stack->values[stack->size++] = getMember(this, value, key);

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

            stack->values[stack->size++] = value;

            destroy(this, newValue);
            destroy(this, key);
            BREAK
        }

        #define ARITHMATIC_OP(iop, fop, funcName) Value aVal = popStack(*stack);\
Value bVal = popStack(*stack);\
\
if (aVal.type == ValueType::Object or\
    aVal.type == ValueType::NativeObject or\
    aVal.type == ValueType::StringType)\
{\
    List<Value> args;\
    args.append(bVal);\
    stack->values[stack->size++] = callMethod(this, aVal, funcName, args);\
} else if ((aVal.type == ValueType::Float or bVal.type == ValueType::Float) and (aVal.type == ValueType::Int or bVal.type == ValueType::Int))\
{\
    double a = aVal.type == ValueType::Float ? aVal.f : aVal.i;\
    double b = bVal.type == ValueType::Float ? bVal.f : bVal.i;\
    \
    stack->values[stack->size++] = createFloat(fop);\
} else if (aVal.type == ValueType::Int and bVal.type == ValueType::Int)\
{\
    int64_t a = aVal.i;\
    int64_t b = bVal.i;\
    \
    stack->values[stack->size++] = createInt(iop);\
} else if (aVal.type == ValueType::Float and bVal.type == ValueType::Float)\
{\
    double a = aVal.f;\
    double b = bVal.f;\
    \
    stack->values[stack->size++] = createFloat(fop);\
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
    stack->values[stack->size++] = callMethod(this, aVal, funcName, args);\
} else if (aVal.type != type_ or bVal.type != type_)\
{\
    throwException(createException(ExcType::TypeError, "Invalid operand types for " STR(op)));\
} else\
{\
    stack->values[stack->size++] = createFunc(aVal.typeMem op bVal.typeMem);\
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
                stack->values[stack->size++] = callMethod(this, val, "__blnot__", List<Value>());
            } else if (val.type == ValueType::Boolean)
            {
                stack->values[stack->size++] = createBoolean(not val.b);
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
    stack->values[stack->size++] = callMethod(this, aVal, funcName, args);\
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
    stack->values[stack->size++] = createInt(result);\
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
                stack->values[stack->size++] = callMethod(this, val, "__btnot__", List<Value>());
            } else if (val.type == ValueType::Int)
            {
                stack->values[stack->size++] = createInt(~val.i);
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
if (aVal.type == ValueType::Object or\
    aVal.type == ValueType::NativeObject or\
    aVal.type == ValueType::StringType)\
{\
    List<Value> args;\
    args.append(bVal);\
    stack->values[stack->size++] = callMethod(this, aVal, funcName, args);\
} else if ((aVal.type == ValueType::Float or bVal.type == ValueType::Float) and (aVal.type == ValueType::Int or bVal.type == ValueType::Int))\
{\
    double a = aVal.type == ValueType::Float ? aVal.f : aVal.i;\
    double b = bVal.type == ValueType::Float ? bVal.f : bVal.i;\
    \
    stack->values[stack->size++] = createBoolean(a op b);\
} else if (aVal.type == ValueType::Int and bVal.type == ValueType::Int)\
{\
    int64_t a = aVal.i;\
    int64_t b = bVal.i;\
    \
    stack->values[stack->size++] = createBoolean(a op b);\
} else if (aVal.type == ValueType::Float and bVal.type == ValueType::Float)\
{\
    double a = aVal.f;\
    double b = bVal.f;\
    \
    stack->values[stack->size++] = createBoolean(a op b);\
} else\
{\
    stack->values[stack->size++] = createBoolean(false);\
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

            //In {} because so destructors are ran when using a computed goto.
            {
                List<Value> args;

                for (int64_t i = 0; i < argCount; ++i)
                {
                    args.append(popStack(*stack));
                }

                stack->values[stack->size++] = call(this, val, args);

                for (auto arg : args)
                {
                    destroy(this, arg);
                }
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
            stack->values[stack->size++] = createInt(args.getCount());
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

            stack->values[stack->size++] = createCopy(this, args[index]);

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

            callstackEntry.stacks.append(Stack());
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
            if (stack->size == SCRIPTING_MAX_STACK_SIZE)
            {
                THROW(StackBoundsException);
            }
            stack->values[stack->size++] = createCopy(this, exception);
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
    callstackEntry.stacks.append(Stack());

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

            Stack& stack = entry->stacks[entry->stacks.getCount()-1];

            for (size_t i = 0; i < stack.size; ++i)
            {
                destroy(this, stack.values[i]);
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
        for (size_t i = 0; i < stack.size; ++i)
        {
            destroy(this, stack.values[i]);
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

Value Context::popStack(Stack& stack)
{
    if (stack.size == 0)
    {
        THROW(StackBoundsException);
    } else
    {
        return stack.values[--stack.size];
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

    return createBoolean(args[0].getStr() == args[1].getStr());
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

    return createBoolean(args[0].getStr() != args[1].getStr());
}

static Value strAdd(Context *ctx, const List<Value>& args)
{
    if (args.getCount() != 2)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::__add__ takes two arguments."));
    }

    if (args[0].type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::__add__ takes a string as the first argument."));
    }

    if (args[1].type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::__add__ takes a string as the second argument."));
    }

    return createString(args[0].getStr() + args[1].getStr());
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

    return createInt(args[0].getStr().find(args[1].getStr()));
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

    Str str = args[0].getStr();
    size_t offset = toIndex(ctx, args[1]);
    size_t length = toIndex(ctx, args[2]);

    if (offset+length > str.getLength())
    {
        ctx->throwException(createException(ExcType::ValueError, "Invalid start or count for String::subStr"));
    }

    return createString(str.subStr(offset, length));
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

    Str formatStr = args[0].getStr();
    Str result;
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
                result = result + c;
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
                    result = result + Str::formatValue((long long int)v.i);
                    break;
                }
                case ValueType::Float:
                {
                    result = result + Str::format("%.2f", v.f);
                    break;
                }
                case ValueType::Boolean:
                {
                    result = result + (v.b ? "true" : "false");
                    break;
                }
                case ValueType::Nil:
                {
                    result = result + "nil";
                    break;
                }
                case ValueType::Function:
                {
                    result = result + "<function>";
                    break;
                }
                case ValueType::Object:
                {
                    result = result + "<object>";
                    break;
                }
                case ValueType::StringType:
                {
                    result = result + v.getStr();
                    break;
                }
                case ValueType::NativeFunction:
                {
                    result = result + "<native function>";
                    break;
                }
                case ValueType::NativeObject:
                {
                    result = result + "<native object>";
                    break;
                }
                case ValueType::Exception:
                {
                    result = result + "<exception>";
                    break;
                }
                }
            } else
            {
                result = result + c;
                --i;
            }
        } else
        {
            result = result + c;
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

        const HashMap<Str, Value>& members = ((ObjectData *)val.p)->members;

        auto pos = members.find(key.getStr());

        if (pos == members.end())
        {
            ctx->throwException(createException(ExcType::KeyError, Str::format("Unknown member: '%s'", key.getStr().getData())));
        }

        return createCopy(ctx, pos->second);
    }
    case ValueType::StringType:
    {
        if (key.type == ValueType::Int or key.type == ValueType::Float)
        {
            size_t index = toIndex(ctx, key);

            if (index >= val.getStr().getLength())
            {
                ctx->throwException(createException(ExcType::IndexError, "String index is out of bounds."));
            }

            return createString(Str(val.getStr()[index]));
        } else if (key.type == ValueType::StringType)
        {
            Str keyStr = key.getStr();

            if (keyStr.equals("__eq__", CPL_STR_HASH("__eq__")))
            {
                return createNativeFunction(strEqual);
            } else if (keyStr.equals("__neq__", CPL_STR_HASH("__neq__")))
            {
                return createNativeFunction(strNotEqual);
            } else if (keyStr.equals("length", CPL_STR_HASH("length")))
            {
                return createInt(val.getStr().getLength());
            } else if (keyStr.equals("__add__", CPL_STR_HASH("__add__")))
            {
                return createNativeFunction(strAdd);
            } else if (keyStr.equals("find", CPL_STR_HASH("find")))
            {
                return createNativeFunction(strFind);
            } else if (keyStr.equals("subStr", CPL_STR_HASH("subStr")))
            {
                return createNativeFunction(strSubStr);
            } else if (keyStr.equals("format", CPL_STR_HASH("format")))
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

        Str name = key.getStr();
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

        HashMap<Str, Value>& members = ((ObjectData *)dest.p)->members;

        Str name = key.getStr();

        auto pos = members.find(name);
        if (pos != members.end())
        {
            destroy(ctx, pos->second);
        }

        members.set(name, createCopy(ctx, value));
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
        ctx->throwException(createException(ExcType::TypeError, "Type does not have members or writable members."));
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

Value callMethod(Context *ctx, const Value& obj, const Str& methName, const List<Value>& args)
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
        HashMap<Str, Value> objMembers = ((ObjectData *)obj.p)->members;
        HashMap<Str, Value> typeMembers = ((ObjectData *)type.p)->members;

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

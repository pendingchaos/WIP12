#include "scripting/vm/context.h"

#include "scripting/vm/engine.h"
#include <cmath>
#include <iostream> //TODO: Get rid of this.
#include <cassert>

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

        for (size_t j = 0; j < entry.variables.getEntryCount(); ++j)
        {
            destroy(this, entry.variables.getValue(j));
        }

        entry.variables.clear();
    }

    callStackSize = 0;
}

Value *Context::_run(const Bytecode& bytecode, List<Value *> args)
{
    CallstackEntry& callstackEntry = callStack[callStackSize-1];
    size_t& offset = callstackEntry.offset;
    List<Value *> *stack = &callstackEntry.stacks[0];

    while (offset < bytecode.data.getSize())
    {
        Opcode opcode = bytecode.getOpcode(offset++);

        switch (opcode)
        {
        case Opcode::PushInt:
        {
            stack->append(createInt(bytecode.getInt64(offset)));
            offset += 8;
            break;
        }
        case Opcode::PushFloat:
        {
            stack->append(createFloat(bytecode.getDouble(offset)));
            offset += 8;
            break;
        }
        case Opcode::PushBoolean:
        {
            stack->append(createBoolean(bytecode.getBoolean(offset)));
            offset += 1;
            break;
        }
        case Opcode::PushNil:
        {
            stack->append(createNil());
            break;
        }
        case Opcode::PushFunc:
        {
            size_t size = bytecode.getUInt32(offset);
            offset += 4;

            ResizableData data = bytecode.getData(offset, size);
            offset += size;

            Bytecode code(data);

            stack->append(createFunction(code));
            break;
        }
        case Opcode::PushObject:
        {
            stack->append(createObject());
            break;
        }
        case Opcode::PushString:
        {
            size_t length = bytecode.getUInt32(offset);
            offset += 4;

            ResizableData data = bytecode.getData(offset, length);
            offset += length;

            stack->append(createString(String(length, (const char *)data.getData())));
            break;
        }
        case Opcode::PushException:
        {
            ExcType type = (ExcType)bytecode.getUInt8(offset);
            offset += 1;

            size_t length = bytecode.getUInt32(offset);
            offset += 4;

            ResizableData data = bytecode.getData(offset, length);
            offset += length;

            stack->append(createException(type, String(length, (const char *)data.getData())));
            break;
        }
        case Opcode::StackPop:
        {
            if (stack->getCount() == 0)
            {
                THROW(StackBoundsException);
            }

            destroy(this, (*stack)[stack->getCount()-1]);

            stack->remove(stack->getCount()-1);
            break;
        }
        case Opcode::LoadVar:
        {
            Value *nameHead = popStack(*stack);

            if (nameHead->type != ValueType::StringType)
            {
                destroy(this, nameHead);

                throwException(createException(ExcType::TypeError, "Variable name must be String."));
                break;
            }

            String name = ((StringValue *)nameHead)->value;

            bool found = false;

            for (ptrdiff_t i = 0; i < (ptrdiff_t)callStackSize; ++i)
            {
                HashMap<String, Value *>& vars = callStack[i].variables;

                int entry = vars.findEntry(name);

                if (entry != -1)
                {
                    stack->append(createCopy(this, vars.getValue(entry)));
                    found = true;
                    break;
                }
            }

            if (not found)
            {
                HashMap<String, Value *>& vars = engine->getGlobalVars();

                int entry = vars.findEntry(name);

                if (entry != -1)
                {
                    stack->append(createCopy(this, vars.getValue(entry)));
                } else
                {
                    throwException(createException(ExcType::KeyError, String::format("No such variable '%s'.", name.getData())));
                }
            }

            destroy(this, nameHead);
            break;
        }
        case Opcode::StoreVar:
        {
            Value *nameHead = popStack(*stack);

            if (nameHead->type != ValueType::StringType)
            {
                destroy(this, nameHead);

                throwException(createException(ExcType::TypeError, "Variable name must be String."));
                break;
            }

            Value *value = popStack(*stack);

            String name = ((StringValue *)nameHead)->value;
            bool found = false;

            for (ptrdiff_t i = callStackSize-1; i >= 0; --i)
            {
                HashMap<String, Value *>& vars = callStack[i].variables;

                int entry = vars.findEntry(name);

                if (entry != -1)
                {
                    destroy(this, vars.getValue(entry));
                    vars.set(name, value);

                    found = true;
                    break;
                }
            }

            if (not found)
            {
                HashMap<String, Value *>& vars = engine->getGlobalVars();

                int entry = vars.findEntry(name);

                if (entry != -1)
                {
                    destroy(this, vars.getValue(entry));
                    vars.set(name, value);
                } else
                {
                    callstackEntry.variables.set(name, value);
                }
            }

            destroy(this, nameHead);
            break;
        }
        case Opcode::DelVar:
        {
            Value *nameHead = popStack(*stack);

            if (nameHead->type != ValueType::StringType)
            {
                destroy(this, nameHead);

                throwException(createException(ExcType::TypeError, "Variable name must be String."));
                break;
            }

            String name = ((StringValue *)nameHead)->value;

            bool found = false;

            for (ptrdiff_t i = 0; i < (ptrdiff_t)callStackSize; ++i)
            {
                HashMap<String, Value *>& vars = callStack[i].variables;

                int entry = vars.findEntry(name);

                if (entry != -1)
                {
                    destroy(this, vars.getValue(entry));

                    vars.remove(name);
                    found = true;
                    break;
                }
            }

            if (not found)
            {
                HashMap<String, Value *>& vars = engine->getGlobalVars();

                int entry = vars.findEntry(name);

                if (entry != -1)
                {
                    destroy(this, vars.getValue(entry));

                    vars.remove(name);
                } else
                {
                    throwException(createException(ExcType::KeyError, "No such variable."));
                }
                break;
            }

            destroy(this, nameHead);
            break;
        }
        case Opcode::GetMember:
        {
            Value *key = popStack(*stack);
            Value *value = popStack(*stack);

            stack->append(getMember(this,
                                    value,
                                    key));

            destroy(this, value);
            destroy(this, key);
            break;
        }
        case Opcode::SetMember:
        {
            Value *value = popStack(*stack);
            Value *key = popStack(*stack);
            Value *newValue = popStack(*stack);

            setMember(this,
                      value,
                      key,
                      newValue);

            stack->append(value);

            destroy(this, newValue);
            destroy(this, key);
            break;
        }
        case Opcode::GetType:
        {
            Value *value = popStack(*stack);

            switch (value->type)
            {
            case ValueType::Int:
            {
                stack->append(createString("int"));
                break;
            }
            case ValueType::Float:
            {
                stack->append(createString("float"));
                break;
            }
            case ValueType::Boolean:
            {
                stack->append(createString("bool"));
                break;
            }
            case ValueType::Nil:
            {
                stack->append(createString("nil"));
                break;
            }
            case ValueType::Function:
            {
                stack->append(createString("func"));
                break;
            }
            case ValueType::Object:
            {
                stack->append(createString("obj"));
                break;
            }
            case ValueType::StringType:
            {
                stack->append(createString("str"));
                break;
            }
            case ValueType::NativeFunction:
            {
                stack->append(createString("native_func"));
                break;
            }
            case ValueType::NativeObject:
            {
                stack->append(createString("native_obj"));
                break;
            }
            case ValueType::Exception:
            {
                stack->append(createString("exception"));
                break;
            }
            }

            destroy(this, value);
            break;
        }

        #define ARITHMATIC_OP(iop, fop, funcName) Value *aHead = popStack(*stack);\
Value *bHead = popStack(*stack);\
\
if (aHead->type == ValueType::Object or aHead->type == ValueType::NativeObject or\
    bHead->type == ValueType::Object or bHead->type == ValueType::NativeObject)\
{\
    List<Value *> args;\
    args.append(bHead);\
    stack->append(callMethod(this, aHead, funcName, args));\
} else if ((aHead->type == ValueType::Float or bHead->type == ValueType::Float) and (aHead->type == ValueType::Int or bHead->type == ValueType::Int))\
{\
    double a = aHead->type == ValueType::Float ? ((FloatValue *)aHead)->value : ((IntValue *)aHead)->value;\
    double b = bHead->type == ValueType::Float ? ((FloatValue *)bHead)->value : ((IntValue *)bHead)->value;\
    \
    stack->append(createFloat(fop));\
} else if (aHead->type == ValueType::Int and bHead->type == ValueType::Int)\
{\
    int64_t a = ((IntValue *)aHead)->value;\
    int64_t b = ((IntValue *)bHead)->value;\
    \
    stack->append(createInt(iop));\
} else if (aHead->type == ValueType::Float and bHead->type == ValueType::Float)\
{\
    double a = ((FloatValue *)aHead)->value;\
    double b = ((FloatValue *)bHead)->value;\
    \
    stack->append(createFloat(fop));\
} else\
{\
    throwException(createException(ExcType::TypeError, "Invalid operand types for " STR(iop)));\
}\
\
destroy(this, aHead);\
destroy(this, bHead);\
\
break;

        case Opcode::Add:
        {
            ARITHMATIC_OP(a + b, a + b, "__add__")
        }
        case Opcode::Subtract:
        {
            ARITHMATIC_OP(a - b, a - b, "__sub__")
        }
        case Opcode::Multiply:
        {
            ARITHMATIC_OP(a * b, a * b, "__mul__")
        }
        case Opcode::Divide:
        {
            ARITHMATIC_OP(a / b, a / b, "__div__")
        }
        case Opcode::Modulo:
        {
            ARITHMATIC_OP(a % b, std::fmod(a, b), "__mod__")
        }

#undef ARITHMATIC_OP

#define TYPED_OP(type_, typeStruct, createFunc, op, funcName) Value *aHead = popStack(*stack);\
Value *bHead = popStack(*stack);\
\
if (aHead->type == ValueType::Object or aHead->type == ValueType::NativeObject)\
{\
    List<Value *> args;\
    args.append(bHead);\
    stack->append(callMethod(this, aHead, funcName, args));\
} else if (aHead->type != type_ or bHead->type != type_)\
{\
    throwException(createException(ExcType::TypeError, "Invalid operand types for " STR(op)));\
} else\
{\
stack->append(createFunc(((typeStruct *)aHead)->value op ((typeStruct *)bHead)->value));\
}\
\
destroy(this, aHead);\
destroy(this, bHead);\
\
break;

        case Opcode::BoolAnd:
        {
            TYPED_OP(ValueType::Boolean, BooleanValue, createBoolean, and, "__bland__")
        }
        case Opcode::BoolOr:
        {
            TYPED_OP(ValueType::Boolean, BooleanValue, createBoolean, or, "__blor__")
        }
        case Opcode::BoolNot:
        {
            Value *head = popStack(*stack);

            if (head->type == ValueType::Object or head->type == ValueType::NativeObject)
            {
                stack->append(callMethod(this, head, "__blnot__", List<Value *>()));
            } else if (head->type == ValueType::Boolean)
            {
                stack->append(createBoolean(not ((BooleanValue *)head)->value));
            } else
            {
                throwException(createException(ExcType::TypeError, "Invalid operand type for not. Must be Boolean."));
            }

            destroy(this, head);
            break;
        }
        case Opcode::BitAnd:
        {
            TYPED_OP(ValueType::Int, IntValue, createInt, &, "__btand__")
        }
        case Opcode::BitOr:
        {
            TYPED_OP(ValueType::Int, IntValue, createInt, |, "__btor__")
        }
        case Opcode::BitXOr:
        {
            TYPED_OP(ValueType::Int, IntValue, createInt, ^, "__btxor__")
        }

#undef TYPED_OP

#define SHIFT_OP(op, funcName) Value *aHead = popStack(*stack);\
Value *bHead = popStack(*stack);\
\
if (aHead->type == ValueType::Object or aHead->type == ValueType::NativeObject)\
{\
    List<Value *> args;\
    args.append(bHead);\
    stack->append(callMethod(this, aHead, funcName, args));\
} else if (aHead->type != ValueType::Int or bHead->type != ValueType::Int)\
{\
    throwException(createException(ExcType::TypeError, "Invalid operand types for " STR(op)));\
} else\
{\
    if (((IntValue *)aHead)->value < 0)\
    {\
        throwException(createException(ExcType::ValueError, "Operand of shift can not be negative."));\
    }\
    \
    if (((IntValue *)bHead)->value < 0)\
    {\
        throwException(createException(ExcType::ValueError, "Operand of shift can not be negative."));\
    }\
    uint64_t result = uint64_t(((IntValue *)aHead)->value) op uint64_t(((IntValue *)bHead)->value);\
    stack->append(createInt(result));\
}\
\
destroy(this, aHead);\
destroy(this, bHead);\
\
break;

        case Opcode::LeftShift:
        {
            SHIFT_OP(<<, "__shl__")
        }
        case Opcode::RightShift:
        {
            SHIFT_OP(>>, "__shr__")
        }
        case Opcode::BitNot:
        {
            Value *head = popStack(*stack);

            if (head->type == ValueType::Object or head->type == ValueType::NativeObject)
            {
                stack->append(callMethod(this, head, "__btnot__", List<Value *>()));
            } else if (head->type == ValueType::Int)
            {
                stack->append(createInt(~((BooleanValue *)head)->value));
            } else
            {
                throwException(createException(ExcType::TypeError, "Invalid operand type. Must be Int."));
            }

            destroy(this, head);
            break;
        }

        #define COMPARE_OP(op, funcName) Value *aHead = popStack(*stack);\
Value *bHead = popStack(*stack);\
\
if (aHead->type == ValueType::Object or aHead->type == ValueType::NativeObject or\
    bHead->type == ValueType::Object or bHead->type == ValueType::NativeObject)\
{\
    List<Value *> args;\
    args.append(bHead);\
    stack->append(callMethod(this, aHead, funcName, args));\
} else if ((aHead->type == ValueType::Float or bHead->type == ValueType::Float) and (aHead->type == ValueType::Int or bHead->type == ValueType::Int))\
{\
    double a = aHead->type == ValueType::Float ? ((FloatValue *)aHead)->value : ((IntValue *)aHead)->value;\
    double b = bHead->type == ValueType::Float ? ((FloatValue *)bHead)->value : ((IntValue *)bHead)->value;\
    \
    stack->append(createBoolean(a op b));\
} else if (aHead->type == ValueType::Int and bHead->type == ValueType::Int)\
{\
    int64_t a = ((IntValue *)aHead)->value;\
    int64_t b = ((IntValue *)bHead)->value;\
    \
    stack->append(createBoolean(a op b));\
} else if (aHead->type == ValueType::Float and bHead->type == ValueType::Float)\
{\
    double a = ((FloatValue *)aHead)->value;\
    double b = ((FloatValue *)bHead)->value;\
    \
    stack->append(createBoolean(a op b));\
} else\
{\
    throwException(createException(ExcType::TypeError, "Invalid operand types for " STR(op)));\
}\
\
destroy(this, bHead);\
destroy(this, aHead);\
\
break;

        case Opcode::Less:
        {
            COMPARE_OP(<, "__less__")
        }
        case Opcode::Greater:
        {
            COMPARE_OP(>, "__grtr__")
        }
        case Opcode::Equal:
        {
            COMPARE_OP(==, "__eq__")
        }
        case Opcode::NotEqual:
        {
            COMPARE_OP(!=, "__neq__")
        }
        case Opcode::LessEqual:
        {
            COMPARE_OP(<=, "__leq__")
        }
        case Opcode::GreaterEqual:
        {
            COMPARE_OP(>=, "__geq__")
        }

#undef COMPARE_OP

        case Opcode::Call:
        {
            Value *head = popStack(*stack);
            Value *argCountHead = popStack(*stack);

            if (argCountHead->type != ValueType::Int)
            {
                throwException(createException(ExcType::TypeError, "Arguments count must be an integer."));
            }

            int64_t argCount = ((IntValue *)argCountHead)->value;

            if (argCount < 0)
            {
                throwException(createException(ExcType::ValueError, "Argument count must not be negative."));
            }

            List<Value *> args;

            for (int64_t i = 0; i < argCount; ++i)
            {
                args.append(popStack(*stack));
            }

            stack->append(call(this, head, args));

            for (auto arg : args)
            {
                destroy(this, arg);
            }

            destroy(this, argCountHead);
            destroy(this, head);
            break;
        }
        case Opcode::CallMethod:
        {
            Value *head = popStack(*stack);
            Value *nameHead = popStack(*stack);

            if (nameHead->type != ValueType::StringType)
            {
                throwException(createException(ExcType::TypeError, "Method name must be string."));
            }

            Value *argCountHead = popStack(*stack);

            if (argCountHead->type != ValueType::Int)
            {
                throwException(createException(ExcType::TypeError, "Arguments count must be an integer."));
            }

            int64_t argCount = ((IntValue *)argCountHead)->value;

            if (argCount < 0)
            {
                throwException(createException(ExcType::ValueError, "Argument count must not be negative."));
            }

            List<Value *> args;

            for (int64_t i = 0; i < argCount; ++i)
            {
                args.append(popStack(*stack));
            }

            stack->append(callMethod(this, head, ((StringValue *)nameHead)->value, args));

            for (auto arg : args)
            {
                destroy(this, arg);
            }

            destroy(this, argCountHead);
            destroy(this, nameHead);
            destroy(this, head);
            break;
        }
        case Opcode::Return:
        {
            return popStack(*stack);
        }
        case Opcode::GetArgCount:
        {
            stack->append(createInt(args.getCount()));
            break;
        }
        case Opcode::GetArg:
        {
            Value *head = popStack(*stack);

            size_t index = toIndex(this, head);

            if (index >= args.getCount())
            {
                throwException(createException(ExcType::IndexError, "Arg index is out of bounds."));
            }

            stack->append(createCopy(this, args[index]));

            destroy(this, head);
            break;
        }
        case Opcode::JumpIf:
        {
            Value *head = popStack(*stack);

            if (head->type != ValueType::Boolean)
            {
                throwException(createException(ExcType::TypeError, "Jump condition is not a Boolean."));
            }

            int32_t success = bytecode.getInt32(offset);
            offset += 4;

            int32_t failure = bytecode.getInt32(offset);
            offset += 4;

            if (((BooleanValue *)head)->value)
            {
                offset += success;
            } else
            {
                offset += failure;
            }

            destroy(this, head);
            break;
        }
        case Opcode::Jump:
        {
            int32_t by = bytecode.getInt32(offset);
            offset += 4;

            offset += by;
            break;
        }
        case Opcode::Try:
        {
            int32_t by = bytecode.getInt32(offset);
            offset += 4;

            callstackEntry.stacks.append(List<Value *>());
            callstackEntry.catchBlocks.append(offset + by);

            stack = &callstackEntry.stacks[callstackEntry.stacks.getCount()-1];
            break;
        }
        case Opcode::EndTry:
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
            break;
        }
        case Opcode::Throw:
        {
            throwException(popStack(*stack));
            break;
        }
        case Opcode::GetException:
        {
            stack->append(createCopy(this, exception));
            break;
        }
        }

        //TODO: Get rid of this.
        if (engine->debugOutput)
        {
            std::cout << "----------------------------------" << std::endl;

            static const char *instructions[] = {"PushInt",
"PushFloat",
"PushBoolean",
"PushNil",
"PushFunc",
"PushObject",
"PushString",
"PushException",
"StackPop",
"LoadVar",
"StoreVar",
"DelVar",
"GetMember",
"SetMember",
"GetType",
"Add",
"Subtract",
"Multiply",
"Divide",
"Modulo",
"BoolAnd",
"BoolOr",
"BoolNot",
"BitAnd",
"BitOr",
"BitNot",
"BitXOr",
"LeftShift",
"RightShift",
"Less",
"Greater",
"Equal",
"NotEqual",
"LessEqual",
"GreaterEqual",
"Call",
"CallMethod",
"Return",
"GetArgCount",
"GetArg",
"JumpIf",
"Jump",
"Try",
"EndTry",
"Throw",
"GetException"};

            std::cout << "Instruction: " << instructions[(int)opcode] << std::endl;

            std::cout << "Callstack:" << std::endl;

            for (size_t i = 0; i < callStackSize; ++i)
            {
                CallstackEntry& entry = callStack[i];

                std::cout << "    Offset: " << entry.offset << std::endl;
                std::cout << "    Variables: " << std::endl;

                for (size_t j = 0; j < entry.variables.getEntryCount(); ++j)
                {
                    Value *head = entry.variables.getValue(j);

                    std::cout << "        " << entry.variables.getKey(j).getData() << ": ";

                    switch (head->type)
                    {
                    case ValueType::Int:
                    {
                        std::cout << ((IntValue *)head)->value << std::endl;
                        break;
                    }
                    case ValueType::Float:
                    {
                        std::cout << ((FloatValue *)head)->value << std::endl;
                        break;
                    }
                    case ValueType::Boolean:
                    {
                        std::cout << (((BooleanValue *)head)->value ? "true" : "false") << std::endl;
                        break;
                    }
                    case ValueType::Nil:
                    {
                        std::cout << "nil" << std::endl;
                        break;
                    }
                    case ValueType::Function:
                    {
                        std::cout << "function" << std::endl;
                        break;
                    }
                    case ValueType::Object:
                    {
                        std::cout << "object" << std::endl;
                        break;
                    }
                    case ValueType::StringType:
                    {
                        std::cout << '"' << ((StringValue *)head)->value.getData() << '"' << std::endl;
                        break;
                    }
                    case ValueType::NativeFunction:
                    {
                        std::cout << "native_function" << std::endl;
                        break;
                    }
                    case ValueType::NativeObject:
                    {
                        std::cout << "native_object" << std::endl;
                        break;
                    }
                    case ValueType::Exception:
                    {
                        ExceptionValue *exc = (ExceptionValue *)head;
                        std::cout << int(exc->type) << ": " << exc->error.getData() << std::endl;
                        break;
                    }
                    }
                }

                std::cout << "    Stack:" << std::endl;

                for (size_t j = 0; j < entry.stacks[entry.stacks.getCount()-1].getCount(); ++j)
                {
                    Value *head = entry.stacks[entry.stacks.getCount()-1][j];

                    std::cout << "        ";

                    switch (head->type)
                    {
                    case ValueType::Int:
                    {
                        std::cout << ((IntValue *)head)->value << std::endl;
                        break;
                    }
                    case ValueType::Float:
                    {
                        std::cout << ((FloatValue *)head)->value << std::endl;
                        break;
                    }
                    case ValueType::Boolean:
                    {
                        std::cout << (((BooleanValue *)head)->value ? "true" : "false") << std::endl;
                        break;
                    }
                    case ValueType::Nil:
                    {
                        std::cout << "nil" << std::endl;
                        break;
                    }
                    case ValueType::Function:
                    {
                        std::cout << "function" << std::endl;
                        break;
                    }
                    case ValueType::Object:
                    {
                        std::cout << "object" << std::endl;
                        break;
                    }
                    case ValueType::StringType:
                    {
                        std::cout << '"' << ((StringValue *)head)->value.getData() << '"' << std::endl;
                        break;
                    }
                    case ValueType::NativeFunction:
                    {
                        std::cout << "native_function" << std::endl;
                        break;
                    }
                    case ValueType::NativeObject:
                    {
                        std::cout << "native_object" << std::endl;
                        break;
                    }
                    case ValueType::Exception:
                    {
                        ExceptionValue *exc = (ExceptionValue *)head;
                        std::cout << "exception: type=" << int(exc->type) << " error=" << exc->error.getData() << std::endl;
                        break;
                    }
                    }
                }
            }
        }
    }

    return createNil();
}

Value *Context::run(const Bytecode& bytecode, List<Value *> args)
{
    if (callStackSize == SCRIPTING_MAX_CALLSTACK_SIZE)
    {
        THROW(CallstackBoundsException)
    }

    callStack[callStackSize++] = CallstackEntry(bytecode);
    CallstackEntry& callstackEntry = callStack[callStackSize-1];

    callstackEntry.stacks.append(List<Value *>());

    //This may not be safe.
    if (!setjmp(jumpBuf))
    {
        Value *result = _run(bytecode, args);

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

            List<Value *>& stack = entry->stacks[entry->stacks.getCount()-1];

            for (auto value : stack)
            {
                destroy(this, value);
            }

            entry->stacks.remove(entry->stacks.getCount()-1);
            entry->offset = offset;

            Value *result = _run(entry->bytecode, List<Value *>());

            destroy(this, exception);
            exception = createNil();

            return result;
        }

        Value *exc = exception;

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

    for (size_t i = 0; i < callstackEntry.variables.getEntryCount(); ++i)
    {
        destroy(this, callstackEntry.variables.getValue(i));
    }

    callstackEntry.variables.clear();

    --callStackSize;
}

void Context::throwException(Value *exc)
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

Value *Context::popStack(List<Value *>& stack)
{
    if (stack.getCount() == 0)
    {
        THROW(StackBoundsException);
    } else
    {
        Value *result = stack[stack.getCount() - 1];
        stack.remove(stack.getCount() - 1);

        return result;
    }
}

UnhandledExcException::UnhandledExcException(const char *file_,
                                             size_t line_,
                                             const char *function_,
                                             Context *ctx_,
                                             Value *exception_)
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

size_t toIndex(Context *ctx, Value *value)
{
    if (value->type == ValueType::Int)
    {
        int64_t i = ((IntValue *)value)->value;

        if (i < 0)
        {
            ctx->throwException(createException(ExcType::ValueError, "Index should not be below zero."));
        } else
        {
            return i;
        }
    } else if (value->type == ValueType::Float)
    {
        double i = ((FloatValue *)value)->value;

        if ((size_t)i < 0)
        {
            ctx->throwException(createException(ExcType::ValueError, "Index should not be below zero."));
        } else
        {
            return (size_t)i;
        }
    } else
    {
        ctx->throwException(createException(ExcType::TypeError, "Invalid index type."));
    }

    assert(false);
}

static Value *strEqual(Context *ctx, const List<Value *>& args)
{
    if (args.getCount() != 2)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::__eq__ takes two arguments."));
    }

    if (args[0]->type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::__eq__ takes a string as the first argument."));
    }

    if (args[1]->type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::__eq__ takes a string as the second argument."));
    }

    return createBoolean(((StringValue *)args[0])->value == ((StringValue *)args[1])->value);
}

static Value *strNotEqual(Context *ctx, const List<Value *>& args)
{
    if (args.getCount() != 2)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::__eq__ takes two arguments."));
    }

    if (args[0]->type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::__eq__ takes a string as the first argument."));
    }

    if (args[1]->type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::__eq__ takes a string as the second argument."));
    }

    return createBoolean(((StringValue *)args[0])->value != ((StringValue *)args[1])->value);
}

static Value *strAppend(Context *ctx, const List<Value *>& args)
{
    if (args.getCount() != 2)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::append takes two arguments."));
    }

    if (args[0]->type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::append takes a string as the first argument."));
    }

    if (args[1]->type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::append takes a string as the second argument."));
    }

    return createString(((StringValue *)args[0])->value.append(((StringValue *)args[1])->value));
}

static Value *strInsert(Context *ctx, const List<Value *>& args)
{
    if (args.getCount() != 3)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::insert takes three arguments."));
    }

    if (args[0]->type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::insert takes a string as the first argument."));
    }

    if (args[1]->type != ValueType::Int or args[1]->type != ValueType::Float)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::insert takes a integer or float as the second argument."));
    }

    if (args[2]->type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::insert takes a string as the third argument."));
    }

    String str = ((StringValue *)args[0])->value;
    size_t start = toIndex(ctx, args[1]);
    String toInsert = ((StringValue *)args[2])->value;

    if (start > str.getLength())
    {
        ctx->throwException(createException(ExcType::ValueError, "Invalid start for string insertion."));
    }

    str.insert(start, toInsert);
    return createNil();
}

static Value *strRemove(Context *ctx, const List<Value *>& args)
{
    if (args.getCount() != 3)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::remove takes three arguments."));
    }

    if (args[0]->type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::remove takes a string as the first argument."));
    }

    if (args[1]->type != ValueType::Int and args[1]->type != ValueType::Float)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::remove takes a integer or float as the second argument."));
    }

    if (args[2]->type != ValueType::Int and args[2]->type != ValueType::Float)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::remove takes a integer or float as the third argument."));
    }

    String str = ((StringValue *)args[0])->value;
    size_t start = toIndex(ctx, args[1]);
    size_t count = toIndex(ctx, args[2]);

    if (start+count > str.getLength())
    {
        ctx->throwException(createException(ExcType::ValueError, "Invalid start and count for string removal."));
    }

    str.remove(start, count);
    return createNil();
}

static Value *strClear(Context *ctx, const List<Value *>& args)
{
    if (args.getCount() != 1)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::clear takes one argument."));
    }

    if (args[0]->type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::clear takes a string as the first argument."));
    }

    ((StringValue *)args[0])->value.clear();

    return createNil();
}

static Value *strResize(Context *ctx, const List<Value *>& args)
{
    if (args.getCount() != 2)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::resize takes two arguments."));
    }

    if (args[0]->type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::resize takes a string as the first argument."));
    }

    if (args[1]->type != ValueType::Int and args[1]->type != ValueType::Float)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::resize takes a integer or float as the second argument."));
    }

    ((StringValue *)args[0])->value.resize(toIndex(ctx, args[1]));

    return createNil();
}

static Value *strFind(Context *ctx, const List<Value *>& args)
{
    if (args.getCount() != 2)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::find takes two arguments."));
    }

    if (args[0]->type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::find takes a string as the first argument."));
    }

    if (args[1]->type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::find takes a string as the second argument."));
    }

    return createInt(((StringValue *)args[0])->value.find(((StringValue *)args[1])->value));
}

static Value *strSubStr(Context *ctx, const List<Value *>& args)
{
    if (args.getCount() != 3)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::subStr takes three arguments."));
    }

    if (args[0]->type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::subStr takes a string as the first argument."));
    }

    if (args[1]->type != ValueType::Int and args[1]->type != ValueType::Float)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::subStr takes a integer or float as the second argument."));
    }

    if (args[2]->type != ValueType::Int and args[2]->type != ValueType::Float)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::subStr takes a integer or float as the third argument."));
    }

    String str = ((StringValue *)args[0])->value;
    size_t offset = toIndex(ctx, args[1]);
    size_t length = toIndex(ctx, args[2]);

    if (offset+length > str.getLength())
    {
        ctx->throwException(createException(ExcType::ValueError, "Invalid start or count for String::subStr"));
    }

    return createString(str.subStr(offset, length));
}

static Value *strCopy(Context *ctx, const List<Value *>& args)
{
    if (args.getCount() != 1)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::copy takes one argument."));
    }

    if (args[0]->type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::copy takes a string as the first argument."));
    }

    return createString(((StringValue *)args[0])->value.copy());
}

static Value *strCopyFrom(Context *ctx, const List<Value *>& args)
{
    if (args.getCount() != 2)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::copyFrom takes two arguments."));
    }

    if (args[0]->type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::copyFrom takes a string as the first argument."));
    }

    if (args[1]->type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::copyFrom takes a string as the second argument."));
    }

    ((StringValue *)args[0])->value.copyFrom(((StringValue *)args[1])->value);

    return createNil();
}

static Value *strFormat(Context *ctx, const List<Value *>& args)
{
    if (args.getCount() < 1)
    {
        ctx->throwException(createException(ExcType::ValueError, "String::format takes at least one argument."));
    }

    if (args[0]->type != ValueType::StringType)
    {
        ctx->throwException(createException(ExcType::TypeError, "String::format takes a string as the first argument."));
    }

    String formatStr = ((StringValue *)args[0])->value;
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

                Value *v = args[argIndex++];

                switch (v->type)
                {
                case ValueType::Int:
                {
                    result.append(String::formatValue((long long int)((IntValue *)v)->value));
                    break;
                }
                case ValueType::Float:
                {
                    result.append(String::format("%.2f", ((FloatValue *)v)->value));
                    break;
                }
                case ValueType::Boolean:
                {
                    result.append(((BooleanValue *)v)->value ? "true" : "false");
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
                    result.append(((StringValue *)v)->value);
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

Value *getMember(Context *ctx, Value *val, Value *key)
{
    switch (val->type)
    {
    case ValueType::Object:
    {
        if (key->type != ValueType::StringType)
        {
            ctx->throwException(createException(ExcType::TypeError, "Member name must be String."));
        }

        HashMap<String, Value *> members = ((ObjectValue *)val)->members;

        String keyStr = ((StringValue *)key)->value;
        int index = members.findEntry(keyStr);

        if (index == -1)
        {
            ctx->throwException(createException(ExcType::KeyError, String::format("Unknown member: '%s'", keyStr.getData())));
        }

        return createCopy(ctx, members.getValue(index));
    }
    case ValueType::StringType:
    {
        if (key->type == ValueType::Int or key->type == ValueType::Float)
        {
            String str = ((StringValue *)val)->value;

            size_t index = toIndex(ctx, key);

            if (index >= str.getLength())
            {
                ctx->throwException(createException(ExcType::IndexError, "String index is out of bounds."));
            }

            return createString(String(str[index]));
        } else if (key->type == ValueType::StringType)
        {
            String keyStr = ((StringValue *)key)->value;

            if (keyStr == "__eq__")
            {
                return createNativeFunction(strEqual);
            } else if (keyStr == "__neq__")
            {
                return createNativeFunction(strNotEqual);
            } else if (keyStr == "length")
            {
                return createInt(((StringValue *)val)->value.getLength());
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
        NativeObject *obj = (NativeObject *)val;

        return obj->funcs.getMember(ctx, obj, key);
    }
    case ValueType::Exception:
    {
        if (key->type != ValueType::StringType)
        {
            ctx->throwException(createException(ExcType::TypeError, "Member name must be String."));
        }

        String name = ((StringValue *)key)->value;
        ExceptionValue *exc = (ExceptionValue *)val;

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

    assert(false);
}

void setMember(Context *ctx, Value *dest, Value *key, Value *value)
{
    switch (dest->type)
    {
    case ValueType::Object:
    {
        if (key->type != ValueType::StringType)
        {
            ctx->throwException(createException(ExcType::TypeError, "Member names must be String."));
        }

        HashMap<String, Value *>& members = ((ObjectValue *)dest)->members;

        String name = ((StringValue *)key)->value;

        if (members.findEntry(name) != -1)
        {
            destroy(ctx, members.get(name));
        }

        members.set(name, createCopy(ctx, value));
        return;
    }
    case ValueType::StringType:
    {
        if (value->type != ValueType::StringType)
        {
            ctx->throwException(createException(ExcType::TypeError, "A string's character can only be set as a String."));
        } else
        {
            if (((StringValue *)value)->value.getLength() != 1)
            {
                ctx->throwException(createException(ExcType::ValueError, "String must of length 1."));
            }
        }

        String str = ((StringValue *)dest)->value;

        size_t index = toIndex(ctx, key);

        if (index >= str.getLength())
        {
            ctx->throwException(createException(ExcType::IndexError, "String index is out of bounds."));
        }

        str[index] = ((StringValue *)value)->value[0];
        return;
    }
    case ValueType::NativeObject:
    {
        NativeObject *obj = (NativeObject *)dest;

        obj->funcs.setMember(ctx, obj, key, value);
        return;
    }
    default:
    {
        ctx->throwException(createException(ExcType::TypeError, "Type does not have members."));
    }
    }

    assert(false);
}

Value *call(Context *ctx, Value *value, const List<Value *>& args)
{
    switch (value->type)
    {
    case ValueType::Function:
    {
        return ctx->run(((FunctionValue *)value)->bytecode, args);
    }
    case ValueType::NativeFunction:
    {
        return ((NativeFunction *)value)->func(ctx, args);
    }
    case ValueType::Object:
    case ValueType::NativeObject:
    {
        Value *result = callMethod(ctx, value, "__call__", args);
        return result;
    }
    default:
    {
        ctx->throwException(createException(ExcType::TypeError, "Type is not callable."));
    }
    }

    assert(false);
}

Value *callMethod(Context *ctx, Value *obj, const String& methName, const List<Value *>& args)
{
    List<Value *> args_;

    args_.append(obj);
    args_.append(args);

    Value *nameHead = createString(methName);

    Value *funcHead = getMember(ctx, obj, nameHead);

    Value *result = call(ctx, funcHead, args_);

    destroy(ctx, funcHead);
    destroy(ctx, nameHead);

    return result;
}

bool isInstance(Context *ctx, Value *obj, Value *type)
{
    if (obj->type != type->type)
    {
        return false;
    }

    if (obj->type == ValueType::NativeObject)
    {
        return ((NativeObject *)obj)->typeID == ((NativeObject *)type)->typeID;
    } else if (obj->type == ValueType::Object)
    {
        HashMap<String, Value *> objMembers = ((ObjectValue *)obj)->members;
        HashMap<String, Value *> typeMembers = ((ObjectValue *)type)->members;

        int entry1 = objMembers.findEntry("__classTypeID__");
        int entry2 = typeMembers.findEntry("__typeID__");

        if (entry1 == -1 or entry2 == -1)
        {
            return false;
        }

        Value *id1 = objMembers.getValue(entry1);
        Value *id2 = objMembers.getValue(entry2);

        if (id1->type != ValueType::Int or id2->type != ValueType::Int)
        {
            ctx->throwException(createException(ExcType::TypeError, "Type IDs must be integers."));
        }

        return ((IntValue *)id1) == ((IntValue *)id2);
    } else
    {
        return false;
    }
}
}

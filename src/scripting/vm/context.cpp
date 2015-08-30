#include "scripting/vm/context.h"

#include "scripting/vm/engine.h"
#include <cmath>
#include <iostream> //TODO: Get rid of this.
#include <cassert>

namespace scripting
{
Context::Context(Engine *engine_) : engine(engine_), callStackSize(0), exception(engine->getRefMgr()->createNil()) {}

Context::~Context()
{
    reset();

    engine->getRefMgr()->destroy(this, exception);
}

void Context::reset()
{
    for (size_t i = 0; i < callStackSize; ++i)
    {
        CallstackEntry& entry = callStack[i];

        for (size_t j = 0; j < entry.stacks.getCount(); ++j)
        {
            for (size_t k = 0; k < entry.stacks[j].getCount(); ++k)
            {
                engine->getRefMgr()->destroy(this, entry.stacks[j][k]);
            }
        }

        entry.stacks.clear();

        for (size_t j = 0; j < entry.variables.getEntryCount(); ++j)
        {
            engine->getRefMgr()->destroy(this, entry.variables.getValue(j));
        }

        entry.variables.clear();
    }

    callStackSize = 0;
}

//TODO: More reference checking.
Ref Context::_run(const Bytecode& bytecode, List<Ref> args)
{
    RefManager *refMgr = engine->getRefMgr();

    CallstackEntry& callstackEntry = callStack[callStackSize-1];
    size_t& offset = callstackEntry.offset;
    List<Ref> *stack = &callstackEntry.stacks[0];

    while (offset < bytecode.data.getSize())
    {
        Opcode opcode = bytecode.getOpcode(offset++);

        switch (opcode)
        {
        case Opcode::PushInt:
        {
            stack->append(refMgr->createInt(bytecode.getInt64(offset)));
            offset += 8;
            break;
        }
        case Opcode::PushFloat:
        {
            stack->append(refMgr->createFloat(bytecode.getDouble(offset)));
            offset += 8;
            break;
        }
        case Opcode::PushBoolean:
        {
            stack->append(refMgr->createBoolean(bytecode.getBoolean(offset)));
            offset += 1;
            break;
        }
        case Opcode::PushNil:
        {
            stack->append(refMgr->createNil());
            break;
        }
        case Opcode::PushFunc:
        {
            size_t size = bytecode.getUInt32(offset);
            offset += 4;

            ResizableData data = bytecode.getData(offset, size);
            offset += size;

            Bytecode code(data);

            stack->append(refMgr->createFunction(code));
            break;
        }
        case Opcode::PushObject:
        {
            stack->append(refMgr->createObject());
            break;
        }
        case Opcode::PushString:
        {
            size_t length = bytecode.getUInt32(offset);
            offset += 4;

            ResizableData data = bytecode.getData(offset, length);
            offset += length;

            stack->append(refMgr->createString(String(length, (const char *)data.getData())));
            break;
        }
        case Opcode::PushList:
        {
            stack->append(refMgr->createList(List<Ref>()));
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

            stack->append(refMgr->createException(type, String(length, (const char *)data.getData())));
            break;
        }
        case Opcode::StackPop:
        {
            if (stack->getCount() == 0)
            {
                THROW(StackBoundsException);
            }

            refMgr->destroy(this, (*stack)[stack->getCount()-1]);

            stack->remove(stack->getCount()-1);
            break;
        }
        case Opcode::LoadVar:
        {
            Ref nameRef = popStack(*stack);
            Value *head = refMgr->translate(nameRef);

            if (head->type != ValueType::String)
            {
                refMgr->destroy(this, nameRef);

                throwException(refMgr->createException(ExcType::TypeError, "Variable name must be String."));
                break;
            }

            String name = ((StringValue *)head)->value;

            bool found = false;

            for (ptrdiff_t i = 0; i < (ptrdiff_t)callStackSize; ++i)
            {
                HashMap<String, Ref>& vars = callStack[i].variables;

                int entry = vars.findEntry(name);

                if (entry != -1)
                {
                    stack->append(refMgr->createCopy(this, vars.getValue(entry)));
                    found = true;
                    break;
                }
            }

            if (not found)
            {
                HashMap<String, Ref>& vars = engine->getGlobalVars();

                int entry = vars.findEntry(name);

                if (entry != -1)
                {
                    stack->append(refMgr->createCopy(this, vars.getValue(entry)));
                } else
                {
                    throwException(refMgr->createException(ExcType::KeyError, "No such variable."));
                }
                break;
            }

            refMgr->destroy(this, nameRef);
            break;
        }
        case Opcode::StoreVar:
        {
            Ref nameRef = popStack(*stack);
            Value *head = refMgr->translate(nameRef);

            if (head->type != ValueType::String)
            {
                refMgr->destroy(this, nameRef);

                throwException(refMgr->createException(ExcType::TypeError, "Variable name must be String."));
                break;
            }

            String name = ((StringValue *)head)->value;
            bool found = false;

            for (ptrdiff_t i = callStackSize-1; i >= 0; --i)
            {
                HashMap<String, Ref>& vars = callStack[i].variables;

                int entry = vars.findEntry(name);

                if (entry != -1)
                {
                    Ref value = popStack(*stack);

                    if (value != vars.getValue(entry))
                    {
                        refMgr->copyRef(this, vars.getValue(entry), value);

                        refMgr->destroy(this, value);
                    }

                    found = true;
                    break;
                }
            }

            if (not found)
            {
                HashMap<String, Ref>& vars = engine->getGlobalVars();

                int entry = vars.findEntry(name);

                if (entry != -1)
                {
                    Ref value = popStack(*stack);

                    if (value != vars.getValue(entry))
                    {
                        refMgr->copyRef(this, vars.getValue(entry), value);

                        refMgr->destroy(this, value);
                    }
                } else
                {
                    Ref value = popStack(*stack);

                    callstackEntry.variables.set(name, refMgr->createCopy(this, value));

                    refMgr->destroy(this, value);
                }
            }

            refMgr->destroy(this, nameRef);
            break;
        }
        case Opcode::DelVar:
        {
            Ref nameRef = popStack(*stack);
            Value *head = refMgr->translate(nameRef);

            if (head->type != ValueType::String)
            {
                refMgr->destroy(this, nameRef);

                throwException(refMgr->createException(ExcType::TypeError, "Variable name must be String."));
                break;
            }

            String name = ((StringValue *)head)->value;

            bool found = false;

            for (ptrdiff_t i = 0; i < (ptrdiff_t)callStackSize; ++i)
            {
                HashMap<String, Ref>& vars = callStack[i].variables;

                int entry = vars.findEntry(name);

                if (entry != -1)
                {
                    refMgr->destroy(this, vars.getValue(entry));

                    vars.remove(name);
                    found = true;
                    break;
                }
            }

            if (not found)
            {
                HashMap<String, Ref>& vars = engine->getGlobalVars();

                int entry = vars.findEntry(name);

                if (entry != -1)
                {
                    refMgr->destroy(this, vars.getValue(entry));

                    vars.remove(name);
                } else
                {
                    throwException(refMgr->createException(ExcType::KeyError, "No such variable."));
                }
                break;
            }

            refMgr->destroy(this, nameRef);
            break;
        }
        case Opcode::GetMember:
        {
            Ref value = popStack(*stack);
            Ref key = popStack(*stack);

            stack->append(getMember(this,
                                    refMgr->translate(value),
                                    refMgr->translate(key)));

            refMgr->destroy(this, key);
            refMgr->destroy(this, value);
            break;
        }
        case Opcode::SetMember:
        {
            Ref value = popStack(*stack);
            Ref key = popStack(*stack);
            Ref newValue = popStack(*stack);

            stack->append(setMember(this,
                                    refMgr->translate(value),
                                    refMgr->translate(key),
                                    refMgr->translate(newValue)));

            refMgr->destroy(this, newValue);
            refMgr->destroy(this, key);
            refMgr->destroy(this, value);
            break;
        }
        case Opcode::GetType:
        {
            Ref value = popStack(*stack);

            switch (refMgr->translate(value)->type)
            {
            case ValueType::Int:
            {
                stack->append(refMgr->createString("int"));
                break;
            }
            case ValueType::Float:
            {
                stack->append(refMgr->createString("float"));
                break;
            }
            case ValueType::Boolean:
            {
                stack->append(refMgr->createString("bool"));
                break;
            }
            case ValueType::Nil:
            {
                stack->append(refMgr->createString("nil"));
                break;
            }
            case ValueType::Function:
            {
                stack->append(refMgr->createString("func"));
                break;
            }
            case ValueType::Object:
            {
                stack->append(refMgr->createString("obj"));
                break;
            }
            case ValueType::String:
            {
                stack->append(refMgr->createString("str"));
                break;
            }
            case ValueType::List:
            {
                stack->append(refMgr->createString("list"));
                break;
            }
            case ValueType::NativeFunction:
            {
                stack->append(refMgr->createString("native_func"));
                break;
            }
            case ValueType::NativeObject:
            {
                stack->append(refMgr->createString("native_obj"));
                break;
            }
            case ValueType::Exception:
            {
                stack->append(refMgr->createString("exception"));
                break;
            }
            }

            refMgr->destroy(this, value);
            break;
        }

        #define ARITHMATIC_OP(iop, fop, funcName) Ref a = popStack(*stack);\
Ref b = popStack(*stack);\
\
Value *aHead = refMgr->translate(a);\
Value *bHead = refMgr->translate(b);\
\
if (aHead->type == ValueType::Object or aHead->type == ValueType::NativeObject or\
    bHead->type == ValueType::Object or bHead->type == ValueType::NativeObject)\
{\
    List<Ref> args;\
    args.append(b);\
    stack->append(callMethod(this, aHead, funcName, args));\
} else if ((aHead->type == ValueType::Float or bHead->type == ValueType::Float) and (aHead->type == ValueType::Int or bHead->type == ValueType::Int))\
{\
    double a = aHead->type == ValueType::Float ? ((FloatValue *)aHead)->value : ((IntValue *)aHead)->value;\
    double b = bHead->type == ValueType::Float ? ((FloatValue *)bHead)->value : ((IntValue *)bHead)->value;\
    \
    stack->append(refMgr->createFloat(fop));\
} else if (aHead->type == ValueType::Int and bHead->type == ValueType::Int)\
{\
    int64_t a = ((IntValue *)aHead)->value;\
    int64_t b = ((IntValue *)bHead)->value;\
    \
    stack->append(refMgr->createInt(iop));\
} else if (aHead->type == ValueType::Float and bHead->type == ValueType::Float)\
{\
    double a = ((FloatValue *)aHead)->value;\
    double b = ((FloatValue *)bHead)->value;\
    \
    stack->append(refMgr->createFloat(fop));\
} else\
{\
    throwException(refMgr->createException(ExcType::TypeError, "Invalid operand types."));\
}\
\
refMgr->destroy(this, a);\
refMgr->destroy(this, b);\
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

#define TYPED_OP(type_, typeStruct, createFunc, op, funcName) Ref a = popStack(*stack);\
Ref b = popStack(*stack);\
\
Value *aHead = refMgr->translate(a);\
Value *bHead = refMgr->translate(b);\
\
if (aHead->type == ValueType::Object or aHead->type == ValueType::NativeObject)\
{\
    List<Ref> args;\
    args.append(b);\
    stack->append(callMethod(this, aHead, funcName, args));\
} else if (aHead->type != type_ or bHead->type != type_)\
{\
    throwException(refMgr->createException(ExcType::TypeError, "Invalid operand types."));\
} else\
{\
stack->append(refMgr->createFunc(((typeStruct *)aHead)->value op ((typeStruct *)bHead)->value));\
}\
\
refMgr->destroy(this, a);\
refMgr->destroy(this, b);\
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
            Ref value = popStack(*stack);
            Value *head = refMgr->translate(value);

            if (head->type == ValueType::Object or head->type == ValueType::NativeObject)
            {
                stack->append(callMethod(this, head, "__blnot__", List<Ref>()));
            } else if (head->type == ValueType::Boolean)
            {
                stack->append(refMgr->createBoolean(not ((BooleanValue *)head)->value));
            } else
            {
                throwException(refMgr->createException(ExcType::TypeError, "Invalid operand type. Must be Boolean."));
            }

            refMgr->destroy(this, value);
            break;
        }
        case Opcode::BitAnd:
        {
            TYPED_OP(ValueType::Int, IntValue, createInt, &&, "__btand__")
        }
        case Opcode::BitOr:
        {
            TYPED_OP(ValueType::Int, IntValue, createInt, ||, "__btor__")
        }
        case Opcode::BitXOr:
        {
            TYPED_OP(ValueType::Int, IntValue, createInt, ^, "__btxor__")
        }

#undef TYPED_OP

#define SHIFT_OP(op, funcName) Ref a = popStack(*stack);\
Ref b = popStack(*stack);\
\
Value *aHead = refMgr->translate(a);\
Value *bHead = refMgr->translate(b);\
\
if (aHead->type == ValueType::Object or aHead->type == ValueType::NativeObject)\
{\
    List<Ref> args;\
    args.append(b);\
    stack->append(callMethod(this, aHead, funcName, args));\
} else if (aHead->type != ValueType::Int or bHead->type != ValueType::Int)\
{\
    throwException(refMgr->createException(ExcType::TypeError, "Invalid operand types."));\
} else\
{\
    union\
    {\
        uint64_t u;\
        int64_t s;\
    } u1;\
    union\
    {\
        uint64_t u;\
        int64_t s;\
    } u2;\
    union\
    {\
        uint64_t u;\
        int64_t s;\
    } u3;\
    u1.s = ((IntValue *)aHead)->value;\
    u2.s = ((IntValue *)bHead)->value;\
    u3.u = u1.u op u2.u;\
    stack->append(refMgr->createInt(u3.s));\
}\
\
refMgr->destroy(this, a);\
refMgr->destroy(this, b);\
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
            Ref value = popStack(*stack);
            Value *head = refMgr->translate(value);

            if (head->type == ValueType::Object or head->type == ValueType::NativeObject)
            {
                stack->append(callMethod(this, head, "__btnot__", List<Ref>()));
            } else if (head->type == ValueType::Int)
            {
                stack->append(refMgr->createInt(~((BooleanValue *)head)->value));
            } else
            {
                throwException(refMgr->createException(ExcType::TypeError, "Invalid operand type. Must be Int."));
            }

            refMgr->destroy(this, value);
            break;
        }

        #define COMPARE_OP(op, funcName) Ref a = popStack(*stack);\
Ref b = popStack(*stack);\
\
Value *aHead = refMgr->translate(a);\
Value *bHead = refMgr->translate(b);\
\
if (aHead->type == ValueType::Object or aHead->type == ValueType::NativeObject or\
    bHead->type == ValueType::Object or bHead->type == ValueType::NativeObject)\
{\
    List<Ref> args;\
    args.append(b);\
    stack->append(callMethod(this, aHead, funcName, args));\
} else if ((aHead->type == ValueType::Float or bHead->type == ValueType::Float) and (aHead->type == ValueType::Int or bHead->type == ValueType::Int))\
{\
    double a = aHead->type == ValueType::Float ? ((FloatValue *)aHead)->value : ((IntValue *)aHead)->value;\
    double b = bHead->type == ValueType::Float ? ((FloatValue *)bHead)->value : ((IntValue *)bHead)->value;\
    \
    stack->append(refMgr->createBoolean(a op b));\
} else if (aHead->type == ValueType::Int and bHead->type == ValueType::Int)\
{\
    int64_t a = ((IntValue *)aHead)->value;\
    int64_t b = ((IntValue *)bHead)->value;\
    \
    stack->append(refMgr->createBoolean(a op b));\
} else if (aHead->type == ValueType::Float and bHead->type == ValueType::Float)\
{\
    double a = ((FloatValue *)aHead)->value;\
    double b = ((FloatValue *)bHead)->value;\
    \
    stack->append(refMgr->createBoolean(a op b));\
} else\
{\
    throwException(refMgr->createException(ExcType::TypeError, "Invalid operand types."));\
}\
\
refMgr->destroy(this, a);\
refMgr->destroy(this, b);\
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
            Ref func = popStack(*stack);
            Value *head = refMgr->translate(func);

            Ref argCountRef = popStack(*stack);
            Value *argCountHead = refMgr->translate(argCountRef);

            if (argCountHead->type != ValueType::Int)
            {
                throwException(refMgr->createException(ExcType::TypeError, "Arguments count must be an integer."));
            }

            int64_t argCount = ((IntValue *)argCountHead)->value;

            if (argCount < 0)
            {
                throwException(refMgr->createException(ExcType::ValueError, "Argument count must not be negative."));
            }

            List<Ref> args;

            for (int64_t i = 0; i < argCount; ++i)
            {
                args.append(popStack(*stack));
            }

            stack->append(call(this, head, args));

            for (size_t i = 0; i < args.getCount(); ++i)
            {
                refMgr->destroy(this, args[i]);
            }

            refMgr->destroy(this, argCountRef);
            refMgr->destroy(this, func);
            break;
        }
        case Opcode::CallMethod:
        {
            Ref object = popStack(*stack);
            Value *head = refMgr->translate(object);

            Ref name = popStack(*stack);
            Value *nameHead = refMgr->translate(name);

            if (nameHead->type != ValueType::String)
            {
                throwException(refMgr->createException(ExcType::TypeError, "Method name must be string."));
            }

            Ref argCountRef = popStack(*stack);
            Value *argCountHead = refMgr->translate(argCountRef);

            if (argCountHead->type != ValueType::Int)
            {
                throwException(refMgr->createException(ExcType::TypeError, "Arguments count must be an integer."));
            }

            int64_t argCount = ((IntValue *)argCountHead)->value;

            if (argCount < 0)
            {
                throwException(refMgr->createException(ExcType::ValueError, "Argument count must not be negative."));
            }

            List<Ref> args;

            for (int64_t i = 0; i < argCount; ++i)
            {
                args.append(popStack(*stack));
            }

            stack->append(callMethod(this, head, ((StringValue *)nameHead)->value, args));

            for (size_t i = 0; i < args.getCount(); ++i)
            {
                refMgr->destroy(this, args[i]);
            }

            refMgr->destroy(this, argCountRef);
            refMgr->destroy(this, name);
            refMgr->destroy(this, object);
            break;
        }
        case Opcode::Return:
        {
            return popStack(*stack);
        }
        case Opcode::GetArgCount:
        {
            stack->append(refMgr->createInt(args.getCount()));

            stack->append(refMgr->createList(args));
            break;
        }
        case Opcode::GetArg:
        {
            Ref indexRef = popStack(*stack);
            Value *head = refMgr->translate(indexRef);

            size_t index = toIndex(this, head);

            if (index >= args.getCount())
            {
                throwException(refMgr->createException(ExcType::IndexError, "Arg index is out of bounds."));
            }

            stack->append(refMgr->createCopy(this, args[index]));

            refMgr->destroy(this, indexRef);
            break;
        }
        case Opcode::JumpIf:
        {
            Ref cond = popStack(*stack);
            Value *head = refMgr->translate(cond);

            if (head->type != ValueType::Boolean)
            {
                throwException(refMgr->createException(ExcType::TypeError, "Jump condition is not a Boolean."));
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

            refMgr->destroy(this, cond);
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

            callstackEntry.stacks.append(List<Ref>());
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
            stack->append(refMgr->createCopy(this, exception));
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
"PushList",
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
                    Ref value = entry.variables.getValue(j);

                    std::cout << "        " << entry.variables.getKey(j).getData() << ": ";

                    Value *head = refMgr->translate(value);

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
                    case ValueType::String:
                    {
                        std::cout << '"' << ((StringValue *)head)->value.getData() << '"' << std::endl;
                        break;
                    }
                    case ValueType::List:
                    {
                        std::cout << "list" << std::endl;
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
                    Ref value = entry.stacks[entry.stacks.getCount()-1][j];

                    std::cout << "        ";

                    Value *head = refMgr->translate(value);

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
                    case ValueType::String:
                    {
                        std::cout << '"' << ((StringValue *)head)->value.getData() << '"' << std::endl;
                        break;
                    }
                    case ValueType::List:
                    {
                        std::cout << "list" << std::endl;
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

    return refMgr->createNil();
}

Ref Context::run(const Bytecode& bytecode, List<Ref> args)
{
    //This may not be safe.
    if (!setjmp(jumpBuf))
    {
        if (callStackSize == SCRIPTING_MAX_CALLSTACK_SIZE)
        {
            THROW(CallstackBoundsException)
        }

        callStack[callStackSize++] = CallstackEntry(bytecode);
        CallstackEntry& callstackEntry = callStack[callStackSize-1];

        callstackEntry.stacks.append(List<Ref>());

        Ref result = _run(bytecode, args);

        for (size_t i = 0; i < callstackEntry.stacks.getCount(); ++i)
        {
            for (size_t j = 0; j < callstackEntry.stacks[i].getCount(); ++j)
            {
                engine->getRefMgr()->destroy(this, callstackEntry.stacks[i][j]);
            }
        }

        callstackEntry.stacks.clear();

        for (size_t i = 0; i < callstackEntry.variables.getEntryCount(); ++i)
        {
            engine->getRefMgr()->destroy(this, callstackEntry.variables.getValue(i));
        }

        callstackEntry.variables.clear();

        --callStackSize;

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

            List<Ref>& stack = entry->stacks[entry->stacks.getCount()-1];

            for (size_t i = 0; i < stack.getCount(); ++i)
            {
                engine->getRefMgr()->destroy(this, stack[i]);
            }

            entry->stacks.remove(entry->stacks.getCount()-1);
            entry->offset = offset;

            Ref result = _run(entry->bytecode, List<Ref>());

            engine->getRefMgr()->destroy(this, exception);
            exception = engine->getRefMgr()->createNil();

            return result;
        }

        Ref exc = exception;

        exception = engine->getRefMgr()->createNil();

        THROW(UnhandledExcException, this, exc);
    }
}

void Context::throwException(Ref exc)
{
    if (callStackSize > 0)
    {
        engine->getRefMgr()->destroy(this, exception);
        exception = exc;

        longjmp(jumpBuf, 1);
    } else
    {
        THROW(UnhandledExcException, this, exc);
    }
}

Ref Context::popStack(List<Ref>& stack)
{
    if (stack.getCount() == 0)
    {
        THROW(StackBoundsException);
    } else
    {
        Ref result = stack[stack.getCount() - 1];
        stack.remove(stack.getCount() - 1);

        return result;
    }
}

UnhandledExcException::UnhandledExcException(const char *file_,
                                             size_t line_,
                                             const char *function_,
                                             Context *ctx_,
                                             Ref exception_)
 : ExecutionException(file_, line_, function_),
   ctx(ctx_),
   exception(exception_) {}

UnhandledExcException::UnhandledExcException(const UnhandledExcException& other)
 : ExecutionException(other.getFile(),
                      other.getLine(),
                      other.getFunction()),
   ctx(other.ctx),
   exception(ctx->getEngine()->getRefMgr()->createCopy(ctx, other.exception)) {}

UnhandledExcException::~UnhandledExcException()
{
    ctx->getEngine()->getRefMgr()->destroy(ctx, exception);
}

size_t toIndex(Context *ctx, Value *value)
{
    RefManager *refMgr = ctx->getEngine()->getRefMgr();

    if (value->type == ValueType::Int)
    {
        int64_t i = ((IntValue *)value)->value;

        if (i < 0)
        {
            ctx->throwException(refMgr->createException(ExcType::ValueError, "Index should not be below zero."));
        } else
        {
            return i;
        }
    } else if (value->type == ValueType::Float)
    {
        double i = ((FloatValue *)value)->value;

        if ((size_t)i < 0)
        {
            ctx->throwException(refMgr->createException(ExcType::ValueError, "Index should not be below zero."));
        } else
        {
            return (size_t)i;
        }
    } else
    {
        ctx->throwException(refMgr->createException(ExcType::TypeError, "Invalid index type."));
    }

    assert(false);
}

Ref getMember(Context *ctx, Value *val, Value *key)
{
    RefManager *refMgr = ctx->getEngine()->getRefMgr();

    switch (val->type)
    {
    case ValueType::Object:
    {
        if (key->type != ValueType::String)
        {
            ctx->throwException(refMgr->createException(ExcType::TypeError, "Member name must be String."));
        }

        HashMap<String, Ref> members = ((ObjectValue *)val)->members;

        int index = members.findEntry(((StringValue *)key)->value);

        if (index == -1)
        {
            ctx->throwException(refMgr->createException(ExcType::KeyError, "Unknown member."));
        }

        return refMgr->createCopy(ctx, members.getValue(index));
    }
    case ValueType::String:
    {
        String str = ((StringValue *)val)->value;

        size_t index = toIndex(ctx, key);

        if (index >= str.getLength())
        {
            ctx->throwException(refMgr->createException(ExcType::IndexError, "String index is out of bounds."));
        }

        return refMgr->createString(String(str[index]));
    }
    case ValueType::List:
    {
        List<Ref> list = ((ListValue *)val)->value;

        size_t index = toIndex(ctx, key);

        if (index >= list.getCount())
        {
            ctx->throwException(refMgr->createException(ExcType::IndexError, "List index is out of bounds."));
        }

        return refMgr->createCopy(ctx, list[index]);
    }
    case ValueType::NativeObject:
    {
        NativeObject *obj = (NativeObject *)val;

        return obj->funcs.getMember(ctx, obj, key);
    }
    case ValueType::Exception:
    {
        if (key->type != ValueType::String)
        {
            ctx->throwException(refMgr->createException(ExcType::TypeError, "Member name must be String."));
        }

        String name = ((StringValue *)key)->value;
        ExceptionValue *exc = (ExceptionValue *)val;

        if (name == "type")
        {
            switch (exc->type)
            {
            case ExcType::ValueError:
            {
                return refMgr->createString("value");
            }
            case ExcType::TypeError:
            {
                return refMgr->createString("type");
            }
            case ExcType::KeyError:
            {
                return refMgr->createString("key");
            }
            case ExcType::IndexError:
            {
                return refMgr->createString("index");
            }
            }
        } else if (name == "error")
        {
            return refMgr->createString(exc->error);
        } else
        {
            ctx->throwException(refMgr->createException(ExcType::KeyError, "Unknown member for Exception."));
        }
    }
    default:
    {
        ctx->throwException(refMgr->createException(ExcType::TypeError, "Type does not have members."));
    }
    }

    assert(false);
}

Ref setMember(Context *ctx, Value *dest, Value *key, Value *value)
{
    RefManager *refMgr = ctx->getEngine()->getRefMgr();

    switch (dest->type)
    {
    case ValueType::Object:
    {
        if (key->type != ValueType::String)
        {
            ctx->throwException(refMgr->createException(ExcType::TypeError, "Member names must be String."));
        }

        HashMap<String, Ref> members = ((ObjectValue *)dest)->members;

        Ref result = refMgr->createCopy(ctx, dest);

        ObjectValue *resultHead = (ObjectValue *)refMgr->translate(result);

        String name = ((StringValue *)key)->value;

        if (resultHead->members.findEntry(name) != -1)
        {
            refMgr->destroy(ctx, resultHead->members.get(name));
        }

        resultHead->members.set(name, refMgr->createCopy(ctx, value));

        return result;
    }
    case ValueType::String:
    {
        if (value->type != ValueType::String)
        {
            ctx->throwException(refMgr->createException(ExcType::TypeError, "A string's character can only be set as a String."));
        } else
        {
            if (((StringValue *)value)->value.getLength() != 1)
            {
                ctx->throwException(refMgr->createException(ExcType::ValueError, "String must of length 1."));
            }
        }

        String str = ((StringValue *)dest)->value;

        size_t index = toIndex(ctx, key);

        if (index >= str.getLength())
        {
            ctx->throwException(refMgr->createException(ExcType::IndexError, "String index is out of bounds."));
        }

        str[index] = ((StringValue *)value)->value[0];

        return refMgr->createCopy(ctx, dest);
    }
    case ValueType::List:
    {
        List<Ref> list = ((ListValue *)dest)->value;

        size_t index = toIndex(ctx, key);

        if (index >= list.getCount())
        {
            ctx->throwException(refMgr->createException(ExcType::IndexError, "List index is out of bounds."));
        }

        list[index] = refMgr->createCopy(ctx, value);

        return refMgr->createCopy(ctx, dest);
    }
    case ValueType::NativeObject:
    {
        Ref result = refMgr->createCopy(ctx, dest);

        NativeObject *obj = (NativeObject *)refMgr->translate(result);

        obj->funcs.setMember(ctx, obj, key, value);

        return result;
    }
    default:
    {
        ctx->throwException(refMgr->createException(ExcType::TypeError, "Type does not have members."));
    }
    }

    assert(false);
}

Ref call(Context *ctx, Value *value, const List<Ref>& args)
{
    RefManager *refMgr = ctx->getEngine()->getRefMgr();

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
        Ref result = callMethod(ctx, value, "__call__", args);
        return result;
    }
    default:
    {
        ctx->throwException(refMgr->createException(ExcType::TypeError, "Type is not callable."));
    }
    }

    assert(false);
}

Ref callMethod(Context *ctx, Value *obj, const String& methName, const List<Ref>& args)
{
    RefManager *refMgr = ctx->getEngine()->getRefMgr();

    List<Ref> args_;

    args_.append(obj->ref);
    args_.append(args);

    Ref name = refMgr->createString(methName);
    Value *nameHead = refMgr->translate(name);

    Ref func = getMember(ctx, obj, nameHead);
    Value *funcHead = refMgr->translate(func);

    Ref result = call(ctx, funcHead, args_);

    refMgr->destroy(ctx, func);
    refMgr->destroy(ctx, name);

    return result;
}

bool isInstance(Context *ctx, Value *obj, Value *type)
{
    RefManager *refMgr = ctx->getEngine()->getRefMgr();

    if (obj->type != type->type)
    {
        return false;
    }

    if (obj->type == ValueType::NativeObject)
    {
        return ((NativeObject *)obj)->typeID == ((NativeObject *)type)->typeID;
    } else if (obj->type == ValueType::Object)
    {
        HashMap<String, Ref> objMembers = ((ObjectValue *)obj)->members;
        HashMap<String, Ref> typeMembers = ((ObjectValue *)type)->members;

        int entry1 = objMembers.findEntry("__classTypeID__");
        int entry2 = typeMembers.findEntry("__typeID__");

        if (entry1 == -1 or entry2 == -1)
        {
            return false;
        }

        Value *id1 = refMgr->translate(objMembers.getValue(entry1));
        Value *id2 = refMgr->translate(objMembers.getValue(entry2));

        if (id1->type != ValueType::Int or id2->type != ValueType::Int)
        {
            ctx->throwException(refMgr->createException(ExcType::TypeError, "Type IDs must be integers."));
        }

        return ((IntValue *)id1) == ((IntValue *)id2);
    } else
    {
        return false;
    }
}
}

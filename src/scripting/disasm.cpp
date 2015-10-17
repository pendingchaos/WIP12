#include "scripting/disasm.h"
#include <iostream>
#include "scripting/vm/types.h"

namespace scripting
{
    Str indent(const Str& in)
    {
        List<Str> lines = in.split('\n');
        Str result;

        for (size_t i = 0; i < lines.getCount(); ++i)
        {
            if (i != lines.getCount()-1)
            {
                result = result + (Str("    ") + lines[i] + '\n');
            }
        }

        return result;
    }

    Str disasm(const Bytecode& bytecode)
    {
        Str result;
        size_t offset = 0;

        while (offset < bytecode.data.getSize())
        {
            result = result + Str::format("%zu: ", offset);

            Opcode opcode = bytecode.getOpcode(offset++);

            switch (opcode)
            {
            case Opcode::PushInt:
            {
                result = result + Str::format("pushInt %lld\n", bytecode.getInt64(offset));
                offset += 8;
                break;
            }
            case Opcode::PushFloat:
            {
                result = result + Str::format("pushFloat %f\n", bytecode.getDouble(offset));
                offset += 8;
                break;
            }
            case Opcode::PushBoolean:
            {
                result = result + Str::format("pushBool %s\n", bytecode.getBoolean(offset) ? "true" : "false");
                offset += 1;
                break;
            }
            case Opcode::PushNil:
            {
                result = result + "pushNil\n";
                break;
            }
            case Opcode::PushFunc:
            {
                size_t size = bytecode.getUInt32(offset);
                offset += 4;

                ResizableData data = bytecode.getData(offset, size);
                offset += size;

                Bytecode code(data);
                code.strings = bytecode.strings;

                result = result + "pushFunc\n";
                result = result + indent(disasm(code));
                break;
            }
            case Opcode::PushObject:
            {
                result = result + "pushObject\n";
                break;
            }
            case Opcode::PushString:
            {
                uint32_t index = bytecode.getUInt32(offset);
                offset += 4;

                result = result + Str::format("pushString '%s'\n", bytecode.strings[index].getData());
                break;
            }
            case Opcode::PushException:
            {
                ExcType type = (ExcType)bytecode.getUInt8(offset);
                offset += 1;

                size_t length = bytecode.getUInt32(offset);
                offset += 4;

                Str str(length, (const char *)bytecode.getData(offset, length).getData());
                offset += length;

                result = result + Str::format("pushException %d %s\n", (int)type, str.getData());
                break;
            }
            case Opcode::StackPop:
            {
                result = result + "stackPop\n";
                break;
            }
            case Opcode::StackDup:
            {
                result = result + "stackDup\n";
                break;
            }
            case Opcode::LoadVar:
            {
                result = result + "loadVar\n";
                break;
            }
            case Opcode::StoreVar:
            {
                result = result + "storeVar\n";
                break;
            }
            case Opcode::GetMember:
            {
                result = result + "getMember\n";
                break;
            }
            case Opcode::SetMember:
            {
                result = result + "setMember\n";
                break;
            }
            case Opcode::Add:
            {
                result = result + "add\n";
                break;
            }
            case Opcode::Subtract:
            {
                result = result + "subtract\n";
                break;
            }
            case Opcode::Multiply:
            {
                result = result + "multiply\n";
                break;
            }
            case Opcode::Divide:
            {
                result = result + "divide\n";
                break;
            }
            case Opcode::Modulo:
            {
                result = result + "modulo\n";
                break;
            }
            case Opcode::BoolAnd:
            {
                result = result + "boolAnd\n";
                break;
            }
            case Opcode::BoolOr:
            {
                result = result + "boolOr\n";
                break;
            }
            case Opcode::BoolNot:
            {
                result = result + "boolNot\n";
                break;
            }
            case Opcode::BitAnd:
            {
                result = result + "bitAnd\n";
                break;
            }
            case Opcode::BitOr:
            {
                result = result + "bitOr\n";
                break;
            }
            case Opcode::BitXOr:
            {
                result = result + "bitXOr\n";
                break;
            }
            case Opcode::LeftShift:
            {
                result = result + "leftShift\n";
                break;
            }
            case Opcode::RightShift:
            {
                result = result + "rightShift\n";
                break;
            }
            case Opcode::BitNot:
            {
                result = result + "bitNot\n";
                break;
            }
            case Opcode::Less:
            {
                result = result + "less\n";
                break;
            }
            case Opcode::Greater:
            {
                result = result + "greater\n";
                break;
            }
            case Opcode::Equal:
            {
                result = result + "equal\n";
                break;
            }
            case Opcode::NotEqual:
            {
                result = result + "notEqual\n";
                break;
            }
            case Opcode::LessEqual:
            {
                result = result + "lessEqual\n";
                break;
            }
            case Opcode::GreaterEqual:
            {
                result = result + "greaterEqual\n";
                break;
            }
            case Opcode::Call:
            {
                result = result + "call\n";
                break;
            }
            case Opcode::Return:
            {
                result = result + "return\n";
                break;
            }
            case Opcode::GetArgCount:
            {
                result = result + "getArgCount\n";
                break;
            }
            case Opcode::GetArg:
            {
                result = result + "getArg\n";
                break;
            }
            case Opcode::JumpIf:
            {
                int32_t success = bytecode.getInt32(offset);
                offset += 4;

                int32_t failure = bytecode.getInt32(offset);
                offset += 4;

                result = result + Str::format("jumpIf success:%zd failure:%zd\n", ptrdiff_t(offset+success), ptrdiff_t(offset+failure));
                break;
            }
            case Opcode::Jump:
            {
                int32_t by = bytecode.getInt32(offset);
                offset += 4;

                result = result + Str::format("jump dest:%zd\n", ptrdiff_t(offset+by));
                break;
            }
            case Opcode::Try:
            {
                int32_t by = bytecode.getInt32(offset);
                offset += 4;

                result = result + Str::format("try catch:%zd\n", ptrdiff_t(offset+by));
                break;
            }
            case Opcode::EndTry:
            {
                result = result + "endTry\n";
                break;
            }
            case Opcode::Throw:
            {
                result = result + "throw\n";
                break;
            }
            case Opcode::GetException:
            {
                result = result + "getException\n";
                break;
            }
            }
        }

        result = result + Str::format("%zu: <end>\n", bytecode.data.getSize());

        return result;
    }
}

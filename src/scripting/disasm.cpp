#include "scripting/disasm.h"

#include "scripting/vm/types.h"

namespace scripting
{
    String indent(const String& in)
    {
        List<String> lines = in.split('\n');
        String result;

        for (size_t i = 0; i < lines.getCount(); ++i)
        {
            if (i != lines.getCount()-1)
            {
                result.append(String("    ").append(lines[i]).append('\n'));
            }
        }

        return result;
    }

    String disasm(const Bytecode& bytecode)
    {
        String result;
        size_t offset = 0;

        while (offset < bytecode.data.getSize())
        {
            result.append(String::format("%zu: ", offset));

            Opcode opcode = bytecode.getOpcode(offset++);

            switch (opcode)
            {
            case Opcode::PushInt:
            {
                result.append(String::format("pushInt %lld\n", bytecode.getInt64(offset)));
                offset += 8;
                break;
            }
            case Opcode::PushFloat:
            {
                result.append(String::format("pushFloat %f\n", bytecode.getDouble(offset)));
                offset += 8;
                break;
            }
            case Opcode::PushBoolean:
            {
                result.append(String::format("pushBool %s\n", bytecode.getBoolean(offset) ? "true" : "false"));
                offset += 1;
                break;
            }
            case Opcode::PushNil:
            {
                result.append("pushNil\n");
                break;
            }
            case Opcode::PushFunc:
            {
                size_t size = bytecode.getUInt32(offset);
                offset += 4;

                ResizableData data = bytecode.getData(offset, size);
                offset += size;

                Bytecode code(data);

                result.append("pushFunc\n");
                result.append(indent(disasm(code)));
                break;
            }
            case Opcode::PushObject:
            {
                result.append("pushObject\n");
                break;
            }
            case Opcode::PushString:
            {
                size_t length = bytecode.getUInt32(offset);
                offset += 4;

                String str(length, (const char *)bytecode.getData(offset, length).getData());
                offset += length;

                result.append(String::format("pushString '%s'\n", str.getData()));
                break;
            }
            case Opcode::PushException:
            {
                ExcType type = (ExcType)bytecode.getUInt8(offset);
                offset += 1;

                size_t length = bytecode.getUInt32(offset);
                offset += 4;

                String str(length, (const char *)bytecode.getData(offset, length).getData());
                offset += length;

                result.append(String::format("pushException %d %s\n", (int)type, str.getData()));
                break;
            }
            case Opcode::StackPop:
            {
                result.append("stackPop\n");
                break;
            }
            case Opcode::LoadVar:
            {
                result.append("loadVar\n");
                break;
            }
            case Opcode::StoreVar:
            {
                result.append("storeVar\n");
                break;
            }
            case Opcode::DelVar:
            {
                result.append("delVar\n");
                break;
            }
            case Opcode::GetMember:
            {
                result.append("getMember\n");
                break;
                break;
            }
            case Opcode::SetMember:
            {
                result.append("setMember\n");
                break;
                break;
            }
            case Opcode::GetType:
            {
                result.append("getType\n");
                break;
            }
            case Opcode::Add:
            {
                result.append("add\n");
                break;
            }
            case Opcode::Subtract:
            {
                result.append("subtract\n");
                break;
            }
            case Opcode::Multiply:
            {
                result.append("multiply\n");
                break;
            }
            case Opcode::Divide:
            {
                result.append("divide\n");
                break;
            }
            case Opcode::Modulo:
            {
                result.append("modulo\n");
                break;
            }
            case Opcode::BoolAnd:
            {
                result.append("boolAnd\n");
                break;
            }
            case Opcode::BoolOr:
            {
                result.append("boolOr\n");
                break;
            }
            case Opcode::BoolNot:
            {
                result.append("boolNot\n");
                break;
            }
            case Opcode::BitAnd:
            {
                result.append("bitAnd\n");
                break;
            }
            case Opcode::BitOr:
            {
                result.append("bitOr\n");
                break;
            }
            case Opcode::BitXOr:
            {
                result.append("bitXOr\n");
                break;
            }
            case Opcode::LeftShift:
            {
                result.append("leftShift\n");
                break;
            }
            case Opcode::RightShift:
            {
                result.append("rightShift\n");
                break;
            }
            case Opcode::BitNot:
            {
                result.append("bitNot\n");
                break;
            }
            case Opcode::Less:
            {
                result.append("less\n");
                break;
            }
            case Opcode::Greater:
            {
                result.append("greater\n");
                break;
            }
            case Opcode::Equal:
            {
                result.append("equal\n");
                break;
            }
            case Opcode::NotEqual:
            {
                result.append("notEqual\n");
                break;
            }
            case Opcode::LessEqual:
            {
                result.append("lessEqual\n");
                break;
            }
            case Opcode::GreaterEqual:
            {
                result.append("greaterEqual\n");
                break;
            }
            case Opcode::Call:
            {
                result.append("call\n");
                break;
            }
            case Opcode::CallMethod:
            {
                result.append("callMethod\n");
                break;
            }
            case Opcode::Return:
            {
                result.append("return\n");
                break;
            }
            case Opcode::GetArgCount:
            {
                result.append("getArgCount\n");
                break;
            }
            case Opcode::GetArg:
            {
                result.append("getArg\n");
                break;
            }
            case Opcode::JumpIf:
            {
                int32_t success = bytecode.getInt32(offset);
                offset += 4;

                int32_t failure = bytecode.getInt32(offset);
                offset += 4;

                result.append(String::format("jumpIf success:%zd failure:%zd\n", ptrdiff_t(offset+success), ptrdiff_t(offset+failure)));
                break;
            }
            case Opcode::Jump:
            {
                int32_t by = bytecode.getInt32(offset);
                offset += 4;

                result.append(String::format("jump dest:%zd\n", ptrdiff_t(offset+by)));
                break;
            }
            case Opcode::Try:
            {
                int32_t by = bytecode.getInt32(offset);
                offset += 4;

                result.append(String::format("try catch:%zd\n", ptrdiff_t(offset+by)));
                break;
            }
            case Opcode::EndTry:
            {
                result.append("endTry\n");
                break;
            }
            case Opcode::Throw:
            {
                result.append("throw\n");
                break;
            }
            case Opcode::GetException:
            {
                result.append("getException\n");
                break;
            }
            }
        }

        result.append(String::format("%zu: <end>\n", bytecode.data.getSize()));

        return result;
    }
}

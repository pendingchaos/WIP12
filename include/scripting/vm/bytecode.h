#ifndef SCRIPTING_BYTECODE_H
#define SCRIPTING_BYTECODE_H

#include "containers/resizabledata.h"
#include "containers/list.h"
#include "containers/string.h"
#include "error.h"
#include "endian_utils.h"
#include <stdint.h>

namespace scripting
{
enum class Opcode
{
    PushInt,
    PushFloat,
    PushBoolean,
    PushNil,
    PushFunc,
    PushObject,
    PushString,
    PushException,
    StackPop,
    StackDup,

    LoadVar,
    StoreVar,

    GetMember,
    SetMember,

    Add,
    Subtract,
    Multiply,
    Divide,
    Modulo,
    BoolAnd,
    BoolOr,
    BoolNot,
    BitAnd,
    BitOr,
    BitNot,
    BitXOr,
    LeftShift,
    RightShift,

    Less,
    Greater,
    Equal,
    NotEqual,
    LessEqual,
    GreaterEqual,

    Call,
    Return,
    GetArgCount,
    GetArg,

    JumpIf,
    Jump,

    Try,
    EndTry,
    Throw,
    GetException
};

class BytecodeBoundsException : public Exception
{
    public:
        BytecodeBoundsException(const char *file_,
                                size_t line_,
                                const char *function_) : Exception(file_, line_, function_) {}

        virtual const char *getString() const
        {
            return "Some bytecode was not large enough.";
        }
};

class Bytecode
{
    public:
        Bytecode() {}
        Bytecode(ResizableData& data);

        int64_t getInt64(size_t offset) const
        {
            if (offset + 8 > data.getSize())
            {
                THROW(BytecodeBoundsException);
            }

            return data.getInt64LE(offset);
        }

        uint32_t getUInt32(size_t offset) const
        {
            if (offset + 4 > data.getSize())
            {
                THROW(BytecodeBoundsException);
            }

            return data.getUInt32LE(offset);
        }

        int32_t getInt32(size_t offset) const
        {
            if (offset + 4 > data.getSize())
            {
                THROW(BytecodeBoundsException);
            }

            return data.getInt32LE(offset);
        }

        double getDouble(size_t offset) const
        {
            if (offset + 8 > data.getSize())
            {
                THROW(BytecodeBoundsException);
            }

            return data.getFloat64(offset);
        }

        uint8_t getUInt8(size_t offset) const
        {
            if (offset >= data.getSize())
            {
                THROW(BytecodeBoundsException);
            }

            return data.getUInt8(offset);
        }

        bool getBoolean(size_t offset) const
        {
            return getUInt8(offset) != 0;
        }

        Opcode getOpcode(size_t offset) const
        {
            return (Opcode)getUInt8(offset);
        }

        ResizableData getData(size_t offset, size_t amount) const
        {
            if (offset+amount > data.getSize())
            {
                THROW(BytecodeBoundsException);
            }

            return ResizableData(amount, ((const uint8_t *)data.getData()) + offset);
        }

        ResizableData data;
        List<Str> strings;
};
}

#endif // SCRIPTING_BYTECODE_H

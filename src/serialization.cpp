#include "serialization.h"

#define CAST_UINT_TO_INT(fromMem) if (fromMem < 0) {THROW(SerializeException)} return fromMem;

#define NUM_CAST(min, max) switch (type)\
{\
case UInt8:\
{\
    if (uint8 > max) {THROW(SerializeException);}\
    return uint8;\
}\
case Int8:\
{\
    if (int8 < min) {THROW(SerializeException);}\
    if (int8 > max) {THROW(SerializeException);}\
    return int8;\
}\
case UInt16:\
{\
    if (uint16 > max) {THROW(SerializeException);}\
    return uint16;\
}\
case Int16:\
{\
    if (int16 < min) {THROW(SerializeException);}\
    if (int16 > max) {THROW(SerializeException);}\
    return int16;\
}\
case UInt32:\
{\
    if (uint32 > max) {THROW(SerializeException);}\
    return uint32;\
}\
case Int32:\
{\
    if (int32 < min) {THROW(SerializeException);}\
    if (int32 > max) {THROW(SerializeException);}\
    return int32;\
}\
case UInt64:\
{\
    if (uint64 > max) {THROW(SerializeException);}\
    return uint64;\
}\
case Int64:\
{\
    if (int64 < min) {THROW(SerializeException);}\
    if (int64 > max) {THROW(SerializeException);}\
    return int64;\
}\
default:\
{\
    THROW(SerializeException);\
}\
}

Serializable::operator uint8_t () const
{
    NUM_CAST(0, UINT8_MAX);
}

Serializable::operator int8_t () const
{
    NUM_CAST(INT8_MIN, INT8_MAX);
}

Serializable::operator uint16_t () const
{
    NUM_CAST(0, UINT16_MAX);
}

Serializable::operator int16_t () const
{
    NUM_CAST(INT16_MIN, INT16_MAX);
}

Serializable::operator uint32_t () const
{
    NUM_CAST(0, UINT32_MAX);
}

Serializable::operator int32_t () const
{
    NUM_CAST(INT32_MIN, INT32_MAX);
}

Serializable::operator uint64_t () const
{
    NUM_CAST(0, UINT64_MAX)
}

Serializable::operator int64_t () const
{
    NUM_CAST(INT64_MIN, INT64_MAX)
}

bool Serializable::operator == (const Serializable& other) const
{
    if (type != other.type)
    {
        return false;
    }

    switch (type)
    {
    case UInt8:
    {
        return uint8 == other.uint8;
    }
    case Int8:
    {
        return int8 == other.int8;
    }
    case UInt16:
    {
        return uint16 == other.uint16;
    }
    case Int16:
    {
        return int16 == other.int16;
    }
    case UInt32:
    {
        return uint32 == other.uint32;
    }
    case Int32:
    {
        return int32 == other.int32;
    }
    case UInt64:
    {
        return uint64 == other.uint64;
    }
    case Int64:
    {
        return int64 == other.int64;
    }
    case StringType:
    {
        return string == other.string;
    }
    case Boolean:
    {
        return boolean == other.boolean;
    }
    case HashMapType:
    {
        return hashmap == other.hashmap;
    }
    case Float:
    {
        return float_ == other.float_;
    }
    case Float2Type:
    {
        return float2.x == other.float2.x and float2.y == other.float2.y;
    }
    case Float3Type:
    {
        return float3.x == other.float3.x and
               float3.y == other.float3.y and
               float3.z == other.float3.z;
    }
    case Float4Type:
    {
        return float4.x == other.float4.x and
               float4.y == other.float4.y and
               float4.z == other.float4.z and
               float4.w == other.float4.w;
    }
    case Int2Type:
    {
        return int2.x == other.int2.x and int2.y == other.int2.y;
    }
    case Int3Type:
    {
        return int3.x == other.int3.x and
               int3.y == other.int3.y and
               int3.z == other.int3.z;
    }
    case Int4Type:
    {
        return int4.x == other.int4.x and
               int4.y == other.int4.y and
               int4.z == other.int4.z and
               int4.w == other.int4.w;
    }
    case UInt2Type:
    {
        return uint2.x == other.uint2.x and uint2.y == other.uint2.y;
    }
    case UInt3Type:
    {
        return uint3.x == other.uint3.x and
               uint3.y == other.uint3.y and
               uint3.z == other.uint3.z;
    }
    case UInt4Type:
    {
        return uint4.x == other.uint4.x and
               uint4.y == other.uint4.y and
               uint4.z == other.uint4.z and
               uint4.w == other.uint4.w;
    }
    case ListType:
    {
        return list == other.list;
    }
    case Object:
    {
        return object == other.object;
    }
    }

    return false;
}

void Serializable::writeToFile(File *file)
{
    file->writeUInt8((uint8_t)type);

    switch (type)
    {
    case UInt8:
    {
        file->writeUInt8(uint8);
        break;
    }
    case Int8:
    {
        file->writeInt8(int8);
        break;
    }
    case UInt16:
    {
        file->writeUInt16LE(uint16);
        break;
    }
    case Int16:
    {
        file->writeInt16LE(int16);
        break;
    }
    case UInt32:
    {
        file->writeUInt32LE(uint32);
        break;
    }
    case Int32:
    {
        file->writeInt32LE(int32);
        break;
    }
    case UInt64:
    {
        file->writeUInt64LE(uint64);
        break;
    }
    case Int64:
    {
        file->writeInt64LE(int64);
        break;
    }
    case StringType:
    {
        file->writeUInt32LE(string.getLength());
        file->write(string.getLength(), string.getData());
        break;
    }
    case Boolean:
    {
        file->writeUInt8(boolean ? 1 : 0);
        break;
    }
    case HashMapType:
    {
        file->writeUInt32LE(hashmap.getEntryCount());

        for (size_t i = 0; i < hashmap.getEntryCount(); ++i)
        {
            hashmap.getKey(i).writeToFile(file);
            hashmap.getValue(i).writeToFile(file);
        }
        break;
    }
    case ListType:
    {
        file->writeUInt32LE(list.getCount());

        for (auto elem : list)
        {
            elem.writeToFile(file);
        }
        break;
    }
    case Object:
    {
        file->writeUInt32LE(object.getEntryCount());

        for (size_t i = 0; i < object.getEntryCount(); ++i)
        {
            const String& key = object.getKey(i);

            file->writeUInt32LE(key.getLength());
            file->write(key.getLength(), key.getData());

            object.getValue(i).writeToFile(file);
        }
        break;
    }
    case Float:
    {
        file->writeFloat32(float_);
        break;
    }
    case Float2Type:
    {
        file->writeFloat32(float2.x);
        file->writeFloat32(float2.y);
        break;
    }
    case Float3Type:
    {
        file->writeFloat32(float3.x);
        file->writeFloat32(float3.y);
        file->writeFloat32(float3.z);
        break;
    }
    case Float4Type:
    {
        file->writeFloat32(float4.x);
        file->writeFloat32(float4.y);
        file->writeFloat32(float4.z);
        file->writeFloat32(float4.w);
        break;
    }
    case Int2Type:
    {
        file->writeInt32LE(int2.x);
        file->writeInt32LE(int2.y);
        break;
    }
    case Int3Type:
    {
        file->writeInt32LE(int3.x);
        file->writeInt32LE(int3.y);
        file->writeInt32LE(int3.z);
        break;
    }
    case Int4Type:
    {
        file->writeInt32LE(int4.x);
        file->writeInt32LE(int4.y);
        file->writeInt32LE(int4.z);
        file->writeInt32LE(int4.w);
    }
    case UInt2Type:
    {
        file->writeUInt32LE(uint2.x);
        file->writeUInt32LE(uint2.y);
        break;
    }
    case UInt3Type:
    {
        file->writeUInt32LE(uint3.x);
        file->writeUInt32LE(uint3.y);
        file->writeUInt32LE(uint3.z);
        break;
    }
    case UInt4Type:
    {
        file->writeUInt32LE(uint4.x);
        file->writeUInt32LE(uint4.y);
        file->writeUInt32LE(uint4.z);
        file->writeUInt32LE(uint4.w);
    }
    }
}

void Serializable::readFromFile(File *file)
{
    type = (Type)file->readUInt8();

    switch (type)
    {
    case UInt8:
    {
        uint8 = file->readUInt8();
        break;
    }
    case Int8:
    {
        int8 = file->readInt8();
        break;
    }
    case UInt16:
    {
        uint16 = file->readUInt16LE();
        break;
    }
    case Int16:
    {
        int16 = file->readInt16LE();
        break;
    }
    case UInt32:
    {
        uint32 = file->readUInt32LE();
        break;
    }
    case Int32:
    {
        int32 = file->readInt32LE();
        break;
    }
    case UInt64:
    {
        uint64 = file->readUInt64LE();
        break;
    }
    case Int64:
    {
        int64 = file->readInt64LE();
        break;
    }
    case StringType:
    {
        uint32_t length = file->readUInt32LE();

        string = String((size_t)length);

        file->read(string.getLength(), string.getData());
        break;
    }
    case Boolean:
    {
        boolean = file->readUInt8() != 0;
        break;
    }
    case HashMapType:
    {
        size_t numEntries = file->readUInt32LE();

        for (size_t i = 0; i < numEntries; ++i)
        {
            Serializable key;
            Serializable value;

            key.readFromFile(file);
            value.readFromFile(file);

            hashmap.set(key, value);
        }
        break;
    }
    case ListType:
    {
        size_t count = file->readUInt32LE();

        for (size_t i = 0; i < count; ++i)
        {
            Serializable value;

            value.readFromFile(file);

            list.append(value);
        }
        break;
    }
    case Object:
    {
        size_t numEntries = file->readUInt32LE();

        for (size_t i = 0; i < numEntries; ++i)
        {
            String key((size_t)file->readUInt32LE());
            file->read(key.getLength(), key.getData());

            Serializable value;

            value.readFromFile(file);

            object.set(key, value);
        }
        break;
    }
    case Float:
    {
        float_ = file->readFloat32();
        break;
    }
    case Float2Type:
    {
        float2.x = file->readFloat32();
        float2.y = file->readFloat32();
        break;
    }
    case Float3Type:
    {
        float3.x = file->readFloat32();
        float3.y = file->readFloat32();
        float3.z = file->readFloat32();
        break;
    }
    case Float4Type:
    {
        float4.x = file->readFloat32();
        float4.y = file->readFloat32();
        float4.z = file->readFloat32();
        float4.w = file->readFloat32();
        break;
    }
    case Int2Type:
    {
        int2.x = file->readInt32LE();
        int2.y = file->readInt32LE();
        break;
    }
    case Int3Type:
    {
        int3.x = file->readInt32LE();
        int3.y = file->readInt32LE();
        int3.z = file->readInt32LE();
        break;
    }
    case Int4Type:
    {
        int4.x = file->readInt32LE();
        int4.y = file->readInt32LE();
        int4.z = file->readInt32LE();
        int4.w = file->readInt32LE();
    }
    case UInt2Type:
    {
        uint2.x = file->readInt32LE();
        uint2.y = file->readInt32LE();
        break;
    }
    case UInt3Type:
    {
        uint3.x = file->readInt32LE();
        uint3.y = file->readInt32LE();
        uint3.z = file->readInt32LE();
        break;
    }
    case UInt4Type:
    {
        uint4.x = file->readInt32LE();
        uint4.y = file->readInt32LE();
        uint4.z = file->readInt32LE();
        uint4.w = file->readInt32LE();
    }
    }
}

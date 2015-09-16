#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include "error.h"
#include "containers/string.h"
#include "containers/hashmap.h"
#include "containers/list.h"
#include "math/t2.h"
#include "math/t3.h"
#include "math/t4.h"
#include "file.h"

#include <stdint.h>

class SerializeException : public Exception
{
    public:
        SerializeException(const char *file_,
                           size_t line_,
                           const char *function_) : Exception(file_, line_, function_) {}
};

class Serializable
{
    public:
        enum Type
        {
            UInt8,
            Int8,
            UInt16,
            Int16,
            UInt32,
            Int32,
            UInt64,
            Int64,
            StringType,
            Boolean,
            HashMapType,
            ListType,
            Object,
            Float,
            Float2Type,
            Float3Type,
            Float4Type,
            Int2Type,
            Int3Type,
            Int4Type,
            UInt2Type,
            UInt3Type,
            UInt4Type
        };

        Serializable() : type(Object) {}
        Serializable(uint8_t value) : type(UInt8), uint8(value) {}
        Serializable(int8_t value) : type(Int8), int8(value) {}
        Serializable(uint16_t value) : type(UInt16), uint16(value) {}
        Serializable(int16_t value) : type(Int16), int16(value) {}
        Serializable(uint32_t value) : type(UInt32), uint32(value) {}
        Serializable(int32_t value) : type(Int32), int32(value) {}
        Serializable(uint64_t value) : type(UInt64), uint64(value) {}
        Serializable(int64_t value) : type(Int64), int64(value) {}
        Serializable(const String& value) : type(StringType), string(value.copy()) {}
        Serializable(bool value) : type(Boolean), boolean(value) {}
        template <typename Key, typename Value>
        Serializable(const HashMap<Key, Value>& value);
        template <typename T>
        Serializable(const List<T>& value);
        Serializable(float value) : type(Float), float_(value) {}
        Serializable(const Float2& value) : type(Float2Type), float2({value.x, value.y}) {}
        Serializable(const Float3& value) : type(Float3Type), float3({value.x, value.y, value.z}) {}
        Serializable(const Float4& value) : type(Float4Type), float4({value.x, value.y, value.z, value.w}) {}
        Serializable(const Int2& value) : type(Int2Type), int2({value.x, value.y}) {}
        Serializable(const Int3& value) : type(Int3Type), int3({value.x, value.y, value.z}) {}
        Serializable(const Int4& value) : type(Int4Type), int4({value.x, value.y, value.z, value.w}) {}
        Serializable(const UInt2& value) : type(UInt2Type), uint2({value.x, value.y}) {}
        Serializable(const UInt3& value) : type(UInt3Type), uint3({value.x, value.y, value.z}) {}
        Serializable(const UInt4& value) : type(UInt4Type), uint4({value.x, value.y, value.z, value.w}) {}

        inline Type getType() const
        {
            return type;
        }

        inline Serializable get(const String& key) const
        {
            if (type == Object)
            {
                try
                {
                    return object.get(key);
                } catch (LookupException& e)
                {
                    THROW(SerializeException);
                }
            } else
            {
                THROW(SerializeException);
            }
        }

        template <typename T>
        inline void get(const String& key, T& value) const
        {
            value = (T)get(key);
        }

        inline void set(const String& key, Serializable value)
        {
            if (type == Object)
            {
                object.set(key, value);
            } else
            {
                THROW(SerializeException);
            }
        }

        template <typename T>
        inline void set(const String& key, const T& value);

        explicit operator uint8_t () const;
        explicit operator int8_t () const;
        explicit operator uint16_t () const;
        explicit operator int16_t () const;
        explicit operator uint32_t () const;
        explicit operator int32_t () const;
        explicit operator uint64_t () const;
        explicit operator int64_t () const;

        explicit operator String () const
        {
            if (type == StringType)
            {
                return string.copy();
            } else
            {
                THROW(SerializeException);
            }
        }

        template <typename Key, typename Value>
        explicit operator HashMap<Key, Type> () const
        {
            if (type == HashMapType)
            {
                HashMap<Key, Value> result;

                for (size_t i = 0; i < hashmap.getEntryCount(); ++i)
                {
                    result.set((Key)hashmap.getKey(i), (Value)hashmap.getValue(i));
                }

                return result;
            } else
            {
                THROW(SerializeException);
            }
        }

        template <typename T>
        explicit operator List<T> () const
        {
            if (type == ListType)
            {
                List<T> result;

                for (auto elem : list)
                {
                    result.append((T)elem);
                }
            } else
            {
                THROW(SerializeException);
            }
        }

        explicit operator bool () const
        {
            if (type == Boolean)
            {
                return boolean;
            } else
            {
                THROW(SerializeException);
            }
        }

        explicit operator float () const
        {
            if (type == Float)
            {
                return float_;
            } else
            {
                THROW(SerializeException);
            }
        }

        explicit operator Float2 () const
        {
            if (type == Float2Type)
            {
                return Float2(float2.x, float2.y);
            } else
            {
                THROW(SerializeException);
            }
        }

        explicit operator Float3 () const
        {
            if (type == Float3Type)
            {
                return Float3(float3.x, float3.y, float3.z);
            } else
            {
                THROW(SerializeException);
            }
        }

        explicit operator Float4 () const
        {
            if (type == Float4Type)
            {
                return Float4(float4.x, float4.y, float4.z, float4.w);
            } else
            {
                THROW(SerializeException);
            }
        }

        explicit operator Int2 () const
        {
            if (type == Int2Type)
            {
                return Int2(int2.x, int2.y);
            } else
            {
                THROW(SerializeException);
            }
        }

        explicit operator Int3 () const
        {
            if (type == Int3Type)
            {
                return Int3(int3.x, int3.y, int3.z);
            } else
            {
                THROW(SerializeException);
            }
        }

        explicit operator Int4 () const
        {
            if (type == Int4Type)
            {
                return Int4(int4.x, int4.y, int4.z, int4.w);
            } else
            {
                THROW(SerializeException);
            }
        }

        explicit operator UInt2 () const
        {
            if (type == UInt2Type)
            {
                return UInt2(uint2.x, uint2.y);
            } else
            {
                THROW(SerializeException);
            }
        }

        explicit operator UInt3 () const
        {
            if (type == UInt3Type)
            {
                return UInt3(uint3.x, uint3.y, uint3.z);
            } else
            {
                THROW(SerializeException);
            }
        }

        explicit operator UInt4 () const
        {
            if (type == UInt4Type)
            {
                return UInt4(uint4.x, uint4.y, uint4.z, uint4.w);
            } else
            {
                THROW(SerializeException);
            }
        }

        bool operator == (const Serializable& other) const;

        void writeToFile(File *file);
        void readFromFile(File *file);
    private:
        Type type;
        union
        {
            uint8_t uint8;
            int8_t int8;
            uint16_t uint16;
            int16_t int16;
            uint32_t uint32;
            int32_t int32;
            uint64_t uint64;
            int64_t int64;
            bool boolean;
            float float_;
            struct {float x; float y;} float2;
            struct {float x; float y; float z;} float3;
            struct {float x; float y; float z; float w;} float4;
            struct {int x; int y;} int2;
            struct {int x; int y; int z;} int3;
            struct {int x; int y; int z; int w;} int4;
            struct {unsigned int x; unsigned int y;} uint2;
            struct {unsigned int x; unsigned int y; unsigned int z;} uint3;
            struct {unsigned int x; unsigned int y; unsigned int z; unsigned int w;} uint4;
        };
        String string;
        HashMap<Serializable, Serializable> hashmap;
        HashMap<String, Serializable> object;
        List<Serializable> list;
};

template <typename T>
Serializable serialize(const T& value)
{
    return Serializable(value);
}

template <typename Key, typename Value>
Serializable::Serializable(const HashMap<Key, Value>& value)
{
    for (size_t i = 0; i < value.getEntryCount(); ++i)
    {
        hashmap.set(serialize(value.getKey(i)), serialize(value.getValue(i)));
    }
}

template <typename T>
Serializable::Serializable(const List<T>& value)
{
    for (auto elem : value)
    {
        list.append(serialize(elem));
    }
}

template <typename T>
inline void Serializable::set(const String& key, const T& value)
{
    set(key, serialize(value));
}

#endif // SERIALIZATION_H

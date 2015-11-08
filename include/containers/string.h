#ifndef STRING_H
#define STRING_H

#include "containers/resizabledata.h"
#include "containers/list.h"
#include "misc_macros.h"
#include "memory.h"
#include "utils.h"

#include <stddef.h>
#include <stdint.h>
#include <cstring>
#include <cstdio>
#include <cstdarg>
#include <limits.h>

STATIC_ASSERT_FAIL_IF_FALSE(CHAR_BIT == 8)

#if __WORDSIZE == 64
#define STR_HASH_PRIME 1099511628211ULL
#else
#define STR_HASH_PRIME 16777619UL
#endif
#define STR_HASH_BASIS 0xc70f6907UL

size_t calcHash(const char *str);

inline size_t calcCharHash(char c)
{
    return (STR_HASH_BASIS ^ union_cast<unsigned char>(c)) * STR_HASH_PRIME;
}

constexpr size_t _calcHash(char c, const char *rest, size_t value)
{
    return c == '\x00' ?
           value :
           _calcHash(rest[0], rest+1, (value ^ c) * STR_HASH_PRIME);
}

constexpr size_t calcHashConst(const char *str)
{
    return _calcHash(str[0], str+1, STR_HASH_BASIS);
}

template <size_t V>
struct pass
{
    static constexpr size_t v = V;
};

#define CPL_STR_HASH(s) pass<calcHashConst(s)>::v

//Refcount(uint32_t) - length(uint32_t) - hash(size_t) - data(char *)
class Str
{
    public:
        Str();
        Str(const char *str);
        Str(size_t length, const char *data);
        Str(char c);
        Str(const Str& a, const Str& b);

        Str(const Str& other) : datav(other.datav)
        {
            setRefCount(getRefCount()+1);
        }

        ~Str();

        Str& operator = (const Str& other);

        bool operator == (const Str& other) const
        {
            return getHash() == other.getHash() ? (strcmp(getData(), other.getData()) == 0) : false;
        }

        bool operator != (const Str& other) const
        {
            return not (*this == other);
        }

        bool operator == (const char *other) const
        {
            return strcmp(getData(), other) == 0;
        }

        bool operator != (const char *other) const
        {
            return not (*this == other);
        }

        bool equals(const char *str, size_t hash) const
        {
            return getHash() == hash ? (*this == str) : false;
        }

        const char& operator [] (std::size_t index) const
        {
            #ifdef DEBUG
            if (index >= getLength())
            {
                THROW(BoundsException);
            }
            #endif

            return getData()[index];
        }

        Str operator + (const Str& other) const
        {
            return Str(*this, other);
        }

        //Super-efficient
        Str operator + (char other) const
        {
            return Str(*this, Str(other));
        }

        const char *getData() const
        {
            return (const char *)(data8+8+sizeof(size_t));
        }

        size_t getLength() const
        {
            return data32[1];
        }

        int find(char character) const;

        int find(const Str& toFind) const;
        int findLast(char character) const;
        Str subStr(size_t offset, size_t length) const;
        static Str format(const char *format, ...);

        static Str formatValue(int value)
        {
            return Str::format("%i", value);
        }

        static Str formatValue(unsigned int value)
        {
            return Str::format("%u", value);
        }

        static Str formatValue(long long int value)
        {
            return Str::format("%lli", value);
        }

        static Str formatValue(unsigned long long int value)
        {
            return Str::format("%llu", value);
        }

        static Str formatValue(float value)
        {
            return Str::format("%f", value);
        }

        static Str formatValue(double value)
        {
            return Str::format("%f", value);
        }

        bool startsWith(const Str& with, size_t offset=0) const;
        bool splitLeftRight(char separator, Str& left, Str& right) const;
        List<Str> split(char separator) const;

        class Iterator
        {
            friend Str;

            public:
                char operator * () const
                {
                    return str[i];
                }

                Iterator& operator ++ ()
                {
                    ++i;
                    return *this;
                }

                bool operator != (const Iterator& other) const
                {
                    return i != other.i;
                }
            private:
                Iterator(Str& str_, size_t i_) : str(str_), i(i_) {}

                const Str& str;
                size_t i;
        };

        Iterator begin() NO_BIND
        {
            return Iterator(*this, 0);
        }

        Iterator end() NO_BIND
        {
            return Iterator(*this, getLength());
        }

        size_t getHash() const
        {
            return *(size_t *)(data8+8);
        }
    private:
        char *_getData()
        {
            return (char *)(data8+8+sizeof(size_t));
        }

        void setHash(size_t hash)
        {
            *(size_t *)(data8+8) = hash;
        }

        void setLength(uint32_t length)
        {
            data32[1] = length;
        }

        void setRefCount(uint32_t count)
        {
            data32[0] = count;
        }

        uint32_t getRefCount() const
        {
            return data32[0];
        }

        void allocate(size_t length)
        {
            datav = ALLOCATE(9+sizeof(size_t)+length);
            setLength(length);
            setRefCount(1);
        }

        union
        {
            void *datav;
            uint8_t *data8;
            uint32_t *data32;
        };
};

size_t calcHash(const Str& value);

inline size_t getHash(const Str& value)
{
    return value.getHash();
}

#endif // STRING_H

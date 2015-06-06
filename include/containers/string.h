#ifndef STRING_H
#define STRING_H

#include "containers/resizabledata.h"
#include "misc_macros.h"
#include "memory.h"

#include <stddef.h>
#include <stdint.h>
#include <cstring>
#include <cstdio>
#include <cstdarg>
#include <limits.h>

STATIC_ASSERT_FAIL_IF_FALSE(CHAR_BIT == 8)

class String
{
    public:
        String() : data(1)
        {
            getData()[0] = '\x00';
        }

        String(size_t length) : data(length+1)
        {
            getData()[length] = '\x00';
        }

        String(size_t length, const char *data_) : data(length, data_)
        {
            data.resize(length+1);
            getData()[length] = '\x00';
        }

        String(const char *data_) : data(std::strlen(data_)+1, data_) {}

        inline bool operator == (const String& other) const
        {
            return data == other.data;
        }

        inline bool operator != (const String& other) const
        {
            return data != other.data;
        }

        inline bool operator == (const char *other) const
        {
            return std::strcmp(getData(), other) == 0;
        }

        inline bool operator != (const char *other) const
        {
            return not (*this == other);
        }

        inline const char& operator [] (std::size_t index) const
        {
            #ifdef DEBUG
            if (index >= getLength())
            {
                THROW(BoundsException);
            }
            #endif

            return getData()[index];
        }

        inline char& operator [] (std::size_t index)
        {
            #ifdef DEBUG
            if (index >= getLength())
            {
                THROW(BoundsException);
            }
            #endif

            return getData()[index];
        }

        inline char *getData()
        {
            return reinterpret_cast<char *>(data.getData());
        }

        inline const char *getData() const
        {
            return reinterpret_cast<const char *>(data.getData());
        }

        inline size_t getLength() const
        {
            return data.getSize() - 1;
        }

        String& append(char toAppend)
        {
            data.insert(getLength(), 1, &toAppend);

            return *this;
        }

        String& append(std::size_t length, const char *toAppend)
        {
            insert(getLength(), length, toAppend);

            return *this;
        }

        String& append(const char *toAppend)
        {
            append(std::strlen(toAppend), toAppend);

            return *this;
        }

        String& append(const String& toAppend)
        {
            append(toAppend.getLength(), toAppend.getData());

            return *this;
        }

        void insert(std::size_t start, std::size_t length, const char *toInsert)
        {
            #ifdef DEBUG
            if (start > getLength())
            {
                THROW(BoundsException);
            }
            #endif

            data.insert(start, length, toInsert);
        }

        void insert(std::size_t start, const char *toInsert)
        {
            #ifdef DEBUG
            if (start > getLength())
            {
                THROW(BoundsException);
            }
            #endif

            data.insert(start, std::strlen(toInsert), toInsert);
        }

        inline void insert(std::size_t start, const String& toInsert)
        {
            #ifdef DEBUG
            if (start > getLength())
            {
                THROW(BoundsException);
            }
            #endif

            insert(start, toInsert.getLength(), toInsert.getData());
        }

        void remove(std::size_t index, std::size_t length)
        {
            #ifdef DEBUG
            if (index+length > getLength())
            {
                THROW(BoundsException);
            }
            #endif

            data.remove(index, length);
        }

        void clear()
        {
            data.resize(1);
            getData()[0] = '\x00';
        }

        void resize(std::size_t length)
        {
            data.resize(length+1);
            getData()[length] = '\x00';
        }

        int find(char character) const
        {
            const char *chars = getData();

            for (size_t i = 0; i < getLength(); ++i)
            {
                if (chars[i] == character)
                {
                    return i;
                }
            }

            return -1;
        }

        int findLast(char character) const
        {
            const char *chars = getData();

            for (int i = getLength()-1; i > 0; --i)
            {
                if (chars[i] == character)
                {
                    return i;
                }
            }

            return -1;
        }

        String subStr(size_t offset, size_t length) const
        {
            #ifdef DEBUG
            if (offset+length > getLength())
            {
                THROW(BoundsException);
            }
            #endif

            return String(length, getData()+offset);
        }

        inline String copy() const
        {
            return String(getData());
        }

        inline void copyFrom(const String& other)
        {
            resize(other.getLength());
            std::memcpy(getData(), other.getData(), getLength());
        }

        inline static String format(const char *format, ...)
        {
            va_list list;
            va_start(list, format);

            va_list list2;
            va_copy(list2, list);

            char dummy_buf[1];
            int amount = vsnprintf(dummy_buf, 0, format, list2);

            va_end(list2);

            if (amount < 0)
            {
                va_end(list);

                return "";
            }

            String result(amount);
            vsnprintf(result.getData(), result.getLength()+1, format, list);

            va_end(list);

            return result;
        }

        inline static String formatValue(int value)
        {
            return String::format("i", value);
        }

        inline static String formatValue(unsigned int value)
        {
            return String::format("u", value);
        }

        inline static String formatValue(long long value)
        {
            return String::format("lli", value);
        }

        inline static String formatValue(unsigned long long value)
        {
            return String::format("llu", value);
        }

        inline static String formatValue(float value)
        {
            return String::format("f", value);
        }
    private:
        ResizableData data;
};

size_t getHash(const String& value);

#endif // STRING_H

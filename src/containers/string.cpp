#include "containers/string.h"

#include "memory.h"

#include <cstdio>

//https://github.com/gcc-mirror/gcc/blob/master/libstdc++-v3/libsupc++/hash_bytes.cc

size_t calcHash(const char *str)
{
    std::size_t result = STR_HASH_BASIS;

    char c;
    while ((c = *(str++)) != '\x00')
    {
        result = (result ^ c) * STR_HASH_PRIME;
    }

    return result;
}

size_t calcHash(const Str& value)
{
    std::size_t result = STR_HASH_BASIS;

    for (size_t i = 0; i < value.getLength(); ++i)
    {
        result = (result ^ value[i]) * STR_HASH_PRIME;
    }

    return result;
}

Str::Str()
{
    allocate(0);
    setHash(STR_HASH_PRIME);
    _getData()[0] = '\x00';
}

Str::Str(const char *str)
{
    size_t length = std::strlen(str);

    allocate(length);
    setHash(calcHash(str));
    std::memcpy(_getData(), str, length+1);
}

Str::Str(size_t length, const char *data)
{
    allocate(length);
    std::memcpy(_getData(), data, length);
    _getData()[length] = '\x00';
    setHash(calcHash(getData()));
}

Str::Str(char c)
{
    allocate(1);
    _getData()[0] = c;
    _getData()[1] = '\x00';
    setHash(calcCharHash(c));
}

Str::Str(const Str& a, const Str& b)
{
    size_t lena = a.getLength();
    size_t lenb = b.getLength();

    allocate(lena+lenb);
    std::memcpy(_getData(), a.getData(), lena);
    std::memcpy(_getData()+lena, b.getData(), lenb);
    _getData()[lena+lenb] = '\x00';
    setHash(calcHash(getData()));
}

Str::~Str()
{
    setRefCount(getRefCount()-1);
    if (getRefCount() == 0)
    {
        DEALLOCATE(datav);
    }
}

Str& Str::operator = (const Str& other)
{
    setRefCount(getRefCount()-1);
    if (getRefCount() == 0)
    {
        DEALLOCATE(datav);
    }

    datav = other.datav;
    setRefCount(getRefCount()+1);

    return *this;
}

Str& Str::operator = (const Str&& other)
{
    setRefCount(getRefCount()-1);
    if (getRefCount() == 0)
    {
        DEALLOCATE(datav);
    }

    datav = other.datav;

    return *this;
}

int Str::find(char character) const
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

int Str::find(const Str& toFind) const
{
    if (toFind.getLength() > getLength())
    {
        return -1;
    }

    for (size_t i = 0; i+toFind.getLength() <= getLength(); ++i)
    {
        bool found = true;

        for (size_t j = 0; j < toFind.getLength(); ++j)
        {
            if (getData()[i+j] != toFind[j])
            {
                found = false;
                break;
            }
        }

        if (found)
        {
            return i;
        }
    }

    return -1;
}

int Str::findLast(char character) const
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

Str Str::subStr(size_t offset, size_t length) const
{
    #ifdef DEBUG
    if (offset+length > getLength())
    {
        THROW(BoundsException);
    }
    #endif

    return Str(length, getData()+offset);
}

Str Str::format(const char *format, ...)
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

        return Str();
    }

    char result[amount+1];
    vsnprintf(result, amount+1, format, list);
    result[amount] = '\x00';

    va_end(list);

    return Str(amount, result);
}

bool Str::startsWith(const Str& with, size_t offset) const
{
    if (getLength() < with.getLength()+offset)
    {
        return false;
    }

    for (size_t i = 0; i < with.getLength(); ++i)
    {
        if ((*this)[i+offset] != with[i])
        {
            return false;
        }
    }

    return true;
}

bool Str::splitLeftRight(char separator, Str& left, Str& right) const
{
    int location = find(separator);

    if (location == -1)
    {
        return false;
    }

    left = subStr(0, location);
    right = subStr(location+1, getLength()-location-1);

    return true;
}

List<Str> Str::split(char separator) const
{
    List<Str> result;

    Str left;
    Str right = *this;
    while (right.splitLeftRight(separator, left, right))
    {
        result.append(left);
    }

    result.append(right);

    return result;
}

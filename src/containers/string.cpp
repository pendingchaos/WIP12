#include "containers/string.h"

#include "memory.h"

#include <cstdio>

size_t getHash(const String& value)
{
    //https://github.com/gcc-mirror/gcc/blob/master/libstdc++-v3/libsupc++/hash_bytes.cc
    std::size_t result = 0xc70f6907UL;

    for (size_t i = 0; i < value.getLength(); ++i)
    {
        result ^= value[i];
        #if __WORDSIZE == 64
        result *= 1099511628211ULL;
        #else
        result *= 16777619UL;
        #endif
    }

    return result;
}

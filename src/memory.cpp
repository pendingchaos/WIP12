#include "memory.h"

#include <cstring>
#include <cstdlib>

#include <iostream>
#include <map>
#include "backtrace.h"

void *_alloc(size_t amount)
{
    void *mem = std::malloc(amount);

    #ifdef DEBUG
    if (mem == nullptr)
    {
        THROW(MemoryException);
    }
    #endif

    return mem;
}

std::map<void *, AllocInfo> allocs;

void setAllocInfo(void *ptr, AllocInfo info)
{
    allocs[ptr] = info;
}

bool _allocDelete(void *ptr)
{
    auto pos = allocs.find(ptr);

    if (pos != allocs.end())
    {
        if (not pos->second.scriptRef)
        {
            allocs.erase(pos);
            return true;
        } else
        {
            pos->second.cppRef = false;
            return false;
        }
    }

    return true;
}

bool _scriptDeletePart(void *ptr)
{
    auto pos = allocs.find(ptr);

    if (pos != allocs.end())
    {
        if (not pos->second.cppRef)
        {
            allocs.erase(pos);
            return true;
        } else
        {
            pos->second.scriptRef = false;
            return false;
        }
    }

    return false;
}

AllocInfo getAllocInfo(void *ptr)
{
    auto pos = allocs.find(ptr);

    if (pos != allocs.end())
    {
        return pos->second;
    }

    return AllocInfo();
}

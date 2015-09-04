#include "memory.h"

#include <cstring>
#include <cstdlib>

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

struct Allocation
{
    void *ptr;
    AllocInfo info;
};

size_t numAllocs = 0;
Allocation *allocs = nullptr;

void _allocAtExit()
{
    free(allocs);
}

void setAllocInfo(void *ptr, AllocInfo info)
{
    if (allocs != nullptr)
    {
        for (size_t i = 0; i < numAllocs; ++i)
        {
            if (allocs[i].ptr == ptr)
            {
                allocs[i].info = info;
                return;
            }
        }

        allocs = (Allocation *)std::realloc(allocs, (numAllocs+1) * sizeof(Allocation));

        allocs[numAllocs].ptr = ptr;
        allocs[numAllocs++].info = info;
    } else
    {
        allocs = (Allocation *)malloc(sizeof(Allocation));
        allocs[0].ptr = ptr;
        allocs[0].info = info;

        std::atexit(_allocAtExit);
    }
}

bool _allocDelete(void *ptr)
{
    if (allocs != nullptr)
    {
        for (size_t i = 0; i < numAllocs; ++i)
        {
            if (allocs[i].ptr == ptr and
                not allocs[i].info.cppRef and
                not allocs[i].info.scriptRef)
            {
                std::memcpy(allocs+i, allocs+i+1, (numAllocs-i-1) * sizeof(Allocation));

                --numAllocs;
                allocs = (Allocation *)std::realloc(allocs, numAllocs * sizeof(Allocation));
                return true;
            } else if (allocs[i].ptr == ptr)
            {
                return false;
            }
        }
    }

    return true;
}

bool shouldScriptDelete(void *ptr)
{
    if (allocs != nullptr)
    {
        for (size_t i = 0; i < numAllocs; ++i)
        {
            if (allocs[i].ptr == ptr and
                not allocs[i].info.cppRef)
            {
                std::memcpy(allocs+i, allocs+i+1, (numAllocs-i-1) * sizeof(Allocation));

                --numAllocs;
                allocs = (Allocation *)std::realloc(allocs, numAllocs * sizeof(Allocation));
                return true;
            } else if (allocs[i].ptr == ptr)
            {
                allocs[i].info.scriptRef = false;
                return false;
            }
        }
    }

    return true;
}

AllocInfo getAllocInfo(void *ptr)
{
    if (allocs == nullptr)
    {
        return AllocInfo();
    } else
    {
        for (size_t i = 0; i < numAllocs; ++i)
        {
            if (allocs[i].ptr == ptr)
            {
                return allocs[i].info;
            }
        }

        return AllocInfo();
    }
}

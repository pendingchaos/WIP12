#include "memory.h"

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

#ifndef MEMORY_H
#define MEMORY_H

#include "misc_macros.h"
#include "error.h"

#include <cstdlib>
#include <stddef.h>

class MemoryException : public Exception
{
    public:
        MemoryException(const char *file_,
                        size_t line_,
                        const char *function_) : Exception(file_, line_, function_) {}

        virtual const char *getString() const
        {
            return "Something to do with memory.";
        }
};

#define ALLOCATE(amount) std::malloc(amount)

#define DEALLOCATE(pointer) do\
{\
    std::free(pointer);\
} while (0)

#ifdef IN_SCRIPT
#define NEW(type, ...) _new<type>::f(__VA_ARGS__)
#define NEW_ARRAY(type, count) _newArray<type>::f(count)
#else
#define NEW(type, ...) (new type(__VA_ARGS__))
#define NEW_ARRAY(type, count) (new type[count])
#endif

#define DELETE(type, pointer) do\
{\
    delete (type *)pointer;\
} while (0)
#define DELETE_ARRAY(type, pointer) do\
{\
    delete [] (type *)pointer;\
} while (0)

void *_alloc(size_t amount);

#endif // MEMORY_H

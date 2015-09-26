#ifndef MEMORY_H
#define MEMORY_H

#include "misc_macros.h"
#include "error.h"

#include <cstdlib>
#include <stddef.h>
#include <stdint.h>

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

#define ALLOCATE(amount) _alloc(amount)

#define DEALLOCATE(pointer) do\
{\
    std::free((void *)pointer);\
} while (0)

#ifdef IN_SCRIPT
#define NEW(type, ...) _new<type>::f(__VA_ARGS__)
#define NEW_ARRAY(type, count) _newArray<type>::f(count)
#else
#define NEW(type, ...) (new type(__VA_ARGS__))
#define NEW_ARRAY(type, count) (new type[count])
#endif

#define DELETE(pointer) do\
{\
    auto p = pointer;\
    if (_allocDelete((void *)p))\
    {\
        delete p;\
    }\
} while (0)
#define DELETE_ARRAY(pointer) do\
{\
    auto p = pointer;\
    if (_allocDelete((void *)p))\
    {\
        delete [] p;\
    }\
} while (0)

#define SCRIPT_DELETE(pointer) do\
{\
    auto p = pointer;\
    if (shouldScriptDelete((void *)p))\
    {\
        delete p;\
    }\
} while (0)

struct AllocInfo
{
    AllocInfo() : scriptRef(false), cppRef(true) {}
    AllocInfo(bool script, bool cpp) : scriptRef(script), cppRef(cpp) {}

    bool scriptRef:1;
    bool cppRef:1;
};

void *_alloc(size_t amount);
bool _allocDelete(void *ptr);
bool shouldScriptDelete(void *ptr);

void setAllocInfo(void *ptr, AllocInfo info);
AllocInfo getAllocInfo(void *ptr);

#endif // MEMORY_H

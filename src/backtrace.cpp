#include "backtrace.h"

#if defined(__GNUC__)
#include <execinfo.h>
#include <cxxabi.h>

#include <dlfcn.h>
#include <cstdlib>
#include <cstring>
#include <algorithm>

char *theBacktrace[256];
unsigned int theDepth;

const char unableToGetFuncName[] = "Unable to get function name.";

void initBacktrace()
{
    for (unsigned int i = 0; i < 256; ++i)
    {
        theBacktrace[i] = (char *)std::malloc(1024);
    }
}

void deinitBacktrace()
{
    for (unsigned int i = 0; i < 256; ++i)
    {
        std::free(theBacktrace[i]);
    }
}

const char **getBacktrace(unsigned int& depth)
{
    void *trace[256];

    depth = backtrace(trace, 256);
    theDepth = depth;

    for (unsigned int i=0; i<depth; ++i)
    {
        std::memset(theBacktrace[i], 0, 1024);

        Dl_info info;

        if (dladdr(trace[i], &info) == 0) //Bottleneck
        {
            std::memcpy(theBacktrace[i],
                        unableToGetFuncName,
                        sizeof(unableToGetFuncName));
            continue;
        }

        const char *name = info.dli_sname;

        if (name == nullptr)
        {
            std::memcpy(theBacktrace[i],
                        unableToGetFuncName,
                        sizeof(unableToGetFuncName));
            continue;
        }

        int status;

        char *demangled = abi::__cxa_demangle(name, nullptr, 0, &status);

        if (status == 0 and demangled != nullptr)
        {
            std::memcpy(theBacktrace[i],
                        demangled,
                        std::min((int)std::strlen(demangled), 1024));

            std::free(demangled);
        } else
        {
            std::memcpy(theBacktrace[i], name, std::min((int)std::strlen(name), 1024));
        }
    }

    return (const char **)theBacktrace;
}
#else
char *theBacktrace[0];

void initBacktrace() {}
void deinitBacktrace() {}

const char **getBacktrace(unsigned int &depth)
{
    depth = 0;

    return (const char **)theBacktrace;
}
#endif

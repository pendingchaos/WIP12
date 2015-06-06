#ifndef ERROR_H
#define ERROR_H

#include "backtrace.h"

#include <stdint.h>
#include <stddef.h>
#include <cstring>
#include <algorithm>

#define THROW(type, ...) throw type(__FILE__, __LINE__, __PRETTY_FUNCTION__,##__VA_ARGS__);

class Exception
{
    public:
        Exception(const char *file_,
                  size_t line_,
                  const char *function_) : file(file_),
                                           line(line_),
                                           function(function_) {}
        virtual ~Exception() {}

        virtual const char *getString() const
        {
            return "";
        }

        inline const char *getFile() const
        {
            return file;
        }

        inline size_t getLine() const
        {
            return line;
        }

        inline const char *getFunction() const
        {
            return function;
        }
    private:
        const char *file;
        size_t line;
        const char *function;
};

class BoundsException : public Exception
{
    public:
        BoundsException(const char *file_,
                        size_t line_,
                        const char *function_) : Exception(file_, line_, function_) {}

        virtual const char *getString() const
        {
            return "An index to a container was outside it's bounds.";
        }
};
#endif // ERROR_H

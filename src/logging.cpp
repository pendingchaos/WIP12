#include "logging.h"

#include "containers/string.h"
#include "file.h"
#include "memory.h"
#include "backtrace.h"

#include <cstdarg>
#include <cstdlib>
#include <cstdio>
#include <cstring>

File *textLog = nullptr;

void initLoggingSystem()
{
    if (textLog == nullptr)
    {
        textLog = NEW(File, "log.txt", "w");
    }
}

void deinitLoggingSystem()
{
    DELETE(textLog);
    textLog = nullptr;
}

void logFatal(const char *format, ...)
{
    textLog->printf("[FATAL]: ");
    std::printf("[FATAL]: ");

    va_list list;
    va_start(list, format);

    va_list list2;
    va_copy(list2, list);
    std::vprintf(format, list2);
    va_end(list2);

    textLog->vprintf(format, list);
    va_end(list);
}

void logError(const char *format, ...)
{
    textLog->printf("[ERROR]: ");
    std::printf("[ERROR]: ");

    va_list list;
    va_start(list, format);

    va_list list2;
    va_copy(list2, list);
    std::vprintf(format, list2);
    va_end(list2);

    textLog->vprintf(format, list);
    va_end(list);
}

void logWarning(const char *format, ...)
{
    textLog->printf("[WARNING]: ");
    std::printf("[WARNING]: ");

    va_list list;
    va_start(list, format);

    va_list list2;
    va_copy(list2, list);
    std::vprintf(format, list2);
    va_end(list2);

    textLog->vprintf(format, list);
    va_end(list);
}

void logInfo(const char *format, ...)
{
    textLog->printf("[INFO]: ");

    va_list list;
    va_start(list, format);
    textLog->vprintf(format, list);
    va_end(list);
}

static void _log(const char *type,
                 const char *file,
                 int line,
                 const char *function,
                 const char *format,
                 va_list args,
                 bool stdout_)
{
    va_list args2;
    va_copy(args2, args);

    textLog->printf("[%s] %s:%d:%s:\n    ", type, file, line, function);
    textLog->vprintf(format, args);
    textLog->writeChar('\n');

    if (stdout_)
    {
        std::printf("[%s] %s:%d:%s:\n    ", type, file, line, function);
        std::vprintf(format, args2);
        std::putc('\n', stdout);
    }

    va_end(args2);
}

void _logFatal(const char *file,
               int line,
               const char *function,
               const char *format,
               ...)
{
    va_list list;

    va_start(list, format);

    _log("FATAL", file, line, function, format, list, true);

    va_end(list);

    std::exit(1);
}

void _logError(const char *file,
               int line,
               const char *function,
               const char *format,
               ...)
{
    va_list list;

    va_start(list, format);

    _log("ERROR", file, line, function, format, list, true);

    va_end(list);
}

void _logWarning(const char *file,
                 int line,
                 const char *function,
                 const char *format,
                 ...)
{
    va_list list;

    va_start(list, format);

    _log("WARNING", file, line, function, format, list, true);

    va_end(list);
}

void _logInfo(const char *file,
              int line,
              const char *function,
              const char *format,
              ...)
{
    va_list list;

    va_start(list, format);

    _log("INFO", file, line, function, format, list, false);

    va_end(list);
}

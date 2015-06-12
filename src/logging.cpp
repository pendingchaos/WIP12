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
    textLog = NEW(File, "log.txt", "w");
}

void deinitLoggingSystem()
{
    DELETE(File, textLog);
}

void log(const char *format, ...)
{
    va_list list;

    va_start(list, format);

    va_list list2;

    va_copy(list2, list);

    std::vprintf(format, list2);

    va_end(list2);

    textLog->vprintf(format, list);

    va_end(list);
}

LogEntry& LogEntry::fatal(const char *category,
                              const char *file,
                              int line,
                              const char *function,
                              const char *format,
                              ...)
{
    va_list list;

    va_start(list, format);

    log("FATAL", category, file, line, function, format, list);

    va_end(list);

    return *this;
}

LogEntry& LogEntry::error(const char *category,
                              const char *file,
                              int line,
                              const char *function,
                              const char *format,
                              ...)
{
    va_list list;

    va_start(list, format);

    log("ERROR", category, file, line, function, format, list);

    va_end(list);

    return *this;
}

LogEntry& LogEntry::warn(const char *category,
                             const char *file,
                             int line,
                             const char *function,
                             const char *format,
                             ...)
{
    va_list list;

    va_start(list, format);

    log("WARNING", category, file, line, function, format, list);

    va_end(list);

    return *this;
}

LogEntry& LogEntry::info(const char *category,
                             const char *file,
                             int line,
                             const char *function,
                             const char *format,
                             ...)
{
    va_list list;

    va_start(list, format);

    log("INFO", category, file, line, function, format, list);

    va_end(list);

    return *this;
}

LogEntry& LogEntry::log(const char *category,
                        const char *type,
                        const char *file,
                        int line,
                        const char *function,
                        const char *format,
                        va_list args)
{
    va_list args2;
    va_copy(args2, args);

    textLog->printf("[%s][%s] %s:%d:%s:\n    ", category, type, file, line, function);
    textLog->vprintf(format, args);
    textLog->writeChar('\n');
    textLog->writeChar('\n');

    std::printf("[%s][%s] %s:%d:%s:\n    ", category, type, file, line, function);
    std::vprintf(format, args2);
    std::putc('\n', stdout);
    std::putc('\n', stdout);

    return *this;
}

LogEntry& LogEntry::variable(const char *name, uint8_t value)
{
    textLog->printf("    %s: %hhu\n", name, value);

    std::printf("    %s: %hhu\n", name, value);

    return *this;
}

LogEntry& LogEntry::variable(const char *name, int8_t value)
{
    textLog->printf("    %s: %hhi\n", name, value);

    std::printf("    %s: %hhi\n", name, value);

    return *this;
}

LogEntry& LogEntry::variable(const char *name, uint16_t value)
{
    textLog->printf("    %s: %hu\n", name, value);

    std::printf("    %s: %hu\n", name, value);

    return *this;
}

LogEntry& LogEntry::variable(const char *name, int16_t value)
{
    textLog->printf("    %s: %hi\n", name, value);

    std::printf("    %s: %hi\n", name, value);

    return *this;
}

LogEntry& LogEntry::variable(const char *name, uint32_t value)
{
    textLog->printf("    %s: %u\n", name, value);

    std::printf("    %s: %u\n", name, value);

    return *this;
}

LogEntry& LogEntry::variable(const char *name, int32_t value)
{
    textLog->printf("    %s: %i\n", name, value);

    std::printf("    %s: %i\n", name, value);

    return *this;
}

LogEntry& LogEntry::variable(const char *name, uint64_t value)
{
    textLog->printf("    %s: %lu\n", name, value);

    std::printf("    %s: %lu\n", name, value);

    return *this;
}

LogEntry& LogEntry::variable(const char *name, int64_t value)
{
    textLog->printf("    %s: %li\n", name, value);

    std::printf("    %s: %li\n", name, value);

    return *this;
}

LogEntry& LogEntry::variable(const char *name, bool value)
{
    textLog->printf("    %s: %s\n", name, value ? "true" : "false");

    std::printf("    %s: %s\n", name, value ? "true" : "false");

    return *this;
}

LogEntry& LogEntry::variable(const char *name, float value)
{
    double doubleValue = static_cast<double>(value);

    textLog->printf("    %s: %f\n", name, doubleValue);

    std::printf("    %s: %f\n", name, doubleValue);

    return *this;
}

LogEntry& LogEntry::variable(const char *name, double value)
{
    textLog->printf("    %s: %f\n", name, value);

    std::printf("    %s: %f\n", name, value);

    return *this;
}

LogEntry& LogEntry::variable(const char *name, long double value)
{
    textLog->printf("    %s: %Lf\n", name, value);

    std::printf("    %s: %Lf\n", name, value);

    return *this;
}

LogEntry& LogEntry::variable(const char *name, const char *value)
{
    if (value == nullptr)
    {
        return *this;
    }

    textLog->printf("    %s: %s\n", name, value);

    std::printf("    %s: %s\n", name, value);

    return *this;
}

LogEntry& LogEntry::variable(const char *name, const String& value)
{
    return variable(name, value.getData());
}

LogEntry& LogEntry::printBacktrace()
{
    unsigned int depth;

    const char **backtrace = getBacktrace(depth);

    return printBacktrace(depth, backtrace);
}

LogEntry& LogEntry::printBacktrace(unsigned int depth, const char **backtrace)
{
    textLog->printf("\n    Backtrace:\n");

    std::printf("\n    Backtrace:\n");

    for (unsigned int i = 0; i < depth; ++i)
    {
        textLog->printf("        %s\n", backtrace[i]);
    }

    for (unsigned int i = 0; i < depth; ++i)
    {
        std::printf("        %s\n", backtrace[i]);
    }

    return *this;
}

int LogEntry::end()
{
    textLog->writeChar('\n');
    textLog->flush();

    std::putc('\n', stdout);
    std::fflush(stdout);

    return 0;
}

int LogEntry::fatalEnd()
{
    end();

    std::exit(EXIT_FAILURE);
}

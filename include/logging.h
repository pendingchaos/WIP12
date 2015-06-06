#ifndef LOGGING_H
#define LOGGING_H

#include "misc_macros.h"

#include <stdint.h>
#include <stdarg.h>

void initLoggingSystem();
void deinitLoggingSystem();

void log(const char *format, ...);

class String;

class LogEntry
{
    public:
        LogEntry& fatal(const char *category,
                        const char *file,
                        int line,
                        const char *function,
                        const char *format,
                        ...);

        LogEntry& error(const char *category,
                        const char *file,
                        int line,
                        const char *function,
                        const char *format,
                        ...);

        LogEntry& warn(const char *category,
                       const char *file,
                       int line,
                       const char *function,
                       const char *format,
                       ...);

        LogEntry& info(const char *category,
                       const char *file,
                       int line,
                       const char *function,
                       const char *format,
                       ...);

        LogEntry& variable(const char *name, uint8_t value);
        LogEntry& variable(const char *name, int8_t value);
        LogEntry& variable(const char *name, uint16_t value);
        LogEntry& variable(const char *name, int16_t value);
        LogEntry& variable(const char *name, uint32_t value);
        LogEntry& variable(const char *name, int32_t value);
        LogEntry& variable(const char *name, uint64_t value);
        LogEntry& variable(const char *name, int64_t value);

        LogEntry& variable(const char *name, bool value);

        LogEntry& variable(const char *name, float value);
        LogEntry& variable(const char *name, double value);
        LogEntry& variable(const char *name, long double value);

        LogEntry& variable(const char *name, const char *value);

        LogEntry& variable(const char *name, const String& value);

        LogEntry& variable(const char *name, void *value)
        {
            #if __WORDSIZE == 64
            variable(name, reinterpret_cast<uint64_t>(value));
            #else
            variable(name, reinterpret_cast<uint32_t>(value));
            #endif

            return *this;
        }

        LogEntry& printBacktrace();
        LogEntry& printBacktrace(unsigned int depth, const char **backtrace);

        int end();
        int fatalEnd();
    private:
        LogEntry& log(const char *category,
                      const char *type,
                      const char *file,
                      int line,
                      const char *function,
                      const char *format,
                      va_list args);
};

#define _LOG_VAR(var) .variable(STR(var), var)

#define _LOG_VARS_INFO(...) FOR_EACH(_LOG_VAR, __VA_ARGS__).end()
#define _LOG_VARS(...) FOR_EACH(_LOG_VAR, __VA_ARGS__).printBacktrace().end()
#define _LOG_VARS_FATAL(...) FOR_EACH(_LOG_VAR, __VA_ARGS__).printBacktrace().fatalEnd()

#define FATAL_IF_FALSE(category,\
                       condition,\
                       ...) (condition)\
                            ? 0\
                            : LogEntry().fatal(category,\
                                               __FILE__,\
                                               __LINE__,\
                                               __PRETTY_FUNCTION__,\
                                               __VA_ARGS__) _LOG_VARS_FATAL

#define FATAL_IF_TRUE(category, condition, ...) FATAL_IF_FALSE(category,\
                                                               not (condition),\
                                                               __VA_ARGS__)

#define ERROR_IF_FALSE(category,\
                       condition,\
                       ...) (condition)\
                            ? 0\
                            : LogEntry().error(category,\
                                               __FILE__,\
                                               __LINE__,\
                                               __PRETTY_FUNCTION__,\
                                               __VA_ARGS__) _LOG_VARS

#define ERROR_IF_TRUE(category, condition, ...) ERROR_IF_FALSE(category,\
                                                               not (condition),\
                                                               __VA_ARGS__)

#define WARN_IF_FALSE(category,\
                      condition,\
                      ...) (condition)\
                           ? 0\
                           : LogEntry().warn(category,\
                                             __FILE__,\
                                             __LINE__,\
                                             __PRETTY_FUNCTION__,\
                                             __VA_ARGS__) _LOG_VARS

#define WARN_IF_TRUE(category, condition, ...) WARN_IF_FALSE(category,\
                                                             not (condition),\
                                                             __VA_ARGS__)

#define INFO_IF_FALSE(category,\
                      condition,\
                      ...) (condition)\
                           ? 0\
                           : LogEntry().info(category,\
                                             __FILE__,\
                                             __LINE__,\
                                             __PRETTY_FUNCTION__,\
                                             __VA_ARGS__) _LOG_VARS_INFO

#define INFO_IF_TRUE(category, condition, ...) INFO_IF_FALSE(category,\
                                                             not (condition),\
                                                             __VA_ARGS__)

#define FATAL(category, ...) FATAL_IF_FALSE(category, false, __VA_ARGS__)
#define ERROR(category, ...) ERROR_IF_FALSE(category, false, __VA_ARGS__)
#define WARN(category, ...) WARN_IF_FALSE(category, false, __VA_ARGS__)
#define INFO(category, ...) INFO_IF_FALSE(category, false, __VA_ARGS__)

#define CATEGORY_OTHER "OTHER"
#define CATEGORY_OPENGL "OPENGL"
#define CATEGORY_RENDER "RENDER"
#define CATEGORY_RESIO "RESIO"
#define CATEGORY_WINDOW "WINDOW"
#define CATEGORY_RESOURCE "RESOURCE"
#define CATEGORY_CONTAINER "CONTAINER"
#define CATEGORY_FILE "FILE"
#define CATEGORY_SCRIPT "SCRIPT"
#define CATEGORY_PHYSICS "PHYSICS"

#endif // LOGGING_H

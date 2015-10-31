#ifndef LOGGING_H
#define LOGGING_H

#include "misc_macros.h"

#include <stdint.h>
#include <stdarg.h>

void initLoggingSystem();
void deinitLoggingSystem();

void logFatal(const char *format, ...);
void logError(const char *format, ...);
void logWarning(const char *format, ...);
void logInfo(const char *format, ...);

void _logFatal(const char *file,
               int line,
               const char *function,
               const char *format,
               ...);
void _logError(const char *file,
               int line,
               const char *function,
               const char *format,
               ...);
void _logWarning(const char *file,
                 int line,
                 const char *function,
                 const char *format,
                 ...);
void _logInfo(const char *file,
              int line,
              const char *function,
              const char *format,
              ...);

#define LOG_FATAL(...) do {_logFatal(__FILE__, __LINE__, __FUNCTION__, __VA_ARGS__);} while (0)
#define LOG_ERROR(...) do {_logError(__FILE__, __LINE__, __FUNCTION__, __VA_ARGS__);} while (0)
#define LOG_WARNING(...) do {_logWarning(__FILE__, __LINE__, __FUNCTION__, __VA_ARGS__);} while (0)
#define LOG_INFO(...) do {_logInfo(__FILE__, __LINE__, __FUNCTION__, __VA_ARGS__);} while (0)

#endif // LOGGING_H

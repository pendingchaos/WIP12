#ifndef BACKTRACE_H
#define BACKTRACE_H

void initBacktrace();
void deinitBacktrace();

const char **getBacktrace(unsigned int& depth);

#endif // BACKTRACE_H

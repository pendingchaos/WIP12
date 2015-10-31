#ifndef JOBSYSTEM_H
#define JOBSYSTEM_H

#include <stddef.h>

typedef void (*JobFunc)(size_t index, size_t workerIndex, void *userdata);

void initJobSystem(size_t numWorkers);
void deinitJobSystem();
void runJobsSync(JobFunc func, size_t count, void *userdata, size_t dataSize);
size_t getNumWorkers();

#endif // JOBSYSTEM_H

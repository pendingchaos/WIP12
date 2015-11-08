#include "jobsystem.h"

#include <thread>
#include <mutex>
#include <atomic>
#include <SDL2/SDL_cpuinfo.h>
#include <SDL2/SDL_assert.h>

#include "memory.h"

static size_t nextWorkerIndex;

struct WorkerThread
{
    WorkerThread() : jobsToRun(false), running(false), workerIndex(nextWorkerIndex++)
    {
        noRunMutex.lock();
        thread = NEW(std::thread, workerFunc, this);
        while (not running) {}
    }

    ~WorkerThread()
    {
        jobsToRun = false;
        noRunMutex.unlock();
        thread->join();
        DELETE(thread);
    }

    static void workerFunc(WorkerThread *worker)
    {
        worker->running = true;

        while (true)
        {
            worker->noRunMutex.lock();

            if (worker->jobsToRun)
            {
                size_t jobOffset = worker->jobOffset;
                size_t jobCount = worker->jobCount;

                JobFunc job = worker->job;
                size_t workerIndex = worker->workerIndex;
                void *userdata = worker->userdata;

                for (size_t i = jobOffset; i < jobOffset+jobCount; ++i)
                {
                    job(i, workerIndex, userdata);
                }

                worker->finishMutex.unlock();
            } else
            {
                break;
            }
        }
    }

    bool jobsToRun;
    std::atomic_bool running;
    std::mutex noRunMutex;
    std::mutex finishMutex;
    std::thread *thread;
    size_t jobOffset;
    size_t jobCount;
    JobFunc job;
    void *userdata;
    size_t workerIndex;
};

static size_t numThreads;
static WorkerThread *workers;

void initJobSystem(size_t numWorkers)
{
    nextWorkerIndex = 0;
    numThreads = numWorkers-1; //The main thread is a worker.
    workers = NEW_ARRAY(WorkerThread, numThreads);
}

void deinitJobSystem()
{
    DELETE_ARRAY(workers);
}

void runJobsSync(JobFunc func, size_t count, void *userdata, size_t dataSize)
{
    if (numThreads == 0)
    {
        for (size_t i = 0; i < count; ++i)
        {
            func(i, 0, userdata);
        }
    } else
    {
        int cacheLineSize = SDL_GetCPUCacheLineSize();
        SDL_assert_paranoid(cacheLineSize >= 0);

        size_t newDataSize = dataSize/cacheLineSize*cacheLineSize + ((dataSize%cacheLineSize)?cacheLineSize:0);

        void *datas = ALLOCATE(newDataSize*(numThreads+1));

        for (size_t i = 0; i < (numThreads+1); ++i)
        {
            std::memcpy(((uint8_t *)datas)+newDataSize*i, userdata, dataSize);
        }

        size_t numPerWorker = count / numThreads;

        size_t jobOffset = 0;
        for (size_t i = 0; i < numThreads; ++i)
        {
            workers[i].jobOffset = jobOffset;
            workers[i].job = func;
            workers[i].userdata = ((uint8_t *)datas)+newDataSize*i;
            workers[i].jobCount = numPerWorker;
            workers[i].jobsToRun = true;

            jobOffset += numPerWorker;

            workers[i].finishMutex.lock();
            workers[i].noRunMutex.unlock();
        }

        for (size_t i = jobOffset; i < count; ++i)
        {
            func(i, numThreads, ((uint8_t *)datas)+newDataSize*numThreads);
        }

        for (size_t i = 0; i < numThreads; ++i)
        {
            std::lock_guard<std::mutex> lock(workers[i].finishMutex);
        }

        DEALLOCATE(datas);
    }
}

size_t getNumWorkers()
{
    return numThreads+1; //The main thread is a worker.
}

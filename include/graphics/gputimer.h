#ifndef GPUTIMER_H
#define GPUTIMER_H

#include "scripting/bindings.h"

#include <stdint.h>

class GPUTimer
{
    public:
        virtual ~GPUTimer();

        virtual bool resultAvailable()=0;
        virtual uint64_t getResult()=0;
        virtual uint64_t getResultResolution()=0;

        virtual void begin()=0;
        virtual void end()=0;

        virtual void swap() {}
} BIND;

#endif // GPUTIMER_H

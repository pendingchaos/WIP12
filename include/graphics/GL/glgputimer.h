#ifndef GLGPUTIMER_H
#define GLGPUTIMER_H

#include "graphics/gputimer.h"
#include "graphics/GL/glfl.h"

class GLGPUTimer : public GPUTimer
{
    public:
        GLGPUTimer();
        virtual ~GLGPUTimer();

        virtual bool resultAvailable();
        virtual uint64_t getResult();
        virtual uint64_t getResultResolution();

        virtual void begin();
        virtual void end();

        virtual void swap();
    private:
        GLuint queries[4];
};

#endif // GLGPUTIMER_H

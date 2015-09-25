#include "graphics/GL/glgputimer.h"

#include "graphics/gfxapi.h"
#include "globals.h"
#include <algorithm>

GLGPUTimer::GLGPUTimer()
{
    glGenQueries(4, queries);

    if (gfxApi->getDriver() == GfxDriver::Nvidia)
    {
        glBeginQuery(GL_TIME_ELAPSED, queries[0]);
        glEndQuery(GL_TIME_ELAPSED);

        glBeginQuery(GL_TIME_ELAPSED, queries[1]);
        glEndQuery(GL_TIME_ELAPSED);

        glBeginQuery(GL_TIME_ELAPSED, queries[2]);
        glEndQuery(GL_TIME_ELAPSED);

        glBeginQuery(GL_TIME_ELAPSED, queries[3]);
        glEndQuery(GL_TIME_ELAPSED);
    }
}

GLGPUTimer::~GLGPUTimer()
{
    glDeleteQueries(2, queries);
}

bool GLGPUTimer::resultAvailable()
{
    GLint timer1;
    GLint timer2;

    glGetQueryObjectiv(queries[0], GL_QUERY_RESULT_AVAILABLE, &timer1);
    glGetQueryObjectiv(queries[1], GL_QUERY_RESULT_AVAILABLE, &timer2);

    return timer1 == GL_TRUE and timer2 == GL_TRUE;
}

uint64_t GLGPUTimer::getResult()
{
    GLuint64 startTime;
    GLuint64 endTime;

    glGetQueryObjectui64v(queries[0], GL_QUERY_RESULT, &startTime);
    glGetQueryObjectui64v(queries[1], GL_QUERY_RESULT, &endTime);

    return endTime - startTime;
}

uint64_t GLGPUTimer::getResultResolution()
{
    return 1000000000;
}

void GLGPUTimer::begin()
{
    glDeleteQueries(1, &queries[0]);
    glGenQueries(1, &queries[0]);
    glQueryCounter(queries[0], GL_TIMESTAMP);
}

void GLGPUTimer::end()
{
    glDeleteQueries(1, &queries[1]);
    glGenQueries(1, &queries[1]);
    glQueryCounter(queries[1], GL_TIMESTAMP);
}

void GLGPUTimer::swap()
{
    std::swap(queries[0], queries[2]);
    std::swap(queries[1], queries[3]);
}

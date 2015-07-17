#include "graphics/GL/glgputimer.h"

#include "graphics/gfxapi.h"
#include "globals.h"

GLGPUTimer::GLGPUTimer()
{
    glGenQueries(2, queries);

    if (gfxApi->getDriver() == GfxApi::Nvidia)
    {
        glBeginQuery(GL_TIME_ELAPSED, queries[0]);
        glEndQuery(GL_TIME_ELAPSED);

        glBeginQuery(GL_TIME_ELAPSED, queries[1]);
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
    glQueryCounter(queries[0], GL_TIMESTAMP);
}

void GLGPUTimer::end()
{
    glQueryCounter(queries[1], GL_TIMESTAMP);
}

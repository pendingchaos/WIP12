#include "graphics/GL/gfxglbuffer.h"

#define BEGIN_BUFFER_BINDING GLint lastBuffer;\
glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &lastBuffer);\
glBindBuffer(GL_ARRAY_BUFFER, buffer);

#define END_BUFFER_BINDING glBindBuffer(GL_ARRAY_BUFFER, lastBuffer);

GfxGLBuffer::GfxGLBuffer()
{
    glGenBuffers(1, &buffer);

    BEGIN_BUFFER_BINDING
    END_BUFFER_BINDING
}

GfxGLBuffer::~GfxGLBuffer()
{
    glDeleteBuffers(1, &buffer);
}

void GfxGLBuffer::allocData(size_t size, const void *data, GfxGLBuffer::Usage usage)
{
    BEGIN_BUFFER_BINDING

    switch (usage)
    {
    case GfxGLBuffer::Stream:
    {
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STREAM_DRAW);
        break;
    }
    case GfxGLBuffer::Static:
    {
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
        break;
    }
    case GfxGLBuffer::Dynamic:
    {
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
        break;
    }
    }

    END_BUFFER_BINDING
}

void GfxGLBuffer::setData(size_t start, size_t size, const void *data)
{
    BEGIN_BUFFER_BINDING

    glBufferSubData(GL_ARRAY_BUFFER, start, size, data);

    END_BUFFER_BINDING
}

void GfxGLBuffer::getData(size_t start, size_t amount, void *data)
{
    BEGIN_BUFFER_BINDING

    glGetBufferSubData(GL_ARRAY_BUFFER, start, amount, data);

    END_BUFFER_BINDING
}

size_t GfxGLBuffer::getSize() const
{
    BEGIN_BUFFER_BINDING

    GLint size;

    glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);

    END_BUFFER_BINDING

    return size;
}

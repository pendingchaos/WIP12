#ifndef GFXGLBUFFER_H
#define GFXGLBUFFER_H

#include "graphics/gfxbuffer.h"
#include "graphics/GL/glfl.h"

class GfxGLBuffer : public GfxBuffer
{
    NO_COPY_INHERITED(GfxGLBuffer, GfxBuffer)

    public:
        GfxGLBuffer();
        virtual ~GfxGLBuffer();

        virtual void allocData(size_t size, const void *data, GfxBufferUsage usage);
        virtual void setData(size_t start, size_t size, const void *data);
        virtual void getData(size_t start, size_t amount, void *data);
        virtual size_t getSize() const;

        inline GLuint getGLBuffer() const
        {
            return buffer;
        }
    private:
        GLuint buffer;
};

#endif // GFXGLBUFFER_H

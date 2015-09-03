#ifndef GFXBUFFER_H
#define GFXBUFFER_H

#include "misc_macros.h"
#include "scripting/bindings.h"

#include <stddef.h>

enum class GfxBufferUsage
{
    Stream,
    Static,
    Dynamic
} BIND ENUM_CLASS;

class GfxBuffer
{
    public:
        GfxBuffer() {}
        virtual ~GfxBuffer() {}

        /**
         *If data is nullptr, then the data is undefined.
         */
        virtual void allocData(size_t size, const void *data, GfxBufferUsage usage) NO_BIND=0;

        /**
         *If data is nullptr, then the data is undefined.
         */
        virtual void setData(size_t start, size_t size, const void *data) NO_BIND=0;

        virtual void getData(size_t start, size_t amount, void *data) NO_BIND=0;

        virtual size_t getSize() const=0;

    NO_COPY(GfxBuffer)
} BIND;

#endif // GFXBUFFER_H

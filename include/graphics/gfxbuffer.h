#ifndef GFXBUFFER_H
#define GFXBUFFER_H

#include "misc_macros.h"
#include "containers/resizabledata.h"
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

        void allocData(const ResizableData& data, GfxBufferUsage usage)
        {
            allocData(data.getSize(), data.getData(), usage);
        }

        /**
         *If data is nullptr, then the data is undefined.
         */
        virtual void setData(size_t start, size_t size, const void *data) NO_BIND=0;

        void setData(size_t start, const ResizableData& data)
        {
            setData(start, data.getSize(), data.getData());
        }

        virtual void getData(size_t start, size_t amount, void *data) NO_BIND=0;

        ResizableData getData(size_t start, size_t amount)
        {
            ResizableData data(amount);
            getData(start, amount, data.getData());
            return data;
        }

        virtual size_t getSize() const=0;

    NO_COPY(GfxBuffer)
} BIND;

#endif // GFXBUFFER_H

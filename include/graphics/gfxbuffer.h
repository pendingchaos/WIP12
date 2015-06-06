#ifndef GFXBUFFER_H
#define GFXBUFFER_H

#include "misc_macros.h"

#include <stddef.h>

class GfxBuffer
{
    public:
        enum Usage
        {
            Stream,
            Static,
            Dynamic
        };

        GfxBuffer() {}
        virtual ~GfxBuffer() {}

        /**
         *If data is nullptr, then the data is undefined.
         */
        virtual void allocData(size_t size, const void *data, Usage usage)=0;

        /**
         *If data is nullptr, then the data is undefined.
         */
        virtual void setData(size_t start, size_t size, const void *data)=0;

        virtual void getData(size_t start, size_t amount, void *data)=0;

        virtual size_t getSize() const=0;

    NO_COPY(GfxBuffer)
};

#endif // GFXBUFFER_H

#ifndef GFXFRAMEBUFFER_H
#define GFXFRAMEBUFFER_H

#include "graphics/gfxtexture.h"
#include <stddef.h>

class GfxFramebuffer
{
    public:
        virtual ~GfxFramebuffer();

        virtual void addColorAttachment(size_t rtIndex,
                                        GfxTexture *texture,
                                        size_t mipmapLevel=0,
                                        int layer=-1)=0;
        virtual void removeColorAttachment(size_t index)=0;
        virtual size_t getNumColorAttachments()=0;
        virtual size_t getColorRT(size_t index)=0;
        virtual GfxTexture *getColorAttachment(size_t index)=0;
        virtual size_t getColorAttachmentMipmapLevel(size_t index)=0;
        virtual int getColorAttachmentLayer(size_t index)=0;

        virtual void setDepthAttachment(GfxTexture *texture,
                                        size_t mipmapLevel=0,
                                        int layer=-1)=0;
        virtual void removeDepthAttachment()=0;
        virtual bool hasDepthAttachment()=0;
        virtual GfxTexture *getDepthTexture()=0;
        virtual size_t getDepthTextureMipmapLevel()=0;
        virtual int getDepthAttachmentLayer()=0;
};

#endif // GFXFRAMEBUFFER_H

#ifndef GFXGLFRAMEBUFFER_H
#define GFXGLFRAMEBUFFER_H

#include "graphics/gfxframebuffer.h"
#include "graphics/GL/glfl.h"

class GfxGLFramebuffer : public GfxFramebuffer
{
    public:
        GfxGLFramebuffer();
        virtual ~GfxGLFramebuffer();

        virtual void addColorAttachment(size_t rtIndex,
                                        GfxTexture *texture,
                                        size_t mipmapLevel=0,
                                        int layer=-1);
        virtual void removeColorAttachment(size_t index);
        virtual size_t getNumColorAttachments();
        virtual size_t getColorRT(size_t index);
        virtual GfxTexture *getColorAttachment(size_t index);
        virtual size_t getColorAttachmentMipmapLevel(size_t index);
        virtual int getColorAttachmentLayer(size_t index);

        virtual void setDepthAttachment(GfxTexture *texture,
                                        size_t mipmapLevel=0,
                                        int layer=-1);
        virtual void removeDepthAttachment();
        virtual bool hasDepthAttachment();
        virtual GfxTexture *getDepthTexture();
        virtual size_t getDepthTextureMipmapLevel();
        virtual int getDepthAttachmentLayer();

        inline GLuint getGLFramebuffer() const
        {
            return fbo;
        }
    private:
        struct Attachment
        {
            size_t rtIndex;
            GfxTexture *texture;
            size_t mipmapLevel;
            int layer;

            inline bool operator == (const Attachment& other) const
            {
                return rtIndex == other.rtIndex and
                       texture == other.texture and
                       mipmapLevel == other.mipmapLevel and
                       layer == other.layer;
            }
        };

        GLuint fbo;

        List<Attachment> attachments;

        bool hasDepth;
        Attachment depthAttachment;
};

#endif // GFXGLFRAMEBUFFER_H

#ifndef GFXGLTEXTUREIMPL_H
#define GFXGLTEXTUREIMPL_H

#include "graphics/gfxtexture.h"

class GfxGLFramebuffer;

class GfxGLTextureImpl : public GfxTextureImpl
{
    NO_COPY_INHERITED(GfxGLTextureImpl, GfxTextureImpl)

    friend GfxGLFramebuffer;

    public:
        GfxGLTextureImpl();
        virtual ~GfxGLTextureImpl();

        virtual void startCreation(GfxTextureType type,
                                   unsigned int baseWidth,
                                   unsigned int baseHeight,
                                   unsigned int baseDepth,
                                   GfxTexFormat format);

        virtual void allocMipmapFace(unsigned int level,
                                     unsigned int pixelAlignment,
                                     GfxFace face,
                                     const void *data);

        virtual void allocMipmap(unsigned int level,
                                 unsigned int pixelAlignment,
                                 const void *data);

        virtual void getMipmapFace(unsigned int level,
                                   unsigned int pixelAlignment,
                                   GfxFace face,
                                   void *data);

        virtual void getMipmap(unsigned int level,
                               unsigned int pixelAlignment,
                               void *data);

        virtual void generateMipmaps();

        GLuint getGLTexture() const
        {
            return texture;
        }

        GLenum getGLTarget() const;
        GLenum getGLBindingGet() const;
        GLenum getGLInternalFormat() const;
    private:
        GLuint texture;
        GfxTextureType textureType;

        unsigned int baseWidth;
        unsigned int baseHeight;
        unsigned int baseDepth;
        GfxTexFormat format;

        List<GfxGLFramebuffer *> framebuffers;
};

#endif // GFXGLTEXTUREIMPL_H

#ifndef GFXGLTEXTUREIMPL_H
#define GFXGLTEXTUREIMPL_H

#include "graphics/gfxtexture.h"

class GfxGLTextureImpl : public GfxTextureImpl
{
    NO_COPY_INHERITED(GfxGLTextureImpl, GfxTextureImpl)

    public:
        GfxGLTextureImpl();
        virtual ~GfxGLTextureImpl();

        virtual void startCreation(GfxTextureType type,
                                   bool compress,
                                   unsigned int baseWidth,
                                   unsigned int baseHeight,
                                   unsigned int baseDepth,
                                   uint8_t compressionQuality,
                                   GfxTexPurpose purpose,
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

        virtual void setMaximumAnisotropy(float maxAnisotropy);
        virtual void setMinFilter(GfxFilter minFilter);
        virtual void setMagFilter(GfxFilter magFilter);
        virtual void setMipmapMode(GfxMipmapMode mode);
        virtual void setWrapMode(GfxWrapMode mode);
        virtual void setShadowmap(bool shadowmap);
    private:
        GLuint texture;
        GfxTextureType textureType;

        GfxFilter minFilter;
        GfxMipmapMode mipmapMode;
        unsigned int baseWidth;
        unsigned int baseHeight;
        unsigned int baseDepth;
        GfxTexFormat format;
        float maximumAnisotropy;
        GfxWrapMode wrapMode;
        bool shadowmap;
        GfxFilter magFilter;

        void setMinFiltering();
};

#endif // GFXGLTEXTUREIMPL_H

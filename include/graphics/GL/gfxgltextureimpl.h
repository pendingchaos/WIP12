#ifndef GFXGLTEXTUREIMPL_H
#define GFXGLTEXTUREIMPL_H

#include "graphics/gfxtexture.h"

class GfxGLTextureImpl : public GfxTextureImpl
{
    NO_COPY_INHERITED(GfxGLTextureImpl, GfxTextureImpl)

    public:
        GfxGLTextureImpl();
        virtual ~GfxGLTextureImpl();

        virtual void startCreation(GfxTexture::TextureType type,
                                   bool compress,
                                   unsigned int baseWidth,
                                   unsigned int baseHeight,
                                   uint8_t compressionQuality,
                                   GfxTexture::Purpose purpose,
                                   GfxTexture::Format format);

        virtual void allocMipmapFace(unsigned int level,
                                     unsigned int pixelAlignment,
                                     GfxTexture::Face face,
                                     const void *data);

        virtual void allocMipmap(unsigned int level,
                                 unsigned int pixelAlignment,
                                 const void *data);

        virtual void getMipmapFace(unsigned int level,
                                   unsigned int pixelAlignment,
                                   GfxTexture::Face face,
                                   void *data);

        virtual void getMipmap(unsigned int level,
                               unsigned int pixelAlignment,
                               void *data);

        GLuint getGLTexture() const
        {
            return texture;
        }

        GLenum getGLTarget() const
        {
            return textureType == GfxTexture::CubeMap ? GL_TEXTURE_CUBE_MAP : GL_TEXTURE_2D;
        }

        GLenum getGLBindingGet() const
        {
            return textureType == GfxTexture::CubeMap ? GL_TEXTURE_BINDING_CUBE_MAP : GL_TEXTURE_BINDING_2D;
        }

        GLenum getGLInternalFormat() const;

        virtual void setMaximumAnisotropy(float maxAnisotropy);
        virtual void setMinFilter(GfxTexture::Filter minFilter);
        virtual void setMagFilter(GfxTexture::Filter magFilter);
        virtual void setMipmapMode(GfxTexture::MipmapMode mode);
        virtual void setWrapMode(GfxTexture::WrapMode mode);
        virtual void setShadowmap(bool shadowmap);
    private:
        GLuint texture;
        GfxTexture::TextureType textureType;

        GfxTexture::Filter minFilter;
        GfxTexture::MipmapMode mipmapMode;
        unsigned int baseWidth;
        unsigned int baseHeight;
        GfxTexture::Format format;
        float maximumAnisotropy;
        GfxTexture::WrapMode wrapMode;
        bool shadowmap;
        GfxTexture::Filter magFilter;

        void setMinFiltering();
};

#endif // GFXGLTEXTUREIMPL_H

#ifndef GFXTEXTURE_H
#define GFXTEXTURE_H

#include "containers/string.h"
#include "resource/resource.h"
#include "graphics/GL/glfl.h"

#include <stdint.h>
#include <cmath>
#include <algorithm>

#define _TEX_POW2(v) (2 << (v - 1))

#define TEX_COMPUTE_MIPMAP_SIZE(baseSize, level) static_cast<unsigned int>(std::max(1u, static_cast<unsigned int>(baseSize / _TEX_POW2(level))))

class GfxTextureImpl;
class GfxGLApi;

class GfxTexture : public Resource
{
    public:
        static const Resource::Type resource_type = GfxTextureType;

        enum TextureType
        {
            Texture2D,
            CubeMap,
            Texture3D
        };

        enum Filter
        {
            Nearest,
            Bilinear
        };

        enum MipmapMode
        {
            None,
            NearestMipmap,
            LinearMipmap
        };

        enum WrapMode
        {
            Stretch,
            Repeat,
            Mirror
        };

        /**
         *F32_F16 means the data is stored as 32 bit floats but is converted to
         *16 bit floats.
         *
         *The Int* And UInt* means that the texture is meant to be sampled with GLSL's
         *usampler* and uisampler* types.
         */
        enum Format
        {
            AlphaU8,
            AlphaI8,
            AlphaU16,
            AlphaI16,
            AlphaF32,
            AlphaF32_F16,

            LuminanceU8,
            LuminanceI8,
            LuminanceU16,
            LuminanceI16,
            LuminanceF32,
            LuminanceF32_F16,

            LuminanceAlphaU8,
            LuminanceAlphaI8,
            LuminanceAlphaU16,
            LuminanceAlphaI16,
            LuminanceAlphaF32,
            LuminanceAlphaF32_F16,

            RGBU8,
            RGBI8,
            RGBU16,
            RGBI16,
            RGBF32,
            RGBF32_F16,

            RGBAU8,
            RGBAI8,
            RGBAU16,
            RGBAI16,
            RGBAF32,
            RGBAF32_F16,

            Int_8,
            UInt_8,
            Int_16,
            UInt_16,
            Int_32,
            UInt_32,

            Int2_8,
            UInt2_8,
            Int2_16,
            UInt2_16,
            Int2_32,
            UInt2_32,

            Int3_8,
            UInt3_8,
            Int3_16,
            UInt3_16,
            Int3_32,
            UInt3_32,

            Int4_8,
            UInt4_8,
            Int4_16,
            UInt4_16,
            Int4_32,
            UInt4_32,

            SRGBU8,
            SRGBAU8,

            DepthF32_F16,
            DepthF32_F24,
            DepthF32,

            RedGreenU8,
            RedGreenI8,
            RedGreenU16,
            RedGreenI16,
            RedGreenF32,
            RedGreenF32_F16,

            RedU8,
            RedI8,
            RedU16,
            RedI16,
            RedF32,
            RedF32_F16
        };

        enum Purpose
        {
            Color,
            Normal,
            Other
        };

        enum Face
        {
            PositiveX,
            NegativeX,
            PositiveY,
            NegativeY,
            PositiveZ,
            NegativeZ
        };

        GfxTexture(const String& filename);
        GfxTexture();
        virtual ~GfxTexture();

        virtual void removeContent();

        void startCreation(GfxTexture::TextureType type,
                           bool compress,
                           unsigned int baseWidth,
                           unsigned int baseHeight,
                           unsigned int baseDepth,
                           uint8_t compressionQuality,
                           GfxTexture::Purpose purpose,
                           GfxTexture::Format format);

        void allocMipmapFace(unsigned int level,
                             unsigned int pixelAlignment,
                             GfxTexture::Face face,
                             const void *data);

        void allocMipmap(unsigned int level,
                         unsigned int pixelAlignment,
                         const void *data);

        void getMipmapFace(unsigned int level,
                           unsigned int pixelAlignment,
                           GfxTexture::Face face,
                           void *data) const;

        void getMipmap(unsigned int level,
                       unsigned int pixelAlignment,
                       void *data) const;

        void generateMipmaps();

        inline GfxTexture::TextureType getTextureType() const
        {
            return textureType;
        }

        inline bool shouldCompress() const
        {
            return compress;
        }

        inline float getMaximumAnisotropy() const
        {
            return maximumAnisotropy;
        }

        inline GfxTexture::Filter getMinFilter() const
        {
            return minFilter;
        }

        inline GfxTexture::Filter getMagFilter() const
        {
            return magFilter;
        }

        inline GfxTexture::MipmapMode getMipmapMode() const
        {
            return mipmapMode;
        }

        inline GfxTexture::WrapMode getWrapMode() const
        {
            return wrapMode;
        }

        inline unsigned int getBaseWidth() const
        {
            return baseWidth;
        }

        inline unsigned int getBaseHeight() const
        {
            return baseHeight;
        }

        inline unsigned int getBaseDepth() const
        {
            return baseDepth;
        }

        inline uint8_t getCompressionQuality() const
        {
            return compressionQuality;
        }

        inline GfxTexture::Purpose getPurpose() const
        {
            return purpose;
        }

        inline GfxTexture::Format getFormat() const
        {
            return format;
        }

        inline bool getShadowmap() const
        {
            return shadowmap;
        }

        void setMaximumAnisotropy(float maxAnisotropy);
        void setMinFilter(GfxTexture::Filter minFilter);
        void setMagFilter(GfxTexture::Filter magFilter);
        void setMipmapMode(GfxTexture::MipmapMode mode);
        void setWrapMode(GfxTexture::WrapMode mode);
        void setShadowmap(bool shadowmap);

        inline GfxTextureImpl *getImpl() const
        {
            return impl;
        }

        virtual void save();
    private:
        GfxTextureImpl *impl;
        TextureType textureType;
        bool compress;
        float maximumAnisotropy;
        Filter minFilter;
        Filter magFilter;
        MipmapMode mipmapMode;
        WrapMode wrapMode;
        unsigned int baseWidth;
        unsigned int baseHeight;
        unsigned int baseDepth;
        uint8_t compressionQuality;
        Purpose purpose;
        Format format;
        bool shadowmap;
    protected:
        virtual void _load();
        virtual Resource *_copy() const;

    NO_COPY_INHERITED(GfxTexture, Resource)
};

class GfxTextureImpl
{
    friend class GfxTexture;

    protected:
        GfxTextureImpl() {}
        virtual ~GfxTextureImpl() {}

        virtual void startCreation(GfxTexture::TextureType type,
                                   bool compress,
                                   unsigned int baseWidth,
                                   unsigned int baseHeight,
                                   unsigned int baseDepth,
                                   uint8_t compressionQuality,
                                   GfxTexture::Purpose purpose,
                                   GfxTexture::Format format)=0;

        virtual void allocMipmapFace(unsigned int level,
                                     unsigned int pixelAlignment,
                                     GfxTexture::Face face,
                                     const void *data)=0;

        virtual void allocMipmap(unsigned int level,
                                 unsigned int pixelAlignment,
                                 const void *data)=0;

        virtual void getMipmapFace(unsigned int level,
                                   unsigned int pixelAlignment,
                                   GfxTexture::Face face,
                                   void *data)=0;

        virtual void getMipmap(unsigned int level,
                               unsigned int pixelAlignment,
                               void *data)=0;

        virtual void generateMipmaps()=0;

        virtual void setMaximumAnisotropy(float maxAnisotropy)=0;
        virtual void setMinFilter(GfxTexture::Filter minFilter)=0;
        virtual void setMagFilter(GfxTexture::Filter magFilter)=0;
        virtual void setMipmapMode(GfxTexture::MipmapMode mode)=0;
        virtual void setWrapMode(GfxTexture::WrapMode mode)=0;
        virtual void setShadowmap(bool shadowmap)=0;

    NO_COPY(GfxTextureImpl)
};

#endif // GFXTEXTURE_H

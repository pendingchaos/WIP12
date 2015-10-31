#ifndef GFXTEXTURE_H
#define GFXTEXTURE_H

#include "containers/string.h"
#include "resource/resource.h"
#include "graphics/GL/glfl.h"
#include "scripting/bindings.h"

#include <stdint.h>
#include <cmath>
#include <algorithm>

#define _TEX_POW2(v) (2 << ((v) - 1))

#define TEX_COMPUTE_MIPMAP_SIZE(baseSize, level) static_cast<unsigned int>(std::max(1u, static_cast<unsigned int>((baseSize) / _TEX_POW2(level))))

class GfxTextureImpl;
class GfxGLApi;

enum class GfxTextureType
{
    Texture2D,
    CubeMap,
    Texture3D,
    Texture2DArray
} BIND ENUM_CLASS;

enum class GfxFilter
{
    Nearest,
    Bilinear
} BIND ENUM_CLASS;

enum class GfxMipmapMode
{
    None,
    Nearest,
    Linear
} BIND ENUM_CLASS;

enum class GfxWrapMode
{
    Stretch,
    Repeat,
    Mirror
} BIND ENUM_CLASS;

struct TextureSampler
{
    TextureSampler() : maxAnisotropy(1.0f),
                       minFilter(GfxFilter::Bilinear),
                       magFilter(GfxFilter::Bilinear),
                       mipmapMode(GfxMipmapMode::None),
                       wrapMode(GfxWrapMode::Repeat),
                       shadowmap(false) {}

    TextureSampler(float maxAnisotropy_,
                   GfxFilter minFilter_,
                   GfxFilter magFilter_,
                   GfxMipmapMode mipmapMode_,
                   GfxWrapMode wrapMode_,
                   bool shadowmap_) : maxAnisotropy(maxAnisotropy_),
                                      minFilter(minFilter_),
                                      magFilter(magFilter_),
                                      mipmapMode(mipmapMode_),
                                      wrapMode(wrapMode_),
                                      shadowmap(shadowmap_) {}

    static TextureSampler createShadowmap() NO_BIND
    {
        return TextureSampler(1.0f,
                              GfxFilter::Bilinear,
                              GfxFilter::Bilinear,
                              GfxMipmapMode::None,
                              GfxWrapMode::Stretch,
                              true);
    }

    float maxAnisotropy;
    GfxFilter minFilter;
    GfxFilter magFilter;
    GfxMipmapMode mipmapMode;
    GfxWrapMode wrapMode;
    bool shadowmap;
} BIND;

/**
 *F32_F16 means the data is stored as 32 bit floats but is converted to
 *16 bit floats.
 *
 *The Int* And UInt* means that the texture is meant to be sampled with GLSL's
 *usampler* and uisampler* types.
 */
enum class GfxTexFormat
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
} BIND ENUM_CLASS;

enum class GfxFace
{
    PositiveX,
    NegativeX,
    PositiveY,
    NegativeY,
    PositiveZ,
    NegativeZ
} BIND ENUM_CLASS;

class GfxTexture : public Resource
{
    public:
        static const ResType resource_type = ResType::GfxTextureType;

        GfxTexture(const Str& filename);
        GfxTexture();
        virtual ~GfxTexture();

        virtual void removeContent();

        void startCreation(GfxTextureType type,
                           unsigned int baseWidth,
                           unsigned int baseHeight,
                           unsigned int baseDepth,
                           GfxTexFormat format);

        void allocMipmapFace(unsigned int level,
                             unsigned int pixelAlignment,
                             GfxFace face,
                             const void *data) NO_BIND;

        void allocMipmap(unsigned int level,
                         unsigned int pixelAlignment,
                         const void *data) NO_BIND;

        void getMipmapFace(unsigned int level,
                           unsigned int pixelAlignment,
                           GfxFace face,
                           void *data) const NO_BIND;

        void getMipmap(unsigned int level,
                       unsigned int pixelAlignment,
                       void *data) const NO_BIND;

        //TODO: Make this safe.
        void allocMipmap(unsigned int level,
                         unsigned int pixelAlignment,
                         GfxFace face,
                         const ResizableData& data)
        {
            allocMipmapFace(level, pixelAlignment, face, data.getData());
        }

        //TODO: Make this safe.
        void allocMipmap(unsigned int level,
                         unsigned int pixelAlignment,
                         const ResizableData& data)
        {
            allocMipmap(level, pixelAlignment, data.getData());
        }

        void generateMipmaps();

        GfxTextureType getTextureType() const
        {
            return textureType;
        }

        unsigned int getBaseWidth() const
        {
            return baseWidth;
        }

        unsigned int getBaseHeight() const
        {
            return baseHeight;
        }

        unsigned int getBaseDepth() const
        {
            return baseDepth;
        }

        GfxTexFormat getFormat() const
        {
            return format;
        }

        GfxTextureImpl *getImpl() const NO_BIND
        {
            return impl;
        }

        virtual void save();

        TextureSampler sampler;
    private:
        GfxTextureImpl *impl;
        GfxTextureType textureType;
        unsigned int baseWidth;
        unsigned int baseHeight;
        unsigned int baseDepth;
        GfxTexFormat format;
    protected:
        virtual void _load();
        virtual Resource *_copy() const;

    NO_COPY_INHERITED(GfxTexture, Resource)
} BIND DESTROY(obj->release());

class GfxTextureImpl
{
    friend class GfxTexture;

    protected:
        GfxTextureImpl() {}
        virtual ~GfxTextureImpl() {}

        virtual void startCreation(GfxTextureType type,
                                   unsigned int baseWidth,
                                   unsigned int baseHeight,
                                   unsigned int baseDepth,
                                   GfxTexFormat format)=0;

        virtual void allocMipmapFace(unsigned int level,
                                     unsigned int pixelAlignment,
                                     GfxFace face,
                                     const void *data)=0;

        virtual void allocMipmap(unsigned int level,
                                 unsigned int pixelAlignment,
                                 const void *data)=0;

        virtual void getMipmapFace(unsigned int level,
                                   unsigned int pixelAlignment,
                                   GfxFace face,
                                   void *data)=0;

        virtual void getMipmap(unsigned int level,
                               unsigned int pixelAlignment,
                               void *data)=0;

        virtual void generateMipmaps()=0;

    NO_COPY(GfxTextureImpl)
};

#endif // GFXTEXTURE_H

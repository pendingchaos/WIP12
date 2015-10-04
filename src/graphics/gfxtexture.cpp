#include "graphics/gfxtexture.h"

#include "graphics/gfxapi.h"
#include "globals.h"
#include "memory.h"
#include "file.h"

#include <cmath>

static const GfxFilter filters[] = {GfxFilter::Nearest, GfxFilter::Bilinear};

static const GfxMipmapMode mipmapModes[] = {GfxMipmapMode::None,
                                            GfxMipmapMode::Nearest,
                                            GfxMipmapMode::Linear};

static const GfxWrapMode wrapModes[] = {GfxWrapMode::Stretch,
                                        GfxWrapMode::Repeat,
                                        GfxWrapMode::Mirror};

static const GfxTexPurpose purposes[] = {GfxTexPurpose::Color,
                                         GfxTexPurpose::Normal,
                                         GfxTexPurpose::Other};

static const GfxTexFormat formats[] = {GfxTexFormat::AlphaU8,
                                       GfxTexFormat::AlphaI8,
                                       GfxTexFormat::AlphaU16,
                                       GfxTexFormat::AlphaI16,
                                       GfxTexFormat::AlphaF32,
                                       GfxTexFormat::AlphaF32_F16,
                                       GfxTexFormat::LuminanceU8,
                                       GfxTexFormat::LuminanceI8,
                                       GfxTexFormat::LuminanceU16,
                                       GfxTexFormat::LuminanceI16,
                                       GfxTexFormat::LuminanceF32,
                                       GfxTexFormat::LuminanceF32_F16,
                                       GfxTexFormat::LuminanceAlphaU8,
                                       GfxTexFormat::LuminanceAlphaI8,
                                       GfxTexFormat::LuminanceAlphaU16,
                                       GfxTexFormat::LuminanceAlphaI16,
                                       GfxTexFormat::LuminanceAlphaF32,
                                       GfxTexFormat::LuminanceAlphaF32_F16,
                                       GfxTexFormat::RGBU8,
                                       GfxTexFormat::RGBI8,
                                       GfxTexFormat::RGBU16,
                                       GfxTexFormat::RGBI16,
                                       GfxTexFormat::RGBF32,
                                       GfxTexFormat::RGBF32_F16,
                                       GfxTexFormat::RGBAU8,
                                       GfxTexFormat::RGBAI8,
                                       GfxTexFormat::RGBAU16,
                                       GfxTexFormat::RGBAI16,
                                       GfxTexFormat::RGBAF32,
                                       GfxTexFormat::RGBAF32_F16,
                                       GfxTexFormat::Int_8,
                                       GfxTexFormat::UInt_8,
                                       GfxTexFormat::Int_16,
                                       GfxTexFormat::UInt_16,
                                       GfxTexFormat::Int_32,
                                       GfxTexFormat::UInt_32,
                                       GfxTexFormat::Int2_8,
                                       GfxTexFormat::UInt2_8,
                                       GfxTexFormat::Int2_16,
                                       GfxTexFormat::UInt2_16,
                                       GfxTexFormat::Int2_32,
                                       GfxTexFormat::UInt2_32,
                                       GfxTexFormat::Int3_8,
                                       GfxTexFormat::UInt3_8,
                                       GfxTexFormat::Int3_16,
                                       GfxTexFormat::UInt3_16,
                                       GfxTexFormat::Int3_32,
                                       GfxTexFormat::UInt3_32,
                                       GfxTexFormat::Int4_8,
                                       GfxTexFormat::UInt4_8,
                                       GfxTexFormat::Int4_16,
                                       GfxTexFormat::UInt4_16,
                                       GfxTexFormat::Int4_32,
                                       GfxTexFormat::UInt4_32,
                                       GfxTexFormat::SRGBU8,
                                       GfxTexFormat::SRGBAU8,
                                       GfxTexFormat::DepthF32_F16,
                                       GfxTexFormat::DepthF32_F24,
                                       GfxTexFormat::DepthF32,
                                       GfxTexFormat::RedGreenU8,
                                       GfxTexFormat::RedGreenI8,
                                       GfxTexFormat::RedGreenU16,
                                       GfxTexFormat::RedGreenI16,
                                       GfxTexFormat::RedGreenF32,
                                       GfxTexFormat::RedGreenF32_F16,
                                       GfxTexFormat::RedU8,
                                       GfxTexFormat::RedI8,
                                       GfxTexFormat::RedU16,
                                       GfxTexFormat::RedI16,
                                       GfxTexFormat::RedF32,
                                       GfxTexFormat::RedF32_F16};

static const GfxFace faces[] = {GfxFace::PositiveX,
                                GfxFace::NegativeX,
                                GfxFace::PositiveY,
                                GfxFace::NegativeY,
                                GfxFace::PositiveZ,
                                GfxFace::NegativeZ};

static const size_t formatSizes[] = {1,
                                     1,
                                     2,
                                     2,
                                     4,
                                     4,
                                     1,
                                     1,
                                     2,
                                     2,
                                     4,
                                     4,
                                     2,
                                     2,
                                     4,
                                     4,
                                     8,
                                     8,
                                     3,
                                     3,
                                     6,
                                     6,
                                     12,
                                     12,
                                     4,
                                     4,
                                     8,
                                     8,
                                     16,
                                     16,
                                     1,
                                     1,
                                     2,
                                     2,
                                     4,
                                     4,
                                     2,
                                     2,
                                     4,
                                     4,
                                     8,
                                     8,
                                     3,
                                     3,
                                     6,
                                     6,
                                     12,
                                     12,
                                     4,
                                     4,
                                     8,
                                     8,
                                     16,
                                     16,
                                     3,
                                     4,
                                     2,
                                     2,
                                     4,
                                     4,
                                     8,
                                     8,
                                     1,
                                     1,
                                     2,
                                     2,
                                     4,
                                     4};

GfxTexture::GfxTexture(const String& filename) : Resource(filename,
                                                          ResType::GfxTextureType),
                                                 impl(gfxApi->createTextureImpl())
{
    textureType = GfxTextureType::Texture2D;
    compress = false;
    setMaximumAnisotropy(1.0f);
    setMinFilter(GfxFilter::Bilinear);
    setMagFilter(GfxFilter::Bilinear);
    setMipmapMode(GfxMipmapMode::None);
    setWrapMode(GfxWrapMode::Repeat);
    baseWidth = 0;
    baseHeight = 0;
    baseDepth = 0;
    compressionQuality = 255;
    purpose = GfxTexPurpose::Other;
    shadowmap = false;
}

GfxTexture::GfxTexture() : Resource(ResType::GfxTextureType),
                           impl(gfxApi->createTextureImpl())
{
    textureType = GfxTextureType::Texture2D;
    compress = false;
    setMaximumAnisotropy(1.0f);
    setMinFilter(GfxFilter::Bilinear);
    setMagFilter(GfxFilter::Bilinear);
    setMipmapMode(GfxMipmapMode::None);
    setWrapMode(GfxWrapMode::Repeat);
    baseWidth = 0;
    baseHeight = 0;
    baseDepth = 0;
    compressionQuality = 255;
    purpose = GfxTexPurpose::Other;
    shadowmap = false;
}

GfxTexture::~GfxTexture()
{
    DELETE(impl);
}

void GfxTexture::removeContent()
{
    textureType = GfxTextureType::Texture2D;
    compress = false;
    setMaximumAnisotropy(1.0f);
    setMinFilter(GfxFilter::Bilinear);
    setMagFilter(GfxFilter::Bilinear);
    setMipmapMode(GfxMipmapMode::None);
    setWrapMode(GfxWrapMode::Repeat);
    baseWidth = 0;
    baseHeight = 0;
    baseDepth = 0;
    compressionQuality = 255;
    purpose = GfxTexPurpose::Other;
    shadowmap = false;

    DELETE(impl);
    impl = gfxApi->createTextureImpl();
}

void GfxTexture::startCreation(GfxTextureType type_,
                               bool compress_,
                               unsigned int baseWidth_,
                               unsigned int baseHeight_,
                               unsigned int baseDepth_,
                               uint8_t compressionQuality_,
                               GfxTexPurpose purpose_,
                               GfxTexFormat format_)
{
    textureType = type_;
    compress = compress_;
    baseWidth = baseWidth_;
    baseHeight = baseHeight_;
    baseDepth = (type_ == GfxTextureType::Texture3D or type_ == GfxTextureType::Texture2DArray) ? baseDepth_ : 1;
    compressionQuality = compressionQuality_;
    purpose = purpose_;
    format = format_;

    impl->startCreation(textureType,
                        compress,
                        baseWidth,
                        baseHeight,
                        baseDepth,
                        compressionQuality,
                        purpose,
                        format);
}

void GfxTexture::allocMipmapFace(unsigned int level,
                                 unsigned int pixelAlignment,
                                 GfxFace face,
                                 const void *data)
{
    impl->allocMipmapFace(level, pixelAlignment, face, data);
}

void GfxTexture::allocMipmap(unsigned int level,
                             unsigned int pixelAlignment,
                             const void *data)
{
    impl->allocMipmap(level, pixelAlignment, data);
}

void GfxTexture::getMipmapFace(unsigned int level,
                               unsigned int pixelAlignment,
                               GfxFace face,
                               void *data) const
{
    impl->getMipmapFace(level, pixelAlignment, face, data);
}

void GfxTexture::getMipmap(unsigned int level,
                           unsigned int pixelAlignment,
                           void *data) const
{
    impl->getMipmap(level, pixelAlignment, data);
}

void GfxTexture::generateMipmaps()
{
    impl->generateMipmaps();
}

void GfxTexture::setMaximumAnisotropy(float maxAnisotropy)
{
    maximumAnisotropy = maxAnisotropy;

    impl->setMaximumAnisotropy(maxAnisotropy);
}

void GfxTexture::setMinFilter(GfxFilter minFilter_)
{
    minFilter = minFilter_;

    impl->setMinFilter(minFilter_);
}

void GfxTexture::setMagFilter(GfxFilter magFilter_)
{
    magFilter = magFilter_;

    impl->setMagFilter(magFilter_);
}

void GfxTexture::setMipmapMode(GfxMipmapMode mode)
{
    mipmapMode = mode;

    impl->setMipmapMode(mode);
}

void GfxTexture::setWrapMode(GfxWrapMode mode)
{
    wrapMode = mode;

    impl->setWrapMode(wrapMode);
}

void GfxTexture::setShadowmap(bool shadowmap_)
{
    shadowmap = shadowmap_;

    impl->setShadowmap(shadowmap_);
}

void GfxTexture::_load()
{
    try
    {
        removeContent();

        File file(getFilename().getData(), "rb");

        char magic[4];

        file.read(4, magic);

        if (magic[0] != 't' or
            magic[1] != 'e' or
            magic[2] != 'x' or
            magic[3] != 'r')
        {
            THROW(ResourceIOException,
                  "texture",
                  getFilename(),
                  "Invalid magic");
        }

        uint8_t majorVer = file.readUInt8();
        uint8_t minorVer = file.readUInt8();

        if (majorVer != 1 or minorVer != 0)
        {
            THROW(ResourceIOException,
                  "texture",
                  getFilename(),
                  "Unsupported version");
        }

        bool compress = file.readUInt8() != 0;
        uint8_t compressionQuality = file.readUInt8();
        GfxFilter minFilter = filters[file.readUInt8()];
        GfxFilter magFilter = filters[file.readUInt8()];
        float maxAnisotropy = file.readFloat32();
        GfxMipmapMode mipmapMode = mipmapModes[file.readUInt8()];
        GfxWrapMode wrapMode = wrapModes[file.readUInt8()];
        GfxTexPurpose purpose = purposes[file.readUInt8()];
        GfxTexFormat format = formats[file.readUInt8()];

        GfxTextureType type = (GfxTextureType)file.readUInt8();
        uint32_t numMipmaps = file.readUInt32LE();
        uint32_t baseWidth = file.readUInt32LE();
        uint32_t baseHeight = file.readUInt32LE();
        uint32_t baseDepth = file.readUInt32LE();

        startCreation(type,
                      compress,
                      baseWidth,
                      baseHeight,
                      baseDepth,
                      compressionQuality,
                      purpose,
                      format);

        setMinFilter(minFilter);
        setMagFilter(magFilter);
        setMipmapMode(mipmapMode);
        setWrapMode(wrapMode);
        setMaximumAnisotropy(maxAnisotropy);

        for (size_t i = 0; i < (type == GfxTextureType::CubeMap ? 6 : 1); ++i)
        {
            GfxFace face = faces[i];

            for (size_t j = 0; j < numMipmaps; ++j)
            {
                uint32_t size = file.readUInt32LE();

                void *data = ALLOCATE(size);

                file.read(size, data);

                if (type == GfxTextureType::CubeMap)
                {
                    allocMipmapFace(j, 1, face, data);
                } else
                {
                    allocMipmap(j, 1, data);
                }

                DEALLOCATE(data);
            }
        }
    } catch (FileException& e)
    {
        THROW(ResourceIOException,
              "texture",
              getFilename(),
              e.getString());
    }
}

void GfxTexture::save()
{
    try
    {
        File file(getFilename().getData(), "wb");

        file.write(6, "texr\x01\x00");

        size_t numMipmaps = std::log2(std::min(baseWidth, baseHeight));

        file.writeUInt8(compress);
        file.writeUInt8(compressionQuality);
        file.writeUInt8((uint8_t)minFilter);
        file.writeUInt8((uint8_t)magFilter);
        file.writeFloat32(maximumAnisotropy);
        file.writeUInt8((uint8_t)mipmapMode);
        file.writeUInt8((uint8_t)wrapMode);
        file.writeUInt8((uint8_t)purpose);
        file.writeUInt8((uint8_t)format);
        file.writeUInt8((uint8_t)textureType);
        file.writeUInt32LE(numMipmaps);
        file.writeUInt32LE(baseWidth);
        file.writeUInt32LE(baseHeight);
        file.writeUInt32LE(baseDepth);

        if (textureType == GfxTextureType::Texture2D)
        {
            size_t width = baseWidth;
            size_t height = baseHeight;

            for (size_t i = 0; i < numMipmaps; ++i)
            {
                size_t amount = formatSizes[(int)format] * width * height;

                file.writeUInt32LE(amount);

                void *data = ALLOCATE(amount);

                getMipmap(i, 1, data);

                file.write(amount, data);

                DEALLOCATE(data);

                width /= 2;
                height /= 2;
            }
        } else if (textureType == GfxTextureType::Texture3D)
        {
            size_t width = baseWidth;
            size_t height = baseHeight;
            size_t depth = baseDepth;

            for (size_t i = 0; i < numMipmaps; ++i)
            {
                size_t amount = formatSizes[(int)format] * width * height * depth;

                file.writeUInt32LE(amount);

                void *data = ALLOCATE(amount);

                //TODO: This won't work.
                getMipmap(i, 1, data);

                file.write(amount, data);

                DEALLOCATE(data);

                width /= 2;
                height /= 2;
                depth /= 2;
            }
        } else if (textureType == GfxTextureType::CubeMap)
        {
            for (size_t j = 0; j < 6; ++j)
            {
                size_t width = baseWidth;
                size_t height = baseHeight;

                for (size_t i = 0; i < numMipmaps; ++i)
                {
                    size_t amount = formatSizes[(int)format] * width * height;

                    file.writeUInt32LE(amount);

                    void *data = ALLOCATE(amount);

                    getMipmapFace(i, 1, (GfxFace)j, data);

                    file.write(amount, data);

                    DEALLOCATE(data);

                    width /= 2;
                    height /= 2;
                }
            }
        } else
        {
            //TODO
        }
    } catch (FileException& e)
    {
        THROW(ResourceIOException,
              "texture",
              getFilename(),
              e.getString());
    }
}

Resource *GfxTexture::_copy() const
{
    GfxTexture *texture = NEW(GfxTexture);

    texture->startCreation(textureType,
                           compress,
                           baseWidth,
                           baseHeight,
                           baseDepth,
                           compressionQuality,
                           purpose,
                           format);

    if (textureType == GfxTextureType::Texture2D)
    {
        size_t w = baseWidth;
        size_t h = baseHeight;

        for (size_t i = 0; w>1 and h>1; ++i)
        {
            void *data = ALLOCATE(formatSizes[(int)format]*w*h);

            getMipmap(i, 1, data);

            texture->allocMipmap(i, 1, data);

            DEALLOCATE(data);

            w /= 2;
            h /= 2;
        }
    } else if (textureType == GfxTextureType::Texture3D)
    {
        size_t w = baseWidth;
        size_t h = baseHeight;
        size_t d = baseDepth;

        for (size_t i = 0; w>1 and h>1 and d>1; ++i)
        {
            void *data = ALLOCATE(formatSizes[(int)format]*w*h*d);

            getMipmap(i, 1, data);

            texture->allocMipmap(i, 1, data);

            DEALLOCATE(data);

            w /= 2;
            h /= 2;
            d /= 2;
        }
    } else if (textureType == GfxTextureType::CubeMap)
    {
        size_t w = baseWidth;
        size_t h = baseHeight;

        for (size_t i = 0; w>1 and h>1; ++i)
        {
            void *data = ALLOCATE(formatSizes[(int)format]*w*h);

            for (size_t j = 0; j < 6; ++j)
            {
                GfxFace face = (GfxFace)j;

                getMipmapFace(i, 1, face, data);

                texture->allocMipmapFace(i, 1, face, data);
            }

            DEALLOCATE(data);

            w /= 2;
            h /= 2;
        }
    }

    texture->setMaximumAnisotropy(maximumAnisotropy);
    texture->setMinFilter(minFilter);
    texture->setMagFilter(magFilter);
    texture->setMipmapMode(mipmapMode);
    texture->setWrapMode(wrapMode);
    texture->setShadowmap(shadowmap);

    return (Resource *)texture;
}

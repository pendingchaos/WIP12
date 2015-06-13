#include "graphics/gfxtexture.h"

#include "graphics/gfxapi.h"
#include "globals.h"
#include "memory.h"
#include "file.h"

#include <cmath>

static const GfxTexture::Filter filters[] = {GfxTexture::Nearest, GfxTexture::Bilinear};

static const GfxTexture::MipmapMode mipmapModes[] = {GfxTexture::None,
                                                     GfxTexture::NearestMipmap,
                                                     GfxTexture::LinearMipmap};

static const GfxTexture::WrapMode wrapModes[] = {GfxTexture::Stretch,
                                                 GfxTexture::Repeat,
                                                 GfxTexture::Mirror};

static const GfxTexture::Purpose purposes[] = {GfxTexture::Color,
                                               GfxTexture::Normal,
                                               GfxTexture::Other};

static const GfxTexture::Format formats[] = {GfxTexture::AlphaU8,
                                             GfxTexture::AlphaI8,
                                             GfxTexture::AlphaU16,
                                             GfxTexture::AlphaI16,
                                             GfxTexture::AlphaF32,
                                             GfxTexture::AlphaF32_F16,
                                             GfxTexture::LuminanceU8,
                                             GfxTexture::LuminanceI8,
                                             GfxTexture::LuminanceU16,
                                             GfxTexture::LuminanceI16,
                                             GfxTexture::LuminanceF32,
                                             GfxTexture::LuminanceF32_F16,
                                             GfxTexture::LuminanceAlphaU8,
                                             GfxTexture::LuminanceAlphaI8,
                                             GfxTexture::LuminanceAlphaU16,
                                             GfxTexture::LuminanceAlphaI16,
                                             GfxTexture::LuminanceAlphaF32,
                                             GfxTexture::LuminanceAlphaF32_F16,
                                             GfxTexture::RGBU8,
                                             GfxTexture::RGBI8,
                                             GfxTexture::RGBU16,
                                             GfxTexture::RGBI16,
                                             GfxTexture::RGBF32,
                                             GfxTexture::RGBF32_F16,
                                             GfxTexture::RGBAU8,
                                             GfxTexture::RGBAI8,
                                             GfxTexture::RGBAU16,
                                             GfxTexture::RGBAI16,
                                             GfxTexture::RGBAF32,
                                             GfxTexture::RGBAF32_F16,
                                             GfxTexture::Int_8,
                                             GfxTexture::UInt_8,
                                             GfxTexture::Int_16,
                                             GfxTexture::UInt_16,
                                             GfxTexture::Int_32,
                                             GfxTexture::UInt_32,
                                             GfxTexture::Int2_8,
                                             GfxTexture::UInt2_8,
                                             GfxTexture::Int2_16,
                                             GfxTexture::UInt2_16,
                                             GfxTexture::Int2_32,
                                             GfxTexture::UInt2_32,
                                             GfxTexture::Int3_8,
                                             GfxTexture::UInt3_8,
                                             GfxTexture::Int3_16,
                                             GfxTexture::UInt3_16,
                                             GfxTexture::Int3_32,
                                             GfxTexture::UInt3_32,
                                             GfxTexture::Int4_8,
                                             GfxTexture::UInt4_8,
                                             GfxTexture::Int4_16,
                                             GfxTexture::UInt4_16,
                                             GfxTexture::Int4_32,
                                             GfxTexture::UInt4_32,
                                             GfxTexture::SRGBU8,
                                             GfxTexture::SRGBAU8,
                                             GfxTexture::DepthF32_F16,
                                             GfxTexture::DepthF32_F24,
                                             GfxTexture::DepthF32,
                                             GfxTexture::RedGreenU8,
                                             GfxTexture::RedGreenI8,
                                             GfxTexture::RedGreenU16,
                                             GfxTexture::RedGreenI16,
                                             GfxTexture::RedGreenF32,
                                             GfxTexture::RedGreenF32_F16,
                                             GfxTexture::RedU8,
                                             GfxTexture::RedI8,
                                             GfxTexture::RedU16,
                                             GfxTexture::RedI16,
                                             GfxTexture::RedF32,
                                             GfxTexture::RedF32_F16};

static const GfxTexture::Face faces[] = {GfxTexture::PositiveX,
                                         GfxTexture::NegativeX,
                                         GfxTexture::PositiveY,
                                         GfxTexture::NegativeY,
                                         GfxTexture::PositiveZ,
                                         GfxTexture::NegativeZ};

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

GfxTexture::GfxTexture(const String& filename,
                       const String& name) : Resource(filename,
                                                      name,
                                                      GfxTextureType),
                                             impl(gfxApi->createTextureImpl())
{
    textureType = Texture2D;
    compress = false;
    setMaximumAnisotropy(1.0f);
    setMinFilter(Bilinear);
    setMagFilter(Bilinear);
    setMipmapMode(None);
    setWrapMode(Repeat);
    baseWidth = 0;
    baseHeight = 0;
    compressionQuality = 255;
    purpose = Other;
    shadowmap = false;
}

GfxTexture::GfxTexture(const String& name) : Resource(name,
                                                      GfxTextureType),
                                             impl(gfxApi->createTextureImpl())
{
    textureType = Texture2D;
    compress = false;
    setMaximumAnisotropy(1.0f);
    setMinFilter(Bilinear);
    setMagFilter(Bilinear);
    setMipmapMode(None);
    setWrapMode(Repeat);
    baseWidth = 0;
    baseHeight = 0;
    compressionQuality = 255;
    purpose = Other;
    shadowmap = false;
}

GfxTexture::~GfxTexture()
{
    DELETE(GfxTextureImpl, impl);
}

void GfxTexture::removeContent()
{
    textureType = Texture2D;
    compress = false;
    setMaximumAnisotropy(1.0f);
    setMinFilter(Bilinear);
    setMagFilter(Bilinear);
    setMipmapMode(None);
    setWrapMode(Repeat);
    baseWidth = 0;
    baseHeight = 0;
    compressionQuality = 255;
    purpose = Other;
    shadowmap = false;

    DELETE(GfxTextureImpl, impl);
    impl = gfxApi->createTextureImpl();
}

void GfxTexture::startCreation(TextureType type_,
                               bool compress_,
                               unsigned int baseWidth_,
                               unsigned int baseHeight_,
                               uint8_t compressionQuality_,
                               Purpose purpose_,
                               Format format_)
{
    textureType = type_;
    compress = compress_;
    baseWidth = baseWidth_;
    baseHeight = baseHeight_;
    compressionQuality = compressionQuality_;
    purpose = purpose_;
    format = format_;

    impl->startCreation(textureType,
                        compress,
                        baseWidth,
                        baseHeight,
                        compressionQuality,
                        purpose,
                        format);
}

void GfxTexture::allocMipmapFace(unsigned int level,
                                 unsigned int pixelAlignment,
                                 Face face,
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
                               Face face,
                               void *data)
{
    getMipmapFace(level, pixelAlignment, face, data);
}

void GfxTexture::getMipmap(unsigned int level,
                           unsigned int pixelAlignment,
                           void *data)
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

void GfxTexture::setMinFilter(Filter minFilter_)
{
    minFilter = minFilter_;

    impl->setMinFilter(minFilter_);
}

void GfxTexture::setMagFilter(Filter magFilter_)
{
    magFilter = magFilter_;

    impl->setMagFilter(magFilter_);
}

void GfxTexture::setMipmapMode(MipmapMode mode)
{
    mipmapMode = mode;

    impl->setMipmapMode(mode);
}

void GfxTexture::setWrapMode(WrapMode mode)
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

        File file(filename.getData(), "rb");

        char magic[4];

        file.read(4, magic);

        if (magic[0] != 't' or
            magic[1] != 'e' or
            magic[2] != 'x' or
            magic[3] != 'r')
        {
            THROW(ResourceIOException,
                  "texture",
                  filename,
                  "Invalid magic");
        }

        uint8_t majorVer = file.readUInt8();
        uint8_t minorVer = file.readUInt8();

        if (majorVer != 1 or minorVer != 0)
        {
            THROW(ResourceIOException,
                  "texture",
                  filename,
                  "Unsupported version");
        }

        bool compress = file.readUInt8() != 0;
        uint8_t compressionQuality = file.readUInt8();
        GfxTexture::Filter minFilter = filters[file.readUInt8()];
        GfxTexture::Filter magFilter = filters[file.readUInt8()];
        float maxAnisotropy = file.readFloat32();
        GfxTexture::MipmapMode mipmapMode = mipmapModes[file.readUInt8()];
        GfxTexture::WrapMode wrapMode = wrapModes[file.readUInt8()];
        GfxTexture::Purpose purpose = purposes[file.readUInt8()];
        GfxTexture::Format format = formats[file.readUInt8()];

        uint32_t numFaces = file.readUInt32LE();
        uint32_t numMipmaps = file.readUInt32LE();
        uint32_t baseWidth = file.readUInt32LE();
        uint32_t baseHeight = file.readUInt32LE();

        if (numFaces != 1 and numFaces != 6)
        {
            THROW(ResourceIOException,
                  "texture",
                  filename,
                  "Invalid face count");
        }

        startCreation(numFaces == 1 ? GfxTexture::Texture2D : GfxTexture::CubeMap,
                      compress,
                      baseWidth,
                      baseHeight,
                      compressionQuality,
                      purpose,
                      format);

        setMinFilter(minFilter);
        setMagFilter(magFilter);
        setMipmapMode(mipmapMode);
        setWrapMode(wrapMode);
        setMaximumAnisotropy(maxAnisotropy);

        for (size_t i = 0; i < numFaces; ++i)
        {
            GfxTexture::Face face = faces[i];

            for (size_t j = 0; j < numMipmaps; ++j)
            {
                uint32_t size = file.readUInt32LE();

                void *data = ALLOCATE(size);

                file.read(size, data);

                if (numFaces == 1)
                {
                    allocMipmap(j, 1, data);
                } else if (numFaces == 6)
                {
                    allocMipmapFace(j, 1, face, data);
                }

                DEALLOCATE(data);
            }
        }
    } catch (FileException& e)
    {
        THROW(ResourceIOException,
              "texture",
              filename,
              e.getString());
    }
}

void GfxTexture::save()
{
    try
    {
        File file(filename.getData(), "wb");

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
        file.writeUInt32LE(textureType == GfxTexture::Texture2D ? 1 : 6);
        file.writeUInt32LE(numMipmaps);
        file.writeUInt32LE(baseWidth);
        file.writeUInt32LE(baseHeight);

        if (textureType == GfxTexture::Texture2D)
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
        } else if (textureType == GfxTexture::CubeMap)
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

                    getMipmapFace(i, 1, (Face)j, data);

                    file.write(amount, data);

                    DEALLOCATE(data);

                    width /= 2;
                    height /= 2;
                }
            }
        }
    } catch (FileException& e)
    {
        THROW(ResourceIOException,
              "texture",
              filename,
              e.getString());
    }
}

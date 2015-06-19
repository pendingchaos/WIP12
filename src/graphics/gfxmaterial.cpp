#include "graphics/gfxmaterial.h"

#include "globals.h"
#include "graphics/gfxapi.h"
#include "graphics/gfxrenderer.h"
#include "file.h"

GfxMaterial::GfxMaterial() : Resource(GfxMaterialType),
                             forward(true)
{
    shaderComb = NEW(GfxShaderCombination,
                     resMgr->getResource<GfxShader>("resources/shaders/forwardVertex.bin"),
                     resMgr->getResource<GfxShader>("resources/shaders/forwardFragment.bin"));
}

GfxMaterial::GfxMaterial(const String& filename) : Resource(filename,
                                                            GfxMaterialType),
                                                   forward(true)
{
    shaderComb = NEW(GfxShaderCombination,
                     resMgr->getResource<GfxShader>("resources/shaders/forwardVertex.bin"),
                     resMgr->getResource<GfxShader>("resources/shaders/forwardFragment.bin"));
}

GfxMaterial::~GfxMaterial()
{
    DELETE(GfxShaderCombination, shaderComb);
}

void GfxMaterial::removeContent()
{
    setForward(true);
}

void GfxMaterial::save()
{
    File file(filename.getData(), "wb");

    file.write(6, "mtrl\x01\x00");

    file.writeUInt8(forward ? 1 : 0);

    file.writeFloat32(albedo.x);
    file.writeFloat32(albedo.y);
    file.writeFloat32(albedo.z);
    file.writeFloat32(albedo.w);
    file.writeFloat32(smoothness);
    file.writeFloat32(metalMask);

    if (albedoMap != nullptr)
    {
        String filename = albedoMap->filename;

        file.writeUInt32LE(filename.getLength());
        file.write(filename.getLength(), filename.getData());
    } else
    {
        file.writeUInt32LE(0);
    }

    if (smoothnessMap != nullptr)
    {
        String filename = smoothnessMap->filename;

        file.writeUInt32LE(filename.getLength());
        file.write(filename.getLength(), filename.getData());
    } else
    {
        file.writeUInt32LE(0);
    }

    if (metalMaskMap != nullptr)
    {
        String filename = metalMaskMap->filename;

        file.writeUInt32LE(filename.getLength());
        file.write(filename.getLength(), filename.getData());
    } else
    {
        file.writeUInt32LE(0);
    }

    if (normalMap != nullptr)
    {
        String filename = normalMap->filename;

        file.writeUInt32LE(filename.getLength());
        file.write(filename.getLength(), filename.getData());
    } else
    {
        file.writeUInt32LE(0);
    }
}

void GfxMaterial::setForward(bool forward_)
{
    forward = forward_;

    if (forward)
    {
        shaderComb = NEW(GfxShaderCombination,
                         resMgr->getResource<GfxShader>("resources/shaders/forwardVertex.bin"),
                         resMgr->getResource<GfxShader>("resources/shaders/forwardFragment.bin"));
    } else
    {
        shaderComb = NEW(GfxShaderCombination,
                         resMgr->getResource<GfxShader>("resources/shaders/gbufferVertex.bin"),
                         resMgr->getResource<GfxShader>("resources/shaders/gbufferFragment.bin"));
    }
}

void GfxMaterial::_load()
{
    try
    {
        File file(filename.getData(), "rb");

        char magic[4];

        file.read(4, magic);

        if (magic[0] != 'm' or
            magic[1] != 't' or
            magic[2] != 'r' or
            magic[3] != 'l')
        {
            THROW(ResourceIOException, "material", filename, "Invalid magic.");
        }

        uint8_t majorVer = file.readUInt8();
        uint8_t minorVer = file.readUInt8();

        if (majorVer != 1 or minorVer != 0)
        {
            THROW(ResourceIOException, "material", filename, "Unsupported version.");
        }

        setForward(file.readUInt8() != 0);

        float r = file.readFloat32();
        float g = file.readFloat32();
        float b = file.readFloat32();
        float a = file.readFloat32();

        albedo = Float4(r, g, b, a);

        smoothness = file.readFloat32();

        metalMask = file.readFloat32();

        uint32_t len = file.readUInt32LE();
        if (len != 0)
        {
            String tex(len);
            file.read(len, tex.getData());
            setAlbedoMap(resMgr->getResource<GfxTexture>(tex));
        }

        len = file.readUInt32LE();
        if (len != 0)
        {
            String tex(len);
            file.read(len, tex.getData());
            setSmoothnessMap(resMgr->getResource<GfxTexture>(tex));
        }

        len = file.readUInt32LE();
        if (len != 0)
        {
            String tex(len);
            file.read(len, tex.getData());
            setMetalMaskMap(resMgr->getResource<GfxTexture>(tex));
        }

        len = file.readUInt32LE();
        if (len != 0)
        {
            String tex(len);
            file.read(len, tex.getData());
            setNormalMap(resMgr->getResource<GfxTexture>(tex));
        }
    } catch (FileException& e)
    {
        THROW(ResourceIOException,
              "material",
              filename,
              e.getString());
    }
}

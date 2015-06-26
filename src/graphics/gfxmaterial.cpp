#include "graphics/gfxmaterial.h"

#include "globals.h"
#include "graphics/gfxapi.h"
#include "graphics/gfxrenderer.h"
#include "file.h"

GfxMaterial::GfxMaterial() : Resource(GfxMaterialType),
                             smoothness(0.5f),
                             metalMask(0.0f),
                             parallaxStrength(0.0F),
                             albedo(1.0f),
                             pomMinLayers(8),
                             pomMaxLayers(32),
                             minTessLevel(1.0f),
                             maxTessLevel(10.0f),
                             tessMinDistance(0.0f),
                             tessMaxDistance(10.0f),
                             displacementStrength(0.1f),
                             displacementMidlevel(0.5f),
                             forward(true)
{
    shaderComb = NEW(GfxShaderCombination,
                     resMgr->getResource<GfxShader>("resources/shaders/objectVertex.bin"),
                     resMgr->getResource<GfxShader>("resources/shaders/forwardFragment.bin"));
}

GfxMaterial::GfxMaterial(const String& filename) : Resource(filename,
                                                            GfxMaterialType),
                                                   smoothness(0.5f),
                                                   metalMask(0.0f),
                                                   parallaxStrength(0.0F),
                                                   albedo(1.0f),
                                                   pomMinLayers(8),
                                                   pomMaxLayers(32),
                                                   minTessLevel(1.0f),
                                                   maxTessLevel(10.0f),
                                                   tessMinDistance(0.0f),
                                                   tessMaxDistance(10.0f),
                                                   displacementStrength(0.1f),
                                                   displacementMidlevel(0.5f),
                                                   forward(true)
{
    shaderComb = NEW(GfxShaderCombination,
                     resMgr->getResource<GfxShader>("resources/shaders/objectVertex.bin"),
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
    file.writeFloat32(parallaxStrength);
    file.writeUInt8(parallaxEdgeDiscard ? 1 : 0);
    file.writeUInt8(pomMinLayers);
    file.writeUInt8(pomMaxLayers);
    file.writeFloat32(minTessLevel);
    file.writeFloat32(maxTessLevel);
    file.writeFloat32(tessMinDistance);
    file.writeFloat32(tessMaxDistance);
    file.writeFloat32(displacementStrength);
    file.writeFloat32(displacementMidlevel);

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

    if (parallaxHeightMap != nullptr)
    {
        String filename = parallaxHeightMap->filename;

        file.writeUInt32LE(filename.getLength());
        file.write(filename.getLength(), filename.getData());
    } else
    {
        file.writeUInt32LE(0);
    }

    if (pomHeightMap != nullptr)
    {
        String filename = pomHeightMap->filename;

        file.writeUInt32LE(filename.getLength());
        file.write(filename.getLength(), filename.getData());
    } else
    {
        file.writeUInt32LE(0);
    }

    if (displacementMap != nullptr)
    {
        String filename = displacementMap->filename;

        file.writeUInt32LE(filename.getLength());
        file.write(filename.getLength(), filename.getData());
    } else
    {
        file.writeUInt32LE(0);
    }
}

void GfxMaterial::setDisplacementMap(ResPtr<GfxTexture> texture)
{
    displacementMap = texture;

    if (displacementMap != nullptr)
    {
        shaderComb->setTessControlShader(resMgr->getResource<GfxShader>("resources/shaders/objectTessControl.bin"));
        shaderComb->setTessEvalShader(resMgr->getResource<GfxShader>("resources/shaders/objectTessEval.bin"));
    }
}

void GfxMaterial::setForward(bool forward_)
{
    forward = forward_;

    if (forward)
    {
        shaderComb = NEW(GfxShaderCombination,
                         resMgr->getResource<GfxShader>("resources/shaders/objectVertex.bin"),
                         resMgr->getResource<GfxShader>("resources/shaders/forwardFragment.bin"));
    } else
    {
        shaderComb = NEW(GfxShaderCombination,
                         resMgr->getResource<GfxShader>("resources/shaders/objectVertex.bin"),
                         resMgr->getResource<GfxShader>("resources/shaders/gbufferFragment.bin"));
    }

    setDisplacementMap(displacementMap);
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

        parallaxStrength = file.readFloat32();

        parallaxEdgeDiscard = file.readUInt8() != 0;

        pomMinLayers = file.readUInt8();
        pomMaxLayers = file.readUInt8();

        minTessLevel = file.readFloat32();
        maxTessLevel = file.readFloat32();
        tessMinDistance = file.readFloat32();
        tessMaxDistance = file.readFloat32();
        displacementStrength = file.readFloat32();
        displacementMidlevel = file.readFloat32();

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

        len = file.readUInt32LE();
        if (len != 0)
        {
            String tex(len);
            file.read(len, tex.getData());
            setParallaxHeightMap(resMgr->getResource<GfxTexture>(tex));
        }

        len = file.readUInt32LE();
        if (len != 0)
        {
            String tex(len);
            file.read(len, tex.getData());
            setPOMHeightMap(resMgr->getResource<GfxTexture>(tex));
        }

        len = file.readUInt32LE();
        if (len != 0)
        {
            String tex(len);
            file.read(len, tex.getData());
            setDisplacementMap(resMgr->getResource<GfxTexture>(tex));
        }
    } catch (FileException& e)
    {
        THROW(ResourceIOException,
              "material",
              filename,
              e.getString());
    }
}

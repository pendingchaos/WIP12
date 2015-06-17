#include "graphics/gfxmaterial.h"

#include "globals.h"
#include "graphics/gfxapi.h"
#include "graphics/gfxrenderer.h"
#include "file.h"

GfxLitMaterialImpl::GfxLitMaterialImpl(bool forward_) : smoothness(1.0f),
                                                        metalMask(1.0f),
                                                        albedo(1.0f),
                                                        forward(forward_),
                                                        fragmentBuffer(gfxApi->createBuffer()),
                                                        lastSmoothness(0.0f),
                                                        lastMetalMask(0.0f),
                                                        lastAlbedo(0.0f)
{
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

    float data[] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};

    fragmentBuffer->allocData(24, data, GfxBuffer::Static);
}

GfxLitMaterialImpl::~GfxLitMaterialImpl()
{
    DELETE(GfxShaderCombination, shaderComb);
    DELETE(GfxBuffer, fragmentBuffer);
}

void GfxLitMaterialImpl::render(GfxRenderer *renderer,
                                ResPtr<GfxMesh> mesh,
                                const Matrix4x4& worldMatrix)
{
    GfxCompiledShader *fragment = shaderComb->getCompiledFragmentShader();

    GfxRenderer::beginRenderMesh(renderer->camera, worldMatrix, mesh, shaderComb);

    if (smoothness != lastSmoothness or
        metalMask != lastMetalMask or
        albedo != lastAlbedo)
    {
        lastSmoothness = smoothness;
        lastMetalMask = metalMask;
        lastAlbedo = albedo;

        float data[] = {albedo.x, albedo.y, albedo.z, albedo.w, smoothness, metalMask};

        fragmentBuffer->setData(0, 24, data);
    }

    gfxApi->addUBOBinding(fragment, "material", fragmentBuffer);

    if (forward)
    {
        gfxApi->uniform(fragment, "numLights", (uint32_t)renderer->getNumLights());
        gfxApi->addUBOBinding(fragment, "lights_", renderer->getLightBuffer());
    }

    if (smoothnessMap != nullptr)
    {
        gfxApi->addTextureBinding(fragment, "smoothnessMap", smoothnessMap);
    }

    if (metalMaskMap != nullptr)
    {
        gfxApi->addTextureBinding(fragment, "metalMaskMap", metalMaskMap);
    }

    if (albedoMap != nullptr)
    {
        gfxApi->addTextureBinding(fragment, "albedoMap", albedoMap);
    }

    if (normalMap != nullptr)
    {
        gfxApi->addTextureBinding(fragment, "normalMap", normalMap);
    }

    if (environmentMap != nullptr and forward)
    {
        gfxApi->addTextureBinding(fragment, "environment", environmentMap);
    }

    GfxRenderer::endRenderMesh(mesh);
}

GfxMaterial::GfxMaterial() : Resource(GfxMaterialType),
                             impl(nullptr)
{
    setMatType(Forward);
}

GfxMaterial::GfxMaterial(const String& filename) : Resource(filename,
                                                            GfxMaterialType),
                                                   impl(nullptr)
{
    setMatType(Forward);
}

GfxMaterial::~GfxMaterial()
{
    DELETE(GfxMaterialImpl, impl);
}

void GfxMaterial::removeContent()
{
    DELETE(GfxMaterialImpl, impl);
    impl = nullptr;
}

void GfxMaterial::save()
{
    File file(filename.getData(), "wb");

    file.write(6, "mtrl\x01\x00");

    switch (matType)
    {
    case Forward:
    case Deferred:
    {
        file.writeUInt8(0);

        GfxLitMaterialImpl *impl_ = dynamic_cast<GfxLitMaterialImpl *>(impl);

        file.writeUInt8(impl_->isForward());

        file.writeFloat32(impl_->albedo.x);
        file.writeFloat32(impl_->albedo.y);
        file.writeFloat32(impl_->albedo.z);
        file.writeFloat32(impl_->albedo.w);
        file.writeFloat32(impl_->smoothness);
        file.writeFloat32(impl_->metalMask);

        if (impl_->getAlbedoMap() != nullptr)
        {
            String filename = impl_->getAlbedoMap()->filename;

            file.writeUInt32LE(filename.getLength());
            file.write(filename.getLength(), filename.getData());
        } else
        {
            file.writeUInt32LE(0);
        }

        if (impl_->getSmoothnessMap() != nullptr)
        {
            String filename = impl_->getSmoothnessMap()->filename;

            file.writeUInt32LE(filename.getLength());
            file.write(filename.getLength(), filename.getData());
        } else
        {
            file.writeUInt32LE(0);
        }

        if (impl_->getMetalMaskMap() != nullptr)
        {
            String filename = impl_->getMetalMaskMap()->filename;

            file.writeUInt32LE(filename.getLength());
            file.write(filename.getLength(), filename.getData());
        } else
        {
            file.writeUInt32LE(0);
        }

        if (impl_->getNormalMap() != nullptr)
        {
            String filename = impl_->getNormalMap()->filename;

            file.writeUInt32LE(filename.getLength());
            file.write(filename.getLength(), filename.getData());
        } else
        {
            file.writeUInt32LE(0);
        }

        if (impl_->getEnvironmentMap() != nullptr)
        {
            String filename = impl_->getEnvironmentMap()->filename;

            file.writeUInt32LE(filename.getLength());
            file.write(filename.getLength(), filename.getData());
        } else
        {
            file.writeUInt32LE(0);
        }
        break;
    }
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

        uint8_t type = file.readUInt8();

        if (type == 0)
        {
            setMatType(file.readUInt8() == 0 ? Deferred : Forward);

            GfxLitMaterialImpl *impl = dynamic_cast<GfxLitMaterialImpl *>(getImpl());

            float r = file.readFloat32();
            float g = file.readFloat32();
            float b = file.readFloat32();
            float a = file.readFloat32();

            impl->albedo = Float4(r, g, b, a);

            impl->smoothness = file.readFloat32();

            impl->metalMask = file.readFloat32();

            uint32_t len = file.readUInt32LE();
            if (len != 0)
            {
                String tex(len);
                file.read(len, tex.getData());
                impl->setAlbedoMap(resMgr->getResource<GfxTexture>(tex));
            }

            len = file.readUInt32LE();
            if (len != 0)
            {
                String tex(len);
                file.read(len, tex.getData());
                impl->setSmoothnessMap(resMgr->getResource<GfxTexture>(tex));
            }

            len = file.readUInt32LE();
            if (len != 0)
            {
                String tex(len);
                file.read(len, tex.getData());
                impl->setMetalMaskMap(resMgr->getResource<GfxTexture>(tex));
            }

            len = file.readUInt32LE();
            if (len != 0)
            {
                String tex(len);
                file.read(len, tex.getData());
                impl->setNormalMap(resMgr->getResource<GfxTexture>(tex));
            }

            len = file.readUInt32LE();
            if (len != 0)
            {
                String tex(len);
                file.read(len, tex.getData());
                impl->setEnvironmentMap(resMgr->getResource<GfxTexture>(tex));
            }
        } else
        {
            THROW(ResourceIOException, "material", filename, "Invalid material type.");
        }
    } catch (FileException& e)
    {
        THROW(ResourceIOException,
              "material",
              filename,
              e.getString());
    }
}

void GfxMaterial::setMatType(MaterialType type_)
{
    DELETE(GfxMaterialImpl, impl);

    switch (type_)
    {
    case Forward:
    {
        impl = NEW(GfxLitMaterialImpl, true);
        break;
    }
    case Deferred:
    {
        impl = NEW(GfxLitMaterialImpl, false);
        break;
    }
    }

    matType = type_;
}

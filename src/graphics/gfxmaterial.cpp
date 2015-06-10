#include "graphics/gfxmaterial.h"

#include "globals.h"
#include "graphics/gfxapi.h"
#include "graphics/gfxrenderer.h"
#include "file.h"

GfxLitMaterialImpl::ShaderComb::ShaderComb(GfxLitMaterialImpl *mat_) : mat(mat_)
{
    if (mat->forward)
    {
        vertexShader = resMgr->getResourceByFilename<GfxShader>("resources/shaders/forwardVertex.bin");
        fragmentShader = resMgr->getResourceByFilename<GfxShader>("resources/shaders/forwardFragment.bin");
    } else
    {
        vertexShader = resMgr->getResourceByFilename<GfxShader>("resources/shaders/gbufferVertex.bin");
        fragmentShader = resMgr->getResourceByFilename<GfxShader>("resources/shaders/gbufferFragment.bin");
    }
}

ResPtr<GfxShader> GfxLitMaterialImpl::ShaderComb::getVertexShader() const
{
    return vertexShader;
}

ResPtr<GfxShader> GfxLitMaterialImpl::ShaderComb::getFragmentShader() const
{
    return fragmentShader;
}

bool GfxLitMaterialImpl::ShaderComb::fragmentDefinesDirty() const
{
    return GfxShaderCombination::fragmentDefinesDirty() or
           lastAlbedoMap != mat->albedoMap or
           lastSmoothnessMap != mat->smoothnessMap or
           lastMetalMaskMap != mat->metalMaskMap or
           lastNormalMap != mat->normalMap or
           lastEnvironmentMap != mat->environmentMap;
}

void GfxLitMaterialImpl::ShaderComb::getFragmentDefines(HashMap<String, String >& defines) const
{
    if (mat->smoothnessMap != nullptr)
    {
        defines.set("SMOOTHNESS_MAP", "1");

        lastSmoothnessMap = mat->smoothnessMap;
    }

    if (mat->metalMaskMap != nullptr)
    {
        defines.set("METAL_MASK_MAP", "1");

        lastMetalMaskMap = mat->metalMaskMap;
    }

    if (mat->albedoMap != nullptr)
    {
        defines.set("ALBEDO_MAP", "1");

        lastAlbedoMap = mat->albedoMap;
    }

    if (mat->normalMap != nullptr)
    {
        defines.set("NORMAL_MAP", "1");

        lastNormalMap = mat->normalMap;
    }

    if (mat->environmentMap != nullptr)
    {
        defines.set("ENVIRONMENT_MAP", "1");

        lastEnvironmentMap = mat->environmentMap;
    }
}

GfxLitMaterialImpl::GfxLitMaterialImpl(bool forward_) : smoothness(1.0f),
                                                        metalMask(1.0f),
                                                        albedo(1.0f),
                                                        forward(forward_),
                                                        fragmentBuffer(gfxApi->createBuffer()),
                                                        lastSmoothness(0.0f),
                                                        lastMetalMask(0.0f),
                                                        lastAlbedo(0.0f)
{
    shaderComb = NEW(ShaderComb, this);

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

GfxMaterial::GfxMaterial(const String& name) : Resource(name,
                                                        GfxMaterialType),
                                               impl(nullptr)
{
    setMatType(Forward);
}

GfxMaterial::GfxMaterial(const String& filename,
                         const String& name) : Resource(filename,
                                                        name,
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

        if (impl_->albedoMap != nullptr)
        {
            String filename = impl_->albedoMap->filename;

            file.writeUInt32LE(filename.getLength());
            file.write(filename.getLength(), filename.getData());
        } else
        {
            file.writeUInt32LE(0);
        }

        if (impl_->smoothnessMap != nullptr)
        {
            String filename = impl_->smoothnessMap->filename;

            file.writeUInt32LE(filename.getLength());
            file.write(filename.getLength(), filename.getData());
        } else
        {
            file.writeUInt32LE(0);
        }

        if (impl_->metalMaskMap != nullptr)
        {
            String filename = impl_->metalMaskMap->filename;

            file.writeUInt32LE(filename.getLength());
            file.write(filename.getLength(), filename.getData());
        } else
        {
            file.writeUInt32LE(0);
        }

        if (impl_->normalMap != nullptr)
        {
            String filename = impl_->normalMap->filename;

            file.writeUInt32LE(filename.getLength());
            file.write(filename.getLength(), filename.getData());
        } else
        {
            file.writeUInt32LE(0);
        }

        if (impl_->environmentMap != nullptr)
        {
            String filename = impl_->environmentMap->filename;

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
                impl->albedoMap = resMgr->getResourceByFilename<GfxTexture>(tex);
            }

            len = file.readUInt32LE();
            if (len != 0)
            {
                String tex(len);
                file.read(len, tex.getData());
                impl->smoothnessMap = resMgr->getResourceByFilename<GfxTexture>(tex);
            }

            len = file.readUInt32LE();
            if (len != 0)
            {
                String tex(len);
                file.read(len, tex.getData());
                impl->metalMaskMap = resMgr->getResourceByFilename<GfxTexture>(tex);
            }

            len = file.readUInt32LE();
            if (len != 0)
            {
                String tex(len);
                file.read(len, tex.getData());
                impl->normalMap = resMgr->getResourceByFilename<GfxTexture>(tex);
            }

            len = file.readUInt32LE();
            if (len != 0)
            {
                String tex(len);
                file.read(len, tex.getData());
                impl->environmentMap = resMgr->getResourceByFilename<GfxTexture>(tex);
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

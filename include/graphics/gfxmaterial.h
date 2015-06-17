#ifndef MATERIAL_H
#define MATERIAL_H

#include "containers/list.h"
#include "containers/hashmap.h"
#include "containers/string.h"
#include "graphics/gfxtexture.h"
#include "graphics/gfxshader.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxdefs.h"
#include "resource/resource.h"
#include "resource/resourcemanager.h"
#include "math/t4.h"
#include "misc_macros.h"
#include "memory.h"

class Matrix4x4;
class GfxRenderer;

class GfxMaterialImpl
{
    public:
        GfxMaterialImpl() {}
        virtual ~GfxMaterialImpl() {}

        virtual void render(GfxRenderer *renderer,
                            ResPtr<GfxMesh> mesh,
                            const Matrix4x4& worldMatrix)=0;

        inline GfxShaderCombination *getShaderComb() const
        {
            return shaderComb;
        }
    protected:
        GfxShaderCombination *shaderComb;

    NO_COPY(GfxMaterialImpl)
};

class GfxLitMaterialImpl : public GfxMaterialImpl
{
    NO_COPY_INHERITED(GfxLitMaterialImpl, GfxMaterialImpl)

    public:
        GfxLitMaterialImpl(bool forward);
        virtual ~GfxLitMaterialImpl();

        virtual void render(GfxRenderer *renderer,
                            ResPtr<GfxMesh> mesh,
                            const Matrix4x4& worldMatrix);

        float smoothness;
        float metalMask;
        Float4 albedo;

        inline void setSmoothnessMap(ResPtr<GfxTexture> texture)
        {
            smoothnessMap = texture;

            if (smoothnessMap != nullptr)
            {
                shaderComb->setFragmentDefine("SMOOTHNESS_MAP", "1");
            } else
            {
                shaderComb->removeFragmentDefine("SMOOTHNESS_MAP");
            }
        }

        inline void setMetalMaskMap(ResPtr<GfxTexture> texture)
        {
            metalMaskMap = texture;

            if (metalMaskMap != nullptr)
            {
                shaderComb->setFragmentDefine("METAL_MASK_MAP", "1");
            } else
            {
                shaderComb->removeFragmentDefine("METAL_MASK_MAP");
            }
        }

        inline void setAlbedoMap(ResPtr<GfxTexture> texture)
        {
            albedoMap = texture;

            if (albedoMap != nullptr)
            {
                shaderComb->setFragmentDefine("ALBEDO_MAP", "1");
            } else
            {
                shaderComb->removeFragmentDefine("ALBEDO_MAP");
            }
        }

        inline void setNormalMap(ResPtr<GfxTexture> texture)
        {
            normalMap = texture;

            if (normalMap != nullptr)
            {
                shaderComb->setFragmentDefine("NORMAL_MAP", "1");
            } else
            {
                shaderComb->removeFragmentDefine("NORMAL_MAP");
            }
        }

        inline void setEnvironmentMap(ResPtr<GfxTexture> texture)
        {
            environmentMap = texture;

            if (environmentMap != nullptr)
            {
                shaderComb->setFragmentDefine("ENVIRONMENT_MAP", "1");
            } else
            {
                shaderComb->removeFragmentDefine("ENVIRONMENT_MAP");
            }
        }

        inline ResPtr<GfxTexture> getSmoothnessMap() const
        {
            return smoothnessMap;
        }

        inline ResPtr<GfxTexture> getMetalMaskMap() const
        {
            return metalMaskMap;
        }

        inline ResPtr<GfxTexture> getAlbedoMap() const
        {
            return albedoMap;
        }

        inline ResPtr<GfxTexture> getNormalMap() const
        {
            return normalMap;
        }

        inline ResPtr<GfxTexture> getEnvironmentMap() const
        {
            return environmentMap;
        }

        inline bool isForward()
        {
            return forward;
        }
    private:
        ResPtr<GfxTexture> smoothnessMap;
        ResPtr<GfxTexture> metalMaskMap;
        ResPtr<GfxTexture> albedoMap;
        ResPtr<GfxTexture> normalMap;
        ResPtr<GfxTexture> environmentMap;

        bool forward;
        GfxBuffer *fragmentBuffer;

        float lastSmoothness;
        float lastMetalMask;
        Float4 lastAlbedo;
};

class GfxMaterial : public Resource
{
    public:
        enum MaterialType
        {
            Forward,
            Deferred
        };

        static const Resource::Type resource_type = GfxMaterialType;

        GfxMaterial();
        GfxMaterial(const String& filename);

        virtual ~GfxMaterial();

        virtual void removeContent();

        virtual void save();

        void setMatType(MaterialType type_);

        inline MaterialType getMatType() const
        {
            return matType;
        }

        void render(GfxRenderer *renderer,
                    ResPtr<GfxMesh> mesh,
                    const Matrix4x4& worldMatrix) const
        {
            impl->render(renderer, mesh, worldMatrix);
        }

        inline GfxShaderCombination *getShaderComb() const
        {
            return impl->getShaderComb();
        }

        inline GfxMaterialImpl *getImpl() const
        {
            return impl;
        }
    private:
        MaterialType matType;
        mutable GfxMaterialImpl *impl;
    protected:
        virtual void _load();

    NO_COPY_INHERITED(GfxMaterial, Resource)
};

#endif // MATERIAL_H

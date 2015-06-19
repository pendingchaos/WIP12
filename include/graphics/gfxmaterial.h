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

class GfxMaterial : public Resource
{
    public:
        static const Resource::Type resource_type = GfxMaterialType;

        GfxMaterial();
        GfxMaterial(const String& filename);

        virtual ~GfxMaterial();

        virtual void removeContent();

        virtual void save();

        inline GfxShaderCombination *getShaderComb() const
        {
            return shaderComb;
        }

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

        inline bool isForward() const
        {
            return forward;
        }

        void setForward(bool forward);
    private:
        GfxShaderCombination *shaderComb;

        ResPtr<GfxTexture> smoothnessMap;
        ResPtr<GfxTexture> metalMaskMap;
        ResPtr<GfxTexture> albedoMap;
        ResPtr<GfxTexture> normalMap;

        bool forward;
    protected:
        virtual void _load();

    NO_COPY_INHERITED(GfxMaterial, Resource)
};

#endif // MATERIAL_H

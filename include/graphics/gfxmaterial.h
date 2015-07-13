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
        float parallaxStrength;
        bool parallaxEdgeDiscard;
        Float4 albedo;
        unsigned int pomMinLayers;
        unsigned int pomMaxLayers;
        float minTessLevel;
        float maxTessLevel;
        float tessMinDistance;
        float tessMaxDistance;
        float displacementStrength;
        float displacementMidlevel;
        bool shadowTesselation;
        float shadowMinTessLevel;
        float shadowMaxTessLevel;

        #define TEXTURE(name, upperName, define) inline void JOIN(set, upperName)(ResPtr<GfxTexture> texture)\
        {\
            if (name != nullptr)\
            {\
                name->release();\
            }\
            name = texture;\
            if (name != nullptr)\
            {\
                shaderComb->setFragmentDefine(define, "1");\
            } else\
            {\
                shaderComb->removeFragmentDefine(define);\
            }\
        }\
        \
        inline ResPtr<GfxTexture> JOIN(get, upperName)() const\
        {\
            return name;\
        }

        TEXTURE(smoothnessMap, SmoothnessMap, "SMOOTHNESS_MAP")
        TEXTURE(metalMaskMap, MetalMaskMap, "METAL_MASK_MAP")
        TEXTURE(albedoMap, AlbedoMap, "ALBEDO_MAP")
        TEXTURE(normalMap, NormalMap, "NORMAL_MAP")
        TEXTURE(parallaxHeightMap, ParallaxHeightMap, "PARALLAX_MAPPING")
        TEXTURE(pomHeightMap, POMHeightMap, "POM")

        #undef TEXTURE

        void setDisplacementMap(ResPtr<GfxTexture> texture);

        inline ResPtr<GfxTexture> getDisplacementMap() const
        {
            return displacementMap;
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
        ResPtr<GfxTexture> parallaxHeightMap;
        ResPtr<GfxTexture> pomHeightMap;
        ResPtr<GfxTexture> displacementMap;

        bool forward;
    protected:
        virtual void _load();
        virtual Resource *_copy() const;

    NO_COPY_INHERITED(GfxMaterial, Resource)
};

#endif // MATERIAL_H

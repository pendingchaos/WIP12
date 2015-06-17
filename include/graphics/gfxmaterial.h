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
    public:
        GfxLitMaterialImpl(bool forward);
        virtual ~GfxLitMaterialImpl();

        virtual void render(GfxRenderer *renderer,
                            ResPtr<GfxMesh> mesh,
                            const Matrix4x4& worldMatrix);

        float smoothness;
        ResPtr<GfxTexture> smoothnessMap;
        float metalMask;
        ResPtr<GfxTexture> metalMaskMap;
        Float4 albedo;
        ResPtr<GfxTexture> albedoMap;
        ResPtr<GfxTexture> environmentMap;
        ResPtr<GfxTexture> normalMap;

        inline bool isForward()
        {
            return forward;
        }
    private:
        bool forward;
        GfxBuffer *fragmentBuffer;

        float lastSmoothness;
        float lastMetalMask;
        Float4 lastAlbedo;

        class ShaderComb : public GfxShaderCombination
        {
            public:
                ShaderComb(GfxLitMaterialImpl *mat);

                virtual ResPtr<GfxShader> getVertexShader() const;

                virtual ResPtr<GfxShader> getFragmentShader() const;

                virtual bool fragmentDefinesDirty() const;
                virtual void getFragmentDefines(HashMap<String, String >& defines) const;

                GfxLitMaterialImpl *mat;

                ResPtr<GfxShader> vertexShader;
                ResPtr<GfxShader> fragmentShader;

                mutable ResPtr<GfxTexture> lastSmoothnessMap;
                mutable ResPtr<GfxTexture> lastMetalMaskMap;
                mutable ResPtr<GfxTexture> lastAlbedoMap;
                mutable ResPtr<GfxTexture> lastNormalMap;
                mutable ResPtr<GfxTexture> lastEnvironmentMap;
        };

    NO_COPY_INHERITED(GfxLitMaterialImpl, GfxMaterialImpl)
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

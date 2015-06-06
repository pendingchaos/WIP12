#ifndef GFXRENDERER_H
#define GFXRENDERER_H

#include "graphics/gfxmesh.h"
#include "graphics/gfxshader.h"
#include "graphics/gfxmodel.h"

class Camera;
class Matrix4x4;
class String;

class GfxRenderer
{
    public:
        GfxRenderer();
        ~GfxRenderer();

        void beginRenderMesh(const Camera& camera,
                             const Matrix4x4& worldMatrix,
                             ResPtr<GfxMesh> mesh,
                             GfxShaderCombination *comb);
        void endRenderMesh(ResPtr<GfxMesh> mesh);

        void renderScene(const ResPtr<Scene> scene);

        inline size_t getNumLights() const
        {
            return numLights;
        }

        inline GfxBuffer *getLightBuffer() const
        {
            return lightBuffer;
        }
    private:
        ResPtr<GfxShader> skyboxVertex;
        ResPtr<GfxShader> skyboxFragment;
        ResPtr<GfxMesh> skyboxMesh;

        size_t numLights;
        GfxBuffer *lightBuffer;

        void fillLightBuffer(ResPtr<Scene> scene);
        void renderModel(GfxModel::ContextType contextName,
                         const Camera& camera,
                         const Matrix4x4& worldMatrix,
                         const ResPtr<GfxModel> model);
};

#endif // GFXRENDERER_H

#ifndef GFXRENDERER_H
#define GFXRENDERER_H

#include "math/t2.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxshader.h"
#include "graphics/gfxmodel.h"
#include "graphics/camera.h"
#include "graphics/light.h"

class Matrix4x4;
class String;

class GfxRenderer
{
    public:
        GfxRenderer(ResPtr<Scene> scene);
        ~GfxRenderer();

        static void beginRenderMesh(const Camera& camera,
                                    const Matrix4x4& worldMatrix,
                                    ResPtr<GfxMesh> mesh,
                                    GfxShaderCombination *comb);
        static void endRenderMesh(ResPtr<GfxMesh> mesh);

        void resize(const UInt2& size);
        void render();

        inline size_t getNumLights() const
        {
            return numLights;
        }

        inline GfxBuffer *getLightBuffer() const
        {
            return lightBuffer;
        }

        Camera camera;
        bool debugDraw;
        ResPtr<GfxTexture> skybox;
        List<Light> lights;
    private:
        unsigned int width;
        unsigned int height;

        ResPtr<Scene> scene;

        ResPtr<GfxShader> skyboxVertex;
        ResPtr<GfxShader> skyboxFragment;
        ResPtr<GfxMesh> skyboxMesh;

        size_t numLights;
        GfxBuffer *lightBuffer;

        void fillLightBuffer(ResPtr<Scene> scene);
        void renderEntities();
        void renderSkybox();
        void renderModel(GfxModel::ContextType contextName,
                         const Camera& camera,
                         const Matrix4x4& worldMatrix,
                         const ResPtr<GfxModel> model);
};

#endif // GFXRENDERER_H

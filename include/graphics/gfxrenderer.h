#ifndef GFXRENDERER_H
#define GFXRENDERER_H

#include "math/t2.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxshader.h"
#include "graphics/gfxmodel.h"
#include "graphics/gfxtexture.h"
#include "graphics/camera.h"
#include "graphics/light.h"
#include "scene/scene.h"

class Matrix4x4;
class String;
class GfxFramebuffer;

class GfxRenderer
{
    private:
        friend class Scene;

        GfxRenderer(Scene *scene);
    public:
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

        float vignetteRadius;
        float vignetteSoftness;
        float vignetteIntensity;
    private:
        unsigned int width;
        unsigned int height;

        Scene *scene;

        ResPtr<GfxShader> skyboxVertex;
        ResPtr<GfxShader> skyboxFragment;
        ResPtr<GfxMesh> skyboxMesh;
        ResPtr<GfxMesh> fullScreenQuadMesh;
        ResPtr<GfxShader> gammaCorrectionFragment;
        ResPtr<GfxShader> vignetteFragment;
        ResPtr<GfxShader> fxaaFragment;
        ResPtr<GfxShader> lightingDirectional;
        ResPtr<GfxShader> lightingPoint;
        ResPtr<GfxShader> lightingSpot;
        ResPtr<GfxShader> ssaoFragment;
        ResPtr<GfxShader> ssaoBlurXFragment;
        ResPtr<GfxShader> ssaoBlurYFragment;
        ResPtr<GfxShader> postEffectVertex;
        GfxCompiledShader *compiledGammaCorrectionFragment;
        GfxCompiledShader *compiledVignetteFragment;
        GfxCompiledShader *compiledFXAAFragment;
        GfxCompiledShader *compiledLightingDirectional;
        GfxCompiledShader *compiledLightingPoint;
        GfxCompiledShader *compiledLightingSpot;
        GfxCompiledShader *compiledSSAOFragment;
        GfxCompiledShader *compiledSSAOBlurXFragment;
        GfxCompiledShader *compiledSSAOBlurYFragment;
        GfxCompiledShader *compiledPostEffectVertex;

        size_t numLights;
        GfxBuffer *lightBuffer;

        void fillLightBuffer(ResPtr<Scene> scene);
        void renderEntities(GfxModel::ContextType contextType);
        void renderSkybox();
        void renderModel(GfxModel::ContextType contextType,
                         const Camera& camera,
                         const Matrix4x4& worldMatrix,
                         const ResPtr<GfxModel> model);

        ResPtr<GfxTexture> writeColorTexture;
        ResPtr<GfxTexture> readColorTexture;
        ResPtr<GfxTexture> depthTexture;
        ResPtr<GfxTexture> materialTexture;
        ResPtr<GfxTexture> normalTexture;
        ResPtr<GfxTexture> ssaoTexture;
        ResPtr<GfxTexture> ssaoBlurXTexture;

        GfxFramebuffer *readFramebuffer;
        GfxFramebuffer *writeFramebuffer;
        GfxFramebuffer *gBufferFramebuffer;
        GfxFramebuffer *ssaoFramebuffer;
        GfxFramebuffer *ssaoBlurXFramebuffer;

        void swapFramebuffers();
};

#endif // GFXRENDERER_H

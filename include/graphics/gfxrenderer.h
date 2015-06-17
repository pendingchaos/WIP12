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
class GPUTimer;

class GfxRenderer
{
    private:
        friend class Scene;

        GfxRenderer(Scene *scene);
    public:
        struct RenderStats
        {
            float gBufferTiming;
            float ssaoTiming;
            float ssaoBlurXTiming;
            float ssaoBlurYTiming;
            float deferredShadingTiming;
            float forwardTiming;
            float gammaCorrectionTiming;
            float fxaaTiming;
            float vignetteTiming;
            float bloomXTiming;
            float bloomYTiming;
            //float lumCalcTiming;
            float tonemappingTiming;
            float shadowmapTiming;
        };

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

        inline RenderStats getStats() const
        {
            return stats;
        }

        /*inline float getAverageLuminance() const
        {
            return averageLuminance;
        }*/

        inline Light *addLight()
        {
            Light *light = NEW(Light);

            lights.append(light);

            return light;
        }

        inline void removeLight(size_t index)
        {
            DELETE(Light, lights[index]);

            lights.remove(index);
        }

        inline const List<Light *>& getLights() const
        {
            return lights;
        }

        void updateStats();

        Camera camera;

        bool debugDraw;

        ResPtr<GfxTexture> skybox;

        float vignetteRadius;
        float vignetteSoftness;
        float vignetteIntensity;
        float bloomThreshold;
        float bloomRadius;
        float bloomQuality;
        bool bloomEnabled;
        float ssaoRadius;
    private:
        List<Light *> lights;

        RenderStats stats;

        GPUTimer *gBufferTimer;
        GPUTimer *ssaoTimer;
        GPUTimer *ssaoBlurXTimer;
        GPUTimer *ssaoBlurYTimer;
        GPUTimer *deferredShadingTimer;
        GPUTimer *forwardTimer;
        GPUTimer *gammaCorrectionTimer;
        GPUTimer *fxaaTimer;
        GPUTimer *vignetteTimer;
        GPUTimer *bloomXTimer;
        GPUTimer *bloomYTimer;
        //GPUTimer *luminanceCalcTimer;
        GPUTimer *tonemappingTimer;
        GPUTimer *shadowmapTimer;

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
        ResPtr<GfxShader> bloomBlurXFragment;
        ResPtr<GfxShader> bloomBlurYFragment;
        ResPtr<GfxShader> tonemapFragment;
        ResPtr<GfxShader> lumCalcFragment;
        ResPtr<GfxShader> postEffectVertex;
        ResPtr<GfxShader> shadowmapVertex;
        ResPtr<GfxShader> shadowmapFragment;
        GfxCompiledShader *compiledGammaCorrectionFragment;
        GfxCompiledShader *compiledVignetteFragment;
        GfxCompiledShader *compiledFXAAFragment;
        GfxCompiledShader *compiledLightingDirectional;
        GfxCompiledShader *compiledLightingPoint;
        GfxCompiledShader *compiledLightingSpot;
        GfxCompiledShader *compiledLightingSpotShadow;
        GfxCompiledShader *compiledSSAOFragment;
        GfxCompiledShader *compiledSSAOBlurXFragment;
        GfxCompiledShader *compiledSSAOBlurYFragment;
        GfxCompiledShader *compiledBloomBlurXFragment;
        GfxCompiledShader *compiledBloomBlurYFragment;
        GfxCompiledShader *compiledTonemapFragment;
        GfxCompiledShader *compiledLumCalcFragment;
        GfxCompiledShader *compiledPostEffectVertex;
        GfxCompiledShader *compiledShadowmapVertex;
        GfxCompiledShader *compiledShadowmapFragment;
        //float averageLuminance;

        size_t numLights;
        GfxBuffer *lightBuffer;

        void fillLightBuffer(ResPtr<Scene> scene);
        void renderEntities(GfxModel::ContextType contextType);
        void renderSkybox();
        void renderModel(GfxModel::ContextType contextType,
                         const Camera& camera,
                         const Matrix4x4& worldMatrix,
                         const ResPtr<GfxModel> model);
        void renderModelToShadowmap(const Matrix4x4& viewMatrix,
                                    const Matrix4x4& projectionMatrix,
                                    const Matrix4x4& worldMatrix,
                                    const ResPtr<GfxModel> model);
        void renderShadowmap(Light *light);

        ResPtr<GfxTexture> writeColorTexture;
        ResPtr<GfxTexture> readColorTexture;
        ResPtr<GfxTexture> depthTexture;
        ResPtr<GfxTexture> materialTexture;
        ResPtr<GfxTexture> normalTexture;
        ResPtr<GfxTexture> ssaoTexture;
        ResPtr<GfxTexture> ssaoBlurXTexture;
        ResPtr<GfxTexture> bloomBlurXTexture;
        //ResPtr<GfxTexture> luminanceTexture;
        ResPtr<GfxTexture> ssaoRandomTexture;

        GfxFramebuffer *readFramebuffer;
        GfxFramebuffer *writeFramebuffer;
        GfxFramebuffer *gBufferFramebuffer;
        GfxFramebuffer *ssaoFramebuffer;
        GfxFramebuffer *ssaoBlurXFramebuffer;
        GfxFramebuffer *bloomblurXFramebuffer;
        //GfxFramebuffer *luminanceFramebuffer;

        void swapFramebuffers();
};

#endif // GFXRENDERER_H

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
            uint64_t gBufferTimingResolution;
            uint64_t ssaoTimingResolution;
            uint64_t ssaoBlurXTimingResolution;
            uint64_t ssaoBlurYTimingResolution;
            uint64_t deferredShadingTimingResolution;
            uint64_t forwardTimingResolution;
            uint64_t gammaCorrectionTimingResolution;
            uint64_t fxaaTimingResolution;
            uint64_t vignetteTimingResolution;
            uint64_t bloomXTimingResolution;
            uint64_t bloomYTimingResolution;
            uint64_t lumCalcTimingResolution;
            uint64_t tonemappingTimingResolution;

            uint64_t gBufferTiming;
            uint64_t ssaoTiming;
            uint64_t ssaoBlurXTiming;
            uint64_t ssaoBlurYTiming;
            uint64_t deferredShadingTiming;
            uint64_t forwardTiming;
            uint64_t gammaCorrectionTiming;
            uint64_t fxaaTiming;
            uint64_t vignetteTiming;
            uint64_t bloomXTiming;
            uint64_t bloomYTiming;
            uint64_t lumCalcTiming;
            uint64_t tonemappingTiming;
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

        inline float getAverageLuminance() const
        {
            return averageLuminance;
        }

        void updateStats();

        Camera camera;

        bool debugDraw;

        ResPtr<GfxTexture> skybox;

        List<Light> lights;

        float vignetteRadius;
        float vignetteSoftness;
        float vignetteIntensity;
        float bloomThreshold;
        float bloomRadius;
        float bloomQuality;
        bool bloomEnabled;
    private:
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
        GPUTimer *luminanceCalcTimer;
        GPUTimer *tonemappingTimer;

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
        GfxCompiledShader *compiledGammaCorrectionFragment;
        GfxCompiledShader *compiledVignetteFragment;
        GfxCompiledShader *compiledFXAAFragment;
        GfxCompiledShader *compiledLightingDirectional;
        GfxCompiledShader *compiledLightingPoint;
        GfxCompiledShader *compiledLightingSpot;
        GfxCompiledShader *compiledSSAOFragment;
        GfxCompiledShader *compiledSSAOBlurXFragment;
        GfxCompiledShader *compiledSSAOBlurYFragment;
        GfxCompiledShader *compiledBloomBlurXFragment;
        GfxCompiledShader *compiledBloomBlurYFragment;
        GfxCompiledShader *compiledTonemapFragment;
        GfxCompiledShader *compiledLumCalcFragment;
        GfxCompiledShader *compiledPostEffectVertex;
        float averageLuminance;

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
        ResPtr<GfxTexture> bloomBlurXTexture;
        ResPtr<GfxTexture> luminanceTexture;

        GfxFramebuffer *readFramebuffer;
        GfxFramebuffer *writeFramebuffer;
        GfxFramebuffer *gBufferFramebuffer;
        GfxFramebuffer *ssaoFramebuffer;
        GfxFramebuffer *ssaoBlurXFramebuffer;
        GfxFramebuffer *bloomblurXFramebuffer;
        GfxFramebuffer *luminanceFramebuffer;

        void swapFramebuffers();
};

#endif // GFXRENDERER_H

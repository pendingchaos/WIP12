#ifndef GFXRENDERER_H
#define GFXRENDERER_H

#include "math/t2.h"
#include "math/aabb.h"
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
        struct ColorModifier
        {
            enum Type
            {
                ReinhardTonemapping,
                Vignette,
                HueShift,
                SaturationShift,
                BrightnessShift,
                Contrast,
                Multiply,
                HueReplace,
                SaturationReplace,
                BrightnessReplace
            };

            Type type;

            union
            {
                struct
                {
                    bool brightnessOnly;
                } reinhardTonemap;
                struct
                {
                    float radius;
                    float softness;
                    float intensity;
                } vignette;
                struct
                {
                    float hue;
                } hueShift;
                struct
                {
                    float saturation;
                } saturationShift;
                struct
                {
                    float brightness;
                } brightnessShift;
                struct
                {
                    float contrast;
                } contrast;
                struct
                {
                    float red;
                    float green;
                    float blue;
                } multiply;
                struct
                {
                    float hue;
                } hueReplace;
                struct
                {
                    float saturation;
                } saturationReplace;
                struct
                {
                    float brightness;
                } brightnessReplace;
            };

            bool operator == (const ColorModifier& other) const
            {
                if (type != other.type)
                {
                    return false;
                }

                switch (type)
                {
                case ReinhardTonemapping:
                {
                    return reinhardTonemap.brightnessOnly ==
                           other.reinhardTonemap.brightnessOnly;
                }
                case Vignette:
                {
                    return vignette.radius == other.vignette.radius and
                           vignette.softness == other.vignette.softness and
                           vignette.intensity == other.vignette.intensity;
                }
                case HueShift:
                {
                    return hueShift.hue == other.hueShift.hue;
                }
                case SaturationShift:
                {
                    return saturationShift.saturation == other.saturationShift.saturation;
                }
                case BrightnessShift:
                {
                    return brightnessShift.brightness == other.brightnessShift.brightness;
                }
                case Contrast:
                {
                    return contrast.contrast == other.contrast.contrast;
                }
                case Multiply:
                {
                    return multiply.red == other.multiply.red and
                           multiply.green == other.multiply.green and
                           multiply.blue == other.multiply.blue;
                }
                case HueReplace:
                {
                    return hueReplace.hue == other.hueReplace.hue;
                }
                case SaturationReplace:
                {
                    return saturationReplace.saturation == other.saturationReplace.saturation;
                }
                case BrightnessReplace:
                {
                    return brightnessReplace.brightness == other.brightnessReplace.brightness;
                }
                }
            }
        };

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
            float colorModifierTiming;
            float bloomTiming;
            //float lumCalcTiming;
            float shadowmapTiming;
            float overlayTiming;
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

        AABB computeSceneAABB() const;
        AABB computeShadowCasterAABB() const;

        void updateStats();

        Camera camera;

        bool debugDraw;

        float bloomThreshold;
        float bloom1Radius;
        float bloom2Radius;
        float bloom3Radius;
        float bloom4Radius;
        float bloom1Strength;
        float bloom2Strength;
        float bloom3Strength;
        float bloom4Strength;
        bool bloomEnabled;
        float ssaoRadius;
        List<ColorModifier> colorModifiers;

        void updateColorModifierShader();

        inline void setSkybox(ResPtr<GfxTexture> skybox_)
        {
            if (skybox != nullptr)
            {
                skybox->release();
            }

            skybox = skybox_;
        }

        inline ResPtr<GfxTexture> getSkybox() const
        {
            return skybox;
        }
    private:
        ResPtr<GfxTexture> skybox;
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
        GPUTimer *colorModifierTimer;
        GPUTimer *bloomTimer;
        //GPUTimer *luminanceCalcTimer;
        GPUTimer *shadowmapTimer;
        GPUTimer *overlayTimer;

        unsigned int width;
        unsigned int height;

        Scene *scene;

        ResPtr<GfxShader> skyboxVertex;
        ResPtr<GfxShader> skyboxFragment;
        ResPtr<GfxMesh> skyboxMesh;
        ResPtr<GfxMesh> quadMesh;
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
        ResPtr<GfxShader> shadowmapTessControl;
        ResPtr<GfxShader> shadowmapTessEval;
        ResPtr<GfxShader> pointShadowmapGeometry;
        ResPtr<GfxShader> shadowmapFragment;
        ResPtr<GfxShader> pointShadowmapFragment;
        ResPtr<GfxShader> overlayVertex;
        ResPtr<GfxShader> overlayFragment;
        ResPtr<GfxShader> colorModifierFragment;
        ResPtr<GfxShader> gammaCorrectionFragment;
        ResPtr<GfxShader> applyBloomFragment;
        ResPtr<GfxShader> bloomDownsampleFragment;
        ResPtr<GfxShader> hbaoFragment;
        ResPtr<GfxShader> ssaoInterleaveFragment;
        ResPtr<GfxShader> ssaoDeinterleaveFragment;
        ResPtr<GfxShader> ssaoGenerateNormalsFragment;
        GfxCompiledShader *compiledFXAAFragment;
        GfxCompiledShader *compiledLightingDirectional;
        GfxCompiledShader *compiledLightingDirectionalShadow;
        GfxCompiledShader *compiledLightingPoint;
        GfxCompiledShader *compiledLightingPointShadow;
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
        GfxCompiledShader *compiledShadowmapVertexTesselation;
        GfxCompiledShader *compiledShadowmapTessControl;
        GfxCompiledShader *compiledShadowmapTessEval;
        GfxCompiledShader *compiledPointShadowmapGeometry;
        GfxCompiledShader *compiledShadowmapFragment;
        GfxCompiledShader *compiledPointShadowmapFragment;
        GfxCompiledShader *compiledOverlayVertex;
        GfxCompiledShader *compiledOverlayFragment;
        GfxCompiledShader *compiledColorModifier;
        GfxCompiledShader *compiledGammaCorrectionFragment;
        GfxCompiledShader *compiledApplyBloomFragment;
        GfxCompiledShader *compiledBloomDownsampleFragment;
        GfxCompiledShader *compiledHBAOFragment;
        GfxCompiledShader *compiledSSAOInterleaveFragment;
        GfxCompiledShader *compiledSSAODeinterleaveFragment;
        GfxCompiledShader *compiledSSAOGenerateNormalsFragment;
        //float averageLuminance;

        size_t numLights;
        GfxBuffer *lightBuffer;

        void fillLightBuffer(ResPtr<Scene> scene);
        void renderEntities(bool forward);
        void renderSkybox();
        void renderModel(bool forward,
                         const Camera& camera,
                         const Matrix4x4& worldMatrix,
                         const ResPtr<GfxModel> model);
        void renderModelToShadowmap(const Matrix4x4& viewMatrix,
                                    const Matrix4x4& projectionMatrix,
                                    const Matrix4x4& worldMatrix,
                                    const ResPtr<GfxModel> model,
                                    Light *light,
                                    size_t cubemapFace);
        void renderShadowmap(Light *light);

        ResPtr<GfxTexture> writeColorTexture;
        ResPtr<GfxTexture> readColorTexture;
        ResPtr<GfxTexture> depthTexture;
        ResPtr<GfxTexture> materialTexture;
        ResPtr<GfxTexture> normalTexture;
        ResPtr<GfxTexture> ssaoTexture;
        ResPtr<GfxTexture> ssaoBlurXTexture;
        ResPtr<GfxTexture> bloomBlurXTexture;
        ResPtr<GfxTexture> ssaoRandomTexture;
        ResPtr<GfxTexture> bloom1Texture;
        ResPtr<GfxTexture> bloom2Texture;
        ResPtr<GfxTexture> bloom3Texture;
        ResPtr<GfxTexture> bloom4Texture;
        ResPtr<GfxTexture> bloomDownsampleTexture;
        ResPtr<GfxTexture> hbaoRandomTexture;
        ResPtr<GfxTexture> deinterleavedDepthTexture;
        ResPtr<GfxTexture> ssaoNormalTexture;
        ResPtr<GfxTexture> deinterleavedSSAOTexture;
        //ResPtr<GfxTexture> luminanceTexture;

        GfxFramebuffer *readFramebuffer;
        GfxFramebuffer *writeFramebuffer;
        GfxFramebuffer *gBufferFramebuffer;
        GfxFramebuffer *ssaoFramebuffer;
        GfxFramebuffer *ssaoBlurXFramebuffer;
        GfxFramebuffer *bloomblurXFramebuffer;
        GfxFramebuffer *bloom1Framebuffer;
        GfxFramebuffer *bloom2Framebuffer;
        GfxFramebuffer *bloom3Framebuffer;
        GfxFramebuffer *bloom4Framebuffer;
        GfxFramebuffer *bloomDownsampleFramebuffer;
        GfxFramebuffer *ssaoDeinterleavedFramebuffer;
        GfxFramebuffer *ssaoDepthDeinterleaveFramebuffer;
        GfxFramebuffer *ssaoNormalsFramebuffer;
        //GfxFramebuffer *luminanceFramebuffer;

        void swapFramebuffers();
};

#endif // GFXRENDERER_H

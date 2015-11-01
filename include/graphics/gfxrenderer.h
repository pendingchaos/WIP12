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
#include "scripting/bindings.h"
#include "graphics/renderlist.h"

#include <mutex>

class Matrix4x4;
class Str;
class GfxFramebuffer;
class GPUTimer;
class GfxTerrain;
class GfxShaderCombination;

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
    float shadowmapTiming;
    float overlayTiming;
    float debugDrawTiming;

    float shadowmapCPUTiming;
    float gbufferCPUTiming;
    float forwardCPUTiming;
    float overlayCPUTiming;
    float batchingCPUTiming;
    float animationCPUTiming;
    float deferredShadingCPUTiming;
    float updateStatsCPUTiming;
    float miscPostEffectsCPUTiming;
    size_t numDrawCalls;
} BIND;

class GfxRenderer
{
    NO_COPY(GfxRenderer);

    private:
        friend class Scene;

        GfxRenderer(Scene *scene);
    public:
        struct ColorModifier
        {
            enum Type
            {
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
        };

        ~GfxRenderer();

        void resize(const UInt2& size);
        void render();

        size_t getNumLights() const
        {
            return numLights;
        }

        GfxBuffer *getLightBuffer() const
        {
            return lightBuffer;
        }

        RenderStats getStats() const
        {
            return stats;
        }

        Light *addLight()
        {
            Light *light = NEW(Light);

            lights.append(light);

            return light;
        }

        void removeLight(size_t index)
        {
            DELETE(lights[index]);

            lights.remove(index);
        }

        const List<Light *>& getLights() const
        {
            return lights;
        }

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
        NO_BIND List<ColorModifier> colorModifiers;

        void updateColorModifierShader();

        void setSkybox(GfxTexture *skybox_)
        {
            if (skybox != nullptr)
            {
                skybox->release();
            }

            skybox = skybox_;
        }

        GfxTexture *getSkybox() const
        {
            return skybox;
        }

        GfxTerrain *addTerrain(float chunkSize,
                               size_t sizeInChunks,
                               GfxTexture *heightmap) NO_BIND;
        void removeTerrain();

        GfxTerrain *getTerrain() const NO_BIND
        {
            return terrain;
        }

        RenderList *getForwardList() const
        {
            return forwardList;
        }

        RenderList *getDeferredList() const
        {
            return deferredList;
        }

        RenderList *getShadowmapList() const
        {
            return shadowmapList;
        }

        AABB getSceneAABB() const
        {
            return sceneAABB;
        }

        AABB getShadowCasterAABB() const
        {
            return shadowCasterAABB;
        }

        void computeSceneAABB();
        void computeShadowCasterAABB();
    private:
        GfxTexture *skybox;
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
        GPUTimer *shadowmapTimer;
        GPUTimer *overlayTimer;
        GPUTimer *debugDrawTimer;

        unsigned int width;
        unsigned int height;

        Scene *scene;

        GfxShaderCombination *skyboxShaders;
        GfxMesh *skyboxMesh;
        GfxMesh *quadMesh;
        GfxShaderCombination *fxaa;
        GfxShaderCombination *lightingDirectional;
        GfxShaderCombination *lightingDirectionalShadow;
        GfxShaderCombination *lightingPoint;
        GfxShaderCombination *lightingPointShadow;
        GfxShaderCombination *lightingSpot;
        GfxShaderCombination *lightingSpotShadow;
        GfxShaderCombination *ssao;
        GfxShaderCombination *ssaoBlurX;
        GfxShaderCombination *ssaoBlurY;
        GfxShaderCombination *bloomBlurX;
        GfxShaderCombination *bloomBlurY;
        GfxShaderCombination *tonemap;
        GfxShaderCombination *gammaCorrection;
        GfxShaderCombination *applyBloom;
        GfxShaderCombination *bloomDownsample;
        GfxShaderCombination *overlayShaders;
        GfxShaderCombination *colorModify;
        GfxShader *colorModifierFragment;
        GfxShader *shadowmapVertex;
        GfxShader *pointShadowmapGeometry;
        GfxShader *shadowmapFragment;
        GfxShader *pointShadowmapFragment;
        GfxShader *overlayVertex;
        GfxShader *overlayFragment;
        GfxShader *terrainVertex;
        GfxShader *terrainTessControl;
        GfxShader *terrainTessEval;
        GfxShader *terrainFragment;

        GfxCompiledShader *compiledShadowmapVertex;
        GfxCompiledShader *compiledShadowmapVertexAnimated;
        GfxCompiledShader *compiledPointShadowmapGeometry;
        GfxCompiledShader *compiledShadowmapFragment;
        GfxCompiledShader *compiledPointShadowmapFragment;
        GfxCompiledShader *compiledColorModifier;
        GfxCompiledShader *compiledTerrainVertex;
        GfxCompiledShader *compiledTerrainTessControl;
        GfxCompiledShader *compiledTerrainTessEval;
        GfxCompiledShader *compiledTerrainFragment;

        size_t numLights;
        GfxBuffer *lightBuffer;
        size_t numPointLights;
        size_t numDirectionalLights;
        size_t numSpotLights;

        GfxMaterial *shadowmapMaterial;

        GfxTerrain *terrain;

        void fillLightBuffer(Scene *scene);
        void renderSkybox();
        void renderShadowmap(Light *light);
        void renderTerrain();
        void renderTerrainToShadowmap(const Matrix4x4& projectionMatrix,
                                      const Matrix4x4& viewMatrix,
                                      float autoBiasScale);

        GfxTexture *writeColorTexture;
        GfxTexture *readColorTexture;
        GfxTexture *depthTexture;
        GfxTexture *materialTexture;
        GfxTexture *normalTexture;
        GfxTexture *ssaoTexture;
        GfxTexture *ssaoBlurXTexture;
        GfxTexture *bloomBlurXTexture;
        GfxTexture *ssaoRandomTexture;
        GfxTexture *bloom1Texture;
        GfxTexture *bloom2Texture;
        GfxTexture *bloom3Texture;
        GfxTexture *bloom4Texture;
        GfxTexture *bloomDownsampleTexture;
        GfxTexture *geomNormalTexture;

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

        RenderList *forwardList;
        RenderList *deferredList;
        RenderList *shadowmapList;

        void fillRenderLists();

        void swapFramebuffers();

        struct Object
        {
            bool shadowCaster;
            GfxMaterial *material;
            GfxMesh *mesh;
            GfxAnimationState *animState;
            Matrix4x4 worldMatrix;
            Matrix4x4 normalMatrix;
        };

        List<Object> objects;

        void fillObjects(const List<Entity *>& entities);

        static void fillRenderListsJob(size_t index, size_t worker, void *userdata);
        struct FillRenderListsData
        {
            GfxRenderer *renderer;
            RenderList *shadowmapLists;
            RenderList *forwardLists;
            RenderList *deferredLists;
            Object *objects;
        };

        AABB sceneAABB;
        AABB shadowCasterAABB;
} BIND NOT_COPYABLE;

#endif // GFXRENDERER_H

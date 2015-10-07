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

class Matrix4x4;
class String;
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
            DELETE(lights[index]);

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
        NO_BIND List<ColorModifier> colorModifiers;

        void updateColorModifierShader();

        inline void setSkybox(GfxTexture *skybox_)
        {
            if (skybox != nullptr)
            {
                skybox->release();
            }

            skybox = skybox_;
        }

        inline GfxTexture *getSkybox() const
        {
            return skybox;
        }

        GfxTerrain *addTerrain(float chunkSize,
                               size_t sizeInChunks,
                               GfxTexture *heightmap) NO_BIND;
        void removeTerrain();

        inline GfxTerrain *getTerrain() const NO_BIND
        {
            return terrain;
        }
    private:
        void _computeSceneAABB(const List<Entity *>& entities, AABB& aabb) const;
        void _computeShadowCasterAABB(const List<Entity *>& entities, AABB& aabb) const;

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
        GfxShader *shadowmapTessControl;
        GfxShader *shadowmapTessEval;
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
        GfxCompiledShader *compiledShadowmapVertexTesselation;
        GfxCompiledShader *compiledShadowmapVertexAnimated;
        GfxCompiledShader *compiledShadowmapVertexTesselationAnimated;
        GfxCompiledShader *compiledShadowmapTessControl;
        GfxCompiledShader *compiledShadowmapTessEval;
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

        GfxTerrain *terrain;

        void fillLightBuffer(Scene *scene);
        void batchEntities(const List<Entity *>& entities);
        void batchModel(const Matrix4x4& worldMatrix,
                        const GfxModel *model,
                        GfxMesh *animMesh,
                        GfxAnimationState *animState);
        void renderBatches(bool forward);
        void renderSkybox();
        void renderBatchesToShadowmap(const Matrix4x4& viewMatrix,
                                      const Matrix4x4& projectionMatrix,
                                      Light *light,
                                      size_t cubemapFace);
        void renderShadowmap(Light *light);
        void renderTerrain();
        void renderTerrainToShadowmap(const Matrix4x4& projectionMatrix,
                                      const Matrix4x4& viewMatrix,
                                      float autoBiasScale);

        void fillMatrixTexture(const List<Matrix4x4>& matrices);

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

        struct Batch
        {
            GfxMesh *mesh;
            GfxMaterial *material;
            List<Matrix4x4> worldMatrices;
            GfxAnimationState *animState;
        };

        List<Batch> batches;
        GfxTexture *matrixTexture;
        //GfxBuffer *instanceBuffer;

        void swapFramebuffers();
} BIND;

#endif // GFXRENDERER_H

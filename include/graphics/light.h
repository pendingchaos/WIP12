#ifndef LIGHT_H
#define LIGHT_H

#include "math/t3.h"
#include "math/t4.h"
#include "math/matrix4x4.h"
#include "graphics/gfxtexture.h"
#include "graphics/gfxframebuffer.h"
#include "misc_macros.h"

class GfxRenderer;

class Light
{
    NO_COPY(Light)

    public:
        enum Type
        {
            Directional,
            Spot,
            Point
        };

        enum ShadowmapPrecision
        {
            Low,
            Medium,
            High
        };

        Light() : type(Directional),
                  power(1.0f),
                  color(1.0f),
                  ambientStrength(0.05f),
                  shadowmapNear(0.1f),
                  shadowmapFar(100.0f),
                  shadowMinBias(0.005f),
                  shadowBiasScale(0.05f),
                  shadowAutoBiasScale(1.0f),
                  direction({Direction3D(0.0f, -1.0f, 0.0f)}),
                  shadowmap(nullptr),
                  shadowmapFramebuffer(nullptr) {point.singlePassShadowMap = true;}
        ~Light() {removeShadowmap();}

        Type type;
        float power;
        Float3 color;
        float ambientStrength;
        float shadowmapNear;
        float shadowmapFar;
        float shadowMinBias;
        float shadowBiasScale;
        float shadowAutoBiasScale;

        struct
        {
            Direction3D direction;
        } direction;

        struct
        {
            Position3D position;
            Direction3D direction;
            float innerCutoff;
            float outerCutoff;
            float radius;
        } spot;

        struct
        {
            Position3D position;
            float radius;
            bool singlePassShadowMap;
        } point;

        void addShadowmap(size_t resolution, ShadowmapPrecision quality);

        inline void removeShadowmap()
        {
            if (shadowmap != nullptr)
            {
                DELETE(GfxFramebuffer, shadowmapFramebuffer);
                shadowmapFramebuffer = nullptr;
                shadowmap = nullptr;

                if (type == Point)
                {
                    DELETE(GfxFramebuffer, pointLightFramebuffers[0]);
                    DELETE(GfxFramebuffer, pointLightFramebuffers[1]);
                    DELETE(GfxFramebuffer, pointLightFramebuffers[2]);
                    DELETE(GfxFramebuffer, pointLightFramebuffers[3]);
                    DELETE(GfxFramebuffer, pointLightFramebuffers[4]);
                    DELETE(GfxFramebuffer, pointLightFramebuffers[5]);
                    pointLightFramebuffers[0] = nullptr;
                    pointLightFramebuffers[1] = nullptr;
                    pointLightFramebuffers[2] = nullptr;
                    pointLightFramebuffers[3] = nullptr;
                    pointLightFramebuffers[4] = nullptr;
                    pointLightFramebuffers[5] = nullptr;
                }
            }
        }

        inline ResPtr<GfxTexture> getShadowmap() const
        {
            return shadowmap;
        }

        inline GfxFramebuffer *getShadowmapFramebuffer() const
        {
            return shadowmapFramebuffer;
        }

        inline GfxFramebuffer *const *getPointLightFramebuffers() const
        {
            return pointLightFramebuffers;
        }

        inline size_t getShadowmapResolution() const
        {
            return shadowmapResolution;
        }

        inline ShadowmapPrecision getShadowmapPrecision() const
        {
            return shadowmapPrecision;
        }

        void updateMatrices(GfxRenderer *renderer);

        //These two functions only work with spot and directional lights.
        inline Matrix4x4 getViewMatrix() const
        {
            return viewMatrix;
        }

        inline Matrix4x4 getProjectionMatrix() const
        {
            return projectionMatrix;
        }
    private:
        ResPtr<GfxTexture> shadowmap;
        GfxFramebuffer *shadowmapFramebuffer;
        GfxFramebuffer *pointLightFramebuffers[6];
        size_t shadowmapResolution;
        ShadowmapPrecision shadowmapPrecision;

        Matrix4x4 viewMatrix;
        Matrix4x4 projectionMatrix;
};

#endif // LIGHT_H

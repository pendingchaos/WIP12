#ifndef LIGHT_H
#define LIGHT_H

#include "math/t3.h"
#include "math/t4.h"
#include "math/matrix4x4.h"
#include "graphics/gfxtexture.h"
#include "graphics/gfxframebuffer.h"
#include "misc_macros.h"

class GfxRenderer;

struct LightDirectionalData
{
    Direction3D direction;
} BIND;

struct LightSpotData
{
    Position3D position;
    Direction3D direction;
    float innerCutoff;
    float outerCutoff;
    float radius;
} BIND;

struct LightPointData
{
    Position3D position;
    float radius;
    bool singlePassShadowMap;
} BIND;

enum class GfxShadowmapPrecision
{
    Low,
    Medium,
    High
} BIND ENUM_CLASS;

enum class GfxLightType
{
    Directional,
    Spot,
    Point
} BIND ENUM_CLASS;

class Light
{
    NO_COPY(Light)

    public:
        Light() : type(GfxLightType::Directional),
                  power(1.0f),
                  color(1.0f),
                  ambientStrength(0.05f),
                  shadowmapNear(0.1f),
                  shadowmapFar(100.0f),
                  shadowMinBias(0.005f),
                  shadowBiasScale(0.05f),
                  shadowAutoBiasScale(1.0f),
                  shadowFixedBias(0.0f),
                  shadowRadius(4.0f),
                  scriptOwned(false),
                  direction({Direction3D(0.0f, -1.0f, 0.0f)}),
                  shadowmap(nullptr),
                  shadowmapFramebuffer(nullptr) {point.singlePassShadowMap = true;}
        ~Light() {removeShadowmap();}

        GfxLightType type;
        float power;
        Float3 color;
        float ambientStrength;
        float shadowmapNear;
        float shadowmapFar;
        float shadowMinBias;
        float shadowBiasScale;
        float shadowAutoBiasScale;
        float shadowFixedBias;
        float shadowRadius;
        bool scriptOwned;

        LightDirectionalData direction;
        LightSpotData spot;
        LightPointData point;

        void addShadowmap(size_t resolution, GfxShadowmapPrecision quality);

        inline void removeShadowmap()
        {
            if (shadowmap != nullptr)
            {
                DELETE(shadowmapFramebuffer);
                shadowmapFramebuffer = nullptr;
                shadowmap->release();
                shadowmap = nullptr;

                if (type == GfxLightType::Point)
                {
                    DELETE(pointLightFramebuffers[0]);
                    DELETE(pointLightFramebuffers[1]);
                    DELETE(pointLightFramebuffers[2]);
                    DELETE(pointLightFramebuffers[3]);
                    DELETE(pointLightFramebuffers[4]);
                    DELETE(pointLightFramebuffers[5]);
                    pointLightFramebuffers[0] = nullptr;
                    pointLightFramebuffers[1] = nullptr;
                    pointLightFramebuffers[2] = nullptr;
                    pointLightFramebuffers[3] = nullptr;
                    pointLightFramebuffers[4] = nullptr;
                    pointLightFramebuffers[5] = nullptr;
                }
            }
        }

        inline GfxTexture *getShadowmap() const
        {
            return shadowmap;
        }

        inline GfxFramebuffer *getShadowmapFramebuffer() const
        {
            return shadowmapFramebuffer;
        }

        inline GfxFramebuffer *const *getPointLightFramebuffers() const NO_BIND
        {
            return pointLightFramebuffers;
        }

        GfxFramebuffer *getPointLightFramebuffer(GfxFace face) const
        {
            if ((int)face > 5)
            {
                THROW(BoundsException);
            }

            return pointLightFramebuffers[(int)face];
        }

        inline size_t getShadowmapResolution() const
        {
            return shadowmapResolution;
        }

        inline GfxShadowmapPrecision getShadowmapPrecision() const
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
        GfxTexture *shadowmap;
        GfxFramebuffer *shadowmapFramebuffer;
        GfxFramebuffer *pointLightFramebuffers[6];
        size_t shadowmapResolution;
        GfxShadowmapPrecision shadowmapPrecision;

        Matrix4x4 viewMatrix;
        Matrix4x4 projectionMatrix;
} BIND NOT_COPYABLE;

#endif // LIGHT_H

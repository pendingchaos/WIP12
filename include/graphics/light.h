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
                  shadowMinBias(0.005f),
                  shadowBiasScale(0.05f),
                  shadowAutoBiasScale(1.0f),
                  shadowFixedBias(0.0f),
                  shadowRadius(4.0f),
                  scriptOwned(false),
                  shadowSplitDistances(3.0f, 6.0f, 9.0f),
                  direction({Direction3D(0.0f, -1.0f, 0.0f)}),
                  shadowmap(nullptr) {point.singlePassShadowMap = true;}
        ~Light() {removeShadowmap();}

        GfxLightType type;
        float power;
        Float3 color;
        float ambientStrength;
        float shadowmapNear;
        float shadowMinBias;
        float shadowBiasScale;
        float shadowAutoBiasScale;
        float shadowFixedBias;
        float shadowRadius;
        bool scriptOwned; //TODO: Get rid of this.
        Float3 shadowSplitDistances;

        LightDirectionalData direction;
        LightSpotData spot;
        LightPointData point;

        void addShadowmap(size_t resolution, GfxShadowmapPrecision quality);
        void removeShadowmap();

        inline GfxTexture *getShadowmap() const
        {
            return shadowmap;
        }

        inline GfxFramebuffer *const *getFramebuffers() const NO_BIND
        {
            return shadowmapFramebuffers;
        }

        inline size_t getShadowmapResolution() const
        {
            return shadowmapResolution;
        }

        inline GfxShadowmapPrecision getShadowmapPrecision() const
        {
            return shadowmapPrecision;
        }

        float getPointLightInfluence(float cutoff=0.039) const;
        float getSpotLightInfluence(float cutoff=0.039) const;

        void updateMatrices(GfxRenderer *renderer);

        //These two functions only work with directional lights.
        inline Matrix4x4 getViewMatrix() const
        {
            return viewMatrices[0];
        }

        inline Matrix4x4 getProjectionMatrix() const
        {
            return projectionMatrices[0];
        }

        //These two methods only work with directional lights
        inline Matrix4x4 getCascadeViewMatrix(size_t index) const
        {
            return viewMatrices[index];
        }

        inline Matrix4x4 getCascadeProjectionMatrix(size_t index) const
        {
            return projectionMatrices[index];
        }
    private:
        GfxTexture *shadowmap;
        GfxFramebuffer *shadowmapFramebuffers[6];
        size_t shadowmapResolution;
        GfxShadowmapPrecision shadowmapPrecision;

        Matrix4x4 viewMatrices[4];
        Matrix4x4 projectionMatrices[4];
} BIND NOT_COPYABLE;

#endif // LIGHT_H

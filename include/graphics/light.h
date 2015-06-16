#ifndef LIGHT_H
#define LIGHT_H

#include "math/t3.h"
#include "math/t4.h"
#include "math/matrix4x4.h"
#include "graphics/gfxtexture.h"
#include "graphics/gfxframebuffer.h"
#include "misc_macros.h"

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

        enum ShadowmapQuality
        {
            Low,
            Medium,
            High
        };

        Light() : type(Directional),
                  power(1.0f),
                  color(1.0f),
                  shadowmapNear(0.1f),
                  shadowmapFar(100.0f),
                  shadowMinBias(0.005f),
                  shadowBiasScale(0.05f),
                  direction({Direction3D(0.0f, -1.0f, 0.0f)}),
                  shadowmap(nullptr),
                  shadowmapFramebuffer(nullptr) {}

        Type type;
        float power;
        Float3 color;
        float shadowmapNear;
        float shadowmapFar;
        float shadowMinBias;
        float shadowBiasScale;

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
        } point;

        void addShadowmap(size_t resolution, ShadowmapQuality quality);

        inline void removeShadowmap()
        {
            DELETE(GfxFramebuffer, shadowmapFramebuffer);
            shadowmap = nullptr;
        }

        inline ResPtr<GfxTexture> getShadowmap() const
        {
            return shadowmap;
        }

        inline GfxFramebuffer *getShadowmapFramebuffer() const
        {
            return shadowmapFramebuffer;
        }

        inline size_t getShadowmapResolution() const
        {
            return shadowmapResolution;
        }

        inline ShadowmapQuality getShadowmapQuality() const
        {
            return shadowmapQuality;
        }

        Matrix4x4 getViewMatrix() const;
        Matrix4x4 getProjectionMatrix() const;
    private:
        ResPtr<GfxTexture> shadowmap;
        GfxFramebuffer *shadowmapFramebuffer;
        size_t shadowmapResolution;
        ShadowmapQuality shadowmapQuality;
};

#endif // LIGHT_H

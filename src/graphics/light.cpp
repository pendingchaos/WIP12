#include "graphics/light.h"

#include "graphics/gfxapi.h"
#include "globals.h"

#include <algorithm>

void Light::addShadowmap(size_t resolution, ShadowmapQuality quality)
{
    removeShadowmap();

    static const GfxTexture::Format formats[] = {GfxTexture::DepthF32_F16,
                                                 GfxTexture::DepthF32_F24,
                                                 GfxTexture::DepthF32};

    if (type == Spot)
    {
        shadowmap = NEW(GfxTexture, "");

        shadowmap->startCreation(GfxTexture::Texture2D,
                                 false,
                                 resolution,
                                 resolution,
                                 0,
                                 GfxTexture::Other,
                                 formats[(int)quality]);
        shadowmap->allocMipmap(0, 1, NULL);
        shadowmap->setShadowmap(true);

        shadowmapFramebuffer = gfxApi->createFramebuffer();
        shadowmapFramebuffer->setDepthAttachment(shadowmap);

        shadowmapResolution = resolution;
        shadowmapQuality = quality;
    }
}

Matrix4x4 Light::getViewMatrix() const
{
    switch (type)
    {
    case Spot:
    {
        Direction3D dir = spot.direction.normalize();

        Direction3D up(0.0f, 1.0f, 0.0f);

        if (std::abs(up.dot(dir)) >= 1.0f)
        {
            up = Direction3D(0.0f, 0.0f, 1.0f);
        }

        Direction3D left = dir.cross(up).normalize();
        up = dir.cross(left).normalize();

        return Matrix4x4::lookAt(spot.position,
                                 spot.position + spot.direction,
                                 up);
    }
    default:
    {
        return Matrix4x4();
    }
    }
}

Matrix4x4 Light::getProjectionMatrix() const
{
    switch (type)
    {
    case Spot:
    {
        return Matrix4x4::perspective(std::min(spot.outerCutoff * 1.2f, 175.0f),
                                      1.0f,
                                      shadowmapNear,
                                      shadowmapFar);
    }
    default:
    {
        return Matrix4x4();
    }
    }

    return Matrix4x4();
}

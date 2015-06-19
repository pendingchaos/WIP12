#include "graphics/light.h"

#include "graphics/gfxapi.h"
#include "graphics/gfxrenderer.h"
#include "globals.h"

#include <algorithm>
#include <cmath>

void Light::addShadowmap(size_t resolution, ShadowmapQuality quality)
{
    removeShadowmap();

    static const GfxTexture::Format formats[] = {GfxTexture::DepthF32_F16,
                                                 GfxTexture::DepthF32_F24,
                                                 GfxTexture::DepthF32};

    if (type == Spot or type == Directional)
    {
        shadowmap = NEW(GfxTexture);

        shadowmap->startCreation(GfxTexture::Texture2D,
                                 false,
                                 resolution,
                                 resolution,
                                 1,
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

void Light::updateMatrices(GfxRenderer *renderer)
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

        viewMatrix = Matrix4x4::lookAt(spot.position,
                                       spot.position + spot.direction,
                                       up);

        projectionMatrix = Matrix4x4::perspective(std::min(spot.outerCutoff * 1.2f, 175.0f),
                                                  1.0f,
                                                  shadowmapNear,
                                                  shadowmapFar);
        break;
    }
    case Directional:
    {
        //Based on the algorithm from 0 A.D.

        //View
        Matrix4x4 cameraView = renderer->camera.getViewMatrix();

        Float3 z = direction.direction.normalize();
        Float3 y;
        Float3 x = Float3(cameraView[0][2], cameraView[1][2], cameraView[2][2]);

        Float3 eyePos = Float3(cameraView[0][3], cameraView[1][3], cameraView[2][3]);

        x -= z * z.dot(x);

        if (x.length() < 0.001f)
        {
            x = Float3(1.0f, 0.0f, 0.0f);
            x -= z * z.dot(x);
        }

        x = x.normalize();
        y = z.cross(x);

        viewMatrix = Matrix4x4();

        viewMatrix[0][0] = x.x;
        viewMatrix[0][1] = x.y;
        viewMatrix[0][2] = x.z;

        viewMatrix[1][0] = y.x;
        viewMatrix[1][1] = y.y;
        viewMatrix[1][2] = y.z;

        viewMatrix[2][0] = z.x;
        viewMatrix[2][1] = z.y;
        viewMatrix[2][2] = z.z;

        viewMatrix[0][3] = -x.dot(eyePos);
        viewMatrix[1][3] = -y.dot(eyePos);
        viewMatrix[2][3] = -z.dot(eyePos);

        //Projection
        AABB casterBounds = renderer->computeShadowCasterAABB().transform(viewMatrix);
        AABB sceneBounds = renderer->computeSceneAABB().transform(viewMatrix);

        sceneBounds.min.z = casterBounds.min.z - 2.0f;
        sceneBounds.max.z = casterBounds.max.z + 2.0f;

        Float3 scale = sceneBounds.max - sceneBounds.min;
        Float3 shift = (sceneBounds.max + sceneBounds.min) * -0.5;

        scale.x = std::max(scale.x, 1.0f);
        scale.y = std::max(scale.y, 1.0f);
        scale.z = std::max(scale.z, 1.0f);

        scale = Float3(2.0f) / scale;

        Float2 offset(std::fmod(sceneBounds.min.x - viewMatrix[0][3], 2.0f / (scale.x * shadowmap->getBaseWidth())),
                      std::fmod(sceneBounds.min.y - viewMatrix[1][3], 2.0f / (scale.y * shadowmap->getBaseHeight())));

        projectionMatrix = Matrix4x4();
        projectionMatrix[0][0] = scale.x;
        projectionMatrix[0][3] = (shift.x + offset.x) * scale.x;
        projectionMatrix[1][1] = scale.y;
        projectionMatrix[1][3] = (shift.y + offset.y) * scale.y;
        projectionMatrix[2][2] = scale.z;
        projectionMatrix[2][3] = shift.z * scale.z;
        break;
    }
    default:
    {
        break;
    }
    }
}

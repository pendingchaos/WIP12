#include "graphics/light.h"

#include "graphics/gfxapi.h"
#include "graphics/gfxrenderer.h"
#include "globals.h"

#include <algorithm>
#include <cmath>

void Light::addShadowmap(size_t resolution, GfxShadowmapPrecision precision)
{
    removeShadowmap();

    static const GfxTexFormat formats[] = {GfxTexFormat::DepthF32_F16,
                                           GfxTexFormat::DepthF32_F24,
                                           GfxTexFormat::DepthF32};

    shadowmap = NEW(GfxTexture);

    if (type == GfxLightType::Spot or type == GfxLightType::Directional)
    {
        shadowmap->startCreation(GfxTextureType::Texture2D,
                                 false,
                                 resolution,
                                 resolution,
                                 1,
                                 0,
                                 GfxTexPurpose::Other,
                                 formats[(int)precision]);

        shadowmap->allocMipmap(0, 1, nullptr);
    } else
    {
        shadowmap->startCreation(GfxTextureType::CubeMap,
                                 false,
                                 resolution,
                                 resolution,
                                 1,
                                 0,
                                 GfxTexPurpose::Other,
                                 formats[(int)precision]);

        shadowmap->allocMipmapFace(0, 1, GfxFace::PositiveX, nullptr);
        shadowmap->allocMipmapFace(0, 1, GfxFace::NegativeX, nullptr);
        shadowmap->allocMipmapFace(0, 1, GfxFace::PositiveY, nullptr);
        shadowmap->allocMipmapFace(0, 1, GfxFace::NegativeY, nullptr);
        shadowmap->allocMipmapFace(0, 1, GfxFace::PositiveZ, nullptr);
        shadowmap->allocMipmapFace(0, 1, GfxFace::NegativeZ, nullptr);

        pointLightFramebuffers[0] = gfxApi->createFramebuffer();
        pointLightFramebuffers[1] = gfxApi->createFramebuffer();
        pointLightFramebuffers[2] = gfxApi->createFramebuffer();
        pointLightFramebuffers[3] = gfxApi->createFramebuffer();
        pointLightFramebuffers[4] = gfxApi->createFramebuffer();
        pointLightFramebuffers[5] = gfxApi->createFramebuffer();

        pointLightFramebuffers[0]->setDepthAttachment(shadowmap, 0, 0);
        pointLightFramebuffers[1]->setDepthAttachment(shadowmap, 0, 1);
        pointLightFramebuffers[2]->setDepthAttachment(shadowmap, 0, 2);
        pointLightFramebuffers[3]->setDepthAttachment(shadowmap, 0, 3);
        pointLightFramebuffers[4]->setDepthAttachment(shadowmap, 0, 4);
        pointLightFramebuffers[5]->setDepthAttachment(shadowmap, 0, 5);
    }

    shadowmap->setShadowmap(true);

    shadowmapFramebuffer = gfxApi->createFramebuffer();
    shadowmapFramebuffer->setDepthAttachment(shadowmap);

    shadowmapResolution = resolution;
    shadowmapPrecision = precision;
}

void Light::updateMatrices(GfxRenderer *renderer)
{
    switch (type)
    {
    case GfxLightType::Spot:
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

        //TODO: Automatic calculation of near and far.
        projectionMatrix = Matrix4x4::perspective(std::min(spot.outerCutoff * 1.2f, 175.0f),
                                                  1.0f,
                                                  shadowmapNear,
                                                  shadowmapFar);
        break;
    }
    case GfxLightType::Directional:
    {
        //This creates a projection matrix where the top and bottom is too high if line 110 is set to Float3(0.0f).
        /*Direction3D dir = direction.direction.normalize();

        Direction3D up(0.0f, 1.0f, 0.0f);

        if (std::abs(up.dot(dir)) >= 1.0f)
        {
            up = Direction3D(0.0f, 0.0f, 1.0f);
        }

        Direction3D left = dir.cross(up).normalize();
        up = dir.cross(left).normalize();

        viewMatrix = Matrix4x4::lookAtDir(Position3D(0.0f),
                                          dir,
                                          up);

        AABB casterBounds = renderer->computeShadowCasterAABB().transform(viewMatrix);

        Float3 shift = -(casterBounds.max + casterBounds.min);

        projectionMatrix = Matrix4x4::orthographic(casterBounds.min.x + shift.x,
                                                   casterBounds.max.x + shift.x,
                                                   casterBounds.min.y + shift.y,
                                                   casterBounds.max.y + shift.y,
                                                   casterBounds.min.z,
                                                   casterBounds.max.z);*/

        //Based on the algorithm from 0 A.D.

        //View
        Float3 z = direction.direction.normalize();
        Float3 y;
        Float3 x = Float3(0.0f);

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
    case GfxLightType::Point:
    {
        projectionMatrix = Matrix4x4::perspective(RADIANS(90.0f),
                                                  1.0f,
                                                  shadowmapNear,
                                                  shadowmapFar);
        break;
    }
    }
}

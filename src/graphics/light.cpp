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

    if (type == GfxLightType::Spot)
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

        shadowmapFramebuffers[0] = gfxApi->createFramebuffer();
        shadowmapFramebuffers[0]->setDepthAttachment(shadowmap);
    } else if (type == GfxLightType::Directional)
    {
        shadowmap->startCreation(GfxTextureType::Texture2DArray,
                                 false,
                                 resolution,
                                 resolution,
                                 4,
                                 0,
                                 GfxTexPurpose::Other,
                                 formats[(int)precision]);

        shadowmap->allocMipmap(0, 1, nullptr);

        shadowmapFramebuffers[0] = gfxApi->createFramebuffer();
        shadowmapFramebuffers[1] = gfxApi->createFramebuffer();
        shadowmapFramebuffers[2] = gfxApi->createFramebuffer();
        shadowmapFramebuffers[3] = gfxApi->createFramebuffer();

        shadowmapFramebuffers[0]->setDepthAttachment(shadowmap, 0, 0);
        shadowmapFramebuffers[1]->setDepthAttachment(shadowmap, 0, 1);
        shadowmapFramebuffers[2]->setDepthAttachment(shadowmap, 0, 2);
        shadowmapFramebuffers[3]->setDepthAttachment(shadowmap, 0, 3);
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

        shadowmapFramebuffers[0] = gfxApi->createFramebuffer();
        shadowmapFramebuffers[1] = gfxApi->createFramebuffer();
        shadowmapFramebuffers[2] = gfxApi->createFramebuffer();
        shadowmapFramebuffers[3] = gfxApi->createFramebuffer();
        shadowmapFramebuffers[4] = gfxApi->createFramebuffer();
        shadowmapFramebuffers[5] = gfxApi->createFramebuffer();

        shadowmapFramebuffers[0]->setDepthAttachment(shadowmap, 0, 0);
        shadowmapFramebuffers[1]->setDepthAttachment(shadowmap, 0, 1);
        shadowmapFramebuffers[2]->setDepthAttachment(shadowmap, 0, 2);
        shadowmapFramebuffers[3]->setDepthAttachment(shadowmap, 0, 3);
        shadowmapFramebuffers[4]->setDepthAttachment(shadowmap, 0, 4);
        shadowmapFramebuffers[5]->setDepthAttachment(shadowmap, 0, 5);
    }

    shadowmap->setMinFilter(GfxFilter::Nearest);
    shadowmap->setMagFilter(GfxFilter::Nearest);
    shadowmap->setWrapMode(GfxWrapMode::Stretch);

    shadowmapResolution = resolution;
    shadowmapPrecision = precision;
}

void Light::removeShadowmap()
{
    if (shadowmap != nullptr)
    {
        shadowmap->release();
        shadowmap = nullptr;

        if (type == GfxLightType::Point)
        {
            DELETE(shadowmapFramebuffers[0]);
            DELETE(shadowmapFramebuffers[1]);
            DELETE(shadowmapFramebuffers[2]);
            DELETE(shadowmapFramebuffers[3]);
            DELETE(shadowmapFramebuffers[4]);
            DELETE(shadowmapFramebuffers[5]);
            shadowmapFramebuffers[0] = nullptr;
            shadowmapFramebuffers[1] = nullptr;
            shadowmapFramebuffers[2] = nullptr;
            shadowmapFramebuffers[3] = nullptr;
            shadowmapFramebuffers[4] = nullptr;
            shadowmapFramebuffers[5] = nullptr;
        } else if (type == GfxLightType::Directional)
        {
            DELETE(shadowmapFramebuffers[0]);
            DELETE(shadowmapFramebuffers[1]);
            DELETE(shadowmapFramebuffers[2]);
            DELETE(shadowmapFramebuffers[3]);
            shadowmapFramebuffers[0] = nullptr;
            shadowmapFramebuffers[1] = nullptr;
            shadowmapFramebuffers[2] = nullptr;
            shadowmapFramebuffers[3] = nullptr;
        } else
        {
            DELETE(shadowmapFramebuffers[0]);
            shadowmapFramebuffers[0] = nullptr;
        }
    }
}

float Light::getPointLightInfluence(float cutoff) const
{
    return (std::sqrt(1.0f / cutoff) - 1.0f) * point.radius;
}

float Light::getSpotLightInfluence(float cutoff) const
{
    return (std::sqrt(1.0f / cutoff) - 1.0f) * spot.radius;
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

        viewMatrices[0] = Matrix4x4::lookAt(spot.position,
                                            spot.position + spot.direction,
                                            up);

        projectionMatrices[0] = Matrix4x4::perspective(std::min(spot.outerCutoff * 1.2f, 175.0f),
                                                       1.0f,
                                                       shadowmapNear,
                                                       getSpotLightInfluence());
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

        /*//Based on the algorithm from 0 A.D.

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
        projectionMatrix[2][3] = shift.z * scale.z;*/

        #if 0
        //A bunch of magic.
        AABB aabb = renderer->computeShadowCasterAABB();

        const Camera& cam = renderer->camera;

        Matrix3x3 viewMat(cam.getViewMatrix());

        float maxDist = -(viewMat * aabb.getCorner(0)).z;
        maxDist = std::max(maxDist, -(viewMat * aabb.getCorner(1)).z);
        maxDist = std::max(maxDist, -(viewMat * aabb.getCorner(2)).z);
        maxDist = std::max(maxDist, -(viewMat * aabb.getCorner(3)).z);
        maxDist = std::max(maxDist, -(viewMat * aabb.getCorner(4)).z);
        maxDist = std::max(maxDist, -(viewMat * aabb.getCorner(5)).z);
        maxDist = std::max(maxDist, -(viewMat * aabb.getCorner(6)).z);
        maxDist = std::max(maxDist, -(viewMat * aabb.getCorner(7)).z);

        float minDist = cam.getNear();
        float nearDist = minDist;
        float farDist = std::max(maxDist, minDist + 0.01f);
        float lambda = 0.5f; //TODO: What is this? //The number to mix between log and uniform split schemes?

        float splitDists[5] = {nearDist,
                               shadowSplitDistances.x,
                               shadowSplitDistances.y,
                               shadowSplitDistances.z,
                               farDist};
        /*splitDists[0] = nearDist;
        splitDists[4] = farDist;

        for (size_t i = 1; i < 4; ++i)
        {
            float f = i / 4.0f;
            float logDist = nearDist * powf(farDist / nearDist, f);
            float uniformDist = nearDist + (farDist - nearDist) * f;

            splitDists[i] = (1.0f-lambda)*uniformDist + lambda*logDist;
        }*/

        for (size_t i = 0; i < 4; ++i)
        {
            float prevSplitDist = splitDists[i];
            float splitDist = splitDists[i+1];

            //World space
            Float3 frustumCorners[8] = {Float3(-1.0f,  1.0f, 0.0f),
                                        Float3( 1.0f,  1.0f, 0.0f),
                                        Float3( 1.0f, -1.0f, 0.0f),
                                        Float3(-1.0f, -1.0f, 0.0f),
                                        Float3(-1.0f,  1.0f, 1.0f),
                                        Float3( 1.0f,  1.0f, 1.0f),
                                        Float3( 1.0f, -1.0f, 1.0f),
                                        Float3(-1.0f, -1.0f, 1.0f)};

            Matrix4x4 inverseViewProj = cam.getProjectionMatrix() * cam.getViewMatrix(); //TODO: Is this correct?
            inverseViewProj = inverseViewProj.inverse();

            for (size_t j = 0; j < 8; ++j)
            {
                Float4 corner = inverseViewProj * Float4(frustumCorners[j].x,
                                                         frustumCorners[j].y,
                                                         frustumCorners[j].z,
                                                         1.0f);
                frustumCorners[j] = corner.getXYZ() / corner.w;
            }

            for (size_t j = 0; j < 4; ++j)
            {
                Float3 cornerRay = frustumCorners[j+4] - frustumCorners[j];
                Float3 nearCornerRay = cornerRay * prevSplitDist;
                Float3 farCornerRay = cornerRay * splitDist;

                frustumCorners[j+4] = frustumCorners[j] + farCornerRay;
                frustumCorners[j] = frustumCorners[j] + nearCornerRay;
            }

            Float3 frustumCenter;
            for (size_t j = 0; j < 8; ++j)
            {
                frustumCenter += frustumCorners[j];
            }
            frustumCenter /= 8.0f;

            Float3 upDir = cam.getDirection().cross(cam.getUp()).normalize();

            Float3 lightCamPos = frustumCenter;
            Matrix3x3 lightCamRot;
            Float3 row2 = -direction.direction;
            Float3 row0 = upDir.cross(row2).normalize();
            Float3 row1 = row2.cross(row0);
            lightCamRot[2][0] = row2.x;
            lightCamRot[2][1] = row2.y;
            lightCamRot[2][2] = row2.z;
            lightCamRot[0][0] = row0.x;
            lightCamRot[0][1] = row0.y;
            lightCamRot[0][2] = row0.z;
            lightCamRot[1][0] = row1.x;
            lightCamRot[1][0] = row1.y;
            lightCamRot[1][0] = row1.z;
            Matrix4x4 lightView = inverseRotationTranslation(lightCamRot, lightCamPos);

            Float3 minExtents(HUGE_VALF);
            Float3 maxExtents(HUGE_VALF);

            for (size_t j = 0; j < 8; ++j)
            {
                Float3 corner = (lightView *
                                 Float4(frustumCorners[j].x,
                                        frustumCorners[j].y,
                                        frustumCorners[j].z,
                                        1.0f)).getXYZ();
                minExtents.x = std::min(minExtents.x, corner.x);
                minExtents.y = std::min(minExtents.y, corner.y);
                minExtents.z = std::min(minExtents.z, corner.z);
                maxExtents.x = std::max(maxExtents.x, corner.x);
                maxExtents.y = std::max(maxExtents.y, corner.y);
                maxExtents.z = std::max(maxExtents.z, corner.z);
            }

            Float3 cascadeExtents = maxExtents - minExtents;

            Float3 shadowCamPos = frustumCenter + direction.direction * -minExtents.z;

            viewMatrices[i] = inverseRotationTranslation(lightCamRot, shadowCamPos);
            projectionMatrices[i] = Matrix4x4::orthographic(minExtents.x, maxExtents.x,
                                                            minExtents.y, maxExtents.y,
                                                            0.0f, cascadeExtents.z);
        }
        #else
        //Based on the algorithm from 0 A.D.
        AABB casterBounds = renderer->computeShadowCasterAABB();
        AABB sceneBounds = renderer->computeSceneAABB();

        for (size_t i = 0; i < 4; ++i)
        {
            //View
            Float3 z = direction.direction.normalize();
            Float3 x = Float3(0.0f);

            x -= z * z.dot(x);

            if (x.length() < 0.001f)
            {
                x = Float3(1.0f, 0.0f, 0.0f);
                x -= z * z.dot(x);
            }

            x = x.normalize();
            Float3 y = z.cross(x);

            Matrix4x4 viewMatrix = Matrix4x4::lookAt(Float3(0.0f), -z, y);

            //Projection
            AABB casterBounds_ = casterBounds.transform(viewMatrix);
            AABB sceneBounds_ = sceneBounds.transform(viewMatrix);

            if (i != 3)
            {
                float splitDist = shadowSplitDistances[i];

                Position3D camPos = renderer->camera.getPosition();
                Position4D camPos_(camPos.x, camPos.y, camPos.z, 1.0f);
                camPos_ = viewMatrix * camPos_;
                camPos = camPos_.getXYZ() / camPos_.w;

                AABB cascadeBounds(Position3D(camPos.x - splitDist, camPos.y - splitDist, -HUGE_VALF),
                                   Position3D(camPos.x + splitDist, camPos.y + splitDist, HUGE_VALF));

                casterBounds_ = casterBounds_.intersection(cascadeBounds);
                sceneBounds_ = sceneBounds_.intersection(cascadeBounds);
            }

            sceneBounds_.min.z = casterBounds_.min.z - 2.0f;
            sceneBounds_.max.z = casterBounds_.max.z + 2.0f;

            Float3 scale = sceneBounds_.max - sceneBounds_.min;
            Float3 shift = (sceneBounds_.max + sceneBounds_.min) * -0.5;

            scale.x = std::max(scale.x, 1.0f);
            scale.y = std::max(scale.y, 1.0f);
            scale.z = std::max(scale.z, 1.0f);

            scale = Float3(2.0f) / scale;

            Float2 offset(std::fmod(sceneBounds_.min.x - viewMatrix[0][3], 2.0f / (scale.x * shadowmap->getBaseWidth())),
                          std::fmod(sceneBounds_.min.y - viewMatrix[1][3], 2.0f / (scale.y * shadowmap->getBaseHeight())));

            Matrix4x4 projectionMatrix;
            projectionMatrix[0][0] = scale.x;
            projectionMatrix[0][3] = (shift.x + offset.x) * scale.x;
            projectionMatrix[1][1] = scale.y;
            projectionMatrix[1][3] = (shift.y + offset.y) * scale.y;
            projectionMatrix[2][2] = scale.z;
            projectionMatrix[2][3] = shift.z * scale.z;

            viewMatrices[i] = viewMatrix;
            projectionMatrices[i] = projectionMatrix;
        }
        #endif
        break;
    }
    case GfxLightType::Point:
    {
        projectionMatrices[0] = Matrix4x4::perspective(RADIANS(90.0f),
                                                       1.0f,
                                                       shadowmapNear,
                                                       getPointLightInfluence());
        break;
    }
    }
}

#include "graphics/light.h"

#include "graphics/gfxapi.h"
#include "graphics/gfxrenderer.h"
#include "globals.h"

#include <algorithm>
#include <cmath>

Matrix4x4 calcCropMatrix(const Frustum& frustum, const Matrix4x4& lightViewProj, AABB bounds)
{
    bounds = frustum.getAABB().intersection(bounds).transform(lightViewProj);

    bounds.min.x = std::max(std::min(bounds.min.x, 1.0f), -1.0f);
    bounds.min.y = std::max(std::min(bounds.min.y, 1.0f), -1.0f);
    bounds.min.z = std::max(std::min(bounds.min.z, 1.0f), -1.0f);
    bounds.max.x = std::max(std::min(bounds.max.x, 1.0f), -1.0f);
    bounds.max.y = std::max(std::min(bounds.max.y, 1.0f), -1.0f);
    bounds.max.z = std::max(std::min(bounds.max.z, 1.0f), -1.0f);

    Float3 scale = Float3(2.0f) / (bounds.max-bounds.min);
    Float3 offset = (bounds.max+bounds.min) * -0.5f * scale;

    return Matrix4x4(Float4(scale.x, 0.0f, 0.0f, offset.x),
                     Float4(0.0f, scale.y, 0.0f, offset.y),
                     Float4(0.0f, 0.0f, scale.z, offset.z),
                     Float4(0.0f, 0.0f, 0.0f, 1.0f));
}

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
                                 resolution,
                                 resolution,
                                 1,
                                 formats[(int)precision]);

        shadowmap->allocMipmap(0, 1, nullptr);

        shadowmapFramebuffers[0] = gfxApi->createFramebuffer();
        shadowmapFramebuffers[0]->setDepthAttachment(shadowmap);
    } else if (type == GfxLightType::Directional)
    {
        shadowmap->startCreation(GfxTextureType::Texture2DArray,
                                 resolution,
                                 resolution,
                                 4,
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
                                 resolution,
                                 resolution,
                                 1,
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

    shadowmap->sampler.minFilter = GfxFilter::Nearest;
    shadowmap->sampler.magFilter = GfxFilter::Nearest;
    shadowmap->sampler.wrapMode = GfxWrapMode::Stretch;

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
    if (shadowmap == nullptr)
    {
        return;
    }

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
        Camera& cam = renderer->camera;
        Matrix4x4 viewMat = cam.getViewMatrix();
        AABB aabb = renderer->getShadowCasterAABB().transform(viewMat);
        float nearDist = cam.getNear();
        float farDist = std::max(std::abs(aabb.min.z), std::abs(aabb.max.z)) + nearDist;
        float lambda = 0.5f; //0 = uniform 1 = log
        float splitDists[5];/* = {nearDist,
                               shadowSplitDistances.x,
                               shadowSplitDistances.y,
                               shadowSplitDistances.z,
                               farDist};*/
        splitDists[0] = nearDist;
        splitDists[4] = farDist;
        for (size_t i = 1; i < 4; ++i)
        {
            float f = i / 5.0f;
            float logDist = nearDist * powf(farDist / nearDist, f);
            float uniformDist = nearDist + (farDist - nearDist) * f;
            splitDists[i] = (1.0f-lambda)*uniformDist + lambda*logDist;
        }

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

        Matrix4x4 view = Matrix4x4::lookAt(Float3(0.0f), -z, y);

        for (size_t i = 0; i < 4; ++i)
        {
            Frustum frustum = Frustum::view(cam.getViewMatrix().inverse(),
                                            cam.getFieldOfView(),
                                            cam.getWidth()/cam.getHeight(),
                                            splitDists[i],
                                            splitDists[i+1]);

            viewMatrices[i] = view;

            Matrix4x4 proj = Matrix4x4::orthographic(-splitDists[4],
                                                     splitDists[4],
                                                     -splitDists[4],
                                                     splitDists[4],
                                                     splitDists[4],
                                                     -splitDists[4]);

            proj = calcCropMatrix(frustum, view*proj, renderer->getShadowCasterAABB()) * proj;

            //cam.setType(CameraType::Matrices);
            //cam.setViewMatrix(view);
            //cam.setProjectionMatrix(proj);

            projectionMatrices[i] = proj;
        }
        #else
        //Based on the algorithm from 0 A.D.
        AABB casterBounds = renderer->getShadowCasterAABB();
        AABB sceneBounds = renderer->getSceneAABB();

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

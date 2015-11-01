#include "math/frustum.h"

#include "misc_macros.h"

#include <cmath>

Frustum::Frustum(const Position3D& origin_, const Position3D corners_[8])
{
    origin = origin_;

    corners[0] = corners_[0];
    corners[1] = corners_[1];
    corners[2] = corners_[2];
    corners[3] = corners_[3];
    corners[4] = corners_[4];
    corners[5] = corners_[5];
    corners[6] = corners_[6];
    corners[7] = corners_[7];

    planes[0] = Plane(origin, corners[3], corners[0]);
    planes[1] = Plane(origin, corners[1], corners[2]);
    planes[2] = Plane(origin, corners[0], corners[1]);
    planes[3] = Plane(origin, corners[2], corners[3]);
    planes[4] = Plane(corners[0], corners[1], corners[2]);
    planes[5] = Plane(corners[5], corners[4], corners[7]);
}

Frustum::Frustum(const Position3D& origin_,
                 const Position3D corner0,
                 const Position3D corner1,
                 const Position3D corner2,
                 const Position3D corner3,
                 const Position3D corner4,
                 const Position3D corner5,
                 const Position3D corner6,
                 const Position3D corner7)
{
    Position3D corners_[8] = {corner0, corner1, corner2, corner3,
                              corner4, corner5, corner6, corner7};

    new (this) Frustum (origin_, corners_);
}

Frustum Frustum::view(const Matrix4x4& matrix, float fov, float aspect, float near, float far)
{
    float ymax = near * std::tan(RADIANS(fov)/2.0f);
    float xmax = ymax * aspect;

    return Frustum::view(matrix, -xmax, xmax, -ymax, ymax, near, far);
}

Frustum Frustum::view(const Matrix4x4& matrix,
                      float left,
                      float right,
                      float bottom,
                      float top,
                      float near,
                      float far)
{
    float leftf = left * far / near;
    float rightf = right * far / near;
    float bottomf = bottom * far / near;
    float topf = top * far / near;

    Position3D corners[8];
    corners[0] = matrix * Position3D(left, bottom, -near);
    corners[1] = matrix * Position3D(right, bottom, -near);
    corners[2] = matrix * Position3D(right, top, -near);
    corners[3] = matrix * Position3D(left, top, -near);
    corners[4] = matrix * Position3D(leftf, bottomf, -far);
    corners[5] = matrix * Position3D(rightf, bottomf, -far);
    corners[6] = matrix * Position3D(rightf, topf, -far);
    corners[7] = matrix * Position3D(leftf, topf, -far);

    return Frustum(matrix * Float3(0.0f), corners);
}

Frustum Frustum::box(const Matrix4x4& matrix,
                     float left,
                     float right,
                     float bottom,
                     float top,
                     float near,
                     float far)
{
    Position3D corners[8];

    corners[0] = Position3D(left, bottom, front);
    corners[1] = Position3D(right, bottom, front);
    corners[2] = Position3D(right, top, front);
    corners[3] = Position3D(left, top, front);

    corners[4] = Position3D(left, bottom, back);
    corners[5] = Position3D(right, bottom, back);
    corners[6] = Position3D(right, top, back);
    corners[7] = Position3D(left, top, back);

    return Frustum(matrix * Float3(0.0f), corners);
}

AABB Frustum::getAABB() const
{
    AABB result(corners[0], corners[0]);
    result.extend(corners[1]);
    result.extend(corners[2]);
    result.extend(corners[3]);
    result.extend(corners[4]);
    result.extend(corners[5]);
    result.extend(corners[6]);
    result.extend(corners[7]);

    return result;
}

bool Frustum::sphereIntersection(const Position3D& position, float radius)
{
    for (size_t i = 0; i < 6; ++i)
    {
        if (planes[i].distanceToPoint(position) > radius)
        {
            return true;
        }
    }

    return false;
}

bool Frustum::aabbIntersection(const AABB& aabb)
{
    for (size_t i = 0; i < 6; ++i)
    {
        const Position3D& n = planes[i].normal;

        Position3D positive;
        positive.x = n.x < 0.0f ? aabb.max.x : aabb.min.x;
        positive.y = n.y < 0.0f ? aabb.max.y : aabb.min.y;
        positive.z = n.z < 0.0f ? aabb.max.z : aabb.min.z;

        if (planes[i].distanceToPoint(positive) > 0.0f)
        {
            return true;
        }
    }

    return false;
}

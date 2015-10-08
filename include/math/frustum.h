#ifndef FRUSTUM_H
#define FRUSTUM_H

#include "math/t3.h"
#include "math/plane.h"
#include "math/aabb.h"
#include "math/matrix4x4.h"
#include "scripting/bindings.h"

//TODO: This is broken.
class Frustum
{
    public:
        static const size_t leftBottomFront = 0;
        static const size_t rightBottomFront = 1;
        static const size_t rightTopFront = 2;
        static const size_t leftTopFront = 3;
        static const size_t leftBottomBack = 4;
        static const size_t rightBottomBack = 5;
        static const size_t rightTopBack = 6;
        static const size_t leftTopBack = 7;

        static const size_t left = 0;
        static const size_t right = 1;
        static const size_t bottom = 2;
        static const size_t top = 3;
        static const size_t front = 4;
        static const size_t back = 5;

        Frustum() {}
        Frustum(const Position3D& origin, const Position3D corners[8]) NO_BIND;
        Frustum(const Position3D& origin,
                const Position3D corner0,
                const Position3D corner1,
                const Position3D corner2,
                const Position3D corner3,
                const Position3D corner4,
                const Position3D corner5,
                const Position3D corner6,
                const Position3D corner7);

        inline Position3D getOrigin() const
        {
            return origin;
        }

        inline Position3D getCorner(size_t index) const
        {
            return corners[index];
        }

        inline Plane getPlane(size_t index) const
        {
            return planes[index];
        }

        static Frustum view(const Matrix4x4& matrix, float fov, float aspect, float near, float far);
        static Frustum view(const Matrix4x4& matrix,
                            float left,
                            float right,
                            float bottom,
                            float top,
                            float near,
                            float far);

        static Frustum box(const Matrix4x4& matrix,
                           float left,
                           float right,
                           float bottom,
                           float top,
                           float near,
                           float far);

        AABB getAABB() const;

        bool sphereIntersection(const Position3D& position, float radius);
        bool aabbIntersection(const AABB& aabb);
    private:
        Plane planes[6];
        Position3D origin;
        Position3D corners[8];
} BIND;

#endif // FRUSTUM_H

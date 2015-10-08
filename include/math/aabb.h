#ifndef AABB_H
#define AABB_H

#include "math/t3.h"
#include "math/matrix4x4.h"
#include "scripting/bindings.h"
#include "error.h"

#include <algorithm>

class AABB
{
    public:
        AABB() {}
        AABB(const Position3D& min_, const Position3D& max_) : min(min_), max(max_) {}

        AABB transform(const Matrix4x4& matrix) const;
        void extend(const Position3D& point);
        void extend(const AABB& aabb);
        void grow(const Vector3D& amount);
        Position3D getCorner(size_t index) const;
        AABB intersection(const AABB& aabb) const;

        Position3D min;
        Position3D max;
} BIND;

#endif // AABB_H

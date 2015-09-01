#ifndef AABB_H
#define AABB_H

#include "math/t3.h"
#include "math/matrix4x4.h"
#include "scripting/bindings.h"

#include <algorithm>

class AABB
{
    public:
        AABB() {}
        AABB(const Position3D& min_, const Position3D& max_) : min(min_), max(max_) {}

        //Modified from https://github.com/horde3d/Horde3D/blob/master/Horde3D/Source/Horde3DEngine/egPrimitives.h#L63
        AABB transform(const Matrix4x4& matrix) const NO_BIND
        {
            AABB result;

            for (size_t i = 0; i < 3; ++i)
            {
                result.min[i] = matrix[i][3];
                result.max[i] = matrix[i][3];

                for (size_t j = 0; j < 3; ++j)
                {
                    float x = min[j] * matrix[i][j];
                    float y = max[j] * matrix[i][j];

                    result.min[i] += std::min(x, y);
                    result.max[i] += std::max(x, y);
                }
            }

            return result;
        }

        inline void extend(const Position3D& point)
        {
            min.x = std::min(min.x, point.x);
            min.y = std::min(min.y, point.y);
            min.z = std::min(min.z, point.z);

            max.x = std::max(max.x, point.x);
            max.y = std::max(max.y, point.y);
            max.z = std::max(max.z, point.z);
        }

        inline void extend(const AABB& aabb)
        {
            extend(aabb.min);
            extend(aabb.max);
        }

        inline void grow(const Vector3D& amount)
        {
            min -= amount;
            max += amount;
        }

        Position3D min;
        Position3D max;
} BIND;

#endif // AABB_H

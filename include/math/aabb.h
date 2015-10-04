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

        //Modified from https://github.com/horde3d/Horde3D/blob/master/Horde3D/Source/Horde3DEngine/egPrimitives.h#L63
        AABB transform(const Matrix4x4& matrix) const
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

        void extend(const Position3D& point)
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

        inline Position3D getCorner(size_t index)
        {
            if (index > 7)
            {
                THROW(BoundsException);
            }

            Position3D corners[] = {Position3D(min.x, min.y, min.z),
                                    Position3D(min.x, min.y, max.z),
                                    Position3D(min.x, max.y, min.z),
                                    Position3D(min.x, max.y, max.z),
                                    Position3D(max.x, min.y, min.z),
                                    Position3D(max.x, min.y, max.z),
                                    Position3D(max.x, max.y, min.z),
                                    Position3D(max.x, max.y, max.z)};

            return corners[index];
        }

        inline AABB intersection(const AABB& aabb)
        {
            AABB result;
            result.min.x = std::max(min.x, aabb.min.x);
            result.min.y = std::max(min.y, aabb.min.y);
            result.min.z = std::max(min.z, aabb.min.z);

            result.max.x = std::min(max.x, aabb.max.x);
            result.max.y = std::min(max.y, aabb.max.y);
            result.max.z = std::min(max.z, aabb.max.z);

            return result;
        }

        Position3D min;
        Position3D max;
} BIND;

#endif // AABB_H

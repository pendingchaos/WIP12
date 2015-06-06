#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "math/t3.h"
#include "math/matrix3x3.h"
#include "math/quaternion.h"

class Transform
{
    public:
        Transform();

        Quaternion orientation;
        Float3 scale;
        Position3D position;

        bool operator == (const Transform& other) const
        {
            return orientation == other.orientation and
                   scale == other.scale and
                   position == other.position;
        }

        Matrix4x4 createMatrix() const;
};

#endif // TRANSFORM_H

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

        //TODO: This does not work. See transform.cpp.
        /*void lookAt(Position3D target,
                    Direction3D up=Direction3D(0.0f, 1.0f, 0.0f),
                    Direction3D forward=Direction3D(0.0f, 0.0f, 1.0f));*/

        bool operator == (const Transform& other) const
        {
            return orientation == other.orientation and
                   scale == other.scale and
                   position == other.position;
        }

        Matrix4x4 createMatrix() const;
};

#endif // TRANSFORM_H

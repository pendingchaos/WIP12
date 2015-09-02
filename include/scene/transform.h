#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "math/t3.h"
#include "math/matrix3x3.h"
#include "math/quaternion.h"
#include "scripting/bindings.h"

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

        Matrix4x4 createMatrix() const;
} BIND;

#endif // TRANSFORM_H

#ifndef PLANE_H
#define PLANE_H

#include "math/t3.h"
#include "scripting/bindings.h"

class Plane
{
    public:
        Plane() : distance(0.0f) {}

        Plane(const Position3D& v0, const Position3D& v1, const Position3D& v2)
        {
            normal = (v1 - v0).cross(v2 - v0).normalize();
            distance = -normal.dot(v0);
        }

        float distanceToPoint(const Position3D& p) const
        {
            return normal.dot(p) + distance;
        }

        Direction3D normal;
        float distance;
} BIND;

#endif // PLANE_H

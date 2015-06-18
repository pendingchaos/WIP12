#ifndef AABB_H
#define AABB_H

#include "math/t3.h"

class AABB
{
    public:
        AABB() {}
        AABB(const Position3D& min_, const Position3D& max_) : min(min_), max(max_) {}

        Position3D min;
        Position3D max;
};

#endif // AABB_H

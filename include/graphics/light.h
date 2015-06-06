#ifndef LIGHT_H
#define LIGHT_H

#include "math/t3.h"
#include "math/t4.h"

class Light
{
    public:
        enum Type
        {
            Directional,
            Spot,
            Point
        };

        Light(const Vector3D& direction_) : type(Directional),
                                            power(1.0f),
                                            color(1.0f),
                                            direction({direction_}) {}

        Light(const Position3D& position,
              const Vector3D& direction_,
              float innerCutoff,
              float outerCutoff,
              float radius) : type(Spot),
                              power(1.0f),
                              color(1.0f),
                              spot({position, direction_, innerCutoff, outerCutoff, radius}) {}

        Light(const Position3D& position,
              float radius) : type(Point),
                              power(1.0f),
                              color(1.0f),
                              point({position, radius}) {}

        bool operator == (const Light& other) const
        {
            if (type != other.type or
                power != other.power or
                color != other.color)
            {
                return false;
            }

            switch (type)
            {
            case Directional:
            {
                return direction.direction == other.direction.direction;
            }
            case Spot:
            {
                return spot.position == other.spot.position or
                       spot.direction == other.spot.direction or
                       spot.innerCutoff == other.spot.innerCutoff or
                       spot.outerCutoff == other.spot.outerCutoff or
                       spot.radius == other.spot.radius;
            }
            case Point:
            {
                return point.position == other.point.position or
                       point.radius == other.point.radius;
            }
            }
        }

        Type type;
        float power;
        Float3 color;

        struct
        {
            Vector3D direction;
        } direction;

        struct
        {
            Position3D position;
            Vector3D direction;
            float innerCutoff;
            float outerCutoff;
            float radius;
        } spot;

        struct
        {
            Position3D position;
            float radius;
        } point;
};

#endif // LIGHT_H

#ifndef QUATERNION_H
#define QUATERNION_H

#include "math/t3.h"
#include "math/matrix4x4.h"
#include "scripting/bindings.h"

#include <cmath>

class Quaternion
{
    public:
        Quaternion();
        Quaternion(const Direction3D& axis, float angle);
        Quaternion(float x, float y, float z, float w);
        explicit Quaternion(const Float3& angles);

        Quaternion operator * (const Quaternion& other) const;

        Matrix4x4 toMatrix() const;

        inline bool operator == (const Quaternion& other) const
        {
            return x == other.x and y == other.y and z == other.z and w == other.w;
        }

        inline Quaternion normalize() const
        {
            float length = std::sqrt(x*x + y*y + z*z + w*w);

            return length == 0.0f ? *this : Quaternion(x / length,
                                                       y / length,
                                                       z / length,
                                                       w / length);
        }

        inline float getAngle() const
        {
            return std::acos(w) * 2.0f;
        }

        inline float getXAxis() const
        {
            return x / std::sin(std::acos(w));
        }

        inline float getYAxis() const
        {
            return y / std::sin(std::acos(w));
        }

        inline float getZAxis() const
        {
            return z / std::sin(std::acos(w));
        }

        inline Direction3D getAxis() const
        {
            float sha = std::sin(std::acos(w));

            return Float3(x / sha, y / sha, z / sha);
        }

        Float4 getAxisAndAngle() const;

        inline void setAngle(float angle)
        {
            w = std::cos(angle / 2.0f);
        }

        inline void setXAxis(float xAxis)
        {
            x = xAxis * std::sin(std::acos(w));
        }

        inline void setYAxis(float yAxis)
        {
            y = yAxis * std::sin(std::acos(w));
        }

        inline void setZAxis(float zAxis)
        {
            z = zAxis * std::sin(std::acos(w));
        }

        void setAxis(const Direction3D& axis);

        void setAxisAndAngle(const Direction3D& axis, float angle);

        void setEulerAngles(const Float3& angles);
        Float3 getEulerAngles();

        float x, y, z, w;
} BIND;

#endif // QUATERNION_H

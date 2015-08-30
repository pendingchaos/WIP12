#ifndef T3_H
#define T3_H

#include "math/t2.h"
#include "misc_macros.h"
#include "scripting/bindings.h"

#include <cmath>
#include <stdint.h>
#include <stddef.h>

template <typename T>
class T3
{
    public:
        inline T3() : x(T()), y(T()), z(T()) {}
        inline T3(T xyz) : x(xyz), y(xyz), z(xyz) {}
        inline T3(T x_, T y_, T z_) : x(x_), y(y_), z(z_) {}

        inline T3(const T3<float>& other) : x(other.x), y(other.y), z(other.z) {}
        inline T3(const T3<int32_t>& other) : x(other.x), y(other.y), z(other.z) {}
        inline T3(const T3<uint32_t>& other) : x(other.x), y(other.y), z(other.z) {}

        inline T3 operator + (const T3<T>& other) const
        {
            return T3(x + (T)other.x, y + (T)other.y, z + (T)other.z);
        }

        inline T3 operator - (const T3<T>& other) const
        {
            return T3(x - (T)other.x, y - (T)other.y, z - (T)other.z);
        }

        inline T3 operator * (const T3<T>& other) const
        {
            return T3(x * (T)other.x, y * (T)other.y, z * (T)other.z);
        }

        inline T3 operator / (const T3<T>& other) const
        {
            return T3(x / (T)other.x, y / (T)other.y, z / (T)other.z);
        }

        inline T3& operator += (const T3<T>& other)
        {
            x += (T)other.x;
            y += (T)other.y;
            z += (T)other.z;

            return *this;
        }

        inline T3& operator -= (const T3<T>& other)
        {
            x -= (T)other.x;
            y -= (T)other.y;
            z -= (T)other.z;

            return *this;
        }

        inline T3& operator *= (const T3<T>& other)
        {
            x *= (T)other.x;
            y *= (T)other.y;
            z *= (T)other.z;

            return *this;
        }

        inline T3& operator /= (const T3<T>& other)
        {
            x /= (T)other.x;
            y /= (T)other.y;
            z /= (T)other.z;

            return *this;
        }

        inline T3 operator + (const T& other) const
        {
            return T3(x + (T)other, y + (T)other, z + (T)other);
        }

        inline T3 operator - (const T& other) const
        {
            return T3(x - (T)other, y - (T)other, z - (T)other);
        }

        inline T3 operator * (const T& other) const
        {
            return T3(x * (T)other, y * (T)other, z * (T)other);
        }

        inline T3 operator / (const T& other) const
        {
            return T3(x / (T)other, y / (T)other, z / (T)other);
        }

        inline T3& operator += (const T& other)
        {
            x += (T)other;
            y += (T)other;
            z += (T)other;

            return *this;
        }

        inline T3& operator -= (const T& other)
        {
            x -= (T)other;
            y -= (T)other;
            z -= (T)other;

            return *this;
        }

        inline T3& operator *= (const T& other)
        {
            x *= (T)other;
            y *= (T)other;
            z *= (T)other;

            return *this;
        }

        inline T3& operator /= (const T& other)
        {
            x /= (T)other;
            y /= (T)other;
            z /= (T)other;

            return *this;
        }

        inline bool operator == (const T3<T>& other) const
        {
            return x == (T)other.x and y == (T)other.y and z == (T)other.z;
        }

        inline bool operator != (const T3<T>& other) const
        {
            return x != (T)other.x or y != (T)other.y or z != (T)other.z;
        }

        inline bool operator < (const T3<T>& other) const
        {
            return x < (T)other.x and y < (T)other.y and z < (T)other.z;
        }

        inline bool operator > (const T3<T>& other) const
        {
            return x > (T)other.x and y > (T)other.y and z > (T)other.z;
        }

        inline bool operator <= (const T3<T>& other) const
        {
            return x <= (T)other.x and y <= (T)other.y and z <= (T)other.z;
        }

        inline bool operator >= (const T3<T>& other) const
        {
            return x >= (T)other.x and y >= (T)other.y and z >= (T)other.z;
        }

        inline T3 operator - () const
        {
            return T3(-x, -y, -z);
        }

        inline T sum() const
        {
            return x + y + z;
        }

        inline T length() const
        {
            return std::sqrt(x*x + y*y + z*z);
        }

        inline T lengthSquared() const
        {
            return x*x + y*y + z*z;
        }

        inline T dot(const T3<T>& other) const
        {
            return x*(T)other.x + y*(T)other.y + z*(T)other.z;
        }

        inline T dot() const
        {
            return x*x + y*y + z*z;
        }

        inline T distance(const T3<T>& other) const
        {
            return (*this - other).length();
        }

        inline T distanceSquared(const T3<T>& other) const
        {
            return (*this - other).lengthSquared();
        }

        inline T3 normalize() const
        {
            T length_ = length();

            return length_ == T(0) ? *this : *this / T3(length_);
        }

        inline T3 cross(const T3<T>& other) const
        {
            return T3(y * other.z - z * other.y,
                      z * other.x - x * other.z,
                      x * other.y - y * other.x);
        }

        inline T& operator [] (size_t index)
        {
            return ((T *)this)[index];
        }

        inline const T& operator [] (size_t index) const
        {
            return ((T *)this)[index];
        }

        #define SWIZZLE3(upperX, upperY, upperZ, X, Y, Z) inline T3 JOIN(JOIN(JOIN(get, upperX), upperY), upperZ)() const\
        {\
            return T3(X, Y, Z);\
        }\
        \
        inline void JOIN(JOIN(JOIN(set, upperX), upperY), upperZ)(const T3& other)\
        {\
            X = other.x;\
            Y = other.y;\
            Z = other.z;\
        }

        #define SWIZZLE2(upperX, upperY, X, Y) inline T2<T> JOIN(JOIN(get, upperX), upperY)() const\
        {\
            return T2<T>(X, Y);\
        }\
        \
        inline void JOIN(JOIN(set, upperX), upperY)(const T2<T>& other)\
        {\
            X = other.x;\
            Y = other.y;\
        }

        SWIZZLE2(X, Y, x, y)
        SWIZZLE2(X, Z, x, z)
        SWIZZLE2(Y, X, y, x)
        SWIZZLE2(Y, Z, y, z)
        SWIZZLE2(Z, X, z, x)
        SWIZZLE2(Z, Y, z, y)

        SWIZZLE3(X, Y, Z, x, y, z)
        SWIZZLE3(X, Z, Y, x, z, y)
        SWIZZLE3(Y, X, Z, y, x, z)
        SWIZZLE3(Y, Z, X, y, z, x)
        SWIZZLE3(Z, X, Y, z, x, y)
        SWIZZLE3(Z, Y, X, z, y, x)

        #undef SWIZZLE2
        #undef SWIZZLE3

        T x, y, z;
};

//BIND_CLASS(T3)
//TEMPLATE_TYPES(T3, <float>:Float3 <int32_t>:Int3 <uint32_t>:UInt3)

typedef T3<float> Float3;
typedef T3<int32_t> Int3;
typedef T3<uint32_t> UInt3;
typedef Float3 Position3D;
typedef Float3 Vector3D;
typedef Float3 Direction3D;

#endif // T3_H

#ifndef T4_H
#define T4_H

#include "math/t2.h"
#include "math/t3.h"
#include "misc_macros.h"
#include "scripting/bindings.h"

#include <cmath>
#include <stdint.h>
#include <stddef.h>

template <typename T>
class T4
{
    public:
        inline T4() : x(T()), y(T()), z(T()), w(T()) {}
        inline T4(T xyzw) : x(xyzw), y(xyzw), z(xyzw), w(xyzw) {}
        inline T4(T x_, T y_, T z_, T w_) : x(x_), y(y_), z(z_), w(w_) {}

        inline T4(const T4<float>& other) : x(other.x), y(other.y), z(other.z), w(other.w) {}
        inline T4(const T4<int32_t>& other) : x(other.x), y(other.y), z(other.z), w(other.w) {}
        inline T4(const T4<uint32_t>& other) : x(other.x), y(other.y), z(other.z), w(other.w) {}

        inline T4 operator + (const T4<T>& other) const
        {
            return T4(x + (T)other.x, y + (T)other.y, z + (T)other.z, w + (T)other.w);
        }

        inline T4 operator - (const T4<T>& other) const
        {
            return T4(x - (T)other.x, y - (T)other.y, z - (T)other.z, w - (T)other.w);
        }

        inline T4 operator * (const T4<T>& other) const
        {
            return T4(x * (T)other.x, y * (T)other.y, z * (T)other.z, w * (T)other.w);
        }

        inline T4 operator / (const T4<T>& other) const
        {
            return T4(x / (T)other.x, y / (T)other.y, z / (T)other.z, w / (T)other.w);
        }

        inline T4& operator += (const T4<T>& other)
        {
            x += (T)other.x;
            y += (T)other.y;
            z += (T)other.z;
            w += (T)other.w;

            return *this;
        }

        inline T4& operator -= (const T4<T>& other)
        {
            x -= (T)other.x;
            y -= (T)other.y;
            z -= (T)other.z;
            w -= (T)other.w;

            return *this;
        }

        inline T4& operator *= (const T4<T>& other)
        {
            x *= (T)other.x;
            y *= (T)other.y;
            z *= (T)other.z;
            w *= (T)other.w;

            return *this;
        }

        inline T4& operator /= (const T4<T>& other)
        {
            x /= (T)other.x;
            y /= (T)other.y;
            z /= (T)other.z;
            w /= (T)other.w;

            return *this;
        }

        inline T4 operator + (const T& other) const
        {
            return T4(x + (T)other, y + (T)other, z + (T)other, w + (T)other);
        }

        inline T4 operator - (const T& other) const
        {
            return T4(x - (T)other, y - (T)other, z - (T)other, w - (T)other);
        }

        inline T4 operator * (const T& other) const
        {
            return T4(x * (T)other, y * (T)other, z * (T)other, w * (T)other);
        }

        inline T4 operator / (const T& other) const
        {
            return T4(x / (T)other, y / (T)other, z / (T)other, w / (T)other);
        }

        inline T4& operator += (const T& other)
        {
            x += (T)other;
            y += (T)other;
            z += (T)other;
            w += (T)other;

            return *this;
        }

        inline T4& operator -= (const T& other)
        {
            x -= (T)other;
            y -= (T)other;
            z -= (T)other;
            w -= (T)other;

            return *this;
        }

        inline T4& operator *= (const T& other)
        {
            x *= (T)other;
            y *= (T)other;
            z *= (T)other;
            w *= (T)other;

            return *this;
        }

        inline T4& operator /= (const T& other)
        {
            x /= (T)other;
            y /= (T)other;
            z /= (T)other;
            w /= (T)other;

            return *this;
        }

        inline bool operator == (const T4<T>& other) const
        {
            return x == (T)other.x and y == (T)other.y and z == (T)other.z and w == (T)other.w;
        }

        inline bool operator != (const T4<T>& other) const
        {
            return x != (T)other.x or y != (T)other.y or z != (T)other.z or w != (T)other.w;
        }

        inline bool operator < (const T4<T>& other) const
        {
            return x < (T)other.x and y < (T)other.y and z < (T)other.z and w < (T)other.w;
        }

        inline bool operator > (const T4<T>& other) const
        {
            return x > (T)other.x and y > (T)other.y and z > (T)other.z and w > (T)other.w;
        }

        inline bool operator <= (const T4<T>& other) const
        {
            return x <= (T)other.x and y <= (T)other.y and z <= (T)other.z and w <= (T)other.w;
        }

        inline bool operator >= (const T4<T>& other) const
        {
            return x >= (T)other.x and y >= (T)other.y and z >= (T)other.z and w >= (T)other.w;
        }

        inline T4 operator - () const
        {
            return T4(-x, -y, -z, -w);
        }

        inline T sum() const
        {
            return x + y + z + w;
        }

        inline T length() const
        {
            return std::sqrt(x*x + y*y + z*z + w*w);
        }

        inline T lengthSquared() const
        {
            return x*x + y*y + z*z + w*w;
        }

        inline T dot(const T4<T>& other) const
        {
            return x*(T)other.x + y*(T)other.y + z*(T)other.z + w*(T)other.w;
        }

        inline T dot() const
        {
            return x*x + y*y + z*z + w*w;
        }

        inline T distance(const T4<T>& other) const
        {
            return (*this - other).length();
        }

        inline T distanceSquared(const T4<T>& other) const
        {
            return (*this - other).lengthSquared();
        }

        inline T4 normalize() const
        {
            T length_ = length();

            return length_ == T(0) ? *this : *this / T4(length_);
        }

        inline T& operator [] (size_t index)
        {
            return ((T *)this)[index];
        }

        inline const T& operator [] (size_t index) const
        {
            return ((T *)this)[index];
        }

        #define SWIZZLE4(upperX, upperY, upperZ, upperW, X, Y, Z, W) inline T4 JOIN(JOIN(JOIN(JOIN(get, upperX), upperY), upperZ), upperW)() const\
        {\
            return T4(X, Y, Z, W);\
        }\
        \
        inline void JOIN(JOIN(JOIN(JOIN(set, upperX), upperY), upperZ), upperW)(const T4& other)\
        {\
            X = other.x;\
            Y = other.y;\
            Z = other.z;\
            W = other.w;\
        }

        #define SWIZZLE3(upperX, upperY, upperZ, X, Y, Z) inline T3<T> JOIN(JOIN(JOIN(get, upperX), upperY), upperZ)() const\
        {\
            return T3<T>(X, Y, Z);\
        }\
        \
        inline void JOIN(JOIN(JOIN(set, upperX), upperY), upperZ)(const T3<T>& other)\
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
        SWIZZLE2(X, W, x, w)
        SWIZZLE2(Y, X, y, x)
        SWIZZLE2(Y, Z, y, z)
        SWIZZLE2(Y, W, y, w)
        SWIZZLE2(Z, X, z, x)
        SWIZZLE2(Z, Y, z, y)
        SWIZZLE2(Z, W, z, w)
        SWIZZLE2(W, X, w, x)
        SWIZZLE2(W, Y, w, y)
        SWIZZLE2(W, Z, w, z)

        SWIZZLE3(X, Y, Z, x, y, z)
        SWIZZLE3(X, Y, W, x, y, w)
        SWIZZLE3(X, Z, Y, x, y, y)
        SWIZZLE3(X, Z, W, x, y, w)
        SWIZZLE3(X, W, Z, x, y, z)
        SWIZZLE3(X, W, Y, x, y, y)
        SWIZZLE3(Y, X, Z, y, x, z)
        SWIZZLE3(Y, X, W, y, x, w)
        SWIZZLE3(Y, Z, X, y, z, x)
        SWIZZLE3(Y, Z, W, y, z, w)
        SWIZZLE3(Y, W, Z, y, w, z)
        SWIZZLE3(Y, W, X, y, w, x)
        SWIZZLE3(Z, X, Y, z, x, y)
        SWIZZLE3(Z, X, W, z, x, w)
        SWIZZLE3(Z, Y, X, z, y, x)
        SWIZZLE3(Z, Y, W, z, y, w)
        SWIZZLE3(Z, W, Y, z, w, y)
        SWIZZLE3(Z, W, X, z, w, x)
        SWIZZLE3(W, X, Y, w, x, y)
        SWIZZLE3(W, X, Z, w, x, z)
        SWIZZLE3(W, Y, X, w, y, x)
        SWIZZLE3(W, Y, Z, w, y, z)
        SWIZZLE3(W, Z, Y, w, z, y)
        SWIZZLE3(W, Z, X, w, z, x)

        SWIZZLE4(X, Y, Z, W, x, y, z, w)
        SWIZZLE4(X, Y, W, Z, x, y, w, z)
        SWIZZLE4(X, Z, Y, W, x, z, y, w)
        SWIZZLE4(X, Z, W, Y, x, z, w, y)
        SWIZZLE4(X, W, Z, Y, x, w, z, y)
        SWIZZLE4(X, W, Y, Z, x, w, y, z)
        SWIZZLE4(Y, X, Z, W, y, x, z, w)
        SWIZZLE4(Y, X, W, Z, y, x, w, z)
        SWIZZLE4(Y, Z, X, W, y, z, x, w)
        SWIZZLE4(Y, Z, W, X, y, z, w, x)
        SWIZZLE4(Y, W, Z, X, y, w, z, x)
        SWIZZLE4(Y, W, X, Z, y, w, x, z)
        SWIZZLE4(Z, Y, X, W, z, y, x, w)
        SWIZZLE4(Z, Y, W, X, z, y, w, x)
        SWIZZLE4(Z, X, Y, W, z, x, y, w)
        SWIZZLE4(Z, X, W, Y, z, x, w, y)
        SWIZZLE4(Z, W, X, Y, z, w, x, y)
        SWIZZLE4(Z, W, Y, X, z, w, y, x)
        SWIZZLE4(W, Y, Z, X, w, y, z, x)
        SWIZZLE4(W, Y, X, Z, w, y, x, z)
        SWIZZLE4(W, Z, Y, X, w, z, y, x)
        SWIZZLE4(W, Z, X, Y, w, z, x, y)
        SWIZZLE4(W, X, Z, Y, w, x, z, y)
        SWIZZLE4(W, X, Y, Z, w, x, y, z)

        #undef SWIZZLE2
        #undef SWIZZLE3
        #undef SWIZZLE4

        inline T4 copy() const
        {
            return T4(x, y, z, w);
        }

        T x, y, z, w;
};

BIND_CLASS(T4)
TEMPLATE_TYPES(T4:T, <float>@Float4 <int32_t>@Int4 <uint32_t>@UInt4)

typedef T4<float> Float4;
typedef T4<int32_t> Int4;
typedef T4<uint32_t> UInt4;
typedef Float4 Position4D;
typedef Float4 Vector4D;
typedef Float4 Direction4D;

#endif // T4_H

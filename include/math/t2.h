#ifndef T2_H
#define T2_H

#include "scripting/bindings.h"

#include <cmath>
#include <stdint.h>
#include <stddef.h>

template <typename T>
class T2
{
    public:
        inline T2() : x(T()), y(T()) {}
        inline T2(T xy) : x(xy), y(xy) {}
        inline T2(T x_, T y_) : x(x_), y(y_) {}

        inline T2(const T2<float>& other) : x(other.x), y(other.y) {}
        inline T2(const T2<int32_t>& other) : x(other.x), y(other.y) {}
        inline T2(const T2<uint32_t>& other) : x(other.x), y(other.y) {}

        inline T2 operator + (const T2<T>& other) const
        {
            return T2(x + (T)other.x, y + (T)other.y);
        }

        inline T2 operator - (const T2<T>& other) const
        {
            return T2(x - (T)other.x, y - (T)other.y);
        }

        inline T2 operator * (const T2<T>& other) const
        {
            return T2(x * (T)other.x, y * (T)other.y);
        }

        inline T2 operator / (const T2<T>& other) const
        {
            return T2(x / (T)other.x, y / (T)other.y);
        }

        inline T2& operator += (const T2<T>& other)
        {
            x += (T)other.x;
            y += (T)other.y;

            return *this;
        }

        inline T2& operator -= (const T2<T>& other)
        {
            x -= (T)other.x;
            y -= (T)other.y;

            return *this;
        }

        inline T2& operator *= (const T2<T>& other)
        {
            x *= (T)other.x;
            y *= (T)other.y;

            return *this;
        }

        inline T2& operator /= (const T2<T>& other)
        {
            x /= (T)other.x;
            y /= (T)other.y;

            return *this;
        }

        inline T2 operator + (T other) const
        {
            return T2(x + (T)other, y + (T)other);
        }

        inline T2 operator - (T other) const
        {
            return T2(x - (T)other, y - (T)other);
        }

        inline T2 operator * (T other) const
        {
            return T2(x * (T)other, y * (T)other);
        }

        inline T2 operator / (T other) const
        {
            return T2(x / (T)other, y / (T)other);
        }

        inline T2& operator += (T other)
        {
            x += (T)other;
            y += (T)other;

            return *this;
        }

        inline T2& operator -= (T other)
        {
            x -= (T)other;
            y -= (T)other;

            return *this;
        }

        inline T2& operator *= (T other)
        {
            x *= (T)other;
            y *= (T)other;

            return *this;
        }

        inline T2& operator /= (T other)
        {
            x /= (T)other;
            y /= (T)other;

            return *this;
        }

        inline bool operator == (const T2<T>& other) const
        {
            return x == (T)other.x and y == (T)other.y;
        }

        inline bool operator != (const T2<T>& other) const
        {
            return x != (T)other.x or y != (T)other.y;
        }

        inline bool operator < (const T2<T>& other) const
        {
            return x < (T)other.x and y < (T)other.y;
        }

        inline bool operator > (const T2<T>& other) const
        {
            return x > (T)other.x and y > (T)other.y;
        }

        inline bool operator <= (const T2<T>& other) const
        {
            return x <= (T)other.x and y <= (T)other.y;
        }

        inline bool operator >= (const T2<T>& other) const
        {
            return x >= (T)other.x and y >= (T)other.y;
        }

        inline T2 operator - () const
        {
            return T2(-x, -y);
        }

        inline T sum() const
        {
            return x + y;
        }

        inline T length() const
        {
            return std::sqrt(x*x + y*y);
        }

        inline T lengthSquared() const
        {
            return x*x + y*y;
        }

        inline T dot(const T2<T>& other) const
        {
            return x*(T)other.x + y*(T)other.y;
        }

        inline T dot() const
        {
            return x*x + y*y;
        }

        inline T distance(const T2<T>& other) const
        {
            return (*this - other).length();
        }

        inline T distanceSquared(const T2<T>& other) const
        {
            return (*this - other).lengthSquared();
        }

        inline T2 normalize() const
        {
            T length_ = length();

            return length_ == T(0) ? *this : *this / T2(length_);
        }

        inline T& operator [] (size_t index)
        {
            return ((T *)this)[index];
        }

        inline const T& operator [] (size_t index) const
        {
            return ((T *)this)[index];
        }

        inline T2 getXY() const
        {
            return T2(x, y);
        }

        inline void setXY(const T2& xy)
        {
            x = xy.x;
            y = xy.y;
        }

        inline T2 getYX() const
        {
            return T2(y, x);
        }

        inline void setYX(const T2& yx)
        {
            x = yx.y;
            y = yx.x;
        }

        T x, y;
};

//BIND_CLASS(T2)
//TEMPLATE_TYPES(T2, <float>:Float2 <int32_t>:Int2 <uint32_t>:UInt2)

typedef T2<float> Float2;
typedef T2<int32_t> Int2;
typedef T2<uint32_t> UInt2;
typedef Float2 Position2D;
typedef Float2 Vector2D;
typedef Float2 Direction2D;

#endif // T2_H

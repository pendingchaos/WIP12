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
        T2() : x(T()), y(T()) {}
        T2(T xy) : x(xy), y(xy) {}
        T2(T x_, T y_) : x(x_), y(y_) {}

        T2(const T2<float>& other) : x(other.x), y(other.y) {}
        T2(const T2<int32_t>& other) : x(other.x), y(other.y) {}
        T2(const T2<uint32_t>& other) : x(other.x), y(other.y) {}

        T2 operator + (const T2<T>& other) const
        {
            return T2(x + (T)other.x, y + (T)other.y);
        }

        T2 operator - (const T2<T>& other) const
        {
            return T2(x - (T)other.x, y - (T)other.y);
        }

        T2 operator * (const T2<T>& other) const
        {
            return T2(x * (T)other.x, y * (T)other.y);
        }

        T2 operator / (const T2<T>& other) const
        {
            return T2(x / (T)other.x, y / (T)other.y);
        }

        T2& operator += (const T2<T>& other)
        {
            x += (T)other.x;
            y += (T)other.y;

            return *this;
        }

        T2& operator -= (const T2<T>& other)
        {
            x -= (T)other.x;
            y -= (T)other.y;

            return *this;
        }

        T2& operator *= (const T2<T>& other)
        {
            x *= (T)other.x;
            y *= (T)other.y;

            return *this;
        }

        T2& operator /= (const T2<T>& other)
        {
            x /= (T)other.x;
            y /= (T)other.y;

            return *this;
        }

        T2 operator + (T other) const
        {
            return T2(x + (T)other, y + (T)other);
        }

        T2 operator - (T other) const
        {
            return T2(x - (T)other, y - (T)other);
        }

        T2 operator * (T other) const
        {
            return T2(x * (T)other, y * (T)other);
        }

        T2 operator / (T other) const
        {
            return T2(x / (T)other, y / (T)other);
        }

        T2& operator += (T other)
        {
            x += (T)other;
            y += (T)other;

            return *this;
        }

        T2& operator -= (T other)
        {
            x -= (T)other;
            y -= (T)other;

            return *this;
        }

        T2& operator *= (T other)
        {
            x *= (T)other;
            y *= (T)other;

            return *this;
        }

        T2& operator /= (T other)
        {
            x /= (T)other;
            y /= (T)other;

            return *this;
        }

        bool operator == (const T2<T>& other) const
        {
            return x == (T)other.x and y == (T)other.y;
        }

        bool operator != (const T2<T>& other) const
        {
            return x != (T)other.x or y != (T)other.y;
        }

        bool operator < (const T2<T>& other) const
        {
            return x < (T)other.x and y < (T)other.y;
        }

        bool operator > (const T2<T>& other) const
        {
            return x > (T)other.x and y > (T)other.y;
        }

        bool operator <= (const T2<T>& other) const
        {
            return x <= (T)other.x and y <= (T)other.y;
        }

        bool operator >= (const T2<T>& other) const
        {
            return x >= (T)other.x and y >= (T)other.y;
        }

        T2 operator - () const
        {
            return T2(-x, -y);
        }

        T sum() const
        {
            return x + y;
        }

        T length() const
        {
            return std::sqrt(x*x + y*y);
        }

        T lengthSquared() const
        {
            return x*x + y*y;
        }

        T dot(const T2<T>& other) const
        {
            return x*(T)other.x + y*(T)other.y;
        }

        T dot() const
        {
            return x*x + y*y;
        }

        T distance(const T2<T>& other) const
        {
            return (*this - other).length();
        }

        T distanceSquared(const T2<T>& other) const
        {
            return (*this - other).lengthSquared();
        }

        T2 normalize() const
        {
            T length_ = length();

            return length_ == T(0) ? *this : *this / T2(length_);
        }

        T& operator [] (size_t index)
        {
            return ((T *)this)[index];
        }

        const T& operator [] (size_t index) const
        {
            return ((T *)this)[index];
        }

        T2 getXY() const
        {
            return T2(x, y);
        }

        void setXY(const T2& xy)
        {
            x = xy.x;
            y = xy.y;
        }

        T2 getYX() const
        {
            return T2(y, x);
        }

        void setYX(const T2& yx)
        {
            x = yx.y;
            y = yx.x;
        }

        T2 copy() const
        {
            return T2(x, y);
        }

        T x, y;
};

BIND_CLASS(T2)
TEMPLATE_TYPES(T2:T, <float>@Float2 <int32_t>@Int2 <uint32_t>@UInt2)

typedef T2<float> Float2;
typedef T2<int32_t> Int2;
typedef T2<uint32_t> UInt2;
typedef Float2 Position2D;
typedef Float2 Vector2D;
typedef Float2 Direction2D;

#endif // T2_H

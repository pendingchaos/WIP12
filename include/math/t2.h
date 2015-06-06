#ifndef T2_H
#define T2_H

#include <cmath>
#include <stdint.h>

template <typename T>
class T2
{
    public:
        inline T2() : x(T()), y(T()) {}
        inline T2(T xy) : x(xy), y(xy) {}
        inline T2(T x_, T y_) : x(x_), y(y_) {}

        inline T2(const T2& other) : x(other.x), y(other.y) {}

        template <typename OtherT>
        inline T2(const T2<OtherT>& other) : x(other.x), y(other.y) {}

        template <typename OtherT>
        inline T2 operator + (const T2<OtherT>& other) const
        {
            return T2(x + (T)other.x, y + (T)other.y);
        }

        template <typename OtherT>
        inline T2 operator - (const T2<OtherT>& other) const
        {
            return T2(x - (T)other.x, y - (T)other.y);
        }

        template <typename OtherT>
        inline T2 operator * (const T2<OtherT>& other) const
        {
            return T2(x * (T)other.x, y * (T)other.y);
        }

        template <typename OtherT>
        inline T2 operator / (const T2<OtherT>& other) const
        {
            return T2(x / (T)other.x, y / (T)other.y);
        }

        template <typename OtherT>
        inline T2& operator += (const T2<OtherT>& other)
        {
            x += (T)other.x;
            y += (T)other.y;

            return *this;
        }

        template <typename OtherT>
        inline T2& operator -= (const T2<OtherT>& other)
        {
            x -= (T)other.x;
            y -= (T)other.y;

            return *this;
        }

        template <typename OtherT>
        inline T2& operator *= (const T2<OtherT>& other)
        {
            x *= (T)other.x;
            y *= (T)other.y;

            return *this;
        }

        template <typename OtherT>
        inline T2& operator /= (const T2<OtherT>& other)
        {
            x /= (T)other.x;
            y /= (T)other.y;

            return *this;
        }

        template <typename OtherT>
        inline T2 operator + (OtherT other) const
        {
            return T2(x + (T)other, y + (T)other);
        }

        template <typename OtherT>
        inline T2 operator - (OtherT other) const
        {
            return T2(x - (T)other, y - (T)other);
        }

        template <typename OtherT>
        inline T2 operator * (OtherT other) const
        {
            return T2(x * (T)other, y * (T)other);
        }

        template <typename OtherT>
        inline T2 operator / (OtherT other) const
        {
            return T2(x / (T)other, y / (T)other);
        }

        template <typename OtherT>
        inline T2& operator += (OtherT other)
        {
            x += (T)other;
            y += (T)other;

            return *this;
        }

        template <typename OtherT>
        inline T2& operator -= (OtherT other)
        {
            x -= (T)other;
            y -= (T)other;

            return *this;
        }

        template <typename OtherT>
        inline T2& operator *= (OtherT other)
        {
            x *= (T)other;
            y *= (T)other;

            return *this;
        }

        template <typename OtherT>
        inline T2& operator /= (OtherT other)
        {
            x /= (T)other;
            y /= (T)other;

            return *this;
        }

        template <typename OtherT>
        inline bool operator == (const T2<OtherT>& other) const
        {
            return x == (T)other.x and y == (T)other.y;
        }

        template <typename OtherT>
        inline bool operator != (const T2<OtherT>& other) const
        {
            return x != (T)other.x or y != (T)other.y;
        }

        template <typename OtherT>
        inline bool operator < (const T2<OtherT>& other) const
        {
            return x < (T)other.x and y < (T)other.y;
        }

        template <typename OtherT>
        inline bool operator > (const T2<OtherT>& other) const
        {
            return x > (T)other.x and y > (T)other.y;
        }

        template <typename OtherT>
        inline bool operator <= (const T2<OtherT>& other) const
        {
            return x <= (T)other.x and y <= (T)other.y;
        }

        template <typename OtherT>
        inline bool operator >= (const T2<OtherT>& other) const
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

        template <typename OtherT>
        inline T dot(const T2<OtherT>& other) const
        {
            return x*(T)other.x + y*(T)other.y;
        }

        inline T dot() const
        {
            return x*x + y*y;
        }

        template <typename OtherT>
        inline T distance(const T2<OtherT>& other) const
        {
            return (*this - other).length();
        }

        template <typename OtherT>
        inline T distanceSquared(const T2<OtherT>& other) const
        {
            return (*this - other).lengthSquared();
        }

        inline T2 normalize() const
        {
            T length_ = length();

            return length_ == T(0) ? *this : *this / T2(length_);
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

typedef T2<float> Float2;
typedef T2<int32_t> Int2;
typedef T2<uint32_t> UInt2;
typedef Float2 Position2D;
typedef Float2 Vector2D;
typedef Float2 Direction2D;

#endif // T2_H

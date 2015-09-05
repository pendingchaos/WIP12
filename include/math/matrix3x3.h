#ifndef MATRIX3X3_H
#define MATRIX3X3_H

#include "math/t2.h"
#include "math/t3.h"
#include "error.h"
#include "scripting/bindings.h"

class Matrix4x4;

/**
 *A matrix is stored in row-major order.
 *
 *It is stored like this:
 *0 1 2
 *3 4 5
 *6 7 8
 *
 *And indexed like this:
 *0,0 0,1 0,2
 *1,0 1,1 1,2
 *2,0 2,1 2,2
 */
class Matrix3x3
{
    public:
        Matrix3x3();
        Matrix3x3(const Matrix4x4& other);

        Matrix3x3(const Float3& row1,
                  const Float3& row2,
                  const Float3& row3);

        Matrix3x3 operator * (const Matrix3x3& other) const;

        Float3 operator * (const Float3& other) const;

        Matrix3x3 operator / (float other) const;

        inline const float *operator [] (unsigned int row) const NO_BIND
        {
            return data[row];
        }

        inline float *operator [] (unsigned int row) NO_BIND
        {
            return data[row];
        }

        inline float get(size_t row, size_t column)
        {
            if (row > 2 or column > 2)
            {
                THROW(BoundsException);
            }

            return data[row][column];
        }

        inline void set(size_t row, size_t column, float value)
        {
            if (row > 2 or column > 2)
            {
                THROW(BoundsException);
            }

            data[row][column] = value;
        }

        inline bool operator == (const Matrix3x3& other) const
        {
            return data[0][0] == other.data[0][0] and
                   data[0][1] == other.data[0][1] and
                   data[0][2] == other.data[0][2] and
                   data[1][0] == other.data[1][0] and
                   data[1][1] == other.data[1][1] and
                   data[1][2] == other.data[1][2] and
                   data[2][0] == other.data[2][0] and
                   data[2][1] == other.data[2][1] and
                   data[2][2] == other.data[2][2];
        }

        Matrix3x3 transpose() const;

        Matrix3x3 inverse() const;

        static Matrix3x3 translate(const Float2& translation);
        static Matrix3x3 scale(const Float3& scale);
        static Matrix3x3 rotate(float rotation);
        static Matrix3x3 rotatex(float rotation);
        static Matrix3x3 rotatey(float rotation);
        static Matrix3x3 rotatez(float rotation);

        NO_BIND float data[3][3];
} BIND;

#endif // MATRIX3X3_H

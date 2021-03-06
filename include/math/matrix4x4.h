#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include "math/t3.h"
#include "math/t4.h"
#include "error.h"

class Matrix3x3;
class Quaternion;

/**
 *A matrix is stored in row-major order.
 *
 *It is stored like this:
 *0  1  2  3
 *4  5  6  7
 *8  9  10 11
 *12 13 14 15
 *
 *And indexed like this:
 *0,0 0,1 0,2 0,3
 *1,0 1,1 1,2 1,3
 *2,0 2,1 2,2 2,3
 *3,0 3,1 3,2 3,3
 */
class Matrix4x4
{
    public:
        enum _NoInit {NoInit};

        Matrix4x4();
        Matrix4x4(_NoInit _) NO_BIND;
        Matrix4x4(const Matrix3x3& other);

        Matrix4x4(const Float4& row1,
                  const Float4& row2,
                  const Float4& row3,
                  const Float4& row4);

        Matrix4x4 operator * (const Matrix4x4& other) const;
        Float4 operator * (const Float4& other) const;

        Float3 operator * (const Float3& other) const
        {
            Float4 other4(other.x, other.y, other.z, 1.0f);
            other4 = *this * other4;
            return other4.getXYZ() / other4.w;
        }

        Matrix4x4 operator / (float other) const;

        const float *operator [] (unsigned int row) const NO_BIND
        {
            return data[row];
        }

        float *operator [] (unsigned int row) NO_BIND
        {
            return data[row];
        }

        float get(size_t row, size_t column)
        {
            if (row > 2 or column > 2)
            {
                THROW(BoundsException);
            }

            return data[row][column];
        }

        void set(size_t row, size_t column, float value)
        {
            if (row > 2 or column > 2)
            {
                THROW(BoundsException);
            }

            data[row][column] = value;
        }

        bool operator == (const Matrix4x4& other) const
        {
            return data[0][0] == other.data[0][0] and
                   data[0][1] == other.data[0][1] and
                   data[0][2] == other.data[0][2] and
                   data[0][3] == other.data[0][3] and
                   data[1][0] == other.data[1][0] and
                   data[1][1] == other.data[1][1] and
                   data[1][2] == other.data[1][2] and
                   data[1][3] == other.data[1][3] and
                   data[2][0] == other.data[2][0] and
                   data[2][1] == other.data[2][1] and
                   data[2][2] == other.data[2][2] and
                   data[2][3] == other.data[2][3] and
                   data[3][0] == other.data[3][0] and
                   data[3][1] == other.data[3][1] and
                   data[3][2] == other.data[3][2] and
                   data[3][3] == other.data[3][3];
        }

        Matrix4x4 transpose() const;
        float determinant() const;
        Matrix4x4 inverse() const;

        void multTrans(const Float3& translation);
        void multScale(const Float3& scale);
        void multQuat(const Quaternion& quat);

        static Matrix4x4 translate(const Float3& translation);

        static Matrix4x4 scale(const Float3& scale);

        static Matrix4x4 rotate(float rotation);
        static Matrix4x4 rotatex(float rotation);
        static Matrix4x4 rotatey(float rotation);
        static Matrix4x4 rotatez(float rotation);

        static Matrix4x4 perspective(float fov, float aspect, float near, float far);
        static Matrix4x4 orthographic(float left,
                                      float right,
                                      float bottom,
                                      float top,
                                      float near,
                                      float far);

        static Matrix4x4 lookAt(const Position3D& eye,
                                const Position3D& center,
                                const Direction3D& up);

        static Matrix4x4 lookAtDir(const Position3D& eye,
                                   const Direction3D& dir,
                                   const Direction3D& up);

        NO_BIND float data[4][4];
} BIND;

inline Matrix4x4 lookAtDirMat(const Position3D& eye, const Direction3D& dir, const Direction3D& up) BIND
{
    return Matrix4x4::lookAtDir(eye, dir, up);
}

#endif // MATRIX4X4_H

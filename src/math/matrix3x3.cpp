#include "math/matrix3x3.h"

#include "math/matrix4x4.h"

#include <cmath>

Matrix3x3::Matrix3x3()
{
    data[0][0] = 1.0f; data[1][0] = 0.0f; data[2][0] = 0.0f;
    data[0][1] = 0.0f; data[1][1] = 1.0f; data[2][1] = 0.0f;
    data[0][2] = 0.0f; data[1][2] = 0.0f; data[2][2] = 1.0f;
}

Matrix3x3::Matrix3x3(const Matrix4x4& other)
{
    data[0][0] = other[0][0];
    data[1][0] = other[1][0];
    data[2][0] = other[2][0];

    data[0][1] = other[0][1];
    data[1][1] = other[1][1];
    data[2][1] = other[2][1];

    data[0][2] = other[0][2];
    data[1][2] = other[1][2];
    data[2][2] = other[2][2];
}

Matrix3x3::Matrix3x3(const Float3& row1,
                     const Float3& row2,
                     const Float3& row3)
{
    data[0][0] = row1.x;
    data[0][1] = row1.y;
    data[0][2] = row1.z;

    data[1][0] = row2.x;
    data[1][1] = row2.y;
    data[1][2] = row2.z;

    data[2][0] = row3.x;
    data[2][1] = row3.y;
    data[2][2] = row3.z;
}

Matrix3x3 Matrix3x3::operator * (const Matrix3x3& other) const
{
    Matrix3x3 result;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            float sum = 0.0f;

            for (int k = 0; k < 3; ++k)
            {
                sum += data[i][k] * other.data[k][j];
            }

            result.data[i][j] = sum;
        }
    }

    return result;
}

Float3 Matrix3x3::operator * (const Float3& other) const
{
    return Float3((*reinterpret_cast<const Float3 *>(data)*other).sum(),
                  (*reinterpret_cast<const Float3 *>(&data[1])*other).sum(),
                  (*reinterpret_cast<const Float3 *>(&data[2])*other).sum());
}

Matrix3x3 Matrix3x3::operator / (float other) const
{
    return Matrix3x3(Float3(data[0][0]/other, data[1][0]/other, data[2][0]/other),
                     Float3(data[0][1]/other, data[1][1]/other, data[2][1]/other),
                     Float3(data[0][2]/other, data[1][2]/other, data[2][2]/other));
}

Matrix3x3 Matrix3x3::transpose() const
{
    const float *m[3] = {data[0], data[1], data[2]};

    return Matrix3x3(Float3(m[0][0], m[0][1], m[0][2]),
                     Float3(m[1][0], m[1][1], m[1][2]),
                     Float3(m[2][0], m[2][1], m[2][2]));
}

Matrix3x3 Matrix3x3::inverse() const
{
    const float *m[3] = {data[0], data[1], data[2]};

    float a00 = m[0][0], a01 = m[1][0], a02 = m[2][0];
    float a10 = m[0][1], a11 = m[1][1], a12 = m[2][1];
    float a20 = m[0][2], a21 = m[1][2], a22 = m[2][2];

    float b01 = a22 * a11 - a12 * a21;
    float b11 = -a22 * a10 + a12 * a20;
    float b21 = a21 * a10 - a11 * a20;

    float det = a00 * b01 + a01 * b11 + a02 * b21;

    return Matrix3x3(Float3(b01, b11, b21),
                     Float3((-a22 * a01 + a02 * a21), (a22 * a00 - a02 * a20), (-a21 * a00 + a01 * a20)),
                     Float3((a12 * a01 - a02 * a11), (-a12 * a00 + a02 * a10), (a11 * a00 - a01 * a10))) / det;
}

Matrix3x3 Matrix3x3::translate(const Float2& translation)
{
    return Matrix3x3(Float3(1.0f, 0.0f, translation.x),
                     Float3(0.0f, 1.0f, translation.y),
                     Float3(0.0f, 0.0f, 1.0f));
}

Matrix3x3 Matrix3x3::scale(const Float3& scale)
{
    return Matrix3x3(Float3(scale.x, 0.0f, 0.0f),
                     Float3(0.0f, scale.y, 0.0f),
                     Float3(0.0f, 0.0f, scale.z));
}

Matrix3x3 Matrix3x3::rotate(float rotation)
{
    float c = std::cos(rotation);
    float s = std::sin(rotation);

    return Matrix3x3(Float3(c, -s, 0.0f),
                     Float3(s, c, 0.0f),
                     Float3(0.0f, 0.0f, 1.0f));
}

Matrix3x3 Matrix3x3::rotatex(float rotation)
{
    float c = std::cos(rotation);
    float s = std::sin(rotation);

    return Matrix3x3(Float3(1.0f, 0.0f, 0.0f),
                     Float3(0.0f, c, -s),
                     Float3(0.0f, s, c));
}

Matrix3x3 Matrix3x3::rotatey(float rotation)
{
    float c = std::cos(rotation);
    float s = std::sin(rotation);

    return Matrix3x3(Float3(c, 0.0f, s),
                     Float3(0.0f, 1.0f, 0.0f),
                     Float3(-s, 0.0f, c));
}

Matrix3x3 Matrix3x3::rotatez(float rotation)
{
    float c = std::cos(rotation);
    float s = std::sin(rotation);

    return Matrix3x3(Float3(c, -s, 0.0f),
                     Float3(s, c, 0.0f),
                     Float3(0.0f, 0.0f, 1.0f));
}

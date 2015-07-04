#include "math/matrix4x4.h"

#include "math/matrix3x3.h"

#include <cmath>

Matrix4x4::Matrix4x4()
{
    float *m[4] = {data[0], data[1], data[2], data[3]};

    m[0][0] = 1.0f; m[1][0] = 0.0f; m[2][0] = 0.0f; m[3][0] = 0.0f;
    m[0][1] = 0.0f; m[1][1] = 1.0f; m[2][1] = 0.0f; m[3][1] = 0.0f;
    m[0][2] = 0.0f; m[1][2] = 0.0f; m[2][2] = 1.0f; m[3][2] = 0.0f;
    m[0][3] = 0.0f; m[1][3] = 0.0f; m[2][3] = 0.0f; m[3][3] = 1.0f;
}

Matrix4x4::Matrix4x4(const Matrix3x3& other)
{
    data[0][0] = other[0][0];
    data[1][0] = other[1][0];
    data[2][0] = other[2][0];
    data[3][0] = 0.0f;

    data[0][1] = other[0][1];
    data[1][1] = other[1][1];
    data[2][1] = other[2][1];
    data[3][1] = 0.0f;

    data[0][2] = other[0][2];
    data[1][2] = other[1][2];
    data[2][2] = other[2][2];
    data[3][2] = 0.0f;

    data[0][3] = 0.0f;
    data[1][3] = 0.0f;
    data[2][3] = 0.0f;
    data[3][3] = 1.0f;
}

Matrix4x4::Matrix4x4(const Float4& row1,
                     const Float4& row2,
                     const Float4& row3,
                     const Float4& row4)
{
    data[0][0] = row1.x;
    data[0][1] = row1.y;
    data[0][2] = row1.z;
    data[0][3] = row1.w;

    data[1][0] = row2.x;
    data[1][1] = row2.y;
    data[1][2] = row2.z;
    data[1][3] = row2.w;

    data[2][0] = row3.x;
    data[2][1] = row3.y;
    data[2][2] = row3.z;
    data[2][3] = row3.w;

    data[3][0] = row4.x;
    data[3][1] = row4.y;
    data[3][2] = row4.z;
    data[3][3] = row4.w;
}

Matrix4x4 Matrix4x4::operator * (const Matrix4x4& other) const
{
    Matrix4x4 result;

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            float sum = 0.0f;

            for (int k = 0; k < 4; ++k)
            {
                sum += data[i][k] * other.data[k][j];
            }

            result.data[i][j] = sum;
        }
    }

    return result;
}

Float4 Matrix4x4::operator * (const Float4& other) const
{
    return Float4((*reinterpret_cast<const Float4 *>(data)*other).sum(),
                  (*reinterpret_cast<const Float4 *>(&data[1])*other).sum(),
                  (*reinterpret_cast<const Float4 *>(&data[2])*other).sum(),
                  (*reinterpret_cast<const Float4 *>(&data[3])*other).sum());
}

Matrix4x4 Matrix4x4::operator / (float other) const
{
    const float *m[4] = {data[0], data[1], data[2], data[3]};

    return Matrix4x4(Float4(m[0][0]/other, m[1][0]/other, m[2][0]/other, m[3][0]/other),
                     Float4(m[0][1]/other, m[1][1]/other, m[2][1]/other, m[3][1]/other),
                     Float4(m[0][2]/other, m[1][2]/other, m[2][2]/other, m[3][2]/other),
                     Float4(m[0][3]/other, m[1][3]/other, m[2][3]/other, m[3][3]/other));
}

Matrix4x4 Matrix4x4::transpose() const
{
    const float *m[4] = {data[0], data[1], data[2], data[3]};

    return Matrix4x4(Float4(m[0][0], m[0][1], m[0][2], m[0][3]),
                     Float4(m[1][0], m[1][1], m[1][2], m[1][3]),
                     Float4(m[2][0], m[2][1], m[2][2], m[2][3]),
                     Float4(m[3][0], m[3][1], m[3][2], m[3][3]));
}

Matrix4x4 Matrix4x4::inverse() const
{
    Matrix4x4 m = transpose();

    float
    a00 = m[0][0], a01 = m[0][1], a02 = m[0][2], a03 = m[0][3],
    a10 = m[1][0], a11 = m[1][1], a12 = m[1][2], a13 = m[1][3],
    a20 = m[2][0], a21 = m[2][1], a22 = m[2][2], a23 = m[2][3],
    a30 = m[3][0], a31 = m[3][1], a32 = m[3][2], a33 = m[3][3],

    b00 = a00 * a11 - a01 * a10,
    b01 = a00 * a12 - a02 * a10,
    b02 = a00 * a13 - a03 * a10,
    b03 = a01 * a12 - a02 * a11,
    b04 = a01 * a13 - a03 * a11,
    b05 = a02 * a13 - a03 * a12,
    b06 = a20 * a31 - a21 * a30,
    b07 = a20 * a32 - a22 * a30,
    b08 = a20 * a33 - a23 * a30,
    b09 = a21 * a32 - a22 * a31,
    b10 = a21 * a33 - a23 * a31,
    b11 = a22 * a33 - a23 * a32,

    det = b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06;

    return Matrix4x4(
          Float4(a11 * b11 - a12 * b10 + a13 * b09,
                  a02 * b10 - a01 * b11 - a03 * b09,
                  a31 * b05 - a32 * b04 + a33 * b03,
                  a22 * b04 - a21 * b05 - a23 * b03),
          Float4(a12 * b08 - a10 * b11 - a13 * b07,
                  a00 * b11 - a02 * b08 + a03 * b07,
                  a32 * b02 - a30 * b05 - a33 * b01,
                  a20 * b05 - a22 * b02 + a23 * b01),
          Float4(a10 * b10 - a11 * b08 + a13 * b06,
                  a01 * b08 - a00 * b10 - a03 * b06,
                  a30 * b04 - a31 * b02 + a33 * b00,
                  a21 * b02 - a20 * b04 - a23 * b00),
          Float4(a11 * b07 - a10 * b09 - a12 * b06,
                  a00 * b09 - a01 * b07 + a02 * b06,
                  a31 * b01 - a30 * b03 - a32 * b00,
                  a20 * b03 - a21 * b01 + a22 * b00)) / det;
}

Matrix4x4 Matrix4x4::translate(const Float3& translation)
{
    return Matrix4x4(Float4(1.0f, 0.0f, 0.0f, translation.x),
                     Float4(0.0f, 1.0f, 0.0f, translation.y),
                     Float4(0.0f, 0.0f, 1.0f, translation.z),
                     Float4(0.0f, 0.0f, 0.0f, 1.0f));
}

Matrix4x4 Matrix4x4::scale(const Float3& scale)
{
    return Matrix4x4(Float4(scale.x, 0.0f, 0.0f, 0.0f),
                     Float4(0.0f, scale.y, 0.0f, 0.0f),
                     Float4(0.0f, 0.0f, scale.z, 0.0f),
                     Float4(0.0f, 0.0f, 0.0f, 1.0f));
}

Matrix4x4 Matrix4x4::rotate(float rotation)
{
    float c = std::cos(rotation);
    float s = std::sin(rotation);

    return Matrix4x4(Float4(c, -s, 0.0f, 0.0f),
                     Float4(s, c, 0.0f, 0.0f),
                     Float4(0.0f, 0.0f, 1.0f, 0.0f),
                     Float4(0.0f, 0.0f, 0.0f, 1.0f));
}

Matrix4x4 Matrix4x4::rotatex(float rotation)
{
    float c = std::cos(rotation);
    float s = std::sin(rotation);

    return Matrix4x4(Float4(1.0f, 0.0f, 0.0f, 0.0f),
                     Float4(0.0f, c, -s, 0.0f),
                     Float4(0.0f, s, c, 0.0f),
                     Float4(0.0f, 0.0f, 0.0f, 1.0f));
}

Matrix4x4 Matrix4x4::rotatey(float rotation)
{
    float c = std::cos(rotation);
    float s = std::sin(rotation);

    return Matrix4x4(Float4(c, 0.0f, s, 0.0f),
                     Float4(0.0f, 1.0f, 0.0f, 0.0f),
                     Float4(-s, 0.0f, c, 0.0f),
                     Float4(0.0f, 0.0f, 0.0f, 1.0f));
}

Matrix4x4 Matrix4x4::rotatez(float rotation)
{
    float c = std::cos(rotation);
    float s = std::sin(rotation);

    return Matrix4x4(Float4(c, -s, 0.0f, 0.0f),
                     Float4(s, c, 0.0f, 0.0f),
                     Float4(0.0f, 0.0f, 1.0f, 0.0f),
                     Float4(0.0f, 0.0f, 0.0f, 1.0f));
}

Matrix4x4 Matrix4x4::perspective(float fov, float aspect, float near, float far)
{
    float e = std::tan(M_PI_2 - fov / 2.0f);

    float fpn = far + near;
    float fmn = far - near;

    return Matrix4x4(Float4(e/aspect, 0.0, 0.0f, 0.0f),
                     Float4(0.0f, e, 0.0f, 0.0f),
                     Float4(0.0f, 0.0f, -(fpn / fmn), -((2.0f * far * near)/fmn)),
                     Float4(0.0f, 0.0f, -1.0f, 0.0f));
}

Matrix4x4 Matrix4x4::orthographic(float left,
                                  float right,
                                  float bottom,
                                  float top,
                                  float near,
                                  float far)
{
    float tx = (right+left) / (right-left);
    float ty = (top+bottom) / (top-bottom);
    float tz = (far+near) / (far-near);

    return Matrix4x4(Float4(2.0f/(right-left), 0.0f, 0.0f, tx),
                     Float4(0.0f, 2.0f/(top-bottom), 0.0f, ty),
                     Float4(0.0f, 0.0f, -2.0f/(far-near), tz),
                     Float4(0.0f, 0.0f, 0.0f, 1.0f));
}

Matrix4x4 Matrix4x4::lookAt(const Position3D& eye,
                            const Position3D& center,
                            const Direction3D& up)
{
    return lookAtDir(eye, center - eye, up);
}

Matrix4x4 Matrix4x4::lookAtDir(const Position3D& eye,
                               const Direction3D& dir,
                               const Direction3D& up)
{
    Direction3D up_ = up.normalize();

    Float3 f = dir.normalize();

    Float3 s = f.cross(up_);
    Float3 u = s.normalize().cross(f);

    return Matrix4x4(Float4(s.x, s.y, s.z, -s.dot(eye)),
                     Float4(u.x, u.y, u.z, -u.dot(eye)),
                     Float4(-f.x, -f.y, -f.z, f.dot(eye)),
                     Float4(0.0f, 0.0f, 0.0f, 1.0f));
}

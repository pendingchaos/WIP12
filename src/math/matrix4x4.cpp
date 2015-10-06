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
    Matrix4x4 result(0);

    /*for (int i = 0; i < 4; ++i)
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
    }*/

    result.data[0][0] = data[0][0] * other.data[0][0] + data[0][1] * other.data[1][0] + data[0][2] * other.data[2][0] + data[0][3] * other.data[3][0];
    result.data[0][1] = data[0][0] * other.data[0][1] + data[0][1] * other.data[1][1] + data[0][2] * other.data[2][1] + data[0][3] * other.data[3][1];
    result.data[0][2] = data[0][0] * other.data[0][2] + data[0][1] * other.data[1][2] + data[0][2] * other.data[2][2] + data[0][3] * other.data[3][2];
    result.data[0][3] = data[0][0] * other.data[0][3] + data[0][1] * other.data[1][3] + data[0][2] * other.data[2][3] + data[0][3] * other.data[3][3];

    result.data[1][0] = data[1][0] * other.data[0][0] + data[1][1] * other.data[1][0] + data[1][2] * other.data[2][0] + data[1][3] * other.data[3][0];
    result.data[1][1] = data[1][0] * other.data[0][1] + data[1][1] * other.data[1][1] + data[1][2] * other.data[2][1] + data[1][3] * other.data[3][1];
    result.data[1][2] = data[1][0] * other.data[0][2] + data[1][1] * other.data[1][2] + data[1][2] * other.data[2][2] + data[1][3] * other.data[3][2];
    result.data[1][3] = data[1][0] * other.data[0][3] + data[1][1] * other.data[1][3] + data[1][2] * other.data[2][3] + data[1][3] * other.data[3][3];

    result.data[2][0] = data[2][0] * other.data[0][0] + data[2][1] * other.data[1][0] + data[2][2] * other.data[2][0] + data[2][3] * other.data[3][0];
    result.data[2][1] = data[2][0] * other.data[0][1] + data[2][1] * other.data[1][1] + data[2][2] * other.data[2][1] + data[2][3] * other.data[3][1];
    result.data[2][2] = data[2][0] * other.data[0][2] + data[2][1] * other.data[1][2] + data[2][2] * other.data[2][2] + data[2][3] * other.data[3][2];
    result.data[2][3] = data[2][0] * other.data[0][3] + data[2][1] * other.data[1][3] + data[2][2] * other.data[2][3] + data[2][3] * other.data[3][3];

    result.data[3][0] = data[3][0] * other.data[0][0] + data[3][1] * other.data[1][0] + data[3][2] * other.data[2][0] + data[3][3] * other.data[3][0];
    result.data[3][1] = data[3][0] * other.data[0][1] + data[3][1] * other.data[1][1] + data[3][2] * other.data[2][1] + data[3][3] * other.data[3][1];
    result.data[3][2] = data[3][0] * other.data[0][2] + data[3][1] * other.data[1][2] + data[3][2] * other.data[2][2] + data[3][3] * other.data[3][2];
    result.data[3][3] = data[3][0] * other.data[0][3] + data[3][1] * other.data[1][3] + data[3][2] * other.data[2][3] + data[3][3] * other.data[3][3];

    return result;
}

Float4 Matrix4x4::operator * (const Float4& other) const
{
    return Float4(reinterpret_cast<const Float4 *>(data)->dot(other),
                  reinterpret_cast<const Float4 *>(&data[1])->dot(other),
                  reinterpret_cast<const Float4 *>(&data[2])->dot(other),
                  reinterpret_cast<const Float4 *>(&data[3])->dot(other));
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

    return Matrix4x4(Float4(m[0][0], m[1][0], m[2][0], m[3][0]),
                     Float4(m[0][1], m[1][1], m[2][1], m[3][1]),
                     Float4(m[0][2], m[1][2], m[2][2], m[3][2]),
                     Float4(m[0][3], m[1][3], m[2][3], m[3][3]));
}

float Matrix4x4::determinant() const
{
    Matrix4x4 c = transpose();

    return c[0][3]*c[1][2]*c[2][1]*c[3][0] - c[0][2]*c[1][3]*c[2][1]*c[3][0] - c[0][3]*c[1][1]*c[2][2]*c[3][0] + c[0][1]*c[1][3]*c[2][2]*c[3][0] +
           c[0][2]*c[1][1]*c[2][3]*c[3][0] - c[0][1]*c[1][2]*c[2][3]*c[3][0] - c[0][3]*c[1][2]*c[2][0]*c[3][1] + c[0][2]*c[1][3]*c[2][0]*c[3][1] +
           c[0][3]*c[1][0]*c[2][2]*c[3][1] - c[0][0]*c[1][3]*c[2][2]*c[3][1] - c[0][2]*c[1][0]*c[2][3]*c[3][1] + c[0][0]*c[1][2]*c[2][3]*c[3][1] +
           c[0][3]*c[1][1]*c[2][0]*c[3][2] - c[0][1]*c[1][3]*c[2][0]*c[3][2] - c[0][3]*c[1][0]*c[2][1]*c[3][2] + c[0][0]*c[1][3]*c[2][1]*c[3][2] +
           c[0][1]*c[1][0]*c[2][3]*c[3][2] - c[0][0]*c[1][1]*c[2][3]*c[3][2] - c[0][2]*c[1][1]*c[2][0]*c[3][3] + c[0][1]*c[1][2]*c[2][0]*c[3][3] +
           c[0][2]*c[1][0]*c[2][1]*c[3][3] - c[0][0]*c[1][2]*c[2][1]*c[3][3] - c[0][1]*c[1][0]*c[2][2]*c[3][3] + c[0][0]*c[1][1]*c[2][2]*c[3][3];
}

Matrix4x4 Matrix4x4::inverse() const
{
    float d = determinant();

    if(d == 0.0f)
    {
        return Matrix4x4();
    }

    d = 1.0f / d;

    Matrix4x4 c = transpose();

    Matrix4x4 m;
    m[0][0] = d * (c[1][2]*c[2][3]*c[3][1] - c[1][3]*c[2][2]*c[3][1] + c[1][3]*c[2][1]*c[3][2] - c[1][1]*c[2][3]*c[3][2] - c[1][2]*c[2][1]*c[3][3] + c[1][1]*c[2][2]*c[3][3]);
    m[0][1] = d * (c[0][3]*c[2][2]*c[3][1] - c[0][2]*c[2][3]*c[3][1] - c[0][3]*c[2][1]*c[3][2] + c[0][1]*c[2][3]*c[3][2] + c[0][2]*c[2][1]*c[3][3] - c[0][1]*c[2][2]*c[3][3]);
    m[0][2] = d * (c[0][2]*c[1][3]*c[3][1] - c[0][3]*c[1][2]*c[3][1] + c[0][3]*c[1][1]*c[3][2] - c[0][1]*c[1][3]*c[3][2] - c[0][2]*c[1][1]*c[3][3] + c[0][1]*c[1][2]*c[3][3]);
    m[0][3] = d * (c[0][3]*c[1][2]*c[2][1] - c[0][2]*c[1][3]*c[2][1] - c[0][3]*c[1][1]*c[2][2] + c[0][1]*c[1][3]*c[2][2] + c[0][2]*c[1][1]*c[2][3] - c[0][1]*c[1][2]*c[2][3]);
    m[1][0] = d * (c[1][3]*c[2][2]*c[3][0] - c[1][2]*c[2][3]*c[3][0] - c[1][3]*c[2][0]*c[3][2] + c[1][0]*c[2][3]*c[3][2] + c[1][2]*c[2][0]*c[3][3] - c[1][0]*c[2][2]*c[3][3]);
    m[1][1] = d * (c[0][2]*c[2][3]*c[3][0] - c[0][3]*c[2][2]*c[3][0] + c[0][3]*c[2][0]*c[3][2] - c[0][0]*c[2][3]*c[3][2] - c[0][2]*c[2][0]*c[3][3] + c[0][0]*c[2][2]*c[3][3]);
    m[1][2] = d * (c[0][3]*c[1][2]*c[3][0] - c[0][2]*c[1][3]*c[3][0] - c[0][3]*c[1][0]*c[3][2] + c[0][0]*c[1][3]*c[3][2] + c[0][2]*c[1][0]*c[3][3] - c[0][0]*c[1][2]*c[3][3]);
    m[1][3] = d * (c[0][2]*c[1][3]*c[2][0] - c[0][3]*c[1][2]*c[2][0] + c[0][3]*c[1][0]*c[2][2] - c[0][0]*c[1][3]*c[2][2] - c[0][2]*c[1][0]*c[2][3] + c[0][0]*c[1][2]*c[2][3]);
    m[2][0] = d * (c[1][1]*c[2][3]*c[3][0] - c[1][3]*c[2][1]*c[3][0] + c[1][3]*c[2][0]*c[3][1] - c[1][0]*c[2][3]*c[3][1] - c[1][1]*c[2][0]*c[3][3] + c[1][0]*c[2][1]*c[3][3]);
    m[2][1] = d * (c[0][3]*c[2][1]*c[3][0] - c[0][1]*c[2][3]*c[3][0] - c[0][3]*c[2][0]*c[3][1] + c[0][0]*c[2][3]*c[3][1] + c[0][1]*c[2][0]*c[3][3] - c[0][0]*c[2][1]*c[3][3]);
    m[2][2] = d * (c[0][1]*c[1][3]*c[3][0] - c[0][3]*c[1][1]*c[3][0] + c[0][3]*c[1][0]*c[3][1] - c[0][0]*c[1][3]*c[3][1] - c[0][1]*c[1][0]*c[3][3] + c[0][0]*c[1][1]*c[3][3]);
    m[2][3] = d * (c[0][3]*c[1][1]*c[2][0] - c[0][1]*c[1][3]*c[2][0] - c[0][3]*c[1][0]*c[2][1] + c[0][0]*c[1][3]*c[2][1] + c[0][1]*c[1][0]*c[2][3] - c[0][0]*c[1][1]*c[2][3]);
    m[3][0] = d * (c[1][2]*c[2][1]*c[3][0] - c[1][1]*c[2][2]*c[3][0] - c[1][2]*c[2][0]*c[3][1] + c[1][0]*c[2][2]*c[3][1] + c[1][1]*c[2][0]*c[3][2] - c[1][0]*c[2][1]*c[3][2]);
    m[3][1] = d * (c[0][1]*c[2][2]*c[3][0] - c[0][2]*c[2][1]*c[3][0] + c[0][2]*c[2][0]*c[3][1] - c[0][0]*c[2][2]*c[3][1] - c[0][1]*c[2][0]*c[3][2] + c[0][0]*c[2][1]*c[3][2]);
    m[3][2] = d * (c[0][2]*c[1][1]*c[3][0] - c[0][1]*c[1][2]*c[3][0] - c[0][2]*c[1][0]*c[3][1] + c[0][0]*c[1][2]*c[3][1] + c[0][1]*c[1][0]*c[3][2] - c[0][0]*c[1][1]*c[3][2]);
    m[3][3] = d * (c[0][1]*c[1][2]*c[2][0] - c[0][2]*c[1][1]*c[2][0] + c[0][2]*c[1][0]*c[2][1] - c[0][0]*c[1][2]*c[2][1] - c[0][1]*c[1][0]*c[2][2] + c[0][0]*c[1][1]*c[2][2]);

    return m.transpose();
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

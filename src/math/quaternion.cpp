#include "math/quaternion.h"

Quaternion::Quaternion() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}

Quaternion::Quaternion(const Direction3D& axis, float angle)
{
    setAxisAndAngle(axis, angle);
}

Quaternion::Quaternion(float x_,
                       float y_,
                       float z_,
                       float w_) : x(x_), y(y_), z(z_), w(w_) {}

Quaternion::Quaternion(const Float3& angles)
{
    setEulerAngles(angles);
}

Quaternion Quaternion::operator * (const Quaternion& other) const
{
    float nw = w * other.w - x * other.x - y * other.y - z * other.z;
    float nx = w * other.x + x * other.w + y * other.z - z * other.y;
    float ny = w * other.y + y * other.w + z * other.x - x * other.z;
    float nz = w * other.z + z * other.w + x * other.y - y * other.x;

    return Quaternion(nx, ny, nz, nw);
}

Matrix4x4 Quaternion::toMatrix() const
{
    float xx = x * x;
    float xy = x * y;
    float xz = x * z;
    float xw = x * w;

    float yy = y * y;
    float yz = y * z;
    float yw = y * w;

    float zz = z * z;
    float zw = z * w;

    return Matrix4x4(Float4(1.0f - 2.0f*yy - 2.0f*zz, 2.0f*xy - 2.0f*zw, 2.0f*xz + 2.0f*yw, 0.0f),
                     Float4(2.0f*xy + 2.0f*zw, 1.0f - 2.0f*xx - 2.0f*zz, 2.0f*yz - 2.0f*xw, 0.0f),
                     Float4(2.0f*xz - 2.0f*yw, 2.0f*yz + 2.0f*xw, 1.0f - 2.0f*xx - 2.0f*yy, 0.0f),
                     Float4(0.0f, 0.0f, 0.0f, 1.0f));
}

Float4 Quaternion::getAxisAndAngle() const
{
    float ha = std::acos(w);
    float sha = std::sin(ha);

    return Float4(x / sha, y / sha, z / sha, ha*2.0f);
}

void Quaternion::setAxis(const Direction3D& axis)
{
    Direction3D axis_ = axis.normalize();

    float sha = std::sin(std::acos(w));

    x = axis_.x * sha;
    y = axis_.y * sha;
    z = axis_.z * sha;
}

void Quaternion::setAxisAndAngle(const Direction3D& axis, float angle)
{
    Direction3D axis_ = axis.normalize();

    float sha = std::sin(angle / 2.0f);

    x = axis_.x * sha;
    y = axis_.y * sha;
    z = axis_.z * sha;
    w = std::cos(angle / 2.0f);
}

void Quaternion::setEulerAngles(const Float3& angles)
{
    float cx = std::cos(angles.x / 2.0f);
    float cy = std::cos(angles.y / 2.0f);
    float cz = std::cos(angles.z / 2.0f);
    float sx = std::sin(angles.x / 2.0f);
    float sy = std::sin(angles.y / 2.0f);
    float sz = std::sin(angles.z / 2.0f);

    x = sx * cy * cz - cx * sy * sz;
    y = cx * sy * cz + sx * cy * sz;
    z = cx * cy * sz - sx * sy * cz;
    w = cx * cy * cz + sx * sy * sz;
}

Float3 Quaternion::getEulerAngles()
{
    return Float3(std::atan2(2.0f * (w*x + y*z), 1.0f-2.0f*(x*x + y*y)),
                  std::asin(2.0f * (w*y - z*x)),
                  std::atan2(2.0f * (w*z + x*y), 1.0f-2.0f*(y*y + z*z)));
}

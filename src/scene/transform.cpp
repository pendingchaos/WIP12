#include "scene/transform.h"

Transform::Transform() : scale(1.0f) {}

//TODO: This does not work when dot is negative
/*void Transform::lookAt(Position3D target, Direction3D up, Direction3D forward)
{
    Vector3D newForward = (target - position).normalize();

    float dot = forward.dot(newForward);

    if (std::abs(dot + 1.0f) < 0.000001f)
    {
        orientation = Quaternion(up, RADIANS(180.0f));
        return;
    } else if (std::abs(dot - 1.0f) < 0.000001f)
    {
        orientation = Quaternion();
        return;
    }

    orientation = Quaternion(forward.cross(newForward).normalize(), std::acos(dot));
}*/

Matrix4x4 Transform::createMatrix() const
{
    bool rotate = (std::abs(orientation.x) > 0.001f or
                   std::abs(orientation.y) > 0.001f or
                   std::abs(orientation.z) > 0.001f) and
                   std::abs(1.0f-orientation.w) > 0.001f;

    Matrix4x4 result = rotate ? (Matrix4x4::translate(position) * orientation.toMatrix()) : Matrix4x4::translate(position);
    result.multScale(scale);
    return result;
}

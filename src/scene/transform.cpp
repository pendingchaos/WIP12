#include "scene/transform.h"

Transform::Transform() : scale(1.0f) {}

Matrix4x4 Transform::createMatrix() const
{
    return Matrix4x4::translate(position) *
           orientation.toMatrix() *
           Matrix4x4::scale(scale);
}

#include "graphics/camera.h"

#include "misc_macros.h"

Camera::Camera() : position(0.0f),
                   direction(0.0f, 0.0f, 1.0f),
                   up(0.0f, 1.0f, 0.0f),
                   near(0.1f),
                   far(100.0f)
{
    setType(Perspective);

    createViewMatrix();
    createProjectionMatrix();
}

void Camera::setType(Type type_)
{
    type = type_;

    switch (type)
    {
    case Perspective:
    {
        perspective.width = 1.0f;
        perspective.height = 1.0f;
        perspective.fov = 60.0f;
        break;
    }
    case Orthographic:
    {
        orthographic.left = -1.0f;
        orthographic.right = 1.0f;
        orthographic.bottom = -1.0f;
        orthographic.top = 1.0f;
        break;
    }
    }

    createProjectionMatrix();
}

void Camera::setPosition(const Position3D& position_)
{
    position = position_;

    createViewMatrix();
}

void Camera::setDirection(const Direction3D& direction_)
{
    direction = direction_.normalize();

    createViewMatrix();
}

void Camera::setUp(const Direction3D& up_)
{
    up = up_.normalize();

    createViewMatrix();
}

void Camera::setWidth(float width)
{
    if (type == Perspective)
    {
        perspective.width = width;

        createProjectionMatrix();
    }
}

void Camera::setHeight(float height)
{
    if (type == Perspective)
    {
        perspective.height = height;

        createProjectionMatrix();
    }
}

void Camera::setFieldOfView(float fov)
{
    if (type == Perspective)
    {
        perspective.fov = fov;

        createProjectionMatrix();
    }
}

void Camera::setLeft(float left)
{
    if (type == Orthographic)
    {
        orthographic.left = left;

        createProjectionMatrix();
    }
}

void Camera::setRight(float right)
{
    if (type == Orthographic)
    {
        orthographic.right = right;

        createProjectionMatrix();
    }
}

void Camera::setBottom(float bottom)
{
    if (type == Orthographic)
    {
        orthographic.bottom = bottom;

        createProjectionMatrix();
    }
}

void Camera::setTop(float top)
{
    if (type == Orthographic)
    {
        orthographic.top = top;

        createProjectionMatrix();
    }
}

void Camera::setNear(float near_)
{
    near = near_;

    createProjectionMatrix();
}

void Camera::setFar(float far_)
{
    far = far_;

    createProjectionMatrix();
}

void Camera::createViewMatrix()
{
    Position3D target = position + direction;

    viewMatrix = Matrix4x4::lookAt(position, target, up);
}

void Camera::createProjectionMatrix()
{
    switch (type)
    {
    case Perspective:
    {
        projectionMatrix = Matrix4x4::perspective(RADIANS(perspective.fov),
                                                  perspective.width/perspective.height,
                                                  near,
                                                  far);
        break;
    }
    case Orthographic:
    {
        projectionMatrix = Matrix4x4::orthographic(orthographic.left,
                                                   orthographic.right,
                                                   orthographic.bottom,
                                                   orthographic.top,
                                                   near,
                                                   far);
        break;
    }
    }
}

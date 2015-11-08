#include "graphics/camera.h"

#include "misc_macros.h"

#include <SDL2/SDL_assert.h>

Camera::Camera() : position(0.0f),
                   direction(0.0f, 0.0f, 1.0f),
                   up(0.0f, 1.0f, 0.0f),
                   near(0.1f),
                   far(100.0f)
{
    setType(CameraType::Perspective);

    createViewMatrix();
    createProjectionMatrix();
    createFrustum();
}

void Camera::setType(CameraType type_)
{
    type = type_;

    switch (type)
    {
    case CameraType::Perspective:
    {
        perspective.width = 1.0f;
        perspective.height = 1.0f;
        perspective.fov = 60.0f;
        break;
    }
    case CameraType::Orthographic:
    {
        orthographic.left = -1.0f;
        orthographic.right = 1.0f;
        orthographic.bottom = -1.0f;
        orthographic.top = 1.0f;
        break;
    }
    case CameraType::Matrices: {break;}
    default: {SDL_assert(false);}
    }

    createProjectionMatrix();
    createFrustum();
}

void Camera::setPosition(const Position3D& position_)
{
    position = position_;

    createViewMatrix();
    createFrustum();
}

void Camera::setDirection(const Direction3D& direction_)
{
    direction = direction_.normalize();

    createViewMatrix();
    createFrustum();
}

void Camera::setUp(const Direction3D& up_)
{
    up = up_.normalize();

    createViewMatrix();
    createFrustum();
}

void Camera::setWidth(float width)
{
    if (type == CameraType::Perspective)
    {
        perspective.width = width;

        createProjectionMatrix();
        createFrustum();
    }
}

void Camera::setHeight(float height)
{
    if (type == CameraType::Perspective)
    {
        perspective.height = height;

        createProjectionMatrix();
        createFrustum();
    }
}

void Camera::setFieldOfView(float fov)
{
    if (type == CameraType::Perspective)
    {
        perspective.fov = fov;

        createProjectionMatrix();
        createFrustum();
    }
}

void Camera::setLeft(float left)
{
    if (type == CameraType::Orthographic)
    {
        orthographic.left = left;

        createProjectionMatrix();
        createFrustum();
    }
}

void Camera::setRight(float right)
{
    if (type == CameraType::Orthographic)
    {
        orthographic.right = right;

        createProjectionMatrix();
        createFrustum();
    }
}

void Camera::setBottom(float bottom)
{
    if (type == CameraType::Orthographic)
    {
        orthographic.bottom = bottom;

        createProjectionMatrix();
        createFrustum();
    }
}

void Camera::setTop(float top)
{
    if (type == CameraType::Orthographic)
    {
        orthographic.top = top;

        createProjectionMatrix();
        createFrustum();
    }
}

void Camera::setNear(float near_)
{
    near = near_;

    createProjectionMatrix();
    createFrustum();
}

void Camera::setFar(float far_)
{
    far = far_;

    createProjectionMatrix();
    createFrustum();
}

void Camera::setViewMatrix(const Matrix4x4& mat)
{
    if (type == CameraType::Matrices)
    {
        viewMatrix = mat;
    }
}

void Camera::setProjectionMatrix(const Matrix4x4& mat)
{
    if (type == CameraType::Matrices)
    {
        projectionMatrix = mat;
    }
}

void Camera::createViewMatrix()
{
    if (type != CameraType::Matrices)
    {
        Position3D target = position + direction;
        viewMatrix = Matrix4x4::lookAt(position, target, up);
    }
}

void Camera::createProjectionMatrix()
{
    switch (type)
    {
    case CameraType::Perspective:
    {
        projectionMatrix = Matrix4x4::perspective(RADIANS(perspective.fov),
                                                  perspective.width/perspective.height,
                                                  near,
                                                  far);
        break;
    }
    case CameraType::Orthographic:
    {
        projectionMatrix = Matrix4x4::orthographic(orthographic.left,
                                                   orthographic.right,
                                                   orthographic.bottom,
                                                   orthographic.top,
                                                   near,
                                                   far);
        break;
    }
    case CameraType::Matrices: {break;}
    default: {SDL_assert(false);}
    }
}

void Camera::createFrustum()
{
    switch (type)
    {
    case CameraType::Perspective:
    {
        frustum = Frustum::view(viewMatrix.inverse(),
                                perspective.fov,
                                perspective.width/perspective.height,
                                near,
                                far);
        break;
    }
    case CameraType::Orthographic:
    {
        frustum = Frustum::view(viewMatrix.inverse(),
                                orthographic.left,
                                orthographic.right,
                                orthographic.bottom,
                                orthographic.top,
                                near,
                                far);
        break;
    }
    case CameraType::Matrices:
    {
        break;
        //TODO
    }
    default: {SDL_assert(false);}
    }
}

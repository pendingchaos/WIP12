#ifndef CAMERA_H
#define CAMERA_H

#include "math/t3.h"
#include "math/matrix4x4.h"
#include "math/frustum.h"
#include "scripting/bindings.h"

enum class CameraType
{
    Perspective,
    Orthographic,
    Matrices
} BIND ENUM_CLASS;

class Camera
{
    public:
        Camera();

        void setType(CameraType type);

        void setPosition(const Position3D& position);
        void setDirection(const Direction3D& direction);
        void setUp(const Direction3D& up);

        void setWidth(float width);
        void setHeight(float height);
        void setFieldOfView(float fov);

        void setLeft(float left);
        void setRight(float right);
        void setBottom(float bottom);
        void setTop(float top);

        void setNear(float near);
        void setFar(float far);

        void setViewMatrix(const Matrix4x4& mat);
        void setProjectionMatrix(const Matrix4x4& mat);

        CameraType getType() const
        {
            return type;
        }

        Position3D getPosition() const
        {
            return position;
        }

        Direction3D getDirection() const
        {
            return direction;
        }

        Direction3D getUp() const
        {
            return up;
        }

        float getWidth() const
        {
            return perspective.width;
        }

        float getHeight() const
        {
            return perspective.height;
        }

        float getFieldOfView() const
        {
            return perspective.fov;
        }

        float getLeft() const
        {
            return orthographic.left;
        }

        float getRight() const
        {
            return orthographic.right;
        }

        float getBottom() const
        {
            return orthographic.bottom;
        }

        float getTop() const
        {
            return orthographic.top;
        }

        float getNear() const
        {
            return near;
        }

        float getFar() const
        {
            return far;
        }

        Matrix4x4 getViewMatrix() const
        {
            return viewMatrix;
        }

        Matrix4x4 getProjectionMatrix() const
        {
            return projectionMatrix;
        }

        Frustum getFrustum() const
        {
            return frustum;
        }
    private:
        Matrix4x4 viewMatrix;
        Matrix4x4 projectionMatrix;
        Frustum frustum;

        CameraType type;

        Position3D position;
        Direction3D direction;
        Direction3D up;

        union
        {
            struct
            {
                float width;
                float height;
                float fov;
            } perspective;
            struct
            {
                float left;
                float right;
                float bottom;
                float top;
            } orthographic;
        };

        float near;
        float far;

        void createViewMatrix();
        void createProjectionMatrix();
        void createFrustum();
} BIND;

#endif // CAMERA_H

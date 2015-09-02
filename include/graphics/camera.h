#ifndef CAMERA_H
#define CAMERA_H

#include "math/t3.h"
#include "math/matrix4x4.h"
#include "scripting/bindings.h"

class Camera
{
    public:
        enum Type
        {
            Perspective,
            Orthographic
        };

        Camera();

        void setType(Camera::Type type) NO_BIND;

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

        inline Camera::Type getType() const NO_BIND
        {
            return type;
        }

        inline Position3D getPosition() const
        {
            return position;
        }

        inline Direction3D getDirection() const
        {
            return direction;
        }

        inline Direction3D getUp() const
        {
            return up;
        }

        inline float getWidth() const
        {
            return perspective.width;
        }

        inline float getHeight() const
        {
            return perspective.height;
        }

        inline float getFieldOfView() const
        {
            return perspective.fov;
        }

        inline float getLeft() const
        {
            return orthographic.left;
        }

        inline float getRight() const
        {
            return orthographic.right;
        }

        inline float getBottom() const
        {
            return orthographic.bottom;
        }

        inline float getTop() const
        {
            return orthographic.top;
        }

        inline float getNear() const
        {
            return near;
        }

        inline float getFar() const
        {
            return far;
        }

        inline Matrix4x4 getViewMatrix() const
        {
            return viewMatrix;
        }

        inline Matrix4x4 getProjectionMatrix() const
        {
            return projectionMatrix;
        }
    private:
        Matrix4x4 viewMatrix;
        Matrix4x4 projectionMatrix;

        Type type;

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
} BIND;

#endif // CAMERA_H

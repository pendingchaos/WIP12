#include <cmath>

BEGIN_SCRIPT
    virtual void init()
    {
        angle = Float2(M_PI, 0.0f);
        speed = 5.0f;
        rotateSpeed = 0.5f;
        zoom = 1.0f;
        maximumVelocity = 12.0f;
        maxAngularVelocity = 0.5f;

        entity->getRigidBody()->setAngularFactor(Float3(0.0f));
    }

    virtual void fixedUpdate(float timestep)
    {
        Camera& camera = entity->getScene()->camera;

        RigidBody *body = entity->getRigidBody();

        Vector3D dir(std::cos(angle.y) * std::sin(angle.x),
                     std::sin(angle.y),
                     std::cos(angle.y) * std::cos(angle.x));

        camera.setDirection(dir);

        Vector3D right(std::sin(angle.x - 3.1415f / 2.0f),
                       0.0f,
                       std::cos(angle.x - 3.1415f / 2.0f));

        camera.setUp(right.cross(dir));

        float resSpeed = speed;

        if (platform->isKeyPressed(Platform::Space))
        {
            resSpeed *= 2.0f;
        }

        if (platform->isKeyPressed(Platform::LeftShift))
        {
            resSpeed /= 2.0f;
        }

        Vector3D moveDir(std::sin(angle.x),
                         0.0f,
                         std::cos(angle.x));

        Vector3D velocity;

        if (platform->isKeyPressed(Platform::A))
        {
            velocity -= right * platform->getFrametime() * resSpeed;
        }

        if (platform->isKeyPressed(Platform::D))
        {
            velocity += right * platform->getFrametime() * resSpeed;
        }

        if (platform->isKeyPressed(Platform::W))
        {
            velocity += dir * platform->getFrametime() * resSpeed;
        }

        if (platform->isKeyPressed(Platform::S))
        {
            velocity -= dir * platform->getFrametime() * resSpeed;
        }

        //Modify the velocity so it does not make it go over the max.
        Vector3D oldVelocity = body->getLinearVelocity();
        Vector3D newVelocity = oldVelocity + velocity;

        if (newVelocity.x > maximumVelocity)
        {
            velocity.x -= newVelocity.x - maximumVelocity;
        } else if (newVelocity.x < -maximumVelocity)
        {
            velocity.x += std::abs(newVelocity.x) - maximumVelocity;
        }

        if (newVelocity.z > maximumVelocity)
        {
            velocity.z -= newVelocity.z - maximumVelocity;
        } else if (newVelocity.z < -maximumVelocity)
        {
            velocity.z += std::abs(newVelocity.z) - maximumVelocity;
        }
        //End of velocity modification.

        body->setLinearVelocity(oldVelocity + velocity);

        if (platform->isLeftMouseButtonPressed())
        {
            platform->setCursorVisible(false);

            float w = platform->getWindowWidth();
            float h = platform->getWindowHeight();
            Float2 pos = platform->getMousePosition();

            platform->setMousePosition(Int2(w/2.0f, h/2.0f));

            angularVelocity.x += rotateSpeed * platform->getFrametime() * (w / 2.0f - pos.x) / 4.0f;
            angularVelocity.y += rotateSpeed * platform->getFrametime() * (h / 2.0f - pos.y) / 4.0f;
        } else
        {
            platform->setCursorVisible(true);
        }

        angularVelocity.x = std::min(angularVelocity.x, maxAngularVelocity);
        angularVelocity.y = std::min(angularVelocity.y, maxAngularVelocity);

        angularVelocity.x = std::max(angularVelocity.x, -maxAngularVelocity);
        angularVelocity.y = std::max(angularVelocity.y, -maxAngularVelocity);

        angle += angularVelocity;

        if (angle.y < -3.1415f / 2.0f)
        {
            angle.y = -3.1415f / 2.0f;
        }

        if (angle.y > 3.1415f / 2.0f)
        {
            angle.y = 3.1415f / 2.0f;
        }

        zoom = std::max(std::min(zoom, 1.7f), 0.3f);

        camera.setFieldOfView(zoom * 50.0f);

        angularVelocity -= angularVelocity * platform->getFrametime() * 15.0f;

        camera.setPosition(entity->transform.position+Position3D(0.0f, 1.5f, 0.0f));
    }

    Float2 angle;
    float speed;
    float rotateSpeed;
    float zoom;
    Float2 angularVelocity;
    float maximumVelocity;
    float maxAngularVelocity;
END_SCRIPT

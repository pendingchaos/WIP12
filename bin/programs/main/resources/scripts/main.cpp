#include <cmath>

class FPSCamera
{
    public:
        FPSCamera() : position(-4.0f, 4.0f, 4.0f),
                      angle(3.1415f, 0.0f),
                      speed(3.0f),
                      rotateSpeed(0.5f),
                      zoom(1.0f),
                      maximumVelocity(12.0f),
                      maxAngularVelocity(0.5f) {}

        void update(Camera& camera)
        {
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
                resSpeed *= 4.0f;
            }

            if (platform->isKeyPressed(Platform::LeftShift))
            {
                resSpeed /= 4.0f;
            }

            /*if (platform->isKeyPressed(Platform::Left))
            {
                angularVelocity.x += rotateSpeed * platform->getFrametime();
            }

            if (platform->isKeyPressed(Platform::Right))
            {
                angularVelocity.x -= rotateSpeed * platform->getFrametime();
            }

            if (platform->isKeyPressed(Platform::Up))
            {
                angularVelocity.y += rotateSpeed * platform->getFrametime();
            }

            if (platform->isKeyPressed(Platform::Down))
            {
                angularVelocity.y -= rotateSpeed * platform->getFrametime();
            }*/

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

            velocity.x = std::min(velocity.x, maximumVelocity);
            velocity.y = std::min(velocity.y, maximumVelocity);
            velocity.z = std::min(velocity.z, maximumVelocity);

            velocity.x = std::max(velocity.x, -maximumVelocity);
            velocity.y = std::max(velocity.y, -maximumVelocity);
            velocity.z = std::max(velocity.z, -maximumVelocity);

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

            position += velocity;

            velocity -= velocity * platform->getFrametime() * 5.0f;
            angularVelocity -= angularVelocity * platform->getFrametime() * 15.0f;

            camera.setPosition(position);
        }

        Position3D position;
        Float2 angle;
        float speed;
        float rotateSpeed;
        float zoom;
        Vector3D velocity;
        Float2 angularVelocity;
        float maximumVelocity;
        float maxAngularVelocity;
};

BEGIN_SCRIPT
    ResPtr<Scene> scene;
    FPSCamera cam;

    virtual void init()
    {
        scene = resMgr->getResourceByFilename<Scene>("resources/scenes/scene.bin");
    }

    virtual void handleInput()
    {
        Platform::Event event;

        while (platform->pollEvent(event))
        {
            switch (event.type)
            {
            case Platform::Event::Quit:
            {
                app->running = false;
                break;
            }
            case Platform::Event::MouseWheel:
            {
                float zoomSpeed = 4.0f;

                if (platform->isKeyPressed(Platform::Space))
                {
                    zoomSpeed *= 4.0f;
                }

                if (platform->isKeyPressed(Platform::LeftShift))
                {
                    zoomSpeed /= 4.0f;
                }

                cam.zoom += -event.mouseWheel.relativeY * zoomSpeed * platform->getFrametime();

                break;
            }
            case Platform::Event::KeyDown:
            {
                switch (event.key.key)
                {
                case Platform::F1:
                {
                    platform->setFullscreen(not platform->getFullscreen());
                    break;
                }
                case Platform::Escape:
                {
                    platform->setFullscreen(false);
                    break;
                }
                }
                break;
            }
            }
        }

        scene->handleInput();

        //cam.update(scene->camera);
    }

    virtual void update()
    {
        scene->update();
    }

    virtual void fixedUpdate(float timestep)
    {
        scene->fixedUpdate(timestep);
    }

    virtual void render()
    {
        scene->getRenderer()->resize(UInt2(platform->getWindowWidth(),
                                           platform->getWindowHeight()));

        bool debugDraw = platform->isRightMouseButtonPressed();
        
        scene->getRenderer()->debugDraw = debugDraw;
        
        if (debugDraw)
        {
            scene->getPhysicsWorld()->debugDraw();
        }
        
        scene->getRenderer()->render();
    }
END_SCRIPT

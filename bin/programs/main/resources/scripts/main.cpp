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

#define TIMINGS_UPDATE_COUNTDOWN 0.1f

BEGIN_SCRIPT
    ResPtr<Scene> scene;
    FPSCamera cam;
    Font *font;
    bool showExtraTimings;
    String timings;
    String extraTimings;
    float timingsUpdateCountdown;
    bool freezeTimings;
    GPUTimer *debugDrawTimer;
    GPUTimer *textTimer;

    virtual void init()
    {
        showExtraTimings = false;
        timingsUpdateCountdown = 0.0f;
        freezeTimings = false;
        
        scene = resMgr->getResource<Scene>("resources/scenes/scene.bin");
    
        font = NEW(Font, "/usr/share/fonts/gnu-free/FreeSans.ttf");
    
        debugDrawTimer = gfxApi->createTimer();
        textTimer = gfxApi->createTimer();
    }
    
    virtual void deinit()
    {
        DELETE(GPUTimer, debugDrawTimer);
        DELETE(GPUTimer, textTimer);
        DELETE(Font, font);
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
                case Platform::F2:
                {
                    showExtraTimings = not showExtraTimings;
                    break;
                }
                case Platform::F3:
                {
                    freezeTimings = not freezeTimings;
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
        while (not debugDrawTimer->resultAvailable());
        while (not textTimer->resultAvailable());
        scene->getRenderer()->updateStats();
        
        timingsUpdateCountdown -= platform->getFrametime();
    
        gfxApi->setViewport(0, 0, platform->getWindowWidth(), platform->getWindowHeight());
        scene->getRenderer()->resize(UInt2(platform->getWindowWidth(),
                                           platform->getWindowHeight()));

        bool debugDraw = platform->isRightMouseButtonPressed();
        
        scene->getRenderer()->debugDraw = debugDraw;
        
        debugDrawTimer->begin();
        if (debugDraw)
        {
            scene->getPhysicsWorld()->debugDraw();
        }
        debugDrawTimer->end();
        
        scene->getRenderer()->render();
        
        size_t fontSize = 40;
        float y = gfxApi->getViewportHeight() - fontSize;
        y /= gfxApi->getViewportHeight();
        
        if (timingsUpdateCountdown < 0.0f and not freezeTimings)
        {
            timingsUpdateCountdown = TIMINGS_UPDATE_COUNTDOWN;
            
            timings = String::format("FPS: %.0f\n"
                                     "Frametime: %.0f ms\n"
                                     "GPU FPS: %.0f\n"
                                     "GPU Frametime: %.0f\n",
                                      1.0f / platform->getFrametime(),
                                      platform->getFrametime() * 1000.0f,
                                      1.0f / platform->getGPUFrametime(),
                                      platform->getGPUFrametime() * 1000.0f);
        
            GfxRenderer::RenderStats stats = scene->getRenderer()->getStats();
            
            float total = platform->getGPUFrametime();
            float debugDrawTiming = debugDrawTimer->getResult() / (float)debugDrawTimer->getResultResolution();
            float textTiming = textTimer->getResult() / (float)textTimer->getResultResolution();
            float sum = stats.gBufferTiming +
                        stats.ssaoTiming +
                        stats.ssaoBlurXTiming +
                        stats.ssaoBlurYTiming +
                        stats.deferredShadingTiming +
                        stats.forwardTiming +
                        stats.gammaCorrectionTiming +
                        stats.fxaaTiming +
                        stats.vignetteTiming +
                        stats.bloomXTiming +
                        stats.bloomYTiming +
                        stats.tonemappingTiming +
                        stats.shadowmapTiming +
                        debugDrawTiming +
                        textTiming;
            
            extraTimings = String::format("GBuffer: %.2f ms (%.0f%)\n"
                                          "SSAO: %.2f ms (%.0f%)\n"
                                          "SSAO blur X: %.2f ms (%.0f%)\n"
                                          "SSAO blur Y: %.2f ms (%.0f%)\n"
                                          "Deferred shading: %.2f ms (%.0f%)\n"
                                          "Forward render: %.2f ms (%.0f%)\n"
                                          "Gamma correction: %.2f ms (%.0f%)\n"
                                          "FXAA: %.2f ms (%.0f%)\n"
                                          "Vignette: %.2f ms (%.0f%)\n"
                                          "Bloom X: %.2f ms (%.0f%)\n"
                                          "Bloom Y: %.2f ms (%.0f%)\n"
                                          "Tonemapping: %.2f ms (%.0f%)\n"
                                          "Shadow map: %.2f ms (%.0f%)\n"
                                          "Debug draw: %.2f ms (%.0f%)\n"
                                          "Text: %.2f ms (%.0f%)\n"
                                          "Other: %.2f ms (%.0f%)\n",
                                          stats.gBufferTiming * 1000.0f,
                                          stats.gBufferTiming / total * 100.0f,
                                          stats.ssaoTiming * 1000.0f,
                                          stats.ssaoTiming / total * 100.0f,
                                          stats.ssaoBlurXTiming * 1000.0f,
                                          stats.ssaoBlurXTiming / total * 100.0f,
                                          stats.ssaoBlurYTiming * 1000.0f,
                                          stats.ssaoBlurYTiming / total * 100.0f,
                                          stats.deferredShadingTiming * 1000.0f,
                                          stats.deferredShadingTiming / total * 100.0f,
                                          stats.forwardTiming * 1000.0f,
                                          stats.forwardTiming / total * 100.0f,
                                          stats.gammaCorrectionTiming * 1000.0f,
                                          stats.gammaCorrectionTiming / total * 100.0f,
                                          stats.fxaaTiming * 1000.0f,
                                          stats.fxaaTiming / total * 100.0f,
                                          stats.vignetteTiming * 1000.0f,
                                          stats.vignetteTiming / total * 100.0f,
                                          stats.bloomXTiming * 1000.0f,
                                          stats.bloomXTiming / total * 100.0f,
                                          stats.bloomYTiming * 1000.0f,
                                          stats.bloomYTiming / total * 100.0f,
                                          stats.tonemappingTiming * 1000.0f,
                                          stats.tonemappingTiming / total * 100.0f,
                                          stats.shadowmapTiming * 1000.0f,
                                          stats.shadowmapTiming / total * 100.0f,
                                          debugDrawTiming * 1000.0f,
                                          debugDrawTiming / total * 100.0f,
                                          textTiming * 1000.0f,
                                          textTiming / total * 100.0f,
                                          (total - sum) * 1000.0f,
                                          (total - sum) / total * 100.0f);
        }
        
        String displayTimings = timings.copy();
        
        if (showExtraTimings)
        {
            displayTimings.append(extraTimings);
        }
        
        textTimer->begin();
        
        font->render(fontSize,
                     Float2(-1.0, y),
                     displayTimings.getData(),
                     NULL,
                     Float3(1.0));
        
        textTimer->end();
    }
END_SCRIPT

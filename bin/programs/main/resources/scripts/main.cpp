#ifndef MAIN
#define MAIN

#include <cmath>
#include "entityscript.cpp"

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

BEGIN_INSTANCE(Main, InstanceBase)
    Scene *scene;
    Font *font;
    bool showExtraTimings;
    String timings;
    String extraTimings;
    float timingsUpdateCountdown;
    bool freezeTimings;
    GPUTimer *textTimer;
    float debugDrawTiming;
    float textTiming;
    AudioSource *source;
    Audio *audio;
    Script *projScript;
    float textCPUTiming;
    
    virtual void init()
    {
        showExtraTimings = false;
        timingsUpdateCountdown = 0.0f;
        freezeTimings = false;
        
        scene = resMgr->load<Scene>("resources/scenes/scene.bin");
        
        font = resMgr->load<Font>("/usr/share/fonts/gnu-free/FreeSans.ttf");
        
        textTimer = gfxApi->createTimer();
        
        Entity *entity = scene->createEntity("Audio source");
        
        source = entity->addAudioSource(resMgr->load<Audio>("resources/audio/hi.ogg"));
        source->position = Position3D(0.0f, 1.0f, 0.0f);
    
        //Kept around to speed up projectile creation.
        projScript = resMgr->load<Script>("resources/scripts/projectilescript.cpp");
    }
    
    virtual void deinit()
    {
        projScript->release();
    
        DELETE(GPUTimer, textTimer);
        
        font->release();
        scene->release();
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
                case Platform::F4:
                {
                    scene->getRenderer()->debugDraw = not scene->getRenderer()->debugDraw;
                    break;
                }
                }
                break;
            }
            }
        }
        
        scene->handleInput();
    }

    virtual void update()
    {
        scene->update();
        
        scene->getAudioWorld()->listenerPosition = scene->getRenderer()->camera.getPosition();
    
        if (platform->isKeyPressed(Platform::H))
        {
            source->playing = true;
        }
    }

    virtual void fixedUpdate(float timestep)
    {
        scene->fixedUpdate(timestep);
    }

    virtual void postRender()
    {
        timingsUpdateCountdown -= platform->getFrametime();
        
        gfxApi->setViewport(0, 0, platform->getWindowWidth(), platform->getWindowHeight());
        scene->getRenderer()->resize(UInt2(platform->getWindowWidth(),
                                           platform->getWindowHeight()));
        
        bool debugDraw = platform->isRightMouseButtonPressed();
        
        if (scene->getRenderer()->debugDraw)
        {
            scene->getPhysicsWorld()->debugDraw();
        }
        
        scene->getRenderer()->render();
        
        size_t fontSize = 40;
        float y = gfxApi->getViewportHeight() - fontSize;
        y /= gfxApi->getViewportHeight();
        
        GfxRenderer::RenderStats stats = scene->getRenderer()->getStats();
        
        if (timingsUpdateCountdown < 0.0f and not freezeTimings)
        {
            timingsUpdateCountdown = TIMINGS_UPDATE_COUNTDOWN;
            
            timings = String::format("FPS: %.0f\n"
                                     "Frametime: %.0f ms\n"
                                     "GPU Frametime: %.0f ms\n"
                                     "CPU Frametime: %.0f ms\n",
                                      1.0f / platform->getFrametime(),
                                      platform->getFrametime() * 1000.0f,
                                      platform->getGPUFrametime() * 1000.0f,
                                      platform->getCPUFrametime() * 1000.0f);
            
            Application::Stats cpuStats = app->getStats();
            
            float total = platform->getGPUFrametime();
            float cpuTotal = platform->getCPUFrametime();
            
            if (textTimer->resultAvailable())
            {
                textTiming = textTimer->getResult() / (float)textTimer->getResultResolution();
            }
            
            float sum = stats.gBufferTiming +
                        stats.ssaoTiming +
                        stats.ssaoBlurXTiming +
                        stats.ssaoBlurYTiming +
                        stats.deferredShadingTiming +
                        stats.forwardTiming +
                        stats.gammaCorrectionTiming +
                        stats.fxaaTiming +
                        stats.colorModifierTiming +
                        stats.bloomTiming +
                        stats.shadowmapTiming +
                        stats.overlayTiming +
                        stats.debugDrawTiming +
                        textTiming;
            
            extraTimings = String::format("GPU Timings:\n"
                                          "    GBuffer: %.2f ms (%.0f%)\n"
                                          "    SSAO: %.2f ms (%.0f%)\n"
                                          "    SSAO blur X: %.2f ms (%.0f%)\n"
                                          "    SSAO blur Y: %.2f ms (%.0f%)\n"
                                          "    Deferred shading: %.2f ms (%.0f%)\n"
                                          "    Forward render: %.2f ms (%.0f%)\n"
                                          "    Gamma correction: %.2f ms (%.0f%)\n"
                                          "    FXAA: %.2f ms (%.0f%)\n"
                                          "    Color modifiers: %.2f ms (%.0f%)\n"
                                          "    Bloom: %.2f ms (%.0f%)\n"
                                          "    Shadow map: %.2f ms (%.0f%)\n"
                                          "    Debug draw: %.2f ms (%.0f%)\n"
                                          "    Text: %.2f ms (%.0f%)\n"
                                          "    Overlays: %.2f ms (%.0f%)\n"
                                          "    Other: %.2f ms (%.0f%)\n"
                                          "CPU Timings:\n"
                                          "    Input: %.2f ms (%.0f%)\n"
                                          "    Update: %.2f ms (%.0f%)\n"
                                          "    Fixed Update: %.2f ms (%.0f%)\n"
                                          "    Pre Render: %.2f ms (%.0f%)\n"
                                          "    Post Render: %.2f ms (%.0f%)\n"
                                          "        Shadowmap: %.2f ms (%.0f%)\n"
                                          "        G Buffer: %.2f ms (%.0f%)\n"
                                          "        Forward: %.2f ms (%.0f%)\n"
                                          "        Overlay: %.2f ms (%.0f%)\n"
                                          "        Batching: %.2f ms (%.0f%)\n"
                                          "        Text: %.2f ms (%.0f%)\n"
                                          "    Audio: %.2f ms (%.0f%)\n",
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
                                          stats.colorModifierTiming * 1000.0f,
                                          stats.colorModifierTiming / total * 100.0f,
                                          stats.bloomTiming * 1000.0f,
                                          stats.bloomTiming / total * 100.0f,
                                          stats.shadowmapTiming * 1000.0f,
                                          stats.shadowmapTiming / total * 100.0f,
                                          stats.debugDrawTiming * 1000.0f,
                                          stats.debugDrawTiming / total * 100.0f,
                                          textTiming * 1000.0f,
                                          textTiming / total * 100.0f,
                                          stats.overlayTiming * 1000.0f,
                                          stats.overlayTiming / total * 100.0f,
                                          (total - sum) * 1000.0f,
                                          (total - sum) / total * 100.0f,
                                          cpuStats.handleInput * 1000.0f,
                                          cpuStats.handleInput / cpuTotal * 100.0f,
                                          cpuStats.update * 1000.0f,
                                          cpuStats.update / cpuTotal * 100.0f,
                                          cpuStats.fixedUpdate * 1000.0f,
                                          cpuStats.fixedUpdate / cpuTotal * 100.0f,
                                          cpuStats.preRender * 1000.0f,
                                          cpuStats.preRender / cpuTotal * 100.0f,
                                          cpuStats.postRender * 1000.0f,
                                          cpuStats.postRender / cpuTotal * 100.0f,
                                          stats.shadowmapCPUTiming * 1000.0f,
                                          stats.shadowmapCPUTiming / cpuTotal * 100.0f,
                                          stats.gbufferCPUTiming * 1000.0f,
                                          stats.gbufferCPUTiming / cpuTotal * 100.0f,
                                          stats.forwardCPUTiming * 1000.0f,
                                          stats.forwardCPUTiming / cpuTotal * 100.0f,
                                          stats.overlayCPUTiming * 1000.0f,
                                          stats.overlayCPUTiming / cpuTotal * 100.0f,
                                          stats.batchingTiming * 1000.0f,
                                          stats.batchingTiming / cpuTotal * 100.0f,
                                          textCPUTiming * 1000.0f,
                                          textCPUTiming / cpuTotal * 100.0f,
                                          cpuStats.audio * 1000.0f,
                                          cpuStats.audio / cpuTotal * 100.0f);
        }
        String displayedText = timings.copy();
        
        displayedText.append(String::format("Draw calls: %zu\n", stats.numDrawCalls));
        
        if (showExtraTimings)
        {
            displayedText.append(extraTimings);
        }
        
        Player *player = scene->findWithScript<Player>();
        
        if (player != nullptr)
        {
            displayedText.append(String::format("Zoom: %f\n", 1.0f / player->zoom));
        }
        
        textTimer->begin();
        uint64_t start = platform->getTime();
        
        font->render(fontSize,
                     Float2(-1.0, y),
                     displayedText.getData(),
                     NULL,
                     Float3(1.0));
        
        textCPUTiming = float(platform->getTime() - start) / platform->getTimerFrequency();
        textTimer->end();
    }
END_INSTANCE(Main)

#endif

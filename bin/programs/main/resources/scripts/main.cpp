#ifndef MAIN
#define MAIN

#include <cmath>
#include "entityscript.cpp"
#include "projectilescript.cpp"

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

            if (platform->isKeyPressed(Key::Space))
            {
                resSpeed *= 4.0f;
            }

            if (platform->isKeyPressed(Key::LeftShift))
            {
                resSpeed /= 4.0f;
            }

            /*if (platform->isKeyPressed(Key::Left))
            {
                angularVelocity.x += rotateSpeed * platform->getFrametime();
            }

            if (platform->isKeyPressed(Key::Right))
            {
                angularVelocity.x -= rotateSpeed * platform->getFrametime();
            }

            if (platform->isKeyPressed(Key::Up))
            {
                angularVelocity.y += rotateSpeed * platform->getFrametime();
            }

            if (platform->isKeyPressed(Key::Down))
            {
                angularVelocity.y -= rotateSpeed * platform->getFrametime();
            }*/

            if (platform->isKeyPressed(Key::A))
            {
                velocity -= right * platform->getFrametime() * resSpeed;
            }

            if (platform->isKeyPressed(Key::D))
            {
                velocity += right * platform->getFrametime() * resSpeed;
            }

            if (platform->isKeyPressed(Key::W))
            {
                velocity += dir * platform->getFrametime() * resSpeed;
            }

            if (platform->isKeyPressed(Key::S))
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
    float playerFindCPUTiming;
    ImGui gui;

    virtual void init()
    {
        showExtraTimings = false;
        timingsUpdateCountdown = 0.0f;
        freezeTimings = false;

        scene = resMgr->load<Scene>("resources/scenes/scene.bin");

        //For some reason Font's constructors are not being bound.
        font = resMgr->load<Font>("/usr/share/fonts/gnu-free/FreeSans.ttf");

        textTimer = gfxApi->createTimer();

        Entity *entity = scene->createEntity("Audio source");

        source = entity->addAudioSource(resMgr->load<Audio>("resources/audio/hi.ogg"));
        source->position = Position3D(0.0f, 1.0f, 0.0f);

        //Kept around to speed up projectile creation.
        projScript = resMgr->load<Script>("resources/scripts/projectilescript.cpp");
        
        textTiming = 0.0f;
        textCPUTiming = 0.0f;
        playerFindCPUTiming = 0.0f;
    }

    virtual void deinit()
    {
        projScript->release();

        DELETE(textTimer);

        font->release();
        scene->release();
    }

    virtual void handleInput()
    {
        Event event;

        while (platform->pollEvent(event))
        {
            switch (event.type)
            {
            case EventType::Quit:
            {
                app->running = false;
                break;
            }
            case EventType::KeyDown:
            {
                switch (event.key.key)
                {
                case Key::F1:
                {
                    platform->setFullscreen(not platform->getFullscreen());
                    break;
                }
                case Key::F2:
                {
                    showExtraTimings = not showExtraTimings;
                    break;
                }
                case Key::F3:
                {
                    freezeTimings = not freezeTimings;
                    break;
                }
                case Key::Escape:
                {
                    platform->setFullscreen(false);
                    break;
                }
                case Key::F4:
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

        if (platform->isKeyPressed(Key::H))
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

        RenderStats stats = scene->getRenderer()->getStats();

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

            Stats cpuStats = app->getStats();

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
                                          "        Player Find: %.2f ms (%.0f%)\n"
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
                                          playerFindCPUTiming * 1000.0f,
                                          playerFindCPUTiming / cpuTotal * 100.0f,
                                          cpuStats.audio * 1000.0f,
                                          cpuStats.audio / cpuTotal * 100.0f);
        }
        String displayedText = timings.copy();

        displayedText.append(String::format("Draw calls: %zu\n", stats.numDrawCalls));

        if (showExtraTimings)
        {
            displayedText.append(extraTimings);
        }

        uint64_t start = platform->getTime();

        Player *player = scene->findWithScript<Player>();

        if (player != nullptr)
        {
            displayedText.append(String::format("Zoom: %f\n", 1.0f / player->zoom));
        }

        playerFindCPUTiming = float(platform->getTime() - start) / platform->getTimerFrequency();

        /*Projectile *proj = scene->findWithScript<Projectile>();

        if (proj != nullptr)
        {
            proj->getEntity()->transform.lookAt(player->getEntity()->transform.position);
        }*/

        textTimer->swap();
        textTimer->begin();
        start = platform->getTime();

        font->render(fontSize,
                     Float2(-1.0, y),
                     displayedText.getData(),
                     NULL,
                     Float3(1.0));

        textCPUTiming = float(platform->getTime() - start) / platform->getTimerFrequency();
        textTimer->end();

        /*gfxApi->clearColor(0, Float4(0.0f));
        
        static int scrollX = 0;
        static int scrollY = 0;
        
        static Container container;
        gui.beginContainer(0, 230, platform->getWindowHeight()-200, platform->getWindowHeight(), &container);
        
        GuiPlacer placer(&gui, platform->getWindowHeight(), 0, 10);
        
        placer.button("Click me!", 100, 20);
        placer.advanceY();
        
        placer.button("No! Me!", 100, 20);
        placer.advanceY();
        
        placer.button("Hullo!", 100, 250);
        placer.button("Good bye!", 100, 20);
        placer.button("Peek a Boo!", 100, 20);
        placer.advanceY();
        
        gui.endContainer(&container);
        
        placer.setXOrigin(XOrigin::Right, platform->getWindowWidth());
        placer.button("Boing!", 75, 30);
        placer.setXOrigin(XOrigin::Left, 0);
        placer.button("Boing!", 75, 40);
        placer.advanceY();
        
        placer.label("This is a label!");
        
        placer.setXOrigin(XOrigin::Right, platform->getWindowWidth());
        placer.resetY();
        placer.button("On the right now!", 150, 20);
        placer.advanceY();
        
        placer.button("Downwards!", 100, 20);
        placer.button("To the left!", 100, 20);
        placer.advanceY();
        
        GuiPlacer placer2 = placer.placer(150, placer.getPadding());
        
        placer2.button("Such fun!", 100, 20);
        placer2.advanceY();
        
        placer.advanceY(placer2);
        
        placer.button("Blah blah!", 100, 20);
        
        static ScrollBar state;
        gui.verticalScrollBar(315, 330, 55, 620, true, true, &state);
        
        static ScrollBar state2;
        gui.horizontalScrollBar(50, 590, 20, 35, true, true, &state2);
        
        gui.render();*/
    }
END_INSTANCE(Main)

#endif

#include "application.h"

#include "platform.h"
#include "graphics/GL/gfxglapi.h"
#include "scene/scene.h"
#include "graphics/gfxshader.h"
#include "graphics/gfxtexture.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxmaterial.h"
#include "graphics/gfxmodel.h"
#include "graphics/gfxdebugdrawer.h"
#include "scripting/script.h"
#include "physics/physicsworld.h"
#include "audio/audiodevice.h"
#include "misc_macros.h"
#include "filesystem.h"
#include "error.h"
#include "globals.h"
#include "logging.h"

Application::Application(const char *workingDir) : fixedTimestep(0.016f),
                                                   stats({0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}),
                                                   nextScript(nullptr)
{
    precompileScriptInclude();

    app = this;

    FT_Init_FreeType(&freeType_);
    freeType = freeType_;

    platform_ = NEW(Platform);
    platform = platform_;

    platform_->initWindow(640, 640, 1);

    fileSystem_ = NEW(Filesystem);
    fileSys = fileSystem_;
    fileSys->addSearchPath(workingDir);

    resMgr_ = NEW(ResourceManager);
    resMgr = resMgr_;

    gfxApi_ = NEW(GfxGLApi);
    gfxApi = gfxApi_;

    debugDrawer_ = NEW(GfxDebugDrawer, gfxApi_);
    debugDrawer = debugDrawer_;

    audioDevice_ = NEW(AudioDevice, 0, 44100, 4096);
    audioDevice = audioDevice_;

    INFO(CATEGORY_AUDIO, "Initialized an audio device called \"%s\".", audioDevice_->getName().getData())();

    script = nullptr;
}

Application::~Application()
{
    if (script != nullptr)
    {
        Script *script_ = script->getScript();

        DELETE(script);

        script_->release();
    }

    if (nextScript != nullptr)
    {
        nextScript->release();
    }

    DELETE(resMgr_);

    DELETE(audioDevice_);
    DELETE(debugDrawer_);
    DELETE(gfxApi_);

    platform_->destroyWindow();

    DELETE(fileSystem_);

    DELETE(platform_);

    FT_Done_FreeType(freeType);
}

void Application::updateFunction()
{
    uint64_t timerFrequency = platform_->getTimerFrequency();

    uint64_t start = platform_->getTime();
    if (script != nullptr)
    {
        script->handleInput();
    }
    uint64_t end = platform_->getTime();
    stats.handleInput = float(end - start) / timerFrequency;

    start = platform_->getTime();

    uint64_t realTime = platform_->getTime();

    while (simulationTime < realTime)
    {
        if (script != nullptr)
        {
            script->fixedUpdate(fixedTimestep);
        }

        simulationTime += fixedTimestep * timerFrequency;
    }

    end = platform_->getTime();
    stats.fixedUpdate = float(end - start) / timerFrequency;

    if (script != nullptr)
    {
        start = platform_->getTime();
        script->update();
        end = platform_->getTime();
        stats.update = float(end - start) / timerFrequency;

        start = platform_->getTime();
        script->preRender();
        end = platform_->getTime();
        stats.preRender = float(end - start) / timerFrequency;

        start = platform_->getTime();
        script->postRender();
        end = platform_->getTime();
        stats.postRender = float(end - start) / timerFrequency;
    }

    _switchScripts();

    resMgr_->cleanupResources();
    resMgr_->autoReloadResources();

    platform_->running = running;

    int numSamples = audioDevice->getSamples() * 2 - audioDevice->getNumQueuedSamples();

    numSamples = std::max(numSamples, 0);

    start = platform_->getTime();

    if (numSamples > 0)
    {
        audioDevice->runCallbacks(numSamples);
    }

    end = platform_->getTime();
    stats.audio = float(end - start) / timerFrequency;

    audioDevice->play();
}

struct Data
{
    Application *app;
    void (Application::*update)();
} data;

void _updateFunction(Platform *platform)
{
    CALL_METHOD_POINTER(*data.app, data.update);
}

void Application::mainloop()
{
    simulationTime = 0;
    running = true;

    data.app = this;
    data.update = &Application::updateFunction;

    platform_->run(_updateFunction);
}

void Application::_switchScripts()
{
    if (nextScript != nullptr)
    {
        DELETE(script);

        script = nextScript->createInstance(nextScriptName.getData());

        nextScript = nullptr;
    }
}

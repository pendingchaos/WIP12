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
#include "scripting/bindings.h"
#include "scripting/vm/engine.h"
#include "extensions/extensions.h"

Application::Application(const char *workingDir) : fixedTimestep(0.016f),
                                                   stats({0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}),
                                                   nextScript(nullptr)
{
    app = this;

    FT_Init_FreeType(&freeType_);
    freeType = freeType_;

    platform_ = NEW(Platform);
    platform = platform_;

    platform_->initWindow(640, 640);

    fileSystem_ = NEW(Filesystem);
    fileSys = fileSystem_;
    fileSys->addSearchPath(workingDir);

    scriptEngine_ = NEW(scripting::Engine);
    scripting::registerBindings(scriptEngine_);
    scriptEngine = scriptEngine_;

    resMgr_ = NEW(ResourceManager);
    resMgr = resMgr_;

    gfxApi_ = NEW(GfxGLApi);
    gfxApi = gfxApi_;

    debugDrawer_ = NEW(GfxDebugDrawer);
    debugDrawer = debugDrawer_;

    audioDevice_ = NEW(AudioDevice, 0, 44100, 4096);
    audioDevice = audioDevice_;

    LOG_INFO("Initialized an audio device called \"%s\".", audioDevice_->getName().getData());

    script = nullptr;

    extensions = initExtensions();
}

Application::~Application()
{
    DELETE(script);

    if (nextScript != nullptr)
    {
        nextScript->release();
    }

    deinitExtensions(extensions);

    DELETE(resMgr_);

    DELETE(audioDevice_);
    DELETE(debugDrawer_);
    DELETE(gfxApi_);

    DELETE(scriptEngine_);

    DELETE(fileSystem_);

    platform_->destroyWindow();
    DELETE(platform_);

    FT_Done_FreeType(freeType);
}

void Application::updateFunction()
{
    uint64_t timerFrequency = platform_->getTimerFrequency();

    uint64_t start = platform_->getTime();
    if (script != nullptr)
    {
        scripting::destroy(script->getScript()->getContext(), script->method("handleInput"));
    }
    uint64_t end = platform_->getTime();
    stats.handleInput = float(end - start) / timerFrequency;

    start = platform_->getTime();

    uint64_t realTime = platform_->getTime();

    size_t num = 0;
    while (simulationTime < realTime && num < 10)
    {
        if (script != nullptr)
        {
            scripting::destroy(script->getScript()->getContext(),
                               script->method("fixedUpdate", scripting::createFloat(fixedTimestep)));
        }

        simulationTime += fixedTimestep * timerFrequency;
        ++num;
    }

    //Don't allow more than 10 per frame. //TODO: Make this configurable.
    if (num == 10)
    {
        simulationTime = realTime;
    }

    end = platform_->getTime();
    stats.fixedUpdate = float(end - start) / timerFrequency;

    if (script != nullptr)
    {
        start = platform_->getTime();
        scripting::destroy(script->getScript()->getContext(),
                           script->method("update"));
        end = platform_->getTime();
        stats.update = float(end - start) / timerFrequency;

        start = platform_->getTime();
        scripting::destroy(script->getScript()->getContext(),
                           script->method("preRender"));
        end = platform_->getTime();
        stats.preRender = float(end - start) / timerFrequency;

        start = platform_->getTime();
        scripting::destroy(script->getScript()->getContext(),
                           script->method("postRender"));
        end = platform_->getTime();
        stats.postRender = float(end - start) / timerFrequency;
    }

    _switchScripts();

    resMgr_->cleanupResources();

    platform_->running = running;

    ptrdiff_t numSamples = (ptrdiff_t)audioDevice->getSamples() * 2 - (ptrdiff_t)audioDevice->getNumQueuedSamples();
    numSamples = std::max(numSamples, (ptrdiff_t)0);
    SDL_assert_paranoid(numSamples >= 0);

    start = platform_->getTime();

    if (numSamples != 0)
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

static void _updateFunction(Platform *platform_)
{
    UNUSED(platform_);
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

        script = nextScript->createInstance();

        nextScript->release();
        nextScript = nullptr;
    }
}

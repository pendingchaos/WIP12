#ifndef APPLICATION_H
#define APPLICATION_H

#include "memory.h"
#include "misc_macros.h"
#include "resource/resourcemanager.h"
#include "scripting/script.h"

#include <stdint.h>
#include <ft2build.h>
#include FT_FREETYPE_H

class Platform;
class Application;
class GfxApi;
class GfxRenderer;
class PhysicsWorld;
class Filesystem;
class GfxDebugDrawer;
class AudioDevice;

namespace scripting
{
    class Engine;
}

struct Stats
{
    float handleInput;
    float update;
    float fixedUpdate;
    float preRender;
    float postRender;
    float audio;
} BIND;

class Application
{
    NO_COPY(Application)

    public:
        Application(const char *workingDir);
        ~Application();

        void mainloop();

        Platform *getPlatform() const
        {
            return platform_;
        }

        ResourceManager *getResourceManager() const
        {
            return resMgr_;
        }

        GfxApi *getGfxApi() const
        {
            return gfxApi_;
        }

        Filesystem *getFilesystem() const
        {
            return fileSystem_;
        }

        GfxDebugDrawer *getDebugDrawer() const
        {
            return debugDrawer_;
        }

        FT_Library getFreeType() const NO_BIND
        {
            return freeType_;
        }

        AudioDevice *getAudioDevice() const
        {
            return audioDevice_;
        }

        scripting::Engine *getScriptEngine() const NO_BIND
        {
            return scriptEngine_;
        }

        void setNextScript(Script *script_)
        {
            if (nextScript != nullptr)
            {
                nextScript->release();
            }

            nextScript = script_->copyRef<Script>();
        }

        Script *getNextScript() const
        {
            return nextScript;
        }

        ScriptInstance *getScript() const
        {
            return script;
        }

        Stats getStats() const
        {
            return stats;
        }

        void *getExtensions() const NO_BIND
        {
            return extensions;
        }

        float fixedTimestep;
        bool running;
    private:
        Stats stats;
        Platform *platform_;
        Filesystem *fileSystem_;
        ResourceManager *resMgr_;
        GfxApi *gfxApi_;
        GfxDebugDrawer *debugDrawer_;
        FT_Library freeType_;
        AudioDevice *audioDevice_;
        scripting::Engine *scriptEngine_;
        void *extensions;

        ScriptInstance *script;
        Script *nextScript;
        uint64_t simulationTime;

        void _switchScripts();
        void updateFunction();
} BIND NOT_COPYABLE;

#endif // APPLICATION_H

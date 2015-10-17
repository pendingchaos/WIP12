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

        inline Platform *getPlatform() const
        {
            return platform_;
        }

        inline ResourceManager *getResourceManager() const
        {
            return resMgr_;
        }

        inline GfxApi *getGfxApi() const
        {
            return gfxApi_;
        }

        inline Filesystem *getFilesystem() const
        {
            return fileSystem_;
        }

        inline GfxDebugDrawer *getDebugDrawer() const
        {
            return debugDrawer_;
        }

        inline FT_Library getFreeType() const NO_BIND
        {
            return freeType_;
        }

        inline AudioDevice *getAudioDevice() const
        {
            return audioDevice_;
        }

        inline scripting::Engine *getScriptEngine() const NO_BIND
        {
            return scriptEngine_;
        }

        inline void setNextScript(Script *script_, const char *name) NO_BIND
        {
            if (nextScript != nullptr)
            {
                nextScript->release();
            }

            nextScript = script_->copyRef<Script>();
            nextScriptName = name;
        }

        inline Script *getNextScript() const NO_BIND
        {
            return nextScript;
        }

        inline ScriptInstance *getScript() const NO_BIND
        {
            return script;
        }

        inline Stats getStats() const
        {
            return stats;
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

        ScriptInstance *script;
        Script *nextScript;
        Str nextScriptName;
        uint64_t simulationTime;

        void _switchScripts();
        void updateFunction();
} BIND NOT_COPYABLE;

#endif // APPLICATION_H

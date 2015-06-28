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

        inline FT_Library getFreeType() const
        {
            return freeType_;
        }

        inline AudioDevice *getAudioDevice() const
        {
            return audioDevice_;
        }

        inline void setNextScript(ResPtr<Script> script_)
        {
            nextScript = script_;
        }

        inline ResPtr<Script> getNextScript() const
        {
            return nextScript;
        }

        inline ScriptInstance *getScript() const
        {
            return script;
        }

        float fixedTimestep;
        bool running;
    private:
        Platform *platform_;
        Filesystem *fileSystem_;
        ResourceManager *resMgr_;
        GfxApi *gfxApi_;
        GfxDebugDrawer *debugDrawer_;
        FT_Library freeType_;
        AudioDevice *audioDevice_;

        ScriptInstance *script;
        ResPtr<Script> nextScript;
        uint64_t simulationTime;

        void _switchScripts();
        void updateFunction();
};

#endif // APPLICATION_H

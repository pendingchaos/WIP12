#include "globals.h"

#include "application.h"

Application *app = nullptr;
Platform *platform = nullptr;
ResourceManager *resMgr = nullptr;
GfxApi *gfxApi = nullptr;
Filesystem *fileSys = nullptr;
GfxDebugDrawer *debugDrawer = nullptr;
FT_Library freeType = nullptr;
AudioDevice *audioDevice = nullptr;
scripting::Engine *scriptEngine = nullptr;

void setApplication(Application *app_)
{
    app = app_;

    if (app != nullptr)
    {
        platform = app->getPlatform();
        resMgr = app->getResourceManager();
        gfxApi = app->getGfxApi();
        fileSys = app->getFilesystem();
        debugDrawer = app->getDebugDrawer();
        freeType = app->getFreeType();
        audioDevice = app->getAudioDevice();
        scriptEngine = app->getScriptEngine();
    } else
    {
        platform = nullptr;
        resMgr = nullptr;
        gfxApi = nullptr;
        fileSys = nullptr;
        debugDrawer = nullptr;
        freeType = nullptr;
        audioDevice = nullptr;
        scriptEngine = nullptr;
    }
}

Application *getApp()
{
    return app;
}

Platform *getPlatform()
{
    return platform;
}

ResourceManager *getResMgr()
{
    return resMgr;
}

GfxApi *getGfxApi()
{
    return gfxApi;
}

Filesystem *getFileSys()
{
    return fileSys;
}

GfxDebugDrawer *getDebugDrawer()
{
    return debugDrawer;
}

AudioDevice *getAudioDevice()
{
    return audioDevice;
}

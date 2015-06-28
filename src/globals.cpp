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
    } else
    {
        platform = nullptr;
        resMgr = nullptr;
        gfxApi = nullptr;
        fileSys = nullptr;
        debugDrawer = nullptr;
        freeType = nullptr;
        audioDevice = nullptr;
    }
}

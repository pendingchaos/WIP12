#include "globals.h"

#include "application.h"

Application *app = nullptr;
Platform *platform = nullptr;
ResourceManager *resMgr = nullptr;
GfxApi *gfxApi = nullptr;
GfxRenderer *renderer = nullptr;
Filesystem *fileSys = nullptr;
GfxDebugDrawer *debugDrawer = nullptr;

void setApplication(Application *app_)
{
    app = app_;

    if (app != nullptr)
    {
        platform = app->getPlatform();
        resMgr = app->getResourceManager();
        gfxApi = app->getGfxApi();
        renderer = app->getRenderer();
        fileSys = app->getFilesystem();
        debugDrawer = app->getDebugDrawer();
    } else
    {
        platform = nullptr;
        resMgr = nullptr;
        gfxApi = nullptr;
        renderer = nullptr;
        fileSys = nullptr;
        debugDrawer = nullptr;
    }
}

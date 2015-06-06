#ifndef GLOBALS_H
#define GLOBALS_H

class Application;
class Platform;
class ResourceManager;
class GfxApi;
class GfxRenderer;
class Filesystem;
class GfxDebugDrawer;

extern const char *programName;
extern Application *app;
extern Platform *platform;
extern ResourceManager *resMgr;
extern GfxApi *gfxApi;
extern GfxRenderer *renderer;
extern Filesystem *fileSys;
extern GfxDebugDrawer *debugDrawer;

void setApplication(Application *app);

#endif // GLOBALS_H

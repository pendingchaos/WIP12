#ifndef GLOBALS_H
#define GLOBALS_H

#include <ft2build.h>
#include FT_FREETYPE_H

class Application;
class Platform;
class ResourceManager;
class GfxApi;
class Filesystem;
class GfxDebugDrawer;
class AudioDevice;

extern const char *programName;
extern Application *app;
extern Platform *platform;
extern ResourceManager *resMgr;
extern GfxApi *gfxApi;
extern Filesystem *fileSys;
extern GfxDebugDrawer *debugDrawer;
extern FT_Library freeType;
extern AudioDevice *audioDevice;

void setApplication(Application *app);

#endif // GLOBALS_H

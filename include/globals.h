#ifndef GLOBALS_H
#define GLOBALS_H

#include <ft2build.h>
#include FT_FREETYPE_H
#include "scripting/bindings.h"

class Application;
class Platform;
class ResourceManager;
class GfxApi;
class Filesystem;
class GfxDebugDrawer;
class AudioDevice;

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

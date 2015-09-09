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

namespace scripting
{
    class Engine;
}

extern Application *app;
extern Platform *platform;
extern ResourceManager *resMgr;
extern GfxApi *gfxApi;
extern Filesystem *fileSys;
extern GfxDebugDrawer *debugDrawer;
extern FT_Library freeType;
extern AudioDevice *audioDevice;
extern scripting::Engine *scriptEngine;

void setApplication(Application *app);

Application *getApp() BIND;
Platform *getPlatform() BIND;
ResourceManager *getResMgr() BIND;
GfxApi *getGfxApi() BIND;
Filesystem *getFileSys() BIND;
GfxDebugDrawer *getDebugDrawer() BIND;
AudioDevice *getAudioDevice() BIND;

#endif // GLOBALS_H

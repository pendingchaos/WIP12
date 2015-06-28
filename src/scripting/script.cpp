#include "scripting/script.h"

#include "error.h"
#include "globals.h"
#include "filesystem.h"
#include "logging.h"
#include "platform/platform.h"

#include <stdio.h>
#include <dlfcn.h>

void precompileScriptInclude()
{
    system("g++ -g -fPIC -D_REENTRANT -I../include"
           " -std=gnu++11 ../include/scripting/scriptinclude.h"
           " -o../include/scripting/scriptinclude.h.gch `sdl2-config --cflags`"
           " `pkg-config bullet --cflags` `freetype-config --cflags` "
           "-fabi-version=" STR(__GXX_ABI_VERSION));
}

const void *getScriptFunctionStruct();

static const String scriptStart = "#line 0 \"scriptStart\"\n#include \"scripting/scriptinclude.h\"\nclass _InstanceBase\n"
"{\n"
"    public:\n"
"        _InstanceBase(Application *app_,\n"
"                      Entity *entity_,\n"
"                      ResPtr<Script> script_) : app(app_),\n"
"                                                platform(app->getPlatform()),\n"
"                                                resMgr(app->getResourceManager()),\n"
"                                                gfxApi(app->getGfxApi()),\n"
"                                                fileSys(app->getFilesystem()),\n"
"                                                debugDrawer(app->getDebugDrawer()),\n"
"                                                audioDevice(app->getAudioDevice()),\n"
"                                                entity(entity_),\n"
"                                                script(script_) {}\n"
"        virtual ~_InstanceBase() {}\n"
"        virtual void init() {}\n"
"        virtual void deinit() {}\n"
"        virtual void handleInput() {}\n"
"        virtual void update() {}\n"
"        virtual void fixedUpdate(float timestep) {}\n"
"        virtual void render() {}\n"
"    protected:"
"        Application *app;\n"
"        Platform *platform;\n"
"        ResourceManager *resMgr;\n"
"        GfxApi *gfxApi;\n"
"        Filesystem *fileSys;\n"
"        GfxDebugDrawer *debugDrawer;\n"
"        AudioDevice *audioDevice;\n"
"        Entity *entity;\n"
"        ResPtr<Script> script;\n"
"};\n"
"#define BEGIN_SCRIPT class _Instance : public _InstanceBase"
"{"
"    public:"
"        _Instance(Application *app, Entity *entity, ResPtr<Script> script) : _InstanceBase(app, entity, script) {init();}"
"        virtual ~_Instance() {deinit();}\n"
"#define END_SCRIPT }; extern \"C\"{_Instance *_createInstance(Application *app, Entity *entity, Script *script){"
"    return new _Instance(app, entity, script);"
"}"
"_Instance *_destroyInstance(_Instance *obj)"
"{"
"    delete obj;"
"}}\n\n#line 1 \"";

class _InstanceBase
{
    public:
        _InstanceBase();
        virtual ~_InstanceBase();

        virtual void init() {}
        virtual void deinit() {}
        virtual void handleInput() {}
        virtual void update() {}
        virtual void fixedUpdate(float timestep) {}
        virtual void render() {}
};

ScriptInstance::ScriptInstance(ResPtr<Script> script_,
                               void *ptr_,
                               Entity *entity_) : script(script_),
                                                  ptr(ptr_),
                                                  entity(entity_) {}

ScriptInstance::~ScriptInstance()
{
    script->destroyInstance(this);
}

void ScriptInstance::handleInput()
{
    if (ptr != nullptr)
    {
        ((_InstanceBase *)ptr)->handleInput();
    }
}

void ScriptInstance::update()
{
    if (ptr != nullptr)
    {
        ((_InstanceBase *)ptr)->update();
    }
}

void ScriptInstance::fixedUpdate(float timestep)
{
    if (ptr != nullptr)
    {
        ((_InstanceBase *)ptr)->fixedUpdate(timestep);
    }
}

void ScriptInstance::render()
{
    if (ptr != nullptr)
    {
        ((_InstanceBase *)ptr)->render();
    }
}

Script::Script() : Resource(ScriptType),
                   dl(nullptr) {}

Script::Script(const String& filename) : Resource(filename,
                                                  ScriptType),
                                         dl(nullptr) {}

Script::~Script()
{
    for (size_t i = 0; i < instances.getCount(); ++i)
    {
        ScriptInstance *instance = instances[i];

        destroyFunc(instance->ptr);
        instance->ptr = nullptr;
    }

    dlclose(dl);
}

void Script::removeContent()
{
    if (dl != nullptr)
    {
        for (size_t i = 0; i < userDatas.getCount(); ++i)
        {
            userDatas[i]->deinitFunc(userDatas[i]->pointer);
        }

        for (size_t i = 0; i < instances.getCount(); ++i)
        {
            ScriptInstance *instance = instances[i];

            destroyFunc(instance->ptr);
            instance->ptr = nullptr;
        }

        dlclose(dl);
        dl = nullptr;
    }
}

void Script::_load()
{
    removeContent();

    String source;

    try
    {
        File sourceFile(filename.getData(), "r");
        source = String(sourceFile.getSize());
        sourceFile.read(sourceFile.getSize(), source.getData());
    } catch (const FileException& e)
    {
        THROW(ResourceIOException,
              "script",
              filename,
              e.getString());
    }

    String scriptFilename = fileSys->getAbsolutePath(filename.getData());

    source = scriptStart.copy().append(scriptFilename).append("\"\n").append(source);

    int index = scriptFilename.findLast('/');

    String dir = scriptFilename.subStr(0, index);
    scriptFilename = scriptFilename.subStr(index+1, scriptFilename.getLength()-index-1);

    String binaryFilename = String::format("%s/bin/%s.so", dir.getData(), scriptFilename.getData());

    String command = String::format("g++ -o\"%s\" -g -I../include -I\"%s\" "
                                    "`pkg-config bullet --cflags` `freetype-config --cflags` -D_REENTRANT"
                                    " -fPIC -shared -std=gnu++11 -Winvalid-pch -fabi-version="
                                    STR(__GXX_ABI_VERSION) " -xc++ -",
                                    binaryFilename.getData(),
                                    dir.getData());

    uint64_t start = platform->getTime();

    FILE *pipe = popen(command.getData(), "w");

    if (pipe == nullptr)
    {
        THROW(ResourceIOException,
              "script",
              filename,
              String("Unable to execute command: ").append(command));
    }

    fwrite(source.getData(), source.getLength(), 1, pipe);

    if (pclose(pipe) == EXIT_SUCCESS)
    {
        uint64_t end = platform->getTime();

        float time = float(end - start) / (float)platform->getTimerFrequency();

        INFO(CATEGORY_SCRIPT, "Compilation complete.")(time);

        dl = dlopen(binaryFilename.getData(), RTLD_LAZY);

        if (dl == nullptr)
        {
            THROW(ResourceIOException,
                  "script",
                  filename,
                  String::format("Unable to load compiled script at %s: %s",
                                 binaryFilename.getData(),
                                 dlerror()));

            return;
        }

        createFunc = (void *(*)(Application *, Entity *, Script *))dlsym(dl, "_createInstance");
        destroyFunc = (void (*)(void *))dlsym(dl, "_destroyInstance");

        void (*initFunc)(const void *) = (void (*)(const void *))dlsym(dl, "_initFunctions");

        if (createFunc == nullptr or destroyFunc == nullptr or initFunc == nullptr)
        {
            dlclose(dl);

            dl = nullptr;

            THROW(ResourceIOException,
                  "script",
                  filename,
                  String::format("Compiled script at %s does not contain the needed functions.",
                                 binaryFilename.getData()));
        } else
        {
            initFunc(getScriptFunctionStruct());

            for (size_t i = 0; i < instances.getCount(); ++i)
            {
                ScriptInstance *instance = instances[i];

                instance->ptr = createFunc(app, instance->entity, this);
            }

            for (size_t i = 0; i < userDatas.getCount(); ++i)
            {
                userDatas[i]->pointer = userDatas[i]->initFunc();
            }
        }
    } else
    {
        THROW(ResourceIOException,
              "script",
              filename,
              String("Unable to execute command: ").append(command));
    }
}

ScriptInstance *Script::createInstance(Entity *entity)
{
    _InstanceBase *ptr = dl == nullptr ? nullptr : (_InstanceBase *)createFunc(app, entity, this);

    ScriptInstance *result = NEW(ScriptInstance, this, ptr, entity);

    instances.append(result);

    return result;
}

void Script::destroyInstance(ScriptInstance *instance)
{
    if (instance->script == this and instance->ptr != nullptr)
    {
        destroyFunc(instance->ptr);

        instances.remove(instances.find(instance));
    }
}

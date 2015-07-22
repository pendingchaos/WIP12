#include "scripting/script.h"

#include "error.h"
#include "globals.h"
#include "filesystem.h"
#include "logging.h"
#include "platform.h"
#include "scene/entity.h"
#include "scene/scene.h"

#include <stdio.h>
#include <dlfcn.h>
#include <sys/stat.h>

void precompileScriptInclude()
{
    system("g++ -g -fPIC -D_REENTRANT -I../include"
           " -std=gnu++11 ../include/scripting/scriptinclude.h"
           " -o../include/scripting/scriptinclude.h.gch `sdl2-config --cflags`"
           " `pkg-config bullet --cflags` `freetype-config --cflags` "
           "-fabi-version=" STR(__GXX_ABI_VERSION));
}

const void *getScriptFunctionStruct();

static const String scriptStart = "#line 0 \"scriptStart\"\n#include \"scripting/scriptinclude.h\"\n"
"#ifndef _INSTANCEBASE\n#define _INSTANCEBASE\n"
"class InstanceBase\n"
"{\n"
"    public:\n"
"        InstanceBase(Application *app_,\n"
"                     Entity *entity_,\n"
"                     Scene *scene_,"
"                     Script *script_) : app(app_),\n"
"                                        platform(app->getPlatform()),\n"
"                                        resMgr(app->getResourceManager()),\n"
"                                        gfxApi(app->getGfxApi()),\n"
"                                        fileSys(app->getFilesystem()),\n"
"                                        debugDrawer(app->getDebugDrawer()),\n"
"                                        audioDevice(app->getAudioDevice()),\n"
"                                        entity(entity_),\n"
"                                        script(script_),\n"
"                                        scene(scene_) {}\n"
"        virtual ~InstanceBase() {}\n"
"        virtual void init() {}\n"
"        virtual void deinit() {}\n"
"        virtual void handleInput() {}\n"
"        virtual void update() {}\n"
"        virtual void fixedUpdate(float timestep) {}\n"
"        virtual void preRender() {}\n"
"        virtual void postRender() {}\n"
"        virtual void serialize(Serializable& serialized) {}\n"
"        virtual void deserialize(const  Serializable& serialized) {}\n"
"        inline Entity *getEntity() const {return entity;}\n"
"    protected:"
"        Application *app;\n"
"        Platform *platform;\n"
"        ResourceManager *resMgr;\n"
"        GfxApi *gfxApi;\n"
"        Filesystem *fileSys;\n"
"        GfxDebugDrawer *debugDrawer;\n"
"        AudioDevice *audioDevice;\n"
"        Entity *entity;\n"
"        Script *script;\n"
"        Scene *scene;\n;\n"
"};\n"
"#endif\n"
"#define BEGIN_INSTANCE(name, inherits) class name : public inherits"
"{"
"    public:"
"        constexpr static const char *_name = STR(name);"
"        name(Application *app, Entity *entity, Scene *scene, Script *script) : inherits(app, entity, scene, script) {name::init();}"
"        virtual ~name() {name::deinit();}\n"
"#define END_INSTANCE(name) }; extern \"C\"{name *JOIN(_create, name)(Application *app, Entity *entity, Scene *scene, Script *script){"
"    return new name(app, entity, scene, script);"
"}"
"name *JOIN(_destroy, name)(name *obj)"
"{"
"    delete obj;"
"}}\n\n#line 1 \"";

class InstanceBase
{
    public:
        InstanceBase();
        virtual ~InstanceBase();

        virtual void init() {}
        virtual void deinit() {}
        virtual void handleInput() {}
        virtual void update() {}
        virtual void fixedUpdate(float timestep) {}
        virtual void preRender() {}
        virtual void postRender() {}
        virtual void serialize(Serializable& serialized) {}
        virtual void deserialize(const Serializable& serialized) {}
};

ScriptInstance::ScriptInstance(const char *name_,
                               Script *script_,
                               void *ptr_,
                               Entity *entity_,
                               Scene *scene_) : name(name_),
                                                script(script_),
                                                ptr(ptr_),
                                                entity(entity_),
                                                scene(scene_) {}

ScriptInstance::~ScriptInstance()
{
    script->destroyInstance(this);
}

void ScriptInstance::handleInput()
{
    if (ptr != nullptr)
    {
        ((InstanceBase *)ptr)->handleInput();
    }
}

void ScriptInstance::update()
{
    if (ptr != nullptr)
    {
        ((InstanceBase *)ptr)->update();
    }
}

void ScriptInstance::fixedUpdate(float timestep)
{
    if (ptr != nullptr)
    {
        ((InstanceBase *)ptr)->fixedUpdate(timestep);
    }
}

void ScriptInstance::preRender()
{
    if (ptr != nullptr)
    {
        ((InstanceBase *)ptr)->preRender();
    }
}

void ScriptInstance::postRender()
{
    if (ptr != nullptr)
    {
        ((InstanceBase *)ptr)->postRender();
    }
}

void ScriptInstance::serialize(Serializable& serialized)
{
    if (ptr != nullptr)
    {
        ((InstanceBase *)ptr)->serialize(serialized);
    }
}

void ScriptInstance::deserialize(const Serializable& serialized)
{
    if (ptr != nullptr)
    {
        ((InstanceBase *)ptr)->deserialize(serialized);
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

        void (*destroyFunc)(void *) = getDestroyFunc(instance->getName().getData());

        if (destroyFunc != nullptr)
        {
            destroyFunc(instance->ptr);
        }

        instance->ptr = nullptr;
    }

    dlclose(dl);
}

void Script::removeContent()
{
    if (dl != nullptr)
    {
        for (size_t i = 0; i < instances.getCount(); ++i)
        {
            ScriptInstance *instance = instances[i];

            void (*destroyFunc)(void *) = getDestroyFunc(instance->getName().getData());

            if (destroyFunc != nullptr)
            {
                destroyFunc(instance->ptr);
            }

            instance->ptr = nullptr;
        }

        dlclose(dl);
        dl = nullptr;
    }

    includes.clear();
    includesModifications.clear();
}

void Script::possiblyReload()
{
    bool includesDirty = false;

    for (size_t i = 0; i < includes.getCount(); ++i)
    {
        try
        {
            if (::getLastFileModification(includes[i].getData()) != includesModifications[i])
            {
                includesDirty = true;
            }
        } catch (FileException& e)
        {
            includesDirty = true;
        }
    }

    if (shouldReload() or includesDirty)
    {
        reload();
    }
}

void Script::_load()
{
    List<Serializable> serialized;

    if (dl != nullptr)
    {
        for (size_t i = 0; i < instances.getCount(); ++i)
        {
            Serializable serialized_;

            instances[i]->serialize(serialized_);

            serialized.append(serialized_);
        }
    }

    removeContent();

    String source;

    try
    {
        File sourceFile(getFilename().getData(), "r");
        source = String(sourceFile.getSize());
        sourceFile.read(sourceFile.getSize(), source.getData());
    } catch (const FileException& e)
    {
        THROW(ResourceIOException,
              "script",
              getFilename(),
              e.getString());
    }

    String scriptFilename = fileSys->getAbsolutePath(getFilename().getData());

    source = scriptStart.copy().append(scriptFilename).append("\"\n").append(source);

    int index = scriptFilename.findLast('/');

    String dir = scriptFilename.subStr(0, index);
    scriptFilename = scriptFilename.subStr(index+1, scriptFilename.getLength()-index-1);

    String binaryFilename = String::format("%s/bin/%s.so", dir.getData(), scriptFilename.getData());

    String binaryDirectory = String::format("%s/bin", dir.getData());

    mkdir(binaryDirectory.getData(), 0777);

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
              getFilename(),
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
                  getFilename(),
                  String::format("Unable to load compiled script at %s: %s",
                                 binaryFilename.getData(),
                                 dlerror()));

            return;
        }

        void (*initFunc)(const void *) = (void (*)(const void *))dlsym(dl, "_initFunctions");

        if (initFunc == nullptr)
        {
            dlclose(dl);

            dl = nullptr;

            THROW(ResourceIOException,
                  "script",
                  getFilename(),
                  String::format("Compiled script at %s does not contain the needed functions.",
                                 binaryFilename.getData()));
        } else
        {
            initFunc(getScriptFunctionStruct());

            for (size_t i = 0; i < instances.getCount(); ++i)
            {
                ScriptInstance *instance = instances[i];

                void *(*createFunc)(Application *, Entity *, Scene *, Script *) = getCreateFunc(instance->getName().getData());

                if (createFunc == nullptr)
                {
                    instance->ptr = nullptr;
                }

                instance->ptr = createFunc(app, instance->entity, instance->scene, this);

                if (serialized.getCount() != 0)
                {
                    try
                    {
                        instance->deserialize(serialized[i]);
                    } catch (SerializeException& e)
                    {
                        log("Serialization exception");
                        log("    File: %s\n", e.getFile());
                        log("    Line: %d\n", e.getLine());
                        log("    Function: %s\n", e.getFunction());
                        log("    Script: %s\n", getFilename().getData());

                        void (*destroyFunc)(void *) = getDestroyFunc(instance->getName().getData());

                        if (destroyFunc != nullptr)
                        {
                            destroyFunc(instance->ptr);
                            instance->ptr = createFunc(app, instance->entity, instance->scene, this);
                        } else
                        {
                            instance->ptr = nullptr;
                        }
                    }
                }
            }
        }
    } else
    {
        THROW(ResourceIOException,
              "script",
              getFilename(),
              String("Unable to execute command: ").append(command));
    }

    List<String> lines = source.split('\n');

    fileSys->pushSearchPaths();
    fileSys->addSearchPath(dir);

    for (size_t i = 0; i < lines.getCount(); ++i)
    {
        const String& line = lines[i];

        try
        {
            if (line.startsWith("#include"))
            {
                List<String> parts = line.split('"');
                String includedFile;

                if (parts.getCount() == 1)
                {
                    parts = line.split('<');

                    includedFile = parts[1].split('>')[0];
                } else
                {
                    includedFile = parts[1];
                }

                includedFile = fileSys->getAbsolutePath(includedFile.getData());

                if (includedFile.getLength() != 0)
                {
                    includes.append(includedFile);
                    includesModifications.append(::getLastFileModification(includedFile.getData()));
                }
            }
        } catch (BoundsException& e) {}
    }

    fileSys->popSearchPaths();
}

ScriptInstance *Script::createInstance(const char *name, Entity *entity, Scene *scene)
{
    if (entity != nullptr)
    {
        scene = entity->getScene();
    }

    void *(*createFunc)(Application *, Entity *, Scene *, Script *) = getCreateFunc(name);

    InstanceBase *ptr;

    if (createFunc == nullptr)
    {
        ptr = nullptr;
    } else
    {
        ptr = dl == nullptr ? nullptr : (InstanceBase *)createFunc(app, entity, scene, this);
    }

    ScriptInstance *result = NEW(ScriptInstance, name, this, ptr, entity, scene);

    instances.append(result);

    return result;
}

void *(*Script::getCreateFunc(const char *name))(Application *, Entity *, Scene *, Script *)
{
    if (dl == nullptr)
    {
        return nullptr;
    }

    String resName = String::format("_create%s", name);

    return (void *(*)(Application *, Entity *, Scene *, Script *))dlsym(dl, resName.getData());
}

void (*Script::getDestroyFunc(const char *name))(void *)
{
    if (dl == nullptr)
    {
        return nullptr;
    }

    String resName = String::format("_destroy%s", name);

    return (void (*)(void *))dlsym(dl, resName.getData());
}

void Script::destroyInstance(ScriptInstance *instance)
{
    if (instance->script == this and instance->ptr != nullptr)
    {
        void (*destroyFunc)(void *) = getDestroyFunc(instance->getName().getData());

        if (destroyFunc != nullptr)
        {
            destroyFunc(instance->ptr);
        }

        instances.remove(instances.find(instance));
    }
}

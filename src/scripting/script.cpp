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

void getIncludes(const String& source, List<String>& includes)
{
    List<String> lines = source.split('\n');

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

                    File f(includedFile.getData(), "r");

                    String source2(f.getSize());
                    f.read(source2.getLength(), source2.getData());

                    getIncludes(source2, includes);
                }
            }
        } catch (BoundsException& e) {}
    }
}

const void *getScriptFunctionStruct();

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
        virtual void handleMessage(BaseMessage *message) {}
        inline Entity *getEntity() const {return entity;}
    protected:
        Application *app;
        Platform *platform;
        ResourceManager *resMgr;
        GfxApi *gfxApi;
        Filesystem *fileSys;
        GfxDebugDrawer *debugDrawer;
        AudioDevice *audioDevice;
        Entity *entity;
        Script *script;
        Scene *scene;
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

void ScriptInstance::handleMessage(BaseMessage *message)
{
    if (ptr != nullptr)
    {
        ((InstanceBase *)ptr)->handleMessage(message);
    }
}

Script::Script() : Resource(ResType::ScriptType),
                   dl(nullptr) {}

Script::Script(const String& filename) : Resource(filename,
                                                  ResType::ScriptType),
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

    source = String("#include <scripting/scriptinclude.h>\n#line 0\"").append(scriptFilename).append("\"\n").append(source);

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

    fileSys->pushSearchPaths();
    fileSys->addSearchPath(dir);

    getIncludes(source, includes);

    fileSys->popSearchPaths();

    for (size_t i = 0; i < includes.getCount(); ++i)
    {
        includesModifications.append(::getLastFileModification(includes[i].getData()));
    }
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

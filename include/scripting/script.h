#ifndef SCRIPT_H
#define SCRIPT_H

#include "resource/resource.h"
#include "serialization.h"

#include <dlfcn.h>

class Script;
class Application;
class Entity;
class Scene;

void precompileScriptInclude();

class ScriptFunctionException : public Exception
{
    public:
        ScriptFunctionException(const char *file_,
                                size_t line_,
                                const char *function_,
                                String filename_,
                                String scriptFunction_,
                                String problem_) : Exception(file_, line_, function_),
                                                   filename(filename_),
                                                   scriptFunction(scriptFunction_),
                                                   problem(problem_) {}

        virtual const char *getString() const
        {
            static char string[FILENAME_MAX+256];
            std::memset(string, 0, sizeof(string));

            std::snprintf(string,
                          sizeof(string),
                          "Unable to do something with a function called \"%s\" at %s: %s",
                          scriptFunction.getData(),
                          filename.getData(),
                          problem.getData());

            return string;
        }

        inline const String& getFilename() const
        {
            return filename;
        }

        inline const String& getScriptFunction() const
        {
            return scriptFunction;
        }

        inline const String& getProblem() const
        {
            return problem;
        }
    private:
        String filename;
        String scriptFunction;
        String problem;
};

class BaseMessage
{
    public:
        virtual ~BaseMessage() {}

        template <typename T>
        inline T *cast()
        {
            if (name == T::_name)
            {
                return (T *)this;
            } else
            {
                return nullptr;
            }
        }

        template <typename T>
        inline T *cast() const
        {
            if (name == T::_name)
            {
                return (const T *)this;
            } else
            {
                return nullptr;
            }
        }
    private:
        const char *name;
    protected:
        BaseMessage(const char *name_) : name(name_) {}
};

class ScriptInstance
{
    NO_COPY(ScriptInstance)

    friend Script;

    public:
        ~ScriptInstance();

        void handleInput();
        void update();
        void fixedUpdate(float timestep);
        void preRender();
        void postRender();
        void serialize(Serializable& serialized);
        void deserialize(const Serializable& serialized);
        void handleMessage(BaseMessage *message);

        inline Script *getScript() const
        {
            return script;
        }

        inline const String& getName() const
        {
            return name;
        }

        inline void *getPointer() const
        {
            return ptr;
        }
    private:
        ScriptInstance(const char *name,
                       Script *script,
                       void *ptr,
                       Entity *entity,
                       Scene *scene);

        String name;
        Script *script;
        void *ptr;
        Entity *entity;
        Scene *scene;
};

class Script : public Resource
{
    friend ScriptInstance;

    NO_COPY_INHERITED(Script, Resource);

    public:
        static const ResType resource_type = ResType::ScriptType;

        Script();
        Script(const String& filename);

        virtual ~Script();

        virtual void removeContent();

        ScriptInstance *createInstance(const char *name, Entity *entity=nullptr, Scene *scene=nullptr);

        template <typename Return, typename ... Args>
        inline Return call(const String& name, Args... args)
        {
            return ((Return (*)(Args...))getFunction(name))(args...);
        }
    protected:
        virtual void _load();
    private:
        void *dl;

        List<ScriptInstance *> instances;
        List<String> includes;
        List<time_t> includesModifications;

        void *(*getCreateFunc(const char *name))(Application *, Entity *, Scene *, Script *);
        void (*getDestroyFunc(const char *name))(void *);

        void (*getFunction(const String& name))()
        {
            if (dl != nullptr)
            {
                void (*func)() = (void (*)())dlsym(dl, name.getData());

                if (func == nullptr)
                {
                    THROW(ScriptFunctionException, getFilename(), name, "No such function.");
                }

                return func;
            } else
            {
                THROW(ScriptFunctionException, getFilename(), name, "Script not loaded.");
            }
        }

        void destroyInstance(ScriptInstance *instance);
} DESTROY(obj->release());

#endif // SCRIPT_H

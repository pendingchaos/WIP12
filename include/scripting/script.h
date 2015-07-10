#ifndef SCRIPT_H
#define SCRIPT_H

#include "resource/resource.h"
#include "serialization.h"

#include <dlfcn.h>

class Script;
class Application;
class Entity;

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

        inline ResPtr<Script> getScript() const
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
                       ResPtr<Script> script,
                       void *ptr,
                       Entity *entity,
                       Scene *scene);

        String name;
        ResPtr<Script> script;
        void *ptr;
        Entity *entity;
        Scene *scene;
};

class UserData;

class Script : public Resource
{
    friend UserData;
    friend ScriptInstance;

    NO_COPY_INHERITED(Script, Resource);

    public:
        static const Type resource_type = ScriptType;

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
        List<UserData *> userDatas;

        void *(*getCreateFunc(const char *name))(Application *, Entity *, Scene *, Script *);
        void (*getDestroyFunc(const char *name))(void *);

        void (*getFunction(const String& name))()
        {
            if (dl != nullptr)
            {
                void (*func)() = (void (*)())dlsym(dl, name.getData());

                if (func == nullptr)
                {
                    THROW(ScriptFunctionException, filename, name, "No such function.");
                }

                return func;
            } else
            {
                THROW(ScriptFunctionException, filename, name, "Script not loaded.");
            }
        }

        void destroyInstance(ScriptInstance *instance);
};

template <typename Return, typename ... Args>
class ScriptFunction
{
    public:
        ScriptFunction(ResPtr<Script> script_, const char *name_) : script(script_),
                                                                    name(name_) {}

        inline ResPtr<Script> getScript() const
        {
            return script;
        }

        inline const String& getName() const
        {
            return name;
        }

        inline Return operator () (Args... args)
        {
            return script->call<Return>(name, args...);
        }
    private:
        ResPtr<Script> script;
        String name;
};

class UserData
{
    friend Script;

    public:
        UserData(const ScriptFunction<void *>& initFunc_,
                 const ScriptFunction<void, void *>& deinitFunc_) : initFunc(initFunc_),
                                                                    deinitFunc(deinitFunc_)
        {
            pointer = initFunc();

            initFunc.getScript()->userDatas.append(this);
        }

        ~UserData()
        {
            deinitFunc(pointer);

            List<UserData *> userDatas = initFunc.getScript()->userDatas;

            userDatas.remove(userDatas.find(this));
        }

        inline void *getPointer()
        {
            return pointer;
        }

        inline void reinit()
        {
            deinitFunc(pointer);

            pointer = initFunc();
        }
    private:
        ScriptFunction<void *> initFunc;
        ScriptFunction<void, void *> deinitFunc;
        void *pointer;
};

#endif // SCRIPT_H

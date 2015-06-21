#ifndef SCRIPT_H
#define SCRIPT_H

#include "resource/resource.h"

#include <dlfcn.h>

class Script;
class Application;
class Entity;

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
        void render();

        inline ResPtr<Script> getScript() const
        {
            return script;
        }
    private:
        ScriptInstance(Script *script,
                       void *ptr,
                       Entity *entity);

        Script *script;
        void *ptr;
        Entity *entity;
};

class Script : public Resource
{
    friend ScriptInstance;

    NO_COPY_INHERITED(Script, Resource);

    public:
        static const Type resource_type = ScriptType;

        Script();
        Script(const String& filename);

        virtual ~Script();

        virtual void removeContent();

        ScriptInstance *createInstance(Entity *entity=nullptr);

        template <typename Return, typename ... Args>
        Return call(const String& name, Args... args)
        {
            return ((Return (*)(Args...))getFunction(name))(args...);
        }
    protected:
        virtual void _load();
    private:
        void *dl;
        void *(*createFunc)(Application *, Entity *entity);
        void (*destroyFunc)(void *);

        List<ScriptInstance *> instances;

        inline void (*getFunction(const String& name))()
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

#endif // SCRIPT_H

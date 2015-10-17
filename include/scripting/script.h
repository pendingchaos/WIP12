#ifndef SCRIPT_H
#define SCRIPT_H

#include "resource/resource.h"
#include "scripting/vm/context.h"
#include "scripting/vm/types.h"

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
                                Str filename_,
                                Str scriptFunction_,
                                Str problem_) : Exception(file_, line_, function_),
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

        inline const Str& getFilename() const
        {
            return filename;
        }

        inline const Str& getScriptFunction() const
        {
            return scriptFunction;
        }

        inline const Str& getProblem() const
        {
            return problem;
        }
    private:
        Str filename;
        Str scriptFunction;
        Str problem;
};

class ScriptInstance
{
    NO_COPY(ScriptInstance)

    friend Script;

    public:
        ~ScriptInstance();

        void method(const Str& name);
        void method(const Str& name, float timestep);

        inline void handleInput()
        {
            method("handleInput");
        }

        inline void fixedUpdate(float timestep)
        {
            method("fixedUpdate", timestep);
        }

        inline void update()
        {
            method("update");
        }

        inline void preRender()
        {
            method("preRender");
        }

        inline void postRender()
        {
            method("postRender");
        }

        inline Script *getScript() const
        {
            return script;
        }

        inline scripting::Value getObj() const
        {
            return obj;
        }
    private:
        ScriptInstance(Script *script,
                       const scripting::Value& obj,
                       Entity *entity,
                       Scene *scene);

        Script *script;
        scripting::Value obj;
        Entity *entity;
        Scene *scene;

        void destroy();
} BIND NOT_COPYABLE;

class Script : public Resource
{
    friend ScriptInstance;

    NO_COPY_INHERITED(Script, Resource);

    public:
        static const ResType resource_type = ResType::ScriptType;

        Script();
        Script(const Str& filename);

        virtual ~Script();

        virtual void removeContent();

        ScriptInstance *createInstance(Entity *entity=nullptr, Scene *scene=nullptr) NO_BIND;

        inline scripting::Context *getContext() const NO_BIND
        {
            return context;
        }
    protected:
        virtual void _load();
    private:
        scripting::Context *context;
        scripting::Value class_;
        List<ScriptInstance *> instances;

        void removeInstance(ScriptInstance *instance);
} BIND DESTROY(obj->release());

#endif // SCRIPT_H

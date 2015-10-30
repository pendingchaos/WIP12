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
class GfxMaterial;

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

        const Str& getFilename() const
        {
            return filename;
        }

        const Str& getScriptFunction() const
        {
            return scriptFunction;
        }

        const Str& getProblem() const
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

        template <typename... Args>
        scripting::Value method(const Str& name, Args... args) NO_BIND
        {
            List<scripting::Value> list;
            buildArgs(list, args...);

            return method(name, list);
        }

        scripting::Value method(const Str& name) NO_BIND
        {
            return method(name, List<scripting::Value>());
        }

        scripting::Value method(const Str& name, const List<scripting::Value>& args) NO_BIND;

        Script *getScript() const
        {
            return script;
        }

        scripting::Value getObj() const
        {
            return obj;
        }
    private:
        template <typename... Args>
        void buildArgs(List<scripting::Value>& list, const scripting::Value& arg0, Args... args)
        {
            list.append(arg0);
            buildArgs(list, args...);
        }

        void buildArgs(List<scripting::Value>& list) {}

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

        ScriptInstance *createInstance(Entity *entity=nullptr, Scene *scene=nullptr, GfxMaterial *material=nullptr) NO_BIND;

        scripting::Context *getContext() const NO_BIND
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

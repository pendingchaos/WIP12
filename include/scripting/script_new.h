#ifndef SCRIPT_H
#define SCRIPT_H

#include "resource/resource.h"
#include "serialization.h"
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

        void serialize(Serializable& serialized);
        void deserialize(const Serializable& serialized);
        void method(const String& name);
        void method(const String& name, float timestep);

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

        inline const String& getName() const
        {
            return name;
        }

        inline scripting::Value *getObject() const
        {
            return obj;
        }
    private:
        ScriptInstance(const char *name,
                       Script *script,
                       scripting::Value *obj,
                       Entity *entity,
                       Scene *scene);

        String name;
        Script *script;
        scripting::Value *obj;
        Entity *entity;
        Scene *scene;

        void destroy();
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
        virtual void possiblyReload();

        //TODO: Get rid of name.
        ScriptInstance *createInstance(const char *name, Entity *entity=nullptr, Scene *scene=nullptr);

        inline scripting::Context *getContext() const
        {
            return context;
        }
    protected:
        virtual void _load();
    private:
        scripting::Context *context;
        scripting::Value *class_;
        List<ScriptInstance *> instances;

        void removeInstance(ScriptInstance *instance);
} DESTROY(obj->release());

#endif // SCRIPT_H
#ifndef SCRIPT_H
#define SCRIPT_H

#include "resource/resource.h"

class Script;
class Application;
class Entity;

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

        Script(const String& name);
        Script(const String& filename,
               const String& name);

        virtual ~Script();

        virtual void removeContent();

        ScriptInstance *createInstance(Entity *entity=nullptr);
    protected:
        virtual void _load();
    private:
        void *dl;
        void *(*createFunc)(Application *, Entity *entity);
        void (*destroyFunc)(void *);

        List<ScriptInstance *> instances;

        void destroyInstance(ScriptInstance *instance);
};

#endif // SCRIPT_H

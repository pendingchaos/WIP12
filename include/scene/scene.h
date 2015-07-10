#ifndef SCENE_H
#define SCENE_H

#include "containers/list.h"
#include "containers/string.h"
#include "graphics/camera.h"
#include "graphics/gfxtexture.h"
#include "resource/resource.h"
#include "scene/entity.h"
#include "memory.h"

class PhysicsWorld;
class GfxShader;
class GfxMesh;
class GfxBuffer;
class GfxRenderer;
class AudioWorld;

class Scene : public Resource
{
    NO_COPY_INHERITED(Scene, Resource);

    public:
        static const Resource::Type resource_type = Resource::SceneType;

        Scene();
        Scene(const String& filename);
        virtual ~Scene();

        virtual void removeContent();

        void handleInput();
        void update();
        void fixedUpdate(float timestep);
        void render();

        inline PhysicsWorld *getPhysicsWorld() const
        {
            return physicsWorld;
        }

        inline GfxRenderer *getRenderer() const
        {
            return renderer;
        }

        inline AudioWorld *getAudioWorld() const
        {
            return audioWorld;
        }

        virtual void save();

        Entity *createEntity(const String& name);
        void removeEntity(size_t index);

        inline const List<Entity *>& getEntities() const
        {
            return entities;
        }

        inline bool addScript(ResPtr<Script> script, const char *name)
        {
            ScriptInstance *inst = findScriptInstanceByName(name);

            if (inst == nullptr)
            {
                scripts.append(script->createInstance(name, nullptr, this));

                return true;
            }

            return false;
        }

        inline void removeScript(ScriptInstance *instance)
        {
            int index = scripts.find(instance);

            if (index != -1)
            {
                scripts.remove(index);

                DELETE(ScriptInstance, instance);
            }
        }

        inline const List<ScriptInstance *>& getScripts() const
        {
            return scripts;
        }

        inline ScriptInstance *findScriptInstanceByName(const char *name) const
        {
            for (size_t i = 0; i < scripts.getCount(); ++i)
            {
                if (scripts[i]->getName() == name)
                {
                    return scripts[i];
                }
            }

            return nullptr;
        }

        #ifdef IN_SCRIPT
        template <typename T>
        inline T *findScriptInstance() const
        {
            ScriptInstance *inst = findScriptInstanceByName(T::_name);

            if (inst == nullptr)
            {
                return nullptr;
            }

            return (T *)inst->getPointer();
        }
        #endif
    private:
        List<ScriptInstance *> scripts;
        GfxRenderer *renderer;
        AudioWorld *audioWorld;
        List<Entity *> entities;

        void _handleInput(const List<Entity *>& entities_);
        void _update(const List<Entity *>& entities_);
        void _fixedUpdate(const List<Entity *>& entities_, float timestep);

        PhysicsWorld *physicsWorld;
    protected:
        virtual void _load();
};

#endif // SCENE_H

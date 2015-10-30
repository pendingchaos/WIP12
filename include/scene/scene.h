#ifndef SCENE_H
#define SCENE_H

#include "containers/list.h"
#include "containers/string.h"
#include "graphics/camera.h"
#include "graphics/gfxtexture.h"
#include "resource/resource.h"
#include "scene/entity.h"
#include "memory.h"
#include "scripting/bindings.h"

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
        static const ResType resource_type = ResType::SceneType;

        Scene();
        Scene(const Str& filename);
        virtual ~Scene();

        virtual void removeContent();

        void handleInput();
        void update();
        void fixedUpdate(float timestep);
        void render();

        PhysicsWorld *getPhysicsWorld() const
        {
            return physicsWorld;
        }

        GfxRenderer *getRenderer() const
        {
            return renderer;
        }

        AudioWorld *getAudioWorld() const
        {
            return audioWorld;
        }

        virtual void save();

        Entity *createEntity(const Str& name);
        void removeEntity(size_t index);
        Entity *findEntity(const Str& name);

        const List<Entity *>& getEntities() const
        {
            return entities;
        }

        ScriptInstance *addScript(Script *script)
        {
            ScriptInstance *inst = findScriptInstance(script->getFilename());

            if (inst == nullptr)
            {
                ScriptInstance *new_ = script->createInstance(nullptr, this);

                scripts.append(new_);

                return new_;
            }

            return nullptr;
        }

        void removeScript(ScriptInstance *instance)
        {
            int index = scripts.find(instance);

            if (index != -1)
            {
                scripts.remove(index);

                DELETE(instance);
            }
        }

        const List<ScriptInstance *>& getScripts() const
        {
            return scripts;
        }

        ScriptInstance *findScriptInstance(const Str& filename) const
        {
            for (auto script : scripts)
            {
                if (script->getScript()->getFilename() == filename)
                {
                    return script;
                }
            }

            return nullptr;
        }
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
        virtual Resource *_copy() const;
} DESTROY(obj->release()) BIND;

#endif // SCENE_H

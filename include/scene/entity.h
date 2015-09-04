#ifndef ENTITY_H
#define ENTITY_H

#include "containers/string.h"
#include "containers/list.h"
#include "scene/transform.h"
#include "misc_macros.h"
#include "memory.h"
#include "physics/rigidbody.h"
#include "physics/physicsworld.h"
#include "graphics/gfxmodel.h"
#include "scripting/script.h"
#include "audio/audioworld.h"
#include "scripting/bindings.h"

class Scene;
class Entity;

class RenderComponent
{
    friend Entity;

    public:
        enum Type
        {
            Nothing,
            Model,
            Overlay
        };

        NO_BIND Type type;

        GfxModel *model;
        GfxTexture *overlayTexture;

        union
        {
            NO_BIND struct
            {
                bool shadowCaster;
            } modelData;
            NO_BIND struct
            {
                Float3 color;
            } overlayData;
        } NO_BIND;
    private:
        RenderComponent() : type(Nothing) {}
        ~RenderComponent() {}
} BIND;

class Entity
{
    friend Scene;

    private:
        Entity(const String& name, Scene *scene);
        ~Entity();
    public:
        inline ScriptInstance *addScript(Script *script, const char *name) NO_BIND
        {
            ScriptInstance *inst = findScriptInstanceByName(name);

            if (inst == nullptr)
            {
                ScriptInstance *new_ = script->createInstance(name, this);

                scripts.append(new_);

                return new_;
            }

            return nullptr;
        }

        inline void removeScript(ScriptInstance *instance) NO_BIND
        {
            int index = scripts.find(instance);

            if (index != -1)
            {
                scripts.remove(index);

                DELETE(instance);
            }
        }

        inline const List<ScriptInstance *>& getScripts() const NO_BIND
        {
            return scripts;
        }

        inline ScriptInstance *findScriptInstanceByName(const char *name) const NO_BIND
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

        RigidBody *addRigidBody(const RigidBodyConstructionInfo& info,
                                PhysicsShape *shape);

        inline RigidBody *getRigidBody() const
        {
            return rigidBody;
        }

        inline void removeRigidBody()
        {
            if (rigidBody != nullptr)
            {
                rigidBody->getWorld()->destroyRigidBody(rigidBody);
                rigidBody = nullptr;
            }
        }

        inline bool hasRigidBody() const
        {
            return rigidBody != nullptr;
        }

        inline void addModel(GfxModel *model, bool shadowCaster=true)
        {
            render = true;
            renderComponent.type = RenderComponent::Model;
            renderComponent.overlayTexture = nullptr;
            renderComponent.model = model;
            renderComponent.modelData.shadowCaster = shadowCaster;
        }

        inline void addOverlay(GfxTexture *texture)
        {
            render = true;
            renderComponent.type = RenderComponent::Overlay;
            renderComponent.model = nullptr;
            renderComponent.overlayTexture = texture;
            renderComponent.overlayData.color = Float3(1.0f);
        }

        inline void removeRenderComponent()
        {
            render = false;
        }

        inline RenderComponent *getRenderComponent()
        {
            return &renderComponent;
        }

        inline const RenderComponent *getRenderComponent() const
        {
            return &renderComponent;
        }

        inline bool hasRenderComponent() const
        {
            return render;
        }

        Scene *getScene() const;

        Entity *createEntity(const String& name);
        void removeEntity(size_t index);

        inline const List<Entity *>& getEntities() const
        {
            return entities;
        }

        inline Entity *getParent() const
        {
            return parent;
        }

        void updateFinalTransform();

        inline const Matrix4x4& getFinalTransform() const
        {
            return finalTransform;
        }

        inline const List<AudioSource *>& getAudioSources() const
        {
            return audioSources;
        }

        AudioSource *addAudioSource(Audio *audio);
        void removeAudioSource(size_t index);

        String name;
        Transform transform;
    private:
        List<ScriptInstance *> scripts;
        RigidBody *rigidBody;
        bool render;
        RenderComponent renderComponent;
        mutable Scene *scene;
        List<Entity *> entities;
        Entity *parent;
        Matrix4x4 finalTransform;
        List<AudioSource *> audioSources;

    NO_COPY(Entity);
} BIND NOT_COPYABLE;

#endif // ENTITY_H

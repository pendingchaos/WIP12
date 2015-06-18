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

        Type type;

        ResPtr<GfxModel> model;
        ResPtr<GfxTexture> overlayTexture;

        union
        {
            struct
            {
                bool shadowCaster;
            } modelData;
            struct
            {
                Float3 color;
            } overlayData;
        };
    private:
        RenderComponent() : type(Nothing) {}
        ~RenderComponent() {}
};

class Entity
{
    friend Scene;

    private:
        Entity(const String& name, ResPtr<Scene> scene);
        ~Entity();
    public:
        inline void addScript(ResPtr<Script> script)
        {
            scripts.append(script->createInstance(this));
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

        inline const List<ScriptInstance *> getScripts() const
        {
            return scripts;
        }

        void addRigidBody(PhysicsWorld *world,
                          const RigidBody::ConstructionInfo& info);

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

        inline void addModel(ResPtr<GfxModel> model, bool shadowCaster=true)
        {
            render = true;
            renderComponent.type = RenderComponent::Model;
            renderComponent.overlayTexture = nullptr;
            renderComponent.model = model;
            renderComponent.modelData.shadowCaster = shadowCaster;
        }

        inline void addOverlay(ResPtr<GfxTexture> texture)
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

        inline bool operator == (const Entity& other) const
        {
            return this == &other;
        }

        inline ResPtr<Scene>& getScene() const
        {
            return scene;
        }

        String name;
        Transform transform;
    private:
        List<ScriptInstance *> scripts;
        RigidBody *rigidBody;
        bool render;
        RenderComponent renderComponent;
        mutable ResPtr<Scene> scene;

    NO_COPY(Entity);
};

#endif // ENTITY_H

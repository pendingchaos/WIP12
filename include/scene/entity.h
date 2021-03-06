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

#include <SDL2/SDL_assert.h>

class Scene;
class Entity;

enum class RenderMode
{
    Nothing,
    Model,
    Overlay
} BIND ENUM_CLASS;

class RenderComponent
{
    friend Entity;

    NO_COPY(RenderComponent)

    public:
        RenderMode mode;

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

        bool getShadowCaster() const
        {
            if (mode == RenderMode::Model)
            {
                return modelData.shadowCaster;
            }

            return false;
        }

        void setShadowCaster(bool caster)
        {
            if (mode == RenderMode::Model)
            {
                modelData.shadowCaster = caster;
            }
        }

        Float3 getOverlayColor() const
        {
            if (mode == RenderMode::Overlay)
            {
                return overlayData.color;
            }

            return Float3(0.0f);
        }

        void setOverlayColor(const Float3& color)
        {
            if (mode == RenderMode::Overlay)
            {
                overlayData.color = color;
            }
        }

        void setAnimationState(GfxMesh *mesh,
                               const Str& animName)
        {
            if (animation != nullptr)
            {
                DELETE(animation);
            }

            animation = NEW(GfxAnimationState, mesh, animName);
        }

        void removeAnimationState()
        {
            DELETE(animation);
            animation = nullptr;
        }

        GfxAnimationState *getAnimationState() const
        {
            return animation;
        }
    private:
        RenderComponent() : mode(RenderMode::Nothing), animation(nullptr) {}
        ~RenderComponent() {}

        GfxAnimationState *animation;
} BIND NOT_COPYABLE;

class Entity
{
    friend Scene;

    private:
        Entity(const Str& name, Scene *scene);
        ~Entity();
    public:
        ScriptInstance *addScript(Script *script)
        {
            ScriptInstance *inst = findScriptInstance(script->getFilename());

            if (inst == nullptr)
            {
                ScriptInstance *new_ = script->createInstance(this);

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
                SDL_assert_paranoid(index >= 0);

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

        scripting::Value findScriptInstanceObj(const Str& filename) const;

        RigidBody *addRigidBody(const RigidBodyConstructionInfo& info,
                                PhysicsShape *shape);

        RigidBody *getRigidBody() const
        {
            return rigidBody;
        }

        void removeRigidBody()
        {
            if (rigidBody != nullptr)
            {
                rigidBody->getWorld()->destroyRigidBody(rigidBody);
                rigidBody = nullptr;
            }
        }

        bool hasRigidBody() const
        {
            return rigidBody != nullptr;
        }

        void addModel(GfxModel *model, bool shadowCaster=true)
        {
            render = true;
            renderComponent.mode = RenderMode::Model;
            renderComponent.overlayTexture = nullptr;
            renderComponent.model = model;
            renderComponent.modelData.shadowCaster = shadowCaster;
        }

        void addOverlay(GfxTexture *texture)
        {
            render = true;
            renderComponent.mode = RenderMode::Overlay;
            renderComponent.model = nullptr;
            renderComponent.overlayTexture = texture;
            renderComponent.overlayData.color = Float3(1.0f);
        }

        void removeRenderComponent()
        {
            render = false;
        }

        RenderComponent *getRenderComponent()
        {
            return &renderComponent;
        }

        const RenderComponent *getRenderComponent() const
        {
            return &renderComponent;
        }

        bool hasRenderComponent() const
        {
            return render;
        }

        Scene *getScene() const
        {
            return scene;
        }

        Entity *createEntity(const Str& name);
        void removeEntity(size_t index);
        Entity *findEntity(const Str& name);

        const List<Entity *>& getEntities() const
        {
            return entities;
        }

        Entity *getParent() const
        {
            return parent;
        }

        void updateFinalTransform();

        const Matrix4x4& getFinalTransform() const
        {
            return finalTransform;
        }

        const Matrix4x4& getFinalTransformNoScale() const
        {
            return finalTransformNoScale;
        }

        const List<AudioSource *>& getAudioSources() const
        {
            return audioSources;
        }

        AudioSource *addAudioSource(Audio *audio);
        void removeAudioSource(size_t index);

        Str name;
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
        Matrix4x4 finalTransformNoScale;
        List<AudioSource *> audioSources;

    NO_COPY(Entity);
} BIND NOT_COPYABLE;

#endif // ENTITY_H

#include "scene/entity.h"

#include "scene/scene.h"
#include "backtrace.h"

Entity::Entity(const String& name_,
               Scene *scene_) : name(name_),
                                rigidBody(nullptr),
                                render(false),
                                scene(scene_),
                                userData(nullptr) {}

Entity::~Entity()
{
    List<ResPtr<Script>> scripts_;

    for (size_t i = 0; i < scripts.getCount(); ++i)
    {
        scripts_.append(scripts[i]->getScript());

        DELETE(ScriptInstance, scripts[i]);
    }

    for (size_t i = 0; i < scripts_.getCount(); ++i)
    {
        scripts_[i]->release();
    }

    if (render)
    {
        if (renderComponent.type == RenderComponent::Model)
        {
            renderComponent.model->release();
        } else if (renderComponent.type == RenderComponent::Overlay)
        {
            renderComponent.overlayTexture->release();
        }
    }

    removeRigidBody();
    removeUserData();
}

void Entity::addRigidBody(PhysicsWorld *world,
                          const RigidBody::ConstructionInfo& info,
                          ResPtr<PhysicsShape> shape)
{
    RigidBody::ConstructionInfo newInfo = info;

    newInfo.transform = &transform;

    rigidBody = world->createRigidBody(newInfo, shape);
}

ResPtr<Scene> Entity::getScene() const
{
    return scene;
}

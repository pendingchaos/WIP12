#include "scene/entity.h"

#include "scene/scene.h"
#include "backtrace.h"

Entity::Entity(const String& name_,
               Scene *scene_) : name(name_),
                                rigidBody(nullptr),
                                render(false),
                                scene(scene_),
                                userData(nullptr),
                                parent(nullptr) {}

Entity::~Entity()
{
    for (size_t i = 0; i < entities.getCount(); ++i)
    {
        DELETE(Entity, entities[i]);
    }

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
    updateFinalTransform();

    RigidBody::ConstructionInfo newInfo = info;

    newInfo.entity = this;

    rigidBody = world->createRigidBody(newInfo, shape);
}

ResPtr<Scene> Entity::getScene() const
{
    return scene;
}

Entity *Entity::createEntity(const String& name)
{
    Entity *entity = NEW(Entity, name, scene);

    entity->parent = this;

    entities.append(entity);

    return entity;
}

void Entity::removeEntity(size_t index)
{
    DELETE(Entity, entities[index]);

    entities.remove(index);
}

void Entity::updateFinalTransform()
{
    if (parent != nullptr)
    {
        finalTransform = parent->getFinalTransform() * transform.createMatrix();
    } else
    {
        finalTransform = transform.createMatrix();
    }

    for (size_t i = 0; i < entities.getCount(); ++i)
    {
        entities[i]->updateFinalTransform();
    }
}

#include "scene/entity.h"

#include "scene/scene.h"
#include "backtrace.h"

Entity::Entity(const String& name_,
               Scene *scene_) : name(name_),
                                rigidBody(nullptr),
                                render(false),
                                scene(scene_),
                                parent(nullptr) {}

Entity::~Entity()
{
    for (size_t i = 0; i < entities.getCount(); ++i)
    {
        DELETE(entities[i]);
    }

    List<Script *> scripts_;

    for (size_t i = 0; i < scripts.getCount(); ++i)
    {
        scripts_.append(scripts[i]->getScript());

        DELETE(scripts[i]);
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
}

RigidBody *Entity::addRigidBody(const RigidBody::ConstructionInfo& info,
                                PhysicsShape *shape)
{
    updateFinalTransform();

    RigidBody::ConstructionInfo newInfo = info;

    newInfo.entity = this;

    rigidBody = scene->getPhysicsWorld()->createRigidBody(newInfo, shape);

    return rigidBody;
}

Scene *Entity::getScene() const
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
    DELETE(entities[index]);

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

AudioSource *Entity::addAudioSource(Audio *audio)
{
    AudioSource *source = scene->getAudioWorld()->createSource(audio);

    audioSources.append(source);

    return source;
}

void Entity::removeAudioSource(size_t index)
{
    scene->getAudioWorld()->destroySource(audioSources[index]);

    audioSources.remove(index);
}

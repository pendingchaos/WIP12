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
    for (auto child : entities)
    {
        DELETE(child);
    }

    List<Script *> scripts_;

    for (auto scriptInst : scripts)
    {
        scripts_.append(scriptInst->getScript());

        DELETE(scriptInst);
    }

    for (auto script : scripts_)
    {
        script->release();
    }

    if (render)
    {
        if (renderComponent.mode == RenderMode::Model)
        {
            renderComponent.model->release();
        } else if (renderComponent.mode == RenderMode::Overlay)
        {
            renderComponent.overlayTexture->release();
        }
    }

    removeRigidBody();
}

RigidBody *Entity::addRigidBody(const RigidBodyConstructionInfo& info,
                                PhysicsShape *shape)
{
    updateFinalTransform();

    RigidBodyConstructionInfo newInfo = info;

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

    for (auto child : entities)
    {
        child->updateFinalTransform();
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

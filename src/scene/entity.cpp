#include "scene/entity.h"

#include "scene/scene.h"

Entity::Entity(const String& name_,
               ResPtr<Scene> scene_) : name(name_),
                                       rigidBody(nullptr),
                                       render(false),
                                       scene(scene_),
                                       userData(nullptr) {}

Entity::~Entity()
{
    for (size_t i = 0; i < scripts.getCount(); ++i)
    {
        DELETE(ScriptInstance, scripts[i]);
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

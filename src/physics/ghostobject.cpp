#include "physics/ghostobject.h"

#include "physics/physicsworld.h"

GhostObject::GhostObject(unsigned short collisionMask,
                         PhysicsWorld *world_,
                         ResPtr<PhysicsShape> shape_) : shape(shape_),
                                                        world(world_),
                                                        userData(nullptr),
                                                        collisionMask(collisionMask)
{
    shape->ghosts.append(this);

    ghostObject = NEW(btPairCachingGhostObject);

    ghostObject->setUserPointer(this);
    ghostObject->setCollisionShape(shape->getBulletShape());
    ghostObject->setCollisionFlags(ghostObject->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);

    world->getBulletWorld()->addCollisionObject(ghostObject, 0xFFFF, collisionMask);
}

GhostObject::~GhostObject()
{
    shape->release();

    removeUserData();

    world->getBulletWorld()->removeCollisionObject(ghostObject);

    DELETE(btPairCachingGhostObject, ghostObject);
}

Transform GhostObject::getTransform()
{
    Transform transform;
    btTransform bullet = ghostObject->getWorldTransform();

    transform.position = Position3D(bullet.getOrigin().getX(),
                                    bullet.getOrigin().getY(),
                                    bullet.getOrigin().getZ());

    transform.orientation = Quaternion(bullet.getRotation().getX(),
                                       bullet.getRotation().getY(),
                                       bullet.getRotation().getZ(),
                                       bullet.getRotation().getW());

    return transform;
}

void GhostObject::setTransform(const Transform& transform) const
{
    btTransform bullet;

    bullet.setOrigin(btVector3(transform.position.x,
                               transform.position.y,
                               transform.position.z));

    bullet.setRotation(btQuaternion(transform.orientation.x,
                                    transform.orientation.y,
                                    transform.orientation.z,
                                    transform.orientation.w));

    ghostObject->setWorldTransform(bullet);
}

#define UPDATE_SHAPE ghostObject->setCollisionShape(shape->getBulletShape());

void GhostObject::setShape(ResPtr<PhysicsShape> shape_)
{
    shape->ghosts.remove(shape->ghosts.find(this));

    shape->release();

    shape = shape_;

    shape->ghosts.append(this);

    ghostObject->setCollisionShape(shape->getBulletShape());
}

void GhostObject::getCollisions(List<RigidBody *>& rigidBodies, List<GhostObject *>& ghostObjects) const
{
    for (size_t i = 0; (int)i < ghostObject->getNumOverlappingObjects(); ++i)
    {
        btCollisionObject *obj = ghostObject->getOverlappingObject(i);

        if (not ghostObject->checkCollideWith(obj))
        {
            continue;
        }

        if (dynamic_cast<const btRigidBody *>(obj) != nullptr)
        {
            rigidBodies.append((RigidBody *)obj->getUserPointer());
        } else
        {
            ghostObjects.append((GhostObject *)obj->getUserPointer());
        }
    }
}

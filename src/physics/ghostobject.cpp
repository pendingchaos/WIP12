#include "physics/ghostobject.h"

#include "physics/physicsworld.h"

GhostObject::GhostObject(unsigned short collisionMask,
                         PhysicsWorld *world_) : shape(NEW(PhysicsShape)),
                                                 world(world_),
                                                 userData(nullptr),
                                                 collisionMask(collisionMask)
{
    ghostObject = NEW(btPairCachingGhostObject);

    ghostObject->setUserPointer(this);
    ghostObject->setCollisionShape(shape->getBulletShape());
    ghostObject->setCollisionFlags(ghostObject->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);

    world->getBulletWorld()->addCollisionObject(ghostObject, 0xFFFF, collisionMask);
}

GhostObject::~GhostObject()
{
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

void GhostObject::setEmpty()
{
    shape->setEmpty();

    UPDATE_SHAPE
}

void GhostObject::setSphere(float radius)
{
    shape->setSphere(radius);

    UPDATE_SHAPE
}

void GhostObject::setBox(const Vector3D& halfExtents)
{
    shape->setBox(halfExtents);

    UPDATE_SHAPE
}

void GhostObject::setCylinder(PhysicsCylinderShape::Axis axis,
                              float height,
                              float radius)
{
    shape->setCylinder(axis, height, radius);

    UPDATE_SHAPE
}

void GhostObject::setCapsule(PhysicsCapsuleShape::Axis axis,
                             float height,
                             float radius)
{
    shape->setCapsule(axis, height, radius);

    UPDATE_SHAPE
}

void GhostObject::setCone(PhysicsConeShape::Axis axis,
                          float height,
                          float radius)
{
    shape->setCone(axis, height, radius);

    UPDATE_SHAPE
}

void GhostObject::setConvexHull(size_t pointCount, const Position3D *points)
{
    shape->setConvexHull(pointCount, points);

    UPDATE_SHAPE
}

void GhostObject::setStaticTriangleMesh(size_t vertexCount, const Position3D *vertices)
{
    shape->setStaticTriangleMesh(vertexCount, vertices);

    UPDATE_SHAPE
}

void GhostObject::setHeightfield(uint32_t width, uint32_t height, const float *data)
{
    shape->setHeightfield(width, height, data);

    UPDATE_SHAPE
}

void GhostObject::setPlane(const Vector3D& normal, float distance)
{
    shape->setPlane(normal, distance);

    UPDATE_SHAPE
}

void GhostObject::setCompound(size_t childCount, const PhysicsCompoundShape::Child *children)
{
    shape->setCompound(childCount, children);

    UPDATE_SHAPE
}

void GhostObject::setShape(ResPtr<PhysicsShape> shape_)
{
    shape = shape_;

    UPDATE_SHAPE
}

#undef UPDATE_SHAPE

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

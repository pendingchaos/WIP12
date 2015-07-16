#ifndef GHOSTOBJECT_H
#define GHOSTOBJECT_H

#include "physics/physicsshape.h"
#include "scripting/script.h"
#include "scene/transform.h"

#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"
#include "BulletCollision/CollisionDispatch/btGhostObject.h"

class PhysicsWorld;
class RigidBody;

class GhostObject
{
    friend PhysicsWorld;
    friend PhysicsShapeImpl;

    public:
        inline btGhostObject *getBulletGhostObject() const
        {
            return ghostObject;
        }

        Transform getTransform();
        void setTransform(const Transform& transform) const;

        inline PhysicsWorld *getWorld() const
        {
            return world;
        }

        inline short getCollisionMask() const
        {
            return collisionMask;
        }

        void setShape(PhysicsShape *shape);

        void getCollisions(List<RigidBody *>& rigidBodies, List<GhostObject *>& ghostObjects) const;

        inline PhysicsShape *getShape() const
        {
            return shape;
        }
    private:
        GhostObject(unsigned short collisionMask, PhysicsWorld *world, PhysicsShape *shape);
        ~GhostObject();

        PhysicsShape *shape;
        btPairCachingGhostObject *ghostObject;
        PhysicsWorld *world;
        unsigned short collisionMask;
};

#endif // GHOSTOBJECT_H

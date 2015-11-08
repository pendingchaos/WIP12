#ifndef GHOSTOBJECT_H
#define GHOSTOBJECT_H

#include "physics/physicsshape.h"
#include "scene/transform.h"
#include "scripting/bindings.h"

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
        btGhostObject *getBulletGhostObject() const NO_BIND
        {
            return ghostObject;
        }

        Transform getTransform();
        void setTransform(const Transform& transform) const;

        PhysicsWorld *getWorld() const
        {
            return world;
        }

        short getCollisionMask() const
        {
            return collisionMask;
        }

        void setShape(PhysicsShape *shape);

        void getCollisions(List<RigidBody *>& rigidBodies, List<GhostObject *>& ghostObjects) const NO_BIND;

        List<RigidBody *> getRigidBodyCollisions() const
        {
            List<RigidBody *> bodies;
            List<GhostObject *> ghosts;
            getCollisions(bodies, ghosts);
            return bodies;
        }

        List<GhostObject *> getGhostCollisions() const
        {
            List<RigidBody *> bodies;
            List<GhostObject *> ghosts;
            getCollisions(bodies, ghosts);
            return ghosts;
        }

        PhysicsShape *getShape() const
        {
            return shape;
        }
    private:
        GhostObject(short collisionMask, PhysicsWorld *world, PhysicsShape *shape);
        ~GhostObject();

        PhysicsShape *shape;
        btPairCachingGhostObject *ghostObject;
        PhysicsWorld *world;
        short collisionMask;
} BIND;

#endif // GHOSTOBJECT_H

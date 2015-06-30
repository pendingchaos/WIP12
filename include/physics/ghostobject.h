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
    friend PhysicsShape;

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

        void setShape(ResPtr<PhysicsShape> shape);

        void getCollisions(List<RigidBody *>& rigidBodies, List<GhostObject *>& ghostObjects) const;

        inline ResPtr<PhysicsShape> getShape() const
        {
            return shape;
        }

        inline void setUserData(const ScriptFunction<void *>& initFunc,
                                const ScriptFunction<void, void *>& deinitFunc)
        {
            userData = NEW(UserData, initFunc, deinitFunc);
        }

        inline void removeUserData()
        {
            DELETE(UserData, userData);
        }

        inline UserData *getUserData()
        {
            return userData;
        }
    private:
        GhostObject(unsigned short collisionMask, PhysicsWorld *world, ResPtr<PhysicsShape> shape);
        ~GhostObject();

        ResPtr<PhysicsShape> shape;
        btPairCachingGhostObject *ghostObject;
        PhysicsWorld *world;
        UserData *userData;
        unsigned short collisionMask;
};

#endif // GHOSTOBJECT_H

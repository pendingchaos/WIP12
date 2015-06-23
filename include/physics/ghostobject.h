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

        void setEmpty();
        void setSphere(float radius);
        void setBox(const Vector3D& halfExtents);
        void setCylinder(PhysicsCylinderShape::Axis axis, float height, float radius);
        void setCapsule(PhysicsCapsuleShape::Axis axis, float height, float radius);
        void setCone(PhysicsConeShape::Axis axis, float height, float radius);
        void setConvexHull(size_t pointCount, const Position3D *points);
        void setStaticTriangleMesh(size_t numVertices, const Position3D *vertices);
        void setHeightfield(uint32_t width, uint32_t height, const float *data);
        void setPlane(const Vector3D& normal, float distance);
        void setCompound(size_t childCount, const PhysicsCompoundShape::Child *children);
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
        GhostObject(unsigned short collisionMask, PhysicsWorld *world);
        ~GhostObject();

        ResPtr<PhysicsShape> shape;
        btPairCachingGhostObject *ghostObject;
        PhysicsWorld *world;
        UserData *userData;
        unsigned short collisionMask;
};

#endif // GHOSTOBJECT_H

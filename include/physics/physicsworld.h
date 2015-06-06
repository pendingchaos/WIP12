#ifndef PHYSICSWORLD_H
#define PHYSICSWORLD_H

#include "math/t3.h"
#include "physics/rigidbody.h"
#include "physics/physicsdebugdrawer.h"
#include "containers/list.h"

#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"
#include <stddef.h>

class ResourceManager;
class Camera;

class PhysicsWorld
{
    public:
        PhysicsWorld();
        virtual ~PhysicsWorld();

        void addDebugDrawer();

        inline void setGravity(const Vector3D& gravity)
        {
            world->setGravity(btVector3(gravity.x, gravity.y, gravity.z));
        }

        inline Vector3D getGravity() const
        {
            btVector3 gravity = world->getGravity();

            return Vector3D(gravity.getX(), gravity.getY(), gravity.getZ());
        }

        inline const List<RigidBody *>& getRigidBodies() const
        {
            return rigidBodies;
        }

        RigidBody *createRigidBody(const RigidBody::ConstructionInfo& info);

        void destroyRigidBody(RigidBody *rigidBody);

        void stepSimulation(float timeStep,
                            size_t maxSubSteps=1,
                            float fixedTimeStep=1.0f/60.0f);

        void debugDraw();

        inline btDynamicsWorld *getBulletWorld()
        {
            return world;
        }
    private:
        btCollisionConfiguration *configuration;
        btCollisionDispatcher *dispatcher;
        btBroadphaseInterface *broadphase;
        btConstraintSolver *solver;
        btDynamicsWorld *world;
        List<RigidBody *> rigidBodies;
        PhysicsDebugDrawer *debugDrawer;
};

#endif // PHYSICSWORLD_H

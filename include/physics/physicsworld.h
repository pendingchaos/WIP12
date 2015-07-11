#ifndef PHYSICSWORLD_H
#define PHYSICSWORLD_H

#include "math/t3.h"
#include "physics/rigidbody.h"
#include "physics/ghostobject.h"
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
        struct RayCastResult
        {
            enum ObjectType
            {
                Body,
                Ghost
            };

            float distance;
            Direction3D normal;
            ObjectType objType;

            union
            {
                RigidBody *body;
                GhostObject *ghost;
            };

            inline bool operator == (const RayCastResult& other) const
            {
                return distance == other.distance and
                       normal == other.normal and
                       objType == other.objType and
                       body == other.body;
            }
        };

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

        inline const List<GhostObject *>& getGhostObjects() const
        {
            return ghostObjects;
        }

        RigidBody *createRigidBody(const RigidBody::ConstructionInfo& info, ResPtr<PhysicsShape> shape);
        void destroyRigidBody(RigidBody *rigidBody);

        GhostObject *createGhostObject(ResPtr<PhysicsShape> shape, unsigned short collisionMask=0xFFFF);
        void destroyGhostObject(GhostObject *object);

        void stepSimulation(float timeStep,
                            size_t maxSubSteps=1,
                            float fixedTimeStep=1.0f/60.0f);

        void debugDraw();

        List<RayCastResult> castRay(const Position3D& start,
                                    const Direction3D& direction,
                                    float distance=9999.0f);

        inline btDynamicsWorld *getBulletWorld()
        {
            return world;
        }
    private:
        btCollisionConfiguration *configuration;
        btCollisionDispatcher *dispatcher;
        btBroadphaseInterface *broadphase;
        btConstraintSolver *solver;
        btGhostPairCallback *ghostCallback;
        btDynamicsWorld *world;
        List<RigidBody *> rigidBodies;
        List<GhostObject *> ghostObjects;
        PhysicsDebugDrawer *debugDrawer;
};

#endif // PHYSICSWORLD_H

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

enum class PhysicsObjectType
{
    Body,
    Ghost
} BIND ENUM_CLASS;

class RayCastResult
{
    public:
        RayCastResult() : distance(0.0f), objType(PhysicsObjectType::Body), body(nullptr) {}

        float distance;
        Direction3D normal;
        PhysicsObjectType objType;

        union
        {
            RigidBody *body;
            GhostObject *ghost;
        } NO_BIND;

        RigidBody *getRigidBody() const
        {
            if (objType == PhysicsObjectType::Body)
            {
                return body;
            }
            return nullptr;
        }

        GhostObject *getGhost() const
        {
            if (objType == PhysicsObjectType::Ghost)
            {
                return ghost;
            }
            return nullptr;
        }

        bool operator == (const RayCastResult& other) const
        {
            return distance == other.distance and
                   normal == other.normal and
                   objType == other.objType and
                   body == other.body;
        }
} BIND;

class PhysicsWorld
{
    public:
        PhysicsWorld();
        virtual ~PhysicsWorld();

        void addDebugDrawer();

        void setGravity(const Vector3D& gravity)
        {
            world->setGravity(btVector3(gravity.x, gravity.y, gravity.z));
        }

        Vector3D getGravity() const
        {
            btVector3 gravity = world->getGravity();

            return Vector3D(gravity.getX(), gravity.getY(), gravity.getZ());
        }

        const List<RigidBody *>& getRigidBodies() const
        {
            return rigidBodies;
        }

        const List<GhostObject *>& getGhostObjects() const
        {
            return ghostObjects;
        }

        RigidBody *createRigidBody(const RigidBodyConstructionInfo& info, PhysicsShape *shape);
        void destroyRigidBody(RigidBody *rigidBody);

        GhostObject *createGhostObject(PhysicsShape *shape, unsigned short collisionMask=0xFFFF);
        void destroyGhostObject(GhostObject *object);

        void stepSimulation(float timeStep,
                            size_t maxSubSteps=1,
                            float fixedTimeStep=1.0f/60.0f);

        void debugDraw();

        List<RayCastResult> castRay(const Position3D& start,
                                    const Direction3D& direction,
                                    float distance=9999.0f);

        btDynamicsWorld *getBulletWorld() const NO_BIND
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
} BIND;

#endif // PHYSICSWORLD_H

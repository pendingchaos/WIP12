#include "physics/physicsworld.h"

#include "graphics/camera.h"

#include "memory.h"

PhysicsWorld::PhysicsWorld() : debugDrawer(nullptr)
{
    configuration = NEW(btDefaultCollisionConfiguration);
    dispatcher = NEW(btCollisionDispatcher, configuration);
    broadphase = NEW(btDbvtBroadphase);
    solver = NEW(btSequentialImpulseConstraintSolver);
    world = NEW(btDiscreteDynamicsWorld, dispatcher, broadphase, solver, configuration);
    world->setGravity(btVector3(0.0f, -9.8f, 0.0f));
}

PhysicsWorld::~PhysicsWorld()
{
    world->setDebugDrawer(nullptr);
    DELETE(PhysicsDebugDrawer, debugDrawer);
    DELETE(btDynamicsWorld, world);
    DELETE(btConstraintSolver, solver);
    DELETE(btBroadphaseInterface, broadphase);
    DELETE(btCollisionDispatcher, dispatcher);
    DELETE(btCollisionConfiguration, configuration);
}

void PhysicsWorld::addDebugDrawer()
{
    debugDrawer = NEW(PhysicsDebugDrawer);

    world->setDebugDrawer(debugDrawer);
}

RigidBody *PhysicsWorld::createRigidBody(const RigidBody::ConstructionInfo& info)
{
    RigidBody *body = NEW(RigidBody, info, this);

    rigidBodies.append(body);

    return body;
}

void PhysicsWorld::destroyRigidBody(RigidBody *rigidBody)
{
    rigidBodies.remove(rigidBodies.find(rigidBody));

    DELETE(RigidBody, rigidBody);
}

void PhysicsWorld::stepSimulation(float timeStep,
                                  size_t maxSubSteps,
                                  float fixedTimeStep)
{
    world->stepSimulation(timeStep, maxSubSteps, fixedTimeStep);
}

void PhysicsWorld::debugDraw()
{
    if (debugDrawer != nullptr)
    {
        world->debugDrawWorld();
    }
}

List<PhysicsWorld::RayCastResult> PhysicsWorld::castRay(const Position3D& start,
                                                        const Direction3D& direction,
                                                        float distance)
{
    class Callback : public btCollisionWorld::RayResultCallback
    {
        public:
            virtual btScalar addSingleResult(btCollisionWorld::LocalRayResult& rayResult,
                                             bool normalInWorldSpace)
            {
                RayCastResult result;

                result.distance = rayResult.m_hitFraction * distance;

                if (normalInWorldSpace)
                {
                    result.normal = Direction3D(rayResult.m_hitNormalLocal.getX(),
                                                rayResult.m_hitNormalLocal.getY(),
                                                rayResult.m_hitNormalLocal.getZ());
                } else
                {
                    btVector3 normal = rayResult.m_collisionObject->getWorldTransform().getBasis() *
                                       rayResult.m_hitNormalLocal;

                    result.normal = Direction3D(normal.getX(), normal.getY(), normal.getZ());
                }

                result.body = (RigidBody *)rayResult.m_collisionObject->getUserPointer();

                results.append(result);

                return m_closestHitFraction;
            }

            float distance;
            List<RayCastResult> results;
    };

    List<RayCastResult> results;

    Callback callback;
    callback.distance = distance;
    callback.results = results;

    world->rayTest(btVector3(start.x, start.y, start.z),
                   btVector3(start.x + direction.x * distance,
                             start.y + direction.y * distance,
                             start.z + direction.z * distance),
                   callback);

    return callback.results;
}

#include "physics/physicsworld.h"

#include "memory.h"

PhysicsWorld::PhysicsWorld() : debugDrawer(nullptr)
{
    configuration = NEW(btDefaultCollisionConfiguration);

    dispatcher = NEW(btCollisionDispatcher, configuration);

    ghostCallback = NEW(btGhostPairCallback);

    broadphase = NEW(btDbvtBroadphase);
    broadphase->getOverlappingPairCache()->setInternalGhostPairCallback(ghostCallback);

    solver = NEW(btSequentialImpulseConstraintSolver);

    world = NEW(btDiscreteDynamicsWorld, dispatcher, broadphase, solver, configuration);
    world->setGravity(btVector3(0.0f, -9.8f, 0.0f));
}

PhysicsWorld::~PhysicsWorld()
{
    for (size_t i = 0; i < rigidBodies.getCount(); ++i)
    {
        DELETE(rigidBodies[i]);
    }

    for (size_t i = 0; i < ghostObjects.getCount(); ++i)
    {
        DELETE(ghostObjects[i]);
    }

    world->setDebugDrawer(nullptr);
    DELETE(debugDrawer);
    DELETE(world);
    DELETE(solver);
    DELETE(broadphase);
    DELETE(ghostCallback);
    DELETE(dispatcher);
    DELETE(configuration);
}

void PhysicsWorld::addDebugDrawer()
{
    debugDrawer = NEW(PhysicsDebugDrawer);

    world->setDebugDrawer(debugDrawer);
}

RigidBody *PhysicsWorld::createRigidBody(const RigidBody::ConstructionInfo& info, PhysicsShape *shape)
{
    RigidBody *body = NEW(RigidBody, info, shape, this);

    rigidBodies.append(body);

    return body;
}

void PhysicsWorld::destroyRigidBody(RigidBody *rigidBody)
{
    rigidBodies.remove(rigidBodies.find(rigidBody));

    DELETE(rigidBody);
}

GhostObject *PhysicsWorld::createGhostObject(PhysicsShape *shape, unsigned short collisionMask)
{
    GhostObject *ghost = NEW(GhostObject, collisionMask, this, shape);

    ghostObjects.append(ghost);

    return ghost;
}

void PhysicsWorld::destroyGhostObject(GhostObject *ghostObject)
{
    ghostObjects.remove(ghostObjects.find(ghostObject));

    DELETE(ghostObject);
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

                const btCollisionObject *object = rayResult.m_collisionObject;

                if (dynamic_cast<const btRigidBody *>(object) != nullptr)
                {
                    result.objType = RayCastResult::ObjectType::Body;
                    result.body = (RigidBody *)rayResult.m_collisionObject->getUserPointer();
                } else
                {
                    result.objType = RayCastResult::ObjectType::Ghost;
                    result.ghost = (GhostObject *)rayResult.m_collisionObject->getUserPointer();
                }

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

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

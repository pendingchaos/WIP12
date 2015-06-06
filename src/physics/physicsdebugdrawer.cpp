#include "physics/physicsdebugdrawer.h"

#include "graphics/gfxbuffer.h"
#include "graphics/gfxshader.h"
#include "resource/resourcemanager.h"
#include "math/matrix4x4.h"
#include "globals.h"
#include "graphics/gfxapi.h"
#include "graphics/gfxdebugdrawer.h"

PhysicsDebugDrawer::PhysicsDebugDrawer()
: debugMode(DBG_DrawAabb|DBG_DrawWireframe|DBG_DrawContactPoints) {}

PhysicsDebugDrawer::~PhysicsDebugDrawer() {}

void PhysicsDebugDrawer::drawLine(const btVector3 &from,
                                  const btVector3 &to,
                                  const btVector3 &color)
{
    debugDrawer->addLine(Position3D(from.getX(), from.getY(), from.getZ()),
                         Position3D(to.getX(), to.getY(), to.getZ()),
                         Float4(color.getX(), color.getY(), color.getZ(), 1.0f),
                         Float4(color.getX(), color.getY(), color.getZ(), 1.0f));
}

void PhysicsDebugDrawer::drawContactPoint(const btVector3 &pointOnB,
                                          const btVector3 &normalOnB,
                                          btScalar distance,
                                          int lifeTime,
                                          const btVector3 &color)
{
    drawLine(pointOnB, pointOnB + normalOnB * distance, color);
}

void PhysicsDebugDrawer::reportErrorWarning(const char *warningString)
{

}

void PhysicsDebugDrawer::draw3dText(const btVector3 &location,
                                    const char *textString)
{

}

void PhysicsDebugDrawer::setDebugMode(int debugMode_)
{
    debugMode = debugMode_;
}

int PhysicsDebugDrawer::getDebugMode() const
{
    return debugMode;
}

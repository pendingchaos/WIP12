#ifndef PHYSICSDEBUGDRAWER_H
#define PHYSICSDEBUGDRAWER_H

#include "resource/resource.h"

#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"

class ResourceManager;
class GfxShader;
class GfxBuffer;

class PhysicsDebugDrawer : public btIDebugDraw
{
    public:
        PhysicsDebugDrawer();
        virtual ~PhysicsDebugDrawer();

        virtual void drawLine(const btVector3 &from,
                              const btVector3 &to,
                              const btVector3 &color);

        virtual void drawContactPoint(const btVector3 &pointOnB,
                                      const btVector3 &normalOnB,
                                      btScalar distance,
                                      int lifeTime,
                                      const btVector3 &color);

        virtual void reportErrorWarning(const char *warningString);

        virtual void draw3dText(const btVector3 &location, const char *textString);

        virtual void setDebugMode(int debugMode);

        virtual int getDebugMode() const;

        int debugMode;
};

#endif // PHYSICSDEBUGDRAWER_H

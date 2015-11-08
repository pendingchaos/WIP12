#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "math/t3.h"
#include "math/matrix4x4.h"
#include "physics/physicsshape.h"
#include "scripting/script.h"
#include "scripting/bindings.h"
#include "utils.h"

#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"

class PhysicsWorld;
class Entity;

enum class RigidBodyType
{
    Static,
    Dynamic,
    Kinematic
} BIND ENUM_CLASS;

class RigidBodyConstructionInfo
{
    public:
        RigidBodyConstructionInfo() : type(RigidBodyType::Dynamic),
                                      mass(1.0f),
                                      entity(nullptr),
                                      linearDamping(0.04f),
                                      angularDamping(0.1f),
                                      friction(0.5f),
                                      rollingFriction(0.0f),
                                      restitution(0.0f),
                                      linearSleepingThreshold(0.8f),
                                      angularSleepingThreshold(1.0f),
                                      collisionMask(union_cast<short>(0xFFFF)) {}

        RigidBodyType type;
        float mass;
        Entity *entity;
        float linearDamping;
        float angularDamping;
        float friction;
        float rollingFriction;
        float restitution;
        float linearSleepingThreshold;
        float angularSleepingThreshold;
        short collisionMask;
} BIND;

class RigidBody
{
    friend PhysicsWorld;
    friend PhysicsShapeImpl;

    public:
        btRigidBody *getBulletRigidBody() const NO_BIND
        {
            return rigidBody;
        }

        RigidBodyType getType() const
        {
            return type;
        }

        Vector3D getGravity() const;

        void setGravity(const Vector3D& gravity);

        void setLinearDamping(float damping);

        float getLinearDamping() const;

        void setAngularDamping(float damping);

        float getAngularDamping() const;

        void setMass(float mass) const;

        float getMass() const;

        float getLinearSleepingThreshold() const;

        void setLinearSleepingThreshold(float threshold);

        float getAngularSleepingThreshold() const;

        void setAngularSleepingThreshold(float threshold);

        void applyTorque(const Vector3D& torque);

        void applyForce(const Vector3D& force, const Position3D& position);

        void applyCentralImpulse(const Vector3D& impulse);

        void applyTorqueImpulse(const Vector3D& torque);

        void applyImpulse(const Vector3D& impulse, const Position3D& position);

        void clearForces();

        Vector3D getLinearVelocity() const;

        void setLinearVelocity(const Vector3D& velocity) const;

        /**
         *The length is the speed and if it is normalized, it is the axis.
         */
        Vector3D getAngularVelocity() const;

        void setAngularVelocity(const Vector3D& velocity) const;

        Vector3D getVelocityOfPoint(const Position3D& point) const;

        float getRestitution() const;

        void setRestitution(float restitution);

        float getFriction() const;

        void setFriction(float friction);

        float getRollingFriction() const;

        void setRollingFriction(float friction);

        Float3 getLinearFactor() const;
        void setLinearFactor(const Float3& factor) const;

        Float3 getAngularFactor() const;
        void setAngularFactor(const Float3& factor) const;

        void setTransform(const Matrix4x4& transform) const;

        PhysicsWorld *getWorld() const
        {
            return world;
        }

        short getCollisionMask() const
        {
            return collisionMask;
        }

        void setShape(PhysicsShape *shape);

        PhysicsShape *getShape() const
        {
            return shape;
        }

        Entity *getEntity() const
        {
            return entity;
        }
    private:
        RigidBody(const RigidBodyConstructionInfo& info, PhysicsShape *shape, PhysicsWorld *world);
        virtual ~RigidBody();

        void updateShape();

        PhysicsShape *shape;
        btRigidBody *rigidBody;
        PhysicsWorld *world;
        Entity *entity;
        RigidBodyType type;
        short collisionMask;
} BIND NOT_COPYABLE;

#endif // RIGIDBODY_H

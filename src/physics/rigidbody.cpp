#include "physics/rigidbody.h"

#include "physics/physicsworld.h"
#include "scene/transform.h"
#include "memory.h"
#include "logging.h"

class MotionState : public btMotionState
{
    public:
        MotionState(Transform *transform_) : transform(transform_) {}

        virtual void getWorldTransform(btTransform& otherTransform) const
        {
            otherTransform.setOrigin(btVector3(transform->position.x,
                                               transform->position.y,
                                               transform->position.z));

            otherTransform.setRotation(btQuaternion(transform->orientation.x,
                                                    transform->orientation.y,
                                                    transform->orientation.z,
                                                    transform->orientation.w));
        }

        virtual void setWorldTransform(const btTransform& otherTransform)
        {
            transform->position = Position3D(otherTransform.getOrigin().getX(),
                                             otherTransform.getOrigin().getY(),
                                             otherTransform.getOrigin().getZ());

            transform->orientation = Quaternion(otherTransform.getRotation().getX(),
                                                otherTransform.getRotation().getY(),
                                                otherTransform.getRotation().getZ(),
                                                otherTransform.getRotation().getW());
        }
    private:
        Transform *transform;
};

RigidBody::RigidBody(const ConstructionInfo& info,
                     PhysicsWorld *world_) : shape(NEW(PhysicsShape)),
                                             world(world_),
                                             type(info.type),
                                             collisionMask(info.collisionMask)
{
    transform = info.transform == nullptr ? NEW(Transform) : nullptr;
    syncTransform = info.transform;

    float mass = info.type == Dynamic ? info.mass : 0.0f;

    btRigidBody::btRigidBodyConstructionInfo btInfo(mass,
                                                    NEW(MotionState, getTransform()),
                                                    shape->getBulletShape());

    shape->getBulletShape()->calculateLocalInertia(mass,
                                                   btInfo.m_localInertia);

    btInfo.m_linearDamping = info.linearDamping;
    btInfo.m_angularDamping = info.angularDamping;
    btInfo.m_friction = info.friction;
    btInfo.m_rollingFriction = info.rollingFriction;
    btInfo.m_restitution = info.restitution;
    btInfo.m_linearSleepingThreshold = info.linearSleepingThreshold;
    btInfo.m_angularSleepingThreshold = info.angularSleepingThreshold;

    rigidBody = NEW(btRigidBody, btInfo);

    rigidBody->setUserPointer(this);

    switch (info.type)
    {
    case Static:
    {
        rigidBody->setCollisionFlags(rigidBody->getCollisionFlags()
                                      | btCollisionObject::CF_STATIC_OBJECT);
        break;
    }
    case Dynamic:
    {
        break;
    }
    case Kinematic:
    {
        rigidBody->setCollisionFlags(rigidBody->getCollisionFlags()
                                      | btCollisionObject::CF_KINEMATIC_OBJECT);
        rigidBody->setActivationState(DISABLE_DEACTIVATION);
        break;
    }
    }

    world->getBulletWorld()->addRigidBody(rigidBody, 0xFFFF, info.collisionMask);
}

RigidBody::~RigidBody()
{
    world->getBulletWorld()->removeRigidBody(rigidBody);

    btMotionState *motionState = rigidBody->getMotionState();

    DELETE(btRigidBody, rigidBody);
    DELETE(Transform, transform);
    DELETE(btMotionState, motionState);
}

Vector3D RigidBody::getGravity() const
{
    btVector3 gravity = rigidBody->getGravity();

    return Vector3D(gravity.getX(), gravity.getY(), gravity.getZ());
}

void RigidBody::setGravity(const Vector3D& gravity)
{
    rigidBody->setGravity(btVector3(gravity.x, gravity.y, gravity.z));
}

void RigidBody::setLinearDamping(float damping)
{
    rigidBody->setDamping(damping, rigidBody->getAngularDamping());
}

float RigidBody::getLinearDamping() const
{
    return rigidBody->getLinearDamping();
}

void RigidBody::setAngularDamping(float damping)
{
    rigidBody->setDamping(rigidBody->getLinearDamping(), damping);
}

float RigidBody::getAngularDamping() const
{
    return rigidBody->getAngularDamping();
}

void RigidBody::setMass(float mass) const
{
    btVector3 inertia;
    shape->getBulletShape()->calculateLocalInertia(mass, inertia);

    rigidBody->setMassProps(mass, inertia);
}

float RigidBody::getMass() const
{
    return 1.0f / rigidBody->getInvMass();
}

float RigidBody::getLinearSleepingThreshold() const
{
    return rigidBody->getLinearSleepingThreshold();
}

void RigidBody::setLinearSleepingThreshold(float threshold)
{
    rigidBody->setSleepingThresholds(threshold, rigidBody->getAngularSleepingThreshold());
}

float RigidBody::getAngularSleepingThreshold() const
{
    return rigidBody->getAngularSleepingThreshold();
}

void RigidBody::setAngularSleepingThreshold(float threshold)
{
    rigidBody->setSleepingThresholds(rigidBody->getLinearSleepingThreshold(), threshold);
}

void RigidBody::applyTorque(const Vector3D& torque)
{
    rigidBody->applyTorque(btVector3(torque.x, torque.y, torque.z));
}

void RigidBody::applyForce(const Vector3D& force, const Position3D& position)
{
    rigidBody->applyForce(btVector3(force.x, force.y, force.z),
                          btVector3(position.x, position.y, position.z));
}

void RigidBody::applyCentralImpulse(const Vector3D& impulse)
{
    rigidBody->applyCentralImpulse(btVector3(impulse.x, impulse.y, impulse.z));
}

void RigidBody::applyTorqueImpulse(const Vector3D& torque)
{
    rigidBody->applyTorqueImpulse(btVector3(torque.x, torque.y, torque.z));
}

void RigidBody::applyImpulse(const Vector3D& impulse, const Position3D& position)
{
    rigidBody->applyImpulse(btVector3(impulse.x,
                                      impulse.y,
                                      impulse.z),
                            btVector3(position.x,
                                      position.y,
                                      position.z));
}

void RigidBody::clearForces()
{
    rigidBody->clearForces();
}

Vector3D RigidBody::getLinearVelocity() const
{
    btVector3 velocity = rigidBody->getLinearVelocity();

    return Vector3D(velocity.getX(), velocity.getY(), velocity.getZ());
}

void RigidBody::setLinearVelocity(const Vector3D& velocity) const
{
    rigidBody->setLinearVelocity(btVector3(velocity.x, velocity.y, velocity.z));
}

Vector3D RigidBody::getAngularVelocity() const
{
    btVector3 velocity = rigidBody->getAngularVelocity();

    return Vector3D(velocity.getX(), velocity.getY(), velocity.getZ());
}

void RigidBody::setAngularVelocity(const Vector3D& velocity) const
{
    rigidBody->setAngularVelocity(btVector3(velocity.x, velocity.y, velocity.z));
}

Vector3D RigidBody::getVelocityOfPoint(const Position3D& point) const
{
    btVector3 velocity = rigidBody->getVelocityInLocalPoint(btVector3(point.x,
                                                                      point.y,
                                                                      point.z));

    return Vector3D(velocity.getX(), velocity.getY(), velocity.getZ());
}

float RigidBody::getRestitution() const
{
    return rigidBody->getRestitution();
}

void RigidBody::setRestitution(float restitution)
{
    rigidBody->setRestitution(restitution);
}

float RigidBody::getFriction() const
{
    return rigidBody->getFriction();
}

void RigidBody::setFriction(float friction)
{
    rigidBody->setFriction(friction);
}

float RigidBody::getRollingFriction() const
{
    return rigidBody->getRollingFriction();
}

void RigidBody::setRollingFriction(float friction)
{
    rigidBody->setRollingFriction(friction);
}

void RigidBody::setTransform(const Transform& transform) const
{
    btTransform btTransform;

    btTransform.setOrigin(btVector3(transform.position.x,
                                    transform.position.y,
                                    transform.position.z));

    btTransform.setRotation(btQuaternion(transform.orientation.x,
                                         transform.orientation.y,
                                         transform.orientation.z,
                                         transform.orientation.w));

    rigidBody->setCenterOfMassTransform(btTransform);
}

Float3 RigidBody::getLinearFactor() const
{
    btVector3 factor = rigidBody->getLinearFactor();

    return Float3(factor.getX(), factor.getY(), factor.getZ());
}

void RigidBody::setLinearFactor(const Float3& factor) const
{
    rigidBody->setLinearFactor(btVector3(factor.x, factor.y, factor.z));
}

Float3 RigidBody::getAngularFactor() const
{
    btVector3 factor = rigidBody->getAngularFactor();

    return Float3(factor.getX(), factor.getY(), factor.getZ());
}

void RigidBody::setAngularFactor(const Float3& factor) const
{
    rigidBody->setAngularFactor(btVector3(factor.x, factor.y, factor.z));
}

#define UPDATE_SHAPE rigidBody->setCollisionShape(shape->getBulletShape());\
btVector3 localInertia;\
shape->getBulletShape()->calculateLocalInertia(getMass(), localInertia);\
rigidBody->setMassProps(getMass(), localInertia);

void RigidBody::setEmpty()
{
    shape->setEmpty();

    UPDATE_SHAPE
}

void RigidBody::setSphere(float radius)
{
    shape->setSphere(radius);

    UPDATE_SHAPE
}

void RigidBody::setBox(const Vector3D& halfExtents)
{
    shape->setBox(halfExtents);

    UPDATE_SHAPE
}

void RigidBody::setCylinder(PhysicsCylinderShape::Axis axis,
                            float height,
                            float radius)
{
    shape->setCylinder(axis, height, radius);

    UPDATE_SHAPE
}

void RigidBody::setCapsule(PhysicsCapsuleShape::Axis axis,
                           float height,
                           float radius)
{
    shape->setCapsule(axis, height, radius);

    UPDATE_SHAPE
}

void RigidBody::setCone(PhysicsConeShape::Axis axis,
                        float height,
                        float radius)
{
    shape->setCone(axis, height, radius);

    UPDATE_SHAPE
}

void RigidBody::setConvexHull(size_t pointCount, const Position3D *points)
{
    shape->setConvexHull(pointCount, points);

    UPDATE_SHAPE
}

void RigidBody::setStaticTriangleMesh(size_t vertexCount, const Position3D *vertices)
{
    shape->setStaticTriangleMesh(vertexCount, vertices);

    UPDATE_SHAPE
}

void RigidBody::setHeightfield(uint32_t width, uint32_t height, const float *data)
{
    shape->setHeightfield(width, height, data);

    UPDATE_SHAPE
}

void RigidBody::setPlane(const Vector3D& normal, float distance)
{
    shape->setPlane(normal, distance);

    UPDATE_SHAPE
}

void RigidBody::setCompound(size_t childCount, const PhysicsCompoundShape::Child *children)
{
    shape->setCompound(childCount, children);

    UPDATE_SHAPE
}

void RigidBody::setShape(ResPtr<PhysicsShape> shape_)
{
    shape = shape_;

    UPDATE_SHAPE
}

#undef UPDATE_SHAPE

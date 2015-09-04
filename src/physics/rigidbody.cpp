#include "physics/rigidbody.h"

#include "physics/physicsworld.h"
#include "scene/entity.h"
#include "memory.h"
#include "logging.h"

class MotionState : public btMotionState
{
    public:
        MotionState(Entity *entity_) : entity(entity_) {}

        virtual void getWorldTransform(btTransform& otherTransform) const
        {
            if (entity != nullptr)
            {
                Matrix4x4 mat = entity->getFinalTransform();

                otherTransform.setOrigin(btVector3(mat[0][3],
                                                   mat[1][3],
                                                   mat[2][3]));

                otherTransform.setBasis(btMatrix3x3(mat[0][0], mat[0][1], mat[0][2],
                                                    mat[1][0], mat[1][1], mat[1][2],
                                                    mat[2][0], mat[2][1], mat[2][2]));
            }
        }

        virtual void setWorldTransform(const btTransform& otherTransform)
        {
            if (entity != nullptr)
            {
                if (entity->getParent() == nullptr)
                {
                    Position3D position = Position3D(otherTransform.getOrigin().getX(),
                                                     otherTransform.getOrigin().getY(),
                                                     otherTransform.getOrigin().getZ());

                    Quaternion orientation = Quaternion(otherTransform.getRotation().getX(),
                                                        otherTransform.getRotation().getY(),
                                                        otherTransform.getRotation().getZ(),
                                                        otherTransform.getRotation().getW());

                    entity->transform.position = position;
                    entity->transform.orientation = orientation;
                } else
                {
                    Matrix4x4 parentMat = entity->getParent()->getFinalTransform().inverse().transpose();

                    btTransform parentTransform;

                    parentTransform.setOrigin(btVector3(parentMat[0][3],
                                                        parentMat[1][3],
                                                        parentMat[2][3]));

                    parentTransform.setBasis(btMatrix3x3(parentMat[0][0], parentMat[0][1], parentMat[0][2],
                                                         parentMat[1][0], parentMat[1][1], parentMat[1][2],
                                                         parentMat[2][0], parentMat[2][1], parentMat[2][2]));

                    btTransform transform = otherTransform * parentTransform.inverse();

                    Position3D position = Position3D(transform.getOrigin().getX(),
                                                     transform.getOrigin().getY(),
                                                     transform.getOrigin().getZ());

                    Quaternion orientation = Quaternion(transform.getRotation().getX(),
                                                        transform.getRotation().getY(),
                                                        transform.getRotation().getZ(),
                                                        transform.getRotation().getW());

                    entity->transform.position = position;
                    entity->transform.orientation = orientation;
                }
            }
        }
    private:
        Entity *entity;
};

RigidBody::RigidBody(const RigidBodyConstructionInfo& info,
                     PhysicsShape *shape_,
                     PhysicsWorld *world_) : shape(shape_),
                                             world(world_),
                                             entity(info.entity),
                                             type(info.type),
                                             collisionMask(info.collisionMask)
{
    shape->rigidBodies.append(this);

    float mass = info.type == RigidBodyType::Dynamic ? std::max(info.mass, 0.0001f) : 0.0f;

    btRigidBody::btRigidBodyConstructionInfo btInfo(mass,
                                                    NEW(MotionState, entity),
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

    if (entity != nullptr)
    {
        setTransform(entity->getFinalTransform());
    }

    switch (info.type)
    {
    case RigidBodyType::Static:
    {
        rigidBody->setCollisionFlags(rigidBody->getCollisionFlags()
                                      | btCollisionObject::CF_STATIC_OBJECT);
        break;
    }
    case RigidBodyType::Dynamic:
    {
        break;
    }
    case RigidBodyType::Kinematic:
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
    shape->rigidBodies.remove(shape->rigidBodies.find(this));

    shape->release();

    world->getBulletWorld()->removeRigidBody(rigidBody);

    btMotionState *motionState = rigidBody->getMotionState();

    DELETE(rigidBody);
    DELETE(motionState);
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

void RigidBody::setTransform(const Matrix4x4& transform) const
{
    btTransform btTransform_;

    Matrix4x4 mat = transform;

    btTransform_.setOrigin(btVector3(mat[0][3],
                                     mat[1][3],
                                     mat[2][3]));

    btTransform_.setBasis(btMatrix3x3(mat[0][0], mat[0][1], mat[0][2],
                                      mat[1][0], mat[1][1], mat[1][2],
                                      mat[2][0], mat[2][1], mat[2][2]));

    rigidBody->setCenterOfMassTransform(btTransform_);
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

void RigidBody::setShape(PhysicsShape *shape_)
{
    shape->rigidBodies.remove(shape->rigidBodies.find(this));

    shape->release();

    shape = shape_;

    updateShape();

    shape->rigidBodies.append(this);
}

void RigidBody::updateShape()
{
    rigidBody->setCollisionShape(shape->getBulletShape());

    btVector3 localInertia;
    shape->getBulletShape()->calculateLocalInertia(getMass(), localInertia);

    rigidBody->setMassProps(getMass(), localInertia);
}

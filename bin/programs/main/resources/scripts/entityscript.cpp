#include <cmath>

#define INST_NAME Player
BEGIN_INSTANCE
    virtual void init()
    {
        angle = Float2(M_PI, 0.0f);
        speed = 5.0f;
        rotateSpeed = 0.5f;
        zoom = 1.0f;
        maximumVelocity = 12.0f;
        maxAngularVelocity = 0.5f;

        entity->getRigidBody()->setAngularFactor(Float3(0.0f));
    
        ResPtr<PhysicsShape> shape = NEW(PhysicsShape);
    
        shape->setCylinder(PhysicsCylinderShape::Y, 0.1f, 0.8f);
        
        feetGhost = entity->getScene()->getPhysicsWorld()->createGhostObject(shape);
    }
    
    virtual void deinit()
    {
        entity->getScene()->getPhysicsWorld()->destroyGhostObject(feetGhost);
    }

    virtual void fixedUpdate(float timestep)
    {
        Camera& camera = entity->getScene()->getRenderer()->camera;

        RigidBody *body = entity->getRigidBody();

        Vector3D dir(std::cos(angle.y) * std::sin(angle.x),
                     std::sin(angle.y),
                     std::cos(angle.y) * std::cos(angle.x));

        camera.setDirection(dir);

        Vector3D right(std::sin(angle.x - 3.1415f / 2.0f),
                       0.0f,
                       std::cos(angle.x - 3.1415f / 2.0f));

        camera.setUp(right.cross(dir));

        float resSpeed = speed;

        if (platform->isKeyPressed(Platform::Space))
        {
            resSpeed *= 2.0f;
        }

        Vector3D moveDir(std::sin(angle.x),
                         0.0f,
                         std::cos(angle.x));

        Vector3D velocity;

        if (platform->isKeyPressed(Platform::A))
        {
            velocity -= right * platform->getFrametime() * resSpeed;
        }

        if (platform->isKeyPressed(Platform::D))
        {
            velocity += right * platform->getFrametime() * resSpeed;
        }

        if (platform->isKeyPressed(Platform::W))
        {
            velocity += dir * platform->getFrametime() * resSpeed;
        }

        if (platform->isKeyPressed(Platform::S))
        {
            velocity -= dir * platform->getFrametime() * resSpeed;
        }

        velocity.y = 0.0f;

        //Modify the velocity so it does not make it go over the max.
        Vector3D oldVelocity = body->getLinearVelocity();
        Vector3D newVelocity = oldVelocity + velocity;

        if (newVelocity.x > maximumVelocity)
        {
            velocity.x -= newVelocity.x - maximumVelocity;
        } else if (newVelocity.x < -maximumVelocity)
        {
            velocity.x += std::abs(newVelocity.x) - maximumVelocity;
        }

        if (newVelocity.z > maximumVelocity)
        {
            velocity.z -= newVelocity.z - maximumVelocity;
        } else if (newVelocity.z < -maximumVelocity)
        {
            velocity.z += std::abs(newVelocity.z) - maximumVelocity;
        }
        //End of velocity modification.

        body->setLinearVelocity(oldVelocity + velocity);

        if (platform->isKeyPressed(Platform::Space) and onFloor)
        {
            Vector3D vel = body->getLinearVelocity();
            
            vel.y = 10.0f;
            
            body->setLinearVelocity(vel);
        }

        if (platform->isLeftMouseButtonPressed())
        {
            platform->setCursorVisible(false);

            float w = platform->getWindowWidth();
            float h = platform->getWindowHeight();
            Float2 pos = platform->getMousePosition();

            platform->setMousePosition(Int2(w/2.0f, h/2.0f));

            Float2 rel = Float2(w, h) / 2.0f - pos;
            
            if (rel.x > -1.0 and rel.x < 1.0)
            {
                rel.x = 0.0;
            }
            
            if (rel.y > -1.0 and rel.y < 1.0)
            {
                rel.y = 0.0;
            }
            
            angularVelocity.x += rotateSpeed * platform->getFrametime() * rel.x / 4.0f;
            angularVelocity.y += rotateSpeed * platform->getFrametime() * rel.y / 4.0f;
        } else
        {
            platform->setCursorVisible(true);
        }

        angularVelocity.x = std::min(angularVelocity.x, maxAngularVelocity);
        angularVelocity.y = std::min(angularVelocity.y, maxAngularVelocity);

        angularVelocity.x = std::max(angularVelocity.x, -maxAngularVelocity);
        angularVelocity.y = std::max(angularVelocity.y, -maxAngularVelocity);
        
        angle += angularVelocity;

        if (angle.y < -3.1415f / 2.0f)
        {
            angle.y = -3.1415f / 2.0f;
        }

        if (angle.y > 3.1415f / 2.0f)
        {
            angle.y = 3.1415f / 2.0f;
        }

        if (platform->getMouseWheel().y > 0)
        {
            zoom -= 1.0f * platform->getFrametime();
        }

        if (platform->getMouseWheel().y < 0)
        {
            zoom += 1.0f * platform->getFrametime();
        }

        zoom = std::max(std::min(zoom, 1.7f), 0.3f);

        camera.setFieldOfView(zoom * 50.0f);

        angularVelocity *= platform->getFrametime() * 0.1f;
        
        if (angularVelocity.x > -0.001f and angularVelocity.x < 0.001f)
        {
            angularVelocity.x = 0.0;
        }
        
        if (angularVelocity.y > -0.001f and angularVelocity.y < 0.001f)
        {
            angularVelocity.y = 0.0f;
        }

        camera.setPosition(entity->transform.position+Position3D(0.0f, 1.5f, 0.0f));
    }
    
    virtual void update()
    {
        Transform feetTransform = entity->transform;
        feetTransform.position.y -= 2.2f;
        feetGhost->setTransform(feetTransform);
        
        List<RigidBody *> rigidBodies;
        List<GhostObject *> ghosts;
        
        feetGhost->getCollisions(rigidBodies, ghosts);
        
        onFloor = rigidBodies.getCount() != 0;
        
        entity->getScene()->getAudioWorld()->listenerVelocity = entity->getRigidBody()->getLinearVelocity();
    }
    
    virtual void serialize(Serializable& serialized)
    {
        serialized.set("angle", angle);
        serialized.set("speed", speed);
        serialized.set("rotateSpeed", rotateSpeed);
        serialized.set("zoom", zoom);
        serialized.set("angularVelocity", angularVelocity);
        serialized.set("maximumVelocity", maximumVelocity);
        serialized.set("maxAngularVelocity", maxAngularVelocity);
    }
    
    virtual void deserialize(const Serializable& serialized)
    {
        serialized.get("angle", angle);
        serialized.get("speed", speed);
        serialized.get("rotateSpeed", rotateSpeed);
        serialized.get("zoom", zoom);
        serialized.get("angularVelocity", angularVelocity);
        serialized.get("maximumVelocity", maximumVelocity);
        serialized.get("maxAngularVelocity", maxAngularVelocity);
    }

    GhostObject *feetGhost;
    bool onFloor;
    Float2 angle;
    float speed;
    float rotateSpeed;
    float zoom;
    Float2 angularVelocity;
    float maximumVelocity;
    float maxAngularVelocity;
END_INSTANCE

#ifndef PROJSCRIPT
#define PROJSCRIPT

#include <cmath>

BEGIN_INSTANCE(Projectile, InstanceBase)
    virtual void init()
    {
        scale = 1.0f;
        scale2 = 1.0f;
    }
    
    virtual void fixedUpdate(float timestep)
    {
        entity->transform.scale = scale * scale2;
        
        entity->getRigidBody()->getShape()->setScale(scale * scale2);
        
        if (entity->transform.position.y < -12.5)
        {
            scene->removeEntity(scene->getEntities().find(entity));
        } else if (entity->transform.position.y < -10.0)
        {
            scale2 = (2.5f - std::abs(entity->transform.position.y + 10.0f)) / 2.5f;
        }
    }
    
    virtual void serialize(Serializable& serialized)
    {
        serialized.set("scale", scale);
    }
    
    virtual void deserialize(const Serializable& serialized)
    {
        serialized.get("scale", scale);
    }

    float scale;
    float scale2;
END_INSTANCE(Projectile)

#endif

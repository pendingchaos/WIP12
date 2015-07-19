#ifndef PROJSCRIPT
#define PROJSCRIPT

BEGIN_INSTANCE(Projectile)
    virtual void init()
    {
        scale = 1.0f;
        timeleft = 5.5f;
    }
    
    virtual void fixedUpdate(float timestep)
    {
        timeleft -= timestep;
    
        if (timeleft < 0.5f)
        {
            entity->transform.scale = Vector3D(timeleft * 2.0f) * scale;
        } else
        {
            entity->transform.scale = scale;
        }
        
        entity->getRigidBody()->getShape()->setScale(entity->transform.scale);
        
        if (timeleft < 0.0f)
        {
            scene->removeEntity(scene->getEntities().find(entity));
        }
    }
    
    virtual void serialize(Serializable& serialized)
    {
        serialized.set("timeleft", timeleft);
    }
    
    virtual void deserialize(const Serializable& serialized)
    {
        serialized.get("timeleft", timeleft);
    }

    float scale;
    float timeleft;
END_INSTANCE(Projectile)

#endif

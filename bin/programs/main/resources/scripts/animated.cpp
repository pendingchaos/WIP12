#ifndef ENTITYSCRIPT
#define ENTITYSCRIPT

BEGIN_INSTANCE(Animated, InstanceBase)
    virtual void init() {}

    virtual void deinit() {}

    virtual void handleInput() {}

    virtual void fixedUpdate(float timestep)
    {
        //TODO: Is this correct?
        /*if (entity->getRenderComponent() != nullptr)
        {
            RenderComponent *comp = entity->getRenderComponent();
            
            if (comp->getAnimationState() != nullptr)
            {
                comp->getAnimationState()->timeOffset += timestep;
            }
        }*/
    }

    virtual void update()
    {
        if (entity->getRenderComponent() != nullptr)
        {
            RenderComponent *comp = entity->getRenderComponent();
            
            if (comp->getAnimationState() != nullptr)
            {
                comp->getAnimationState()->timeOffset += platform->getFrametime();
            }
        }
    }

    virtual void serialize(Serializable& serialized) {}

    virtual void deserialize(const Serializable& serialized) {}
END_INSTANCE(Animated)

#endif

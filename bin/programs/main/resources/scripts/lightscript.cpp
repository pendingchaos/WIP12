#ifndef LIGHTSCRIPT
#define LIGHTSCRIPT

BEGIN_INSTANCE(PlayerLight, InstanceBase)
    virtual void init()
    {
        on = false;

        GfxRenderer *renderer = entity->getScene()->getRenderer();

        light = renderer->addLight();

        light->scriptOwned = true;
        light->type = GfxLightType::Point;
        light->color = Float3(1.0, 0.5, 0.0);
        light->point.position = Position3D(0.0f);
        light->point.radius = 5.0f;
    }

    virtual void deinit()
    {
        GfxRenderer *renderer = entity->getScene()->getRenderer();

        renderer->removeLight(renderer->getLights().find(light));
    }

    virtual void handleInput()
    {
        on = platform->isKeyPressed(Key::LeftShift);
    }

    virtual void fixedUpdate(float timestep)
    {
        light->point.position = entity->transform.position;

        if (on)
        {
            light->power += timestep;
            light->power = std::min(light->power, 1.0f);
        } else
        {
            light->power -= timestep;
            light->power = std::max(light->power, 0.0f);
        }

        if (light->power < 0.001f and light->getShadowmap() != nullptr)
        {
            light->removeShadowmap();
        } else if (light->power > 0.001f and light->getShadowmap() == nullptr)
        {
            light->addShadowmap(1024, GfxShadowmapPrecision::Low);
        }

        GfxRenderer *renderer = entity->getScene()->getRenderer();

        for (size_t i = 0; i < renderer->getLights().getCount(); ++i)
        {
            Light *light2 = renderer->getLights()[i];

            if (light2->type == GfxLightType::Directional)
            {
                light2->power = 1.0f - light->power;
                break;
            }
        }

    }

    virtual void serialize(Serializable& serialized)
    {
        serialized.set("on", on);
        serialized.set("power", light->power);
    }

    virtual void deserialize(const Serializable& serialized)
    {
        serialized.get("on", on);
        serialized.get("power", light->power);
    }

    Light *light;
    bool on;
END_INSTANCE(PlayerLight)

#endif

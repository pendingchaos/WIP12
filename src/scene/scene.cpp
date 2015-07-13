#include "scene/scene.h"

#include "scene/entity.h"
#include "graphics/gfxrenderer.h"
#include "graphics/gfxshader.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxapi.h"
#include "physics/physicsworld.h"
#include "scripting/script.h"
#include "audio/audioworld.h"
#include "globals.h"
#include "file.h"

Scene::Scene() : Resource(SceneType)
{
    physicsWorld = NEW(PhysicsWorld);
    renderer = NEW(GfxRenderer, this);
    audioWorld = NEW(AudioWorld);

    audioWorld->addToAudioDevice(audioDevice);
}

Scene::Scene(const String& filename) : Resource(filename,
                                                SceneType)
{
    physicsWorld = NEW(PhysicsWorld);
    renderer = NEW(GfxRenderer, this);
    audioWorld = NEW(AudioWorld);

    audioWorld->addToAudioDevice(audioDevice);
}

Scene::~Scene()
{
    for (size_t i = 0; i < entities.getCount(); ++i)
    {
        DELETE(Entity, entities[i]);
    }

    List<ResPtr<Script>> scripts_;

    for (size_t i = 0; i < scripts.getCount(); ++i)
    {
        scripts_.append(scripts[i]->getScript());

        DELETE(ScriptInstance, scripts[i]);
    }

    for (size_t i = 0; i < scripts_.getCount(); ++i)
    {
        scripts_[i]->release();
    }

    audioWorld->removeFromAudioDevice(audioDevice);

    DELETE(AudioWorld, audioWorld);
    DELETE(GfxRenderer, renderer);
    DELETE(PhysicsWorld, physicsWorld);
}

void Scene::removeContent()
{
    for (size_t i = 0; i < entities.getCount(); ++i)
    {
        DELETE(Entity, entities[i]);
    }

    entities.clear();

    List<ResPtr<Script>> scripts_;

    for (size_t i = 0; i < scripts.getCount(); ++i)
    {
        scripts_.append(scripts[i]->getScript());

        DELETE(ScriptInstance, scripts[i]);
    }

    for (size_t i = 0; i < scripts_.getCount(); ++i)
    {
        scripts_[i]->release();
    }

    scripts.clear();

    audioWorld->clearSources();

    renderer->~GfxRenderer();
    new (renderer) GfxRenderer(this);

    physicsWorld->~PhysicsWorld();
    new (physicsWorld) PhysicsWorld;
}

void Scene::handleInput()
{
    _handleInput(entities);

    for (size_t i = 0; i < scripts.getCount(); ++i)
    {
        scripts[i]->handleInput();
    }
}

void Scene::update()
{
    _update(entities);

    for (size_t i = 0; i < scripts.getCount(); ++i)
    {
        scripts[i]->update();
    }
}

void Scene::fixedUpdate(float timestep)
{
    for (size_t i = 0; i < entities.getCount(); ++i)
    {
        entities[i]->updateFinalTransform();
    }

    _fixedUpdate(entities, timestep);

    for (size_t i = 0; i < scripts.getCount(); ++i)
    {
        scripts[i]->fixedUpdate(timestep);
    }

    physicsWorld->stepSimulation(timestep);
}

void Scene::_handleInput(const List<Entity *>& entities_)
{
    for (size_t i = 0; i < entities_.getCount(); ++i)
    {
        const Entity *entity = entities_[i];

        for (size_t i = 0; i < entity->getScripts().getCount(); ++i)
        {
            entity->getScripts()[i]->handleInput();
        }

        _handleInput(entity->getEntities());
    }
}

void Scene::_update(const List<Entity *>& entities_)
{
    for (size_t i = 0; i < entities_.getCount(); ++i)
    {
        const Entity *entity = entities_[i];

        for (size_t i = 0; i < entity->getScripts().getCount(); ++i)
        {
            entity->getScripts()[i]->update();
        }

        _update(entity->getEntities());
    }
}

void Scene::_fixedUpdate(const List<Entity *>& entities_, float timestep)
{
    for (size_t i = 0; i < entities_.getCount(); ++i)
    {
        const Entity *entity = entities_[i];

        for (size_t i = 0; i < entity->getScripts().getCount(); ++i)
        {
            entity->getScripts()[i]->fixedUpdate(timestep);
        }

        _fixedUpdate(entity->getEntities(), timestep);
    }
}

void Scene::render()
{
    renderer->updateStats();

    for (size_t i = 0; i < scripts.getCount(); ++i)
    {
        scripts[i]->preRender();
    }

    renderer->render();

    for (size_t i = 0; i < scripts.getCount(); ++i)
    {
        scripts[i]->postRender();
    }
}

void loadEntity(Entity *entity, PhysicsWorld *world, File *file)
{
    float posX = file->readFloat32();
    float posY = file->readFloat32();
    float posZ = file->readFloat32();

    float scaleX = file->readFloat32();
    float scaleY = file->readFloat32();
    float scaleZ = file->readFloat32();

    float rotX = RADIANS(file->readFloat32());
    float rotY = RADIANS(file->readFloat32());
    float rotZ = RADIANS(file->readFloat32());

    entity->transform.position = Position3D(posX, posY, posZ);
    entity->transform.scale = Float3(scaleX, scaleY, scaleZ);
    entity->transform.orientation = Quaternion(Float3(rotX, rotY, rotZ));

    entity->updateFinalTransform();

    bool useModel = file->readUInt8() != 0;
    bool useOverlay = file->readUInt8() != 0;
    bool useRigidBody = file->readUInt8() != 0;

    if (useModel)
    {
        uint32_t modelFileLen = file->readUInt32LE();

        String modelFile(modelFileLen);
        file->read(modelFileLen, modelFile.getData());

        bool shadowCaster = file->readUInt8() != 0;

        entity->addModel(resMgr->load<GfxModel>(modelFile), shadowCaster);
    } else if (useOverlay)
    {
        uint32_t textureFileLen = file->readUInt32LE();

        String textureFile(textureFileLen);
        file->read(textureFileLen, textureFile.getData());

        float red = file->readFloat32();
        float green = file->readFloat32();
        float blue = file->readFloat32();

        entity->addOverlay(resMgr->load<GfxTexture>(textureFile));

        entity->getRenderComponent()->overlayData.color = Float3(red, green, blue);
    }

    if (useRigidBody)
    {
        uint8_t type = file->readUInt8();
        float mass = file->readFloat32();
        float linearDamping = file->readFloat32();
        float angularDamping = file->readFloat32();
        float friction = file->readFloat32();
        float rollingFriction = file->readFloat32();
        float restitution = file->readFloat32();
        float linearSleepingThreshold = file->readFloat32();
        float angularSleepingThreshold = file->readFloat32();
        uint16_t collisionMask = file->readUInt16LE();

        RigidBody::ConstructionInfo info;

        switch (type)
        {
        case 0:
        {
            info.type = RigidBody::Static;
            break;
        }
        case 1:
        {
            info.type = RigidBody::Dynamic;
            break;
        }
        case 2:
        {
            info.type = RigidBody::Kinematic;
            break;
        }
        }

        info.mass = mass;
        info.linearDamping = linearDamping;
        info.angularDamping = angularDamping;
        info.friction = friction;
        info.rollingFriction = rollingFriction;
        info.restitution = restitution;
        info.linearSleepingThreshold = linearSleepingThreshold;
        info.angularSleepingThreshold = angularSleepingThreshold;
        info.collisionMask = collisionMask;

        uint32_t length = file->readUInt32LE();
        String shape(length);
        file->read(length, shape.getData());

        entity->addRigidBody(world, info, resMgr->load<PhysicsShape>(shape));
    }

    uint32_t numScripts = file->readUInt32LE();

    for (size_t i = 0; i < numScripts; ++i)
    {
        uint32_t scriptFileLen = file->readUInt32LE();
        String scriptFile(scriptFileLen);
        file->read(scriptFileLen, scriptFile.getData());

        uint32_t nameLen = file->readUInt32LE();
        String name(nameLen);
        file->read(nameLen, name.getData());

        entity->addScript(resMgr->load<Script>(scriptFile), name.getData());
    }

    uint32_t numChildren = file->readUInt32LE();

    for (size_t i = 0; i < numChildren; ++i)
    {
        uint32_t nameLen = file->readUInt32LE();
        String name(nameLen);
        file->read(nameLen, name.getData());

        Entity *child = entity->createEntity(name);

        loadEntity(child, world, file);
    }
}

void Scene::_load()
{
    try
    {
        removeContent();

        physicsWorld->addDebugDrawer();

        File file(getFilename().getData(), "rb");

        char magic[4];

        file.read(4, magic);

        if (magic[0] != 's' or
            magic[1] != 'c' or
            magic[2] != 'e' or
            magic[3] != 'n')
        {
            THROW(ResourceIOException,
                  "scene",
                  getFilename(),
                  "Invalid magic");
        }

        uint8_t majorVer = file.readUInt8();
        uint8_t minorVer = file.readUInt8();

        if (majorVer != 1 or minorVer != 0)
        {
            THROW(ResourceIOException,
                  "scene",
                  getFilename(),
                  "Unsupported version");
        }

        uint8_t camType = file.readUInt8();
        float camPosX = file.readFloat32();
        float camPosY = file.readFloat32();
        float camPosZ = file.readFloat32();
        float camDirX = file.readFloat32();
        float camDirY = file.readFloat32();
        float camDirZ = file.readFloat32();
        float camUpX = file.readFloat32();
        float camUpY = file.readFloat32();
        float camUpZ = file.readFloat32();
        float camNear = file.readFloat32();
        float camFar = file.readFloat32();

        Camera& camera = renderer->camera;

        camera.setPosition(Position3D(camPosX, camPosY, camPosZ));
        camera.setDirection(Direction3D(camDirX, camDirY, camDirZ));
        camera.setUp(Direction3D(camUpX, camUpY, camUpZ));
        camera.setNear(camNear);
        camera.setFar(camFar);

        if (camType == 0)
        {
            camera.setType(Camera::Perspective);

            camera.setFieldOfView(file.readFloat32());
            camera.setWidth(file.readFloat32());
            camera.setHeight(file.readFloat32());
        } else if (camType == 1)
        {
            camera.setType(Camera::Orthographic);

            camera.setLeft(file.readFloat32());
            camera.setRight(file.readFloat32());
            camera.setTop(file.readFloat32());
            camera.setBottom(file.readFloat32());
        } else
        {
            THROW(ResourceIOException,
                  "scene",
                  getFilename(),
                  "Invalid camera type");
        }

        uint32_t skyboxFileLen = file.readUInt32LE();
        String skyboxFile(skyboxFileLen);
        file.read(skyboxFileLen, skyboxFile.getData());

        if (skyboxFileLen != 0)
        {
            renderer->setSkybox(resMgr->load<GfxTexture>(skyboxFile));
        } else
        {
            renderer->setSkybox(nullptr);
        }

        renderer->bloomThreshold = file.readFloat32();
        renderer->bloom1Radius = file.readFloat32();
        renderer->bloom2Radius = file.readFloat32();
        renderer->bloom3Radius = file.readFloat32();
        renderer->bloom4Radius = file.readFloat32();
        renderer->bloom1Strength = file.readFloat32();
        renderer->bloom2Strength = file.readFloat32();
        renderer->bloom3Strength = file.readFloat32();
        renderer->bloom4Strength = file.readFloat32();
        renderer->ssaoRadius = file.readFloat32();
        renderer->bloomEnabled = file.readUInt8() != 0;
        uint32_t numColorModifiers = file.readUInt32LE();

        renderer->colorModifiers.clear();

        for (size_t i = 0; i < numColorModifiers; ++i)
        {
            GfxRenderer::ColorModifier::Type type = (GfxRenderer::ColorModifier::Type)file.readUInt8();

            GfxRenderer::ColorModifier modifier;
            modifier.type = type;

            switch (type)
            {
            case GfxRenderer::ColorModifier::ReinhardTonemapping:
            {
                modifier.reinhardTonemap.brightnessOnly = file.readUInt8() != 0;
                break;
            }
            case GfxRenderer::ColorModifier::Vignette:
            {
                modifier.vignette.radius = file.readFloat32();
                modifier.vignette.softness = file.readFloat32();
                modifier.vignette.intensity = file.readFloat32();
                break;
            }
            case GfxRenderer::ColorModifier::HueShift:
            {
                modifier.hueShift.hue = file.readFloat32();
                break;
            }
            case GfxRenderer::ColorModifier::SaturationShift:
            {
                modifier.saturationShift.saturation = file.readFloat32();
                break;
            }
            case GfxRenderer::ColorModifier::BrightnessShift:
            {
                modifier.brightnessShift.brightness = file.readFloat32();
                break;
            }
            case GfxRenderer::ColorModifier::Contrast:
            {
                modifier.contrast.contrast = file.readFloat32();
                break;
            }
            case GfxRenderer::ColorModifier::Multiply:
            {
                modifier.multiply.red = file.readFloat32();
                modifier.multiply.green = file.readFloat32();
                modifier.multiply.blue = file.readFloat32();
                break;
            }
            case GfxRenderer::ColorModifier::HueReplace:
            {
                modifier.hueReplace.hue = file.readFloat32();
                break;
            }
            case GfxRenderer::ColorModifier::SaturationReplace:
            {
                modifier.saturationReplace.saturation = file.readFloat32();
                break;
            }
            case GfxRenderer::ColorModifier::BrightnessReplace:
            {
                modifier.brightnessReplace.brightness = file.readFloat32();
                break;
            }
            default:
            {
                THROW(ResourceIOException,
                      "scene",
                      getFilename(),
                      "Invalid color modifier type");
            }
            }

            renderer->colorModifiers.append(modifier);
        }

        renderer->updateColorModifierShader();

        uint32_t numEntities = file.readUInt32LE();

        for (uint32_t i = 0; i < numEntities; ++i)
        {
            uint32_t nameLen = file.readUInt32LE();
            String name(nameLen);
            file.read(nameLen, name.getData());

            Entity *entity = createEntity(name);

            loadEntity(entity, physicsWorld, &file);
        }

        uint32_t numLights = file.readUInt32LE();

        for (uint32_t i = 0; i < numLights; ++i)
        {
            uint8_t type = file.readUInt8();
            float power = file.readFloat32();
            float red = file.readFloat32();
            float green = file.readFloat32();
            float blue = file.readFloat32();

            Light *light = renderer->addLight();

            light->power = power;
            light->color = Float3(red, green, blue);
            light->ambientStrength = file.readFloat32();

            if (type == 0)
            {
                float dirX = file.readFloat32();
                float dirY = file.readFloat32();
                float dirZ = file.readFloat32();

                light->type = Light::Directional;

                light->direction.direction = Vector3D(dirX, dirY, dirZ);
            } else if (type == 1)
            {
                float posX = file.readFloat32();
                float posY = file.readFloat32();
                float posZ = file.readFloat32();
                float dirX = file.readFloat32();
                float dirY = file.readFloat32();
                float dirZ = file.readFloat32();
                float innerCutoff = file.readFloat32();
                float outerCutoff = file.readFloat32();
                float radius = file.readFloat32();

                light->type = Light::Spot;

                light->spot.position = Position3D(posX, posY, posZ);
                light->spot.direction = Vector3D(dirX, dirY, dirZ);
                light->spot.innerCutoff = innerCutoff;
                light->spot.outerCutoff = outerCutoff;
                light->spot.radius = radius;
            } else if (type == 2)
            {
                float posX = file.readFloat32();
                float posY = file.readFloat32();
                float posZ = file.readFloat32();
                float radius = file.readFloat32();

                light->type = Light::Point;

                light->point.position = Position3D(posX, posY, posZ);
                light->point.radius = radius;
            } else
            {
                THROW(ResourceIOException,
                      "scene",
                      getFilename(),
                      "Invalid light type");
            }

            bool shadowmap = file.readUInt8() != 0;

            if (shadowmap)
            {
                float near = file.readFloat32();
                float far = file.readFloat32();
                float minBias = file.readFloat32();
                float biasScale = file.readFloat32();
                float autoBiasScale = file.readFloat32();
                size_t resolution = file.readUInt16LE();
                Light::ShadowmapPrecision precision = (Light::ShadowmapPrecision)file.readUInt8();

                light->addShadowmap(resolution, precision);

                light->shadowmapNear = near;
                light->shadowmapFar = far;
                light->shadowMinBias = minBias;
                light->shadowBiasScale = biasScale;
                light->shadowAutoBiasScale = autoBiasScale;
            }
        }

        uint32_t numScripts = file.readUInt32LE();

        for (size_t i = 0; i < numScripts; ++i)
        {
            uint32_t scriptFileLen = file.readUInt32LE();
            String scriptFile(scriptFileLen);
            file.read(scriptFileLen, scriptFile.getData());

            uint32_t nameLen = file.readUInt32LE();
            String name(nameLen);
            file.read(nameLen, name.getData());

            addScript(resMgr->load<Script>(scriptFile), name.getData());
        }
    } catch (FileException& e)
    {
        THROW(ResourceIOException,
              "scene",
              getFilename(),
              e.getString());
    }
}

void saveEntity(Entity *entity, File *file, const String& filename)
{
    file->writeUInt32LE(entity->name.getLength());
    file->write(entity->name.getLength(), entity->name.getData());

    file->writeFloat32(entity->transform.position.x);
    file->writeFloat32(entity->transform.position.y);
    file->writeFloat32(entity->transform.position.z);
    file->writeFloat32(entity->transform.scale.x);
    file->writeFloat32(entity->transform.scale.y);
    file->writeFloat32(entity->transform.scale.z);

    Float3 orientation = entity->transform.orientation.getEulerAngles();

    file->writeFloat32(DEGREES(orientation.x));
    file->writeFloat32(DEGREES(orientation.y));
    file->writeFloat32(DEGREES(orientation.z));

    if (entity->hasRenderComponent())
    {
        if (entity->getRenderComponent()->type == RenderComponent::Model)
        {
            file->writeUInt8(1);
        } else
        {
            file->writeUInt8(0);
        }
    } else
    {
        file->writeUInt8(0);
    }

    file->writeUInt8(entity->hasRigidBody());

    if (entity->hasRenderComponent())
    {
        if (entity->getRenderComponent()->type == RenderComponent::Model)
        {
            ResPtr<GfxModel> model = entity->getRenderComponent()->model;

            file->writeUInt32LE(model->getFilename().getLength());
            file->write(model->getFilename().getLength(), model->getFilename().getData());

            file->writeUInt8(entity->getRenderComponent()->modelData.shadowCaster);
        }
    }

    if (entity->hasRigidBody())
    {
        RigidBody *body = entity->getRigidBody();

        file->writeUInt8(1);

        file->writeUInt8((uint8_t)body->getType());
        file->writeFloat32(body->getMass());
        file->writeFloat32(body->getLinearDamping());
        file->writeFloat32(body->getAngularDamping());
        file->writeFloat32(body->getFriction());
        file->writeFloat32(body->getRollingFriction());
        file->writeFloat32(body->getRestitution());
        file->writeFloat32(body->getLinearSleepingThreshold());
        file->writeFloat32(body->getAngularSleepingThreshold());
        file->writeInt16LE(body->getCollisionMask());

        String shapeFilename = body->getShape()->getFilename();

        if (shapeFilename.getLength() == 0)
        {
            THROW(ResourceIOException,
                  "scene",
                  filename,
                  "The rigid body's shape must have a filename.");
        }

        file->writeUInt32LE(shapeFilename.getLength());
        file->write(shapeFilename.getLength(), shapeFilename.getData());
    } else
    {
        file->writeUInt8(0);
    }

    file->writeUInt32LE(entity->getScripts().getCount());

    for (size_t i = 0; i < entity->getScripts().getCount(); ++i)
    {
        String filename = entity->getScripts()[i]->getScript()->getFilename();

        file->writeUInt32LE(filename.getLength());
        file->write(filename.getLength(), filename.getData());
    }

    file->writeUInt32LE(entity->getEntities().getCount());

    for (size_t i = 0; i < entity->getEntities().getCount(); ++i)
    {
        saveEntity(entity->getEntities()[i], file, filename);
    }

}

void Scene::save()
{
    try
    {
        File file(getFilename().getData(), "wb");

        file.write(6, "scen\x01\x00");

        const Camera& camera = renderer->camera;

        file.writeUInt8(camera.getType() == Camera::Perspective ? 0 : 1);
        file.writeFloat32(camera.getPosition().x);
        file.writeFloat32(camera.getPosition().y);
        file.writeFloat32(camera.getPosition().z);
        file.writeFloat32(camera.getDirection().x);
        file.writeFloat32(camera.getDirection().y);
        file.writeFloat32(camera.getDirection().z);
        file.writeFloat32(camera.getUp().x);
        file.writeFloat32(camera.getUp().y);
        file.writeFloat32(camera.getUp().z);
        file.writeFloat32(camera.getNear());
        file.writeFloat32(camera.getFar());

        if (camera.getType() == Camera::Perspective)
        {
            file.writeFloat32(camera.getFieldOfView());
            file.writeFloat32(camera.getWidth());
            file.writeFloat32(camera.getHeight());
        } else if (camera.getType() == Camera::Orthographic)
        {
            file.writeFloat32(camera.getLeft());
            file.writeFloat32(camera.getRight());
            file.writeFloat32(camera.getTop());
            file.writeFloat32(camera.getBottom());
        }

        ResPtr<GfxTexture> skybox = renderer->skybox;

        if (skybox != nullptr)
        {
            if (skybox->getFilename().getLength() == 0)
            {
                THROW(ResourceIOException,
                      "scene",
                      getFilename(),
                      "The scene must have a skybox with a filename");
            }

            file.writeUInt32LE(skybox->getFilename().getLength());
            file.write(skybox->getFilename().getLength(), skybox->getFilename().getData());
        } else
        {
            file.writeUInt32LE(0);
        }

        file.writeFloat32(renderer->bloomThreshold);
        file.writeFloat32(renderer->bloom1Radius);
        file.writeFloat32(renderer->bloom2Radius);
        file.writeFloat32(renderer->bloom3Radius);
        file.writeFloat32(renderer->bloom4Radius);
        file.writeFloat32(renderer->bloom1Strength);
        file.writeFloat32(renderer->bloom2Strength);
        file.writeFloat32(renderer->bloom3Strength);
        file.writeFloat32(renderer->bloom4Strength);
        file.writeFloat32(renderer->ssaoRadius);
        file.writeUInt8(renderer->bloomEnabled ? 1 : 0);

        file.writeUInt32LE(renderer->colorModifiers.getCount());

        for (size_t i = 0; i < renderer->colorModifiers.getCount(); ++i)
        {
            GfxRenderer::ColorModifier& modifier = renderer->colorModifiers[i];

            file.writeUInt8((uint8_t)modifier.type);

            switch (modifier.type)
            {
            case GfxRenderer::ColorModifier::ReinhardTonemapping:
            {
                file.writeUInt8(modifier.reinhardTonemap.brightnessOnly ? 1 : 0);
                break;
            }
            case GfxRenderer::ColorModifier::Vignette:
            {
                file.writeFloat32(modifier.vignette.radius);
                file.writeFloat32(modifier.vignette.softness);
                file.writeFloat32(modifier.vignette.intensity);
                break;
            }
            case GfxRenderer::ColorModifier::HueShift:
            {
                file.writeFloat32(modifier.hueShift.hue);
                break;
            }
            case GfxRenderer::ColorModifier::SaturationShift:
            {
                file.writeFloat32(modifier.saturationShift.saturation);
                break;
            }
            case GfxRenderer::ColorModifier::BrightnessShift:
            {
                file.writeFloat32(modifier.brightnessShift.brightness);
                break;
            }
            case GfxRenderer::ColorModifier::Contrast:
            {
                file.writeFloat32(modifier.contrast.contrast);
                break;
            }
            case GfxRenderer::ColorModifier::Multiply:
            {
                file.writeFloat32(modifier.multiply.red);
                file.writeFloat32(modifier.multiply.green);
                file.writeFloat32(modifier.multiply.blue);
                break;
            }
            case GfxRenderer::ColorModifier::HueReplace:
            {
                file.writeFloat32(modifier.hueReplace.hue);
                break;
            }
            case GfxRenderer::ColorModifier::SaturationReplace:
            {
                file.writeFloat32(modifier.saturationReplace.saturation);
                break;
            }
            case GfxRenderer::ColorModifier::BrightnessReplace:
            {
                file.writeFloat32(modifier.brightnessReplace.brightness);
                break;
            }
            }
        }

        file.writeUInt32LE(entities.getCount());

        for (size_t i = 0; i < entities.getCount(); ++i)
        {
            saveEntity(entities[i], &file, getFilename());
        }

        file.writeUInt32LE(renderer->getLights().getCount());

        for (uint32_t i = 0; i < renderer->getLights().getCount(); ++i)
        {
            const Light *light = renderer->getLights()[i];

            file.writeUInt8((uint8_t)light->type);
            file.writeFloat32(light->power);
            file.writeFloat32(light->color.x);
            file.writeFloat32(light->color.y);
            file.writeFloat32(light->color.z);
            file.writeFloat32(light->ambientStrength);

            switch (light->type)
            {
            case Light::Directional:
            {
                file.writeFloat32(light->direction.direction.x);
                file.writeFloat32(light->direction.direction.y);
                file.writeFloat32(light->direction.direction.z);
                break;
            }
            case Light::Spot:
            {
                file.writeFloat32(light->spot.position.x);
                file.writeFloat32(light->spot.position.y);
                file.writeFloat32(light->spot.position.z);
                file.writeFloat32(light->spot.direction.x);
                file.writeFloat32(light->spot.direction.y);
                file.writeFloat32(light->spot.direction.z);
                file.writeFloat32(light->spot.innerCutoff);
                file.writeFloat32(light->spot.outerCutoff);
                file.writeFloat32(light->spot.radius);
                break;
            }
            case Light::Point:
            {
                file.writeFloat32(light->point.position.x);
                file.writeFloat32(light->point.position.y);
                file.writeFloat32(light->point.position.z);
                file.writeFloat32(light->point.radius);
            }
            }

            file.writeUInt8(light->getShadowmap() != nullptr);

            if (light->getShadowmap() != nullptr)
            {
                file.writeFloat32(light->shadowmapNear);
                file.writeFloat32(light->shadowmapFar);
                file.writeUInt16LE(light->getShadowmapResolution());
                file.writeUInt8((int)light->getShadowmapPrecision());
            }
        }

        file.writeUInt32LE(scripts.getCount());

        for (size_t i = 0; i < scripts.getCount(); ++i)
        {
            String filename = scripts[i]->getScript()->getFilename();

            file.writeUInt32LE(filename.getLength());
            file.write(filename.getLength(), filename.getData());
        }
    } catch (FileException& e)
    {
        THROW(ResourceIOException,
              "scene",
              getFilename(),
              e.getString());
    }
}

Entity *Scene::createEntity(const String& name)
{
    Entity *entity = NEW(Entity, name, this);

    entities.append(entity);

    return entity;
}

void Scene::removeEntity(size_t index)
{
    DELETE(Entity, entities[index]);

    entities.remove(index);
}

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
#include "logging.h"

Scene::Scene() : Resource(ResType::SceneType)
{
    physicsWorld = NEW(PhysicsWorld);
    renderer = NEW(GfxRenderer, this);
    audioWorld = NEW(AudioWorld);

    audioWorld->addToAudioDevice(audioDevice);
}

Scene::Scene(const Str& filename) : Resource(filename,
                                                ResType::SceneType)
{
    physicsWorld = NEW(PhysicsWorld);
    renderer = NEW(GfxRenderer, this);
    audioWorld = NEW(AudioWorld);

    audioWorld->addToAudioDevice(audioDevice);
}

Scene::~Scene()
{
    for (auto entity : entities)
    {
        DELETE(entity);
    }

    List<Script *> scripts_;

    for (auto scriptInst : scripts)
    {
        scripts_.append(scriptInst->getScript());

        DELETE(scriptInst);
    }

    for (auto script : scripts_)
    {
        script->release();
    }

    audioWorld->removeFromAudioDevice(audioDevice);

    DELETE(audioWorld);
    DELETE(renderer);
    DELETE(physicsWorld);
}

void Scene::removeContent()
{
    for (auto entity : entities)
    {
        DELETE(entity);
    }
    entities.clear();

    List<Script *> scripts_;

    for (auto scriptInst : scripts)
    {
        scripts_.append(scriptInst->getScript());

        DELETE(scriptInst);
    }
    scripts.clear();

    for (auto script : scripts_)
    {
        script->release();
    }

    audioWorld->clearSources();

    renderer->~GfxRenderer();
    new (renderer) GfxRenderer(this);

    physicsWorld->~PhysicsWorld();
    new (physicsWorld) PhysicsWorld;
}

void Scene::handleInput()
{
    _handleInput(entities);

    for (auto scriptInst : scripts)
    {
        scripting::destroy(scriptInst->getScript()->getContext(), scriptInst->method("handleInput"));
    }
}

void Scene::update()
{
    _update(entities);

    for (auto scriptInst : scripts)
    {
        scripting::destroy(scriptInst->getScript()->getContext(), scriptInst->method("update"));
    }
}

void Scene::fixedUpdate(float timestep)
{
    _fixedUpdate(entities, timestep);

    for (auto scriptInst : scripts)
    {
        scripting::destroy(scriptInst->getScript()->getContext(),
                           scriptInst->method("fixedUpdate", scripting::createFloat(timestep)));
    }

    physicsWorld->stepSimulation(timestep);

    for (auto entity : entities)
    {
        entity->updateFinalTransform();
    }
}

void Scene::_handleInput(const List<Entity *>& entities_)
{
    for (auto entity : entities_)
    {
        for (auto scriptInst : entity->getScripts())
        {
            scripting::destroy(scriptInst->getScript()->getContext(),
                               scriptInst->method("handleInput"));
        }

        _handleInput(entity->getEntities());
    }
}

void Scene::_update(const List<Entity *>& entities_)
{
    for (auto entity : entities_)
    {
        for (auto scriptInst : entity->getScripts())
        {
            scripting::destroy(scriptInst->getScript()->getContext(),
                               scriptInst->method("update"));
        }

        _update(entity->getEntities());
    }
}

void Scene::_fixedUpdate(const List<Entity *>& entities_, float timestep)
{
    for (auto entity : entities_)
    {
        for (auto scriptInst : entity->getScripts())
        {
            scripting::destroy(scriptInst->getScript()->getContext(),
                               scriptInst->method("fixedUpdate", scripting::createFloat(timestep)));
        }

        _fixedUpdate(entity->getEntities(), timestep);
    }
}

void Scene::render()
{
    for (auto entity : entities)
    {
        entity->updateFinalTransform();
    }

    renderer->updateStats();

    for (auto scriptInst : scripts)
    {
        scripting::destroy(scriptInst->getScript()->getContext(),
                           scriptInst->method("preRender"));
    }

    renderer->render();

    for (auto scriptInst : scripts)
    {
        scripting::destroy(scriptInst->getScript()->getContext(),
                           scriptInst->method("postRender"));
    }
}

void loadEntity(Entity *entity, File *file)
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
        Str modelFile = file->readStr(modelFileLen);

        bool shadowCaster = file->readUInt8() != 0;

        entity->addModel(resMgr->load<GfxModel>(modelFile), shadowCaster);

        if (file->readUInt8())
        {
            uint32_t animNameLen = file->readUInt32LE();

            Str animName = file->readStr(animNameLen);

            GfxModel *model = entity->getRenderComponent()->model;
            GfxMesh *mesh = nullptr;

            for (auto subModel : model->subModels)
            {
                for (auto lod : subModel)
                {
                    if (lod.mesh->animations.isEntry(animName))
                    {
                        mesh = lod.mesh;
                    }
                    break;
                }

                if (mesh != nullptr)
                {
                    break;
                }
            }

            if (mesh != nullptr)
            {
                entity->getRenderComponent()->setAnimationState(mesh, animName);
            }
        }
    } else if (useOverlay)
    {
        uint32_t textureFileLen = file->readUInt32LE();
        Str textureFile = file->readStr(textureFileLen);

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

        RigidBodyConstructionInfo info;

        switch (type)
        {
        case 0:
        {
            info.type = RigidBodyType::Static;
            break;
        }
        case 1:
        {
            info.type = RigidBodyType::Dynamic;
            break;
        }
        case 2:
        {
            info.type = RigidBodyType::Kinematic;
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
        Str shape = file->readStr(length);

        entity->addRigidBody(info, resMgr->load<PhysicsShape>(shape));
    }

    uint32_t numScripts = file->readUInt32LE();

    for (size_t i = 0; i < numScripts; ++i)
    {
        uint32_t scriptFileLen = file->readUInt32LE();
        Str scriptFile = file->readStr(scriptFileLen);

        entity->addScript(resMgr->load<Script>(scriptFile));
    }

    uint32_t numChildren = file->readUInt32LE();

    for (size_t i = 0; i < numChildren; ++i)
    {
        uint32_t nameLen = file->readUInt32LE();
        Str name = file->readStr(nameLen);

        Entity *child = entity->createEntity(name);

        loadEntity(child, file);
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
            camera.setType(CameraType::Perspective);

            camera.setFieldOfView(file.readFloat32());
            camera.setWidth(file.readFloat32());
            camera.setHeight(file.readFloat32());
        } else if (camType == 1)
        {
            camera.setType(CameraType::Orthographic);

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
        Str skyboxFile = file.readStr(skyboxFileLen);

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
            Str name = file.readStr(nameLen);

            Entity *entity = createEntity(name);

            loadEntity(entity, &file);
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

                light->type = GfxLightType::Directional;

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

                light->type = GfxLightType::Spot;

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

                light->type = GfxLightType::Point;

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
                float minBias = file.readFloat32();
                float biasScale = file.readFloat32();
                float autoBiasScale = file.readFloat32();
                float fixedBias = file.readFloat32();
                float shadowRadius = file.readFloat32();
                size_t resolution = file.readUInt16LE();
                GfxShadowmapPrecision precision = (GfxShadowmapPrecision)file.readUInt8();

                light->addShadowmap(resolution, precision);

                light->shadowmapNear = near;
                light->shadowMinBias = minBias;
                light->shadowBiasScale = biasScale;
                light->shadowAutoBiasScale = autoBiasScale;
                light->shadowFixedBias = fixedBias;
                light->shadowRadius = shadowRadius;
            }
        }

        uint32_t numScripts = file.readUInt32LE();

        for (size_t i = 0; i < numScripts; ++i)
        {
            uint32_t scriptFileLen = file.readUInt32LE();
            Str scriptFile = file.readStr(scriptFileLen);

            addScript(resMgr->load<Script>(scriptFile));
        }
    } catch (FileException& e)
    {
        THROW(ResourceIOException,
              "scene",
              getFilename(),
              e.getString());
    }
}

void saveEntity(Entity *entity, File *file, const Str& filename)
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
        if (entity->getRenderComponent()->mode == RenderMode::Model)
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
        if (entity->getRenderComponent()->mode == RenderMode::Model)
        {
            GfxModel *model = entity->getRenderComponent()->model;

            file->writeUInt32LE(model->getFilename().getLength());
            file->write(model->getFilename().getLength(), model->getFilename().getData());

            file->writeUInt8(entity->getRenderComponent()->modelData.shadowCaster);

            GfxAnimationState *animState = entity->getRenderComponent()->getAnimationState();

            file->writeUInt8(animState != nullptr);

            if (animState != nullptr)
            {
                file->writeUInt32LE(animState->getAnimName().getLength());
                file->write(animState->getAnimName().getLength(), animState->getAnimName().getData());
            }
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

        Str shapeFilename = body->getShape()->getFilename();

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

    for (auto scriptInst : entity->getScripts())
    {
        Str filename = scriptInst->getScript()->getFilename();

        file->writeUInt32LE(filename.getLength());
        file->write(filename.getLength(), filename.getData());
    }

    file->writeUInt32LE(entity->getEntities().getCount());

    for (auto child : entity->getEntities())
    {
        saveEntity(child, file, filename);
    }

}

void Scene::save()
{
    try
    {
        File file(getFilename().getData(), "wb");

        file.write(6, "scen\x01\x00");

        const Camera& camera = renderer->camera;

        file.writeUInt8(camera.getType() == CameraType::Perspective ? 0 : 1);
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

        if (camera.getType() == CameraType::Perspective)
        {
            file.writeFloat32(camera.getFieldOfView());
            file.writeFloat32(camera.getWidth());
            file.writeFloat32(camera.getHeight());
        } else if (camera.getType() == CameraType::Orthographic)
        {
            file.writeFloat32(camera.getLeft());
            file.writeFloat32(camera.getRight());
            file.writeFloat32(camera.getTop());
            file.writeFloat32(camera.getBottom());
        }

        GfxTexture *skybox = renderer->skybox;

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

        for (auto modifier : renderer->colorModifiers)
        {
            file.writeUInt8((uint8_t)modifier.type);

            switch (modifier.type)
            {
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

        for (auto entity : entities)
        {
            saveEntity(entity, &file, getFilename());
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
            case GfxLightType::Directional:
            {
                file.writeFloat32(light->direction.direction.x);
                file.writeFloat32(light->direction.direction.y);
                file.writeFloat32(light->direction.direction.z);
                break;
            }
            case GfxLightType::Spot:
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
            case GfxLightType::Point:
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
                file.writeFloat32(light->shadowMinBias);
                file.writeFloat32(light->shadowBiasScale);
                file.writeFloat32(light->shadowAutoBiasScale);
                file.writeFloat32(light->shadowFixedBias);
                file.writeFloat32(light->shadowRadius);
                file.writeUInt16LE(light->getShadowmapResolution());
                file.writeUInt8((int)light->getShadowmapPrecision());
            }
        }

        file.writeUInt32LE(scripts.getCount());

        for (auto scriptInst : scripts)
        {
            Str filename = scriptInst->getScript()->getFilename();

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

Entity *Scene::createEntity(const Str& name)
{
    Entity *entity = NEW(Entity, name, this);

    entities.append(entity);

    return entity;
}

void Scene::removeEntity(size_t index)
{
    DELETE(entities[index]);

    entities.remove(index);
}

Entity *Scene::findEntity(const Str& name)
{
    for (auto entity : entities)
    {
        if (entity->name == name)
        {
            return entity;
        }

        Entity *result = entity->findEntity(name);

        if (result != nullptr)
        {
            return result;
        }
    }

    return nullptr;
}

void copyEntity(Entity *dest, Entity *source)
{
    dest->transform = source->transform;
    dest->updateFinalTransform();

    if (source->hasRigidBody())
    {
        RigidBody *body = source->getRigidBody();
        RigidBodyConstructionInfo info;

        info.type = body->getType();
        info.mass = body->getMass();
        info.linearDamping = body->getLinearDamping();
        info.angularDamping = body->getAngularDamping();
        info.friction = body->getFriction();
        info.rollingFriction = body->getRollingFriction();
        info.restitution = body->getRestitution();
        info.linearSleepingThreshold = body->getLinearSleepingThreshold();
        info.angularSleepingThreshold = body->getAngularSleepingThreshold();
        info.collisionMask = body->getCollisionMask();

        RigidBody *body2 = dest->addRigidBody(info,
                                              source->getRigidBody()->getShape()->copyRef<PhysicsShape>());

        body2->setGravity(body->getGravity());
        body2->setLinearVelocity(body->getLinearVelocity());
        body2->setAngularVelocity(body->getAngularVelocity());
    }

    if (source->hasRenderComponent())
    {
        RenderComponent *render = source->getRenderComponent();

        if (render->mode == RenderMode::Model)
        {
            dest->addModel(render->model->copyRef<GfxModel>(), render->modelData.shadowCaster);
        } else if (render->mode == RenderMode::Overlay)
        {
            dest->addOverlay(render->overlayTexture);
            dest->getRenderComponent()->overlayData.color = render->overlayData.color;
        }
    }

    for (auto audio : source->getAudioSources())
    {
        AudioSource *audio2 = dest->addAudioSource(audio->getAudio()->copyRef<Audio>());

        audio2->is3d = audio->is3d;
        audio2->position = audio->position;
        audio2->referenceDistance = audio->referenceDistance;
        audio2->rolloffFactor = audio->rolloffFactor;
        audio2->maxDistance = audio->maxDistance;
        audio2->volume = audio->volume;
        audio2->velocity = audio->velocity;
        audio2->dopplerFactor = audio->dopplerFactor;
        audio2->offset = audio->offset;
        audio2->loop = audio->loop;
        audio2->playing = audio->playing;
    }

    //TODO
    /*for (auto inst : source->getScripts())
    {
        Serializable serialized;

        inst->serialize(serialized);

        ScriptInstance *new_ = dest->addScript(inst->getScript()->copyRef<Script>());

        try
        {
            new_->deserialize(serialized);
        } catch (SerializeException& e)
        {
            log("Serialization exception");
            log("    File: %s\n", e.getFile());
            log("    Line: %d\n", e.getLine());
            log("    Function: %s\n", e.getFunction());
            log("    Script: %s\n", inst->getScript()->getFilename().getData());

            dest->removeScript(new_);

            dest->addScript(inst->getScript()->copyRef<Script>());
        }
    }*/

    for (size_t i = 0; i < source->getEntities().getCount(); ++i)
    {
        Entity *entity = source->getEntities()[i];

        copyEntity(dest->createEntity(entity->name), entity);
    }
}

Resource *Scene::_copy() const
{
    Scene *scene = NEW(Scene);

    for (auto inst : scripts)
    {
        scene->addScript(inst->getScript());
    }

    scene->renderer->camera = renderer->camera;
    scene->renderer->debugDraw = renderer->debugDraw;
    scene->renderer->bloomThreshold = renderer->bloomThreshold;
    scene->renderer->bloom1Radius = renderer->bloom1Radius;
    scene->renderer->bloom2Radius = renderer->bloom2Radius;
    scene->renderer->bloom3Radius = renderer->bloom3Radius;
    scene->renderer->bloom4Radius = renderer->bloom4Radius;
    scene->renderer->bloom1Strength = renderer->bloom1Strength;
    scene->renderer->bloom2Strength = renderer->bloom2Strength;
    scene->renderer->bloom3Strength = renderer->bloom3Strength;
    scene->renderer->bloom4Strength = renderer->bloom4Strength;
    scene->renderer->bloomEnabled = renderer->bloomEnabled;
    scene->renderer->ssaoRadius = renderer->ssaoRadius;
    scene->renderer->colorModifiers = renderer->colorModifiers.copy();
    scene->renderer->setSkybox(renderer->getSkybox()->copyRef<GfxTexture>());

    scene->renderer->updateColorModifierShader();

    for (auto light : renderer->getLights())
    {
        Light *light2 = scene->renderer->addLight();

        light2->type = light->type;
        light2->power = light->power;
        light2->color = light->color;
        light2->ambientStrength = light->ambientStrength;
        light2->shadowmapNear = light->shadowmapNear;
        light2->shadowMinBias = light->shadowMinBias;
        light2->shadowAutoBiasScale = light->shadowAutoBiasScale;
        light2->direction.direction = light->direction.direction;
        light2->spot.position = light->spot.position;
        light2->spot.direction = light->spot.direction;
        light2->spot.innerCutoff = light->spot.innerCutoff;
        light2->spot.outerCutoff = light->spot.outerCutoff;
        light2->spot.radius = light->spot.radius;
        light2->point.position = light->point.position;
        light2->point.radius = light->point.radius;
        light2->point.singlePassShadowMap = light->point.singlePassShadowMap;

        if (light->getShadowmap() != nullptr)
        {
            light2->addShadowmap(light->getShadowmapResolution(),
                                 light->getShadowmapPrecision());
        }
    }

    for (auto entity : entities)
    {
        copyEntity(scene->createEntity(entity->name), entity);
    }

    //TODO:
    /*for (auto inst : scripts)
    {
        Serializable serialized;

        inst->serialize(serialized);

        ScriptInstance *new_ = scene->addScript(inst->getScript()->copyRef<Script>());

        try
        {
            new_->deserialize(serialized);
        } catch (SerializeException& e)
        {
            log("Serialization exception");
            log("    File: %s\n", e.getFile());
            log("    Line: %d\n", e.getLine());
            log("    Function: %s\n", e.getFunction());
            log("    Script: %s\n", inst->getScript()->getFilename().getData());

            scene->removeScript(new_);

            scene->addScript(inst->getScript()->copyRef<Script>());
        }
    }*/

    return (Resource *)scene;
}

#include "scene/scene.h"

#include "scene/entity.h"
#include "graphics/gfxrenderer.h"
#include "graphics/gfxshader.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxapi.h"
#include "physics/physicsworld.h"
#include "scripting/script.h"
#include "globals.h"
#include "file.h"

Scene::Scene() : Resource(SceneType)
{
    physicsWorld = NEW(PhysicsWorld);
    renderer = NEW(GfxRenderer, this);
}

Scene::Scene(const String& filename) : Resource(filename,
                                                SceneType)
{
    physicsWorld = NEW(PhysicsWorld);
    renderer = NEW(GfxRenderer, this);
}

Scene::~Scene()
{
    for (size_t i = 0; i < entities.getCount(); ++i)
    {
        DELETE(Entity, entities[i]);
    }

    DELETE(GfxRenderer, renderer);
    DELETE(PhysicsWorld, physicsWorld);
}

void Scene::removeContent()
{
    for (size_t i = 0; i < entities.getCount(); ++i)
    {
        DELETE(Entity, entities[i]);
    }

    physicsWorld->~PhysicsWorld();
    new (physicsWorld) PhysicsWorld;

    renderer->~GfxRenderer();
    new (renderer) GfxRenderer(this);

    entities = List<Entity *>();
}

void Scene::handleInput()
{
    _handleInput(entities);
}

void Scene::update()
{
    _update(entities);
}

void Scene::fixedUpdate(float timestep)
{
    _fixedUpdate(entities, timestep);

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

    bool useModel = file->readUInt8() != 0;
    bool useOverlay = file->readUInt8() != 0;
    bool useRigidBody = file->readUInt8() != 0;

    if (useModel)
    {
        uint32_t modelFileLen = file->readUInt32LE();

        String modelFile(modelFileLen);
        file->read(modelFileLen, modelFile.getData());

        bool shadowCaster = file->readUInt8() != 0;

        entity->addModel(resMgr->getResource<GfxModel>(modelFile), shadowCaster);
    } else if (useOverlay)
    {
        uint32_t textureFileLen = file->readUInt32LE();

        String textureFile(textureFileLen);
        file->read(textureFileLen, textureFile.getData());

        float red = file->readFloat32();
        float green = file->readFloat32();
        float blue = file->readFloat32();

        entity->addOverlay(resMgr->getResource<GfxTexture>(textureFile));

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

        entity->addRigidBody(world, info);

        RigidBody *rigidBody = entity->getRigidBody();

        uint32_t length = file->readUInt32LE();
        String shape(length);
        file->read(length, shape.getData());

        rigidBody->setShape(resMgr->getResource<PhysicsShape>(shape));
    }

    uint32_t numScripts = file->readUInt32LE();

    for (size_t i = 0; i < numScripts; ++i)
    {
        uint32_t scriptFileLen = file->readUInt32LE();
        String scriptFile(scriptFileLen);
        file->read(scriptFileLen, scriptFile.getData());

        entity->addScript(resMgr->getResource<Script>(scriptFile));
    }
}

void Scene::_load()
{
    try
    {
        removeContent();

        physicsWorld->addDebugDrawer();

        File file(filename.getData(), "rb");

        char magic[4];

        file.read(4, magic);

        if (magic[0] != 's' or
            magic[1] != 'c' or
            magic[2] != 'e' or
            magic[3] != 'n')
        {
            THROW(ResourceIOException,
                  "scene",
                  filename,
                  "Invalid magic");
        }

        uint8_t majorVer = file.readUInt8();
        uint8_t minorVer = file.readUInt8();

        if (majorVer != 1 or minorVer != 0)
        {
            THROW(ResourceIOException,
                  "scene",
                  filename,
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
                  filename,
                  "Invalid camera type");
        }

        uint32_t skyboxFileLen = file.readUInt32LE();
        String skyboxFile(skyboxFileLen);
        file.read(skyboxFileLen, skyboxFile.getData());

        if (skyboxFileLen != 0)
        {
            renderer->skybox = resMgr->getResource<GfxTexture>(skyboxFile);
        } else
        {
            renderer->skybox = nullptr;
        }

        uint32_t numEntities = file.readUInt32LE();

        for (uint32_t i = 0; i < numEntities; ++i)
        {
            uint32_t nameLen = file.readUInt32LE();
            String name(nameLen);
            file.read(nameLen, name.getData());

            Entity *entity = createEntity(name);

            loadEntity(entity, physicsWorld, &file);

            entities.append(entity);
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

                light->point.position = Position3D(posX, posY, posZ);
                light->point.radius = radius;
            } else
            {
                THROW(ResourceIOException,
                      "scene",
                      filename,
                      "Invalid light type");
            }

            bool shadowmap = file.readUInt8() != 0;

            if (shadowmap)
            {
                float near = file.readFloat32();
                float far = file.readFloat32();
                float minBias = file.readFloat32();
                float biasScale = file.readFloat32();
                size_t resolution = file.readUInt16LE();
                Light::ShadowmapQuality quality = (Light::ShadowmapQuality)file.readUInt8();

                light->addShadowmap(resolution, quality);

                light->shadowmapNear = near;
                light->shadowmapFar = far;
                light->shadowMinBias = minBias;
                light->shadowBiasScale = biasScale;
            }
        }
    } catch (FileException& e)
    {
        THROW(ResourceIOException,
              "scene",
              filename,
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

            file->writeUInt32LE(model->filename.getLength());
            file->write(model->filename.getLength(), model->filename.getData());

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

        String shapeFilename = body->getShape()->filename;

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
        String filename = entity->getScripts()[i]->getScript()->filename;

        file->writeUInt32LE(filename.getLength());
        file->write(filename.getLength(), filename.getData());
    }
}

void Scene::save()
{
    try
    {
        File file(filename.getData(), "wb");

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
            if (skybox->filename.getLength() == 0)
            {
                THROW(ResourceIOException,
                      "scene",
                      filename,
                      "The scene must have a skybox with a filename");
            }

            file.writeUInt32LE(skybox->filename.getLength());
            file.write(skybox->filename.getLength(), skybox->filename.getData());
        } else
        {
            file.writeUInt32LE(0);
        }

        file.writeUInt32LE(entities.getCount());

        for (size_t i = 0; i < entities.getCount(); ++i)
        {
            saveEntity(entities[i], &file, filename);
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
                file.writeUInt8((int)light->getShadowmapQuality());
            }
        }
    } catch (FileException& e)
    {
        THROW(ResourceIOException,
              "scene",
              filename,
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

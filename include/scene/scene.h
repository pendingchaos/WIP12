#ifndef SCENE_H
#define SCENE_H

#include "containers/list.h"
#include "containers/string.h"
#include "graphics/camera.h"
#include "graphics/gfxtexture.h"
#include "graphics/light.h"
#include "resource/resource.h"
#include "scene/entity.h"
#include "memory.h"

class PhysicsWorld;
class GfxShader;
class GfxMesh;
class GfxBuffer;

class Scene : public Resource
{
    NO_COPY_INHERITED(Scene, Resource);

    public:
        static const Resource::Type resource_type = Resource::SceneType;

        Scene(const String& name);
        Scene(const String& filename,
              const String& name);
        virtual ~Scene();

        virtual void removeContent();

        void handleInput();
        void update();
        void fixedUpdate(float timestep);

        Camera camera;
        ResPtr<GfxTexture> skybox;
        List<Light> lights;

        inline PhysicsWorld *getPhysicsWorld() const
        {
            return physicsWorld;
        }

        virtual void save();

        Entity *createEntity(const String& name);
        void removeEntity(size_t index);

        inline const List<Entity *>& getEntities() const
        {
            return entities;
        }
    private:
        List<Entity *> entities;

        void _handleInput(const List<Entity *>& entities_);
        void _update(const List<Entity *>& entities_);
        void _fixedUpdate(const List<Entity *>& entities_, float timestep);

        PhysicsWorld *physicsWorld;
    protected:
        virtual void _load();
};

#endif // SCENE_H

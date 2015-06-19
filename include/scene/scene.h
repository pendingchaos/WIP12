#ifndef SCENE_H
#define SCENE_H

#include "containers/list.h"
#include "containers/string.h"
#include "graphics/camera.h"
#include "graphics/gfxtexture.h"
#include "resource/resource.h"
#include "scene/entity.h"
#include "memory.h"

class PhysicsWorld;
class GfxShader;
class GfxMesh;
class GfxBuffer;
class GfxRenderer;

class Scene : public Resource
{
    NO_COPY_INHERITED(Scene, Resource);

    public:
        static const Resource::Type resource_type = Resource::SceneType;

        Scene();
        Scene(const String& filename);
        virtual ~Scene();

        virtual void removeContent();

        void handleInput();
        void update();
        void fixedUpdate(float timestep);

        inline PhysicsWorld *getPhysicsWorld() const
        {
            return physicsWorld;
        }

        inline GfxRenderer *getRenderer() const
        {
            return renderer;
        }

        virtual void save();

        Entity *createEntity(const String& name);
        void removeEntity(size_t index);

        inline const List<Entity *>& getEntities() const
        {
            return entities;
        }
    private:
        GfxRenderer *renderer;
        List<Entity *> entities;

        void _handleInput(const List<Entity *>& entities_);
        void _update(const List<Entity *>& entities_);
        void _fixedUpdate(const List<Entity *>& entities_, float timestep);

        PhysicsWorld *physicsWorld;
    protected:
        virtual void _load();
};

#endif // SCENE_H

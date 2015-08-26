#ifndef SCRIPTINCLUDE_H
#define SCRIPTINCLUDE_H

#include <stddef.h>

#define IN_SCRIPT

#include "scripting/scriptsidebindings.h"

#include "file.h"
#include "error.h"
#include "memory.h"
#include "globals.h"
#include "logging.h"
#include "backtrace.h"
#include "filesystem.h"
#include "application.h"
#include "misc_macros.h"
#include "endian_utils.h"
#include "scene/scene.h"
#include "scene/entity.h"
#include "scene/transform.h"
#include "graphics/gfxapi.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxmodel.h"
#include "graphics/gfxshader.h"
#include "graphics/gfxtexture.h"
#include "graphics/gfxmaterial.h"
#include "graphics/gfxbuffer.h"
#include "graphics/gfxdefs.h"
#include "graphics/gfxrenderer.h"
#include "graphics/camera.h"
#include "graphics/gfxdebugdrawer.h"
#include "graphics/font.h"
#include "graphics/gputimer.h"
#include "scripting/script.h"
#include "resource/resource.h"
#include "resource/resourcemanager.h"
#include "math/t2.h"
#include "math/t3.h"
#include "math/t4.h"
#include "math/matrix3x3.h"
#include "math/matrix4x4.h"
#include "math/quaternion.h"
#include "math/aabb.h"
#include "containers/list.h"
#include "containers/string.h"
#include "containers/hashmap.h"
#include "containers/resizabledata.h"
#include "physics/physicsworld.h"
#include "physics/rigidbody.h"
#include "physics/physicsshape.h"
#include "physics/physicsdebugdrawer.h"
#include "platform.h"
#include "audio/audio.h"
#include "audio/audioworld.h"
#include "audio/audiodevice.h"

#define _SCRIPT_SIDE_IMPLS
#include "scripting/scriptsidebindings.h"

class InstanceBase
{
    public:
        InstanceBase(Application *app_,
                     Entity *entity_,
                     Scene *scene_,
                     Script *script_) : app(app_),
                                        platform(app->getPlatform()),
                                        resMgr(app->getResourceManager()),
                                        gfxApi(app->getGfxApi()),
                                        fileSys(app->getFilesystem()),
                                        debugDrawer(app->getDebugDrawer()),
                                        audioDevice(app->getAudioDevice()),
                                        entity(entity_),
                                        script(script_),
                                        scene(scene_) {}
        virtual ~InstanceBase() {}
        virtual void init() {}
        virtual void deinit() {}
        virtual void handleInput() {}
        virtual void update() {}
        virtual void fixedUpdate(float timestep) {}
        virtual void preRender() {}
        virtual void postRender() {}
        virtual void serialize(Serializable& serialized) {}
        virtual void deserialize(const Serializable& serialized) {}
        virtual void handleMessage(BaseMessage *message) {}
        inline Entity *getEntity() const {return entity;}

        template <typename T, typename... Args>
        void sendMessageLocal(Args... args)
        {
            sendMessageEntity<T>(entity, args...);
        }

        template <typename T, typename... Args>
        void sendMessageLocalRecursive(Args... args)
        {
            sendMessageEntityRecursive<T>(entity, args...);
        }

        template <typename T, typename... Args>
        void sendMessageEntity(Entity *target, Args... args)
        {
            T message(args...);

            for (size_t i = 0; i < target->getScripts().getCount(); ++i)
            {
                target->getScripts()[i]->handleMessage(&message);
            }
        }

        template <typename T, typename... Args>
        void sendMessageEntityRecursive(Entity *target, Args... args)
        {
            sendMessageEntity<T>(target, args...);

            for (size_t i = 0; i < target->getEntities().getCount(); ++i)
            {
                sendMessageEntityRecursive<T>(target->getEntities()[i], args...);
            }
        }

        template <typename T, typename... Args>
        void sendMessageGlobal(Args... args)
        {
            for (size_t i = 0; i < scene->getEntities().getCount(); ++i)
            {
                sendMessageEntityRecursive<T>(scene->getEntities()[i], args...);
            }
        }
    protected:
        Application *app;
        Platform *platform;
        ResourceManager *resMgr;
        GfxApi *gfxApi;
        Filesystem *fileSys;
        GfxDebugDrawer *debugDrawer;
        AudioDevice *audioDevice;
        Entity *entity;
        Script *script;
        Scene *scene;
};

#define BEGIN_INSTANCE(name, inherits) class name : public inherits\
{\
    public:\
        constexpr static const char *_name = STR(name);\
        name(Application *app, Entity *entity, Scene *scene, Script *script) : inherits(app, entity, scene, script) {name::init();}\
        virtual ~name() {name::deinit();}

#define END_INSTANCE(name) };\
extern "C" {\
name *JOIN(_create, name)(Application *app, Entity *entity, Scene *scene, Script *script){\
    return new name(app, entity, scene, script);\
}\
name *JOIN(_destroy, name)(name *obj)\
{\
    delete obj;\
}\
}

#define BEGIN_MESSAGE(name) class name : public BaseMessage\
{\
    public:\
        constexpr static const char *_name = STR(name);

#define END_MESSAGE(name) };


#define BEGIN_MESSAGE_HANDLERS virtual void handleMessage(BaseMessage *message)\
{

#define DEF_MESSAGE_HANDLER(type) if (message->cast<type>() != nullptr)
#define DEF_UNKNOWN_MESSAGE_HANDLER else

#define END_MESSAGE_HANDLERS };

#endif // SCRIPTINCLUDE_H

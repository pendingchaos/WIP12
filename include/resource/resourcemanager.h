#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "containers/hashmap.h"
#include "containers/string.h"
#include "resource.h"
#include "memory.h"
#include "scripting/bindings.h"
#include <SDL2/SDL_assert.h>

class GfxShader;
class GfxTexture;
class GfxMesh;
class GfxMaterial;
class GfxModel;
class Scene;
class Script;
class PhysicsShape;
class Audio;
class Font;

class ResourceManager
{
    public:
        ResourceManager();
        ~ResourceManager();

        template <typename T>
        T *load(const Str& filename) NO_BIND
        {
            if (isResource(getType<T>(), filename))
            {
                Resource *res = resources.get(getType<T>()).get(filename);

                return (T *)res->copyRef<Resource>();
            }

            T *resource = NEW(T, filename);

            resource->load();

            HashMap<Str, Resource *> *resources_;

            ResType type = resource->getType();

            try
            {
                resources_ = &resources.get(type);
            } catch (const LookupException& e)
            {
                resources.set(type, HashMap<Str, Resource *>());

                resources_ = &resources.get(type);
            }

            resources_->set(filename, resource);

            Resource *res = resource;

            return (T *)res->copyRef<Resource>();
        }

        GfxShader *loadShader(const Str& filename) RET_PTR_NO_CPP_REF;
        GfxTexture *loadTexture(const Str& filename) RET_PTR_NO_CPP_REF;
        GfxMesh *loadMesh(const Str& filename) RET_PTR_NO_CPP_REF;
        GfxMaterial *loadMaterial(const Str& filename) RET_PTR_NO_CPP_REF;
        GfxModel *loadModel(const Str& filename) RET_PTR_NO_CPP_REF;
        Scene *loadScene(const Str& filename) RET_PTR_NO_CPP_REF;
        Script *loadScript(const Str& filename) NO_BIND;
        PhysicsShape *loadPhysicsShape(const Str& filename) RET_PTR_NO_CPP_REF;
        Audio *loadAudio(const Str& filename) RET_PTR_NO_CPP_REF;
        Font *loadFont(const Str& filename) RET_PTR_NO_CPP_REF;

        Resource *load(ResType type, const Str& filename) RET_PTR_NO_CPP_REF
        {
            switch (type)
            {
            case ResType::GfxShaderType: return (Resource *)loadShader(filename);
            case ResType::GfxTextureType: return (Resource *)loadTexture(filename);
            case ResType::GfxMeshType: return (Resource *)loadMesh(filename);
            case ResType::GfxMaterialType: return (Resource *)loadMaterial(filename);
            case ResType::GfxModelType: return (Resource *)loadModel(filename);
            case ResType::SceneType: return (Resource *)loadScene(filename);
            case ResType::ScriptType: return (Resource *)loadScript(filename);
            case ResType::PhysicsShapeType: return (Resource *)loadPhysicsShape(filename);
            case ResType::AudioType: return (Resource *)loadAudio(filename);
            case ResType::FontType: return (Resource *)loadFont(filename);
            default: SDL_assert_release(false);
            }
        }

        GfxShader *loadShaderAndCopy(const Str& filename) RET_PTR_NO_CPP_REF;
        GfxTexture *loadTextureAndCopy(const Str& filename) RET_PTR_NO_CPP_REF;
        GfxMesh *loadMeshAndCopy(const Str& filename) RET_PTR_NO_CPP_REF;
        GfxMaterial *loadMaterialAndCopy(const Str& filename) RET_PTR_NO_CPP_REF;
        GfxModel *loadModelAndCopy(const Str& filename) RET_PTR_NO_CPP_REF;
        Scene *loadSceneAndCopy(const Str& filename) RET_PTR_NO_CPP_REF;
        Script *loadScriptAndCopy(const Str& filename) NO_BIND;
        PhysicsShape *loadPhysicsShapeAndCopy(const Str& filename) RET_PTR_NO_CPP_REF;
        Audio *loadAudioAndCopy(const Str& filename) RET_PTR_NO_CPP_REF;
        Font *loadFontAndCopy(const Str& filename) RET_PTR_NO_CPP_REF;

        Resource *loadAndCopy(ResType type, const Str& filename) RET_PTR_NO_CPP_REF
        {
            switch (type)
            {
            case ResType::GfxShaderType: return (Resource *)loadShaderAndCopy(filename);
            case ResType::GfxTextureType: return (Resource *)loadTextureAndCopy(filename);
            case ResType::GfxMeshType: return (Resource *)loadMeshAndCopy(filename);
            case ResType::GfxMaterialType: return (Resource *)loadMaterialAndCopy(filename);
            case ResType::GfxModelType: return (Resource *)loadModelAndCopy(filename);
            case ResType::SceneType: return (Resource *)loadSceneAndCopy(filename);
            case ResType::ScriptType: return (Resource *)loadScriptAndCopy(filename);
            case ResType::PhysicsShapeType: return (Resource *)loadPhysicsShapeAndCopy(filename);
            case ResType::AudioType: return (Resource *)loadAudioAndCopy(filename);
            case ResType::FontType: return (Resource *)loadFontAndCopy(filename);
            default: SDL_assert_release(false);
            }
        }

        template <typename T>
        T *loadAndCopy(const Str& filename) NO_BIND
        {
            T *res = load<T>(filename);
            res->release();

            return (T *)res->copy();
        }

        bool isResource(ResType type, const Str& filename) const;

        void cleanupResources();
    private:
        HashMap<ResType, HashMap<Str, Resource *>> resources;

        template <typename T>
        ResType getType() const
        {
            return T::resource_type;
        }
} BIND NOT_COPYABLE;

#endif // RESOURCEMANAGER_H

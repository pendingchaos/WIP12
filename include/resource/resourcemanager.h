#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "containers/hashmap.h"
#include "containers/string.h"
#include "resource.h"
#include "memory.h"
#include "scripting/bindings.h"

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
        T *load(const String& filename) NO_BIND
        {
            if (isResource(getType<T>(), filename))
            {
                Resource *res = resources.get(getType<T>()).get(filename);

                return (T *)res->copyRef<Resource>();
            }

            T *resource = NEW(T, filename);

            resource->load();

            HashMap<String, Resource *> *resources_;

            ResType type = resource->getType();

            try
            {
                resources_ = &resources.get(type);
            } catch (const LookupException& e)
            {
                resources.set(type, HashMap<String, Resource *>());

                resources_ = &resources.get(type);
            }

            resources_->set(filename, resource);

            Resource *res = resource;

            return (T *)res->copyRef<Resource>();
        }

        GfxShader *loadShader(const String& filename);
        GfxTexture *loadTexture(const String& filename);
        GfxMesh *loadMesh(const String& filename);
        GfxMaterial *loadMaterial(const String& filename);
        GfxModel *loadModel(const String& filename);
        Scene *loadScene(const String& filename);
        Script *loadScript(const String& filename) NO_BIND;
        PhysicsShape *loadPhysicsShape(const String& filename);
        Audio *loadAudio(const String& filename);
        Font *loadFont(const String& filename);

        Resource *load(ResType type, const String& filename)
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
            }
        }

        GfxShader *loadShaderAndCopy(const String& filename);
        GfxTexture *loadTextureAndCopy(const String& filename);
        GfxMesh *loadMeshAndCopy(const String& filename);
        GfxMaterial *loadMaterialAndCopy(const String& filename);
        GfxModel *loadModelAndCopy(const String& filename);
        Scene *loadSceneAndCopy(const String& filename);
        Script *loadScriptAndCopy(const String& filename) NO_BIND;
        PhysicsShape *loadPhysicsShapeAndCopy(const String& filename);
        Audio *loadAudioAndCopy(const String& filename);
        Font *loadFontAndCopy(const String& filename);

        Resource *loadAndCopy(ResType type, const String& filename)
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
            }
        }

        template <typename T>
        T *loadAndCopy(const String& filename) NO_BIND
        {
            T *res = load<T>(filename);
            res->release();

            return (T *)res->copy();
        }

        bool isResource(ResType type, const String& filename) const;

        void cleanupResources();
    private:
        HashMap<ResType, HashMap<String, Resource *>> resources;

        template <typename T>
        inline ResType getType() const
        {
            return T::resource_type;
        }
} BIND NOT_COPYABLE;

#endif // RESOURCEMANAGER_H

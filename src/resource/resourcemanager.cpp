#include "resource/resourcemanager.h"

#include "logging.h"
#include "graphics/gfxshader.h"
#include "graphics/gfxtexture.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxmaterial.h"
#include "graphics/gfxmodel.h"
#include "scene/scene.h"
#include "scripting/script.h"
#include "physics/physicsshape.h"
#include "audio/audio.h"
#include "graphics/font.h"

ResourceManager::ResourceManager() {}

ResourceManager::~ResourceManager()
{
    for (auto kv : resources)
    {
        HashMap<Str, Resource *> resources_ = kv.second;

        for (auto kv_ : resources_)
        {
            kv_.second->release();
        }
    }
}

bool ResourceManager::isResource(ResType type, const Str& filename) const
{
    auto pos = resources.find(type);

    if (pos != resources.end())
    {
        return pos->second.isEntry(filename);
    }

    return false;
}

GfxShader *ResourceManager::loadShader(const Str& filename) {return load<GfxShader>(filename);}
GfxTexture *ResourceManager::loadTexture(const Str& filename) {return load<GfxTexture>(filename);}
GfxMesh *ResourceManager::loadMesh(const Str& filename) {return load<GfxMesh>(filename);}
GfxMaterial *ResourceManager::loadMaterial(const Str& filename) {return load<GfxMaterial>(filename);}
GfxModel *ResourceManager::loadModel(const Str& filename) {return load<GfxModel>(filename);}
Scene *ResourceManager::loadScene(const Str& filename) {return load<Scene>(filename);}
Script *ResourceManager::loadScript(const Str& filename) {return load<Script>(filename);}
PhysicsShape *ResourceManager::loadPhysicsShape(const Str& filename) {return load<PhysicsShape>(filename);}
Audio *ResourceManager::loadAudio(const Str& filename) {return load<Audio>(filename);}
Font *ResourceManager::loadFont(const Str& filename) {return load<Font>(filename);}

GfxShader *ResourceManager::loadShaderAndCopy(const Str& filename) {return loadAndCopy<GfxShader>(filename);}
GfxTexture *ResourceManager::loadTextureAndCopy(const Str& filename) {return loadAndCopy<GfxTexture>(filename);}
GfxMesh *ResourceManager::loadMeshAndCopy(const Str& filename) {return loadAndCopy<GfxMesh>(filename);}
GfxMaterial *ResourceManager::loadMaterialAndCopy(const Str& filename) {return loadAndCopy<GfxMaterial>(filename);}
GfxModel *ResourceManager::loadModelAndCopy(const Str& filename) {return loadAndCopy<GfxModel>(filename);}
Scene *ResourceManager::loadSceneAndCopy(const Str& filename) {return loadAndCopy<Scene>(filename);}
Script *ResourceManager::loadScriptAndCopy(const Str& filename) {return loadAndCopy<Script>(filename);}
PhysicsShape *ResourceManager::loadPhysicsShapeAndCopy(const Str& filename) {return loadAndCopy<PhysicsShape>(filename);}
Audio *ResourceManager::loadAudioAndCopy(const Str& filename) {return loadAndCopy<Audio>(filename);}
Font *ResourceManager::loadFontAndCopy(const Str& filename) {return loadAndCopy<Font>(filename);}

void ResourceManager::cleanupResources()
{
    //TODO: Invalid read of size 4.
    /*for (auto kv : resources)
    {
        HashMap<String, Resource *>& resources_ = kv.second;

        List<Resource *> toDelete;

        for (auto kv_ : resources_)
        {
            Resource *resource = kv_.second;

            if (resource->getRefCount() == 1)
            {
                toDelete.append(resource);
            }
        }

        for (auto res : toDelete)
        {
            auto it = resources_.begin();

            for (; it != resources_.end(); ++it)
            {
                if (it->second == res)
                {
                    break;
                }
            }

            if (it != resources_.end())
            {
                resources_.removeEntry(it);
            }

            res->release();
        }
    }*/
}

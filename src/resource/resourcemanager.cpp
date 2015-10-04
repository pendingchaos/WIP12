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
        HashMap<String, Resource *> resources_ = kv.second;

        for (auto kv_ : resources_)
        {
            kv_.second->release();
        }
    }
}

bool ResourceManager::isResource(ResType type, const String& filename) const
{
    auto pos = resources.find(type);

    if (pos != resources.end())
    {
        return pos->second.isEntry(filename);
    }

    return false;
}

GfxShader *ResourceManager::loadShader(const String& filename) {return load<GfxShader>(filename);}
GfxTexture *ResourceManager::loadTexture(const String& filename) {return load<GfxTexture>(filename);}
GfxMesh *ResourceManager::loadMesh(const String& filename) {return load<GfxMesh>(filename);}
GfxMaterial *ResourceManager::loadMaterial(const String& filename) {return load<GfxMaterial>(filename);}
GfxModel *ResourceManager::loadModel(const String& filename) {return load<GfxModel>(filename);}
Scene *ResourceManager::loadScene(const String& filename) {return load<Scene>(filename);}
Script *ResourceManager::loadScript(const String& filename) {return load<Script>(filename);}
PhysicsShape *ResourceManager::loadPhysicsShape(const String& filename) {return load<PhysicsShape>(filename);}
Audio *ResourceManager::loadAudio(const String& filename) {return load<Audio>(filename);}
Font *ResourceManager::loadFont(const String& filename) {return load<Font>(filename);}

GfxShader *ResourceManager::loadShaderAndCopy(const String& filename) {return loadAndCopy<GfxShader>(filename);}
GfxTexture *ResourceManager::loadTextureAndCopy(const String& filename) {return loadAndCopy<GfxTexture>(filename);}
GfxMesh *ResourceManager::loadMeshAndCopy(const String& filename) {return loadAndCopy<GfxMesh>(filename);}
GfxMaterial *ResourceManager::loadMaterialAndCopy(const String& filename) {return loadAndCopy<GfxMaterial>(filename);}
GfxModel *ResourceManager::loadModelAndCopy(const String& filename) {return loadAndCopy<GfxModel>(filename);}
Scene *ResourceManager::loadSceneAndCopy(const String& filename) {return loadAndCopy<Scene>(filename);}
Script *ResourceManager::loadScriptAndCopy(const String& filename) {return loadAndCopy<Script>(filename);}
PhysicsShape *ResourceManager::loadPhysicsShapeAndCopy(const String& filename) {return loadAndCopy<PhysicsShape>(filename);}
Audio *ResourceManager::loadAudioAndCopy(const String& filename) {return loadAndCopy<Audio>(filename);}
Font *ResourceManager::loadFontAndCopy(const String& filename) {return loadAndCopy<Font>(filename);}

void ResourceManager::cleanupResources()
{
    for (auto kv : resources)
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
    }
}

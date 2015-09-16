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
    for (size_t i = 0; i < resources.getEntryCount(); ++i)
    {
        HashMap<String, Resource *> resources_ = resources.getValue(i);

        for (size_t j = 0; j < resources_.getEntryCount(); ++j)
        {
            resources_.getValue(j)->release();
        }
    }
}

bool ResourceManager::isResource(ResType type, const String& filename) const
{
    int entry = resources.findEntry(type);

    if (entry != -1)
    {
        return resources.getValue(entry).findEntry(filename) != -1;
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

void ResourceManager::autoReloadResources() const
{
    for (size_t i = 0; i < resources.getEntryCount(); ++i)
    {
        HashMap<String, Resource *> resources_ = resources.getValue(i);

        for (size_t j = 0; j < resources_.getEntryCount(); ++j)
        {
            Resource *resource = resources_.getValue(j);

            try
            {
                resource->possiblyReload();
            } catch (ResourceIOException& e)
            {
                ERROR(CATEGORY_RENDER,
                      "Unable to reload resource at %s: %s",
                      resource->getFilename().getData(),
                      e.getString())(e.getFile(),
                                     e.getLine(),
                                     e.getFunction());
            }
        }
    }
}

void ResourceManager::cleanupResources()
{
    for (size_t i = 0; i < resources.getEntryCount(); ++i)
    {
        HashMap<String, Resource *>& resources_ = resources.getValue(i);

        List<Resource *> toDelete;

        for (size_t j = 0; j < resources_.getEntryCount(); ++j)
        {
            Resource *resource = resources_.getValue(j);

            if (resource->getRefCount() == 1)
            {
                toDelete.append(resource);
            }
        }

        for (auto res : toDelete)
        {
            int index = -1;

            for (size_t i2 = 0; i2 < resources_.getEntryCount(); ++i2)
            {
                if (resources_.getValue(i2) == res)
                {
                    index = i2;
                    break;
                }
            }

            if (index != -1)
            {
                resources_.removeEntry(index);
            }

            res->release();
        }
    }
}

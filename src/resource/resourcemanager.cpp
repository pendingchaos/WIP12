#include "resource/resourcemanager.h"

#include "logging.h"

ResourceManager::ResourceManager() {}

ResourceManager::~ResourceManager() {}

void ResourceManager::removeResource(Resource::Type type, const String& filename)
{
    HashMap<String, ResPtr<Resource> > resources_ = resources.get(type);

    int entry = resources_.findEntry(filename);

    if (entry != -1)
    {
        resources_.removeEntry(entry);
    }
}

bool ResourceManager::isResource(Resource::Type type, const String& filename) const
{
    int entry = resources.findEntry(type);

    if (entry != -1)
    {
        return resources.getValue(entry).findEntry(filename) != -1;
    }

    return false;
}

void ResourceManager::autoReloadResources() const
{
    for (size_t i = 0; i < resources.getEntryCount(); ++i)
    {
        HashMap<String, ResPtr<Resource> > resources_ = resources.getValue(i);

        for (size_t j = 0; j < resources_.getEntryCount(); ++j)
        {
            ResPtr<Resource> resource = resources_.getValue(j);

            try
            {
                resource->possiblyReload();
            } catch (ResourceIOException& e)
            {
                ERROR(CATEGORY_RENDER,
                      "Unable to reload resource at %s: %s",
                      resource->filename.getData(),
                      e.getString())(e.getFile(),
                                     e.getLine(),
                                     e.getFunction());
            }
        }
    }
}

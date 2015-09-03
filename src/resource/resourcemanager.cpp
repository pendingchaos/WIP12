#include "resource/resourcemanager.h"

#include "logging.h"

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

        for (size_t j = 0; j < toDelete.getCount(); ++j)
        {
            int index = -1;

            for (size_t i2 = 0; i2 < resources_.getEntryCount(); ++i2)
            {
                if (resources_.getValue(i2) == toDelete[j])
                {
                    index = i2;
                    break;
                }
            }

            if (index != -1)
            {
                resources_.removeEntry(index);
            }

            toDelete[j]->release();
        }
    }
}

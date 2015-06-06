#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "containers/hashmap.h"
#include "containers/string.h"
#include "resource.h"
#include "memory.h"

class ResourceManager
{
    public:
        ResourceManager();
        ~ResourceManager();

        template <typename T>
        ResPtr<T> newResource(const String& name,
                              const String& filename)
        {
            try
            {
                return getResource<T>(name);
            } catch (const LookupException& e) {}

            ResPtr<T> resource = NEW(T, filename, name);

            resource->load();

            HashMap<String, ResPtr<Resource> > *resources_;

            Resource::Type type = resource->getType();

            try
            {
                resources_ = &resources.get(type);
            } catch (const LookupException& e)
            {
                resources.set(type, HashMap<String, ResPtr<Resource> >());

                resources_ = &resources.get(type);
            }

            resources_->set(name, resource.getPtr());

            return resource;
        }

        void removeResource(Resource::Type type, const String& name);

        template <typename T>
        inline ResPtr<T> getResource(const String& name)
        {
            return ResPtr<T>((T *)resources.get(getType<T>()).get(name).getPtr());
        }

        template <typename T>
        ResPtr<T> getResourceByFilename(const String& filename)
        {
            Resource::Type type = T::resource_type;

            int entry = resources.findEntry(type);

            if (entry == -1)
            {
                return newResource<T>(filename, filename);
            }

            HashMap<String, ResPtr<Resource> > resources_ = resources.getValue(entry);

            for (size_t i = 0; i < resources_.getEntryCount(); ++i)
            {
                if (resources_.getValue(i)->filename == filename)
                {
                    return ResPtr<T>((T *)resources_.getValue(i).getPtr());
                }
            }

            return newResource<T>(filename, filename);
        }

        bool isResource(Resource::Type type, const String& name) const;

        void autoReloadResources() const;
    private:
        HashMap<Resource::Type, HashMap<String, ResPtr<Resource> > > resources;

        //Hack around wierd compilation error.
        template <typename T>
        inline Resource::Type getType() const
        {
            return T::resource_type;
        }
};

#endif // RESOURCEMANAGER_H

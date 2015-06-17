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
        ResPtr<T> newResource(const String& filename)
        {
            if (isResource(T::resource_type, filename))
            {
                return getResource<T>(filename);
            }

            ResPtr<T> resource = NEW(T, filename);

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

            resources_->set(filename, resource.getPtr());

            return resource;
        }

        void removeResource(Resource::Type type, const String& filename);

        template <typename T>
        ResPtr<T> getResource(const String& filename)
        {
            Resource::Type type = T::resource_type;

            int entry = resources.findEntry(type);

            if (entry == -1)
            {
                return newResource<T>(filename);
            }

            HashMap<String, ResPtr<Resource> > resources_ = resources.getValue(entry);

            entry = resources_.findEntry(filename);

            if (entry == -1)
            {
                return newResource<T>(filename);
            }

            return ResPtr<T>((T *)resources_.getValue(entry).getPtr());
        }

        bool isResource(Resource::Type type, const String& filename) const;

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

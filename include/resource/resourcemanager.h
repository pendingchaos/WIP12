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
        ResPtr<T> load(const String& filename)
        {
            if (isResource(getType<T>(), filename))
            {
                ResPtr<Resource> res = resources.get(getType<T>()).get(filename);

                return ResPtr<T>((T *)res->copyRef<Resource>().getPtr());
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

            ResPtr<Resource> res((Resource *)resource.getPtr());

            return ResPtr<T>((T *)res->copyRef<Resource>().getPtr());
        }

        bool isResource(Resource::Type type, const String& filename) const;

        void autoReloadResources() const;
        void cleanupResources();
    private:
        HashMap<Resource::Type, HashMap<String, ResPtr<Resource> > > resources;

        template <typename T>
        inline Resource::Type getType() const
        {
            return T::resource_type;
        }
};

#endif // RESOURCEMANAGER_H

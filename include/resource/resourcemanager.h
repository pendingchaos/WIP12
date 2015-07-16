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
        T *load(const String& filename)
        {
            if (isResource(getType<T>(), filename))
            {
                Resource *res = resources.get(getType<T>()).get(filename);

                return (T *)res->copyRef<Resource>();
            }

            T *resource = NEW(T, filename);

            resource->load();

            HashMap<String, Resource *> *resources_;

            Resource::Type type = resource->getType();

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

        template <typename T>
        T *loadAndCopy(const String& filename)
        {
            T *res = load<T>(filename);
            res->release();

            return (T *)res->copy();
        }

        bool isResource(Resource::Type type, const String& filename) const;

        void autoReloadResources() const;
        void cleanupResources();
    private:
        HashMap<Resource::Type, HashMap<String, Resource *>> resources;

        template <typename T>
        inline Resource::Type getType() const
        {
            return T::resource_type;
        }
};

#endif // RESOURCEMANAGER_H

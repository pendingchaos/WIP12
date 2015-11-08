#ifndef RESOURCE_H
#define RESOURCE_H

#include "containers/string.h"
#include "containers/list.h"
#include "misc_macros.h"
#include "memory.h"
#include "scripting/bindings.h"

#include <atomic>

class ResourceManager;

class ResourceIOException : public Exception
{
    public:
        ResourceIOException(const char *file_,
                            size_t line_,
                            const char *function_,
                            const Str& resourceType_,
                            const Str& filename_,
                            const Str& problem_) : Exception(file_, line_, function_),
                                                      resourceType(resourceType_),
                                                      filename(filename_),
                                                      problem(problem_) {}

        virtual const char *getString() const
        {
            static char string[FILENAME_MAX+1024];
            std::memset(string, 0, sizeof(string));

            std::snprintf(string,
                          sizeof(string),
                          "Unable to load/save %s resource at %s: %s",
                          resourceType.getData(),
                          filename.getData(),
                          problem.getData());

            return string;
        }

        const Str& getResourceType() const
        {
            return resourceType;
        }

        const Str& getFilename() const
        {
            return filename;
        }

        const Str& getProblem() const
        {
            return problem;
        }
    private:
        Str resourceType;
        Str filename;
        Str problem;
};

enum class ResType
{
    GfxShaderType,
    GfxTextureType,
    GfxMeshType,
    GfxMaterialType,
    GfxModelType,
    SceneType,
    ScriptType,
    PhysicsShapeType,
    AudioType,
    FontType
} BIND ENUM_CLASS;

class Resource
{
    public:
        virtual ~Resource();

        virtual void removeContent()=0;

        void load();
        virtual void save();

        Resource *copy() const
        {
            return _copy();
        }

        ResType getType() const
        {
            return type;
        }

        void release()
        {
            if (--refCount == 0)
            {
                DELETE(this);
            }
        }

        uint32_t getRefCount() const
        {
            return refCount;
        }

        template <typename T>
        T *copyRef() NO_BIND
        {
            ++refCount;

            return (T *)this;
        }

        template <typename T>
        const T *copyRef() const NO_BIND
        {
            ++refCount;

            return (const T *)this;
        }

        const Str& getFilename() const
        {
            return filename;
        }

        void setFilename(const Str& filename_)
        {
            removeContent();
            filename = filename_;
            load();
        }
    private:
        Str filename;

        ResType type;
        mutable std::atomic_uint_fast32_t refCount;
    protected:
        virtual void _load() {}
        virtual Resource *_copy() const {return nullptr;}

        Resource(ResType type);
        Resource(const Str& filename,
                 ResType type);

    NO_COPY(Resource)
} BIND DESTROY(obj->release());

#endif // RESOURCE_H

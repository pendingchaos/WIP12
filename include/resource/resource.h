#ifndef RESOURCE_H
#define RESOURCE_H

#include "containers/string.h"
#include "containers/list.h"
#include "misc_macros.h"
#include "memory.h"
#include "scripting/bindings.h"

#include <ctime>

class ResourceManager;
class GfxShader;
class GfxTexture;
class GfxMesh;
class GfxMaterial;
class GfxModel;
class Scene;
class Script;

class ResourceIOException : public Exception
{
    public:
        ResourceIOException(const char *file_,
                            size_t line_,
                            const char *function_,
                            const String& resourceType_,
                            const String& filename_,
                            const String& problem_) : Exception(file_, line_, function_),
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

        inline const String& getResourceType() const
        {
            return resourceType;
        }

        inline const String& getFilename() const
        {
            return filename;
        }

        inline const String& getProblem() const
        {
            return problem;
        }
    private:
        String resourceType;
        String filename;
        String problem;
};

#undef _RES_INC_REF_COUNT
#undef _RES_RELEASE

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

class GfxShader;
class GfxTexture;
class GfxMesh;
class GfxMaterial;
class GfxModel;
class Scene;
class Script;
class PhysicsShape;
class Audio;
class Font;

class Resource
{
    public:
        virtual ~Resource();

        virtual void removeContent()=0;

        void load();
        virtual void reload();
        virtual void save();

        Resource *copy() const
        {
            return _copy();
        }

        inline ResType getType() const
        {
            return type;
        }

        inline bool isLoaded() const
        {
            return loaded;
        }

        inline time_t getLastFileModification() const
        {
            return lastFileModification;
        }

        bool shouldReload() const;

        virtual void possiblyReload()
        {
            if (shouldReload())
            {
                reload();
            }
        }

        inline void release()
        {
            --refCount;

            if (refCount == 0)
            {
                DELETE(Resource, this);
            }
        }

        inline uint32_t getRefCount() const
        {
            return refCount;
        }

        template <typename T>
        inline T *copyRef() NO_BIND
        {
            ++refCount;

            return (T *)this;
        }

        template <typename T>
        inline T *copyRef() const NO_BIND
        {
            ++refCount;

            return (const T *)this;
        }

        inline const String& getFilename() const
        {
            return filename;
        }

        inline void setFilename(const String& filename_)
        {
            removeContent();

            filename = filename_.copy();

            load();
        }

        bool autoReload;
    private:
        String filename;
        void refreshModification();

        ResType type;
        bool loaded;
        time_t lastFileModification;
        mutable uint32_t refCount;
    protected:
        virtual void _load() {}
        virtual Resource *_copy() const {return nullptr;}

        Resource(ResType type);
        Resource(const String& filename,
                 ResType type);

    NO_COPY(Resource)
} BIND DESTROY(obj->release());

#endif // RESOURCE_H

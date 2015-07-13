#ifndef RESOURCE_H
#define RESOURCE_H

#include "containers/string.h"
#include "containers/list.h"
#include "containers/pair.h"
#include "misc_macros.h"
#include "memory.h"

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

template <typename T>
class ResPtr
{
    public:
        typedef T type;

        ResPtr() : ptr(nullptr) {}
        ResPtr(nullptr_t null) : ptr(nullptr) {}

        ResPtr(T *ptr_) : ptr(ptr_) {}

        ResPtr(const ResPtr& other)
         : ptr(const_cast<T *>(other.getPtr())) {}

        ResPtr& operator = (const ResPtr& other)
        {
            T *otherPtr = const_cast<T *>(other.getPtr());

            ptr = reinterpret_cast<T *>(otherPtr);

            return *this;
        }

        template <typename Other>
        ResPtr& operator = (Other *other)
        {
            ptr = reinterpret_cast<T *>(other);

            return *this;
        }

        inline T& operator * ()
        {
            return *ptr;
        }

        inline const T& operator * () const
        {
            return *ptr;
        }

        inline T *operator -> ()
        {
            return ptr;
        }

        inline const T *operator -> () const
        {
            return ptr;
        }

        inline T *getPtr()
        {
            return ptr;
        }

        inline const T *getPtr() const
        {
            return ptr;
        }

        template <typename OtherT>
        inline bool operator == (const ResPtr<OtherT>& other) const
        {
            return ptr == other.getPtr();
        }

        template <typename OtherT>
        inline bool operator == (OtherT other) const
        {
            return ptr == (T *)other;
        }

        template <typename OtherT>
        inline bool operator != (const ResPtr<OtherT>& other) const
        {
            return ptr != other.getPtr();
        }

        template <typename OtherT>
        inline bool operator != (OtherT other) const
        {
            return ptr != (T *)other;
        }
    private:
        T *ptr;
};

#undef _RES_INC_REF_COUNT
#undef _RES_RELEASE

class Resource
{
    public:
        enum Type
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
        };

        virtual ~Resource();

        virtual void removeContent()=0;

        void load();
        virtual void reload();
        virtual void save();

        template <typename T>
        ResPtr<T> *copy() const
        {
            return ResPtr<T>((T *)_copy());
        }

        inline Type getType() const
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
        inline ResPtr<T> copyRef() const
        {
            ++refCount;

            return ResPtr<T>(const_cast<Resource *>(this));
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

        Type type;
        bool loaded;
        time_t lastFileModification;
        mutable uint32_t refCount;
    protected:
        virtual void _load() {}
        virtual Resource *_copy() const {return nullptr;}

        Resource(Type type);
        Resource(const String& filename,
                 Type type);

    NO_COPY(Resource)
};

#endif // RESOURCE_H

#ifndef GFXSHADER_H
#define GFXSHADER_H

#include "misc_macros.h"
#include "containers/string.h"
#include "containers/hashmap.h"
#include "graphics/GL/glfl.h"
#include "resource/resource.h"
#include "error.h"

#include <stddef.h>
#include <exception>
#include <time.h>
#include <iostream>

class GfxShader;
class GfxShaderImpl;
class GfxGLApi;

class ShaderCompileException : public Exception
{
    public:
        ShaderCompileException(const char *file_,
                               size_t line_,
                               const char *function_,
                               const String& infoLog_) : Exception(file_, line_, function_),
                                                         infoLog(infoLog_.copy()) {}

        virtual const char* getString() const
        {
            return static_cast<const char *>(infoLog.getData());
        }
    private:
        String infoLog;
};

class GfxCompiledShader
{
    NO_COPY(GfxCompiledShader)

    public:
        virtual ~GfxCompiledShader() {}

        virtual bool isInvalid() const=0;
    protected:
        GfxCompiledShader() {}
};

class GfxShader : public Resource
{
    friend class GfxCompiledShader;

    public:
        static const Resource::Type resource_type = GfxShaderType;

        enum Stage
        {
            Vertex,
            TessControl,
            TessEval,
            Geometry,
            Fragment,
            Compute
        };

        GfxShader(const String& filename);
        GfxShader();

        ~GfxShader();

        virtual void removeContent();

        virtual void save();

        void setSource(GfxShader::Stage stage, const String& source);
        const String getSource() const;

        inline GfxCompiledShader *getCompiled(const HashMap<String, String >& defines
                                              =HashMap<String, String >()) const
        {
            //Ugly hack to get around undefined reference error (g++ bug?).
            List<String> names;
            List<String> values;

            for (size_t i = 0; i < defines.getEntryCount(); ++i)
            {
                names.append(defines.getKey(i));
                values.append(defines.getValue(i));
            }

            return _getCompiled(names, values);
        }

        void recompile();

        GfxShader::Stage getStage() const;

        inline GfxShaderImpl *getImpl() const
        {
            return impl;
        }

        virtual void possiblyReload();
    private:
        GfxCompiledShader *_getCompiled(List<String> defineNames, List<String> defineValues) const;

        GfxShaderImpl *impl;
    protected:
        virtual void _load();

    NO_COPY_INHERITED(GfxShader, Resource)
};

class GfxShaderImpl
{
    friend class GfxShader;
    friend class GfxGLApi;

    protected:
        GfxShaderImpl() {}
        virtual ~GfxShaderImpl() {}

        virtual void setSource(GfxShader::Stage stage, const String& source)=0;
        virtual String getSource() const=0;

        virtual GfxCompiledShader *getCompiled(const HashMap<String, String >& defines=
                                               HashMap<String, String >()) const=0;

        virtual void recompile()=0;

        virtual GfxShader::Stage getStage() const=0;

    NO_COPY(GfxShaderImpl)
};

class GfxShaderCombination
{
    public:
        GfxShaderCombination() : cachedVertexShader(nullptr),
                                 cachedTessControlShader(nullptr),
                                 cachedTessEvalShader(nullptr),
                                 cachedGeometryShader(nullptr),
                                 cachedFragmentShader(nullptr) {}
        virtual ~GfxShaderCombination() {}

        virtual ResPtr<GfxShader> getVertexShader() const=0;

        virtual ResPtr<GfxShader> getTessControlShader() const
        {
            return nullptr;
        }

        virtual ResPtr<GfxShader> getTessEvalShader() const
        {
            return nullptr;
        }

        virtual ResPtr<GfxShader> getGeometryShader() const
        {
            return nullptr;
        }

        virtual ResPtr<GfxShader> getFragmentShader() const=0;

        virtual bool vertexDefinesDirty() const {return false;}
        virtual void getVertexDefines(HashMap<String, String >& defines) const {}

        virtual bool tessControlDefinesDirty() const {return false;}
        virtual void getTessControlDefines(HashMap<String, String >& defines) const {}

        virtual bool tessEvalDefinesDirty() const {return false;}
        virtual void getTessEvalDefines(HashMap<String, String >& defines) const {}

        virtual bool geometryDefinesDirty() const {return false;}
        virtual void getGeometryDefines(HashMap<String, String >& defines) const {}

        virtual bool fragmentDefinesDirty() const {return false;}
        virtual void getFragmentDefines(HashMap<String, String >& defines) const {}

        GfxCompiledShader *getCompiledVertexShader() const;
        GfxCompiledShader *getCompiledTessControlShader() const;
        GfxCompiledShader *getCompiledTessEvalShader() const;
        GfxCompiledShader *getCompiledGeometryShader() const;
        GfxCompiledShader *getCompiledFragmentShader() const;
    private:
        mutable GfxCompiledShader *cachedVertexShader;
        mutable GfxCompiledShader *cachedTessControlShader;
        mutable GfxCompiledShader *cachedTessEvalShader;
        mutable GfxCompiledShader *cachedGeometryShader;
        mutable GfxCompiledShader *cachedFragmentShader;

    NO_COPY(GfxShaderCombination)
};

#endif // GFXSHADER_H

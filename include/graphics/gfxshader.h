#ifndef GFXSHADER_H
#define GFXSHADER_H

#include "misc_macros.h"
#include "containers/string.h"
#include "containers/hashmap.h"
#include "graphics/GL/glfl.h"
#include "resource/resource.h"
#include "error.h"
#include "scripting/bindings.h"

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

class GfxCompiledShader;

enum class GfxShaderType
{
    Vertex,
    TessControl,
    TessEval,
    Geometry,
    Fragment,
    Compute
} BIND ENUM_CLASS;

class GfxShader : public Resource
{
    NO_COPY_INHERITED(GfxShader, Resource)

    public:
        static const ResType resource_type = ResType::GfxShaderType;

        GfxShader(const String& filename);
        GfxShader();
        ~GfxShader();

        virtual void removeContent();

        virtual void save();

        void compile(GfxShaderType type, const String& source);

        inline const String& getSource() const
        {
            return source;
        }

        inline GfxShaderType getShaderType() const
        {
            return shaderType;
        }

        GfxCompiledShader *getCompiled(const HashMap<String, String>& defines=HashMap<String, String>()) const;

        virtual void possiblyReload();
    private:
        virtual void _load();
        virtual Resource *_copy() const;
        GLuint _compile(GLuint program, const HashMap<String, String >& defines) const;

        GfxShaderType shaderType;
        mutable HashMap<HashMap<String, String>, GfxCompiledShader *> compiled;
        String source;
} DESTROY(obj->release()) BIND;

class GfxCompiledShader
{
    friend GfxShader;

    public:
        inline GfxShader *getShader() const
        {
            return shader;
        }

        inline GLuint getGLProgram() const
        {
            return program;
        }

        inline GLuint getGLShader() const
        {
            return glShader;
        }
    protected:
        GfxCompiledShader(GfxShader *shader_,
                          GLuint program_,
                          GLuint glShader_) : shader(shader_),
                                              program(program_),
                                              glShader(glShader_) {}
    private:
        GfxShader *shader;
        GLuint program;
        GLuint glShader;
} BIND;

class GfxShaderCombination
{
    public:
        GfxShaderCombination(GfxShader *vertex_,
                             GfxShader *fragment_) : vertex(vertex_),
                                                     tessControl(nullptr),
                                                     tessEval(nullptr),
                                                     geometry(nullptr),
                                                     fragment(fragment_),
                                                     compiledVertex(vertex_->getCompiled()),
                                                     compiledTessControl(nullptr),
                                                     compiledTessEval(nullptr),
                                                     compiledGeometry(nullptr),
                                                     compiledFragment(fragment_->getCompiled()) {}

        inline GfxShader *getVertexShader() const
        {
            return vertex;
        }

        inline GfxShader *getTessControlShader() const
        {
            return tessControl;
        }

        inline GfxShader *getTessEvalShader() const
        {
            return tessEval;
        }

        inline GfxShader *getGeometryShader() const
        {
            return geometry;
        }

        inline GfxShader *getFragmentShader() const
        {
            return fragment;
        }

        inline void setVertexShader(GfxShader *shader)
        {
            vertex = shader;
            compileVertex();
        }

        inline void setTessControlShader(GfxShader *shader)
        {
            tessControl = shader;
            compileTessControl();
        }

        inline void setTessEvalShader(GfxShader *shader)
        {
            tessEval = shader;
            compileTessEval();
        }

        inline void setGeometryShader(GfxShader *shader)
        {
            geometry = shader;
            compileGeometry();
        }

        inline void setFragmentShader(GfxShader *shader)
        {
            fragment = shader;
            compileFragment();
        }

        inline void setVertexDefine(const char *name, const char *value)
        {
            vertexDefines.set(name, value);
            compileVertex();
        }

        inline void setTessControlDefine(const char *name, const char *value)
        {
            tessControlDefines.set(name, value);
            compileTessControl();
        }

        inline void setTessEvalDefine(const char *name, const char *value)
        {
            tessEvalDefines.set(name, value);
            compileTessEval();
        }

        inline void setGeometryDefine(const char *name, const char *value)
        {
            geometryDefines.set(name, value);
            compileGeometry();
        }

        inline void setFragmentDefine(const char *name, const char *value)
        {
            fragmentDefines.set(name, value);
            compileFragment();
        }

        inline const String& getVertexDefine(const String& name)
        {
            return vertexDefines.get(name);
        }

        inline const String& getTessControlDefine(const String& name)
        {
            return tessControlDefines.get(name);
        }

        inline const String& getTessEvalDefine(const String& name)
        {
            return tessEvalDefines.get(name);
        }

        inline const String& getGeometryDefine(const String& name)
        {
            return geometryDefines.get(name);
        }

        inline const String& getFragmentDefine(const String& name)
        {
            return fragmentDefines.get(name);
        }

        inline void removeVertexDefine(const String& name)
        {
            vertexDefines.remove(name);
            compileVertex();
        }

        inline void removeTessControlDefine(const String& name)
        {
            tessControlDefines.remove(name);
            compileTessControl();
        }

        inline void removeTessEvalDefine(const String& name)
        {
            tessEvalDefines.remove(name);
            compileTessEval();
        }

        inline void removeGeometryDefine(const String& name)
        {
            geometryDefines.remove(name);
            compileGeometry();
        }

        inline void removeFragmentDefine(const String& name)
        {
            fragmentDefines.remove(name);
            compileFragment();
        }

        inline GfxCompiledShader *getCompiledVertexShader() const
        {
            return compiledVertex;
        }

        inline GfxCompiledShader *getCompiledTessControlShader() const
        {
            return compiledTessControl;
        }

        inline GfxCompiledShader *getCompiledTessEvalShader() const
        {
            return compiledTessEval;
        }

        inline GfxCompiledShader *getCompiledGeometryShader() const
        {
            return compiledGeometry;
        }

        inline GfxCompiledShader *getCompiledFragmentShader() const
        {
            return compiledFragment;
        }
    private:
        inline void compileVertex()
        {
            if (vertex != nullptr)
            {
                compiledVertex = vertex->getCompiled(vertexDefines);
            }
        }

        inline void compileTessControl()
        {
            if (tessControl != nullptr)
            {
                compiledTessControl = tessControl->getCompiled(tessControlDefines);
            }
        }

        inline void compileTessEval()
        {
            if (tessEval != nullptr)
            {
                compiledTessEval = tessEval->getCompiled(tessEvalDefines);
            }
        }

        inline void compileGeometry()
        {
            if (geometry != nullptr)
            {
                compiledGeometry = geometry->getCompiled(geometryDefines);
            }
        }

        inline void compileFragment()
        {
            if (fragment != nullptr)
            {
                compiledFragment = fragment->getCompiled(fragmentDefines);
            }
        }

        HashMap<String, String> vertexDefines;
        HashMap<String, String> tessControlDefines;
        HashMap<String, String> tessEvalDefines;
        HashMap<String, String> geometryDefines;
        HashMap<String, String> fragmentDefines;

        GfxShader *vertex;
        GfxShader *tessControl;
        GfxShader *tessEval;
        GfxShader *geometry;
        GfxShader *fragment;

        GfxCompiledShader *compiledVertex;
        GfxCompiledShader *compiledTessControl;
        GfxCompiledShader *compiledTessEval;
        GfxCompiledShader *compiledGeometry;
        GfxCompiledShader *compiledFragment;

    NO_COPY(GfxShaderCombination)
} NOT_COPYABLE BIND;

#endif // GFXSHADER_H

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
        GfxShaderCombination(GfxShader *vertex,
                             GfxShader *fragment);

        void setDefine(GfxShaderType shader, const String& name, const String& content);
        const String& getDefine(GfxShaderType shader, const String& name);
        void removeDefine(GfxShaderType shader, const String& name);

        GfxShader *getShader(GfxShaderType type);
        void setShader(GfxShaderType type, GfxShader *shader);

        GfxCompiledShader *getCompiled(GfxShaderType type) const;
    private:
        void compile(size_t index) const;

        HashMap<String, String> defines[5];
        GfxShader *shaders[5];
        mutable GfxCompiledShader *compiled[5];
        mutable bool dirty[5];

    NO_COPY(GfxShaderCombination)
} NOT_COPYABLE BIND;

#endif // GFXSHADER_H

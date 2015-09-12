#ifndef GFXGLSHADERIMPL_H
#define GFXGLSHADERIMPL_H

#include "misc_macros.h"
#include "containers/string.h"
#include "containers/hashmap.h"
#include "graphics/GL/glfl.h"
#include "resource/resource.h"
#include "graphics/gfxshader.h"

class GfxGLApi;
class GfxGLShaderImpl;

class GfxGLCompiledShader : public GfxCompiledShader
{
    NO_COPY_INHERITED(GfxGLCompiledShader, GfxCompiledShader)

    friend class GfxGLShaderImpl;

    public:
        virtual ~GfxGLCompiledShader() {}

        /**
        This is a shader if GL_ARB_seperate_shader_objects is not supported.
        **/
        inline GLuint getGLProgram() const
        {
            return program;
        }

        virtual bool isInvalid() const
        {
            return program == 0;
        }
    private:
        GfxGLCompiledShader(GfxShaderType type, GLuint program_) : GfxCompiledShader(type), program(program_) {}

        GLuint program;
};

class GfxGLShaderImpl : public GfxShaderImpl
{
    NO_COPY(GfxGLShaderImpl)

    public:
        GfxGLShaderImpl();
        virtual ~GfxGLShaderImpl();

        virtual void setSource(GfxShaderType type, const String& source);
        virtual String getSource() const;

        virtual GfxCompiledShader *getCompiled(const HashMap<String, String >& defines=
                                               HashMap<String, String >()) const;

        virtual void recompile();

        virtual GfxShaderType getType() const
        {
            return type;
        }

        GLuint _compile(GLenum type, GLsizei count, const char **strings, String& infoLog) const;
        void _compile();
        GLuint _compile(const HashMap<String, String >& defines) const;
    private:
        GfxShaderType type;

        String source;

        mutable HashMap<HashMap<String, String >, GfxGLCompiledShader *> compiledShaders;
};

#endif // GFXGLSHADERIMPL_H

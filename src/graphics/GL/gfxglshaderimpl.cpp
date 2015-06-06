#include "graphics/GL/gfxglshaderimpl.h"

#include <iostream>

GfxGLShaderImpl::GfxGLShaderImpl() : stage(GfxShader::Vertex) {}

GfxGLShaderImpl::~GfxGLShaderImpl()
{
    for (size_t i = 0; i < compiledShaders.getEntryCount(); ++i)
    {
        glDeleteProgram(compiledShaders.getValue(i)->getGLProgram());

        DELETE(CompiledShader, compiledShaders.getValue(i));
    }
}

GLuint GfxGLShaderImpl::_compile(GLenum type, GLsizei count, const char **strings, String& infoLog) const
{
    GLuint shader = glCreateShader(type);

    glShaderSource(shader, count, strings, nullptr);

    glCompileShader(shader);

    GLuint program = glCreateProgram();

    GLint compiled;

    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

    glProgramParameteri(program, GL_PROGRAM_SEPARABLE, GL_TRUE);

    if (compiled)
    {
        glAttachShader(program, shader);
        glLinkProgram(program);
        glDetachShader(program, shader);
    } else
    {
        GLint length;

        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

        infoLog.resize(length);

        glGetShaderInfoLog(shader, length, nullptr, infoLog.getData());
    }

    glDeleteShader(shader);

    return program;
}

void GfxGLShaderImpl::_compile()
{
    for (size_t i = 0; i < compiledShaders.getEntryCount(); ++i)
    {
        try
        {
            GfxGLCompiledShader *compiled = compiledShaders.getValue(i);

            GLuint oldProgram = compiled->program;

            compiled->program = _compile(compiledShaders.getKey(i));

            if (oldProgram != 0)
            {
                glDeleteProgram(oldProgram);
            }
        } catch (ShaderCompileException& e)
        {
            throw e;
        }
    }
}

void GfxGLShaderImpl::recompile()
{
    _compile();
}

GfxCompiledShader *GfxGLShaderImpl::getCompiled(const HashMap<String, String >& defines) const
{
    int entry = compiledShaders.findEntry(defines);

    if (entry == -1)
    {
        GfxGLCompiledShader *shader = NEW(GfxGLCompiledShader, _compile(defines));

        compiledShaders.set(defines, shader);

        return shader;
    }

    return compiledShaders.getValue(entry);
}

GLuint GfxGLShaderImpl::_compile(const HashMap<String, String >& defines) const
{
    GLsizei numSources = defines.getEntryCount() + 4;
    const char **sources = NEW_ARRAY(const char *, numSources);
    String *defineSources = NEW_ARRAY(String, defines.getEntryCount());

    sources[0] = "#version 430 core\n";

    for (size_t i = 0; i < defines.getEntryCount(); ++i)
    {
        defineSources[i] = String::format("#define %s %s\n",
                                          defines.getKey(i).getData(),
                                          defines.getValue(i).getData());
        sources[i+1] = defineSources[i].getData();
    }

    switch (stage)
    {
    case GfxShader::Vertex:
    {
        sources[defines.getEntryCount()+1] = "#define __VERTEX__ 1\n";
        break;
    }
    case GfxShader::TessControl:
    {
        sources[defines.getEntryCount()+1] = "#define __TESS_CONTROL__ 1\n";
        break;
    }
    case GfxShader::TessEval:
    {
        sources[defines.getEntryCount()+1] = "#define __TESS_EVAL__ 1\n";
        break;
    }
    case GfxShader::Geometry:
    {
        sources[defines.getEntryCount()+1] = "#define __GEOMETRY__ 1\n";
        break;
    }
    case GfxShader::Fragment:
    {
        sources[defines.getEntryCount()+1] = "#define __FRAGMENT__ 1\n";
        break;
    }
    case GfxShader::Compute:
    {
        sources[defines.getEntryCount()+1] = "#define __COMPUTE__ 1\n";
        break;
    }
    }

    sources[defines.getEntryCount()+2] = "#line 1\n";

    sources[defines.getEntryCount()+3] = source.getData();

    GLuint result = 0;
    String infoLog;

    switch (stage)
    {
    case GfxShader::Vertex:
    {
        result = _compile(GL_VERTEX_SHADER, numSources, sources, infoLog);
        break;
    }
    case GfxShader::TessControl:
    {
        result = _compile(GL_TESS_CONTROL_SHADER, numSources, sources, infoLog);
        break;
    }
    case GfxShader::TessEval:
    {
        result = _compile(GL_TESS_EVALUATION_SHADER, numSources, sources, infoLog);
        break;
    }
    case GfxShader::Geometry:
    {
        result = _compile(GL_GEOMETRY_SHADER, numSources, sources, infoLog);
        break;
    }
    case GfxShader::Fragment:
    {
        result = _compile(GL_FRAGMENT_SHADER, numSources, sources, infoLog);
        break;
    }
    case GfxShader::Compute:
    {
        result = _compile(GL_COMPUTE_SHADER, numSources, sources, infoLog);
        break;
    }
    }

    DELETE_ARRAY(const char *, defineSources);
    DELETE_ARRAY(String, sources);

    if (infoLog.getLength() != 0)
    {
        THROW(ShaderCompileException, infoLog);
    }

    return result;
}

void GfxGLShaderImpl::setSource(GfxShader::Stage stage_, const String& source_)
{
    stage = stage_;
    source = source_;

    recompile();
}

String GfxGLShaderImpl::getSource() const
{
    return source;
}

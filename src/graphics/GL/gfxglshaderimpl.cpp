#include "graphics/GL/gfxglshaderimpl.h"

#include "graphics/GL/gfxglapi.h"
#include "globals.h"

GfxGLShaderImpl::GfxGLShaderImpl() : stage(GfxShader::Vertex) {}

GfxGLShaderImpl::~GfxGLShaderImpl()
{
    for (size_t i = 0; i < compiledShaders.getEntryCount(); ++i)
    {
        if (GLFL_GL_ARB_separate_shader_objects)
        {
            glDeleteProgram(compiledShaders.getValue(i)->getGLProgram());
        } else
        {
            glDeleteShader(compiledShaders.getValue(i)->getGLProgram());
        }

        DELETE(CompiledShader, compiledShaders.getValue(i));
    }
}

GLuint GfxGLShaderImpl::_compile(GLenum type, GLsizei count, const char **strings, String& infoLog) const
{
    GLuint shader = glCreateShader(type);

    glShaderSource(shader, count, strings, nullptr);

    glCompileShader(shader);

    if (GLFL_GL_ARB_separate_shader_objects)
    {
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

        GLint linked;

        glGetProgramiv(program, GL_LINK_STATUS, &linked);

        if (not linked and compiled)
        {
            GLint length;

            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);

            infoLog.resize(length);

            glGetProgramInfoLog(program, length, nullptr, infoLog.getData());
        }

        return program;
    } else
    {
        GLint compiled;

        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

        if (not compiled)
        {
            GLint length;

            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

            infoLog.resize(length);

            glGetShaderInfoLog(shader, length, nullptr, infoLog.getData());
        }

        return shader;
    }
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
                if (GLFL_GL_ARB_separate_shader_objects)
                {
                    glDeleteProgram(oldProgram);
                } else
                {
                    glDeleteShader(oldProgram);
                }
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
        GfxGLCompiledShader *shader = NEW(GfxGLCompiledShader, stage, _compile(defines));

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

    unsigned int major = ((GfxGLApi *)gfxApi)->getOpenGLMajorVersion();
    unsigned int minor = ((GfxGLApi *)gfxApi)->getOpenGLMinorVersion();

    if (major == 3 and minor == 3)
    {
        sources[0] = "#version 330 core\n#extension GL_ARB_separate_shader_objects : enable\n";
    } else if (major == 4 and minor == 0)
    {
        sources[0] = "#version 400 core\n#extension GL_ARB_separate_shader_objects : enable\n";
    } else if (major == 4 and minor == 1)
    {
        sources[0] = "#version 410 core\n#extension GL_ARB_separate_shader_objects : enable\n";
    } else if (major == 4 and minor == 2)
    {
        sources[0] = "#version 420 core\n#extension GL_ARB_separate_shader_objects : enable\n";
    } else if (major == 4 and minor == 3)
    {
        sources[0] = "#version 430 core\n#extension GL_ARB_separate_shader_objects : enable\n";
    } else if (major == 4 and minor == 4)
    {
        sources[0] = "#version 440 core\n#extension GL_ARB_separate_shader_objects : enable\n";
    } else if (major == 4 and minor == 5)
    {
        sources[0] = "#version 450 core\n#extension GL_ARB_separate_shader_objects : enable\n";
    }

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
        sources[defines.getEntryCount()+1] = "#define VERTEX 1\n";
        break;
    }
    case GfxShader::TessControl:
    {
        sources[defines.getEntryCount()+1] = "#define TESS_CONTROL 1\n";
        break;
    }
    case GfxShader::TessEval:
    {
        sources[defines.getEntryCount()+1] = "#define TESS_EVAL 1\n";
        break;
    }
    case GfxShader::Geometry:
    {
        sources[defines.getEntryCount()+1] = "#define GEOMETRY 1\n";
        break;
    }
    case GfxShader::Fragment:
    {
        sources[defines.getEntryCount()+1] = "#define FRAGMENT 1\n";
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

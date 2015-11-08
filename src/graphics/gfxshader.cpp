#include "graphics/gfxshader.h"

#include "file.h"
#include "error.h"
#include "filesystem.h"
#include "globals.h"
#include "graphics/GL/gfxglapi.h"

#include <unistd.h>

GfxShader::GfxShader(const Str& filename_) : Resource(filename_,
                                                      ResType::GfxShaderType),
                                               shaderType(GfxShaderType::Vertex) {}

GfxShader::GfxShader() : Resource(ResType::GfxShaderType),
                         shaderType(GfxShaderType::Vertex) {}

GfxShader::~GfxShader()
{
    for (auto kv : compiled)
    {
        GfxCompiledShader *shader = kv.second;

        glDeleteProgram(shader->getGLProgram());
        glDeleteShader(shader->getGLShader());
        DELETE(shader);
    }
}

void GfxShader::removeContent()
{
    for (auto kv : compiled)
    {
        GfxCompiledShader *shader = kv.second;

        glDeleteProgram(shader->getGLProgram());
        glDeleteShader(shader->getGLShader());
        DELETE(shader);
    }

    compiled.clear();

    shaderType = GfxShaderType::Vertex;
}

void GfxShader::save()
{
    File file(getFilename().getData(), "wb");

    file.write(6, "shdr\x01\x00");

    switch (getShaderType())
    {
    case GfxShaderType::Vertex:
    {
        file.writeUInt8(0);
        break;
    }
    case GfxShaderType::TessControl:
    {
        file.writeUInt8(1);
        break;
    }
    case GfxShaderType::TessEval:
    {
        file.writeUInt8(2);
        break;
    }
    case GfxShaderType::Geometry:
    {
        file.writeUInt8(3);
        break;
    }
    case GfxShaderType::Fragment:
    {
        file.writeUInt8(4);
        break;
    }
    case GfxShaderType::Compute:
    {
        file.writeUInt8(5);
        break;
    }
    }

    file.write(source.getLength(), source.getData());
}

void GfxShader::_load()
{
    try
    {
        File file(getFilename().getData(), "rb");

        char magic[4];

        file.read(4, magic);

        if (magic[0] != 's' or
            magic[1] != 'h' or
            magic[2] != 'd' or
            magic[3] != 'r')
        {
            THROW(ResourceIOException, "shader", getFilename(), "Invalid magic.");
        }

        uint8_t majorVer = file.readUInt8();
        uint8_t minorVer = file.readUInt8();

        if (majorVer != 1 or minorVer != 0)
        {
            THROW(ResourceIOException, "shader", getFilename(), "Unsupported version.");
        }

        GfxShaderType type = GfxShaderType::Vertex;

        switch (file.readUInt8())
        {
        case 0:
        {
            type = GfxShaderType::Vertex;
            break;
        }
        case 1:
        {
            type = GfxShaderType::TessControl;
            break;
        }
        case 2:
        {
            type = GfxShaderType::TessEval;
            break;
        }
        case 3:
        {
            type = GfxShaderType::Geometry;
            break;
        }
        case 4:
        {
            type = GfxShaderType::Fragment;
            break;
        }
        case 5:
        {
            type = GfxShaderType::Compute;
            break;
        }
        default:
        {
            THROW(ResourceIOException, "shader", getFilename(), "Invalid shader type.");
            break;
        }
        }

        char source[file.getSize()-7];
        file.read(file.getSize()-7, source);

        try
        {
            compile(type, Str(file.getSize()-7, source));
        } catch (ShaderCompileException& e)
        {
            THROW(ResourceIOException,
                  "shader",
                  getFilename(),
                  Str::format("Unable to compile shader: %s", e.getString()));
        }
    } catch (const FileException& e)
    {
        THROW(ResourceIOException,
              "shader",
              getFilename(),
              e.getString());
    }
}

GLuint _compile(GLuint program, GLenum type, GLsizei count, const char **strings, Str& infoLog)
{
    GLuint shader = glCreateShader(type);

    glShaderSource(shader, count, strings, nullptr);
    glCompileShader(shader);

    GLint compiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

    if (compiled)
    {
        glAttachShader(program, shader);
        glLinkProgram(program);
    } else
    {
        GLint length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

        char log[length];
        glGetShaderInfoLog(shader, length, nullptr, log);
        infoLog = Str(length, log);

        glDeleteShader(shader);

        return 0;
    }

    GLint linked;
    glGetProgramiv(program, GL_LINK_STATUS, &linked);

    if (not linked and compiled)
    {
        GLint length;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);

        char log[length];
        glGetProgramInfoLog(shader, length, nullptr, log);
        infoLog = Str(length, log);

        glDeleteShader(shader);

        return 0;
    }

    return shader;
}

void GfxShader::compile(GfxShaderType type, const Str& source_)
{
    shaderType = type;
    source = source_;

    for (auto kv : compiled)
    {
        GfxCompiledShader *shader = kv.second;

        glDetachShader(shader->program, shader->glShader);

        shader->glShader = _compile(shader->program, kv.first);
    }
}

GfxCompiledShader *GfxShader::getCompiled(const HashMap<Str, Str>& defines) const
{
    auto pos = compiled.find(defines);

    if (pos == compiled.end())
    {
        GLuint program = glCreateProgram();
        glProgramParameteri(program, GL_PROGRAM_SEPARABLE, GL_TRUE);

        GfxCompiledShader *shader = NEW(GfxCompiledShader, const_cast<GfxShader *>(this), program, _compile(program, defines));

        compiled.set(defines, shader);

        return shader;
    }

    return pos->second;
}

GLuint GfxShader::_compile(GLuint program, const HashMap<Str, Str >& defines) const
{
    size_t defineCount = defines.getCount();

    GLsizei numSources = defineCount + 4;
    const char *sources[numSources];
    Str defineSources[defineCount];

    unsigned int major = ((GfxGLApi *)gfxApi)->getOpenGLMajorVersion();
    unsigned int minor = ((GfxGLApi *)gfxApi)->getOpenGLMinorVersion();

    if (major == 3 and minor == 3)
    {
        sources[0] = "#version 330 core\n";
    } else if (major == 4 and minor == 0)
    {
        sources[0] = "#version 400 core\n";
    } else if (major == 4 and minor == 1)
    {
        sources[0] = "#version 410 core\n";
    } else if (major == 4 and minor == 2)
    {
        sources[0] = "#version 420 core\n";
    } else if (major == 4 and minor == 3)
    {
        sources[0] = "#version 430 core\n";
    } else if (major == 4 and minor == 4)
    {
        sources[0] = "#version 440 core\n";
    } else if (major == 4 and minor == 5)
    {
        sources[0] = "#version 450 core\n";
    }

    sources[1] = "#extension GL_ARB_gpu_shader5 : enable\n"
"#pragma optionNV(fastmath on)\n"
"#pragma optionNV(fastprecision on)\n"
"#pragma optionNV(ifcvt none)\n"
"#pragma optionNV(inline all)\n"
"#pragma optionNV(strict on)\n"
"#pragma optionNV(unroll all)\n"
"#if GL_ARB_gpu_shader5 || (__VERSION__ >= 400)\n"
"#else\n"
"#define fma(a, b, c) ((a) * (b) + (c))\n"
"#endif\n";

    size_t i = 0;
    for (auto kv : defines)
    {
        defineSources[i] = Str::format("#define %s %s\n",
                                          kv.first.getData(),
                                          kv.second.getData());
        sources[i+2] = defineSources[i].getData();
        ++i;
    }

    sources[defineCount+2] = "#line 1\n";

    sources[defineCount+3] = source.getData();

    GLuint result = 0;
    Str infoLog;

    switch (shaderType)
    {
    case GfxShaderType::Vertex:
    {
        result = ::_compile(program, GL_VERTEX_SHADER, numSources, sources, infoLog);
        break;
    }
    case GfxShaderType::TessControl:
    {
        result = ::_compile(program, GL_TESS_CONTROL_SHADER, numSources, sources, infoLog);
        break;
    }
    case GfxShaderType::TessEval:
    {
        result = ::_compile(program, GL_TESS_EVALUATION_SHADER, numSources, sources, infoLog);
        break;
    }
    case GfxShaderType::Geometry:
    {
        result = ::_compile(program, GL_GEOMETRY_SHADER, numSources, sources, infoLog);
        break;
    }
    case GfxShaderType::Fragment:
    {
        result = ::_compile(program, GL_FRAGMENT_SHADER, numSources, sources, infoLog);
        break;
    }
    case GfxShaderType::Compute:
    {
        result = ::_compile(program, GL_COMPUTE_SHADER, numSources, sources, infoLog);
        break;
    }
    }

    if (infoLog.getLength() != 0)
    {
        THROW(ShaderCompileException, Str::format("Filename: %s\n%s", getFilename().getData(), infoLog.getData()));
    }

    return result;
}

Resource *GfxShader::_copy() const
{
    GfxShader *shader = NEW(GfxShader);

    shader->compile(shaderType, source);

    return (Resource *)shader;
}

GfxShaderCombination::GfxShaderCombination(GfxShader *vertex,
                                           GfxShader *fragment)
 : shaders{nullptr, nullptr, nullptr, nullptr, nullptr},
   compiled{nullptr, nullptr, nullptr, nullptr, nullptr},
   dirty{true, true, true, true, true}
{
    setShader(GfxShaderType::Vertex, vertex),
    setShader(GfxShaderType::Fragment, fragment);

    glGenProgramPipelines(1, &pipeline);
}

GfxShaderCombination::~GfxShaderCombination()
{
    glDeleteProgramPipelines(1, &pipeline);

    if (shaders[0] != nullptr)
    {
        shaders[0]->release();
    }

    if (shaders[1] != nullptr)
    {
        shaders[1]->release();
    }

    if (shaders[2] != nullptr)
    {
        shaders[2]->release();
    }

    if (shaders[3] != nullptr)
    {
        shaders[3]->release();
    }

    if (shaders[4] != nullptr)
    {
        shaders[4]->release();
    }
}

void GfxShaderCombination::setDefine(GfxShaderType shader, const Str& name, const Str& content)
{
    size_t index = (size_t)shader;

    if (index > 4)
    {
        THROW(BoundsException);
    }

    defines[index].set(name, content);
    dirty[index] = true;
}

const Str& GfxShaderCombination::getDefine(GfxShaderType shader, const Str& name) const
{
    size_t index = (size_t)shader;

    if (index > 4)
    {
        THROW(BoundsException);
    }

    return defines[index].get(name);
}

void GfxShaderCombination::removeDefine(GfxShaderType shader, const Str& name)
{
    size_t index = (size_t)shader;

    if (index > 4)
    {
        THROW(BoundsException);
    }

    dirty[index] = true;
    defines[index].remove(name);
}

GfxShader *GfxShaderCombination::getShader(GfxShaderType type) const
{
    size_t index = (size_t)type;

    if (index > 4)
    {
        THROW(BoundsException);
    }

    return shaders[index];
}

void GfxShaderCombination::setShader(GfxShaderType type, GfxShader *shader)
{
    size_t index = (size_t)type;

    if (index > 4)
    {
        THROW(BoundsException);
    }

    if (shaders[index] != nullptr)
    {
        shaders[index]->release();
    }

    shaders[index] = shader->copyRef<GfxShader>();
    dirty[index] = true;
}

GfxCompiledShader *GfxShaderCombination::getCompiled(GfxShaderType type) const
{
    size_t index = (size_t)type;

    if (index > 4)
    {
        THROW(BoundsException);
    }

    if (dirty[index])
    {
        compile(index);
    }

    return compiled[index];
}

static GLbitfield bits[] = {GL_VERTEX_SHADER_BIT,
                            GL_TESS_CONTROL_SHADER_BIT,
                            GL_TESS_EVALUATION_SHADER_BIT,
                            GL_GEOMETRY_SHADER_BIT,
                            GL_FRAGMENT_SHADER_BIT};

void GfxShaderCombination::compile(size_t index) const
{
    if (shaders[index] != nullptr)
    {
        compiled[index] = shaders[index]->getCompiled(defines[index]);

        glUseProgramStages(pipeline, bits[index], compiled[index]->getGLProgram());
    } else
    {
        compiled[index] = nullptr;
        dirty[index] = false;

        glUseProgramStages(pipeline, bits[index], 0);
    }
}

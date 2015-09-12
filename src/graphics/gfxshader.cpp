#include "graphics/gfxshader.h"

#include "file.h"
#include "error.h"
#include "filesystem.h"
#include "globals.h"
#include "graphics/GL/gfxglapi.h"

#include <unistd.h>

GfxShader::GfxShader(const String& filename) : Resource(filename,
                                                        ResType::GfxShaderType),
                                               shaderType(GfxShaderType::Vertex) {}

GfxShader::GfxShader() : Resource(ResType::GfxShaderType),
                         shaderType(GfxShaderType::Vertex) {}

GfxShader::~GfxShader()
{
    for (size_t i = 0; i < compiled.getEntryCount(); ++i)
    {
        GfxCompiledShader *shader = compiled.getValue(i);

        glDeleteProgram(shader->getGLProgram());
        glDeleteShader(shader->getGLShader());
        DELETE(shader);
    }
}

void GfxShader::removeContent()
{
    for (size_t i = 0; i < compiled.getEntryCount(); ++i)
    {
        GfxCompiledShader *shader = compiled.getValue(i);

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

        source = String(file.getSize()-7);

        file.read(source.getLength(), source.getData());

        try
        {
            compile(type, source);
        } catch (ShaderCompileException& e)
        {
            THROW(ResourceIOException,
                  "shader",
                  getFilename(),
                  String::format("Unable to compile shader: %s", e.getString()));
        }
    } catch (const FileException& e)
    {
        THROW(ResourceIOException,
              "shader",
              getFilename(),
              e.getString());
    }
}

void GfxShader::possiblyReload()
{
    if (shouldReload())
    {
        reload();
    }
}

GLuint _compile(GLuint program, GLenum type, GLsizei count, const char **strings, String& infoLog)
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

        infoLog.resize(length);
        glGetShaderInfoLog(shader, length, nullptr, infoLog.getData());

        glDeleteShader(shader);

        return 0;
    }

    GLint linked;
    glGetProgramiv(program, GL_LINK_STATUS, &linked);

    if (not linked and compiled)
    {
        GLint length;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);

        infoLog.resize(length);
        glGetProgramInfoLog(program, length, nullptr, infoLog.getData());

        glDeleteShader(shader);

        return 0;
    }

    return shader;
}

void GfxShader::compile(GfxShaderType type, const String& source_)
{
    shaderType = type;
    source = source_;

    for (size_t i = 0; i < compiled.getEntryCount(); ++i)
    {
        GfxCompiledShader *shader = compiled.getValue(i);

        glDetachShader(shader->program, shader->glShader);

        shader->glShader = _compile(shader->program, compiled.getKey(i));
    }
}

GfxCompiledShader *GfxShader::getCompiled(const HashMap<String, String>& defines) const
{
    int entry = compiled.findEntry(defines);

    if (entry == -1)
    {
        GLuint program = glCreateProgram();
        glProgramParameteri(program, GL_PROGRAM_SEPARABLE, GL_TRUE);

        GfxCompiledShader *shader = NEW(GfxCompiledShader, const_cast<GfxShader *>(this), program, _compile(program, defines));

        compiled.set(defines, shader);

        return shader;
    }

    return compiled.getValue(entry);
}

GLuint GfxShader::_compile(GLuint program, const HashMap<String, String >& defines) const
{
    GLsizei numSources = defines.getEntryCount() + 4;
    const char *sources[numSources];
    String defineSources[defines.getEntryCount()];

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

    for (size_t i = 0; i < defines.getEntryCount(); ++i)
    {
        defineSources[i] = String::format("#define %s %s\n",
                                          defines.getKey(i).getData(),
                                          defines.getValue(i).getData());
        sources[i+2] = defineSources[i].getData();
    }

    sources[defines.getEntryCount()+2] = "#line 1\n";

    sources[defines.getEntryCount()+3] = source.getData();

    if (source.getLength() < 10)
    {
        std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAA\n" << source.getData() << std::endl;
    }

    GLuint result = 0;
    String infoLog;

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
        THROW(ShaderCompileException, infoLog);
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
   compiled{nullptr, nullptr, nullptr, nullptr, nullptr}
{
    setShader(GfxShaderType::Vertex, vertex),
    setShader(GfxShaderType::Fragment, fragment);
}

void GfxShaderCombination::setDefine(GfxShaderType shader, const String& name, const String& content)
{
    size_t index = (size_t)shader;

    if (index > 4)
    {
        THROW(BoundsException);
    }

    defines[index].set(name, content);
    dirty[index] = true;
}

const String& GfxShaderCombination::getDefine(GfxShaderType shader, const String& name)
{
    size_t index = (size_t)shader;

    if (index > 4)
    {
        THROW(BoundsException);
    }

    return defines[index].get(name);
}

void GfxShaderCombination::removeDefine(GfxShaderType shader, const String& name)
{
    size_t index = (size_t)shader;

    if (index > 4)
    {
        THROW(BoundsException);
    }

    dirty[index] = true;
    defines[index].remove(name);
}

GfxShader *GfxShaderCombination::getShader(GfxShaderType type)
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

    shaders[index] = shader;
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

void GfxShaderCombination::compile(size_t index) const
{
    if (shaders[index] != nullptr)
    {
        compiled[index] = shaders[index]->getCompiled(defines[index]);
    } else
    {
        compiled[index] = nullptr;
    }
}

#include "graphics/gfxshader.h"

#include "file.h"
#include "error.h"
#include "filesystem.h"
#include "globals.h"
#include "graphics/gfxapi.h"

#include <unistd.h>

GfxShader::GfxShader(const String& filename) : Resource(filename,
                                                        GfxShaderType),
                                               impl(gfxApi->createShaderImpl()) {}

GfxShader::GfxShader() : Resource(GfxShaderType),
                         impl(gfxApi->createShaderImpl()) {}

GfxShader::~GfxShader()
{
    DELETE(GfxShaderImpl, impl);
}

void GfxShader::removeContent()
{
    DELETE(GfxShaderImpl, impl);
    impl = gfxApi->createShaderImpl();
}

void GfxShader::save()
{
    File file(getFilename().getData(), "wb");

    file.write(6, "shdr\x01\x00");

    switch (getStage())
    {
    case Vertex:
    {
        file.writeUInt8(0);
        break;
    }
    case TessControl:
    {
        file.writeUInt8(1);
        break;
    }
    case TessEval:
    {
        file.writeUInt8(2);
        break;
    }
    case Geometry:
    {
        file.writeUInt8(3);
        break;
    }
    case Fragment:
    {
        file.writeUInt8(4);
        break;
    }
    case Compute:
    {
        file.writeUInt8(5);
        break;
    }
    }

    const String source = getSource();

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

        Stage stage = GfxShader::Vertex;

        switch (file.readUInt8())
        {
        case 0:
        {
            stage = Vertex;
            break;
        }
        case 1:
        {
            stage = TessControl;
            break;
        }
        case 2:
        {
            stage = TessEval;
            break;
        }
        case 3:
        {
            stage = Geometry;
            break;
        }
        case 4:
        {
            stage = Fragment;
            break;
        }
        case 5:
        {
            stage = Compute;
            break;
        }
        default:
        {
            THROW(ResourceIOException, "shader", getFilename(), "Invalid stage.");
            break;
        }
        }

        String source(file.getSize()-7);

        file.read(source.getLength(), source.getData());

        try
        {
            setSource(stage, source);
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

void GfxShader::setSource(Stage stage, const String& source)
{
    impl->setSource(stage, source.copy());
}

const String GfxShader::getSource() const
{
    return impl->getSource();
}

GfxCompiledShader *GfxShader::_getCompiled(List<String> defineNames, List<String> defineValues) const
{
    HashMap<String, String> defines;

    for (size_t i = 0; i < defineNames.getCount(); ++i)
    {
        defines.set(defineNames[i], defineValues[i]);
    }

    return impl->getCompiled(defines);
}

void GfxShader::recompile()
{
    impl->recompile();
}

GfxShader::Stage GfxShader::getStage() const
{
    return impl->getStage();
}

Resource *GfxShader::_copy() const
{
    GfxShader *shader = NEW(GfxShader);

    shader->setSource(getStage(), getSource());

    return (Resource *)shader;
}

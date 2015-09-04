#include "graphics/gfxshader.h"

#include "file.h"
#include "error.h"
#include "filesystem.h"
#include "globals.h"
#include "graphics/gfxapi.h"

#include <unistd.h>

GfxShader::GfxShader(const String& filename) : Resource(filename,
                                                        ResType::GfxShaderType),
                                               impl(gfxApi->createShaderImpl()) {}

GfxShader::GfxShader() : Resource(ResType::GfxShaderType),
                         impl(gfxApi->createShaderImpl()) {}

GfxShader::~GfxShader()
{
    DELETE(impl);
}

void GfxShader::removeContent()
{
    DELETE(impl);
    impl = gfxApi->createShaderImpl();
}

void GfxShader::save()
{
    File file(getFilename().getData(), "wb");

    file.write(6, "shdr\x01\x00");

    switch (getStage())
    {
    case GfxStage::Vertex:
    {
        file.writeUInt8(0);
        break;
    }
    case GfxStage::TessControl:
    {
        file.writeUInt8(1);
        break;
    }
    case GfxStage::TessEval:
    {
        file.writeUInt8(2);
        break;
    }
    case GfxStage::Geometry:
    {
        file.writeUInt8(3);
        break;
    }
    case GfxStage::Fragment:
    {
        file.writeUInt8(4);
        break;
    }
    case GfxStage::Compute:
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

        GfxStage stage = GfxStage::Vertex;

        switch (file.readUInt8())
        {
        case 0:
        {
            stage = GfxStage::Vertex;
            break;
        }
        case 1:
        {
            stage = GfxStage::TessControl;
            break;
        }
        case 2:
        {
            stage = GfxStage::TessEval;
            break;
        }
        case 3:
        {
            stage = GfxStage::Geometry;
            break;
        }
        case 4:
        {
            stage = GfxStage::Fragment;
            break;
        }
        case 5:
        {
            stage = GfxStage::Compute;
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

void GfxShader::setSource(GfxStage stage, const String& source)
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

GfxStage GfxShader::getStage() const
{
    return impl->getStage();
}

Resource *GfxShader::_copy() const
{
    GfxShader *shader = NEW(GfxShader);

    shader->setSource(getStage(), getSource());

    return (Resource *)shader;
}

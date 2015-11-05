#include "graphics/gfxmaterial.h"

#include "globals.h"
#include "graphics/gfxapi.h"
#include "graphics/gfxrenderer.h"
#include "file.h"
#include "scripting/bindings2.h"

GfxMaterial::GfxMaterial() : Resource(ResType::GfxMaterialType), script(nullptr) {}

GfxMaterial::GfxMaterial(const Str& filename) : Resource(filename,
                                                            ResType::GfxMaterialType),
                                                script(nullptr) {}

GfxMaterial::~GfxMaterial()
{
    DELETE(script);
}

void GfxMaterial::removeContent()
{
    DELETE(script);
    script = nullptr;
}

void GfxMaterial::save()
{
    File file(getFilename().getData(), "wb");

    file.write(6, "mtrl\x02\x00");

    file.writeUInt32LE(script->getScript()->getFilename().getLength());
    file.writeStr(script->getScript()->getFilename());

    scripting::destroy(script->getScript()->getContext(),
                       script->method("save",
                                      scripting::create(script->getScript()->getContext(),
                                      &file)));
}

void GfxMaterial::_load()
{
    try
    {
        File file(getFilename().getData(), "rb");

        char magic[4];

        file.read(4, magic);

        if (magic[0] != 'm' or
            magic[1] != 't' or
            magic[2] != 'r' or
            magic[3] != 'l')
        {
            THROW(ResourceIOException, "material", getFilename(), "Invalid magic.");
        }

        uint8_t majorVer = file.readUInt8();
        uint8_t minorVer = file.readUInt8();

        if (majorVer != 2 or minorVer != 0)
        {
            THROW(ResourceIOException, "material", getFilename(), "Unsupported version.");
        }

        uint32_t length = file.readUInt32LE();
        Str scriptFile = file.readStr(length);

        Script *newScript = resMgr->load<Script>(scriptFile);
        setScript(newScript);
        newScript->release();

        scripting::destroy(script->getScript()->getContext(),
                           script->method("load",
                                          scripting::create(script->getScript()->getContext(),
                                                            &file)));
    } catch (FileException& e)
    {
        THROW(ResourceIOException,
              "material",
              getFilename(),
              e.getString());
    }
}

void GfxMaterial::setupRender(GfxMesh *mesh, GfxAnimationState *animState, const Camera& camera)
{
    scripting::Context *ctx = script->getScript()->getContext();

    scripting::destroy(ctx,
                       script->method("setupRender",
                       scripting::create(ctx, mesh),
                       scripting::create(ctx, animState),
                       scripting::create(ctx, camera)));
}

Resource *GfxMaterial::_copy() const
{
    GfxMaterial *material = NEW(GfxMaterial);

    material->setScript(script->getScript());

    scripting::Context *ctx = script->getScript()->getContext();

    scripting::destroy(ctx, material->getScriptInst()->method("copyFrom",
                                                              scripting::createCopy(script->getObj())));

    return (Resource *)material;
}

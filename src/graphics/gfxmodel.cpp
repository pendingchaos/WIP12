#include "graphics/gfxmodel.h"

#include "file.h"
#include "globals.h"

GfxModel::LOD::LOD(float minDistance_,
                   float maxDistance_,
                   ResPtr<GfxMesh> mesh_,
                   ResPtr<GfxMaterial> material_,
                   const Matrix4x4& matrix) : minDistance(minDistance_),
                                              maxDistance(maxDistance_),
                                              mesh(mesh_),
                                              material(material_),
                                              worldMatrix(matrix) {}

GfxModel::GfxModel() : Resource(Resource::GfxModelType) {}

GfxModel::GfxModel(const String& filename) : Resource(filename,
                                                      Resource::GfxModelType) {}

void GfxModel::removeContent()
{
    contexts = HashMap<ContextType, Context>();
}

void GfxModel::save()
{
    File file(filename.getData(), "wb");

    file.write(6, "modl\x01\x00");

    file.writeUInt32LE(contexts.getEntryCount());

    for (size_t i = 0; i < contexts.getEntryCount(); ++i)
    {
        file.writeUInt8((uint8_t)contexts.getKey(i));

        const Context& context = contexts.getValue(i);

        file.writeUInt32LE(context.getCount());

        for (size_t j = 0; j < context.getCount(); ++i)
        {
            const SubModel& subModel = context[i];

            file.writeUInt32LE(subModel.getCount());

            for (size_t j2 = 0; j2 < subModel.getCount(); ++j2)
            {
                const LOD& lod = subModel[j2];

                file.writeFloat32(lod.minDistance);
                file.writeFloat32(lod.maxDistance);

                file.writeFloat32(lod.worldMatrix[0][0]);
                file.writeFloat32(lod.worldMatrix[0][1]);
                file.writeFloat32(lod.worldMatrix[0][2]);
                file.writeFloat32(lod.worldMatrix[0][3]);
                file.writeFloat32(lod.worldMatrix[1][0]);
                file.writeFloat32(lod.worldMatrix[1][1]);
                file.writeFloat32(lod.worldMatrix[1][2]);
                file.writeFloat32(lod.worldMatrix[1][3]);
                file.writeFloat32(lod.worldMatrix[2][0]);
                file.writeFloat32(lod.worldMatrix[2][1]);
                file.writeFloat32(lod.worldMatrix[2][2]);
                file.writeFloat32(lod.worldMatrix[2][3]);
                file.writeFloat32(lod.worldMatrix[3][0]);
                file.writeFloat32(lod.worldMatrix[3][1]);
                file.writeFloat32(lod.worldMatrix[3][2]);
                file.writeFloat32(lod.worldMatrix[3][3]);

                const String& mesh = lod.mesh->filename;
                const String& material = lod.material->filename;

                if (mesh.getLength() == 0)
                {
                    THROW(ResourceIOException, "model", filename, "Model's mesh must have a filename.");
                }

                if (material.getLength() == 0)
                {
                    THROW(ResourceIOException, "model", filename, "Model's material must have a filename.");
                }

                file.writeUInt32LE(mesh.getLength());
                file.write(mesh.getLength(), mesh.getData());

                file.writeUInt32LE(material.getLength());
                file.write(material.getLength(), material.getData());
            }
        }
    }
}

void GfxModel::_load()
{
    try
    {
        removeContent();

        File file(filename.getData(), "rb");

        char magic[4];

        file.read(4, magic);

        if (magic[0] != 'm' or
            magic[1] != 'o' or
            magic[2] != 'd' or
            magic[3] != 'l')
        {
            THROW(ResourceIOException, "model", filename, "Invalid magic.");
        }

        uint8_t majorVer = file.readUInt8();
        uint8_t minorVer = file.readUInt8();

        if (majorVer != 1 or minorVer != 0)
        {
            THROW(ResourceIOException, "model", filename, "Unsupported version.");
        }

        uint32_t numContexts = file.readUInt32LE();

        for (uint32_t i = 0; i < numContexts; ++i)
        {
            ContextType contextType = (ContextType)file.readUInt8();

            Context context;

            uint32_t numSubModels = file.readUInt32LE();

            for (uint32_t j = 0; j < numSubModels; ++j)
            {
                SubModel subModel;

                uint32_t numLODs = file.readUInt32LE();

                for (uint32_t j2 = 0; j2 < numLODs; ++j2)
                {
                    float minDistance = file.readFloat32();
                    float maxDistance = file.readFloat32();

                    float r0c0 = file.readFloat32();
                    float r0c1 = file.readFloat32();
                    float r0c2 = file.readFloat32();
                    float r0c3 = file.readFloat32();
                    float r1c0 = file.readFloat32();
                    float r1c1 = file.readFloat32();
                    float r1c2 = file.readFloat32();
                    float r1c3 = file.readFloat32();
                    float r2c0 = file.readFloat32();
                    float r2c1 = file.readFloat32();
                    float r2c2 = file.readFloat32();
                    float r2c3 = file.readFloat32();
                    float r3c0 = file.readFloat32();
                    float r3c1 = file.readFloat32();
                    float r3c2 = file.readFloat32();
                    float r3c3 = file.readFloat32();

                    uint32_t meshLen = file.readUInt32LE();
                    String mesh(meshLen);
                    file.read(meshLen, mesh.getData());

                    uint32_t materialLen = file.readUInt32LE();
                    String material(materialLen);
                    file.read(materialLen, material.getData());

                    subModel.append(LOD(minDistance,
                                        maxDistance,
                                        resMgr->getResource<GfxMesh>(mesh),
                                        resMgr->getResource<GfxMaterial>(material),
                                        Matrix4x4(Float4(r0c0, r0c1, r0c2, r0c3),
                                                  Float4(r1c0, r1c1, r1c2, r1c3),
                                                  Float4(r2c0, r2c1, r2c2, r2c3),
                                                  Float4(r3c0, r3c1, r3c2, r3c3))));
                }

                context.append(subModel);
            }

            contexts.set(contextType, context);
        }
    } catch (FileException& e)
    {
        THROW(ResourceIOException,
              "model",
              filename,
              e.getString());
    }
}

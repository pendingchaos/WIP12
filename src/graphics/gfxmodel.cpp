#include "graphics/gfxmodel.h"

#include "file.h"
#include "globals.h"

GfxLOD::GfxLOD(float minDistance_,
              float maxDistance_,
              GfxMesh *mesh_,
              GfxMaterial *material_,
              const Matrix4x4& matrix) : minDistance(minDistance_),
                                         maxDistance(maxDistance_),
                                         mesh(mesh_),
                                         material(material_),
                                         worldMatrix(matrix) {}

GfxModel::GfxModel() : Resource(ResType::GfxModelType) {}

GfxModel::GfxModel(const String& filename) : Resource(filename,
                                                      ResType::GfxModelType) {}

GfxModel::~GfxModel()
{
    for (auto subModel : subModels)
    {
        for (auto lod : subModel)
        {
            lod.mesh->release();
            lod.material->release();
        }
    }
}

void GfxModel::removeContent()
{
    for (auto subModel : subModels)
    {
        for (auto lod : subModel)
        {
            lod.mesh->release();
            lod.material->release();
        }
    }

    subModels.clear();
}

void GfxModel::save()
{
    File file(getFilename().getData(), "wb");

    file.write(6, "modl\x01\x00");

    file.writeUInt32LE(subModels.getCount());

    for (auto subModel : subModels)
    {
        file.writeUInt32LE(subModel.getCount());

        for (auto lod : subModel)
        {
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

            const String& mesh = lod.mesh->getFilename();
            const String& material = lod.material->getFilename();

            if (mesh.getLength() == 0)
            {
                THROW(ResourceIOException, "model", getFilename(), "Model's mesh must have a filename.");
            }

            if (material.getLength() == 0)
            {
                THROW(ResourceIOException, "model", getFilename(), "Model's material must have a filename.");
            }

            file.writeUInt32LE(mesh.getLength());
            file.write(mesh.getLength(), mesh.getData());

            file.writeUInt32LE(material.getLength());
            file.write(material.getLength(), material.getData());
        }
    }
}

void GfxModel::_load()
{
    try
    {
        removeContent();

        File file(getFilename().getData(), "rb");

        char magic[4];

        file.read(4, magic);

        if (magic[0] != 'm' or
            magic[1] != 'o' or
            magic[2] != 'd' or
            magic[3] != 'l')
        {
            THROW(ResourceIOException, "model", getFilename(), "Invalid magic.");
        }

        uint8_t majorVer = file.readUInt8();
        uint8_t minorVer = file.readUInt8();

        if (majorVer != 1 or minorVer != 0)
        {
            THROW(ResourceIOException, "model", getFilename(), "Unsupported version.");
        }

        subModels.clear();

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
                String mesh((size_t)meshLen);
                file.read(meshLen, mesh.getData());

                uint32_t materialLen = file.readUInt32LE();
                String material((size_t)materialLen);
                file.read(materialLen, material.getData());

                subModel.append(GfxLOD(minDistance,
                                       maxDistance,
                                       resMgr->load<GfxMesh>(mesh),
                                       resMgr->load<GfxMaterial>(material),
                                       Matrix4x4(Float4(r0c0, r0c1, r0c2, r0c3),
                                                 Float4(r1c0, r1c1, r1c2, r1c3),
                                                 Float4(r2c0, r2c1, r2c2, r2c3),
                                                 Float4(r3c0, r3c1, r3c2, r3c3))));
            }

            subModels.append(subModel);
        }
    } catch (FileException& e)
    {
        THROW(ResourceIOException,
              "model",
              getFilename(),
              e.getString());
    }
}

Resource *GfxModel::_copy() const
{
    GfxModel *model = NEW(GfxModel);

    for (auto subModel : subModels)
    {
        SubModel newSubModel;

        for (auto lod : subModel)
        {
            newSubModel.append(GfxLOD(lod.minDistance,
                                      lod.maxDistance,
                                      lod.mesh->copyRef<GfxMesh>(),
                                      lod.material->copyRef<GfxMaterial>(),
                                      lod.worldMatrix));
        }

        model->subModels.append(newSubModel);
    }

    return (Resource *)model;
}

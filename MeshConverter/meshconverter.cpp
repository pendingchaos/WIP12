#include "../include/endian_utils.h"

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <stddef.h>
#include <stdint.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

void importError(const char *message)
{
    std::cerr << "Import error: " << message << '\n';
}

void importWarning(const char *message)
{
    std::cerr << "Import warning: " << message << '\n';
}

void writeUData(const char *filename, uint32_t size, void *data)
{
    FILE *file = std::fopen(filename, "wb");

    std::fwrite("udat", 4, 1, file); //magic
    std::putc(1, file); //major version
    std::putc(0, file); //minor version

    size = TO_LE_U32(size);
    std::fwrite(&size, 4, 1, file);
    size = FROM_LE_U32(size);

    std::fwrite(data, size, 1, file);

    std::fclose(file);
}

void writeVertexAttrib(FILE *file,
                       uint8_t purpose,
                       uint8_t numComponents,
                       uint8_t type,
                       uint32_t stride,
                       uint32_t offset)
{
    uint8_t data[] = {purpose, numComponents, type};
    uint32_t data2[] = {stride, offset};

    std::fwrite(data2, 8, 1, file);

    std::fwrite(data, 3, 1, file);
}

extern "C"
{
void convert(const char *input, const char *out)
{
    Assimp::Importer importer;

    const aiScene *scene = importer.ReadFile(input,   aiProcess_CalcTangentSpace
                                                    | aiProcess_JoinIdenticalVertices
                                                    | aiProcess_Triangulate
                                                    | aiProcess_GenSmoothNormals
                                                    | aiProcess_PreTransformVertices
                                                    | aiProcess_ValidateDataStructure
                                                    | aiProcess_ImproveCacheLocality
                                                    | aiProcess_FindInvalidData
                                                    | aiProcess_GenUVCoords
                                                    | aiProcess_FindInstances
                                                    | aiProcess_OptimizeMeshes
                                                    | aiProcess_OptimizeGraph);

    if (scene == NULL)
    {
        importError(importer.GetErrorString());
        return;
    }

    if (scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE)
    {
        importError(importer.GetErrorString());
        return;
    }

    if (scene->mNumMeshes == 0)
    {
        importError("No meshes in the file.");
        return;
    }

    if (scene->mNumMeshes > 1)
    {
        importWarning("There are multiple meshes in the file.\n"
                      "The first one is being used.");
    }

    aiMesh *mesh = scene->mMeshes[0];

    bool indexed = mesh->mNumVertices < 0xFFFFFFFFu;
    size_t indexSize = (mesh->mNumVertices < 0xFFu) ? 1 : (mesh->mNumVertices < 0xFFFFu) ? 2 : 4;

    FILE *output = std::fopen(out, "wb");

    std::fwrite("mesh\x01\x00", 6, 1, output);

    unsigned int count = indexed ? mesh->mNumFaces*3 : mesh->mNumVertices;

    std::fwrite(&count, 4, 1, output);

    std::fwrite("\x06\x01\x00", 3, 1, output); //primitive, winding, cull mode

    std::fwrite(indexed ? "\x01" : "\x00", 1, 1, output);

    float minX = 0.0f;
    float minY = 0.0f;
    float minZ = 0.0f;
    float maxX = 0.0f;
    float maxY = 0.0f;
    float maxZ = 0.0f;

    if (mesh->HasPositions())
    {
        for (size_t i = 0; i < mesh->mNumVertices; ++i)
        {
            aiVector3D position = mesh->mVertices[i];

            minX = std::min(minX, position.x);
            minY = std::min(minY, position.y);
            minZ = std::min(minZ, position.z);
            maxX = std::max(maxX, position.x);
            maxY = std::max(maxY, position.y);
            maxZ = std::max(maxZ, position.z);
        }
    }

    std::fwrite(&minX, 4, 1, output);
    std::fwrite(&minY, 4, 1, output);
    std::fwrite(&minZ, 4, 1, output);
    std::fwrite(&maxX, 4, 1, output);
    std::fwrite(&maxY, 4, 1, output);
    std::fwrite(&maxZ, 4, 1, output);

    uint32_t stride = 0;

    stride += mesh->HasPositions() ? 12 : 0;
    stride += mesh->HasNormals() ? 6 : 0;
    stride += mesh->HasTangentsAndBitangents() ? 6 : 0;
    stride += mesh->GetNumUVChannels() != 0 ? 4 : 0;
    stride += mesh->GetNumColorChannels() != 0 ? 3 : 0;

    uint32_t offset = 0;

    if (indexed)
    {
        static uint8_t arr[] = {0, 4, 6, 0, 8};
        std::fwrite(&arr[indexSize], 1, 1, output); //Type

        uint32_t indicesOffset = mesh->mNumVertices*stride;

        std::fwrite(&indicesOffset, 4, 1, output);
    }

    uint8_t numVertexAttribs = (mesh->HasPositions() != 0 ? 1 : 0) +
                               (mesh->HasNormals() != 0 ? 1 : 0) +
                               (mesh->HasTangentsAndBitangents() != 0 ? 1 : 0) +
                               (mesh->GetNumUVChannels() != 0 ? 1 : 0) +
                               (mesh->GetNumColorChannels() != 0 ? 1 : 0);

    std::fwrite(&numVertexAttribs, 1, 1, output);

    if (mesh->HasPositions())
    {
        writeVertexAttrib(output, 0, 3, 1, stride, offset);
        offset += 12;
    }

    if (mesh->HasNormals())
    {
        writeVertexAttrib(output, 1, 3, 11, stride, offset);
        offset += 6;
    }

    if (mesh->HasTangentsAndBitangents())
    {
        writeVertexAttrib(output, 2, 3, 11, stride, offset);
        offset += 6;
    }

    if (mesh->GetNumUVChannels() != 0)
    {
        writeVertexAttrib(output, 4, 2, 12, stride, offset);

        offset += 4;
    }

    if (mesh->GetNumColorChannels() != 0)
    {
        writeVertexAttrib(output, 5, 3, 10, stride, offset);
    }

    if (not indexed)
    {
        unsigned int numVertices = 0;

        for (unsigned int i = 0; i < mesh->mNumFaces; ++i)
        {
            numVertices += mesh->mFaces[i].mNumIndices;
        }

        char *data = (char *)std::malloc(stride * numVertices);

        unsigned di = 0;

        for (unsigned int i = 0; i < mesh->mNumFaces; ++i)
        {
            aiFace face = mesh->mFaces[i];

            for (unsigned int i2 = 0; i2 < face.mNumIndices; ++i2)
            {
                unsigned int si = face.mIndices[i2];

                offset = 0;

                if (mesh->HasPositions())
                {
                    std::memcpy(data+di*stride, &mesh->mVertices[si], 12);

                    offset += 12;
                }

                if (mesh->HasNormals())
                {
                    aiVector3D normal = mesh->mNormals[si];

                    struct
                    {
                        int16_t x;
                        int16_t y;
                        int16_t z;
                    } vert;

                    vert.x = normal.x * 32767.0f;
                    vert.y = normal.y * 32767.0f;
                    vert.z = normal.z * 32767.0f;

                    std::memcpy(data+di*stride+offset, &vert, 6);
                    offset += 6;
                }

                if (mesh->HasTangentsAndBitangents())
                {
                    aiVector3D tangent = mesh->mTangents[si];

                    struct
                    {
                        int16_t x;
                        int16_t y;
                        int16_t z;
                    } vert;

                    vert.x = tangent.x * 32767.0f;
                    vert.y = tangent.y * 32767.0f;
                    vert.z = tangent.z * 32767.0f;

                    std::memcpy(data+di*stride+offset, &vert, 6);
                    offset += 6;
                }

                if (mesh->GetNumUVChannels() != 0)
                {
                    const aiVector3D& texCoord = mesh->mTextureCoords[0][si];

                    struct {uint16_t u, v;} uv;

                    uv.u = static_cast<uint16_t>(texCoord.x * 65535.0f);
                    uv.v = static_cast<uint16_t>(texCoord.y * 65535.0f);

                    std::memcpy(data+di*stride+offset, &uv, 4);

                    offset += 4;
                }

                if (mesh->GetNumColorChannels() != 0)
                {
                    const aiColor4D& color = mesh->mColors[0][si];

                    struct {uint8_t r, g, b, a;} rgba;

                    rgba.r = color.r * 255;
                    rgba.g = color.g * 255;
                    rgba.b = color.b * 255;
                    rgba.a = color.a * 255;

                    std::memcpy(data+di*stride+offset, &rgba, 4);

                    offset += 4;
                }

                ++di;
            }
        }

        uint32_t size = stride * numVertices;

        std::fwrite(&size, 4, 1, output);
        std::fwrite(data, size, 1, output);

        std::free(data);
    } else
    {
        char *data = (char *)std::malloc(stride*mesh->mNumVertices + mesh->mNumFaces*indexSize*3);

        for (unsigned int i = 0; i < mesh->mNumVertices; ++i)
        {
            offset = 0;

            if (mesh->HasPositions())
            {
                std::memcpy(data+i*stride, &mesh->mVertices[i], 12);

                offset += 12;
            }

            if (mesh->HasNormals())
            {
                aiVector3D normal = mesh->mNormals[i];

                struct
                {
                    int16_t x;
                    int16_t y;
                    int16_t z;
                } vert;

                vert.x = normal.x * 32767.0f;
                vert.y = normal.y * 32767.0f;
                vert.z = normal.z * 32767.0f;

                std::memcpy(data+i*stride+offset, &vert, 6);
                offset += 6;
            }

            if (mesh->HasTangentsAndBitangents())
            {
                aiVector3D tangent = mesh->mTangents[i];

                struct
                {
                    int16_t x;
                    int16_t y;
                    int16_t z;
                } vert;

                vert.x = tangent.x * 32767.0f;
                vert.y = tangent.y * 32767.0f;
                vert.z = tangent.z * 32767.0f;

                std::memcpy(data+i*stride+offset, &vert, 6);
                offset += 6;
            }

            if (mesh->GetNumUVChannels() != 0)
            {
                const aiVector3D& texCoord = mesh->mTextureCoords[0][i];

                struct {uint16_t u, v;} uv;

                uv.u = static_cast<uint16_t>(texCoord.x * 65535.0f);
                uv.v = static_cast<uint16_t>(texCoord.y * 65535.0f);

                std::memcpy(data+i*stride+offset, &uv, 4);

                offset += 4;
            }

            if (mesh->GetNumColorChannels() != 0)
            {
                const aiColor4D& color = mesh->mColors[0][i];

                struct {uint8_t r, g, b, a;} rgba;

                rgba.r = color.r * 255;
                rgba.g = color.g * 255;
                rgba.b = color.b * 255;
                rgba.a = color.a * 255;

                std::memcpy(data+i*stride+offset, &rgba, 4);

                offset += 4;
            }
        }

        if (indexSize == 4)
        {
            for (size_t i = 0; i < mesh->mNumFaces; ++i)
            {
                uint32_t i1 = mesh->mFaces[i].mIndices[0];
                uint32_t i2 = mesh->mFaces[i].mIndices[1];
                uint32_t i3 = mesh->mFaces[i].mIndices[2];

                std::memcpy(data+mesh->mNumVertices*stride+i*12, &i1, 4);
                std::memcpy(data+mesh->mNumVertices*stride+i*12+4, &i2, 4);
                std::memcpy(data+mesh->mNumVertices*stride+i*12+8, &i3, 4);
            }
        } else if (indexSize == 2)
        {
            for (size_t i = 0; i < mesh->mNumFaces; ++i)
            {
                uint16_t i1 = mesh->mFaces[i].mIndices[0];
                uint16_t i2 = mesh->mFaces[i].mIndices[1];
                uint16_t i3 = mesh->mFaces[i].mIndices[2];

                std::memcpy(data+mesh->mNumVertices*stride+i*6, &i1, 2);
                std::memcpy(data+mesh->mNumVertices*stride+i*6+2, &i2, 2);
                std::memcpy(data+mesh->mNumVertices*stride+i*6+4, &i3, 2);
            }
        } else if (indexSize == 1)
        {
            for (size_t i = 0; i < mesh->mNumFaces; ++i)
            {
                uint8_t i1 = mesh->mFaces[i].mIndices[0];
                uint8_t i2 = mesh->mFaces[i].mIndices[1];
                uint8_t i3 = mesh->mFaces[i].mIndices[2];

                std::memcpy(data+mesh->mNumVertices*stride+i*3, &i1, 1);
                std::memcpy(data+mesh->mNumVertices*stride+i*3+1, &i2, 1);
                std::memcpy(data+mesh->mNumVertices*stride+i*3+2, &i3, 1);
            }
        }

        uint32_t size = stride*mesh->mNumVertices + mesh->mNumFaces*indexSize*3;

        std::fwrite(&size, 4, 1, output);
        std::fwrite(data, size, 1, output);

        std::free(data);
    }

    std::fclose(output);
}
}

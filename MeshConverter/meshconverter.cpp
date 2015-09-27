#include "../include/endian_utils.h"

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <stddef.h>
#include <stdint.h>
#include <vector>
#include <array>
#include <assert.h>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#if __BYTE_ORDER != __LITTLE_ENDIAN
#error "The byte order is not little endian."
#endif

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

struct VertexBoneData
{
    VertexBoneData()
    {
        count = 0;
        bones[0] = bones[1] = bones[2] = bones[3] = 0;
        weights[0] = 255;
        weights[1] = weights[2] = weights[3] = 0;
    }

    void add(uint8_t bone, uint8_t weight)
    {
        assert(count < 4);

        bones[count] = bone;
        weights[count++] = weight;
    }

    size_t count;
    uint8_t bones[4];
    uint8_t weights[4];
};

extern "C"
{
void convert(const char *input, const char *out, bool animated)
{
    Assimp::Importer importer;

    const aiScene *scene = importer.ReadFile(input,   aiProcess_CalcTangentSpace
                                                    | aiProcess_JoinIdenticalVertices
                                                    | aiProcess_Triangulate
                                                    | aiProcess_GenSmoothNormals
                                                    | aiProcess_ValidateDataStructure
                                                    | aiProcess_ImproveCacheLocality
                                                    | aiProcess_FindInvalidData
                                                    | aiProcess_GenUVCoords
                                                    | aiProcess_FindInstances
                                                    | aiProcess_OptimizeMeshes
                                                    | aiProcess_LimitBoneWeights
                                                    | (animated ? 0 : aiProcess_PreTransformVertices));

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

        std::cerr << "Meshes:\n";

        for (size_t i = 0; i < scene->mNumMeshes; ++i)
        {
            std::cout << "    " << scene->mMeshes[i]->mName.data << std::endl;
        }
    }

    aiMesh *mesh = scene->mMeshes[0];

    size_t indexSize = (mesh->mNumVertices < 0xFFu) ? 1 : (mesh->mNumVertices < 0xFFFFu) ? 2 : 4;

    FILE *output = std::fopen(out, "wb");

    std::fwrite("mesh\x00\x00", 6, 1, output);

    unsigned int count = mesh->mNumFaces*3;

    std::fwrite(&count, 4, 1, output);

    std::fwrite("\x01\x06\x00\x01", 4, 1, output); //indexed, primitive, cull mode, winding

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

    uint32_t numVertexAttribs = ((mesh->HasPositions() != 0) ? 1 : 0) +
                                ((mesh->HasNormals() != 0) ? 1 : 0) +
                                ((mesh->HasTangentsAndBitangents() != 0) ? 1 : 0) +
                                ((mesh->GetNumUVChannels() != 0) ? 1 : 0) +
                                ((mesh->GetNumColorChannels() != 0) ? 1 : 0) +
                                ((mesh->HasBones() != 0) ? 2 : 0);

    std::fwrite(&numVertexAttribs, 4, 1, output);

    if (mesh->HasPositions())
    {
        std::fwrite("\x00\x06", 2, 1, output); //type, datatype

        uint32_t size = mesh->mNumVertices * 12;
        std::fwrite(&size, 4, 1, output);

        for (size_t i = 0; i < mesh->mNumVertices; ++i)
        {
            std::fwrite(&mesh->mVertices[i].x, 4, 1, output);
            std::fwrite(&mesh->mVertices[i].y, 4, 1, output);
            std::fwrite(&mesh->mVertices[i].z, 4, 1, output);
        }
    }

    if (mesh->HasNormals())
    {
        std::fwrite("\x01\x16", 2, 1, output); //type, datatype

        uint32_t size = mesh->mNumVertices * 6;
        std::fwrite(&size, 4, 1, output);

        for (size_t i = 0; i < mesh->mNumVertices; ++i)
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

            std::fwrite(&vert, 6, 1, output);
        }
    }

    if (mesh->HasTangentsAndBitangents())
    {
        std::fwrite("\x02\x16", 2, 1, output); //type, datatype

        uint32_t size = mesh->mNumVertices * 6;
        std::fwrite(&size, 4, 1, output);

        for (size_t i = 0; i < mesh->mNumVertices; ++i)
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

            std::fwrite(&vert, 6, 1, output);
        }
    }

    if (mesh->GetNumColorChannels() != 0)
    {
        std::fwrite("\x03\x23", 2, 1, output); //type, datatype

        uint32_t size = mesh->mNumVertices * 4;
        std::fwrite(&size, 4, 1, output);

        for (size_t i = 0; i < mesh->mNumVertices; ++i)
        {
            const aiColor4D& color = mesh->mColors[0][i];

            struct {uint8_t r, g, b, a;} rgba;

            rgba.r = color.r * 255;
            rgba.g = color.g * 255;
            rgba.b = color.b * 255;
            rgba.a = color.a * 255;

            std::fwrite(&rgba, 4, 1, output);
        }
    }

    if (mesh->GetNumUVChannels() != 0)
    {
        std::fwrite("\x04\x29", 2, 1, output); //type, datatype

        uint32_t size = mesh->mNumVertices * 4;
        std::fwrite(&size, 4, 1, output);

        for (size_t i = 0; i < mesh->mNumVertices; ++i)
        {
            const aiVector3D& texCoord = mesh->mTextureCoords[0][i];

            uint16_t u = static_cast<uint16_t>(texCoord.x * 65535.0f);
            uint16_t v = static_cast<uint16_t>(texCoord.y * 65535.0f);

            std::fwrite(&u, 2, 1, output);
            std::fwrite(&v, 2, 1, output);
        }
    }

    if (mesh->HasBones())
    {
        std::vector<VertexBoneData> boneData(mesh->mNumVertices);

        for (size_t i = 0; i < mesh->mNumBones; ++i)
        {
            aiBone *bone = mesh->mBones[i];

            for (size_t j = 0; j < bone->mNumWeights; ++j)
            {
                boneData[bone->mWeights[j].mVertexId].add(i+1, bone->mWeights[j].mWeight * 255.0f);
            }
        }

        //Bone indices
        std::fwrite("\x05\x0b", 2, 1, output); //type, datatype

        uint32_t size = mesh->mNumVertices * 4;
        std::fwrite(&size, 4, 1, output);

        for (size_t i = 0; i < mesh->mNumVertices; ++i)
        {
            std::fwrite(boneData[i].bones, 4, 1, output);
        }

        //Bone weights
        std::fwrite("\x06\x23", 2, 1, output); //type, datatype

        std::fwrite(&size, 4, 1, output);

        for (size_t i = 0; i < mesh->mNumVertices; ++i)
        {
            std::fwrite(boneData[i].weights, 4, 1, output);
        }
    }

    uint8_t indexType;

    if (indexSize == 4)
    {
        indexType = 2;
    } else if (indexSize == 2)
    {
        indexType = 1;
    } else if (indexSize == 1)
    {
        indexType = 0;
    }

    std::fwrite(&indexType, 1, 1, output);

    if (indexSize == 4)
    {
        for (size_t i = 0; i < mesh->mNumFaces; ++i)
        {
            uint32_t i1 = mesh->mFaces[i].mIndices[0];
            uint32_t i2 = mesh->mFaces[i].mIndices[1];
            uint32_t i3 = mesh->mFaces[i].mIndices[2];

            std::fwrite(&i1, 4, 1, output);
            std::fwrite(&i2, 4, 1, output);
            std::fwrite(&i3, 4, 1, output);
        }
    } else if (indexSize == 2)
    {
        for (size_t i = 0; i < mesh->mNumFaces; ++i)
        {
            uint16_t i1 = mesh->mFaces[i].mIndices[0];
            uint16_t i2 = mesh->mFaces[i].mIndices[1];
            uint16_t i3 = mesh->mFaces[i].mIndices[2];

            std::fwrite(&i1, 2, 1, output);
            std::fwrite(&i2, 2, 1, output);
            std::fwrite(&i3, 2, 1, output);
        }
    } else if (indexSize == 1)
    {
        for (size_t i = 0; i < mesh->mNumFaces; ++i)
        {
            uint8_t i1 = mesh->mFaces[i].mIndices[0];
            uint8_t i2 = mesh->mFaces[i].mIndices[1];
            uint8_t i3 = mesh->mFaces[i].mIndices[2];

            std::fwrite(&i1, 1, 1, output);
            std::fwrite(&i2, 1, 1, output);
            std::fwrite(&i3, 1, 1, output);
        }
    }

    uint32_t boneCount = mesh->mNumBones+1;
    std::fwrite(&boneCount, 4, 1, output);

    //Identity bone
    float identityMatrix[] = {1.0f, 0.0f, 0.0f, 0.0f,
                              0.0f, 1.0f, 0.0f, 0.0f,
                              0.0f, 0.0f, 1.0f, 0.0f,
                              0.0f, 0.0f, 0.0f, 1.0f};
    std::fwrite(identityMatrix, 64, 1, output);

    uint32_t numChildren = 0;
    std::fwrite(&numChildren, 4, 1, output);

    for (size_t i = 0; i < mesh->mNumBones; ++i)
    {
        aiMatrix4x4 boneMatrix = mesh->mBones[i]->mOffsetMatrix;

        boneMatrix.Transpose();

        std::fwrite(&boneMatrix, 64, 1, output);

        aiNode *bone = scene->mRootNode->FindNode(mesh->mBones[i]->mName);

        std::vector<uint8_t> children;
        for (size_t j = 0; j < bone->mNumChildren; ++j)
        {
            int boneIndex = -1;

            for (size_t k = 0; k < mesh->mNumBones; ++k)
            {
                if (mesh->mBones[i]->mName == bone->mChildren[j]->mName)
                {
                    boneIndex = k;
                    break;
                }
            }

            if (boneIndex == -1)
            {
                continue;
            }

            uint8_t v = boneIndex + 1;
            children.push_back(v);
        }

        uint32_t numChildren = children.size();

        std::fwrite(&numChildren, 4, 1, output);

        std::fwrite(children.data(), numChildren, 1, output);
    }

    uint32_t animationCount = scene->mNumAnimations;
    std::fwrite(&animationCount, 4, 1, output);

    for (size_t i = 0; i < scene->mNumAnimations; ++i)
    {
        aiAnimation *anim = scene->mAnimations[i];

        uint32_t nameLength = 9;
        std::fwrite(&nameLength, 4, 1, output);

        std::cout << "Animation name: '" << "animation" << "'" << std::endl;

        std::fwrite("animation", 9, 1, output);

        uint32_t fps = 24;
        uint32_t numFrames = anim->mDuration * fps;

        std::fwrite(&fps, 4, 1, output);
        std::fwrite(&numFrames, 4, 1, output);

        for (size_t j = 0; j < numFrames; ++j)
        {
            std::vector<std::array<float, 10>> transforms(mesh->mNumBones+1);

            for (auto& transform : transforms)
            {
                transform[0] = 0.0f;
                transform[1] = 0.0f;
                transform[2] = 0.0f;
                transform[3] = 1.0f;
                transform[4] = 1.0f;
                transform[5] = 1.0f;
                transform[6] = 1.0f;
                transform[7] = 0.0f;
                transform[8] = 0.0f;
                transform[9] = 0.0f;
            }

            for (size_t k = 0; k < anim->mNumChannels; ++k)
            {
                aiNodeAnim *nodeAnim = anim->mChannels[k];

                int boneIndex = -1;

                for (size_t k = 0; k < mesh->mNumBones; ++k)
                {
                    if (mesh->mBones[k]->mName == nodeAnim->mNodeName)
                    {
                        boneIndex = k;
                        break;
                    }
                }

                if (boneIndex == -1)
                {
                    continue;
                }

                aiVectorKey positionKey;
                aiVectorKey scaleKey;
                aiQuatKey orientationKey;

                for (size_t k2 = 0; k2 < nodeAnim->mNumPositionKeys; ++k2)
                {
                    if (size_t(nodeAnim->mPositionKeys[k2].mTime * fps) >= j)
                    {
                        positionKey = nodeAnim->mPositionKeys[k2];
                    }
                }

                for (size_t k2 = 0; k2 < nodeAnim->mNumScalingKeys; ++k2)
                {
                    if (size_t(nodeAnim->mScalingKeys[k2].mTime * fps) >= j)
                    {
                        scaleKey = nodeAnim->mScalingKeys[k2];
                    }
                }

                for (size_t k2 = 0; k2 < nodeAnim->mNumRotationKeys; ++k2)
                {
                    if (size_t(nodeAnim->mRotationKeys[k2].mTime * fps) >= j)
                    {
                        orientationKey = nodeAnim->mRotationKeys[k2];
                    }
                }

                transforms[boneIndex+1] = {orientationKey.mValue.x,
                                           orientationKey.mValue.y,
                                           orientationKey.mValue.z,
                                           orientationKey.mValue.w,
                                           scaleKey.mValue.x,
                                           scaleKey.mValue.y,
                                           scaleKey.mValue.z,
                                           positionKey.mValue.x,
                                           positionKey.mValue.y,
                                           positionKey.mValue.z};

                /*std::cout << transforms[boneIndex][0] << " "
                          << transforms[boneIndex][1] << " "
                          << transforms[boneIndex][2] << " "
                          << transforms[boneIndex][3] << " "
                          << transforms[boneIndex][4] << " "
                          << transforms[boneIndex][5] << " "
                          << transforms[boneIndex][6] << " "
                          << transforms[boneIndex][7] << " "
                          << transforms[boneIndex][8] << " "
                          << transforms[boneIndex][9] << std::endl;*/
            }

            for (auto transform : transforms)
            {
                std::fwrite(transform.data(), 40, 1, output);
            }
        }
    }

    std::fclose(output);
}
}

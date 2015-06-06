#ifndef GFXMODEL_H
#define GFXMODEL_H

#include "containers/string.h"
#include "containers/list.h"
#include "containers/pair.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxmaterial.h"
#include "resource/resource.h"
#include "math/matrix4x4.h"
#include "misc_macros.h"

class GfxModel : public Resource
{
    public:
        enum ContextType
        {
            Forward
        };

        static const Resource::Type resource_type = GfxModelType;

        struct LOD
        {
            LOD(float minDistance,
                float maxDistance,
                ResPtr<GfxMesh> mesh,
                ResPtr<GfxMaterial> material,
                const Matrix4x4& matrix);

            float minDistance;
            float maxDistance;
            ResPtr<GfxMesh> mesh;
            ResPtr<GfxMaterial> material;
            Matrix4x4 worldMatrix;

            bool operator == (const GfxModel::LOD& other) const
            {
                return minDistance == other.minDistance and
                       maxDistance == other.maxDistance and
                       mesh == other.mesh and
                       material == other.material and
                       worldMatrix == other.worldMatrix;
            }
        };

        typedef List<LOD> SubModel;
        typedef List<SubModel> Context;

        GfxModel(const String& name);
        GfxModel(const String& filename,
                 const String& name);

        virtual void removeContent();

        virtual void save();

        HashMap<ContextType, Context> contexts;
    protected:
        virtual void _load();

    NO_COPY_INHERITED(GfxModel, Resource)
};

#endif // GFXMODEL_H

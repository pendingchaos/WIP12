#ifndef GFXMODEL_H
#define GFXMODEL_H

#include "containers/string.h"
#include "containers/list.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxmaterial.h"
#include "resource/resource.h"
#include "math/matrix4x4.h"
#include "misc_macros.h"

class GfxModel : public Resource
{
    NO_COPY_INHERITED(GfxModel, Resource)

    public:
        static const ResType resource_type = ResType::GfxModelType;

        struct LOD
        {
            LOD(float minDistance,
                float maxDistance,
                GfxMesh *mesh,
                GfxMaterial *material,
                const Matrix4x4& matrix);

            float minDistance;
            float maxDistance;
            GfxMesh *mesh;
            GfxMaterial *material;
            Matrix4x4 worldMatrix;
        };

        typedef List<LOD> SubModel;

        GfxModel();
        GfxModel(const String& filename);
        virtual ~GfxModel();

        virtual void removeContent();

        virtual void save();

        List<SubModel> subModels;
    protected:
        virtual void _load();
        virtual Resource *_copy() const;
};

#endif // GFXMODEL_H

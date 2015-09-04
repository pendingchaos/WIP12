#ifndef GFXMODEL_H
#define GFXMODEL_H

#include "containers/string.h"
#include "containers/list.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxmaterial.h"
#include "resource/resource.h"
#include "math/matrix4x4.h"
#include "scripting/bindings.h"
#include "misc_macros.h"

struct GfxLOD
{
    //TODO: Handle pointer ownership.
    GfxLOD() : minDistance(0.0f), maxDistance(0.0f), mesh(NEW(GfxMesh)), material(NEW(GfxMaterial)) {}
    GfxLOD(float minDistance,
           float maxDistance,
           GfxMesh *mesh,
           GfxMaterial *material,
           const Matrix4x4& matrix) NO_BIND;

    bool operator == (const GfxLOD& other) const
    {
        return minDistance == other.minDistance and
               maxDistance == other.maxDistance and
               mesh == other.mesh and
               material == other.material and
               worldMatrix == other.worldMatrix;
    }

    float minDistance;
    float maxDistance;
    NO_BIND GfxMesh *mesh;
    NO_BIND GfxMaterial *material;
    Matrix4x4 worldMatrix;
} BIND;

class GfxModel : public Resource
{
    NO_COPY_INHERITED(GfxModel, Resource)

    public:
        static const ResType resource_type = ResType::GfxModelType;

        typedef List<GfxLOD> SubModel;

        GfxModel();
        GfxModel(const String& filename);
        virtual ~GfxModel();

        virtual void removeContent();

        virtual void save();

        List<SubModel> subModels;
    protected:
        virtual void _load();
        virtual Resource *_copy() const;
} BIND DESTROY(obj->release());

#endif // GFXMODEL_H

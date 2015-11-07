#ifndef MATERIAL_H
#define MATERIAL_H

#include "containers/list.h"
#include "containers/hashmap.h"
#include "containers/string.h"
#include "graphics/gfxtexture.h"
#include "graphics/gfxshader.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxdefs.h"
#include "resource/resource.h"
#include "resource/resourcemanager.h"
#include "math/t4.h"
#include "misc_macros.h"
#include "memory.h"
#include "scripting/bindings.h"
#include "scripting/script.h"

class GfxMesh;
class GfxAnimationState;
class Camera;
class Light;

class GfxMaterial : public Resource
{
    public:
        static const ResType resource_type = ResType::GfxMaterialType;

        GfxMaterial();
        GfxMaterial(const Str& filename);

        virtual ~GfxMaterial();

        virtual void removeContent();
        virtual void save();

        void setScript(Script *script_)
        {
            DELETE(script);
            script = script_->createInstance(nullptr, nullptr, this);
        }

        ScriptInstance *getScriptInst() const
        {
            return script;
        }

        void setupRender(GfxAnimationState *animState, const Camera& camera);
        GfxShaderCombination *getShaders(bool animated);

        bool forward;
        GfxCompiledShader *vertex;
        GfxCompiledShader *tessControl;
        GfxCompiledShader *tessEval;
        GfxCompiledShader *geometry;
        GfxCompiledShader *fragment;
        GfxCompiledShader *animVertex;
        GfxCompiledShader *animTessControl;
        GfxCompiledShader *animTessEval;
        GfxCompiledShader *animGeometry;
        GfxCompiledShader *animFragment;
    private:
        ScriptInstance *script;
    protected:
        virtual void _load();
        virtual Resource *_copy() const;

    NO_COPY_INHERITED(GfxMaterial, Resource)
} DESTROY(obj->release()) BIND;

#endif // MATERIAL_H

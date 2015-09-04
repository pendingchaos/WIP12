//Generated from script_binding_generator2.py. Do not edit. Edit script_binding_generator2.py instead.
#include "platform.h"
#include "filesystem.h"
#include "serialization.h"
#include "misc_macros.h"
#include "error.h"
#include "globals.h"
#include "memory.h"
#include "application.h"
#include "endian_utils.h"
#include "logging.h"
#include "backtrace.h"
#include "file.h"
#include "graphics/gfxdefs.h"
#include "graphics/gfxmaterial.h"
#include "graphics/gfxdebugdrawer.h"
#include "graphics/light.h"
#include "graphics/gputimer.h"
#include "graphics/gfxbuffer.h"
#include "graphics/gfxframebuffer.h"
#include "graphics/gfxapi.h"
#include "graphics/font.h"
#include "graphics/gfxtexture.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxrenderer.h"
#include "graphics/gfxshader.h"
#include "graphics/camera.h"
#include "graphics/gfxmodel.h"
#include "graphics/GL/gfxglmeshimpl.h"
#include "graphics/GL/gfxglshaderimpl.h"
#include "graphics/GL/gfxglframebuffer.h"
#include "graphics/GL/glfl.h"
#include "graphics/GL/glgputimer.h"
#include "graphics/GL/gfxglbuffer.h"
#include "graphics/GL/gfxglapi.h"
#include "graphics/GL/gfxgltextureimpl.h"
#include "audio/audioworld.h"
#include "audio/audio.h"
#include "audio/audiodevice.h"
#include "resource/resourcemanager.h"
#include "resource/resource.h"
#include "physics/ghostobject.h"
#include "physics/physicsshape.h"
#include "physics/rigidbody.h"
#include "physics/physicsworld.h"
#include "physics/physicsdebugdrawer.h"
#include "math/quaternion.h"
#include "math/aabb.h"
#include "math/t2.h"
#include "math/t3.h"
#include "math/t4.h"
#include "math/matrix4x4.h"
#include "math/matrix3x3.h"
#include "scene/entity.h"
#include "scene/scene.h"
#include "scene/transform.h"
#include "containers/resizabledata.h"
#include "containers/hashmap.h"
#include "containers/list.h"
#include "containers/string.h"
#include "scripting/parser.h"
#include "scripting/bytecodegen.h"
#include "scripting/bindings.h"
#include "scripting/script.h"
#include "scripting/vm/engine.h"
#include "scripting/vm/context.h"
#include "scripting/vm/bytecode.h"
#include "scripting/vm/types.h"
#include <stdint.h>

#include "scripting/vm/engine.h"
#include "scripting/vm/context.h"
#include "scripting/vm/bytecode.h"
#include "scripting/vm/types.h"
#include "scripting/parser.h"
#include "scripting/bytecodegen.h"
#include <type_traits>

struct BindingsExt
{
    int64_t Filesystem_typeID, Filesystem_ptr_typeID, GfxCompiledShader_typeID, GfxCompiledShader_ptr_typeID, UInt2_typeID, UInt2_ptr_typeID, GPUTimer_typeID, GPUTimer_ptr_typeID, RigidBody_typeID, RigidBody_ptr_typeID, Float2_typeID, Float2_ptr_typeID, AudioSource_typeID, AudioSource_ptr_typeID, Camera_typeID, Camera_ptr_typeID, Resource_typeID, Resource_ptr_typeID, GfxShader_typeID, GfxShader_ptr_typeID, UInt4_typeID, UInt4_ptr_typeID, Int3_typeID, Int3_ptr_typeID, ResizableData_typeID, ResizableData_ptr_typeID, Int4_typeID, Int4_ptr_typeID, Float3_typeID, Float3_ptr_typeID, GfxLODList_typeID, GfxLODList_ptr_typeID, GfxBuffer_typeID, GfxBuffer_ptr_typeID, Transform_typeID, Transform_ptr_typeID, Quaternion_typeID, Quaternion_ptr_typeID, Int2_typeID, Int2_ptr_typeID, AudioWorld_typeID, AudioWorld_ptr_typeID, StrStrMap_typeID, StrStrMap_ptr_typeID, Light_typeID, Light_ptr_typeID, LightPointData_typeID, LightPointData_ptr_typeID, Float4_typeID, Float4_ptr_typeID, LightDirectionalData_typeID, LightDirectionalData_ptr_typeID, Matrix4x4_typeID, Matrix4x4_ptr_typeID, UInt3_typeID, UInt3_ptr_typeID, LightSpotData_typeID, LightSpotData_ptr_typeID, AudioDevice_typeID, AudioDevice_ptr_typeID, GfxLOD_typeID, GfxLOD_ptr_typeID, File_typeID, File_ptr_typeID, AABB_typeID, AABB_ptr_typeID, List_typeID, List_ptr_typeID, Audio_typeID, Audio_ptr_typeID, GfxSubModelList_typeID, GfxSubModelList_ptr_typeID, GfxModel_typeID, GfxModel_ptr_typeID, Matrix3x3_typeID, Matrix3x3_ptr_typeID, GfxDebugDrawer_typeID, GfxDebugDrawer_ptr_typeID, ResType_typeID, GfxPrimitive_typeID, GfxDepthFunction_typeID, GfxBlendMode_typeID, GfxBlendFactor_typeID, GfxCullMode_typeID, GfxWinding_typeID, GfxVertexAttribPurpose_typeID, GfxVertexAttribType_typeID, GfxStage_typeID, GfxBufferUsage_typeID, GfxShadowmapPrecision_typeID, GfxLightType_typeID, CameraType_typeID;
    scripting::Value *Filesystem, *Filesystem_ptr, *GfxCompiledShader, *GfxCompiledShader_ptr, *UInt2, *UInt2_ptr, *GPUTimer, *GPUTimer_ptr, *RigidBody, *RigidBody_ptr, *Float2, *Float2_ptr, *AudioSource, *AudioSource_ptr, *Camera, *Camera_ptr, *Resource, *Resource_ptr, *GfxShader, *GfxShader_ptr, *UInt4, *UInt4_ptr, *Int3, *Int3_ptr, *ResizableData, *ResizableData_ptr, *Int4, *Int4_ptr, *Float3, *Float3_ptr, *GfxLODList, *GfxLODList_ptr, *GfxBuffer, *GfxBuffer_ptr, *Transform, *Transform_ptr, *Quaternion, *Quaternion_ptr, *Int2, *Int2_ptr, *AudioWorld, *AudioWorld_ptr, *StrStrMap, *StrStrMap_ptr, *Light, *Light_ptr, *LightPointData, *LightPointData_ptr, *Float4, *Float4_ptr, *LightDirectionalData, *LightDirectionalData_ptr, *Matrix4x4, *Matrix4x4_ptr, *UInt3, *UInt3_ptr, *LightSpotData, *LightSpotData_ptr, *AudioDevice, *AudioDevice_ptr, *GfxLOD, *GfxLOD_ptr, *File, *File_ptr, *AABB, *AABB_ptr, *List, *List_ptr, *Audio, *Audio_ptr, *GfxSubModelList, *GfxSubModelList_ptr, *GfxModel, *GfxModel_ptr, *Matrix3x3, *Matrix3x3_ptr, *GfxDebugDrawer, *GfxDebugDrawer_ptr, *ResType, *GfxPrimitive, *GfxDepthFunction, *GfxBlendMode, *GfxBlendFactor, *GfxCullMode, *GfxWinding, *GfxVertexAttribPurpose, *GfxVertexAttribType, *GfxStage, *GfxBufferUsage, *GfxShadowmapPrecision, *GfxLightType, *CameraType;
};


#define CATE ctx->throwException(scripting::createException
#define SV scripting::Value*
#define NO scripting::NativeObject*
#define CV(expr) create_val<std::remove_reference<decltype(expr)>::type>::f(ctx, expr)
#define TS(expr, ...) type_same<__VA_ARGS__>::f(ctx, expr)
#define VE scripting::ExcType::ValueError
#define TE scripting::ExcType::TypeError
#define KE scripting::ExcType::KeyError
#define CTX scripting::Context*
#define EXT ((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)
#define S scripting
#define EI else if
#define R return
#define UFOF(cm) "Unable to find overload for " cm
#define FAE(meth, cls) meth " expects " cls "as first argument."
#define EAOE " expects at least one argument."
#define CN S::createNil()
#define CNF S::createNativeFunction
#define F self

template <typename T>
struct val_to_c {};

#define VAL_TO_C_INT(T, T2, min, max) template <>struct val_to_c<T2>{    static T f(scripting::Context *ctx, const SV head)    {        int64_t v;                if (head->type == scripting::ValueType::Int)        {            v = ((scripting::IntValue *)head)->value;        } else if (head->type == scripting::ValueType::Float)        {            v = ((scripting::FloatValue *)head)->value;        } else        {            CATE(scripting::ExcType::TypeError, "Value can not be converted to int."));        }                if (v < min or v > max)        {            CATE(scripting::ExcType::TypeError, "Value out of bounds."));        }                return v;    }};

VAL_TO_C_INT(uint8_t, uint8_t, 0, UINT8_MAX)
VAL_TO_C_INT(int8_t, int8_t, INT8_MIN, INT8_MAX)
VAL_TO_C_INT(uint16_t, uint16_t, 0, UINT16_MAX)
VAL_TO_C_INT(int16_t, int16_t, INT16_MIN, INT16_MAX)
VAL_TO_C_INT(uint32_t, uint32_t, 0, UINT32_MAX)
VAL_TO_C_INT(int32_t, int32_t, INT32_MIN, INT32_MAX)
VAL_TO_C_INT(uint64_t, uint64_t, 0, UINT64_MAX)
VAL_TO_C_INT(int64_t, int64_t, INT64_MIN, INT64_MAX)
VAL_TO_C_INT(uint8_t, const uint8_t&, 0, UINT8_MAX)
VAL_TO_C_INT(int8_t, const int8_t&, INT8_MIN, INT8_MAX)
VAL_TO_C_INT(uint16_t, const uint16_t&, 0, UINT16_MAX)
VAL_TO_C_INT(int16_t, const int16_t&, INT16_MIN, INT16_MAX)
VAL_TO_C_INT(uint32_t, const uint32_t&, 0, UINT32_MAX)
VAL_TO_C_INT(int32_t, const int32_t&, INT32_MIN, INT32_MAX)
VAL_TO_C_INT(uint64_t, const uint64_t&, 0, UINT64_MAX)
VAL_TO_C_INT(int64_t, const int64_t&, INT64_MIN, INT64_MAX)

template <>
struct val_to_c<float>
{
    static float f(scripting::Context *ctx, const SV head)
    {
        float v;
        
        if (head->type == scripting::ValueType::Int)
        {
            v = ((scripting::IntValue *)head)->value;
        } else if (head->type == scripting::ValueType::Float)
        {
            v = ((scripting::FloatValue *)head)->value;
        } else
        {
            CATE(scripting::ExcType::TypeError, "Value can not be converted to float."));
        }
        
        return v;
    }
};

template <>
struct val_to_c<double>
{
    static double f(scripting::Context *ctx, const SV head)
    {
        double v;
        
        if (head->type == scripting::ValueType::Int)
        {
            v = ((scripting::IntValue *)head)->value;
        } else if (head->type == scripting::ValueType::Float)
        {
            v = ((scripting::FloatValue *)head)->value;
        } else
        {
            CATE(scripting::ExcType::TypeError, "Value can not be converted to float."));
        }
        
        return v;
    }
};

template <>
struct val_to_c<bool>
{
    static bool f(scripting::Context *ctx, const SV head)
    {
        if (head->type == scripting::ValueType::Boolean)
        {
            return ((scripting::BooleanValue *)head)->value;
        } else
        {
            CATE(scripting::ExcType::TypeError, "Value can not be converted to bool."));
        }
    }
};

template <>
struct val_to_c<String>
{
    static String f(scripting::Context *ctx, const SV head)
    {
        if (head->type == scripting::ValueType::StringType)
        {
            return ((scripting::StringValue *)head)->value;
        } else
        {
            CATE(scripting::ExcType::TypeError, "Value can not be converted to string."));
        }
    }
};

template <>
struct val_to_c<const char *>
{
    static const char *f(scripting::Context *ctx, const SV head)
    {
        if (head->type == scripting::ValueType::StringType)
        {
            return ((scripting::StringValue *)head)->value.getData();
        } else
        {
            CATE(scripting::ExcType::TypeError, "Value can not be converted to string."));
        }
    }
};

template <>
struct val_to_c<char>
{
    static char f(scripting::Context *ctx, const SV head)
    {
        if (head->type == scripting::ValueType::StringType)
        {
            if (((scripting::StringValue *)head)->value.getLength() == 1)
            {
                return ((scripting::StringValue *)head)->value[0];
            } else
            {
                CATE(scripting::ExcType::ValueError, "Value can not be converted to character."));
            }
        } else
        {
            CATE(scripting::ExcType::TypeError, "Value can not be converted to character."));
        }
    }
};

template <>
struct val_to_c<SV>
{
    static SV f(scripting::Context *ctx, const SV head)
    {
        return scripting::createCopy(ctx, head);
    }
};

template <>
struct val_to_c<const SV>
{
    static SV f(scripting::Context *ctx, const SV head)
    {
        return scripting::createCopy(ctx, head);
    }
};

template <>
struct val_to_c<const SV&>
{
    static SV f(scripting::Context *ctx, const SV head)
    {
        return scripting::createCopy(ctx, head);
    }
};

template <typename T>
struct val_to_c<const T&> {
    static T f(scripting::Context *ctx, const SV head)
    {
        return val_to_c<T>::f(ctx, head);
    }
};

template <typename T>
struct create_val {};

#define CREATE_VAL(T, func) template <>struct create_val<T>{    static SV f(scripting::Context *ctx, const T& v)    {        return scripting::func(v);    }};

template <>
struct create_val<SV>
{
    static scripting::Value *f(scripting::Context *ctx, const SV head)
    {
        return scripting::createCopy(ctx, head);
    }
};

template <>
struct create_val<const char *>
{
    static SV f(scripting::Context *ctx, const char *data)
    {
        return scripting::createString(String(data));
    }
};

template <>
struct create_val<char>
{
    static SV f(scripting::Context *ctx, char data)
    {
        return scripting::createString(String(data));
    }
};

template <>
struct create_val<const String>
{
    static SV f(scripting::Context *ctx, const String& data)
    {
        return scripting::createString(data);
    }
};

CREATE_VAL(uint8_t, createInt)
CREATE_VAL(int8_t, createInt)
CREATE_VAL(uint16_t, createInt)
CREATE_VAL(int16_t, createInt)
CREATE_VAL(uint32_t, createInt)
CREATE_VAL(int32_t, createInt)
CREATE_VAL(uint64_t, createInt)
CREATE_VAL(int64_t, createInt)
CREATE_VAL(float, createFloat)
CREATE_VAL(double, createFloat)
CREATE_VAL(bool, createBoolean)
CREATE_VAL(String, createString)

template <typename T>
struct type_same;

template <typename T>
struct type_same<const T&>
{
    static bool f(scripting::Context *ctx, const SV head)
    {
        return type_same<T>::f(ctx, head);
    }
};

template <typename T>
struct type_same<const T>
{
    static bool f(scripting::Context *ctx, const SV head)
    {
        return type_same<T>::f(ctx, head);
    }
};

template <>
struct type_same<SV>
{
    static bool f(scripting::Context *ctx, const SV head)
    {
        return true;
    }
};

template <>
struct type_same<const SV&>
{
    static bool f(scripting::Context *ctx, const SV head)
    {
        return true;
    }
};

template <>
struct type_same<const SV>
{
    static bool f(scripting::Context *ctx, const SV head)
    {
        return true;
    }
};

template <>
struct type_same<char>
{
    static bool f(scripting::Context *ctx, const SV head)
    {
        if (head->type == scripting::ValueType::StringType)
        {
            return ((const scripting::StringValue *)head)->value.getLength() == 1;
        } else
        {
            return false;
        }
    }
};

#define TYPE_SAME_HELPER(T, enumValue) template <>struct type_same<T>{    static bool f(scripting::Context *ctx, const SV head)    {        return head->type == scripting::ValueType::enumValue;    }};

TYPE_SAME_HELPER(uint8_t, Int)
TYPE_SAME_HELPER(int8_t, Int)
TYPE_SAME_HELPER(uint16_t, Int)
TYPE_SAME_HELPER(int16_t, Int)
TYPE_SAME_HELPER(uint32_t, Int)
TYPE_SAME_HELPER(int32_t, Int)
TYPE_SAME_HELPER(uint64_t, Int)
TYPE_SAME_HELPER(int64_t, Int)
TYPE_SAME_HELPER(float, Float)
TYPE_SAME_HELPER(double, Float)
TYPE_SAME_HELPER(bool, Boolean)
TYPE_SAME_HELPER(String, StringType)
TYPE_SAME_HELPER(const char *, StringType)

template <typename T>
T *own(scripting::Context *ctx, SV value)
{
    if (type_same<T *>::f(ctx, value))
    {
        void *ptr = ((NO)value)->data;
        AllocInfo i = getAllocInfo(ptr);
        i.cppRef = true;
        setAllocInfo(ptr, i);

        return (T *)ptr;
    }

    CATE(scripting::ExcType::TypeError, "Argument's value can not be converted."));
}
void ResType_destroy(CTX,NO) {}
SV ResType_get_member(CTX,NO,SV);
void ResType_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs ResType_funcs={
.destroy = ResType_destroy,
.getMember = ResType_get_member,
.setMember = ResType_set_member
};
template <>
struct create_val<ResType>
{
static SV f(CTX ctx,ResType v)
{
R S::createNativeObject(ResType_funcs,(void *)v,EXT->ResType_typeID);
}
};
template <>
struct val_to_c<ResType>
{
static ResType f(CTX ctx,const SV head)
{
if(head->type!=S::ValueType::NativeObject)
CATE(TE,"Value can not be converted to ResType."));

NO obj=(NO)head;
if(obj->typeID!=EXT->ResType_typeID)
CATE(TE,"Value can not be converted to ResType."));
size_t v=size_t(obj->data);
if(v==3)return ResType::GfxMaterialType;
if(v==6)return ResType::ScriptType;
if(v==1)return ResType::GfxTextureType;
if(v==2)return ResType::GfxMeshType;
if(v==8)return ResType::AudioType;
if(v==9)return ResType::FontType;
if(v==4)return ResType::GfxModelType;
if(v==7)return ResType::PhysicsShapeType;
if(v==0)return ResType::GfxShaderType;
if(v==5)return ResType::SceneType;
}
};
template <>
struct type_same<ResType>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->ResType_typeID;
else
 R false;
}
};void GfxPrimitive_destroy(CTX,NO) {}
SV GfxPrimitive_get_member(CTX,NO,SV);
void GfxPrimitive_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxPrimitive_funcs={
.destroy = GfxPrimitive_destroy,
.getMember = GfxPrimitive_get_member,
.setMember = GfxPrimitive_set_member
};
template <>
struct create_val<GfxPrimitive>
{
static SV f(CTX ctx,GfxPrimitive v)
{
R S::createNativeObject(GfxPrimitive_funcs,(void *)v,EXT->GfxPrimitive_typeID);
}
};
template <>
struct val_to_c<GfxPrimitive>
{
static GfxPrimitive f(CTX ctx,const SV head)
{
if(head->type!=S::ValueType::NativeObject)
CATE(TE,"Value can not be converted to GfxPrimitive."));

NO obj=(NO)head;
if(obj->typeID!=EXT->GfxPrimitive_typeID)
CATE(TE,"Value can not be converted to GfxPrimitive."));
size_t v=size_t(obj->data);
if(v==1)return GfxLineStrip;
if(v==5)return GfxTriangleFan;
if(v==6)return GfxTriangles;
if(v==0)return GfxPoints;
if(v==3)return GfxLines;
if(v==2)return GfxLineLoop;
if(v==4)return GfxTriangleStrip;
if(v==7)return GfxPatches;
}
};
template <>
struct type_same<GfxPrimitive>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxPrimitive_typeID;
else
 R false;
}
};void GfxDepthFunction_destroy(CTX,NO) {}
SV GfxDepthFunction_get_member(CTX,NO,SV);
void GfxDepthFunction_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxDepthFunction_funcs={
.destroy = GfxDepthFunction_destroy,
.getMember = GfxDepthFunction_get_member,
.setMember = GfxDepthFunction_set_member
};
template <>
struct create_val<GfxDepthFunction>
{
static SV f(CTX ctx,GfxDepthFunction v)
{
R S::createNativeObject(GfxDepthFunction_funcs,(void *)v,EXT->GfxDepthFunction_typeID);
}
};
template <>
struct val_to_c<GfxDepthFunction>
{
static GfxDepthFunction f(CTX ctx,const SV head)
{
if(head->type!=S::ValueType::NativeObject)
CATE(TE,"Value can not be converted to GfxDepthFunction."));

NO obj=(NO)head;
if(obj->typeID!=EXT->GfxDepthFunction_typeID)
CATE(TE,"Value can not be converted to GfxDepthFunction."));
size_t v=size_t(obj->data);
if(v==6)return GfxGreaterEqual;
if(v==0)return GfxNever;
if(v==3)return GfxLessEqual;
if(v==7)return GfxAlways;
if(v==1)return GfxLess;
if(v==4)return GfxGreater;
if(v==2)return GfxEqual;
if(v==5)return GfxNotEqual;
}
};
template <>
struct type_same<GfxDepthFunction>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxDepthFunction_typeID;
else
 R false;
}
};void GfxBlendMode_destroy(CTX,NO) {}
SV GfxBlendMode_get_member(CTX,NO,SV);
void GfxBlendMode_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxBlendMode_funcs={
.destroy = GfxBlendMode_destroy,
.getMember = GfxBlendMode_get_member,
.setMember = GfxBlendMode_set_member
};
template <>
struct create_val<GfxBlendMode>
{
static SV f(CTX ctx,GfxBlendMode v)
{
R S::createNativeObject(GfxBlendMode_funcs,(void *)v,EXT->GfxBlendMode_typeID);
}
};
template <>
struct val_to_c<GfxBlendMode>
{
static GfxBlendMode f(CTX ctx,const SV head)
{
if(head->type!=S::ValueType::NativeObject)
CATE(TE,"Value can not be converted to GfxBlendMode."));

NO obj=(NO)head;
if(obj->typeID!=EXT->GfxBlendMode_typeID)
CATE(TE,"Value can not be converted to GfxBlendMode."));
size_t v=size_t(obj->data);
if(v==2)return GfxReverseSubtract;
if(v==0)return GfxAdd;
if(v==1)return GfxSubtract;
}
};
template <>
struct type_same<GfxBlendMode>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxBlendMode_typeID;
else
 R false;
}
};void GfxBlendFactor_destroy(CTX,NO) {}
SV GfxBlendFactor_get_member(CTX,NO,SV);
void GfxBlendFactor_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxBlendFactor_funcs={
.destroy = GfxBlendFactor_destroy,
.getMember = GfxBlendFactor_get_member,
.setMember = GfxBlendFactor_set_member
};
template <>
struct create_val<GfxBlendFactor>
{
static SV f(CTX ctx,GfxBlendFactor v)
{
R S::createNativeObject(GfxBlendFactor_funcs,(void *)v,EXT->GfxBlendFactor_typeID);
}
};
template <>
struct val_to_c<GfxBlendFactor>
{
static GfxBlendFactor f(CTX ctx,const SV head)
{
if(head->type!=S::ValueType::NativeObject)
CATE(TE,"Value can not be converted to GfxBlendFactor."));

NO obj=(NO)head;
if(obj->typeID!=EXT->GfxBlendFactor_typeID)
CATE(TE,"Value can not be converted to GfxBlendFactor."));
size_t v=size_t(obj->data);
if(v==0)return GfxZero;
if(v==2)return GfxSrcColor;
if(v==7)return GfxOneMinusSrcAlpha;
if(v==12)return GfxConstantAlpha;
if(v==8)return GfxDstAlpha;
if(v==6)return GfxSrcAlpha;
if(v==5)return GfxOneMinusDstColor;
if(v==4)return GfxDstColor;
if(v==11)return GfxOneMinusConstantColor;
if(v==3)return GfxOneMinusSrcColor;
if(v==10)return GfxConstantColor;
if(v==13)return GfxOneMinusConstantAlpha;
if(v==1)return GfxOne;
if(v==9)return GfxOneMinusDstAlpha;
}
};
template <>
struct type_same<GfxBlendFactor>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxBlendFactor_typeID;
else
 R false;
}
};void GfxCullMode_destroy(CTX,NO) {}
SV GfxCullMode_get_member(CTX,NO,SV);
void GfxCullMode_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxCullMode_funcs={
.destroy = GfxCullMode_destroy,
.getMember = GfxCullMode_get_member,
.setMember = GfxCullMode_set_member
};
template <>
struct create_val<GfxCullMode>
{
static SV f(CTX ctx,GfxCullMode v)
{
R S::createNativeObject(GfxCullMode_funcs,(void *)v,EXT->GfxCullMode_typeID);
}
};
template <>
struct val_to_c<GfxCullMode>
{
static GfxCullMode f(CTX ctx,const SV head)
{
if(head->type!=S::ValueType::NativeObject)
CATE(TE,"Value can not be converted to GfxCullMode."));

NO obj=(NO)head;
if(obj->typeID!=EXT->GfxCullMode_typeID)
CATE(TE,"Value can not be converted to GfxCullMode."));
size_t v=size_t(obj->data);
if(v==0)return GfxCullNone;
if(v==2)return GfxCullBack;
if(v==1)return GfxCullFront;
}
};
template <>
struct type_same<GfxCullMode>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxCullMode_typeID;
else
 R false;
}
};void GfxWinding_destroy(CTX,NO) {}
SV GfxWinding_get_member(CTX,NO,SV);
void GfxWinding_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxWinding_funcs={
.destroy = GfxWinding_destroy,
.getMember = GfxWinding_get_member,
.setMember = GfxWinding_set_member
};
template <>
struct create_val<GfxWinding>
{
static SV f(CTX ctx,GfxWinding v)
{
R S::createNativeObject(GfxWinding_funcs,(void *)v,EXT->GfxWinding_typeID);
}
};
template <>
struct val_to_c<GfxWinding>
{
static GfxWinding f(CTX ctx,const SV head)
{
if(head->type!=S::ValueType::NativeObject)
CATE(TE,"Value can not be converted to GfxWinding."));

NO obj=(NO)head;
if(obj->typeID!=EXT->GfxWinding_typeID)
CATE(TE,"Value can not be converted to GfxWinding."));
size_t v=size_t(obj->data);
if(v==1)return GfxCCW;
if(v==0)return GfxCW;
}
};
template <>
struct type_same<GfxWinding>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxWinding_typeID;
else
 R false;
}
};void GfxVertexAttribPurpose_destroy(CTX,NO) {}
SV GfxVertexAttribPurpose_get_member(CTX,NO,SV);
void GfxVertexAttribPurpose_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxVertexAttribPurpose_funcs={
.destroy = GfxVertexAttribPurpose_destroy,
.getMember = GfxVertexAttribPurpose_get_member,
.setMember = GfxVertexAttribPurpose_set_member
};
template <>
struct create_val<GfxVertexAttribPurpose>
{
static SV f(CTX ctx,GfxVertexAttribPurpose v)
{
R S::createNativeObject(GfxVertexAttribPurpose_funcs,(void *)v,EXT->GfxVertexAttribPurpose_typeID);
}
};
template <>
struct val_to_c<GfxVertexAttribPurpose>
{
static GfxVertexAttribPurpose f(CTX ctx,const SV head)
{
if(head->type!=S::ValueType::NativeObject)
CATE(TE,"Value can not be converted to GfxVertexAttribPurpose."));

NO obj=(NO)head;
if(obj->typeID!=EXT->GfxVertexAttribPurpose_typeID)
CATE(TE,"Value can not be converted to GfxVertexAttribPurpose."));
size_t v=size_t(obj->data);
if(v==4)return GfxTexCoord;
if(v==2)return GfxTangent;
if(v==0)return GfxPosition;
if(v==1)return GfxNormal;
if(v==3)return GfxColor;
}
};
template <>
struct type_same<GfxVertexAttribPurpose>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxVertexAttribPurpose_typeID;
else
 R false;
}
};void GfxVertexAttribType_destroy(CTX,NO) {}
SV GfxVertexAttribType_get_member(CTX,NO,SV);
void GfxVertexAttribType_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxVertexAttribType_funcs={
.destroy = GfxVertexAttribType_destroy,
.getMember = GfxVertexAttribType_get_member,
.setMember = GfxVertexAttribType_set_member
};
template <>
struct create_val<GfxVertexAttribType>
{
static SV f(CTX ctx,GfxVertexAttribType v)
{
R S::createNativeObject(GfxVertexAttribType_funcs,(void *)v,EXT->GfxVertexAttribType_typeID);
}
};
template <>
struct val_to_c<GfxVertexAttribType>
{
static GfxVertexAttribType f(CTX ctx,const SV head)
{
if(head->type!=S::ValueType::NativeObject)
CATE(TE,"Value can not be converted to GfxVertexAttribType."));

NO obj=(NO)head;
if(obj->typeID!=EXT->GfxVertexAttribType_typeID)
CATE(TE,"Value can not be converted to GfxVertexAttribType."));
size_t v=size_t(obj->data);
if(v==8)return GfxUnsignedInteger;
if(v==10)return GfxNormalizedUnsignedByte;
if(v==1)return GfxFloat;
if(v==14)return GfxNormalizedUnsignedInteger;
if(v==5)return GfxShort;
if(v==7)return GfxInteger;
if(v==3)return GfxByte;
if(v==9)return GfxNormalizedByte;
if(v==6)return GfxUnsignedShort;
if(v==2)return GfxDouble;
if(v==0)return GfxHalfFloat;
if(v==11)return GfxNormalizedShort;
if(v==13)return GfxNormalizedInteger;
if(v==4)return GfxUnsignedByte;
if(v==12)return GfxNormalizedUnsignedShort;
}
};
template <>
struct type_same<GfxVertexAttribType>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxVertexAttribType_typeID;
else
 R false;
}
};void GfxStage_destroy(CTX,NO) {}
SV GfxStage_get_member(CTX,NO,SV);
void GfxStage_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxStage_funcs={
.destroy = GfxStage_destroy,
.getMember = GfxStage_get_member,
.setMember = GfxStage_set_member
};
template <>
struct create_val<GfxStage>
{
static SV f(CTX ctx,GfxStage v)
{
R S::createNativeObject(GfxStage_funcs,(void *)v,EXT->GfxStage_typeID);
}
};
template <>
struct val_to_c<GfxStage>
{
static GfxStage f(CTX ctx,const SV head)
{
if(head->type!=S::ValueType::NativeObject)
CATE(TE,"Value can not be converted to GfxStage."));

NO obj=(NO)head;
if(obj->typeID!=EXT->GfxStage_typeID)
CATE(TE,"Value can not be converted to GfxStage."));
size_t v=size_t(obj->data);
if(v==5)return GfxStage::Compute;
if(v==3)return GfxStage::Geometry;
if(v==0)return GfxStage::Vertex;
if(v==4)return GfxStage::Fragment;
if(v==1)return GfxStage::TessControl;
if(v==2)return GfxStage::TessEval;
}
};
template <>
struct type_same<GfxStage>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxStage_typeID;
else
 R false;
}
};void GfxBufferUsage_destroy(CTX,NO) {}
SV GfxBufferUsage_get_member(CTX,NO,SV);
void GfxBufferUsage_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxBufferUsage_funcs={
.destroy = GfxBufferUsage_destroy,
.getMember = GfxBufferUsage_get_member,
.setMember = GfxBufferUsage_set_member
};
template <>
struct create_val<GfxBufferUsage>
{
static SV f(CTX ctx,GfxBufferUsage v)
{
R S::createNativeObject(GfxBufferUsage_funcs,(void *)v,EXT->GfxBufferUsage_typeID);
}
};
template <>
struct val_to_c<GfxBufferUsage>
{
static GfxBufferUsage f(CTX ctx,const SV head)
{
if(head->type!=S::ValueType::NativeObject)
CATE(TE,"Value can not be converted to GfxBufferUsage."));

NO obj=(NO)head;
if(obj->typeID!=EXT->GfxBufferUsage_typeID)
CATE(TE,"Value can not be converted to GfxBufferUsage."));
size_t v=size_t(obj->data);
if(v==2)return GfxBufferUsage::Dynamic;
if(v==1)return GfxBufferUsage::Static;
if(v==0)return GfxBufferUsage::Stream;
}
};
template <>
struct type_same<GfxBufferUsage>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxBufferUsage_typeID;
else
 R false;
}
};void GfxShadowmapPrecision_destroy(CTX,NO) {}
SV GfxShadowmapPrecision_get_member(CTX,NO,SV);
void GfxShadowmapPrecision_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxShadowmapPrecision_funcs={
.destroy = GfxShadowmapPrecision_destroy,
.getMember = GfxShadowmapPrecision_get_member,
.setMember = GfxShadowmapPrecision_set_member
};
template <>
struct create_val<GfxShadowmapPrecision>
{
static SV f(CTX ctx,GfxShadowmapPrecision v)
{
R S::createNativeObject(GfxShadowmapPrecision_funcs,(void *)v,EXT->GfxShadowmapPrecision_typeID);
}
};
template <>
struct val_to_c<GfxShadowmapPrecision>
{
static GfxShadowmapPrecision f(CTX ctx,const SV head)
{
if(head->type!=S::ValueType::NativeObject)
CATE(TE,"Value can not be converted to GfxShadowmapPrecision."));

NO obj=(NO)head;
if(obj->typeID!=EXT->GfxShadowmapPrecision_typeID)
CATE(TE,"Value can not be converted to GfxShadowmapPrecision."));
size_t v=size_t(obj->data);
if(v==2)return GfxShadowmapPrecision::High;
if(v==1)return GfxShadowmapPrecision::Medium;
if(v==0)return GfxShadowmapPrecision::Low;
}
};
template <>
struct type_same<GfxShadowmapPrecision>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxShadowmapPrecision_typeID;
else
 R false;
}
};void GfxLightType_destroy(CTX,NO) {}
SV GfxLightType_get_member(CTX,NO,SV);
void GfxLightType_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxLightType_funcs={
.destroy = GfxLightType_destroy,
.getMember = GfxLightType_get_member,
.setMember = GfxLightType_set_member
};
template <>
struct create_val<GfxLightType>
{
static SV f(CTX ctx,GfxLightType v)
{
R S::createNativeObject(GfxLightType_funcs,(void *)v,EXT->GfxLightType_typeID);
}
};
template <>
struct val_to_c<GfxLightType>
{
static GfxLightType f(CTX ctx,const SV head)
{
if(head->type!=S::ValueType::NativeObject)
CATE(TE,"Value can not be converted to GfxLightType."));

NO obj=(NO)head;
if(obj->typeID!=EXT->GfxLightType_typeID)
CATE(TE,"Value can not be converted to GfxLightType."));
size_t v=size_t(obj->data);
if(v==2)return GfxLightType::Point;
if(v==1)return GfxLightType::Spot;
if(v==0)return GfxLightType::Directional;
}
};
template <>
struct type_same<GfxLightType>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxLightType_typeID;
else
 R false;
}
};void CameraType_destroy(CTX,NO) {}
SV CameraType_get_member(CTX,NO,SV);
void CameraType_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs CameraType_funcs={
.destroy = CameraType_destroy,
.getMember = CameraType_get_member,
.setMember = CameraType_set_member
};
template <>
struct create_val<CameraType>
{
static SV f(CTX ctx,CameraType v)
{
R S::createNativeObject(CameraType_funcs,(void *)v,EXT->CameraType_typeID);
}
};
template <>
struct val_to_c<CameraType>
{
static CameraType f(CTX ctx,const SV head)
{
if(head->type!=S::ValueType::NativeObject)
CATE(TE,"Value can not be converted to CameraType."));

NO obj=(NO)head;
if(obj->typeID!=EXT->CameraType_typeID)
CATE(TE,"Value can not be converted to CameraType."));
size_t v=size_t(obj->data);
if(v==0)return CameraType::Perspective;
if(v==1)return CameraType::Orthographic;
}
};
template <>
struct type_same<CameraType>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->CameraType_typeID;
else
 R false;
}
};void Filesystem_destroy(CTX,NO);
SV Filesystem_get_member(CTX,NO,SV);
void Filesystem_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Filesystem_funcs={
.destroy = Filesystem_destroy,
.getMember = Filesystem_get_member,
.setMember = Filesystem_set_member
};
template <>
struct create_val<Filesystem>
{
static SV f(CTX ctx,const Filesystem&obj)
{
#define ghfj Filesystem
R S::createNativeObject(Filesystem_funcs,NEW(ghfj, obj),EXT->Filesystem_typeID);
}
};
template <>
struct val_to_c<Filesystem>
{
static Filesystem f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Filesystem_typeID)
R*((Filesystem*)obj->data);
else
 CATE(TE,"Value can not be converted to Filesystem."));
} else
 CATE(TE,"Value can not be converted to Filesystem."));
}
};
template <>
struct type_same<Filesystem>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Filesystem_typeID;
else
 R false;
}
};

SV Filesystem_pushSearchPaths(CTX ctx,const List<SV>&a);
SV Filesystem_popSearchPaths(CTX ctx,const List<SV>&a);
SV Filesystem_addSearchPath(CTX ctx,const List<SV>&a);
SV Filesystem_getAbsolutePath(CTX ctx,const List<SV>&a);
void GfxCompiledShader_destroy(CTX,NO);
SV GfxCompiledShader_get_member(CTX,NO,SV);
void GfxCompiledShader_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxCompiledShader_funcs={
.destroy = GfxCompiledShader_destroy,
.getMember = GfxCompiledShader_get_member,
.setMember = GfxCompiledShader_set_member
};
template <>
struct type_same<GfxCompiledShader>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxCompiledShader_typeID;
else
 R false;
}
};

SV GfxCompiledShader_isInvalid(CTX ctx,const List<SV>&a);
SV GfxCompiledShader_getStage(CTX ctx,const List<SV>&a);
void UInt2_destroy(CTX,NO);
SV UInt2_get_member(CTX,NO,SV);
void UInt2_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs UInt2_funcs={
.destroy = UInt2_destroy,
.getMember = UInt2_get_member,
.setMember = UInt2_set_member
};
template <>
struct create_val<T2<uint32_t>>
{
static SV f(CTX ctx,const T2<uint32_t>&obj)
{
#define ghfj T2<uint32_t>
R S::createNativeObject(UInt2_funcs,NEW(ghfj, obj),EXT->UInt2_typeID);
}
};
template <>
struct val_to_c<T2<uint32_t>>
{
static T2<uint32_t> f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->UInt2_typeID)
R*((T2<uint32_t>*)obj->data);
else
 CATE(TE,"Value can not be converted to UInt2."));
} else
 CATE(TE,"Value can not be converted to UInt2."));
}
};
template <>
struct type_same<T2<uint32_t>>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->UInt2_typeID;
else
 R false;
}
};

SV UInt2___add__(CTX ctx,const List<SV>&a);
SV UInt2___sub__(CTX ctx,const List<SV>&a);
SV UInt2___mul__(CTX ctx,const List<SV>&a);
SV UInt2___div__(CTX ctx,const List<SV>&a);
SV UInt2___eq__(CTX ctx,const List<SV>&a);
SV UInt2___neq__(CTX ctx,const List<SV>&a);
SV UInt2___less__(CTX ctx,const List<SV>&a);
SV UInt2___grtr__(CTX ctx,const List<SV>&a);
SV UInt2___leq__(CTX ctx,const List<SV>&a);
SV UInt2___geq__(CTX ctx,const List<SV>&a);
SV UInt2_sum(CTX ctx,const List<SV>&a);
SV UInt2_length(CTX ctx,const List<SV>&a);
SV UInt2_lengthSquared(CTX ctx,const List<SV>&a);
SV UInt2_dot(CTX ctx,const List<SV>&a);
SV UInt2_distance(CTX ctx,const List<SV>&a);
SV UInt2_distanceSquared(CTX ctx,const List<SV>&a);
SV UInt2_normalize(CTX ctx,const List<SV>&a);
SV UInt2_getXY(CTX ctx,const List<SV>&a);
SV UInt2_setXY(CTX ctx,const List<SV>&a);
SV UInt2_getYX(CTX ctx,const List<SV>&a);
SV UInt2_setYX(CTX ctx,const List<SV>&a);
void GPUTimer_destroy(CTX,NO);
SV GPUTimer_get_member(CTX,NO,SV);
void GPUTimer_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GPUTimer_funcs={
.destroy = GPUTimer_destroy,
.getMember = GPUTimer_get_member,
.setMember = GPUTimer_set_member
};
template <>
struct type_same<GPUTimer>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GPUTimer_typeID;
else
 R false;
}
};

SV GPUTimer_resultAvailable(CTX ctx,const List<SV>&a);
SV GPUTimer_getResult(CTX ctx,const List<SV>&a);
SV GPUTimer_getResultResolution(CTX ctx,const List<SV>&a);
SV GPUTimer_begin(CTX ctx,const List<SV>&a);
SV GPUTimer_end(CTX ctx,const List<SV>&a);
void RigidBody_destroy(CTX,NO);
SV RigidBody_get_member(CTX,NO,SV);
void RigidBody_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs RigidBody_funcs={
.destroy = RigidBody_destroy,
.getMember = RigidBody_get_member,
.setMember = RigidBody_set_member
};
template <>
struct type_same<RigidBody>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->RigidBody_typeID;
else
 R false;
}
};

SV RigidBody_getBulletRigidBody(CTX ctx,const List<SV>&a);
SV RigidBody_getType(CTX ctx,const List<SV>&a);
SV RigidBody_getGravity(CTX ctx,const List<SV>&a);
SV RigidBody_setGravity(CTX ctx,const List<SV>&a);
SV RigidBody_setLinearDamping(CTX ctx,const List<SV>&a);
SV RigidBody_getLinearDamping(CTX ctx,const List<SV>&a);
SV RigidBody_setAngularDamping(CTX ctx,const List<SV>&a);
SV RigidBody_getAngularDamping(CTX ctx,const List<SV>&a);
SV RigidBody_setMass(CTX ctx,const List<SV>&a);
SV RigidBody_getMass(CTX ctx,const List<SV>&a);
SV RigidBody_getLinearSleepingThreshold(CTX ctx,const List<SV>&a);
SV RigidBody_setLinearSleepingThreshold(CTX ctx,const List<SV>&a);
SV RigidBody_getAngularSleepingThreshold(CTX ctx,const List<SV>&a);
SV RigidBody_setAngularSleepingThreshold(CTX ctx,const List<SV>&a);
SV RigidBody_applyTorque(CTX ctx,const List<SV>&a);
SV RigidBody_applyForce(CTX ctx,const List<SV>&a);
SV RigidBody_applyCentralImpulse(CTX ctx,const List<SV>&a);
SV RigidBody_applyTorqueImpulse(CTX ctx,const List<SV>&a);
SV RigidBody_applyImpulse(CTX ctx,const List<SV>&a);
SV RigidBody_clearForces(CTX ctx,const List<SV>&a);
SV RigidBody_getLinearVelocity(CTX ctx,const List<SV>&a);
SV RigidBody_setLinearVelocity(CTX ctx,const List<SV>&a);
SV RigidBody_getAngularVelocity(CTX ctx,const List<SV>&a);
SV RigidBody_setAngularVelocity(CTX ctx,const List<SV>&a);
SV RigidBody_getVelocityOfPoint(CTX ctx,const List<SV>&a);
SV RigidBody_getRestitution(CTX ctx,const List<SV>&a);
SV RigidBody_setRestitution(CTX ctx,const List<SV>&a);
SV RigidBody_getFriction(CTX ctx,const List<SV>&a);
SV RigidBody_setFriction(CTX ctx,const List<SV>&a);
SV RigidBody_getRollingFriction(CTX ctx,const List<SV>&a);
SV RigidBody_setRollingFriction(CTX ctx,const List<SV>&a);
SV RigidBody_getLinearFactor(CTX ctx,const List<SV>&a);
SV RigidBody_setLinearFactor(CTX ctx,const List<SV>&a);
SV RigidBody_getAngularFactor(CTX ctx,const List<SV>&a);
SV RigidBody_setAngularFactor(CTX ctx,const List<SV>&a);
SV RigidBody_setTransform(CTX ctx,const List<SV>&a);
SV RigidBody_getWorld(CTX ctx,const List<SV>&a);
SV RigidBody_getCollisionMask(CTX ctx,const List<SV>&a);
SV RigidBody_setShape(CTX ctx,const List<SV>&a);
SV RigidBody_getShape(CTX ctx,const List<SV>&a);
SV RigidBody_getEntity(CTX ctx,const List<SV>&a);
void Float2_destroy(CTX,NO);
SV Float2_get_member(CTX,NO,SV);
void Float2_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Float2_funcs={
.destroy = Float2_destroy,
.getMember = Float2_get_member,
.setMember = Float2_set_member
};
template <>
struct create_val<T2<float>>
{
static SV f(CTX ctx,const T2<float>&obj)
{
#define ghfj T2<float>
R S::createNativeObject(Float2_funcs,NEW(ghfj, obj),EXT->Float2_typeID);
}
};
template <>
struct val_to_c<T2<float>>
{
static T2<float> f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Float2_typeID)
R*((T2<float>*)obj->data);
else
 CATE(TE,"Value can not be converted to Float2."));
} else
 CATE(TE,"Value can not be converted to Float2."));
}
};
template <>
struct type_same<T2<float>>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Float2_typeID;
else
 R false;
}
};

SV Float2___add__(CTX ctx,const List<SV>&a);
SV Float2___sub__(CTX ctx,const List<SV>&a);
SV Float2___mul__(CTX ctx,const List<SV>&a);
SV Float2___div__(CTX ctx,const List<SV>&a);
SV Float2___eq__(CTX ctx,const List<SV>&a);
SV Float2___neq__(CTX ctx,const List<SV>&a);
SV Float2___less__(CTX ctx,const List<SV>&a);
SV Float2___grtr__(CTX ctx,const List<SV>&a);
SV Float2___leq__(CTX ctx,const List<SV>&a);
SV Float2___geq__(CTX ctx,const List<SV>&a);
SV Float2_sum(CTX ctx,const List<SV>&a);
SV Float2_length(CTX ctx,const List<SV>&a);
SV Float2_lengthSquared(CTX ctx,const List<SV>&a);
SV Float2_dot(CTX ctx,const List<SV>&a);
SV Float2_distance(CTX ctx,const List<SV>&a);
SV Float2_distanceSquared(CTX ctx,const List<SV>&a);
SV Float2_normalize(CTX ctx,const List<SV>&a);
SV Float2_getXY(CTX ctx,const List<SV>&a);
SV Float2_setXY(CTX ctx,const List<SV>&a);
SV Float2_getYX(CTX ctx,const List<SV>&a);
SV Float2_setYX(CTX ctx,const List<SV>&a);
void AudioSource_destroy(CTX,NO);
SV AudioSource_get_member(CTX,NO,SV);
void AudioSource_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs AudioSource_funcs={
.destroy = AudioSource_destroy,
.getMember = AudioSource_get_member,
.setMember = AudioSource_set_member
};
template <>
struct create_val<AudioSource>
{
static SV f(CTX ctx,const AudioSource&obj)
{
#define ghfj AudioSource
R S::createNativeObject(AudioSource_funcs,NEW(ghfj, obj),EXT->AudioSource_typeID);
}
};
template <>
struct val_to_c<AudioSource>
{
static AudioSource f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->AudioSource_typeID)
R*((AudioSource*)obj->data);
else
 CATE(TE,"Value can not be converted to AudioSource."));
} else
 CATE(TE,"Value can not be converted to AudioSource."));
}
};
template <>
struct type_same<AudioSource>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->AudioSource_typeID;
else
 R false;
}
};

SV AudioSource_getAudio(CTX ctx,const List<SV>&a);
SV AudioSource_setAudio(CTX ctx,const List<SV>&a);
void Camera_destroy(CTX,NO);
SV Camera_get_member(CTX,NO,SV);
void Camera_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Camera_funcs={
.destroy = Camera_destroy,
.getMember = Camera_get_member,
.setMember = Camera_set_member
};
template <>
struct create_val<Camera>
{
static SV f(CTX ctx,const Camera&obj)
{
#define ghfj Camera
R S::createNativeObject(Camera_funcs,NEW(ghfj, obj),EXT->Camera_typeID);
}
};
template <>
struct val_to_c<Camera>
{
static Camera f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Camera_typeID)
R*((Camera*)obj->data);
else
 CATE(TE,"Value can not be converted to Camera."));
} else
 CATE(TE,"Value can not be converted to Camera."));
}
};
template <>
struct type_same<Camera>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Camera_typeID;
else
 R false;
}
};

SV Camera_setType(CTX ctx,const List<SV>&a);
SV Camera_setPosition(CTX ctx,const List<SV>&a);
SV Camera_setDirection(CTX ctx,const List<SV>&a);
SV Camera_setUp(CTX ctx,const List<SV>&a);
SV Camera_setWidth(CTX ctx,const List<SV>&a);
SV Camera_setHeight(CTX ctx,const List<SV>&a);
SV Camera_setFieldOfView(CTX ctx,const List<SV>&a);
SV Camera_setLeft(CTX ctx,const List<SV>&a);
SV Camera_setRight(CTX ctx,const List<SV>&a);
SV Camera_setBottom(CTX ctx,const List<SV>&a);
SV Camera_setTop(CTX ctx,const List<SV>&a);
SV Camera_setNear(CTX ctx,const List<SV>&a);
SV Camera_setFar(CTX ctx,const List<SV>&a);
SV Camera_getType(CTX ctx,const List<SV>&a);
SV Camera_getPosition(CTX ctx,const List<SV>&a);
SV Camera_getDirection(CTX ctx,const List<SV>&a);
SV Camera_getUp(CTX ctx,const List<SV>&a);
SV Camera_getWidth(CTX ctx,const List<SV>&a);
SV Camera_getHeight(CTX ctx,const List<SV>&a);
SV Camera_getFieldOfView(CTX ctx,const List<SV>&a);
SV Camera_getLeft(CTX ctx,const List<SV>&a);
SV Camera_getRight(CTX ctx,const List<SV>&a);
SV Camera_getBottom(CTX ctx,const List<SV>&a);
SV Camera_getTop(CTX ctx,const List<SV>&a);
SV Camera_getNear(CTX ctx,const List<SV>&a);
SV Camera_getFar(CTX ctx,const List<SV>&a);
SV Camera_getViewMatrix(CTX ctx,const List<SV>&a);
SV Camera_getProjectionMatrix(CTX ctx,const List<SV>&a);
void Resource_destroy(CTX,NO);
SV Resource_get_member(CTX,NO,SV);
void Resource_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Resource_funcs={
.destroy = Resource_destroy,
.getMember = Resource_get_member,
.setMember = Resource_set_member
};
template <>
struct type_same<Resource>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Resource_typeID;
else
 R false;
}
};

SV Resource_removeContent(CTX ctx,const List<SV>&a);
SV Resource_load(CTX ctx,const List<SV>&a);
SV Resource_reload(CTX ctx,const List<SV>&a);
SV Resource_save(CTX ctx,const List<SV>&a);
SV Resource_copy(CTX ctx,const List<SV>&a);
SV Resource_getType(CTX ctx,const List<SV>&a);
SV Resource_isLoaded(CTX ctx,const List<SV>&a);
SV Resource_getLastFileModification(CTX ctx,const List<SV>&a);
SV Resource_shouldReload(CTX ctx,const List<SV>&a);
SV Resource_possiblyReload(CTX ctx,const List<SV>&a);
SV Resource_release(CTX ctx,const List<SV>&a);
SV Resource_getRefCount(CTX ctx,const List<SV>&a);
SV Resource_getFilename(CTX ctx,const List<SV>&a);
SV Resource_setFilename(CTX ctx,const List<SV>&a);
void GfxShader_destroy(CTX,NO);
SV GfxShader_get_member(CTX,NO,SV);
void GfxShader_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxShader_funcs={
.destroy = GfxShader_destroy,
.getMember = GfxShader_get_member,
.setMember = GfxShader_set_member
};
template <>
struct type_same<GfxShader>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxShader_typeID;
else
 R false;
}
};

SV GfxShader_removeContent(CTX ctx,const List<SV>&a);
SV GfxShader_save(CTX ctx,const List<SV>&a);
SV GfxShader_setSource(CTX ctx,const List<SV>&a);
SV GfxShader_getSource(CTX ctx,const List<SV>&a);
SV GfxShader_getCompiled(CTX ctx,const List<SV>&a);
SV GfxShader_recompile(CTX ctx,const List<SV>&a);
SV GfxShader_getStage(CTX ctx,const List<SV>&a);
SV GfxShader_getImpl(CTX ctx,const List<SV>&a);
SV GfxShader_possiblyReload(CTX ctx,const List<SV>&a);
SV GfxShader_load(CTX ctx,const List<SV>&a);
SV GfxShader_reload(CTX ctx,const List<SV>&a);
SV GfxShader_copy(CTX ctx,const List<SV>&a);
SV GfxShader_getType(CTX ctx,const List<SV>&a);
SV GfxShader_isLoaded(CTX ctx,const List<SV>&a);
SV GfxShader_getLastFileModification(CTX ctx,const List<SV>&a);
SV GfxShader_shouldReload(CTX ctx,const List<SV>&a);
SV GfxShader_release(CTX ctx,const List<SV>&a);
SV GfxShader_getRefCount(CTX ctx,const List<SV>&a);
SV GfxShader_getFilename(CTX ctx,const List<SV>&a);
SV GfxShader_setFilename(CTX ctx,const List<SV>&a);
void UInt4_destroy(CTX,NO);
SV UInt4_get_member(CTX,NO,SV);
void UInt4_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs UInt4_funcs={
.destroy = UInt4_destroy,
.getMember = UInt4_get_member,
.setMember = UInt4_set_member
};
template <>
struct create_val<T4<uint32_t>>
{
static SV f(CTX ctx,const T4<uint32_t>&obj)
{
#define ghfj T4<uint32_t>
R S::createNativeObject(UInt4_funcs,NEW(ghfj, obj),EXT->UInt4_typeID);
}
};
template <>
struct val_to_c<T4<uint32_t>>
{
static T4<uint32_t> f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->UInt4_typeID)
R*((T4<uint32_t>*)obj->data);
else
 CATE(TE,"Value can not be converted to UInt4."));
} else
 CATE(TE,"Value can not be converted to UInt4."));
}
};
template <>
struct type_same<T4<uint32_t>>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->UInt4_typeID;
else
 R false;
}
};

SV UInt4___add__(CTX ctx,const List<SV>&a);
SV UInt4___sub__(CTX ctx,const List<SV>&a);
SV UInt4___mul__(CTX ctx,const List<SV>&a);
SV UInt4___div__(CTX ctx,const List<SV>&a);
SV UInt4___eq__(CTX ctx,const List<SV>&a);
SV UInt4___neq__(CTX ctx,const List<SV>&a);
SV UInt4___less__(CTX ctx,const List<SV>&a);
SV UInt4___grtr__(CTX ctx,const List<SV>&a);
SV UInt4___leq__(CTX ctx,const List<SV>&a);
SV UInt4___geq__(CTX ctx,const List<SV>&a);
SV UInt4_sum(CTX ctx,const List<SV>&a);
SV UInt4_length(CTX ctx,const List<SV>&a);
SV UInt4_lengthSquared(CTX ctx,const List<SV>&a);
SV UInt4_dot(CTX ctx,const List<SV>&a);
SV UInt4_distance(CTX ctx,const List<SV>&a);
SV UInt4_distanceSquared(CTX ctx,const List<SV>&a);
SV UInt4_normalize(CTX ctx,const List<SV>&a);
SV UInt4_getXY(CTX ctx,const List<SV>&a);
SV UInt4_setXY(CTX ctx,const List<SV>&a);
SV UInt4_getXZ(CTX ctx,const List<SV>&a);
SV UInt4_setXZ(CTX ctx,const List<SV>&a);
SV UInt4_getXW(CTX ctx,const List<SV>&a);
SV UInt4_setXW(CTX ctx,const List<SV>&a);
SV UInt4_getYX(CTX ctx,const List<SV>&a);
SV UInt4_setYX(CTX ctx,const List<SV>&a);
SV UInt4_getYZ(CTX ctx,const List<SV>&a);
SV UInt4_setYZ(CTX ctx,const List<SV>&a);
SV UInt4_getYW(CTX ctx,const List<SV>&a);
SV UInt4_setYW(CTX ctx,const List<SV>&a);
SV UInt4_getZX(CTX ctx,const List<SV>&a);
SV UInt4_setZX(CTX ctx,const List<SV>&a);
SV UInt4_getZY(CTX ctx,const List<SV>&a);
SV UInt4_setZY(CTX ctx,const List<SV>&a);
SV UInt4_getZW(CTX ctx,const List<SV>&a);
SV UInt4_setZW(CTX ctx,const List<SV>&a);
SV UInt4_getWX(CTX ctx,const List<SV>&a);
SV UInt4_setWX(CTX ctx,const List<SV>&a);
SV UInt4_getWY(CTX ctx,const List<SV>&a);
SV UInt4_setWY(CTX ctx,const List<SV>&a);
SV UInt4_getWZ(CTX ctx,const List<SV>&a);
SV UInt4_setWZ(CTX ctx,const List<SV>&a);
SV UInt4_getXYZ(CTX ctx,const List<SV>&a);
SV UInt4_setXYZ(CTX ctx,const List<SV>&a);
SV UInt4_getXYW(CTX ctx,const List<SV>&a);
SV UInt4_setXYW(CTX ctx,const List<SV>&a);
SV UInt4_getXZY(CTX ctx,const List<SV>&a);
SV UInt4_setXZY(CTX ctx,const List<SV>&a);
SV UInt4_getXZW(CTX ctx,const List<SV>&a);
SV UInt4_setXZW(CTX ctx,const List<SV>&a);
SV UInt4_getXWZ(CTX ctx,const List<SV>&a);
SV UInt4_setXWZ(CTX ctx,const List<SV>&a);
SV UInt4_getXWY(CTX ctx,const List<SV>&a);
SV UInt4_setXWY(CTX ctx,const List<SV>&a);
SV UInt4_getYXZ(CTX ctx,const List<SV>&a);
SV UInt4_setYXZ(CTX ctx,const List<SV>&a);
SV UInt4_getYXW(CTX ctx,const List<SV>&a);
SV UInt4_setYXW(CTX ctx,const List<SV>&a);
SV UInt4_getYZX(CTX ctx,const List<SV>&a);
SV UInt4_setYZX(CTX ctx,const List<SV>&a);
SV UInt4_getYZW(CTX ctx,const List<SV>&a);
SV UInt4_setYZW(CTX ctx,const List<SV>&a);
SV UInt4_getYWZ(CTX ctx,const List<SV>&a);
SV UInt4_setYWZ(CTX ctx,const List<SV>&a);
SV UInt4_getYWX(CTX ctx,const List<SV>&a);
SV UInt4_setYWX(CTX ctx,const List<SV>&a);
SV UInt4_getZXY(CTX ctx,const List<SV>&a);
SV UInt4_setZXY(CTX ctx,const List<SV>&a);
SV UInt4_getZXW(CTX ctx,const List<SV>&a);
SV UInt4_setZXW(CTX ctx,const List<SV>&a);
SV UInt4_getZYX(CTX ctx,const List<SV>&a);
SV UInt4_setZYX(CTX ctx,const List<SV>&a);
SV UInt4_getZYW(CTX ctx,const List<SV>&a);
SV UInt4_setZYW(CTX ctx,const List<SV>&a);
SV UInt4_getZWY(CTX ctx,const List<SV>&a);
SV UInt4_setZWY(CTX ctx,const List<SV>&a);
SV UInt4_getZWX(CTX ctx,const List<SV>&a);
SV UInt4_setZWX(CTX ctx,const List<SV>&a);
SV UInt4_getWXY(CTX ctx,const List<SV>&a);
SV UInt4_setWXY(CTX ctx,const List<SV>&a);
SV UInt4_getWXZ(CTX ctx,const List<SV>&a);
SV UInt4_setWXZ(CTX ctx,const List<SV>&a);
SV UInt4_getWYX(CTX ctx,const List<SV>&a);
SV UInt4_setWYX(CTX ctx,const List<SV>&a);
SV UInt4_getWYZ(CTX ctx,const List<SV>&a);
SV UInt4_setWYZ(CTX ctx,const List<SV>&a);
SV UInt4_getWZY(CTX ctx,const List<SV>&a);
SV UInt4_setWZY(CTX ctx,const List<SV>&a);
SV UInt4_getWZX(CTX ctx,const List<SV>&a);
SV UInt4_setWZX(CTX ctx,const List<SV>&a);
SV UInt4_getXYZW(CTX ctx,const List<SV>&a);
SV UInt4_setXYZW(CTX ctx,const List<SV>&a);
SV UInt4_getXYWZ(CTX ctx,const List<SV>&a);
SV UInt4_setXYWZ(CTX ctx,const List<SV>&a);
SV UInt4_getXZYW(CTX ctx,const List<SV>&a);
SV UInt4_setXZYW(CTX ctx,const List<SV>&a);
SV UInt4_getXZWY(CTX ctx,const List<SV>&a);
SV UInt4_setXZWY(CTX ctx,const List<SV>&a);
SV UInt4_getXWZY(CTX ctx,const List<SV>&a);
SV UInt4_setXWZY(CTX ctx,const List<SV>&a);
SV UInt4_getXWYZ(CTX ctx,const List<SV>&a);
SV UInt4_setXWYZ(CTX ctx,const List<SV>&a);
SV UInt4_getYXZW(CTX ctx,const List<SV>&a);
SV UInt4_setYXZW(CTX ctx,const List<SV>&a);
SV UInt4_getYXWZ(CTX ctx,const List<SV>&a);
SV UInt4_setYXWZ(CTX ctx,const List<SV>&a);
SV UInt4_getYZXW(CTX ctx,const List<SV>&a);
SV UInt4_setYZXW(CTX ctx,const List<SV>&a);
SV UInt4_getYZWX(CTX ctx,const List<SV>&a);
SV UInt4_setYZWX(CTX ctx,const List<SV>&a);
SV UInt4_getYWZX(CTX ctx,const List<SV>&a);
SV UInt4_setYWZX(CTX ctx,const List<SV>&a);
SV UInt4_getYWXZ(CTX ctx,const List<SV>&a);
SV UInt4_setYWXZ(CTX ctx,const List<SV>&a);
SV UInt4_getZYXW(CTX ctx,const List<SV>&a);
SV UInt4_setZYXW(CTX ctx,const List<SV>&a);
SV UInt4_getZYWX(CTX ctx,const List<SV>&a);
SV UInt4_setZYWX(CTX ctx,const List<SV>&a);
SV UInt4_getZXYW(CTX ctx,const List<SV>&a);
SV UInt4_setZXYW(CTX ctx,const List<SV>&a);
SV UInt4_getZXWY(CTX ctx,const List<SV>&a);
SV UInt4_setZXWY(CTX ctx,const List<SV>&a);
SV UInt4_getZWXY(CTX ctx,const List<SV>&a);
SV UInt4_setZWXY(CTX ctx,const List<SV>&a);
SV UInt4_getZWYX(CTX ctx,const List<SV>&a);
SV UInt4_setZWYX(CTX ctx,const List<SV>&a);
SV UInt4_getWYZX(CTX ctx,const List<SV>&a);
SV UInt4_setWYZX(CTX ctx,const List<SV>&a);
SV UInt4_getWYXZ(CTX ctx,const List<SV>&a);
SV UInt4_setWYXZ(CTX ctx,const List<SV>&a);
SV UInt4_getWZYX(CTX ctx,const List<SV>&a);
SV UInt4_setWZYX(CTX ctx,const List<SV>&a);
SV UInt4_getWZXY(CTX ctx,const List<SV>&a);
SV UInt4_setWZXY(CTX ctx,const List<SV>&a);
SV UInt4_getWXZY(CTX ctx,const List<SV>&a);
SV UInt4_setWXZY(CTX ctx,const List<SV>&a);
SV UInt4_getWXYZ(CTX ctx,const List<SV>&a);
SV UInt4_setWXYZ(CTX ctx,const List<SV>&a);
void Int3_destroy(CTX,NO);
SV Int3_get_member(CTX,NO,SV);
void Int3_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Int3_funcs={
.destroy = Int3_destroy,
.getMember = Int3_get_member,
.setMember = Int3_set_member
};
template <>
struct create_val<T3<int32_t>>
{
static SV f(CTX ctx,const T3<int32_t>&obj)
{
#define ghfj T3<int32_t>
R S::createNativeObject(Int3_funcs,NEW(ghfj, obj),EXT->Int3_typeID);
}
};
template <>
struct val_to_c<T3<int32_t>>
{
static T3<int32_t> f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Int3_typeID)
R*((T3<int32_t>*)obj->data);
else
 CATE(TE,"Value can not be converted to Int3."));
} else
 CATE(TE,"Value can not be converted to Int3."));
}
};
template <>
struct type_same<T3<int32_t>>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Int3_typeID;
else
 R false;
}
};

SV Int3___add__(CTX ctx,const List<SV>&a);
SV Int3___sub__(CTX ctx,const List<SV>&a);
SV Int3___mul__(CTX ctx,const List<SV>&a);
SV Int3___div__(CTX ctx,const List<SV>&a);
SV Int3___eq__(CTX ctx,const List<SV>&a);
SV Int3___neq__(CTX ctx,const List<SV>&a);
SV Int3___less__(CTX ctx,const List<SV>&a);
SV Int3___grtr__(CTX ctx,const List<SV>&a);
SV Int3___leq__(CTX ctx,const List<SV>&a);
SV Int3___geq__(CTX ctx,const List<SV>&a);
SV Int3_sum(CTX ctx,const List<SV>&a);
SV Int3_length(CTX ctx,const List<SV>&a);
SV Int3_lengthSquared(CTX ctx,const List<SV>&a);
SV Int3_dot(CTX ctx,const List<SV>&a);
SV Int3_distance(CTX ctx,const List<SV>&a);
SV Int3_distanceSquared(CTX ctx,const List<SV>&a);
SV Int3_normalize(CTX ctx,const List<SV>&a);
SV Int3_cross(CTX ctx,const List<SV>&a);
SV Int3_getXY(CTX ctx,const List<SV>&a);
SV Int3_setXY(CTX ctx,const List<SV>&a);
SV Int3_getXZ(CTX ctx,const List<SV>&a);
SV Int3_setXZ(CTX ctx,const List<SV>&a);
SV Int3_getYX(CTX ctx,const List<SV>&a);
SV Int3_setYX(CTX ctx,const List<SV>&a);
SV Int3_getYZ(CTX ctx,const List<SV>&a);
SV Int3_setYZ(CTX ctx,const List<SV>&a);
SV Int3_getZX(CTX ctx,const List<SV>&a);
SV Int3_setZX(CTX ctx,const List<SV>&a);
SV Int3_getZY(CTX ctx,const List<SV>&a);
SV Int3_setZY(CTX ctx,const List<SV>&a);
SV Int3_getXYZ(CTX ctx,const List<SV>&a);
SV Int3_setXYZ(CTX ctx,const List<SV>&a);
SV Int3_getXZY(CTX ctx,const List<SV>&a);
SV Int3_setXZY(CTX ctx,const List<SV>&a);
SV Int3_getYXZ(CTX ctx,const List<SV>&a);
SV Int3_setYXZ(CTX ctx,const List<SV>&a);
SV Int3_getYZX(CTX ctx,const List<SV>&a);
SV Int3_setYZX(CTX ctx,const List<SV>&a);
SV Int3_getZXY(CTX ctx,const List<SV>&a);
SV Int3_setZXY(CTX ctx,const List<SV>&a);
SV Int3_getZYX(CTX ctx,const List<SV>&a);
SV Int3_setZYX(CTX ctx,const List<SV>&a);
void ResizableData_destroy(CTX,NO);
SV ResizableData_get_member(CTX,NO,SV);
void ResizableData_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs ResizableData_funcs={
.destroy = ResizableData_destroy,
.getMember = ResizableData_get_member,
.setMember = ResizableData_set_member
};
template <>
struct create_val<ResizableData>
{
static SV f(CTX ctx,const ResizableData&obj)
{
#define ghfj ResizableData
R S::createNativeObject(ResizableData_funcs,NEW(ghfj, obj),EXT->ResizableData_typeID);
}
};
template <>
struct val_to_c<ResizableData>
{
static ResizableData f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->ResizableData_typeID)
R*((ResizableData*)obj->data);
else
 CATE(TE,"Value can not be converted to ResizableData."));
} else
 CATE(TE,"Value can not be converted to ResizableData."));
}
};
template <>
struct type_same<ResizableData>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->ResizableData_typeID;
else
 R false;
}
};

SV ResizableData___eq__(CTX ctx,const List<SV>&a);
SV ResizableData___neq__(CTX ctx,const List<SV>&a);
SV ResizableData_getData(CTX ctx,const List<SV>&a);
SV ResizableData_getSize(CTX ctx,const List<SV>&a);
SV ResizableData_resize(CTX ctx,const List<SV>&a);
SV ResizableData_insert(CTX ctx,const List<SV>&a);
SV ResizableData_append(CTX ctx,const List<SV>&a);
SV ResizableData_remove(CTX ctx,const List<SV>&a);
SV ResizableData_clear(CTX ctx,const List<SV>&a);
SV ResizableData_copy(CTX ctx,const List<SV>&a);
SV ResizableData_getUInt8(CTX ctx,const List<SV>&a);
SV ResizableData_getInt8(CTX ctx,const List<SV>&a);
SV ResizableData_getUInt16(CTX ctx,const List<SV>&a);
SV ResizableData_getInt16(CTX ctx,const List<SV>&a);
SV ResizableData_getUInt32(CTX ctx,const List<SV>&a);
SV ResizableData_getInt32(CTX ctx,const List<SV>&a);
SV ResizableData_getUInt64(CTX ctx,const List<SV>&a);
SV ResizableData_getInt64(CTX ctx,const List<SV>&a);
SV ResizableData_getUInt16LE(CTX ctx,const List<SV>&a);
SV ResizableData_getInt16LE(CTX ctx,const List<SV>&a);
SV ResizableData_getUInt32LE(CTX ctx,const List<SV>&a);
SV ResizableData_getInt32LE(CTX ctx,const List<SV>&a);
SV ResizableData_getUInt64LE(CTX ctx,const List<SV>&a);
SV ResizableData_getInt64LE(CTX ctx,const List<SV>&a);
SV ResizableData_getUInt16BE(CTX ctx,const List<SV>&a);
SV ResizableData_getInt16BE(CTX ctx,const List<SV>&a);
SV ResizableData_getUInt32BE(CTX ctx,const List<SV>&a);
SV ResizableData_getInt32BE(CTX ctx,const List<SV>&a);
SV ResizableData_getUInt64BE(CTX ctx,const List<SV>&a);
SV ResizableData_getInt64BE(CTX ctx,const List<SV>&a);
SV ResizableData_setUInt8(CTX ctx,const List<SV>&a);
SV ResizableData_setInt8(CTX ctx,const List<SV>&a);
SV ResizableData_setUInt16(CTX ctx,const List<SV>&a);
SV ResizableData_setInt16(CTX ctx,const List<SV>&a);
SV ResizableData_setUInt32(CTX ctx,const List<SV>&a);
SV ResizableData_setInt32(CTX ctx,const List<SV>&a);
SV ResizableData_setUInt64(CTX ctx,const List<SV>&a);
SV ResizableData_setInt64(CTX ctx,const List<SV>&a);
SV ResizableData_setUInt16LE(CTX ctx,const List<SV>&a);
SV ResizableData_setInt16LE(CTX ctx,const List<SV>&a);
SV ResizableData_setUInt32LE(CTX ctx,const List<SV>&a);
SV ResizableData_setInt32LE(CTX ctx,const List<SV>&a);
SV ResizableData_setUInt64LE(CTX ctx,const List<SV>&a);
SV ResizableData_setInt64LE(CTX ctx,const List<SV>&a);
SV ResizableData_setUInt16BE(CTX ctx,const List<SV>&a);
SV ResizableData_setInt16BE(CTX ctx,const List<SV>&a);
SV ResizableData_setUInt32BE(CTX ctx,const List<SV>&a);
SV ResizableData_setInt32BE(CTX ctx,const List<SV>&a);
SV ResizableData_setUInt64BE(CTX ctx,const List<SV>&a);
SV ResizableData_setInt64BE(CTX ctx,const List<SV>&a);
SV ResizableData_getChar(CTX ctx,const List<SV>&a);
SV ResizableData_setChar(CTX ctx,const List<SV>&a);
void Int4_destroy(CTX,NO);
SV Int4_get_member(CTX,NO,SV);
void Int4_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Int4_funcs={
.destroy = Int4_destroy,
.getMember = Int4_get_member,
.setMember = Int4_set_member
};
template <>
struct create_val<T4<int32_t>>
{
static SV f(CTX ctx,const T4<int32_t>&obj)
{
#define ghfj T4<int32_t>
R S::createNativeObject(Int4_funcs,NEW(ghfj, obj),EXT->Int4_typeID);
}
};
template <>
struct val_to_c<T4<int32_t>>
{
static T4<int32_t> f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Int4_typeID)
R*((T4<int32_t>*)obj->data);
else
 CATE(TE,"Value can not be converted to Int4."));
} else
 CATE(TE,"Value can not be converted to Int4."));
}
};
template <>
struct type_same<T4<int32_t>>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Int4_typeID;
else
 R false;
}
};

SV Int4___add__(CTX ctx,const List<SV>&a);
SV Int4___sub__(CTX ctx,const List<SV>&a);
SV Int4___mul__(CTX ctx,const List<SV>&a);
SV Int4___div__(CTX ctx,const List<SV>&a);
SV Int4___eq__(CTX ctx,const List<SV>&a);
SV Int4___neq__(CTX ctx,const List<SV>&a);
SV Int4___less__(CTX ctx,const List<SV>&a);
SV Int4___grtr__(CTX ctx,const List<SV>&a);
SV Int4___leq__(CTX ctx,const List<SV>&a);
SV Int4___geq__(CTX ctx,const List<SV>&a);
SV Int4_sum(CTX ctx,const List<SV>&a);
SV Int4_length(CTX ctx,const List<SV>&a);
SV Int4_lengthSquared(CTX ctx,const List<SV>&a);
SV Int4_dot(CTX ctx,const List<SV>&a);
SV Int4_distance(CTX ctx,const List<SV>&a);
SV Int4_distanceSquared(CTX ctx,const List<SV>&a);
SV Int4_normalize(CTX ctx,const List<SV>&a);
SV Int4_getXY(CTX ctx,const List<SV>&a);
SV Int4_setXY(CTX ctx,const List<SV>&a);
SV Int4_getXZ(CTX ctx,const List<SV>&a);
SV Int4_setXZ(CTX ctx,const List<SV>&a);
SV Int4_getXW(CTX ctx,const List<SV>&a);
SV Int4_setXW(CTX ctx,const List<SV>&a);
SV Int4_getYX(CTX ctx,const List<SV>&a);
SV Int4_setYX(CTX ctx,const List<SV>&a);
SV Int4_getYZ(CTX ctx,const List<SV>&a);
SV Int4_setYZ(CTX ctx,const List<SV>&a);
SV Int4_getYW(CTX ctx,const List<SV>&a);
SV Int4_setYW(CTX ctx,const List<SV>&a);
SV Int4_getZX(CTX ctx,const List<SV>&a);
SV Int4_setZX(CTX ctx,const List<SV>&a);
SV Int4_getZY(CTX ctx,const List<SV>&a);
SV Int4_setZY(CTX ctx,const List<SV>&a);
SV Int4_getZW(CTX ctx,const List<SV>&a);
SV Int4_setZW(CTX ctx,const List<SV>&a);
SV Int4_getWX(CTX ctx,const List<SV>&a);
SV Int4_setWX(CTX ctx,const List<SV>&a);
SV Int4_getWY(CTX ctx,const List<SV>&a);
SV Int4_setWY(CTX ctx,const List<SV>&a);
SV Int4_getWZ(CTX ctx,const List<SV>&a);
SV Int4_setWZ(CTX ctx,const List<SV>&a);
SV Int4_getXYZ(CTX ctx,const List<SV>&a);
SV Int4_setXYZ(CTX ctx,const List<SV>&a);
SV Int4_getXYW(CTX ctx,const List<SV>&a);
SV Int4_setXYW(CTX ctx,const List<SV>&a);
SV Int4_getXZY(CTX ctx,const List<SV>&a);
SV Int4_setXZY(CTX ctx,const List<SV>&a);
SV Int4_getXZW(CTX ctx,const List<SV>&a);
SV Int4_setXZW(CTX ctx,const List<SV>&a);
SV Int4_getXWZ(CTX ctx,const List<SV>&a);
SV Int4_setXWZ(CTX ctx,const List<SV>&a);
SV Int4_getXWY(CTX ctx,const List<SV>&a);
SV Int4_setXWY(CTX ctx,const List<SV>&a);
SV Int4_getYXZ(CTX ctx,const List<SV>&a);
SV Int4_setYXZ(CTX ctx,const List<SV>&a);
SV Int4_getYXW(CTX ctx,const List<SV>&a);
SV Int4_setYXW(CTX ctx,const List<SV>&a);
SV Int4_getYZX(CTX ctx,const List<SV>&a);
SV Int4_setYZX(CTX ctx,const List<SV>&a);
SV Int4_getYZW(CTX ctx,const List<SV>&a);
SV Int4_setYZW(CTX ctx,const List<SV>&a);
SV Int4_getYWZ(CTX ctx,const List<SV>&a);
SV Int4_setYWZ(CTX ctx,const List<SV>&a);
SV Int4_getYWX(CTX ctx,const List<SV>&a);
SV Int4_setYWX(CTX ctx,const List<SV>&a);
SV Int4_getZXY(CTX ctx,const List<SV>&a);
SV Int4_setZXY(CTX ctx,const List<SV>&a);
SV Int4_getZXW(CTX ctx,const List<SV>&a);
SV Int4_setZXW(CTX ctx,const List<SV>&a);
SV Int4_getZYX(CTX ctx,const List<SV>&a);
SV Int4_setZYX(CTX ctx,const List<SV>&a);
SV Int4_getZYW(CTX ctx,const List<SV>&a);
SV Int4_setZYW(CTX ctx,const List<SV>&a);
SV Int4_getZWY(CTX ctx,const List<SV>&a);
SV Int4_setZWY(CTX ctx,const List<SV>&a);
SV Int4_getZWX(CTX ctx,const List<SV>&a);
SV Int4_setZWX(CTX ctx,const List<SV>&a);
SV Int4_getWXY(CTX ctx,const List<SV>&a);
SV Int4_setWXY(CTX ctx,const List<SV>&a);
SV Int4_getWXZ(CTX ctx,const List<SV>&a);
SV Int4_setWXZ(CTX ctx,const List<SV>&a);
SV Int4_getWYX(CTX ctx,const List<SV>&a);
SV Int4_setWYX(CTX ctx,const List<SV>&a);
SV Int4_getWYZ(CTX ctx,const List<SV>&a);
SV Int4_setWYZ(CTX ctx,const List<SV>&a);
SV Int4_getWZY(CTX ctx,const List<SV>&a);
SV Int4_setWZY(CTX ctx,const List<SV>&a);
SV Int4_getWZX(CTX ctx,const List<SV>&a);
SV Int4_setWZX(CTX ctx,const List<SV>&a);
SV Int4_getXYZW(CTX ctx,const List<SV>&a);
SV Int4_setXYZW(CTX ctx,const List<SV>&a);
SV Int4_getXYWZ(CTX ctx,const List<SV>&a);
SV Int4_setXYWZ(CTX ctx,const List<SV>&a);
SV Int4_getXZYW(CTX ctx,const List<SV>&a);
SV Int4_setXZYW(CTX ctx,const List<SV>&a);
SV Int4_getXZWY(CTX ctx,const List<SV>&a);
SV Int4_setXZWY(CTX ctx,const List<SV>&a);
SV Int4_getXWZY(CTX ctx,const List<SV>&a);
SV Int4_setXWZY(CTX ctx,const List<SV>&a);
SV Int4_getXWYZ(CTX ctx,const List<SV>&a);
SV Int4_setXWYZ(CTX ctx,const List<SV>&a);
SV Int4_getYXZW(CTX ctx,const List<SV>&a);
SV Int4_setYXZW(CTX ctx,const List<SV>&a);
SV Int4_getYXWZ(CTX ctx,const List<SV>&a);
SV Int4_setYXWZ(CTX ctx,const List<SV>&a);
SV Int4_getYZXW(CTX ctx,const List<SV>&a);
SV Int4_setYZXW(CTX ctx,const List<SV>&a);
SV Int4_getYZWX(CTX ctx,const List<SV>&a);
SV Int4_setYZWX(CTX ctx,const List<SV>&a);
SV Int4_getYWZX(CTX ctx,const List<SV>&a);
SV Int4_setYWZX(CTX ctx,const List<SV>&a);
SV Int4_getYWXZ(CTX ctx,const List<SV>&a);
SV Int4_setYWXZ(CTX ctx,const List<SV>&a);
SV Int4_getZYXW(CTX ctx,const List<SV>&a);
SV Int4_setZYXW(CTX ctx,const List<SV>&a);
SV Int4_getZYWX(CTX ctx,const List<SV>&a);
SV Int4_setZYWX(CTX ctx,const List<SV>&a);
SV Int4_getZXYW(CTX ctx,const List<SV>&a);
SV Int4_setZXYW(CTX ctx,const List<SV>&a);
SV Int4_getZXWY(CTX ctx,const List<SV>&a);
SV Int4_setZXWY(CTX ctx,const List<SV>&a);
SV Int4_getZWXY(CTX ctx,const List<SV>&a);
SV Int4_setZWXY(CTX ctx,const List<SV>&a);
SV Int4_getZWYX(CTX ctx,const List<SV>&a);
SV Int4_setZWYX(CTX ctx,const List<SV>&a);
SV Int4_getWYZX(CTX ctx,const List<SV>&a);
SV Int4_setWYZX(CTX ctx,const List<SV>&a);
SV Int4_getWYXZ(CTX ctx,const List<SV>&a);
SV Int4_setWYXZ(CTX ctx,const List<SV>&a);
SV Int4_getWZYX(CTX ctx,const List<SV>&a);
SV Int4_setWZYX(CTX ctx,const List<SV>&a);
SV Int4_getWZXY(CTX ctx,const List<SV>&a);
SV Int4_setWZXY(CTX ctx,const List<SV>&a);
SV Int4_getWXZY(CTX ctx,const List<SV>&a);
SV Int4_setWXZY(CTX ctx,const List<SV>&a);
SV Int4_getWXYZ(CTX ctx,const List<SV>&a);
SV Int4_setWXYZ(CTX ctx,const List<SV>&a);
void Float3_destroy(CTX,NO);
SV Float3_get_member(CTX,NO,SV);
void Float3_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Float3_funcs={
.destroy = Float3_destroy,
.getMember = Float3_get_member,
.setMember = Float3_set_member
};
template <>
struct create_val<T3<float>>
{
static SV f(CTX ctx,const T3<float>&obj)
{
#define ghfj T3<float>
R S::createNativeObject(Float3_funcs,NEW(ghfj, obj),EXT->Float3_typeID);
}
};
template <>
struct val_to_c<T3<float>>
{
static T3<float> f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Float3_typeID)
R*((T3<float>*)obj->data);
else
 CATE(TE,"Value can not be converted to Float3."));
} else
 CATE(TE,"Value can not be converted to Float3."));
}
};
template <>
struct type_same<T3<float>>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Float3_typeID;
else
 R false;
}
};

SV Float3___add__(CTX ctx,const List<SV>&a);
SV Float3___sub__(CTX ctx,const List<SV>&a);
SV Float3___mul__(CTX ctx,const List<SV>&a);
SV Float3___div__(CTX ctx,const List<SV>&a);
SV Float3___eq__(CTX ctx,const List<SV>&a);
SV Float3___neq__(CTX ctx,const List<SV>&a);
SV Float3___less__(CTX ctx,const List<SV>&a);
SV Float3___grtr__(CTX ctx,const List<SV>&a);
SV Float3___leq__(CTX ctx,const List<SV>&a);
SV Float3___geq__(CTX ctx,const List<SV>&a);
SV Float3_sum(CTX ctx,const List<SV>&a);
SV Float3_length(CTX ctx,const List<SV>&a);
SV Float3_lengthSquared(CTX ctx,const List<SV>&a);
SV Float3_dot(CTX ctx,const List<SV>&a);
SV Float3_distance(CTX ctx,const List<SV>&a);
SV Float3_distanceSquared(CTX ctx,const List<SV>&a);
SV Float3_normalize(CTX ctx,const List<SV>&a);
SV Float3_cross(CTX ctx,const List<SV>&a);
SV Float3_getXY(CTX ctx,const List<SV>&a);
SV Float3_setXY(CTX ctx,const List<SV>&a);
SV Float3_getXZ(CTX ctx,const List<SV>&a);
SV Float3_setXZ(CTX ctx,const List<SV>&a);
SV Float3_getYX(CTX ctx,const List<SV>&a);
SV Float3_setYX(CTX ctx,const List<SV>&a);
SV Float3_getYZ(CTX ctx,const List<SV>&a);
SV Float3_setYZ(CTX ctx,const List<SV>&a);
SV Float3_getZX(CTX ctx,const List<SV>&a);
SV Float3_setZX(CTX ctx,const List<SV>&a);
SV Float3_getZY(CTX ctx,const List<SV>&a);
SV Float3_setZY(CTX ctx,const List<SV>&a);
SV Float3_getXYZ(CTX ctx,const List<SV>&a);
SV Float3_setXYZ(CTX ctx,const List<SV>&a);
SV Float3_getXZY(CTX ctx,const List<SV>&a);
SV Float3_setXZY(CTX ctx,const List<SV>&a);
SV Float3_getYXZ(CTX ctx,const List<SV>&a);
SV Float3_setYXZ(CTX ctx,const List<SV>&a);
SV Float3_getYZX(CTX ctx,const List<SV>&a);
SV Float3_setYZX(CTX ctx,const List<SV>&a);
SV Float3_getZXY(CTX ctx,const List<SV>&a);
SV Float3_setZXY(CTX ctx,const List<SV>&a);
SV Float3_getZYX(CTX ctx,const List<SV>&a);
SV Float3_setZYX(CTX ctx,const List<SV>&a);
void GfxLODList_destroy(CTX,NO);
SV GfxLODList_get_member(CTX,NO,SV);
void GfxLODList_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxLODList_funcs={
.destroy = GfxLODList_destroy,
.getMember = GfxLODList_get_member,
.setMember = GfxLODList_set_member
};
template <>
struct create_val<List<GfxLOD>>
{
static SV f(CTX ctx,const List<GfxLOD>&obj)
{
#define ghfj List<GfxLOD>
R S::createNativeObject(GfxLODList_funcs,NEW(ghfj, obj),EXT->GfxLODList_typeID);
}
};
template <>
struct val_to_c<List<GfxLOD>>
{
static List<GfxLOD> f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->GfxLODList_typeID)
R*((List<GfxLOD>*)obj->data);
else
 CATE(TE,"Value can not be converted to GfxLODList."));
} else
 CATE(TE,"Value can not be converted to GfxLODList."));
}
};
template <>
struct type_same<List<GfxLOD>>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxLODList_typeID;
else
 R false;
}
};

SV GfxLODList___eq__(CTX ctx,const List<SV>&a);
SV GfxLODList___neq__(CTX ctx,const List<SV>&a);
SV GfxLODList_getCount(CTX ctx,const List<SV>&a);
SV GfxLODList_getData(CTX ctx,const List<SV>&a);
SV GfxLODList_append(CTX ctx,const List<SV>&a);
SV GfxLODList_insert(CTX ctx,const List<SV>&a);
SV GfxLODList_remove(CTX ctx,const List<SV>&a);
SV GfxLODList_clear(CTX ctx,const List<SV>&a);
SV GfxLODList_find(CTX ctx,const List<SV>&a);
SV GfxLODList_copy(CTX ctx,const List<SV>&a);
SV GfxLODList_in(CTX ctx,const List<SV>&a);
void GfxBuffer_destroy(CTX,NO);
SV GfxBuffer_get_member(CTX,NO,SV);
void GfxBuffer_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxBuffer_funcs={
.destroy = GfxBuffer_destroy,
.getMember = GfxBuffer_get_member,
.setMember = GfxBuffer_set_member
};
template <>
struct type_same<GfxBuffer>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxBuffer_typeID;
else
 R false;
}
};

SV GfxBuffer_allocData(CTX ctx,const List<SV>&a);
SV GfxBuffer_setData(CTX ctx,const List<SV>&a);
SV GfxBuffer_getData(CTX ctx,const List<SV>&a);
SV GfxBuffer_getSize(CTX ctx,const List<SV>&a);
void Transform_destroy(CTX,NO);
SV Transform_get_member(CTX,NO,SV);
void Transform_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Transform_funcs={
.destroy = Transform_destroy,
.getMember = Transform_get_member,
.setMember = Transform_set_member
};
template <>
struct create_val<Transform>
{
static SV f(CTX ctx,const Transform&obj)
{
#define ghfj Transform
R S::createNativeObject(Transform_funcs,NEW(ghfj, obj),EXT->Transform_typeID);
}
};
template <>
struct val_to_c<Transform>
{
static Transform f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Transform_typeID)
R*((Transform*)obj->data);
else
 CATE(TE,"Value can not be converted to Transform."));
} else
 CATE(TE,"Value can not be converted to Transform."));
}
};
template <>
struct type_same<Transform>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Transform_typeID;
else
 R false;
}
};

SV Transform_createMatrix(CTX ctx,const List<SV>&a);
void Quaternion_destroy(CTX,NO);
SV Quaternion_get_member(CTX,NO,SV);
void Quaternion_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Quaternion_funcs={
.destroy = Quaternion_destroy,
.getMember = Quaternion_get_member,
.setMember = Quaternion_set_member
};
template <>
struct create_val<Quaternion>
{
static SV f(CTX ctx,const Quaternion&obj)
{
#define ghfj Quaternion
R S::createNativeObject(Quaternion_funcs,NEW(ghfj, obj),EXT->Quaternion_typeID);
}
};
template <>
struct val_to_c<Quaternion>
{
static Quaternion f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Quaternion_typeID)
R*((Quaternion*)obj->data);
else
 CATE(TE,"Value can not be converted to Quaternion."));
} else
 CATE(TE,"Value can not be converted to Quaternion."));
}
};
template <>
struct type_same<Quaternion>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Quaternion_typeID;
else
 R false;
}
};

SV Quaternion___mul__(CTX ctx,const List<SV>&a);
SV Quaternion_toMatrix(CTX ctx,const List<SV>&a);
SV Quaternion___eq__(CTX ctx,const List<SV>&a);
SV Quaternion_normalize(CTX ctx,const List<SV>&a);
SV Quaternion_getAngle(CTX ctx,const List<SV>&a);
SV Quaternion_getXAxis(CTX ctx,const List<SV>&a);
SV Quaternion_getYAxis(CTX ctx,const List<SV>&a);
SV Quaternion_getZAxis(CTX ctx,const List<SV>&a);
SV Quaternion_getAxis(CTX ctx,const List<SV>&a);
SV Quaternion_getAxisAndAngle(CTX ctx,const List<SV>&a);
SV Quaternion_setAngle(CTX ctx,const List<SV>&a);
SV Quaternion_setXAxis(CTX ctx,const List<SV>&a);
SV Quaternion_setYAxis(CTX ctx,const List<SV>&a);
SV Quaternion_setZAxis(CTX ctx,const List<SV>&a);
SV Quaternion_setAxis(CTX ctx,const List<SV>&a);
SV Quaternion_setAxisAndAngle(CTX ctx,const List<SV>&a);
SV Quaternion_setEulerAngles(CTX ctx,const List<SV>&a);
SV Quaternion_getEulerAngles(CTX ctx,const List<SV>&a);
void Int2_destroy(CTX,NO);
SV Int2_get_member(CTX,NO,SV);
void Int2_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Int2_funcs={
.destroy = Int2_destroy,
.getMember = Int2_get_member,
.setMember = Int2_set_member
};
template <>
struct create_val<T2<int32_t>>
{
static SV f(CTX ctx,const T2<int32_t>&obj)
{
#define ghfj T2<int32_t>
R S::createNativeObject(Int2_funcs,NEW(ghfj, obj),EXT->Int2_typeID);
}
};
template <>
struct val_to_c<T2<int32_t>>
{
static T2<int32_t> f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Int2_typeID)
R*((T2<int32_t>*)obj->data);
else
 CATE(TE,"Value can not be converted to Int2."));
} else
 CATE(TE,"Value can not be converted to Int2."));
}
};
template <>
struct type_same<T2<int32_t>>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Int2_typeID;
else
 R false;
}
};

SV Int2___add__(CTX ctx,const List<SV>&a);
SV Int2___sub__(CTX ctx,const List<SV>&a);
SV Int2___mul__(CTX ctx,const List<SV>&a);
SV Int2___div__(CTX ctx,const List<SV>&a);
SV Int2___eq__(CTX ctx,const List<SV>&a);
SV Int2___neq__(CTX ctx,const List<SV>&a);
SV Int2___less__(CTX ctx,const List<SV>&a);
SV Int2___grtr__(CTX ctx,const List<SV>&a);
SV Int2___leq__(CTX ctx,const List<SV>&a);
SV Int2___geq__(CTX ctx,const List<SV>&a);
SV Int2_sum(CTX ctx,const List<SV>&a);
SV Int2_length(CTX ctx,const List<SV>&a);
SV Int2_lengthSquared(CTX ctx,const List<SV>&a);
SV Int2_dot(CTX ctx,const List<SV>&a);
SV Int2_distance(CTX ctx,const List<SV>&a);
SV Int2_distanceSquared(CTX ctx,const List<SV>&a);
SV Int2_normalize(CTX ctx,const List<SV>&a);
SV Int2_getXY(CTX ctx,const List<SV>&a);
SV Int2_setXY(CTX ctx,const List<SV>&a);
SV Int2_getYX(CTX ctx,const List<SV>&a);
SV Int2_setYX(CTX ctx,const List<SV>&a);
void AudioWorld_destroy(CTX,NO);
SV AudioWorld_get_member(CTX,NO,SV);
void AudioWorld_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs AudioWorld_funcs={
.destroy = AudioWorld_destroy,
.getMember = AudioWorld_get_member,
.setMember = AudioWorld_set_member
};
template <>
struct create_val<AudioWorld>
{
static SV f(CTX ctx,const AudioWorld&obj)
{
#define ghfj AudioWorld
R S::createNativeObject(AudioWorld_funcs,NEW(ghfj, obj),EXT->AudioWorld_typeID);
}
};
template <>
struct val_to_c<AudioWorld>
{
static AudioWorld f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->AudioWorld_typeID)
R*((AudioWorld*)obj->data);
else
 CATE(TE,"Value can not be converted to AudioWorld."));
} else
 CATE(TE,"Value can not be converted to AudioWorld."));
}
};
template <>
struct type_same<AudioWorld>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->AudioWorld_typeID;
else
 R false;
}
};

SV AudioWorld_createSource(CTX ctx,const List<SV>&a);
SV AudioWorld_destroySource(CTX ctx,const List<SV>&a);
SV AudioWorld_clearSources(CTX ctx,const List<SV>&a);
SV AudioWorld_getSources(CTX ctx,const List<SV>&a);
SV AudioWorld_addToAudioDevice(CTX ctx,const List<SV>&a);
SV AudioWorld_removeFromAudioDevice(CTX ctx,const List<SV>&a);
void StrStrMap_destroy(CTX,NO);
SV StrStrMap_get_member(CTX,NO,SV);
void StrStrMap_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs StrStrMap_funcs={
.destroy = StrStrMap_destroy,
.getMember = StrStrMap_get_member,
.setMember = StrStrMap_set_member
};
template <>
struct create_val<HashMap<String,String>>
{
static SV f(CTX ctx,const HashMap<String,String>&obj)
{
#define ghfj HashMap<String,String>
R S::createNativeObject(StrStrMap_funcs,NEW(ghfj, obj),EXT->StrStrMap_typeID);
}
};
template <>
struct val_to_c<HashMap<String,String>>
{
static HashMap<String,String> f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->StrStrMap_typeID)
R*((HashMap<String,String>*)obj->data);
else
 CATE(TE,"Value can not be converted to StrStrMap."));
} else
 CATE(TE,"Value can not be converted to StrStrMap."));
}
};
template <>
struct type_same<HashMap<String,String>>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->StrStrMap_typeID;
else
 R false;
}
};

SV StrStrMap___eq__(CTX ctx,const List<SV>&a);
SV StrStrMap___neq__(CTX ctx,const List<SV>&a);
SV StrStrMap_getEntryCount(CTX ctx,const List<SV>&a);
SV StrStrMap_findEntry(CTX ctx,const List<SV>&a);
SV StrStrMap_getKey(CTX ctx,const List<SV>&a);
SV StrStrMap_getValue(CTX ctx,const List<SV>&a);
SV StrStrMap_getKeyHash(CTX ctx,const List<SV>&a);
SV StrStrMap_get(CTX ctx,const List<SV>&a);
SV StrStrMap_set(CTX ctx,const List<SV>&a);
SV StrStrMap_removeEntry(CTX ctx,const List<SV>&a);
SV StrStrMap_remove(CTX ctx,const List<SV>&a);
SV StrStrMap_clear(CTX ctx,const List<SV>&a);
SV StrStrMap_append(CTX ctx,const List<SV>&a);
void Light_destroy(CTX,NO);
SV Light_get_member(CTX,NO,SV);
void Light_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Light_funcs={
.destroy = Light_destroy,
.getMember = Light_get_member,
.setMember = Light_set_member
};
template <>
struct type_same<Light>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Light_typeID;
else
 R false;
}
};

SV Light_addShadowmap(CTX ctx,const List<SV>&a);
SV Light_removeShadowmap(CTX ctx,const List<SV>&a);
SV Light_getShadowmap(CTX ctx,const List<SV>&a);
SV Light_getShadowmapFramebuffer(CTX ctx,const List<SV>&a);
SV Light_getPointLightFramebuffers(CTX ctx,const List<SV>&a);
SV Light_getShadowmapResolution(CTX ctx,const List<SV>&a);
SV Light_getShadowmapPrecision(CTX ctx,const List<SV>&a);
SV Light_updateMatrices(CTX ctx,const List<SV>&a);
SV Light_getViewMatrix(CTX ctx,const List<SV>&a);
SV Light_getProjectionMatrix(CTX ctx,const List<SV>&a);
void LightPointData_destroy(CTX,NO);
SV LightPointData_get_member(CTX,NO,SV);
void LightPointData_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs LightPointData_funcs={
.destroy = LightPointData_destroy,
.getMember = LightPointData_get_member,
.setMember = LightPointData_set_member
};
template <>
struct create_val<LightPointData>
{
static SV f(CTX ctx,const LightPointData&obj)
{
#define ghfj LightPointData
R S::createNativeObject(LightPointData_funcs,NEW(ghfj, obj),EXT->LightPointData_typeID);
}
};
template <>
struct val_to_c<LightPointData>
{
static LightPointData f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->LightPointData_typeID)
R*((LightPointData*)obj->data);
else
 CATE(TE,"Value can not be converted to LightPointData."));
} else
 CATE(TE,"Value can not be converted to LightPointData."));
}
};
template <>
struct type_same<LightPointData>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->LightPointData_typeID;
else
 R false;
}
};

void Float4_destroy(CTX,NO);
SV Float4_get_member(CTX,NO,SV);
void Float4_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Float4_funcs={
.destroy = Float4_destroy,
.getMember = Float4_get_member,
.setMember = Float4_set_member
};
template <>
struct create_val<T4<float>>
{
static SV f(CTX ctx,const T4<float>&obj)
{
#define ghfj T4<float>
R S::createNativeObject(Float4_funcs,NEW(ghfj, obj),EXT->Float4_typeID);
}
};
template <>
struct val_to_c<T4<float>>
{
static T4<float> f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Float4_typeID)
R*((T4<float>*)obj->data);
else
 CATE(TE,"Value can not be converted to Float4."));
} else
 CATE(TE,"Value can not be converted to Float4."));
}
};
template <>
struct type_same<T4<float>>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Float4_typeID;
else
 R false;
}
};

SV Float4___add__(CTX ctx,const List<SV>&a);
SV Float4___sub__(CTX ctx,const List<SV>&a);
SV Float4___mul__(CTX ctx,const List<SV>&a);
SV Float4___div__(CTX ctx,const List<SV>&a);
SV Float4___eq__(CTX ctx,const List<SV>&a);
SV Float4___neq__(CTX ctx,const List<SV>&a);
SV Float4___less__(CTX ctx,const List<SV>&a);
SV Float4___grtr__(CTX ctx,const List<SV>&a);
SV Float4___leq__(CTX ctx,const List<SV>&a);
SV Float4___geq__(CTX ctx,const List<SV>&a);
SV Float4_sum(CTX ctx,const List<SV>&a);
SV Float4_length(CTX ctx,const List<SV>&a);
SV Float4_lengthSquared(CTX ctx,const List<SV>&a);
SV Float4_dot(CTX ctx,const List<SV>&a);
SV Float4_distance(CTX ctx,const List<SV>&a);
SV Float4_distanceSquared(CTX ctx,const List<SV>&a);
SV Float4_normalize(CTX ctx,const List<SV>&a);
SV Float4_getXY(CTX ctx,const List<SV>&a);
SV Float4_setXY(CTX ctx,const List<SV>&a);
SV Float4_getXZ(CTX ctx,const List<SV>&a);
SV Float4_setXZ(CTX ctx,const List<SV>&a);
SV Float4_getXW(CTX ctx,const List<SV>&a);
SV Float4_setXW(CTX ctx,const List<SV>&a);
SV Float4_getYX(CTX ctx,const List<SV>&a);
SV Float4_setYX(CTX ctx,const List<SV>&a);
SV Float4_getYZ(CTX ctx,const List<SV>&a);
SV Float4_setYZ(CTX ctx,const List<SV>&a);
SV Float4_getYW(CTX ctx,const List<SV>&a);
SV Float4_setYW(CTX ctx,const List<SV>&a);
SV Float4_getZX(CTX ctx,const List<SV>&a);
SV Float4_setZX(CTX ctx,const List<SV>&a);
SV Float4_getZY(CTX ctx,const List<SV>&a);
SV Float4_setZY(CTX ctx,const List<SV>&a);
SV Float4_getZW(CTX ctx,const List<SV>&a);
SV Float4_setZW(CTX ctx,const List<SV>&a);
SV Float4_getWX(CTX ctx,const List<SV>&a);
SV Float4_setWX(CTX ctx,const List<SV>&a);
SV Float4_getWY(CTX ctx,const List<SV>&a);
SV Float4_setWY(CTX ctx,const List<SV>&a);
SV Float4_getWZ(CTX ctx,const List<SV>&a);
SV Float4_setWZ(CTX ctx,const List<SV>&a);
SV Float4_getXYZ(CTX ctx,const List<SV>&a);
SV Float4_setXYZ(CTX ctx,const List<SV>&a);
SV Float4_getXYW(CTX ctx,const List<SV>&a);
SV Float4_setXYW(CTX ctx,const List<SV>&a);
SV Float4_getXZY(CTX ctx,const List<SV>&a);
SV Float4_setXZY(CTX ctx,const List<SV>&a);
SV Float4_getXZW(CTX ctx,const List<SV>&a);
SV Float4_setXZW(CTX ctx,const List<SV>&a);
SV Float4_getXWZ(CTX ctx,const List<SV>&a);
SV Float4_setXWZ(CTX ctx,const List<SV>&a);
SV Float4_getXWY(CTX ctx,const List<SV>&a);
SV Float4_setXWY(CTX ctx,const List<SV>&a);
SV Float4_getYXZ(CTX ctx,const List<SV>&a);
SV Float4_setYXZ(CTX ctx,const List<SV>&a);
SV Float4_getYXW(CTX ctx,const List<SV>&a);
SV Float4_setYXW(CTX ctx,const List<SV>&a);
SV Float4_getYZX(CTX ctx,const List<SV>&a);
SV Float4_setYZX(CTX ctx,const List<SV>&a);
SV Float4_getYZW(CTX ctx,const List<SV>&a);
SV Float4_setYZW(CTX ctx,const List<SV>&a);
SV Float4_getYWZ(CTX ctx,const List<SV>&a);
SV Float4_setYWZ(CTX ctx,const List<SV>&a);
SV Float4_getYWX(CTX ctx,const List<SV>&a);
SV Float4_setYWX(CTX ctx,const List<SV>&a);
SV Float4_getZXY(CTX ctx,const List<SV>&a);
SV Float4_setZXY(CTX ctx,const List<SV>&a);
SV Float4_getZXW(CTX ctx,const List<SV>&a);
SV Float4_setZXW(CTX ctx,const List<SV>&a);
SV Float4_getZYX(CTX ctx,const List<SV>&a);
SV Float4_setZYX(CTX ctx,const List<SV>&a);
SV Float4_getZYW(CTX ctx,const List<SV>&a);
SV Float4_setZYW(CTX ctx,const List<SV>&a);
SV Float4_getZWY(CTX ctx,const List<SV>&a);
SV Float4_setZWY(CTX ctx,const List<SV>&a);
SV Float4_getZWX(CTX ctx,const List<SV>&a);
SV Float4_setZWX(CTX ctx,const List<SV>&a);
SV Float4_getWXY(CTX ctx,const List<SV>&a);
SV Float4_setWXY(CTX ctx,const List<SV>&a);
SV Float4_getWXZ(CTX ctx,const List<SV>&a);
SV Float4_setWXZ(CTX ctx,const List<SV>&a);
SV Float4_getWYX(CTX ctx,const List<SV>&a);
SV Float4_setWYX(CTX ctx,const List<SV>&a);
SV Float4_getWYZ(CTX ctx,const List<SV>&a);
SV Float4_setWYZ(CTX ctx,const List<SV>&a);
SV Float4_getWZY(CTX ctx,const List<SV>&a);
SV Float4_setWZY(CTX ctx,const List<SV>&a);
SV Float4_getWZX(CTX ctx,const List<SV>&a);
SV Float4_setWZX(CTX ctx,const List<SV>&a);
SV Float4_getXYZW(CTX ctx,const List<SV>&a);
SV Float4_setXYZW(CTX ctx,const List<SV>&a);
SV Float4_getXYWZ(CTX ctx,const List<SV>&a);
SV Float4_setXYWZ(CTX ctx,const List<SV>&a);
SV Float4_getXZYW(CTX ctx,const List<SV>&a);
SV Float4_setXZYW(CTX ctx,const List<SV>&a);
SV Float4_getXZWY(CTX ctx,const List<SV>&a);
SV Float4_setXZWY(CTX ctx,const List<SV>&a);
SV Float4_getXWZY(CTX ctx,const List<SV>&a);
SV Float4_setXWZY(CTX ctx,const List<SV>&a);
SV Float4_getXWYZ(CTX ctx,const List<SV>&a);
SV Float4_setXWYZ(CTX ctx,const List<SV>&a);
SV Float4_getYXZW(CTX ctx,const List<SV>&a);
SV Float4_setYXZW(CTX ctx,const List<SV>&a);
SV Float4_getYXWZ(CTX ctx,const List<SV>&a);
SV Float4_setYXWZ(CTX ctx,const List<SV>&a);
SV Float4_getYZXW(CTX ctx,const List<SV>&a);
SV Float4_setYZXW(CTX ctx,const List<SV>&a);
SV Float4_getYZWX(CTX ctx,const List<SV>&a);
SV Float4_setYZWX(CTX ctx,const List<SV>&a);
SV Float4_getYWZX(CTX ctx,const List<SV>&a);
SV Float4_setYWZX(CTX ctx,const List<SV>&a);
SV Float4_getYWXZ(CTX ctx,const List<SV>&a);
SV Float4_setYWXZ(CTX ctx,const List<SV>&a);
SV Float4_getZYXW(CTX ctx,const List<SV>&a);
SV Float4_setZYXW(CTX ctx,const List<SV>&a);
SV Float4_getZYWX(CTX ctx,const List<SV>&a);
SV Float4_setZYWX(CTX ctx,const List<SV>&a);
SV Float4_getZXYW(CTX ctx,const List<SV>&a);
SV Float4_setZXYW(CTX ctx,const List<SV>&a);
SV Float4_getZXWY(CTX ctx,const List<SV>&a);
SV Float4_setZXWY(CTX ctx,const List<SV>&a);
SV Float4_getZWXY(CTX ctx,const List<SV>&a);
SV Float4_setZWXY(CTX ctx,const List<SV>&a);
SV Float4_getZWYX(CTX ctx,const List<SV>&a);
SV Float4_setZWYX(CTX ctx,const List<SV>&a);
SV Float4_getWYZX(CTX ctx,const List<SV>&a);
SV Float4_setWYZX(CTX ctx,const List<SV>&a);
SV Float4_getWYXZ(CTX ctx,const List<SV>&a);
SV Float4_setWYXZ(CTX ctx,const List<SV>&a);
SV Float4_getWZYX(CTX ctx,const List<SV>&a);
SV Float4_setWZYX(CTX ctx,const List<SV>&a);
SV Float4_getWZXY(CTX ctx,const List<SV>&a);
SV Float4_setWZXY(CTX ctx,const List<SV>&a);
SV Float4_getWXZY(CTX ctx,const List<SV>&a);
SV Float4_setWXZY(CTX ctx,const List<SV>&a);
SV Float4_getWXYZ(CTX ctx,const List<SV>&a);
SV Float4_setWXYZ(CTX ctx,const List<SV>&a);
void LightDirectionalData_destroy(CTX,NO);
SV LightDirectionalData_get_member(CTX,NO,SV);
void LightDirectionalData_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs LightDirectionalData_funcs={
.destroy = LightDirectionalData_destroy,
.getMember = LightDirectionalData_get_member,
.setMember = LightDirectionalData_set_member
};
template <>
struct create_val<LightDirectionalData>
{
static SV f(CTX ctx,const LightDirectionalData&obj)
{
#define ghfj LightDirectionalData
R S::createNativeObject(LightDirectionalData_funcs,NEW(ghfj, obj),EXT->LightDirectionalData_typeID);
}
};
template <>
struct val_to_c<LightDirectionalData>
{
static LightDirectionalData f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->LightDirectionalData_typeID)
R*((LightDirectionalData*)obj->data);
else
 CATE(TE,"Value can not be converted to LightDirectionalData."));
} else
 CATE(TE,"Value can not be converted to LightDirectionalData."));
}
};
template <>
struct type_same<LightDirectionalData>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->LightDirectionalData_typeID;
else
 R false;
}
};

void Matrix4x4_destroy(CTX,NO);
SV Matrix4x4_get_member(CTX,NO,SV);
void Matrix4x4_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Matrix4x4_funcs={
.destroy = Matrix4x4_destroy,
.getMember = Matrix4x4_get_member,
.setMember = Matrix4x4_set_member
};
template <>
struct create_val<Matrix4x4>
{
static SV f(CTX ctx,const Matrix4x4&obj)
{
#define ghfj Matrix4x4
R S::createNativeObject(Matrix4x4_funcs,NEW(ghfj, obj),EXT->Matrix4x4_typeID);
}
};
template <>
struct val_to_c<Matrix4x4>
{
static Matrix4x4 f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Matrix4x4_typeID)
R*((Matrix4x4*)obj->data);
else
 CATE(TE,"Value can not be converted to Matrix4x4."));
} else
 CATE(TE,"Value can not be converted to Matrix4x4."));
}
};
template <>
struct type_same<Matrix4x4>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Matrix4x4_typeID;
else
 R false;
}
};

SV Matrix4x4___mul__(CTX ctx,const List<SV>&a);
SV Matrix4x4___div__(CTX ctx,const List<SV>&a);
SV Matrix4x4___eq__(CTX ctx,const List<SV>&a);
SV Matrix4x4_transpose(CTX ctx,const List<SV>&a);
SV Matrix4x4_inverse(CTX ctx,const List<SV>&a);
SV Matrix4x4_translate(CTX ctx,const List<SV>&a);
SV Matrix4x4_scale(CTX ctx,const List<SV>&a);
SV Matrix4x4_rotate(CTX ctx,const List<SV>&a);
SV Matrix4x4_rotatex(CTX ctx,const List<SV>&a);
SV Matrix4x4_rotatey(CTX ctx,const List<SV>&a);
SV Matrix4x4_rotatez(CTX ctx,const List<SV>&a);
SV Matrix4x4_perspective(CTX ctx,const List<SV>&a);
SV Matrix4x4_orthographic(CTX ctx,const List<SV>&a);
SV Matrix4x4_lookAt(CTX ctx,const List<SV>&a);
SV Matrix4x4_lookAtDir(CTX ctx,const List<SV>&a);
void UInt3_destroy(CTX,NO);
SV UInt3_get_member(CTX,NO,SV);
void UInt3_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs UInt3_funcs={
.destroy = UInt3_destroy,
.getMember = UInt3_get_member,
.setMember = UInt3_set_member
};
template <>
struct create_val<T3<uint32_t>>
{
static SV f(CTX ctx,const T3<uint32_t>&obj)
{
#define ghfj T3<uint32_t>
R S::createNativeObject(UInt3_funcs,NEW(ghfj, obj),EXT->UInt3_typeID);
}
};
template <>
struct val_to_c<T3<uint32_t>>
{
static T3<uint32_t> f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->UInt3_typeID)
R*((T3<uint32_t>*)obj->data);
else
 CATE(TE,"Value can not be converted to UInt3."));
} else
 CATE(TE,"Value can not be converted to UInt3."));
}
};
template <>
struct type_same<T3<uint32_t>>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->UInt3_typeID;
else
 R false;
}
};

SV UInt3___add__(CTX ctx,const List<SV>&a);
SV UInt3___sub__(CTX ctx,const List<SV>&a);
SV UInt3___mul__(CTX ctx,const List<SV>&a);
SV UInt3___div__(CTX ctx,const List<SV>&a);
SV UInt3___eq__(CTX ctx,const List<SV>&a);
SV UInt3___neq__(CTX ctx,const List<SV>&a);
SV UInt3___less__(CTX ctx,const List<SV>&a);
SV UInt3___grtr__(CTX ctx,const List<SV>&a);
SV UInt3___leq__(CTX ctx,const List<SV>&a);
SV UInt3___geq__(CTX ctx,const List<SV>&a);
SV UInt3_sum(CTX ctx,const List<SV>&a);
SV UInt3_length(CTX ctx,const List<SV>&a);
SV UInt3_lengthSquared(CTX ctx,const List<SV>&a);
SV UInt3_dot(CTX ctx,const List<SV>&a);
SV UInt3_distance(CTX ctx,const List<SV>&a);
SV UInt3_distanceSquared(CTX ctx,const List<SV>&a);
SV UInt3_normalize(CTX ctx,const List<SV>&a);
SV UInt3_cross(CTX ctx,const List<SV>&a);
SV UInt3_getXY(CTX ctx,const List<SV>&a);
SV UInt3_setXY(CTX ctx,const List<SV>&a);
SV UInt3_getXZ(CTX ctx,const List<SV>&a);
SV UInt3_setXZ(CTX ctx,const List<SV>&a);
SV UInt3_getYX(CTX ctx,const List<SV>&a);
SV UInt3_setYX(CTX ctx,const List<SV>&a);
SV UInt3_getYZ(CTX ctx,const List<SV>&a);
SV UInt3_setYZ(CTX ctx,const List<SV>&a);
SV UInt3_getZX(CTX ctx,const List<SV>&a);
SV UInt3_setZX(CTX ctx,const List<SV>&a);
SV UInt3_getZY(CTX ctx,const List<SV>&a);
SV UInt3_setZY(CTX ctx,const List<SV>&a);
SV UInt3_getXYZ(CTX ctx,const List<SV>&a);
SV UInt3_setXYZ(CTX ctx,const List<SV>&a);
SV UInt3_getXZY(CTX ctx,const List<SV>&a);
SV UInt3_setXZY(CTX ctx,const List<SV>&a);
SV UInt3_getYXZ(CTX ctx,const List<SV>&a);
SV UInt3_setYXZ(CTX ctx,const List<SV>&a);
SV UInt3_getYZX(CTX ctx,const List<SV>&a);
SV UInt3_setYZX(CTX ctx,const List<SV>&a);
SV UInt3_getZXY(CTX ctx,const List<SV>&a);
SV UInt3_setZXY(CTX ctx,const List<SV>&a);
SV UInt3_getZYX(CTX ctx,const List<SV>&a);
SV UInt3_setZYX(CTX ctx,const List<SV>&a);
void LightSpotData_destroy(CTX,NO);
SV LightSpotData_get_member(CTX,NO,SV);
void LightSpotData_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs LightSpotData_funcs={
.destroy = LightSpotData_destroy,
.getMember = LightSpotData_get_member,
.setMember = LightSpotData_set_member
};
template <>
struct create_val<LightSpotData>
{
static SV f(CTX ctx,const LightSpotData&obj)
{
#define ghfj LightSpotData
R S::createNativeObject(LightSpotData_funcs,NEW(ghfj, obj),EXT->LightSpotData_typeID);
}
};
template <>
struct val_to_c<LightSpotData>
{
static LightSpotData f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->LightSpotData_typeID)
R*((LightSpotData*)obj->data);
else
 CATE(TE,"Value can not be converted to LightSpotData."));
} else
 CATE(TE,"Value can not be converted to LightSpotData."));
}
};
template <>
struct type_same<LightSpotData>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->LightSpotData_typeID;
else
 R false;
}
};

void AudioDevice_destroy(CTX,NO);
SV AudioDevice_get_member(CTX,NO,SV);
void AudioDevice_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs AudioDevice_funcs={
.destroy = AudioDevice_destroy,
.getMember = AudioDevice_get_member,
.setMember = AudioDevice_set_member
};
template <>
struct create_val<AudioDevice>
{
static SV f(CTX ctx,const AudioDevice&obj)
{
#define ghfj AudioDevice
R S::createNativeObject(AudioDevice_funcs,NEW(ghfj, obj),EXT->AudioDevice_typeID);
}
};
template <>
struct val_to_c<AudioDevice>
{
static AudioDevice f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->AudioDevice_typeID)
R*((AudioDevice*)obj->data);
else
 CATE(TE,"Value can not be converted to AudioDevice."));
} else
 CATE(TE,"Value can not be converted to AudioDevice."));
}
};
template <>
struct type_same<AudioDevice>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->AudioDevice_typeID;
else
 R false;
}
};

SV AudioDevice_getName(CTX ctx,const List<SV>&a);
SV AudioDevice_getDeviceCount(CTX ctx,const List<SV>&a);
SV AudioDevice_setIndex(CTX ctx,const List<SV>&a);
SV AudioDevice_setFrequency(CTX ctx,const List<SV>&a);
SV AudioDevice_setSamples(CTX ctx,const List<SV>&a);
SV AudioDevice_getIndex(CTX ctx,const List<SV>&a);
SV AudioDevice_getFrequency(CTX ctx,const List<SV>&a);
SV AudioDevice_getSamples(CTX ctx,const List<SV>&a);
SV AudioDevice_getNumQueuedSamples(CTX ctx,const List<SV>&a);
SV AudioDevice_pause(CTX ctx,const List<SV>&a);
SV AudioDevice_play(CTX ctx,const List<SV>&a);
SV AudioDevice_getPaused(CTX ctx,const List<SV>&a);
SV AudioDevice_runCallbacks(CTX ctx,const List<SV>&a);
void GfxLOD_destroy(CTX,NO);
SV GfxLOD_get_member(CTX,NO,SV);
void GfxLOD_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxLOD_funcs={
.destroy = GfxLOD_destroy,
.getMember = GfxLOD_get_member,
.setMember = GfxLOD_set_member
};
template <>
struct create_val<GfxLOD>
{
static SV f(CTX ctx,const GfxLOD&obj)
{
#define ghfj GfxLOD
R S::createNativeObject(GfxLOD_funcs,NEW(ghfj, obj),EXT->GfxLOD_typeID);
}
};
template <>
struct val_to_c<GfxLOD>
{
static GfxLOD f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->GfxLOD_typeID)
R*((GfxLOD*)obj->data);
else
 CATE(TE,"Value can not be converted to GfxLOD."));
} else
 CATE(TE,"Value can not be converted to GfxLOD."));
}
};
template <>
struct type_same<GfxLOD>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxLOD_typeID;
else
 R false;
}
};

SV GfxLOD___eq__(CTX ctx,const List<SV>&a);
void File_destroy(CTX,NO);
SV File_get_member(CTX,NO,SV);
void File_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs File_funcs={
.destroy = File_destroy,
.getMember = File_get_member,
.setMember = File_set_member
};
template <>
struct type_same<File>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->File_typeID;
else
 R false;
}
};

SV File_read(CTX ctx,const List<SV>&a);
SV File_write(CTX ctx,const List<SV>&a);
SV File_seek(CTX ctx,const List<SV>&a);
SV File_tell(CTX ctx,const List<SV>&a);
SV File_flush(CTX ctx,const List<SV>&a);
SV File_isAtEndOfFile(CTX ctx,const List<SV>&a);
SV File_getSize(CTX ctx,const List<SV>&a);
SV File_readUInt8(CTX ctx,const List<SV>&a);
SV File_readInt8(CTX ctx,const List<SV>&a);
SV File_readUInt16LE(CTX ctx,const List<SV>&a);
SV File_readInt16LE(CTX ctx,const List<SV>&a);
SV File_readUInt32LE(CTX ctx,const List<SV>&a);
SV File_readInt32LE(CTX ctx,const List<SV>&a);
SV File_readUInt64LE(CTX ctx,const List<SV>&a);
SV File_readInt64LE(CTX ctx,const List<SV>&a);
SV File_readUInt16BE(CTX ctx,const List<SV>&a);
SV File_readInt16BE(CTX ctx,const List<SV>&a);
SV File_readUInt32BE(CTX ctx,const List<SV>&a);
SV File_readInt32BE(CTX ctx,const List<SV>&a);
SV File_readUInt64BE(CTX ctx,const List<SV>&a);
SV File_readInt64BE(CTX ctx,const List<SV>&a);
SV File_readFloat32(CTX ctx,const List<SV>&a);
SV File_readChar(CTX ctx,const List<SV>&a);
SV File_writeUInt8(CTX ctx,const List<SV>&a);
SV File_writeInt8(CTX ctx,const List<SV>&a);
SV File_writeUInt16LE(CTX ctx,const List<SV>&a);
SV File_writeInt16LE(CTX ctx,const List<SV>&a);
SV File_writeUInt32LE(CTX ctx,const List<SV>&a);
SV File_writeInt32LE(CTX ctx,const List<SV>&a);
SV File_writeUInt64LE(CTX ctx,const List<SV>&a);
SV File_writeInt64LE(CTX ctx,const List<SV>&a);
SV File_writeUInt16BE(CTX ctx,const List<SV>&a);
SV File_writeInt16BE(CTX ctx,const List<SV>&a);
SV File_writeUInt32BE(CTX ctx,const List<SV>&a);
SV File_writeInt32BE(CTX ctx,const List<SV>&a);
SV File_writeUInt64BE(CTX ctx,const List<SV>&a);
SV File_writeInt64BE(CTX ctx,const List<SV>&a);
SV File_writeFloat32(CTX ctx,const List<SV>&a);
SV File_printf(CTX ctx,const List<SV>&a);
SV File_vprintf(CTX ctx,const List<SV>&a);
SV File_writeChar(CTX ctx,const List<SV>&a);
void AABB_destroy(CTX,NO);
SV AABB_get_member(CTX,NO,SV);
void AABB_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs AABB_funcs={
.destroy = AABB_destroy,
.getMember = AABB_get_member,
.setMember = AABB_set_member
};
template <>
struct create_val<AABB>
{
static SV f(CTX ctx,const AABB&obj)
{
#define ghfj AABB
R S::createNativeObject(AABB_funcs,NEW(ghfj, obj),EXT->AABB_typeID);
}
};
template <>
struct val_to_c<AABB>
{
static AABB f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->AABB_typeID)
R*((AABB*)obj->data);
else
 CATE(TE,"Value can not be converted to AABB."));
} else
 CATE(TE,"Value can not be converted to AABB."));
}
};
template <>
struct type_same<AABB>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->AABB_typeID;
else
 R false;
}
};

SV AABB_transform(CTX ctx,const List<SV>&a);
SV AABB_extend(CTX ctx,const List<SV>&a);
SV AABB_grow(CTX ctx,const List<SV>&a);
void List_destroy(CTX,NO);
SV List_get_member(CTX,NO,SV);
void List_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs List_funcs={
.destroy = List_destroy,
.getMember = List_get_member,
.setMember = List_set_member
};
template <>
struct create_val<List<scripting::Value*>>
{
static SV f(CTX ctx,const List<scripting::Value*>&obj)
{
#define ghfj List<scripting::Value*>
R S::createNativeObject(List_funcs,NEW(ghfj, obj),EXT->List_typeID);
}
};
template <>
struct val_to_c<List<scripting::Value*>>
{
static List<scripting::Value*> f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->List_typeID)
R*((List<scripting::Value*>*)obj->data);
else
 CATE(TE,"Value can not be converted to List."));
} else
 CATE(TE,"Value can not be converted to List."));
}
};
template <>
struct type_same<List<scripting::Value*>>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->List_typeID;
else
 R false;
}
};

SV List___eq__(CTX ctx,const List<SV>&a);
SV List___neq__(CTX ctx,const List<SV>&a);
SV List_getCount(CTX ctx,const List<SV>&a);
SV List_getData(CTX ctx,const List<SV>&a);
SV List_append(CTX ctx,const List<SV>&a);
SV List_insert(CTX ctx,const List<SV>&a);
SV List_remove(CTX ctx,const List<SV>&a);
SV List_clear(CTX ctx,const List<SV>&a);
SV List_find(CTX ctx,const List<SV>&a);
SV List_copy(CTX ctx,const List<SV>&a);
SV List_in(CTX ctx,const List<SV>&a);
void Audio_destroy(CTX,NO);
SV Audio_get_member(CTX,NO,SV);
void Audio_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Audio_funcs={
.destroy = Audio_destroy,
.getMember = Audio_get_member,
.setMember = Audio_set_member
};
template <>
struct type_same<Audio>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Audio_typeID;
else
 R false;
}
};

SV Audio_removeContent(CTX ctx,const List<SV>&a);
SV Audio_changeSampleFrequency(CTX ctx,const List<SV>&a);
SV Audio_getNumSamples(CTX ctx,const List<SV>&a);
SV Audio_getSample(CTX ctx,const List<SV>&a);
SV Audio_getMonoSample(CTX ctx,const List<SV>&a);
SV Audio_setSample(CTX ctx,const List<SV>&a);
SV Audio_setMonoSample(CTX ctx,const List<SV>&a);
SV Audio_getDuration(CTX ctx,const List<SV>&a);
SV Audio_getSampleIndex(CTX ctx,const List<SV>&a);
SV Audio_load(CTX ctx,const List<SV>&a);
SV Audio_reload(CTX ctx,const List<SV>&a);
SV Audio_save(CTX ctx,const List<SV>&a);
SV Audio_copy(CTX ctx,const List<SV>&a);
SV Audio_getType(CTX ctx,const List<SV>&a);
SV Audio_isLoaded(CTX ctx,const List<SV>&a);
SV Audio_getLastFileModification(CTX ctx,const List<SV>&a);
SV Audio_shouldReload(CTX ctx,const List<SV>&a);
SV Audio_possiblyReload(CTX ctx,const List<SV>&a);
SV Audio_release(CTX ctx,const List<SV>&a);
SV Audio_getRefCount(CTX ctx,const List<SV>&a);
SV Audio_getFilename(CTX ctx,const List<SV>&a);
SV Audio_setFilename(CTX ctx,const List<SV>&a);
void GfxSubModelList_destroy(CTX,NO);
SV GfxSubModelList_get_member(CTX,NO,SV);
void GfxSubModelList_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxSubModelList_funcs={
.destroy = GfxSubModelList_destroy,
.getMember = GfxSubModelList_get_member,
.setMember = GfxSubModelList_set_member
};
template <>
struct create_val<List<GfxModel::SubModel>>
{
static SV f(CTX ctx,const List<GfxModel::SubModel>&obj)
{
#define ghfj List<GfxModel::SubModel>
R S::createNativeObject(GfxSubModelList_funcs,NEW(ghfj, obj),EXT->GfxSubModelList_typeID);
}
};
template <>
struct val_to_c<List<GfxModel::SubModel>>
{
static List<GfxModel::SubModel> f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->GfxSubModelList_typeID)
R*((List<GfxModel::SubModel>*)obj->data);
else
 CATE(TE,"Value can not be converted to GfxSubModelList."));
} else
 CATE(TE,"Value can not be converted to GfxSubModelList."));
}
};
template <>
struct type_same<List<GfxModel::SubModel>>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxSubModelList_typeID;
else
 R false;
}
};

SV GfxSubModelList___eq__(CTX ctx,const List<SV>&a);
SV GfxSubModelList___neq__(CTX ctx,const List<SV>&a);
SV GfxSubModelList_getCount(CTX ctx,const List<SV>&a);
SV GfxSubModelList_getData(CTX ctx,const List<SV>&a);
SV GfxSubModelList_append(CTX ctx,const List<SV>&a);
SV GfxSubModelList_insert(CTX ctx,const List<SV>&a);
SV GfxSubModelList_remove(CTX ctx,const List<SV>&a);
SV GfxSubModelList_clear(CTX ctx,const List<SV>&a);
SV GfxSubModelList_find(CTX ctx,const List<SV>&a);
SV GfxSubModelList_copy(CTX ctx,const List<SV>&a);
SV GfxSubModelList_in(CTX ctx,const List<SV>&a);
void GfxModel_destroy(CTX,NO);
SV GfxModel_get_member(CTX,NO,SV);
void GfxModel_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxModel_funcs={
.destroy = GfxModel_destroy,
.getMember = GfxModel_get_member,
.setMember = GfxModel_set_member
};
template <>
struct type_same<GfxModel>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxModel_typeID;
else
 R false;
}
};

SV GfxModel_removeContent(CTX ctx,const List<SV>&a);
SV GfxModel_save(CTX ctx,const List<SV>&a);
SV GfxModel_load(CTX ctx,const List<SV>&a);
SV GfxModel_reload(CTX ctx,const List<SV>&a);
SV GfxModel_copy(CTX ctx,const List<SV>&a);
SV GfxModel_getType(CTX ctx,const List<SV>&a);
SV GfxModel_isLoaded(CTX ctx,const List<SV>&a);
SV GfxModel_getLastFileModification(CTX ctx,const List<SV>&a);
SV GfxModel_shouldReload(CTX ctx,const List<SV>&a);
SV GfxModel_possiblyReload(CTX ctx,const List<SV>&a);
SV GfxModel_release(CTX ctx,const List<SV>&a);
SV GfxModel_getRefCount(CTX ctx,const List<SV>&a);
SV GfxModel_getFilename(CTX ctx,const List<SV>&a);
SV GfxModel_setFilename(CTX ctx,const List<SV>&a);
void Matrix3x3_destroy(CTX,NO);
SV Matrix3x3_get_member(CTX,NO,SV);
void Matrix3x3_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Matrix3x3_funcs={
.destroy = Matrix3x3_destroy,
.getMember = Matrix3x3_get_member,
.setMember = Matrix3x3_set_member
};
template <>
struct create_val<Matrix3x3>
{
static SV f(CTX ctx,const Matrix3x3&obj)
{
#define ghfj Matrix3x3
R S::createNativeObject(Matrix3x3_funcs,NEW(ghfj, obj),EXT->Matrix3x3_typeID);
}
};
template <>
struct val_to_c<Matrix3x3>
{
static Matrix3x3 f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Matrix3x3_typeID)
R*((Matrix3x3*)obj->data);
else
 CATE(TE,"Value can not be converted to Matrix3x3."));
} else
 CATE(TE,"Value can not be converted to Matrix3x3."));
}
};
template <>
struct type_same<Matrix3x3>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Matrix3x3_typeID;
else
 R false;
}
};

SV Matrix3x3___mul__(CTX ctx,const List<SV>&a);
SV Matrix3x3___div__(CTX ctx,const List<SV>&a);
SV Matrix3x3___eq__(CTX ctx,const List<SV>&a);
SV Matrix3x3_transpose(CTX ctx,const List<SV>&a);
SV Matrix3x3_inverse(CTX ctx,const List<SV>&a);
SV Matrix3x3_translate(CTX ctx,const List<SV>&a);
SV Matrix3x3_scale(CTX ctx,const List<SV>&a);
SV Matrix3x3_rotate(CTX ctx,const List<SV>&a);
SV Matrix3x3_rotatex(CTX ctx,const List<SV>&a);
SV Matrix3x3_rotatey(CTX ctx,const List<SV>&a);
SV Matrix3x3_rotatez(CTX ctx,const List<SV>&a);
void GfxDebugDrawer_destroy(CTX,NO);
SV GfxDebugDrawer_get_member(CTX,NO,SV);
void GfxDebugDrawer_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxDebugDrawer_funcs={
.destroy = GfxDebugDrawer_destroy,
.getMember = GfxDebugDrawer_get_member,
.setMember = GfxDebugDrawer_set_member
};
template <>
struct type_same<GfxDebugDrawer>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxDebugDrawer_typeID;
else
 R false;
}
};

SV GfxDebugDrawer_addLine(CTX ctx,const List<SV>&a);
SV GfxDebugDrawer_render(CTX ctx,const List<SV>&a);
SV Filesystem_ptr_copy(CTX,NO);
void Filesystem_ptr_destroy(CTX,NO);
SV Filesystem_ptr_get_member(CTX,NO,SV);
void Filesystem_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Filesystem_ptr_funcs={
.destroy = Filesystem_ptr_destroy,
.getMember = Filesystem_ptr_get_member,
.setMember = Filesystem_ptr_set_member
};
template <>
struct create_val<Filesystem *>
{
static SV f(CTX ctx,Filesystem*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(Filesystem_ptr_funcs,obj,EXT->Filesystem_ptr_typeID);
}
};
template <>
struct val_to_c<Filesystem *>
{
static Filesystem *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Filesystem_ptr_typeID)
R(Filesystem*)obj->data;
else
 CATE(TE,"Value is not a FilesystemRef."));
} else
 CATE(TE,"Value is not a FilesystemRef."));
}
};
template <>
struct type_same<Filesystem *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Filesystem_ptr_typeID;
else
 R false;
}
};

SV GfxCompiledShader_ptr_copy(CTX,NO);
void GfxCompiledShader_ptr_destroy(CTX,NO);
SV GfxCompiledShader_ptr_get_member(CTX,NO,SV);
void GfxCompiledShader_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxCompiledShader_ptr_funcs={
.destroy = GfxCompiledShader_ptr_destroy,
.getMember = GfxCompiledShader_ptr_get_member,
.setMember = GfxCompiledShader_ptr_set_member
};
template <>
struct create_val<GfxCompiledShader *>
{
static SV f(CTX ctx,GfxCompiledShader*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(GfxCompiledShader_ptr_funcs,obj,EXT->GfxCompiledShader_ptr_typeID);
}
};
template <>
struct val_to_c<GfxCompiledShader *>
{
static GfxCompiledShader *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->GfxCompiledShader_ptr_typeID)
R(GfxCompiledShader*)obj->data;
else
 CATE(TE,"Value is not a GfxCompiledShaderRef."));
} else
 CATE(TE,"Value is not a GfxCompiledShaderRef."));
}
};
template <>
struct type_same<GfxCompiledShader *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxCompiledShader_ptr_typeID;
else
 R false;
}
};

SV UInt2_ptr_copy(CTX,NO);
void UInt2_ptr_destroy(CTX,NO);
SV UInt2_ptr_get_member(CTX,NO,SV);
void UInt2_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs UInt2_ptr_funcs={
.destroy = UInt2_ptr_destroy,
.getMember = UInt2_ptr_get_member,
.setMember = UInt2_ptr_set_member
};
template <>
struct create_val<T2<uint32_t> *>
{
static SV f(CTX ctx,T2<uint32_t>*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(UInt2_ptr_funcs,obj,EXT->UInt2_ptr_typeID);
}
};
template <>
struct val_to_c<T2<uint32_t> *>
{
static T2<uint32_t> *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->UInt2_ptr_typeID)
R(T2<uint32_t>*)obj->data;
else
 CATE(TE,"Value is not a UInt2Ref."));
} else
 CATE(TE,"Value is not a UInt2Ref."));
}
};
template <>
struct type_same<T2<uint32_t> *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->UInt2_ptr_typeID;
else
 R false;
}
};

SV GPUTimer_ptr_copy(CTX,NO);
void GPUTimer_ptr_destroy(CTX,NO);
SV GPUTimer_ptr_get_member(CTX,NO,SV);
void GPUTimer_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GPUTimer_ptr_funcs={
.destroy = GPUTimer_ptr_destroy,
.getMember = GPUTimer_ptr_get_member,
.setMember = GPUTimer_ptr_set_member
};
template <>
struct create_val<GPUTimer *>
{
static SV f(CTX ctx,GPUTimer*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(GPUTimer_ptr_funcs,obj,EXT->GPUTimer_ptr_typeID);
}
};
template <>
struct val_to_c<GPUTimer *>
{
static GPUTimer *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->GPUTimer_ptr_typeID)
R(GPUTimer*)obj->data;
else
 CATE(TE,"Value is not a GPUTimerRef."));
} else
 CATE(TE,"Value is not a GPUTimerRef."));
}
};
template <>
struct type_same<GPUTimer *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GPUTimer_ptr_typeID;
else
 R false;
}
};

SV RigidBody_ptr_copy(CTX,NO);
void RigidBody_ptr_destroy(CTX,NO);
SV RigidBody_ptr_get_member(CTX,NO,SV);
void RigidBody_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs RigidBody_ptr_funcs={
.destroy = RigidBody_ptr_destroy,
.getMember = RigidBody_ptr_get_member,
.setMember = RigidBody_ptr_set_member
};
template <>
struct create_val<RigidBody *>
{
static SV f(CTX ctx,RigidBody*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(RigidBody_ptr_funcs,obj,EXT->RigidBody_ptr_typeID);
}
};
template <>
struct val_to_c<RigidBody *>
{
static RigidBody *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->RigidBody_ptr_typeID)
R(RigidBody*)obj->data;
else
 CATE(TE,"Value is not a RigidBodyRef."));
} else
 CATE(TE,"Value is not a RigidBodyRef."));
}
};
template <>
struct type_same<RigidBody *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->RigidBody_ptr_typeID;
else
 R false;
}
};

SV Float2_ptr_copy(CTX,NO);
void Float2_ptr_destroy(CTX,NO);
SV Float2_ptr_get_member(CTX,NO,SV);
void Float2_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Float2_ptr_funcs={
.destroy = Float2_ptr_destroy,
.getMember = Float2_ptr_get_member,
.setMember = Float2_ptr_set_member
};
template <>
struct create_val<T2<float> *>
{
static SV f(CTX ctx,T2<float>*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(Float2_ptr_funcs,obj,EXT->Float2_ptr_typeID);
}
};
template <>
struct val_to_c<T2<float> *>
{
static T2<float> *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Float2_ptr_typeID)
R(T2<float>*)obj->data;
else
 CATE(TE,"Value is not a Float2Ref."));
} else
 CATE(TE,"Value is not a Float2Ref."));
}
};
template <>
struct type_same<T2<float> *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Float2_ptr_typeID;
else
 R false;
}
};

SV AudioSource_ptr_copy(CTX,NO);
void AudioSource_ptr_destroy(CTX,NO);
SV AudioSource_ptr_get_member(CTX,NO,SV);
void AudioSource_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs AudioSource_ptr_funcs={
.destroy = AudioSource_ptr_destroy,
.getMember = AudioSource_ptr_get_member,
.setMember = AudioSource_ptr_set_member
};
template <>
struct create_val<AudioSource *>
{
static SV f(CTX ctx,AudioSource*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(AudioSource_ptr_funcs,obj,EXT->AudioSource_ptr_typeID);
}
};
template <>
struct val_to_c<AudioSource *>
{
static AudioSource *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->AudioSource_ptr_typeID)
R(AudioSource*)obj->data;
else
 CATE(TE,"Value is not a AudioSourceRef."));
} else
 CATE(TE,"Value is not a AudioSourceRef."));
}
};
template <>
struct type_same<AudioSource *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->AudioSource_ptr_typeID;
else
 R false;
}
};

SV Camera_ptr_copy(CTX,NO);
void Camera_ptr_destroy(CTX,NO);
SV Camera_ptr_get_member(CTX,NO,SV);
void Camera_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Camera_ptr_funcs={
.destroy = Camera_ptr_destroy,
.getMember = Camera_ptr_get_member,
.setMember = Camera_ptr_set_member
};
template <>
struct create_val<Camera *>
{
static SV f(CTX ctx,Camera*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(Camera_ptr_funcs,obj,EXT->Camera_ptr_typeID);
}
};
template <>
struct val_to_c<Camera *>
{
static Camera *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Camera_ptr_typeID)
R(Camera*)obj->data;
else
 CATE(TE,"Value is not a CameraRef."));
} else
 CATE(TE,"Value is not a CameraRef."));
}
};
template <>
struct type_same<Camera *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Camera_ptr_typeID;
else
 R false;
}
};

SV Resource_ptr_copy(CTX,NO);
void Resource_ptr_destroy(CTX,NO);
SV Resource_ptr_get_member(CTX,NO,SV);
void Resource_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Resource_ptr_funcs={
.destroy = Resource_ptr_destroy,
.getMember = Resource_ptr_get_member,
.setMember = Resource_ptr_set_member
};
template <>
struct create_val<Resource *>
{
static SV f(CTX ctx,Resource*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(Resource_ptr_funcs,obj,EXT->Resource_ptr_typeID);
}
};
template <>
struct val_to_c<Resource *>
{
static Resource *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Resource_ptr_typeID)
R(Resource*)obj->data;
else
 CATE(TE,"Value is not a ResourceRef."));
} else
 CATE(TE,"Value is not a ResourceRef."));
}
};
template <>
struct type_same<Resource *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Resource_ptr_typeID;
else
 R false;
}
};

SV GfxShader_ptr_copy(CTX,NO);
void GfxShader_ptr_destroy(CTX,NO);
SV GfxShader_ptr_get_member(CTX,NO,SV);
void GfxShader_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxShader_ptr_funcs={
.destroy = GfxShader_ptr_destroy,
.getMember = GfxShader_ptr_get_member,
.setMember = GfxShader_ptr_set_member
};
template <>
struct create_val<GfxShader *>
{
static SV f(CTX ctx,GfxShader*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(GfxShader_ptr_funcs,obj,EXT->GfxShader_ptr_typeID);
}
};
template <>
struct val_to_c<GfxShader *>
{
static GfxShader *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->GfxShader_ptr_typeID)
R(GfxShader*)obj->data;
else
 CATE(TE,"Value is not a GfxShaderRef."));
} else
 CATE(TE,"Value is not a GfxShaderRef."));
}
};
template <>
struct type_same<GfxShader *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxShader_ptr_typeID;
else
 R false;
}
};

SV UInt4_ptr_copy(CTX,NO);
void UInt4_ptr_destroy(CTX,NO);
SV UInt4_ptr_get_member(CTX,NO,SV);
void UInt4_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs UInt4_ptr_funcs={
.destroy = UInt4_ptr_destroy,
.getMember = UInt4_ptr_get_member,
.setMember = UInt4_ptr_set_member
};
template <>
struct create_val<T4<uint32_t> *>
{
static SV f(CTX ctx,T4<uint32_t>*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(UInt4_ptr_funcs,obj,EXT->UInt4_ptr_typeID);
}
};
template <>
struct val_to_c<T4<uint32_t> *>
{
static T4<uint32_t> *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->UInt4_ptr_typeID)
R(T4<uint32_t>*)obj->data;
else
 CATE(TE,"Value is not a UInt4Ref."));
} else
 CATE(TE,"Value is not a UInt4Ref."));
}
};
template <>
struct type_same<T4<uint32_t> *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->UInt4_ptr_typeID;
else
 R false;
}
};

SV Int3_ptr_copy(CTX,NO);
void Int3_ptr_destroy(CTX,NO);
SV Int3_ptr_get_member(CTX,NO,SV);
void Int3_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Int3_ptr_funcs={
.destroy = Int3_ptr_destroy,
.getMember = Int3_ptr_get_member,
.setMember = Int3_ptr_set_member
};
template <>
struct create_val<T3<int32_t> *>
{
static SV f(CTX ctx,T3<int32_t>*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(Int3_ptr_funcs,obj,EXT->Int3_ptr_typeID);
}
};
template <>
struct val_to_c<T3<int32_t> *>
{
static T3<int32_t> *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Int3_ptr_typeID)
R(T3<int32_t>*)obj->data;
else
 CATE(TE,"Value is not a Int3Ref."));
} else
 CATE(TE,"Value is not a Int3Ref."));
}
};
template <>
struct type_same<T3<int32_t> *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Int3_ptr_typeID;
else
 R false;
}
};

SV ResizableData_ptr_copy(CTX,NO);
void ResizableData_ptr_destroy(CTX,NO);
SV ResizableData_ptr_get_member(CTX,NO,SV);
void ResizableData_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs ResizableData_ptr_funcs={
.destroy = ResizableData_ptr_destroy,
.getMember = ResizableData_ptr_get_member,
.setMember = ResizableData_ptr_set_member
};
template <>
struct create_val<ResizableData *>
{
static SV f(CTX ctx,ResizableData*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(ResizableData_ptr_funcs,obj,EXT->ResizableData_ptr_typeID);
}
};
template <>
struct val_to_c<ResizableData *>
{
static ResizableData *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->ResizableData_ptr_typeID)
R(ResizableData*)obj->data;
else
 CATE(TE,"Value is not a ResizableDataRef."));
} else
 CATE(TE,"Value is not a ResizableDataRef."));
}
};
template <>
struct type_same<ResizableData *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->ResizableData_ptr_typeID;
else
 R false;
}
};

SV Int4_ptr_copy(CTX,NO);
void Int4_ptr_destroy(CTX,NO);
SV Int4_ptr_get_member(CTX,NO,SV);
void Int4_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Int4_ptr_funcs={
.destroy = Int4_ptr_destroy,
.getMember = Int4_ptr_get_member,
.setMember = Int4_ptr_set_member
};
template <>
struct create_val<T4<int32_t> *>
{
static SV f(CTX ctx,T4<int32_t>*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(Int4_ptr_funcs,obj,EXT->Int4_ptr_typeID);
}
};
template <>
struct val_to_c<T4<int32_t> *>
{
static T4<int32_t> *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Int4_ptr_typeID)
R(T4<int32_t>*)obj->data;
else
 CATE(TE,"Value is not a Int4Ref."));
} else
 CATE(TE,"Value is not a Int4Ref."));
}
};
template <>
struct type_same<T4<int32_t> *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Int4_ptr_typeID;
else
 R false;
}
};

SV Float3_ptr_copy(CTX,NO);
void Float3_ptr_destroy(CTX,NO);
SV Float3_ptr_get_member(CTX,NO,SV);
void Float3_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Float3_ptr_funcs={
.destroy = Float3_ptr_destroy,
.getMember = Float3_ptr_get_member,
.setMember = Float3_ptr_set_member
};
template <>
struct create_val<T3<float> *>
{
static SV f(CTX ctx,T3<float>*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(Float3_ptr_funcs,obj,EXT->Float3_ptr_typeID);
}
};
template <>
struct val_to_c<T3<float> *>
{
static T3<float> *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Float3_ptr_typeID)
R(T3<float>*)obj->data;
else
 CATE(TE,"Value is not a Float3Ref."));
} else
 CATE(TE,"Value is not a Float3Ref."));
}
};
template <>
struct type_same<T3<float> *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Float3_ptr_typeID;
else
 R false;
}
};

SV GfxLODList_ptr_copy(CTX,NO);
void GfxLODList_ptr_destroy(CTX,NO);
SV GfxLODList_ptr_get_member(CTX,NO,SV);
void GfxLODList_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxLODList_ptr_funcs={
.destroy = GfxLODList_ptr_destroy,
.getMember = GfxLODList_ptr_get_member,
.setMember = GfxLODList_ptr_set_member
};
template <>
struct create_val<List<GfxLOD> *>
{
static SV f(CTX ctx,List<GfxLOD>*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(GfxLODList_ptr_funcs,obj,EXT->GfxLODList_ptr_typeID);
}
};
template <>
struct val_to_c<List<GfxLOD> *>
{
static List<GfxLOD> *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->GfxLODList_ptr_typeID)
R(List<GfxLOD>*)obj->data;
else
 CATE(TE,"Value is not a GfxLODListRef."));
} else
 CATE(TE,"Value is not a GfxLODListRef."));
}
};
template <>
struct type_same<List<GfxLOD> *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxLODList_ptr_typeID;
else
 R false;
}
};

SV GfxBuffer_ptr_copy(CTX,NO);
void GfxBuffer_ptr_destroy(CTX,NO);
SV GfxBuffer_ptr_get_member(CTX,NO,SV);
void GfxBuffer_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxBuffer_ptr_funcs={
.destroy = GfxBuffer_ptr_destroy,
.getMember = GfxBuffer_ptr_get_member,
.setMember = GfxBuffer_ptr_set_member
};
template <>
struct create_val<GfxBuffer *>
{
static SV f(CTX ctx,GfxBuffer*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(GfxBuffer_ptr_funcs,obj,EXT->GfxBuffer_ptr_typeID);
}
};
template <>
struct val_to_c<GfxBuffer *>
{
static GfxBuffer *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->GfxBuffer_ptr_typeID)
R(GfxBuffer*)obj->data;
else
 CATE(TE,"Value is not a GfxBufferRef."));
} else
 CATE(TE,"Value is not a GfxBufferRef."));
}
};
template <>
struct type_same<GfxBuffer *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxBuffer_ptr_typeID;
else
 R false;
}
};

SV Transform_ptr_copy(CTX,NO);
void Transform_ptr_destroy(CTX,NO);
SV Transform_ptr_get_member(CTX,NO,SV);
void Transform_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Transform_ptr_funcs={
.destroy = Transform_ptr_destroy,
.getMember = Transform_ptr_get_member,
.setMember = Transform_ptr_set_member
};
template <>
struct create_val<Transform *>
{
static SV f(CTX ctx,Transform*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(Transform_ptr_funcs,obj,EXT->Transform_ptr_typeID);
}
};
template <>
struct val_to_c<Transform *>
{
static Transform *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Transform_ptr_typeID)
R(Transform*)obj->data;
else
 CATE(TE,"Value is not a TransformRef."));
} else
 CATE(TE,"Value is not a TransformRef."));
}
};
template <>
struct type_same<Transform *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Transform_ptr_typeID;
else
 R false;
}
};

SV Quaternion_ptr_copy(CTX,NO);
void Quaternion_ptr_destroy(CTX,NO);
SV Quaternion_ptr_get_member(CTX,NO,SV);
void Quaternion_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Quaternion_ptr_funcs={
.destroy = Quaternion_ptr_destroy,
.getMember = Quaternion_ptr_get_member,
.setMember = Quaternion_ptr_set_member
};
template <>
struct create_val<Quaternion *>
{
static SV f(CTX ctx,Quaternion*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(Quaternion_ptr_funcs,obj,EXT->Quaternion_ptr_typeID);
}
};
template <>
struct val_to_c<Quaternion *>
{
static Quaternion *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Quaternion_ptr_typeID)
R(Quaternion*)obj->data;
else
 CATE(TE,"Value is not a QuaternionRef."));
} else
 CATE(TE,"Value is not a QuaternionRef."));
}
};
template <>
struct type_same<Quaternion *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Quaternion_ptr_typeID;
else
 R false;
}
};

SV Int2_ptr_copy(CTX,NO);
void Int2_ptr_destroy(CTX,NO);
SV Int2_ptr_get_member(CTX,NO,SV);
void Int2_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Int2_ptr_funcs={
.destroy = Int2_ptr_destroy,
.getMember = Int2_ptr_get_member,
.setMember = Int2_ptr_set_member
};
template <>
struct create_val<T2<int32_t> *>
{
static SV f(CTX ctx,T2<int32_t>*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(Int2_ptr_funcs,obj,EXT->Int2_ptr_typeID);
}
};
template <>
struct val_to_c<T2<int32_t> *>
{
static T2<int32_t> *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Int2_ptr_typeID)
R(T2<int32_t>*)obj->data;
else
 CATE(TE,"Value is not a Int2Ref."));
} else
 CATE(TE,"Value is not a Int2Ref."));
}
};
template <>
struct type_same<T2<int32_t> *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Int2_ptr_typeID;
else
 R false;
}
};

SV AudioWorld_ptr_copy(CTX,NO);
void AudioWorld_ptr_destroy(CTX,NO);
SV AudioWorld_ptr_get_member(CTX,NO,SV);
void AudioWorld_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs AudioWorld_ptr_funcs={
.destroy = AudioWorld_ptr_destroy,
.getMember = AudioWorld_ptr_get_member,
.setMember = AudioWorld_ptr_set_member
};
template <>
struct create_val<AudioWorld *>
{
static SV f(CTX ctx,AudioWorld*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(AudioWorld_ptr_funcs,obj,EXT->AudioWorld_ptr_typeID);
}
};
template <>
struct val_to_c<AudioWorld *>
{
static AudioWorld *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->AudioWorld_ptr_typeID)
R(AudioWorld*)obj->data;
else
 CATE(TE,"Value is not a AudioWorldRef."));
} else
 CATE(TE,"Value is not a AudioWorldRef."));
}
};
template <>
struct type_same<AudioWorld *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->AudioWorld_ptr_typeID;
else
 R false;
}
};

SV StrStrMap_ptr_copy(CTX,NO);
void StrStrMap_ptr_destroy(CTX,NO);
SV StrStrMap_ptr_get_member(CTX,NO,SV);
void StrStrMap_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs StrStrMap_ptr_funcs={
.destroy = StrStrMap_ptr_destroy,
.getMember = StrStrMap_ptr_get_member,
.setMember = StrStrMap_ptr_set_member
};
template <>
struct create_val<HashMap<String,String> *>
{
static SV f(CTX ctx,HashMap<String,String>*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(StrStrMap_ptr_funcs,obj,EXT->StrStrMap_ptr_typeID);
}
};
template <>
struct val_to_c<HashMap<String,String> *>
{
static HashMap<String,String> *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->StrStrMap_ptr_typeID)
R(HashMap<String,String>*)obj->data;
else
 CATE(TE,"Value is not a StrStrMapRef."));
} else
 CATE(TE,"Value is not a StrStrMapRef."));
}
};
template <>
struct type_same<HashMap<String,String> *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->StrStrMap_ptr_typeID;
else
 R false;
}
};

SV Light_ptr_copy(CTX,NO);
void Light_ptr_destroy(CTX,NO);
SV Light_ptr_get_member(CTX,NO,SV);
void Light_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Light_ptr_funcs={
.destroy = Light_ptr_destroy,
.getMember = Light_ptr_get_member,
.setMember = Light_ptr_set_member
};
template <>
struct create_val<Light *>
{
static SV f(CTX ctx,Light*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(Light_ptr_funcs,obj,EXT->Light_ptr_typeID);
}
};
template <>
struct val_to_c<Light *>
{
static Light *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Light_ptr_typeID)
R(Light*)obj->data;
else
 CATE(TE,"Value is not a LightRef."));
} else
 CATE(TE,"Value is not a LightRef."));
}
};
template <>
struct type_same<Light *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Light_ptr_typeID;
else
 R false;
}
};

SV LightPointData_ptr_copy(CTX,NO);
void LightPointData_ptr_destroy(CTX,NO);
SV LightPointData_ptr_get_member(CTX,NO,SV);
void LightPointData_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs LightPointData_ptr_funcs={
.destroy = LightPointData_ptr_destroy,
.getMember = LightPointData_ptr_get_member,
.setMember = LightPointData_ptr_set_member
};
template <>
struct create_val<LightPointData *>
{
static SV f(CTX ctx,LightPointData*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(LightPointData_ptr_funcs,obj,EXT->LightPointData_ptr_typeID);
}
};
template <>
struct val_to_c<LightPointData *>
{
static LightPointData *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->LightPointData_ptr_typeID)
R(LightPointData*)obj->data;
else
 CATE(TE,"Value is not a LightPointDataRef."));
} else
 CATE(TE,"Value is not a LightPointDataRef."));
}
};
template <>
struct type_same<LightPointData *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->LightPointData_ptr_typeID;
else
 R false;
}
};

SV Float4_ptr_copy(CTX,NO);
void Float4_ptr_destroy(CTX,NO);
SV Float4_ptr_get_member(CTX,NO,SV);
void Float4_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Float4_ptr_funcs={
.destroy = Float4_ptr_destroy,
.getMember = Float4_ptr_get_member,
.setMember = Float4_ptr_set_member
};
template <>
struct create_val<T4<float> *>
{
static SV f(CTX ctx,T4<float>*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(Float4_ptr_funcs,obj,EXT->Float4_ptr_typeID);
}
};
template <>
struct val_to_c<T4<float> *>
{
static T4<float> *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Float4_ptr_typeID)
R(T4<float>*)obj->data;
else
 CATE(TE,"Value is not a Float4Ref."));
} else
 CATE(TE,"Value is not a Float4Ref."));
}
};
template <>
struct type_same<T4<float> *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Float4_ptr_typeID;
else
 R false;
}
};

SV LightDirectionalData_ptr_copy(CTX,NO);
void LightDirectionalData_ptr_destroy(CTX,NO);
SV LightDirectionalData_ptr_get_member(CTX,NO,SV);
void LightDirectionalData_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs LightDirectionalData_ptr_funcs={
.destroy = LightDirectionalData_ptr_destroy,
.getMember = LightDirectionalData_ptr_get_member,
.setMember = LightDirectionalData_ptr_set_member
};
template <>
struct create_val<LightDirectionalData *>
{
static SV f(CTX ctx,LightDirectionalData*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(LightDirectionalData_ptr_funcs,obj,EXT->LightDirectionalData_ptr_typeID);
}
};
template <>
struct val_to_c<LightDirectionalData *>
{
static LightDirectionalData *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->LightDirectionalData_ptr_typeID)
R(LightDirectionalData*)obj->data;
else
 CATE(TE,"Value is not a LightDirectionalDataRef."));
} else
 CATE(TE,"Value is not a LightDirectionalDataRef."));
}
};
template <>
struct type_same<LightDirectionalData *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->LightDirectionalData_ptr_typeID;
else
 R false;
}
};

SV Matrix4x4_ptr_copy(CTX,NO);
void Matrix4x4_ptr_destroy(CTX,NO);
SV Matrix4x4_ptr_get_member(CTX,NO,SV);
void Matrix4x4_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Matrix4x4_ptr_funcs={
.destroy = Matrix4x4_ptr_destroy,
.getMember = Matrix4x4_ptr_get_member,
.setMember = Matrix4x4_ptr_set_member
};
template <>
struct create_val<Matrix4x4 *>
{
static SV f(CTX ctx,Matrix4x4*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(Matrix4x4_ptr_funcs,obj,EXT->Matrix4x4_ptr_typeID);
}
};
template <>
struct val_to_c<Matrix4x4 *>
{
static Matrix4x4 *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Matrix4x4_ptr_typeID)
R(Matrix4x4*)obj->data;
else
 CATE(TE,"Value is not a Matrix4x4Ref."));
} else
 CATE(TE,"Value is not a Matrix4x4Ref."));
}
};
template <>
struct type_same<Matrix4x4 *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Matrix4x4_ptr_typeID;
else
 R false;
}
};

SV UInt3_ptr_copy(CTX,NO);
void UInt3_ptr_destroy(CTX,NO);
SV UInt3_ptr_get_member(CTX,NO,SV);
void UInt3_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs UInt3_ptr_funcs={
.destroy = UInt3_ptr_destroy,
.getMember = UInt3_ptr_get_member,
.setMember = UInt3_ptr_set_member
};
template <>
struct create_val<T3<uint32_t> *>
{
static SV f(CTX ctx,T3<uint32_t>*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(UInt3_ptr_funcs,obj,EXT->UInt3_ptr_typeID);
}
};
template <>
struct val_to_c<T3<uint32_t> *>
{
static T3<uint32_t> *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->UInt3_ptr_typeID)
R(T3<uint32_t>*)obj->data;
else
 CATE(TE,"Value is not a UInt3Ref."));
} else
 CATE(TE,"Value is not a UInt3Ref."));
}
};
template <>
struct type_same<T3<uint32_t> *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->UInt3_ptr_typeID;
else
 R false;
}
};

SV LightSpotData_ptr_copy(CTX,NO);
void LightSpotData_ptr_destroy(CTX,NO);
SV LightSpotData_ptr_get_member(CTX,NO,SV);
void LightSpotData_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs LightSpotData_ptr_funcs={
.destroy = LightSpotData_ptr_destroy,
.getMember = LightSpotData_ptr_get_member,
.setMember = LightSpotData_ptr_set_member
};
template <>
struct create_val<LightSpotData *>
{
static SV f(CTX ctx,LightSpotData*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(LightSpotData_ptr_funcs,obj,EXT->LightSpotData_ptr_typeID);
}
};
template <>
struct val_to_c<LightSpotData *>
{
static LightSpotData *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->LightSpotData_ptr_typeID)
R(LightSpotData*)obj->data;
else
 CATE(TE,"Value is not a LightSpotDataRef."));
} else
 CATE(TE,"Value is not a LightSpotDataRef."));
}
};
template <>
struct type_same<LightSpotData *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->LightSpotData_ptr_typeID;
else
 R false;
}
};

SV AudioDevice_ptr_copy(CTX,NO);
void AudioDevice_ptr_destroy(CTX,NO);
SV AudioDevice_ptr_get_member(CTX,NO,SV);
void AudioDevice_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs AudioDevice_ptr_funcs={
.destroy = AudioDevice_ptr_destroy,
.getMember = AudioDevice_ptr_get_member,
.setMember = AudioDevice_ptr_set_member
};
template <>
struct create_val<AudioDevice *>
{
static SV f(CTX ctx,AudioDevice*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(AudioDevice_ptr_funcs,obj,EXT->AudioDevice_ptr_typeID);
}
};
template <>
struct val_to_c<AudioDevice *>
{
static AudioDevice *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->AudioDevice_ptr_typeID)
R(AudioDevice*)obj->data;
else
 CATE(TE,"Value is not a AudioDeviceRef."));
} else
 CATE(TE,"Value is not a AudioDeviceRef."));
}
};
template <>
struct type_same<AudioDevice *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->AudioDevice_ptr_typeID;
else
 R false;
}
};

SV GfxLOD_ptr_copy(CTX,NO);
void GfxLOD_ptr_destroy(CTX,NO);
SV GfxLOD_ptr_get_member(CTX,NO,SV);
void GfxLOD_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxLOD_ptr_funcs={
.destroy = GfxLOD_ptr_destroy,
.getMember = GfxLOD_ptr_get_member,
.setMember = GfxLOD_ptr_set_member
};
template <>
struct create_val<GfxLOD *>
{
static SV f(CTX ctx,GfxLOD*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(GfxLOD_ptr_funcs,obj,EXT->GfxLOD_ptr_typeID);
}
};
template <>
struct val_to_c<GfxLOD *>
{
static GfxLOD *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->GfxLOD_ptr_typeID)
R(GfxLOD*)obj->data;
else
 CATE(TE,"Value is not a GfxLODRef."));
} else
 CATE(TE,"Value is not a GfxLODRef."));
}
};
template <>
struct type_same<GfxLOD *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxLOD_ptr_typeID;
else
 R false;
}
};

SV File_ptr_copy(CTX,NO);
void File_ptr_destroy(CTX,NO);
SV File_ptr_get_member(CTX,NO,SV);
void File_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs File_ptr_funcs={
.destroy = File_ptr_destroy,
.getMember = File_ptr_get_member,
.setMember = File_ptr_set_member
};
template <>
struct create_val<File *>
{
static SV f(CTX ctx,File*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(File_ptr_funcs,obj,EXT->File_ptr_typeID);
}
};
template <>
struct val_to_c<File *>
{
static File *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->File_ptr_typeID)
R(File*)obj->data;
else
 CATE(TE,"Value is not a FileRef."));
} else
 CATE(TE,"Value is not a FileRef."));
}
};
template <>
struct type_same<File *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->File_ptr_typeID;
else
 R false;
}
};

SV AABB_ptr_copy(CTX,NO);
void AABB_ptr_destroy(CTX,NO);
SV AABB_ptr_get_member(CTX,NO,SV);
void AABB_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs AABB_ptr_funcs={
.destroy = AABB_ptr_destroy,
.getMember = AABB_ptr_get_member,
.setMember = AABB_ptr_set_member
};
template <>
struct create_val<AABB *>
{
static SV f(CTX ctx,AABB*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(AABB_ptr_funcs,obj,EXT->AABB_ptr_typeID);
}
};
template <>
struct val_to_c<AABB *>
{
static AABB *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->AABB_ptr_typeID)
R(AABB*)obj->data;
else
 CATE(TE,"Value is not a AABBRef."));
} else
 CATE(TE,"Value is not a AABBRef."));
}
};
template <>
struct type_same<AABB *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->AABB_ptr_typeID;
else
 R false;
}
};

SV List_ptr_copy(CTX,NO);
void List_ptr_destroy(CTX,NO);
SV List_ptr_get_member(CTX,NO,SV);
void List_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs List_ptr_funcs={
.destroy = List_ptr_destroy,
.getMember = List_ptr_get_member,
.setMember = List_ptr_set_member
};
template <>
struct create_val<List<scripting::Value*> *>
{
static SV f(CTX ctx,List<scripting::Value*>*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(List_ptr_funcs,obj,EXT->List_ptr_typeID);
}
};
template <>
struct val_to_c<List<scripting::Value*> *>
{
static List<scripting::Value*> *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->List_ptr_typeID)
R(List<scripting::Value*>*)obj->data;
else
 CATE(TE,"Value is not a ListRef."));
} else
 CATE(TE,"Value is not a ListRef."));
}
};
template <>
struct type_same<List<scripting::Value*> *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->List_ptr_typeID;
else
 R false;
}
};

SV Audio_ptr_copy(CTX,NO);
void Audio_ptr_destroy(CTX,NO);
SV Audio_ptr_get_member(CTX,NO,SV);
void Audio_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Audio_ptr_funcs={
.destroy = Audio_ptr_destroy,
.getMember = Audio_ptr_get_member,
.setMember = Audio_ptr_set_member
};
template <>
struct create_val<Audio *>
{
static SV f(CTX ctx,Audio*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(Audio_ptr_funcs,obj,EXT->Audio_ptr_typeID);
}
};
template <>
struct val_to_c<Audio *>
{
static Audio *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Audio_ptr_typeID)
R(Audio*)obj->data;
else
 CATE(TE,"Value is not a AudioRef."));
} else
 CATE(TE,"Value is not a AudioRef."));
}
};
template <>
struct type_same<Audio *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Audio_ptr_typeID;
else
 R false;
}
};

SV GfxSubModelList_ptr_copy(CTX,NO);
void GfxSubModelList_ptr_destroy(CTX,NO);
SV GfxSubModelList_ptr_get_member(CTX,NO,SV);
void GfxSubModelList_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxSubModelList_ptr_funcs={
.destroy = GfxSubModelList_ptr_destroy,
.getMember = GfxSubModelList_ptr_get_member,
.setMember = GfxSubModelList_ptr_set_member
};
template <>
struct create_val<List<GfxModel::SubModel> *>
{
static SV f(CTX ctx,List<GfxModel::SubModel>*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(GfxSubModelList_ptr_funcs,obj,EXT->GfxSubModelList_ptr_typeID);
}
};
template <>
struct val_to_c<List<GfxModel::SubModel> *>
{
static List<GfxModel::SubModel> *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->GfxSubModelList_ptr_typeID)
R(List<GfxModel::SubModel>*)obj->data;
else
 CATE(TE,"Value is not a GfxSubModelListRef."));
} else
 CATE(TE,"Value is not a GfxSubModelListRef."));
}
};
template <>
struct type_same<List<GfxModel::SubModel> *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxSubModelList_ptr_typeID;
else
 R false;
}
};

SV GfxModel_ptr_copy(CTX,NO);
void GfxModel_ptr_destroy(CTX,NO);
SV GfxModel_ptr_get_member(CTX,NO,SV);
void GfxModel_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxModel_ptr_funcs={
.destroy = GfxModel_ptr_destroy,
.getMember = GfxModel_ptr_get_member,
.setMember = GfxModel_ptr_set_member
};
template <>
struct create_val<GfxModel *>
{
static SV f(CTX ctx,GfxModel*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(GfxModel_ptr_funcs,obj,EXT->GfxModel_ptr_typeID);
}
};
template <>
struct val_to_c<GfxModel *>
{
static GfxModel *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->GfxModel_ptr_typeID)
R(GfxModel*)obj->data;
else
 CATE(TE,"Value is not a GfxModelRef."));
} else
 CATE(TE,"Value is not a GfxModelRef."));
}
};
template <>
struct type_same<GfxModel *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxModel_ptr_typeID;
else
 R false;
}
};

SV Matrix3x3_ptr_copy(CTX,NO);
void Matrix3x3_ptr_destroy(CTX,NO);
SV Matrix3x3_ptr_get_member(CTX,NO,SV);
void Matrix3x3_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs Matrix3x3_ptr_funcs={
.destroy = Matrix3x3_ptr_destroy,
.getMember = Matrix3x3_ptr_get_member,
.setMember = Matrix3x3_ptr_set_member
};
template <>
struct create_val<Matrix3x3 *>
{
static SV f(CTX ctx,Matrix3x3*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(Matrix3x3_ptr_funcs,obj,EXT->Matrix3x3_ptr_typeID);
}
};
template <>
struct val_to_c<Matrix3x3 *>
{
static Matrix3x3 *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->Matrix3x3_ptr_typeID)
R(Matrix3x3*)obj->data;
else
 CATE(TE,"Value is not a Matrix3x3Ref."));
} else
 CATE(TE,"Value is not a Matrix3x3Ref."));
}
};
template <>
struct type_same<Matrix3x3 *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->Matrix3x3_ptr_typeID;
else
 R false;
}
};

SV GfxDebugDrawer_ptr_copy(CTX,NO);
void GfxDebugDrawer_ptr_destroy(CTX,NO);
SV GfxDebugDrawer_ptr_get_member(CTX,NO,SV);
void GfxDebugDrawer_ptr_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs GfxDebugDrawer_ptr_funcs={
.destroy = GfxDebugDrawer_ptr_destroy,
.getMember = GfxDebugDrawer_ptr_get_member,
.setMember = GfxDebugDrawer_ptr_set_member
};
template <>
struct create_val<GfxDebugDrawer *>
{
static SV f(CTX ctx,GfxDebugDrawer*obj)
{
AllocInfo i=getAllocInfo((void*)obj);
i.scriptRef = true;
setAllocInfo((void *)obj, i);
R S::createNativeObject(GfxDebugDrawer_ptr_funcs,obj,EXT->GfxDebugDrawer_ptr_typeID);
}
};
template <>
struct val_to_c<GfxDebugDrawer *>
{
static GfxDebugDrawer *f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
{
NO obj=(NO)head;
if(obj->typeID==EXT->GfxDebugDrawer_ptr_typeID)
R(GfxDebugDrawer*)obj->data;
else
 CATE(TE,"Value is not a GfxDebugDrawerRef."));
} else
 CATE(TE,"Value is not a GfxDebugDrawerRef."));
}
};
template <>
struct type_same<GfxDebugDrawer *>
{
static bool f(CTX ctx,const SV head)
{
if(head->type==S::ValueType::NativeObject)
R((NO)head)->typeID==EXT->GfxDebugDrawer_ptr_typeID;
else
 R false;
}
};

SV ResType___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,UFOF("ResType::__eq__")));
size_t F;
if(!TS(a[0],ResType))
CATE(TE,FAE("ResType::ResType","ResType")));
else
 F=(size_t)((NO)a[0])->data;
size_t other;
if(!TS(a[1],ResType))
CATE(VE,UFOF("ResType::__eq__")));
else
 other=(size_t)((NO)a[1])->data;
return S::createBoolean(F == other);
}SV ResType_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("ResType");
EI(keyStr=="__eq__")
R CNF(ResType___eq__);
EI(keyStr=="GfxMaterialType")R S::createNativeObject(ResType_funcs,(void *)3,EXT->ResType_typeID);
EI(keyStr=="ScriptType")R S::createNativeObject(ResType_funcs,(void *)6,EXT->ResType_typeID);
EI(keyStr=="GfxTextureType")R S::createNativeObject(ResType_funcs,(void *)1,EXT->ResType_typeID);
EI(keyStr=="GfxMeshType")R S::createNativeObject(ResType_funcs,(void *)2,EXT->ResType_typeID);
EI(keyStr=="AudioType")R S::createNativeObject(ResType_funcs,(void *)8,EXT->ResType_typeID);
EI(keyStr=="FontType")R S::createNativeObject(ResType_funcs,(void *)9,EXT->ResType_typeID);
EI(keyStr=="GfxModelType")R S::createNativeObject(ResType_funcs,(void *)4,EXT->ResType_typeID);
EI(keyStr=="PhysicsShapeType")R S::createNativeObject(ResType_funcs,(void *)7,EXT->ResType_typeID);
EI(keyStr=="GfxShaderType")R S::createNativeObject(ResType_funcs,(void *)0,EXT->ResType_typeID);
EI(keyStr=="SceneType")R S::createNativeObject(ResType_funcs,(void *)5,EXT->ResType_typeID);

else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("ResType");
EI(keyStr=="__eq__")
R CNF(ResType___eq__);
EI(keyStr=="GfxMaterialType")R S::createNativeObject(ResType_funcs,(void *)3,EXT->ResType_typeID);
EI(keyStr=="ScriptType")R S::createNativeObject(ResType_funcs,(void *)6,EXT->ResType_typeID);
EI(keyStr=="GfxTextureType")R S::createNativeObject(ResType_funcs,(void *)1,EXT->ResType_typeID);
EI(keyStr=="GfxMeshType")R S::createNativeObject(ResType_funcs,(void *)2,EXT->ResType_typeID);
EI(keyStr=="AudioType")R S::createNativeObject(ResType_funcs,(void *)8,EXT->ResType_typeID);
EI(keyStr=="FontType")R S::createNativeObject(ResType_funcs,(void *)9,EXT->ResType_typeID);
EI(keyStr=="GfxModelType")R S::createNativeObject(ResType_funcs,(void *)4,EXT->ResType_typeID);
EI(keyStr=="PhysicsShapeType")R S::createNativeObject(ResType_funcs,(void *)7,EXT->ResType_typeID);
EI(keyStr=="GfxShaderType")R S::createNativeObject(ResType_funcs,(void *)0,EXT->ResType_typeID);
EI(keyStr=="SceneType")R S::createNativeObject(ResType_funcs,(void *)5,EXT->ResType_typeID);

else
 CATE(KE,"Unknown member."));
}
}
}
void ResType_set_member(CTX ctx,NO,SV,SV){CATE(KE,"Enums are read-only."));}
SV GfxPrimitive___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,UFOF("GfxPrimitive::__eq__")));
size_t F;
if(!TS(a[0],GfxPrimitive))
CATE(TE,FAE("GfxPrimitive::GfxPrimitive","GfxPrimitive")));
else
 F=(size_t)((NO)a[0])->data;
size_t other;
if(!TS(a[1],GfxPrimitive))
CATE(VE,UFOF("GfxPrimitive::__eq__")));
else
 other=(size_t)((NO)a[1])->data;
return S::createBoolean(F == other);
}SV GfxPrimitive_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxPrimitive");
EI(keyStr=="__eq__")
R CNF(GfxPrimitive___eq__);
EI(keyStr=="GfxLineStrip")R S::createNativeObject(GfxPrimitive_funcs,(void *)1,EXT->GfxPrimitive_typeID);
EI(keyStr=="GfxTriangleFan")R S::createNativeObject(GfxPrimitive_funcs,(void *)5,EXT->GfxPrimitive_typeID);
EI(keyStr=="GfxTriangles")R S::createNativeObject(GfxPrimitive_funcs,(void *)6,EXT->GfxPrimitive_typeID);
EI(keyStr=="GfxPoints")R S::createNativeObject(GfxPrimitive_funcs,(void *)0,EXT->GfxPrimitive_typeID);
EI(keyStr=="GfxLines")R S::createNativeObject(GfxPrimitive_funcs,(void *)3,EXT->GfxPrimitive_typeID);
EI(keyStr=="GfxLineLoop")R S::createNativeObject(GfxPrimitive_funcs,(void *)2,EXT->GfxPrimitive_typeID);
EI(keyStr=="GfxTriangleStrip")R S::createNativeObject(GfxPrimitive_funcs,(void *)4,EXT->GfxPrimitive_typeID);
EI(keyStr=="GfxPatches")R S::createNativeObject(GfxPrimitive_funcs,(void *)7,EXT->GfxPrimitive_typeID);

else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxPrimitive");
EI(keyStr=="__eq__")
R CNF(GfxPrimitive___eq__);
EI(keyStr=="GfxLineStrip")R S::createNativeObject(GfxPrimitive_funcs,(void *)1,EXT->GfxPrimitive_typeID);
EI(keyStr=="GfxTriangleFan")R S::createNativeObject(GfxPrimitive_funcs,(void *)5,EXT->GfxPrimitive_typeID);
EI(keyStr=="GfxTriangles")R S::createNativeObject(GfxPrimitive_funcs,(void *)6,EXT->GfxPrimitive_typeID);
EI(keyStr=="GfxPoints")R S::createNativeObject(GfxPrimitive_funcs,(void *)0,EXT->GfxPrimitive_typeID);
EI(keyStr=="GfxLines")R S::createNativeObject(GfxPrimitive_funcs,(void *)3,EXT->GfxPrimitive_typeID);
EI(keyStr=="GfxLineLoop")R S::createNativeObject(GfxPrimitive_funcs,(void *)2,EXT->GfxPrimitive_typeID);
EI(keyStr=="GfxTriangleStrip")R S::createNativeObject(GfxPrimitive_funcs,(void *)4,EXT->GfxPrimitive_typeID);
EI(keyStr=="GfxPatches")R S::createNativeObject(GfxPrimitive_funcs,(void *)7,EXT->GfxPrimitive_typeID);

else
 CATE(KE,"Unknown member."));
}
}
}
void GfxPrimitive_set_member(CTX ctx,NO,SV,SV){CATE(KE,"Enums are read-only."));}
SV GfxDepthFunction___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,UFOF("GfxDepthFunction::__eq__")));
size_t F;
if(!TS(a[0],GfxDepthFunction))
CATE(TE,FAE("GfxDepthFunction::GfxDepthFunction","GfxDepthFunction")));
else
 F=(size_t)((NO)a[0])->data;
size_t other;
if(!TS(a[1],GfxDepthFunction))
CATE(VE,UFOF("GfxDepthFunction::__eq__")));
else
 other=(size_t)((NO)a[1])->data;
return S::createBoolean(F == other);
}SV GfxDepthFunction_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxDepthFunction");
EI(keyStr=="__eq__")
R CNF(GfxDepthFunction___eq__);
EI(keyStr=="GfxGreaterEqual")R S::createNativeObject(GfxDepthFunction_funcs,(void *)6,EXT->GfxDepthFunction_typeID);
EI(keyStr=="GfxNever")R S::createNativeObject(GfxDepthFunction_funcs,(void *)0,EXT->GfxDepthFunction_typeID);
EI(keyStr=="GfxLessEqual")R S::createNativeObject(GfxDepthFunction_funcs,(void *)3,EXT->GfxDepthFunction_typeID);
EI(keyStr=="GfxAlways")R S::createNativeObject(GfxDepthFunction_funcs,(void *)7,EXT->GfxDepthFunction_typeID);
EI(keyStr=="GfxLess")R S::createNativeObject(GfxDepthFunction_funcs,(void *)1,EXT->GfxDepthFunction_typeID);
EI(keyStr=="GfxGreater")R S::createNativeObject(GfxDepthFunction_funcs,(void *)4,EXT->GfxDepthFunction_typeID);
EI(keyStr=="GfxEqual")R S::createNativeObject(GfxDepthFunction_funcs,(void *)2,EXT->GfxDepthFunction_typeID);
EI(keyStr=="GfxNotEqual")R S::createNativeObject(GfxDepthFunction_funcs,(void *)5,EXT->GfxDepthFunction_typeID);

else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxDepthFunction");
EI(keyStr=="__eq__")
R CNF(GfxDepthFunction___eq__);
EI(keyStr=="GfxGreaterEqual")R S::createNativeObject(GfxDepthFunction_funcs,(void *)6,EXT->GfxDepthFunction_typeID);
EI(keyStr=="GfxNever")R S::createNativeObject(GfxDepthFunction_funcs,(void *)0,EXT->GfxDepthFunction_typeID);
EI(keyStr=="GfxLessEqual")R S::createNativeObject(GfxDepthFunction_funcs,(void *)3,EXT->GfxDepthFunction_typeID);
EI(keyStr=="GfxAlways")R S::createNativeObject(GfxDepthFunction_funcs,(void *)7,EXT->GfxDepthFunction_typeID);
EI(keyStr=="GfxLess")R S::createNativeObject(GfxDepthFunction_funcs,(void *)1,EXT->GfxDepthFunction_typeID);
EI(keyStr=="GfxGreater")R S::createNativeObject(GfxDepthFunction_funcs,(void *)4,EXT->GfxDepthFunction_typeID);
EI(keyStr=="GfxEqual")R S::createNativeObject(GfxDepthFunction_funcs,(void *)2,EXT->GfxDepthFunction_typeID);
EI(keyStr=="GfxNotEqual")R S::createNativeObject(GfxDepthFunction_funcs,(void *)5,EXT->GfxDepthFunction_typeID);

else
 CATE(KE,"Unknown member."));
}
}
}
void GfxDepthFunction_set_member(CTX ctx,NO,SV,SV){CATE(KE,"Enums are read-only."));}
SV GfxBlendMode___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,UFOF("GfxBlendMode::__eq__")));
size_t F;
if(!TS(a[0],GfxBlendMode))
CATE(TE,FAE("GfxBlendMode::GfxBlendMode","GfxBlendMode")));
else
 F=(size_t)((NO)a[0])->data;
size_t other;
if(!TS(a[1],GfxBlendMode))
CATE(VE,UFOF("GfxBlendMode::__eq__")));
else
 other=(size_t)((NO)a[1])->data;
return S::createBoolean(F == other);
}SV GfxBlendMode_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxBlendMode");
EI(keyStr=="__eq__")
R CNF(GfxBlendMode___eq__);
EI(keyStr=="GfxReverseSubtract")R S::createNativeObject(GfxBlendMode_funcs,(void *)2,EXT->GfxBlendMode_typeID);
EI(keyStr=="GfxAdd")R S::createNativeObject(GfxBlendMode_funcs,(void *)0,EXT->GfxBlendMode_typeID);
EI(keyStr=="GfxSubtract")R S::createNativeObject(GfxBlendMode_funcs,(void *)1,EXT->GfxBlendMode_typeID);

else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxBlendMode");
EI(keyStr=="__eq__")
R CNF(GfxBlendMode___eq__);
EI(keyStr=="GfxReverseSubtract")R S::createNativeObject(GfxBlendMode_funcs,(void *)2,EXT->GfxBlendMode_typeID);
EI(keyStr=="GfxAdd")R S::createNativeObject(GfxBlendMode_funcs,(void *)0,EXT->GfxBlendMode_typeID);
EI(keyStr=="GfxSubtract")R S::createNativeObject(GfxBlendMode_funcs,(void *)1,EXT->GfxBlendMode_typeID);

else
 CATE(KE,"Unknown member."));
}
}
}
void GfxBlendMode_set_member(CTX ctx,NO,SV,SV){CATE(KE,"Enums are read-only."));}
SV GfxBlendFactor___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,UFOF("GfxBlendFactor::__eq__")));
size_t F;
if(!TS(a[0],GfxBlendFactor))
CATE(TE,FAE("GfxBlendFactor::GfxBlendFactor","GfxBlendFactor")));
else
 F=(size_t)((NO)a[0])->data;
size_t other;
if(!TS(a[1],GfxBlendFactor))
CATE(VE,UFOF("GfxBlendFactor::__eq__")));
else
 other=(size_t)((NO)a[1])->data;
return S::createBoolean(F == other);
}SV GfxBlendFactor_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxBlendFactor");
EI(keyStr=="__eq__")
R CNF(GfxBlendFactor___eq__);
EI(keyStr=="GfxZero")R S::createNativeObject(GfxBlendFactor_funcs,(void *)0,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxSrcColor")R S::createNativeObject(GfxBlendFactor_funcs,(void *)2,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxOneMinusSrcAlpha")R S::createNativeObject(GfxBlendFactor_funcs,(void *)7,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxConstantAlpha")R S::createNativeObject(GfxBlendFactor_funcs,(void *)12,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxDstAlpha")R S::createNativeObject(GfxBlendFactor_funcs,(void *)8,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxSrcAlpha")R S::createNativeObject(GfxBlendFactor_funcs,(void *)6,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxOneMinusDstColor")R S::createNativeObject(GfxBlendFactor_funcs,(void *)5,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxDstColor")R S::createNativeObject(GfxBlendFactor_funcs,(void *)4,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxOneMinusConstantColor")R S::createNativeObject(GfxBlendFactor_funcs,(void *)11,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxOneMinusSrcColor")R S::createNativeObject(GfxBlendFactor_funcs,(void *)3,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxConstantColor")R S::createNativeObject(GfxBlendFactor_funcs,(void *)10,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxOneMinusConstantAlpha")R S::createNativeObject(GfxBlendFactor_funcs,(void *)13,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxOne")R S::createNativeObject(GfxBlendFactor_funcs,(void *)1,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxOneMinusDstAlpha")R S::createNativeObject(GfxBlendFactor_funcs,(void *)9,EXT->GfxBlendFactor_typeID);

else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxBlendFactor");
EI(keyStr=="__eq__")
R CNF(GfxBlendFactor___eq__);
EI(keyStr=="GfxZero")R S::createNativeObject(GfxBlendFactor_funcs,(void *)0,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxSrcColor")R S::createNativeObject(GfxBlendFactor_funcs,(void *)2,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxOneMinusSrcAlpha")R S::createNativeObject(GfxBlendFactor_funcs,(void *)7,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxConstantAlpha")R S::createNativeObject(GfxBlendFactor_funcs,(void *)12,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxDstAlpha")R S::createNativeObject(GfxBlendFactor_funcs,(void *)8,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxSrcAlpha")R S::createNativeObject(GfxBlendFactor_funcs,(void *)6,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxOneMinusDstColor")R S::createNativeObject(GfxBlendFactor_funcs,(void *)5,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxDstColor")R S::createNativeObject(GfxBlendFactor_funcs,(void *)4,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxOneMinusConstantColor")R S::createNativeObject(GfxBlendFactor_funcs,(void *)11,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxOneMinusSrcColor")R S::createNativeObject(GfxBlendFactor_funcs,(void *)3,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxConstantColor")R S::createNativeObject(GfxBlendFactor_funcs,(void *)10,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxOneMinusConstantAlpha")R S::createNativeObject(GfxBlendFactor_funcs,(void *)13,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxOne")R S::createNativeObject(GfxBlendFactor_funcs,(void *)1,EXT->GfxBlendFactor_typeID);
EI(keyStr=="GfxOneMinusDstAlpha")R S::createNativeObject(GfxBlendFactor_funcs,(void *)9,EXT->GfxBlendFactor_typeID);

else
 CATE(KE,"Unknown member."));
}
}
}
void GfxBlendFactor_set_member(CTX ctx,NO,SV,SV){CATE(KE,"Enums are read-only."));}
SV GfxCullMode___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,UFOF("GfxCullMode::__eq__")));
size_t F;
if(!TS(a[0],GfxCullMode))
CATE(TE,FAE("GfxCullMode::GfxCullMode","GfxCullMode")));
else
 F=(size_t)((NO)a[0])->data;
size_t other;
if(!TS(a[1],GfxCullMode))
CATE(VE,UFOF("GfxCullMode::__eq__")));
else
 other=(size_t)((NO)a[1])->data;
return S::createBoolean(F == other);
}SV GfxCullMode_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxCullMode");
EI(keyStr=="__eq__")
R CNF(GfxCullMode___eq__);
EI(keyStr=="GfxCullNone")R S::createNativeObject(GfxCullMode_funcs,(void *)0,EXT->GfxCullMode_typeID);
EI(keyStr=="GfxCullBack")R S::createNativeObject(GfxCullMode_funcs,(void *)2,EXT->GfxCullMode_typeID);
EI(keyStr=="GfxCullFront")R S::createNativeObject(GfxCullMode_funcs,(void *)1,EXT->GfxCullMode_typeID);

else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxCullMode");
EI(keyStr=="__eq__")
R CNF(GfxCullMode___eq__);
EI(keyStr=="GfxCullNone")R S::createNativeObject(GfxCullMode_funcs,(void *)0,EXT->GfxCullMode_typeID);
EI(keyStr=="GfxCullBack")R S::createNativeObject(GfxCullMode_funcs,(void *)2,EXT->GfxCullMode_typeID);
EI(keyStr=="GfxCullFront")R S::createNativeObject(GfxCullMode_funcs,(void *)1,EXT->GfxCullMode_typeID);

else
 CATE(KE,"Unknown member."));
}
}
}
void GfxCullMode_set_member(CTX ctx,NO,SV,SV){CATE(KE,"Enums are read-only."));}
SV GfxWinding___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,UFOF("GfxWinding::__eq__")));
size_t F;
if(!TS(a[0],GfxWinding))
CATE(TE,FAE("GfxWinding::GfxWinding","GfxWinding")));
else
 F=(size_t)((NO)a[0])->data;
size_t other;
if(!TS(a[1],GfxWinding))
CATE(VE,UFOF("GfxWinding::__eq__")));
else
 other=(size_t)((NO)a[1])->data;
return S::createBoolean(F == other);
}SV GfxWinding_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxWinding");
EI(keyStr=="__eq__")
R CNF(GfxWinding___eq__);
EI(keyStr=="GfxCCW")R S::createNativeObject(GfxWinding_funcs,(void *)1,EXT->GfxWinding_typeID);
EI(keyStr=="GfxCW")R S::createNativeObject(GfxWinding_funcs,(void *)0,EXT->GfxWinding_typeID);

else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxWinding");
EI(keyStr=="__eq__")
R CNF(GfxWinding___eq__);
EI(keyStr=="GfxCCW")R S::createNativeObject(GfxWinding_funcs,(void *)1,EXT->GfxWinding_typeID);
EI(keyStr=="GfxCW")R S::createNativeObject(GfxWinding_funcs,(void *)0,EXT->GfxWinding_typeID);

else
 CATE(KE,"Unknown member."));
}
}
}
void GfxWinding_set_member(CTX ctx,NO,SV,SV){CATE(KE,"Enums are read-only."));}
SV GfxVertexAttribPurpose___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,UFOF("GfxVertexAttribPurpose::__eq__")));
size_t F;
if(!TS(a[0],GfxVertexAttribPurpose))
CATE(TE,FAE("GfxVertexAttribPurpose::GfxVertexAttribPurpose","GfxVertexAttribPurpose")));
else
 F=(size_t)((NO)a[0])->data;
size_t other;
if(!TS(a[1],GfxVertexAttribPurpose))
CATE(VE,UFOF("GfxVertexAttribPurpose::__eq__")));
else
 other=(size_t)((NO)a[1])->data;
return S::createBoolean(F == other);
}SV GfxVertexAttribPurpose_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxVertexAttribPurpose");
EI(keyStr=="__eq__")
R CNF(GfxVertexAttribPurpose___eq__);
EI(keyStr=="GfxTexCoord")R S::createNativeObject(GfxVertexAttribPurpose_funcs,(void *)4,EXT->GfxVertexAttribPurpose_typeID);
EI(keyStr=="GfxTangent")R S::createNativeObject(GfxVertexAttribPurpose_funcs,(void *)2,EXT->GfxVertexAttribPurpose_typeID);
EI(keyStr=="GfxPosition")R S::createNativeObject(GfxVertexAttribPurpose_funcs,(void *)0,EXT->GfxVertexAttribPurpose_typeID);
EI(keyStr=="GfxNormal")R S::createNativeObject(GfxVertexAttribPurpose_funcs,(void *)1,EXT->GfxVertexAttribPurpose_typeID);
EI(keyStr=="GfxColor")R S::createNativeObject(GfxVertexAttribPurpose_funcs,(void *)3,EXT->GfxVertexAttribPurpose_typeID);

else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxVertexAttribPurpose");
EI(keyStr=="__eq__")
R CNF(GfxVertexAttribPurpose___eq__);
EI(keyStr=="GfxTexCoord")R S::createNativeObject(GfxVertexAttribPurpose_funcs,(void *)4,EXT->GfxVertexAttribPurpose_typeID);
EI(keyStr=="GfxTangent")R S::createNativeObject(GfxVertexAttribPurpose_funcs,(void *)2,EXT->GfxVertexAttribPurpose_typeID);
EI(keyStr=="GfxPosition")R S::createNativeObject(GfxVertexAttribPurpose_funcs,(void *)0,EXT->GfxVertexAttribPurpose_typeID);
EI(keyStr=="GfxNormal")R S::createNativeObject(GfxVertexAttribPurpose_funcs,(void *)1,EXT->GfxVertexAttribPurpose_typeID);
EI(keyStr=="GfxColor")R S::createNativeObject(GfxVertexAttribPurpose_funcs,(void *)3,EXT->GfxVertexAttribPurpose_typeID);

else
 CATE(KE,"Unknown member."));
}
}
}
void GfxVertexAttribPurpose_set_member(CTX ctx,NO,SV,SV){CATE(KE,"Enums are read-only."));}
SV GfxVertexAttribType___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,UFOF("GfxVertexAttribType::__eq__")));
size_t F;
if(!TS(a[0],GfxVertexAttribType))
CATE(TE,FAE("GfxVertexAttribType::GfxVertexAttribType","GfxVertexAttribType")));
else
 F=(size_t)((NO)a[0])->data;
size_t other;
if(!TS(a[1],GfxVertexAttribType))
CATE(VE,UFOF("GfxVertexAttribType::__eq__")));
else
 other=(size_t)((NO)a[1])->data;
return S::createBoolean(F == other);
}SV GfxVertexAttribType_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxVertexAttribType");
EI(keyStr=="__eq__")
R CNF(GfxVertexAttribType___eq__);
EI(keyStr=="GfxUnsignedInteger")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)8,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxNormalizedUnsignedByte")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)10,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxFloat")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)1,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxNormalizedUnsignedInteger")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)14,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxShort")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)5,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxInteger")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)7,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxByte")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)3,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxNormalizedByte")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)9,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxUnsignedShort")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)6,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxDouble")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)2,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxHalfFloat")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)0,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxNormalizedShort")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)11,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxNormalizedInteger")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)13,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxUnsignedByte")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)4,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxNormalizedUnsignedShort")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)12,EXT->GfxVertexAttribType_typeID);

else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxVertexAttribType");
EI(keyStr=="__eq__")
R CNF(GfxVertexAttribType___eq__);
EI(keyStr=="GfxUnsignedInteger")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)8,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxNormalizedUnsignedByte")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)10,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxFloat")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)1,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxNormalizedUnsignedInteger")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)14,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxShort")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)5,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxInteger")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)7,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxByte")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)3,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxNormalizedByte")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)9,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxUnsignedShort")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)6,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxDouble")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)2,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxHalfFloat")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)0,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxNormalizedShort")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)11,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxNormalizedInteger")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)13,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxUnsignedByte")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)4,EXT->GfxVertexAttribType_typeID);
EI(keyStr=="GfxNormalizedUnsignedShort")R S::createNativeObject(GfxVertexAttribType_funcs,(void *)12,EXT->GfxVertexAttribType_typeID);

else
 CATE(KE,"Unknown member."));
}
}
}
void GfxVertexAttribType_set_member(CTX ctx,NO,SV,SV){CATE(KE,"Enums are read-only."));}
SV GfxStage___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,UFOF("GfxStage::__eq__")));
size_t F;
if(!TS(a[0],GfxStage))
CATE(TE,FAE("GfxStage::GfxStage","GfxStage")));
else
 F=(size_t)((NO)a[0])->data;
size_t other;
if(!TS(a[1],GfxStage))
CATE(VE,UFOF("GfxStage::__eq__")));
else
 other=(size_t)((NO)a[1])->data;
return S::createBoolean(F == other);
}SV GfxStage_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxStage");
EI(keyStr=="__eq__")
R CNF(GfxStage___eq__);
EI(keyStr=="Compute")R S::createNativeObject(GfxStage_funcs,(void *)5,EXT->GfxStage_typeID);
EI(keyStr=="Geometry")R S::createNativeObject(GfxStage_funcs,(void *)3,EXT->GfxStage_typeID);
EI(keyStr=="Vertex")R S::createNativeObject(GfxStage_funcs,(void *)0,EXT->GfxStage_typeID);
EI(keyStr=="Fragment")R S::createNativeObject(GfxStage_funcs,(void *)4,EXT->GfxStage_typeID);
EI(keyStr=="TessControl")R S::createNativeObject(GfxStage_funcs,(void *)1,EXT->GfxStage_typeID);
EI(keyStr=="TessEval")R S::createNativeObject(GfxStage_funcs,(void *)2,EXT->GfxStage_typeID);

else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxStage");
EI(keyStr=="__eq__")
R CNF(GfxStage___eq__);
EI(keyStr=="Compute")R S::createNativeObject(GfxStage_funcs,(void *)5,EXT->GfxStage_typeID);
EI(keyStr=="Geometry")R S::createNativeObject(GfxStage_funcs,(void *)3,EXT->GfxStage_typeID);
EI(keyStr=="Vertex")R S::createNativeObject(GfxStage_funcs,(void *)0,EXT->GfxStage_typeID);
EI(keyStr=="Fragment")R S::createNativeObject(GfxStage_funcs,(void *)4,EXT->GfxStage_typeID);
EI(keyStr=="TessControl")R S::createNativeObject(GfxStage_funcs,(void *)1,EXT->GfxStage_typeID);
EI(keyStr=="TessEval")R S::createNativeObject(GfxStage_funcs,(void *)2,EXT->GfxStage_typeID);

else
 CATE(KE,"Unknown member."));
}
}
}
void GfxStage_set_member(CTX ctx,NO,SV,SV){CATE(KE,"Enums are read-only."));}
SV GfxBufferUsage___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,UFOF("GfxBufferUsage::__eq__")));
size_t F;
if(!TS(a[0],GfxBufferUsage))
CATE(TE,FAE("GfxBufferUsage::GfxBufferUsage","GfxBufferUsage")));
else
 F=(size_t)((NO)a[0])->data;
size_t other;
if(!TS(a[1],GfxBufferUsage))
CATE(VE,UFOF("GfxBufferUsage::__eq__")));
else
 other=(size_t)((NO)a[1])->data;
return S::createBoolean(F == other);
}SV GfxBufferUsage_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxBufferUsage");
EI(keyStr=="__eq__")
R CNF(GfxBufferUsage___eq__);
EI(keyStr=="Dynamic")R S::createNativeObject(GfxBufferUsage_funcs,(void *)2,EXT->GfxBufferUsage_typeID);
EI(keyStr=="Static")R S::createNativeObject(GfxBufferUsage_funcs,(void *)1,EXT->GfxBufferUsage_typeID);
EI(keyStr=="Stream")R S::createNativeObject(GfxBufferUsage_funcs,(void *)0,EXT->GfxBufferUsage_typeID);

else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxBufferUsage");
EI(keyStr=="__eq__")
R CNF(GfxBufferUsage___eq__);
EI(keyStr=="Dynamic")R S::createNativeObject(GfxBufferUsage_funcs,(void *)2,EXT->GfxBufferUsage_typeID);
EI(keyStr=="Static")R S::createNativeObject(GfxBufferUsage_funcs,(void *)1,EXT->GfxBufferUsage_typeID);
EI(keyStr=="Stream")R S::createNativeObject(GfxBufferUsage_funcs,(void *)0,EXT->GfxBufferUsage_typeID);

else
 CATE(KE,"Unknown member."));
}
}
}
void GfxBufferUsage_set_member(CTX ctx,NO,SV,SV){CATE(KE,"Enums are read-only."));}
SV GfxShadowmapPrecision___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,UFOF("GfxShadowmapPrecision::__eq__")));
size_t F;
if(!TS(a[0],GfxShadowmapPrecision))
CATE(TE,FAE("GfxShadowmapPrecision::GfxShadowmapPrecision","GfxShadowmapPrecision")));
else
 F=(size_t)((NO)a[0])->data;
size_t other;
if(!TS(a[1],GfxShadowmapPrecision))
CATE(VE,UFOF("GfxShadowmapPrecision::__eq__")));
else
 other=(size_t)((NO)a[1])->data;
return S::createBoolean(F == other);
}SV GfxShadowmapPrecision_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxShadowmapPrecision");
EI(keyStr=="__eq__")
R CNF(GfxShadowmapPrecision___eq__);
EI(keyStr=="High")R S::createNativeObject(GfxShadowmapPrecision_funcs,(void *)2,EXT->GfxShadowmapPrecision_typeID);
EI(keyStr=="Medium")R S::createNativeObject(GfxShadowmapPrecision_funcs,(void *)1,EXT->GfxShadowmapPrecision_typeID);
EI(keyStr=="Low")R S::createNativeObject(GfxShadowmapPrecision_funcs,(void *)0,EXT->GfxShadowmapPrecision_typeID);

else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxShadowmapPrecision");
EI(keyStr=="__eq__")
R CNF(GfxShadowmapPrecision___eq__);
EI(keyStr=="High")R S::createNativeObject(GfxShadowmapPrecision_funcs,(void *)2,EXT->GfxShadowmapPrecision_typeID);
EI(keyStr=="Medium")R S::createNativeObject(GfxShadowmapPrecision_funcs,(void *)1,EXT->GfxShadowmapPrecision_typeID);
EI(keyStr=="Low")R S::createNativeObject(GfxShadowmapPrecision_funcs,(void *)0,EXT->GfxShadowmapPrecision_typeID);

else
 CATE(KE,"Unknown member."));
}
}
}
void GfxShadowmapPrecision_set_member(CTX ctx,NO,SV,SV){CATE(KE,"Enums are read-only."));}
SV GfxLightType___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,UFOF("GfxLightType::__eq__")));
size_t F;
if(!TS(a[0],GfxLightType))
CATE(TE,FAE("GfxLightType::GfxLightType","GfxLightType")));
else
 F=(size_t)((NO)a[0])->data;
size_t other;
if(!TS(a[1],GfxLightType))
CATE(VE,UFOF("GfxLightType::__eq__")));
else
 other=(size_t)((NO)a[1])->data;
return S::createBoolean(F == other);
}SV GfxLightType_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxLightType");
EI(keyStr=="__eq__")
R CNF(GfxLightType___eq__);
EI(keyStr=="Point")R S::createNativeObject(GfxLightType_funcs,(void *)2,EXT->GfxLightType_typeID);
EI(keyStr=="Spot")R S::createNativeObject(GfxLightType_funcs,(void *)1,EXT->GfxLightType_typeID);
EI(keyStr=="Directional")R S::createNativeObject(GfxLightType_funcs,(void *)0,EXT->GfxLightType_typeID);

else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxLightType");
EI(keyStr=="__eq__")
R CNF(GfxLightType___eq__);
EI(keyStr=="Point")R S::createNativeObject(GfxLightType_funcs,(void *)2,EXT->GfxLightType_typeID);
EI(keyStr=="Spot")R S::createNativeObject(GfxLightType_funcs,(void *)1,EXT->GfxLightType_typeID);
EI(keyStr=="Directional")R S::createNativeObject(GfxLightType_funcs,(void *)0,EXT->GfxLightType_typeID);

else
 CATE(KE,"Unknown member."));
}
}
}
void GfxLightType_set_member(CTX ctx,NO,SV,SV){CATE(KE,"Enums are read-only."));}
SV CameraType___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,UFOF("CameraType::__eq__")));
size_t F;
if(!TS(a[0],CameraType))
CATE(TE,FAE("CameraType::CameraType","CameraType")));
else
 F=(size_t)((NO)a[0])->data;
size_t other;
if(!TS(a[1],CameraType))
CATE(VE,UFOF("CameraType::__eq__")));
else
 other=(size_t)((NO)a[1])->data;
return S::createBoolean(F == other);
}SV CameraType_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("CameraType");
EI(keyStr=="__eq__")
R CNF(CameraType___eq__);
EI(keyStr=="Perspective")R S::createNativeObject(CameraType_funcs,(void *)0,EXT->CameraType_typeID);
EI(keyStr=="Orthographic")R S::createNativeObject(CameraType_funcs,(void *)1,EXT->CameraType_typeID);

else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("CameraType");
EI(keyStr=="__eq__")
R CNF(CameraType___eq__);
EI(keyStr=="Perspective")R S::createNativeObject(CameraType_funcs,(void *)0,EXT->CameraType_typeID);
EI(keyStr=="Orthographic")R S::createNativeObject(CameraType_funcs,(void *)1,EXT->CameraType_typeID);

else
 CATE(KE,"Unknown member."));
}
}
}
void CameraType_set_member(CTX ctx,NO,SV,SV){CATE(KE,"Enums are read-only."));}
void Filesystem_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,Filesystem))
CATE(TE,"Filesystem::__del__ expects Filesystem as first argument."));

DELETE((Filesystem*)F->data);
}SV Filesystem_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Filesystem's constructor" EAOE));
if(!TS(a[0],Filesystem))
CATE(TE,"Filesystem's constructor expects Filesystem as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Filesystem_funcs,NEW(Filesystem),EXT->Filesystem_typeID);
CATE(TE,UFOF("Filesystem's constructor.")));
R CN;
}

SV Filesystem_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Filesystem");
EI(keyStr=="__new__")
R CNF(Filesystem_new);
EI(keyStr=="__call__")
R CNF(Filesystem_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(Filesystem_new);
 EI(keyStr == "pushSearchPaths")
R CNF(Filesystem_pushSearchPaths);
 EI(keyStr == "popSearchPaths")
R CNF(Filesystem_popSearchPaths);
 EI(keyStr == "addSearchPath")
R CNF(Filesystem_addSearchPath);
 EI(keyStr == "getAbsolutePath")
R CNF(Filesystem_getAbsolutePath);
 else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void Filesystem_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV Filesystem_addSearchPath(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Filesystem::addSearchPath" EAOE));
Filesystem*F;
if(!TS(a[0],Filesystem))
CATE(TE,FAE("Filesystem::addSearchPath","Filesystem")));
else
 F=(Filesystem*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const String &))
{
( F->addSearchPath(val_to_c<const String &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Filesystem::addSearchPath.")));
R CN;
}

SV Filesystem_pushSearchPaths(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Filesystem::pushSearchPaths" EAOE));
Filesystem*F;
if(!TS(a[0],Filesystem))
CATE(TE,FAE("Filesystem::pushSearchPaths","Filesystem")));
else
 F=(Filesystem*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->pushSearchPaths());
R CN;
}
CATE(TE,UFOF("Filesystem::pushSearchPaths.")));
R CN;
}

SV Filesystem_popSearchPaths(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Filesystem::popSearchPaths" EAOE));
Filesystem*F;
if(!TS(a[0],Filesystem))
CATE(TE,FAE("Filesystem::popSearchPaths","Filesystem")));
else
 F=(Filesystem*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->popSearchPaths());
R CN;
}
CATE(TE,UFOF("Filesystem::popSearchPaths.")));
R CN;
}

SV Filesystem_getAbsolutePath(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Filesystem::getAbsolutePath" EAOE));
Filesystem*F;
if(!TS(a[0],Filesystem))
CATE(TE,FAE("Filesystem::getAbsolutePath","Filesystem")));
else
 F=(Filesystem*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const char *))
{
R CV( F->getAbsolutePath(val_to_c<const char *>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Filesystem::getAbsolutePath.")));
R CN;
}

void GfxCompiledShader_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,GfxCompiledShader))
CATE(TE,"GfxCompiledShader::__del__ expects GfxCompiledShader as first argument."));

DELETE((GfxCompiledShader*)F->data);
}SV GfxCompiledShader_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"GfxCompiledShader's constructor" EAOE));
if(!TS(a[0],GfxCompiledShader))
CATE(TE,"GfxCompiledShader's constructor expects GfxCompiledShader as first argument."));
CATE(TE,UFOF("GfxCompiledShader's constructor.")));
}

SV GfxCompiledShader_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxCompiledShader");
EI(keyStr=="__new__")
R CNF(GfxCompiledShader_new);
EI(keyStr=="__call__")
R CNF(GfxCompiledShader_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(GfxCompiledShader_new);
 EI(keyStr == "isInvalid")
R CNF(GfxCompiledShader_isInvalid);
 EI(keyStr == "getStage")
R CNF(GfxCompiledShader_getStage);
 else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void GfxCompiledShader_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV GfxCompiledShader_isInvalid(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxCompiledShader::isInvalid" EAOE));
GfxCompiledShader*F;
if(!TS(a[0],GfxCompiledShader))
CATE(TE,FAE("GfxCompiledShader::isInvalid","GfxCompiledShader")));
else
 F=(GfxCompiledShader*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->isInvalid());
;
}
CATE(TE,UFOF("GfxCompiledShader::isInvalid.")));
R CN;
}

SV GfxCompiledShader_getStage(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxCompiledShader::getStage" EAOE));
GfxCompiledShader*F;
if(!TS(a[0],GfxCompiledShader))
CATE(TE,FAE("GfxCompiledShader::getStage","GfxCompiledShader")));
else
 F=(GfxCompiledShader*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getStage());
;
}
CATE(TE,UFOF("GfxCompiledShader::getStage.")));
R CN;
}

void UInt2_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,T2<uint32_t>))
CATE(TE,"UInt2::__del__ expects UInt2 as first argument."));

DELETE((T2<uint32_t>*)F->data);
}SV UInt2_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2's constructor" EAOE));
if(!TS(a[0],T2<uint32_t>))
CATE(TE,"UInt2's constructor expects UInt2 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(UInt2_funcs,NEW(T2<uint32_t>),EXT->UInt2_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],uint32_t))
R S::createNativeObject(UInt2_funcs,NEW(T2<uint32_t>,val_to_c<uint32_t>::f(ctx,a[1])),EXT->UInt2_typeID);
if(a.getCount()==3)
if(true&&TS(a[1],uint32_t)&&TS(a[2],uint32_t))
R S::createNativeObject(UInt2_funcs,NEW(T2<uint32_t>,val_to_c<uint32_t>::f(ctx,a[1]),val_to_c<uint32_t>::f(ctx,a[2])),EXT->UInt2_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T2<float> &))
R S::createNativeObject(UInt2_funcs,NEW(T2<uint32_t>,val_to_c<const T2<float> &>::f(ctx,a[1])),EXT->UInt2_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T2<int32_t> &))
R S::createNativeObject(UInt2_funcs,NEW(T2<uint32_t>,val_to_c<const T2<int32_t> &>::f(ctx,a[1])),EXT->UInt2_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T2<uint32_t> &))
R S::createNativeObject(UInt2_funcs,NEW(T2<uint32_t>,val_to_c<const T2<uint32_t> &>::f(ctx,a[1])),EXT->UInt2_typeID);
CATE(TE,UFOF("UInt2's constructor.")));
R CN;
}

SV UInt2_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("UInt2");
EI(keyStr=="__new__")
R CNF(UInt2_new);
EI(keyStr=="__call__")
R CNF(UInt2_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(UInt2_new);
 EI(keyStr == "__add__")
R CNF(UInt2___add__);
 EI(keyStr == "__sub__")
R CNF(UInt2___sub__);
 EI(keyStr == "__mul__")
R CNF(UInt2___mul__);
 EI(keyStr == "__div__")
R CNF(UInt2___div__);
 EI(keyStr == "__eq__")
R CNF(UInt2___eq__);
 EI(keyStr == "__neq__")
R CNF(UInt2___neq__);
 EI(keyStr == "__less__")
R CNF(UInt2___less__);
 EI(keyStr == "__grtr__")
R CNF(UInt2___grtr__);
 EI(keyStr == "__leq__")
R CNF(UInt2___leq__);
 EI(keyStr == "__geq__")
R CNF(UInt2___geq__);
 EI(keyStr == "sum")
R CNF(UInt2_sum);
 EI(keyStr == "length")
R CNF(UInt2_length);
 EI(keyStr == "lengthSquared")
R CNF(UInt2_lengthSquared);
 EI(keyStr == "dot")
R CNF(UInt2_dot);
 EI(keyStr == "distance")
R CNF(UInt2_distance);
 EI(keyStr == "distanceSquared")
R CNF(UInt2_distanceSquared);
 EI(keyStr == "normalize")
R CNF(UInt2_normalize);
 EI(keyStr == "getXY")
R CNF(UInt2_getXY);
 EI(keyStr == "setXY")
R CNF(UInt2_setXY);
 EI(keyStr == "getYX")
R CNF(UInt2_getYX);
 EI(keyStr == "setYX")
R CNF(UInt2_setYX);
 EI(keyStr=="x")
{
T2<uint32_t>*obj=(T2<uint32_t>*)F->data;
R CV(obj->x);
} EI(keyStr=="y")
{
T2<uint32_t>*obj=(T2<uint32_t>*)F->data;
R CV(obj->y);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void UInt2_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="x")
{
T2<uint32_t>*obj=(T2<uint32_t>*)F->data;
obj->x=val_to_c<decltype(obj->x)>::f(ctx,value);
} EI(keyStr=="y")
{
T2<uint32_t>*obj=(T2<uint32_t>*)F->data;
obj->y=val_to_c<decltype(obj->y)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV UInt2_normalize(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::normalize" EAOE));
T2<uint32_t>*F;
if(!TS(a[0],T2<uint32_t>))
CATE(TE,FAE("UInt2::normalize","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->normalize());
;
}
CATE(TE,UFOF("UInt2::normalize.")));
R CN;
}

SV UInt2_distance(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::distance" EAOE));
T2<uint32_t>*F;
if(!TS(a[0],T2<uint32_t>))
CATE(TE,FAE("UInt2::distance","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
R CV( F->distance(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("UInt2::distance.")));
R CN;
}

SV UInt2_lengthSquared(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::lengthSquared" EAOE));
T2<uint32_t>*F;
if(!TS(a[0],T2<uint32_t>))
CATE(TE,FAE("UInt2::lengthSquared","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->lengthSquared());
;
}
CATE(TE,UFOF("UInt2::lengthSquared.")));
R CN;
}

SV UInt2___leq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::__leq__" EAOE));
T2<uint32_t>*F;
if(!TS(a[0],T2<uint32_t>))
CATE(TE,FAE("UInt2::__leq__","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
auto v=val_to_c<const T2<uint32_t> &>::f(ctx,a[1]);
R CV(*F <= v);
}
CATE(TE,UFOF("UInt2::__leq__.")));
R CN;
}

SV UInt2_setYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::setYX" EAOE));
T2<uint32_t>*F;
if(!TS(a[0],T2<uint32_t>))
CATE(TE,FAE("UInt2::setYX","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
( F->setYX(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt2::setYX.")));
R CN;
}

SV UInt2___grtr__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::__grtr__" EAOE));
T2<uint32_t>*F;
if(!TS(a[0],T2<uint32_t>))
CATE(TE,FAE("UInt2::__grtr__","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
auto v=val_to_c<const T2<uint32_t> &>::f(ctx,a[1]);
R CV(*F > v);
}
CATE(TE,UFOF("UInt2::__grtr__.")));
R CN;
}

SV UInt2_sum(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::sum" EAOE));
T2<uint32_t>*F;
if(!TS(a[0],T2<uint32_t>))
CATE(TE,FAE("UInt2::sum","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->sum());
;
}
CATE(TE,UFOF("UInt2::sum.")));
R CN;
}

SV UInt2_getXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::getXY" EAOE));
T2<uint32_t>*F;
if(!TS(a[0],T2<uint32_t>))
CATE(TE,FAE("UInt2::getXY","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXY());
;
}
CATE(TE,UFOF("UInt2::getXY.")));
R CN;
}

SV UInt2_length(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::length" EAOE));
T2<uint32_t>*F;
if(!TS(a[0],T2<uint32_t>))
CATE(TE,FAE("UInt2::length","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->length());
;
}
CATE(TE,UFOF("UInt2::length.")));
R CN;
}

SV UInt2_getYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::getYX" EAOE));
T2<uint32_t>*F;
if(!TS(a[0],T2<uint32_t>))
CATE(TE,FAE("UInt2::getYX","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYX());
;
}
CATE(TE,UFOF("UInt2::getYX.")));
R CN;
}

SV UInt2___div__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::__div__" EAOE));
T2<uint32_t>*F;
if(!TS(a[0],T2<uint32_t>))
CATE(TE,FAE("UInt2::__div__","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
auto v=val_to_c<const T2<uint32_t> &>::f(ctx,a[1]);
R CV(*F / v);
}
if(a.getCount()==2)
if(1&&TS(a[1],uint32_t))
{
auto v=val_to_c<uint32_t>::f(ctx,a[1]);
R CV(*F / v);
}
CATE(TE,UFOF("UInt2::__div__.")));
R CN;
}

SV UInt2_setXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::setXY" EAOE));
T2<uint32_t>*F;
if(!TS(a[0],T2<uint32_t>))
CATE(TE,FAE("UInt2::setXY","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
( F->setXY(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt2::setXY.")));
R CN;
}

SV UInt2___mul__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::__mul__" EAOE));
T2<uint32_t>*F;
if(!TS(a[0],T2<uint32_t>))
CATE(TE,FAE("UInt2::__mul__","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
auto v=val_to_c<const T2<uint32_t> &>::f(ctx,a[1]);
R CV(*F * v);
}
if(a.getCount()==2)
if(1&&TS(a[1],uint32_t))
{
auto v=val_to_c<uint32_t>::f(ctx,a[1]);
R CV(*F * v);
}
CATE(TE,UFOF("UInt2::__mul__.")));
R CN;
}

SV UInt2___add__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::__add__" EAOE));
T2<uint32_t>*F;
if(!TS(a[0],T2<uint32_t>))
CATE(TE,FAE("UInt2::__add__","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
auto v=val_to_c<const T2<uint32_t> &>::f(ctx,a[1]);
R CV(*F + v);
}
if(a.getCount()==2)
if(1&&TS(a[1],uint32_t))
{
auto v=val_to_c<uint32_t>::f(ctx,a[1]);
R CV(*F + v);
}
CATE(TE,UFOF("UInt2::__add__.")));
R CN;
}

SV UInt2___less__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::__less__" EAOE));
T2<uint32_t>*F;
if(!TS(a[0],T2<uint32_t>))
CATE(TE,FAE("UInt2::__less__","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
auto v=val_to_c<const T2<uint32_t> &>::f(ctx,a[1]);
R CV(*F < v);
}
CATE(TE,UFOF("UInt2::__less__.")));
R CN;
}

SV UInt2___sub__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::__sub__" EAOE));
T2<uint32_t>*F;
if(!TS(a[0],T2<uint32_t>))
CATE(TE,FAE("UInt2::__sub__","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
auto v=val_to_c<const T2<uint32_t> &>::f(ctx,a[1]);
R CV(*F - v);
}
if(a.getCount()==2)
if(1&&TS(a[1],uint32_t))
{
auto v=val_to_c<uint32_t>::f(ctx,a[1]);
R CV(*F - v);
}
CATE(TE,UFOF("UInt2::__sub__.")));
R CN;
}

SV UInt2___geq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::__geq__" EAOE));
T2<uint32_t>*F;
if(!TS(a[0],T2<uint32_t>))
CATE(TE,FAE("UInt2::__geq__","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
auto v=val_to_c<const T2<uint32_t> &>::f(ctx,a[1]);
R CV(*F >= v);
}
CATE(TE,UFOF("UInt2::__geq__.")));
R CN;
}

SV UInt2_distanceSquared(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::distanceSquared" EAOE));
T2<uint32_t>*F;
if(!TS(a[0],T2<uint32_t>))
CATE(TE,FAE("UInt2::distanceSquared","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
R CV( F->distanceSquared(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("UInt2::distanceSquared.")));
R CN;
}

SV UInt2___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::__eq__" EAOE));
T2<uint32_t>*F;
if(!TS(a[0],T2<uint32_t>))
CATE(TE,FAE("UInt2::__eq__","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
auto v=val_to_c<const T2<uint32_t> &>::f(ctx,a[1]);
R CV(*F == v);
}
CATE(TE,UFOF("UInt2::__eq__.")));
R CN;
}

SV UInt2_dot(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::dot" EAOE));
T2<uint32_t>*F;
if(!TS(a[0],T2<uint32_t>))
CATE(TE,FAE("UInt2::dot","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
R CV( F->dot(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
;
}
if(a.getCount()==1)
if(1)
{
R CV( F->dot());
;
}
CATE(TE,UFOF("UInt2::dot.")));
R CN;
}

SV UInt2___neq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::__neq__" EAOE));
T2<uint32_t>*F;
if(!TS(a[0],T2<uint32_t>))
CATE(TE,FAE("UInt2::__neq__","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
auto v=val_to_c<const T2<uint32_t> &>::f(ctx,a[1]);
R CV(*F != v);
}
CATE(TE,UFOF("UInt2::__neq__.")));
R CN;
}

void GPUTimer_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,GPUTimer))
CATE(TE,"GPUTimer::__del__ expects GPUTimer as first argument."));

DELETE((GPUTimer*)F->data);
}SV GPUTimer_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"GPUTimer's constructor" EAOE));
if(!TS(a[0],GPUTimer))
CATE(TE,"GPUTimer's constructor expects GPUTimer as first argument."));
CATE(TE,UFOF("GPUTimer's constructor.")));
}

SV GPUTimer_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GPUTimer");
EI(keyStr=="__new__")
R CNF(GPUTimer_new);
EI(keyStr=="__call__")
R CNF(GPUTimer_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(GPUTimer_new);
 EI(keyStr == "resultAvailable")
R CNF(GPUTimer_resultAvailable);
 EI(keyStr == "getResult")
R CNF(GPUTimer_getResult);
 EI(keyStr == "getResultResolution")
R CNF(GPUTimer_getResultResolution);
 EI(keyStr == "begin")
R CNF(GPUTimer_begin);
 EI(keyStr == "end")
R CNF(GPUTimer_end);
 else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void GPUTimer_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV GPUTimer_begin(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GPUTimer::begin" EAOE));
GPUTimer*F;
if(!TS(a[0],GPUTimer))
CATE(TE,FAE("GPUTimer::begin","GPUTimer")));
else
 F=(GPUTimer*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->begin());
R CN;
}
CATE(TE,UFOF("GPUTimer::begin.")));
R CN;
}

SV GPUTimer_resultAvailable(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GPUTimer::resultAvailable" EAOE));
GPUTimer*F;
if(!TS(a[0],GPUTimer))
CATE(TE,FAE("GPUTimer::resultAvailable","GPUTimer")));
else
 F=(GPUTimer*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->resultAvailable());
;
}
CATE(TE,UFOF("GPUTimer::resultAvailable.")));
R CN;
}

SV GPUTimer_end(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GPUTimer::end" EAOE));
GPUTimer*F;
if(!TS(a[0],GPUTimer))
CATE(TE,FAE("GPUTimer::end","GPUTimer")));
else
 F=(GPUTimer*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->end());
R CN;
}
CATE(TE,UFOF("GPUTimer::end.")));
R CN;
}

SV GPUTimer_getResultResolution(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GPUTimer::getResultResolution" EAOE));
GPUTimer*F;
if(!TS(a[0],GPUTimer))
CATE(TE,FAE("GPUTimer::getResultResolution","GPUTimer")));
else
 F=(GPUTimer*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getResultResolution());
;
}
CATE(TE,UFOF("GPUTimer::getResultResolution.")));
R CN;
}

SV GPUTimer_getResult(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GPUTimer::getResult" EAOE));
GPUTimer*F;
if(!TS(a[0],GPUTimer))
CATE(TE,FAE("GPUTimer::getResult","GPUTimer")));
else
 F=(GPUTimer*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getResult());
;
}
CATE(TE,UFOF("GPUTimer::getResult.")));
R CN;
}

void RigidBody_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,RigidBody))
CATE(TE,"RigidBody::__del__ expects RigidBody as first argument."));

}SV RigidBody_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"RigidBody's constructor" EAOE));
if(!TS(a[0],RigidBody))
CATE(TE,"RigidBody's constructor expects RigidBody as first argument."));
CATE(TE,UFOF("RigidBody's constructor.")));
}

SV RigidBody_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("RigidBody");
EI(keyStr=="__new__")
R CNF(RigidBody_new);
EI(keyStr=="__call__")
R CNF(RigidBody_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(RigidBody_new);
 EI(keyStr == "getBulletRigidBody")
R CNF(RigidBody_getBulletRigidBody);
 EI(keyStr == "getType")
R CNF(RigidBody_getType);
 EI(keyStr == "getGravity")
R CNF(RigidBody_getGravity);
 EI(keyStr == "setGravity")
R CNF(RigidBody_setGravity);
 EI(keyStr == "setLinearDamping")
R CNF(RigidBody_setLinearDamping);
 EI(keyStr == "getLinearDamping")
R CNF(RigidBody_getLinearDamping);
 EI(keyStr == "setAngularDamping")
R CNF(RigidBody_setAngularDamping);
 EI(keyStr == "getAngularDamping")
R CNF(RigidBody_getAngularDamping);
 EI(keyStr == "setMass")
R CNF(RigidBody_setMass);
 EI(keyStr == "getMass")
R CNF(RigidBody_getMass);
 EI(keyStr == "getLinearSleepingThreshold")
R CNF(RigidBody_getLinearSleepingThreshold);
 EI(keyStr == "setLinearSleepingThreshold")
R CNF(RigidBody_setLinearSleepingThreshold);
 EI(keyStr == "getAngularSleepingThreshold")
R CNF(RigidBody_getAngularSleepingThreshold);
 EI(keyStr == "setAngularSleepingThreshold")
R CNF(RigidBody_setAngularSleepingThreshold);
 EI(keyStr == "applyTorque")
R CNF(RigidBody_applyTorque);
 EI(keyStr == "applyForce")
R CNF(RigidBody_applyForce);
 EI(keyStr == "applyCentralImpulse")
R CNF(RigidBody_applyCentralImpulse);
 EI(keyStr == "applyTorqueImpulse")
R CNF(RigidBody_applyTorqueImpulse);
 EI(keyStr == "applyImpulse")
R CNF(RigidBody_applyImpulse);
 EI(keyStr == "clearForces")
R CNF(RigidBody_clearForces);
 EI(keyStr == "getLinearVelocity")
R CNF(RigidBody_getLinearVelocity);
 EI(keyStr == "setLinearVelocity")
R CNF(RigidBody_setLinearVelocity);
 EI(keyStr == "getAngularVelocity")
R CNF(RigidBody_getAngularVelocity);
 EI(keyStr == "setAngularVelocity")
R CNF(RigidBody_setAngularVelocity);
 EI(keyStr == "getVelocityOfPoint")
R CNF(RigidBody_getVelocityOfPoint);
 EI(keyStr == "getRestitution")
R CNF(RigidBody_getRestitution);
 EI(keyStr == "setRestitution")
R CNF(RigidBody_setRestitution);
 EI(keyStr == "getFriction")
R CNF(RigidBody_getFriction);
 EI(keyStr == "setFriction")
R CNF(RigidBody_setFriction);
 EI(keyStr == "getRollingFriction")
R CNF(RigidBody_getRollingFriction);
 EI(keyStr == "setRollingFriction")
R CNF(RigidBody_setRollingFriction);
 EI(keyStr == "getLinearFactor")
R CNF(RigidBody_getLinearFactor);
 EI(keyStr == "setLinearFactor")
R CNF(RigidBody_setLinearFactor);
 EI(keyStr == "getAngularFactor")
R CNF(RigidBody_getAngularFactor);
 EI(keyStr == "setAngularFactor")
R CNF(RigidBody_setAngularFactor);
 EI(keyStr == "setTransform")
R CNF(RigidBody_setTransform);
 EI(keyStr == "getWorld")
R CNF(RigidBody_getWorld);
 EI(keyStr == "getCollisionMask")
R CNF(RigidBody_getCollisionMask);
 EI(keyStr == "setShape")
R CNF(RigidBody_setShape);
 EI(keyStr == "getShape")
R CNF(RigidBody_getShape);
 EI(keyStr == "getEntity")
R CNF(RigidBody_getEntity);
 else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void RigidBody_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV RigidBody_setGravity(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::setGravity" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::setGravity","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Vector3D &))
{
( F->setGravity(val_to_c<const Vector3D &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("RigidBody::setGravity.")));
R CN;
}

SV RigidBody_getFriction(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::getFriction" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::getFriction","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getFriction());
;
}
CATE(TE,UFOF("RigidBody::getFriction.")));
R CN;
}

SV RigidBody_getRollingFriction(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::getRollingFriction" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::getRollingFriction","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getRollingFriction());
;
}
CATE(TE,UFOF("RigidBody::getRollingFriction.")));
R CN;
}

SV RigidBody_setAngularFactor(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::setAngularFactor" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::setAngularFactor","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Float3 &))
{
( F->setAngularFactor(val_to_c<const Float3 &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("RigidBody::setAngularFactor.")));
R CN;
}

SV RigidBody_getVelocityOfPoint(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::getVelocityOfPoint" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::getVelocityOfPoint","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Position3D &))
{
R CV( F->getVelocityOfPoint(val_to_c<const Position3D &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("RigidBody::getVelocityOfPoint.")));
R CN;
}

SV RigidBody_setTransform(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::setTransform" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::setTransform","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Matrix4x4 &))
{
( F->setTransform(val_to_c<const Matrix4x4 &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("RigidBody::setTransform.")));
R CN;
}

SV RigidBody_getMass(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::getMass" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::getMass","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getMass());
;
}
CATE(TE,UFOF("RigidBody::getMass.")));
R CN;
}

SV RigidBody_setFriction(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::setFriction" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::setFriction","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->setFriction(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("RigidBody::setFriction.")));
R CN;
}

SV RigidBody_clearForces(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::clearForces" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::clearForces","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->clearForces());
R CN;
}
CATE(TE,UFOF("RigidBody::clearForces.")));
R CN;
}

SV RigidBody_applyImpulse(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::applyImpulse" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::applyImpulse","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],const Vector3D &)&&TS(a[2],const Position3D &))
{
( F->applyImpulse(val_to_c<const Vector3D &>::f(ctx,a[1]), val_to_c<const Position3D &>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("RigidBody::applyImpulse.")));
R CN;
}

SV RigidBody_applyTorque(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::applyTorque" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::applyTorque","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Vector3D &))
{
( F->applyTorque(val_to_c<const Vector3D &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("RigidBody::applyTorque.")));
R CN;
}

SV RigidBody_setLinearFactor(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::setLinearFactor" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::setLinearFactor","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Float3 &))
{
( F->setLinearFactor(val_to_c<const Float3 &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("RigidBody::setLinearFactor.")));
R CN;
}

SV RigidBody_setLinearDamping(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::setLinearDamping" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::setLinearDamping","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->setLinearDamping(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("RigidBody::setLinearDamping.")));
R CN;
}

SV RigidBody_getLinearFactor(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::getLinearFactor" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::getLinearFactor","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getLinearFactor());
;
}
CATE(TE,UFOF("RigidBody::getLinearFactor.")));
R CN;
}

SV RigidBody_setAngularDamping(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::setAngularDamping" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::setAngularDamping","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->setAngularDamping(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("RigidBody::setAngularDamping.")));
R CN;
}

SV RigidBody_getWorld(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::getWorld" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::getWorld","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

CATE(TE,UFOF("RigidBody::getWorld.")));
R CN;
}

SV RigidBody_getAngularVelocity(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::getAngularVelocity" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::getAngularVelocity","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getAngularVelocity());
;
}
CATE(TE,UFOF("RigidBody::getAngularVelocity.")));
R CN;
}

SV RigidBody_getShape(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::getShape" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::getShape","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

CATE(TE,UFOF("RigidBody::getShape.")));
R CN;
}

SV RigidBody_setAngularSleepingThreshold(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::setAngularSleepingThreshold" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::setAngularSleepingThreshold","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->setAngularSleepingThreshold(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("RigidBody::setAngularSleepingThreshold.")));
R CN;
}

SV RigidBody_applyTorqueImpulse(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::applyTorqueImpulse" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::applyTorqueImpulse","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Vector3D &))
{
( F->applyTorqueImpulse(val_to_c<const Vector3D &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("RigidBody::applyTorqueImpulse.")));
R CN;
}

SV RigidBody_setLinearVelocity(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::setLinearVelocity" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::setLinearVelocity","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Vector3D &))
{
( F->setLinearVelocity(val_to_c<const Vector3D &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("RigidBody::setLinearVelocity.")));
R CN;
}

SV RigidBody_getCollisionMask(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::getCollisionMask" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::getCollisionMask","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getCollisionMask());
;
}
CATE(TE,UFOF("RigidBody::getCollisionMask.")));
R CN;
}

SV RigidBody_getLinearVelocity(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::getLinearVelocity" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::getLinearVelocity","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getLinearVelocity());
;
}
CATE(TE,UFOF("RigidBody::getLinearVelocity.")));
R CN;
}

SV RigidBody_setAngularVelocity(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::setAngularVelocity" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::setAngularVelocity","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Vector3D &))
{
( F->setAngularVelocity(val_to_c<const Vector3D &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("RigidBody::setAngularVelocity.")));
R CN;
}

SV RigidBody_getType(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::getType" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::getType","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

CATE(TE,UFOF("RigidBody::getType.")));
R CN;
}

SV RigidBody_getAngularSleepingThreshold(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::getAngularSleepingThreshold" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::getAngularSleepingThreshold","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getAngularSleepingThreshold());
;
}
CATE(TE,UFOF("RigidBody::getAngularSleepingThreshold.")));
R CN;
}

SV RigidBody_setLinearSleepingThreshold(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::setLinearSleepingThreshold" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::setLinearSleepingThreshold","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->setLinearSleepingThreshold(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("RigidBody::setLinearSleepingThreshold.")));
R CN;
}

SV RigidBody_setRollingFriction(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::setRollingFriction" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::setRollingFriction","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->setRollingFriction(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("RigidBody::setRollingFriction.")));
R CN;
}

SV RigidBody_getGravity(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::getGravity" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::getGravity","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getGravity());
;
}
CATE(TE,UFOF("RigidBody::getGravity.")));
R CN;
}

SV RigidBody_setMass(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::setMass" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::setMass","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->setMass(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("RigidBody::setMass.")));
R CN;
}

SV RigidBody_applyCentralImpulse(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::applyCentralImpulse" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::applyCentralImpulse","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Vector3D &))
{
( F->applyCentralImpulse(val_to_c<const Vector3D &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("RigidBody::applyCentralImpulse.")));
R CN;
}

SV RigidBody_getBulletRigidBody(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::getBulletRigidBody" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::getBulletRigidBody","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

CATE(TE,UFOF("RigidBody::getBulletRigidBody.")));
R CN;
}

SV RigidBody_getRestitution(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::getRestitution" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::getRestitution","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getRestitution());
;
}
CATE(TE,UFOF("RigidBody::getRestitution.")));
R CN;
}

SV RigidBody_getAngularFactor(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::getAngularFactor" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::getAngularFactor","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getAngularFactor());
;
}
CATE(TE,UFOF("RigidBody::getAngularFactor.")));
R CN;
}

SV RigidBody_getAngularDamping(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::getAngularDamping" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::getAngularDamping","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getAngularDamping());
;
}
CATE(TE,UFOF("RigidBody::getAngularDamping.")));
R CN;
}

SV RigidBody_getLinearSleepingThreshold(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::getLinearSleepingThreshold" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::getLinearSleepingThreshold","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getLinearSleepingThreshold());
;
}
CATE(TE,UFOF("RigidBody::getLinearSleepingThreshold.")));
R CN;
}

SV RigidBody_applyForce(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::applyForce" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::applyForce","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],const Vector3D &)&&TS(a[2],const Position3D &))
{
( F->applyForce(val_to_c<const Vector3D &>::f(ctx,a[1]), val_to_c<const Position3D &>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("RigidBody::applyForce.")));
R CN;
}

SV RigidBody_getEntity(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::getEntity" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::getEntity","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

CATE(TE,UFOF("RigidBody::getEntity.")));
R CN;
}

SV RigidBody_setRestitution(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::setRestitution" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::setRestitution","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->setRestitution(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("RigidBody::setRestitution.")));
R CN;
}

SV RigidBody_setShape(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::setShape" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::setShape","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

CATE(TE,UFOF("RigidBody::setShape.")));
R CN;
}

SV RigidBody_getLinearDamping(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"RigidBody::getLinearDamping" EAOE));
RigidBody*F;
if(!TS(a[0],RigidBody))
CATE(TE,FAE("RigidBody::getLinearDamping","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getLinearDamping());
;
}
CATE(TE,UFOF("RigidBody::getLinearDamping.")));
R CN;
}

void Float2_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,T2<float>))
CATE(TE,"Float2::__del__ expects Float2 as first argument."));

DELETE((T2<float>*)F->data);
}SV Float2_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2's constructor" EAOE));
if(!TS(a[0],T2<float>))
CATE(TE,"Float2's constructor expects Float2 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Float2_funcs,NEW(T2<float>),EXT->Float2_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],float))
R S::createNativeObject(Float2_funcs,NEW(T2<float>,val_to_c<float>::f(ctx,a[1])),EXT->Float2_typeID);
if(a.getCount()==3)
if(true&&TS(a[1],float)&&TS(a[2],float))
R S::createNativeObject(Float2_funcs,NEW(T2<float>,val_to_c<float>::f(ctx,a[1]),val_to_c<float>::f(ctx,a[2])),EXT->Float2_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T2<float> &))
R S::createNativeObject(Float2_funcs,NEW(T2<float>,val_to_c<const T2<float> &>::f(ctx,a[1])),EXT->Float2_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T2<int32_t> &))
R S::createNativeObject(Float2_funcs,NEW(T2<float>,val_to_c<const T2<int32_t> &>::f(ctx,a[1])),EXT->Float2_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T2<uint32_t> &))
R S::createNativeObject(Float2_funcs,NEW(T2<float>,val_to_c<const T2<uint32_t> &>::f(ctx,a[1])),EXT->Float2_typeID);
CATE(TE,UFOF("Float2's constructor.")));
R CN;
}

SV Float2_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Float2");
EI(keyStr=="__new__")
R CNF(Float2_new);
EI(keyStr=="__call__")
R CNF(Float2_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(Float2_new);
 EI(keyStr == "__add__")
R CNF(Float2___add__);
 EI(keyStr == "__sub__")
R CNF(Float2___sub__);
 EI(keyStr == "__mul__")
R CNF(Float2___mul__);
 EI(keyStr == "__div__")
R CNF(Float2___div__);
 EI(keyStr == "__eq__")
R CNF(Float2___eq__);
 EI(keyStr == "__neq__")
R CNF(Float2___neq__);
 EI(keyStr == "__less__")
R CNF(Float2___less__);
 EI(keyStr == "__grtr__")
R CNF(Float2___grtr__);
 EI(keyStr == "__leq__")
R CNF(Float2___leq__);
 EI(keyStr == "__geq__")
R CNF(Float2___geq__);
 EI(keyStr == "sum")
R CNF(Float2_sum);
 EI(keyStr == "length")
R CNF(Float2_length);
 EI(keyStr == "lengthSquared")
R CNF(Float2_lengthSquared);
 EI(keyStr == "dot")
R CNF(Float2_dot);
 EI(keyStr == "distance")
R CNF(Float2_distance);
 EI(keyStr == "distanceSquared")
R CNF(Float2_distanceSquared);
 EI(keyStr == "normalize")
R CNF(Float2_normalize);
 EI(keyStr == "getXY")
R CNF(Float2_getXY);
 EI(keyStr == "setXY")
R CNF(Float2_setXY);
 EI(keyStr == "getYX")
R CNF(Float2_getYX);
 EI(keyStr == "setYX")
R CNF(Float2_setYX);
 EI(keyStr=="x")
{
T2<float>*obj=(T2<float>*)F->data;
R CV(obj->x);
} EI(keyStr=="y")
{
T2<float>*obj=(T2<float>*)F->data;
R CV(obj->y);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void Float2_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="x")
{
T2<float>*obj=(T2<float>*)F->data;
obj->x=val_to_c<decltype(obj->x)>::f(ctx,value);
} EI(keyStr=="y")
{
T2<float>*obj=(T2<float>*)F->data;
obj->y=val_to_c<decltype(obj->y)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV Float2_normalize(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::normalize" EAOE));
T2<float>*F;
if(!TS(a[0],T2<float>))
CATE(TE,FAE("Float2::normalize","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->normalize());
;
}
CATE(TE,UFOF("Float2::normalize.")));
R CN;
}

SV Float2_distance(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::distance" EAOE));
T2<float>*F;
if(!TS(a[0],T2<float>))
CATE(TE,FAE("Float2::distance","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
R CV( F->distance(val_to_c<const T2<float> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Float2::distance.")));
R CN;
}

SV Float2_lengthSquared(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::lengthSquared" EAOE));
T2<float>*F;
if(!TS(a[0],T2<float>))
CATE(TE,FAE("Float2::lengthSquared","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->lengthSquared());
;
}
CATE(TE,UFOF("Float2::lengthSquared.")));
R CN;
}

SV Float2___leq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::__leq__" EAOE));
T2<float>*F;
if(!TS(a[0],T2<float>))
CATE(TE,FAE("Float2::__leq__","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
auto v=val_to_c<const T2<float> &>::f(ctx,a[1]);
R CV(*F <= v);
}
CATE(TE,UFOF("Float2::__leq__.")));
R CN;
}

SV Float2_setYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::setYX" EAOE));
T2<float>*F;
if(!TS(a[0],T2<float>))
CATE(TE,FAE("Float2::setYX","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
( F->setYX(val_to_c<const T2<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float2::setYX.")));
R CN;
}

SV Float2___grtr__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::__grtr__" EAOE));
T2<float>*F;
if(!TS(a[0],T2<float>))
CATE(TE,FAE("Float2::__grtr__","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
auto v=val_to_c<const T2<float> &>::f(ctx,a[1]);
R CV(*F > v);
}
CATE(TE,UFOF("Float2::__grtr__.")));
R CN;
}

SV Float2_sum(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::sum" EAOE));
T2<float>*F;
if(!TS(a[0],T2<float>))
CATE(TE,FAE("Float2::sum","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->sum());
;
}
CATE(TE,UFOF("Float2::sum.")));
R CN;
}

SV Float2_getXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::getXY" EAOE));
T2<float>*F;
if(!TS(a[0],T2<float>))
CATE(TE,FAE("Float2::getXY","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXY());
;
}
CATE(TE,UFOF("Float2::getXY.")));
R CN;
}

SV Float2_length(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::length" EAOE));
T2<float>*F;
if(!TS(a[0],T2<float>))
CATE(TE,FAE("Float2::length","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->length());
;
}
CATE(TE,UFOF("Float2::length.")));
R CN;
}

SV Float2_getYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::getYX" EAOE));
T2<float>*F;
if(!TS(a[0],T2<float>))
CATE(TE,FAE("Float2::getYX","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYX());
;
}
CATE(TE,UFOF("Float2::getYX.")));
R CN;
}

SV Float2___div__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::__div__" EAOE));
T2<float>*F;
if(!TS(a[0],T2<float>))
CATE(TE,FAE("Float2::__div__","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
auto v=val_to_c<const T2<float> &>::f(ctx,a[1]);
R CV(*F / v);
}
if(a.getCount()==2)
if(1&&TS(a[1],float))
{
auto v=val_to_c<float>::f(ctx,a[1]);
R CV(*F / v);
}
CATE(TE,UFOF("Float2::__div__.")));
R CN;
}

SV Float2_setXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::setXY" EAOE));
T2<float>*F;
if(!TS(a[0],T2<float>))
CATE(TE,FAE("Float2::setXY","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
( F->setXY(val_to_c<const T2<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float2::setXY.")));
R CN;
}

SV Float2___mul__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::__mul__" EAOE));
T2<float>*F;
if(!TS(a[0],T2<float>))
CATE(TE,FAE("Float2::__mul__","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
auto v=val_to_c<const T2<float> &>::f(ctx,a[1]);
R CV(*F * v);
}
if(a.getCount()==2)
if(1&&TS(a[1],float))
{
auto v=val_to_c<float>::f(ctx,a[1]);
R CV(*F * v);
}
CATE(TE,UFOF("Float2::__mul__.")));
R CN;
}

SV Float2___add__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::__add__" EAOE));
T2<float>*F;
if(!TS(a[0],T2<float>))
CATE(TE,FAE("Float2::__add__","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
auto v=val_to_c<const T2<float> &>::f(ctx,a[1]);
R CV(*F + v);
}
if(a.getCount()==2)
if(1&&TS(a[1],float))
{
auto v=val_to_c<float>::f(ctx,a[1]);
R CV(*F + v);
}
CATE(TE,UFOF("Float2::__add__.")));
R CN;
}

SV Float2___less__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::__less__" EAOE));
T2<float>*F;
if(!TS(a[0],T2<float>))
CATE(TE,FAE("Float2::__less__","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
auto v=val_to_c<const T2<float> &>::f(ctx,a[1]);
R CV(*F < v);
}
CATE(TE,UFOF("Float2::__less__.")));
R CN;
}

SV Float2___sub__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::__sub__" EAOE));
T2<float>*F;
if(!TS(a[0],T2<float>))
CATE(TE,FAE("Float2::__sub__","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
auto v=val_to_c<const T2<float> &>::f(ctx,a[1]);
R CV(*F - v);
}
if(a.getCount()==2)
if(1&&TS(a[1],float))
{
auto v=val_to_c<float>::f(ctx,a[1]);
R CV(*F - v);
}
CATE(TE,UFOF("Float2::__sub__.")));
R CN;
}

SV Float2___geq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::__geq__" EAOE));
T2<float>*F;
if(!TS(a[0],T2<float>))
CATE(TE,FAE("Float2::__geq__","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
auto v=val_to_c<const T2<float> &>::f(ctx,a[1]);
R CV(*F >= v);
}
CATE(TE,UFOF("Float2::__geq__.")));
R CN;
}

SV Float2_distanceSquared(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::distanceSquared" EAOE));
T2<float>*F;
if(!TS(a[0],T2<float>))
CATE(TE,FAE("Float2::distanceSquared","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
R CV( F->distanceSquared(val_to_c<const T2<float> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Float2::distanceSquared.")));
R CN;
}

SV Float2___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::__eq__" EAOE));
T2<float>*F;
if(!TS(a[0],T2<float>))
CATE(TE,FAE("Float2::__eq__","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
auto v=val_to_c<const T2<float> &>::f(ctx,a[1]);
R CV(*F == v);
}
CATE(TE,UFOF("Float2::__eq__.")));
R CN;
}

SV Float2_dot(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::dot" EAOE));
T2<float>*F;
if(!TS(a[0],T2<float>))
CATE(TE,FAE("Float2::dot","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
R CV( F->dot(val_to_c<const T2<float> &>::f(ctx,a[1])));
;
}
if(a.getCount()==1)
if(1)
{
R CV( F->dot());
;
}
CATE(TE,UFOF("Float2::dot.")));
R CN;
}

SV Float2___neq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::__neq__" EAOE));
T2<float>*F;
if(!TS(a[0],T2<float>))
CATE(TE,FAE("Float2::__neq__","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
auto v=val_to_c<const T2<float> &>::f(ctx,a[1]);
R CV(*F != v);
}
CATE(TE,UFOF("Float2::__neq__.")));
R CN;
}

void AudioSource_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,AudioSource))
CATE(TE,"AudioSource::__del__ expects AudioSource as first argument."));

DELETE((AudioSource*)F->data);
}SV AudioSource_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioSource's constructor" EAOE));
if(!TS(a[0],AudioSource))
CATE(TE,"AudioSource's constructor expects AudioSource as first argument."));
if(a.getCount()==2)
if(true&&TS(a[1],Audio *))
R S::createNativeObject(AudioSource_funcs,NEW(AudioSource,val_to_c<Audio *>::f(ctx,a[1])),EXT->AudioSource_typeID);
CATE(TE,UFOF("AudioSource's constructor.")));
R CN;
}

SV AudioSource_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("AudioSource");
EI(keyStr=="__new__")
R CNF(AudioSource_new);
EI(keyStr=="__call__")
R CNF(AudioSource_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(AudioSource_new);
 EI(keyStr == "getAudio")
R CNF(AudioSource_getAudio);
 EI(keyStr == "setAudio")
R CNF(AudioSource_setAudio);
 EI(keyStr=="is3d")
{
AudioSource*obj=(AudioSource*)F->data;
R CV(obj->is3d);
} EI(keyStr=="position")
{
AudioSource*obj=(AudioSource*)F->data;
R CV(obj->position);
} EI(keyStr=="referenceDistance")
{
AudioSource*obj=(AudioSource*)F->data;
R CV(obj->referenceDistance);
} EI(keyStr=="rolloffFactor")
{
AudioSource*obj=(AudioSource*)F->data;
R CV(obj->rolloffFactor);
} EI(keyStr=="maxDistance")
{
AudioSource*obj=(AudioSource*)F->data;
R CV(obj->maxDistance);
} EI(keyStr=="volume")
{
AudioSource*obj=(AudioSource*)F->data;
R CV(obj->volume);
} EI(keyStr=="velocity")
{
AudioSource*obj=(AudioSource*)F->data;
R CV(obj->velocity);
} EI(keyStr=="dopplerFactor")
{
AudioSource*obj=(AudioSource*)F->data;
R CV(obj->dopplerFactor);
} EI(keyStr=="offset")
{
AudioSource*obj=(AudioSource*)F->data;
R CV(obj->offset);
} EI(keyStr=="loop")
{
AudioSource*obj=(AudioSource*)F->data;
R CV(obj->loop);
} EI(keyStr=="playing")
{
AudioSource*obj=(AudioSource*)F->data;
R CV(obj->playing);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void AudioSource_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="is3d")
{
AudioSource*obj=(AudioSource*)F->data;
obj->is3d=val_to_c<decltype(obj->is3d)>::f(ctx,value);
} EI(keyStr=="position")
{
AudioSource*obj=(AudioSource*)F->data;
obj->position=val_to_c<decltype(obj->position)>::f(ctx,value);
} EI(keyStr=="referenceDistance")
{
AudioSource*obj=(AudioSource*)F->data;
obj->referenceDistance=val_to_c<decltype(obj->referenceDistance)>::f(ctx,value);
} EI(keyStr=="rolloffFactor")
{
AudioSource*obj=(AudioSource*)F->data;
obj->rolloffFactor=val_to_c<decltype(obj->rolloffFactor)>::f(ctx,value);
} EI(keyStr=="maxDistance")
{
AudioSource*obj=(AudioSource*)F->data;
obj->maxDistance=val_to_c<decltype(obj->maxDistance)>::f(ctx,value);
} EI(keyStr=="volume")
{
AudioSource*obj=(AudioSource*)F->data;
obj->volume=val_to_c<decltype(obj->volume)>::f(ctx,value);
} EI(keyStr=="velocity")
{
AudioSource*obj=(AudioSource*)F->data;
obj->velocity=val_to_c<decltype(obj->velocity)>::f(ctx,value);
} EI(keyStr=="dopplerFactor")
{
AudioSource*obj=(AudioSource*)F->data;
obj->dopplerFactor=val_to_c<decltype(obj->dopplerFactor)>::f(ctx,value);
} EI(keyStr=="offset")
{
AudioSource*obj=(AudioSource*)F->data;
obj->offset=val_to_c<decltype(obj->offset)>::f(ctx,value);
} EI(keyStr=="loop")
{
AudioSource*obj=(AudioSource*)F->data;
obj->loop=val_to_c<decltype(obj->loop)>::f(ctx,value);
} EI(keyStr=="playing")
{
AudioSource*obj=(AudioSource*)F->data;
obj->playing=val_to_c<decltype(obj->playing)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV AudioSource_getAudio(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioSource::getAudio" EAOE));
AudioSource*F;
if(!TS(a[0],AudioSource))
CATE(TE,FAE("AudioSource::getAudio","AudioSource")));
else
 F=(AudioSource*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getAudio());
;
}
CATE(TE,UFOF("AudioSource::getAudio.")));
R CN;
}

SV AudioSource_setAudio(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioSource::setAudio" EAOE));
AudioSource*F;
if(!TS(a[0],AudioSource))
CATE(TE,FAE("AudioSource::setAudio","AudioSource")));
else
 F=(AudioSource*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],Audio *))
{
( F->setAudio(val_to_c<Audio *>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("AudioSource::setAudio.")));
R CN;
}

void Camera_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,Camera))
CATE(TE,"Camera::__del__ expects Camera as first argument."));

DELETE((Camera*)F->data);
}SV Camera_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera's constructor" EAOE));
if(!TS(a[0],Camera))
CATE(TE,"Camera's constructor expects Camera as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Camera_funcs,NEW(Camera),EXT->Camera_typeID);
CATE(TE,UFOF("Camera's constructor.")));
R CN;
}

SV Camera_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Camera");
EI(keyStr=="__new__")
R CNF(Camera_new);
EI(keyStr=="__call__")
R CNF(Camera_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(Camera_new);
 EI(keyStr == "setType")
R CNF(Camera_setType);
 EI(keyStr == "setPosition")
R CNF(Camera_setPosition);
 EI(keyStr == "setDirection")
R CNF(Camera_setDirection);
 EI(keyStr == "setUp")
R CNF(Camera_setUp);
 EI(keyStr == "setWidth")
R CNF(Camera_setWidth);
 EI(keyStr == "setHeight")
R CNF(Camera_setHeight);
 EI(keyStr == "setFieldOfView")
R CNF(Camera_setFieldOfView);
 EI(keyStr == "setLeft")
R CNF(Camera_setLeft);
 EI(keyStr == "setRight")
R CNF(Camera_setRight);
 EI(keyStr == "setBottom")
R CNF(Camera_setBottom);
 EI(keyStr == "setTop")
R CNF(Camera_setTop);
 EI(keyStr == "setNear")
R CNF(Camera_setNear);
 EI(keyStr == "setFar")
R CNF(Camera_setFar);
 EI(keyStr == "getType")
R CNF(Camera_getType);
 EI(keyStr == "getPosition")
R CNF(Camera_getPosition);
 EI(keyStr == "getDirection")
R CNF(Camera_getDirection);
 EI(keyStr == "getUp")
R CNF(Camera_getUp);
 EI(keyStr == "getWidth")
R CNF(Camera_getWidth);
 EI(keyStr == "getHeight")
R CNF(Camera_getHeight);
 EI(keyStr == "getFieldOfView")
R CNF(Camera_getFieldOfView);
 EI(keyStr == "getLeft")
R CNF(Camera_getLeft);
 EI(keyStr == "getRight")
R CNF(Camera_getRight);
 EI(keyStr == "getBottom")
R CNF(Camera_getBottom);
 EI(keyStr == "getTop")
R CNF(Camera_getTop);
 EI(keyStr == "getNear")
R CNF(Camera_getNear);
 EI(keyStr == "getFar")
R CNF(Camera_getFar);
 EI(keyStr == "getViewMatrix")
R CNF(Camera_getViewMatrix);
 EI(keyStr == "getProjectionMatrix")
R CNF(Camera_getProjectionMatrix);
 else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void Camera_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV Camera_setBottom(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::setBottom" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::setBottom","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->setBottom(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Camera::setBottom.")));
R CN;
}

SV Camera_getRight(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::getRight" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::getRight","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getRight());
;
}
CATE(TE,UFOF("Camera::getRight.")));
R CN;
}

SV Camera_setTop(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::setTop" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::setTop","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->setTop(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Camera::setTop.")));
R CN;
}

SV Camera_getWidth(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::getWidth" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::getWidth","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWidth());
;
}
CATE(TE,UFOF("Camera::getWidth.")));
R CN;
}

SV Camera_getDirection(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::getDirection" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::getDirection","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getDirection());
;
}
CATE(TE,UFOF("Camera::getDirection.")));
R CN;
}

SV Camera_getFieldOfView(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::getFieldOfView" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::getFieldOfView","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getFieldOfView());
;
}
CATE(TE,UFOF("Camera::getFieldOfView.")));
R CN;
}

SV Camera_setWidth(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::setWidth" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::setWidth","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->setWidth(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Camera::setWidth.")));
R CN;
}

SV Camera_setType(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::setType" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::setType","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],CameraType))
{
( F->setType(val_to_c<CameraType>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Camera::setType.")));
R CN;
}

SV Camera_setDirection(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::setDirection" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::setDirection","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Direction3D &))
{
( F->setDirection(val_to_c<const Direction3D &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Camera::setDirection.")));
R CN;
}

SV Camera_getLeft(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::getLeft" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::getLeft","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getLeft());
;
}
CATE(TE,UFOF("Camera::getLeft.")));
R CN;
}

SV Camera_getProjectionMatrix(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::getProjectionMatrix" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::getProjectionMatrix","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getProjectionMatrix());
;
}
CATE(TE,UFOF("Camera::getProjectionMatrix.")));
R CN;
}

SV Camera_getHeight(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::getHeight" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::getHeight","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getHeight());
;
}
CATE(TE,UFOF("Camera::getHeight.")));
R CN;
}

SV Camera_setFar(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::setFar" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::setFar","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->setFar(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Camera::setFar.")));
R CN;
}

SV Camera_setFieldOfView(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::setFieldOfView" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::setFieldOfView","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->setFieldOfView(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Camera::setFieldOfView.")));
R CN;
}

SV Camera_getTop(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::getTop" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::getTop","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getTop());
;
}
CATE(TE,UFOF("Camera::getTop.")));
R CN;
}

SV Camera_getBottom(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::getBottom" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::getBottom","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getBottom());
;
}
CATE(TE,UFOF("Camera::getBottom.")));
R CN;
}

SV Camera_getFar(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::getFar" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::getFar","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getFar());
;
}
CATE(TE,UFOF("Camera::getFar.")));
R CN;
}

SV Camera_setUp(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::setUp" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::setUp","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Direction3D &))
{
( F->setUp(val_to_c<const Direction3D &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Camera::setUp.")));
R CN;
}

SV Camera_getType(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::getType" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::getType","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getType());
;
}
CATE(TE,UFOF("Camera::getType.")));
R CN;
}

SV Camera_setNear(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::setNear" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::setNear","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->setNear(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Camera::setNear.")));
R CN;
}

SV Camera_setPosition(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::setPosition" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::setPosition","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Position3D &))
{
( F->setPosition(val_to_c<const Position3D &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Camera::setPosition.")));
R CN;
}

SV Camera_setLeft(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::setLeft" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::setLeft","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->setLeft(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Camera::setLeft.")));
R CN;
}

SV Camera_getPosition(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::getPosition" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::getPosition","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getPosition());
;
}
CATE(TE,UFOF("Camera::getPosition.")));
R CN;
}

SV Camera_setHeight(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::setHeight" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::setHeight","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->setHeight(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Camera::setHeight.")));
R CN;
}

SV Camera_getViewMatrix(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::getViewMatrix" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::getViewMatrix","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getViewMatrix());
;
}
CATE(TE,UFOF("Camera::getViewMatrix.")));
R CN;
}

SV Camera_getNear(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::getNear" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::getNear","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getNear());
;
}
CATE(TE,UFOF("Camera::getNear.")));
R CN;
}

SV Camera_setRight(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::setRight" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::setRight","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->setRight(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Camera::setRight.")));
R CN;
}

SV Camera_getUp(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::getUp" EAOE));
Camera*F;
if(!TS(a[0],Camera))
CATE(TE,FAE("Camera::getUp","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getUp());
;
}
CATE(TE,UFOF("Camera::getUp.")));
R CN;
}

void Resource_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,Resource))
CATE(TE,"Resource::__del__ expects Resource as first argument."));

Resource*obj=(Resource*)F->data;
obj->release();
}SV Resource_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"Resource's constructor" EAOE));
if(!TS(a[0],Resource))
CATE(TE,"Resource's constructor expects Resource as first argument."));
CATE(TE,UFOF("Resource's constructor.")));
}

SV Resource_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Resource");
EI(keyStr=="__new__")
R CNF(Resource_new);
EI(keyStr=="__call__")
R CNF(Resource_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(Resource_new);
 EI(keyStr == "removeContent")
R CNF(Resource_removeContent);
 EI(keyStr == "load")
R CNF(Resource_load);
 EI(keyStr == "reload")
R CNF(Resource_reload);
 EI(keyStr == "save")
R CNF(Resource_save);
 EI(keyStr == "copy")
R CNF(Resource_copy);
 EI(keyStr == "getType")
R CNF(Resource_getType);
 EI(keyStr == "isLoaded")
R CNF(Resource_isLoaded);
 EI(keyStr == "getLastFileModification")
R CNF(Resource_getLastFileModification);
 EI(keyStr == "shouldReload")
R CNF(Resource_shouldReload);
 EI(keyStr == "possiblyReload")
R CNF(Resource_possiblyReload);
 EI(keyStr == "release")
R CNF(Resource_release);
 EI(keyStr == "getRefCount")
R CNF(Resource_getRefCount);
 EI(keyStr == "getFilename")
R CNF(Resource_getFilename);
 EI(keyStr == "setFilename")
R CNF(Resource_setFilename);
 EI(keyStr=="autoReload")
{
Resource*obj=(Resource*)F->data;
R CV(obj->autoReload);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void Resource_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="autoReload")
{
Resource*obj=(Resource*)F->data;
obj->autoReload=val_to_c<decltype(obj->autoReload)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV Resource_load(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Resource::load" EAOE));
Resource*F;
if(!TS(a[0],Resource))
CATE(TE,FAE("Resource::load","Resource")));
else
 F=(Resource*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->load());
R CN;
}
CATE(TE,UFOF("Resource::load.")));
R CN;
}

SV Resource_getFilename(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Resource::getFilename" EAOE));
Resource*F;
if(!TS(a[0],Resource))
CATE(TE,FAE("Resource::getFilename","Resource")));
else
 F=(Resource*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getFilename());
;
}
CATE(TE,UFOF("Resource::getFilename.")));
R CN;
}

SV Resource_copy(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Resource::copy" EAOE));
Resource*F;
if(!TS(a[0],Resource))
CATE(TE,FAE("Resource::copy","Resource")));
else
 F=(Resource*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->copy());
;
}
CATE(TE,UFOF("Resource::copy.")));
R CN;
}

SV Resource_getLastFileModification(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Resource::getLastFileModification" EAOE));
Resource*F;
if(!TS(a[0],Resource))
CATE(TE,FAE("Resource::getLastFileModification","Resource")));
else
 F=(Resource*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getLastFileModification());
;
}
CATE(TE,UFOF("Resource::getLastFileModification.")));
R CN;
}

SV Resource_possiblyReload(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Resource::possiblyReload" EAOE));
Resource*F;
if(!TS(a[0],Resource))
CATE(TE,FAE("Resource::possiblyReload","Resource")));
else
 F=(Resource*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->possiblyReload());
R CN;
}
CATE(TE,UFOF("Resource::possiblyReload.")));
R CN;
}

SV Resource_getType(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Resource::getType" EAOE));
Resource*F;
if(!TS(a[0],Resource))
CATE(TE,FAE("Resource::getType","Resource")));
else
 F=(Resource*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getType());
;
}
CATE(TE,UFOF("Resource::getType.")));
R CN;
}

SV Resource_setFilename(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Resource::setFilename" EAOE));
Resource*F;
if(!TS(a[0],Resource))
CATE(TE,FAE("Resource::setFilename","Resource")));
else
 F=(Resource*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const String &))
{
( F->setFilename(val_to_c<const String &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Resource::setFilename.")));
R CN;
}

SV Resource_isLoaded(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Resource::isLoaded" EAOE));
Resource*F;
if(!TS(a[0],Resource))
CATE(TE,FAE("Resource::isLoaded","Resource")));
else
 F=(Resource*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->isLoaded());
;
}
CATE(TE,UFOF("Resource::isLoaded.")));
R CN;
}

SV Resource_reload(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Resource::reload" EAOE));
Resource*F;
if(!TS(a[0],Resource))
CATE(TE,FAE("Resource::reload","Resource")));
else
 F=(Resource*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->reload());
R CN;
}
CATE(TE,UFOF("Resource::reload.")));
R CN;
}

SV Resource_removeContent(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Resource::removeContent" EAOE));
Resource*F;
if(!TS(a[0],Resource))
CATE(TE,FAE("Resource::removeContent","Resource")));
else
 F=(Resource*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->removeContent());
R CN;
}
CATE(TE,UFOF("Resource::removeContent.")));
R CN;
}

SV Resource_getRefCount(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Resource::getRefCount" EAOE));
Resource*F;
if(!TS(a[0],Resource))
CATE(TE,FAE("Resource::getRefCount","Resource")));
else
 F=(Resource*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getRefCount());
;
}
CATE(TE,UFOF("Resource::getRefCount.")));
R CN;
}

SV Resource_release(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Resource::release" EAOE));
Resource*F;
if(!TS(a[0],Resource))
CATE(TE,FAE("Resource::release","Resource")));
else
 F=(Resource*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->release());
R CN;
}
CATE(TE,UFOF("Resource::release.")));
R CN;
}

SV Resource_shouldReload(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Resource::shouldReload" EAOE));
Resource*F;
if(!TS(a[0],Resource))
CATE(TE,FAE("Resource::shouldReload","Resource")));
else
 F=(Resource*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->shouldReload());
;
}
CATE(TE,UFOF("Resource::shouldReload.")));
R CN;
}

SV Resource_save(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Resource::save" EAOE));
Resource*F;
if(!TS(a[0],Resource))
CATE(TE,FAE("Resource::save","Resource")));
else
 F=(Resource*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->save());
R CN;
}
CATE(TE,UFOF("Resource::save.")));
R CN;
}

void GfxShader_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,GfxShader))
CATE(TE,"GfxShader::__del__ expects GfxShader as first argument."));

GfxShader*obj=(GfxShader*)F->data;
obj->release();
}SV GfxShader_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"GfxShader's constructor" EAOE));
if(!TS(a[0],GfxShader))
CATE(TE,"GfxShader's constructor expects GfxShader as first argument."));
CATE(TE,UFOF("GfxShader's constructor.")));
}

SV GfxShader_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxShader");
EI(keyStr=="__new__")
R CNF(GfxShader_new);
EI(keyStr=="__call__")
R CNF(GfxShader_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(GfxShader_new);
 EI(keyStr == "removeContent")
R CNF(GfxShader_removeContent);
 EI(keyStr == "save")
R CNF(GfxShader_save);
 EI(keyStr == "setSource")
R CNF(GfxShader_setSource);
 EI(keyStr == "getSource")
R CNF(GfxShader_getSource);
 EI(keyStr == "getCompiled")
R CNF(GfxShader_getCompiled);
 EI(keyStr == "recompile")
R CNF(GfxShader_recompile);
 EI(keyStr == "getStage")
R CNF(GfxShader_getStage);
 EI(keyStr == "getImpl")
R CNF(GfxShader_getImpl);
 EI(keyStr == "possiblyReload")
R CNF(GfxShader_possiblyReload);
 EI(keyStr == "load")
R CNF(GfxShader_load);
 EI(keyStr == "reload")
R CNF(GfxShader_reload);
 EI(keyStr == "copy")
R CNF(GfxShader_copy);
 EI(keyStr == "getType")
R CNF(GfxShader_getType);
 EI(keyStr == "isLoaded")
R CNF(GfxShader_isLoaded);
 EI(keyStr == "getLastFileModification")
R CNF(GfxShader_getLastFileModification);
 EI(keyStr == "shouldReload")
R CNF(GfxShader_shouldReload);
 EI(keyStr == "release")
R CNF(GfxShader_release);
 EI(keyStr == "getRefCount")
R CNF(GfxShader_getRefCount);
 EI(keyStr == "getFilename")
R CNF(GfxShader_getFilename);
 EI(keyStr == "setFilename")
R CNF(GfxShader_setFilename);
 EI(keyStr=="autoReload")
{
GfxShader*obj=(GfxShader*)F->data;
R CV(obj->autoReload);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void GfxShader_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="autoReload")
{
GfxShader*obj=(GfxShader*)F->data;
obj->autoReload=val_to_c<decltype(obj->autoReload)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV GfxShader_load(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxShader::load" EAOE));
GfxShader*F;
if(!TS(a[0],GfxShader))
CATE(TE,FAE("GfxShader::load","GfxShader")));
else
 F=(GfxShader*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->load());
R CN;
}
CATE(TE,UFOF("GfxShader::load.")));
R CN;
}

SV GfxShader_getFilename(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxShader::getFilename" EAOE));
GfxShader*F;
if(!TS(a[0],GfxShader))
CATE(TE,FAE("GfxShader::getFilename","GfxShader")));
else
 F=(GfxShader*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getFilename());
;
}
CATE(TE,UFOF("GfxShader::getFilename.")));
R CN;
}

SV GfxShader_copy(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxShader::copy" EAOE));
GfxShader*F;
if(!TS(a[0],GfxShader))
CATE(TE,FAE("GfxShader::copy","GfxShader")));
else
 F=(GfxShader*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->copy());
;
}
CATE(TE,UFOF("GfxShader::copy.")));
R CN;
}

SV GfxShader_getCompiled(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxShader::getCompiled" EAOE));
GfxShader*F;
if(!TS(a[0],GfxShader))
CATE(TE,FAE("GfxShader::getCompiled","GfxShader")));
else
 F=(GfxShader*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const HashMap<String, String> &))
{
R CV( F->getCompiled(val_to_c<const HashMap<String, String> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("GfxShader::getCompiled.")));
R CN;
}

SV GfxShader_recompile(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxShader::recompile" EAOE));
GfxShader*F;
if(!TS(a[0],GfxShader))
CATE(TE,FAE("GfxShader::recompile","GfxShader")));
else
 F=(GfxShader*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->recompile());
R CN;
}
CATE(TE,UFOF("GfxShader::recompile.")));
R CN;
}

SV GfxShader_possiblyReload(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxShader::possiblyReload" EAOE));
GfxShader*F;
if(!TS(a[0],GfxShader))
CATE(TE,FAE("GfxShader::possiblyReload","GfxShader")));
else
 F=(GfxShader*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->possiblyReload());
R CN;
}
if(a.getCount()==1)
if(1)
{
( F->possiblyReload());
R CN;
}
CATE(TE,UFOF("GfxShader::possiblyReload.")));
R CN;
}

SV GfxShader_getImpl(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxShader::getImpl" EAOE));
GfxShader*F;
if(!TS(a[0],GfxShader))
CATE(TE,FAE("GfxShader::getImpl","GfxShader")));
else
 F=(GfxShader*)((NO)a[0])->data;

CATE(TE,UFOF("GfxShader::getImpl.")));
R CN;
}

SV GfxShader_getType(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxShader::getType" EAOE));
GfxShader*F;
if(!TS(a[0],GfxShader))
CATE(TE,FAE("GfxShader::getType","GfxShader")));
else
 F=(GfxShader*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getType());
;
}
CATE(TE,UFOF("GfxShader::getType.")));
R CN;
}

SV GfxShader_setFilename(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxShader::setFilename" EAOE));
GfxShader*F;
if(!TS(a[0],GfxShader))
CATE(TE,FAE("GfxShader::setFilename","GfxShader")));
else
 F=(GfxShader*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const String &))
{
( F->setFilename(val_to_c<const String &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("GfxShader::setFilename.")));
R CN;
}

SV GfxShader_isLoaded(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxShader::isLoaded" EAOE));
GfxShader*F;
if(!TS(a[0],GfxShader))
CATE(TE,FAE("GfxShader::isLoaded","GfxShader")));
else
 F=(GfxShader*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->isLoaded());
;
}
CATE(TE,UFOF("GfxShader::isLoaded.")));
R CN;
}

SV GfxShader_reload(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxShader::reload" EAOE));
GfxShader*F;
if(!TS(a[0],GfxShader))
CATE(TE,FAE("GfxShader::reload","GfxShader")));
else
 F=(GfxShader*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->reload());
R CN;
}
CATE(TE,UFOF("GfxShader::reload.")));
R CN;
}

SV GfxShader_removeContent(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxShader::removeContent" EAOE));
GfxShader*F;
if(!TS(a[0],GfxShader))
CATE(TE,FAE("GfxShader::removeContent","GfxShader")));
else
 F=(GfxShader*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->removeContent());
R CN;
}
if(a.getCount()==1)
if(1)
{
( F->removeContent());
R CN;
}
CATE(TE,UFOF("GfxShader::removeContent.")));
R CN;
}

SV GfxShader_getRefCount(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxShader::getRefCount" EAOE));
GfxShader*F;
if(!TS(a[0],GfxShader))
CATE(TE,FAE("GfxShader::getRefCount","GfxShader")));
else
 F=(GfxShader*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getRefCount());
;
}
CATE(TE,UFOF("GfxShader::getRefCount.")));
R CN;
}

SV GfxShader_getStage(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxShader::getStage" EAOE));
GfxShader*F;
if(!TS(a[0],GfxShader))
CATE(TE,FAE("GfxShader::getStage","GfxShader")));
else
 F=(GfxShader*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getStage());
;
}
CATE(TE,UFOF("GfxShader::getStage.")));
R CN;
}

SV GfxShader_release(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxShader::release" EAOE));
GfxShader*F;
if(!TS(a[0],GfxShader))
CATE(TE,FAE("GfxShader::release","GfxShader")));
else
 F=(GfxShader*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->release());
R CN;
}
CATE(TE,UFOF("GfxShader::release.")));
R CN;
}

SV GfxShader_getLastFileModification(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxShader::getLastFileModification" EAOE));
GfxShader*F;
if(!TS(a[0],GfxShader))
CATE(TE,FAE("GfxShader::getLastFileModification","GfxShader")));
else
 F=(GfxShader*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getLastFileModification());
;
}
CATE(TE,UFOF("GfxShader::getLastFileModification.")));
R CN;
}

SV GfxShader_getSource(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxShader::getSource" EAOE));
GfxShader*F;
if(!TS(a[0],GfxShader))
CATE(TE,FAE("GfxShader::getSource","GfxShader")));
else
 F=(GfxShader*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getSource());
;
}
CATE(TE,UFOF("GfxShader::getSource.")));
R CN;
}

SV GfxShader_save(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxShader::save" EAOE));
GfxShader*F;
if(!TS(a[0],GfxShader))
CATE(TE,FAE("GfxShader::save","GfxShader")));
else
 F=(GfxShader*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->save());
R CN;
}
if(a.getCount()==1)
if(1)
{
( F->save());
R CN;
}
CATE(TE,UFOF("GfxShader::save.")));
R CN;
}

SV GfxShader_shouldReload(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxShader::shouldReload" EAOE));
GfxShader*F;
if(!TS(a[0],GfxShader))
CATE(TE,FAE("GfxShader::shouldReload","GfxShader")));
else
 F=(GfxShader*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->shouldReload());
;
}
CATE(TE,UFOF("GfxShader::shouldReload.")));
R CN;
}

SV GfxShader_setSource(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxShader::setSource" EAOE));
GfxShader*F;
if(!TS(a[0],GfxShader))
CATE(TE,FAE("GfxShader::setSource","GfxShader")));
else
 F=(GfxShader*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],GfxStage)&&TS(a[2],const String &))
{
( F->setSource(val_to_c<GfxStage>::f(ctx,a[1]), val_to_c<const String &>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("GfxShader::setSource.")));
R CN;
}

void UInt4_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,T4<uint32_t>))
CATE(TE,"UInt4::__del__ expects UInt4 as first argument."));

DELETE((T4<uint32_t>*)F->data);
}SV UInt4_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4's constructor" EAOE));
if(!TS(a[0],T4<uint32_t>))
CATE(TE,"UInt4's constructor expects UInt4 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(UInt4_funcs,NEW(T4<uint32_t>),EXT->UInt4_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],uint32_t))
R S::createNativeObject(UInt4_funcs,NEW(T4<uint32_t>,val_to_c<uint32_t>::f(ctx,a[1])),EXT->UInt4_typeID);
if(a.getCount()==5)
if(true&&TS(a[1],uint32_t)&&TS(a[2],uint32_t)&&TS(a[3],uint32_t)&&TS(a[4],uint32_t))
R S::createNativeObject(UInt4_funcs,NEW(T4<uint32_t>,val_to_c<uint32_t>::f(ctx,a[1]),val_to_c<uint32_t>::f(ctx,a[2]),val_to_c<uint32_t>::f(ctx,a[3]),val_to_c<uint32_t>::f(ctx,a[4])),EXT->UInt4_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T4<float> &))
R S::createNativeObject(UInt4_funcs,NEW(T4<uint32_t>,val_to_c<const T4<float> &>::f(ctx,a[1])),EXT->UInt4_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T4<int32_t> &))
R S::createNativeObject(UInt4_funcs,NEW(T4<uint32_t>,val_to_c<const T4<int32_t> &>::f(ctx,a[1])),EXT->UInt4_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T4<uint32_t> &))
R S::createNativeObject(UInt4_funcs,NEW(T4<uint32_t>,val_to_c<const T4<uint32_t> &>::f(ctx,a[1])),EXT->UInt4_typeID);
CATE(TE,UFOF("UInt4's constructor.")));
R CN;
}

SV UInt4_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("UInt4");
EI(keyStr=="__new__")
R CNF(UInt4_new);
EI(keyStr=="__call__")
R CNF(UInt4_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(UInt4_new);
 EI(keyStr == "__add__")
R CNF(UInt4___add__);
 EI(keyStr == "__sub__")
R CNF(UInt4___sub__);
 EI(keyStr == "__mul__")
R CNF(UInt4___mul__);
 EI(keyStr == "__div__")
R CNF(UInt4___div__);
 EI(keyStr == "__eq__")
R CNF(UInt4___eq__);
 EI(keyStr == "__neq__")
R CNF(UInt4___neq__);
 EI(keyStr == "__less__")
R CNF(UInt4___less__);
 EI(keyStr == "__grtr__")
R CNF(UInt4___grtr__);
 EI(keyStr == "__leq__")
R CNF(UInt4___leq__);
 EI(keyStr == "__geq__")
R CNF(UInt4___geq__);
 EI(keyStr == "sum")
R CNF(UInt4_sum);
 EI(keyStr == "length")
R CNF(UInt4_length);
 EI(keyStr == "lengthSquared")
R CNF(UInt4_lengthSquared);
 EI(keyStr == "dot")
R CNF(UInt4_dot);
 EI(keyStr == "distance")
R CNF(UInt4_distance);
 EI(keyStr == "distanceSquared")
R CNF(UInt4_distanceSquared);
 EI(keyStr == "normalize")
R CNF(UInt4_normalize);
 EI(keyStr == "getXY")
R CNF(UInt4_getXY);
 EI(keyStr == "setXY")
R CNF(UInt4_setXY);
 EI(keyStr == "getXZ")
R CNF(UInt4_getXZ);
 EI(keyStr == "setXZ")
R CNF(UInt4_setXZ);
 EI(keyStr == "getXW")
R CNF(UInt4_getXW);
 EI(keyStr == "setXW")
R CNF(UInt4_setXW);
 EI(keyStr == "getYX")
R CNF(UInt4_getYX);
 EI(keyStr == "setYX")
R CNF(UInt4_setYX);
 EI(keyStr == "getYZ")
R CNF(UInt4_getYZ);
 EI(keyStr == "setYZ")
R CNF(UInt4_setYZ);
 EI(keyStr == "getYW")
R CNF(UInt4_getYW);
 EI(keyStr == "setYW")
R CNF(UInt4_setYW);
 EI(keyStr == "getZX")
R CNF(UInt4_getZX);
 EI(keyStr == "setZX")
R CNF(UInt4_setZX);
 EI(keyStr == "getZY")
R CNF(UInt4_getZY);
 EI(keyStr == "setZY")
R CNF(UInt4_setZY);
 EI(keyStr == "getZW")
R CNF(UInt4_getZW);
 EI(keyStr == "setZW")
R CNF(UInt4_setZW);
 EI(keyStr == "getWX")
R CNF(UInt4_getWX);
 EI(keyStr == "setWX")
R CNF(UInt4_setWX);
 EI(keyStr == "getWY")
R CNF(UInt4_getWY);
 EI(keyStr == "setWY")
R CNF(UInt4_setWY);
 EI(keyStr == "getWZ")
R CNF(UInt4_getWZ);
 EI(keyStr == "setWZ")
R CNF(UInt4_setWZ);
 EI(keyStr == "getXYZ")
R CNF(UInt4_getXYZ);
 EI(keyStr == "setXYZ")
R CNF(UInt4_setXYZ);
 EI(keyStr == "getXYW")
R CNF(UInt4_getXYW);
 EI(keyStr == "setXYW")
R CNF(UInt4_setXYW);
 EI(keyStr == "getXZY")
R CNF(UInt4_getXZY);
 EI(keyStr == "setXZY")
R CNF(UInt4_setXZY);
 EI(keyStr == "getXZW")
R CNF(UInt4_getXZW);
 EI(keyStr == "setXZW")
R CNF(UInt4_setXZW);
 EI(keyStr == "getXWZ")
R CNF(UInt4_getXWZ);
 EI(keyStr == "setXWZ")
R CNF(UInt4_setXWZ);
 EI(keyStr == "getXWY")
R CNF(UInt4_getXWY);
 EI(keyStr == "setXWY")
R CNF(UInt4_setXWY);
 EI(keyStr == "getYXZ")
R CNF(UInt4_getYXZ);
 EI(keyStr == "setYXZ")
R CNF(UInt4_setYXZ);
 EI(keyStr == "getYXW")
R CNF(UInt4_getYXW);
 EI(keyStr == "setYXW")
R CNF(UInt4_setYXW);
 EI(keyStr == "getYZX")
R CNF(UInt4_getYZX);
 EI(keyStr == "setYZX")
R CNF(UInt4_setYZX);
 EI(keyStr == "getYZW")
R CNF(UInt4_getYZW);
 EI(keyStr == "setYZW")
R CNF(UInt4_setYZW);
 EI(keyStr == "getYWZ")
R CNF(UInt4_getYWZ);
 EI(keyStr == "setYWZ")
R CNF(UInt4_setYWZ);
 EI(keyStr == "getYWX")
R CNF(UInt4_getYWX);
 EI(keyStr == "setYWX")
R CNF(UInt4_setYWX);
 EI(keyStr == "getZXY")
R CNF(UInt4_getZXY);
 EI(keyStr == "setZXY")
R CNF(UInt4_setZXY);
 EI(keyStr == "getZXW")
R CNF(UInt4_getZXW);
 EI(keyStr == "setZXW")
R CNF(UInt4_setZXW);
 EI(keyStr == "getZYX")
R CNF(UInt4_getZYX);
 EI(keyStr == "setZYX")
R CNF(UInt4_setZYX);
 EI(keyStr == "getZYW")
R CNF(UInt4_getZYW);
 EI(keyStr == "setZYW")
R CNF(UInt4_setZYW);
 EI(keyStr == "getZWY")
R CNF(UInt4_getZWY);
 EI(keyStr == "setZWY")
R CNF(UInt4_setZWY);
 EI(keyStr == "getZWX")
R CNF(UInt4_getZWX);
 EI(keyStr == "setZWX")
R CNF(UInt4_setZWX);
 EI(keyStr == "getWXY")
R CNF(UInt4_getWXY);
 EI(keyStr == "setWXY")
R CNF(UInt4_setWXY);
 EI(keyStr == "getWXZ")
R CNF(UInt4_getWXZ);
 EI(keyStr == "setWXZ")
R CNF(UInt4_setWXZ);
 EI(keyStr == "getWYX")
R CNF(UInt4_getWYX);
 EI(keyStr == "setWYX")
R CNF(UInt4_setWYX);
 EI(keyStr == "getWYZ")
R CNF(UInt4_getWYZ);
 EI(keyStr == "setWYZ")
R CNF(UInt4_setWYZ);
 EI(keyStr == "getWZY")
R CNF(UInt4_getWZY);
 EI(keyStr == "setWZY")
R CNF(UInt4_setWZY);
 EI(keyStr == "getWZX")
R CNF(UInt4_getWZX);
 EI(keyStr == "setWZX")
R CNF(UInt4_setWZX);
 EI(keyStr == "getXYZW")
R CNF(UInt4_getXYZW);
 EI(keyStr == "setXYZW")
R CNF(UInt4_setXYZW);
 EI(keyStr == "getXYWZ")
R CNF(UInt4_getXYWZ);
 EI(keyStr == "setXYWZ")
R CNF(UInt4_setXYWZ);
 EI(keyStr == "getXZYW")
R CNF(UInt4_getXZYW);
 EI(keyStr == "setXZYW")
R CNF(UInt4_setXZYW);
 EI(keyStr == "getXZWY")
R CNF(UInt4_getXZWY);
 EI(keyStr == "setXZWY")
R CNF(UInt4_setXZWY);
 EI(keyStr == "getXWZY")
R CNF(UInt4_getXWZY);
 EI(keyStr == "setXWZY")
R CNF(UInt4_setXWZY);
 EI(keyStr == "getXWYZ")
R CNF(UInt4_getXWYZ);
 EI(keyStr == "setXWYZ")
R CNF(UInt4_setXWYZ);
 EI(keyStr == "getYXZW")
R CNF(UInt4_getYXZW);
 EI(keyStr == "setYXZW")
R CNF(UInt4_setYXZW);
 EI(keyStr == "getYXWZ")
R CNF(UInt4_getYXWZ);
 EI(keyStr == "setYXWZ")
R CNF(UInt4_setYXWZ);
 EI(keyStr == "getYZXW")
R CNF(UInt4_getYZXW);
 EI(keyStr == "setYZXW")
R CNF(UInt4_setYZXW);
 EI(keyStr == "getYZWX")
R CNF(UInt4_getYZWX);
 EI(keyStr == "setYZWX")
R CNF(UInt4_setYZWX);
 EI(keyStr == "getYWZX")
R CNF(UInt4_getYWZX);
 EI(keyStr == "setYWZX")
R CNF(UInt4_setYWZX);
 EI(keyStr == "getYWXZ")
R CNF(UInt4_getYWXZ);
 EI(keyStr == "setYWXZ")
R CNF(UInt4_setYWXZ);
 EI(keyStr == "getZYXW")
R CNF(UInt4_getZYXW);
 EI(keyStr == "setZYXW")
R CNF(UInt4_setZYXW);
 EI(keyStr == "getZYWX")
R CNF(UInt4_getZYWX);
 EI(keyStr == "setZYWX")
R CNF(UInt4_setZYWX);
 EI(keyStr == "getZXYW")
R CNF(UInt4_getZXYW);
 EI(keyStr == "setZXYW")
R CNF(UInt4_setZXYW);
 EI(keyStr == "getZXWY")
R CNF(UInt4_getZXWY);
 EI(keyStr == "setZXWY")
R CNF(UInt4_setZXWY);
 EI(keyStr == "getZWXY")
R CNF(UInt4_getZWXY);
 EI(keyStr == "setZWXY")
R CNF(UInt4_setZWXY);
 EI(keyStr == "getZWYX")
R CNF(UInt4_getZWYX);
 EI(keyStr == "setZWYX")
R CNF(UInt4_setZWYX);
 EI(keyStr == "getWYZX")
R CNF(UInt4_getWYZX);
 EI(keyStr == "setWYZX")
R CNF(UInt4_setWYZX);
 EI(keyStr == "getWYXZ")
R CNF(UInt4_getWYXZ);
 EI(keyStr == "setWYXZ")
R CNF(UInt4_setWYXZ);
 EI(keyStr == "getWZYX")
R CNF(UInt4_getWZYX);
 EI(keyStr == "setWZYX")
R CNF(UInt4_setWZYX);
 EI(keyStr == "getWZXY")
R CNF(UInt4_getWZXY);
 EI(keyStr == "setWZXY")
R CNF(UInt4_setWZXY);
 EI(keyStr == "getWXZY")
R CNF(UInt4_getWXZY);
 EI(keyStr == "setWXZY")
R CNF(UInt4_setWXZY);
 EI(keyStr == "getWXYZ")
R CNF(UInt4_getWXYZ);
 EI(keyStr == "setWXYZ")
R CNF(UInt4_setWXYZ);
 EI(keyStr=="x")
{
T4<uint32_t>*obj=(T4<uint32_t>*)F->data;
R CV(obj->x);
} EI(keyStr=="y")
{
T4<uint32_t>*obj=(T4<uint32_t>*)F->data;
R CV(obj->y);
} EI(keyStr=="z")
{
T4<uint32_t>*obj=(T4<uint32_t>*)F->data;
R CV(obj->z);
} EI(keyStr=="w")
{
T4<uint32_t>*obj=(T4<uint32_t>*)F->data;
R CV(obj->w);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void UInt4_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="x")
{
T4<uint32_t>*obj=(T4<uint32_t>*)F->data;
obj->x=val_to_c<decltype(obj->x)>::f(ctx,value);
} EI(keyStr=="y")
{
T4<uint32_t>*obj=(T4<uint32_t>*)F->data;
obj->y=val_to_c<decltype(obj->y)>::f(ctx,value);
} EI(keyStr=="z")
{
T4<uint32_t>*obj=(T4<uint32_t>*)F->data;
obj->z=val_to_c<decltype(obj->z)>::f(ctx,value);
} EI(keyStr=="w")
{
T4<uint32_t>*obj=(T4<uint32_t>*)F->data;
obj->w=val_to_c<decltype(obj->w)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV UInt4_setZXYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setZXYW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setZXYW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setZXYW(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setZXYW.")));
R CN;
}

SV UInt4_setWYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setWYZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setWYZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setWYZ(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setWYZ.")));
R CN;
}

SV UInt4_setWYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setWYX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setWYX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setWYX(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setWYX.")));
R CN;
}

SV UInt4_getZWYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getZWYX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getZWYX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZWYX());
;
}
CATE(TE,UFOF("UInt4::getZWYX.")));
R CN;
}

SV UInt4_getZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getZW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getZW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZW());
;
}
CATE(TE,UFOF("UInt4::getZW.")));
R CN;
}

SV UInt4_getZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getZY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getZY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZY());
;
}
CATE(TE,UFOF("UInt4::getZY.")));
R CN;
}

SV UInt4_distanceSquared(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::distanceSquared" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::distanceSquared","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
R CV( F->distanceSquared(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("UInt4::distanceSquared.")));
R CN;
}

SV UInt4_getYXZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getYXZW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getYXZW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYXZW());
;
}
CATE(TE,UFOF("UInt4::getYXZW.")));
R CN;
}

SV UInt4_setYZWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setYZWX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setYZWX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setYZWX(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setYZWX.")));
R CN;
}

SV UInt4_getYWZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getYWZX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getYWZX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYWZX());
;
}
CATE(TE,UFOF("UInt4::getYWZX.")));
R CN;
}

SV UInt4_getWZXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getWZXY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getWZXY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWZXY());
;
}
CATE(TE,UFOF("UInt4::getWZXY.")));
R CN;
}

SV UInt4_getZYXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getZYXW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getZYXW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZYXW());
;
}
CATE(TE,UFOF("UInt4::getZYXW.")));
R CN;
}

SV UInt4_setXWYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setXWYZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setXWYZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setXWYZ(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setXWYZ.")));
R CN;
}

SV UInt4_setZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setZY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setZY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
( F->setZY(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setZY.")));
R CN;
}

SV UInt4_setZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setZX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setZX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
( F->setZX(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setZX.")));
R CN;
}

SV UInt4_getZXWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getZXWY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getZXWY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZXWY());
;
}
CATE(TE,UFOF("UInt4::getZXWY.")));
R CN;
}

SV UInt4_getXWZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getXWZY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getXWZY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXWZY());
;
}
CATE(TE,UFOF("UInt4::getXWZY.")));
R CN;
}

SV UInt4_setZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setZW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setZW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
( F->setZW(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setZW.")));
R CN;
}

SV UInt4_setZYWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setZYWX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setZYWX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setZYWX(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setZYWX.")));
R CN;
}

SV UInt4_getYZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getYZX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getYZX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYZX());
;
}
CATE(TE,UFOF("UInt4::getYZX.")));
R CN;
}

SV UInt4_getXYWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getXYWZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getXYWZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXYWZ());
;
}
CATE(TE,UFOF("UInt4::getXYWZ.")));
R CN;
}

SV UInt4_setYXZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setYXZW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setYXZW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setYXZW(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setYXZW.")));
R CN;
}

SV UInt4_getWZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getWZY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getWZY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWZY());
;
}
CATE(TE,UFOF("UInt4::getWZY.")));
R CN;
}

SV UInt4_getWZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getWZX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getWZX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWZX());
;
}
CATE(TE,UFOF("UInt4::getWZX.")));
R CN;
}

SV UInt4_getWZYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getWZYX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getWZYX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWZYX());
;
}
CATE(TE,UFOF("UInt4::getWZYX.")));
R CN;
}

SV UInt4_setXWZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setXWZY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setXWZY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setXWZY(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setXWZY.")));
R CN;
}

SV UInt4_getZXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getZXY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getZXY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZXY());
;
}
CATE(TE,UFOF("UInt4::getZXY.")));
R CN;
}

SV UInt4_setWZYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setWZYX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setWZYX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setWZYX(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setWZYX.")));
R CN;
}

SV UInt4_setZYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setZYW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setZYW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setZYW(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setZYW.")));
R CN;
}

SV UInt4_setZYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setZYX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setZYX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setZYX(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setZYX.")));
R CN;
}

SV UInt4_setXZYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setXZYW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setXZYW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setXZYW(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setXZYW.")));
R CN;
}

SV UInt4_getZXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getZXW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getZXW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZXW());
;
}
CATE(TE,UFOF("UInt4::getZXW.")));
R CN;
}

SV UInt4_setYZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setYZW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setYZW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setYZW(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setYZW.")));
R CN;
}

SV UInt4_getYWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getYWZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getYWZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYWZ());
;
}
CATE(TE,UFOF("UInt4::getYWZ.")));
R CN;
}

SV UInt4___leq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::__leq__" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::__leq__","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
auto v=val_to_c<const T4<uint32_t> &>::f(ctx,a[1]);
R CV(*F <= v);
}
CATE(TE,UFOF("UInt4::__leq__.")));
R CN;
}

SV UInt4_getYWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getYWX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getYWX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYWX());
;
}
CATE(TE,UFOF("UInt4::getYWX.")));
R CN;
}

SV UInt4_sum(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::sum" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::sum","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->sum());
;
}
CATE(TE,UFOF("UInt4::sum.")));
R CN;
}

SV UInt4_setYZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setYZX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setYZX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setYZX(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setYZX.")));
R CN;
}

SV UInt4_getXYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getXYZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getXYZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXYZ());
;
}
CATE(TE,UFOF("UInt4::getXYZ.")));
R CN;
}

SV UInt4_getZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getZX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getZX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZX());
;
}
CATE(TE,UFOF("UInt4::getZX.")));
R CN;
}

SV UInt4_getXYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getXYW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getXYW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXYW());
;
}
CATE(TE,UFOF("UInt4::getXYW.")));
R CN;
}

SV UInt4_setYWZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setYWZX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setYWZX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setYWZX(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setYWZX.")));
R CN;
}

SV UInt4_setWXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setWXY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setWXY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setWXY(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setWXY.")));
R CN;
}

SV UInt4_setWXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setWXZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setWXZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setWXZ(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setWXZ.")));
R CN;
}

SV UInt4_setZXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setZXW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setZXW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setZXW(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setZXW.")));
R CN;
}

SV UInt4_getXWYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getXWYZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getXWYZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXWYZ());
;
}
CATE(TE,UFOF("UInt4::getXWYZ.")));
R CN;
}

SV UInt4_setWYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setWYXZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setWYXZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setWYXZ(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setWYXZ.")));
R CN;
}

SV UInt4_setZXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setZXY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setZXY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setZXY(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setZXY.")));
R CN;
}

SV UInt4_getXWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getXWY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getXWY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXWY());
;
}
CATE(TE,UFOF("UInt4::getXWY.")));
R CN;
}

SV UInt4_getYXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getYXW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getYXW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYXW());
;
}
CATE(TE,UFOF("UInt4::getYXW.")));
R CN;
}

SV UInt4_getYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getYXZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getYXZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYXZ());
;
}
CATE(TE,UFOF("UInt4::getYXZ.")));
R CN;
}

SV UInt4_setXYWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setXYWZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setXYWZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setXYWZ(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setXYWZ.")));
R CN;
}

SV UInt4_length(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::length" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::length","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->length());
;
}
CATE(TE,UFOF("UInt4::length.")));
R CN;
}

SV UInt4_setWXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setWXZY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setWXZY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setWXZY(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setWXZY.")));
R CN;
}

SV UInt4_getYZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getYZW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getYZW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYZW());
;
}
CATE(TE,UFOF("UInt4::getYZW.")));
R CN;
}

SV UInt4_setXWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setXWZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setXWZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setXWZ(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setXWZ.")));
R CN;
}

SV UInt4_setXWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setXWY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setXWY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setXWY(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setXWY.")));
R CN;
}

SV UInt4_getWYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getWYZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getWYZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWYZ());
;
}
CATE(TE,UFOF("UInt4::getWYZ.")));
R CN;
}

SV UInt4_getWYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getWYX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getWYX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWYX());
;
}
CATE(TE,UFOF("UInt4::getWYX.")));
R CN;
}

SV UInt4_getZYWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getZYWX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getZYWX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZYWX());
;
}
CATE(TE,UFOF("UInt4::getZYWX.")));
R CN;
}

SV UInt4_getXYZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getXYZW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getXYZW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXYZW());
;
}
CATE(TE,UFOF("UInt4::getXYZW.")));
R CN;
}

SV UInt4_setZWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setZWY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setZWY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setZWY(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setZWY.")));
R CN;
}

SV UInt4_setZWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setZWX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setZWX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setZWX(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setZWX.")));
R CN;
}

SV UInt4_setWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setWX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setWX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
( F->setWX(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setWX.")));
R CN;
}

SV UInt4_setWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setWY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setWY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
( F->setWY(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setWY.")));
R CN;
}

SV UInt4_setWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setWZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setWZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
( F->setWZ(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setWZ.")));
R CN;
}

SV UInt4_getZWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getZWY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getZWY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZWY());
;
}
CATE(TE,UFOF("UInt4::getZWY.")));
R CN;
}

SV UInt4_getZWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getZWX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getZWX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZWX());
;
}
CATE(TE,UFOF("UInt4::getZWX.")));
R CN;
}

SV UInt4_setYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setYXZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setYXZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setYXZ(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setYXZ.")));
R CN;
}

SV UInt4_setYXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setYXW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setYXW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setYXW(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setYXW.")));
R CN;
}

SV UInt4_getXWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getXWZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getXWZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXWZ());
;
}
CATE(TE,UFOF("UInt4::getXWZ.")));
R CN;
}

SV UInt4_getXZWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getXZWY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getXZWY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXZWY());
;
}
CATE(TE,UFOF("UInt4::getXZWY.")));
R CN;
}

SV UInt4___less__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::__less__" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::__less__","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
auto v=val_to_c<const T4<uint32_t> &>::f(ctx,a[1]);
R CV(*F < v);
}
CATE(TE,UFOF("UInt4::__less__.")));
R CN;
}

SV UInt4_getZYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getZYW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getZYW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZYW());
;
}
CATE(TE,UFOF("UInt4::getZYW.")));
R CN;
}

SV UInt4_setWZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setWZY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setWZY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setWZY(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setWZY.")));
R CN;
}

SV UInt4_setWZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setWZX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setWZX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setWZX(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setWZX.")));
R CN;
}

SV UInt4_setZYXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setZYXW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setZYXW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setZYXW(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setZYXW.")));
R CN;
}

SV UInt4_getYZWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getYZWX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getYZWX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYZWX());
;
}
CATE(TE,UFOF("UInt4::getYZWX.")));
R CN;
}

SV UInt4_getZYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getZYX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getZYX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZYX());
;
}
CATE(TE,UFOF("UInt4::getZYX.")));
R CN;
}

SV UInt4_getXZYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getXZYW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getXZYW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXZYW());
;
}
CATE(TE,UFOF("UInt4::getXZYW.")));
R CN;
}

SV UInt4_setYXWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setYXWZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setYXWZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setYXWZ(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setYXWZ.")));
R CN;
}

SV UInt4___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::__eq__" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::__eq__","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
auto v=val_to_c<const T4<uint32_t> &>::f(ctx,a[1]);
R CV(*F == v);
}
CATE(TE,UFOF("UInt4::__eq__.")));
R CN;
}

SV UInt4_getWYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getWYXZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getWYXZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWYXZ());
;
}
CATE(TE,UFOF("UInt4::getWYXZ.")));
R CN;
}

SV UInt4_distance(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::distance" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::distance","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
R CV( F->distance(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("UInt4::distance.")));
R CN;
}

SV UInt4_getXZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getXZW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getXZW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXZW());
;
}
CATE(TE,UFOF("UInt4::getXZW.")));
R CN;
}

SV UInt4_setYZXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setYZXW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setYZXW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setYZXW(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setYZXW.")));
R CN;
}

SV UInt4_getZWXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getZWXY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getZWXY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZWXY());
;
}
CATE(TE,UFOF("UInt4::getZWXY.")));
R CN;
}

SV UInt4_getXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getXZY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getXZY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXZY());
;
}
CATE(TE,UFOF("UInt4::getXZY.")));
R CN;
}

SV UInt4_getYZXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getYZXW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getYZXW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYZXW());
;
}
CATE(TE,UFOF("UInt4::getYZXW.")));
R CN;
}

SV UInt4_setZWYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setZWYX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setZWYX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setZWYX(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setZWYX.")));
R CN;
}

SV UInt4___sub__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::__sub__" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::__sub__","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
auto v=val_to_c<const T4<uint32_t> &>::f(ctx,a[1]);
R CV(*F - v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const uint32_t&))
{
auto v=val_to_c<const uint32_t&>::f(ctx,a[1]);
R CV(*F - v);
}
CATE(TE,UFOF("UInt4::__sub__.")));
R CN;
}

SV UInt4_getYXWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getYXWZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getYXWZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYXWZ());
;
}
CATE(TE,UFOF("UInt4::getYXWZ.")));
R CN;
}

SV UInt4_setXZWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setXZWY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setXZWY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setXZWY(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setXZWY.")));
R CN;
}

SV UInt4_setYWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setYWZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setYWZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setYWZ(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setYWZ.")));
R CN;
}

SV UInt4_setYWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setYWX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setYWX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setYWX(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setYWX.")));
R CN;
}

SV UInt4_setYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setYZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setYZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
( F->setYZ(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setYZ.")));
R CN;
}

SV UInt4_setYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setYX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setYX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
( F->setYX(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setYX.")));
R CN;
}

SV UInt4_setYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setYW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setYW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
( F->setYW(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setYW.")));
R CN;
}

SV UInt4_getWXYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getWXYZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getWXYZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWXYZ());
;
}
CATE(TE,UFOF("UInt4::getWXYZ.")));
R CN;
}

SV UInt4___neq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::__neq__" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::__neq__","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
auto v=val_to_c<const T4<uint32_t> &>::f(ctx,a[1]);
R CV(*F != v);
}
CATE(TE,UFOF("UInt4::__neq__.")));
R CN;
}

SV UInt4_normalize(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::normalize" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::normalize","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->normalize());
;
}
CATE(TE,UFOF("UInt4::normalize.")));
R CN;
}

SV UInt4_getYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getYX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getYX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYX());
;
}
CATE(TE,UFOF("UInt4::getYX.")));
R CN;
}

SV UInt4_setXZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setXZW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setXZW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setXZW(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setXZW.")));
R CN;
}

SV UInt4_setXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setXZY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setXZY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setXZY(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setXZY.")));
R CN;
}

SV UInt4_setXYZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setXYZW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setXYZW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setXYZW(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setXYZW.")));
R CN;
}

SV UInt4_getYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getYW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getYW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYW());
;
}
CATE(TE,UFOF("UInt4::getYW.")));
R CN;
}

SV UInt4_setWXYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setWXYZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setWXYZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setWXYZ(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setWXYZ.")));
R CN;
}

SV UInt4_getYWXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getYWXZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getYWXZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYWXZ());
;
}
CATE(TE,UFOF("UInt4::getYWXZ.")));
R CN;
}

SV UInt4___mul__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::__mul__" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::__mul__","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
auto v=val_to_c<const T4<uint32_t> &>::f(ctx,a[1]);
R CV(*F * v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const uint32_t&))
{
auto v=val_to_c<const uint32_t&>::f(ctx,a[1]);
R CV(*F * v);
}
CATE(TE,UFOF("UInt4::__mul__.")));
R CN;
}

SV UInt4_getYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getYZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getYZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYZ());
;
}
CATE(TE,UFOF("UInt4::getYZ.")));
R CN;
}

SV UInt4_lengthSquared(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::lengthSquared" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::lengthSquared","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->lengthSquared());
;
}
CATE(TE,UFOF("UInt4::lengthSquared.")));
R CN;
}

SV UInt4_getWXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getWXY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getWXY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWXY());
;
}
CATE(TE,UFOF("UInt4::getWXY.")));
R CN;
}

SV UInt4_getWXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getWXZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getWXZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWXZ());
;
}
CATE(TE,UFOF("UInt4::getWXZ.")));
R CN;
}

SV UInt4_getWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getWX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getWX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWX());
;
}
CATE(TE,UFOF("UInt4::getWX.")));
R CN;
}

SV UInt4_getWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getWY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getWY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWY());
;
}
CATE(TE,UFOF("UInt4::getWY.")));
R CN;
}

SV UInt4_getWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getWZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getWZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWZ());
;
}
CATE(TE,UFOF("UInt4::getWZ.")));
R CN;
}

SV UInt4_setXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setXY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setXY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
( F->setXY(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setXY.")));
R CN;
}

SV UInt4_getZXYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getZXYW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getZXYW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZXYW());
;
}
CATE(TE,UFOF("UInt4::getZXYW.")));
R CN;
}

SV UInt4___add__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::__add__" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::__add__","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
auto v=val_to_c<const T4<uint32_t> &>::f(ctx,a[1]);
R CV(*F + v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const uint32_t&))
{
auto v=val_to_c<const uint32_t&>::f(ctx,a[1]);
R CV(*F + v);
}
CATE(TE,UFOF("UInt4::__add__.")));
R CN;
}

SV UInt4_setXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setXZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setXZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
( F->setXZ(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setXZ.")));
R CN;
}

SV UInt4_getWYZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getWYZX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getWYZX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWYZX());
;
}
CATE(TE,UFOF("UInt4::getWYZX.")));
R CN;
}

SV UInt4_setXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setXW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setXW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
( F->setXW(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setXW.")));
R CN;
}

SV UInt4_getWXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getWXZY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getWXZY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWXZY());
;
}
CATE(TE,UFOF("UInt4::getWXZY.")));
R CN;
}

SV UInt4_getXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getXY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getXY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXY());
;
}
CATE(TE,UFOF("UInt4::getXY.")));
R CN;
}

SV UInt4_setZXWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setZXWY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setZXWY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setZXWY(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setZXWY.")));
R CN;
}

SV UInt4_setXYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setXYW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setXYW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setXYW(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setXYW.")));
R CN;
}

SV UInt4_getXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getXZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getXZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXZ());
;
}
CATE(TE,UFOF("UInt4::getXZ.")));
R CN;
}

SV UInt4_setWZXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setWZXY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setWZXY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setWZXY(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setWZXY.")));
R CN;
}

SV UInt4___grtr__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::__grtr__" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::__grtr__","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
auto v=val_to_c<const T4<uint32_t> &>::f(ctx,a[1]);
R CV(*F > v);
}
CATE(TE,UFOF("UInt4::__grtr__.")));
R CN;
}

SV UInt4_setZWXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setZWXY" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setZWXY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setZWXY(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setZWXY.")));
R CN;
}

SV UInt4_getXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getXW" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::getXW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXW());
;
}
CATE(TE,UFOF("UInt4::getXW.")));
R CN;
}

SV UInt4_setXYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setXYZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setXYZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setXYZ(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setXYZ.")));
R CN;
}

SV UInt4___div__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::__div__" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::__div__","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
auto v=val_to_c<const T4<uint32_t> &>::f(ctx,a[1]);
R CV(*F / v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const uint32_t&))
{
auto v=val_to_c<const uint32_t&>::f(ctx,a[1]);
R CV(*F / v);
}
CATE(TE,UFOF("UInt4::__div__.")));
R CN;
}

SV UInt4_setWYZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setWYZX" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setWYZX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setWYZX(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setWYZX.")));
R CN;
}

SV UInt4_setYWXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setYWXZ" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::setYWXZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
( F->setYWXZ(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt4::setYWXZ.")));
R CN;
}

SV UInt4___geq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::__geq__" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::__geq__","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
auto v=val_to_c<const T4<uint32_t> &>::f(ctx,a[1]);
R CV(*F >= v);
}
CATE(TE,UFOF("UInt4::__geq__.")));
R CN;
}

SV UInt4_dot(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::dot" EAOE));
T4<uint32_t>*F;
if(!TS(a[0],T4<uint32_t>))
CATE(TE,FAE("UInt4::dot","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<uint32_t> &))
{
R CV( F->dot(val_to_c<const T4<uint32_t> &>::f(ctx,a[1])));
;
}
if(a.getCount()==1)
if(1)
{
R CV( F->dot());
;
}
CATE(TE,UFOF("UInt4::dot.")));
R CN;
}

void Int3_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,T3<int32_t>))
CATE(TE,"Int3::__del__ expects Int3 as first argument."));

DELETE((T3<int32_t>*)F->data);
}SV Int3_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3's constructor" EAOE));
if(!TS(a[0],T3<int32_t>))
CATE(TE,"Int3's constructor expects Int3 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Int3_funcs,NEW(T3<int32_t>),EXT->Int3_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],int32_t))
R S::createNativeObject(Int3_funcs,NEW(T3<int32_t>,val_to_c<int32_t>::f(ctx,a[1])),EXT->Int3_typeID);
if(a.getCount()==4)
if(true&&TS(a[1],int32_t)&&TS(a[2],int32_t)&&TS(a[3],int32_t))
R S::createNativeObject(Int3_funcs,NEW(T3<int32_t>,val_to_c<int32_t>::f(ctx,a[1]),val_to_c<int32_t>::f(ctx,a[2]),val_to_c<int32_t>::f(ctx,a[3])),EXT->Int3_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T3<float> &))
R S::createNativeObject(Int3_funcs,NEW(T3<int32_t>,val_to_c<const T3<float> &>::f(ctx,a[1])),EXT->Int3_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T3<int32_t> &))
R S::createNativeObject(Int3_funcs,NEW(T3<int32_t>,val_to_c<const T3<int32_t> &>::f(ctx,a[1])),EXT->Int3_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T3<uint32_t> &))
R S::createNativeObject(Int3_funcs,NEW(T3<int32_t>,val_to_c<const T3<uint32_t> &>::f(ctx,a[1])),EXT->Int3_typeID);
CATE(TE,UFOF("Int3's constructor.")));
R CN;
}

SV Int3_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Int3");
EI(keyStr=="__new__")
R CNF(Int3_new);
EI(keyStr=="__call__")
R CNF(Int3_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(Int3_new);
 EI(keyStr == "__add__")
R CNF(Int3___add__);
 EI(keyStr == "__sub__")
R CNF(Int3___sub__);
 EI(keyStr == "__mul__")
R CNF(Int3___mul__);
 EI(keyStr == "__div__")
R CNF(Int3___div__);
 EI(keyStr == "__eq__")
R CNF(Int3___eq__);
 EI(keyStr == "__neq__")
R CNF(Int3___neq__);
 EI(keyStr == "__less__")
R CNF(Int3___less__);
 EI(keyStr == "__grtr__")
R CNF(Int3___grtr__);
 EI(keyStr == "__leq__")
R CNF(Int3___leq__);
 EI(keyStr == "__geq__")
R CNF(Int3___geq__);
 EI(keyStr == "sum")
R CNF(Int3_sum);
 EI(keyStr == "length")
R CNF(Int3_length);
 EI(keyStr == "lengthSquared")
R CNF(Int3_lengthSquared);
 EI(keyStr == "dot")
R CNF(Int3_dot);
 EI(keyStr == "distance")
R CNF(Int3_distance);
 EI(keyStr == "distanceSquared")
R CNF(Int3_distanceSquared);
 EI(keyStr == "normalize")
R CNF(Int3_normalize);
 EI(keyStr == "cross")
R CNF(Int3_cross);
 EI(keyStr == "getXY")
R CNF(Int3_getXY);
 EI(keyStr == "setXY")
R CNF(Int3_setXY);
 EI(keyStr == "getXZ")
R CNF(Int3_getXZ);
 EI(keyStr == "setXZ")
R CNF(Int3_setXZ);
 EI(keyStr == "getYX")
R CNF(Int3_getYX);
 EI(keyStr == "setYX")
R CNF(Int3_setYX);
 EI(keyStr == "getYZ")
R CNF(Int3_getYZ);
 EI(keyStr == "setYZ")
R CNF(Int3_setYZ);
 EI(keyStr == "getZX")
R CNF(Int3_getZX);
 EI(keyStr == "setZX")
R CNF(Int3_setZX);
 EI(keyStr == "getZY")
R CNF(Int3_getZY);
 EI(keyStr == "setZY")
R CNF(Int3_setZY);
 EI(keyStr == "getXYZ")
R CNF(Int3_getXYZ);
 EI(keyStr == "setXYZ")
R CNF(Int3_setXYZ);
 EI(keyStr == "getXZY")
R CNF(Int3_getXZY);
 EI(keyStr == "setXZY")
R CNF(Int3_setXZY);
 EI(keyStr == "getYXZ")
R CNF(Int3_getYXZ);
 EI(keyStr == "setYXZ")
R CNF(Int3_setYXZ);
 EI(keyStr == "getYZX")
R CNF(Int3_getYZX);
 EI(keyStr == "setYZX")
R CNF(Int3_setYZX);
 EI(keyStr == "getZXY")
R CNF(Int3_getZXY);
 EI(keyStr == "setZXY")
R CNF(Int3_setZXY);
 EI(keyStr == "getZYX")
R CNF(Int3_getZYX);
 EI(keyStr == "setZYX")
R CNF(Int3_setZYX);
 EI(keyStr=="x")
{
T3<int32_t>*obj=(T3<int32_t>*)F->data;
R CV(obj->x);
} EI(keyStr=="y")
{
T3<int32_t>*obj=(T3<int32_t>*)F->data;
R CV(obj->y);
} EI(keyStr=="z")
{
T3<int32_t>*obj=(T3<int32_t>*)F->data;
R CV(obj->z);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void Int3_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="x")
{
T3<int32_t>*obj=(T3<int32_t>*)F->data;
obj->x=val_to_c<decltype(obj->x)>::f(ctx,value);
} EI(keyStr=="y")
{
T3<int32_t>*obj=(T3<int32_t>*)F->data;
obj->y=val_to_c<decltype(obj->y)>::f(ctx,value);
} EI(keyStr=="z")
{
T3<int32_t>*obj=(T3<int32_t>*)F->data;
obj->z=val_to_c<decltype(obj->z)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV Int3_setYZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::setYZX" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::setYZX","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setYZX(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int3::setYZX.")));
R CN;
}

SV Int3_getZXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::getZXY" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::getZXY","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZXY());
;
}
CATE(TE,UFOF("Int3::getZXY.")));
R CN;
}

SV Int3_setYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::setYZ" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::setYZ","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
( F->setYZ(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int3::setYZ.")));
R CN;
}

SV Int3_setYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::setYX" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::setYX","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
( F->setYX(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int3::setYX.")));
R CN;
}

SV Int3_setZYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::setZYX" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::setZYX","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setZYX(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int3::setZYX.")));
R CN;
}

SV Int3_getZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::getZY" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::getZY","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZY());
;
}
CATE(TE,UFOF("Int3::getZY.")));
R CN;
}

SV Int3_distanceSquared(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::distanceSquared" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::distanceSquared","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
R CV( F->distanceSquared(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Int3::distanceSquared.")));
R CN;
}

SV Int3_normalize(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::normalize" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::normalize","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->normalize());
;
}
CATE(TE,UFOF("Int3::normalize.")));
R CN;
}

SV Int3_getYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::getYX" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::getYX","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYX());
;
}
CATE(TE,UFOF("Int3::getYX.")));
R CN;
}

SV Int3___leq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::__leq__" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::__leq__","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
auto v=val_to_c<const T3<int32_t> &>::f(ctx,a[1]);
R CV(*F <= v);
}
CATE(TE,UFOF("Int3::__leq__.")));
R CN;
}

SV Int3_setXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::setXZY" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::setXZY","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setXZY(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int3::setXZY.")));
R CN;
}

SV Int3_sum(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::sum" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::sum","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->sum());
;
}
CATE(TE,UFOF("Int3::sum.")));
R CN;
}

SV Int3_cross(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::cross" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::cross","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
R CV( F->cross(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Int3::cross.")));
R CN;
}

SV Int3_getXYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::getXYZ" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::getXYZ","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXYZ());
;
}
CATE(TE,UFOF("Int3::getXYZ.")));
R CN;
}

SV Int3___less__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::__less__" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::__less__","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
auto v=val_to_c<const T3<int32_t> &>::f(ctx,a[1]);
R CV(*F < v);
}
CATE(TE,UFOF("Int3::__less__.")));
R CN;
}

SV Int3___neq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::__neq__" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::__neq__","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
auto v=val_to_c<const T3<int32_t> &>::f(ctx,a[1]);
R CV(*F != v);
}
CATE(TE,UFOF("Int3::__neq__.")));
R CN;
}

SV Int3_getYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::getYZ" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::getYZ","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYZ());
;
}
CATE(TE,UFOF("Int3::getYZ.")));
R CN;
}

SV Int3_lengthSquared(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::lengthSquared" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::lengthSquared","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->lengthSquared());
;
}
CATE(TE,UFOF("Int3::lengthSquared.")));
R CN;
}

SV Int3_getZYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::getZYX" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::getZYX","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZYX());
;
}
CATE(TE,UFOF("Int3::getZYX.")));
R CN;
}

SV Int3___div__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::__div__" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::__div__","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
auto v=val_to_c<const T3<int32_t> &>::f(ctx,a[1]);
R CV(*F / v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const int32_t&))
{
auto v=val_to_c<const int32_t&>::f(ctx,a[1]);
R CV(*F / v);
}
CATE(TE,UFOF("Int3::__div__.")));
R CN;
}

SV Int3_setZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::setZY" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::setZY","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
( F->setZY(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int3::setZY.")));
R CN;
}

SV Int3_setZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::setZX" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::setZX","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
( F->setZX(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int3::setZX.")));
R CN;
}

SV Int3_setXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::setXY" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::setXY","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
( F->setXY(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int3::setXY.")));
R CN;
}

SV Int3___add__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::__add__" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::__add__","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
auto v=val_to_c<const T3<int32_t> &>::f(ctx,a[1]);
R CV(*F + v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const int32_t&))
{
auto v=val_to_c<const int32_t&>::f(ctx,a[1]);
R CV(*F + v);
}
CATE(TE,UFOF("Int3::__add__.")));
R CN;
}

SV Int3_setXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::setXZ" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::setXZ","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
( F->setXZ(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int3::setXZ.")));
R CN;
}

SV Int3___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::__eq__" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::__eq__","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
auto v=val_to_c<const T3<int32_t> &>::f(ctx,a[1]);
R CV(*F == v);
}
CATE(TE,UFOF("Int3::__eq__.")));
R CN;
}

SV Int3_setZXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::setZXY" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::setZXY","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setZXY(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int3::setZXY.")));
R CN;
}

SV Int3_setYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::setYXZ" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::setYXZ","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setYXZ(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int3::setYXZ.")));
R CN;
}

SV Int3_getXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::getXY" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::getXY","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXY());
;
}
CATE(TE,UFOF("Int3::getXY.")));
R CN;
}

SV Int3_distance(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::distance" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::distance","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
R CV( F->distance(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Int3::distance.")));
R CN;
}

SV Int3_getXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::getXZ" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::getXZ","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXZ());
;
}
CATE(TE,UFOF("Int3::getXZ.")));
R CN;
}

SV Int3___grtr__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::__grtr__" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::__grtr__","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
auto v=val_to_c<const T3<int32_t> &>::f(ctx,a[1]);
R CV(*F > v);
}
CATE(TE,UFOF("Int3::__grtr__.")));
R CN;
}

SV Int3_getXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::getXZY" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::getXZY","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXZY());
;
}
CATE(TE,UFOF("Int3::getXZY.")));
R CN;
}

SV Int3_setXYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::setXYZ" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::setXYZ","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setXYZ(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int3::setXYZ.")));
R CN;
}

SV Int3_getYZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::getYZX" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::getYZX","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYZX());
;
}
CATE(TE,UFOF("Int3::getYZX.")));
R CN;
}

SV Int3_length(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::length" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::length","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->length());
;
}
CATE(TE,UFOF("Int3::length.")));
R CN;
}

SV Int3___mul__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::__mul__" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::__mul__","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
auto v=val_to_c<const T3<int32_t> &>::f(ctx,a[1]);
R CV(*F * v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const int32_t&))
{
auto v=val_to_c<const int32_t&>::f(ctx,a[1]);
R CV(*F * v);
}
CATE(TE,UFOF("Int3::__mul__.")));
R CN;
}

SV Int3_getYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::getYXZ" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::getYXZ","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYXZ());
;
}
CATE(TE,UFOF("Int3::getYXZ.")));
R CN;
}

SV Int3_getZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::getZX" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::getZX","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZX());
;
}
CATE(TE,UFOF("Int3::getZX.")));
R CN;
}

SV Int3___sub__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::__sub__" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::__sub__","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
auto v=val_to_c<const T3<int32_t> &>::f(ctx,a[1]);
R CV(*F - v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const int32_t&))
{
auto v=val_to_c<const int32_t&>::f(ctx,a[1]);
R CV(*F - v);
}
CATE(TE,UFOF("Int3::__sub__.")));
R CN;
}

SV Int3___geq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::__geq__" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::__geq__","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
auto v=val_to_c<const T3<int32_t> &>::f(ctx,a[1]);
R CV(*F >= v);
}
CATE(TE,UFOF("Int3::__geq__.")));
R CN;
}

SV Int3_dot(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::dot" EAOE));
T3<int32_t>*F;
if(!TS(a[0],T3<int32_t>))
CATE(TE,FAE("Int3::dot","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
R CV( F->dot(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
;
}
if(a.getCount()==1)
if(1)
{
R CV( F->dot());
;
}
CATE(TE,UFOF("Int3::dot.")));
R CN;
}

void ResizableData_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,ResizableData))
CATE(TE,"ResizableData::__del__ expects ResizableData as first argument."));

DELETE((ResizableData*)F->data);
}SV ResizableData_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData's constructor" EAOE));
if(!TS(a[0],ResizableData))
CATE(TE,"ResizableData's constructor expects ResizableData as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(ResizableData_funcs,NEW(ResizableData),EXT->ResizableData_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],std::size_t))
R S::createNativeObject(ResizableData_funcs,NEW(ResizableData,val_to_c<std::size_t>::f(ctx,a[1])),EXT->ResizableData_typeID);
CATE(TE,UFOF("ResizableData's constructor.")));
R CN;
}

SV ResizableData_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("ResizableData");
EI(keyStr=="__new__")
R CNF(ResizableData_new);
EI(keyStr=="__call__")
R CNF(ResizableData_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(ResizableData_new);
 EI(keyStr == "__eq__")
R CNF(ResizableData___eq__);
 EI(keyStr == "__neq__")
R CNF(ResizableData___neq__);
 EI(keyStr == "getData")
R CNF(ResizableData_getData);
 EI(keyStr == "getSize")
R CNF(ResizableData_getSize);
 EI(keyStr == "resize")
R CNF(ResizableData_resize);
 EI(keyStr == "insert")
R CNF(ResizableData_insert);
 EI(keyStr == "append")
R CNF(ResizableData_append);
 EI(keyStr == "remove")
R CNF(ResizableData_remove);
 EI(keyStr == "clear")
R CNF(ResizableData_clear);
 EI(keyStr == "copy")
R CNF(ResizableData_copy);
 EI(keyStr == "getUInt8")
R CNF(ResizableData_getUInt8);
 EI(keyStr == "getInt8")
R CNF(ResizableData_getInt8);
 EI(keyStr == "getUInt16")
R CNF(ResizableData_getUInt16);
 EI(keyStr == "getInt16")
R CNF(ResizableData_getInt16);
 EI(keyStr == "getUInt32")
R CNF(ResizableData_getUInt32);
 EI(keyStr == "getInt32")
R CNF(ResizableData_getInt32);
 EI(keyStr == "getUInt64")
R CNF(ResizableData_getUInt64);
 EI(keyStr == "getInt64")
R CNF(ResizableData_getInt64);
 EI(keyStr == "getUInt16LE")
R CNF(ResizableData_getUInt16LE);
 EI(keyStr == "getInt16LE")
R CNF(ResizableData_getInt16LE);
 EI(keyStr == "getUInt32LE")
R CNF(ResizableData_getUInt32LE);
 EI(keyStr == "getInt32LE")
R CNF(ResizableData_getInt32LE);
 EI(keyStr == "getUInt64LE")
R CNF(ResizableData_getUInt64LE);
 EI(keyStr == "getInt64LE")
R CNF(ResizableData_getInt64LE);
 EI(keyStr == "getUInt16BE")
R CNF(ResizableData_getUInt16BE);
 EI(keyStr == "getInt16BE")
R CNF(ResizableData_getInt16BE);
 EI(keyStr == "getUInt32BE")
R CNF(ResizableData_getUInt32BE);
 EI(keyStr == "getInt32BE")
R CNF(ResizableData_getInt32BE);
 EI(keyStr == "getUInt64BE")
R CNF(ResizableData_getUInt64BE);
 EI(keyStr == "getInt64BE")
R CNF(ResizableData_getInt64BE);
 EI(keyStr == "setUInt8")
R CNF(ResizableData_setUInt8);
 EI(keyStr == "setInt8")
R CNF(ResizableData_setInt8);
 EI(keyStr == "setUInt16")
R CNF(ResizableData_setUInt16);
 EI(keyStr == "setInt16")
R CNF(ResizableData_setInt16);
 EI(keyStr == "setUInt32")
R CNF(ResizableData_setUInt32);
 EI(keyStr == "setInt32")
R CNF(ResizableData_setInt32);
 EI(keyStr == "setUInt64")
R CNF(ResizableData_setUInt64);
 EI(keyStr == "setInt64")
R CNF(ResizableData_setInt64);
 EI(keyStr == "setUInt16LE")
R CNF(ResizableData_setUInt16LE);
 EI(keyStr == "setInt16LE")
R CNF(ResizableData_setInt16LE);
 EI(keyStr == "setUInt32LE")
R CNF(ResizableData_setUInt32LE);
 EI(keyStr == "setInt32LE")
R CNF(ResizableData_setInt32LE);
 EI(keyStr == "setUInt64LE")
R CNF(ResizableData_setUInt64LE);
 EI(keyStr == "setInt64LE")
R CNF(ResizableData_setInt64LE);
 EI(keyStr == "setUInt16BE")
R CNF(ResizableData_setUInt16BE);
 EI(keyStr == "setInt16BE")
R CNF(ResizableData_setInt16BE);
 EI(keyStr == "setUInt32BE")
R CNF(ResizableData_setUInt32BE);
 EI(keyStr == "setInt32BE")
R CNF(ResizableData_setInt32BE);
 EI(keyStr == "setUInt64BE")
R CNF(ResizableData_setUInt64BE);
 EI(keyStr == "setInt64BE")
R CNF(ResizableData_setInt64BE);
 EI(keyStr == "getChar")
R CNF(ResizableData_getChar);
 EI(keyStr == "setChar")
R CNF(ResizableData_setChar);
 else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void ResizableData_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV ResizableData_getInt64BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getInt64BE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getInt64BE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getInt64BE(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("ResizableData::getInt64BE.")));
R CN;
}

SV ResizableData_setUInt8(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::setUInt8" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::setUInt8","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],uint8_t))
{
( F->setUInt8(val_to_c<size_t>::f(ctx,a[1]), val_to_c<uint8_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::setUInt8.")));
R CN;
}

SV ResizableData_getUInt64BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getUInt64BE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getUInt64BE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getUInt64BE(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("ResizableData::getUInt64BE.")));
R CN;
}

SV ResizableData_getUInt16BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getUInt16BE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getUInt16BE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getUInt16BE(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("ResizableData::getUInt16BE.")));
R CN;
}

SV ResizableData_getUInt16LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getUInt16LE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getUInt16LE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getUInt16LE(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("ResizableData::getUInt16LE.")));
R CN;
}

SV ResizableData_getSize(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getSize" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getSize","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getSize());
;
}
CATE(TE,UFOF("ResizableData::getSize.")));
R CN;
}

SV ResizableData_setUInt16BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::setUInt16BE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::setUInt16BE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],uint16_t))
{
( F->setUInt16BE(val_to_c<size_t>::f(ctx,a[1]), val_to_c<uint16_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::setUInt16BE.")));
R CN;
}

SV ResizableData_getUInt8(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getUInt8" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getUInt8","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getUInt8(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("ResizableData::getUInt8.")));
R CN;
}

SV ResizableData_setInt16(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::setInt16" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::setInt16","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],int16_t))
{
( F->setInt16(val_to_c<size_t>::f(ctx,a[1]), val_to_c<int16_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::setInt16.")));
R CN;
}

SV ResizableData_setInt64(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::setInt64" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::setInt64","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],int64_t))
{
( F->setInt64(val_to_c<size_t>::f(ctx,a[1]), val_to_c<int64_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::setInt64.")));
R CN;
}

SV ResizableData_getInt16LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getInt16LE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getInt16LE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getInt16LE(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("ResizableData::getInt16LE.")));
R CN;
}

SV ResizableData_append(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::append" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::append","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const ResizableData &))
{
( F->append(val_to_c<const ResizableData &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("ResizableData::append.")));
R CN;
}

SV ResizableData___neq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::__neq__" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::__neq__","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const ResizableData &))
{
auto v=val_to_c<const ResizableData &>::f(ctx,a[1]);
R CV(*F != v);
}
CATE(TE,UFOF("ResizableData::__neq__.")));
R CN;
}

SV ResizableData_getInt64(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getInt64" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getInt64","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getInt64(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("ResizableData::getInt64.")));
R CN;
}

SV ResizableData_setInt64BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::setInt64BE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::setInt64BE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],int64_t))
{
( F->setInt64BE(val_to_c<size_t>::f(ctx,a[1]), val_to_c<int64_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::setInt64BE.")));
R CN;
}

SV ResizableData_setInt32(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::setInt32" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::setInt32","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],int32_t))
{
( F->setInt32(val_to_c<size_t>::f(ctx,a[1]), val_to_c<int32_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::setInt32.")));
R CN;
}

SV ResizableData_getInt64LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getInt64LE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getInt64LE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getInt64LE(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("ResizableData::getInt64LE.")));
R CN;
}

SV ResizableData_setInt32LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::setInt32LE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::setInt32LE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],int32_t))
{
( F->setInt32LE(val_to_c<size_t>::f(ctx,a[1]), val_to_c<int32_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::setInt32LE.")));
R CN;
}

SV ResizableData_setUInt32(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::setUInt32" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::setUInt32","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],uint32_t))
{
( F->setUInt32(val_to_c<size_t>::f(ctx,a[1]), val_to_c<uint32_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::setUInt32.")));
R CN;
}

SV ResizableData_setChar(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::setChar" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::setChar","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],char))
{
( F->setChar(val_to_c<size_t>::f(ctx,a[1]), val_to_c<char>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::setChar.")));
R CN;
}

SV ResizableData_setUInt64LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::setUInt64LE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::setUInt64LE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],uint64_t))
{
( F->setUInt64LE(val_to_c<size_t>::f(ctx,a[1]), val_to_c<uint64_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::setUInt64LE.")));
R CN;
}

SV ResizableData_setUInt64BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::setUInt64BE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::setUInt64BE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],uint64_t))
{
( F->setUInt64BE(val_to_c<size_t>::f(ctx,a[1]), val_to_c<uint64_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::setUInt64BE.")));
R CN;
}

SV ResizableData_setUInt16LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::setUInt16LE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::setUInt16LE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],uint16_t))
{
( F->setUInt16LE(val_to_c<size_t>::f(ctx,a[1]), val_to_c<uint16_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::setUInt16LE.")));
R CN;
}

SV ResizableData_setUInt32LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::setUInt32LE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::setUInt32LE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],uint32_t))
{
( F->setUInt32LE(val_to_c<size_t>::f(ctx,a[1]), val_to_c<uint32_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::setUInt32LE.")));
R CN;
}

SV ResizableData_getData(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getData" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getData","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

CATE(TE,UFOF("ResizableData::getData.")));
R CN;
}

SV ResizableData_setUInt16(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::setUInt16" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::setUInt16","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],uint16_t))
{
( F->setUInt16(val_to_c<size_t>::f(ctx,a[1]), val_to_c<uint16_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::setUInt16.")));
R CN;
}

SV ResizableData_getUInt32(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getUInt32" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getUInt32","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getUInt32(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("ResizableData::getUInt32.")));
R CN;
}

SV ResizableData_setInt16LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::setInt16LE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::setInt16LE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],int16_t))
{
( F->setInt16LE(val_to_c<size_t>::f(ctx,a[1]), val_to_c<int16_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::setInt16LE.")));
R CN;
}

SV ResizableData_getUInt16(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getUInt16" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getUInt16","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getUInt16(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("ResizableData::getUInt16.")));
R CN;
}

SV ResizableData_getUInt64(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getUInt64" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getUInt64","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getUInt64(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("ResizableData::getUInt64.")));
R CN;
}

SV ResizableData_setInt32BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::setInt32BE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::setInt32BE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],int32_t))
{
( F->setInt32BE(val_to_c<size_t>::f(ctx,a[1]), val_to_c<int32_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::setInt32BE.")));
R CN;
}

SV ResizableData_getUInt64LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getUInt64LE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getUInt64LE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getUInt64LE(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("ResizableData::getUInt64LE.")));
R CN;
}

SV ResizableData_getUInt32BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getUInt32BE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getUInt32BE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getUInt32BE(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("ResizableData::getUInt32BE.")));
R CN;
}

SV ResizableData_getInt32(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getInt32" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getInt32","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getInt32(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("ResizableData::getInt32.")));
R CN;
}

SV ResizableData_getInt32BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getInt32BE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getInt32BE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getInt32BE(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("ResizableData::getInt32BE.")));
R CN;
}

SV ResizableData_copy(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::copy" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::copy","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->copy());
;
}
CATE(TE,UFOF("ResizableData::copy.")));
R CN;
}

SV ResizableData___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::__eq__" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::__eq__","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const ResizableData &))
{
auto v=val_to_c<const ResizableData &>::f(ctx,a[1]);
R CV(*F == v);
}
CATE(TE,UFOF("ResizableData::__eq__.")));
R CN;
}

SV ResizableData_resize(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::resize" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::resize","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],std::size_t))
{
( F->resize(val_to_c<std::size_t>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("ResizableData::resize.")));
R CN;
}

SV ResizableData_setInt16BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::setInt16BE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::setInt16BE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],int16_t))
{
( F->setInt16BE(val_to_c<size_t>::f(ctx,a[1]), val_to_c<int16_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::setInt16BE.")));
R CN;
}

SV ResizableData_insert(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::insert" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::insert","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],std::size_t)&&TS(a[2],const ResizableData &))
{
( F->insert(val_to_c<std::size_t>::f(ctx,a[1]), val_to_c<const ResizableData &>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::insert.")));
R CN;
}

SV ResizableData_getInt16(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getInt16" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getInt16","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getInt16(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("ResizableData::getInt16.")));
R CN;
}

SV ResizableData_getInt16BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getInt16BE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getInt16BE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getInt16BE(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("ResizableData::getInt16BE.")));
R CN;
}

SV ResizableData_setUInt32BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::setUInt32BE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::setUInt32BE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],uint32_t))
{
( F->setUInt32BE(val_to_c<size_t>::f(ctx,a[1]), val_to_c<uint32_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::setUInt32BE.")));
R CN;
}

SV ResizableData_clear(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::clear" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::clear","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->clear());
R CN;
}
CATE(TE,UFOF("ResizableData::clear.")));
R CN;
}

SV ResizableData_remove(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::remove" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::remove","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],std::size_t)&&TS(a[2],std::size_t))
{
( F->remove(val_to_c<std::size_t>::f(ctx,a[1]), val_to_c<std::size_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::remove.")));
R CN;
}

SV ResizableData_setUInt64(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::setUInt64" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::setUInt64","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],uint64_t))
{
( F->setUInt64(val_to_c<size_t>::f(ctx,a[1]), val_to_c<uint64_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::setUInt64.")));
R CN;
}

SV ResizableData_setInt64LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::setInt64LE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::setInt64LE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],int64_t))
{
( F->setInt64LE(val_to_c<size_t>::f(ctx,a[1]), val_to_c<int64_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::setInt64LE.")));
R CN;
}

SV ResizableData_setInt8(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::setInt8" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::setInt8","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],int8_t))
{
( F->setInt8(val_to_c<size_t>::f(ctx,a[1]), val_to_c<int8_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("ResizableData::setInt8.")));
R CN;
}

SV ResizableData_getUInt32LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getUInt32LE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getUInt32LE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getUInt32LE(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("ResizableData::getUInt32LE.")));
R CN;
}

SV ResizableData_getInt8(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getInt8" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getInt8","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getInt8(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("ResizableData::getInt8.")));
R CN;
}

SV ResizableData_getInt32LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getInt32LE" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getInt32LE","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getInt32LE(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("ResizableData::getInt32LE.")));
R CN;
}

SV ResizableData_getChar(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"ResizableData::getChar" EAOE));
ResizableData*F;
if(!TS(a[0],ResizableData))
CATE(TE,FAE("ResizableData::getChar","ResizableData")));
else
 F=(ResizableData*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getChar(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("ResizableData::getChar.")));
R CN;
}

void Int4_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,T4<int32_t>))
CATE(TE,"Int4::__del__ expects Int4 as first argument."));

DELETE((T4<int32_t>*)F->data);
}SV Int4_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4's constructor" EAOE));
if(!TS(a[0],T4<int32_t>))
CATE(TE,"Int4's constructor expects Int4 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Int4_funcs,NEW(T4<int32_t>),EXT->Int4_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],int32_t))
R S::createNativeObject(Int4_funcs,NEW(T4<int32_t>,val_to_c<int32_t>::f(ctx,a[1])),EXT->Int4_typeID);
if(a.getCount()==5)
if(true&&TS(a[1],int32_t)&&TS(a[2],int32_t)&&TS(a[3],int32_t)&&TS(a[4],int32_t))
R S::createNativeObject(Int4_funcs,NEW(T4<int32_t>,val_to_c<int32_t>::f(ctx,a[1]),val_to_c<int32_t>::f(ctx,a[2]),val_to_c<int32_t>::f(ctx,a[3]),val_to_c<int32_t>::f(ctx,a[4])),EXT->Int4_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T4<float> &))
R S::createNativeObject(Int4_funcs,NEW(T4<int32_t>,val_to_c<const T4<float> &>::f(ctx,a[1])),EXT->Int4_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T4<int32_t> &))
R S::createNativeObject(Int4_funcs,NEW(T4<int32_t>,val_to_c<const T4<int32_t> &>::f(ctx,a[1])),EXT->Int4_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T4<uint32_t> &))
R S::createNativeObject(Int4_funcs,NEW(T4<int32_t>,val_to_c<const T4<uint32_t> &>::f(ctx,a[1])),EXT->Int4_typeID);
CATE(TE,UFOF("Int4's constructor.")));
R CN;
}

SV Int4_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Int4");
EI(keyStr=="__new__")
R CNF(Int4_new);
EI(keyStr=="__call__")
R CNF(Int4_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(Int4_new);
 EI(keyStr == "__add__")
R CNF(Int4___add__);
 EI(keyStr == "__sub__")
R CNF(Int4___sub__);
 EI(keyStr == "__mul__")
R CNF(Int4___mul__);
 EI(keyStr == "__div__")
R CNF(Int4___div__);
 EI(keyStr == "__eq__")
R CNF(Int4___eq__);
 EI(keyStr == "__neq__")
R CNF(Int4___neq__);
 EI(keyStr == "__less__")
R CNF(Int4___less__);
 EI(keyStr == "__grtr__")
R CNF(Int4___grtr__);
 EI(keyStr == "__leq__")
R CNF(Int4___leq__);
 EI(keyStr == "__geq__")
R CNF(Int4___geq__);
 EI(keyStr == "sum")
R CNF(Int4_sum);
 EI(keyStr == "length")
R CNF(Int4_length);
 EI(keyStr == "lengthSquared")
R CNF(Int4_lengthSquared);
 EI(keyStr == "dot")
R CNF(Int4_dot);
 EI(keyStr == "distance")
R CNF(Int4_distance);
 EI(keyStr == "distanceSquared")
R CNF(Int4_distanceSquared);
 EI(keyStr == "normalize")
R CNF(Int4_normalize);
 EI(keyStr == "getXY")
R CNF(Int4_getXY);
 EI(keyStr == "setXY")
R CNF(Int4_setXY);
 EI(keyStr == "getXZ")
R CNF(Int4_getXZ);
 EI(keyStr == "setXZ")
R CNF(Int4_setXZ);
 EI(keyStr == "getXW")
R CNF(Int4_getXW);
 EI(keyStr == "setXW")
R CNF(Int4_setXW);
 EI(keyStr == "getYX")
R CNF(Int4_getYX);
 EI(keyStr == "setYX")
R CNF(Int4_setYX);
 EI(keyStr == "getYZ")
R CNF(Int4_getYZ);
 EI(keyStr == "setYZ")
R CNF(Int4_setYZ);
 EI(keyStr == "getYW")
R CNF(Int4_getYW);
 EI(keyStr == "setYW")
R CNF(Int4_setYW);
 EI(keyStr == "getZX")
R CNF(Int4_getZX);
 EI(keyStr == "setZX")
R CNF(Int4_setZX);
 EI(keyStr == "getZY")
R CNF(Int4_getZY);
 EI(keyStr == "setZY")
R CNF(Int4_setZY);
 EI(keyStr == "getZW")
R CNF(Int4_getZW);
 EI(keyStr == "setZW")
R CNF(Int4_setZW);
 EI(keyStr == "getWX")
R CNF(Int4_getWX);
 EI(keyStr == "setWX")
R CNF(Int4_setWX);
 EI(keyStr == "getWY")
R CNF(Int4_getWY);
 EI(keyStr == "setWY")
R CNF(Int4_setWY);
 EI(keyStr == "getWZ")
R CNF(Int4_getWZ);
 EI(keyStr == "setWZ")
R CNF(Int4_setWZ);
 EI(keyStr == "getXYZ")
R CNF(Int4_getXYZ);
 EI(keyStr == "setXYZ")
R CNF(Int4_setXYZ);
 EI(keyStr == "getXYW")
R CNF(Int4_getXYW);
 EI(keyStr == "setXYW")
R CNF(Int4_setXYW);
 EI(keyStr == "getXZY")
R CNF(Int4_getXZY);
 EI(keyStr == "setXZY")
R CNF(Int4_setXZY);
 EI(keyStr == "getXZW")
R CNF(Int4_getXZW);
 EI(keyStr == "setXZW")
R CNF(Int4_setXZW);
 EI(keyStr == "getXWZ")
R CNF(Int4_getXWZ);
 EI(keyStr == "setXWZ")
R CNF(Int4_setXWZ);
 EI(keyStr == "getXWY")
R CNF(Int4_getXWY);
 EI(keyStr == "setXWY")
R CNF(Int4_setXWY);
 EI(keyStr == "getYXZ")
R CNF(Int4_getYXZ);
 EI(keyStr == "setYXZ")
R CNF(Int4_setYXZ);
 EI(keyStr == "getYXW")
R CNF(Int4_getYXW);
 EI(keyStr == "setYXW")
R CNF(Int4_setYXW);
 EI(keyStr == "getYZX")
R CNF(Int4_getYZX);
 EI(keyStr == "setYZX")
R CNF(Int4_setYZX);
 EI(keyStr == "getYZW")
R CNF(Int4_getYZW);
 EI(keyStr == "setYZW")
R CNF(Int4_setYZW);
 EI(keyStr == "getYWZ")
R CNF(Int4_getYWZ);
 EI(keyStr == "setYWZ")
R CNF(Int4_setYWZ);
 EI(keyStr == "getYWX")
R CNF(Int4_getYWX);
 EI(keyStr == "setYWX")
R CNF(Int4_setYWX);
 EI(keyStr == "getZXY")
R CNF(Int4_getZXY);
 EI(keyStr == "setZXY")
R CNF(Int4_setZXY);
 EI(keyStr == "getZXW")
R CNF(Int4_getZXW);
 EI(keyStr == "setZXW")
R CNF(Int4_setZXW);
 EI(keyStr == "getZYX")
R CNF(Int4_getZYX);
 EI(keyStr == "setZYX")
R CNF(Int4_setZYX);
 EI(keyStr == "getZYW")
R CNF(Int4_getZYW);
 EI(keyStr == "setZYW")
R CNF(Int4_setZYW);
 EI(keyStr == "getZWY")
R CNF(Int4_getZWY);
 EI(keyStr == "setZWY")
R CNF(Int4_setZWY);
 EI(keyStr == "getZWX")
R CNF(Int4_getZWX);
 EI(keyStr == "setZWX")
R CNF(Int4_setZWX);
 EI(keyStr == "getWXY")
R CNF(Int4_getWXY);
 EI(keyStr == "setWXY")
R CNF(Int4_setWXY);
 EI(keyStr == "getWXZ")
R CNF(Int4_getWXZ);
 EI(keyStr == "setWXZ")
R CNF(Int4_setWXZ);
 EI(keyStr == "getWYX")
R CNF(Int4_getWYX);
 EI(keyStr == "setWYX")
R CNF(Int4_setWYX);
 EI(keyStr == "getWYZ")
R CNF(Int4_getWYZ);
 EI(keyStr == "setWYZ")
R CNF(Int4_setWYZ);
 EI(keyStr == "getWZY")
R CNF(Int4_getWZY);
 EI(keyStr == "setWZY")
R CNF(Int4_setWZY);
 EI(keyStr == "getWZX")
R CNF(Int4_getWZX);
 EI(keyStr == "setWZX")
R CNF(Int4_setWZX);
 EI(keyStr == "getXYZW")
R CNF(Int4_getXYZW);
 EI(keyStr == "setXYZW")
R CNF(Int4_setXYZW);
 EI(keyStr == "getXYWZ")
R CNF(Int4_getXYWZ);
 EI(keyStr == "setXYWZ")
R CNF(Int4_setXYWZ);
 EI(keyStr == "getXZYW")
R CNF(Int4_getXZYW);
 EI(keyStr == "setXZYW")
R CNF(Int4_setXZYW);
 EI(keyStr == "getXZWY")
R CNF(Int4_getXZWY);
 EI(keyStr == "setXZWY")
R CNF(Int4_setXZWY);
 EI(keyStr == "getXWZY")
R CNF(Int4_getXWZY);
 EI(keyStr == "setXWZY")
R CNF(Int4_setXWZY);
 EI(keyStr == "getXWYZ")
R CNF(Int4_getXWYZ);
 EI(keyStr == "setXWYZ")
R CNF(Int4_setXWYZ);
 EI(keyStr == "getYXZW")
R CNF(Int4_getYXZW);
 EI(keyStr == "setYXZW")
R CNF(Int4_setYXZW);
 EI(keyStr == "getYXWZ")
R CNF(Int4_getYXWZ);
 EI(keyStr == "setYXWZ")
R CNF(Int4_setYXWZ);
 EI(keyStr == "getYZXW")
R CNF(Int4_getYZXW);
 EI(keyStr == "setYZXW")
R CNF(Int4_setYZXW);
 EI(keyStr == "getYZWX")
R CNF(Int4_getYZWX);
 EI(keyStr == "setYZWX")
R CNF(Int4_setYZWX);
 EI(keyStr == "getYWZX")
R CNF(Int4_getYWZX);
 EI(keyStr == "setYWZX")
R CNF(Int4_setYWZX);
 EI(keyStr == "getYWXZ")
R CNF(Int4_getYWXZ);
 EI(keyStr == "setYWXZ")
R CNF(Int4_setYWXZ);
 EI(keyStr == "getZYXW")
R CNF(Int4_getZYXW);
 EI(keyStr == "setZYXW")
R CNF(Int4_setZYXW);
 EI(keyStr == "getZYWX")
R CNF(Int4_getZYWX);
 EI(keyStr == "setZYWX")
R CNF(Int4_setZYWX);
 EI(keyStr == "getZXYW")
R CNF(Int4_getZXYW);
 EI(keyStr == "setZXYW")
R CNF(Int4_setZXYW);
 EI(keyStr == "getZXWY")
R CNF(Int4_getZXWY);
 EI(keyStr == "setZXWY")
R CNF(Int4_setZXWY);
 EI(keyStr == "getZWXY")
R CNF(Int4_getZWXY);
 EI(keyStr == "setZWXY")
R CNF(Int4_setZWXY);
 EI(keyStr == "getZWYX")
R CNF(Int4_getZWYX);
 EI(keyStr == "setZWYX")
R CNF(Int4_setZWYX);
 EI(keyStr == "getWYZX")
R CNF(Int4_getWYZX);
 EI(keyStr == "setWYZX")
R CNF(Int4_setWYZX);
 EI(keyStr == "getWYXZ")
R CNF(Int4_getWYXZ);
 EI(keyStr == "setWYXZ")
R CNF(Int4_setWYXZ);
 EI(keyStr == "getWZYX")
R CNF(Int4_getWZYX);
 EI(keyStr == "setWZYX")
R CNF(Int4_setWZYX);
 EI(keyStr == "getWZXY")
R CNF(Int4_getWZXY);
 EI(keyStr == "setWZXY")
R CNF(Int4_setWZXY);
 EI(keyStr == "getWXZY")
R CNF(Int4_getWXZY);
 EI(keyStr == "setWXZY")
R CNF(Int4_setWXZY);
 EI(keyStr == "getWXYZ")
R CNF(Int4_getWXYZ);
 EI(keyStr == "setWXYZ")
R CNF(Int4_setWXYZ);
 EI(keyStr=="x")
{
T4<int32_t>*obj=(T4<int32_t>*)F->data;
R CV(obj->x);
} EI(keyStr=="y")
{
T4<int32_t>*obj=(T4<int32_t>*)F->data;
R CV(obj->y);
} EI(keyStr=="z")
{
T4<int32_t>*obj=(T4<int32_t>*)F->data;
R CV(obj->z);
} EI(keyStr=="w")
{
T4<int32_t>*obj=(T4<int32_t>*)F->data;
R CV(obj->w);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void Int4_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="x")
{
T4<int32_t>*obj=(T4<int32_t>*)F->data;
obj->x=val_to_c<decltype(obj->x)>::f(ctx,value);
} EI(keyStr=="y")
{
T4<int32_t>*obj=(T4<int32_t>*)F->data;
obj->y=val_to_c<decltype(obj->y)>::f(ctx,value);
} EI(keyStr=="z")
{
T4<int32_t>*obj=(T4<int32_t>*)F->data;
obj->z=val_to_c<decltype(obj->z)>::f(ctx,value);
} EI(keyStr=="w")
{
T4<int32_t>*obj=(T4<int32_t>*)F->data;
obj->w=val_to_c<decltype(obj->w)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV Int4_setZXYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setZXYW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setZXYW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setZXYW(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setZXYW.")));
R CN;
}

SV Int4_setWYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setWYZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setWYZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setWYZ(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setWYZ.")));
R CN;
}

SV Int4_setWYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setWYX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setWYX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setWYX(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setWYX.")));
R CN;
}

SV Int4_getZWYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getZWYX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getZWYX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZWYX());
;
}
CATE(TE,UFOF("Int4::getZWYX.")));
R CN;
}

SV Int4_getZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getZW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getZW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZW());
;
}
CATE(TE,UFOF("Int4::getZW.")));
R CN;
}

SV Int4_getZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getZY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getZY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZY());
;
}
CATE(TE,UFOF("Int4::getZY.")));
R CN;
}

SV Int4_distanceSquared(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::distanceSquared" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::distanceSquared","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
R CV( F->distanceSquared(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Int4::distanceSquared.")));
R CN;
}

SV Int4_getYXZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getYXZW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getYXZW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYXZW());
;
}
CATE(TE,UFOF("Int4::getYXZW.")));
R CN;
}

SV Int4_setYZWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setYZWX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setYZWX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setYZWX(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setYZWX.")));
R CN;
}

SV Int4_getYWZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getYWZX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getYWZX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYWZX());
;
}
CATE(TE,UFOF("Int4::getYWZX.")));
R CN;
}

SV Int4_getWZXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getWZXY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getWZXY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWZXY());
;
}
CATE(TE,UFOF("Int4::getWZXY.")));
R CN;
}

SV Int4_getZYXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getZYXW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getZYXW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZYXW());
;
}
CATE(TE,UFOF("Int4::getZYXW.")));
R CN;
}

SV Int4_setXWYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setXWYZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setXWYZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setXWYZ(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setXWYZ.")));
R CN;
}

SV Int4_setZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setZY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setZY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
( F->setZY(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setZY.")));
R CN;
}

SV Int4_setZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setZX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setZX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
( F->setZX(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setZX.")));
R CN;
}

SV Int4_getZXWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getZXWY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getZXWY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZXWY());
;
}
CATE(TE,UFOF("Int4::getZXWY.")));
R CN;
}

SV Int4_getXWZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getXWZY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getXWZY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXWZY());
;
}
CATE(TE,UFOF("Int4::getXWZY.")));
R CN;
}

SV Int4_setZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setZW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setZW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
( F->setZW(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setZW.")));
R CN;
}

SV Int4_setZYWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setZYWX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setZYWX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setZYWX(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setZYWX.")));
R CN;
}

SV Int4_getYZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getYZX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getYZX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYZX());
;
}
CATE(TE,UFOF("Int4::getYZX.")));
R CN;
}

SV Int4_getXYWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getXYWZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getXYWZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXYWZ());
;
}
CATE(TE,UFOF("Int4::getXYWZ.")));
R CN;
}

SV Int4_setYXZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setYXZW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setYXZW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setYXZW(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setYXZW.")));
R CN;
}

SV Int4_getWZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getWZY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getWZY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWZY());
;
}
CATE(TE,UFOF("Int4::getWZY.")));
R CN;
}

SV Int4_getWZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getWZX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getWZX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWZX());
;
}
CATE(TE,UFOF("Int4::getWZX.")));
R CN;
}

SV Int4_getWZYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getWZYX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getWZYX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWZYX());
;
}
CATE(TE,UFOF("Int4::getWZYX.")));
R CN;
}

SV Int4_setXWZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setXWZY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setXWZY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setXWZY(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setXWZY.")));
R CN;
}

SV Int4_getZXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getZXY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getZXY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZXY());
;
}
CATE(TE,UFOF("Int4::getZXY.")));
R CN;
}

SV Int4_setWZYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setWZYX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setWZYX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setWZYX(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setWZYX.")));
R CN;
}

SV Int4_setZYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setZYW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setZYW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setZYW(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setZYW.")));
R CN;
}

SV Int4_setZYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setZYX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setZYX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setZYX(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setZYX.")));
R CN;
}

SV Int4_setXZYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setXZYW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setXZYW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setXZYW(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setXZYW.")));
R CN;
}

SV Int4_getZXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getZXW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getZXW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZXW());
;
}
CATE(TE,UFOF("Int4::getZXW.")));
R CN;
}

SV Int4_setYZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setYZW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setYZW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setYZW(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setYZW.")));
R CN;
}

SV Int4_getYWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getYWZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getYWZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYWZ());
;
}
CATE(TE,UFOF("Int4::getYWZ.")));
R CN;
}

SV Int4___leq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::__leq__" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::__leq__","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
auto v=val_to_c<const T4<int32_t> &>::f(ctx,a[1]);
R CV(*F <= v);
}
CATE(TE,UFOF("Int4::__leq__.")));
R CN;
}

SV Int4_getYWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getYWX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getYWX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYWX());
;
}
CATE(TE,UFOF("Int4::getYWX.")));
R CN;
}

SV Int4_sum(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::sum" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::sum","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->sum());
;
}
CATE(TE,UFOF("Int4::sum.")));
R CN;
}

SV Int4_setYZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setYZX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setYZX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setYZX(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setYZX.")));
R CN;
}

SV Int4_getXYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getXYZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getXYZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXYZ());
;
}
CATE(TE,UFOF("Int4::getXYZ.")));
R CN;
}

SV Int4_getZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getZX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getZX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZX());
;
}
CATE(TE,UFOF("Int4::getZX.")));
R CN;
}

SV Int4_getXYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getXYW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getXYW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXYW());
;
}
CATE(TE,UFOF("Int4::getXYW.")));
R CN;
}

SV Int4_setYWZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setYWZX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setYWZX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setYWZX(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setYWZX.")));
R CN;
}

SV Int4_setWXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setWXY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setWXY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setWXY(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setWXY.")));
R CN;
}

SV Int4_setWXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setWXZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setWXZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setWXZ(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setWXZ.")));
R CN;
}

SV Int4_setZXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setZXW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setZXW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setZXW(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setZXW.")));
R CN;
}

SV Int4_getXWYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getXWYZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getXWYZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXWYZ());
;
}
CATE(TE,UFOF("Int4::getXWYZ.")));
R CN;
}

SV Int4_setWYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setWYXZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setWYXZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setWYXZ(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setWYXZ.")));
R CN;
}

SV Int4_setZXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setZXY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setZXY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setZXY(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setZXY.")));
R CN;
}

SV Int4_getXWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getXWY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getXWY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXWY());
;
}
CATE(TE,UFOF("Int4::getXWY.")));
R CN;
}

SV Int4_getYXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getYXW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getYXW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYXW());
;
}
CATE(TE,UFOF("Int4::getYXW.")));
R CN;
}

SV Int4_getYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getYXZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getYXZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYXZ());
;
}
CATE(TE,UFOF("Int4::getYXZ.")));
R CN;
}

SV Int4_setXYWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setXYWZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setXYWZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setXYWZ(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setXYWZ.")));
R CN;
}

SV Int4_length(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::length" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::length","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->length());
;
}
CATE(TE,UFOF("Int4::length.")));
R CN;
}

SV Int4_setWXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setWXZY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setWXZY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setWXZY(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setWXZY.")));
R CN;
}

SV Int4_getYZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getYZW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getYZW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYZW());
;
}
CATE(TE,UFOF("Int4::getYZW.")));
R CN;
}

SV Int4_setXWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setXWZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setXWZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setXWZ(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setXWZ.")));
R CN;
}

SV Int4_setXWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setXWY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setXWY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setXWY(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setXWY.")));
R CN;
}

SV Int4_getWYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getWYZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getWYZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWYZ());
;
}
CATE(TE,UFOF("Int4::getWYZ.")));
R CN;
}

SV Int4_getWYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getWYX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getWYX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWYX());
;
}
CATE(TE,UFOF("Int4::getWYX.")));
R CN;
}

SV Int4_getZYWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getZYWX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getZYWX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZYWX());
;
}
CATE(TE,UFOF("Int4::getZYWX.")));
R CN;
}

SV Int4_getXYZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getXYZW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getXYZW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXYZW());
;
}
CATE(TE,UFOF("Int4::getXYZW.")));
R CN;
}

SV Int4_setZWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setZWY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setZWY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setZWY(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setZWY.")));
R CN;
}

SV Int4_setZWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setZWX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setZWX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setZWX(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setZWX.")));
R CN;
}

SV Int4_setWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setWX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setWX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
( F->setWX(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setWX.")));
R CN;
}

SV Int4_setWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setWY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setWY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
( F->setWY(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setWY.")));
R CN;
}

SV Int4_setWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setWZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setWZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
( F->setWZ(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setWZ.")));
R CN;
}

SV Int4_getZWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getZWY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getZWY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZWY());
;
}
CATE(TE,UFOF("Int4::getZWY.")));
R CN;
}

SV Int4_getZWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getZWX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getZWX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZWX());
;
}
CATE(TE,UFOF("Int4::getZWX.")));
R CN;
}

SV Int4_setYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setYXZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setYXZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setYXZ(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setYXZ.")));
R CN;
}

SV Int4_setYXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setYXW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setYXW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setYXW(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setYXW.")));
R CN;
}

SV Int4_getXWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getXWZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getXWZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXWZ());
;
}
CATE(TE,UFOF("Int4::getXWZ.")));
R CN;
}

SV Int4_getXZWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getXZWY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getXZWY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXZWY());
;
}
CATE(TE,UFOF("Int4::getXZWY.")));
R CN;
}

SV Int4___less__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::__less__" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::__less__","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
auto v=val_to_c<const T4<int32_t> &>::f(ctx,a[1]);
R CV(*F < v);
}
CATE(TE,UFOF("Int4::__less__.")));
R CN;
}

SV Int4_getZYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getZYW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getZYW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZYW());
;
}
CATE(TE,UFOF("Int4::getZYW.")));
R CN;
}

SV Int4_setWZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setWZY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setWZY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setWZY(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setWZY.")));
R CN;
}

SV Int4_setWZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setWZX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setWZX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setWZX(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setWZX.")));
R CN;
}

SV Int4_setZYXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setZYXW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setZYXW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setZYXW(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setZYXW.")));
R CN;
}

SV Int4_getYZWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getYZWX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getYZWX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYZWX());
;
}
CATE(TE,UFOF("Int4::getYZWX.")));
R CN;
}

SV Int4_getZYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getZYX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getZYX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZYX());
;
}
CATE(TE,UFOF("Int4::getZYX.")));
R CN;
}

SV Int4_getXZYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getXZYW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getXZYW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXZYW());
;
}
CATE(TE,UFOF("Int4::getXZYW.")));
R CN;
}

SV Int4_setYXWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setYXWZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setYXWZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setYXWZ(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setYXWZ.")));
R CN;
}

SV Int4___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::__eq__" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::__eq__","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
auto v=val_to_c<const T4<int32_t> &>::f(ctx,a[1]);
R CV(*F == v);
}
CATE(TE,UFOF("Int4::__eq__.")));
R CN;
}

SV Int4_getWYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getWYXZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getWYXZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWYXZ());
;
}
CATE(TE,UFOF("Int4::getWYXZ.")));
R CN;
}

SV Int4_distance(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::distance" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::distance","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
R CV( F->distance(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Int4::distance.")));
R CN;
}

SV Int4_getXZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getXZW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getXZW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXZW());
;
}
CATE(TE,UFOF("Int4::getXZW.")));
R CN;
}

SV Int4_setYZXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setYZXW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setYZXW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setYZXW(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setYZXW.")));
R CN;
}

SV Int4_getZWXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getZWXY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getZWXY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZWXY());
;
}
CATE(TE,UFOF("Int4::getZWXY.")));
R CN;
}

SV Int4_getXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getXZY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getXZY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXZY());
;
}
CATE(TE,UFOF("Int4::getXZY.")));
R CN;
}

SV Int4_getYZXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getYZXW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getYZXW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYZXW());
;
}
CATE(TE,UFOF("Int4::getYZXW.")));
R CN;
}

SV Int4_setZWYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setZWYX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setZWYX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setZWYX(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setZWYX.")));
R CN;
}

SV Int4___sub__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::__sub__" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::__sub__","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
auto v=val_to_c<const T4<int32_t> &>::f(ctx,a[1]);
R CV(*F - v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const int32_t&))
{
auto v=val_to_c<const int32_t&>::f(ctx,a[1]);
R CV(*F - v);
}
CATE(TE,UFOF("Int4::__sub__.")));
R CN;
}

SV Int4_getYXWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getYXWZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getYXWZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYXWZ());
;
}
CATE(TE,UFOF("Int4::getYXWZ.")));
R CN;
}

SV Int4_setXZWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setXZWY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setXZWY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setXZWY(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setXZWY.")));
R CN;
}

SV Int4_setYWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setYWZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setYWZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setYWZ(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setYWZ.")));
R CN;
}

SV Int4_setYWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setYWX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setYWX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setYWX(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setYWX.")));
R CN;
}

SV Int4_setYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setYZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setYZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
( F->setYZ(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setYZ.")));
R CN;
}

SV Int4_setYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setYX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setYX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
( F->setYX(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setYX.")));
R CN;
}

SV Int4_setYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setYW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setYW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
( F->setYW(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setYW.")));
R CN;
}

SV Int4_getWXYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getWXYZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getWXYZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWXYZ());
;
}
CATE(TE,UFOF("Int4::getWXYZ.")));
R CN;
}

SV Int4___neq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::__neq__" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::__neq__","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
auto v=val_to_c<const T4<int32_t> &>::f(ctx,a[1]);
R CV(*F != v);
}
CATE(TE,UFOF("Int4::__neq__.")));
R CN;
}

SV Int4_normalize(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::normalize" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::normalize","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->normalize());
;
}
CATE(TE,UFOF("Int4::normalize.")));
R CN;
}

SV Int4_getYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getYX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getYX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYX());
;
}
CATE(TE,UFOF("Int4::getYX.")));
R CN;
}

SV Int4_setXZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setXZW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setXZW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setXZW(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setXZW.")));
R CN;
}

SV Int4_setXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setXZY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setXZY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setXZY(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setXZY.")));
R CN;
}

SV Int4_setXYZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setXYZW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setXYZW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setXYZW(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setXYZW.")));
R CN;
}

SV Int4_getYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getYW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getYW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYW());
;
}
CATE(TE,UFOF("Int4::getYW.")));
R CN;
}

SV Int4_setWXYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setWXYZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setWXYZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setWXYZ(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setWXYZ.")));
R CN;
}

SV Int4_getYWXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getYWXZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getYWXZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYWXZ());
;
}
CATE(TE,UFOF("Int4::getYWXZ.")));
R CN;
}

SV Int4___mul__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::__mul__" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::__mul__","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
auto v=val_to_c<const T4<int32_t> &>::f(ctx,a[1]);
R CV(*F * v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const int32_t&))
{
auto v=val_to_c<const int32_t&>::f(ctx,a[1]);
R CV(*F * v);
}
CATE(TE,UFOF("Int4::__mul__.")));
R CN;
}

SV Int4_getYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getYZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getYZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYZ());
;
}
CATE(TE,UFOF("Int4::getYZ.")));
R CN;
}

SV Int4_lengthSquared(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::lengthSquared" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::lengthSquared","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->lengthSquared());
;
}
CATE(TE,UFOF("Int4::lengthSquared.")));
R CN;
}

SV Int4_getWXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getWXY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getWXY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWXY());
;
}
CATE(TE,UFOF("Int4::getWXY.")));
R CN;
}

SV Int4_getWXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getWXZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getWXZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWXZ());
;
}
CATE(TE,UFOF("Int4::getWXZ.")));
R CN;
}

SV Int4_getWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getWX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getWX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWX());
;
}
CATE(TE,UFOF("Int4::getWX.")));
R CN;
}

SV Int4_getWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getWY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getWY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWY());
;
}
CATE(TE,UFOF("Int4::getWY.")));
R CN;
}

SV Int4_getWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getWZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getWZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWZ());
;
}
CATE(TE,UFOF("Int4::getWZ.")));
R CN;
}

SV Int4_setXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setXY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setXY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
( F->setXY(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setXY.")));
R CN;
}

SV Int4_getZXYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getZXYW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getZXYW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZXYW());
;
}
CATE(TE,UFOF("Int4::getZXYW.")));
R CN;
}

SV Int4___add__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::__add__" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::__add__","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
auto v=val_to_c<const T4<int32_t> &>::f(ctx,a[1]);
R CV(*F + v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const int32_t&))
{
auto v=val_to_c<const int32_t&>::f(ctx,a[1]);
R CV(*F + v);
}
CATE(TE,UFOF("Int4::__add__.")));
R CN;
}

SV Int4_setXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setXZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setXZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
( F->setXZ(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setXZ.")));
R CN;
}

SV Int4_getWYZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getWYZX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getWYZX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWYZX());
;
}
CATE(TE,UFOF("Int4::getWYZX.")));
R CN;
}

SV Int4_setXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setXW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setXW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
( F->setXW(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setXW.")));
R CN;
}

SV Int4_getWXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getWXZY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getWXZY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWXZY());
;
}
CATE(TE,UFOF("Int4::getWXZY.")));
R CN;
}

SV Int4_getXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getXY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getXY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXY());
;
}
CATE(TE,UFOF("Int4::getXY.")));
R CN;
}

SV Int4_setZXWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setZXWY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setZXWY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setZXWY(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setZXWY.")));
R CN;
}

SV Int4_setXYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setXYW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setXYW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setXYW(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setXYW.")));
R CN;
}

SV Int4_getXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getXZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getXZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXZ());
;
}
CATE(TE,UFOF("Int4::getXZ.")));
R CN;
}

SV Int4_setWZXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setWZXY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setWZXY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setWZXY(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setWZXY.")));
R CN;
}

SV Int4___grtr__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::__grtr__" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::__grtr__","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
auto v=val_to_c<const T4<int32_t> &>::f(ctx,a[1]);
R CV(*F > v);
}
CATE(TE,UFOF("Int4::__grtr__.")));
R CN;
}

SV Int4_setZWXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setZWXY" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setZWXY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setZWXY(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setZWXY.")));
R CN;
}

SV Int4_getXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getXW" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::getXW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXW());
;
}
CATE(TE,UFOF("Int4::getXW.")));
R CN;
}

SV Int4_setXYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setXYZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setXYZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<int32_t> &))
{
( F->setXYZ(val_to_c<const T3<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setXYZ.")));
R CN;
}

SV Int4___div__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::__div__" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::__div__","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
auto v=val_to_c<const T4<int32_t> &>::f(ctx,a[1]);
R CV(*F / v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const int32_t&))
{
auto v=val_to_c<const int32_t&>::f(ctx,a[1]);
R CV(*F / v);
}
CATE(TE,UFOF("Int4::__div__.")));
R CN;
}

SV Int4_setWYZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setWYZX" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setWYZX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setWYZX(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setWYZX.")));
R CN;
}

SV Int4_setYWXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setYWXZ" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::setYWXZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
( F->setYWXZ(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int4::setYWXZ.")));
R CN;
}

SV Int4___geq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::__geq__" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::__geq__","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
auto v=val_to_c<const T4<int32_t> &>::f(ctx,a[1]);
R CV(*F >= v);
}
CATE(TE,UFOF("Int4::__geq__.")));
R CN;
}

SV Int4_dot(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::dot" EAOE));
T4<int32_t>*F;
if(!TS(a[0],T4<int32_t>))
CATE(TE,FAE("Int4::dot","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<int32_t> &))
{
R CV( F->dot(val_to_c<const T4<int32_t> &>::f(ctx,a[1])));
;
}
if(a.getCount()==1)
if(1)
{
R CV( F->dot());
;
}
CATE(TE,UFOF("Int4::dot.")));
R CN;
}

void Float3_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,T3<float>))
CATE(TE,"Float3::__del__ expects Float3 as first argument."));

DELETE((T3<float>*)F->data);
}SV Float3_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3's constructor" EAOE));
if(!TS(a[0],T3<float>))
CATE(TE,"Float3's constructor expects Float3 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Float3_funcs,NEW(T3<float>),EXT->Float3_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],float))
R S::createNativeObject(Float3_funcs,NEW(T3<float>,val_to_c<float>::f(ctx,a[1])),EXT->Float3_typeID);
if(a.getCount()==4)
if(true&&TS(a[1],float)&&TS(a[2],float)&&TS(a[3],float))
R S::createNativeObject(Float3_funcs,NEW(T3<float>,val_to_c<float>::f(ctx,a[1]),val_to_c<float>::f(ctx,a[2]),val_to_c<float>::f(ctx,a[3])),EXT->Float3_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T3<float> &))
R S::createNativeObject(Float3_funcs,NEW(T3<float>,val_to_c<const T3<float> &>::f(ctx,a[1])),EXT->Float3_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T3<int32_t> &))
R S::createNativeObject(Float3_funcs,NEW(T3<float>,val_to_c<const T3<int32_t> &>::f(ctx,a[1])),EXT->Float3_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T3<uint32_t> &))
R S::createNativeObject(Float3_funcs,NEW(T3<float>,val_to_c<const T3<uint32_t> &>::f(ctx,a[1])),EXT->Float3_typeID);
CATE(TE,UFOF("Float3's constructor.")));
R CN;
}

SV Float3_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Float3");
EI(keyStr=="__new__")
R CNF(Float3_new);
EI(keyStr=="__call__")
R CNF(Float3_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(Float3_new);
 EI(keyStr == "__add__")
R CNF(Float3___add__);
 EI(keyStr == "__sub__")
R CNF(Float3___sub__);
 EI(keyStr == "__mul__")
R CNF(Float3___mul__);
 EI(keyStr == "__div__")
R CNF(Float3___div__);
 EI(keyStr == "__eq__")
R CNF(Float3___eq__);
 EI(keyStr == "__neq__")
R CNF(Float3___neq__);
 EI(keyStr == "__less__")
R CNF(Float3___less__);
 EI(keyStr == "__grtr__")
R CNF(Float3___grtr__);
 EI(keyStr == "__leq__")
R CNF(Float3___leq__);
 EI(keyStr == "__geq__")
R CNF(Float3___geq__);
 EI(keyStr == "sum")
R CNF(Float3_sum);
 EI(keyStr == "length")
R CNF(Float3_length);
 EI(keyStr == "lengthSquared")
R CNF(Float3_lengthSquared);
 EI(keyStr == "dot")
R CNF(Float3_dot);
 EI(keyStr == "distance")
R CNF(Float3_distance);
 EI(keyStr == "distanceSquared")
R CNF(Float3_distanceSquared);
 EI(keyStr == "normalize")
R CNF(Float3_normalize);
 EI(keyStr == "cross")
R CNF(Float3_cross);
 EI(keyStr == "getXY")
R CNF(Float3_getXY);
 EI(keyStr == "setXY")
R CNF(Float3_setXY);
 EI(keyStr == "getXZ")
R CNF(Float3_getXZ);
 EI(keyStr == "setXZ")
R CNF(Float3_setXZ);
 EI(keyStr == "getYX")
R CNF(Float3_getYX);
 EI(keyStr == "setYX")
R CNF(Float3_setYX);
 EI(keyStr == "getYZ")
R CNF(Float3_getYZ);
 EI(keyStr == "setYZ")
R CNF(Float3_setYZ);
 EI(keyStr == "getZX")
R CNF(Float3_getZX);
 EI(keyStr == "setZX")
R CNF(Float3_setZX);
 EI(keyStr == "getZY")
R CNF(Float3_getZY);
 EI(keyStr == "setZY")
R CNF(Float3_setZY);
 EI(keyStr == "getXYZ")
R CNF(Float3_getXYZ);
 EI(keyStr == "setXYZ")
R CNF(Float3_setXYZ);
 EI(keyStr == "getXZY")
R CNF(Float3_getXZY);
 EI(keyStr == "setXZY")
R CNF(Float3_setXZY);
 EI(keyStr == "getYXZ")
R CNF(Float3_getYXZ);
 EI(keyStr == "setYXZ")
R CNF(Float3_setYXZ);
 EI(keyStr == "getYZX")
R CNF(Float3_getYZX);
 EI(keyStr == "setYZX")
R CNF(Float3_setYZX);
 EI(keyStr == "getZXY")
R CNF(Float3_getZXY);
 EI(keyStr == "setZXY")
R CNF(Float3_setZXY);
 EI(keyStr == "getZYX")
R CNF(Float3_getZYX);
 EI(keyStr == "setZYX")
R CNF(Float3_setZYX);
 EI(keyStr=="x")
{
T3<float>*obj=(T3<float>*)F->data;
R CV(obj->x);
} EI(keyStr=="y")
{
T3<float>*obj=(T3<float>*)F->data;
R CV(obj->y);
} EI(keyStr=="z")
{
T3<float>*obj=(T3<float>*)F->data;
R CV(obj->z);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void Float3_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="x")
{
T3<float>*obj=(T3<float>*)F->data;
obj->x=val_to_c<decltype(obj->x)>::f(ctx,value);
} EI(keyStr=="y")
{
T3<float>*obj=(T3<float>*)F->data;
obj->y=val_to_c<decltype(obj->y)>::f(ctx,value);
} EI(keyStr=="z")
{
T3<float>*obj=(T3<float>*)F->data;
obj->z=val_to_c<decltype(obj->z)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV Float3_setYZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::setYZX" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::setYZX","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setYZX(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float3::setYZX.")));
R CN;
}

SV Float3_getZXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::getZXY" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::getZXY","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZXY());
;
}
CATE(TE,UFOF("Float3::getZXY.")));
R CN;
}

SV Float3_setYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::setYZ" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::setYZ","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
( F->setYZ(val_to_c<const T2<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float3::setYZ.")));
R CN;
}

SV Float3_setYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::setYX" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::setYX","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
( F->setYX(val_to_c<const T2<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float3::setYX.")));
R CN;
}

SV Float3_setZYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::setZYX" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::setZYX","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setZYX(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float3::setZYX.")));
R CN;
}

SV Float3_getZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::getZY" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::getZY","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZY());
;
}
CATE(TE,UFOF("Float3::getZY.")));
R CN;
}

SV Float3_distanceSquared(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::distanceSquared" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::distanceSquared","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
R CV( F->distanceSquared(val_to_c<const T3<float> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Float3::distanceSquared.")));
R CN;
}

SV Float3_normalize(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::normalize" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::normalize","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->normalize());
;
}
CATE(TE,UFOF("Float3::normalize.")));
R CN;
}

SV Float3_getYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::getYX" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::getYX","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYX());
;
}
CATE(TE,UFOF("Float3::getYX.")));
R CN;
}

SV Float3___leq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::__leq__" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::__leq__","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
auto v=val_to_c<const T3<float> &>::f(ctx,a[1]);
R CV(*F <= v);
}
CATE(TE,UFOF("Float3::__leq__.")));
R CN;
}

SV Float3_setXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::setXZY" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::setXZY","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setXZY(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float3::setXZY.")));
R CN;
}

SV Float3_sum(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::sum" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::sum","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->sum());
;
}
CATE(TE,UFOF("Float3::sum.")));
R CN;
}

SV Float3_cross(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::cross" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::cross","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
R CV( F->cross(val_to_c<const T3<float> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Float3::cross.")));
R CN;
}

SV Float3_getXYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::getXYZ" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::getXYZ","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXYZ());
;
}
CATE(TE,UFOF("Float3::getXYZ.")));
R CN;
}

SV Float3___less__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::__less__" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::__less__","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
auto v=val_to_c<const T3<float> &>::f(ctx,a[1]);
R CV(*F < v);
}
CATE(TE,UFOF("Float3::__less__.")));
R CN;
}

SV Float3___neq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::__neq__" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::__neq__","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
auto v=val_to_c<const T3<float> &>::f(ctx,a[1]);
R CV(*F != v);
}
CATE(TE,UFOF("Float3::__neq__.")));
R CN;
}

SV Float3_getYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::getYZ" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::getYZ","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYZ());
;
}
CATE(TE,UFOF("Float3::getYZ.")));
R CN;
}

SV Float3_lengthSquared(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::lengthSquared" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::lengthSquared","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->lengthSquared());
;
}
CATE(TE,UFOF("Float3::lengthSquared.")));
R CN;
}

SV Float3_getZYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::getZYX" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::getZYX","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZYX());
;
}
CATE(TE,UFOF("Float3::getZYX.")));
R CN;
}

SV Float3___div__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::__div__" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::__div__","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
auto v=val_to_c<const T3<float> &>::f(ctx,a[1]);
R CV(*F / v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const float&))
{
auto v=val_to_c<const float&>::f(ctx,a[1]);
R CV(*F / v);
}
CATE(TE,UFOF("Float3::__div__.")));
R CN;
}

SV Float3_setZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::setZY" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::setZY","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
( F->setZY(val_to_c<const T2<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float3::setZY.")));
R CN;
}

SV Float3_setZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::setZX" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::setZX","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
( F->setZX(val_to_c<const T2<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float3::setZX.")));
R CN;
}

SV Float3_setXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::setXY" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::setXY","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
( F->setXY(val_to_c<const T2<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float3::setXY.")));
R CN;
}

SV Float3___add__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::__add__" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::__add__","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
auto v=val_to_c<const T3<float> &>::f(ctx,a[1]);
R CV(*F + v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const float&))
{
auto v=val_to_c<const float&>::f(ctx,a[1]);
R CV(*F + v);
}
CATE(TE,UFOF("Float3::__add__.")));
R CN;
}

SV Float3_setXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::setXZ" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::setXZ","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
( F->setXZ(val_to_c<const T2<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float3::setXZ.")));
R CN;
}

SV Float3___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::__eq__" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::__eq__","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
auto v=val_to_c<const T3<float> &>::f(ctx,a[1]);
R CV(*F == v);
}
CATE(TE,UFOF("Float3::__eq__.")));
R CN;
}

SV Float3_setZXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::setZXY" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::setZXY","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setZXY(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float3::setZXY.")));
R CN;
}

SV Float3_setYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::setYXZ" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::setYXZ","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setYXZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float3::setYXZ.")));
R CN;
}

SV Float3_getXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::getXY" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::getXY","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXY());
;
}
CATE(TE,UFOF("Float3::getXY.")));
R CN;
}

SV Float3_distance(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::distance" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::distance","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
R CV( F->distance(val_to_c<const T3<float> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Float3::distance.")));
R CN;
}

SV Float3_getXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::getXZ" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::getXZ","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXZ());
;
}
CATE(TE,UFOF("Float3::getXZ.")));
R CN;
}

SV Float3___grtr__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::__grtr__" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::__grtr__","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
auto v=val_to_c<const T3<float> &>::f(ctx,a[1]);
R CV(*F > v);
}
CATE(TE,UFOF("Float3::__grtr__.")));
R CN;
}

SV Float3_getXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::getXZY" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::getXZY","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXZY());
;
}
CATE(TE,UFOF("Float3::getXZY.")));
R CN;
}

SV Float3_setXYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::setXYZ" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::setXYZ","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setXYZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float3::setXYZ.")));
R CN;
}

SV Float3_getYZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::getYZX" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::getYZX","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYZX());
;
}
CATE(TE,UFOF("Float3::getYZX.")));
R CN;
}

SV Float3_length(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::length" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::length","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->length());
;
}
CATE(TE,UFOF("Float3::length.")));
R CN;
}

SV Float3___mul__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::__mul__" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::__mul__","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
auto v=val_to_c<const T3<float> &>::f(ctx,a[1]);
R CV(*F * v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const float&))
{
auto v=val_to_c<const float&>::f(ctx,a[1]);
R CV(*F * v);
}
CATE(TE,UFOF("Float3::__mul__.")));
R CN;
}

SV Float3_getYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::getYXZ" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::getYXZ","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYXZ());
;
}
CATE(TE,UFOF("Float3::getYXZ.")));
R CN;
}

SV Float3_getZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::getZX" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::getZX","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZX());
;
}
CATE(TE,UFOF("Float3::getZX.")));
R CN;
}

SV Float3___sub__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::__sub__" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::__sub__","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
auto v=val_to_c<const T3<float> &>::f(ctx,a[1]);
R CV(*F - v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const float&))
{
auto v=val_to_c<const float&>::f(ctx,a[1]);
R CV(*F - v);
}
CATE(TE,UFOF("Float3::__sub__.")));
R CN;
}

SV Float3___geq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::__geq__" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::__geq__","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
auto v=val_to_c<const T3<float> &>::f(ctx,a[1]);
R CV(*F >= v);
}
CATE(TE,UFOF("Float3::__geq__.")));
R CN;
}

SV Float3_dot(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::dot" EAOE));
T3<float>*F;
if(!TS(a[0],T3<float>))
CATE(TE,FAE("Float3::dot","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
R CV( F->dot(val_to_c<const T3<float> &>::f(ctx,a[1])));
;
}
if(a.getCount()==1)
if(1)
{
R CV( F->dot());
;
}
CATE(TE,UFOF("Float3::dot.")));
R CN;
}

void GfxLODList_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,List<GfxLOD>))
CATE(TE,"GfxLODList::__del__ expects GfxLODList as first argument."));

DELETE((List<GfxLOD>*)F->data);
}SV GfxLODList_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxLODList's constructor" EAOE));
if(!TS(a[0],List<GfxLOD>))
CATE(TE,"GfxLODList's constructor expects GfxLODList as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(GfxLODList_funcs,NEW(List<GfxLOD>),EXT->GfxLODList_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],std::size_t))
R S::createNativeObject(GfxLODList_funcs,NEW(List<GfxLOD>,val_to_c<std::size_t>::f(ctx,a[1])),EXT->GfxLODList_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const List<GfxLOD> &))
R S::createNativeObject(GfxLODList_funcs,NEW(List<GfxLOD>,val_to_c<const List<GfxLOD> &>::f(ctx,a[1])),EXT->GfxLODList_typeID);
CATE(TE,UFOF("GfxLODList's constructor.")));
R CN;
}

SV GfxLODList_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxLODList");
EI(keyStr=="__new__")
R CNF(GfxLODList_new);
EI(keyStr=="__call__")
R CNF(GfxLODList_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(GfxLODList_new);
 EI(keyStr == "__eq__")
R CNF(GfxLODList___eq__);
 EI(keyStr == "__neq__")
R CNF(GfxLODList___neq__);
 EI(keyStr == "getCount")
R CNF(GfxLODList_getCount);
 EI(keyStr == "getData")
R CNF(GfxLODList_getData);
 EI(keyStr == "append")
R CNF(GfxLODList_append);
 EI(keyStr == "insert")
R CNF(GfxLODList_insert);
 EI(keyStr == "remove")
R CNF(GfxLODList_remove);
 EI(keyStr == "clear")
R CNF(GfxLODList_clear);
 EI(keyStr == "find")
R CNF(GfxLODList_find);
 EI(keyStr == "copy")
R CNF(GfxLODList_copy);
 EI(keyStr == "in")
R CNF(GfxLODList_in);
 else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void GfxLODList_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV GfxLODList_insert(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxLODList::insert" EAOE));
List<GfxLOD>*F;
if(!TS(a[0],List<GfxLOD>))
CATE(TE,FAE("GfxLODList::insert","GfxLODList")));
else
 F=(List<GfxLOD>*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],std::size_t)&&TS(a[2],const GfxLOD&))
{
( F->insert(val_to_c<std::size_t>::f(ctx,a[1]), val_to_c<const GfxLOD&>::f(ctx,a[2])));
R CN;
}
if(a.getCount()==3)
if(1&&TS(a[1],std::size_t)&&TS(a[2],const List<GfxLOD> &))
{
( F->insert(val_to_c<std::size_t>::f(ctx,a[1]), val_to_c<const List<GfxLOD> &>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("GfxLODList::insert.")));
R CN;
}

SV GfxLODList_copy(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxLODList::copy" EAOE));
List<GfxLOD>*F;
if(!TS(a[0],List<GfxLOD>))
CATE(TE,FAE("GfxLODList::copy","GfxLODList")));
else
 F=(List<GfxLOD>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->copy());
;
}
CATE(TE,UFOF("GfxLODList::copy.")));
R CN;
}

SV GfxLODList_clear(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxLODList::clear" EAOE));
List<GfxLOD>*F;
if(!TS(a[0],List<GfxLOD>))
CATE(TE,FAE("GfxLODList::clear","GfxLODList")));
else
 F=(List<GfxLOD>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->clear());
R CN;
}
CATE(TE,UFOF("GfxLODList::clear.")));
R CN;
}

SV GfxLODList_remove(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxLODList::remove" EAOE));
List<GfxLOD>*F;
if(!TS(a[0],List<GfxLOD>))
CATE(TE,FAE("GfxLODList::remove","GfxLODList")));
else
 F=(List<GfxLOD>*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],std::size_t)&&TS(a[2],std::size_t))
{
( F->remove(val_to_c<std::size_t>::f(ctx,a[1]), val_to_c<std::size_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("GfxLODList::remove.")));
R CN;
}

SV GfxLODList_in(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxLODList::in" EAOE));
List<GfxLOD>*F;
if(!TS(a[0],List<GfxLOD>))
CATE(TE,FAE("GfxLODList::in","GfxLODList")));
else
 F=(List<GfxLOD>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const GfxLOD&))
{
R CV( F->in(val_to_c<const GfxLOD&>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("GfxLODList::in.")));
R CN;
}

SV GfxLODList_getCount(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxLODList::getCount" EAOE));
List<GfxLOD>*F;
if(!TS(a[0],List<GfxLOD>))
CATE(TE,FAE("GfxLODList::getCount","GfxLODList")));
else
 F=(List<GfxLOD>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getCount());
;
}
CATE(TE,UFOF("GfxLODList::getCount.")));
R CN;
}

SV GfxLODList_getData(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxLODList::getData" EAOE));
List<GfxLOD>*F;
if(!TS(a[0],List<GfxLOD>))
CATE(TE,FAE("GfxLODList::getData","GfxLODList")));
else
 F=(List<GfxLOD>*)((NO)a[0])->data;

CATE(TE,UFOF("GfxLODList::getData.")));
R CN;
}

SV GfxLODList___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxLODList::__eq__" EAOE));
List<GfxLOD>*F;
if(!TS(a[0],List<GfxLOD>))
CATE(TE,FAE("GfxLODList::__eq__","GfxLODList")));
else
 F=(List<GfxLOD>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const List<GfxLOD> &))
{
auto v=val_to_c<const List<GfxLOD> &>::f(ctx,a[1]);
R CV(*F == v);
}
CATE(TE,UFOF("GfxLODList::__eq__.")));
R CN;
}

SV GfxLODList_find(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxLODList::find" EAOE));
List<GfxLOD>*F;
if(!TS(a[0],List<GfxLOD>))
CATE(TE,FAE("GfxLODList::find","GfxLODList")));
else
 F=(List<GfxLOD>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const GfxLOD&))
{
R CV( F->find(val_to_c<const GfxLOD&>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("GfxLODList::find.")));
R CN;
}

SV GfxLODList_append(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxLODList::append" EAOE));
List<GfxLOD>*F;
if(!TS(a[0],List<GfxLOD>))
CATE(TE,FAE("GfxLODList::append","GfxLODList")));
else
 F=(List<GfxLOD>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const GfxLOD&))
{
( F->append(val_to_c<const GfxLOD&>::f(ctx,a[1])));
R CN;
}
if(a.getCount()==2)
if(1&&TS(a[1],const List<GfxLOD> &))
{
( F->append(val_to_c<const List<GfxLOD> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("GfxLODList::append.")));
R CN;
}

SV GfxLODList___neq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxLODList::__neq__" EAOE));
List<GfxLOD>*F;
if(!TS(a[0],List<GfxLOD>))
CATE(TE,FAE("GfxLODList::__neq__","GfxLODList")));
else
 F=(List<GfxLOD>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const List<GfxLOD> &))
{
auto v=val_to_c<const List<GfxLOD> &>::f(ctx,a[1]);
R CV(*F != v);
}
CATE(TE,UFOF("GfxLODList::__neq__.")));
R CN;
}

void GfxBuffer_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,GfxBuffer))
CATE(TE,"GfxBuffer::__del__ expects GfxBuffer as first argument."));

DELETE((GfxBuffer*)F->data);
}SV GfxBuffer_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"GfxBuffer's constructor" EAOE));
if(!TS(a[0],GfxBuffer))
CATE(TE,"GfxBuffer's constructor expects GfxBuffer as first argument."));
CATE(TE,UFOF("GfxBuffer's constructor.")));
}

SV GfxBuffer_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxBuffer");
EI(keyStr=="__new__")
R CNF(GfxBuffer_new);
EI(keyStr=="__call__")
R CNF(GfxBuffer_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(GfxBuffer_new);
 EI(keyStr == "allocData")
R CNF(GfxBuffer_allocData);
 EI(keyStr == "setData")
R CNF(GfxBuffer_setData);
 EI(keyStr == "getData")
R CNF(GfxBuffer_getData);
 EI(keyStr == "getSize")
R CNF(GfxBuffer_getSize);
 else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void GfxBuffer_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV GfxBuffer_getSize(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxBuffer::getSize" EAOE));
GfxBuffer*F;
if(!TS(a[0],GfxBuffer))
CATE(TE,FAE("GfxBuffer::getSize","GfxBuffer")));
else
 F=(GfxBuffer*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getSize());
;
}
CATE(TE,UFOF("GfxBuffer::getSize.")));
R CN;
}

SV GfxBuffer_getData(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxBuffer::getData" EAOE));
GfxBuffer*F;
if(!TS(a[0],GfxBuffer))
CATE(TE,FAE("GfxBuffer::getData","GfxBuffer")));
else
 F=(GfxBuffer*)((NO)a[0])->data;

CATE(TE,UFOF("GfxBuffer::getData.")));
R CN;
}

SV GfxBuffer_allocData(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxBuffer::allocData" EAOE));
GfxBuffer*F;
if(!TS(a[0],GfxBuffer))
CATE(TE,FAE("GfxBuffer::allocData","GfxBuffer")));
else
 F=(GfxBuffer*)((NO)a[0])->data;

CATE(TE,UFOF("GfxBuffer::allocData.")));
R CN;
}

SV GfxBuffer_setData(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxBuffer::setData" EAOE));
GfxBuffer*F;
if(!TS(a[0],GfxBuffer))
CATE(TE,FAE("GfxBuffer::setData","GfxBuffer")));
else
 F=(GfxBuffer*)((NO)a[0])->data;

CATE(TE,UFOF("GfxBuffer::setData.")));
R CN;
}

void Transform_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,Transform))
CATE(TE,"Transform::__del__ expects Transform as first argument."));

DELETE((Transform*)F->data);
}SV Transform_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Transform's constructor" EAOE));
if(!TS(a[0],Transform))
CATE(TE,"Transform's constructor expects Transform as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Transform_funcs,NEW(Transform),EXT->Transform_typeID);
CATE(TE,UFOF("Transform's constructor.")));
R CN;
}

SV Transform_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Transform");
EI(keyStr=="__new__")
R CNF(Transform_new);
EI(keyStr=="__call__")
R CNF(Transform_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(Transform_new);
 EI(keyStr == "createMatrix")
R CNF(Transform_createMatrix);
 EI(keyStr=="orientation")
{
Transform*obj=(Transform*)F->data;
R CV(obj->orientation);
} EI(keyStr=="scale")
{
Transform*obj=(Transform*)F->data;
R CV(obj->scale);
} EI(keyStr=="position")
{
Transform*obj=(Transform*)F->data;
R CV(obj->position);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void Transform_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="orientation")
{
Transform*obj=(Transform*)F->data;
obj->orientation=val_to_c<decltype(obj->orientation)>::f(ctx,value);
} EI(keyStr=="scale")
{
Transform*obj=(Transform*)F->data;
obj->scale=val_to_c<decltype(obj->scale)>::f(ctx,value);
} EI(keyStr=="position")
{
Transform*obj=(Transform*)F->data;
obj->position=val_to_c<decltype(obj->position)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV Transform_createMatrix(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Transform::createMatrix" EAOE));
Transform*F;
if(!TS(a[0],Transform))
CATE(TE,FAE("Transform::createMatrix","Transform")));
else
 F=(Transform*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->createMatrix());
;
}
CATE(TE,UFOF("Transform::createMatrix.")));
R CN;
}

void Quaternion_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,Quaternion))
CATE(TE,"Quaternion::__del__ expects Quaternion as first argument."));

DELETE((Quaternion*)F->data);
}SV Quaternion_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion's constructor" EAOE));
if(!TS(a[0],Quaternion))
CATE(TE,"Quaternion's constructor expects Quaternion as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Quaternion_funcs,NEW(Quaternion),EXT->Quaternion_typeID);
if(a.getCount()==3)
if(true&&TS(a[1],const Direction3D &)&&TS(a[2],float))
R S::createNativeObject(Quaternion_funcs,NEW(Quaternion,val_to_c<const Direction3D &>::f(ctx,a[1]),val_to_c<float>::f(ctx,a[2])),EXT->Quaternion_typeID);
if(a.getCount()==5)
if(true&&TS(a[1],float)&&TS(a[2],float)&&TS(a[3],float)&&TS(a[4],float))
R S::createNativeObject(Quaternion_funcs,NEW(Quaternion,val_to_c<float>::f(ctx,a[1]),val_to_c<float>::f(ctx,a[2]),val_to_c<float>::f(ctx,a[3]),val_to_c<float>::f(ctx,a[4])),EXT->Quaternion_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const Float3 &))
R S::createNativeObject(Quaternion_funcs,NEW(Quaternion,val_to_c<const Float3 &>::f(ctx,a[1])),EXT->Quaternion_typeID);
CATE(TE,UFOF("Quaternion's constructor.")));
R CN;
}

SV Quaternion_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Quaternion");
EI(keyStr=="__new__")
R CNF(Quaternion_new);
EI(keyStr=="__call__")
R CNF(Quaternion_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(Quaternion_new);
 EI(keyStr == "__mul__")
R CNF(Quaternion___mul__);
 EI(keyStr == "toMatrix")
R CNF(Quaternion_toMatrix);
 EI(keyStr == "__eq__")
R CNF(Quaternion___eq__);
 EI(keyStr == "normalize")
R CNF(Quaternion_normalize);
 EI(keyStr == "getAngle")
R CNF(Quaternion_getAngle);
 EI(keyStr == "getXAxis")
R CNF(Quaternion_getXAxis);
 EI(keyStr == "getYAxis")
R CNF(Quaternion_getYAxis);
 EI(keyStr == "getZAxis")
R CNF(Quaternion_getZAxis);
 EI(keyStr == "getAxis")
R CNF(Quaternion_getAxis);
 EI(keyStr == "getAxisAndAngle")
R CNF(Quaternion_getAxisAndAngle);
 EI(keyStr == "setAngle")
R CNF(Quaternion_setAngle);
 EI(keyStr == "setXAxis")
R CNF(Quaternion_setXAxis);
 EI(keyStr == "setYAxis")
R CNF(Quaternion_setYAxis);
 EI(keyStr == "setZAxis")
R CNF(Quaternion_setZAxis);
 EI(keyStr == "setAxis")
R CNF(Quaternion_setAxis);
 EI(keyStr == "setAxisAndAngle")
R CNF(Quaternion_setAxisAndAngle);
 EI(keyStr == "setEulerAngles")
R CNF(Quaternion_setEulerAngles);
 EI(keyStr == "getEulerAngles")
R CNF(Quaternion_getEulerAngles);
 EI(keyStr=="x")
{
Quaternion*obj=(Quaternion*)F->data;
R CV(obj->x);
} EI(keyStr=="y")
{
Quaternion*obj=(Quaternion*)F->data;
R CV(obj->y);
} EI(keyStr=="z")
{
Quaternion*obj=(Quaternion*)F->data;
R CV(obj->z);
} EI(keyStr=="w")
{
Quaternion*obj=(Quaternion*)F->data;
R CV(obj->w);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void Quaternion_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="x")
{
Quaternion*obj=(Quaternion*)F->data;
obj->x=val_to_c<decltype(obj->x)>::f(ctx,value);
} EI(keyStr=="y")
{
Quaternion*obj=(Quaternion*)F->data;
obj->y=val_to_c<decltype(obj->y)>::f(ctx,value);
} EI(keyStr=="z")
{
Quaternion*obj=(Quaternion*)F->data;
obj->z=val_to_c<decltype(obj->z)>::f(ctx,value);
} EI(keyStr=="w")
{
Quaternion*obj=(Quaternion*)F->data;
obj->w=val_to_c<decltype(obj->w)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV Quaternion_normalize(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion::normalize" EAOE));
Quaternion*F;
if(!TS(a[0],Quaternion))
CATE(TE,FAE("Quaternion::normalize","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->normalize());
;
}
CATE(TE,UFOF("Quaternion::normalize.")));
R CN;
}

SV Quaternion_setEulerAngles(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion::setEulerAngles" EAOE));
Quaternion*F;
if(!TS(a[0],Quaternion))
CATE(TE,FAE("Quaternion::setEulerAngles","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Float3 &))
{
( F->setEulerAngles(val_to_c<const Float3 &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Quaternion::setEulerAngles.")));
R CN;
}

SV Quaternion_getAngle(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion::getAngle" EAOE));
Quaternion*F;
if(!TS(a[0],Quaternion))
CATE(TE,FAE("Quaternion::getAngle","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getAngle());
;
}
CATE(TE,UFOF("Quaternion::getAngle.")));
R CN;
}

SV Quaternion_getAxis(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion::getAxis" EAOE));
Quaternion*F;
if(!TS(a[0],Quaternion))
CATE(TE,FAE("Quaternion::getAxis","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getAxis());
;
}
CATE(TE,UFOF("Quaternion::getAxis.")));
R CN;
}

SV Quaternion_setAngle(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion::setAngle" EAOE));
Quaternion*F;
if(!TS(a[0],Quaternion))
CATE(TE,FAE("Quaternion::setAngle","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->setAngle(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Quaternion::setAngle.")));
R CN;
}

SV Quaternion_setYAxis(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion::setYAxis" EAOE));
Quaternion*F;
if(!TS(a[0],Quaternion))
CATE(TE,FAE("Quaternion::setYAxis","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->setYAxis(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Quaternion::setYAxis.")));
R CN;
}

SV Quaternion_getEulerAngles(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion::getEulerAngles" EAOE));
Quaternion*F;
if(!TS(a[0],Quaternion))
CATE(TE,FAE("Quaternion::getEulerAngles","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getEulerAngles());
;
}
CATE(TE,UFOF("Quaternion::getEulerAngles.")));
R CN;
}

SV Quaternion_setAxisAndAngle(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion::setAxisAndAngle" EAOE));
Quaternion*F;
if(!TS(a[0],Quaternion))
CATE(TE,FAE("Quaternion::setAxisAndAngle","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],const Direction3D &)&&TS(a[2],float))
{
( F->setAxisAndAngle(val_to_c<const Direction3D &>::f(ctx,a[1]), val_to_c<float>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("Quaternion::setAxisAndAngle.")));
R CN;
}

SV Quaternion_getAxisAndAngle(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion::getAxisAndAngle" EAOE));
Quaternion*F;
if(!TS(a[0],Quaternion))
CATE(TE,FAE("Quaternion::getAxisAndAngle","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getAxisAndAngle());
;
}
CATE(TE,UFOF("Quaternion::getAxisAndAngle.")));
R CN;
}

SV Quaternion_setAxis(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion::setAxis" EAOE));
Quaternion*F;
if(!TS(a[0],Quaternion))
CATE(TE,FAE("Quaternion::setAxis","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Direction3D &))
{
( F->setAxis(val_to_c<const Direction3D &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Quaternion::setAxis.")));
R CN;
}

SV Quaternion___mul__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion::__mul__" EAOE));
Quaternion*F;
if(!TS(a[0],Quaternion))
CATE(TE,FAE("Quaternion::__mul__","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Quaternion &))
{
auto v=val_to_c<const Quaternion &>::f(ctx,a[1]);
R CV(*F * v);
}
CATE(TE,UFOF("Quaternion::__mul__.")));
R CN;
}

SV Quaternion_getYAxis(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion::getYAxis" EAOE));
Quaternion*F;
if(!TS(a[0],Quaternion))
CATE(TE,FAE("Quaternion::getYAxis","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYAxis());
;
}
CATE(TE,UFOF("Quaternion::getYAxis.")));
R CN;
}

SV Quaternion_getXAxis(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion::getXAxis" EAOE));
Quaternion*F;
if(!TS(a[0],Quaternion))
CATE(TE,FAE("Quaternion::getXAxis","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXAxis());
;
}
CATE(TE,UFOF("Quaternion::getXAxis.")));
R CN;
}

SV Quaternion_toMatrix(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion::toMatrix" EAOE));
Quaternion*F;
if(!TS(a[0],Quaternion))
CATE(TE,FAE("Quaternion::toMatrix","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->toMatrix());
;
}
CATE(TE,UFOF("Quaternion::toMatrix.")));
R CN;
}

SV Quaternion_setZAxis(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion::setZAxis" EAOE));
Quaternion*F;
if(!TS(a[0],Quaternion))
CATE(TE,FAE("Quaternion::setZAxis","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->setZAxis(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Quaternion::setZAxis.")));
R CN;
}

SV Quaternion_setXAxis(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion::setXAxis" EAOE));
Quaternion*F;
if(!TS(a[0],Quaternion))
CATE(TE,FAE("Quaternion::setXAxis","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->setXAxis(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Quaternion::setXAxis.")));
R CN;
}

SV Quaternion___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion::__eq__" EAOE));
Quaternion*F;
if(!TS(a[0],Quaternion))
CATE(TE,FAE("Quaternion::__eq__","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Quaternion &))
{
auto v=val_to_c<const Quaternion &>::f(ctx,a[1]);
R CV(*F == v);
}
CATE(TE,UFOF("Quaternion::__eq__.")));
R CN;
}

SV Quaternion_getZAxis(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion::getZAxis" EAOE));
Quaternion*F;
if(!TS(a[0],Quaternion))
CATE(TE,FAE("Quaternion::getZAxis","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZAxis());
;
}
CATE(TE,UFOF("Quaternion::getZAxis.")));
R CN;
}

void Int2_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,T2<int32_t>))
CATE(TE,"Int2::__del__ expects Int2 as first argument."));

DELETE((T2<int32_t>*)F->data);
}SV Int2_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2's constructor" EAOE));
if(!TS(a[0],T2<int32_t>))
CATE(TE,"Int2's constructor expects Int2 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Int2_funcs,NEW(T2<int32_t>),EXT->Int2_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],int32_t))
R S::createNativeObject(Int2_funcs,NEW(T2<int32_t>,val_to_c<int32_t>::f(ctx,a[1])),EXT->Int2_typeID);
if(a.getCount()==3)
if(true&&TS(a[1],int32_t)&&TS(a[2],int32_t))
R S::createNativeObject(Int2_funcs,NEW(T2<int32_t>,val_to_c<int32_t>::f(ctx,a[1]),val_to_c<int32_t>::f(ctx,a[2])),EXT->Int2_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T2<float> &))
R S::createNativeObject(Int2_funcs,NEW(T2<int32_t>,val_to_c<const T2<float> &>::f(ctx,a[1])),EXT->Int2_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T2<int32_t> &))
R S::createNativeObject(Int2_funcs,NEW(T2<int32_t>,val_to_c<const T2<int32_t> &>::f(ctx,a[1])),EXT->Int2_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T2<uint32_t> &))
R S::createNativeObject(Int2_funcs,NEW(T2<int32_t>,val_to_c<const T2<uint32_t> &>::f(ctx,a[1])),EXT->Int2_typeID);
CATE(TE,UFOF("Int2's constructor.")));
R CN;
}

SV Int2_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Int2");
EI(keyStr=="__new__")
R CNF(Int2_new);
EI(keyStr=="__call__")
R CNF(Int2_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(Int2_new);
 EI(keyStr == "__add__")
R CNF(Int2___add__);
 EI(keyStr == "__sub__")
R CNF(Int2___sub__);
 EI(keyStr == "__mul__")
R CNF(Int2___mul__);
 EI(keyStr == "__div__")
R CNF(Int2___div__);
 EI(keyStr == "__eq__")
R CNF(Int2___eq__);
 EI(keyStr == "__neq__")
R CNF(Int2___neq__);
 EI(keyStr == "__less__")
R CNF(Int2___less__);
 EI(keyStr == "__grtr__")
R CNF(Int2___grtr__);
 EI(keyStr == "__leq__")
R CNF(Int2___leq__);
 EI(keyStr == "__geq__")
R CNF(Int2___geq__);
 EI(keyStr == "sum")
R CNF(Int2_sum);
 EI(keyStr == "length")
R CNF(Int2_length);
 EI(keyStr == "lengthSquared")
R CNF(Int2_lengthSquared);
 EI(keyStr == "dot")
R CNF(Int2_dot);
 EI(keyStr == "distance")
R CNF(Int2_distance);
 EI(keyStr == "distanceSquared")
R CNF(Int2_distanceSquared);
 EI(keyStr == "normalize")
R CNF(Int2_normalize);
 EI(keyStr == "getXY")
R CNF(Int2_getXY);
 EI(keyStr == "setXY")
R CNF(Int2_setXY);
 EI(keyStr == "getYX")
R CNF(Int2_getYX);
 EI(keyStr == "setYX")
R CNF(Int2_setYX);
 EI(keyStr=="x")
{
T2<int32_t>*obj=(T2<int32_t>*)F->data;
R CV(obj->x);
} EI(keyStr=="y")
{
T2<int32_t>*obj=(T2<int32_t>*)F->data;
R CV(obj->y);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void Int2_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="x")
{
T2<int32_t>*obj=(T2<int32_t>*)F->data;
obj->x=val_to_c<decltype(obj->x)>::f(ctx,value);
} EI(keyStr=="y")
{
T2<int32_t>*obj=(T2<int32_t>*)F->data;
obj->y=val_to_c<decltype(obj->y)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV Int2_normalize(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::normalize" EAOE));
T2<int32_t>*F;
if(!TS(a[0],T2<int32_t>))
CATE(TE,FAE("Int2::normalize","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->normalize());
;
}
CATE(TE,UFOF("Int2::normalize.")));
R CN;
}

SV Int2_distance(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::distance" EAOE));
T2<int32_t>*F;
if(!TS(a[0],T2<int32_t>))
CATE(TE,FAE("Int2::distance","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
R CV( F->distance(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Int2::distance.")));
R CN;
}

SV Int2_lengthSquared(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::lengthSquared" EAOE));
T2<int32_t>*F;
if(!TS(a[0],T2<int32_t>))
CATE(TE,FAE("Int2::lengthSquared","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->lengthSquared());
;
}
CATE(TE,UFOF("Int2::lengthSquared.")));
R CN;
}

SV Int2___leq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::__leq__" EAOE));
T2<int32_t>*F;
if(!TS(a[0],T2<int32_t>))
CATE(TE,FAE("Int2::__leq__","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
auto v=val_to_c<const T2<int32_t> &>::f(ctx,a[1]);
R CV(*F <= v);
}
CATE(TE,UFOF("Int2::__leq__.")));
R CN;
}

SV Int2_setYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::setYX" EAOE));
T2<int32_t>*F;
if(!TS(a[0],T2<int32_t>))
CATE(TE,FAE("Int2::setYX","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
( F->setYX(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int2::setYX.")));
R CN;
}

SV Int2___grtr__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::__grtr__" EAOE));
T2<int32_t>*F;
if(!TS(a[0],T2<int32_t>))
CATE(TE,FAE("Int2::__grtr__","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
auto v=val_to_c<const T2<int32_t> &>::f(ctx,a[1]);
R CV(*F > v);
}
CATE(TE,UFOF("Int2::__grtr__.")));
R CN;
}

SV Int2_sum(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::sum" EAOE));
T2<int32_t>*F;
if(!TS(a[0],T2<int32_t>))
CATE(TE,FAE("Int2::sum","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->sum());
;
}
CATE(TE,UFOF("Int2::sum.")));
R CN;
}

SV Int2_getXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::getXY" EAOE));
T2<int32_t>*F;
if(!TS(a[0],T2<int32_t>))
CATE(TE,FAE("Int2::getXY","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXY());
;
}
CATE(TE,UFOF("Int2::getXY.")));
R CN;
}

SV Int2_length(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::length" EAOE));
T2<int32_t>*F;
if(!TS(a[0],T2<int32_t>))
CATE(TE,FAE("Int2::length","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->length());
;
}
CATE(TE,UFOF("Int2::length.")));
R CN;
}

SV Int2_getYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::getYX" EAOE));
T2<int32_t>*F;
if(!TS(a[0],T2<int32_t>))
CATE(TE,FAE("Int2::getYX","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYX());
;
}
CATE(TE,UFOF("Int2::getYX.")));
R CN;
}

SV Int2___div__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::__div__" EAOE));
T2<int32_t>*F;
if(!TS(a[0],T2<int32_t>))
CATE(TE,FAE("Int2::__div__","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
auto v=val_to_c<const T2<int32_t> &>::f(ctx,a[1]);
R CV(*F / v);
}
if(a.getCount()==2)
if(1&&TS(a[1],int32_t))
{
auto v=val_to_c<int32_t>::f(ctx,a[1]);
R CV(*F / v);
}
CATE(TE,UFOF("Int2::__div__.")));
R CN;
}

SV Int2_setXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::setXY" EAOE));
T2<int32_t>*F;
if(!TS(a[0],T2<int32_t>))
CATE(TE,FAE("Int2::setXY","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
( F->setXY(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Int2::setXY.")));
R CN;
}

SV Int2___mul__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::__mul__" EAOE));
T2<int32_t>*F;
if(!TS(a[0],T2<int32_t>))
CATE(TE,FAE("Int2::__mul__","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
auto v=val_to_c<const T2<int32_t> &>::f(ctx,a[1]);
R CV(*F * v);
}
if(a.getCount()==2)
if(1&&TS(a[1],int32_t))
{
auto v=val_to_c<int32_t>::f(ctx,a[1]);
R CV(*F * v);
}
CATE(TE,UFOF("Int2::__mul__.")));
R CN;
}

SV Int2___add__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::__add__" EAOE));
T2<int32_t>*F;
if(!TS(a[0],T2<int32_t>))
CATE(TE,FAE("Int2::__add__","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
auto v=val_to_c<const T2<int32_t> &>::f(ctx,a[1]);
R CV(*F + v);
}
if(a.getCount()==2)
if(1&&TS(a[1],int32_t))
{
auto v=val_to_c<int32_t>::f(ctx,a[1]);
R CV(*F + v);
}
CATE(TE,UFOF("Int2::__add__.")));
R CN;
}

SV Int2___less__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::__less__" EAOE));
T2<int32_t>*F;
if(!TS(a[0],T2<int32_t>))
CATE(TE,FAE("Int2::__less__","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
auto v=val_to_c<const T2<int32_t> &>::f(ctx,a[1]);
R CV(*F < v);
}
CATE(TE,UFOF("Int2::__less__.")));
R CN;
}

SV Int2___sub__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::__sub__" EAOE));
T2<int32_t>*F;
if(!TS(a[0],T2<int32_t>))
CATE(TE,FAE("Int2::__sub__","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
auto v=val_to_c<const T2<int32_t> &>::f(ctx,a[1]);
R CV(*F - v);
}
if(a.getCount()==2)
if(1&&TS(a[1],int32_t))
{
auto v=val_to_c<int32_t>::f(ctx,a[1]);
R CV(*F - v);
}
CATE(TE,UFOF("Int2::__sub__.")));
R CN;
}

SV Int2___geq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::__geq__" EAOE));
T2<int32_t>*F;
if(!TS(a[0],T2<int32_t>))
CATE(TE,FAE("Int2::__geq__","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
auto v=val_to_c<const T2<int32_t> &>::f(ctx,a[1]);
R CV(*F >= v);
}
CATE(TE,UFOF("Int2::__geq__.")));
R CN;
}

SV Int2_distanceSquared(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::distanceSquared" EAOE));
T2<int32_t>*F;
if(!TS(a[0],T2<int32_t>))
CATE(TE,FAE("Int2::distanceSquared","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
R CV( F->distanceSquared(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Int2::distanceSquared.")));
R CN;
}

SV Int2___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::__eq__" EAOE));
T2<int32_t>*F;
if(!TS(a[0],T2<int32_t>))
CATE(TE,FAE("Int2::__eq__","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
auto v=val_to_c<const T2<int32_t> &>::f(ctx,a[1]);
R CV(*F == v);
}
CATE(TE,UFOF("Int2::__eq__.")));
R CN;
}

SV Int2_dot(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::dot" EAOE));
T2<int32_t>*F;
if(!TS(a[0],T2<int32_t>))
CATE(TE,FAE("Int2::dot","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
R CV( F->dot(val_to_c<const T2<int32_t> &>::f(ctx,a[1])));
;
}
if(a.getCount()==1)
if(1)
{
R CV( F->dot());
;
}
CATE(TE,UFOF("Int2::dot.")));
R CN;
}

SV Int2___neq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::__neq__" EAOE));
T2<int32_t>*F;
if(!TS(a[0],T2<int32_t>))
CATE(TE,FAE("Int2::__neq__","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<int32_t> &))
{
auto v=val_to_c<const T2<int32_t> &>::f(ctx,a[1]);
R CV(*F != v);
}
CATE(TE,UFOF("Int2::__neq__.")));
R CN;
}

void AudioWorld_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,AudioWorld))
CATE(TE,"AudioWorld::__del__ expects AudioWorld as first argument."));

DELETE((AudioWorld*)F->data);
}SV AudioWorld_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioWorld's constructor" EAOE));
if(!TS(a[0],AudioWorld))
CATE(TE,"AudioWorld's constructor expects AudioWorld as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(AudioWorld_funcs,NEW(AudioWorld),EXT->AudioWorld_typeID);
CATE(TE,UFOF("AudioWorld's constructor.")));
R CN;
}

SV AudioWorld_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("AudioWorld");
EI(keyStr=="__new__")
R CNF(AudioWorld_new);
EI(keyStr=="__call__")
R CNF(AudioWorld_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(AudioWorld_new);
 EI(keyStr == "createSource")
R CNF(AudioWorld_createSource);
 EI(keyStr == "destroySource")
R CNF(AudioWorld_destroySource);
 EI(keyStr == "clearSources")
R CNF(AudioWorld_clearSources);
 EI(keyStr == "getSources")
R CNF(AudioWorld_getSources);
 EI(keyStr == "addToAudioDevice")
R CNF(AudioWorld_addToAudioDevice);
 EI(keyStr == "removeFromAudioDevice")
R CNF(AudioWorld_removeFromAudioDevice);
 EI(keyStr=="listenerVelocity")
{
AudioWorld*obj=(AudioWorld*)F->data;
R CV(obj->listenerVelocity);
} EI(keyStr=="dopplerFactor")
{
AudioWorld*obj=(AudioWorld*)F->data;
R CV(obj->dopplerFactor);
} EI(keyStr=="listenerPosition")
{
AudioWorld*obj=(AudioWorld*)F->data;
R CV(obj->listenerPosition);
} EI(keyStr=="speedOfSound")
{
AudioWorld*obj=(AudioWorld*)F->data;
R CV(obj->speedOfSound);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void AudioWorld_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="listenerVelocity")
{
AudioWorld*obj=(AudioWorld*)F->data;
obj->listenerVelocity=val_to_c<decltype(obj->listenerVelocity)>::f(ctx,value);
} EI(keyStr=="dopplerFactor")
{
AudioWorld*obj=(AudioWorld*)F->data;
obj->dopplerFactor=val_to_c<decltype(obj->dopplerFactor)>::f(ctx,value);
} EI(keyStr=="listenerPosition")
{
AudioWorld*obj=(AudioWorld*)F->data;
obj->listenerPosition=val_to_c<decltype(obj->listenerPosition)>::f(ctx,value);
} EI(keyStr=="speedOfSound")
{
AudioWorld*obj=(AudioWorld*)F->data;
obj->speedOfSound=val_to_c<decltype(obj->speedOfSound)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV AudioWorld_destroySource(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioWorld::destroySource" EAOE));
AudioWorld*F;
if(!TS(a[0],AudioWorld))
CATE(TE,FAE("AudioWorld::destroySource","AudioWorld")));
else
 F=(AudioWorld*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],AudioSource *))
{
( F->destroySource(val_to_c<AudioSource *>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("AudioWorld::destroySource.")));
R CN;
}

SV AudioWorld_getSources(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioWorld::getSources" EAOE));
AudioWorld*F;
if(!TS(a[0],AudioWorld))
CATE(TE,FAE("AudioWorld::getSources","AudioWorld")));
else
 F=(AudioWorld*)((NO)a[0])->data;

CATE(TE,UFOF("AudioWorld::getSources.")));
R CN;
}

SV AudioWorld_addToAudioDevice(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioWorld::addToAudioDevice" EAOE));
AudioWorld*F;
if(!TS(a[0],AudioWorld))
CATE(TE,FAE("AudioWorld::addToAudioDevice","AudioWorld")));
else
 F=(AudioWorld*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],AudioDevice *))
{
( F->addToAudioDevice(val_to_c<AudioDevice *>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("AudioWorld::addToAudioDevice.")));
R CN;
}

SV AudioWorld_createSource(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioWorld::createSource" EAOE));
AudioWorld*F;
if(!TS(a[0],AudioWorld))
CATE(TE,FAE("AudioWorld::createSource","AudioWorld")));
else
 F=(AudioWorld*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],Audio *))
{
R CV( F->createSource(val_to_c<Audio *>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("AudioWorld::createSource.")));
R CN;
}

SV AudioWorld_removeFromAudioDevice(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioWorld::removeFromAudioDevice" EAOE));
AudioWorld*F;
if(!TS(a[0],AudioWorld))
CATE(TE,FAE("AudioWorld::removeFromAudioDevice","AudioWorld")));
else
 F=(AudioWorld*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],AudioDevice *))
{
( F->removeFromAudioDevice(val_to_c<AudioDevice *>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("AudioWorld::removeFromAudioDevice.")));
R CN;
}

SV AudioWorld_clearSources(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioWorld::clearSources" EAOE));
AudioWorld*F;
if(!TS(a[0],AudioWorld))
CATE(TE,FAE("AudioWorld::clearSources","AudioWorld")));
else
 F=(AudioWorld*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->clearSources());
R CN;
}
CATE(TE,UFOF("AudioWorld::clearSources.")));
R CN;
}

void StrStrMap_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,HashMap<String,String>))
CATE(TE,"StrStrMap::__del__ expects StrStrMap as first argument."));

DELETE((HashMap<String,String>*)F->data);
}SV StrStrMap_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"StrStrMap's constructor" EAOE));
if(!TS(a[0],HashMap<String,String>))
CATE(TE,"StrStrMap's constructor expects StrStrMap as first argument."));
#define fjis HashMap<String,String>
R S::createNativeObject(StrStrMap_funcs,NEW(fjis),EXT->StrStrMap_typeID);
}

SV StrStrMap_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("StrStrMap");
EI(keyStr=="__new__")
R CNF(StrStrMap_new);
EI(keyStr=="__call__")
R CNF(StrStrMap_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(StrStrMap_new);
 EI(keyStr == "__eq__")
R CNF(StrStrMap___eq__);
 EI(keyStr == "__neq__")
R CNF(StrStrMap___neq__);
 EI(keyStr == "getEntryCount")
R CNF(StrStrMap_getEntryCount);
 EI(keyStr == "findEntry")
R CNF(StrStrMap_findEntry);
 EI(keyStr == "getKey")
R CNF(StrStrMap_getKey);
 EI(keyStr == "getValue")
R CNF(StrStrMap_getValue);
 EI(keyStr == "getKeyHash")
R CNF(StrStrMap_getKeyHash);
 EI(keyStr == "get")
R CNF(StrStrMap_get);
 EI(keyStr == "set")
R CNF(StrStrMap_set);
 EI(keyStr == "removeEntry")
R CNF(StrStrMap_removeEntry);
 EI(keyStr == "remove")
R CNF(StrStrMap_remove);
 EI(keyStr == "clear")
R CNF(StrStrMap_clear);
 EI(keyStr == "append")
R CNF(StrStrMap_append);
 else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void StrStrMap_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV StrStrMap_removeEntry(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"StrStrMap::removeEntry" EAOE));
HashMap<String,String>*F;
if(!TS(a[0],HashMap<String,String>))
CATE(TE,FAE("StrStrMap::removeEntry","StrStrMap")));
else
 F=(HashMap<String,String>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],int))
{
( F->removeEntry(val_to_c<int>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("StrStrMap::removeEntry.")));
R CN;
}

SV StrStrMap_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"StrStrMap::set" EAOE));
HashMap<String,String>*F;
if(!TS(a[0],HashMap<String,String>))
CATE(TE,FAE("StrStrMap::set","StrStrMap")));
else
 F=(HashMap<String,String>*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],const String&)&&TS(a[2],const String&))
{
R CV( F->set(val_to_c<const String&>::f(ctx,a[1]), val_to_c<const String&>::f(ctx,a[2])));
;
}
CATE(TE,UFOF("StrStrMap::set.")));
R CN;
}

SV StrStrMap_get(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"StrStrMap::get" EAOE));
HashMap<String,String>*F;
if(!TS(a[0],HashMap<String,String>))
CATE(TE,FAE("StrStrMap::get","StrStrMap")));
else
 F=(HashMap<String,String>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const String&))
{
R CV( F->get(val_to_c<const String&>::f(ctx,a[1])));
;
}
if(a.getCount()==2)
if(1&&TS(a[1],const String&))
{
R CV( F->get(val_to_c<const String&>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("StrStrMap::get.")));
R CN;
}

SV StrStrMap_getEntryCount(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"StrStrMap::getEntryCount" EAOE));
HashMap<String,String>*F;
if(!TS(a[0],HashMap<String,String>))
CATE(TE,FAE("StrStrMap::getEntryCount","StrStrMap")));
else
 F=(HashMap<String,String>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getEntryCount());
;
}
CATE(TE,UFOF("StrStrMap::getEntryCount.")));
R CN;
}

SV StrStrMap_clear(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"StrStrMap::clear" EAOE));
HashMap<String,String>*F;
if(!TS(a[0],HashMap<String,String>))
CATE(TE,FAE("StrStrMap::clear","StrStrMap")));
else
 F=(HashMap<String,String>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->clear());
R CN;
}
CATE(TE,UFOF("StrStrMap::clear.")));
R CN;
}

SV StrStrMap_remove(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"StrStrMap::remove" EAOE));
HashMap<String,String>*F;
if(!TS(a[0],HashMap<String,String>))
CATE(TE,FAE("StrStrMap::remove","StrStrMap")));
else
 F=(HashMap<String,String>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const String&))
{
( F->remove(val_to_c<const String&>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("StrStrMap::remove.")));
R CN;
}

SV StrStrMap_getValue(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"StrStrMap::getValue" EAOE));
HashMap<String,String>*F;
if(!TS(a[0],HashMap<String,String>))
CATE(TE,FAE("StrStrMap::getValue","StrStrMap")));
else
 F=(HashMap<String,String>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getValue(val_to_c<size_t>::f(ctx,a[1])));
;
}
if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getValue(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("StrStrMap::getValue.")));
R CN;
}

SV StrStrMap_getKeyHash(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"StrStrMap::getKeyHash" EAOE));
HashMap<String,String>*F;
if(!TS(a[0],HashMap<String,String>))
CATE(TE,FAE("StrStrMap::getKeyHash","StrStrMap")));
else
 F=(HashMap<String,String>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getKeyHash(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("StrStrMap::getKeyHash.")));
R CN;
}

SV StrStrMap_append(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"StrStrMap::append" EAOE));
HashMap<String,String>*F;
if(!TS(a[0],HashMap<String,String>))
CATE(TE,FAE("StrStrMap::append","StrStrMap")));
else
 F=(HashMap<String,String>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const HashMap<String, String> &))
{
( F->append(val_to_c<const HashMap<String, String> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("StrStrMap::append.")));
R CN;
}

SV StrStrMap_getKey(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"StrStrMap::getKey" EAOE));
HashMap<String,String>*F;
if(!TS(a[0],HashMap<String,String>))
CATE(TE,FAE("StrStrMap::getKey","StrStrMap")));
else
 F=(HashMap<String,String>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getKey(val_to_c<size_t>::f(ctx,a[1])));
;
}
if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getKey(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("StrStrMap::getKey.")));
R CN;
}

SV StrStrMap___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"StrStrMap::__eq__" EAOE));
HashMap<String,String>*F;
if(!TS(a[0],HashMap<String,String>))
CATE(TE,FAE("StrStrMap::__eq__","StrStrMap")));
else
 F=(HashMap<String,String>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const HashMap<String, String> &))
{
auto v=val_to_c<const HashMap<String, String> &>::f(ctx,a[1]);
R CV(*F == v);
}
CATE(TE,UFOF("StrStrMap::__eq__.")));
R CN;
}

SV StrStrMap_findEntry(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"StrStrMap::findEntry" EAOE));
HashMap<String,String>*F;
if(!TS(a[0],HashMap<String,String>))
CATE(TE,FAE("StrStrMap::findEntry","StrStrMap")));
else
 F=(HashMap<String,String>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const String&))
{
R CV( F->findEntry(val_to_c<const String&>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("StrStrMap::findEntry.")));
R CN;
}

SV StrStrMap___neq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"StrStrMap::__neq__" EAOE));
HashMap<String,String>*F;
if(!TS(a[0],HashMap<String,String>))
CATE(TE,FAE("StrStrMap::__neq__","StrStrMap")));
else
 F=(HashMap<String,String>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const HashMap<String, String> &))
{
auto v=val_to_c<const HashMap<String, String> &>::f(ctx,a[1]);
R CV(*F != v);
}
CATE(TE,UFOF("StrStrMap::__neq__.")));
R CN;
}

void Light_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,Light))
CATE(TE,"Light::__del__ expects Light as first argument."));

DELETE((Light*)F->data);
}SV Light_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Light's constructor" EAOE));
if(!TS(a[0],Light))
CATE(TE,"Light's constructor expects Light as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Light_funcs,NEW(Light),EXT->Light_typeID);
CATE(TE,UFOF("Light's constructor.")));
R CN;
}

SV Light_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Light");
EI(keyStr=="__new__")
R CNF(Light_new);
EI(keyStr=="__call__")
R CNF(Light_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(Light_new);
 EI(keyStr == "addShadowmap")
R CNF(Light_addShadowmap);
 EI(keyStr == "removeShadowmap")
R CNF(Light_removeShadowmap);
 EI(keyStr == "getShadowmap")
R CNF(Light_getShadowmap);
 EI(keyStr == "getShadowmapFramebuffer")
R CNF(Light_getShadowmapFramebuffer);
 EI(keyStr == "getPointLightFramebuffers")
R CNF(Light_getPointLightFramebuffers);
 EI(keyStr == "getShadowmapResolution")
R CNF(Light_getShadowmapResolution);
 EI(keyStr == "getShadowmapPrecision")
R CNF(Light_getShadowmapPrecision);
 EI(keyStr == "updateMatrices")
R CNF(Light_updateMatrices);
 EI(keyStr == "getViewMatrix")
R CNF(Light_getViewMatrix);
 EI(keyStr == "getProjectionMatrix")
R CNF(Light_getProjectionMatrix);
 EI(keyStr=="type")
{
Light*obj=(Light*)F->data;
R CV(obj->type);
} EI(keyStr=="power")
{
Light*obj=(Light*)F->data;
R CV(obj->power);
} EI(keyStr=="color")
{
Light*obj=(Light*)F->data;
R CV(obj->color);
} EI(keyStr=="ambientStrength")
{
Light*obj=(Light*)F->data;
R CV(obj->ambientStrength);
} EI(keyStr=="shadowmapNear")
{
Light*obj=(Light*)F->data;
R CV(obj->shadowmapNear);
} EI(keyStr=="shadowmapFar")
{
Light*obj=(Light*)F->data;
R CV(obj->shadowmapFar);
} EI(keyStr=="shadowMinBias")
{
Light*obj=(Light*)F->data;
R CV(obj->shadowMinBias);
} EI(keyStr=="shadowBiasScale")
{
Light*obj=(Light*)F->data;
R CV(obj->shadowBiasScale);
} EI(keyStr=="shadowAutoBiasScale")
{
Light*obj=(Light*)F->data;
R CV(obj->shadowAutoBiasScale);
} EI(keyStr=="scriptOwned")
{
Light*obj=(Light*)F->data;
R CV(obj->scriptOwned);
} EI(keyStr=="direction")
{
Light*obj=(Light*)F->data;
R CV(obj->direction);
} EI(keyStr=="spot")
{
Light*obj=(Light*)F->data;
R CV(obj->spot);
} EI(keyStr=="point")
{
Light*obj=(Light*)F->data;
R CV(obj->point);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void Light_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="type")
{
Light*obj=(Light*)F->data;
obj->type=val_to_c<decltype(obj->type)>::f(ctx,value);
} EI(keyStr=="power")
{
Light*obj=(Light*)F->data;
obj->power=val_to_c<decltype(obj->power)>::f(ctx,value);
} EI(keyStr=="color")
{
Light*obj=(Light*)F->data;
obj->color=val_to_c<decltype(obj->color)>::f(ctx,value);
} EI(keyStr=="ambientStrength")
{
Light*obj=(Light*)F->data;
obj->ambientStrength=val_to_c<decltype(obj->ambientStrength)>::f(ctx,value);
} EI(keyStr=="shadowmapNear")
{
Light*obj=(Light*)F->data;
obj->shadowmapNear=val_to_c<decltype(obj->shadowmapNear)>::f(ctx,value);
} EI(keyStr=="shadowmapFar")
{
Light*obj=(Light*)F->data;
obj->shadowmapFar=val_to_c<decltype(obj->shadowmapFar)>::f(ctx,value);
} EI(keyStr=="shadowMinBias")
{
Light*obj=(Light*)F->data;
obj->shadowMinBias=val_to_c<decltype(obj->shadowMinBias)>::f(ctx,value);
} EI(keyStr=="shadowBiasScale")
{
Light*obj=(Light*)F->data;
obj->shadowBiasScale=val_to_c<decltype(obj->shadowBiasScale)>::f(ctx,value);
} EI(keyStr=="shadowAutoBiasScale")
{
Light*obj=(Light*)F->data;
obj->shadowAutoBiasScale=val_to_c<decltype(obj->shadowAutoBiasScale)>::f(ctx,value);
} EI(keyStr=="scriptOwned")
{
Light*obj=(Light*)F->data;
obj->scriptOwned=val_to_c<decltype(obj->scriptOwned)>::f(ctx,value);
} EI(keyStr=="direction")
{
Light*obj=(Light*)F->data;
obj->direction=val_to_c<decltype(obj->direction)>::f(ctx,value);
} EI(keyStr=="spot")
{
Light*obj=(Light*)F->data;
obj->spot=val_to_c<decltype(obj->spot)>::f(ctx,value);
} EI(keyStr=="point")
{
Light*obj=(Light*)F->data;
obj->point=val_to_c<decltype(obj->point)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV Light_getShadowmapResolution(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Light::getShadowmapResolution" EAOE));
Light*F;
if(!TS(a[0],Light))
CATE(TE,FAE("Light::getShadowmapResolution","Light")));
else
 F=(Light*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getShadowmapResolution());
;
}
CATE(TE,UFOF("Light::getShadowmapResolution.")));
R CN;
}

SV Light_updateMatrices(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Light::updateMatrices" EAOE));
Light*F;
if(!TS(a[0],Light))
CATE(TE,FAE("Light::updateMatrices","Light")));
else
 F=(Light*)((NO)a[0])->data;

CATE(TE,UFOF("Light::updateMatrices.")));
R CN;
}

SV Light_getShadowmap(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Light::getShadowmap" EAOE));
Light*F;
if(!TS(a[0],Light))
CATE(TE,FAE("Light::getShadowmap","Light")));
else
 F=(Light*)((NO)a[0])->data;

CATE(TE,UFOF("Light::getShadowmap.")));
R CN;
}

SV Light_getViewMatrix(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Light::getViewMatrix" EAOE));
Light*F;
if(!TS(a[0],Light))
CATE(TE,FAE("Light::getViewMatrix","Light")));
else
 F=(Light*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getViewMatrix());
;
}
CATE(TE,UFOF("Light::getViewMatrix.")));
R CN;
}

SV Light_getProjectionMatrix(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Light::getProjectionMatrix" EAOE));
Light*F;
if(!TS(a[0],Light))
CATE(TE,FAE("Light::getProjectionMatrix","Light")));
else
 F=(Light*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getProjectionMatrix());
;
}
CATE(TE,UFOF("Light::getProjectionMatrix.")));
R CN;
}

SV Light_addShadowmap(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Light::addShadowmap" EAOE));
Light*F;
if(!TS(a[0],Light))
CATE(TE,FAE("Light::addShadowmap","Light")));
else
 F=(Light*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],GfxShadowmapPrecision))
{
( F->addShadowmap(val_to_c<size_t>::f(ctx,a[1]), val_to_c<GfxShadowmapPrecision>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("Light::addShadowmap.")));
R CN;
}

SV Light_getShadowmapFramebuffer(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Light::getShadowmapFramebuffer" EAOE));
Light*F;
if(!TS(a[0],Light))
CATE(TE,FAE("Light::getShadowmapFramebuffer","Light")));
else
 F=(Light*)((NO)a[0])->data;

CATE(TE,UFOF("Light::getShadowmapFramebuffer.")));
R CN;
}

SV Light_getShadowmapPrecision(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Light::getShadowmapPrecision" EAOE));
Light*F;
if(!TS(a[0],Light))
CATE(TE,FAE("Light::getShadowmapPrecision","Light")));
else
 F=(Light*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getShadowmapPrecision());
;
}
CATE(TE,UFOF("Light::getShadowmapPrecision.")));
R CN;
}

SV Light_getPointLightFramebuffers(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Light::getPointLightFramebuffers" EAOE));
Light*F;
if(!TS(a[0],Light))
CATE(TE,FAE("Light::getPointLightFramebuffers","Light")));
else
 F=(Light*)((NO)a[0])->data;

CATE(TE,UFOF("Light::getPointLightFramebuffers.")));
R CN;
}

SV Light_removeShadowmap(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Light::removeShadowmap" EAOE));
Light*F;
if(!TS(a[0],Light))
CATE(TE,FAE("Light::removeShadowmap","Light")));
else
 F=(Light*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->removeShadowmap());
R CN;
}
CATE(TE,UFOF("Light::removeShadowmap.")));
R CN;
}

void LightPointData_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,LightPointData))
CATE(TE,"LightPointData::__del__ expects LightPointData as first argument."));

DELETE((LightPointData*)F->data);
}SV LightPointData_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"LightPointData's constructor" EAOE));
if(!TS(a[0],LightPointData))
CATE(TE,"LightPointData's constructor expects LightPointData as first argument."));
#define fjis LightPointData
R S::createNativeObject(LightPointData_funcs,NEW(fjis),EXT->LightPointData_typeID);
}

SV LightPointData_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("LightPointData");
EI(keyStr=="__new__")
R CNF(LightPointData_new);
EI(keyStr=="__call__")
R CNF(LightPointData_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(LightPointData_new);
 EI(keyStr=="position")
{
LightPointData*obj=(LightPointData*)F->data;
R CV(obj->position);
} EI(keyStr=="radius")
{
LightPointData*obj=(LightPointData*)F->data;
R CV(obj->radius);
} EI(keyStr=="singlePassShadowMap")
{
LightPointData*obj=(LightPointData*)F->data;
R CV(obj->singlePassShadowMap);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void LightPointData_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="position")
{
LightPointData*obj=(LightPointData*)F->data;
obj->position=val_to_c<decltype(obj->position)>::f(ctx,value);
} EI(keyStr=="radius")
{
LightPointData*obj=(LightPointData*)F->data;
obj->radius=val_to_c<decltype(obj->radius)>::f(ctx,value);
} EI(keyStr=="singlePassShadowMap")
{
LightPointData*obj=(LightPointData*)F->data;
obj->singlePassShadowMap=val_to_c<decltype(obj->singlePassShadowMap)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

void Float4_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,T4<float>))
CATE(TE,"Float4::__del__ expects Float4 as first argument."));

DELETE((T4<float>*)F->data);
}SV Float4_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4's constructor" EAOE));
if(!TS(a[0],T4<float>))
CATE(TE,"Float4's constructor expects Float4 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Float4_funcs,NEW(T4<float>),EXT->Float4_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],float))
R S::createNativeObject(Float4_funcs,NEW(T4<float>,val_to_c<float>::f(ctx,a[1])),EXT->Float4_typeID);
if(a.getCount()==5)
if(true&&TS(a[1],float)&&TS(a[2],float)&&TS(a[3],float)&&TS(a[4],float))
R S::createNativeObject(Float4_funcs,NEW(T4<float>,val_to_c<float>::f(ctx,a[1]),val_to_c<float>::f(ctx,a[2]),val_to_c<float>::f(ctx,a[3]),val_to_c<float>::f(ctx,a[4])),EXT->Float4_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T4<float> &))
R S::createNativeObject(Float4_funcs,NEW(T4<float>,val_to_c<const T4<float> &>::f(ctx,a[1])),EXT->Float4_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T4<int32_t> &))
R S::createNativeObject(Float4_funcs,NEW(T4<float>,val_to_c<const T4<int32_t> &>::f(ctx,a[1])),EXT->Float4_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T4<uint32_t> &))
R S::createNativeObject(Float4_funcs,NEW(T4<float>,val_to_c<const T4<uint32_t> &>::f(ctx,a[1])),EXT->Float4_typeID);
CATE(TE,UFOF("Float4's constructor.")));
R CN;
}

SV Float4_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Float4");
EI(keyStr=="__new__")
R CNF(Float4_new);
EI(keyStr=="__call__")
R CNF(Float4_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(Float4_new);
 EI(keyStr == "__add__")
R CNF(Float4___add__);
 EI(keyStr == "__sub__")
R CNF(Float4___sub__);
 EI(keyStr == "__mul__")
R CNF(Float4___mul__);
 EI(keyStr == "__div__")
R CNF(Float4___div__);
 EI(keyStr == "__eq__")
R CNF(Float4___eq__);
 EI(keyStr == "__neq__")
R CNF(Float4___neq__);
 EI(keyStr == "__less__")
R CNF(Float4___less__);
 EI(keyStr == "__grtr__")
R CNF(Float4___grtr__);
 EI(keyStr == "__leq__")
R CNF(Float4___leq__);
 EI(keyStr == "__geq__")
R CNF(Float4___geq__);
 EI(keyStr == "sum")
R CNF(Float4_sum);
 EI(keyStr == "length")
R CNF(Float4_length);
 EI(keyStr == "lengthSquared")
R CNF(Float4_lengthSquared);
 EI(keyStr == "dot")
R CNF(Float4_dot);
 EI(keyStr == "distance")
R CNF(Float4_distance);
 EI(keyStr == "distanceSquared")
R CNF(Float4_distanceSquared);
 EI(keyStr == "normalize")
R CNF(Float4_normalize);
 EI(keyStr == "getXY")
R CNF(Float4_getXY);
 EI(keyStr == "setXY")
R CNF(Float4_setXY);
 EI(keyStr == "getXZ")
R CNF(Float4_getXZ);
 EI(keyStr == "setXZ")
R CNF(Float4_setXZ);
 EI(keyStr == "getXW")
R CNF(Float4_getXW);
 EI(keyStr == "setXW")
R CNF(Float4_setXW);
 EI(keyStr == "getYX")
R CNF(Float4_getYX);
 EI(keyStr == "setYX")
R CNF(Float4_setYX);
 EI(keyStr == "getYZ")
R CNF(Float4_getYZ);
 EI(keyStr == "setYZ")
R CNF(Float4_setYZ);
 EI(keyStr == "getYW")
R CNF(Float4_getYW);
 EI(keyStr == "setYW")
R CNF(Float4_setYW);
 EI(keyStr == "getZX")
R CNF(Float4_getZX);
 EI(keyStr == "setZX")
R CNF(Float4_setZX);
 EI(keyStr == "getZY")
R CNF(Float4_getZY);
 EI(keyStr == "setZY")
R CNF(Float4_setZY);
 EI(keyStr == "getZW")
R CNF(Float4_getZW);
 EI(keyStr == "setZW")
R CNF(Float4_setZW);
 EI(keyStr == "getWX")
R CNF(Float4_getWX);
 EI(keyStr == "setWX")
R CNF(Float4_setWX);
 EI(keyStr == "getWY")
R CNF(Float4_getWY);
 EI(keyStr == "setWY")
R CNF(Float4_setWY);
 EI(keyStr == "getWZ")
R CNF(Float4_getWZ);
 EI(keyStr == "setWZ")
R CNF(Float4_setWZ);
 EI(keyStr == "getXYZ")
R CNF(Float4_getXYZ);
 EI(keyStr == "setXYZ")
R CNF(Float4_setXYZ);
 EI(keyStr == "getXYW")
R CNF(Float4_getXYW);
 EI(keyStr == "setXYW")
R CNF(Float4_setXYW);
 EI(keyStr == "getXZY")
R CNF(Float4_getXZY);
 EI(keyStr == "setXZY")
R CNF(Float4_setXZY);
 EI(keyStr == "getXZW")
R CNF(Float4_getXZW);
 EI(keyStr == "setXZW")
R CNF(Float4_setXZW);
 EI(keyStr == "getXWZ")
R CNF(Float4_getXWZ);
 EI(keyStr == "setXWZ")
R CNF(Float4_setXWZ);
 EI(keyStr == "getXWY")
R CNF(Float4_getXWY);
 EI(keyStr == "setXWY")
R CNF(Float4_setXWY);
 EI(keyStr == "getYXZ")
R CNF(Float4_getYXZ);
 EI(keyStr == "setYXZ")
R CNF(Float4_setYXZ);
 EI(keyStr == "getYXW")
R CNF(Float4_getYXW);
 EI(keyStr == "setYXW")
R CNF(Float4_setYXW);
 EI(keyStr == "getYZX")
R CNF(Float4_getYZX);
 EI(keyStr == "setYZX")
R CNF(Float4_setYZX);
 EI(keyStr == "getYZW")
R CNF(Float4_getYZW);
 EI(keyStr == "setYZW")
R CNF(Float4_setYZW);
 EI(keyStr == "getYWZ")
R CNF(Float4_getYWZ);
 EI(keyStr == "setYWZ")
R CNF(Float4_setYWZ);
 EI(keyStr == "getYWX")
R CNF(Float4_getYWX);
 EI(keyStr == "setYWX")
R CNF(Float4_setYWX);
 EI(keyStr == "getZXY")
R CNF(Float4_getZXY);
 EI(keyStr == "setZXY")
R CNF(Float4_setZXY);
 EI(keyStr == "getZXW")
R CNF(Float4_getZXW);
 EI(keyStr == "setZXW")
R CNF(Float4_setZXW);
 EI(keyStr == "getZYX")
R CNF(Float4_getZYX);
 EI(keyStr == "setZYX")
R CNF(Float4_setZYX);
 EI(keyStr == "getZYW")
R CNF(Float4_getZYW);
 EI(keyStr == "setZYW")
R CNF(Float4_setZYW);
 EI(keyStr == "getZWY")
R CNF(Float4_getZWY);
 EI(keyStr == "setZWY")
R CNF(Float4_setZWY);
 EI(keyStr == "getZWX")
R CNF(Float4_getZWX);
 EI(keyStr == "setZWX")
R CNF(Float4_setZWX);
 EI(keyStr == "getWXY")
R CNF(Float4_getWXY);
 EI(keyStr == "setWXY")
R CNF(Float4_setWXY);
 EI(keyStr == "getWXZ")
R CNF(Float4_getWXZ);
 EI(keyStr == "setWXZ")
R CNF(Float4_setWXZ);
 EI(keyStr == "getWYX")
R CNF(Float4_getWYX);
 EI(keyStr == "setWYX")
R CNF(Float4_setWYX);
 EI(keyStr == "getWYZ")
R CNF(Float4_getWYZ);
 EI(keyStr == "setWYZ")
R CNF(Float4_setWYZ);
 EI(keyStr == "getWZY")
R CNF(Float4_getWZY);
 EI(keyStr == "setWZY")
R CNF(Float4_setWZY);
 EI(keyStr == "getWZX")
R CNF(Float4_getWZX);
 EI(keyStr == "setWZX")
R CNF(Float4_setWZX);
 EI(keyStr == "getXYZW")
R CNF(Float4_getXYZW);
 EI(keyStr == "setXYZW")
R CNF(Float4_setXYZW);
 EI(keyStr == "getXYWZ")
R CNF(Float4_getXYWZ);
 EI(keyStr == "setXYWZ")
R CNF(Float4_setXYWZ);
 EI(keyStr == "getXZYW")
R CNF(Float4_getXZYW);
 EI(keyStr == "setXZYW")
R CNF(Float4_setXZYW);
 EI(keyStr == "getXZWY")
R CNF(Float4_getXZWY);
 EI(keyStr == "setXZWY")
R CNF(Float4_setXZWY);
 EI(keyStr == "getXWZY")
R CNF(Float4_getXWZY);
 EI(keyStr == "setXWZY")
R CNF(Float4_setXWZY);
 EI(keyStr == "getXWYZ")
R CNF(Float4_getXWYZ);
 EI(keyStr == "setXWYZ")
R CNF(Float4_setXWYZ);
 EI(keyStr == "getYXZW")
R CNF(Float4_getYXZW);
 EI(keyStr == "setYXZW")
R CNF(Float4_setYXZW);
 EI(keyStr == "getYXWZ")
R CNF(Float4_getYXWZ);
 EI(keyStr == "setYXWZ")
R CNF(Float4_setYXWZ);
 EI(keyStr == "getYZXW")
R CNF(Float4_getYZXW);
 EI(keyStr == "setYZXW")
R CNF(Float4_setYZXW);
 EI(keyStr == "getYZWX")
R CNF(Float4_getYZWX);
 EI(keyStr == "setYZWX")
R CNF(Float4_setYZWX);
 EI(keyStr == "getYWZX")
R CNF(Float4_getYWZX);
 EI(keyStr == "setYWZX")
R CNF(Float4_setYWZX);
 EI(keyStr == "getYWXZ")
R CNF(Float4_getYWXZ);
 EI(keyStr == "setYWXZ")
R CNF(Float4_setYWXZ);
 EI(keyStr == "getZYXW")
R CNF(Float4_getZYXW);
 EI(keyStr == "setZYXW")
R CNF(Float4_setZYXW);
 EI(keyStr == "getZYWX")
R CNF(Float4_getZYWX);
 EI(keyStr == "setZYWX")
R CNF(Float4_setZYWX);
 EI(keyStr == "getZXYW")
R CNF(Float4_getZXYW);
 EI(keyStr == "setZXYW")
R CNF(Float4_setZXYW);
 EI(keyStr == "getZXWY")
R CNF(Float4_getZXWY);
 EI(keyStr == "setZXWY")
R CNF(Float4_setZXWY);
 EI(keyStr == "getZWXY")
R CNF(Float4_getZWXY);
 EI(keyStr == "setZWXY")
R CNF(Float4_setZWXY);
 EI(keyStr == "getZWYX")
R CNF(Float4_getZWYX);
 EI(keyStr == "setZWYX")
R CNF(Float4_setZWYX);
 EI(keyStr == "getWYZX")
R CNF(Float4_getWYZX);
 EI(keyStr == "setWYZX")
R CNF(Float4_setWYZX);
 EI(keyStr == "getWYXZ")
R CNF(Float4_getWYXZ);
 EI(keyStr == "setWYXZ")
R CNF(Float4_setWYXZ);
 EI(keyStr == "getWZYX")
R CNF(Float4_getWZYX);
 EI(keyStr == "setWZYX")
R CNF(Float4_setWZYX);
 EI(keyStr == "getWZXY")
R CNF(Float4_getWZXY);
 EI(keyStr == "setWZXY")
R CNF(Float4_setWZXY);
 EI(keyStr == "getWXZY")
R CNF(Float4_getWXZY);
 EI(keyStr == "setWXZY")
R CNF(Float4_setWXZY);
 EI(keyStr == "getWXYZ")
R CNF(Float4_getWXYZ);
 EI(keyStr == "setWXYZ")
R CNF(Float4_setWXYZ);
 EI(keyStr=="x")
{
T4<float>*obj=(T4<float>*)F->data;
R CV(obj->x);
} EI(keyStr=="y")
{
T4<float>*obj=(T4<float>*)F->data;
R CV(obj->y);
} EI(keyStr=="z")
{
T4<float>*obj=(T4<float>*)F->data;
R CV(obj->z);
} EI(keyStr=="w")
{
T4<float>*obj=(T4<float>*)F->data;
R CV(obj->w);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void Float4_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="x")
{
T4<float>*obj=(T4<float>*)F->data;
obj->x=val_to_c<decltype(obj->x)>::f(ctx,value);
} EI(keyStr=="y")
{
T4<float>*obj=(T4<float>*)F->data;
obj->y=val_to_c<decltype(obj->y)>::f(ctx,value);
} EI(keyStr=="z")
{
T4<float>*obj=(T4<float>*)F->data;
obj->z=val_to_c<decltype(obj->z)>::f(ctx,value);
} EI(keyStr=="w")
{
T4<float>*obj=(T4<float>*)F->data;
obj->w=val_to_c<decltype(obj->w)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV Float4_setZXYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setZXYW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setZXYW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setZXYW(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setZXYW.")));
R CN;
}

SV Float4_setWYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setWYZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setWYZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setWYZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setWYZ.")));
R CN;
}

SV Float4_setWYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setWYX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setWYX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setWYX(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setWYX.")));
R CN;
}

SV Float4_getZWYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getZWYX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getZWYX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZWYX());
;
}
CATE(TE,UFOF("Float4::getZWYX.")));
R CN;
}

SV Float4_getZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getZW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getZW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZW());
;
}
CATE(TE,UFOF("Float4::getZW.")));
R CN;
}

SV Float4_getZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getZY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getZY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZY());
;
}
CATE(TE,UFOF("Float4::getZY.")));
R CN;
}

SV Float4_distanceSquared(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::distanceSquared" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::distanceSquared","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
R CV( F->distanceSquared(val_to_c<const T4<float> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Float4::distanceSquared.")));
R CN;
}

SV Float4_getYXZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getYXZW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getYXZW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYXZW());
;
}
CATE(TE,UFOF("Float4::getYXZW.")));
R CN;
}

SV Float4_setYZWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setYZWX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setYZWX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setYZWX(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setYZWX.")));
R CN;
}

SV Float4_getYWZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getYWZX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getYWZX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYWZX());
;
}
CATE(TE,UFOF("Float4::getYWZX.")));
R CN;
}

SV Float4_getWZXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getWZXY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getWZXY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWZXY());
;
}
CATE(TE,UFOF("Float4::getWZXY.")));
R CN;
}

SV Float4_getZYXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getZYXW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getZYXW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZYXW());
;
}
CATE(TE,UFOF("Float4::getZYXW.")));
R CN;
}

SV Float4_setXWYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setXWYZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setXWYZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setXWYZ(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setXWYZ.")));
R CN;
}

SV Float4_setZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setZY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setZY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
( F->setZY(val_to_c<const T2<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setZY.")));
R CN;
}

SV Float4_setZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setZX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setZX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
( F->setZX(val_to_c<const T2<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setZX.")));
R CN;
}

SV Float4_getZXWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getZXWY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getZXWY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZXWY());
;
}
CATE(TE,UFOF("Float4::getZXWY.")));
R CN;
}

SV Float4_getXWZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getXWZY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getXWZY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXWZY());
;
}
CATE(TE,UFOF("Float4::getXWZY.")));
R CN;
}

SV Float4_setZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setZW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setZW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
( F->setZW(val_to_c<const T2<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setZW.")));
R CN;
}

SV Float4_setZYWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setZYWX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setZYWX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setZYWX(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setZYWX.")));
R CN;
}

SV Float4_getYZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getYZX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getYZX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYZX());
;
}
CATE(TE,UFOF("Float4::getYZX.")));
R CN;
}

SV Float4_getXYWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getXYWZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getXYWZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXYWZ());
;
}
CATE(TE,UFOF("Float4::getXYWZ.")));
R CN;
}

SV Float4_setYXZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setYXZW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setYXZW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setYXZW(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setYXZW.")));
R CN;
}

SV Float4_getWZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getWZY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getWZY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWZY());
;
}
CATE(TE,UFOF("Float4::getWZY.")));
R CN;
}

SV Float4_getWZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getWZX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getWZX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWZX());
;
}
CATE(TE,UFOF("Float4::getWZX.")));
R CN;
}

SV Float4_getWZYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getWZYX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getWZYX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWZYX());
;
}
CATE(TE,UFOF("Float4::getWZYX.")));
R CN;
}

SV Float4_setXWZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setXWZY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setXWZY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setXWZY(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setXWZY.")));
R CN;
}

SV Float4_getZXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getZXY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getZXY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZXY());
;
}
CATE(TE,UFOF("Float4::getZXY.")));
R CN;
}

SV Float4_setWZYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setWZYX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setWZYX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setWZYX(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setWZYX.")));
R CN;
}

SV Float4_setZYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setZYW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setZYW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setZYW(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setZYW.")));
R CN;
}

SV Float4_setZYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setZYX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setZYX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setZYX(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setZYX.")));
R CN;
}

SV Float4_setXZYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setXZYW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setXZYW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setXZYW(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setXZYW.")));
R CN;
}

SV Float4_getZXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getZXW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getZXW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZXW());
;
}
CATE(TE,UFOF("Float4::getZXW.")));
R CN;
}

SV Float4_setYZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setYZW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setYZW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setYZW(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setYZW.")));
R CN;
}

SV Float4_getYWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getYWZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getYWZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYWZ());
;
}
CATE(TE,UFOF("Float4::getYWZ.")));
R CN;
}

SV Float4___leq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::__leq__" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::__leq__","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
auto v=val_to_c<const T4<float> &>::f(ctx,a[1]);
R CV(*F <= v);
}
CATE(TE,UFOF("Float4::__leq__.")));
R CN;
}

SV Float4_getYWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getYWX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getYWX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYWX());
;
}
CATE(TE,UFOF("Float4::getYWX.")));
R CN;
}

SV Float4_sum(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::sum" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::sum","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->sum());
;
}
CATE(TE,UFOF("Float4::sum.")));
R CN;
}

SV Float4_setYZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setYZX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setYZX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setYZX(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setYZX.")));
R CN;
}

SV Float4_getXYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getXYZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getXYZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXYZ());
;
}
CATE(TE,UFOF("Float4::getXYZ.")));
R CN;
}

SV Float4_getZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getZX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getZX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZX());
;
}
CATE(TE,UFOF("Float4::getZX.")));
R CN;
}

SV Float4_getXYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getXYW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getXYW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXYW());
;
}
CATE(TE,UFOF("Float4::getXYW.")));
R CN;
}

SV Float4_setYWZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setYWZX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setYWZX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setYWZX(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setYWZX.")));
R CN;
}

SV Float4_setWXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setWXY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setWXY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setWXY(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setWXY.")));
R CN;
}

SV Float4_setWXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setWXZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setWXZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setWXZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setWXZ.")));
R CN;
}

SV Float4_setZXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setZXW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setZXW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setZXW(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setZXW.")));
R CN;
}

SV Float4_getXWYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getXWYZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getXWYZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXWYZ());
;
}
CATE(TE,UFOF("Float4::getXWYZ.")));
R CN;
}

SV Float4_setWYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setWYXZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setWYXZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setWYXZ(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setWYXZ.")));
R CN;
}

SV Float4_setZXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setZXY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setZXY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setZXY(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setZXY.")));
R CN;
}

SV Float4_getXWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getXWY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getXWY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXWY());
;
}
CATE(TE,UFOF("Float4::getXWY.")));
R CN;
}

SV Float4_getYXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getYXW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getYXW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYXW());
;
}
CATE(TE,UFOF("Float4::getYXW.")));
R CN;
}

SV Float4_getYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getYXZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getYXZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYXZ());
;
}
CATE(TE,UFOF("Float4::getYXZ.")));
R CN;
}

SV Float4_setXYWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setXYWZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setXYWZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setXYWZ(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setXYWZ.")));
R CN;
}

SV Float4_length(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::length" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::length","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->length());
;
}
CATE(TE,UFOF("Float4::length.")));
R CN;
}

SV Float4_setWXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setWXZY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setWXZY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setWXZY(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setWXZY.")));
R CN;
}

SV Float4_getYZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getYZW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getYZW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYZW());
;
}
CATE(TE,UFOF("Float4::getYZW.")));
R CN;
}

SV Float4_setXWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setXWZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setXWZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setXWZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setXWZ.")));
R CN;
}

SV Float4_setXWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setXWY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setXWY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setXWY(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setXWY.")));
R CN;
}

SV Float4_getWYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getWYZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getWYZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWYZ());
;
}
CATE(TE,UFOF("Float4::getWYZ.")));
R CN;
}

SV Float4_getWYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getWYX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getWYX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWYX());
;
}
CATE(TE,UFOF("Float4::getWYX.")));
R CN;
}

SV Float4_getZYWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getZYWX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getZYWX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZYWX());
;
}
CATE(TE,UFOF("Float4::getZYWX.")));
R CN;
}

SV Float4_getXYZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getXYZW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getXYZW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXYZW());
;
}
CATE(TE,UFOF("Float4::getXYZW.")));
R CN;
}

SV Float4_setZWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setZWY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setZWY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setZWY(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setZWY.")));
R CN;
}

SV Float4_setZWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setZWX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setZWX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setZWX(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setZWX.")));
R CN;
}

SV Float4_setWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setWX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setWX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
( F->setWX(val_to_c<const T2<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setWX.")));
R CN;
}

SV Float4_setWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setWY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setWY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
( F->setWY(val_to_c<const T2<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setWY.")));
R CN;
}

SV Float4_setWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setWZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setWZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
( F->setWZ(val_to_c<const T2<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setWZ.")));
R CN;
}

SV Float4_getZWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getZWY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getZWY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZWY());
;
}
CATE(TE,UFOF("Float4::getZWY.")));
R CN;
}

SV Float4_getZWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getZWX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getZWX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZWX());
;
}
CATE(TE,UFOF("Float4::getZWX.")));
R CN;
}

SV Float4_setYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setYXZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setYXZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setYXZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setYXZ.")));
R CN;
}

SV Float4_setYXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setYXW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setYXW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setYXW(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setYXW.")));
R CN;
}

SV Float4_getXWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getXWZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getXWZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXWZ());
;
}
CATE(TE,UFOF("Float4::getXWZ.")));
R CN;
}

SV Float4_getXZWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getXZWY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getXZWY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXZWY());
;
}
CATE(TE,UFOF("Float4::getXZWY.")));
R CN;
}

SV Float4___less__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::__less__" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::__less__","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
auto v=val_to_c<const T4<float> &>::f(ctx,a[1]);
R CV(*F < v);
}
CATE(TE,UFOF("Float4::__less__.")));
R CN;
}

SV Float4_getZYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getZYW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getZYW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZYW());
;
}
CATE(TE,UFOF("Float4::getZYW.")));
R CN;
}

SV Float4_setWZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setWZY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setWZY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setWZY(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setWZY.")));
R CN;
}

SV Float4_setWZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setWZX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setWZX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setWZX(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setWZX.")));
R CN;
}

SV Float4_setZYXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setZYXW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setZYXW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setZYXW(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setZYXW.")));
R CN;
}

SV Float4_getYZWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getYZWX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getYZWX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYZWX());
;
}
CATE(TE,UFOF("Float4::getYZWX.")));
R CN;
}

SV Float4_getZYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getZYX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getZYX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZYX());
;
}
CATE(TE,UFOF("Float4::getZYX.")));
R CN;
}

SV Float4_getXZYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getXZYW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getXZYW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXZYW());
;
}
CATE(TE,UFOF("Float4::getXZYW.")));
R CN;
}

SV Float4_setYXWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setYXWZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setYXWZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setYXWZ(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setYXWZ.")));
R CN;
}

SV Float4___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::__eq__" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::__eq__","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
auto v=val_to_c<const T4<float> &>::f(ctx,a[1]);
R CV(*F == v);
}
CATE(TE,UFOF("Float4::__eq__.")));
R CN;
}

SV Float4_getWYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getWYXZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getWYXZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWYXZ());
;
}
CATE(TE,UFOF("Float4::getWYXZ.")));
R CN;
}

SV Float4_distance(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::distance" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::distance","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
R CV( F->distance(val_to_c<const T4<float> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Float4::distance.")));
R CN;
}

SV Float4_getXZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getXZW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getXZW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXZW());
;
}
CATE(TE,UFOF("Float4::getXZW.")));
R CN;
}

SV Float4_setYZXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setYZXW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setYZXW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setYZXW(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setYZXW.")));
R CN;
}

SV Float4_getZWXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getZWXY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getZWXY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZWXY());
;
}
CATE(TE,UFOF("Float4::getZWXY.")));
R CN;
}

SV Float4_getXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getXZY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getXZY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXZY());
;
}
CATE(TE,UFOF("Float4::getXZY.")));
R CN;
}

SV Float4_getYZXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getYZXW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getYZXW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYZXW());
;
}
CATE(TE,UFOF("Float4::getYZXW.")));
R CN;
}

SV Float4_setZWYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setZWYX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setZWYX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setZWYX(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setZWYX.")));
R CN;
}

SV Float4___sub__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::__sub__" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::__sub__","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
auto v=val_to_c<const T4<float> &>::f(ctx,a[1]);
R CV(*F - v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const float&))
{
auto v=val_to_c<const float&>::f(ctx,a[1]);
R CV(*F - v);
}
CATE(TE,UFOF("Float4::__sub__.")));
R CN;
}

SV Float4_getYXWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getYXWZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getYXWZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYXWZ());
;
}
CATE(TE,UFOF("Float4::getYXWZ.")));
R CN;
}

SV Float4_setXZWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setXZWY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setXZWY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setXZWY(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setXZWY.")));
R CN;
}

SV Float4_setYWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setYWZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setYWZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setYWZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setYWZ.")));
R CN;
}

SV Float4_setYWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setYWX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setYWX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setYWX(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setYWX.")));
R CN;
}

SV Float4_setYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setYZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setYZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
( F->setYZ(val_to_c<const T2<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setYZ.")));
R CN;
}

SV Float4_setYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setYX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setYX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
( F->setYX(val_to_c<const T2<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setYX.")));
R CN;
}

SV Float4_setYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setYW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setYW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
( F->setYW(val_to_c<const T2<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setYW.")));
R CN;
}

SV Float4_getWXYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getWXYZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getWXYZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWXYZ());
;
}
CATE(TE,UFOF("Float4::getWXYZ.")));
R CN;
}

SV Float4___neq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::__neq__" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::__neq__","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
auto v=val_to_c<const T4<float> &>::f(ctx,a[1]);
R CV(*F != v);
}
CATE(TE,UFOF("Float4::__neq__.")));
R CN;
}

SV Float4_normalize(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::normalize" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::normalize","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->normalize());
;
}
CATE(TE,UFOF("Float4::normalize.")));
R CN;
}

SV Float4_getYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getYX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getYX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYX());
;
}
CATE(TE,UFOF("Float4::getYX.")));
R CN;
}

SV Float4_setXZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setXZW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setXZW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setXZW(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setXZW.")));
R CN;
}

SV Float4_setXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setXZY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setXZY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setXZY(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setXZY.")));
R CN;
}

SV Float4_setXYZW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setXYZW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setXYZW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setXYZW(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setXYZW.")));
R CN;
}

SV Float4_getYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getYW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getYW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYW());
;
}
CATE(TE,UFOF("Float4::getYW.")));
R CN;
}

SV Float4_setWXYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setWXYZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setWXYZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setWXYZ(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setWXYZ.")));
R CN;
}

SV Float4_getYWXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getYWXZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getYWXZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYWXZ());
;
}
CATE(TE,UFOF("Float4::getYWXZ.")));
R CN;
}

SV Float4___mul__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::__mul__" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::__mul__","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
auto v=val_to_c<const T4<float> &>::f(ctx,a[1]);
R CV(*F * v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const float&))
{
auto v=val_to_c<const float&>::f(ctx,a[1]);
R CV(*F * v);
}
CATE(TE,UFOF("Float4::__mul__.")));
R CN;
}

SV Float4_getYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getYZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getYZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYZ());
;
}
CATE(TE,UFOF("Float4::getYZ.")));
R CN;
}

SV Float4_lengthSquared(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::lengthSquared" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::lengthSquared","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->lengthSquared());
;
}
CATE(TE,UFOF("Float4::lengthSquared.")));
R CN;
}

SV Float4_getWXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getWXY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getWXY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWXY());
;
}
CATE(TE,UFOF("Float4::getWXY.")));
R CN;
}

SV Float4_getWXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getWXZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getWXZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWXZ());
;
}
CATE(TE,UFOF("Float4::getWXZ.")));
R CN;
}

SV Float4_getWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getWX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getWX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWX());
;
}
CATE(TE,UFOF("Float4::getWX.")));
R CN;
}

SV Float4_getWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getWY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getWY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWY());
;
}
CATE(TE,UFOF("Float4::getWY.")));
R CN;
}

SV Float4_getWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getWZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getWZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWZ());
;
}
CATE(TE,UFOF("Float4::getWZ.")));
R CN;
}

SV Float4_setXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setXY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setXY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
( F->setXY(val_to_c<const T2<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setXY.")));
R CN;
}

SV Float4_getZXYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getZXYW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getZXYW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZXYW());
;
}
CATE(TE,UFOF("Float4::getZXYW.")));
R CN;
}

SV Float4___add__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::__add__" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::__add__","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
auto v=val_to_c<const T4<float> &>::f(ctx,a[1]);
R CV(*F + v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const float&))
{
auto v=val_to_c<const float&>::f(ctx,a[1]);
R CV(*F + v);
}
CATE(TE,UFOF("Float4::__add__.")));
R CN;
}

SV Float4_setXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setXZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setXZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
( F->setXZ(val_to_c<const T2<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setXZ.")));
R CN;
}

SV Float4_getWYZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getWYZX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getWYZX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWYZX());
;
}
CATE(TE,UFOF("Float4::getWYZX.")));
R CN;
}

SV Float4_setXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setXW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setXW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<float> &))
{
( F->setXW(val_to_c<const T2<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setXW.")));
R CN;
}

SV Float4_getWXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getWXZY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getWXZY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getWXZY());
;
}
CATE(TE,UFOF("Float4::getWXZY.")));
R CN;
}

SV Float4_getXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getXY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getXY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXY());
;
}
CATE(TE,UFOF("Float4::getXY.")));
R CN;
}

SV Float4_setZXWY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setZXWY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setZXWY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setZXWY(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setZXWY.")));
R CN;
}

SV Float4_setXYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setXYW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setXYW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setXYW(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setXYW.")));
R CN;
}

SV Float4_getXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getXZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getXZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXZ());
;
}
CATE(TE,UFOF("Float4::getXZ.")));
R CN;
}

SV Float4_setWZXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setWZXY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setWZXY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setWZXY(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setWZXY.")));
R CN;
}

SV Float4___grtr__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::__grtr__" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::__grtr__","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
auto v=val_to_c<const T4<float> &>::f(ctx,a[1]);
R CV(*F > v);
}
CATE(TE,UFOF("Float4::__grtr__.")));
R CN;
}

SV Float4_setZWXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setZWXY" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setZWXY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setZWXY(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setZWXY.")));
R CN;
}

SV Float4_getXW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getXW" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::getXW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXW());
;
}
CATE(TE,UFOF("Float4::getXW.")));
R CN;
}

SV Float4_setXYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setXYZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setXYZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<float> &))
{
( F->setXYZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setXYZ.")));
R CN;
}

SV Float4___div__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::__div__" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::__div__","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
auto v=val_to_c<const T4<float> &>::f(ctx,a[1]);
R CV(*F / v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const float&))
{
auto v=val_to_c<const float&>::f(ctx,a[1]);
R CV(*F / v);
}
CATE(TE,UFOF("Float4::__div__.")));
R CN;
}

SV Float4_setWYZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setWYZX" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setWYZX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setWYZX(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setWYZX.")));
R CN;
}

SV Float4_setYWXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setYWXZ" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::setYWXZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
( F->setYWXZ(val_to_c<const T4<float> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Float4::setYWXZ.")));
R CN;
}

SV Float4___geq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::__geq__" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::__geq__","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
auto v=val_to_c<const T4<float> &>::f(ctx,a[1]);
R CV(*F >= v);
}
CATE(TE,UFOF("Float4::__geq__.")));
R CN;
}

SV Float4_dot(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::dot" EAOE));
T4<float>*F;
if(!TS(a[0],T4<float>))
CATE(TE,FAE("Float4::dot","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T4<float> &))
{
R CV( F->dot(val_to_c<const T4<float> &>::f(ctx,a[1])));
;
}
if(a.getCount()==1)
if(1)
{
R CV( F->dot());
;
}
CATE(TE,UFOF("Float4::dot.")));
R CN;
}

void LightDirectionalData_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,LightDirectionalData))
CATE(TE,"LightDirectionalData::__del__ expects LightDirectionalData as first argument."));

DELETE((LightDirectionalData*)F->data);
}SV LightDirectionalData_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"LightDirectionalData's constructor" EAOE));
if(!TS(a[0],LightDirectionalData))
CATE(TE,"LightDirectionalData's constructor expects LightDirectionalData as first argument."));
#define fjis LightDirectionalData
R S::createNativeObject(LightDirectionalData_funcs,NEW(fjis),EXT->LightDirectionalData_typeID);
}

SV LightDirectionalData_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("LightDirectionalData");
EI(keyStr=="__new__")
R CNF(LightDirectionalData_new);
EI(keyStr=="__call__")
R CNF(LightDirectionalData_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(LightDirectionalData_new);
 EI(keyStr=="direction")
{
LightDirectionalData*obj=(LightDirectionalData*)F->data;
R CV(obj->direction);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void LightDirectionalData_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="direction")
{
LightDirectionalData*obj=(LightDirectionalData*)F->data;
obj->direction=val_to_c<decltype(obj->direction)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

void Matrix4x4_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,Matrix4x4))
CATE(TE,"Matrix4x4::__del__ expects Matrix4x4 as first argument."));

DELETE((Matrix4x4*)F->data);
}SV Matrix4x4_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix4x4's constructor" EAOE));
if(!TS(a[0],Matrix4x4))
CATE(TE,"Matrix4x4's constructor expects Matrix4x4 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Matrix4x4_funcs,NEW(Matrix4x4),EXT->Matrix4x4_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const Matrix3x3 &))
R S::createNativeObject(Matrix4x4_funcs,NEW(Matrix4x4,val_to_c<const Matrix3x3 &>::f(ctx,a[1])),EXT->Matrix4x4_typeID);
if(a.getCount()==5)
if(true&&TS(a[1],const Float4 &)&&TS(a[2],const Float4 &)&&TS(a[3],const Float4 &)&&TS(a[4],const Float4 &))
R S::createNativeObject(Matrix4x4_funcs,NEW(Matrix4x4,val_to_c<const Float4 &>::f(ctx,a[1]),val_to_c<const Float4 &>::f(ctx,a[2]),val_to_c<const Float4 &>::f(ctx,a[3]),val_to_c<const Float4 &>::f(ctx,a[4])),EXT->Matrix4x4_typeID);
CATE(TE,UFOF("Matrix4x4's constructor.")));
R CN;
}

SV Matrix4x4_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Matrix4x4");
EI(keyStr=="__new__")
R CNF(Matrix4x4_new);
EI(keyStr=="__call__")
R CNF(Matrix4x4_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(Matrix4x4_new);
 EI(keyStr == "__mul__")
R CNF(Matrix4x4___mul__);
 EI(keyStr == "__div__")
R CNF(Matrix4x4___div__);
 EI(keyStr == "__eq__")
R CNF(Matrix4x4___eq__);
 EI(keyStr == "transpose")
R CNF(Matrix4x4_transpose);
 EI(keyStr == "inverse")
R CNF(Matrix4x4_inverse);
 EI(keyStr == "translate")
R CNF(Matrix4x4_translate);
 EI(keyStr == "scale")
R CNF(Matrix4x4_scale);
 EI(keyStr == "rotate")
R CNF(Matrix4x4_rotate);
 EI(keyStr == "rotatex")
R CNF(Matrix4x4_rotatex);
 EI(keyStr == "rotatey")
R CNF(Matrix4x4_rotatey);
 EI(keyStr == "rotatez")
R CNF(Matrix4x4_rotatez);
 EI(keyStr == "perspective")
R CNF(Matrix4x4_perspective);
 EI(keyStr == "orthographic")
R CNF(Matrix4x4_orthographic);
 EI(keyStr == "lookAt")
R CNF(Matrix4x4_lookAt);
 EI(keyStr == "lookAtDir")
R CNF(Matrix4x4_lookAtDir);
 else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void Matrix4x4_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV Matrix4x4_inverse(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix4x4::inverse" EAOE));
Matrix4x4*F;
if(!TS(a[0],Matrix4x4))
CATE(TE,FAE("Matrix4x4::inverse","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->inverse());
;
}
CATE(TE,UFOF("Matrix4x4::inverse.")));
R CN;
}

SV Matrix4x4_lookAtDir(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix4x4::lookAtDir" EAOE));
Matrix4x4*F;
if(!TS(a[0],Matrix4x4))
CATE(TE,FAE("Matrix4x4::lookAtDir","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==4)
if(1&&TS(a[1],const Position3D &)&&TS(a[2],const Direction3D &)&&TS(a[3],const Direction3D &))
{
R CV( F->lookAtDir(val_to_c<const Position3D &>::f(ctx,a[1]), val_to_c<const Direction3D &>::f(ctx,a[2]), val_to_c<const Direction3D &>::f(ctx,a[3])));
;
}
CATE(TE,UFOF("Matrix4x4::lookAtDir.")));
R CN;
}

SV Matrix4x4_transpose(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix4x4::transpose" EAOE));
Matrix4x4*F;
if(!TS(a[0],Matrix4x4))
CATE(TE,FAE("Matrix4x4::transpose","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->transpose());
;
}
CATE(TE,UFOF("Matrix4x4::transpose.")));
R CN;
}

SV Matrix4x4_rotatez(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix4x4::rotatez" EAOE));
Matrix4x4*F;
if(!TS(a[0],Matrix4x4))
CATE(TE,FAE("Matrix4x4::rotatez","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
R CV( F->rotatez(val_to_c<float>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Matrix4x4::rotatez.")));
R CN;
}

SV Matrix4x4_rotatex(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix4x4::rotatex" EAOE));
Matrix4x4*F;
if(!TS(a[0],Matrix4x4))
CATE(TE,FAE("Matrix4x4::rotatex","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
R CV( F->rotatex(val_to_c<float>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Matrix4x4::rotatex.")));
R CN;
}

SV Matrix4x4_rotatey(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix4x4::rotatey" EAOE));
Matrix4x4*F;
if(!TS(a[0],Matrix4x4))
CATE(TE,FAE("Matrix4x4::rotatey","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
R CV( F->rotatey(val_to_c<float>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Matrix4x4::rotatey.")));
R CN;
}

SV Matrix4x4___div__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix4x4::__div__" EAOE));
Matrix4x4*F;
if(!TS(a[0],Matrix4x4))
CATE(TE,FAE("Matrix4x4::__div__","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
auto v=val_to_c<float>::f(ctx,a[1]);
R CV(*F / v);
}
CATE(TE,UFOF("Matrix4x4::__div__.")));
R CN;
}

SV Matrix4x4_scale(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix4x4::scale" EAOE));
Matrix4x4*F;
if(!TS(a[0],Matrix4x4))
CATE(TE,FAE("Matrix4x4::scale","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Float3 &))
{
R CV( F->scale(val_to_c<const Float3 &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Matrix4x4::scale.")));
R CN;
}

SV Matrix4x4_lookAt(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix4x4::lookAt" EAOE));
Matrix4x4*F;
if(!TS(a[0],Matrix4x4))
CATE(TE,FAE("Matrix4x4::lookAt","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==4)
if(1&&TS(a[1],const Position3D &)&&TS(a[2],const Position3D &)&&TS(a[3],const Direction3D &))
{
R CV( F->lookAt(val_to_c<const Position3D &>::f(ctx,a[1]), val_to_c<const Position3D &>::f(ctx,a[2]), val_to_c<const Direction3D &>::f(ctx,a[3])));
;
}
CATE(TE,UFOF("Matrix4x4::lookAt.")));
R CN;
}

SV Matrix4x4___mul__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix4x4::__mul__" EAOE));
Matrix4x4*F;
if(!TS(a[0],Matrix4x4))
CATE(TE,FAE("Matrix4x4::__mul__","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Matrix4x4 &))
{
auto v=val_to_c<const Matrix4x4 &>::f(ctx,a[1]);
R CV(*F * v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const Float4 &))
{
auto v=val_to_c<const Float4 &>::f(ctx,a[1]);
R CV(*F * v);
}
CATE(TE,UFOF("Matrix4x4::__mul__.")));
R CN;
}

SV Matrix4x4_orthographic(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix4x4::orthographic" EAOE));
Matrix4x4*F;
if(!TS(a[0],Matrix4x4))
CATE(TE,FAE("Matrix4x4::orthographic","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==7)
if(1&&TS(a[1],float)&&TS(a[2],float)&&TS(a[3],float)&&TS(a[4],float)&&TS(a[5],float)&&TS(a[6],float))
{
R CV( F->orthographic(val_to_c<float>::f(ctx,a[1]), val_to_c<float>::f(ctx,a[2]), val_to_c<float>::f(ctx,a[3]), val_to_c<float>::f(ctx,a[4]), val_to_c<float>::f(ctx,a[5]), val_to_c<float>::f(ctx,a[6])));
;
}
CATE(TE,UFOF("Matrix4x4::orthographic.")));
R CN;
}

SV Matrix4x4_translate(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix4x4::translate" EAOE));
Matrix4x4*F;
if(!TS(a[0],Matrix4x4))
CATE(TE,FAE("Matrix4x4::translate","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Float3 &))
{
R CV( F->translate(val_to_c<const Float3 &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Matrix4x4::translate.")));
R CN;
}

SV Matrix4x4___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix4x4::__eq__" EAOE));
Matrix4x4*F;
if(!TS(a[0],Matrix4x4))
CATE(TE,FAE("Matrix4x4::__eq__","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Matrix4x4 &))
{
auto v=val_to_c<const Matrix4x4 &>::f(ctx,a[1]);
R CV(*F == v);
}
CATE(TE,UFOF("Matrix4x4::__eq__.")));
R CN;
}

SV Matrix4x4_rotate(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix4x4::rotate" EAOE));
Matrix4x4*F;
if(!TS(a[0],Matrix4x4))
CATE(TE,FAE("Matrix4x4::rotate","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
R CV( F->rotate(val_to_c<float>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Matrix4x4::rotate.")));
R CN;
}

SV Matrix4x4_perspective(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix4x4::perspective" EAOE));
Matrix4x4*F;
if(!TS(a[0],Matrix4x4))
CATE(TE,FAE("Matrix4x4::perspective","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==5)
if(1&&TS(a[1],float)&&TS(a[2],float)&&TS(a[3],float)&&TS(a[4],float))
{
R CV( F->perspective(val_to_c<float>::f(ctx,a[1]), val_to_c<float>::f(ctx,a[2]), val_to_c<float>::f(ctx,a[3]), val_to_c<float>::f(ctx,a[4])));
;
}
CATE(TE,UFOF("Matrix4x4::perspective.")));
R CN;
}

void UInt3_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,T3<uint32_t>))
CATE(TE,"UInt3::__del__ expects UInt3 as first argument."));

DELETE((T3<uint32_t>*)F->data);
}SV UInt3_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3's constructor" EAOE));
if(!TS(a[0],T3<uint32_t>))
CATE(TE,"UInt3's constructor expects UInt3 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(UInt3_funcs,NEW(T3<uint32_t>),EXT->UInt3_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],uint32_t))
R S::createNativeObject(UInt3_funcs,NEW(T3<uint32_t>,val_to_c<uint32_t>::f(ctx,a[1])),EXT->UInt3_typeID);
if(a.getCount()==4)
if(true&&TS(a[1],uint32_t)&&TS(a[2],uint32_t)&&TS(a[3],uint32_t))
R S::createNativeObject(UInt3_funcs,NEW(T3<uint32_t>,val_to_c<uint32_t>::f(ctx,a[1]),val_to_c<uint32_t>::f(ctx,a[2]),val_to_c<uint32_t>::f(ctx,a[3])),EXT->UInt3_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T3<float> &))
R S::createNativeObject(UInt3_funcs,NEW(T3<uint32_t>,val_to_c<const T3<float> &>::f(ctx,a[1])),EXT->UInt3_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T3<int32_t> &))
R S::createNativeObject(UInt3_funcs,NEW(T3<uint32_t>,val_to_c<const T3<int32_t> &>::f(ctx,a[1])),EXT->UInt3_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const T3<uint32_t> &))
R S::createNativeObject(UInt3_funcs,NEW(T3<uint32_t>,val_to_c<const T3<uint32_t> &>::f(ctx,a[1])),EXT->UInt3_typeID);
CATE(TE,UFOF("UInt3's constructor.")));
R CN;
}

SV UInt3_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("UInt3");
EI(keyStr=="__new__")
R CNF(UInt3_new);
EI(keyStr=="__call__")
R CNF(UInt3_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(UInt3_new);
 EI(keyStr == "__add__")
R CNF(UInt3___add__);
 EI(keyStr == "__sub__")
R CNF(UInt3___sub__);
 EI(keyStr == "__mul__")
R CNF(UInt3___mul__);
 EI(keyStr == "__div__")
R CNF(UInt3___div__);
 EI(keyStr == "__eq__")
R CNF(UInt3___eq__);
 EI(keyStr == "__neq__")
R CNF(UInt3___neq__);
 EI(keyStr == "__less__")
R CNF(UInt3___less__);
 EI(keyStr == "__grtr__")
R CNF(UInt3___grtr__);
 EI(keyStr == "__leq__")
R CNF(UInt3___leq__);
 EI(keyStr == "__geq__")
R CNF(UInt3___geq__);
 EI(keyStr == "sum")
R CNF(UInt3_sum);
 EI(keyStr == "length")
R CNF(UInt3_length);
 EI(keyStr == "lengthSquared")
R CNF(UInt3_lengthSquared);
 EI(keyStr == "dot")
R CNF(UInt3_dot);
 EI(keyStr == "distance")
R CNF(UInt3_distance);
 EI(keyStr == "distanceSquared")
R CNF(UInt3_distanceSquared);
 EI(keyStr == "normalize")
R CNF(UInt3_normalize);
 EI(keyStr == "cross")
R CNF(UInt3_cross);
 EI(keyStr == "getXY")
R CNF(UInt3_getXY);
 EI(keyStr == "setXY")
R CNF(UInt3_setXY);
 EI(keyStr == "getXZ")
R CNF(UInt3_getXZ);
 EI(keyStr == "setXZ")
R CNF(UInt3_setXZ);
 EI(keyStr == "getYX")
R CNF(UInt3_getYX);
 EI(keyStr == "setYX")
R CNF(UInt3_setYX);
 EI(keyStr == "getYZ")
R CNF(UInt3_getYZ);
 EI(keyStr == "setYZ")
R CNF(UInt3_setYZ);
 EI(keyStr == "getZX")
R CNF(UInt3_getZX);
 EI(keyStr == "setZX")
R CNF(UInt3_setZX);
 EI(keyStr == "getZY")
R CNF(UInt3_getZY);
 EI(keyStr == "setZY")
R CNF(UInt3_setZY);
 EI(keyStr == "getXYZ")
R CNF(UInt3_getXYZ);
 EI(keyStr == "setXYZ")
R CNF(UInt3_setXYZ);
 EI(keyStr == "getXZY")
R CNF(UInt3_getXZY);
 EI(keyStr == "setXZY")
R CNF(UInt3_setXZY);
 EI(keyStr == "getYXZ")
R CNF(UInt3_getYXZ);
 EI(keyStr == "setYXZ")
R CNF(UInt3_setYXZ);
 EI(keyStr == "getYZX")
R CNF(UInt3_getYZX);
 EI(keyStr == "setYZX")
R CNF(UInt3_setYZX);
 EI(keyStr == "getZXY")
R CNF(UInt3_getZXY);
 EI(keyStr == "setZXY")
R CNF(UInt3_setZXY);
 EI(keyStr == "getZYX")
R CNF(UInt3_getZYX);
 EI(keyStr == "setZYX")
R CNF(UInt3_setZYX);
 EI(keyStr=="x")
{
T3<uint32_t>*obj=(T3<uint32_t>*)F->data;
R CV(obj->x);
} EI(keyStr=="y")
{
T3<uint32_t>*obj=(T3<uint32_t>*)F->data;
R CV(obj->y);
} EI(keyStr=="z")
{
T3<uint32_t>*obj=(T3<uint32_t>*)F->data;
R CV(obj->z);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void UInt3_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="x")
{
T3<uint32_t>*obj=(T3<uint32_t>*)F->data;
obj->x=val_to_c<decltype(obj->x)>::f(ctx,value);
} EI(keyStr=="y")
{
T3<uint32_t>*obj=(T3<uint32_t>*)F->data;
obj->y=val_to_c<decltype(obj->y)>::f(ctx,value);
} EI(keyStr=="z")
{
T3<uint32_t>*obj=(T3<uint32_t>*)F->data;
obj->z=val_to_c<decltype(obj->z)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV UInt3_setYZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::setYZX" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::setYZX","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setYZX(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt3::setYZX.")));
R CN;
}

SV UInt3_getZXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::getZXY" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::getZXY","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZXY());
;
}
CATE(TE,UFOF("UInt3::getZXY.")));
R CN;
}

SV UInt3_setYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::setYZ" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::setYZ","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
( F->setYZ(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt3::setYZ.")));
R CN;
}

SV UInt3_setYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::setYX" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::setYX","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
( F->setYX(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt3::setYX.")));
R CN;
}

SV UInt3_setZYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::setZYX" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::setZYX","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setZYX(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt3::setZYX.")));
R CN;
}

SV UInt3_getZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::getZY" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::getZY","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZY());
;
}
CATE(TE,UFOF("UInt3::getZY.")));
R CN;
}

SV UInt3_distanceSquared(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::distanceSquared" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::distanceSquared","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
R CV( F->distanceSquared(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("UInt3::distanceSquared.")));
R CN;
}

SV UInt3_normalize(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::normalize" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::normalize","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->normalize());
;
}
CATE(TE,UFOF("UInt3::normalize.")));
R CN;
}

SV UInt3_getYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::getYX" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::getYX","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYX());
;
}
CATE(TE,UFOF("UInt3::getYX.")));
R CN;
}

SV UInt3___leq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::__leq__" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::__leq__","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
auto v=val_to_c<const T3<uint32_t> &>::f(ctx,a[1]);
R CV(*F <= v);
}
CATE(TE,UFOF("UInt3::__leq__.")));
R CN;
}

SV UInt3_setXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::setXZY" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::setXZY","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setXZY(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt3::setXZY.")));
R CN;
}

SV UInt3_sum(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::sum" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::sum","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->sum());
;
}
CATE(TE,UFOF("UInt3::sum.")));
R CN;
}

SV UInt3_cross(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::cross" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::cross","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
R CV( F->cross(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("UInt3::cross.")));
R CN;
}

SV UInt3_getXYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::getXYZ" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::getXYZ","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXYZ());
;
}
CATE(TE,UFOF("UInt3::getXYZ.")));
R CN;
}

SV UInt3___less__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::__less__" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::__less__","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
auto v=val_to_c<const T3<uint32_t> &>::f(ctx,a[1]);
R CV(*F < v);
}
CATE(TE,UFOF("UInt3::__less__.")));
R CN;
}

SV UInt3___neq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::__neq__" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::__neq__","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
auto v=val_to_c<const T3<uint32_t> &>::f(ctx,a[1]);
R CV(*F != v);
}
CATE(TE,UFOF("UInt3::__neq__.")));
R CN;
}

SV UInt3_getYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::getYZ" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::getYZ","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYZ());
;
}
CATE(TE,UFOF("UInt3::getYZ.")));
R CN;
}

SV UInt3_lengthSquared(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::lengthSquared" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::lengthSquared","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->lengthSquared());
;
}
CATE(TE,UFOF("UInt3::lengthSquared.")));
R CN;
}

SV UInt3_getZYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::getZYX" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::getZYX","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZYX());
;
}
CATE(TE,UFOF("UInt3::getZYX.")));
R CN;
}

SV UInt3___div__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::__div__" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::__div__","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
auto v=val_to_c<const T3<uint32_t> &>::f(ctx,a[1]);
R CV(*F / v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const uint32_t&))
{
auto v=val_to_c<const uint32_t&>::f(ctx,a[1]);
R CV(*F / v);
}
CATE(TE,UFOF("UInt3::__div__.")));
R CN;
}

SV UInt3_setZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::setZY" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::setZY","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
( F->setZY(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt3::setZY.")));
R CN;
}

SV UInt3_setZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::setZX" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::setZX","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
( F->setZX(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt3::setZX.")));
R CN;
}

SV UInt3_setXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::setXY" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::setXY","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
( F->setXY(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt3::setXY.")));
R CN;
}

SV UInt3___add__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::__add__" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::__add__","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
auto v=val_to_c<const T3<uint32_t> &>::f(ctx,a[1]);
R CV(*F + v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const uint32_t&))
{
auto v=val_to_c<const uint32_t&>::f(ctx,a[1]);
R CV(*F + v);
}
CATE(TE,UFOF("UInt3::__add__.")));
R CN;
}

SV UInt3_setXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::setXZ" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::setXZ","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T2<uint32_t> &))
{
( F->setXZ(val_to_c<const T2<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt3::setXZ.")));
R CN;
}

SV UInt3___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::__eq__" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::__eq__","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
auto v=val_to_c<const T3<uint32_t> &>::f(ctx,a[1]);
R CV(*F == v);
}
CATE(TE,UFOF("UInt3::__eq__.")));
R CN;
}

SV UInt3_setZXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::setZXY" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::setZXY","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setZXY(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt3::setZXY.")));
R CN;
}

SV UInt3_setYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::setYXZ" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::setYXZ","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setYXZ(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt3::setYXZ.")));
R CN;
}

SV UInt3_getXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::getXY" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::getXY","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXY());
;
}
CATE(TE,UFOF("UInt3::getXY.")));
R CN;
}

SV UInt3_distance(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::distance" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::distance","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
R CV( F->distance(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("UInt3::distance.")));
R CN;
}

SV UInt3_getXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::getXZ" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::getXZ","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXZ());
;
}
CATE(TE,UFOF("UInt3::getXZ.")));
R CN;
}

SV UInt3___grtr__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::__grtr__" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::__grtr__","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
auto v=val_to_c<const T3<uint32_t> &>::f(ctx,a[1]);
R CV(*F > v);
}
CATE(TE,UFOF("UInt3::__grtr__.")));
R CN;
}

SV UInt3_getXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::getXZY" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::getXZY","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getXZY());
;
}
CATE(TE,UFOF("UInt3::getXZY.")));
R CN;
}

SV UInt3_setXYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::setXYZ" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::setXYZ","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
( F->setXYZ(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("UInt3::setXYZ.")));
R CN;
}

SV UInt3_getYZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::getYZX" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::getYZX","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYZX());
;
}
CATE(TE,UFOF("UInt3::getYZX.")));
R CN;
}

SV UInt3_length(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::length" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::length","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->length());
;
}
CATE(TE,UFOF("UInt3::length.")));
R CN;
}

SV UInt3___mul__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::__mul__" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::__mul__","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
auto v=val_to_c<const T3<uint32_t> &>::f(ctx,a[1]);
R CV(*F * v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const uint32_t&))
{
auto v=val_to_c<const uint32_t&>::f(ctx,a[1]);
R CV(*F * v);
}
CATE(TE,UFOF("UInt3::__mul__.")));
R CN;
}

SV UInt3_getYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::getYXZ" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::getYXZ","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getYXZ());
;
}
CATE(TE,UFOF("UInt3::getYXZ.")));
R CN;
}

SV UInt3_getZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::getZX" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::getZX","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getZX());
;
}
CATE(TE,UFOF("UInt3::getZX.")));
R CN;
}

SV UInt3___sub__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::__sub__" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::__sub__","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
auto v=val_to_c<const T3<uint32_t> &>::f(ctx,a[1]);
R CV(*F - v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const uint32_t&))
{
auto v=val_to_c<const uint32_t&>::f(ctx,a[1]);
R CV(*F - v);
}
CATE(TE,UFOF("UInt3::__sub__.")));
R CN;
}

SV UInt3___geq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::__geq__" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::__geq__","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
auto v=val_to_c<const T3<uint32_t> &>::f(ctx,a[1]);
R CV(*F >= v);
}
CATE(TE,UFOF("UInt3::__geq__.")));
R CN;
}

SV UInt3_dot(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::dot" EAOE));
T3<uint32_t>*F;
if(!TS(a[0],T3<uint32_t>))
CATE(TE,FAE("UInt3::dot","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const T3<uint32_t> &))
{
R CV( F->dot(val_to_c<const T3<uint32_t> &>::f(ctx,a[1])));
;
}
if(a.getCount()==1)
if(1)
{
R CV( F->dot());
;
}
CATE(TE,UFOF("UInt3::dot.")));
R CN;
}

void LightSpotData_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,LightSpotData))
CATE(TE,"LightSpotData::__del__ expects LightSpotData as first argument."));

DELETE((LightSpotData*)F->data);
}SV LightSpotData_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"LightSpotData's constructor" EAOE));
if(!TS(a[0],LightSpotData))
CATE(TE,"LightSpotData's constructor expects LightSpotData as first argument."));
#define fjis LightSpotData
R S::createNativeObject(LightSpotData_funcs,NEW(fjis),EXT->LightSpotData_typeID);
}

SV LightSpotData_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("LightSpotData");
EI(keyStr=="__new__")
R CNF(LightSpotData_new);
EI(keyStr=="__call__")
R CNF(LightSpotData_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(LightSpotData_new);
 EI(keyStr=="position")
{
LightSpotData*obj=(LightSpotData*)F->data;
R CV(obj->position);
} EI(keyStr=="direction")
{
LightSpotData*obj=(LightSpotData*)F->data;
R CV(obj->direction);
} EI(keyStr=="innerCutoff")
{
LightSpotData*obj=(LightSpotData*)F->data;
R CV(obj->innerCutoff);
} EI(keyStr=="outerCutoff")
{
LightSpotData*obj=(LightSpotData*)F->data;
R CV(obj->outerCutoff);
} EI(keyStr=="radius")
{
LightSpotData*obj=(LightSpotData*)F->data;
R CV(obj->radius);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void LightSpotData_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="position")
{
LightSpotData*obj=(LightSpotData*)F->data;
obj->position=val_to_c<decltype(obj->position)>::f(ctx,value);
} EI(keyStr=="direction")
{
LightSpotData*obj=(LightSpotData*)F->data;
obj->direction=val_to_c<decltype(obj->direction)>::f(ctx,value);
} EI(keyStr=="innerCutoff")
{
LightSpotData*obj=(LightSpotData*)F->data;
obj->innerCutoff=val_to_c<decltype(obj->innerCutoff)>::f(ctx,value);
} EI(keyStr=="outerCutoff")
{
LightSpotData*obj=(LightSpotData*)F->data;
obj->outerCutoff=val_to_c<decltype(obj->outerCutoff)>::f(ctx,value);
} EI(keyStr=="radius")
{
LightSpotData*obj=(LightSpotData*)F->data;
obj->radius=val_to_c<decltype(obj->radius)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

void AudioDevice_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,AudioDevice))
CATE(TE,"AudioDevice::__del__ expects AudioDevice as first argument."));

DELETE((AudioDevice*)F->data);
}SV AudioDevice_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioDevice's constructor" EAOE));
if(!TS(a[0],AudioDevice))
CATE(TE,"AudioDevice's constructor expects AudioDevice as first argument."));
if(a.getCount()==4)
if(true&&TS(a[1],size_t)&&TS(a[2],size_t)&&TS(a[3],size_t))
R S::createNativeObject(AudioDevice_funcs,NEW(AudioDevice,val_to_c<size_t>::f(ctx,a[1]),val_to_c<size_t>::f(ctx,a[2]),val_to_c<size_t>::f(ctx,a[3])),EXT->AudioDevice_typeID);
CATE(TE,UFOF("AudioDevice's constructor.")));
R CN;
}

SV AudioDevice_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("AudioDevice");
EI(keyStr=="__new__")
R CNF(AudioDevice_new);
EI(keyStr=="__call__")
R CNF(AudioDevice_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(AudioDevice_new);
 EI(keyStr == "getName")
R CNF(AudioDevice_getName);
 EI(keyStr == "getDeviceCount")
R CNF(AudioDevice_getDeviceCount);
 EI(keyStr == "setIndex")
R CNF(AudioDevice_setIndex);
 EI(keyStr == "setFrequency")
R CNF(AudioDevice_setFrequency);
 EI(keyStr == "setSamples")
R CNF(AudioDevice_setSamples);
 EI(keyStr == "getIndex")
R CNF(AudioDevice_getIndex);
 EI(keyStr == "getFrequency")
R CNF(AudioDevice_getFrequency);
 EI(keyStr == "getSamples")
R CNF(AudioDevice_getSamples);
 EI(keyStr == "getNumQueuedSamples")
R CNF(AudioDevice_getNumQueuedSamples);
 EI(keyStr == "pause")
R CNF(AudioDevice_pause);
 EI(keyStr == "play")
R CNF(AudioDevice_play);
 EI(keyStr == "getPaused")
R CNF(AudioDevice_getPaused);
 EI(keyStr == "runCallbacks")
R CNF(AudioDevice_runCallbacks);
 EI(keyStr=="volume")
{
AudioDevice*obj=(AudioDevice*)F->data;
R CV(obj->volume);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void AudioDevice_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="volume")
{
AudioDevice*obj=(AudioDevice*)F->data;
obj->volume=val_to_c<decltype(obj->volume)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV AudioDevice_getIndex(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioDevice::getIndex" EAOE));
AudioDevice*F;
if(!TS(a[0],AudioDevice))
CATE(TE,FAE("AudioDevice::getIndex","AudioDevice")));
else
 F=(AudioDevice*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getIndex());
;
}
CATE(TE,UFOF("AudioDevice::getIndex.")));
R CN;
}

SV AudioDevice_getFrequency(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioDevice::getFrequency" EAOE));
AudioDevice*F;
if(!TS(a[0],AudioDevice))
CATE(TE,FAE("AudioDevice::getFrequency","AudioDevice")));
else
 F=(AudioDevice*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getFrequency());
;
}
CATE(TE,UFOF("AudioDevice::getFrequency.")));
R CN;
}

SV AudioDevice_pause(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioDevice::pause" EAOE));
AudioDevice*F;
if(!TS(a[0],AudioDevice))
CATE(TE,FAE("AudioDevice::pause","AudioDevice")));
else
 F=(AudioDevice*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->pause());
R CN;
}
CATE(TE,UFOF("AudioDevice::pause.")));
R CN;
}

SV AudioDevice_runCallbacks(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioDevice::runCallbacks" EAOE));
AudioDevice*F;
if(!TS(a[0],AudioDevice))
CATE(TE,FAE("AudioDevice::runCallbacks","AudioDevice")));
else
 F=(AudioDevice*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
( F->runCallbacks(val_to_c<size_t>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("AudioDevice::runCallbacks.")));
R CN;
}

SV AudioDevice_getName(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioDevice::getName" EAOE));
AudioDevice*F;
if(!TS(a[0],AudioDevice))
CATE(TE,FAE("AudioDevice::getName","AudioDevice")));
else
 F=(AudioDevice*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getName());
;
}
if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getName(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("AudioDevice::getName.")));
R CN;
}

SV AudioDevice_getPaused(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioDevice::getPaused" EAOE));
AudioDevice*F;
if(!TS(a[0],AudioDevice))
CATE(TE,FAE("AudioDevice::getPaused","AudioDevice")));
else
 F=(AudioDevice*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getPaused());
;
}
CATE(TE,UFOF("AudioDevice::getPaused.")));
R CN;
}

SV AudioDevice_setIndex(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioDevice::setIndex" EAOE));
AudioDevice*F;
if(!TS(a[0],AudioDevice))
CATE(TE,FAE("AudioDevice::setIndex","AudioDevice")));
else
 F=(AudioDevice*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
( F->setIndex(val_to_c<size_t>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("AudioDevice::setIndex.")));
R CN;
}

SV AudioDevice_play(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioDevice::play" EAOE));
AudioDevice*F;
if(!TS(a[0],AudioDevice))
CATE(TE,FAE("AudioDevice::play","AudioDevice")));
else
 F=(AudioDevice*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->play());
R CN;
}
CATE(TE,UFOF("AudioDevice::play.")));
R CN;
}

SV AudioDevice_getSamples(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioDevice::getSamples" EAOE));
AudioDevice*F;
if(!TS(a[0],AudioDevice))
CATE(TE,FAE("AudioDevice::getSamples","AudioDevice")));
else
 F=(AudioDevice*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getSamples());
;
}
CATE(TE,UFOF("AudioDevice::getSamples.")));
R CN;
}

SV AudioDevice_setFrequency(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioDevice::setFrequency" EAOE));
AudioDevice*F;
if(!TS(a[0],AudioDevice))
CATE(TE,FAE("AudioDevice::setFrequency","AudioDevice")));
else
 F=(AudioDevice*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
( F->setFrequency(val_to_c<size_t>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("AudioDevice::setFrequency.")));
R CN;
}

SV AudioDevice_getNumQueuedSamples(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioDevice::getNumQueuedSamples" EAOE));
AudioDevice*F;
if(!TS(a[0],AudioDevice))
CATE(TE,FAE("AudioDevice::getNumQueuedSamples","AudioDevice")));
else
 F=(AudioDevice*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getNumQueuedSamples());
;
}
CATE(TE,UFOF("AudioDevice::getNumQueuedSamples.")));
R CN;
}

SV AudioDevice_getDeviceCount(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioDevice::getDeviceCount" EAOE));
AudioDevice*F;
if(!TS(a[0],AudioDevice))
CATE(TE,FAE("AudioDevice::getDeviceCount","AudioDevice")));
else
 F=(AudioDevice*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getDeviceCount());
;
}
CATE(TE,UFOF("AudioDevice::getDeviceCount.")));
R CN;
}

SV AudioDevice_setSamples(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AudioDevice::setSamples" EAOE));
AudioDevice*F;
if(!TS(a[0],AudioDevice))
CATE(TE,FAE("AudioDevice::setSamples","AudioDevice")));
else
 F=(AudioDevice*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
( F->setSamples(val_to_c<size_t>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("AudioDevice::setSamples.")));
R CN;
}

void GfxLOD_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,GfxLOD))
CATE(TE,"GfxLOD::__del__ expects GfxLOD as first argument."));

DELETE((GfxLOD*)F->data);
}SV GfxLOD_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxLOD's constructor" EAOE));
if(!TS(a[0],GfxLOD))
CATE(TE,"GfxLOD's constructor expects GfxLOD as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(GfxLOD_funcs,NEW(GfxLOD),EXT->GfxLOD_typeID);
CATE(TE,UFOF("GfxLOD's constructor.")));
R CN;
}

SV GfxLOD_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxLOD");
EI(keyStr=="__new__")
R CNF(GfxLOD_new);
EI(keyStr=="__call__")
R CNF(GfxLOD_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(GfxLOD_new);
 EI(keyStr == "__eq__")
R CNF(GfxLOD___eq__);
 EI(keyStr=="minDistance")
{
GfxLOD*obj=(GfxLOD*)F->data;
R CV(obj->minDistance);
} EI(keyStr=="maxDistance")
{
GfxLOD*obj=(GfxLOD*)F->data;
R CV(obj->maxDistance);
} EI(keyStr=="worldMatrix")
{
GfxLOD*obj=(GfxLOD*)F->data;
R CV(obj->worldMatrix);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void GfxLOD_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="minDistance")
{
GfxLOD*obj=(GfxLOD*)F->data;
obj->minDistance=val_to_c<decltype(obj->minDistance)>::f(ctx,value);
} EI(keyStr=="maxDistance")
{
GfxLOD*obj=(GfxLOD*)F->data;
obj->maxDistance=val_to_c<decltype(obj->maxDistance)>::f(ctx,value);
} EI(keyStr=="worldMatrix")
{
GfxLOD*obj=(GfxLOD*)F->data;
obj->worldMatrix=val_to_c<decltype(obj->worldMatrix)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV GfxLOD___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxLOD::__eq__" EAOE));
GfxLOD*F;
if(!TS(a[0],GfxLOD))
CATE(TE,FAE("GfxLOD::__eq__","GfxLOD")));
else
 F=(GfxLOD*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const GfxLOD &))
{
auto v=val_to_c<const GfxLOD &>::f(ctx,a[1]);
R CV(*F == v);
}
CATE(TE,UFOF("GfxLOD::__eq__.")));
R CN;
}

void File_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,File))
CATE(TE,"File::__del__ expects File as first argument."));

DELETE((File*)F->data);
}SV File_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File's constructor" EAOE));
if(!TS(a[0],File))
CATE(TE,"File's constructor expects File as first argument."));
if(a.getCount()==3)
if(true&&TS(a[1],const char *)&&TS(a[2],const char *))
R S::createNativeObject(File_funcs,NEW(File,val_to_c<const char *>::f(ctx,a[1]),val_to_c<const char *>::f(ctx,a[2])),EXT->File_typeID);
CATE(TE,UFOF("File's constructor.")));
R CN;
}

SV File_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("File");
EI(keyStr=="__new__")
R CNF(File_new);
EI(keyStr=="__call__")
R CNF(File_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(File_new);
 EI(keyStr == "read")
R CNF(File_read);
 EI(keyStr == "write")
R CNF(File_write);
 EI(keyStr == "seek")
R CNF(File_seek);
 EI(keyStr == "tell")
R CNF(File_tell);
 EI(keyStr == "flush")
R CNF(File_flush);
 EI(keyStr == "isAtEndOfFile")
R CNF(File_isAtEndOfFile);
 EI(keyStr == "getSize")
R CNF(File_getSize);
 EI(keyStr == "readUInt8")
R CNF(File_readUInt8);
 EI(keyStr == "readInt8")
R CNF(File_readInt8);
 EI(keyStr == "readUInt16LE")
R CNF(File_readUInt16LE);
 EI(keyStr == "readInt16LE")
R CNF(File_readInt16LE);
 EI(keyStr == "readUInt32LE")
R CNF(File_readUInt32LE);
 EI(keyStr == "readInt32LE")
R CNF(File_readInt32LE);
 EI(keyStr == "readUInt64LE")
R CNF(File_readUInt64LE);
 EI(keyStr == "readInt64LE")
R CNF(File_readInt64LE);
 EI(keyStr == "readUInt16BE")
R CNF(File_readUInt16BE);
 EI(keyStr == "readInt16BE")
R CNF(File_readInt16BE);
 EI(keyStr == "readUInt32BE")
R CNF(File_readUInt32BE);
 EI(keyStr == "readInt32BE")
R CNF(File_readInt32BE);
 EI(keyStr == "readUInt64BE")
R CNF(File_readUInt64BE);
 EI(keyStr == "readInt64BE")
R CNF(File_readInt64BE);
 EI(keyStr == "readFloat32")
R CNF(File_readFloat32);
 EI(keyStr == "readChar")
R CNF(File_readChar);
 EI(keyStr == "writeUInt8")
R CNF(File_writeUInt8);
 EI(keyStr == "writeInt8")
R CNF(File_writeInt8);
 EI(keyStr == "writeUInt16LE")
R CNF(File_writeUInt16LE);
 EI(keyStr == "writeInt16LE")
R CNF(File_writeInt16LE);
 EI(keyStr == "writeUInt32LE")
R CNF(File_writeUInt32LE);
 EI(keyStr == "writeInt32LE")
R CNF(File_writeInt32LE);
 EI(keyStr == "writeUInt64LE")
R CNF(File_writeUInt64LE);
 EI(keyStr == "writeInt64LE")
R CNF(File_writeInt64LE);
 EI(keyStr == "writeUInt16BE")
R CNF(File_writeUInt16BE);
 EI(keyStr == "writeInt16BE")
R CNF(File_writeInt16BE);
 EI(keyStr == "writeUInt32BE")
R CNF(File_writeUInt32BE);
 EI(keyStr == "writeInt32BE")
R CNF(File_writeInt32BE);
 EI(keyStr == "writeUInt64BE")
R CNF(File_writeUInt64BE);
 EI(keyStr == "writeInt64BE")
R CNF(File_writeInt64BE);
 EI(keyStr == "writeFloat32")
R CNF(File_writeFloat32);
 EI(keyStr == "printf")
R CNF(File_printf);
 EI(keyStr == "vprintf")
R CNF(File_vprintf);
 EI(keyStr == "writeChar")
R CNF(File_writeChar);
 else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void File_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV File_readFloat32(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::readFloat32" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::readFloat32","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->readFloat32());
;
}
CATE(TE,UFOF("File::readFloat32.")));
R CN;
}

SV File_printf(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::printf" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::printf","File")));
else
 F=(File*)((NO)a[0])->data;

CATE(TE,UFOF("File::printf.")));
R CN;
}

SV File_readUInt8(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::readUInt8" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::readUInt8","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->readUInt8());
;
}
CATE(TE,UFOF("File::readUInt8.")));
R CN;
}

SV File_getSize(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::getSize" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::getSize","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getSize());
;
}
CATE(TE,UFOF("File::getSize.")));
R CN;
}

SV File_readInt32LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::readInt32LE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::readInt32LE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->readInt32LE());
;
}
CATE(TE,UFOF("File::readInt32LE.")));
R CN;
}

SV File_flush(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::flush" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::flush","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->flush());
R CN;
}
CATE(TE,UFOF("File::flush.")));
R CN;
}

SV File_writeChar(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::writeChar" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::writeChar","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],char))
{
( F->writeChar(val_to_c<char>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("File::writeChar.")));
R CN;
}

SV File_seek(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::seek" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::seek","File")));
else
 F=(File*)((NO)a[0])->data;

CATE(TE,UFOF("File::seek.")));
R CN;
}

SV File_readInt8(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::readInt8" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::readInt8","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->readInt8());
;
}
CATE(TE,UFOF("File::readInt8.")));
R CN;
}

SV File_readInt32BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::readInt32BE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::readInt32BE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->readInt32BE());
;
}
CATE(TE,UFOF("File::readInt32BE.")));
R CN;
}

SV File_writeInt32BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::writeInt32BE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::writeInt32BE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],int32_t))
{
( F->writeInt32BE(val_to_c<int32_t>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("File::writeInt32BE.")));
R CN;
}

SV File_readInt64LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::readInt64LE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::readInt64LE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->readInt64LE());
;
}
CATE(TE,UFOF("File::readInt64LE.")));
R CN;
}

SV File_writeUInt32BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::writeUInt32BE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::writeUInt32BE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],uint32_t))
{
( F->writeUInt32BE(val_to_c<uint32_t>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("File::writeUInt32BE.")));
R CN;
}

SV File_writeUInt64LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::writeUInt64LE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::writeUInt64LE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],uint64_t))
{
( F->writeUInt64LE(val_to_c<uint64_t>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("File::writeUInt64LE.")));
R CN;
}

SV File_write(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::write" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::write","File")));
else
 F=(File*)((NO)a[0])->data;

CATE(TE,UFOF("File::write.")));
R CN;
}

SV File_writeFloat32(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::writeFloat32" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::writeFloat32","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
( F->writeFloat32(val_to_c<float>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("File::writeFloat32.")));
R CN;
}

SV File_writeInt64BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::writeInt64BE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::writeInt64BE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],int64_t))
{
( F->writeInt64BE(val_to_c<int64_t>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("File::writeInt64BE.")));
R CN;
}

SV File_readUInt32LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::readUInt32LE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::readUInt32LE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->readUInt32LE());
;
}
CATE(TE,UFOF("File::readUInt32LE.")));
R CN;
}

SV File_tell(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::tell" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::tell","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->tell());
;
}
CATE(TE,UFOF("File::tell.")));
R CN;
}

SV File_writeUInt32LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::writeUInt32LE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::writeUInt32LE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],uint32_t))
{
( F->writeUInt32LE(val_to_c<uint32_t>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("File::writeUInt32LE.")));
R CN;
}

SV File_vprintf(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::vprintf" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::vprintf","File")));
else
 F=(File*)((NO)a[0])->data;

CATE(TE,UFOF("File::vprintf.")));
R CN;
}

SV File_writeUInt64BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::writeUInt64BE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::writeUInt64BE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],uint64_t))
{
( F->writeUInt64BE(val_to_c<uint64_t>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("File::writeUInt64BE.")));
R CN;
}

SV File_read(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::read" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::read","File")));
else
 F=(File*)((NO)a[0])->data;

CATE(TE,UFOF("File::read.")));
R CN;
}

SV File_readInt64BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::readInt64BE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::readInt64BE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->readInt64BE());
;
}
CATE(TE,UFOF("File::readInt64BE.")));
R CN;
}

SV File_writeInt16LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::writeInt16LE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::writeInt16LE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],int16_t))
{
( F->writeInt16LE(val_to_c<int16_t>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("File::writeInt16LE.")));
R CN;
}

SV File_isAtEndOfFile(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::isAtEndOfFile" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::isAtEndOfFile","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->isAtEndOfFile());
;
}
CATE(TE,UFOF("File::isAtEndOfFile.")));
R CN;
}

SV File_writeInt64LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::writeInt64LE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::writeInt64LE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],int64_t))
{
( F->writeInt64LE(val_to_c<int64_t>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("File::writeInt64LE.")));
R CN;
}

SV File_readUInt32BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::readUInt32BE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::readUInt32BE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->readUInt32BE());
;
}
CATE(TE,UFOF("File::readUInt32BE.")));
R CN;
}

SV File_readChar(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::readChar" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::readChar","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->readChar());
;
}
CATE(TE,UFOF("File::readChar.")));
R CN;
}

SV File_readUInt16BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::readUInt16BE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::readUInt16BE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->readUInt16BE());
;
}
CATE(TE,UFOF("File::readUInt16BE.")));
R CN;
}

SV File_writeInt32LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::writeInt32LE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::writeInt32LE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],int32_t))
{
( F->writeInt32LE(val_to_c<int32_t>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("File::writeInt32LE.")));
R CN;
}

SV File_readUInt64LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::readUInt64LE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::readUInt64LE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->readUInt64LE());
;
}
CATE(TE,UFOF("File::readUInt64LE.")));
R CN;
}

SV File_writeUInt16LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::writeUInt16LE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::writeUInt16LE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],uint16_t))
{
( F->writeUInt16LE(val_to_c<uint16_t>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("File::writeUInt16LE.")));
R CN;
}

SV File_writeInt8(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::writeInt8" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::writeInt8","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],int8_t))
{
( F->writeInt8(val_to_c<int8_t>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("File::writeInt8.")));
R CN;
}

SV File_readInt16BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::readInt16BE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::readInt16BE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->readInt16BE());
;
}
CATE(TE,UFOF("File::readInt16BE.")));
R CN;
}

SV File_writeUInt16BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::writeUInt16BE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::writeUInt16BE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],uint16_t))
{
( F->writeUInt16BE(val_to_c<uint16_t>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("File::writeUInt16BE.")));
R CN;
}

SV File_writeUInt8(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::writeUInt8" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::writeUInt8","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],uint8_t))
{
( F->writeUInt8(val_to_c<uint8_t>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("File::writeUInt8.")));
R CN;
}

SV File_readInt16LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::readInt16LE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::readInt16LE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->readInt16LE());
;
}
CATE(TE,UFOF("File::readInt16LE.")));
R CN;
}

SV File_readUInt16LE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::readUInt16LE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::readUInt16LE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->readUInt16LE());
;
}
CATE(TE,UFOF("File::readUInt16LE.")));
R CN;
}

SV File_readUInt64BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::readUInt64BE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::readUInt64BE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->readUInt64BE());
;
}
CATE(TE,UFOF("File::readUInt64BE.")));
R CN;
}

SV File_writeInt16BE(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File::writeInt16BE" EAOE));
File*F;
if(!TS(a[0],File))
CATE(TE,FAE("File::writeInt16BE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],int16_t))
{
( F->writeInt16BE(val_to_c<int16_t>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("File::writeInt16BE.")));
R CN;
}

void AABB_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,AABB))
CATE(TE,"AABB::__del__ expects AABB as first argument."));

DELETE((AABB*)F->data);
}SV AABB_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AABB's constructor" EAOE));
if(!TS(a[0],AABB))
CATE(TE,"AABB's constructor expects AABB as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(AABB_funcs,NEW(AABB),EXT->AABB_typeID);
if(a.getCount()==3)
if(true&&TS(a[1],const Position3D &)&&TS(a[2],const Position3D &))
R S::createNativeObject(AABB_funcs,NEW(AABB,val_to_c<const Position3D &>::f(ctx,a[1]),val_to_c<const Position3D &>::f(ctx,a[2])),EXT->AABB_typeID);
CATE(TE,UFOF("AABB's constructor.")));
R CN;
}

SV AABB_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("AABB");
EI(keyStr=="__new__")
R CNF(AABB_new);
EI(keyStr=="__call__")
R CNF(AABB_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(AABB_new);
 EI(keyStr == "transform")
R CNF(AABB_transform);
 EI(keyStr == "extend")
R CNF(AABB_extend);
 EI(keyStr == "grow")
R CNF(AABB_grow);
 EI(keyStr=="min")
{
AABB*obj=(AABB*)F->data;
R CV(obj->min);
} EI(keyStr=="max")
{
AABB*obj=(AABB*)F->data;
R CV(obj->max);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void AABB_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="min")
{
AABB*obj=(AABB*)F->data;
obj->min=val_to_c<decltype(obj->min)>::f(ctx,value);
} EI(keyStr=="max")
{
AABB*obj=(AABB*)F->data;
obj->max=val_to_c<decltype(obj->max)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV AABB_transform(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AABB::transform" EAOE));
AABB*F;
if(!TS(a[0],AABB))
CATE(TE,FAE("AABB::transform","AABB")));
else
 F=(AABB*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Matrix4x4 &))
{
R CV( F->transform(val_to_c<const Matrix4x4 &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("AABB::transform.")));
R CN;
}

SV AABB_extend(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AABB::extend" EAOE));
AABB*F;
if(!TS(a[0],AABB))
CATE(TE,FAE("AABB::extend","AABB")));
else
 F=(AABB*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Position3D &))
{
( F->extend(val_to_c<const Position3D &>::f(ctx,a[1])));
R CN;
}
if(a.getCount()==2)
if(1&&TS(a[1],const AABB &))
{
( F->extend(val_to_c<const AABB &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("AABB::extend.")));
R CN;
}

SV AABB_grow(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AABB::grow" EAOE));
AABB*F;
if(!TS(a[0],AABB))
CATE(TE,FAE("AABB::grow","AABB")));
else
 F=(AABB*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Vector3D &))
{
( F->grow(val_to_c<const Vector3D &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("AABB::grow.")));
R CN;
}

void List_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,List<scripting::Value*>))
CATE(TE,"List::__del__ expects List as first argument."));

DELETE((List<scripting::Value*>*)F->data);
}SV List_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"List's constructor" EAOE));
if(!TS(a[0],List<scripting::Value*>))
CATE(TE,"List's constructor expects List as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(List_funcs,NEW(List<scripting::Value*>),EXT->List_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],std::size_t))
R S::createNativeObject(List_funcs,NEW(List<scripting::Value*>,val_to_c<std::size_t>::f(ctx,a[1])),EXT->List_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const List<scripting::Value*> &))
R S::createNativeObject(List_funcs,NEW(List<scripting::Value*>,val_to_c<const List<scripting::Value*> &>::f(ctx,a[1])),EXT->List_typeID);
CATE(TE,UFOF("List's constructor.")));
R CN;
}

SV List_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("List");
EI(keyStr=="__new__")
R CNF(List_new);
EI(keyStr=="__call__")
R CNF(List_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(List_new);
 EI(keyStr == "__eq__")
R CNF(List___eq__);
 EI(keyStr == "__neq__")
R CNF(List___neq__);
 EI(keyStr == "getCount")
R CNF(List_getCount);
 EI(keyStr == "getData")
R CNF(List_getData);
 EI(keyStr == "append")
R CNF(List_append);
 EI(keyStr == "insert")
R CNF(List_insert);
 EI(keyStr == "remove")
R CNF(List_remove);
 EI(keyStr == "clear")
R CNF(List_clear);
 EI(keyStr == "find")
R CNF(List_find);
 EI(keyStr == "copy")
R CNF(List_copy);
 EI(keyStr == "in")
R CNF(List_in);
 else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void List_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV List_insert(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"List::insert" EAOE));
List<scripting::Value*>*F;
if(!TS(a[0],List<scripting::Value*>))
CATE(TE,FAE("List::insert","List")));
else
 F=(List<scripting::Value*>*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],std::size_t)&&TS(a[2],const scripting::Value*&))
{
( F->insert(val_to_c<std::size_t>::f(ctx,a[1]), val_to_c<const scripting::Value*&>::f(ctx,a[2])));
R CN;
}
if(a.getCount()==3)
if(1&&TS(a[1],std::size_t)&&TS(a[2],const List<scripting::Value*> &))
{
( F->insert(val_to_c<std::size_t>::f(ctx,a[1]), val_to_c<const List<scripting::Value*> &>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("List::insert.")));
R CN;
}

SV List_copy(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"List::copy" EAOE));
List<scripting::Value*>*F;
if(!TS(a[0],List<scripting::Value*>))
CATE(TE,FAE("List::copy","List")));
else
 F=(List<scripting::Value*>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->copy());
;
}
CATE(TE,UFOF("List::copy.")));
R CN;
}

SV List_clear(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"List::clear" EAOE));
List<scripting::Value*>*F;
if(!TS(a[0],List<scripting::Value*>))
CATE(TE,FAE("List::clear","List")));
else
 F=(List<scripting::Value*>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->clear());
R CN;
}
CATE(TE,UFOF("List::clear.")));
R CN;
}

SV List_remove(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"List::remove" EAOE));
List<scripting::Value*>*F;
if(!TS(a[0],List<scripting::Value*>))
CATE(TE,FAE("List::remove","List")));
else
 F=(List<scripting::Value*>*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],std::size_t)&&TS(a[2],std::size_t))
{
( F->remove(val_to_c<std::size_t>::f(ctx,a[1]), val_to_c<std::size_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("List::remove.")));
R CN;
}

SV List_in(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"List::in" EAOE));
List<scripting::Value*>*F;
if(!TS(a[0],List<scripting::Value*>))
CATE(TE,FAE("List::in","List")));
else
 F=(List<scripting::Value*>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const scripting::Value*&))
{
R CV( F->in(val_to_c<const scripting::Value*&>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("List::in.")));
R CN;
}

SV List_getCount(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"List::getCount" EAOE));
List<scripting::Value*>*F;
if(!TS(a[0],List<scripting::Value*>))
CATE(TE,FAE("List::getCount","List")));
else
 F=(List<scripting::Value*>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getCount());
;
}
CATE(TE,UFOF("List::getCount.")));
R CN;
}

SV List_getData(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"List::getData" EAOE));
List<scripting::Value*>*F;
if(!TS(a[0],List<scripting::Value*>))
CATE(TE,FAE("List::getData","List")));
else
 F=(List<scripting::Value*>*)((NO)a[0])->data;

CATE(TE,UFOF("List::getData.")));
R CN;
}

SV List___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"List::__eq__" EAOE));
List<scripting::Value*>*F;
if(!TS(a[0],List<scripting::Value*>))
CATE(TE,FAE("List::__eq__","List")));
else
 F=(List<scripting::Value*>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const List<scripting::Value*> &))
{
auto v=val_to_c<const List<scripting::Value*> &>::f(ctx,a[1]);
R CV(*F == v);
}
CATE(TE,UFOF("List::__eq__.")));
R CN;
}

SV List_find(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"List::find" EAOE));
List<scripting::Value*>*F;
if(!TS(a[0],List<scripting::Value*>))
CATE(TE,FAE("List::find","List")));
else
 F=(List<scripting::Value*>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const scripting::Value*&))
{
R CV( F->find(val_to_c<const scripting::Value*&>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("List::find.")));
R CN;
}

SV List_append(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"List::append" EAOE));
List<scripting::Value*>*F;
if(!TS(a[0],List<scripting::Value*>))
CATE(TE,FAE("List::append","List")));
else
 F=(List<scripting::Value*>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const scripting::Value*&))
{
( F->append(val_to_c<const scripting::Value*&>::f(ctx,a[1])));
R CN;
}
if(a.getCount()==2)
if(1&&TS(a[1],const List<scripting::Value*> &))
{
( F->append(val_to_c<const List<scripting::Value*> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("List::append.")));
R CN;
}

SV List___neq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"List::__neq__" EAOE));
List<scripting::Value*>*F;
if(!TS(a[0],List<scripting::Value*>))
CATE(TE,FAE("List::__neq__","List")));
else
 F=(List<scripting::Value*>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const List<scripting::Value*> &))
{
auto v=val_to_c<const List<scripting::Value*> &>::f(ctx,a[1]);
R CV(*F != v);
}
CATE(TE,UFOF("List::__neq__.")));
R CN;
}

void Audio_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,Audio))
CATE(TE,"Audio::__del__ expects Audio as first argument."));

Audio*obj=(Audio*)F->data;
obj->release();
}SV Audio_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"Audio's constructor" EAOE));
if(!TS(a[0],Audio))
CATE(TE,"Audio's constructor expects Audio as first argument."));
CATE(TE,UFOF("Audio's constructor.")));
}

SV Audio_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Audio");
EI(keyStr=="__new__")
R CNF(Audio_new);
EI(keyStr=="__call__")
R CNF(Audio_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(Audio_new);
 EI(keyStr == "removeContent")
R CNF(Audio_removeContent);
 EI(keyStr == "changeSampleFrequency")
R CNF(Audio_changeSampleFrequency);
 EI(keyStr == "getNumSamples")
R CNF(Audio_getNumSamples);
 EI(keyStr == "getSample")
R CNF(Audio_getSample);
 EI(keyStr == "getMonoSample")
R CNF(Audio_getMonoSample);
 EI(keyStr == "setSample")
R CNF(Audio_setSample);
 EI(keyStr == "setMonoSample")
R CNF(Audio_setMonoSample);
 EI(keyStr == "getDuration")
R CNF(Audio_getDuration);
 EI(keyStr == "getSampleIndex")
R CNF(Audio_getSampleIndex);
 EI(keyStr == "load")
R CNF(Audio_load);
 EI(keyStr == "reload")
R CNF(Audio_reload);
 EI(keyStr == "save")
R CNF(Audio_save);
 EI(keyStr == "copy")
R CNF(Audio_copy);
 EI(keyStr == "getType")
R CNF(Audio_getType);
 EI(keyStr == "isLoaded")
R CNF(Audio_isLoaded);
 EI(keyStr == "getLastFileModification")
R CNF(Audio_getLastFileModification);
 EI(keyStr == "shouldReload")
R CNF(Audio_shouldReload);
 EI(keyStr == "possiblyReload")
R CNF(Audio_possiblyReload);
 EI(keyStr == "release")
R CNF(Audio_release);
 EI(keyStr == "getRefCount")
R CNF(Audio_getRefCount);
 EI(keyStr == "getFilename")
R CNF(Audio_getFilename);
 EI(keyStr == "setFilename")
R CNF(Audio_setFilename);
 EI(keyStr=="frequency")
{
Audio*obj=(Audio*)F->data;
R CV(obj->frequency);
} EI(keyStr=="autoReload")
{
Audio*obj=(Audio*)F->data;
R CV(obj->autoReload);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void Audio_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="frequency")
{
Audio*obj=(Audio*)F->data;
obj->frequency=val_to_c<decltype(obj->frequency)>::f(ctx,value);
} EI(keyStr=="autoReload")
{
Audio*obj=(Audio*)F->data;
obj->autoReload=val_to_c<decltype(obj->autoReload)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV Audio_load(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::load" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::load","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->load());
R CN;
}
CATE(TE,UFOF("Audio::load.")));
R CN;
}

SV Audio_changeSampleFrequency(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::changeSampleFrequency" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::changeSampleFrequency","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==4)
if(1&&TS(a[1],size_t)&&TS(a[2],size_t)&&TS(a[3],size_t))
{
R CV( F->changeSampleFrequency(val_to_c<size_t>::f(ctx,a[1]), val_to_c<size_t>::f(ctx,a[2]), val_to_c<size_t>::f(ctx,a[3])));
;
}
CATE(TE,UFOF("Audio::changeSampleFrequency.")));
R CN;
}

SV Audio_possiblyReload(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::possiblyReload" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::possiblyReload","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->possiblyReload());
R CN;
}
CATE(TE,UFOF("Audio::possiblyReload.")));
R CN;
}

SV Audio_setFilename(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::setFilename" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::setFilename","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const String &))
{
( F->setFilename(val_to_c<const String &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("Audio::setFilename.")));
R CN;
}

SV Audio_isLoaded(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::isLoaded" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::isLoaded","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->isLoaded());
;
}
CATE(TE,UFOF("Audio::isLoaded.")));
R CN;
}

SV Audio_getFilename(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::getFilename" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::getFilename","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getFilename());
;
}
CATE(TE,UFOF("Audio::getFilename.")));
R CN;
}

SV Audio_getMonoSample(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::getMonoSample" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::getMonoSample","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],size_t))
{
R CV( F->getMonoSample(val_to_c<size_t>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Audio::getMonoSample.")));
R CN;
}

SV Audio_getLastFileModification(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::getLastFileModification" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::getLastFileModification","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getLastFileModification());
;
}
CATE(TE,UFOF("Audio::getLastFileModification.")));
R CN;
}

SV Audio_shouldReload(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::shouldReload" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::shouldReload","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->shouldReload());
;
}
CATE(TE,UFOF("Audio::shouldReload.")));
R CN;
}

SV Audio_save(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::save" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::save","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->save());
R CN;
}
CATE(TE,UFOF("Audio::save.")));
R CN;
}

SV Audio_getSampleIndex(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::getSampleIndex" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::getSampleIndex","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
R CV( F->getSampleIndex(val_to_c<float>::f(ctx,a[1])));
;
}
if(a.getCount()==4)
if(1&&TS(a[1],size_t)&&TS(a[2],size_t)&&TS(a[3],float))
{
R CV( F->getSampleIndex(val_to_c<size_t>::f(ctx,a[1]), val_to_c<size_t>::f(ctx,a[2]), val_to_c<float>::f(ctx,a[3])));
;
}
CATE(TE,UFOF("Audio::getSampleIndex.")));
R CN;
}

SV Audio_getRefCount(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::getRefCount" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::getRefCount","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getRefCount());
;
}
CATE(TE,UFOF("Audio::getRefCount.")));
R CN;
}

SV Audio_getType(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::getType" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::getType","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getType());
;
}
CATE(TE,UFOF("Audio::getType.")));
R CN;
}

SV Audio_removeContent(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::removeContent" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::removeContent","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->removeContent());
R CN;
}
if(a.getCount()==1)
if(1)
{
( F->removeContent());
R CN;
}
CATE(TE,UFOF("Audio::removeContent.")));
R CN;
}

SV Audio_getDuration(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::getDuration" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::getDuration","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getDuration());
;
}
CATE(TE,UFOF("Audio::getDuration.")));
R CN;
}

SV Audio_getNumSamples(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::getNumSamples" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::getNumSamples","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getNumSamples());
;
}
CATE(TE,UFOF("Audio::getNumSamples.")));
R CN;
}

SV Audio_copy(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::copy" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::copy","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->copy());
;
}
CATE(TE,UFOF("Audio::copy.")));
R CN;
}

SV Audio_getSample(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::getSample" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::getSample","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],size_t))
{
R CV( F->getSample(val_to_c<size_t>::f(ctx,a[1]), val_to_c<size_t>::f(ctx,a[2])));
;
}
CATE(TE,UFOF("Audio::getSample.")));
R CN;
}

SV Audio_setMonoSample(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::setMonoSample" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::setMonoSample","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],size_t)&&TS(a[2],float))
{
( F->setMonoSample(val_to_c<size_t>::f(ctx,a[1]), val_to_c<float>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("Audio::setMonoSample.")));
R CN;
}

SV Audio_reload(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::reload" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::reload","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->reload());
R CN;
}
CATE(TE,UFOF("Audio::reload.")));
R CN;
}

SV Audio_release(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::release" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::release","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->release());
R CN;
}
CATE(TE,UFOF("Audio::release.")));
R CN;
}

SV Audio_setSample(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Audio::setSample" EAOE));
Audio*F;
if(!TS(a[0],Audio))
CATE(TE,FAE("Audio::setSample","Audio")));
else
 F=(Audio*)((NO)a[0])->data;

if(a.getCount()==4)
if(1&&TS(a[1],size_t)&&TS(a[2],size_t)&&TS(a[3],float))
{
( F->setSample(val_to_c<size_t>::f(ctx,a[1]), val_to_c<size_t>::f(ctx,a[2]), val_to_c<float>::f(ctx,a[3])));
R CN;
}
CATE(TE,UFOF("Audio::setSample.")));
R CN;
}

void GfxSubModelList_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,List<GfxModel::SubModel>))
CATE(TE,"GfxSubModelList::__del__ expects GfxSubModelList as first argument."));

DELETE((List<GfxModel::SubModel>*)F->data);
}SV GfxSubModelList_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxSubModelList's constructor" EAOE));
if(!TS(a[0],List<GfxModel::SubModel>))
CATE(TE,"GfxSubModelList's constructor expects GfxSubModelList as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(GfxSubModelList_funcs,NEW(List<GfxModel::SubModel>),EXT->GfxSubModelList_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],std::size_t))
R S::createNativeObject(GfxSubModelList_funcs,NEW(List<GfxModel::SubModel>,val_to_c<std::size_t>::f(ctx,a[1])),EXT->GfxSubModelList_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const List<GfxModel::SubModel> &))
R S::createNativeObject(GfxSubModelList_funcs,NEW(List<GfxModel::SubModel>,val_to_c<const List<GfxModel::SubModel> &>::f(ctx,a[1])),EXT->GfxSubModelList_typeID);
CATE(TE,UFOF("GfxSubModelList's constructor.")));
R CN;
}

SV GfxSubModelList_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxSubModelList");
EI(keyStr=="__new__")
R CNF(GfxSubModelList_new);
EI(keyStr=="__call__")
R CNF(GfxSubModelList_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(GfxSubModelList_new);
 EI(keyStr == "__eq__")
R CNF(GfxSubModelList___eq__);
 EI(keyStr == "__neq__")
R CNF(GfxSubModelList___neq__);
 EI(keyStr == "getCount")
R CNF(GfxSubModelList_getCount);
 EI(keyStr == "getData")
R CNF(GfxSubModelList_getData);
 EI(keyStr == "append")
R CNF(GfxSubModelList_append);
 EI(keyStr == "insert")
R CNF(GfxSubModelList_insert);
 EI(keyStr == "remove")
R CNF(GfxSubModelList_remove);
 EI(keyStr == "clear")
R CNF(GfxSubModelList_clear);
 EI(keyStr == "find")
R CNF(GfxSubModelList_find);
 EI(keyStr == "copy")
R CNF(GfxSubModelList_copy);
 EI(keyStr == "in")
R CNF(GfxSubModelList_in);
 else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void GfxSubModelList_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV GfxSubModelList_insert(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxSubModelList::insert" EAOE));
List<GfxModel::SubModel>*F;
if(!TS(a[0],List<GfxModel::SubModel>))
CATE(TE,FAE("GfxSubModelList::insert","GfxSubModelList")));
else
 F=(List<GfxModel::SubModel>*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],std::size_t)&&TS(a[2],const GfxModel::SubModel&))
{
( F->insert(val_to_c<std::size_t>::f(ctx,a[1]), val_to_c<const GfxModel::SubModel&>::f(ctx,a[2])));
R CN;
}
if(a.getCount()==3)
if(1&&TS(a[1],std::size_t)&&TS(a[2],const List<GfxModel::SubModel> &))
{
( F->insert(val_to_c<std::size_t>::f(ctx,a[1]), val_to_c<const List<GfxModel::SubModel> &>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("GfxSubModelList::insert.")));
R CN;
}

SV GfxSubModelList_copy(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxSubModelList::copy" EAOE));
List<GfxModel::SubModel>*F;
if(!TS(a[0],List<GfxModel::SubModel>))
CATE(TE,FAE("GfxSubModelList::copy","GfxSubModelList")));
else
 F=(List<GfxModel::SubModel>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->copy());
;
}
CATE(TE,UFOF("GfxSubModelList::copy.")));
R CN;
}

SV GfxSubModelList_clear(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxSubModelList::clear" EAOE));
List<GfxModel::SubModel>*F;
if(!TS(a[0],List<GfxModel::SubModel>))
CATE(TE,FAE("GfxSubModelList::clear","GfxSubModelList")));
else
 F=(List<GfxModel::SubModel>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->clear());
R CN;
}
CATE(TE,UFOF("GfxSubModelList::clear.")));
R CN;
}

SV GfxSubModelList_remove(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxSubModelList::remove" EAOE));
List<GfxModel::SubModel>*F;
if(!TS(a[0],List<GfxModel::SubModel>))
CATE(TE,FAE("GfxSubModelList::remove","GfxSubModelList")));
else
 F=(List<GfxModel::SubModel>*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(a[1],std::size_t)&&TS(a[2],std::size_t))
{
( F->remove(val_to_c<std::size_t>::f(ctx,a[1]), val_to_c<std::size_t>::f(ctx,a[2])));
R CN;
}
CATE(TE,UFOF("GfxSubModelList::remove.")));
R CN;
}

SV GfxSubModelList_in(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxSubModelList::in" EAOE));
List<GfxModel::SubModel>*F;
if(!TS(a[0],List<GfxModel::SubModel>))
CATE(TE,FAE("GfxSubModelList::in","GfxSubModelList")));
else
 F=(List<GfxModel::SubModel>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const GfxModel::SubModel&))
{
R CV( F->in(val_to_c<const GfxModel::SubModel&>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("GfxSubModelList::in.")));
R CN;
}

SV GfxSubModelList_getCount(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxSubModelList::getCount" EAOE));
List<GfxModel::SubModel>*F;
if(!TS(a[0],List<GfxModel::SubModel>))
CATE(TE,FAE("GfxSubModelList::getCount","GfxSubModelList")));
else
 F=(List<GfxModel::SubModel>*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getCount());
;
}
CATE(TE,UFOF("GfxSubModelList::getCount.")));
R CN;
}

SV GfxSubModelList_getData(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxSubModelList::getData" EAOE));
List<GfxModel::SubModel>*F;
if(!TS(a[0],List<GfxModel::SubModel>))
CATE(TE,FAE("GfxSubModelList::getData","GfxSubModelList")));
else
 F=(List<GfxModel::SubModel>*)((NO)a[0])->data;

CATE(TE,UFOF("GfxSubModelList::getData.")));
R CN;
}

SV GfxSubModelList___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxSubModelList::__eq__" EAOE));
List<GfxModel::SubModel>*F;
if(!TS(a[0],List<GfxModel::SubModel>))
CATE(TE,FAE("GfxSubModelList::__eq__","GfxSubModelList")));
else
 F=(List<GfxModel::SubModel>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const List<GfxModel::SubModel> &))
{
auto v=val_to_c<const List<GfxModel::SubModel> &>::f(ctx,a[1]);
R CV(*F == v);
}
CATE(TE,UFOF("GfxSubModelList::__eq__.")));
R CN;
}

SV GfxSubModelList_find(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxSubModelList::find" EAOE));
List<GfxModel::SubModel>*F;
if(!TS(a[0],List<GfxModel::SubModel>))
CATE(TE,FAE("GfxSubModelList::find","GfxSubModelList")));
else
 F=(List<GfxModel::SubModel>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const GfxModel::SubModel&))
{
R CV( F->find(val_to_c<const GfxModel::SubModel&>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("GfxSubModelList::find.")));
R CN;
}

SV GfxSubModelList_append(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxSubModelList::append" EAOE));
List<GfxModel::SubModel>*F;
if(!TS(a[0],List<GfxModel::SubModel>))
CATE(TE,FAE("GfxSubModelList::append","GfxSubModelList")));
else
 F=(List<GfxModel::SubModel>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const GfxModel::SubModel&))
{
( F->append(val_to_c<const GfxModel::SubModel&>::f(ctx,a[1])));
R CN;
}
if(a.getCount()==2)
if(1&&TS(a[1],const List<GfxModel::SubModel> &))
{
( F->append(val_to_c<const List<GfxModel::SubModel> &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("GfxSubModelList::append.")));
R CN;
}

SV GfxSubModelList___neq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxSubModelList::__neq__" EAOE));
List<GfxModel::SubModel>*F;
if(!TS(a[0],List<GfxModel::SubModel>))
CATE(TE,FAE("GfxSubModelList::__neq__","GfxSubModelList")));
else
 F=(List<GfxModel::SubModel>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const List<GfxModel::SubModel> &))
{
auto v=val_to_c<const List<GfxModel::SubModel> &>::f(ctx,a[1]);
R CV(*F != v);
}
CATE(TE,UFOF("GfxSubModelList::__neq__.")));
R CN;
}

void GfxModel_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,GfxModel))
CATE(TE,"GfxModel::__del__ expects GfxModel as first argument."));

GfxModel*obj=(GfxModel*)F->data;
obj->release();
}SV GfxModel_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"GfxModel's constructor" EAOE));
if(!TS(a[0],GfxModel))
CATE(TE,"GfxModel's constructor expects GfxModel as first argument."));
CATE(TE,UFOF("GfxModel's constructor.")));
}

SV GfxModel_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxModel");
EI(keyStr=="__new__")
R CNF(GfxModel_new);
EI(keyStr=="__call__")
R CNF(GfxModel_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(GfxModel_new);
 EI(keyStr == "removeContent")
R CNF(GfxModel_removeContent);
 EI(keyStr == "save")
R CNF(GfxModel_save);
 EI(keyStr == "load")
R CNF(GfxModel_load);
 EI(keyStr == "reload")
R CNF(GfxModel_reload);
 EI(keyStr == "copy")
R CNF(GfxModel_copy);
 EI(keyStr == "getType")
R CNF(GfxModel_getType);
 EI(keyStr == "isLoaded")
R CNF(GfxModel_isLoaded);
 EI(keyStr == "getLastFileModification")
R CNF(GfxModel_getLastFileModification);
 EI(keyStr == "shouldReload")
R CNF(GfxModel_shouldReload);
 EI(keyStr == "possiblyReload")
R CNF(GfxModel_possiblyReload);
 EI(keyStr == "release")
R CNF(GfxModel_release);
 EI(keyStr == "getRefCount")
R CNF(GfxModel_getRefCount);
 EI(keyStr == "getFilename")
R CNF(GfxModel_getFilename);
 EI(keyStr == "setFilename")
R CNF(GfxModel_setFilename);
 EI(keyStr=="subModels")
{
GfxModel*obj=(GfxModel*)F->data;
R CV(obj->subModels);
} EI(keyStr=="autoReload")
{
GfxModel*obj=(GfxModel*)F->data;
R CV(obj->autoReload);
} else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void GfxModel_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} EI(keyStr=="subModels")
{
GfxModel*obj=(GfxModel*)F->data;
obj->subModels=val_to_c<decltype(obj->subModels)>::f(ctx,value);
} EI(keyStr=="autoReload")
{
GfxModel*obj=(GfxModel*)F->data;
obj->autoReload=val_to_c<decltype(obj->autoReload)>::f(ctx,value);
} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV GfxModel_load(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxModel::load" EAOE));
GfxModel*F;
if(!TS(a[0],GfxModel))
CATE(TE,FAE("GfxModel::load","GfxModel")));
else
 F=(GfxModel*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->load());
R CN;
}
CATE(TE,UFOF("GfxModel::load.")));
R CN;
}

SV GfxModel_getFilename(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxModel::getFilename" EAOE));
GfxModel*F;
if(!TS(a[0],GfxModel))
CATE(TE,FAE("GfxModel::getFilename","GfxModel")));
else
 F=(GfxModel*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getFilename());
;
}
CATE(TE,UFOF("GfxModel::getFilename.")));
R CN;
}

SV GfxModel_copy(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxModel::copy" EAOE));
GfxModel*F;
if(!TS(a[0],GfxModel))
CATE(TE,FAE("GfxModel::copy","GfxModel")));
else
 F=(GfxModel*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->copy());
;
}
CATE(TE,UFOF("GfxModel::copy.")));
R CN;
}

SV GfxModel_getLastFileModification(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxModel::getLastFileModification" EAOE));
GfxModel*F;
if(!TS(a[0],GfxModel))
CATE(TE,FAE("GfxModel::getLastFileModification","GfxModel")));
else
 F=(GfxModel*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getLastFileModification());
;
}
CATE(TE,UFOF("GfxModel::getLastFileModification.")));
R CN;
}

SV GfxModel_possiblyReload(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxModel::possiblyReload" EAOE));
GfxModel*F;
if(!TS(a[0],GfxModel))
CATE(TE,FAE("GfxModel::possiblyReload","GfxModel")));
else
 F=(GfxModel*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->possiblyReload());
R CN;
}
CATE(TE,UFOF("GfxModel::possiblyReload.")));
R CN;
}

SV GfxModel_getType(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxModel::getType" EAOE));
GfxModel*F;
if(!TS(a[0],GfxModel))
CATE(TE,FAE("GfxModel::getType","GfxModel")));
else
 F=(GfxModel*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getType());
;
}
CATE(TE,UFOF("GfxModel::getType.")));
R CN;
}

SV GfxModel_setFilename(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxModel::setFilename" EAOE));
GfxModel*F;
if(!TS(a[0],GfxModel))
CATE(TE,FAE("GfxModel::setFilename","GfxModel")));
else
 F=(GfxModel*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const String &))
{
( F->setFilename(val_to_c<const String &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("GfxModel::setFilename.")));
R CN;
}

SV GfxModel_isLoaded(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxModel::isLoaded" EAOE));
GfxModel*F;
if(!TS(a[0],GfxModel))
CATE(TE,FAE("GfxModel::isLoaded","GfxModel")));
else
 F=(GfxModel*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->isLoaded());
;
}
CATE(TE,UFOF("GfxModel::isLoaded.")));
R CN;
}

SV GfxModel_reload(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxModel::reload" EAOE));
GfxModel*F;
if(!TS(a[0],GfxModel))
CATE(TE,FAE("GfxModel::reload","GfxModel")));
else
 F=(GfxModel*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->reload());
R CN;
}
CATE(TE,UFOF("GfxModel::reload.")));
R CN;
}

SV GfxModel_removeContent(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxModel::removeContent" EAOE));
GfxModel*F;
if(!TS(a[0],GfxModel))
CATE(TE,FAE("GfxModel::removeContent","GfxModel")));
else
 F=(GfxModel*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->removeContent());
R CN;
}
if(a.getCount()==1)
if(1)
{
( F->removeContent());
R CN;
}
CATE(TE,UFOF("GfxModel::removeContent.")));
R CN;
}

SV GfxModel_getRefCount(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxModel::getRefCount" EAOE));
GfxModel*F;
if(!TS(a[0],GfxModel))
CATE(TE,FAE("GfxModel::getRefCount","GfxModel")));
else
 F=(GfxModel*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->getRefCount());
;
}
CATE(TE,UFOF("GfxModel::getRefCount.")));
R CN;
}

SV GfxModel_release(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxModel::release" EAOE));
GfxModel*F;
if(!TS(a[0],GfxModel))
CATE(TE,FAE("GfxModel::release","GfxModel")));
else
 F=(GfxModel*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->release());
R CN;
}
CATE(TE,UFOF("GfxModel::release.")));
R CN;
}

SV GfxModel_shouldReload(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxModel::shouldReload" EAOE));
GfxModel*F;
if(!TS(a[0],GfxModel))
CATE(TE,FAE("GfxModel::shouldReload","GfxModel")));
else
 F=(GfxModel*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->shouldReload());
;
}
CATE(TE,UFOF("GfxModel::shouldReload.")));
R CN;
}

SV GfxModel_save(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxModel::save" EAOE));
GfxModel*F;
if(!TS(a[0],GfxModel))
CATE(TE,FAE("GfxModel::save","GfxModel")));
else
 F=(GfxModel*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
( F->save());
R CN;
}
if(a.getCount()==1)
if(1)
{
( F->save());
R CN;
}
CATE(TE,UFOF("GfxModel::save.")));
R CN;
}

void Matrix3x3_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,Matrix3x3))
CATE(TE,"Matrix3x3::__del__ expects Matrix3x3 as first argument."));

DELETE((Matrix3x3*)F->data);
}SV Matrix3x3_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix3x3's constructor" EAOE));
if(!TS(a[0],Matrix3x3))
CATE(TE,"Matrix3x3's constructor expects Matrix3x3 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Matrix3x3_funcs,NEW(Matrix3x3),EXT->Matrix3x3_typeID);
if(a.getCount()==2)
if(true&&TS(a[1],const Matrix4x4 &))
R S::createNativeObject(Matrix3x3_funcs,NEW(Matrix3x3,val_to_c<const Matrix4x4 &>::f(ctx,a[1])),EXT->Matrix3x3_typeID);
if(a.getCount()==4)
if(true&&TS(a[1],const Float3 &)&&TS(a[2],const Float3 &)&&TS(a[3],const Float3 &))
R S::createNativeObject(Matrix3x3_funcs,NEW(Matrix3x3,val_to_c<const Float3 &>::f(ctx,a[1]),val_to_c<const Float3 &>::f(ctx,a[2]),val_to_c<const Float3 &>::f(ctx,a[3])),EXT->Matrix3x3_typeID);
CATE(TE,UFOF("Matrix3x3's constructor.")));
R CN;
}

SV Matrix3x3_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Matrix3x3");
EI(keyStr=="__new__")
R CNF(Matrix3x3_new);
EI(keyStr=="__call__")
R CNF(Matrix3x3_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(Matrix3x3_new);
 EI(keyStr == "__mul__")
R CNF(Matrix3x3___mul__);
 EI(keyStr == "__div__")
R CNF(Matrix3x3___div__);
 EI(keyStr == "__eq__")
R CNF(Matrix3x3___eq__);
 EI(keyStr == "transpose")
R CNF(Matrix3x3_transpose);
 EI(keyStr == "inverse")
R CNF(Matrix3x3_inverse);
 EI(keyStr == "translate")
R CNF(Matrix3x3_translate);
 EI(keyStr == "scale")
R CNF(Matrix3x3_scale);
 EI(keyStr == "rotate")
R CNF(Matrix3x3_rotate);
 EI(keyStr == "rotatex")
R CNF(Matrix3x3_rotatex);
 EI(keyStr == "rotatey")
R CNF(Matrix3x3_rotatey);
 EI(keyStr == "rotatez")
R CNF(Matrix3x3_rotatez);
 else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void Matrix3x3_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV Matrix3x3_inverse(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix3x3::inverse" EAOE));
Matrix3x3*F;
if(!TS(a[0],Matrix3x3))
CATE(TE,FAE("Matrix3x3::inverse","Matrix3x3")));
else
 F=(Matrix3x3*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->inverse());
;
}
CATE(TE,UFOF("Matrix3x3::inverse.")));
R CN;
}

SV Matrix3x3_transpose(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix3x3::transpose" EAOE));
Matrix3x3*F;
if(!TS(a[0],Matrix3x3))
CATE(TE,FAE("Matrix3x3::transpose","Matrix3x3")));
else
 F=(Matrix3x3*)((NO)a[0])->data;

if(a.getCount()==1)
if(1)
{
R CV( F->transpose());
;
}
CATE(TE,UFOF("Matrix3x3::transpose.")));
R CN;
}

SV Matrix3x3_rotatez(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix3x3::rotatez" EAOE));
Matrix3x3*F;
if(!TS(a[0],Matrix3x3))
CATE(TE,FAE("Matrix3x3::rotatez","Matrix3x3")));
else
 F=(Matrix3x3*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
R CV( F->rotatez(val_to_c<float>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Matrix3x3::rotatez.")));
R CN;
}

SV Matrix3x3_rotatex(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix3x3::rotatex" EAOE));
Matrix3x3*F;
if(!TS(a[0],Matrix3x3))
CATE(TE,FAE("Matrix3x3::rotatex","Matrix3x3")));
else
 F=(Matrix3x3*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
R CV( F->rotatex(val_to_c<float>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Matrix3x3::rotatex.")));
R CN;
}

SV Matrix3x3_rotatey(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix3x3::rotatey" EAOE));
Matrix3x3*F;
if(!TS(a[0],Matrix3x3))
CATE(TE,FAE("Matrix3x3::rotatey","Matrix3x3")));
else
 F=(Matrix3x3*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
R CV( F->rotatey(val_to_c<float>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Matrix3x3::rotatey.")));
R CN;
}

SV Matrix3x3___div__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix3x3::__div__" EAOE));
Matrix3x3*F;
if(!TS(a[0],Matrix3x3))
CATE(TE,FAE("Matrix3x3::__div__","Matrix3x3")));
else
 F=(Matrix3x3*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
auto v=val_to_c<float>::f(ctx,a[1]);
R CV(*F / v);
}
CATE(TE,UFOF("Matrix3x3::__div__.")));
R CN;
}

SV Matrix3x3_scale(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix3x3::scale" EAOE));
Matrix3x3*F;
if(!TS(a[0],Matrix3x3))
CATE(TE,FAE("Matrix3x3::scale","Matrix3x3")));
else
 F=(Matrix3x3*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Float3 &))
{
R CV( F->scale(val_to_c<const Float3 &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Matrix3x3::scale.")));
R CN;
}

SV Matrix3x3___mul__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix3x3::__mul__" EAOE));
Matrix3x3*F;
if(!TS(a[0],Matrix3x3))
CATE(TE,FAE("Matrix3x3::__mul__","Matrix3x3")));
else
 F=(Matrix3x3*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Matrix3x3 &))
{
auto v=val_to_c<const Matrix3x3 &>::f(ctx,a[1]);
R CV(*F * v);
}
if(a.getCount()==2)
if(1&&TS(a[1],const Float3 &))
{
auto v=val_to_c<const Float3 &>::f(ctx,a[1]);
R CV(*F * v);
}
CATE(TE,UFOF("Matrix3x3::__mul__.")));
R CN;
}

SV Matrix3x3_translate(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix3x3::translate" EAOE));
Matrix3x3*F;
if(!TS(a[0],Matrix3x3))
CATE(TE,FAE("Matrix3x3::translate","Matrix3x3")));
else
 F=(Matrix3x3*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Float2 &))
{
R CV( F->translate(val_to_c<const Float2 &>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Matrix3x3::translate.")));
R CN;
}

SV Matrix3x3___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix3x3::__eq__" EAOE));
Matrix3x3*F;
if(!TS(a[0],Matrix3x3))
CATE(TE,FAE("Matrix3x3::__eq__","Matrix3x3")));
else
 F=(Matrix3x3*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Matrix3x3 &))
{
auto v=val_to_c<const Matrix3x3 &>::f(ctx,a[1]);
R CV(*F == v);
}
CATE(TE,UFOF("Matrix3x3::__eq__.")));
R CN;
}

SV Matrix3x3_rotate(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix3x3::rotate" EAOE));
Matrix3x3*F;
if(!TS(a[0],Matrix3x3))
CATE(TE,FAE("Matrix3x3::rotate","Matrix3x3")));
else
 F=(Matrix3x3*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],float))
{
R CV( F->rotate(val_to_c<float>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Matrix3x3::rotate.")));
R CN;
}

void GfxDebugDrawer_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,GfxDebugDrawer))
CATE(TE,"GfxDebugDrawer::__del__ expects GfxDebugDrawer as first argument."));

DELETE((GfxDebugDrawer*)F->data);
}SV GfxDebugDrawer_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxDebugDrawer's constructor" EAOE));
if(!TS(a[0],GfxDebugDrawer))
CATE(TE,"GfxDebugDrawer's constructor expects GfxDebugDrawer as first argument."));
CATE(TE,UFOF("GfxDebugDrawer's constructor.")));
R CN;
}

SV GfxDebugDrawer_get_member(CTX ctx,NO F,SV key)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxDebugDrawer");
EI(keyStr=="__new__")
R CNF(GfxDebugDrawer_new);
EI(keyStr=="__call__")
R CNF(GfxDebugDrawer_new);
else
 CATE(KE,"Unknown member."));
} else
{
if(keyStr=="__classTypeID__")
R S::createInt(F->typeID);
EI(keyStr=="__init__")
R CNF(GfxDebugDrawer_new);
 EI(keyStr == "addLine")
R CNF(GfxDebugDrawer_addLine);
 EI(keyStr == "render")
R CNF(GfxDebugDrawer_render);
 else
 CATE(KE,"Unknown member."));
}
}
R CN;
}

void GfxDebugDrawer_set_member(CTX ctx,NO F,SV key,SV value)
{
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue*)key)->value;
if(F->data==NULL)
CATE(KE,"Native classes are read-only."));
else
{
if(0) {} else
 CATE(KE,"Unknown member or member if read-only."));
}
}
}

SV GfxDebugDrawer_addLine(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxDebugDrawer::addLine" EAOE));
GfxDebugDrawer*F;
if(!TS(a[0],GfxDebugDrawer))
CATE(TE,FAE("GfxDebugDrawer::addLine","GfxDebugDrawer")));
else
 F=(GfxDebugDrawer*)((NO)a[0])->data;

if(a.getCount()==5)
if(1&&TS(a[1],const Position3D &)&&TS(a[2],const Position3D &)&&TS(a[3],const Float4 &)&&TS(a[4],const Float4 &))
{
( F->addLine(val_to_c<const Position3D &>::f(ctx,a[1]), val_to_c<const Position3D &>::f(ctx,a[2]), val_to_c<const Float4 &>::f(ctx,a[3]), val_to_c<const Float4 &>::f(ctx,a[4])));
R CN;
}
CATE(TE,UFOF("GfxDebugDrawer::addLine.")));
R CN;
}

SV GfxDebugDrawer_render(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"GfxDebugDrawer::render" EAOE));
GfxDebugDrawer*F;
if(!TS(a[0],GfxDebugDrawer))
CATE(TE,FAE("GfxDebugDrawer::render","GfxDebugDrawer")));
else
 F=(GfxDebugDrawer*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(a[1],const Camera &))
{
( F->render(val_to_c<const Camera &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("GfxDebugDrawer::render.")));
R CN;
}

SV Filesystem_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->Filesystem;
NO obj=(NO)Filesystem_new(ctx, args2);
obj->funcs=Filesystem_ptr_funcs;
obj->typeID=EXT->Filesystem_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV Filesystem_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"FilesystemRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,Filesystem*))
CATE(TE,"FilesystemRef::deref expects FilesystemRef as first argument."));
R CV(*(Filesystem *)((NO)F)->data);
}
SV Filesystem_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Filesystem::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,Filesystem*))
CATE(TE,"FilesystemRef::refset expects FilesystemRef as first argument."));
*((Filesystem *)((NO)F)->data) = val_to_c<Filesystem>::f(ctx,a[1]);
R CN;
}

void Filesystem_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,Filesystem*))
CATE(TE,"FilesystemRef::__del__ expects FilesystemRef as first argument."));
SCRIPT_DELETE((Filesystem *)F->data);
}
SV Filesystem_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,Filesystem*))
CATE(TE,FAE("FilesystemRef's get method","FilesystemRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("FilesystemPtr");
EI(keyStr=="__new__")
R CNF(Filesystem_ptr_new);
EI(keyStr=="__call__")
R CNF(Filesystem_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(Filesystem_ptr_deref);
if(keyStr=="refset")R CNF(Filesystem_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Filesystem_funcs;
obj.typeID=EXT->Filesystem_typeID;
obj.refCount=1;
obj.data=F->data;
R Filesystem_get_member(ctx, &obj, key);
}
void Filesystem_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,Filesystem*))
CATE(TE,FAE("FilesystemRef's set method","FilesystemRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Filesystem_funcs;
obj.typeID=EXT->Filesystem_typeID;
obj.refCount=1;
obj.data=F->data;
Filesystem_set_member(ctx, &obj, key, value);
}
SV GfxCompiledShader_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->GfxCompiledShader;
NO obj=(NO)GfxCompiledShader_new(ctx, args2);
obj->funcs=GfxCompiledShader_ptr_funcs;
obj->typeID=EXT->GfxCompiledShader_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV GfxCompiledShader_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"GfxCompiledShaderRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,GfxCompiledShader*))
CATE(TE,"GfxCompiledShaderRef::deref expects GfxCompiledShaderRef as first argument."));
CATE(TE,"GfxCompiledShader objects are not copyable."));
}
SV GfxCompiledShader_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"GfxCompiledShader::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,GfxCompiledShader*))
CATE(TE,"GfxCompiledShaderRef::refset expects GfxCompiledShaderRef as first argument."));
CATE(TE,"GfxCompiledShader objects are not copyable."));
R CN;
}

void GfxCompiledShader_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,GfxCompiledShader*))
CATE(TE,"GfxCompiledShaderRef::__del__ expects GfxCompiledShaderRef as first argument."));
SCRIPT_DELETE((GfxCompiledShader *)F->data);
}
SV GfxCompiledShader_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,GfxCompiledShader*))
CATE(TE,FAE("GfxCompiledShaderRef's get method","GfxCompiledShaderRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxCompiledShaderPtr");
EI(keyStr=="__new__")
R CNF(GfxCompiledShader_ptr_new);
EI(keyStr=="__call__")
R CNF(GfxCompiledShader_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(GfxCompiledShader_ptr_deref);
if(keyStr=="refset")R CNF(GfxCompiledShader_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=GfxCompiledShader_funcs;
obj.typeID=EXT->GfxCompiledShader_typeID;
obj.refCount=1;
obj.data=F->data;
R GfxCompiledShader_get_member(ctx, &obj, key);
}
void GfxCompiledShader_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,GfxCompiledShader*))
CATE(TE,FAE("GfxCompiledShaderRef's set method","GfxCompiledShaderRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=GfxCompiledShader_funcs;
obj.typeID=EXT->GfxCompiledShader_typeID;
obj.refCount=1;
obj.data=F->data;
GfxCompiledShader_set_member(ctx, &obj, key, value);
}
SV UInt2_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->UInt2;
NO obj=(NO)UInt2_new(ctx, args2);
obj->funcs=UInt2_ptr_funcs;
obj->typeID=EXT->UInt2_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV UInt2_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"UInt2Ref::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,T2<uint32_t>*))
CATE(TE,"UInt2Ref::deref expects UInt2Ref as first argument."));
R CV(*(T2<uint32_t> *)((NO)F)->data);
}
SV UInt2_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"UInt2::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,T2<uint32_t>*))
CATE(TE,"UInt2Ref::refset expects UInt2Ref as first argument."));
*((T2<uint32_t> *)((NO)F)->data) = val_to_c<T2<uint32_t>>::f(ctx,a[1]);
R CN;
}

void UInt2_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,T2<uint32_t>*))
CATE(TE,"UInt2Ref::__del__ expects UInt2Ref as first argument."));
SCRIPT_DELETE((T2<uint32_t> *)F->data);
}
SV UInt2_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,T2<uint32_t>*))
CATE(TE,FAE("UInt2Ref's get method","UInt2Ref")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("UInt2Ptr");
EI(keyStr=="__new__")
R CNF(UInt2_ptr_new);
EI(keyStr=="__call__")
R CNF(UInt2_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(UInt2_ptr_deref);
if(keyStr=="refset")R CNF(UInt2_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=UInt2_funcs;
obj.typeID=EXT->UInt2_typeID;
obj.refCount=1;
obj.data=F->data;
R UInt2_get_member(ctx, &obj, key);
}
void UInt2_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,T2<uint32_t>*))
CATE(TE,FAE("UInt2Ref's set method","UInt2Ref")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=UInt2_funcs;
obj.typeID=EXT->UInt2_typeID;
obj.refCount=1;
obj.data=F->data;
UInt2_set_member(ctx, &obj, key, value);
}
SV GPUTimer_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->GPUTimer;
NO obj=(NO)GPUTimer_new(ctx, args2);
obj->funcs=GPUTimer_ptr_funcs;
obj->typeID=EXT->GPUTimer_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV GPUTimer_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"GPUTimerRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,GPUTimer*))
CATE(TE,"GPUTimerRef::deref expects GPUTimerRef as first argument."));
CATE(TE,"GPUTimer objects are not copyable."));
}
SV GPUTimer_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"GPUTimer::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,GPUTimer*))
CATE(TE,"GPUTimerRef::refset expects GPUTimerRef as first argument."));
CATE(TE,"GPUTimer objects are not copyable."));
R CN;
}

void GPUTimer_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,GPUTimer*))
CATE(TE,"GPUTimerRef::__del__ expects GPUTimerRef as first argument."));
SCRIPT_DELETE((GPUTimer *)F->data);
}
SV GPUTimer_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,GPUTimer*))
CATE(TE,FAE("GPUTimerRef's get method","GPUTimerRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GPUTimerPtr");
EI(keyStr=="__new__")
R CNF(GPUTimer_ptr_new);
EI(keyStr=="__call__")
R CNF(GPUTimer_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(GPUTimer_ptr_deref);
if(keyStr=="refset")R CNF(GPUTimer_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=GPUTimer_funcs;
obj.typeID=EXT->GPUTimer_typeID;
obj.refCount=1;
obj.data=F->data;
R GPUTimer_get_member(ctx, &obj, key);
}
void GPUTimer_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,GPUTimer*))
CATE(TE,FAE("GPUTimerRef's set method","GPUTimerRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=GPUTimer_funcs;
obj.typeID=EXT->GPUTimer_typeID;
obj.refCount=1;
obj.data=F->data;
GPUTimer_set_member(ctx, &obj, key, value);
}
SV RigidBody_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->RigidBody;
NO obj=(NO)RigidBody_new(ctx, args2);
obj->funcs=RigidBody_ptr_funcs;
obj->typeID=EXT->RigidBody_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV RigidBody_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"RigidBodyRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,RigidBody*))
CATE(TE,"RigidBodyRef::deref expects RigidBodyRef as first argument."));
CATE(TE,"RigidBody objects are not copyable."));
}
SV RigidBody_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"RigidBody::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,RigidBody*))
CATE(TE,"RigidBodyRef::refset expects RigidBodyRef as first argument."));
CATE(TE,"RigidBody objects are not copyable."));
R CN;
}

void RigidBody_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,RigidBody*))
CATE(TE,"RigidBodyRef::__del__ expects RigidBodyRef as first argument."));
}
SV RigidBody_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,RigidBody*))
CATE(TE,FAE("RigidBodyRef's get method","RigidBodyRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("RigidBodyPtr");
EI(keyStr=="__new__")
R CNF(RigidBody_ptr_new);
EI(keyStr=="__call__")
R CNF(RigidBody_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(RigidBody_ptr_deref);
if(keyStr=="refset")R CNF(RigidBody_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=RigidBody_funcs;
obj.typeID=EXT->RigidBody_typeID;
obj.refCount=1;
obj.data=F->data;
R RigidBody_get_member(ctx, &obj, key);
}
void RigidBody_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,RigidBody*))
CATE(TE,FAE("RigidBodyRef's set method","RigidBodyRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=RigidBody_funcs;
obj.typeID=EXT->RigidBody_typeID;
obj.refCount=1;
obj.data=F->data;
RigidBody_set_member(ctx, &obj, key, value);
}
SV Float2_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->Float2;
NO obj=(NO)Float2_new(ctx, args2);
obj->funcs=Float2_ptr_funcs;
obj->typeID=EXT->Float2_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV Float2_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"Float2Ref::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,T2<float>*))
CATE(TE,"Float2Ref::deref expects Float2Ref as first argument."));
R CV(*(T2<float> *)((NO)F)->data);
}
SV Float2_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Float2::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,T2<float>*))
CATE(TE,"Float2Ref::refset expects Float2Ref as first argument."));
*((T2<float> *)((NO)F)->data) = val_to_c<T2<float>>::f(ctx,a[1]);
R CN;
}

void Float2_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,T2<float>*))
CATE(TE,"Float2Ref::__del__ expects Float2Ref as first argument."));
SCRIPT_DELETE((T2<float> *)F->data);
}
SV Float2_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,T2<float>*))
CATE(TE,FAE("Float2Ref's get method","Float2Ref")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Float2Ptr");
EI(keyStr=="__new__")
R CNF(Float2_ptr_new);
EI(keyStr=="__call__")
R CNF(Float2_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(Float2_ptr_deref);
if(keyStr=="refset")R CNF(Float2_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Float2_funcs;
obj.typeID=EXT->Float2_typeID;
obj.refCount=1;
obj.data=F->data;
R Float2_get_member(ctx, &obj, key);
}
void Float2_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,T2<float>*))
CATE(TE,FAE("Float2Ref's set method","Float2Ref")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Float2_funcs;
obj.typeID=EXT->Float2_typeID;
obj.refCount=1;
obj.data=F->data;
Float2_set_member(ctx, &obj, key, value);
}
SV AudioSource_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->AudioSource;
NO obj=(NO)AudioSource_new(ctx, args2);
obj->funcs=AudioSource_ptr_funcs;
obj->typeID=EXT->AudioSource_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV AudioSource_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"AudioSourceRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,AudioSource*))
CATE(TE,"AudioSourceRef::deref expects AudioSourceRef as first argument."));
R CV(*(AudioSource *)((NO)F)->data);
}
SV AudioSource_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"AudioSource::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,AudioSource*))
CATE(TE,"AudioSourceRef::refset expects AudioSourceRef as first argument."));
*((AudioSource *)((NO)F)->data) = val_to_c<AudioSource>::f(ctx,a[1]);
R CN;
}

void AudioSource_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,AudioSource*))
CATE(TE,"AudioSourceRef::__del__ expects AudioSourceRef as first argument."));
SCRIPT_DELETE((AudioSource *)F->data);
}
SV AudioSource_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,AudioSource*))
CATE(TE,FAE("AudioSourceRef's get method","AudioSourceRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("AudioSourcePtr");
EI(keyStr=="__new__")
R CNF(AudioSource_ptr_new);
EI(keyStr=="__call__")
R CNF(AudioSource_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(AudioSource_ptr_deref);
if(keyStr=="refset")R CNF(AudioSource_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=AudioSource_funcs;
obj.typeID=EXT->AudioSource_typeID;
obj.refCount=1;
obj.data=F->data;
R AudioSource_get_member(ctx, &obj, key);
}
void AudioSource_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,AudioSource*))
CATE(TE,FAE("AudioSourceRef's set method","AudioSourceRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=AudioSource_funcs;
obj.typeID=EXT->AudioSource_typeID;
obj.refCount=1;
obj.data=F->data;
AudioSource_set_member(ctx, &obj, key, value);
}
SV Camera_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->Camera;
NO obj=(NO)Camera_new(ctx, args2);
obj->funcs=Camera_ptr_funcs;
obj->typeID=EXT->Camera_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV Camera_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"CameraRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,Camera*))
CATE(TE,"CameraRef::deref expects CameraRef as first argument."));
R CV(*(Camera *)((NO)F)->data);
}
SV Camera_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Camera::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,Camera*))
CATE(TE,"CameraRef::refset expects CameraRef as first argument."));
*((Camera *)((NO)F)->data) = val_to_c<Camera>::f(ctx,a[1]);
R CN;
}

void Camera_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,Camera*))
CATE(TE,"CameraRef::__del__ expects CameraRef as first argument."));
SCRIPT_DELETE((Camera *)F->data);
}
SV Camera_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,Camera*))
CATE(TE,FAE("CameraRef's get method","CameraRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("CameraPtr");
EI(keyStr=="__new__")
R CNF(Camera_ptr_new);
EI(keyStr=="__call__")
R CNF(Camera_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(Camera_ptr_deref);
if(keyStr=="refset")R CNF(Camera_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Camera_funcs;
obj.typeID=EXT->Camera_typeID;
obj.refCount=1;
obj.data=F->data;
R Camera_get_member(ctx, &obj, key);
}
void Camera_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,Camera*))
CATE(TE,FAE("CameraRef's set method","CameraRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Camera_funcs;
obj.typeID=EXT->Camera_typeID;
obj.refCount=1;
obj.data=F->data;
Camera_set_member(ctx, &obj, key, value);
}
SV Resource_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->Resource;
NO obj=(NO)Resource_new(ctx, args2);
obj->funcs=Resource_ptr_funcs;
obj->typeID=EXT->Resource_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV Resource_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"ResourceRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,Resource*))
CATE(TE,"ResourceRef::deref expects ResourceRef as first argument."));
CATE(TE,"Resource objects are not copyable."));
}
SV Resource_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Resource::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,Resource*))
CATE(TE,"ResourceRef::refset expects ResourceRef as first argument."));
CATE(TE,"Resource objects are not copyable."));
R CN;
}

void Resource_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,Resource*))
CATE(TE,"ResourceRef::__del__ expects ResourceRef as first argument."));
Resource*obj=(Resource*)F->data;
if(shouldScriptDelete(F->data)) {obj->release();}
}
SV Resource_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,Resource*))
CATE(TE,FAE("ResourceRef's get method","ResourceRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("ResourcePtr");
EI(keyStr=="__new__")
R CNF(Resource_ptr_new);
EI(keyStr=="__call__")
R CNF(Resource_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(Resource_ptr_deref);
if(keyStr=="refset")R CNF(Resource_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Resource_funcs;
obj.typeID=EXT->Resource_typeID;
obj.refCount=1;
obj.data=F->data;
R Resource_get_member(ctx, &obj, key);
}
void Resource_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,Resource*))
CATE(TE,FAE("ResourceRef's set method","ResourceRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Resource_funcs;
obj.typeID=EXT->Resource_typeID;
obj.refCount=1;
obj.data=F->data;
Resource_set_member(ctx, &obj, key, value);
}
SV GfxShader_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->GfxShader;
NO obj=(NO)GfxShader_new(ctx, args2);
obj->funcs=GfxShader_ptr_funcs;
obj->typeID=EXT->GfxShader_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV GfxShader_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"GfxShaderRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,GfxShader*))
CATE(TE,"GfxShaderRef::deref expects GfxShaderRef as first argument."));
CATE(TE,"GfxShader objects are not copyable."));
}
SV GfxShader_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"GfxShader::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,GfxShader*))
CATE(TE,"GfxShaderRef::refset expects GfxShaderRef as first argument."));
CATE(TE,"GfxShader objects are not copyable."));
R CN;
}

void GfxShader_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,GfxShader*))
CATE(TE,"GfxShaderRef::__del__ expects GfxShaderRef as first argument."));
GfxShader*obj=(GfxShader*)F->data;
if(shouldScriptDelete(F->data)) {obj->release();}
}
SV GfxShader_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,GfxShader*))
CATE(TE,FAE("GfxShaderRef's get method","GfxShaderRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxShaderPtr");
EI(keyStr=="__new__")
R CNF(GfxShader_ptr_new);
EI(keyStr=="__call__")
R CNF(GfxShader_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(GfxShader_ptr_deref);
if(keyStr=="refset")R CNF(GfxShader_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=GfxShader_funcs;
obj.typeID=EXT->GfxShader_typeID;
obj.refCount=1;
obj.data=F->data;
R GfxShader_get_member(ctx, &obj, key);
}
void GfxShader_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,GfxShader*))
CATE(TE,FAE("GfxShaderRef's set method","GfxShaderRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=GfxShader_funcs;
obj.typeID=EXT->GfxShader_typeID;
obj.refCount=1;
obj.data=F->data;
GfxShader_set_member(ctx, &obj, key, value);
}
SV UInt4_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->UInt4;
NO obj=(NO)UInt4_new(ctx, args2);
obj->funcs=UInt4_ptr_funcs;
obj->typeID=EXT->UInt4_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV UInt4_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"UInt4Ref::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,T4<uint32_t>*))
CATE(TE,"UInt4Ref::deref expects UInt4Ref as first argument."));
R CV(*(T4<uint32_t> *)((NO)F)->data);
}
SV UInt4_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"UInt4::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,T4<uint32_t>*))
CATE(TE,"UInt4Ref::refset expects UInt4Ref as first argument."));
*((T4<uint32_t> *)((NO)F)->data) = val_to_c<T4<uint32_t>>::f(ctx,a[1]);
R CN;
}

void UInt4_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,T4<uint32_t>*))
CATE(TE,"UInt4Ref::__del__ expects UInt4Ref as first argument."));
SCRIPT_DELETE((T4<uint32_t> *)F->data);
}
SV UInt4_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,T4<uint32_t>*))
CATE(TE,FAE("UInt4Ref's get method","UInt4Ref")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("UInt4Ptr");
EI(keyStr=="__new__")
R CNF(UInt4_ptr_new);
EI(keyStr=="__call__")
R CNF(UInt4_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(UInt4_ptr_deref);
if(keyStr=="refset")R CNF(UInt4_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=UInt4_funcs;
obj.typeID=EXT->UInt4_typeID;
obj.refCount=1;
obj.data=F->data;
R UInt4_get_member(ctx, &obj, key);
}
void UInt4_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,T4<uint32_t>*))
CATE(TE,FAE("UInt4Ref's set method","UInt4Ref")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=UInt4_funcs;
obj.typeID=EXT->UInt4_typeID;
obj.refCount=1;
obj.data=F->data;
UInt4_set_member(ctx, &obj, key, value);
}
SV Int3_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->Int3;
NO obj=(NO)Int3_new(ctx, args2);
obj->funcs=Int3_ptr_funcs;
obj->typeID=EXT->Int3_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV Int3_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"Int3Ref::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,T3<int32_t>*))
CATE(TE,"Int3Ref::deref expects Int3Ref as first argument."));
R CV(*(T3<int32_t> *)((NO)F)->data);
}
SV Int3_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Int3::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,T3<int32_t>*))
CATE(TE,"Int3Ref::refset expects Int3Ref as first argument."));
*((T3<int32_t> *)((NO)F)->data) = val_to_c<T3<int32_t>>::f(ctx,a[1]);
R CN;
}

void Int3_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,T3<int32_t>*))
CATE(TE,"Int3Ref::__del__ expects Int3Ref as first argument."));
SCRIPT_DELETE((T3<int32_t> *)F->data);
}
SV Int3_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,T3<int32_t>*))
CATE(TE,FAE("Int3Ref's get method","Int3Ref")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Int3Ptr");
EI(keyStr=="__new__")
R CNF(Int3_ptr_new);
EI(keyStr=="__call__")
R CNF(Int3_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(Int3_ptr_deref);
if(keyStr=="refset")R CNF(Int3_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Int3_funcs;
obj.typeID=EXT->Int3_typeID;
obj.refCount=1;
obj.data=F->data;
R Int3_get_member(ctx, &obj, key);
}
void Int3_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,T3<int32_t>*))
CATE(TE,FAE("Int3Ref's set method","Int3Ref")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Int3_funcs;
obj.typeID=EXT->Int3_typeID;
obj.refCount=1;
obj.data=F->data;
Int3_set_member(ctx, &obj, key, value);
}
SV ResizableData_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->ResizableData;
NO obj=(NO)ResizableData_new(ctx, args2);
obj->funcs=ResizableData_ptr_funcs;
obj->typeID=EXT->ResizableData_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV ResizableData_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"ResizableDataRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,ResizableData*))
CATE(TE,"ResizableDataRef::deref expects ResizableDataRef as first argument."));
R CV(*(ResizableData *)((NO)F)->data);
}
SV ResizableData_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"ResizableData::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,ResizableData*))
CATE(TE,"ResizableDataRef::refset expects ResizableDataRef as first argument."));
*((ResizableData *)((NO)F)->data) = val_to_c<ResizableData>::f(ctx,a[1]);
R CN;
}

void ResizableData_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,ResizableData*))
CATE(TE,"ResizableDataRef::__del__ expects ResizableDataRef as first argument."));
SCRIPT_DELETE((ResizableData *)F->data);
}
SV ResizableData_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,ResizableData*))
CATE(TE,FAE("ResizableDataRef's get method","ResizableDataRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("ResizableDataPtr");
EI(keyStr=="__new__")
R CNF(ResizableData_ptr_new);
EI(keyStr=="__call__")
R CNF(ResizableData_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(ResizableData_ptr_deref);
if(keyStr=="refset")R CNF(ResizableData_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=ResizableData_funcs;
obj.typeID=EXT->ResizableData_typeID;
obj.refCount=1;
obj.data=F->data;
R ResizableData_get_member(ctx, &obj, key);
}
void ResizableData_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,ResizableData*))
CATE(TE,FAE("ResizableDataRef's set method","ResizableDataRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=ResizableData_funcs;
obj.typeID=EXT->ResizableData_typeID;
obj.refCount=1;
obj.data=F->data;
ResizableData_set_member(ctx, &obj, key, value);
}
SV Int4_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->Int4;
NO obj=(NO)Int4_new(ctx, args2);
obj->funcs=Int4_ptr_funcs;
obj->typeID=EXT->Int4_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV Int4_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"Int4Ref::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,T4<int32_t>*))
CATE(TE,"Int4Ref::deref expects Int4Ref as first argument."));
R CV(*(T4<int32_t> *)((NO)F)->data);
}
SV Int4_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Int4::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,T4<int32_t>*))
CATE(TE,"Int4Ref::refset expects Int4Ref as first argument."));
*((T4<int32_t> *)((NO)F)->data) = val_to_c<T4<int32_t>>::f(ctx,a[1]);
R CN;
}

void Int4_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,T4<int32_t>*))
CATE(TE,"Int4Ref::__del__ expects Int4Ref as first argument."));
SCRIPT_DELETE((T4<int32_t> *)F->data);
}
SV Int4_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,T4<int32_t>*))
CATE(TE,FAE("Int4Ref's get method","Int4Ref")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Int4Ptr");
EI(keyStr=="__new__")
R CNF(Int4_ptr_new);
EI(keyStr=="__call__")
R CNF(Int4_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(Int4_ptr_deref);
if(keyStr=="refset")R CNF(Int4_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Int4_funcs;
obj.typeID=EXT->Int4_typeID;
obj.refCount=1;
obj.data=F->data;
R Int4_get_member(ctx, &obj, key);
}
void Int4_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,T4<int32_t>*))
CATE(TE,FAE("Int4Ref's set method","Int4Ref")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Int4_funcs;
obj.typeID=EXT->Int4_typeID;
obj.refCount=1;
obj.data=F->data;
Int4_set_member(ctx, &obj, key, value);
}
SV Float3_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->Float3;
NO obj=(NO)Float3_new(ctx, args2);
obj->funcs=Float3_ptr_funcs;
obj->typeID=EXT->Float3_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV Float3_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"Float3Ref::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,T3<float>*))
CATE(TE,"Float3Ref::deref expects Float3Ref as first argument."));
R CV(*(T3<float> *)((NO)F)->data);
}
SV Float3_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Float3::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,T3<float>*))
CATE(TE,"Float3Ref::refset expects Float3Ref as first argument."));
*((T3<float> *)((NO)F)->data) = val_to_c<T3<float>>::f(ctx,a[1]);
R CN;
}

void Float3_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,T3<float>*))
CATE(TE,"Float3Ref::__del__ expects Float3Ref as first argument."));
SCRIPT_DELETE((T3<float> *)F->data);
}
SV Float3_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,T3<float>*))
CATE(TE,FAE("Float3Ref's get method","Float3Ref")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Float3Ptr");
EI(keyStr=="__new__")
R CNF(Float3_ptr_new);
EI(keyStr=="__call__")
R CNF(Float3_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(Float3_ptr_deref);
if(keyStr=="refset")R CNF(Float3_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Float3_funcs;
obj.typeID=EXT->Float3_typeID;
obj.refCount=1;
obj.data=F->data;
R Float3_get_member(ctx, &obj, key);
}
void Float3_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,T3<float>*))
CATE(TE,FAE("Float3Ref's set method","Float3Ref")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Float3_funcs;
obj.typeID=EXT->Float3_typeID;
obj.refCount=1;
obj.data=F->data;
Float3_set_member(ctx, &obj, key, value);
}
SV GfxLODList_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->GfxLODList;
NO obj=(NO)GfxLODList_new(ctx, args2);
obj->funcs=GfxLODList_ptr_funcs;
obj->typeID=EXT->GfxLODList_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV GfxLODList_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"GfxLODListRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,List<GfxLOD>*))
CATE(TE,"GfxLODListRef::deref expects GfxLODListRef as first argument."));
R CV(*(List<GfxLOD> *)((NO)F)->data);
}
SV GfxLODList_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"GfxLODList::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,List<GfxLOD>*))
CATE(TE,"GfxLODListRef::refset expects GfxLODListRef as first argument."));
*((List<GfxLOD> *)((NO)F)->data) = val_to_c<List<GfxLOD>>::f(ctx,a[1]);
R CN;
}

void GfxLODList_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,List<GfxLOD>*))
CATE(TE,"GfxLODListRef::__del__ expects GfxLODListRef as first argument."));
SCRIPT_DELETE((List<GfxLOD> *)F->data);
}
SV GfxLODList_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,List<GfxLOD>*))
CATE(TE,FAE("GfxLODListRef's get method","GfxLODListRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxLODListPtr");
EI(keyStr=="__new__")
R CNF(GfxLODList_ptr_new);
EI(keyStr=="__call__")
R CNF(GfxLODList_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(GfxLODList_ptr_deref);
if(keyStr=="refset")R CNF(GfxLODList_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=GfxLODList_funcs;
obj.typeID=EXT->GfxLODList_typeID;
obj.refCount=1;
obj.data=F->data;
R GfxLODList_get_member(ctx, &obj, key);
}
void GfxLODList_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,List<GfxLOD>*))
CATE(TE,FAE("GfxLODListRef's set method","GfxLODListRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=GfxLODList_funcs;
obj.typeID=EXT->GfxLODList_typeID;
obj.refCount=1;
obj.data=F->data;
GfxLODList_set_member(ctx, &obj, key, value);
}
SV GfxBuffer_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->GfxBuffer;
NO obj=(NO)GfxBuffer_new(ctx, args2);
obj->funcs=GfxBuffer_ptr_funcs;
obj->typeID=EXT->GfxBuffer_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV GfxBuffer_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"GfxBufferRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,GfxBuffer*))
CATE(TE,"GfxBufferRef::deref expects GfxBufferRef as first argument."));
CATE(TE,"GfxBuffer objects are not copyable."));
}
SV GfxBuffer_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"GfxBuffer::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,GfxBuffer*))
CATE(TE,"GfxBufferRef::refset expects GfxBufferRef as first argument."));
CATE(TE,"GfxBuffer objects are not copyable."));
R CN;
}

void GfxBuffer_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,GfxBuffer*))
CATE(TE,"GfxBufferRef::__del__ expects GfxBufferRef as first argument."));
SCRIPT_DELETE((GfxBuffer *)F->data);
}
SV GfxBuffer_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,GfxBuffer*))
CATE(TE,FAE("GfxBufferRef's get method","GfxBufferRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxBufferPtr");
EI(keyStr=="__new__")
R CNF(GfxBuffer_ptr_new);
EI(keyStr=="__call__")
R CNF(GfxBuffer_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(GfxBuffer_ptr_deref);
if(keyStr=="refset")R CNF(GfxBuffer_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=GfxBuffer_funcs;
obj.typeID=EXT->GfxBuffer_typeID;
obj.refCount=1;
obj.data=F->data;
R GfxBuffer_get_member(ctx, &obj, key);
}
void GfxBuffer_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,GfxBuffer*))
CATE(TE,FAE("GfxBufferRef's set method","GfxBufferRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=GfxBuffer_funcs;
obj.typeID=EXT->GfxBuffer_typeID;
obj.refCount=1;
obj.data=F->data;
GfxBuffer_set_member(ctx, &obj, key, value);
}
SV Transform_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->Transform;
NO obj=(NO)Transform_new(ctx, args2);
obj->funcs=Transform_ptr_funcs;
obj->typeID=EXT->Transform_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV Transform_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"TransformRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,Transform*))
CATE(TE,"TransformRef::deref expects TransformRef as first argument."));
R CV(*(Transform *)((NO)F)->data);
}
SV Transform_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Transform::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,Transform*))
CATE(TE,"TransformRef::refset expects TransformRef as first argument."));
*((Transform *)((NO)F)->data) = val_to_c<Transform>::f(ctx,a[1]);
R CN;
}

void Transform_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,Transform*))
CATE(TE,"TransformRef::__del__ expects TransformRef as first argument."));
SCRIPT_DELETE((Transform *)F->data);
}
SV Transform_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,Transform*))
CATE(TE,FAE("TransformRef's get method","TransformRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("TransformPtr");
EI(keyStr=="__new__")
R CNF(Transform_ptr_new);
EI(keyStr=="__call__")
R CNF(Transform_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(Transform_ptr_deref);
if(keyStr=="refset")R CNF(Transform_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Transform_funcs;
obj.typeID=EXT->Transform_typeID;
obj.refCount=1;
obj.data=F->data;
R Transform_get_member(ctx, &obj, key);
}
void Transform_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,Transform*))
CATE(TE,FAE("TransformRef's set method","TransformRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Transform_funcs;
obj.typeID=EXT->Transform_typeID;
obj.refCount=1;
obj.data=F->data;
Transform_set_member(ctx, &obj, key, value);
}
SV Quaternion_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->Quaternion;
NO obj=(NO)Quaternion_new(ctx, args2);
obj->funcs=Quaternion_ptr_funcs;
obj->typeID=EXT->Quaternion_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV Quaternion_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"QuaternionRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,Quaternion*))
CATE(TE,"QuaternionRef::deref expects QuaternionRef as first argument."));
R CV(*(Quaternion *)((NO)F)->data);
}
SV Quaternion_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Quaternion::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,Quaternion*))
CATE(TE,"QuaternionRef::refset expects QuaternionRef as first argument."));
*((Quaternion *)((NO)F)->data) = val_to_c<Quaternion>::f(ctx,a[1]);
R CN;
}

void Quaternion_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,Quaternion*))
CATE(TE,"QuaternionRef::__del__ expects QuaternionRef as first argument."));
SCRIPT_DELETE((Quaternion *)F->data);
}
SV Quaternion_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,Quaternion*))
CATE(TE,FAE("QuaternionRef's get method","QuaternionRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("QuaternionPtr");
EI(keyStr=="__new__")
R CNF(Quaternion_ptr_new);
EI(keyStr=="__call__")
R CNF(Quaternion_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(Quaternion_ptr_deref);
if(keyStr=="refset")R CNF(Quaternion_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Quaternion_funcs;
obj.typeID=EXT->Quaternion_typeID;
obj.refCount=1;
obj.data=F->data;
R Quaternion_get_member(ctx, &obj, key);
}
void Quaternion_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,Quaternion*))
CATE(TE,FAE("QuaternionRef's set method","QuaternionRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Quaternion_funcs;
obj.typeID=EXT->Quaternion_typeID;
obj.refCount=1;
obj.data=F->data;
Quaternion_set_member(ctx, &obj, key, value);
}
SV Int2_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->Int2;
NO obj=(NO)Int2_new(ctx, args2);
obj->funcs=Int2_ptr_funcs;
obj->typeID=EXT->Int2_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV Int2_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"Int2Ref::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,T2<int32_t>*))
CATE(TE,"Int2Ref::deref expects Int2Ref as first argument."));
R CV(*(T2<int32_t> *)((NO)F)->data);
}
SV Int2_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Int2::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,T2<int32_t>*))
CATE(TE,"Int2Ref::refset expects Int2Ref as first argument."));
*((T2<int32_t> *)((NO)F)->data) = val_to_c<T2<int32_t>>::f(ctx,a[1]);
R CN;
}

void Int2_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,T2<int32_t>*))
CATE(TE,"Int2Ref::__del__ expects Int2Ref as first argument."));
SCRIPT_DELETE((T2<int32_t> *)F->data);
}
SV Int2_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,T2<int32_t>*))
CATE(TE,FAE("Int2Ref's get method","Int2Ref")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Int2Ptr");
EI(keyStr=="__new__")
R CNF(Int2_ptr_new);
EI(keyStr=="__call__")
R CNF(Int2_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(Int2_ptr_deref);
if(keyStr=="refset")R CNF(Int2_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Int2_funcs;
obj.typeID=EXT->Int2_typeID;
obj.refCount=1;
obj.data=F->data;
R Int2_get_member(ctx, &obj, key);
}
void Int2_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,T2<int32_t>*))
CATE(TE,FAE("Int2Ref's set method","Int2Ref")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Int2_funcs;
obj.typeID=EXT->Int2_typeID;
obj.refCount=1;
obj.data=F->data;
Int2_set_member(ctx, &obj, key, value);
}
SV AudioWorld_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->AudioWorld;
NO obj=(NO)AudioWorld_new(ctx, args2);
obj->funcs=AudioWorld_ptr_funcs;
obj->typeID=EXT->AudioWorld_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV AudioWorld_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"AudioWorldRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,AudioWorld*))
CATE(TE,"AudioWorldRef::deref expects AudioWorldRef as first argument."));
R CV(*(AudioWorld *)((NO)F)->data);
}
SV AudioWorld_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"AudioWorld::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,AudioWorld*))
CATE(TE,"AudioWorldRef::refset expects AudioWorldRef as first argument."));
*((AudioWorld *)((NO)F)->data) = val_to_c<AudioWorld>::f(ctx,a[1]);
R CN;
}

void AudioWorld_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,AudioWorld*))
CATE(TE,"AudioWorldRef::__del__ expects AudioWorldRef as first argument."));
SCRIPT_DELETE((AudioWorld *)F->data);
}
SV AudioWorld_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,AudioWorld*))
CATE(TE,FAE("AudioWorldRef's get method","AudioWorldRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("AudioWorldPtr");
EI(keyStr=="__new__")
R CNF(AudioWorld_ptr_new);
EI(keyStr=="__call__")
R CNF(AudioWorld_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(AudioWorld_ptr_deref);
if(keyStr=="refset")R CNF(AudioWorld_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=AudioWorld_funcs;
obj.typeID=EXT->AudioWorld_typeID;
obj.refCount=1;
obj.data=F->data;
R AudioWorld_get_member(ctx, &obj, key);
}
void AudioWorld_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,AudioWorld*))
CATE(TE,FAE("AudioWorldRef's set method","AudioWorldRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=AudioWorld_funcs;
obj.typeID=EXT->AudioWorld_typeID;
obj.refCount=1;
obj.data=F->data;
AudioWorld_set_member(ctx, &obj, key, value);
}
SV StrStrMap_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->StrStrMap;
NO obj=(NO)StrStrMap_new(ctx, args2);
obj->funcs=StrStrMap_ptr_funcs;
obj->typeID=EXT->StrStrMap_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV StrStrMap_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"StrStrMapRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,HashMap<String,String>*))
CATE(TE,"StrStrMapRef::deref expects StrStrMapRef as first argument."));
R CV(*(HashMap<String,String> *)((NO)F)->data);
}
SV StrStrMap_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"StrStrMap::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,HashMap<String,String>*))
CATE(TE,"StrStrMapRef::refset expects StrStrMapRef as first argument."));
*((HashMap<String,String> *)((NO)F)->data) = val_to_c<HashMap<String,String>>::f(ctx,a[1]);
R CN;
}

void StrStrMap_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,HashMap<String,String>*))
CATE(TE,"StrStrMapRef::__del__ expects StrStrMapRef as first argument."));
SCRIPT_DELETE((HashMap<String,String> *)F->data);
}
SV StrStrMap_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,HashMap<String,String>*))
CATE(TE,FAE("StrStrMapRef's get method","StrStrMapRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("StrStrMapPtr");
EI(keyStr=="__new__")
R CNF(StrStrMap_ptr_new);
EI(keyStr=="__call__")
R CNF(StrStrMap_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(StrStrMap_ptr_deref);
if(keyStr=="refset")R CNF(StrStrMap_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=StrStrMap_funcs;
obj.typeID=EXT->StrStrMap_typeID;
obj.refCount=1;
obj.data=F->data;
R StrStrMap_get_member(ctx, &obj, key);
}
void StrStrMap_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,HashMap<String,String>*))
CATE(TE,FAE("StrStrMapRef's set method","StrStrMapRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=StrStrMap_funcs;
obj.typeID=EXT->StrStrMap_typeID;
obj.refCount=1;
obj.data=F->data;
StrStrMap_set_member(ctx, &obj, key, value);
}
SV Light_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->Light;
NO obj=(NO)Light_new(ctx, args2);
obj->funcs=Light_ptr_funcs;
obj->typeID=EXT->Light_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV Light_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"LightRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,Light*))
CATE(TE,"LightRef::deref expects LightRef as first argument."));
CATE(TE,"Light objects are not copyable."));
}
SV Light_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Light::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,Light*))
CATE(TE,"LightRef::refset expects LightRef as first argument."));
CATE(TE,"Light objects are not copyable."));
R CN;
}

void Light_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,Light*))
CATE(TE,"LightRef::__del__ expects LightRef as first argument."));
SCRIPT_DELETE((Light *)F->data);
}
SV Light_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,Light*))
CATE(TE,FAE("LightRef's get method","LightRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("LightPtr");
EI(keyStr=="__new__")
R CNF(Light_ptr_new);
EI(keyStr=="__call__")
R CNF(Light_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(Light_ptr_deref);
if(keyStr=="refset")R CNF(Light_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Light_funcs;
obj.typeID=EXT->Light_typeID;
obj.refCount=1;
obj.data=F->data;
R Light_get_member(ctx, &obj, key);
}
void Light_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,Light*))
CATE(TE,FAE("LightRef's set method","LightRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Light_funcs;
obj.typeID=EXT->Light_typeID;
obj.refCount=1;
obj.data=F->data;
Light_set_member(ctx, &obj, key, value);
}
SV LightPointData_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->LightPointData;
NO obj=(NO)LightPointData_new(ctx, args2);
obj->funcs=LightPointData_ptr_funcs;
obj->typeID=EXT->LightPointData_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV LightPointData_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"LightPointDataRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,LightPointData*))
CATE(TE,"LightPointDataRef::deref expects LightPointDataRef as first argument."));
R CV(*(LightPointData *)((NO)F)->data);
}
SV LightPointData_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"LightPointData::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,LightPointData*))
CATE(TE,"LightPointDataRef::refset expects LightPointDataRef as first argument."));
*((LightPointData *)((NO)F)->data) = val_to_c<LightPointData>::f(ctx,a[1]);
R CN;
}

void LightPointData_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,LightPointData*))
CATE(TE,"LightPointDataRef::__del__ expects LightPointDataRef as first argument."));
SCRIPT_DELETE((LightPointData *)F->data);
}
SV LightPointData_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,LightPointData*))
CATE(TE,FAE("LightPointDataRef's get method","LightPointDataRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("LightPointDataPtr");
EI(keyStr=="__new__")
R CNF(LightPointData_ptr_new);
EI(keyStr=="__call__")
R CNF(LightPointData_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(LightPointData_ptr_deref);
if(keyStr=="refset")R CNF(LightPointData_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=LightPointData_funcs;
obj.typeID=EXT->LightPointData_typeID;
obj.refCount=1;
obj.data=F->data;
R LightPointData_get_member(ctx, &obj, key);
}
void LightPointData_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,LightPointData*))
CATE(TE,FAE("LightPointDataRef's set method","LightPointDataRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=LightPointData_funcs;
obj.typeID=EXT->LightPointData_typeID;
obj.refCount=1;
obj.data=F->data;
LightPointData_set_member(ctx, &obj, key, value);
}
SV Float4_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->Float4;
NO obj=(NO)Float4_new(ctx, args2);
obj->funcs=Float4_ptr_funcs;
obj->typeID=EXT->Float4_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV Float4_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"Float4Ref::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,T4<float>*))
CATE(TE,"Float4Ref::deref expects Float4Ref as first argument."));
R CV(*(T4<float> *)((NO)F)->data);
}
SV Float4_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Float4::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,T4<float>*))
CATE(TE,"Float4Ref::refset expects Float4Ref as first argument."));
*((T4<float> *)((NO)F)->data) = val_to_c<T4<float>>::f(ctx,a[1]);
R CN;
}

void Float4_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,T4<float>*))
CATE(TE,"Float4Ref::__del__ expects Float4Ref as first argument."));
SCRIPT_DELETE((T4<float> *)F->data);
}
SV Float4_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,T4<float>*))
CATE(TE,FAE("Float4Ref's get method","Float4Ref")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Float4Ptr");
EI(keyStr=="__new__")
R CNF(Float4_ptr_new);
EI(keyStr=="__call__")
R CNF(Float4_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(Float4_ptr_deref);
if(keyStr=="refset")R CNF(Float4_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Float4_funcs;
obj.typeID=EXT->Float4_typeID;
obj.refCount=1;
obj.data=F->data;
R Float4_get_member(ctx, &obj, key);
}
void Float4_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,T4<float>*))
CATE(TE,FAE("Float4Ref's set method","Float4Ref")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Float4_funcs;
obj.typeID=EXT->Float4_typeID;
obj.refCount=1;
obj.data=F->data;
Float4_set_member(ctx, &obj, key, value);
}
SV LightDirectionalData_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->LightDirectionalData;
NO obj=(NO)LightDirectionalData_new(ctx, args2);
obj->funcs=LightDirectionalData_ptr_funcs;
obj->typeID=EXT->LightDirectionalData_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV LightDirectionalData_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"LightDirectionalDataRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,LightDirectionalData*))
CATE(TE,"LightDirectionalDataRef::deref expects LightDirectionalDataRef as first argument."));
R CV(*(LightDirectionalData *)((NO)F)->data);
}
SV LightDirectionalData_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"LightDirectionalData::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,LightDirectionalData*))
CATE(TE,"LightDirectionalDataRef::refset expects LightDirectionalDataRef as first argument."));
*((LightDirectionalData *)((NO)F)->data) = val_to_c<LightDirectionalData>::f(ctx,a[1]);
R CN;
}

void LightDirectionalData_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,LightDirectionalData*))
CATE(TE,"LightDirectionalDataRef::__del__ expects LightDirectionalDataRef as first argument."));
SCRIPT_DELETE((LightDirectionalData *)F->data);
}
SV LightDirectionalData_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,LightDirectionalData*))
CATE(TE,FAE("LightDirectionalDataRef's get method","LightDirectionalDataRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("LightDirectionalDataPtr");
EI(keyStr=="__new__")
R CNF(LightDirectionalData_ptr_new);
EI(keyStr=="__call__")
R CNF(LightDirectionalData_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(LightDirectionalData_ptr_deref);
if(keyStr=="refset")R CNF(LightDirectionalData_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=LightDirectionalData_funcs;
obj.typeID=EXT->LightDirectionalData_typeID;
obj.refCount=1;
obj.data=F->data;
R LightDirectionalData_get_member(ctx, &obj, key);
}
void LightDirectionalData_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,LightDirectionalData*))
CATE(TE,FAE("LightDirectionalDataRef's set method","LightDirectionalDataRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=LightDirectionalData_funcs;
obj.typeID=EXT->LightDirectionalData_typeID;
obj.refCount=1;
obj.data=F->data;
LightDirectionalData_set_member(ctx, &obj, key, value);
}
SV Matrix4x4_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->Matrix4x4;
NO obj=(NO)Matrix4x4_new(ctx, args2);
obj->funcs=Matrix4x4_ptr_funcs;
obj->typeID=EXT->Matrix4x4_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV Matrix4x4_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"Matrix4x4Ref::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,Matrix4x4*))
CATE(TE,"Matrix4x4Ref::deref expects Matrix4x4Ref as first argument."));
R CV(*(Matrix4x4 *)((NO)F)->data);
}
SV Matrix4x4_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Matrix4x4::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,Matrix4x4*))
CATE(TE,"Matrix4x4Ref::refset expects Matrix4x4Ref as first argument."));
*((Matrix4x4 *)((NO)F)->data) = val_to_c<Matrix4x4>::f(ctx,a[1]);
R CN;
}

void Matrix4x4_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,Matrix4x4*))
CATE(TE,"Matrix4x4Ref::__del__ expects Matrix4x4Ref as first argument."));
SCRIPT_DELETE((Matrix4x4 *)F->data);
}
SV Matrix4x4_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,Matrix4x4*))
CATE(TE,FAE("Matrix4x4Ref's get method","Matrix4x4Ref")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Matrix4x4Ptr");
EI(keyStr=="__new__")
R CNF(Matrix4x4_ptr_new);
EI(keyStr=="__call__")
R CNF(Matrix4x4_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(Matrix4x4_ptr_deref);
if(keyStr=="refset")R CNF(Matrix4x4_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Matrix4x4_funcs;
obj.typeID=EXT->Matrix4x4_typeID;
obj.refCount=1;
obj.data=F->data;
R Matrix4x4_get_member(ctx, &obj, key);
}
void Matrix4x4_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,Matrix4x4*))
CATE(TE,FAE("Matrix4x4Ref's set method","Matrix4x4Ref")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Matrix4x4_funcs;
obj.typeID=EXT->Matrix4x4_typeID;
obj.refCount=1;
obj.data=F->data;
Matrix4x4_set_member(ctx, &obj, key, value);
}
SV UInt3_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->UInt3;
NO obj=(NO)UInt3_new(ctx, args2);
obj->funcs=UInt3_ptr_funcs;
obj->typeID=EXT->UInt3_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV UInt3_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"UInt3Ref::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,T3<uint32_t>*))
CATE(TE,"UInt3Ref::deref expects UInt3Ref as first argument."));
R CV(*(T3<uint32_t> *)((NO)F)->data);
}
SV UInt3_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"UInt3::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,T3<uint32_t>*))
CATE(TE,"UInt3Ref::refset expects UInt3Ref as first argument."));
*((T3<uint32_t> *)((NO)F)->data) = val_to_c<T3<uint32_t>>::f(ctx,a[1]);
R CN;
}

void UInt3_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,T3<uint32_t>*))
CATE(TE,"UInt3Ref::__del__ expects UInt3Ref as first argument."));
SCRIPT_DELETE((T3<uint32_t> *)F->data);
}
SV UInt3_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,T3<uint32_t>*))
CATE(TE,FAE("UInt3Ref's get method","UInt3Ref")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("UInt3Ptr");
EI(keyStr=="__new__")
R CNF(UInt3_ptr_new);
EI(keyStr=="__call__")
R CNF(UInt3_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(UInt3_ptr_deref);
if(keyStr=="refset")R CNF(UInt3_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=UInt3_funcs;
obj.typeID=EXT->UInt3_typeID;
obj.refCount=1;
obj.data=F->data;
R UInt3_get_member(ctx, &obj, key);
}
void UInt3_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,T3<uint32_t>*))
CATE(TE,FAE("UInt3Ref's set method","UInt3Ref")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=UInt3_funcs;
obj.typeID=EXT->UInt3_typeID;
obj.refCount=1;
obj.data=F->data;
UInt3_set_member(ctx, &obj, key, value);
}
SV LightSpotData_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->LightSpotData;
NO obj=(NO)LightSpotData_new(ctx, args2);
obj->funcs=LightSpotData_ptr_funcs;
obj->typeID=EXT->LightSpotData_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV LightSpotData_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"LightSpotDataRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,LightSpotData*))
CATE(TE,"LightSpotDataRef::deref expects LightSpotDataRef as first argument."));
R CV(*(LightSpotData *)((NO)F)->data);
}
SV LightSpotData_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"LightSpotData::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,LightSpotData*))
CATE(TE,"LightSpotDataRef::refset expects LightSpotDataRef as first argument."));
*((LightSpotData *)((NO)F)->data) = val_to_c<LightSpotData>::f(ctx,a[1]);
R CN;
}

void LightSpotData_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,LightSpotData*))
CATE(TE,"LightSpotDataRef::__del__ expects LightSpotDataRef as first argument."));
SCRIPT_DELETE((LightSpotData *)F->data);
}
SV LightSpotData_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,LightSpotData*))
CATE(TE,FAE("LightSpotDataRef's get method","LightSpotDataRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("LightSpotDataPtr");
EI(keyStr=="__new__")
R CNF(LightSpotData_ptr_new);
EI(keyStr=="__call__")
R CNF(LightSpotData_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(LightSpotData_ptr_deref);
if(keyStr=="refset")R CNF(LightSpotData_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=LightSpotData_funcs;
obj.typeID=EXT->LightSpotData_typeID;
obj.refCount=1;
obj.data=F->data;
R LightSpotData_get_member(ctx, &obj, key);
}
void LightSpotData_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,LightSpotData*))
CATE(TE,FAE("LightSpotDataRef's set method","LightSpotDataRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=LightSpotData_funcs;
obj.typeID=EXT->LightSpotData_typeID;
obj.refCount=1;
obj.data=F->data;
LightSpotData_set_member(ctx, &obj, key, value);
}
SV AudioDevice_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->AudioDevice;
NO obj=(NO)AudioDevice_new(ctx, args2);
obj->funcs=AudioDevice_ptr_funcs;
obj->typeID=EXT->AudioDevice_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV AudioDevice_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"AudioDeviceRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,AudioDevice*))
CATE(TE,"AudioDeviceRef::deref expects AudioDeviceRef as first argument."));
R CV(*(AudioDevice *)((NO)F)->data);
}
SV AudioDevice_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"AudioDevice::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,AudioDevice*))
CATE(TE,"AudioDeviceRef::refset expects AudioDeviceRef as first argument."));
*((AudioDevice *)((NO)F)->data) = val_to_c<AudioDevice>::f(ctx,a[1]);
R CN;
}

void AudioDevice_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,AudioDevice*))
CATE(TE,"AudioDeviceRef::__del__ expects AudioDeviceRef as first argument."));
SCRIPT_DELETE((AudioDevice *)F->data);
}
SV AudioDevice_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,AudioDevice*))
CATE(TE,FAE("AudioDeviceRef's get method","AudioDeviceRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("AudioDevicePtr");
EI(keyStr=="__new__")
R CNF(AudioDevice_ptr_new);
EI(keyStr=="__call__")
R CNF(AudioDevice_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(AudioDevice_ptr_deref);
if(keyStr=="refset")R CNF(AudioDevice_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=AudioDevice_funcs;
obj.typeID=EXT->AudioDevice_typeID;
obj.refCount=1;
obj.data=F->data;
R AudioDevice_get_member(ctx, &obj, key);
}
void AudioDevice_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,AudioDevice*))
CATE(TE,FAE("AudioDeviceRef's set method","AudioDeviceRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=AudioDevice_funcs;
obj.typeID=EXT->AudioDevice_typeID;
obj.refCount=1;
obj.data=F->data;
AudioDevice_set_member(ctx, &obj, key, value);
}
SV GfxLOD_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->GfxLOD;
NO obj=(NO)GfxLOD_new(ctx, args2);
obj->funcs=GfxLOD_ptr_funcs;
obj->typeID=EXT->GfxLOD_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV GfxLOD_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"GfxLODRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,GfxLOD*))
CATE(TE,"GfxLODRef::deref expects GfxLODRef as first argument."));
R CV(*(GfxLOD *)((NO)F)->data);
}
SV GfxLOD_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"GfxLOD::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,GfxLOD*))
CATE(TE,"GfxLODRef::refset expects GfxLODRef as first argument."));
*((GfxLOD *)((NO)F)->data) = val_to_c<GfxLOD>::f(ctx,a[1]);
R CN;
}

void GfxLOD_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,GfxLOD*))
CATE(TE,"GfxLODRef::__del__ expects GfxLODRef as first argument."));
SCRIPT_DELETE((GfxLOD *)F->data);
}
SV GfxLOD_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,GfxLOD*))
CATE(TE,FAE("GfxLODRef's get method","GfxLODRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxLODPtr");
EI(keyStr=="__new__")
R CNF(GfxLOD_ptr_new);
EI(keyStr=="__call__")
R CNF(GfxLOD_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(GfxLOD_ptr_deref);
if(keyStr=="refset")R CNF(GfxLOD_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=GfxLOD_funcs;
obj.typeID=EXT->GfxLOD_typeID;
obj.refCount=1;
obj.data=F->data;
R GfxLOD_get_member(ctx, &obj, key);
}
void GfxLOD_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,GfxLOD*))
CATE(TE,FAE("GfxLODRef's set method","GfxLODRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=GfxLOD_funcs;
obj.typeID=EXT->GfxLOD_typeID;
obj.refCount=1;
obj.data=F->data;
GfxLOD_set_member(ctx, &obj, key, value);
}
SV File_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->File;
NO obj=(NO)File_new(ctx, args2);
obj->funcs=File_ptr_funcs;
obj->typeID=EXT->File_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV File_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"FileRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,File*))
CATE(TE,"FileRef::deref expects FileRef as first argument."));
CATE(TE,"File objects are not copyable."));
}
SV File_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"File::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,File*))
CATE(TE,"FileRef::refset expects FileRef as first argument."));
CATE(TE,"File objects are not copyable."));
R CN;
}

void File_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,File*))
CATE(TE,"FileRef::__del__ expects FileRef as first argument."));
SCRIPT_DELETE((File *)F->data);
}
SV File_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,File*))
CATE(TE,FAE("FileRef's get method","FileRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("FilePtr");
EI(keyStr=="__new__")
R CNF(File_ptr_new);
EI(keyStr=="__call__")
R CNF(File_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(File_ptr_deref);
if(keyStr=="refset")R CNF(File_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=File_funcs;
obj.typeID=EXT->File_typeID;
obj.refCount=1;
obj.data=F->data;
R File_get_member(ctx, &obj, key);
}
void File_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,File*))
CATE(TE,FAE("FileRef's set method","FileRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=File_funcs;
obj.typeID=EXT->File_typeID;
obj.refCount=1;
obj.data=F->data;
File_set_member(ctx, &obj, key, value);
}
SV AABB_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->AABB;
NO obj=(NO)AABB_new(ctx, args2);
obj->funcs=AABB_ptr_funcs;
obj->typeID=EXT->AABB_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV AABB_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"AABBRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,AABB*))
CATE(TE,"AABBRef::deref expects AABBRef as first argument."));
R CV(*(AABB *)((NO)F)->data);
}
SV AABB_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"AABB::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,AABB*))
CATE(TE,"AABBRef::refset expects AABBRef as first argument."));
*((AABB *)((NO)F)->data) = val_to_c<AABB>::f(ctx,a[1]);
R CN;
}

void AABB_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,AABB*))
CATE(TE,"AABBRef::__del__ expects AABBRef as first argument."));
SCRIPT_DELETE((AABB *)F->data);
}
SV AABB_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,AABB*))
CATE(TE,FAE("AABBRef's get method","AABBRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("AABBPtr");
EI(keyStr=="__new__")
R CNF(AABB_ptr_new);
EI(keyStr=="__call__")
R CNF(AABB_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(AABB_ptr_deref);
if(keyStr=="refset")R CNF(AABB_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=AABB_funcs;
obj.typeID=EXT->AABB_typeID;
obj.refCount=1;
obj.data=F->data;
R AABB_get_member(ctx, &obj, key);
}
void AABB_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,AABB*))
CATE(TE,FAE("AABBRef's set method","AABBRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=AABB_funcs;
obj.typeID=EXT->AABB_typeID;
obj.refCount=1;
obj.data=F->data;
AABB_set_member(ctx, &obj, key, value);
}
SV List_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->List;
NO obj=(NO)List_new(ctx, args2);
obj->funcs=List_ptr_funcs;
obj->typeID=EXT->List_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV List_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"ListRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,List<scripting::Value*>*))
CATE(TE,"ListRef::deref expects ListRef as first argument."));
R CV(*(List<scripting::Value*> *)((NO)F)->data);
}
SV List_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"List::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,List<scripting::Value*>*))
CATE(TE,"ListRef::refset expects ListRef as first argument."));
*((List<scripting::Value*> *)((NO)F)->data) = val_to_c<List<scripting::Value*>>::f(ctx,a[1]);
R CN;
}

void List_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,List<scripting::Value*>*))
CATE(TE,"ListRef::__del__ expects ListRef as first argument."));
SCRIPT_DELETE((List<scripting::Value*> *)F->data);
}
SV List_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,List<scripting::Value*>*))
CATE(TE,FAE("ListRef's get method","ListRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("ListPtr");
EI(keyStr=="__new__")
R CNF(List_ptr_new);
EI(keyStr=="__call__")
R CNF(List_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(List_ptr_deref);
if(keyStr=="refset")R CNF(List_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=List_funcs;
obj.typeID=EXT->List_typeID;
obj.refCount=1;
obj.data=F->data;
R List_get_member(ctx, &obj, key);
}
void List_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,List<scripting::Value*>*))
CATE(TE,FAE("ListRef's set method","ListRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=List_funcs;
obj.typeID=EXT->List_typeID;
obj.refCount=1;
obj.data=F->data;
List_set_member(ctx, &obj, key, value);
}
SV Audio_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->Audio;
NO obj=(NO)Audio_new(ctx, args2);
obj->funcs=Audio_ptr_funcs;
obj->typeID=EXT->Audio_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV Audio_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"AudioRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,Audio*))
CATE(TE,"AudioRef::deref expects AudioRef as first argument."));
CATE(TE,"Audio objects are not copyable."));
}
SV Audio_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Audio::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,Audio*))
CATE(TE,"AudioRef::refset expects AudioRef as first argument."));
CATE(TE,"Audio objects are not copyable."));
R CN;
}

void Audio_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,Audio*))
CATE(TE,"AudioRef::__del__ expects AudioRef as first argument."));
Audio*obj=(Audio*)F->data;
if(shouldScriptDelete(F->data)) {obj->release();}
}
SV Audio_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,Audio*))
CATE(TE,FAE("AudioRef's get method","AudioRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("AudioPtr");
EI(keyStr=="__new__")
R CNF(Audio_ptr_new);
EI(keyStr=="__call__")
R CNF(Audio_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(Audio_ptr_deref);
if(keyStr=="refset")R CNF(Audio_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Audio_funcs;
obj.typeID=EXT->Audio_typeID;
obj.refCount=1;
obj.data=F->data;
R Audio_get_member(ctx, &obj, key);
}
void Audio_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,Audio*))
CATE(TE,FAE("AudioRef's set method","AudioRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Audio_funcs;
obj.typeID=EXT->Audio_typeID;
obj.refCount=1;
obj.data=F->data;
Audio_set_member(ctx, &obj, key, value);
}
SV GfxSubModelList_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->GfxSubModelList;
NO obj=(NO)GfxSubModelList_new(ctx, args2);
obj->funcs=GfxSubModelList_ptr_funcs;
obj->typeID=EXT->GfxSubModelList_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV GfxSubModelList_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"GfxSubModelListRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,List<GfxModel::SubModel>*))
CATE(TE,"GfxSubModelListRef::deref expects GfxSubModelListRef as first argument."));
R CV(*(List<GfxModel::SubModel> *)((NO)F)->data);
}
SV GfxSubModelList_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"GfxSubModelList::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,List<GfxModel::SubModel>*))
CATE(TE,"GfxSubModelListRef::refset expects GfxSubModelListRef as first argument."));
*((List<GfxModel::SubModel> *)((NO)F)->data) = val_to_c<List<GfxModel::SubModel>>::f(ctx,a[1]);
R CN;
}

void GfxSubModelList_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,List<GfxModel::SubModel>*))
CATE(TE,"GfxSubModelListRef::__del__ expects GfxSubModelListRef as first argument."));
SCRIPT_DELETE((List<GfxModel::SubModel> *)F->data);
}
SV GfxSubModelList_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,List<GfxModel::SubModel>*))
CATE(TE,FAE("GfxSubModelListRef's get method","GfxSubModelListRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxSubModelListPtr");
EI(keyStr=="__new__")
R CNF(GfxSubModelList_ptr_new);
EI(keyStr=="__call__")
R CNF(GfxSubModelList_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(GfxSubModelList_ptr_deref);
if(keyStr=="refset")R CNF(GfxSubModelList_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=GfxSubModelList_funcs;
obj.typeID=EXT->GfxSubModelList_typeID;
obj.refCount=1;
obj.data=F->data;
R GfxSubModelList_get_member(ctx, &obj, key);
}
void GfxSubModelList_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,List<GfxModel::SubModel>*))
CATE(TE,FAE("GfxSubModelListRef's set method","GfxSubModelListRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=GfxSubModelList_funcs;
obj.typeID=EXT->GfxSubModelList_typeID;
obj.refCount=1;
obj.data=F->data;
GfxSubModelList_set_member(ctx, &obj, key, value);
}
SV GfxModel_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->GfxModel;
NO obj=(NO)GfxModel_new(ctx, args2);
obj->funcs=GfxModel_ptr_funcs;
obj->typeID=EXT->GfxModel_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV GfxModel_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"GfxModelRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,GfxModel*))
CATE(TE,"GfxModelRef::deref expects GfxModelRef as first argument."));
CATE(TE,"GfxModel objects are not copyable."));
}
SV GfxModel_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"GfxModel::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,GfxModel*))
CATE(TE,"GfxModelRef::refset expects GfxModelRef as first argument."));
CATE(TE,"GfxModel objects are not copyable."));
R CN;
}

void GfxModel_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,GfxModel*))
CATE(TE,"GfxModelRef::__del__ expects GfxModelRef as first argument."));
GfxModel*obj=(GfxModel*)F->data;
if(shouldScriptDelete(F->data)) {obj->release();}
}
SV GfxModel_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,GfxModel*))
CATE(TE,FAE("GfxModelRef's get method","GfxModelRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxModelPtr");
EI(keyStr=="__new__")
R CNF(GfxModel_ptr_new);
EI(keyStr=="__call__")
R CNF(GfxModel_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(GfxModel_ptr_deref);
if(keyStr=="refset")R CNF(GfxModel_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=GfxModel_funcs;
obj.typeID=EXT->GfxModel_typeID;
obj.refCount=1;
obj.data=F->data;
R GfxModel_get_member(ctx, &obj, key);
}
void GfxModel_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,GfxModel*))
CATE(TE,FAE("GfxModelRef's set method","GfxModelRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=GfxModel_funcs;
obj.typeID=EXT->GfxModel_typeID;
obj.refCount=1;
obj.data=F->data;
GfxModel_set_member(ctx, &obj, key, value);
}
SV Matrix3x3_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->Matrix3x3;
NO obj=(NO)Matrix3x3_new(ctx, args2);
obj->funcs=Matrix3x3_ptr_funcs;
obj->typeID=EXT->Matrix3x3_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV Matrix3x3_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"Matrix3x3Ref::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,Matrix3x3*))
CATE(TE,"Matrix3x3Ref::deref expects Matrix3x3Ref as first argument."));
R CV(*(Matrix3x3 *)((NO)F)->data);
}
SV Matrix3x3_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Matrix3x3::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,Matrix3x3*))
CATE(TE,"Matrix3x3Ref::refset expects Matrix3x3Ref as first argument."));
*((Matrix3x3 *)((NO)F)->data) = val_to_c<Matrix3x3>::f(ctx,a[1]);
R CN;
}

void Matrix3x3_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,Matrix3x3*))
CATE(TE,"Matrix3x3Ref::__del__ expects Matrix3x3Ref as first argument."));
SCRIPT_DELETE((Matrix3x3 *)F->data);
}
SV Matrix3x3_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,Matrix3x3*))
CATE(TE,FAE("Matrix3x3Ref's get method","Matrix3x3Ref")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("Matrix3x3Ptr");
EI(keyStr=="__new__")
R CNF(Matrix3x3_ptr_new);
EI(keyStr=="__call__")
R CNF(Matrix3x3_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(Matrix3x3_ptr_deref);
if(keyStr=="refset")R CNF(Matrix3x3_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Matrix3x3_funcs;
obj.typeID=EXT->Matrix3x3_typeID;
obj.refCount=1;
obj.data=F->data;
R Matrix3x3_get_member(ctx, &obj, key);
}
void Matrix3x3_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,Matrix3x3*))
CATE(TE,FAE("Matrix3x3Ref's set method","Matrix3x3Ref")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Matrix3x3_funcs;
obj.typeID=EXT->Matrix3x3_typeID;
obj.refCount=1;
obj.data=F->data;
Matrix3x3_set_member(ctx, &obj, key, value);
}
SV GfxDebugDrawer_ptr_new(CTX ctx,const List<SV>&a)
{
List<SV> args2 = a.copy();
args2[0]=EXT->GfxDebugDrawer;
NO obj=(NO)GfxDebugDrawer_new(ctx, args2);
obj->funcs=GfxDebugDrawer_ptr_funcs;
obj->typeID=EXT->GfxDebugDrawer_ptr_typeID;
setAllocInfo(obj->data, AllocInfo(true, false));
R(SV)obj;
}
SV GfxDebugDrawer_ptr_deref(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"GfxDebugDrawerRef::deref" EAOE));
SV F=a[0];
if(!TS((SV)F,GfxDebugDrawer*))
CATE(TE,"GfxDebugDrawerRef::deref expects GfxDebugDrawerRef as first argument."));
CATE(TE,"GfxDebugDrawer objects are not copyable."));
}
SV GfxDebugDrawer_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"GfxDebugDrawer::refset expects two arguments."));
SV F=a[0];
if(!TS((SV)F,GfxDebugDrawer*))
CATE(TE,"GfxDebugDrawerRef::refset expects GfxDebugDrawerRef as first argument."));
CATE(TE,"GfxDebugDrawer objects are not copyable."));
R CN;
}

void GfxDebugDrawer_ptr_destroy(CTX ctx,NO F)
{
if(!TS((SV)F,GfxDebugDrawer*))
CATE(TE,"GfxDebugDrawerRef::__del__ expects GfxDebugDrawerRef as first argument."));
SCRIPT_DELETE((GfxDebugDrawer *)F->data);
}
SV GfxDebugDrawer_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS((SV)F,GfxDebugDrawer*))
CATE(TE,FAE("GfxDebugDrawerRef's get method","GfxDebugDrawerRef")));
if (key->type==S::ValueType::StringType)
{
String keyStr=((S::StringValue *)key)->value;
if(F->data==NULL)
{
if(keyStr=="__typeID__")
R S::createInt(F->typeID);
EI(keyStr=="__name__")
R S::createString("GfxDebugDrawerPtr");
EI(keyStr=="__new__")
R CNF(GfxDebugDrawer_ptr_new);
EI(keyStr=="__call__")
R CNF(GfxDebugDrawer_ptr_new);
else
CATE(KE,"Unknown member."));
} else
{
if(keyStr=="deref")R CNF(GfxDebugDrawer_ptr_deref);
if(keyStr=="refset")R CNF(GfxDebugDrawer_ptr_set);
}
}
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=GfxDebugDrawer_funcs;
obj.typeID=EXT->GfxDebugDrawer_typeID;
obj.refCount=1;
obj.data=F->data;
R GfxDebugDrawer_get_member(ctx, &obj, key);
}
void GfxDebugDrawer_ptr_set_member(CTX ctx,NO F,SV key,SV value)
{
if(!TS((SV)F,GfxDebugDrawer*))
CATE(TE,FAE("GfxDebugDrawerRef's set method","GfxDebugDrawerRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=GfxDebugDrawer_funcs;
obj.typeID=EXT->GfxDebugDrawer_typeID;
obj.refCount=1;
obj.data=F->data;
GfxDebugDrawer_set_member(ctx, &obj, key, value);
}
void *initBindings(scripting::Engine *engine, void *data)
{
    BindingsExt *ext = NEW(BindingsExt);

    int64_t typeID;
    
    typeID = engine->createNewTypeID();
    ext->Filesystem_typeID = typeID;
    ext->Filesystem = scripting::createNativeObject(Filesystem_funcs, NULL, typeID);
    engine->getGlobalVars().set("Filesystem", ext->Filesystem);
    
    typeID = engine->createNewTypeID();
    ext->Filesystem_ptr_typeID = typeID;
    ext->Filesystem_ptr = scripting::createNativeObject(Filesystem_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("FilesystemRef", ext->Filesystem_ptr);
    
    typeID = engine->createNewTypeID();
    ext->GfxCompiledShader_typeID = typeID;
    ext->GfxCompiledShader = scripting::createNativeObject(GfxCompiledShader_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxCompiledShader", ext->GfxCompiledShader);
    
    typeID = engine->createNewTypeID();
    ext->GfxCompiledShader_ptr_typeID = typeID;
    ext->GfxCompiledShader_ptr = scripting::createNativeObject(GfxCompiledShader_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxCompiledShaderRef", ext->GfxCompiledShader_ptr);
    
    typeID = engine->createNewTypeID();
    ext->UInt2_typeID = typeID;
    ext->UInt2 = scripting::createNativeObject(UInt2_funcs, NULL, typeID);
    engine->getGlobalVars().set("UInt2", ext->UInt2);
    
    typeID = engine->createNewTypeID();
    ext->UInt2_ptr_typeID = typeID;
    ext->UInt2_ptr = scripting::createNativeObject(UInt2_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("UInt2Ref", ext->UInt2_ptr);
    
    typeID = engine->createNewTypeID();
    ext->GPUTimer_typeID = typeID;
    ext->GPUTimer = scripting::createNativeObject(GPUTimer_funcs, NULL, typeID);
    engine->getGlobalVars().set("GPUTimer", ext->GPUTimer);
    
    typeID = engine->createNewTypeID();
    ext->GPUTimer_ptr_typeID = typeID;
    ext->GPUTimer_ptr = scripting::createNativeObject(GPUTimer_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("GPUTimerRef", ext->GPUTimer_ptr);
    
    typeID = engine->createNewTypeID();
    ext->RigidBody_typeID = typeID;
    ext->RigidBody = scripting::createNativeObject(RigidBody_funcs, NULL, typeID);
    engine->getGlobalVars().set("RigidBody", ext->RigidBody);
    
    typeID = engine->createNewTypeID();
    ext->RigidBody_ptr_typeID = typeID;
    ext->RigidBody_ptr = scripting::createNativeObject(RigidBody_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("RigidBodyRef", ext->RigidBody_ptr);
    
    typeID = engine->createNewTypeID();
    ext->Float2_typeID = typeID;
    ext->Float2 = scripting::createNativeObject(Float2_funcs, NULL, typeID);
    engine->getGlobalVars().set("Float2", ext->Float2);
    
    typeID = engine->createNewTypeID();
    ext->Float2_ptr_typeID = typeID;
    ext->Float2_ptr = scripting::createNativeObject(Float2_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("Float2Ref", ext->Float2_ptr);
    
    typeID = engine->createNewTypeID();
    ext->AudioSource_typeID = typeID;
    ext->AudioSource = scripting::createNativeObject(AudioSource_funcs, NULL, typeID);
    engine->getGlobalVars().set("AudioSource", ext->AudioSource);
    
    typeID = engine->createNewTypeID();
    ext->AudioSource_ptr_typeID = typeID;
    ext->AudioSource_ptr = scripting::createNativeObject(AudioSource_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("AudioSourceRef", ext->AudioSource_ptr);
    
    typeID = engine->createNewTypeID();
    ext->Camera_typeID = typeID;
    ext->Camera = scripting::createNativeObject(Camera_funcs, NULL, typeID);
    engine->getGlobalVars().set("Camera", ext->Camera);
    
    typeID = engine->createNewTypeID();
    ext->Camera_ptr_typeID = typeID;
    ext->Camera_ptr = scripting::createNativeObject(Camera_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("CameraRef", ext->Camera_ptr);
    
    typeID = engine->createNewTypeID();
    ext->Resource_typeID = typeID;
    ext->Resource = scripting::createNativeObject(Resource_funcs, NULL, typeID);
    engine->getGlobalVars().set("Resource", ext->Resource);
    
    typeID = engine->createNewTypeID();
    ext->Resource_ptr_typeID = typeID;
    ext->Resource_ptr = scripting::createNativeObject(Resource_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("ResourceRef", ext->Resource_ptr);
    
    typeID = engine->createNewTypeID();
    ext->GfxShader_typeID = typeID;
    ext->GfxShader = scripting::createNativeObject(GfxShader_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxShader", ext->GfxShader);
    
    typeID = engine->createNewTypeID();
    ext->GfxShader_ptr_typeID = typeID;
    ext->GfxShader_ptr = scripting::createNativeObject(GfxShader_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxShaderRef", ext->GfxShader_ptr);
    
    typeID = engine->createNewTypeID();
    ext->UInt4_typeID = typeID;
    ext->UInt4 = scripting::createNativeObject(UInt4_funcs, NULL, typeID);
    engine->getGlobalVars().set("UInt4", ext->UInt4);
    
    typeID = engine->createNewTypeID();
    ext->UInt4_ptr_typeID = typeID;
    ext->UInt4_ptr = scripting::createNativeObject(UInt4_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("UInt4Ref", ext->UInt4_ptr);
    
    typeID = engine->createNewTypeID();
    ext->Int3_typeID = typeID;
    ext->Int3 = scripting::createNativeObject(Int3_funcs, NULL, typeID);
    engine->getGlobalVars().set("Int3", ext->Int3);
    
    typeID = engine->createNewTypeID();
    ext->Int3_ptr_typeID = typeID;
    ext->Int3_ptr = scripting::createNativeObject(Int3_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("Int3Ref", ext->Int3_ptr);
    
    typeID = engine->createNewTypeID();
    ext->ResizableData_typeID = typeID;
    ext->ResizableData = scripting::createNativeObject(ResizableData_funcs, NULL, typeID);
    engine->getGlobalVars().set("ResizableData", ext->ResizableData);
    
    typeID = engine->createNewTypeID();
    ext->ResizableData_ptr_typeID = typeID;
    ext->ResizableData_ptr = scripting::createNativeObject(ResizableData_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("ResizableDataRef", ext->ResizableData_ptr);
    
    typeID = engine->createNewTypeID();
    ext->Int4_typeID = typeID;
    ext->Int4 = scripting::createNativeObject(Int4_funcs, NULL, typeID);
    engine->getGlobalVars().set("Int4", ext->Int4);
    
    typeID = engine->createNewTypeID();
    ext->Int4_ptr_typeID = typeID;
    ext->Int4_ptr = scripting::createNativeObject(Int4_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("Int4Ref", ext->Int4_ptr);
    
    typeID = engine->createNewTypeID();
    ext->Float3_typeID = typeID;
    ext->Float3 = scripting::createNativeObject(Float3_funcs, NULL, typeID);
    engine->getGlobalVars().set("Float3", ext->Float3);
    
    typeID = engine->createNewTypeID();
    ext->Float3_ptr_typeID = typeID;
    ext->Float3_ptr = scripting::createNativeObject(Float3_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("Float3Ref", ext->Float3_ptr);
    
    typeID = engine->createNewTypeID();
    ext->GfxLODList_typeID = typeID;
    ext->GfxLODList = scripting::createNativeObject(GfxLODList_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxLODList", ext->GfxLODList);
    
    typeID = engine->createNewTypeID();
    ext->GfxLODList_ptr_typeID = typeID;
    ext->GfxLODList_ptr = scripting::createNativeObject(GfxLODList_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxLODListRef", ext->GfxLODList_ptr);
    
    typeID = engine->createNewTypeID();
    ext->GfxBuffer_typeID = typeID;
    ext->GfxBuffer = scripting::createNativeObject(GfxBuffer_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxBuffer", ext->GfxBuffer);
    
    typeID = engine->createNewTypeID();
    ext->GfxBuffer_ptr_typeID = typeID;
    ext->GfxBuffer_ptr = scripting::createNativeObject(GfxBuffer_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxBufferRef", ext->GfxBuffer_ptr);
    
    typeID = engine->createNewTypeID();
    ext->Transform_typeID = typeID;
    ext->Transform = scripting::createNativeObject(Transform_funcs, NULL, typeID);
    engine->getGlobalVars().set("Transform", ext->Transform);
    
    typeID = engine->createNewTypeID();
    ext->Transform_ptr_typeID = typeID;
    ext->Transform_ptr = scripting::createNativeObject(Transform_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("TransformRef", ext->Transform_ptr);
    
    typeID = engine->createNewTypeID();
    ext->Quaternion_typeID = typeID;
    ext->Quaternion = scripting::createNativeObject(Quaternion_funcs, NULL, typeID);
    engine->getGlobalVars().set("Quaternion", ext->Quaternion);
    
    typeID = engine->createNewTypeID();
    ext->Quaternion_ptr_typeID = typeID;
    ext->Quaternion_ptr = scripting::createNativeObject(Quaternion_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("QuaternionRef", ext->Quaternion_ptr);
    
    typeID = engine->createNewTypeID();
    ext->Int2_typeID = typeID;
    ext->Int2 = scripting::createNativeObject(Int2_funcs, NULL, typeID);
    engine->getGlobalVars().set("Int2", ext->Int2);
    
    typeID = engine->createNewTypeID();
    ext->Int2_ptr_typeID = typeID;
    ext->Int2_ptr = scripting::createNativeObject(Int2_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("Int2Ref", ext->Int2_ptr);
    
    typeID = engine->createNewTypeID();
    ext->AudioWorld_typeID = typeID;
    ext->AudioWorld = scripting::createNativeObject(AudioWorld_funcs, NULL, typeID);
    engine->getGlobalVars().set("AudioWorld", ext->AudioWorld);
    
    typeID = engine->createNewTypeID();
    ext->AudioWorld_ptr_typeID = typeID;
    ext->AudioWorld_ptr = scripting::createNativeObject(AudioWorld_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("AudioWorldRef", ext->AudioWorld_ptr);
    
    typeID = engine->createNewTypeID();
    ext->StrStrMap_typeID = typeID;
    ext->StrStrMap = scripting::createNativeObject(StrStrMap_funcs, NULL, typeID);
    engine->getGlobalVars().set("StrStrMap", ext->StrStrMap);
    
    typeID = engine->createNewTypeID();
    ext->StrStrMap_ptr_typeID = typeID;
    ext->StrStrMap_ptr = scripting::createNativeObject(StrStrMap_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("StrStrMapRef", ext->StrStrMap_ptr);
    
    typeID = engine->createNewTypeID();
    ext->Light_typeID = typeID;
    ext->Light = scripting::createNativeObject(Light_funcs, NULL, typeID);
    engine->getGlobalVars().set("Light", ext->Light);
    
    typeID = engine->createNewTypeID();
    ext->Light_ptr_typeID = typeID;
    ext->Light_ptr = scripting::createNativeObject(Light_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("LightRef", ext->Light_ptr);
    
    typeID = engine->createNewTypeID();
    ext->LightPointData_typeID = typeID;
    ext->LightPointData = scripting::createNativeObject(LightPointData_funcs, NULL, typeID);
    engine->getGlobalVars().set("LightPointData", ext->LightPointData);
    
    typeID = engine->createNewTypeID();
    ext->LightPointData_ptr_typeID = typeID;
    ext->LightPointData_ptr = scripting::createNativeObject(LightPointData_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("LightPointDataRef", ext->LightPointData_ptr);
    
    typeID = engine->createNewTypeID();
    ext->Float4_typeID = typeID;
    ext->Float4 = scripting::createNativeObject(Float4_funcs, NULL, typeID);
    engine->getGlobalVars().set("Float4", ext->Float4);
    
    typeID = engine->createNewTypeID();
    ext->Float4_ptr_typeID = typeID;
    ext->Float4_ptr = scripting::createNativeObject(Float4_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("Float4Ref", ext->Float4_ptr);
    
    typeID = engine->createNewTypeID();
    ext->LightDirectionalData_typeID = typeID;
    ext->LightDirectionalData = scripting::createNativeObject(LightDirectionalData_funcs, NULL, typeID);
    engine->getGlobalVars().set("LightDirectionalData", ext->LightDirectionalData);
    
    typeID = engine->createNewTypeID();
    ext->LightDirectionalData_ptr_typeID = typeID;
    ext->LightDirectionalData_ptr = scripting::createNativeObject(LightDirectionalData_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("LightDirectionalDataRef", ext->LightDirectionalData_ptr);
    
    typeID = engine->createNewTypeID();
    ext->Matrix4x4_typeID = typeID;
    ext->Matrix4x4 = scripting::createNativeObject(Matrix4x4_funcs, NULL, typeID);
    engine->getGlobalVars().set("Matrix4x4", ext->Matrix4x4);
    
    typeID = engine->createNewTypeID();
    ext->Matrix4x4_ptr_typeID = typeID;
    ext->Matrix4x4_ptr = scripting::createNativeObject(Matrix4x4_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("Matrix4x4Ref", ext->Matrix4x4_ptr);
    
    typeID = engine->createNewTypeID();
    ext->UInt3_typeID = typeID;
    ext->UInt3 = scripting::createNativeObject(UInt3_funcs, NULL, typeID);
    engine->getGlobalVars().set("UInt3", ext->UInt3);
    
    typeID = engine->createNewTypeID();
    ext->UInt3_ptr_typeID = typeID;
    ext->UInt3_ptr = scripting::createNativeObject(UInt3_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("UInt3Ref", ext->UInt3_ptr);
    
    typeID = engine->createNewTypeID();
    ext->LightSpotData_typeID = typeID;
    ext->LightSpotData = scripting::createNativeObject(LightSpotData_funcs, NULL, typeID);
    engine->getGlobalVars().set("LightSpotData", ext->LightSpotData);
    
    typeID = engine->createNewTypeID();
    ext->LightSpotData_ptr_typeID = typeID;
    ext->LightSpotData_ptr = scripting::createNativeObject(LightSpotData_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("LightSpotDataRef", ext->LightSpotData_ptr);
    
    typeID = engine->createNewTypeID();
    ext->AudioDevice_typeID = typeID;
    ext->AudioDevice = scripting::createNativeObject(AudioDevice_funcs, NULL, typeID);
    engine->getGlobalVars().set("AudioDevice", ext->AudioDevice);
    
    typeID = engine->createNewTypeID();
    ext->AudioDevice_ptr_typeID = typeID;
    ext->AudioDevice_ptr = scripting::createNativeObject(AudioDevice_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("AudioDeviceRef", ext->AudioDevice_ptr);
    
    typeID = engine->createNewTypeID();
    ext->GfxLOD_typeID = typeID;
    ext->GfxLOD = scripting::createNativeObject(GfxLOD_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxLOD", ext->GfxLOD);
    
    typeID = engine->createNewTypeID();
    ext->GfxLOD_ptr_typeID = typeID;
    ext->GfxLOD_ptr = scripting::createNativeObject(GfxLOD_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxLODRef", ext->GfxLOD_ptr);
    
    typeID = engine->createNewTypeID();
    ext->File_typeID = typeID;
    ext->File = scripting::createNativeObject(File_funcs, NULL, typeID);
    engine->getGlobalVars().set("File", ext->File);
    
    typeID = engine->createNewTypeID();
    ext->File_ptr_typeID = typeID;
    ext->File_ptr = scripting::createNativeObject(File_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("FileRef", ext->File_ptr);
    
    typeID = engine->createNewTypeID();
    ext->AABB_typeID = typeID;
    ext->AABB = scripting::createNativeObject(AABB_funcs, NULL, typeID);
    engine->getGlobalVars().set("AABB", ext->AABB);
    
    typeID = engine->createNewTypeID();
    ext->AABB_ptr_typeID = typeID;
    ext->AABB_ptr = scripting::createNativeObject(AABB_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("AABBRef", ext->AABB_ptr);
    
    typeID = engine->createNewTypeID();
    ext->List_typeID = typeID;
    ext->List = scripting::createNativeObject(List_funcs, NULL, typeID);
    engine->getGlobalVars().set("List", ext->List);
    
    typeID = engine->createNewTypeID();
    ext->List_ptr_typeID = typeID;
    ext->List_ptr = scripting::createNativeObject(List_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("ListRef", ext->List_ptr);
    
    typeID = engine->createNewTypeID();
    ext->Audio_typeID = typeID;
    ext->Audio = scripting::createNativeObject(Audio_funcs, NULL, typeID);
    engine->getGlobalVars().set("Audio", ext->Audio);
    
    typeID = engine->createNewTypeID();
    ext->Audio_ptr_typeID = typeID;
    ext->Audio_ptr = scripting::createNativeObject(Audio_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("AudioRef", ext->Audio_ptr);
    
    typeID = engine->createNewTypeID();
    ext->GfxSubModelList_typeID = typeID;
    ext->GfxSubModelList = scripting::createNativeObject(GfxSubModelList_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxSubModelList", ext->GfxSubModelList);
    
    typeID = engine->createNewTypeID();
    ext->GfxSubModelList_ptr_typeID = typeID;
    ext->GfxSubModelList_ptr = scripting::createNativeObject(GfxSubModelList_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxSubModelListRef", ext->GfxSubModelList_ptr);
    
    typeID = engine->createNewTypeID();
    ext->GfxModel_typeID = typeID;
    ext->GfxModel = scripting::createNativeObject(GfxModel_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxModel", ext->GfxModel);
    
    typeID = engine->createNewTypeID();
    ext->GfxModel_ptr_typeID = typeID;
    ext->GfxModel_ptr = scripting::createNativeObject(GfxModel_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxModelRef", ext->GfxModel_ptr);
    
    typeID = engine->createNewTypeID();
    ext->Matrix3x3_typeID = typeID;
    ext->Matrix3x3 = scripting::createNativeObject(Matrix3x3_funcs, NULL, typeID);
    engine->getGlobalVars().set("Matrix3x3", ext->Matrix3x3);
    
    typeID = engine->createNewTypeID();
    ext->Matrix3x3_ptr_typeID = typeID;
    ext->Matrix3x3_ptr = scripting::createNativeObject(Matrix3x3_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("Matrix3x3Ref", ext->Matrix3x3_ptr);
    
    typeID = engine->createNewTypeID();
    ext->GfxDebugDrawer_typeID = typeID;
    ext->GfxDebugDrawer = scripting::createNativeObject(GfxDebugDrawer_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxDebugDrawer", ext->GfxDebugDrawer);
    
    typeID = engine->createNewTypeID();
    ext->GfxDebugDrawer_ptr_typeID = typeID;
    ext->GfxDebugDrawer_ptr = scripting::createNativeObject(GfxDebugDrawer_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxDebugDrawerRef", ext->GfxDebugDrawer_ptr);
    
    typeID = engine->createNewTypeID();
    ext->ResType_typeID = typeID;
    ext->ResType = scripting::createNativeObject(ResType_funcs, NULL, typeID);
    engine->getGlobalVars().set("ResType", ext->ResType);
    
    typeID = engine->createNewTypeID();
    ext->GfxPrimitive_typeID = typeID;
    ext->GfxPrimitive = scripting::createNativeObject(GfxPrimitive_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxPrimitive", ext->GfxPrimitive);
    
    typeID = engine->createNewTypeID();
    ext->GfxDepthFunction_typeID = typeID;
    ext->GfxDepthFunction = scripting::createNativeObject(GfxDepthFunction_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxDepthFunction", ext->GfxDepthFunction);
    
    typeID = engine->createNewTypeID();
    ext->GfxBlendMode_typeID = typeID;
    ext->GfxBlendMode = scripting::createNativeObject(GfxBlendMode_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxBlendMode", ext->GfxBlendMode);
    
    typeID = engine->createNewTypeID();
    ext->GfxBlendFactor_typeID = typeID;
    ext->GfxBlendFactor = scripting::createNativeObject(GfxBlendFactor_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxBlendFactor", ext->GfxBlendFactor);
    
    typeID = engine->createNewTypeID();
    ext->GfxCullMode_typeID = typeID;
    ext->GfxCullMode = scripting::createNativeObject(GfxCullMode_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxCullMode", ext->GfxCullMode);
    
    typeID = engine->createNewTypeID();
    ext->GfxWinding_typeID = typeID;
    ext->GfxWinding = scripting::createNativeObject(GfxWinding_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxWinding", ext->GfxWinding);
    
    typeID = engine->createNewTypeID();
    ext->GfxVertexAttribPurpose_typeID = typeID;
    ext->GfxVertexAttribPurpose = scripting::createNativeObject(GfxVertexAttribPurpose_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxVertexAttribPurpose", ext->GfxVertexAttribPurpose);
    
    typeID = engine->createNewTypeID();
    ext->GfxVertexAttribType_typeID = typeID;
    ext->GfxVertexAttribType = scripting::createNativeObject(GfxVertexAttribType_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxVertexAttribType", ext->GfxVertexAttribType);
    
    typeID = engine->createNewTypeID();
    ext->GfxStage_typeID = typeID;
    ext->GfxStage = scripting::createNativeObject(GfxStage_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxStage", ext->GfxStage);
    
    typeID = engine->createNewTypeID();
    ext->GfxBufferUsage_typeID = typeID;
    ext->GfxBufferUsage = scripting::createNativeObject(GfxBufferUsage_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxBufferUsage", ext->GfxBufferUsage);
    
    typeID = engine->createNewTypeID();
    ext->GfxShadowmapPrecision_typeID = typeID;
    ext->GfxShadowmapPrecision = scripting::createNativeObject(GfxShadowmapPrecision_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxShadowmapPrecision", ext->GfxShadowmapPrecision);
    
    typeID = engine->createNewTypeID();
    ext->GfxLightType_typeID = typeID;
    ext->GfxLightType = scripting::createNativeObject(GfxLightType_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxLightType", ext->GfxLightType);
    
    typeID = engine->createNewTypeID();
    ext->CameraType_typeID = typeID;
    ext->CameraType = scripting::createNativeObject(CameraType_funcs, NULL, typeID);
    engine->getGlobalVars().set("CameraType", ext->CameraType);
    
    return ext;
}

void deinitBindings(scripting::Engine *engine, void *data)
{
    DELETE((BindingsExt *)data);
}

namespace scripting
{
void registerBindings(scripting::Engine *engine)
{
    scripting::Extension ext;

    ext.init = initBindings;
    ext.deinit = deinitBindings;

    engine->addExtension("bindings", ext);
}
}

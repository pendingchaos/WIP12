//Generated from script_binding_generator2.py. Do not edit. Edit script_binding_generator2.py instead.
#include "file.h"
#include "error.h"
#include "memory.h"
#include "globals.h"
#include "logging.h"
#include "backtrace.h"
#include "filesystem.h"
#include "application.h"
#include "misc_macros.h"
#include "endian_utils.h"
#include "scene/scene.h"
#include "scene/entity.h"
#include "scene/transform.h"
#include "graphics/gfxapi.h"
#include "graphics/gfxmesh.h"
#include "graphics/gfxmodel.h"
#include "graphics/gfxshader.h"
#include "graphics/gfxtexture.h"
#include "graphics/gfxmaterial.h"
#include "graphics/gfxbuffer.h"
#include "graphics/gfxdefs.h"
#include "graphics/gfxrenderer.h"
#include "graphics/camera.h"
#include "graphics/gfxdebugdrawer.h"
#include "graphics/font.h"
#include "graphics/gputimer.h"
#include "scripting/script.h"
#include "resource/resource.h"
#include "resource/resourcemanager.h"
#include "math/t2.h"
#include "math/t3.h"
#include "math/t4.h"
#include "math/matrix3x3.h"
#include "math/matrix4x4.h"
#include "math/quaternion.h"
#include "math/aabb.h"
#include "containers/list.h"
#include "containers/string.h"
#include "containers/hashmap.h"
#include "containers/resizabledata.h"
#include "physics/physicsworld.h"
#include "physics/rigidbody.h"
#include "physics/physicsshape.h"
#include "physics/physicsdebugdrawer.h"
#include "platform.h"
#include "audio/audio.h"
#include "audio/audioworld.h"
#include "audio/audiodevice.h"
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
    int64_t UInt3_typeID, UInt3_ptr_typeID, UInt2_typeID, UInt2_ptr_typeID, RigidBody_typeID, RigidBody_ptr_typeID, File_typeID, File_ptr_typeID, Int3_typeID, Int3_ptr_typeID, Camera_typeID, Camera_ptr_typeID, Float2_typeID, Float2_ptr_typeID, Int4_typeID, Int4_ptr_typeID, Float3_typeID, Float3_ptr_typeID, Transform_typeID, Transform_ptr_typeID, Quaternion_typeID, Quaternion_ptr_typeID, Int2_typeID, Int2_ptr_typeID, Float4_typeID, Float4_ptr_typeID, Matrix4x4_typeID, Matrix4x4_ptr_typeID, UInt4_typeID, UInt4_ptr_typeID, AABB_typeID, AABB_ptr_typeID, Matrix3x3_typeID, Matrix3x3_ptr_typeID, GfxPrimitive_typeID;
    scripting::Value *UInt3, *UInt3_ptr, *UInt2, *UInt2_ptr, *RigidBody, *RigidBody_ptr, *File, *File_ptr, *Int3, *Int3_ptr, *Camera, *Camera_ptr, *Float2, *Float2_ptr, *Int4, *Int4_ptr, *Float3, *Float3_ptr, *Transform, *Transform_ptr, *Quaternion, *Quaternion_ptr, *Int2, *Int2_ptr, *Float4, *Float4_ptr, *Matrix4x4, *Matrix4x4_ptr, *UInt4, *UInt4_ptr, *AABB, *AABB_ptr, *Matrix3x3, *Matrix3x3_ptr, *GfxPrimitive;
};


#define CATE ctx->throwException(scripting::createException
#define SV scripting::Value*
#define NO scripting::NativeObject*
#define CV(expr) create_val<std::remove_reference<decltype(expr)>::type>::f(ctx, expr)
#define TS(T, expr) type_same<T>::f(ctx, expr)
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

template <>
struct type_same<SV>
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
void GfxPrimitive_destroy(CTX,NO) {}
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
};void UInt3_destroy(CTX,NO);
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
R S::createNativeObject(UInt3_funcs,NEW(T3<uint32_t>, obj),EXT->UInt3_typeID);
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
R S::createNativeObject(UInt2_funcs,NEW(T2<uint32_t>, obj),EXT->UInt2_typeID);
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
R S::createNativeObject(Int3_funcs,NEW(T3<int32_t>, obj),EXT->Int3_typeID);
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
R S::createNativeObject(Camera_funcs,NEW(Camera, obj),EXT->Camera_typeID);
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
R S::createNativeObject(Float2_funcs,NEW(T2<float>, obj),EXT->Float2_typeID);
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
R S::createNativeObject(Int4_funcs,NEW(T4<int32_t>, obj),EXT->Int4_typeID);
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
R S::createNativeObject(Float3_funcs,NEW(T3<float>, obj),EXT->Float3_typeID);
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
R S::createNativeObject(Transform_funcs,NEW(Transform, obj),EXT->Transform_typeID);
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
R S::createNativeObject(Quaternion_funcs,NEW(Quaternion, obj),EXT->Quaternion_typeID);
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
R S::createNativeObject(Int2_funcs,NEW(T2<int32_t>, obj),EXT->Int2_typeID);
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
R S::createNativeObject(Float4_funcs,NEW(T4<float>, obj),EXT->Float4_typeID);
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
R S::createNativeObject(Matrix4x4_funcs,NEW(Matrix4x4, obj),EXT->Matrix4x4_typeID);
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
R S::createNativeObject(UInt4_funcs,NEW(T4<uint32_t>, obj),EXT->UInt4_typeID);
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
R S::createNativeObject(AABB_funcs,NEW(AABB, obj),EXT->AABB_typeID);
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
R S::createNativeObject(Matrix3x3_funcs,NEW(Matrix3x3, obj),EXT->Matrix3x3_typeID);
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
i.cppRef = false;
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
i.cppRef = false;
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
i.cppRef = false;
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
i.cppRef = false;
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
i.cppRef = false;
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
i.cppRef = false;
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
i.cppRef = false;
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
i.cppRef = false;
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
i.cppRef = false;
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
i.cppRef = false;
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
i.cppRef = false;
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
i.cppRef = false;
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
i.cppRef = false;
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
i.cppRef = false;
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
i.cppRef = false;
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
i.cppRef = false;
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
i.cppRef = false;
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

SV GfxPrimitive___eq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,UFOF("GfxPrimitive::__eq__")));
size_t F;
if(!TS(GfxPrimitive,a[0]))
CATE(TE,FAE("GfxPrimitive::GfxPrimitive","GfxPrimitive")));
else
 F=(size_t)((NO)a[0])->data;
size_t other;
if(!TS(GfxPrimitive,a[1]))
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
void UInt3_destroy(CTX ctx,NO F)
{
if(!TS(T3<uint32_t>, (SV)F))
CATE(TE,"UInt3::__del__ expects UInt3 as first argument."));

DELETE(T3<uint32_t>,(T3<uint32_t> *)F->data);
}SV UInt3_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3's constructor" EAOE));
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,"UInt3's constructor expects UInt3 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(UInt3_funcs,NEW(UInt3),EXT->UInt3_typeID);
if(a.getCount()==2)
if(true&&TS(float,a[1]))
R S::createNativeObject(UInt3_funcs,NEW(UInt3,val_to_c<float>::f(ctx,a[1])),EXT->UInt3_typeID);
if(a.getCount()==4)
if(true&&TS(float,a[1])&&TS(float,a[2])&&TS(float,a[3]))
R S::createNativeObject(UInt3_funcs,NEW(UInt3,val_to_c<float>::f(ctx,a[1]),val_to_c<float>::f(ctx,a[2]),val_to_c<float>::f(ctx,a[3])),EXT->UInt3_typeID);
if(a.getCount()==2)
if(true&&TS(const T3<float> &,a[1]))
R S::createNativeObject(UInt3_funcs,NEW(UInt3,val_to_c<const T3<float> &>::f(ctx,a[1])),EXT->UInt3_typeID);
if(a.getCount()==2)
if(true&&TS(const T3<int32_t> &,a[1]))
R S::createNativeObject(UInt3_funcs,NEW(UInt3,val_to_c<const T3<int32_t> &>::f(ctx,a[1])),EXT->UInt3_typeID);
if(a.getCount()==2)
if(true&&TS(const T3<uint32_t> &,a[1]))
R S::createNativeObject(UInt3_funcs,NEW(UInt3,val_to_c<const T3<uint32_t> &>::f(ctx,a[1])),EXT->UInt3_typeID);
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
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::setYZX","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setYZX(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T3<uint32_t>,a[0]))
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
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::setYZ","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setYZ(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::setYX","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setYX(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::setZYX","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setZYX(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T3<uint32_t>,a[0]))
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
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::distanceSquared","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV( F->distanceSquared(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T3<uint32_t>,a[0]))
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
if(!TS(T3<uint32_t>,a[0]))
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
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::__leq__","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F <= val_to_c<const T3<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt3::__leq__.")));
R CN;
}

SV UInt3_setXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::setXZY" EAOE));
T3<uint32_t>*F;
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::setXZY","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setXZY(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T3<uint32_t>,a[0]))
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
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::cross","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV( F->cross(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T3<uint32_t>,a[0]))
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
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::__less__","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F < val_to_c<const T3<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt3::__less__.")));
R CN;
}

SV UInt3___neq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::__neq__" EAOE));
T3<uint32_t>*F;
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::__neq__","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F != val_to_c<const T3<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt3::__neq__.")));
R CN;
}

SV UInt3_getYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::getYZ" EAOE));
T3<uint32_t>*F;
if(!TS(T3<uint32_t>,a[0]))
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
if(!TS(T3<uint32_t>,a[0]))
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
if(!TS(T3<uint32_t>,a[0]))
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
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::__div__","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F / val_to_c<const T3<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F / val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt3::__div__.")));
R CN;
}

SV UInt3_setZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::setZY" EAOE));
T3<uint32_t>*F;
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::setZY","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setZY(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::setZX","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setZX(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::setXY","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setXY(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::__add__","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F + val_to_c<const T3<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F + val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt3::__add__.")));
R CN;
}

SV UInt3_setXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::setXZ" EAOE));
T3<uint32_t>*F;
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::setXZ","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setXZ(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::__eq__","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F == val_to_c<const T3<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt3::__eq__.")));
R CN;
}

SV UInt3_setZXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::setZXY" EAOE));
T3<uint32_t>*F;
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::setZXY","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setZXY(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::setYXZ","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setYXZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T3<uint32_t>,a[0]))
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
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::distance","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV( F->distance(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T3<uint32_t>,a[0]))
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
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::__grtr__","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F > val_to_c<const T3<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt3::__grtr__.")));
R CN;
}

SV UInt3_getXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::getXZY" EAOE));
T3<uint32_t>*F;
if(!TS(T3<uint32_t>,a[0]))
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
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::setXYZ","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setXYZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T3<uint32_t>,a[0]))
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
if(!TS(T3<uint32_t>,a[0]))
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
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::__mul__","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F * val_to_c<const T3<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F * val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt3::__mul__.")));
R CN;
}

SV UInt3_getYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::getYXZ" EAOE));
T3<uint32_t>*F;
if(!TS(T3<uint32_t>,a[0]))
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
if(!TS(T3<uint32_t>,a[0]))
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
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::__sub__","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F - val_to_c<const T3<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F - val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt3::__sub__.")));
R CN;
}

SV UInt3___geq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::__geq__" EAOE));
T3<uint32_t>*F;
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::__geq__","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F >= val_to_c<const T3<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt3::__geq__.")));
R CN;
}

SV UInt3_dot(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt3::dot" EAOE));
T3<uint32_t>*F;
if(!TS(T3<uint32_t>,a[0]))
CATE(TE,FAE("UInt3::dot","UInt3")));
else
 F=(T3<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
CATE(TE,UFOF("UInt3::dot.")));
R CN;
}

void UInt2_destroy(CTX ctx,NO F)
{
if(!TS(T2<uint32_t>, (SV)F))
CATE(TE,"UInt2::__del__ expects UInt2 as first argument."));

DELETE(T2<uint32_t>,(T2<uint32_t> *)F->data);
}SV UInt2_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2's constructor" EAOE));
if(!TS(T2<uint32_t>,a[0]))
CATE(TE,"UInt2's constructor expects UInt2 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(UInt2_funcs,NEW(UInt2),EXT->UInt2_typeID);
if(a.getCount()==2)
if(true&&TS(float,a[1]))
R S::createNativeObject(UInt2_funcs,NEW(UInt2,val_to_c<float>::f(ctx,a[1])),EXT->UInt2_typeID);
if(a.getCount()==3)
if(true&&TS(float,a[1])&&TS(float,a[2]))
R S::createNativeObject(UInt2_funcs,NEW(UInt2,val_to_c<float>::f(ctx,a[1]),val_to_c<float>::f(ctx,a[2])),EXT->UInt2_typeID);
if(a.getCount()==2)
if(true&&TS(const T2<float> &,a[1]))
R S::createNativeObject(UInt2_funcs,NEW(UInt2,val_to_c<const T2<float> &>::f(ctx,a[1])),EXT->UInt2_typeID);
if(a.getCount()==2)
if(true&&TS(const T2<int32_t> &,a[1]))
R S::createNativeObject(UInt2_funcs,NEW(UInt2,val_to_c<const T2<int32_t> &>::f(ctx,a[1])),EXT->UInt2_typeID);
if(a.getCount()==2)
if(true&&TS(const T2<uint32_t> &,a[1]))
R S::createNativeObject(UInt2_funcs,NEW(UInt2,val_to_c<const T2<uint32_t> &>::f(ctx,a[1])),EXT->UInt2_typeID);
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
if(!TS(T2<uint32_t>,a[0]))
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
if(!TS(T2<uint32_t>,a[0]))
CATE(TE,FAE("UInt2::distance","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV( F->distance(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T2<uint32_t>,a[0]))
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
if(!TS(T2<uint32_t>,a[0]))
CATE(TE,FAE("UInt2::__leq__","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F <= val_to_c<const T2<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt2::__leq__.")));
R CN;
}

SV UInt2_setYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::setYX" EAOE));
T2<uint32_t>*F;
if(!TS(T2<uint32_t>,a[0]))
CATE(TE,FAE("UInt2::setYX","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setYX(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T2<uint32_t>,a[0]))
CATE(TE,FAE("UInt2::__grtr__","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F > val_to_c<const T2<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt2::__grtr__.")));
R CN;
}

SV UInt2_sum(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::sum" EAOE));
T2<uint32_t>*F;
if(!TS(T2<uint32_t>,a[0]))
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
if(!TS(T2<uint32_t>,a[0]))
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
if(!TS(T2<uint32_t>,a[0]))
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
if(!TS(T2<uint32_t>,a[0]))
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
if(!TS(T2<uint32_t>,a[0]))
CATE(TE,FAE("UInt2::__div__","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F / val_to_c<const T2<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(float,a[1]))
{
R CV(*F / val_to_c<float>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt2::__div__.")));
R CN;
}

SV UInt2_setXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::setXY" EAOE));
T2<uint32_t>*F;
if(!TS(T2<uint32_t>,a[0]))
CATE(TE,FAE("UInt2::setXY","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setXY(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T2<uint32_t>,a[0]))
CATE(TE,FAE("UInt2::__mul__","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F * val_to_c<const T2<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(float,a[1]))
{
R CV(*F * val_to_c<float>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt2::__mul__.")));
R CN;
}

SV UInt2___add__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::__add__" EAOE));
T2<uint32_t>*F;
if(!TS(T2<uint32_t>,a[0]))
CATE(TE,FAE("UInt2::__add__","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F + val_to_c<const T2<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(float,a[1]))
{
R CV(*F + val_to_c<float>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt2::__add__.")));
R CN;
}

SV UInt2___less__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::__less__" EAOE));
T2<uint32_t>*F;
if(!TS(T2<uint32_t>,a[0]))
CATE(TE,FAE("UInt2::__less__","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F < val_to_c<const T2<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt2::__less__.")));
R CN;
}

SV UInt2___sub__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::__sub__" EAOE));
T2<uint32_t>*F;
if(!TS(T2<uint32_t>,a[0]))
CATE(TE,FAE("UInt2::__sub__","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F - val_to_c<const T2<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(float,a[1]))
{
R CV(*F - val_to_c<float>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt2::__sub__.")));
R CN;
}

SV UInt2___geq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::__geq__" EAOE));
T2<uint32_t>*F;
if(!TS(T2<uint32_t>,a[0]))
CATE(TE,FAE("UInt2::__geq__","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F >= val_to_c<const T2<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt2::__geq__.")));
R CN;
}

SV UInt2_distanceSquared(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::distanceSquared" EAOE));
T2<uint32_t>*F;
if(!TS(T2<uint32_t>,a[0]))
CATE(TE,FAE("UInt2::distanceSquared","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV( F->distanceSquared(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T2<uint32_t>,a[0]))
CATE(TE,FAE("UInt2::__eq__","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F == val_to_c<const T2<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt2::__eq__.")));
R CN;
}

SV UInt2_dot(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::dot" EAOE));
T2<uint32_t>*F;
if(!TS(T2<uint32_t>,a[0]))
CATE(TE,FAE("UInt2::dot","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
CATE(TE,UFOF("UInt2::dot.")));
R CN;
}

SV UInt2___neq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt2::__neq__" EAOE));
T2<uint32_t>*F;
if(!TS(T2<uint32_t>,a[0]))
CATE(TE,FAE("UInt2::__neq__","UInt2")));
else
 F=(T2<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F != val_to_c<const T2<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt2::__neq__.")));
R CN;
}

void RigidBody_destroy(CTX ctx,NO F)
{
if(!TS(RigidBody, (SV)F))
CATE(TE,"RigidBody::__del__ expects RigidBody as first argument."));

}SV RigidBody_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=1)
CATE(VE,"RigidBody's constructor" EAOE));
if(!TS(RigidBody,a[0]))
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
if(!TS(RigidBody,a[0]))
CATE(TE,FAE("RigidBody::setGravity","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Vector3D &,a[1]))
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
if(!TS(RigidBody,a[0]))
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
if(!TS(RigidBody,a[0]))
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
if(!TS(RigidBody,a[0]))
CATE(TE,FAE("RigidBody::setAngularFactor","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Float3 &,a[1]))
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
if(!TS(RigidBody,a[0]))
CATE(TE,FAE("RigidBody::getVelocityOfPoint","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Position3D &,a[1]))
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
if(!TS(RigidBody,a[0]))
CATE(TE,FAE("RigidBody::setTransform","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Matrix4x4 &,a[1]))
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
if(!TS(RigidBody,a[0]))
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
if(!TS(RigidBody,a[0]))
CATE(TE,FAE("RigidBody::setFriction","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(RigidBody,a[0]))
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
if(!TS(RigidBody,a[0]))
CATE(TE,FAE("RigidBody::applyImpulse","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(const Vector3D &,a[1])&&TS(const Position3D &,a[2]))
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
if(!TS(RigidBody,a[0]))
CATE(TE,FAE("RigidBody::applyTorque","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Vector3D &,a[1]))
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
if(!TS(RigidBody,a[0]))
CATE(TE,FAE("RigidBody::setLinearFactor","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Float3 &,a[1]))
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
if(!TS(RigidBody,a[0]))
CATE(TE,FAE("RigidBody::setLinearDamping","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(RigidBody,a[0]))
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
if(!TS(RigidBody,a[0]))
CATE(TE,FAE("RigidBody::setAngularDamping","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(RigidBody,a[0]))
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
if(!TS(RigidBody,a[0]))
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
if(!TS(RigidBody,a[0]))
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
if(!TS(RigidBody,a[0]))
CATE(TE,FAE("RigidBody::setAngularSleepingThreshold","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(RigidBody,a[0]))
CATE(TE,FAE("RigidBody::applyTorqueImpulse","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Vector3D &,a[1]))
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
if(!TS(RigidBody,a[0]))
CATE(TE,FAE("RigidBody::setLinearVelocity","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Vector3D &,a[1]))
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
if(!TS(RigidBody,a[0]))
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
if(!TS(RigidBody,a[0]))
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
if(!TS(RigidBody,a[0]))
CATE(TE,FAE("RigidBody::setAngularVelocity","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Vector3D &,a[1]))
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
if(!TS(RigidBody,a[0]))
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
if(!TS(RigidBody,a[0]))
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
if(!TS(RigidBody,a[0]))
CATE(TE,FAE("RigidBody::setLinearSleepingThreshold","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(RigidBody,a[0]))
CATE(TE,FAE("RigidBody::setRollingFriction","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(RigidBody,a[0]))
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
if(!TS(RigidBody,a[0]))
CATE(TE,FAE("RigidBody::setMass","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(RigidBody,a[0]))
CATE(TE,FAE("RigidBody::applyCentralImpulse","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Vector3D &,a[1]))
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
if(!TS(RigidBody,a[0]))
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
if(!TS(RigidBody,a[0]))
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
if(!TS(RigidBody,a[0]))
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
if(!TS(RigidBody,a[0]))
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
if(!TS(RigidBody,a[0]))
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
if(!TS(RigidBody,a[0]))
CATE(TE,FAE("RigidBody::applyForce","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(const Vector3D &,a[1])&&TS(const Position3D &,a[2]))
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
if(!TS(RigidBody,a[0]))
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
if(!TS(RigidBody,a[0]))
CATE(TE,FAE("RigidBody::setRestitution","RigidBody")));
else
 F=(RigidBody*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(RigidBody,a[0]))
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
if(!TS(RigidBody,a[0]))
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

void File_destroy(CTX ctx,NO F)
{
if(!TS(File, (SV)F))
CATE(TE,"File::__del__ expects File as first argument."));

DELETE(File,(File *)F->data);
}SV File_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"File's constructor" EAOE));
if(!TS(File,a[0]))
CATE(TE,"File's constructor expects File as first argument."));
if(a.getCount()==3)
if(true&&TS(const char *,a[1])&&TS(const char *,a[2]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
CATE(TE,FAE("File::writeChar","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(char,a[1]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
CATE(TE,FAE("File::writeInt32BE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(int32_t,a[1]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
CATE(TE,FAE("File::writeUInt32BE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(uint32_t,a[1]))
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
if(!TS(File,a[0]))
CATE(TE,FAE("File::writeUInt64LE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(uint64_t,a[1]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
CATE(TE,FAE("File::writeFloat32","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(File,a[0]))
CATE(TE,FAE("File::writeInt64BE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(int64_t,a[1]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
CATE(TE,FAE("File::writeUInt32LE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(uint32_t,a[1]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
CATE(TE,FAE("File::writeUInt64BE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(uint64_t,a[1]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
CATE(TE,FAE("File::writeInt16LE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(int16_t,a[1]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
CATE(TE,FAE("File::writeInt64LE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(int64_t,a[1]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
CATE(TE,FAE("File::writeInt32LE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(int32_t,a[1]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
CATE(TE,FAE("File::writeUInt16LE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(uint16_t,a[1]))
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
if(!TS(File,a[0]))
CATE(TE,FAE("File::writeInt8","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(int8_t,a[1]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
CATE(TE,FAE("File::writeUInt16BE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(uint16_t,a[1]))
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
if(!TS(File,a[0]))
CATE(TE,FAE("File::writeUInt8","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(uint8_t,a[1]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
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
if(!TS(File,a[0]))
CATE(TE,FAE("File::writeInt16BE","File")));
else
 F=(File*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(int16_t,a[1]))
{
( F->writeInt16BE(val_to_c<int16_t>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("File::writeInt16BE.")));
R CN;
}

void Int3_destroy(CTX ctx,NO F)
{
if(!TS(T3<int32_t>, (SV)F))
CATE(TE,"Int3::__del__ expects Int3 as first argument."));

DELETE(T3<int32_t>,(T3<int32_t> *)F->data);
}SV Int3_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3's constructor" EAOE));
if(!TS(T3<int32_t>,a[0]))
CATE(TE,"Int3's constructor expects Int3 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Int3_funcs,NEW(Int3),EXT->Int3_typeID);
if(a.getCount()==2)
if(true&&TS(float,a[1]))
R S::createNativeObject(Int3_funcs,NEW(Int3,val_to_c<float>::f(ctx,a[1])),EXT->Int3_typeID);
if(a.getCount()==4)
if(true&&TS(float,a[1])&&TS(float,a[2])&&TS(float,a[3]))
R S::createNativeObject(Int3_funcs,NEW(Int3,val_to_c<float>::f(ctx,a[1]),val_to_c<float>::f(ctx,a[2]),val_to_c<float>::f(ctx,a[3])),EXT->Int3_typeID);
if(a.getCount()==2)
if(true&&TS(const T3<float> &,a[1]))
R S::createNativeObject(Int3_funcs,NEW(Int3,val_to_c<const T3<float> &>::f(ctx,a[1])),EXT->Int3_typeID);
if(a.getCount()==2)
if(true&&TS(const T3<int32_t> &,a[1]))
R S::createNativeObject(Int3_funcs,NEW(Int3,val_to_c<const T3<int32_t> &>::f(ctx,a[1])),EXT->Int3_typeID);
if(a.getCount()==2)
if(true&&TS(const T3<uint32_t> &,a[1]))
R S::createNativeObject(Int3_funcs,NEW(Int3,val_to_c<const T3<uint32_t> &>::f(ctx,a[1])),EXT->Int3_typeID);
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
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::setYZX","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setYZX(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T3<int32_t>,a[0]))
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
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::setYZ","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setYZ(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::setYX","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setYX(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::setZYX","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setZYX(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T3<int32_t>,a[0]))
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
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::distanceSquared","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV( F->distanceSquared(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T3<int32_t>,a[0]))
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
if(!TS(T3<int32_t>,a[0]))
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
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::__leq__","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F <= val_to_c<const T3<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int3::__leq__.")));
R CN;
}

SV Int3_setXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::setXZY" EAOE));
T3<int32_t>*F;
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::setXZY","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setXZY(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T3<int32_t>,a[0]))
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
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::cross","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV( F->cross(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T3<int32_t>,a[0]))
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
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::__less__","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F < val_to_c<const T3<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int3::__less__.")));
R CN;
}

SV Int3___neq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::__neq__" EAOE));
T3<int32_t>*F;
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::__neq__","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F != val_to_c<const T3<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int3::__neq__.")));
R CN;
}

SV Int3_getYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::getYZ" EAOE));
T3<int32_t>*F;
if(!TS(T3<int32_t>,a[0]))
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
if(!TS(T3<int32_t>,a[0]))
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
if(!TS(T3<int32_t>,a[0]))
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
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::__div__","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F / val_to_c<const T3<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F / val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int3::__div__.")));
R CN;
}

SV Int3_setZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::setZY" EAOE));
T3<int32_t>*F;
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::setZY","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setZY(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::setZX","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setZX(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::setXY","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setXY(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::__add__","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F + val_to_c<const T3<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F + val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int3::__add__.")));
R CN;
}

SV Int3_setXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::setXZ" EAOE));
T3<int32_t>*F;
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::setXZ","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setXZ(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::__eq__","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F == val_to_c<const T3<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int3::__eq__.")));
R CN;
}

SV Int3_setZXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::setZXY" EAOE));
T3<int32_t>*F;
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::setZXY","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setZXY(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::setYXZ","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setYXZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T3<int32_t>,a[0]))
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
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::distance","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV( F->distance(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T3<int32_t>,a[0]))
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
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::__grtr__","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F > val_to_c<const T3<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int3::__grtr__.")));
R CN;
}

SV Int3_getXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::getXZY" EAOE));
T3<int32_t>*F;
if(!TS(T3<int32_t>,a[0]))
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
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::setXYZ","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setXYZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T3<int32_t>,a[0]))
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
if(!TS(T3<int32_t>,a[0]))
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
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::__mul__","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F * val_to_c<const T3<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F * val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int3::__mul__.")));
R CN;
}

SV Int3_getYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::getYXZ" EAOE));
T3<int32_t>*F;
if(!TS(T3<int32_t>,a[0]))
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
if(!TS(T3<int32_t>,a[0]))
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
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::__sub__","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F - val_to_c<const T3<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F - val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int3::__sub__.")));
R CN;
}

SV Int3___geq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::__geq__" EAOE));
T3<int32_t>*F;
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::__geq__","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F >= val_to_c<const T3<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int3::__geq__.")));
R CN;
}

SV Int3_dot(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int3::dot" EAOE));
T3<int32_t>*F;
if(!TS(T3<int32_t>,a[0]))
CATE(TE,FAE("Int3::dot","Int3")));
else
 F=(T3<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
CATE(TE,UFOF("Int3::dot.")));
R CN;
}

void Camera_destroy(CTX ctx,NO F)
{
if(!TS(Camera, (SV)F))
CATE(TE,"Camera::__del__ expects Camera as first argument."));

DELETE(Camera,(Camera *)F->data);
}SV Camera_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera's constructor" EAOE));
if(!TS(Camera,a[0]))
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
if(!TS(Camera,a[0]))
CATE(TE,FAE("Camera::setBottom","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(Camera,a[0]))
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
if(!TS(Camera,a[0]))
CATE(TE,FAE("Camera::setTop","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(Camera,a[0]))
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
if(!TS(Camera,a[0]))
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
if(!TS(Camera,a[0]))
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
if(!TS(Camera,a[0]))
CATE(TE,FAE("Camera::setWidth","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(Camera,a[0]))
CATE(TE,FAE("Camera::setType","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

CATE(TE,UFOF("Camera::setType.")));
R CN;
}

SV Camera_setDirection(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::setDirection" EAOE));
Camera*F;
if(!TS(Camera,a[0]))
CATE(TE,FAE("Camera::setDirection","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Direction3D &,a[1]))
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
if(!TS(Camera,a[0]))
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
if(!TS(Camera,a[0]))
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
if(!TS(Camera,a[0]))
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
if(!TS(Camera,a[0]))
CATE(TE,FAE("Camera::setFar","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(Camera,a[0]))
CATE(TE,FAE("Camera::setFieldOfView","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(Camera,a[0]))
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
if(!TS(Camera,a[0]))
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
if(!TS(Camera,a[0]))
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
if(!TS(Camera,a[0]))
CATE(TE,FAE("Camera::setUp","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Direction3D &,a[1]))
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
if(!TS(Camera,a[0]))
CATE(TE,FAE("Camera::getType","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

CATE(TE,UFOF("Camera::getType.")));
R CN;
}

SV Camera_setNear(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Camera::setNear" EAOE));
Camera*F;
if(!TS(Camera,a[0]))
CATE(TE,FAE("Camera::setNear","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(Camera,a[0]))
CATE(TE,FAE("Camera::setPosition","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Position3D &,a[1]))
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
if(!TS(Camera,a[0]))
CATE(TE,FAE("Camera::setLeft","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(Camera,a[0]))
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
if(!TS(Camera,a[0]))
CATE(TE,FAE("Camera::setHeight","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(Camera,a[0]))
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
if(!TS(Camera,a[0]))
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
if(!TS(Camera,a[0]))
CATE(TE,FAE("Camera::setRight","Camera")));
else
 F=(Camera*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(Camera,a[0]))
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

void Float2_destroy(CTX ctx,NO F)
{
if(!TS(T2<float>, (SV)F))
CATE(TE,"Float2::__del__ expects Float2 as first argument."));

DELETE(T2<float>,(T2<float> *)F->data);
}SV Float2_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2's constructor" EAOE));
if(!TS(T2<float>,a[0]))
CATE(TE,"Float2's constructor expects Float2 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Float2_funcs,NEW(Float2),EXT->Float2_typeID);
if(a.getCount()==2)
if(true&&TS(float,a[1]))
R S::createNativeObject(Float2_funcs,NEW(Float2,val_to_c<float>::f(ctx,a[1])),EXT->Float2_typeID);
if(a.getCount()==3)
if(true&&TS(float,a[1])&&TS(float,a[2]))
R S::createNativeObject(Float2_funcs,NEW(Float2,val_to_c<float>::f(ctx,a[1]),val_to_c<float>::f(ctx,a[2])),EXT->Float2_typeID);
if(a.getCount()==2)
if(true&&TS(const T2<float> &,a[1]))
R S::createNativeObject(Float2_funcs,NEW(Float2,val_to_c<const T2<float> &>::f(ctx,a[1])),EXT->Float2_typeID);
if(a.getCount()==2)
if(true&&TS(const T2<int32_t> &,a[1]))
R S::createNativeObject(Float2_funcs,NEW(Float2,val_to_c<const T2<int32_t> &>::f(ctx,a[1])),EXT->Float2_typeID);
if(a.getCount()==2)
if(true&&TS(const T2<uint32_t> &,a[1]))
R S::createNativeObject(Float2_funcs,NEW(Float2,val_to_c<const T2<uint32_t> &>::f(ctx,a[1])),EXT->Float2_typeID);
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
if(!TS(T2<float>,a[0]))
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
if(!TS(T2<float>,a[0]))
CATE(TE,FAE("Float2::distance","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T2<float>,a[0]))
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
if(!TS(T2<float>,a[0]))
CATE(TE,FAE("Float2::__leq__","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F <= val_to_c<const T2<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float2::__leq__.")));
R CN;
}

SV Float2_setYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::setYX" EAOE));
T2<float>*F;
if(!TS(T2<float>,a[0]))
CATE(TE,FAE("Float2::setYX","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T2<float>,a[0]))
CATE(TE,FAE("Float2::__grtr__","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F > val_to_c<const T2<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float2::__grtr__.")));
R CN;
}

SV Float2_sum(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::sum" EAOE));
T2<float>*F;
if(!TS(T2<float>,a[0]))
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
if(!TS(T2<float>,a[0]))
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
if(!TS(T2<float>,a[0]))
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
if(!TS(T2<float>,a[0]))
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
if(!TS(T2<float>,a[0]))
CATE(TE,FAE("Float2::__div__","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F / val_to_c<const T2<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(float,a[1]))
{
R CV(*F / val_to_c<float>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float2::__div__.")));
R CN;
}

SV Float2_setXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::setXY" EAOE));
T2<float>*F;
if(!TS(T2<float>,a[0]))
CATE(TE,FAE("Float2::setXY","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T2<float>,a[0]))
CATE(TE,FAE("Float2::__mul__","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F * val_to_c<const T2<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(float,a[1]))
{
R CV(*F * val_to_c<float>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float2::__mul__.")));
R CN;
}

SV Float2___add__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::__add__" EAOE));
T2<float>*F;
if(!TS(T2<float>,a[0]))
CATE(TE,FAE("Float2::__add__","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F + val_to_c<const T2<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(float,a[1]))
{
R CV(*F + val_to_c<float>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float2::__add__.")));
R CN;
}

SV Float2___less__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::__less__" EAOE));
T2<float>*F;
if(!TS(T2<float>,a[0]))
CATE(TE,FAE("Float2::__less__","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F < val_to_c<const T2<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float2::__less__.")));
R CN;
}

SV Float2___sub__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::__sub__" EAOE));
T2<float>*F;
if(!TS(T2<float>,a[0]))
CATE(TE,FAE("Float2::__sub__","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F - val_to_c<const T2<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(float,a[1]))
{
R CV(*F - val_to_c<float>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float2::__sub__.")));
R CN;
}

SV Float2___geq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::__geq__" EAOE));
T2<float>*F;
if(!TS(T2<float>,a[0]))
CATE(TE,FAE("Float2::__geq__","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F >= val_to_c<const T2<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float2::__geq__.")));
R CN;
}

SV Float2_distanceSquared(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::distanceSquared" EAOE));
T2<float>*F;
if(!TS(T2<float>,a[0]))
CATE(TE,FAE("Float2::distanceSquared","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T2<float>,a[0]))
CATE(TE,FAE("Float2::__eq__","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F == val_to_c<const T2<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float2::__eq__.")));
R CN;
}

SV Float2_dot(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float2::dot" EAOE));
T2<float>*F;
if(!TS(T2<float>,a[0]))
CATE(TE,FAE("Float2::dot","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T2<float>,a[0]))
CATE(TE,FAE("Float2::__neq__","Float2")));
else
 F=(T2<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F != val_to_c<const T2<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float2::__neq__.")));
R CN;
}

void Int4_destroy(CTX ctx,NO F)
{
if(!TS(T4<int32_t>, (SV)F))
CATE(TE,"Int4::__del__ expects Int4 as first argument."));

DELETE(T4<int32_t>,(T4<int32_t> *)F->data);
}SV Int4_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4's constructor" EAOE));
if(!TS(T4<int32_t>,a[0]))
CATE(TE,"Int4's constructor expects Int4 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Int4_funcs,NEW(Int4),EXT->Int4_typeID);
if(a.getCount()==2)
if(true&&TS(float,a[1]))
R S::createNativeObject(Int4_funcs,NEW(Int4,val_to_c<float>::f(ctx,a[1])),EXT->Int4_typeID);
if(a.getCount()==5)
if(true&&TS(float,a[1])&&TS(float,a[2])&&TS(float,a[3])&&TS(float,a[4]))
R S::createNativeObject(Int4_funcs,NEW(Int4,val_to_c<float>::f(ctx,a[1]),val_to_c<float>::f(ctx,a[2]),val_to_c<float>::f(ctx,a[3]),val_to_c<float>::f(ctx,a[4])),EXT->Int4_typeID);
if(a.getCount()==2)
if(true&&TS(const T4<float> &,a[1]))
R S::createNativeObject(Int4_funcs,NEW(Int4,val_to_c<const T4<float> &>::f(ctx,a[1])),EXT->Int4_typeID);
if(a.getCount()==2)
if(true&&TS(const T4<int32_t> &,a[1]))
R S::createNativeObject(Int4_funcs,NEW(Int4,val_to_c<const T4<int32_t> &>::f(ctx,a[1])),EXT->Int4_typeID);
if(a.getCount()==2)
if(true&&TS(const T4<uint32_t> &,a[1]))
R S::createNativeObject(Int4_funcs,NEW(Int4,val_to_c<const T4<uint32_t> &>::f(ctx,a[1])),EXT->Int4_typeID);
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setZXYW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setZXYW(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setWYZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setWYZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setWYX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setWYX(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::distanceSquared","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV( F->distanceSquared(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setYZWX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setYZWX(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setXWYZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setXWYZ(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setZY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setZY(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setZX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setZX(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setZW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setZW(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setZYWX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setZYWX(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setYXZW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setYXZW(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setXWZY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setXWZY(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setWZYX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setWZYX(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setZYW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setZYW(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setZYX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setZYX(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setXZYW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setXZYW(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setYZW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setYZW(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::__leq__","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F <= val_to_c<const T4<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int4::__leq__.")));
R CN;
}

SV Int4_getYWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getYWX" EAOE));
T4<int32_t>*F;
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setYZX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setYZX(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setYWZX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setYWZX(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setWXY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setWXY(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setWXZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setWXZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setZXW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setZXW(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setWYXZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setWYXZ(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setZXY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setZXY(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setXYWZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setXYWZ(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setWXZY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setWXZY(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setXWZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setXWZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setXWY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setXWY(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setZWY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setZWY(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setZWX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setZWX(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setWX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setWX(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setWY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setWY(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setWZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setWZ(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setYXZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setYXZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setYXW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setYXW(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::__less__","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F < val_to_c<const T4<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int4::__less__.")));
R CN;
}

SV Int4_getZYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getZYW" EAOE));
T4<int32_t>*F;
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setWZY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setWZY(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setWZX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setWZX(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setZYXW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setZYXW(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setYXWZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setYXWZ(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::__eq__","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F == val_to_c<const T4<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int4::__eq__.")));
R CN;
}

SV Int4_getWYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getWYXZ" EAOE));
T4<int32_t>*F;
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::distance","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV( F->distance(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setYZXW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setYZXW(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setZWYX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setZWYX(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::__sub__","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F - val_to_c<const T4<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F - val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int4::__sub__.")));
R CN;
}

SV Int4_getYXWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getYXWZ" EAOE));
T4<int32_t>*F;
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setXZWY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setXZWY(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setYWZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setYWZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setYWX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setYWX(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setYZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setYZ(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setYX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setYX(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setYW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setYW(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::__neq__","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F != val_to_c<const T4<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int4::__neq__.")));
R CN;
}

SV Int4_normalize(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::normalize" EAOE));
T4<int32_t>*F;
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setXZW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setXZW(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setXZY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setXZY(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setXYZW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setXYZW(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setWXYZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setWXYZ(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::__mul__","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F * val_to_c<const T4<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F * val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int4::__mul__.")));
R CN;
}

SV Int4_getYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::getYZ" EAOE));
T4<int32_t>*F;
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setXY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setXY(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::__add__","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F + val_to_c<const T4<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F + val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int4::__add__.")));
R CN;
}

SV Int4_setXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setXZ" EAOE));
T4<int32_t>*F;
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setXZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setXZ(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setXW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setXW(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setZXWY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setZXWY(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setXYW","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setXYW(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setWZXY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setWZXY(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::__grtr__","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F > val_to_c<const T4<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int4::__grtr__.")));
R CN;
}

SV Int4_setZWXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setZWXY" EAOE));
T4<int32_t>*F;
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setZWXY","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setZWXY(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setXYZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setXYZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::__div__","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F / val_to_c<const T4<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F / val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int4::__div__.")));
R CN;
}

SV Int4_setWYZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::setWYZX" EAOE));
T4<int32_t>*F;
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setWYZX","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setWYZX(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::setYWXZ","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setYWXZ(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::__geq__","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F >= val_to_c<const T4<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int4::__geq__.")));
R CN;
}

SV Int4_dot(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int4::dot" EAOE));
T4<int32_t>*F;
if(!TS(T4<int32_t>,a[0]))
CATE(TE,FAE("Int4::dot","Int4")));
else
 F=(T4<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
CATE(TE,UFOF("Int4::dot.")));
R CN;
}

void Float3_destroy(CTX ctx,NO F)
{
if(!TS(T3<float>, (SV)F))
CATE(TE,"Float3::__del__ expects Float3 as first argument."));

DELETE(T3<float>,(T3<float> *)F->data);
}SV Float3_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3's constructor" EAOE));
if(!TS(T3<float>,a[0]))
CATE(TE,"Float3's constructor expects Float3 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Float3_funcs,NEW(Float3),EXT->Float3_typeID);
if(a.getCount()==2)
if(true&&TS(float,a[1]))
R S::createNativeObject(Float3_funcs,NEW(Float3,val_to_c<float>::f(ctx,a[1])),EXT->Float3_typeID);
if(a.getCount()==4)
if(true&&TS(float,a[1])&&TS(float,a[2])&&TS(float,a[3]))
R S::createNativeObject(Float3_funcs,NEW(Float3,val_to_c<float>::f(ctx,a[1]),val_to_c<float>::f(ctx,a[2]),val_to_c<float>::f(ctx,a[3])),EXT->Float3_typeID);
if(a.getCount()==2)
if(true&&TS(const T3<float> &,a[1]))
R S::createNativeObject(Float3_funcs,NEW(Float3,val_to_c<const T3<float> &>::f(ctx,a[1])),EXT->Float3_typeID);
if(a.getCount()==2)
if(true&&TS(const T3<int32_t> &,a[1]))
R S::createNativeObject(Float3_funcs,NEW(Float3,val_to_c<const T3<int32_t> &>::f(ctx,a[1])),EXT->Float3_typeID);
if(a.getCount()==2)
if(true&&TS(const T3<uint32_t> &,a[1]))
R S::createNativeObject(Float3_funcs,NEW(Float3,val_to_c<const T3<uint32_t> &>::f(ctx,a[1])),EXT->Float3_typeID);
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
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::setYZX","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T3<float>,a[0]))
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
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::setYZ","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::setYX","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::setZYX","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T3<float>,a[0]))
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
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::distanceSquared","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T3<float>,a[0]))
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
if(!TS(T3<float>,a[0]))
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
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::__leq__","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F <= val_to_c<const T3<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float3::__leq__.")));
R CN;
}

SV Float3_setXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::setXZY" EAOE));
T3<float>*F;
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::setXZY","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T3<float>,a[0]))
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
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::cross","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T3<float>,a[0]))
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
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::__less__","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F < val_to_c<const T3<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float3::__less__.")));
R CN;
}

SV Float3___neq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::__neq__" EAOE));
T3<float>*F;
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::__neq__","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F != val_to_c<const T3<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float3::__neq__.")));
R CN;
}

SV Float3_getYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::getYZ" EAOE));
T3<float>*F;
if(!TS(T3<float>,a[0]))
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
if(!TS(T3<float>,a[0]))
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
if(!TS(T3<float>,a[0]))
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
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::__div__","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F / val_to_c<const T3<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F / val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float3::__div__.")));
R CN;
}

SV Float3_setZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::setZY" EAOE));
T3<float>*F;
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::setZY","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::setZX","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::setXY","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::__add__","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F + val_to_c<const T3<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F + val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float3::__add__.")));
R CN;
}

SV Float3_setXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::setXZ" EAOE));
T3<float>*F;
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::setXZ","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::__eq__","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F == val_to_c<const T3<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float3::__eq__.")));
R CN;
}

SV Float3_setZXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::setZXY" EAOE));
T3<float>*F;
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::setZXY","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::setYXZ","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T3<float>,a[0]))
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
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::distance","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T3<float>,a[0]))
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
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::__grtr__","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F > val_to_c<const T3<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float3::__grtr__.")));
R CN;
}

SV Float3_getXZY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::getXZY" EAOE));
T3<float>*F;
if(!TS(T3<float>,a[0]))
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
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::setXYZ","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T3<float>,a[0]))
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
if(!TS(T3<float>,a[0]))
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
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::__mul__","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F * val_to_c<const T3<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F * val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float3::__mul__.")));
R CN;
}

SV Float3_getYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::getYXZ" EAOE));
T3<float>*F;
if(!TS(T3<float>,a[0]))
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
if(!TS(T3<float>,a[0]))
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
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::__sub__","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F - val_to_c<const T3<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F - val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float3::__sub__.")));
R CN;
}

SV Float3___geq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::__geq__" EAOE));
T3<float>*F;
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::__geq__","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
R CV(*F >= val_to_c<const T3<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float3::__geq__.")));
R CN;
}

SV Float3_dot(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float3::dot" EAOE));
T3<float>*F;
if(!TS(T3<float>,a[0]))
CATE(TE,FAE("Float3::dot","Float3")));
else
 F=(T3<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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

void Transform_destroy(CTX ctx,NO F)
{
if(!TS(Transform, (SV)F))
CATE(TE,"Transform::__del__ expects Transform as first argument."));

DELETE(Transform,(Transform *)F->data);
}SV Transform_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Transform's constructor" EAOE));
if(!TS(Transform,a[0]))
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
if(!TS(Transform,a[0]))
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
if(!TS(Quaternion, (SV)F))
CATE(TE,"Quaternion::__del__ expects Quaternion as first argument."));

DELETE(Quaternion,(Quaternion *)F->data);
}SV Quaternion_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion's constructor" EAOE));
if(!TS(Quaternion,a[0]))
CATE(TE,"Quaternion's constructor expects Quaternion as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Quaternion_funcs,NEW(Quaternion),EXT->Quaternion_typeID);
if(a.getCount()==3)
if(true&&TS(const Direction3D &,a[1])&&TS(float,a[2]))
R S::createNativeObject(Quaternion_funcs,NEW(Quaternion,val_to_c<const Direction3D &>::f(ctx,a[1]),val_to_c<float>::f(ctx,a[2])),EXT->Quaternion_typeID);
if(a.getCount()==5)
if(true&&TS(float,a[1])&&TS(float,a[2])&&TS(float,a[3])&&TS(float,a[4]))
R S::createNativeObject(Quaternion_funcs,NEW(Quaternion,val_to_c<float>::f(ctx,a[1]),val_to_c<float>::f(ctx,a[2]),val_to_c<float>::f(ctx,a[3]),val_to_c<float>::f(ctx,a[4])),EXT->Quaternion_typeID);
if(a.getCount()==2)
if(true&&TS(const Float3 &,a[1]))
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
if(!TS(Quaternion,a[0]))
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
if(!TS(Quaternion,a[0]))
CATE(TE,FAE("Quaternion::setEulerAngles","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Float3 &,a[1]))
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
if(!TS(Quaternion,a[0]))
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
if(!TS(Quaternion,a[0]))
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
if(!TS(Quaternion,a[0]))
CATE(TE,FAE("Quaternion::setAngle","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(Quaternion,a[0]))
CATE(TE,FAE("Quaternion::setYAxis","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(Quaternion,a[0]))
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
if(!TS(Quaternion,a[0]))
CATE(TE,FAE("Quaternion::setAxisAndAngle","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==3)
if(1&&TS(const Direction3D &,a[1])&&TS(float,a[2]))
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
if(!TS(Quaternion,a[0]))
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
if(!TS(Quaternion,a[0]))
CATE(TE,FAE("Quaternion::setAxis","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Direction3D &,a[1]))
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
if(!TS(Quaternion,a[0]))
CATE(TE,FAE("Quaternion::__mul__","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Quaternion &,a[1]))
{
R CV(*F * val_to_c<const Quaternion &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Quaternion::__mul__.")));
R CN;
}

SV Quaternion_getYAxis(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion::getYAxis" EAOE));
Quaternion*F;
if(!TS(Quaternion,a[0]))
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
if(!TS(Quaternion,a[0]))
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
if(!TS(Quaternion,a[0]))
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
if(!TS(Quaternion,a[0]))
CATE(TE,FAE("Quaternion::setZAxis","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(Quaternion,a[0]))
CATE(TE,FAE("Quaternion::setXAxis","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(Quaternion,a[0]))
CATE(TE,FAE("Quaternion::__eq__","Quaternion")));
else
 F=(Quaternion*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Quaternion &,a[1]))
{
R CV(*F == val_to_c<const Quaternion &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Quaternion::__eq__.")));
R CN;
}

SV Quaternion_getZAxis(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Quaternion::getZAxis" EAOE));
Quaternion*F;
if(!TS(Quaternion,a[0]))
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
if(!TS(T2<int32_t>, (SV)F))
CATE(TE,"Int2::__del__ expects Int2 as first argument."));

DELETE(T2<int32_t>,(T2<int32_t> *)F->data);
}SV Int2_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2's constructor" EAOE));
if(!TS(T2<int32_t>,a[0]))
CATE(TE,"Int2's constructor expects Int2 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Int2_funcs,NEW(Int2),EXT->Int2_typeID);
if(a.getCount()==2)
if(true&&TS(float,a[1]))
R S::createNativeObject(Int2_funcs,NEW(Int2,val_to_c<float>::f(ctx,a[1])),EXT->Int2_typeID);
if(a.getCount()==3)
if(true&&TS(float,a[1])&&TS(float,a[2]))
R S::createNativeObject(Int2_funcs,NEW(Int2,val_to_c<float>::f(ctx,a[1]),val_to_c<float>::f(ctx,a[2])),EXT->Int2_typeID);
if(a.getCount()==2)
if(true&&TS(const T2<float> &,a[1]))
R S::createNativeObject(Int2_funcs,NEW(Int2,val_to_c<const T2<float> &>::f(ctx,a[1])),EXT->Int2_typeID);
if(a.getCount()==2)
if(true&&TS(const T2<int32_t> &,a[1]))
R S::createNativeObject(Int2_funcs,NEW(Int2,val_to_c<const T2<int32_t> &>::f(ctx,a[1])),EXT->Int2_typeID);
if(a.getCount()==2)
if(true&&TS(const T2<uint32_t> &,a[1]))
R S::createNativeObject(Int2_funcs,NEW(Int2,val_to_c<const T2<uint32_t> &>::f(ctx,a[1])),EXT->Int2_typeID);
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
if(!TS(T2<int32_t>,a[0]))
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
if(!TS(T2<int32_t>,a[0]))
CATE(TE,FAE("Int2::distance","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV( F->distance(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T2<int32_t>,a[0]))
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
if(!TS(T2<int32_t>,a[0]))
CATE(TE,FAE("Int2::__leq__","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F <= val_to_c<const T2<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int2::__leq__.")));
R CN;
}

SV Int2_setYX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::setYX" EAOE));
T2<int32_t>*F;
if(!TS(T2<int32_t>,a[0]))
CATE(TE,FAE("Int2::setYX","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setYX(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T2<int32_t>,a[0]))
CATE(TE,FAE("Int2::__grtr__","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F > val_to_c<const T2<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int2::__grtr__.")));
R CN;
}

SV Int2_sum(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::sum" EAOE));
T2<int32_t>*F;
if(!TS(T2<int32_t>,a[0]))
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
if(!TS(T2<int32_t>,a[0]))
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
if(!TS(T2<int32_t>,a[0]))
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
if(!TS(T2<int32_t>,a[0]))
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
if(!TS(T2<int32_t>,a[0]))
CATE(TE,FAE("Int2::__div__","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F / val_to_c<const T2<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(float,a[1]))
{
R CV(*F / val_to_c<float>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int2::__div__.")));
R CN;
}

SV Int2_setXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::setXY" EAOE));
T2<int32_t>*F;
if(!TS(T2<int32_t>,a[0]))
CATE(TE,FAE("Int2::setXY","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setXY(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T2<int32_t>,a[0]))
CATE(TE,FAE("Int2::__mul__","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F * val_to_c<const T2<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(float,a[1]))
{
R CV(*F * val_to_c<float>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int2::__mul__.")));
R CN;
}

SV Int2___add__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::__add__" EAOE));
T2<int32_t>*F;
if(!TS(T2<int32_t>,a[0]))
CATE(TE,FAE("Int2::__add__","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F + val_to_c<const T2<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(float,a[1]))
{
R CV(*F + val_to_c<float>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int2::__add__.")));
R CN;
}

SV Int2___less__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::__less__" EAOE));
T2<int32_t>*F;
if(!TS(T2<int32_t>,a[0]))
CATE(TE,FAE("Int2::__less__","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F < val_to_c<const T2<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int2::__less__.")));
R CN;
}

SV Int2___sub__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::__sub__" EAOE));
T2<int32_t>*F;
if(!TS(T2<int32_t>,a[0]))
CATE(TE,FAE("Int2::__sub__","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F - val_to_c<const T2<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(float,a[1]))
{
R CV(*F - val_to_c<float>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int2::__sub__.")));
R CN;
}

SV Int2___geq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::__geq__" EAOE));
T2<int32_t>*F;
if(!TS(T2<int32_t>,a[0]))
CATE(TE,FAE("Int2::__geq__","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F >= val_to_c<const T2<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int2::__geq__.")));
R CN;
}

SV Int2_distanceSquared(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::distanceSquared" EAOE));
T2<int32_t>*F;
if(!TS(T2<int32_t>,a[0]))
CATE(TE,FAE("Int2::distanceSquared","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV( F->distanceSquared(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T2<int32_t>,a[0]))
CATE(TE,FAE("Int2::__eq__","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F == val_to_c<const T2<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int2::__eq__.")));
R CN;
}

SV Int2_dot(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::dot" EAOE));
T2<int32_t>*F;
if(!TS(T2<int32_t>,a[0]))
CATE(TE,FAE("Int2::dot","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
CATE(TE,UFOF("Int2::dot.")));
R CN;
}

SV Int2___neq__(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Int2::__neq__" EAOE));
T2<int32_t>*F;
if(!TS(T2<int32_t>,a[0]))
CATE(TE,FAE("Int2::__neq__","Int2")));
else
 F=(T2<int32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
R CV(*F != val_to_c<const T2<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Int2::__neq__.")));
R CN;
}

void Float4_destroy(CTX ctx,NO F)
{
if(!TS(T4<float>, (SV)F))
CATE(TE,"Float4::__del__ expects Float4 as first argument."));

DELETE(T4<float>,(T4<float> *)F->data);
}SV Float4_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4's constructor" EAOE));
if(!TS(T4<float>,a[0]))
CATE(TE,"Float4's constructor expects Float4 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Float4_funcs,NEW(Float4),EXT->Float4_typeID);
if(a.getCount()==2)
if(true&&TS(float,a[1]))
R S::createNativeObject(Float4_funcs,NEW(Float4,val_to_c<float>::f(ctx,a[1])),EXT->Float4_typeID);
if(a.getCount()==5)
if(true&&TS(float,a[1])&&TS(float,a[2])&&TS(float,a[3])&&TS(float,a[4]))
R S::createNativeObject(Float4_funcs,NEW(Float4,val_to_c<float>::f(ctx,a[1]),val_to_c<float>::f(ctx,a[2]),val_to_c<float>::f(ctx,a[3]),val_to_c<float>::f(ctx,a[4])),EXT->Float4_typeID);
if(a.getCount()==2)
if(true&&TS(const T4<float> &,a[1]))
R S::createNativeObject(Float4_funcs,NEW(Float4,val_to_c<const T4<float> &>::f(ctx,a[1])),EXT->Float4_typeID);
if(a.getCount()==2)
if(true&&TS(const T4<int32_t> &,a[1]))
R S::createNativeObject(Float4_funcs,NEW(Float4,val_to_c<const T4<int32_t> &>::f(ctx,a[1])),EXT->Float4_typeID);
if(a.getCount()==2)
if(true&&TS(const T4<uint32_t> &,a[1]))
R S::createNativeObject(Float4_funcs,NEW(Float4,val_to_c<const T4<uint32_t> &>::f(ctx,a[1])),EXT->Float4_typeID);
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setZXYW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setWYZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setWYX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::distanceSquared","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setYZWX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setXWYZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setZY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setZX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setZW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setZYWX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setYXZW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setXWZY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setWZYX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setZYW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setZYX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setXZYW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setYZW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::__leq__","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F <= val_to_c<const T4<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float4::__leq__.")));
R CN;
}

SV Float4_getYWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getYWX" EAOE));
T4<float>*F;
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setYZX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setYWZX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setWXY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setWXZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setZXW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setWYXZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setZXY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setXYWZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setWXZY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setXWZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setXWY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setZWY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setZWX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setWX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setWY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setWZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setYXZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setYXW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::__less__","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F < val_to_c<const T4<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float4::__less__.")));
R CN;
}

SV Float4_getZYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getZYW" EAOE));
T4<float>*F;
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setWZY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setWZX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setZYXW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setYXWZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::__eq__","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F == val_to_c<const T4<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float4::__eq__.")));
R CN;
}

SV Float4_getWYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getWYXZ" EAOE));
T4<float>*F;
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::distance","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setYZXW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setZWYX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::__sub__","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F - val_to_c<const T4<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F - val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float4::__sub__.")));
R CN;
}

SV Float4_getYXWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getYXWZ" EAOE));
T4<float>*F;
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setXZWY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setYWZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setYWX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setYZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setYX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setYW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::__neq__","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F != val_to_c<const T4<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float4::__neq__.")));
R CN;
}

SV Float4_normalize(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::normalize" EAOE));
T4<float>*F;
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setXZW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setXZY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setXYZW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setWXYZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::__mul__","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F * val_to_c<const T4<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F * val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float4::__mul__.")));
R CN;
}

SV Float4_getYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::getYZ" EAOE));
T4<float>*F;
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setXY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::__add__","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F + val_to_c<const T4<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F + val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float4::__add__.")));
R CN;
}

SV Float4_setXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setXZ" EAOE));
T4<float>*F;
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setXZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setXW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setZXWY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setXYW","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setWZXY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::__grtr__","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F > val_to_c<const T4<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float4::__grtr__.")));
R CN;
}

SV Float4_setZWXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setZWXY" EAOE));
T4<float>*F;
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setZWXY","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setXYZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::__div__","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F / val_to_c<const T4<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F / val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float4::__div__.")));
R CN;
}

SV Float4_setWYZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::setWYZX" EAOE));
T4<float>*F;
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setWYZX","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::setYWXZ","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::__geq__","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F >= val_to_c<const T4<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Float4::__geq__.")));
R CN;
}

SV Float4_dot(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Float4::dot" EAOE));
T4<float>*F;
if(!TS(T4<float>,a[0]))
CATE(TE,FAE("Float4::dot","Float4")));
else
 F=(T4<float>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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

void Matrix4x4_destroy(CTX ctx,NO F)
{
if(!TS(Matrix4x4, (SV)F))
CATE(TE,"Matrix4x4::__del__ expects Matrix4x4 as first argument."));

DELETE(Matrix4x4,(Matrix4x4 *)F->data);
}SV Matrix4x4_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix4x4's constructor" EAOE));
if(!TS(Matrix4x4,a[0]))
CATE(TE,"Matrix4x4's constructor expects Matrix4x4 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Matrix4x4_funcs,NEW(Matrix4x4),EXT->Matrix4x4_typeID);
if(a.getCount()==2)
if(true&&TS(const Matrix3x3 &,a[1]))
R S::createNativeObject(Matrix4x4_funcs,NEW(Matrix4x4,val_to_c<const Matrix3x3 &>::f(ctx,a[1])),EXT->Matrix4x4_typeID);
if(a.getCount()==5)
if(true&&TS(const Float4 &,a[1])&&TS(const Float4 &,a[2])&&TS(const Float4 &,a[3])&&TS(const Float4 &,a[4]))
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
if(!TS(Matrix4x4,a[0]))
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
if(!TS(Matrix4x4,a[0]))
CATE(TE,FAE("Matrix4x4::lookAtDir","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==4)
if(1&&TS(const Position3D &,a[1])&&TS(const Direction3D &,a[2])&&TS(const Direction3D &,a[3]))
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
if(!TS(Matrix4x4,a[0]))
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
if(!TS(Matrix4x4,a[0]))
CATE(TE,FAE("Matrix4x4::rotatez","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(Matrix4x4,a[0]))
CATE(TE,FAE("Matrix4x4::rotatex","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(Matrix4x4,a[0]))
CATE(TE,FAE("Matrix4x4::rotatey","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(Matrix4x4,a[0]))
CATE(TE,FAE("Matrix4x4::__div__","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
{
R CV(*F / val_to_c<float>::f(ctx,a[1]));
}
CATE(TE,UFOF("Matrix4x4::__div__.")));
R CN;
}

SV Matrix4x4_scale(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix4x4::scale" EAOE));
Matrix4x4*F;
if(!TS(Matrix4x4,a[0]))
CATE(TE,FAE("Matrix4x4::scale","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Float3 &,a[1]))
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
if(!TS(Matrix4x4,a[0]))
CATE(TE,FAE("Matrix4x4::lookAt","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==4)
if(1&&TS(const Position3D &,a[1])&&TS(const Position3D &,a[2])&&TS(const Direction3D &,a[3]))
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
if(!TS(Matrix4x4,a[0]))
CATE(TE,FAE("Matrix4x4::__mul__","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Matrix4x4 &,a[1]))
{
R CV(*F * val_to_c<const Matrix4x4 &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const Float4 &,a[1]))
{
R CV(*F * val_to_c<const Float4 &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Matrix4x4::__mul__.")));
R CN;
}

SV Matrix4x4_orthographic(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix4x4::orthographic" EAOE));
Matrix4x4*F;
if(!TS(Matrix4x4,a[0]))
CATE(TE,FAE("Matrix4x4::orthographic","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==7)
if(1&&TS(float,a[1])&&TS(float,a[2])&&TS(float,a[3])&&TS(float,a[4])&&TS(float,a[5])&&TS(float,a[6]))
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
if(!TS(Matrix4x4,a[0]))
CATE(TE,FAE("Matrix4x4::translate","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Float3 &,a[1]))
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
if(!TS(Matrix4x4,a[0]))
CATE(TE,FAE("Matrix4x4::__eq__","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Matrix4x4 &,a[1]))
{
R CV(*F == val_to_c<const Matrix4x4 &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Matrix4x4::__eq__.")));
R CN;
}

SV Matrix4x4_rotate(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix4x4::rotate" EAOE));
Matrix4x4*F;
if(!TS(Matrix4x4,a[0]))
CATE(TE,FAE("Matrix4x4::rotate","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(Matrix4x4,a[0]))
CATE(TE,FAE("Matrix4x4::perspective","Matrix4x4")));
else
 F=(Matrix4x4*)((NO)a[0])->data;

if(a.getCount()==5)
if(1&&TS(float,a[1])&&TS(float,a[2])&&TS(float,a[3])&&TS(float,a[4]))
{
R CV( F->perspective(val_to_c<float>::f(ctx,a[1]), val_to_c<float>::f(ctx,a[2]), val_to_c<float>::f(ctx,a[3]), val_to_c<float>::f(ctx,a[4])));
;
}
CATE(TE,UFOF("Matrix4x4::perspective.")));
R CN;
}

void UInt4_destroy(CTX ctx,NO F)
{
if(!TS(T4<uint32_t>, (SV)F))
CATE(TE,"UInt4::__del__ expects UInt4 as first argument."));

DELETE(T4<uint32_t>,(T4<uint32_t> *)F->data);
}SV UInt4_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4's constructor" EAOE));
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,"UInt4's constructor expects UInt4 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(UInt4_funcs,NEW(UInt4),EXT->UInt4_typeID);
if(a.getCount()==2)
if(true&&TS(float,a[1]))
R S::createNativeObject(UInt4_funcs,NEW(UInt4,val_to_c<float>::f(ctx,a[1])),EXT->UInt4_typeID);
if(a.getCount()==5)
if(true&&TS(float,a[1])&&TS(float,a[2])&&TS(float,a[3])&&TS(float,a[4]))
R S::createNativeObject(UInt4_funcs,NEW(UInt4,val_to_c<float>::f(ctx,a[1]),val_to_c<float>::f(ctx,a[2]),val_to_c<float>::f(ctx,a[3]),val_to_c<float>::f(ctx,a[4])),EXT->UInt4_typeID);
if(a.getCount()==2)
if(true&&TS(const T4<float> &,a[1]))
R S::createNativeObject(UInt4_funcs,NEW(UInt4,val_to_c<const T4<float> &>::f(ctx,a[1])),EXT->UInt4_typeID);
if(a.getCount()==2)
if(true&&TS(const T4<int32_t> &,a[1]))
R S::createNativeObject(UInt4_funcs,NEW(UInt4,val_to_c<const T4<int32_t> &>::f(ctx,a[1])),EXT->UInt4_typeID);
if(a.getCount()==2)
if(true&&TS(const T4<uint32_t> &,a[1]))
R S::createNativeObject(UInt4_funcs,NEW(UInt4,val_to_c<const T4<uint32_t> &>::f(ctx,a[1])),EXT->UInt4_typeID);
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setZXYW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setZXYW(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setWYZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setWYZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setWYX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setWYX(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::distanceSquared","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV( F->distanceSquared(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setYZWX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setYZWX(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setXWYZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setXWYZ(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setZY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setZY(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setZX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setZX(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setZW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setZW(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setZYWX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setZYWX(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setYXZW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setYXZW(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setXWZY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setXWZY(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setWZYX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setWZYX(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setZYW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setZYW(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setZYX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setZYX(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setXZYW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setXZYW(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setYZW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setYZW(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::__leq__","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F <= val_to_c<const T4<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt4::__leq__.")));
R CN;
}

SV UInt4_getYWX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getYWX" EAOE));
T4<uint32_t>*F;
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setYZX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setYZX(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setYWZX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setYWZX(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setWXY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setWXY(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setWXZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setWXZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setZXW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setZXW(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setWYXZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setWYXZ(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setZXY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setZXY(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setXYWZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setXYWZ(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setWXZY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setWXZY(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setXWZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setXWZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setXWY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setXWY(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setZWY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setZWY(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setZWX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setZWX(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setWX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setWX(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setWY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setWY(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setWZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setWZ(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setYXZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setYXZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setYXW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setYXW(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::__less__","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F < val_to_c<const T4<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt4::__less__.")));
R CN;
}

SV UInt4_getZYW(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getZYW" EAOE));
T4<uint32_t>*F;
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setWZY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setWZY(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setWZX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setWZX(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setZYXW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setZYXW(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setYXWZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setYXWZ(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::__eq__","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F == val_to_c<const T4<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt4::__eq__.")));
R CN;
}

SV UInt4_getWYXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getWYXZ" EAOE));
T4<uint32_t>*F;
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::distance","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV( F->distance(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setYZXW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setYZXW(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setZWYX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setZWYX(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::__sub__","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F - val_to_c<const T4<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F - val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt4::__sub__.")));
R CN;
}

SV UInt4_getYXWZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getYXWZ" EAOE));
T4<uint32_t>*F;
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setXZWY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setXZWY(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setYWZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setYWZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setYWX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setYWX(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setYZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setYZ(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setYX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setYX(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setYW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setYW(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::__neq__","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F != val_to_c<const T4<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt4::__neq__.")));
R CN;
}

SV UInt4_normalize(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::normalize" EAOE));
T4<uint32_t>*F;
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setXZW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setXZW(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setXZY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setXZY(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setXYZW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setXYZW(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setWXYZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setWXYZ(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::__mul__","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F * val_to_c<const T4<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F * val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt4::__mul__.")));
R CN;
}

SV UInt4_getYZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::getYZ" EAOE));
T4<uint32_t>*F;
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setXY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setXY(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::__add__","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F + val_to_c<const T4<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F + val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt4::__add__.")));
R CN;
}

SV UInt4_setXZ(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setXZ" EAOE));
T4<uint32_t>*F;
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setXZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setXZ(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setXW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T2<float> &,a[1]))
{
( F->setXW(val_to_c<const T2<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setZXWY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setZXWY(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setXYW","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setXYW(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setWZXY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setWZXY(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::__grtr__","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F > val_to_c<const T4<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt4::__grtr__.")));
R CN;
}

SV UInt4_setZWXY(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setZWXY" EAOE));
T4<uint32_t>*F;
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setZWXY","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setZWXY(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setXYZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T3<float> &,a[1]))
{
( F->setXYZ(val_to_c<const T3<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::__div__","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F / val_to_c<const T4<float> &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const float&,a[1]))
{
R CV(*F / val_to_c<const float&>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt4::__div__.")));
R CN;
}

SV UInt4_setWYZX(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::setWYZX" EAOE));
T4<uint32_t>*F;
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setWYZX","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setWYZX(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::setYWXZ","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
( F->setYWXZ(val_to_c<const T4<float> &>::f(ctx,a[1])));
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
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::__geq__","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
{
R CV(*F >= val_to_c<const T4<float> &>::f(ctx,a[1]));
}
CATE(TE,UFOF("UInt4::__geq__.")));
R CN;
}

SV UInt4_dot(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"UInt4::dot" EAOE));
T4<uint32_t>*F;
if(!TS(T4<uint32_t>,a[0]))
CATE(TE,FAE("UInt4::dot","UInt4")));
else
 F=(T4<uint32_t>*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const T4<float> &,a[1]))
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
CATE(TE,UFOF("UInt4::dot.")));
R CN;
}

void AABB_destroy(CTX ctx,NO F)
{
if(!TS(AABB, (SV)F))
CATE(TE,"AABB::__del__ expects AABB as first argument."));

DELETE(AABB,(AABB *)F->data);
}SV AABB_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"AABB's constructor" EAOE));
if(!TS(AABB,a[0]))
CATE(TE,"AABB's constructor expects AABB as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(AABB_funcs,NEW(AABB),EXT->AABB_typeID);
if(a.getCount()==3)
if(true&&TS(const Position3D &,a[1])&&TS(const Position3D &,a[2]))
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
if(!TS(AABB,a[0]))
CATE(TE,FAE("AABB::transform","AABB")));
else
 F=(AABB*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Matrix4x4 &,a[1]))
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
if(!TS(AABB,a[0]))
CATE(TE,FAE("AABB::extend","AABB")));
else
 F=(AABB*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Position3D &,a[1]))
{
( F->extend(val_to_c<const Position3D &>::f(ctx,a[1])));
R CN;
}
if(a.getCount()==2)
if(1&&TS(const AABB &,a[1]))
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
if(!TS(AABB,a[0]))
CATE(TE,FAE("AABB::grow","AABB")));
else
 F=(AABB*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Vector3D &,a[1]))
{
( F->grow(val_to_c<const Vector3D &>::f(ctx,a[1])));
R CN;
}
CATE(TE,UFOF("AABB::grow.")));
R CN;
}

void Matrix3x3_destroy(CTX ctx,NO F)
{
if(!TS(Matrix3x3, (SV)F))
CATE(TE,"Matrix3x3::__del__ expects Matrix3x3 as first argument."));

DELETE(Matrix3x3,(Matrix3x3 *)F->data);
}SV Matrix3x3_new(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix3x3's constructor" EAOE));
if(!TS(Matrix3x3,a[0]))
CATE(TE,"Matrix3x3's constructor expects Matrix3x3 as first argument."));
if(a.getCount()==1)
if(true)
R S::createNativeObject(Matrix3x3_funcs,NEW(Matrix3x3),EXT->Matrix3x3_typeID);
if(a.getCount()==2)
if(true&&TS(const Matrix4x4 &,a[1]))
R S::createNativeObject(Matrix3x3_funcs,NEW(Matrix3x3,val_to_c<const Matrix4x4 &>::f(ctx,a[1])),EXT->Matrix3x3_typeID);
if(a.getCount()==4)
if(true&&TS(const Float3 &,a[1])&&TS(const Float3 &,a[2])&&TS(const Float3 &,a[3]))
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
if(!TS(Matrix3x3,a[0]))
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
if(!TS(Matrix3x3,a[0]))
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
if(!TS(Matrix3x3,a[0]))
CATE(TE,FAE("Matrix3x3::rotatez","Matrix3x3")));
else
 F=(Matrix3x3*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(Matrix3x3,a[0]))
CATE(TE,FAE("Matrix3x3::rotatex","Matrix3x3")));
else
 F=(Matrix3x3*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(Matrix3x3,a[0]))
CATE(TE,FAE("Matrix3x3::rotatey","Matrix3x3")));
else
 F=(Matrix3x3*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
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
if(!TS(Matrix3x3,a[0]))
CATE(TE,FAE("Matrix3x3::__div__","Matrix3x3")));
else
 F=(Matrix3x3*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
{
R CV(*F / val_to_c<float>::f(ctx,a[1]));
}
CATE(TE,UFOF("Matrix3x3::__div__.")));
R CN;
}

SV Matrix3x3_scale(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix3x3::scale" EAOE));
Matrix3x3*F;
if(!TS(Matrix3x3,a[0]))
CATE(TE,FAE("Matrix3x3::scale","Matrix3x3")));
else
 F=(Matrix3x3*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Float3 &,a[1]))
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
if(!TS(Matrix3x3,a[0]))
CATE(TE,FAE("Matrix3x3::__mul__","Matrix3x3")));
else
 F=(Matrix3x3*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Matrix3x3 &,a[1]))
{
R CV(*F * val_to_c<const Matrix3x3 &>::f(ctx,a[1]));
}
if(a.getCount()==2)
if(1&&TS(const Float3 &,a[1]))
{
R CV(*F * val_to_c<const Float3 &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Matrix3x3::__mul__.")));
R CN;
}

SV Matrix3x3_translate(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix3x3::translate" EAOE));
Matrix3x3*F;
if(!TS(Matrix3x3,a[0]))
CATE(TE,FAE("Matrix3x3::translate","Matrix3x3")));
else
 F=(Matrix3x3*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Float2 &,a[1]))
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
if(!TS(Matrix3x3,a[0]))
CATE(TE,FAE("Matrix3x3::__eq__","Matrix3x3")));
else
 F=(Matrix3x3*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(const Matrix3x3 &,a[1]))
{
R CV(*F == val_to_c<const Matrix3x3 &>::f(ctx,a[1]));
}
CATE(TE,UFOF("Matrix3x3::__eq__.")));
R CN;
}

SV Matrix3x3_rotate(CTX ctx,const List<SV>&a)
{
if(a.getCount()<1)
CATE(VE,"Matrix3x3::rotate" EAOE));
Matrix3x3*F;
if(!TS(Matrix3x3,a[0]))
CATE(TE,FAE("Matrix3x3::rotate","Matrix3x3")));
else
 F=(Matrix3x3*)((NO)a[0])->data;

if(a.getCount()==2)
if(1&&TS(float,a[1]))
{
R CV( F->rotate(val_to_c<float>::f(ctx,a[1])));
;
}
CATE(TE,UFOF("Matrix3x3::rotate.")));
R CN;
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
if(!TS(T3<uint32_t>*,(SV)F))
CATE(TE,"UInt3Ref::deref expects UInt3Ref as first argument."));
R CV(*(T3<uint32_t> *)((NO)F)->data);
}
SV UInt3_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"UInt3::refset expects two arguments."));
SV F=a[0];
if(!TS(T3<uint32_t>*,(SV)F))
CATE(TE,"UInt3Ref::refset expects UInt3Ref as first argument."));
*((T3<uint32_t> *)((NO)F)->data) = val_to_c<T3<uint32_t>>::f(ctx,a[1]);
R CN;
}

void UInt3_ptr_destroy(CTX ctx,NO F)
{
if(!TS(T3<uint32_t>*,(SV)F))
CATE(TE,"UInt3Ref::__del__ expects UInt3Ref as first argument."));
SCRIPT_DELETE(T3<uint32_t>, (T3<uint32_t> *)F->data);
}
SV UInt3_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS(T3<uint32_t>*,(SV)F))
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
if(!TS(T3<uint32_t>*,(SV)F))
CATE(TE,FAE("UInt3Ref's set method","UInt3Ref")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=UInt3_funcs;
obj.typeID=EXT->UInt3_typeID;
obj.refCount=1;
obj.data=F->data;
UInt3_set_member(ctx, &obj, key, value);
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
if(!TS(T2<uint32_t>*,(SV)F))
CATE(TE,"UInt2Ref::deref expects UInt2Ref as first argument."));
R CV(*(T2<uint32_t> *)((NO)F)->data);
}
SV UInt2_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"UInt2::refset expects two arguments."));
SV F=a[0];
if(!TS(T2<uint32_t>*,(SV)F))
CATE(TE,"UInt2Ref::refset expects UInt2Ref as first argument."));
*((T2<uint32_t> *)((NO)F)->data) = val_to_c<T2<uint32_t>>::f(ctx,a[1]);
R CN;
}

void UInt2_ptr_destroy(CTX ctx,NO F)
{
if(!TS(T2<uint32_t>*,(SV)F))
CATE(TE,"UInt2Ref::__del__ expects UInt2Ref as first argument."));
SCRIPT_DELETE(T2<uint32_t>, (T2<uint32_t> *)F->data);
}
SV UInt2_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS(T2<uint32_t>*,(SV)F))
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
if(!TS(T2<uint32_t>*,(SV)F))
CATE(TE,FAE("UInt2Ref's set method","UInt2Ref")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=UInt2_funcs;
obj.typeID=EXT->UInt2_typeID;
obj.refCount=1;
obj.data=F->data;
UInt2_set_member(ctx, &obj, key, value);
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
if(!TS(RigidBody*,(SV)F))
CATE(TE,"RigidBodyRef::deref expects RigidBodyRef as first argument."));
CATE(TE,"RigidBody objects are not copyable."));
}
SV RigidBody_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"RigidBody::refset expects two arguments."));
SV F=a[0];
if(!TS(RigidBody*,(SV)F))
CATE(TE,"RigidBodyRef::refset expects RigidBodyRef as first argument."));
CATE(TE,"RigidBody objects are not copyable."));
R CN;
}

void RigidBody_ptr_destroy(CTX ctx,NO F)
{
if(!TS(RigidBody*,(SV)F))
CATE(TE,"RigidBodyRef::__del__ expects RigidBodyRef as first argument."));
}
SV RigidBody_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS(RigidBody*,(SV)F))
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
if(!TS(RigidBody*,(SV)F))
CATE(TE,FAE("RigidBodyRef's set method","RigidBodyRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=RigidBody_funcs;
obj.typeID=EXT->RigidBody_typeID;
obj.refCount=1;
obj.data=F->data;
RigidBody_set_member(ctx, &obj, key, value);
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
if(!TS(File*,(SV)F))
CATE(TE,"FileRef::deref expects FileRef as first argument."));
CATE(TE,"File objects are not copyable."));
}
SV File_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"File::refset expects two arguments."));
SV F=a[0];
if(!TS(File*,(SV)F))
CATE(TE,"FileRef::refset expects FileRef as first argument."));
CATE(TE,"File objects are not copyable."));
R CN;
}

void File_ptr_destroy(CTX ctx,NO F)
{
if(!TS(File*,(SV)F))
CATE(TE,"FileRef::__del__ expects FileRef as first argument."));
SCRIPT_DELETE(File, (File *)F->data);
}
SV File_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS(File*,(SV)F))
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
if(!TS(File*,(SV)F))
CATE(TE,FAE("FileRef's set method","FileRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=File_funcs;
obj.typeID=EXT->File_typeID;
obj.refCount=1;
obj.data=F->data;
File_set_member(ctx, &obj, key, value);
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
if(!TS(T3<int32_t>*,(SV)F))
CATE(TE,"Int3Ref::deref expects Int3Ref as first argument."));
R CV(*(T3<int32_t> *)((NO)F)->data);
}
SV Int3_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Int3::refset expects two arguments."));
SV F=a[0];
if(!TS(T3<int32_t>*,(SV)F))
CATE(TE,"Int3Ref::refset expects Int3Ref as first argument."));
*((T3<int32_t> *)((NO)F)->data) = val_to_c<T3<int32_t>>::f(ctx,a[1]);
R CN;
}

void Int3_ptr_destroy(CTX ctx,NO F)
{
if(!TS(T3<int32_t>*,(SV)F))
CATE(TE,"Int3Ref::__del__ expects Int3Ref as first argument."));
SCRIPT_DELETE(T3<int32_t>, (T3<int32_t> *)F->data);
}
SV Int3_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS(T3<int32_t>*,(SV)F))
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
if(!TS(T3<int32_t>*,(SV)F))
CATE(TE,FAE("Int3Ref's set method","Int3Ref")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Int3_funcs;
obj.typeID=EXT->Int3_typeID;
obj.refCount=1;
obj.data=F->data;
Int3_set_member(ctx, &obj, key, value);
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
if(!TS(Camera*,(SV)F))
CATE(TE,"CameraRef::deref expects CameraRef as first argument."));
R CV(*(Camera *)((NO)F)->data);
}
SV Camera_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Camera::refset expects two arguments."));
SV F=a[0];
if(!TS(Camera*,(SV)F))
CATE(TE,"CameraRef::refset expects CameraRef as first argument."));
*((Camera *)((NO)F)->data) = val_to_c<Camera>::f(ctx,a[1]);
R CN;
}

void Camera_ptr_destroy(CTX ctx,NO F)
{
if(!TS(Camera*,(SV)F))
CATE(TE,"CameraRef::__del__ expects CameraRef as first argument."));
SCRIPT_DELETE(Camera, (Camera *)F->data);
}
SV Camera_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS(Camera*,(SV)F))
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
if(!TS(Camera*,(SV)F))
CATE(TE,FAE("CameraRef's set method","CameraRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Camera_funcs;
obj.typeID=EXT->Camera_typeID;
obj.refCount=1;
obj.data=F->data;
Camera_set_member(ctx, &obj, key, value);
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
if(!TS(T2<float>*,(SV)F))
CATE(TE,"Float2Ref::deref expects Float2Ref as first argument."));
R CV(*(T2<float> *)((NO)F)->data);
}
SV Float2_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Float2::refset expects two arguments."));
SV F=a[0];
if(!TS(T2<float>*,(SV)F))
CATE(TE,"Float2Ref::refset expects Float2Ref as first argument."));
*((T2<float> *)((NO)F)->data) = val_to_c<T2<float>>::f(ctx,a[1]);
R CN;
}

void Float2_ptr_destroy(CTX ctx,NO F)
{
if(!TS(T2<float>*,(SV)F))
CATE(TE,"Float2Ref::__del__ expects Float2Ref as first argument."));
SCRIPT_DELETE(T2<float>, (T2<float> *)F->data);
}
SV Float2_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS(T2<float>*,(SV)F))
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
if(!TS(T2<float>*,(SV)F))
CATE(TE,FAE("Float2Ref's set method","Float2Ref")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Float2_funcs;
obj.typeID=EXT->Float2_typeID;
obj.refCount=1;
obj.data=F->data;
Float2_set_member(ctx, &obj, key, value);
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
if(!TS(T4<int32_t>*,(SV)F))
CATE(TE,"Int4Ref::deref expects Int4Ref as first argument."));
R CV(*(T4<int32_t> *)((NO)F)->data);
}
SV Int4_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Int4::refset expects two arguments."));
SV F=a[0];
if(!TS(T4<int32_t>*,(SV)F))
CATE(TE,"Int4Ref::refset expects Int4Ref as first argument."));
*((T4<int32_t> *)((NO)F)->data) = val_to_c<T4<int32_t>>::f(ctx,a[1]);
R CN;
}

void Int4_ptr_destroy(CTX ctx,NO F)
{
if(!TS(T4<int32_t>*,(SV)F))
CATE(TE,"Int4Ref::__del__ expects Int4Ref as first argument."));
SCRIPT_DELETE(T4<int32_t>, (T4<int32_t> *)F->data);
}
SV Int4_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS(T4<int32_t>*,(SV)F))
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
if(!TS(T4<int32_t>*,(SV)F))
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
if(!TS(T3<float>*,(SV)F))
CATE(TE,"Float3Ref::deref expects Float3Ref as first argument."));
R CV(*(T3<float> *)((NO)F)->data);
}
SV Float3_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Float3::refset expects two arguments."));
SV F=a[0];
if(!TS(T3<float>*,(SV)F))
CATE(TE,"Float3Ref::refset expects Float3Ref as first argument."));
*((T3<float> *)((NO)F)->data) = val_to_c<T3<float>>::f(ctx,a[1]);
R CN;
}

void Float3_ptr_destroy(CTX ctx,NO F)
{
if(!TS(T3<float>*,(SV)F))
CATE(TE,"Float3Ref::__del__ expects Float3Ref as first argument."));
SCRIPT_DELETE(T3<float>, (T3<float> *)F->data);
}
SV Float3_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS(T3<float>*,(SV)F))
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
if(!TS(T3<float>*,(SV)F))
CATE(TE,FAE("Float3Ref's set method","Float3Ref")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Float3_funcs;
obj.typeID=EXT->Float3_typeID;
obj.refCount=1;
obj.data=F->data;
Float3_set_member(ctx, &obj, key, value);
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
if(!TS(Transform*,(SV)F))
CATE(TE,"TransformRef::deref expects TransformRef as first argument."));
R CV(*(Transform *)((NO)F)->data);
}
SV Transform_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Transform::refset expects two arguments."));
SV F=a[0];
if(!TS(Transform*,(SV)F))
CATE(TE,"TransformRef::refset expects TransformRef as first argument."));
*((Transform *)((NO)F)->data) = val_to_c<Transform>::f(ctx,a[1]);
R CN;
}

void Transform_ptr_destroy(CTX ctx,NO F)
{
if(!TS(Transform*,(SV)F))
CATE(TE,"TransformRef::__del__ expects TransformRef as first argument."));
SCRIPT_DELETE(Transform, (Transform *)F->data);
}
SV Transform_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS(Transform*,(SV)F))
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
if(!TS(Transform*,(SV)F))
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
if(!TS(Quaternion*,(SV)F))
CATE(TE,"QuaternionRef::deref expects QuaternionRef as first argument."));
R CV(*(Quaternion *)((NO)F)->data);
}
SV Quaternion_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Quaternion::refset expects two arguments."));
SV F=a[0];
if(!TS(Quaternion*,(SV)F))
CATE(TE,"QuaternionRef::refset expects QuaternionRef as first argument."));
*((Quaternion *)((NO)F)->data) = val_to_c<Quaternion>::f(ctx,a[1]);
R CN;
}

void Quaternion_ptr_destroy(CTX ctx,NO F)
{
if(!TS(Quaternion*,(SV)F))
CATE(TE,"QuaternionRef::__del__ expects QuaternionRef as first argument."));
SCRIPT_DELETE(Quaternion, (Quaternion *)F->data);
}
SV Quaternion_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS(Quaternion*,(SV)F))
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
if(!TS(Quaternion*,(SV)F))
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
if(!TS(T2<int32_t>*,(SV)F))
CATE(TE,"Int2Ref::deref expects Int2Ref as first argument."));
R CV(*(T2<int32_t> *)((NO)F)->data);
}
SV Int2_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Int2::refset expects two arguments."));
SV F=a[0];
if(!TS(T2<int32_t>*,(SV)F))
CATE(TE,"Int2Ref::refset expects Int2Ref as first argument."));
*((T2<int32_t> *)((NO)F)->data) = val_to_c<T2<int32_t>>::f(ctx,a[1]);
R CN;
}

void Int2_ptr_destroy(CTX ctx,NO F)
{
if(!TS(T2<int32_t>*,(SV)F))
CATE(TE,"Int2Ref::__del__ expects Int2Ref as first argument."));
SCRIPT_DELETE(T2<int32_t>, (T2<int32_t> *)F->data);
}
SV Int2_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS(T2<int32_t>*,(SV)F))
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
if(!TS(T2<int32_t>*,(SV)F))
CATE(TE,FAE("Int2Ref's set method","Int2Ref")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Int2_funcs;
obj.typeID=EXT->Int2_typeID;
obj.refCount=1;
obj.data=F->data;
Int2_set_member(ctx, &obj, key, value);
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
if(!TS(T4<float>*,(SV)F))
CATE(TE,"Float4Ref::deref expects Float4Ref as first argument."));
R CV(*(T4<float> *)((NO)F)->data);
}
SV Float4_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Float4::refset expects two arguments."));
SV F=a[0];
if(!TS(T4<float>*,(SV)F))
CATE(TE,"Float4Ref::refset expects Float4Ref as first argument."));
*((T4<float> *)((NO)F)->data) = val_to_c<T4<float>>::f(ctx,a[1]);
R CN;
}

void Float4_ptr_destroy(CTX ctx,NO F)
{
if(!TS(T4<float>*,(SV)F))
CATE(TE,"Float4Ref::__del__ expects Float4Ref as first argument."));
SCRIPT_DELETE(T4<float>, (T4<float> *)F->data);
}
SV Float4_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS(T4<float>*,(SV)F))
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
if(!TS(T4<float>*,(SV)F))
CATE(TE,FAE("Float4Ref's set method","Float4Ref")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Float4_funcs;
obj.typeID=EXT->Float4_typeID;
obj.refCount=1;
obj.data=F->data;
Float4_set_member(ctx, &obj, key, value);
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
if(!TS(Matrix4x4*,(SV)F))
CATE(TE,"Matrix4x4Ref::deref expects Matrix4x4Ref as first argument."));
R CV(*(Matrix4x4 *)((NO)F)->data);
}
SV Matrix4x4_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Matrix4x4::refset expects two arguments."));
SV F=a[0];
if(!TS(Matrix4x4*,(SV)F))
CATE(TE,"Matrix4x4Ref::refset expects Matrix4x4Ref as first argument."));
*((Matrix4x4 *)((NO)F)->data) = val_to_c<Matrix4x4>::f(ctx,a[1]);
R CN;
}

void Matrix4x4_ptr_destroy(CTX ctx,NO F)
{
if(!TS(Matrix4x4*,(SV)F))
CATE(TE,"Matrix4x4Ref::__del__ expects Matrix4x4Ref as first argument."));
SCRIPT_DELETE(Matrix4x4, (Matrix4x4 *)F->data);
}
SV Matrix4x4_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS(Matrix4x4*,(SV)F))
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
if(!TS(Matrix4x4*,(SV)F))
CATE(TE,FAE("Matrix4x4Ref's set method","Matrix4x4Ref")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Matrix4x4_funcs;
obj.typeID=EXT->Matrix4x4_typeID;
obj.refCount=1;
obj.data=F->data;
Matrix4x4_set_member(ctx, &obj, key, value);
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
if(!TS(T4<uint32_t>*,(SV)F))
CATE(TE,"UInt4Ref::deref expects UInt4Ref as first argument."));
R CV(*(T4<uint32_t> *)((NO)F)->data);
}
SV UInt4_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"UInt4::refset expects two arguments."));
SV F=a[0];
if(!TS(T4<uint32_t>*,(SV)F))
CATE(TE,"UInt4Ref::refset expects UInt4Ref as first argument."));
*((T4<uint32_t> *)((NO)F)->data) = val_to_c<T4<uint32_t>>::f(ctx,a[1]);
R CN;
}

void UInt4_ptr_destroy(CTX ctx,NO F)
{
if(!TS(T4<uint32_t>*,(SV)F))
CATE(TE,"UInt4Ref::__del__ expects UInt4Ref as first argument."));
SCRIPT_DELETE(T4<uint32_t>, (T4<uint32_t> *)F->data);
}
SV UInt4_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS(T4<uint32_t>*,(SV)F))
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
if(!TS(T4<uint32_t>*,(SV)F))
CATE(TE,FAE("UInt4Ref's set method","UInt4Ref")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=UInt4_funcs;
obj.typeID=EXT->UInt4_typeID;
obj.refCount=1;
obj.data=F->data;
UInt4_set_member(ctx, &obj, key, value);
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
if(!TS(AABB*,(SV)F))
CATE(TE,"AABBRef::deref expects AABBRef as first argument."));
R CV(*(AABB *)((NO)F)->data);
}
SV AABB_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"AABB::refset expects two arguments."));
SV F=a[0];
if(!TS(AABB*,(SV)F))
CATE(TE,"AABBRef::refset expects AABBRef as first argument."));
*((AABB *)((NO)F)->data) = val_to_c<AABB>::f(ctx,a[1]);
R CN;
}

void AABB_ptr_destroy(CTX ctx,NO F)
{
if(!TS(AABB*,(SV)F))
CATE(TE,"AABBRef::__del__ expects AABBRef as first argument."));
SCRIPT_DELETE(AABB, (AABB *)F->data);
}
SV AABB_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS(AABB*,(SV)F))
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
if(!TS(AABB*,(SV)F))
CATE(TE,FAE("AABBRef's set method","AABBRef")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=AABB_funcs;
obj.typeID=EXT->AABB_typeID;
obj.refCount=1;
obj.data=F->data;
AABB_set_member(ctx, &obj, key, value);
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
if(!TS(Matrix3x3*,(SV)F))
CATE(TE,"Matrix3x3Ref::deref expects Matrix3x3Ref as first argument."));
R CV(*(Matrix3x3 *)((NO)F)->data);
}
SV Matrix3x3_ptr_set(CTX ctx,const List<SV>&a)
{
if(a.getCount()!=2)
CATE(VE,"Matrix3x3::refset expects two arguments."));
SV F=a[0];
if(!TS(Matrix3x3*,(SV)F))
CATE(TE,"Matrix3x3Ref::refset expects Matrix3x3Ref as first argument."));
*((Matrix3x3 *)((NO)F)->data) = val_to_c<Matrix3x3>::f(ctx,a[1]);
R CN;
}

void Matrix3x3_ptr_destroy(CTX ctx,NO F)
{
if(!TS(Matrix3x3*,(SV)F))
CATE(TE,"Matrix3x3Ref::__del__ expects Matrix3x3Ref as first argument."));
SCRIPT_DELETE(Matrix3x3, (Matrix3x3 *)F->data);
}
SV Matrix3x3_ptr_get_member(CTX ctx,NO F,SV key)
{
if(!TS(Matrix3x3*,(SV)F))
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
if(!TS(Matrix3x3*,(SV)F))
CATE(TE,FAE("Matrix3x3Ref's set method","Matrix3x3Ref")));
S::NativeObject obj;
obj.head.type=S::ValueType::NativeObject;
obj.funcs=Matrix3x3_funcs;
obj.typeID=EXT->Matrix3x3_typeID;
obj.refCount=1;
obj.data=F->data;
Matrix3x3_set_member(ctx, &obj, key, value);
}
void *initBindings(scripting::Engine *engine, void *data)
{
    BindingsExt *ext = NEW(BindingsExt);

    int64_t typeID;
    
    typeID = engine->createNewTypeID();
    ext->UInt3_typeID = typeID;
    ext->UInt3 = scripting::createNativeObject(UInt3_funcs, NULL, typeID);
    engine->getGlobalVars().set("UInt3", ext->UInt3);
    
    typeID = engine->createNewTypeID();
    ext->UInt3_ptr_typeID = typeID;
    ext->UInt3_ptr = scripting::createNativeObject(UInt3_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("UInt3Ref", ext->UInt3_ptr);
    
    typeID = engine->createNewTypeID();
    ext->UInt2_typeID = typeID;
    ext->UInt2 = scripting::createNativeObject(UInt2_funcs, NULL, typeID);
    engine->getGlobalVars().set("UInt2", ext->UInt2);
    
    typeID = engine->createNewTypeID();
    ext->UInt2_ptr_typeID = typeID;
    ext->UInt2_ptr = scripting::createNativeObject(UInt2_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("UInt2Ref", ext->UInt2_ptr);
    
    typeID = engine->createNewTypeID();
    ext->RigidBody_typeID = typeID;
    ext->RigidBody = scripting::createNativeObject(RigidBody_funcs, NULL, typeID);
    engine->getGlobalVars().set("RigidBody", ext->RigidBody);
    
    typeID = engine->createNewTypeID();
    ext->RigidBody_ptr_typeID = typeID;
    ext->RigidBody_ptr = scripting::createNativeObject(RigidBody_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("RigidBodyRef", ext->RigidBody_ptr);
    
    typeID = engine->createNewTypeID();
    ext->File_typeID = typeID;
    ext->File = scripting::createNativeObject(File_funcs, NULL, typeID);
    engine->getGlobalVars().set("File", ext->File);
    
    typeID = engine->createNewTypeID();
    ext->File_ptr_typeID = typeID;
    ext->File_ptr = scripting::createNativeObject(File_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("FileRef", ext->File_ptr);
    
    typeID = engine->createNewTypeID();
    ext->Int3_typeID = typeID;
    ext->Int3 = scripting::createNativeObject(Int3_funcs, NULL, typeID);
    engine->getGlobalVars().set("Int3", ext->Int3);
    
    typeID = engine->createNewTypeID();
    ext->Int3_ptr_typeID = typeID;
    ext->Int3_ptr = scripting::createNativeObject(Int3_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("Int3Ref", ext->Int3_ptr);
    
    typeID = engine->createNewTypeID();
    ext->Camera_typeID = typeID;
    ext->Camera = scripting::createNativeObject(Camera_funcs, NULL, typeID);
    engine->getGlobalVars().set("Camera", ext->Camera);
    
    typeID = engine->createNewTypeID();
    ext->Camera_ptr_typeID = typeID;
    ext->Camera_ptr = scripting::createNativeObject(Camera_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("CameraRef", ext->Camera_ptr);
    
    typeID = engine->createNewTypeID();
    ext->Float2_typeID = typeID;
    ext->Float2 = scripting::createNativeObject(Float2_funcs, NULL, typeID);
    engine->getGlobalVars().set("Float2", ext->Float2);
    
    typeID = engine->createNewTypeID();
    ext->Float2_ptr_typeID = typeID;
    ext->Float2_ptr = scripting::createNativeObject(Float2_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("Float2Ref", ext->Float2_ptr);
    
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
    ext->Float4_typeID = typeID;
    ext->Float4 = scripting::createNativeObject(Float4_funcs, NULL, typeID);
    engine->getGlobalVars().set("Float4", ext->Float4);
    
    typeID = engine->createNewTypeID();
    ext->Float4_ptr_typeID = typeID;
    ext->Float4_ptr = scripting::createNativeObject(Float4_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("Float4Ref", ext->Float4_ptr);
    
    typeID = engine->createNewTypeID();
    ext->Matrix4x4_typeID = typeID;
    ext->Matrix4x4 = scripting::createNativeObject(Matrix4x4_funcs, NULL, typeID);
    engine->getGlobalVars().set("Matrix4x4", ext->Matrix4x4);
    
    typeID = engine->createNewTypeID();
    ext->Matrix4x4_ptr_typeID = typeID;
    ext->Matrix4x4_ptr = scripting::createNativeObject(Matrix4x4_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("Matrix4x4Ref", ext->Matrix4x4_ptr);
    
    typeID = engine->createNewTypeID();
    ext->UInt4_typeID = typeID;
    ext->UInt4 = scripting::createNativeObject(UInt4_funcs, NULL, typeID);
    engine->getGlobalVars().set("UInt4", ext->UInt4);
    
    typeID = engine->createNewTypeID();
    ext->UInt4_ptr_typeID = typeID;
    ext->UInt4_ptr = scripting::createNativeObject(UInt4_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("UInt4Ref", ext->UInt4_ptr);
    
    typeID = engine->createNewTypeID();
    ext->AABB_typeID = typeID;
    ext->AABB = scripting::createNativeObject(AABB_funcs, NULL, typeID);
    engine->getGlobalVars().set("AABB", ext->AABB);
    
    typeID = engine->createNewTypeID();
    ext->AABB_ptr_typeID = typeID;
    ext->AABB_ptr = scripting::createNativeObject(AABB_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("AABBRef", ext->AABB_ptr);
    
    typeID = engine->createNewTypeID();
    ext->Matrix3x3_typeID = typeID;
    ext->Matrix3x3 = scripting::createNativeObject(Matrix3x3_funcs, NULL, typeID);
    engine->getGlobalVars().set("Matrix3x3", ext->Matrix3x3);
    
    typeID = engine->createNewTypeID();
    ext->Matrix3x3_ptr_typeID = typeID;
    ext->Matrix3x3_ptr = scripting::createNativeObject(Matrix3x3_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("Matrix3x3Ref", ext->Matrix3x3_ptr);
    
    typeID = engine->createNewTypeID();
    ext->GfxPrimitive_typeID = typeID;
    ext->GfxPrimitive = scripting::createNativeObject(GfxPrimitive_funcs, NULL, typeID);
    engine->getGlobalVars().set("GfxPrimitive", ext->GfxPrimitive);
    
    return ext;
}

void deinitBindings(scripting::Engine *engine, void *data)
{
    DELETE(BindingsExt, (BindingsExt *)data);
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

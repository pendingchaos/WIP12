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

struct BindingsExt
{
    int64_t UInt3_typeID, UInt3_ptr_typeID, UInt2_typeID, UInt2_ptr_typeID, RigidBody_typeID, RigidBody_ptr_typeID, Int3_typeID, Int3_ptr_typeID, Float2_typeID, Float2_ptr_typeID, Int4_typeID, Int4_ptr_typeID, Float3_typeID, Float3_ptr_typeID, Int2_typeID, Int2_ptr_typeID, Float4_typeID, Float4_ptr_typeID, Matrix4x4_typeID, Matrix4x4_ptr_typeID, UInt4_typeID, UInt4_ptr_typeID, AABB_typeID, AABB_ptr_typeID, Matrix3x3_typeID, Matrix3x3_ptr_typeID;
    scripting::Value *UInt3, *UInt3_ptr, *UInt2, *UInt2_ptr, *RigidBody, *RigidBody_ptr, *Int3, *Int3_ptr, *Float2, *Float2_ptr, *Int4, *Int4_ptr, *Float3, *Float3_ptr, *Int2, *Int2_ptr, *Float4, *Float4_ptr, *Matrix4x4, *Matrix4x4_ptr, *UInt4, *UInt4_ptr, *AABB, *AABB_ptr, *Matrix3x3, *Matrix3x3_ptr;
};


template <typename T>
struct val_to_c {};

#define VAL_TO_C_INT(T, T2, min, max) template <>struct val_to_c<T2>{    static T f(scripting::Context *ctx, const scripting::Value *head)    {        int64_t v;                if (head->type == scripting::ValueType::Int)        {            v = ((scripting::IntValue *)head)->value;        } else if (head->type == scripting::ValueType::Float)        {            v = ((scripting::FloatValue *)head)->value;        } else        {            ctx->throwException(scripting::createException(scripting::ExcType::TypeError, "Value can not be converted to int."));        }                if (v < min or v > max)        {            ctx->throwException(scripting::createException(scripting::ExcType::TypeError, "Value out of bounds."));        }                return v;    }};

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
    static float f(scripting::Context *ctx, const scripting::Value *head)
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
            ctx->throwException(scripting::createException(scripting::ExcType::TypeError, "Value can not be converted to float."));
        }
        
        return v;
    }
};

template <>
struct val_to_c<double>
{
    static double f(scripting::Context *ctx, const scripting::Value *head)
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
            ctx->throwException(scripting::createException(scripting::ExcType::TypeError, "Value can not be converted to float."));
        }
        
        return v;
    }
};

template <>
struct val_to_c<bool>
{
    static bool f(scripting::Context *ctx, const scripting::Value *head)
    {
        if (head->type == scripting::ValueType::Boolean)
        {
            return ((scripting::BooleanValue *)head)->value;
        } else
        {
            ctx->throwException(scripting::createException(scripting::ExcType::TypeError, "Value can not be converted to bool."));
        }
    }
};

template <>
struct val_to_c<String>
{
    static String f(scripting::Context *ctx, const scripting::Value *head)
    {
        if (head->type == scripting::ValueType::StringType)
        {
            return ((scripting::StringValue *)head)->value;
        } else
        {
            ctx->throwException(scripting::createException(scripting::ExcType::TypeError, "Value can not be converted to string."));
        }
    }
};

template <>
struct val_to_c<scripting::Value *>
{
    static scripting::Value *f(scripting::Context *ctx, const scripting::Value *head)
    {
        return scripting::createCopy(ctx, head);
    }
};

template <>
struct val_to_c<const scripting::Value *>
{
    static scripting::Value *f(scripting::Context *ctx, const scripting::Value *head)
    {
        return scripting::createCopy(ctx, head);
    }
};

template <typename T>
struct val_to_c<const T&> {
    static T f(scripting::Context *ctx, const scripting::Value *head)
    {
        return val_to_c<T>::f(ctx, head);
    }
};

template <typename T>
struct create_val {};

#define CREATE_VAL(T, func) template <>struct create_val<T>{    static scripting::Value *f(scripting::Context *ctx, const T& v)    {        return scripting::func(v);    }};

template <>
struct create_val<scripting::Value *>
{
    static scripting::Value *f(scripting::Context *ctx, const scripting::Value *head)
    {
        return scripting::createCopy(ctx, head);
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
    static bool f(scripting::Context *ctx, const scripting::Value *head)
    {
        return type_same<T>::f(ctx, head);
    }
};

template <>
struct type_same<scripting::Value *>
{
    static bool f(scripting::Context *ctx, const scripting::Value *head)
    {
        return true;
    }
};

#define TYPE_SAME_HELPER(T, enumValue) template <>struct type_same<T>{    static bool f(scripting::Context *ctx, const scripting::Value *head)    {        return head->type == scripting::ValueType::enumValue;    }};

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

template <typename T>
T *own(scripting::Context *ctx, scripting::Value *value)
{
    if (type_same<T *>::f(ctx, value))
    {
        void *ptr = ((scripting::NativeObject *)value)->data;
        AllocInfo i = getAllocInfo(ptr);
        i.cppRef = true;
        setAllocInfo(ptr, i);

        return (T *)ptr;
    }

    ctx->throwException(scripting::createException(scripting::ExcType::TypeError, "Argument's value can not be converted."));
}
scripting::Value *UInt3_copy(scripting::Context*, scripting::NativeObject*);
void UInt3_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *UInt3_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void UInt3_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs UInt3_funcs={
    .copy = UInt3_copy,
    .destroy = UInt3_destroy,
    .getMember = UInt3_get_member,
    .setMember = UInt3_set_member
};
template <>
struct create_val<T3<uint32_t>>
{
    static scripting::Value *f(scripting::Context*ctx,const T3<uint32_t>&obj)
    {
        return scripting::createNativeObject(UInt3_funcs,NEW(T3<uint32_t>, obj),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt3_typeID);
    }
};
template <>
struct val_to_c<T3<uint32_t>>
{
    static T3<uint32_t> f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt3_typeID)
                return *((T3<uint32_t>*)obj->data);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to UInt3."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to UInt3."));
    }
};
template <>
struct type_same<T3<uint32_t>>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->UInt3_typeID;
        else
             return false;
    }
};

scripting::Value *UInt3___add__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3___sub__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3___mul__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3___div__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3___eq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3___neq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3___less__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3___grtr__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3___leq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3___geq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_sum(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_length(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_lengthSquared(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_dot(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_distance(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_distanceSquared(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_normalize(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_cross(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_getXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_setXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_getXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_setXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_getYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_setYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_getYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_setYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_getZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_setZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_getZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_setZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_getXYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_setXYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_getXZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_setXZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_getYXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_setYXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_getYZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_setYZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_getZXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_setZXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_getZYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_setZYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt2_copy(scripting::Context*, scripting::NativeObject*);
void UInt2_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *UInt2_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void UInt2_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs UInt2_funcs={
    .copy = UInt2_copy,
    .destroy = UInt2_destroy,
    .getMember = UInt2_get_member,
    .setMember = UInt2_set_member
};
template <>
struct create_val<T2<uint32_t>>
{
    static scripting::Value *f(scripting::Context*ctx,const T2<uint32_t>&obj)
    {
        return scripting::createNativeObject(UInt2_funcs,NEW(T2<uint32_t>, obj),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt2_typeID);
    }
};
template <>
struct val_to_c<T2<uint32_t>>
{
    static T2<uint32_t> f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt2_typeID)
                return *((T2<uint32_t>*)obj->data);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to UInt2."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to UInt2."));
    }
};
template <>
struct type_same<T2<uint32_t>>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->UInt2_typeID;
        else
             return false;
    }
};

scripting::Value *UInt2___add__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt2___sub__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt2___mul__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt2___div__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt2___eq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt2___neq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt2___less__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt2___grtr__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt2___leq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt2___geq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt2_sum(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt2_length(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt2_lengthSquared(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt2_dot(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt2_distance(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt2_distanceSquared(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt2_normalize(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt2_getXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt2_setXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt2_getYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt2_setYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_copy(scripting::Context*, scripting::NativeObject*);
void RigidBody_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *RigidBody_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void RigidBody_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs RigidBody_funcs={
    .copy = RigidBody_copy,
    .destroy = RigidBody_destroy,
    .getMember = RigidBody_get_member,
    .setMember = RigidBody_set_member
};
template <>
struct create_val<RigidBody>
{
    static scripting::Value *f(scripting::Context*ctx,const RigidBody&obj)
    {
        return scripting::createNativeObject(RigidBody_funcs,NEW(RigidBody, obj),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->RigidBody_typeID);
    }
};
template <>
struct type_same<RigidBody>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->RigidBody_typeID;
        else
             return false;
    }
};

scripting::Value *RigidBody_getBulletRigidBody(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_getType(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_getGravity(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_setGravity(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_setLinearDamping(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_getLinearDamping(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_setAngularDamping(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_getAngularDamping(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_setMass(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_getMass(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_getLinearSleepingThreshold(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_setLinearSleepingThreshold(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_getAngularSleepingThreshold(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_setAngularSleepingThreshold(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_applyTorque(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_applyForce(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_applyCentralImpulse(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_applyTorqueImpulse(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_applyImpulse(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_clearForces(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_getLinearVelocity(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_setLinearVelocity(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_getAngularVelocity(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_setAngularVelocity(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_getVelocityOfPoint(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_getRestitution(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_setRestitution(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_getFriction(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_setFriction(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_getRollingFriction(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_setRollingFriction(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_getLinearFactor(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_setLinearFactor(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_getAngularFactor(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_setAngularFactor(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_setTransform(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_getWorld(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_getCollisionMask(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_setShape(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_getShape(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *RigidBody_getEntity(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_copy(scripting::Context*, scripting::NativeObject*);
void Int3_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *Int3_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void Int3_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs Int3_funcs={
    .copy = Int3_copy,
    .destroy = Int3_destroy,
    .getMember = Int3_get_member,
    .setMember = Int3_set_member
};
template <>
struct create_val<T3<int32_t>>
{
    static scripting::Value *f(scripting::Context*ctx,const T3<int32_t>&obj)
    {
        return scripting::createNativeObject(Int3_funcs,NEW(T3<int32_t>, obj),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int3_typeID);
    }
};
template <>
struct val_to_c<T3<int32_t>>
{
    static T3<int32_t> f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int3_typeID)
                return *((T3<int32_t>*)obj->data);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to Int3."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to Int3."));
    }
};
template <>
struct type_same<T3<int32_t>>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->Int3_typeID;
        else
             return false;
    }
};

scripting::Value *Int3___add__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3___sub__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3___mul__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3___div__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3___eq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3___neq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3___less__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3___grtr__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3___leq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3___geq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_sum(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_length(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_lengthSquared(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_dot(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_distance(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_distanceSquared(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_normalize(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_cross(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_getXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_setXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_getXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_setXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_getYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_setYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_getYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_setYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_getZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_setZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_getZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_setZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_getXYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_setXYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_getXZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_setXZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_getYXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_setYXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_getYZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_setYZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_getZXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_setZXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_getZYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int3_setZYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float2_copy(scripting::Context*, scripting::NativeObject*);
void Float2_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *Float2_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void Float2_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs Float2_funcs={
    .copy = Float2_copy,
    .destroy = Float2_destroy,
    .getMember = Float2_get_member,
    .setMember = Float2_set_member
};
template <>
struct create_val<T2<float>>
{
    static scripting::Value *f(scripting::Context*ctx,const T2<float>&obj)
    {
        return scripting::createNativeObject(Float2_funcs,NEW(T2<float>, obj),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float2_typeID);
    }
};
template <>
struct val_to_c<T2<float>>
{
    static T2<float> f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float2_typeID)
                return *((T2<float>*)obj->data);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to Float2."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to Float2."));
    }
};
template <>
struct type_same<T2<float>>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->Float2_typeID;
        else
             return false;
    }
};

scripting::Value *Float2___add__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float2___sub__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float2___mul__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float2___div__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float2___eq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float2___neq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float2___less__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float2___grtr__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float2___leq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float2___geq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float2_sum(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float2_length(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float2_lengthSquared(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float2_dot(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float2_distance(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float2_distanceSquared(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float2_normalize(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float2_getXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float2_setXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float2_getYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float2_setYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_copy(scripting::Context*, scripting::NativeObject*);
void Int4_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *Int4_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void Int4_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs Int4_funcs={
    .copy = Int4_copy,
    .destroy = Int4_destroy,
    .getMember = Int4_get_member,
    .setMember = Int4_set_member
};
template <>
struct create_val<T4<int32_t>>
{
    static scripting::Value *f(scripting::Context*ctx,const T4<int32_t>&obj)
    {
        return scripting::createNativeObject(Int4_funcs,NEW(T4<int32_t>, obj),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int4_typeID);
    }
};
template <>
struct val_to_c<T4<int32_t>>
{
    static T4<int32_t> f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int4_typeID)
                return *((T4<int32_t>*)obj->data);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to Int4."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to Int4."));
    }
};
template <>
struct type_same<T4<int32_t>>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->Int4_typeID;
        else
             return false;
    }
};

scripting::Value *Int4___add__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4___sub__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4___mul__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4___div__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4___eq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4___neq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4___less__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4___grtr__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4___leq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4___geq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_sum(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_length(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_lengthSquared(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_dot(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_distance(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_distanceSquared(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_normalize(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getXYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setXYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getXYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setXYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getXZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setXZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getXZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setXZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getXWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setXWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getXWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setXWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getYXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setYXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getYXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setYXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getYZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setYZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getYZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setYZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getYWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setYWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getYWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setYWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getZXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setZXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getZXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setZXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getZYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setZYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getZYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setZYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getZWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setZWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getZWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setZWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getWXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setWXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getWXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setWXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getWYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setWYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getWYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setWYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getWZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setWZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getWZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setWZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getXYZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setXYZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getXYWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setXYWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getXZYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setXZYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getXZWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setXZWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getXWZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setXWZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getXWYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setXWYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getYXZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setYXZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getYXWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setYXWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getYZXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setYZXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getYZWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setYZWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getYWZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setYWZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getYWXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setYWXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getZYXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setZYXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getZYWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setZYWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getZXYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setZXYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getZXWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setZXWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getZWXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setZWXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getZWYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setZWYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getWYZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setWYZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getWYXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setWYXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getWZYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setWZYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getWZXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setWZXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getWXZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setWXZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_getWXYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int4_setWXYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_copy(scripting::Context*, scripting::NativeObject*);
void Float3_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *Float3_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void Float3_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs Float3_funcs={
    .copy = Float3_copy,
    .destroy = Float3_destroy,
    .getMember = Float3_get_member,
    .setMember = Float3_set_member
};
template <>
struct create_val<T3<float>>
{
    static scripting::Value *f(scripting::Context*ctx,const T3<float>&obj)
    {
        return scripting::createNativeObject(Float3_funcs,NEW(T3<float>, obj),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float3_typeID);
    }
};
template <>
struct val_to_c<T3<float>>
{
    static T3<float> f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float3_typeID)
                return *((T3<float>*)obj->data);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to Float3."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to Float3."));
    }
};
template <>
struct type_same<T3<float>>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->Float3_typeID;
        else
             return false;
    }
};

scripting::Value *Float3___add__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3___sub__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3___mul__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3___div__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3___eq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3___neq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3___less__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3___grtr__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3___leq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3___geq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_sum(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_length(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_lengthSquared(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_dot(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_distance(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_distanceSquared(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_normalize(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_cross(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_getXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_setXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_getXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_setXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_getYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_setYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_getYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_setYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_getZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_setZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_getZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_setZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_getXYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_setXYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_getXZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_setXZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_getYXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_setYXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_getYZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_setYZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_getZXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_setZXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_getZYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float3_setZYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int2_copy(scripting::Context*, scripting::NativeObject*);
void Int2_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *Int2_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void Int2_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs Int2_funcs={
    .copy = Int2_copy,
    .destroy = Int2_destroy,
    .getMember = Int2_get_member,
    .setMember = Int2_set_member
};
template <>
struct create_val<T2<int32_t>>
{
    static scripting::Value *f(scripting::Context*ctx,const T2<int32_t>&obj)
    {
        return scripting::createNativeObject(Int2_funcs,NEW(T2<int32_t>, obj),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int2_typeID);
    }
};
template <>
struct val_to_c<T2<int32_t>>
{
    static T2<int32_t> f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int2_typeID)
                return *((T2<int32_t>*)obj->data);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to Int2."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to Int2."));
    }
};
template <>
struct type_same<T2<int32_t>>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->Int2_typeID;
        else
             return false;
    }
};

scripting::Value *Int2___add__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int2___sub__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int2___mul__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int2___div__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int2___eq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int2___neq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int2___less__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int2___grtr__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int2___leq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int2___geq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int2_sum(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int2_length(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int2_lengthSquared(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int2_dot(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int2_distance(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int2_distanceSquared(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int2_normalize(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int2_getXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int2_setXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int2_getYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Int2_setYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_copy(scripting::Context*, scripting::NativeObject*);
void Float4_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *Float4_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void Float4_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs Float4_funcs={
    .copy = Float4_copy,
    .destroy = Float4_destroy,
    .getMember = Float4_get_member,
    .setMember = Float4_set_member
};
template <>
struct create_val<T4<float>>
{
    static scripting::Value *f(scripting::Context*ctx,const T4<float>&obj)
    {
        return scripting::createNativeObject(Float4_funcs,NEW(T4<float>, obj),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float4_typeID);
    }
};
template <>
struct val_to_c<T4<float>>
{
    static T4<float> f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float4_typeID)
                return *((T4<float>*)obj->data);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to Float4."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to Float4."));
    }
};
template <>
struct type_same<T4<float>>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->Float4_typeID;
        else
             return false;
    }
};

scripting::Value *Float4___add__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4___sub__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4___mul__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4___div__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4___eq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4___neq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4___less__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4___grtr__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4___leq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4___geq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_sum(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_length(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_lengthSquared(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_dot(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_distance(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_distanceSquared(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_normalize(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getXYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setXYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getXYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setXYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getXZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setXZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getXZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setXZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getXWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setXWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getXWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setXWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getYXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setYXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getYXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setYXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getYZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setYZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getYZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setYZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getYWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setYWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getYWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setYWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getZXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setZXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getZXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setZXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getZYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setZYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getZYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setZYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getZWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setZWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getZWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setZWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getWXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setWXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getWXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setWXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getWYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setWYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getWYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setWYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getWZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setWZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getWZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setWZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getXYZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setXYZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getXYWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setXYWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getXZYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setXZYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getXZWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setXZWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getXWZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setXWZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getXWYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setXWYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getYXZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setYXZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getYXWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setYXWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getYZXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setYZXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getYZWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setYZWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getYWZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setYWZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getYWXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setYWXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getZYXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setZYXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getZYWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setZYWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getZXYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setZXYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getZXWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setZXWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getZWXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setZWXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getZWYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setZWYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getWYZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setWYZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getWYXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setWYXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getWZYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setWZYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getWZXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setWZXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getWXZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setWXZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_getWXYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Float4_setWXYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix4x4_copy(scripting::Context*, scripting::NativeObject*);
void Matrix4x4_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *Matrix4x4_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void Matrix4x4_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs Matrix4x4_funcs={
    .copy = Matrix4x4_copy,
    .destroy = Matrix4x4_destroy,
    .getMember = Matrix4x4_get_member,
    .setMember = Matrix4x4_set_member
};
template <>
struct create_val<Matrix4x4>
{
    static scripting::Value *f(scripting::Context*ctx,const Matrix4x4&obj)
    {
        return scripting::createNativeObject(Matrix4x4_funcs,NEW(Matrix4x4, obj),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix4x4_typeID);
    }
};
template <>
struct val_to_c<Matrix4x4>
{
    static Matrix4x4 f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix4x4_typeID)
                return *((Matrix4x4*)obj->data);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to Matrix4x4."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to Matrix4x4."));
    }
};
template <>
struct type_same<Matrix4x4>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->Matrix4x4_typeID;
        else
             return false;
    }
};

scripting::Value *Matrix4x4___mul__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix4x4___div__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix4x4___eq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix4x4_transpose(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix4x4_inverse(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix4x4_translate(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix4x4_scale(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix4x4_rotate(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix4x4_rotatex(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix4x4_rotatey(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix4x4_rotatez(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix4x4_perspective(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix4x4_orthographic(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix4x4_lookAt(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix4x4_lookAtDir(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_copy(scripting::Context*, scripting::NativeObject*);
void UInt4_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *UInt4_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void UInt4_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs UInt4_funcs={
    .copy = UInt4_copy,
    .destroy = UInt4_destroy,
    .getMember = UInt4_get_member,
    .setMember = UInt4_set_member
};
template <>
struct create_val<T4<uint32_t>>
{
    static scripting::Value *f(scripting::Context*ctx,const T4<uint32_t>&obj)
    {
        return scripting::createNativeObject(UInt4_funcs,NEW(T4<uint32_t>, obj),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt4_typeID);
    }
};
template <>
struct val_to_c<T4<uint32_t>>
{
    static T4<uint32_t> f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt4_typeID)
                return *((T4<uint32_t>*)obj->data);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to UInt4."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to UInt4."));
    }
};
template <>
struct type_same<T4<uint32_t>>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->UInt4_typeID;
        else
             return false;
    }
};

scripting::Value *UInt4___add__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4___sub__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4___mul__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4___div__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4___eq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4___neq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4___less__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4___grtr__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4___leq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4___geq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_sum(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_length(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_lengthSquared(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_dot(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_distance(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_distanceSquared(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_normalize(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getXYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setXYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getXYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setXYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getXZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setXZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getXZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setXZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getXWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setXWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getXWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setXWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getYXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setYXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getYXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setYXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getYZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setYZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getYZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setYZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getYWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setYWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getYWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setYWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getZXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setZXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getZXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setZXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getZYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setZYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getZYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setZYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getZWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setZWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getZWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setZWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getWXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setWXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getWXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setWXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getWYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setWYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getWYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setWYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getWZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setWZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getWZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setWZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getXYZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setXYZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getXYWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setXYWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getXZYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setXZYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getXZWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setXZWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getXWZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setXWZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getXWYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setXWYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getYXZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setYXZW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getYXWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setYXWZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getYZXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setYZXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getYZWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setYZWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getYWZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setYWZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getYWXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setYWXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getZYXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setZYXW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getZYWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setZYWX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getZXYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setZXYW(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getZXWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setZXWY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getZWXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setZWXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getZWYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setZWYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getWYZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setWYZX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getWYXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setWYXZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getWZYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setWZYX(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getWZXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setWZXY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getWXZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setWXZY(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_getWXYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt4_setWXYZ(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *AABB_copy(scripting::Context*, scripting::NativeObject*);
void AABB_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *AABB_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void AABB_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs AABB_funcs={
    .copy = AABB_copy,
    .destroy = AABB_destroy,
    .getMember = AABB_get_member,
    .setMember = AABB_set_member
};
template <>
struct create_val<AABB>
{
    static scripting::Value *f(scripting::Context*ctx,const AABB&obj)
    {
        return scripting::createNativeObject(AABB_funcs,NEW(AABB, obj),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->AABB_typeID);
    }
};
template <>
struct val_to_c<AABB>
{
    static AABB f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->AABB_typeID)
                return *((AABB*)obj->data);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to AABB."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to AABB."));
    }
};
template <>
struct type_same<AABB>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->AABB_typeID;
        else
             return false;
    }
};

scripting::Value *AABB_transform(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *AABB_extend(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *AABB_grow(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix3x3_copy(scripting::Context*, scripting::NativeObject*);
void Matrix3x3_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *Matrix3x3_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void Matrix3x3_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs Matrix3x3_funcs={
    .copy = Matrix3x3_copy,
    .destroy = Matrix3x3_destroy,
    .getMember = Matrix3x3_get_member,
    .setMember = Matrix3x3_set_member
};
template <>
struct create_val<Matrix3x3>
{
    static scripting::Value *f(scripting::Context*ctx,const Matrix3x3&obj)
    {
        return scripting::createNativeObject(Matrix3x3_funcs,NEW(Matrix3x3, obj),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix3x3_typeID);
    }
};
template <>
struct val_to_c<Matrix3x3>
{
    static Matrix3x3 f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix3x3_typeID)
                return *((Matrix3x3*)obj->data);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to Matrix3x3."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value can not be converted to Matrix3x3."));
    }
};
template <>
struct type_same<Matrix3x3>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->Matrix3x3_typeID;
        else
             return false;
    }
};

scripting::Value *Matrix3x3___mul__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix3x3___div__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix3x3___eq__(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix3x3_transpose(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix3x3_inverse(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix3x3_translate(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix3x3_scale(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix3x3_rotate(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix3x3_rotatex(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix3x3_rotatey(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *Matrix3x3_rotatez(scripting::Context *ctx, const List<scripting::Value *>& args);
scripting::Value *UInt3_ptr_copy(scripting::Context*, scripting::NativeObject*);
void UInt3_ptr_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *UInt3_ptr_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void UInt3_ptr_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs UInt3_ptr_funcs={
    .copy = UInt3_ptr_copy,
    .destroy = UInt3_ptr_destroy,
    .getMember = UInt3_ptr_get_member,
    .setMember = UInt3_ptr_set_member
};
template <>
struct create_val<T3<uint32_t> *>
{
    static scripting::Value *f(scripting::Context*ctx,T3<uint32_t>*obj)
    {
        AllocInfo i=getAllocInfo((void*)obj);
        i.cppRef = false;
        i.scriptRef = true;
        setAllocInfo((void *)obj, i);
        return scripting::createNativeObject(UInt3_ptr_funcs,obj,((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt3_ptr_typeID);
    }
};
template <>
struct val_to_c<T3<uint32_t> *>
{
    static T3<uint32_t> *f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt3_ptr_typeID)
                return (T3<uint32_t>*)obj->data;
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a UInt3Ref."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a UInt3Ref."));
    }
};
template <>
struct type_same<T3<uint32_t> *>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->UInt3_ptr_typeID;
        else
             return false;
    }
};

scripting::Value *UInt2_ptr_copy(scripting::Context*, scripting::NativeObject*);
void UInt2_ptr_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *UInt2_ptr_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void UInt2_ptr_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs UInt2_ptr_funcs={
    .copy = UInt2_ptr_copy,
    .destroy = UInt2_ptr_destroy,
    .getMember = UInt2_ptr_get_member,
    .setMember = UInt2_ptr_set_member
};
template <>
struct create_val<T2<uint32_t> *>
{
    static scripting::Value *f(scripting::Context*ctx,T2<uint32_t>*obj)
    {
        AllocInfo i=getAllocInfo((void*)obj);
        i.cppRef = false;
        i.scriptRef = true;
        setAllocInfo((void *)obj, i);
        return scripting::createNativeObject(UInt2_ptr_funcs,obj,((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt2_ptr_typeID);
    }
};
template <>
struct val_to_c<T2<uint32_t> *>
{
    static T2<uint32_t> *f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt2_ptr_typeID)
                return (T2<uint32_t>*)obj->data;
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a UInt2Ref."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a UInt2Ref."));
    }
};
template <>
struct type_same<T2<uint32_t> *>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->UInt2_ptr_typeID;
        else
             return false;
    }
};

scripting::Value *RigidBody_ptr_copy(scripting::Context*, scripting::NativeObject*);
void RigidBody_ptr_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *RigidBody_ptr_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void RigidBody_ptr_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs RigidBody_ptr_funcs={
    .copy = RigidBody_ptr_copy,
    .destroy = RigidBody_ptr_destroy,
    .getMember = RigidBody_ptr_get_member,
    .setMember = RigidBody_ptr_set_member
};
template <>
struct create_val<RigidBody *>
{
    static scripting::Value *f(scripting::Context*ctx,RigidBody*obj)
    {
        AllocInfo i=getAllocInfo((void*)obj);
        i.cppRef = false;
        i.scriptRef = true;
        setAllocInfo((void *)obj, i);
        return scripting::createNativeObject(RigidBody_ptr_funcs,obj,((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->RigidBody_ptr_typeID);
    }
};
template <>
struct val_to_c<RigidBody *>
{
    static RigidBody *f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->RigidBody_ptr_typeID)
                return (RigidBody*)obj->data;
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a RigidBodyRef."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a RigidBodyRef."));
    }
};
template <>
struct type_same<RigidBody *>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->RigidBody_ptr_typeID;
        else
             return false;
    }
};

scripting::Value *Int3_ptr_copy(scripting::Context*, scripting::NativeObject*);
void Int3_ptr_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *Int3_ptr_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void Int3_ptr_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs Int3_ptr_funcs={
    .copy = Int3_ptr_copy,
    .destroy = Int3_ptr_destroy,
    .getMember = Int3_ptr_get_member,
    .setMember = Int3_ptr_set_member
};
template <>
struct create_val<T3<int32_t> *>
{
    static scripting::Value *f(scripting::Context*ctx,T3<int32_t>*obj)
    {
        AllocInfo i=getAllocInfo((void*)obj);
        i.cppRef = false;
        i.scriptRef = true;
        setAllocInfo((void *)obj, i);
        return scripting::createNativeObject(Int3_ptr_funcs,obj,((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int3_ptr_typeID);
    }
};
template <>
struct val_to_c<T3<int32_t> *>
{
    static T3<int32_t> *f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int3_ptr_typeID)
                return (T3<int32_t>*)obj->data;
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a Int3Ref."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a Int3Ref."));
    }
};
template <>
struct type_same<T3<int32_t> *>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->Int3_ptr_typeID;
        else
             return false;
    }
};

scripting::Value *Float2_ptr_copy(scripting::Context*, scripting::NativeObject*);
void Float2_ptr_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *Float2_ptr_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void Float2_ptr_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs Float2_ptr_funcs={
    .copy = Float2_ptr_copy,
    .destroy = Float2_ptr_destroy,
    .getMember = Float2_ptr_get_member,
    .setMember = Float2_ptr_set_member
};
template <>
struct create_val<T2<float> *>
{
    static scripting::Value *f(scripting::Context*ctx,T2<float>*obj)
    {
        AllocInfo i=getAllocInfo((void*)obj);
        i.cppRef = false;
        i.scriptRef = true;
        setAllocInfo((void *)obj, i);
        return scripting::createNativeObject(Float2_ptr_funcs,obj,((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float2_ptr_typeID);
    }
};
template <>
struct val_to_c<T2<float> *>
{
    static T2<float> *f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float2_ptr_typeID)
                return (T2<float>*)obj->data;
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a Float2Ref."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a Float2Ref."));
    }
};
template <>
struct type_same<T2<float> *>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->Float2_ptr_typeID;
        else
             return false;
    }
};

scripting::Value *Int4_ptr_copy(scripting::Context*, scripting::NativeObject*);
void Int4_ptr_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *Int4_ptr_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void Int4_ptr_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs Int4_ptr_funcs={
    .copy = Int4_ptr_copy,
    .destroy = Int4_ptr_destroy,
    .getMember = Int4_ptr_get_member,
    .setMember = Int4_ptr_set_member
};
template <>
struct create_val<T4<int32_t> *>
{
    static scripting::Value *f(scripting::Context*ctx,T4<int32_t>*obj)
    {
        AllocInfo i=getAllocInfo((void*)obj);
        i.cppRef = false;
        i.scriptRef = true;
        setAllocInfo((void *)obj, i);
        return scripting::createNativeObject(Int4_ptr_funcs,obj,((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int4_ptr_typeID);
    }
};
template <>
struct val_to_c<T4<int32_t> *>
{
    static T4<int32_t> *f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int4_ptr_typeID)
                return (T4<int32_t>*)obj->data;
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a Int4Ref."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a Int4Ref."));
    }
};
template <>
struct type_same<T4<int32_t> *>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->Int4_ptr_typeID;
        else
             return false;
    }
};

scripting::Value *Float3_ptr_copy(scripting::Context*, scripting::NativeObject*);
void Float3_ptr_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *Float3_ptr_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void Float3_ptr_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs Float3_ptr_funcs={
    .copy = Float3_ptr_copy,
    .destroy = Float3_ptr_destroy,
    .getMember = Float3_ptr_get_member,
    .setMember = Float3_ptr_set_member
};
template <>
struct create_val<T3<float> *>
{
    static scripting::Value *f(scripting::Context*ctx,T3<float>*obj)
    {
        AllocInfo i=getAllocInfo((void*)obj);
        i.cppRef = false;
        i.scriptRef = true;
        setAllocInfo((void *)obj, i);
        return scripting::createNativeObject(Float3_ptr_funcs,obj,((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float3_ptr_typeID);
    }
};
template <>
struct val_to_c<T3<float> *>
{
    static T3<float> *f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float3_ptr_typeID)
                return (T3<float>*)obj->data;
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a Float3Ref."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a Float3Ref."));
    }
};
template <>
struct type_same<T3<float> *>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->Float3_ptr_typeID;
        else
             return false;
    }
};

scripting::Value *Int2_ptr_copy(scripting::Context*, scripting::NativeObject*);
void Int2_ptr_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *Int2_ptr_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void Int2_ptr_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs Int2_ptr_funcs={
    .copy = Int2_ptr_copy,
    .destroy = Int2_ptr_destroy,
    .getMember = Int2_ptr_get_member,
    .setMember = Int2_ptr_set_member
};
template <>
struct create_val<T2<int32_t> *>
{
    static scripting::Value *f(scripting::Context*ctx,T2<int32_t>*obj)
    {
        AllocInfo i=getAllocInfo((void*)obj);
        i.cppRef = false;
        i.scriptRef = true;
        setAllocInfo((void *)obj, i);
        return scripting::createNativeObject(Int2_ptr_funcs,obj,((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int2_ptr_typeID);
    }
};
template <>
struct val_to_c<T2<int32_t> *>
{
    static T2<int32_t> *f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int2_ptr_typeID)
                return (T2<int32_t>*)obj->data;
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a Int2Ref."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a Int2Ref."));
    }
};
template <>
struct type_same<T2<int32_t> *>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->Int2_ptr_typeID;
        else
             return false;
    }
};

scripting::Value *Float4_ptr_copy(scripting::Context*, scripting::NativeObject*);
void Float4_ptr_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *Float4_ptr_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void Float4_ptr_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs Float4_ptr_funcs={
    .copy = Float4_ptr_copy,
    .destroy = Float4_ptr_destroy,
    .getMember = Float4_ptr_get_member,
    .setMember = Float4_ptr_set_member
};
template <>
struct create_val<T4<float> *>
{
    static scripting::Value *f(scripting::Context*ctx,T4<float>*obj)
    {
        AllocInfo i=getAllocInfo((void*)obj);
        i.cppRef = false;
        i.scriptRef = true;
        setAllocInfo((void *)obj, i);
        return scripting::createNativeObject(Float4_ptr_funcs,obj,((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float4_ptr_typeID);
    }
};
template <>
struct val_to_c<T4<float> *>
{
    static T4<float> *f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float4_ptr_typeID)
                return (T4<float>*)obj->data;
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a Float4Ref."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a Float4Ref."));
    }
};
template <>
struct type_same<T4<float> *>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->Float4_ptr_typeID;
        else
             return false;
    }
};

scripting::Value *Matrix4x4_ptr_copy(scripting::Context*, scripting::NativeObject*);
void Matrix4x4_ptr_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *Matrix4x4_ptr_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void Matrix4x4_ptr_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs Matrix4x4_ptr_funcs={
    .copy = Matrix4x4_ptr_copy,
    .destroy = Matrix4x4_ptr_destroy,
    .getMember = Matrix4x4_ptr_get_member,
    .setMember = Matrix4x4_ptr_set_member
};
template <>
struct create_val<Matrix4x4 *>
{
    static scripting::Value *f(scripting::Context*ctx,Matrix4x4*obj)
    {
        AllocInfo i=getAllocInfo((void*)obj);
        i.cppRef = false;
        i.scriptRef = true;
        setAllocInfo((void *)obj, i);
        return scripting::createNativeObject(Matrix4x4_ptr_funcs,obj,((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix4x4_ptr_typeID);
    }
};
template <>
struct val_to_c<Matrix4x4 *>
{
    static Matrix4x4 *f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix4x4_ptr_typeID)
                return (Matrix4x4*)obj->data;
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a Matrix4x4Ref."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a Matrix4x4Ref."));
    }
};
template <>
struct type_same<Matrix4x4 *>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->Matrix4x4_ptr_typeID;
        else
             return false;
    }
};

scripting::Value *UInt4_ptr_copy(scripting::Context*, scripting::NativeObject*);
void UInt4_ptr_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *UInt4_ptr_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void UInt4_ptr_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs UInt4_ptr_funcs={
    .copy = UInt4_ptr_copy,
    .destroy = UInt4_ptr_destroy,
    .getMember = UInt4_ptr_get_member,
    .setMember = UInt4_ptr_set_member
};
template <>
struct create_val<T4<uint32_t> *>
{
    static scripting::Value *f(scripting::Context*ctx,T4<uint32_t>*obj)
    {
        AllocInfo i=getAllocInfo((void*)obj);
        i.cppRef = false;
        i.scriptRef = true;
        setAllocInfo((void *)obj, i);
        return scripting::createNativeObject(UInt4_ptr_funcs,obj,((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt4_ptr_typeID);
    }
};
template <>
struct val_to_c<T4<uint32_t> *>
{
    static T4<uint32_t> *f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt4_ptr_typeID)
                return (T4<uint32_t>*)obj->data;
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a UInt4Ref."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a UInt4Ref."));
    }
};
template <>
struct type_same<T4<uint32_t> *>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->UInt4_ptr_typeID;
        else
             return false;
    }
};

scripting::Value *AABB_ptr_copy(scripting::Context*, scripting::NativeObject*);
void AABB_ptr_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *AABB_ptr_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void AABB_ptr_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs AABB_ptr_funcs={
    .copy = AABB_ptr_copy,
    .destroy = AABB_ptr_destroy,
    .getMember = AABB_ptr_get_member,
    .setMember = AABB_ptr_set_member
};
template <>
struct create_val<AABB *>
{
    static scripting::Value *f(scripting::Context*ctx,AABB*obj)
    {
        AllocInfo i=getAllocInfo((void*)obj);
        i.cppRef = false;
        i.scriptRef = true;
        setAllocInfo((void *)obj, i);
        return scripting::createNativeObject(AABB_ptr_funcs,obj,((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->AABB_ptr_typeID);
    }
};
template <>
struct val_to_c<AABB *>
{
    static AABB *f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->AABB_ptr_typeID)
                return (AABB*)obj->data;
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a AABBRef."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a AABBRef."));
    }
};
template <>
struct type_same<AABB *>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->AABB_ptr_typeID;
        else
             return false;
    }
};

scripting::Value *Matrix3x3_ptr_copy(scripting::Context*, scripting::NativeObject*);
void Matrix3x3_ptr_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Value *Matrix3x3_ptr_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void Matrix3x3_ptr_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs Matrix3x3_ptr_funcs={
    .copy = Matrix3x3_ptr_copy,
    .destroy = Matrix3x3_ptr_destroy,
    .getMember = Matrix3x3_ptr_get_member,
    .setMember = Matrix3x3_ptr_set_member
};
template <>
struct create_val<Matrix3x3 *>
{
    static scripting::Value *f(scripting::Context*ctx,Matrix3x3*obj)
    {
        AllocInfo i=getAllocInfo((void*)obj);
        i.cppRef = false;
        i.scriptRef = true;
        setAllocInfo((void *)obj, i);
        return scripting::createNativeObject(Matrix3x3_ptr_funcs,obj,((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix3x3_ptr_typeID);
    }
};
template <>
struct val_to_c<Matrix3x3 *>
{
    static Matrix3x3 *f(scripting::Context*ctx,const scripting::Value*head)
    {
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix3x3_ptr_typeID)
                return (Matrix3x3*)obj->data;
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a Matrix3x3Ref."));
        } else
             ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Value is not a Matrix3x3Ref."));
    }
};
template <>
struct type_same<Matrix3x3 *>
{
    static bool f(scripting::Context *ctx,const scripting::Value *head)
    {
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->Matrix3x3_ptr_typeID;
        else
             return false;
    }
};

scripting::Value *UInt3_copy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(UInt3_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(UInt3_funcs,NEW(T3<uint32_t>,*((T3<uint32_t>*)self->data)),self->typeID);
}

void UInt3_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<T3<uint32_t>>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::__del__ expects UInt3 as first argument."));

    DELETE(T3<uint32_t>,(T3<uint32_t> *)self->data);
}scripting::Value *UInt3_new(scripting::Context*ctx,const List<scripting::Value *>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3's constructor expects at least one argument."));
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3's constructor expects UInt3 as first argument."));
    if(args.getCount()==1)
        if(true)
            return scripting::createNativeObject(UInt3_funcs,NEW(UInt3),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt3_typeID);
    if(args.getCount()==2)
        if(true&&type_same<float>::f(ctx,args[1]))
            return scripting::createNativeObject(UInt3_funcs,NEW(UInt3,val_to_c<float>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt3_typeID);
    if(args.getCount()==4)
        if(true&&type_same<float>::f(ctx,args[1])&&type_same<float>::f(ctx,args[2])&&type_same<float>::f(ctx,args[3]))
            return scripting::createNativeObject(UInt3_funcs,NEW(UInt3,val_to_c<float>::f(ctx,args[1]),val_to_c<float>::f(ctx,args[2]),val_to_c<float>::f(ctx,args[3])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt3_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T3<float> &>::f(ctx,args[1]))
            return scripting::createNativeObject(UInt3_funcs,NEW(UInt3,val_to_c<const T3<float> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt3_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T3<int32_t> &>::f(ctx,args[1]))
            return scripting::createNativeObject(UInt3_funcs,NEW(UInt3,val_to_c<const T3<int32_t> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt3_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T3<uint32_t> &>::f(ctx,args[1]))
            return scripting::createNativeObject(UInt3_funcs,NEW(UInt3,val_to_c<const T3<uint32_t> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt3_typeID);
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3's constructor."));
    return scripting::createNil();
}

scripting::Value *UInt3_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
            if(keyStr=="__typeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__name__")
                return scripting::createString("UInt3");
            else if(keyStr=="__new__")
                return scripting::createNativeFunction(UInt3_new);
            else if(keyStr=="__call__")
                return scripting::createNativeFunction(UInt3_new);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
            if(keyStr=="__classTypeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__init__")
                return scripting::createNativeFunction(UInt3_new);
             else if (keyStr == "__add__")
                return scripting::createNativeFunction(UInt3___add__);
             else if (keyStr == "__sub__")
                return scripting::createNativeFunction(UInt3___sub__);
             else if (keyStr == "__mul__")
                return scripting::createNativeFunction(UInt3___mul__);
             else if (keyStr == "__div__")
                return scripting::createNativeFunction(UInt3___div__);
             else if (keyStr == "__eq__")
                return scripting::createNativeFunction(UInt3___eq__);
             else if (keyStr == "__neq__")
                return scripting::createNativeFunction(UInt3___neq__);
             else if (keyStr == "__less__")
                return scripting::createNativeFunction(UInt3___less__);
             else if (keyStr == "__grtr__")
                return scripting::createNativeFunction(UInt3___grtr__);
             else if (keyStr == "__leq__")
                return scripting::createNativeFunction(UInt3___leq__);
             else if (keyStr == "__geq__")
                return scripting::createNativeFunction(UInt3___geq__);
             else if (keyStr == "sum")
                return scripting::createNativeFunction(UInt3_sum);
             else if (keyStr == "length")
                return scripting::createNativeFunction(UInt3_length);
             else if (keyStr == "lengthSquared")
                return scripting::createNativeFunction(UInt3_lengthSquared);
             else if (keyStr == "dot")
                return scripting::createNativeFunction(UInt3_dot);
             else if (keyStr == "distance")
                return scripting::createNativeFunction(UInt3_distance);
             else if (keyStr == "distanceSquared")
                return scripting::createNativeFunction(UInt3_distanceSquared);
             else if (keyStr == "normalize")
                return scripting::createNativeFunction(UInt3_normalize);
             else if (keyStr == "cross")
                return scripting::createNativeFunction(UInt3_cross);
             else if (keyStr == "getXY")
                return scripting::createNativeFunction(UInt3_getXY);
             else if (keyStr == "setXY")
                return scripting::createNativeFunction(UInt3_setXY);
             else if (keyStr == "getXZ")
                return scripting::createNativeFunction(UInt3_getXZ);
             else if (keyStr == "setXZ")
                return scripting::createNativeFunction(UInt3_setXZ);
             else if (keyStr == "getYX")
                return scripting::createNativeFunction(UInt3_getYX);
             else if (keyStr == "setYX")
                return scripting::createNativeFunction(UInt3_setYX);
             else if (keyStr == "getYZ")
                return scripting::createNativeFunction(UInt3_getYZ);
             else if (keyStr == "setYZ")
                return scripting::createNativeFunction(UInt3_setYZ);
             else if (keyStr == "getZX")
                return scripting::createNativeFunction(UInt3_getZX);
             else if (keyStr == "setZX")
                return scripting::createNativeFunction(UInt3_setZX);
             else if (keyStr == "getZY")
                return scripting::createNativeFunction(UInt3_getZY);
             else if (keyStr == "setZY")
                return scripting::createNativeFunction(UInt3_setZY);
             else if (keyStr == "getXYZ")
                return scripting::createNativeFunction(UInt3_getXYZ);
             else if (keyStr == "setXYZ")
                return scripting::createNativeFunction(UInt3_setXYZ);
             else if (keyStr == "getXZY")
                return scripting::createNativeFunction(UInt3_getXZY);
             else if (keyStr == "setXZY")
                return scripting::createNativeFunction(UInt3_setXZY);
             else if (keyStr == "getYXZ")
                return scripting::createNativeFunction(UInt3_getYXZ);
             else if (keyStr == "setYXZ")
                return scripting::createNativeFunction(UInt3_setYXZ);
             else if (keyStr == "getYZX")
                return scripting::createNativeFunction(UInt3_getYZX);
             else if (keyStr == "setYZX")
                return scripting::createNativeFunction(UInt3_setYZX);
             else if (keyStr == "getZXY")
                return scripting::createNativeFunction(UInt3_getZXY);
             else if (keyStr == "setZXY")
                return scripting::createNativeFunction(UInt3_setZXY);
             else if (keyStr == "getZYX")
                return scripting::createNativeFunction(UInt3_getZYX);
             else if (keyStr == "setZYX")
                return scripting::createNativeFunction(UInt3_setZYX);
             else if(keyStr=="x")
            {
                T3<uint32_t>*obj=(T3<uint32_t>*)self->data;
                return create_val<decltype(obj->x)>::f(ctx,obj->x);
            } else if(keyStr=="y")
            {
                T3<uint32_t>*obj=(T3<uint32_t>*)self->data;
                return create_val<decltype(obj->y)>::f(ctx,obj->y);
            } else if(keyStr=="z")
            {
                T3<uint32_t>*obj=(T3<uint32_t>*)self->data;
                return create_val<decltype(obj->z)>::f(ctx,obj->z);
            } else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        }
    }
    return scripting::createNil();
}

void UInt3_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue*)key)->value;
        if(self->data==NULL)
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Native classes are read-only."));
        else
        {
            if(0) {} else if(keyStr=="x")
            {
                T3<uint32_t>*obj=(T3<uint32_t>*)self->data;
                obj->x=val_to_c<decltype(obj->x)>::f(ctx,value);
            } else if(keyStr=="y")
            {
                T3<uint32_t>*obj=(T3<uint32_t>*)self->data;
                obj->y=val_to_c<decltype(obj->y)>::f(ctx,value);
            } else if(keyStr=="z")
            {
                T3<uint32_t>*obj=(T3<uint32_t>*)self->data;
                obj->z=val_to_c<decltype(obj->z)>::f(ctx,value);
            } else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member or member if read-only."));
        }
    }
}

scripting::Value *UInt3_setYZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::setYZX expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::setYZX expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYZX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::setYZX."));
    return scripting::createNil();
}

scripting::Value *UInt3_getZXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::getZXY expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::getZXY expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::getZXY."));
    return scripting::createNil();
}

scripting::Value *UInt3_setYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::setYZ expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::setYZ expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setYZ(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::setYZ."));
    return scripting::createNil();
}

scripting::Value *UInt3_setYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::setYX expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::setYX expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setYX(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::setYX."));
    return scripting::createNil();
}

scripting::Value *UInt3_setZYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::setZYX expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::setZYX expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZYX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::setZYX."));
    return scripting::createNil();
}

scripting::Value *UInt3_getZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::getZY expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::getZY expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getZY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::getZY."));
    return scripting::createNil();
}

scripting::Value *UInt3_distanceSquared(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::distanceSquared expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::distanceSquared expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->distanceSquared(val_to_c<const T3<float> &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::distanceSquared."));
    return scripting::createNil();
}

scripting::Value *UInt3_normalize(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::normalize expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::normalize expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->normalize());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::normalize."));
    return scripting::createNil();
}

scripting::Value *UInt3_getYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::getYX expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::getYX expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::getYX."));
    return scripting::createNil();
}

scripting::Value *UInt3___leq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::__leq__ expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::__leq__ expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self <= val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::__leq__."));
    return scripting::createNil();
}

scripting::Value *UInt3_setXZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::setXZY expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::setXZY expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXZY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::setXZY."));
    return scripting::createNil();
}

scripting::Value *UInt3_sum(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::sum expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::sum expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->sum());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::sum."));
    return scripting::createNil();
}

scripting::Value *UInt3_cross(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::cross expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::cross expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx,  self->cross(val_to_c<const T3<float> &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::cross."));
    return scripting::createNil();
}

scripting::Value *UInt3_getXYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::getXYZ expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::getXYZ expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXYZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::getXYZ."));
    return scripting::createNil();
}

scripting::Value *UInt3___less__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::__less__ expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::__less__ expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self < val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::__less__."));
    return scripting::createNil();
}

scripting::Value *UInt3___neq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::__neq__ expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::__neq__ expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self != val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::__neq__."));
    return scripting::createNil();
}

scripting::Value *UInt3_getYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::getYZ expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::getYZ expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getYZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::getYZ."));
    return scripting::createNil();
}

scripting::Value *UInt3_lengthSquared(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::lengthSquared expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::lengthSquared expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->lengthSquared());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::lengthSquared."));
    return scripting::createNil();
}

scripting::Value *UInt3_getZYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::getZYX expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::getZYX expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::getZYX."));
    return scripting::createNil();
}

scripting::Value *UInt3___div__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::__div__ expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::__div__ expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self / val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self / val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::__div__."));
    return scripting::createNil();
}

scripting::Value *UInt3_setZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::setZY expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::setZY expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setZY(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::setZY."));
    return scripting::createNil();
}

scripting::Value *UInt3_setZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::setZX expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::setZX expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setZX(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::setZX."));
    return scripting::createNil();
}

scripting::Value *UInt3_setXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::setXY expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::setXY expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setXY(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::setXY."));
    return scripting::createNil();
}

scripting::Value *UInt3___add__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::__add__ expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::__add__ expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self + val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self + val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::__add__."));
    return scripting::createNil();
}

scripting::Value *UInt3_setXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::setXZ expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::setXZ expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setXZ(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::setXZ."));
    return scripting::createNil();
}

scripting::Value *UInt3___eq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::__eq__ expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::__eq__ expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self == val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::__eq__."));
    return scripting::createNil();
}

scripting::Value *UInt3_setZXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::setZXY expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::setZXY expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZXY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::setZXY."));
    return scripting::createNil();
}

scripting::Value *UInt3_setYXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::setYXZ expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::setYXZ expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYXZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::setYXZ."));
    return scripting::createNil();
}

scripting::Value *UInt3_getXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::getXY expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::getXY expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::getXY."));
    return scripting::createNil();
}

scripting::Value *UInt3_distance(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::distance expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::distance expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->distance(val_to_c<const T3<float> &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::distance."));
    return scripting::createNil();
}

scripting::Value *UInt3_getXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::getXZ expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::getXZ expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getXZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::getXZ."));
    return scripting::createNil();
}

scripting::Value *UInt3___grtr__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::__grtr__ expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::__grtr__ expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self > val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::__grtr__."));
    return scripting::createNil();
}

scripting::Value *UInt3_getXZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::getXZY expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::getXZY expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXZY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::getXZY."));
    return scripting::createNil();
}

scripting::Value *UInt3_setXYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::setXYZ expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::setXYZ expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXYZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::setXYZ."));
    return scripting::createNil();
}

scripting::Value *UInt3_getYZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::getYZX expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::getYZX expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYZX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::getYZX."));
    return scripting::createNil();
}

scripting::Value *UInt3_length(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::length expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::length expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->length());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::length."));
    return scripting::createNil();
}

scripting::Value *UInt3___mul__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::__mul__ expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::__mul__ expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self * val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self * val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::__mul__."));
    return scripting::createNil();
}

scripting::Value *UInt3_getYXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::getYXZ expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::getYXZ expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYXZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::getYXZ."));
    return scripting::createNil();
}

scripting::Value *UInt3_getZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::getZX expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::getZX expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getZX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::getZX."));
    return scripting::createNil();
}

scripting::Value *UInt3___sub__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::__sub__ expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::__sub__ expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self - val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self - val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::__sub__."));
    return scripting::createNil();
}

scripting::Value *UInt3___geq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::__geq__ expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::__geq__ expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self >= val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::__geq__."));
    return scripting::createNil();
}

scripting::Value *UInt3_dot(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::dot expects at least one argument."));
    T3<uint32_t>*self;
    if(!type_same<T3<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3::dot expects UInt3 as first argument."));
    else
         self=(T3<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->dot(val_to_c<const T3<float> &>::f(ctx,args[1])));
            ;
        }
    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->dot());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt3::dot."));
    return scripting::createNil();
}

scripting::Value *UInt2_copy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(UInt2_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(UInt2_funcs,NEW(T2<uint32_t>,*((T2<uint32_t>*)self->data)),self->typeID);
}

void UInt2_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<T2<uint32_t>>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::__del__ expects UInt2 as first argument."));

    DELETE(T2<uint32_t>,(T2<uint32_t> *)self->data);
}scripting::Value *UInt2_new(scripting::Context*ctx,const List<scripting::Value *>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2's constructor expects at least one argument."));
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2's constructor expects UInt2 as first argument."));
    if(args.getCount()==1)
        if(true)
            return scripting::createNativeObject(UInt2_funcs,NEW(UInt2),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt2_typeID);
    if(args.getCount()==2)
        if(true&&type_same<float>::f(ctx,args[1]))
            return scripting::createNativeObject(UInt2_funcs,NEW(UInt2,val_to_c<float>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt2_typeID);
    if(args.getCount()==3)
        if(true&&type_same<float>::f(ctx,args[1])&&type_same<float>::f(ctx,args[2]))
            return scripting::createNativeObject(UInt2_funcs,NEW(UInt2,val_to_c<float>::f(ctx,args[1]),val_to_c<float>::f(ctx,args[2])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt2_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T2<float> &>::f(ctx,args[1]))
            return scripting::createNativeObject(UInt2_funcs,NEW(UInt2,val_to_c<const T2<float> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt2_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T2<int32_t> &>::f(ctx,args[1]))
            return scripting::createNativeObject(UInt2_funcs,NEW(UInt2,val_to_c<const T2<int32_t> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt2_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T2<uint32_t> &>::f(ctx,args[1]))
            return scripting::createNativeObject(UInt2_funcs,NEW(UInt2,val_to_c<const T2<uint32_t> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt2_typeID);
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2's constructor."));
    return scripting::createNil();
}

scripting::Value *UInt2_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
            if(keyStr=="__typeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__name__")
                return scripting::createString("UInt2");
            else if(keyStr=="__new__")
                return scripting::createNativeFunction(UInt2_new);
            else if(keyStr=="__call__")
                return scripting::createNativeFunction(UInt2_new);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
            if(keyStr=="__classTypeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__init__")
                return scripting::createNativeFunction(UInt2_new);
             else if (keyStr == "__add__")
                return scripting::createNativeFunction(UInt2___add__);
             else if (keyStr == "__sub__")
                return scripting::createNativeFunction(UInt2___sub__);
             else if (keyStr == "__mul__")
                return scripting::createNativeFunction(UInt2___mul__);
             else if (keyStr == "__div__")
                return scripting::createNativeFunction(UInt2___div__);
             else if (keyStr == "__eq__")
                return scripting::createNativeFunction(UInt2___eq__);
             else if (keyStr == "__neq__")
                return scripting::createNativeFunction(UInt2___neq__);
             else if (keyStr == "__less__")
                return scripting::createNativeFunction(UInt2___less__);
             else if (keyStr == "__grtr__")
                return scripting::createNativeFunction(UInt2___grtr__);
             else if (keyStr == "__leq__")
                return scripting::createNativeFunction(UInt2___leq__);
             else if (keyStr == "__geq__")
                return scripting::createNativeFunction(UInt2___geq__);
             else if (keyStr == "sum")
                return scripting::createNativeFunction(UInt2_sum);
             else if (keyStr == "length")
                return scripting::createNativeFunction(UInt2_length);
             else if (keyStr == "lengthSquared")
                return scripting::createNativeFunction(UInt2_lengthSquared);
             else if (keyStr == "dot")
                return scripting::createNativeFunction(UInt2_dot);
             else if (keyStr == "distance")
                return scripting::createNativeFunction(UInt2_distance);
             else if (keyStr == "distanceSquared")
                return scripting::createNativeFunction(UInt2_distanceSquared);
             else if (keyStr == "normalize")
                return scripting::createNativeFunction(UInt2_normalize);
             else if (keyStr == "getXY")
                return scripting::createNativeFunction(UInt2_getXY);
             else if (keyStr == "setXY")
                return scripting::createNativeFunction(UInt2_setXY);
             else if (keyStr == "getYX")
                return scripting::createNativeFunction(UInt2_getYX);
             else if (keyStr == "setYX")
                return scripting::createNativeFunction(UInt2_setYX);
             else if(keyStr=="x")
            {
                T2<uint32_t>*obj=(T2<uint32_t>*)self->data;
                return create_val<decltype(obj->x)>::f(ctx,obj->x);
            } else if(keyStr=="y")
            {
                T2<uint32_t>*obj=(T2<uint32_t>*)self->data;
                return create_val<decltype(obj->y)>::f(ctx,obj->y);
            } else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        }
    }
    return scripting::createNil();
}

void UInt2_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue*)key)->value;
        if(self->data==NULL)
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Native classes are read-only."));
        else
        {
            if(0) {} else if(keyStr=="x")
            {
                T2<uint32_t>*obj=(T2<uint32_t>*)self->data;
                obj->x=val_to_c<decltype(obj->x)>::f(ctx,value);
            } else if(keyStr=="y")
            {
                T2<uint32_t>*obj=(T2<uint32_t>*)self->data;
                obj->y=val_to_c<decltype(obj->y)>::f(ctx,value);
            } else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member or member if read-only."));
        }
    }
}

scripting::Value *UInt2_normalize(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::normalize expects at least one argument."));
    T2<uint32_t>*self;
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::normalize expects UInt2 as first argument."));
    else
         self=(T2<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->normalize());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2::normalize."));
    return scripting::createNil();
}

scripting::Value *UInt2_distance(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::distance expects at least one argument."));
    T2<uint32_t>*self;
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::distance expects UInt2 as first argument."));
    else
         self=(T2<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->distance(val_to_c<const T2<float> &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2::distance."));
    return scripting::createNil();
}

scripting::Value *UInt2_lengthSquared(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::lengthSquared expects at least one argument."));
    T2<uint32_t>*self;
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::lengthSquared expects UInt2 as first argument."));
    else
         self=(T2<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->lengthSquared());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2::lengthSquared."));
    return scripting::createNil();
}

scripting::Value *UInt2___leq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::__leq__ expects at least one argument."));
    T2<uint32_t>*self;
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::__leq__ expects UInt2 as first argument."));
    else
         self=(T2<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self <= val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2::__leq__."));
    return scripting::createNil();
}

scripting::Value *UInt2_setYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::setYX expects at least one argument."));
    T2<uint32_t>*self;
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::setYX expects UInt2 as first argument."));
    else
         self=(T2<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setYX(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2::setYX."));
    return scripting::createNil();
}

scripting::Value *UInt2___grtr__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::__grtr__ expects at least one argument."));
    T2<uint32_t>*self;
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::__grtr__ expects UInt2 as first argument."));
    else
         self=(T2<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self > val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2::__grtr__."));
    return scripting::createNil();
}

scripting::Value *UInt2_sum(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::sum expects at least one argument."));
    T2<uint32_t>*self;
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::sum expects UInt2 as first argument."));
    else
         self=(T2<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->sum());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2::sum."));
    return scripting::createNil();
}

scripting::Value *UInt2_getXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::getXY expects at least one argument."));
    T2<uint32_t>*self;
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::getXY expects UInt2 as first argument."));
    else
         self=(T2<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2::getXY."));
    return scripting::createNil();
}

scripting::Value *UInt2_length(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::length expects at least one argument."));
    T2<uint32_t>*self;
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::length expects UInt2 as first argument."));
    else
         self=(T2<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->length());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2::length."));
    return scripting::createNil();
}

scripting::Value *UInt2_getYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::getYX expects at least one argument."));
    T2<uint32_t>*self;
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::getYX expects UInt2 as first argument."));
    else
         self=(T2<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2::getYX."));
    return scripting::createNil();
}

scripting::Value *UInt2___div__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::__div__ expects at least one argument."));
    T2<uint32_t>*self;
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::__div__ expects UInt2 as first argument."));
    else
         self=(T2<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self / val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self / val_to_c<float>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2::__div__."));
    return scripting::createNil();
}

scripting::Value *UInt2_setXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::setXY expects at least one argument."));
    T2<uint32_t>*self;
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::setXY expects UInt2 as first argument."));
    else
         self=(T2<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setXY(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2::setXY."));
    return scripting::createNil();
}

scripting::Value *UInt2___mul__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::__mul__ expects at least one argument."));
    T2<uint32_t>*self;
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::__mul__ expects UInt2 as first argument."));
    else
         self=(T2<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self * val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self * val_to_c<float>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2::__mul__."));
    return scripting::createNil();
}

scripting::Value *UInt2___add__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::__add__ expects at least one argument."));
    T2<uint32_t>*self;
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::__add__ expects UInt2 as first argument."));
    else
         self=(T2<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self + val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self + val_to_c<float>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2::__add__."));
    return scripting::createNil();
}

scripting::Value *UInt2___less__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::__less__ expects at least one argument."));
    T2<uint32_t>*self;
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::__less__ expects UInt2 as first argument."));
    else
         self=(T2<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self < val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2::__less__."));
    return scripting::createNil();
}

scripting::Value *UInt2___sub__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::__sub__ expects at least one argument."));
    T2<uint32_t>*self;
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::__sub__ expects UInt2 as first argument."));
    else
         self=(T2<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self - val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self - val_to_c<float>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2::__sub__."));
    return scripting::createNil();
}

scripting::Value *UInt2___geq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::__geq__ expects at least one argument."));
    T2<uint32_t>*self;
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::__geq__ expects UInt2 as first argument."));
    else
         self=(T2<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self >= val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2::__geq__."));
    return scripting::createNil();
}

scripting::Value *UInt2_distanceSquared(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::distanceSquared expects at least one argument."));
    T2<uint32_t>*self;
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::distanceSquared expects UInt2 as first argument."));
    else
         self=(T2<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->distanceSquared(val_to_c<const T2<float> &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2::distanceSquared."));
    return scripting::createNil();
}

scripting::Value *UInt2___eq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::__eq__ expects at least one argument."));
    T2<uint32_t>*self;
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::__eq__ expects UInt2 as first argument."));
    else
         self=(T2<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self == val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2::__eq__."));
    return scripting::createNil();
}

scripting::Value *UInt2_dot(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::dot expects at least one argument."));
    T2<uint32_t>*self;
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::dot expects UInt2 as first argument."));
    else
         self=(T2<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->dot(val_to_c<const T2<float> &>::f(ctx,args[1])));
            ;
        }
    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->dot());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2::dot."));
    return scripting::createNil();
}

scripting::Value *UInt2___neq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::__neq__ expects at least one argument."));
    T2<uint32_t>*self;
    if(!type_same<T2<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2::__neq__ expects UInt2 as first argument."));
    else
         self=(T2<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self != val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt2::__neq__."));
    return scripting::createNil();
}

scripting::Value *RigidBody_copy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(RigidBody_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(RigidBody_funcs,NEW(RigidBody,*((RigidBody*)self->data)),self->typeID);
}

void RigidBody_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<RigidBody>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::__del__ expects RigidBody as first argument."));

}scripting::Value *RigidBody_new(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody's constructor expects one argument."));
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody's constructor expects RigidBody as first argument."));
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody's constructor."));
}

scripting::Value *RigidBody_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
            if(keyStr=="__typeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__name__")
                return scripting::createString("RigidBody");
            else if(keyStr=="__new__")
                return scripting::createNativeFunction(RigidBody_new);
            else if(keyStr=="__call__")
                return scripting::createNativeFunction(RigidBody_new);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
            if(keyStr=="__classTypeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__init__")
                return scripting::createNativeFunction(RigidBody_new);
             else if (keyStr == "getBulletRigidBody")
                return scripting::createNativeFunction(RigidBody_getBulletRigidBody);
             else if (keyStr == "getType")
                return scripting::createNativeFunction(RigidBody_getType);
             else if (keyStr == "getGravity")
                return scripting::createNativeFunction(RigidBody_getGravity);
             else if (keyStr == "setGravity")
                return scripting::createNativeFunction(RigidBody_setGravity);
             else if (keyStr == "setLinearDamping")
                return scripting::createNativeFunction(RigidBody_setLinearDamping);
             else if (keyStr == "getLinearDamping")
                return scripting::createNativeFunction(RigidBody_getLinearDamping);
             else if (keyStr == "setAngularDamping")
                return scripting::createNativeFunction(RigidBody_setAngularDamping);
             else if (keyStr == "getAngularDamping")
                return scripting::createNativeFunction(RigidBody_getAngularDamping);
             else if (keyStr == "setMass")
                return scripting::createNativeFunction(RigidBody_setMass);
             else if (keyStr == "getMass")
                return scripting::createNativeFunction(RigidBody_getMass);
             else if (keyStr == "getLinearSleepingThreshold")
                return scripting::createNativeFunction(RigidBody_getLinearSleepingThreshold);
             else if (keyStr == "setLinearSleepingThreshold")
                return scripting::createNativeFunction(RigidBody_setLinearSleepingThreshold);
             else if (keyStr == "getAngularSleepingThreshold")
                return scripting::createNativeFunction(RigidBody_getAngularSleepingThreshold);
             else if (keyStr == "setAngularSleepingThreshold")
                return scripting::createNativeFunction(RigidBody_setAngularSleepingThreshold);
             else if (keyStr == "applyTorque")
                return scripting::createNativeFunction(RigidBody_applyTorque);
             else if (keyStr == "applyForce")
                return scripting::createNativeFunction(RigidBody_applyForce);
             else if (keyStr == "applyCentralImpulse")
                return scripting::createNativeFunction(RigidBody_applyCentralImpulse);
             else if (keyStr == "applyTorqueImpulse")
                return scripting::createNativeFunction(RigidBody_applyTorqueImpulse);
             else if (keyStr == "applyImpulse")
                return scripting::createNativeFunction(RigidBody_applyImpulse);
             else if (keyStr == "clearForces")
                return scripting::createNativeFunction(RigidBody_clearForces);
             else if (keyStr == "getLinearVelocity")
                return scripting::createNativeFunction(RigidBody_getLinearVelocity);
             else if (keyStr == "setLinearVelocity")
                return scripting::createNativeFunction(RigidBody_setLinearVelocity);
             else if (keyStr == "getAngularVelocity")
                return scripting::createNativeFunction(RigidBody_getAngularVelocity);
             else if (keyStr == "setAngularVelocity")
                return scripting::createNativeFunction(RigidBody_setAngularVelocity);
             else if (keyStr == "getVelocityOfPoint")
                return scripting::createNativeFunction(RigidBody_getVelocityOfPoint);
             else if (keyStr == "getRestitution")
                return scripting::createNativeFunction(RigidBody_getRestitution);
             else if (keyStr == "setRestitution")
                return scripting::createNativeFunction(RigidBody_setRestitution);
             else if (keyStr == "getFriction")
                return scripting::createNativeFunction(RigidBody_getFriction);
             else if (keyStr == "setFriction")
                return scripting::createNativeFunction(RigidBody_setFriction);
             else if (keyStr == "getRollingFriction")
                return scripting::createNativeFunction(RigidBody_getRollingFriction);
             else if (keyStr == "setRollingFriction")
                return scripting::createNativeFunction(RigidBody_setRollingFriction);
             else if (keyStr == "getLinearFactor")
                return scripting::createNativeFunction(RigidBody_getLinearFactor);
             else if (keyStr == "setLinearFactor")
                return scripting::createNativeFunction(RigidBody_setLinearFactor);
             else if (keyStr == "getAngularFactor")
                return scripting::createNativeFunction(RigidBody_getAngularFactor);
             else if (keyStr == "setAngularFactor")
                return scripting::createNativeFunction(RigidBody_setAngularFactor);
             else if (keyStr == "setTransform")
                return scripting::createNativeFunction(RigidBody_setTransform);
             else if (keyStr == "getWorld")
                return scripting::createNativeFunction(RigidBody_getWorld);
             else if (keyStr == "getCollisionMask")
                return scripting::createNativeFunction(RigidBody_getCollisionMask);
             else if (keyStr == "setShape")
                return scripting::createNativeFunction(RigidBody_setShape);
             else if (keyStr == "getShape")
                return scripting::createNativeFunction(RigidBody_getShape);
             else if (keyStr == "getEntity")
                return scripting::createNativeFunction(RigidBody_getEntity);
             else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        }
    }
    return scripting::createNil();
}

void RigidBody_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue*)key)->value;
        if(self->data==NULL)
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Native classes are read-only."));
        else
        {
            if(0) {} else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member or member if read-only."));
        }
    }
}

scripting::Value *RigidBody_setGravity(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::setGravity expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::setGravity expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const Vector3D &>::f(ctx,args[1]))
        {
            ( self->setGravity(val_to_c<const Vector3D &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::setGravity."));
    return scripting::createNil();
}

scripting::Value *RigidBody_getFriction(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::getFriction expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::getFriction expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->getFriction());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::getFriction."));
    return scripting::createNil();
}

scripting::Value *RigidBody_getRollingFriction(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::getRollingFriction expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::getRollingFriction expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->getRollingFriction());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::getRollingFriction."));
    return scripting::createNil();
}

scripting::Value *RigidBody_setAngularFactor(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::setAngularFactor expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::setAngularFactor expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const Float3 &>::f(ctx,args[1]))
        {
            ( self->setAngularFactor(val_to_c<const Float3 &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::setAngularFactor."));
    return scripting::createNil();
}

scripting::Value *RigidBody_getVelocityOfPoint(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::getVelocityOfPoint expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::getVelocityOfPoint expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const Position3D &>::f(ctx,args[1]))
        {
            return create_val<Vector3D>::f(ctx,  self->getVelocityOfPoint(val_to_c<const Position3D &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::getVelocityOfPoint."));
    return scripting::createNil();
}

scripting::Value *RigidBody_setTransform(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::setTransform expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::setTransform expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const Matrix4x4 &>::f(ctx,args[1]))
        {
            ( self->setTransform(val_to_c<const Matrix4x4 &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::setTransform."));
    return scripting::createNil();
}

scripting::Value *RigidBody_getMass(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::getMass expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::getMass expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->getMass());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::getMass."));
    return scripting::createNil();
}

scripting::Value *RigidBody_setFriction(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::setFriction expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::setFriction expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            ( self->setFriction(val_to_c<float>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::setFriction."));
    return scripting::createNil();
}

scripting::Value *RigidBody_clearForces(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::clearForces expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::clearForces expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            ( self->clearForces());
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::clearForces."));
    return scripting::createNil();
}

scripting::Value *RigidBody_applyImpulse(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::applyImpulse expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::applyImpulse expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==3)
        if(1&&type_same<const Vector3D &>::f(ctx,args[1])&&type_same<const Position3D &>::f(ctx,args[2]))
        {
            ( self->applyImpulse(val_to_c<const Vector3D &>::f(ctx,args[1]), val_to_c<const Position3D &>::f(ctx,args[2])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::applyImpulse."));
    return scripting::createNil();
}

scripting::Value *RigidBody_applyTorque(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::applyTorque expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::applyTorque expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const Vector3D &>::f(ctx,args[1]))
        {
            ( self->applyTorque(val_to_c<const Vector3D &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::applyTorque."));
    return scripting::createNil();
}

scripting::Value *RigidBody_setLinearFactor(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::setLinearFactor expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::setLinearFactor expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const Float3 &>::f(ctx,args[1]))
        {
            ( self->setLinearFactor(val_to_c<const Float3 &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::setLinearFactor."));
    return scripting::createNil();
}

scripting::Value *RigidBody_setLinearDamping(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::setLinearDamping expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::setLinearDamping expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            ( self->setLinearDamping(val_to_c<float>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::setLinearDamping."));
    return scripting::createNil();
}

scripting::Value *RigidBody_getLinearFactor(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::getLinearFactor expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::getLinearFactor expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<Float3>::f(ctx,  self->getLinearFactor());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::getLinearFactor."));
    return scripting::createNil();
}

scripting::Value *RigidBody_setAngularDamping(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::setAngularDamping expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::setAngularDamping expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            ( self->setAngularDamping(val_to_c<float>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::setAngularDamping."));
    return scripting::createNil();
}

scripting::Value *RigidBody_getWorld(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::getWorld expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::getWorld expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::getWorld."));
    return scripting::createNil();
}

scripting::Value *RigidBody_getAngularVelocity(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::getAngularVelocity expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::getAngularVelocity expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<Vector3D>::f(ctx,  self->getAngularVelocity());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::getAngularVelocity."));
    return scripting::createNil();
}

scripting::Value *RigidBody_getShape(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::getShape expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::getShape expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::getShape."));
    return scripting::createNil();
}

scripting::Value *RigidBody_setAngularSleepingThreshold(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::setAngularSleepingThreshold expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::setAngularSleepingThreshold expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            ( self->setAngularSleepingThreshold(val_to_c<float>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::setAngularSleepingThreshold."));
    return scripting::createNil();
}

scripting::Value *RigidBody_applyTorqueImpulse(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::applyTorqueImpulse expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::applyTorqueImpulse expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const Vector3D &>::f(ctx,args[1]))
        {
            ( self->applyTorqueImpulse(val_to_c<const Vector3D &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::applyTorqueImpulse."));
    return scripting::createNil();
}

scripting::Value *RigidBody_setLinearVelocity(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::setLinearVelocity expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::setLinearVelocity expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const Vector3D &>::f(ctx,args[1]))
        {
            ( self->setLinearVelocity(val_to_c<const Vector3D &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::setLinearVelocity."));
    return scripting::createNil();
}

scripting::Value *RigidBody_getCollisionMask(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::getCollisionMask expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::getCollisionMask expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<short>::f(ctx,  self->getCollisionMask());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::getCollisionMask."));
    return scripting::createNil();
}

scripting::Value *RigidBody_getLinearVelocity(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::getLinearVelocity expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::getLinearVelocity expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<Vector3D>::f(ctx,  self->getLinearVelocity());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::getLinearVelocity."));
    return scripting::createNil();
}

scripting::Value *RigidBody_setAngularVelocity(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::setAngularVelocity expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::setAngularVelocity expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const Vector3D &>::f(ctx,args[1]))
        {
            ( self->setAngularVelocity(val_to_c<const Vector3D &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::setAngularVelocity."));
    return scripting::createNil();
}

scripting::Value *RigidBody_getType(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::getType expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::getType expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::getType."));
    return scripting::createNil();
}

scripting::Value *RigidBody_getAngularSleepingThreshold(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::getAngularSleepingThreshold expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::getAngularSleepingThreshold expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->getAngularSleepingThreshold());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::getAngularSleepingThreshold."));
    return scripting::createNil();
}

scripting::Value *RigidBody_setLinearSleepingThreshold(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::setLinearSleepingThreshold expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::setLinearSleepingThreshold expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            ( self->setLinearSleepingThreshold(val_to_c<float>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::setLinearSleepingThreshold."));
    return scripting::createNil();
}

scripting::Value *RigidBody_setRollingFriction(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::setRollingFriction expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::setRollingFriction expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            ( self->setRollingFriction(val_to_c<float>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::setRollingFriction."));
    return scripting::createNil();
}

scripting::Value *RigidBody_getGravity(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::getGravity expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::getGravity expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<Vector3D>::f(ctx,  self->getGravity());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::getGravity."));
    return scripting::createNil();
}

scripting::Value *RigidBody_setMass(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::setMass expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::setMass expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            ( self->setMass(val_to_c<float>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::setMass."));
    return scripting::createNil();
}

scripting::Value *RigidBody_applyCentralImpulse(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::applyCentralImpulse expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::applyCentralImpulse expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const Vector3D &>::f(ctx,args[1]))
        {
            ( self->applyCentralImpulse(val_to_c<const Vector3D &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::applyCentralImpulse."));
    return scripting::createNil();
}

scripting::Value *RigidBody_getBulletRigidBody(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::getBulletRigidBody expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::getBulletRigidBody expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::getBulletRigidBody."));
    return scripting::createNil();
}

scripting::Value *RigidBody_getRestitution(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::getRestitution expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::getRestitution expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->getRestitution());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::getRestitution."));
    return scripting::createNil();
}

scripting::Value *RigidBody_getAngularFactor(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::getAngularFactor expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::getAngularFactor expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<Float3>::f(ctx,  self->getAngularFactor());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::getAngularFactor."));
    return scripting::createNil();
}

scripting::Value *RigidBody_getAngularDamping(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::getAngularDamping expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::getAngularDamping expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->getAngularDamping());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::getAngularDamping."));
    return scripting::createNil();
}

scripting::Value *RigidBody_getLinearSleepingThreshold(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::getLinearSleepingThreshold expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::getLinearSleepingThreshold expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->getLinearSleepingThreshold());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::getLinearSleepingThreshold."));
    return scripting::createNil();
}

scripting::Value *RigidBody_applyForce(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::applyForce expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::applyForce expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==3)
        if(1&&type_same<const Vector3D &>::f(ctx,args[1])&&type_same<const Position3D &>::f(ctx,args[2]))
        {
            ( self->applyForce(val_to_c<const Vector3D &>::f(ctx,args[1]), val_to_c<const Position3D &>::f(ctx,args[2])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::applyForce."));
    return scripting::createNil();
}

scripting::Value *RigidBody_getEntity(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::getEntity expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::getEntity expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::getEntity."));
    return scripting::createNil();
}

scripting::Value *RigidBody_setRestitution(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::setRestitution expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::setRestitution expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            ( self->setRestitution(val_to_c<float>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::setRestitution."));
    return scripting::createNil();
}

scripting::Value *RigidBody_setShape(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::setShape expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::setShape expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::setShape."));
    return scripting::createNil();
}

scripting::Value *RigidBody_getLinearDamping(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::getLinearDamping expects at least one argument."));
    RigidBody*self;
    if(!type_same<RigidBody>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody::getLinearDamping expects RigidBody as first argument."));
    else
         self=(RigidBody*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->getLinearDamping());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for RigidBody::getLinearDamping."));
    return scripting::createNil();
}

scripting::Value *Int3_copy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(Int3_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(Int3_funcs,NEW(T3<int32_t>,*((T3<int32_t>*)self->data)),self->typeID);
}

void Int3_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<T3<int32_t>>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::__del__ expects Int3 as first argument."));

    DELETE(T3<int32_t>,(T3<int32_t> *)self->data);
}scripting::Value *Int3_new(scripting::Context*ctx,const List<scripting::Value *>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3's constructor expects at least one argument."));
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3's constructor expects Int3 as first argument."));
    if(args.getCount()==1)
        if(true)
            return scripting::createNativeObject(Int3_funcs,NEW(Int3),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int3_typeID);
    if(args.getCount()==2)
        if(true&&type_same<float>::f(ctx,args[1]))
            return scripting::createNativeObject(Int3_funcs,NEW(Int3,val_to_c<float>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int3_typeID);
    if(args.getCount()==4)
        if(true&&type_same<float>::f(ctx,args[1])&&type_same<float>::f(ctx,args[2])&&type_same<float>::f(ctx,args[3]))
            return scripting::createNativeObject(Int3_funcs,NEW(Int3,val_to_c<float>::f(ctx,args[1]),val_to_c<float>::f(ctx,args[2]),val_to_c<float>::f(ctx,args[3])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int3_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T3<float> &>::f(ctx,args[1]))
            return scripting::createNativeObject(Int3_funcs,NEW(Int3,val_to_c<const T3<float> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int3_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T3<int32_t> &>::f(ctx,args[1]))
            return scripting::createNativeObject(Int3_funcs,NEW(Int3,val_to_c<const T3<int32_t> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int3_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T3<uint32_t> &>::f(ctx,args[1]))
            return scripting::createNativeObject(Int3_funcs,NEW(Int3,val_to_c<const T3<uint32_t> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int3_typeID);
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3's constructor."));
    return scripting::createNil();
}

scripting::Value *Int3_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
            if(keyStr=="__typeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__name__")
                return scripting::createString("Int3");
            else if(keyStr=="__new__")
                return scripting::createNativeFunction(Int3_new);
            else if(keyStr=="__call__")
                return scripting::createNativeFunction(Int3_new);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
            if(keyStr=="__classTypeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__init__")
                return scripting::createNativeFunction(Int3_new);
             else if (keyStr == "__add__")
                return scripting::createNativeFunction(Int3___add__);
             else if (keyStr == "__sub__")
                return scripting::createNativeFunction(Int3___sub__);
             else if (keyStr == "__mul__")
                return scripting::createNativeFunction(Int3___mul__);
             else if (keyStr == "__div__")
                return scripting::createNativeFunction(Int3___div__);
             else if (keyStr == "__eq__")
                return scripting::createNativeFunction(Int3___eq__);
             else if (keyStr == "__neq__")
                return scripting::createNativeFunction(Int3___neq__);
             else if (keyStr == "__less__")
                return scripting::createNativeFunction(Int3___less__);
             else if (keyStr == "__grtr__")
                return scripting::createNativeFunction(Int3___grtr__);
             else if (keyStr == "__leq__")
                return scripting::createNativeFunction(Int3___leq__);
             else if (keyStr == "__geq__")
                return scripting::createNativeFunction(Int3___geq__);
             else if (keyStr == "sum")
                return scripting::createNativeFunction(Int3_sum);
             else if (keyStr == "length")
                return scripting::createNativeFunction(Int3_length);
             else if (keyStr == "lengthSquared")
                return scripting::createNativeFunction(Int3_lengthSquared);
             else if (keyStr == "dot")
                return scripting::createNativeFunction(Int3_dot);
             else if (keyStr == "distance")
                return scripting::createNativeFunction(Int3_distance);
             else if (keyStr == "distanceSquared")
                return scripting::createNativeFunction(Int3_distanceSquared);
             else if (keyStr == "normalize")
                return scripting::createNativeFunction(Int3_normalize);
             else if (keyStr == "cross")
                return scripting::createNativeFunction(Int3_cross);
             else if (keyStr == "getXY")
                return scripting::createNativeFunction(Int3_getXY);
             else if (keyStr == "setXY")
                return scripting::createNativeFunction(Int3_setXY);
             else if (keyStr == "getXZ")
                return scripting::createNativeFunction(Int3_getXZ);
             else if (keyStr == "setXZ")
                return scripting::createNativeFunction(Int3_setXZ);
             else if (keyStr == "getYX")
                return scripting::createNativeFunction(Int3_getYX);
             else if (keyStr == "setYX")
                return scripting::createNativeFunction(Int3_setYX);
             else if (keyStr == "getYZ")
                return scripting::createNativeFunction(Int3_getYZ);
             else if (keyStr == "setYZ")
                return scripting::createNativeFunction(Int3_setYZ);
             else if (keyStr == "getZX")
                return scripting::createNativeFunction(Int3_getZX);
             else if (keyStr == "setZX")
                return scripting::createNativeFunction(Int3_setZX);
             else if (keyStr == "getZY")
                return scripting::createNativeFunction(Int3_getZY);
             else if (keyStr == "setZY")
                return scripting::createNativeFunction(Int3_setZY);
             else if (keyStr == "getXYZ")
                return scripting::createNativeFunction(Int3_getXYZ);
             else if (keyStr == "setXYZ")
                return scripting::createNativeFunction(Int3_setXYZ);
             else if (keyStr == "getXZY")
                return scripting::createNativeFunction(Int3_getXZY);
             else if (keyStr == "setXZY")
                return scripting::createNativeFunction(Int3_setXZY);
             else if (keyStr == "getYXZ")
                return scripting::createNativeFunction(Int3_getYXZ);
             else if (keyStr == "setYXZ")
                return scripting::createNativeFunction(Int3_setYXZ);
             else if (keyStr == "getYZX")
                return scripting::createNativeFunction(Int3_getYZX);
             else if (keyStr == "setYZX")
                return scripting::createNativeFunction(Int3_setYZX);
             else if (keyStr == "getZXY")
                return scripting::createNativeFunction(Int3_getZXY);
             else if (keyStr == "setZXY")
                return scripting::createNativeFunction(Int3_setZXY);
             else if (keyStr == "getZYX")
                return scripting::createNativeFunction(Int3_getZYX);
             else if (keyStr == "setZYX")
                return scripting::createNativeFunction(Int3_setZYX);
             else if(keyStr=="x")
            {
                T3<int32_t>*obj=(T3<int32_t>*)self->data;
                return create_val<decltype(obj->x)>::f(ctx,obj->x);
            } else if(keyStr=="y")
            {
                T3<int32_t>*obj=(T3<int32_t>*)self->data;
                return create_val<decltype(obj->y)>::f(ctx,obj->y);
            } else if(keyStr=="z")
            {
                T3<int32_t>*obj=(T3<int32_t>*)self->data;
                return create_val<decltype(obj->z)>::f(ctx,obj->z);
            } else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        }
    }
    return scripting::createNil();
}

void Int3_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue*)key)->value;
        if(self->data==NULL)
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Native classes are read-only."));
        else
        {
            if(0) {} else if(keyStr=="x")
            {
                T3<int32_t>*obj=(T3<int32_t>*)self->data;
                obj->x=val_to_c<decltype(obj->x)>::f(ctx,value);
            } else if(keyStr=="y")
            {
                T3<int32_t>*obj=(T3<int32_t>*)self->data;
                obj->y=val_to_c<decltype(obj->y)>::f(ctx,value);
            } else if(keyStr=="z")
            {
                T3<int32_t>*obj=(T3<int32_t>*)self->data;
                obj->z=val_to_c<decltype(obj->z)>::f(ctx,value);
            } else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member or member if read-only."));
        }
    }
}

scripting::Value *Int3_setYZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::setYZX expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::setYZX expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYZX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::setYZX."));
    return scripting::createNil();
}

scripting::Value *Int3_getZXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::getZXY expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::getZXY expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::getZXY."));
    return scripting::createNil();
}

scripting::Value *Int3_setYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::setYZ expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::setYZ expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setYZ(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::setYZ."));
    return scripting::createNil();
}

scripting::Value *Int3_setYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::setYX expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::setYX expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setYX(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::setYX."));
    return scripting::createNil();
}

scripting::Value *Int3_setZYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::setZYX expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::setZYX expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZYX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::setZYX."));
    return scripting::createNil();
}

scripting::Value *Int3_getZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::getZY expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::getZY expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getZY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::getZY."));
    return scripting::createNil();
}

scripting::Value *Int3_distanceSquared(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::distanceSquared expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::distanceSquared expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->distanceSquared(val_to_c<const T3<float> &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::distanceSquared."));
    return scripting::createNil();
}

scripting::Value *Int3_normalize(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::normalize expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::normalize expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->normalize());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::normalize."));
    return scripting::createNil();
}

scripting::Value *Int3_getYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::getYX expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::getYX expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::getYX."));
    return scripting::createNil();
}

scripting::Value *Int3___leq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::__leq__ expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::__leq__ expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self <= val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::__leq__."));
    return scripting::createNil();
}

scripting::Value *Int3_setXZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::setXZY expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::setXZY expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXZY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::setXZY."));
    return scripting::createNil();
}

scripting::Value *Int3_sum(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::sum expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::sum expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->sum());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::sum."));
    return scripting::createNil();
}

scripting::Value *Int3_cross(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::cross expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::cross expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx,  self->cross(val_to_c<const T3<float> &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::cross."));
    return scripting::createNil();
}

scripting::Value *Int3_getXYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::getXYZ expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::getXYZ expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXYZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::getXYZ."));
    return scripting::createNil();
}

scripting::Value *Int3___less__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::__less__ expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::__less__ expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self < val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::__less__."));
    return scripting::createNil();
}

scripting::Value *Int3___neq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::__neq__ expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::__neq__ expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self != val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::__neq__."));
    return scripting::createNil();
}

scripting::Value *Int3_getYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::getYZ expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::getYZ expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getYZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::getYZ."));
    return scripting::createNil();
}

scripting::Value *Int3_lengthSquared(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::lengthSquared expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::lengthSquared expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->lengthSquared());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::lengthSquared."));
    return scripting::createNil();
}

scripting::Value *Int3_getZYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::getZYX expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::getZYX expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::getZYX."));
    return scripting::createNil();
}

scripting::Value *Int3___div__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::__div__ expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::__div__ expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self / val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self / val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::__div__."));
    return scripting::createNil();
}

scripting::Value *Int3_setZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::setZY expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::setZY expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setZY(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::setZY."));
    return scripting::createNil();
}

scripting::Value *Int3_setZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::setZX expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::setZX expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setZX(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::setZX."));
    return scripting::createNil();
}

scripting::Value *Int3_setXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::setXY expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::setXY expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setXY(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::setXY."));
    return scripting::createNil();
}

scripting::Value *Int3___add__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::__add__ expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::__add__ expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self + val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self + val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::__add__."));
    return scripting::createNil();
}

scripting::Value *Int3_setXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::setXZ expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::setXZ expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setXZ(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::setXZ."));
    return scripting::createNil();
}

scripting::Value *Int3___eq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::__eq__ expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::__eq__ expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self == val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::__eq__."));
    return scripting::createNil();
}

scripting::Value *Int3_setZXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::setZXY expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::setZXY expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZXY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::setZXY."));
    return scripting::createNil();
}

scripting::Value *Int3_setYXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::setYXZ expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::setYXZ expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYXZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::setYXZ."));
    return scripting::createNil();
}

scripting::Value *Int3_getXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::getXY expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::getXY expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::getXY."));
    return scripting::createNil();
}

scripting::Value *Int3_distance(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::distance expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::distance expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->distance(val_to_c<const T3<float> &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::distance."));
    return scripting::createNil();
}

scripting::Value *Int3_getXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::getXZ expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::getXZ expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getXZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::getXZ."));
    return scripting::createNil();
}

scripting::Value *Int3___grtr__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::__grtr__ expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::__grtr__ expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self > val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::__grtr__."));
    return scripting::createNil();
}

scripting::Value *Int3_getXZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::getXZY expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::getXZY expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXZY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::getXZY."));
    return scripting::createNil();
}

scripting::Value *Int3_setXYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::setXYZ expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::setXYZ expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXYZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::setXYZ."));
    return scripting::createNil();
}

scripting::Value *Int3_getYZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::getYZX expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::getYZX expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYZX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::getYZX."));
    return scripting::createNil();
}

scripting::Value *Int3_length(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::length expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::length expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->length());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::length."));
    return scripting::createNil();
}

scripting::Value *Int3___mul__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::__mul__ expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::__mul__ expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self * val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self * val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::__mul__."));
    return scripting::createNil();
}

scripting::Value *Int3_getYXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::getYXZ expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::getYXZ expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYXZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::getYXZ."));
    return scripting::createNil();
}

scripting::Value *Int3_getZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::getZX expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::getZX expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getZX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::getZX."));
    return scripting::createNil();
}

scripting::Value *Int3___sub__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::__sub__ expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::__sub__ expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self - val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self - val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::__sub__."));
    return scripting::createNil();
}

scripting::Value *Int3___geq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::__geq__ expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::__geq__ expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self >= val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::__geq__."));
    return scripting::createNil();
}

scripting::Value *Int3_dot(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::dot expects at least one argument."));
    T3<int32_t>*self;
    if(!type_same<T3<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3::dot expects Int3 as first argument."));
    else
         self=(T3<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->dot(val_to_c<const T3<float> &>::f(ctx,args[1])));
            ;
        }
    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->dot());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int3::dot."));
    return scripting::createNil();
}

scripting::Value *Float2_copy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(Float2_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(Float2_funcs,NEW(T2<float>,*((T2<float>*)self->data)),self->typeID);
}

void Float2_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<T2<float>>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::__del__ expects Float2 as first argument."));

    DELETE(T2<float>,(T2<float> *)self->data);
}scripting::Value *Float2_new(scripting::Context*ctx,const List<scripting::Value *>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2's constructor expects at least one argument."));
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2's constructor expects Float2 as first argument."));
    if(args.getCount()==1)
        if(true)
            return scripting::createNativeObject(Float2_funcs,NEW(Float2),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float2_typeID);
    if(args.getCount()==2)
        if(true&&type_same<float>::f(ctx,args[1]))
            return scripting::createNativeObject(Float2_funcs,NEW(Float2,val_to_c<float>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float2_typeID);
    if(args.getCount()==3)
        if(true&&type_same<float>::f(ctx,args[1])&&type_same<float>::f(ctx,args[2]))
            return scripting::createNativeObject(Float2_funcs,NEW(Float2,val_to_c<float>::f(ctx,args[1]),val_to_c<float>::f(ctx,args[2])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float2_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T2<float> &>::f(ctx,args[1]))
            return scripting::createNativeObject(Float2_funcs,NEW(Float2,val_to_c<const T2<float> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float2_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T2<int32_t> &>::f(ctx,args[1]))
            return scripting::createNativeObject(Float2_funcs,NEW(Float2,val_to_c<const T2<int32_t> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float2_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T2<uint32_t> &>::f(ctx,args[1]))
            return scripting::createNativeObject(Float2_funcs,NEW(Float2,val_to_c<const T2<uint32_t> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float2_typeID);
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2's constructor."));
    return scripting::createNil();
}

scripting::Value *Float2_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
            if(keyStr=="__typeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__name__")
                return scripting::createString("Float2");
            else if(keyStr=="__new__")
                return scripting::createNativeFunction(Float2_new);
            else if(keyStr=="__call__")
                return scripting::createNativeFunction(Float2_new);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
            if(keyStr=="__classTypeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__init__")
                return scripting::createNativeFunction(Float2_new);
             else if (keyStr == "__add__")
                return scripting::createNativeFunction(Float2___add__);
             else if (keyStr == "__sub__")
                return scripting::createNativeFunction(Float2___sub__);
             else if (keyStr == "__mul__")
                return scripting::createNativeFunction(Float2___mul__);
             else if (keyStr == "__div__")
                return scripting::createNativeFunction(Float2___div__);
             else if (keyStr == "__eq__")
                return scripting::createNativeFunction(Float2___eq__);
             else if (keyStr == "__neq__")
                return scripting::createNativeFunction(Float2___neq__);
             else if (keyStr == "__less__")
                return scripting::createNativeFunction(Float2___less__);
             else if (keyStr == "__grtr__")
                return scripting::createNativeFunction(Float2___grtr__);
             else if (keyStr == "__leq__")
                return scripting::createNativeFunction(Float2___leq__);
             else if (keyStr == "__geq__")
                return scripting::createNativeFunction(Float2___geq__);
             else if (keyStr == "sum")
                return scripting::createNativeFunction(Float2_sum);
             else if (keyStr == "length")
                return scripting::createNativeFunction(Float2_length);
             else if (keyStr == "lengthSquared")
                return scripting::createNativeFunction(Float2_lengthSquared);
             else if (keyStr == "dot")
                return scripting::createNativeFunction(Float2_dot);
             else if (keyStr == "distance")
                return scripting::createNativeFunction(Float2_distance);
             else if (keyStr == "distanceSquared")
                return scripting::createNativeFunction(Float2_distanceSquared);
             else if (keyStr == "normalize")
                return scripting::createNativeFunction(Float2_normalize);
             else if (keyStr == "getXY")
                return scripting::createNativeFunction(Float2_getXY);
             else if (keyStr == "setXY")
                return scripting::createNativeFunction(Float2_setXY);
             else if (keyStr == "getYX")
                return scripting::createNativeFunction(Float2_getYX);
             else if (keyStr == "setYX")
                return scripting::createNativeFunction(Float2_setYX);
             else if(keyStr=="x")
            {
                T2<float>*obj=(T2<float>*)self->data;
                return create_val<decltype(obj->x)>::f(ctx,obj->x);
            } else if(keyStr=="y")
            {
                T2<float>*obj=(T2<float>*)self->data;
                return create_val<decltype(obj->y)>::f(ctx,obj->y);
            } else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        }
    }
    return scripting::createNil();
}

void Float2_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue*)key)->value;
        if(self->data==NULL)
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Native classes are read-only."));
        else
        {
            if(0) {} else if(keyStr=="x")
            {
                T2<float>*obj=(T2<float>*)self->data;
                obj->x=val_to_c<decltype(obj->x)>::f(ctx,value);
            } else if(keyStr=="y")
            {
                T2<float>*obj=(T2<float>*)self->data;
                obj->y=val_to_c<decltype(obj->y)>::f(ctx,value);
            } else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member or member if read-only."));
        }
    }
}

scripting::Value *Float2_normalize(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::normalize expects at least one argument."));
    T2<float>*self;
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::normalize expects Float2 as first argument."));
    else
         self=(T2<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->normalize());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2::normalize."));
    return scripting::createNil();
}

scripting::Value *Float2_distance(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::distance expects at least one argument."));
    T2<float>*self;
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::distance expects Float2 as first argument."));
    else
         self=(T2<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->distance(val_to_c<const T2<float> &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2::distance."));
    return scripting::createNil();
}

scripting::Value *Float2_lengthSquared(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::lengthSquared expects at least one argument."));
    T2<float>*self;
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::lengthSquared expects Float2 as first argument."));
    else
         self=(T2<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->lengthSquared());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2::lengthSquared."));
    return scripting::createNil();
}

scripting::Value *Float2___leq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::__leq__ expects at least one argument."));
    T2<float>*self;
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::__leq__ expects Float2 as first argument."));
    else
         self=(T2<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self <= val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2::__leq__."));
    return scripting::createNil();
}

scripting::Value *Float2_setYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::setYX expects at least one argument."));
    T2<float>*self;
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::setYX expects Float2 as first argument."));
    else
         self=(T2<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setYX(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2::setYX."));
    return scripting::createNil();
}

scripting::Value *Float2___grtr__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::__grtr__ expects at least one argument."));
    T2<float>*self;
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::__grtr__ expects Float2 as first argument."));
    else
         self=(T2<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self > val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2::__grtr__."));
    return scripting::createNil();
}

scripting::Value *Float2_sum(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::sum expects at least one argument."));
    T2<float>*self;
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::sum expects Float2 as first argument."));
    else
         self=(T2<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->sum());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2::sum."));
    return scripting::createNil();
}

scripting::Value *Float2_getXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::getXY expects at least one argument."));
    T2<float>*self;
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::getXY expects Float2 as first argument."));
    else
         self=(T2<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2::getXY."));
    return scripting::createNil();
}

scripting::Value *Float2_length(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::length expects at least one argument."));
    T2<float>*self;
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::length expects Float2 as first argument."));
    else
         self=(T2<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->length());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2::length."));
    return scripting::createNil();
}

scripting::Value *Float2_getYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::getYX expects at least one argument."));
    T2<float>*self;
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::getYX expects Float2 as first argument."));
    else
         self=(T2<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2::getYX."));
    return scripting::createNil();
}

scripting::Value *Float2___div__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::__div__ expects at least one argument."));
    T2<float>*self;
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::__div__ expects Float2 as first argument."));
    else
         self=(T2<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self / val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self / val_to_c<float>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2::__div__."));
    return scripting::createNil();
}

scripting::Value *Float2_setXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::setXY expects at least one argument."));
    T2<float>*self;
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::setXY expects Float2 as first argument."));
    else
         self=(T2<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setXY(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2::setXY."));
    return scripting::createNil();
}

scripting::Value *Float2___mul__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::__mul__ expects at least one argument."));
    T2<float>*self;
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::__mul__ expects Float2 as first argument."));
    else
         self=(T2<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self * val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self * val_to_c<float>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2::__mul__."));
    return scripting::createNil();
}

scripting::Value *Float2___add__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::__add__ expects at least one argument."));
    T2<float>*self;
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::__add__ expects Float2 as first argument."));
    else
         self=(T2<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self + val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self + val_to_c<float>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2::__add__."));
    return scripting::createNil();
}

scripting::Value *Float2___less__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::__less__ expects at least one argument."));
    T2<float>*self;
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::__less__ expects Float2 as first argument."));
    else
         self=(T2<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self < val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2::__less__."));
    return scripting::createNil();
}

scripting::Value *Float2___sub__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::__sub__ expects at least one argument."));
    T2<float>*self;
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::__sub__ expects Float2 as first argument."));
    else
         self=(T2<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self - val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self - val_to_c<float>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2::__sub__."));
    return scripting::createNil();
}

scripting::Value *Float2___geq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::__geq__ expects at least one argument."));
    T2<float>*self;
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::__geq__ expects Float2 as first argument."));
    else
         self=(T2<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self >= val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2::__geq__."));
    return scripting::createNil();
}

scripting::Value *Float2_distanceSquared(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::distanceSquared expects at least one argument."));
    T2<float>*self;
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::distanceSquared expects Float2 as first argument."));
    else
         self=(T2<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->distanceSquared(val_to_c<const T2<float> &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2::distanceSquared."));
    return scripting::createNil();
}

scripting::Value *Float2___eq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::__eq__ expects at least one argument."));
    T2<float>*self;
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::__eq__ expects Float2 as first argument."));
    else
         self=(T2<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self == val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2::__eq__."));
    return scripting::createNil();
}

scripting::Value *Float2_dot(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::dot expects at least one argument."));
    T2<float>*self;
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::dot expects Float2 as first argument."));
    else
         self=(T2<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->dot(val_to_c<const T2<float> &>::f(ctx,args[1])));
            ;
        }
    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->dot());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2::dot."));
    return scripting::createNil();
}

scripting::Value *Float2___neq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::__neq__ expects at least one argument."));
    T2<float>*self;
    if(!type_same<T2<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2::__neq__ expects Float2 as first argument."));
    else
         self=(T2<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self != val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float2::__neq__."));
    return scripting::createNil();
}

scripting::Value *Int4_copy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(Int4_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(Int4_funcs,NEW(T4<int32_t>,*((T4<int32_t>*)self->data)),self->typeID);
}

void Int4_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<T4<int32_t>>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::__del__ expects Int4 as first argument."));

    DELETE(T4<int32_t>,(T4<int32_t> *)self->data);
}scripting::Value *Int4_new(scripting::Context*ctx,const List<scripting::Value *>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4's constructor expects at least one argument."));
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4's constructor expects Int4 as first argument."));
    if(args.getCount()==1)
        if(true)
            return scripting::createNativeObject(Int4_funcs,NEW(Int4),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int4_typeID);
    if(args.getCount()==2)
        if(true&&type_same<float>::f(ctx,args[1]))
            return scripting::createNativeObject(Int4_funcs,NEW(Int4,val_to_c<float>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int4_typeID);
    if(args.getCount()==5)
        if(true&&type_same<float>::f(ctx,args[1])&&type_same<float>::f(ctx,args[2])&&type_same<float>::f(ctx,args[3])&&type_same<float>::f(ctx,args[4]))
            return scripting::createNativeObject(Int4_funcs,NEW(Int4,val_to_c<float>::f(ctx,args[1]),val_to_c<float>::f(ctx,args[2]),val_to_c<float>::f(ctx,args[3]),val_to_c<float>::f(ctx,args[4])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int4_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T4<float> &>::f(ctx,args[1]))
            return scripting::createNativeObject(Int4_funcs,NEW(Int4,val_to_c<const T4<float> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int4_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T4<int32_t> &>::f(ctx,args[1]))
            return scripting::createNativeObject(Int4_funcs,NEW(Int4,val_to_c<const T4<int32_t> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int4_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T4<uint32_t> &>::f(ctx,args[1]))
            return scripting::createNativeObject(Int4_funcs,NEW(Int4,val_to_c<const T4<uint32_t> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int4_typeID);
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4's constructor."));
    return scripting::createNil();
}

scripting::Value *Int4_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
            if(keyStr=="__typeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__name__")
                return scripting::createString("Int4");
            else if(keyStr=="__new__")
                return scripting::createNativeFunction(Int4_new);
            else if(keyStr=="__call__")
                return scripting::createNativeFunction(Int4_new);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
            if(keyStr=="__classTypeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__init__")
                return scripting::createNativeFunction(Int4_new);
             else if (keyStr == "__add__")
                return scripting::createNativeFunction(Int4___add__);
             else if (keyStr == "__sub__")
                return scripting::createNativeFunction(Int4___sub__);
             else if (keyStr == "__mul__")
                return scripting::createNativeFunction(Int4___mul__);
             else if (keyStr == "__div__")
                return scripting::createNativeFunction(Int4___div__);
             else if (keyStr == "__eq__")
                return scripting::createNativeFunction(Int4___eq__);
             else if (keyStr == "__neq__")
                return scripting::createNativeFunction(Int4___neq__);
             else if (keyStr == "__less__")
                return scripting::createNativeFunction(Int4___less__);
             else if (keyStr == "__grtr__")
                return scripting::createNativeFunction(Int4___grtr__);
             else if (keyStr == "__leq__")
                return scripting::createNativeFunction(Int4___leq__);
             else if (keyStr == "__geq__")
                return scripting::createNativeFunction(Int4___geq__);
             else if (keyStr == "sum")
                return scripting::createNativeFunction(Int4_sum);
             else if (keyStr == "length")
                return scripting::createNativeFunction(Int4_length);
             else if (keyStr == "lengthSquared")
                return scripting::createNativeFunction(Int4_lengthSquared);
             else if (keyStr == "dot")
                return scripting::createNativeFunction(Int4_dot);
             else if (keyStr == "distance")
                return scripting::createNativeFunction(Int4_distance);
             else if (keyStr == "distanceSquared")
                return scripting::createNativeFunction(Int4_distanceSquared);
             else if (keyStr == "normalize")
                return scripting::createNativeFunction(Int4_normalize);
             else if (keyStr == "getXY")
                return scripting::createNativeFunction(Int4_getXY);
             else if (keyStr == "setXY")
                return scripting::createNativeFunction(Int4_setXY);
             else if (keyStr == "getXZ")
                return scripting::createNativeFunction(Int4_getXZ);
             else if (keyStr == "setXZ")
                return scripting::createNativeFunction(Int4_setXZ);
             else if (keyStr == "getXW")
                return scripting::createNativeFunction(Int4_getXW);
             else if (keyStr == "setXW")
                return scripting::createNativeFunction(Int4_setXW);
             else if (keyStr == "getYX")
                return scripting::createNativeFunction(Int4_getYX);
             else if (keyStr == "setYX")
                return scripting::createNativeFunction(Int4_setYX);
             else if (keyStr == "getYZ")
                return scripting::createNativeFunction(Int4_getYZ);
             else if (keyStr == "setYZ")
                return scripting::createNativeFunction(Int4_setYZ);
             else if (keyStr == "getYW")
                return scripting::createNativeFunction(Int4_getYW);
             else if (keyStr == "setYW")
                return scripting::createNativeFunction(Int4_setYW);
             else if (keyStr == "getZX")
                return scripting::createNativeFunction(Int4_getZX);
             else if (keyStr == "setZX")
                return scripting::createNativeFunction(Int4_setZX);
             else if (keyStr == "getZY")
                return scripting::createNativeFunction(Int4_getZY);
             else if (keyStr == "setZY")
                return scripting::createNativeFunction(Int4_setZY);
             else if (keyStr == "getZW")
                return scripting::createNativeFunction(Int4_getZW);
             else if (keyStr == "setZW")
                return scripting::createNativeFunction(Int4_setZW);
             else if (keyStr == "getWX")
                return scripting::createNativeFunction(Int4_getWX);
             else if (keyStr == "setWX")
                return scripting::createNativeFunction(Int4_setWX);
             else if (keyStr == "getWY")
                return scripting::createNativeFunction(Int4_getWY);
             else if (keyStr == "setWY")
                return scripting::createNativeFunction(Int4_setWY);
             else if (keyStr == "getWZ")
                return scripting::createNativeFunction(Int4_getWZ);
             else if (keyStr == "setWZ")
                return scripting::createNativeFunction(Int4_setWZ);
             else if (keyStr == "getXYZ")
                return scripting::createNativeFunction(Int4_getXYZ);
             else if (keyStr == "setXYZ")
                return scripting::createNativeFunction(Int4_setXYZ);
             else if (keyStr == "getXYW")
                return scripting::createNativeFunction(Int4_getXYW);
             else if (keyStr == "setXYW")
                return scripting::createNativeFunction(Int4_setXYW);
             else if (keyStr == "getXZY")
                return scripting::createNativeFunction(Int4_getXZY);
             else if (keyStr == "setXZY")
                return scripting::createNativeFunction(Int4_setXZY);
             else if (keyStr == "getXZW")
                return scripting::createNativeFunction(Int4_getXZW);
             else if (keyStr == "setXZW")
                return scripting::createNativeFunction(Int4_setXZW);
             else if (keyStr == "getXWZ")
                return scripting::createNativeFunction(Int4_getXWZ);
             else if (keyStr == "setXWZ")
                return scripting::createNativeFunction(Int4_setXWZ);
             else if (keyStr == "getXWY")
                return scripting::createNativeFunction(Int4_getXWY);
             else if (keyStr == "setXWY")
                return scripting::createNativeFunction(Int4_setXWY);
             else if (keyStr == "getYXZ")
                return scripting::createNativeFunction(Int4_getYXZ);
             else if (keyStr == "setYXZ")
                return scripting::createNativeFunction(Int4_setYXZ);
             else if (keyStr == "getYXW")
                return scripting::createNativeFunction(Int4_getYXW);
             else if (keyStr == "setYXW")
                return scripting::createNativeFunction(Int4_setYXW);
             else if (keyStr == "getYZX")
                return scripting::createNativeFunction(Int4_getYZX);
             else if (keyStr == "setYZX")
                return scripting::createNativeFunction(Int4_setYZX);
             else if (keyStr == "getYZW")
                return scripting::createNativeFunction(Int4_getYZW);
             else if (keyStr == "setYZW")
                return scripting::createNativeFunction(Int4_setYZW);
             else if (keyStr == "getYWZ")
                return scripting::createNativeFunction(Int4_getYWZ);
             else if (keyStr == "setYWZ")
                return scripting::createNativeFunction(Int4_setYWZ);
             else if (keyStr == "getYWX")
                return scripting::createNativeFunction(Int4_getYWX);
             else if (keyStr == "setYWX")
                return scripting::createNativeFunction(Int4_setYWX);
             else if (keyStr == "getZXY")
                return scripting::createNativeFunction(Int4_getZXY);
             else if (keyStr == "setZXY")
                return scripting::createNativeFunction(Int4_setZXY);
             else if (keyStr == "getZXW")
                return scripting::createNativeFunction(Int4_getZXW);
             else if (keyStr == "setZXW")
                return scripting::createNativeFunction(Int4_setZXW);
             else if (keyStr == "getZYX")
                return scripting::createNativeFunction(Int4_getZYX);
             else if (keyStr == "setZYX")
                return scripting::createNativeFunction(Int4_setZYX);
             else if (keyStr == "getZYW")
                return scripting::createNativeFunction(Int4_getZYW);
             else if (keyStr == "setZYW")
                return scripting::createNativeFunction(Int4_setZYW);
             else if (keyStr == "getZWY")
                return scripting::createNativeFunction(Int4_getZWY);
             else if (keyStr == "setZWY")
                return scripting::createNativeFunction(Int4_setZWY);
             else if (keyStr == "getZWX")
                return scripting::createNativeFunction(Int4_getZWX);
             else if (keyStr == "setZWX")
                return scripting::createNativeFunction(Int4_setZWX);
             else if (keyStr == "getWXY")
                return scripting::createNativeFunction(Int4_getWXY);
             else if (keyStr == "setWXY")
                return scripting::createNativeFunction(Int4_setWXY);
             else if (keyStr == "getWXZ")
                return scripting::createNativeFunction(Int4_getWXZ);
             else if (keyStr == "setWXZ")
                return scripting::createNativeFunction(Int4_setWXZ);
             else if (keyStr == "getWYX")
                return scripting::createNativeFunction(Int4_getWYX);
             else if (keyStr == "setWYX")
                return scripting::createNativeFunction(Int4_setWYX);
             else if (keyStr == "getWYZ")
                return scripting::createNativeFunction(Int4_getWYZ);
             else if (keyStr == "setWYZ")
                return scripting::createNativeFunction(Int4_setWYZ);
             else if (keyStr == "getWZY")
                return scripting::createNativeFunction(Int4_getWZY);
             else if (keyStr == "setWZY")
                return scripting::createNativeFunction(Int4_setWZY);
             else if (keyStr == "getWZX")
                return scripting::createNativeFunction(Int4_getWZX);
             else if (keyStr == "setWZX")
                return scripting::createNativeFunction(Int4_setWZX);
             else if (keyStr == "getXYZW")
                return scripting::createNativeFunction(Int4_getXYZW);
             else if (keyStr == "setXYZW")
                return scripting::createNativeFunction(Int4_setXYZW);
             else if (keyStr == "getXYWZ")
                return scripting::createNativeFunction(Int4_getXYWZ);
             else if (keyStr == "setXYWZ")
                return scripting::createNativeFunction(Int4_setXYWZ);
             else if (keyStr == "getXZYW")
                return scripting::createNativeFunction(Int4_getXZYW);
             else if (keyStr == "setXZYW")
                return scripting::createNativeFunction(Int4_setXZYW);
             else if (keyStr == "getXZWY")
                return scripting::createNativeFunction(Int4_getXZWY);
             else if (keyStr == "setXZWY")
                return scripting::createNativeFunction(Int4_setXZWY);
             else if (keyStr == "getXWZY")
                return scripting::createNativeFunction(Int4_getXWZY);
             else if (keyStr == "setXWZY")
                return scripting::createNativeFunction(Int4_setXWZY);
             else if (keyStr == "getXWYZ")
                return scripting::createNativeFunction(Int4_getXWYZ);
             else if (keyStr == "setXWYZ")
                return scripting::createNativeFunction(Int4_setXWYZ);
             else if (keyStr == "getYXZW")
                return scripting::createNativeFunction(Int4_getYXZW);
             else if (keyStr == "setYXZW")
                return scripting::createNativeFunction(Int4_setYXZW);
             else if (keyStr == "getYXWZ")
                return scripting::createNativeFunction(Int4_getYXWZ);
             else if (keyStr == "setYXWZ")
                return scripting::createNativeFunction(Int4_setYXWZ);
             else if (keyStr == "getYZXW")
                return scripting::createNativeFunction(Int4_getYZXW);
             else if (keyStr == "setYZXW")
                return scripting::createNativeFunction(Int4_setYZXW);
             else if (keyStr == "getYZWX")
                return scripting::createNativeFunction(Int4_getYZWX);
             else if (keyStr == "setYZWX")
                return scripting::createNativeFunction(Int4_setYZWX);
             else if (keyStr == "getYWZX")
                return scripting::createNativeFunction(Int4_getYWZX);
             else if (keyStr == "setYWZX")
                return scripting::createNativeFunction(Int4_setYWZX);
             else if (keyStr == "getYWXZ")
                return scripting::createNativeFunction(Int4_getYWXZ);
             else if (keyStr == "setYWXZ")
                return scripting::createNativeFunction(Int4_setYWXZ);
             else if (keyStr == "getZYXW")
                return scripting::createNativeFunction(Int4_getZYXW);
             else if (keyStr == "setZYXW")
                return scripting::createNativeFunction(Int4_setZYXW);
             else if (keyStr == "getZYWX")
                return scripting::createNativeFunction(Int4_getZYWX);
             else if (keyStr == "setZYWX")
                return scripting::createNativeFunction(Int4_setZYWX);
             else if (keyStr == "getZXYW")
                return scripting::createNativeFunction(Int4_getZXYW);
             else if (keyStr == "setZXYW")
                return scripting::createNativeFunction(Int4_setZXYW);
             else if (keyStr == "getZXWY")
                return scripting::createNativeFunction(Int4_getZXWY);
             else if (keyStr == "setZXWY")
                return scripting::createNativeFunction(Int4_setZXWY);
             else if (keyStr == "getZWXY")
                return scripting::createNativeFunction(Int4_getZWXY);
             else if (keyStr == "setZWXY")
                return scripting::createNativeFunction(Int4_setZWXY);
             else if (keyStr == "getZWYX")
                return scripting::createNativeFunction(Int4_getZWYX);
             else if (keyStr == "setZWYX")
                return scripting::createNativeFunction(Int4_setZWYX);
             else if (keyStr == "getWYZX")
                return scripting::createNativeFunction(Int4_getWYZX);
             else if (keyStr == "setWYZX")
                return scripting::createNativeFunction(Int4_setWYZX);
             else if (keyStr == "getWYXZ")
                return scripting::createNativeFunction(Int4_getWYXZ);
             else if (keyStr == "setWYXZ")
                return scripting::createNativeFunction(Int4_setWYXZ);
             else if (keyStr == "getWZYX")
                return scripting::createNativeFunction(Int4_getWZYX);
             else if (keyStr == "setWZYX")
                return scripting::createNativeFunction(Int4_setWZYX);
             else if (keyStr == "getWZXY")
                return scripting::createNativeFunction(Int4_getWZXY);
             else if (keyStr == "setWZXY")
                return scripting::createNativeFunction(Int4_setWZXY);
             else if (keyStr == "getWXZY")
                return scripting::createNativeFunction(Int4_getWXZY);
             else if (keyStr == "setWXZY")
                return scripting::createNativeFunction(Int4_setWXZY);
             else if (keyStr == "getWXYZ")
                return scripting::createNativeFunction(Int4_getWXYZ);
             else if (keyStr == "setWXYZ")
                return scripting::createNativeFunction(Int4_setWXYZ);
             else if(keyStr=="x")
            {
                T4<int32_t>*obj=(T4<int32_t>*)self->data;
                return create_val<decltype(obj->x)>::f(ctx,obj->x);
            } else if(keyStr=="y")
            {
                T4<int32_t>*obj=(T4<int32_t>*)self->data;
                return create_val<decltype(obj->y)>::f(ctx,obj->y);
            } else if(keyStr=="z")
            {
                T4<int32_t>*obj=(T4<int32_t>*)self->data;
                return create_val<decltype(obj->z)>::f(ctx,obj->z);
            } else if(keyStr=="w")
            {
                T4<int32_t>*obj=(T4<int32_t>*)self->data;
                return create_val<decltype(obj->w)>::f(ctx,obj->w);
            } else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        }
    }
    return scripting::createNil();
}

void Int4_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue*)key)->value;
        if(self->data==NULL)
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Native classes are read-only."));
        else
        {
            if(0) {} else if(keyStr=="x")
            {
                T4<int32_t>*obj=(T4<int32_t>*)self->data;
                obj->x=val_to_c<decltype(obj->x)>::f(ctx,value);
            } else if(keyStr=="y")
            {
                T4<int32_t>*obj=(T4<int32_t>*)self->data;
                obj->y=val_to_c<decltype(obj->y)>::f(ctx,value);
            } else if(keyStr=="z")
            {
                T4<int32_t>*obj=(T4<int32_t>*)self->data;
                obj->z=val_to_c<decltype(obj->z)>::f(ctx,value);
            } else if(keyStr=="w")
            {
                T4<int32_t>*obj=(T4<int32_t>*)self->data;
                obj->w=val_to_c<decltype(obj->w)>::f(ctx,value);
            } else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member or member if read-only."));
        }
    }
}

scripting::Value *Int4_setZXYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setZXYW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setZXYW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setZXYW(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setZXYW."));
    return scripting::createNil();
}

scripting::Value *Int4_setWYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setWYZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setWYZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setWYZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setWYZ."));
    return scripting::createNil();
}

scripting::Value *Int4_setWYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setWYX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setWYX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setWYX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setWYX."));
    return scripting::createNil();
}

scripting::Value *Int4_getZWYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getZWYX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getZWYX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getZWYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getZWYX."));
    return scripting::createNil();
}

scripting::Value *Int4_getZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getZW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getZW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getZW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getZW."));
    return scripting::createNil();
}

scripting::Value *Int4_getZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getZY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getZY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getZY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getZY."));
    return scripting::createNil();
}

scripting::Value *Int4_distanceSquared(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::distanceSquared expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::distanceSquared expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->distanceSquared(val_to_c<const T4<float> &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::distanceSquared."));
    return scripting::createNil();
}

scripting::Value *Int4_getYXZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getYXZW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getYXZW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getYXZW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getYXZW."));
    return scripting::createNil();
}

scripting::Value *Int4_setYZWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setYZWX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setYZWX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setYZWX(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setYZWX."));
    return scripting::createNil();
}

scripting::Value *Int4_getYWZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getYWZX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getYWZX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getYWZX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getYWZX."));
    return scripting::createNil();
}

scripting::Value *Int4_getWZXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getWZXY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getWZXY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getWZXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getWZXY."));
    return scripting::createNil();
}

scripting::Value *Int4_getZYXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getZYXW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getZYXW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getZYXW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getZYXW."));
    return scripting::createNil();
}

scripting::Value *Int4_setXWYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setXWYZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setXWYZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setXWYZ(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setXWYZ."));
    return scripting::createNil();
}

scripting::Value *Int4_setZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setZY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setZY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setZY(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setZY."));
    return scripting::createNil();
}

scripting::Value *Int4_setZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setZX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setZX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setZX(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setZX."));
    return scripting::createNil();
}

scripting::Value *Int4_getZXWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getZXWY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getZXWY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getZXWY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getZXWY."));
    return scripting::createNil();
}

scripting::Value *Int4_getXWZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getXWZY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getXWZY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getXWZY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getXWZY."));
    return scripting::createNil();
}

scripting::Value *Int4_setZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setZW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setZW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setZW(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setZW."));
    return scripting::createNil();
}

scripting::Value *Int4_setZYWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setZYWX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setZYWX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setZYWX(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setZYWX."));
    return scripting::createNil();
}

scripting::Value *Int4_getYZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getYZX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getYZX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYZX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getYZX."));
    return scripting::createNil();
}

scripting::Value *Int4_getXYWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getXYWZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getXYWZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getXYWZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getXYWZ."));
    return scripting::createNil();
}

scripting::Value *Int4_setYXZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setYXZW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setYXZW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setYXZW(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setYXZW."));
    return scripting::createNil();
}

scripting::Value *Int4_getWZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getWZY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getWZY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getWZY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getWZY."));
    return scripting::createNil();
}

scripting::Value *Int4_getWZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getWZX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getWZX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getWZX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getWZX."));
    return scripting::createNil();
}

scripting::Value *Int4_getWZYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getWZYX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getWZYX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getWZYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getWZYX."));
    return scripting::createNil();
}

scripting::Value *Int4_setXWZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setXWZY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setXWZY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setXWZY(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setXWZY."));
    return scripting::createNil();
}

scripting::Value *Int4_getZXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getZXY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getZXY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getZXY."));
    return scripting::createNil();
}

scripting::Value *Int4_setWZYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setWZYX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setWZYX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setWZYX(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setWZYX."));
    return scripting::createNil();
}

scripting::Value *Int4_setZYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setZYW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setZYW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZYW(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setZYW."));
    return scripting::createNil();
}

scripting::Value *Int4_setZYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setZYX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setZYX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZYX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setZYX."));
    return scripting::createNil();
}

scripting::Value *Int4_setXZYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setXZYW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setXZYW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setXZYW(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setXZYW."));
    return scripting::createNil();
}

scripting::Value *Int4_getZXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getZXW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getZXW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZXW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getZXW."));
    return scripting::createNil();
}

scripting::Value *Int4_setYZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setYZW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setYZW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYZW(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setYZW."));
    return scripting::createNil();
}

scripting::Value *Int4_getYWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getYWZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getYWZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYWZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getYWZ."));
    return scripting::createNil();
}

scripting::Value *Int4___leq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::__leq__ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::__leq__ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self <= val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::__leq__."));
    return scripting::createNil();
}

scripting::Value *Int4_getYWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getYWX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getYWX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYWX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getYWX."));
    return scripting::createNil();
}

scripting::Value *Int4_sum(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::sum expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::sum expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->sum());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::sum."));
    return scripting::createNil();
}

scripting::Value *Int4_setYZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setYZX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setYZX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYZX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setYZX."));
    return scripting::createNil();
}

scripting::Value *Int4_getXYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getXYZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getXYZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXYZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getXYZ."));
    return scripting::createNil();
}

scripting::Value *Int4_getZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getZX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getZX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getZX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getZX."));
    return scripting::createNil();
}

scripting::Value *Int4_getXYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getXYW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getXYW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXYW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getXYW."));
    return scripting::createNil();
}

scripting::Value *Int4_setYWZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setYWZX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setYWZX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setYWZX(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setYWZX."));
    return scripting::createNil();
}

scripting::Value *Int4_setWXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setWXY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setWXY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setWXY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setWXY."));
    return scripting::createNil();
}

scripting::Value *Int4_setWXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setWXZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setWXZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setWXZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setWXZ."));
    return scripting::createNil();
}

scripting::Value *Int4_setZXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setZXW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setZXW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZXW(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setZXW."));
    return scripting::createNil();
}

scripting::Value *Int4_getXWYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getXWYZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getXWYZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getXWYZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getXWYZ."));
    return scripting::createNil();
}

scripting::Value *Int4_setWYXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setWYXZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setWYXZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setWYXZ(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setWYXZ."));
    return scripting::createNil();
}

scripting::Value *Int4_setZXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setZXY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setZXY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZXY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setZXY."));
    return scripting::createNil();
}

scripting::Value *Int4_getXWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getXWY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getXWY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXWY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getXWY."));
    return scripting::createNil();
}

scripting::Value *Int4_getYXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getYXW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getYXW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYXW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getYXW."));
    return scripting::createNil();
}

scripting::Value *Int4_getYXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getYXZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getYXZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYXZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getYXZ."));
    return scripting::createNil();
}

scripting::Value *Int4_setXYWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setXYWZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setXYWZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setXYWZ(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setXYWZ."));
    return scripting::createNil();
}

scripting::Value *Int4_length(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::length expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::length expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->length());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::length."));
    return scripting::createNil();
}

scripting::Value *Int4_setWXZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setWXZY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setWXZY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setWXZY(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setWXZY."));
    return scripting::createNil();
}

scripting::Value *Int4_getYZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getYZW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getYZW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYZW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getYZW."));
    return scripting::createNil();
}

scripting::Value *Int4_setXWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setXWZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setXWZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXWZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setXWZ."));
    return scripting::createNil();
}

scripting::Value *Int4_setXWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setXWY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setXWY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXWY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setXWY."));
    return scripting::createNil();
}

scripting::Value *Int4_getWYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getWYZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getWYZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getWYZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getWYZ."));
    return scripting::createNil();
}

scripting::Value *Int4_getWYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getWYX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getWYX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getWYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getWYX."));
    return scripting::createNil();
}

scripting::Value *Int4_getZYWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getZYWX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getZYWX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getZYWX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getZYWX."));
    return scripting::createNil();
}

scripting::Value *Int4_getXYZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getXYZW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getXYZW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getXYZW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getXYZW."));
    return scripting::createNil();
}

scripting::Value *Int4_setZWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setZWY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setZWY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZWY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setZWY."));
    return scripting::createNil();
}

scripting::Value *Int4_setZWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setZWX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setZWX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZWX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setZWX."));
    return scripting::createNil();
}

scripting::Value *Int4_setWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setWX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setWX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setWX(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setWX."));
    return scripting::createNil();
}

scripting::Value *Int4_setWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setWY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setWY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setWY(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setWY."));
    return scripting::createNil();
}

scripting::Value *Int4_setWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setWZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setWZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setWZ(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setWZ."));
    return scripting::createNil();
}

scripting::Value *Int4_getZWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getZWY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getZWY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZWY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getZWY."));
    return scripting::createNil();
}

scripting::Value *Int4_getZWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getZWX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getZWX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZWX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getZWX."));
    return scripting::createNil();
}

scripting::Value *Int4_setYXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setYXZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setYXZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYXZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setYXZ."));
    return scripting::createNil();
}

scripting::Value *Int4_setYXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setYXW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setYXW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYXW(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setYXW."));
    return scripting::createNil();
}

scripting::Value *Int4_getXWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getXWZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getXWZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXWZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getXWZ."));
    return scripting::createNil();
}

scripting::Value *Int4_getXZWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getXZWY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getXZWY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getXZWY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getXZWY."));
    return scripting::createNil();
}

scripting::Value *Int4___less__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::__less__ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::__less__ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self < val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::__less__."));
    return scripting::createNil();
}

scripting::Value *Int4_getZYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getZYW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getZYW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZYW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getZYW."));
    return scripting::createNil();
}

scripting::Value *Int4_setWZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setWZY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setWZY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setWZY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setWZY."));
    return scripting::createNil();
}

scripting::Value *Int4_setWZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setWZX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setWZX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setWZX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setWZX."));
    return scripting::createNil();
}

scripting::Value *Int4_setZYXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setZYXW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setZYXW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setZYXW(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setZYXW."));
    return scripting::createNil();
}

scripting::Value *Int4_getYZWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getYZWX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getYZWX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getYZWX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getYZWX."));
    return scripting::createNil();
}

scripting::Value *Int4_getZYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getZYX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getZYX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getZYX."));
    return scripting::createNil();
}

scripting::Value *Int4_getXZYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getXZYW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getXZYW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getXZYW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getXZYW."));
    return scripting::createNil();
}

scripting::Value *Int4_setYXWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setYXWZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setYXWZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setYXWZ(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setYXWZ."));
    return scripting::createNil();
}

scripting::Value *Int4___eq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::__eq__ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::__eq__ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self == val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::__eq__."));
    return scripting::createNil();
}

scripting::Value *Int4_getWYXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getWYXZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getWYXZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getWYXZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getWYXZ."));
    return scripting::createNil();
}

scripting::Value *Int4_distance(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::distance expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::distance expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->distance(val_to_c<const T4<float> &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::distance."));
    return scripting::createNil();
}

scripting::Value *Int4_getXZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getXZW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getXZW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXZW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getXZW."));
    return scripting::createNil();
}

scripting::Value *Int4_setYZXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setYZXW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setYZXW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setYZXW(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setYZXW."));
    return scripting::createNil();
}

scripting::Value *Int4_getZWXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getZWXY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getZWXY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getZWXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getZWXY."));
    return scripting::createNil();
}

scripting::Value *Int4_getXZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getXZY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getXZY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXZY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getXZY."));
    return scripting::createNil();
}

scripting::Value *Int4_getYZXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getYZXW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getYZXW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getYZXW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getYZXW."));
    return scripting::createNil();
}

scripting::Value *Int4_setZWYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setZWYX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setZWYX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setZWYX(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setZWYX."));
    return scripting::createNil();
}

scripting::Value *Int4___sub__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::__sub__ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::__sub__ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self - val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self - val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::__sub__."));
    return scripting::createNil();
}

scripting::Value *Int4_getYXWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getYXWZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getYXWZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getYXWZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getYXWZ."));
    return scripting::createNil();
}

scripting::Value *Int4_setXZWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setXZWY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setXZWY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setXZWY(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setXZWY."));
    return scripting::createNil();
}

scripting::Value *Int4_setYWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setYWZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setYWZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYWZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setYWZ."));
    return scripting::createNil();
}

scripting::Value *Int4_setYWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setYWX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setYWX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYWX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setYWX."));
    return scripting::createNil();
}

scripting::Value *Int4_setYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setYZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setYZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setYZ(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setYZ."));
    return scripting::createNil();
}

scripting::Value *Int4_setYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setYX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setYX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setYX(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setYX."));
    return scripting::createNil();
}

scripting::Value *Int4_setYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setYW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setYW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setYW(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setYW."));
    return scripting::createNil();
}

scripting::Value *Int4_getWXYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getWXYZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getWXYZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getWXYZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getWXYZ."));
    return scripting::createNil();
}

scripting::Value *Int4___neq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::__neq__ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::__neq__ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self != val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::__neq__."));
    return scripting::createNil();
}

scripting::Value *Int4_normalize(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::normalize expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::normalize expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->normalize());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::normalize."));
    return scripting::createNil();
}

scripting::Value *Int4_getYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getYX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getYX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getYX."));
    return scripting::createNil();
}

scripting::Value *Int4_setXZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setXZW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setXZW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXZW(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setXZW."));
    return scripting::createNil();
}

scripting::Value *Int4_setXZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setXZY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setXZY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXZY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setXZY."));
    return scripting::createNil();
}

scripting::Value *Int4_setXYZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setXYZW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setXYZW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setXYZW(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setXYZW."));
    return scripting::createNil();
}

scripting::Value *Int4_getYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getYW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getYW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getYW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getYW."));
    return scripting::createNil();
}

scripting::Value *Int4_setWXYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setWXYZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setWXYZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setWXYZ(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setWXYZ."));
    return scripting::createNil();
}

scripting::Value *Int4_getYWXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getYWXZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getYWXZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getYWXZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getYWXZ."));
    return scripting::createNil();
}

scripting::Value *Int4___mul__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::__mul__ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::__mul__ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self * val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self * val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::__mul__."));
    return scripting::createNil();
}

scripting::Value *Int4_getYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getYZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getYZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getYZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getYZ."));
    return scripting::createNil();
}

scripting::Value *Int4_lengthSquared(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::lengthSquared expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::lengthSquared expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->lengthSquared());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::lengthSquared."));
    return scripting::createNil();
}

scripting::Value *Int4_getWXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getWXY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getWXY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getWXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getWXY."));
    return scripting::createNil();
}

scripting::Value *Int4_getWXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getWXZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getWXZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getWXZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getWXZ."));
    return scripting::createNil();
}

scripting::Value *Int4_getWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getWX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getWX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getWX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getWX."));
    return scripting::createNil();
}

scripting::Value *Int4_getWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getWY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getWY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getWY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getWY."));
    return scripting::createNil();
}

scripting::Value *Int4_getWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getWZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getWZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getWZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getWZ."));
    return scripting::createNil();
}

scripting::Value *Int4_setXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setXY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setXY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setXY(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setXY."));
    return scripting::createNil();
}

scripting::Value *Int4_getZXYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getZXYW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getZXYW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getZXYW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getZXYW."));
    return scripting::createNil();
}

scripting::Value *Int4___add__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::__add__ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::__add__ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self + val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self + val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::__add__."));
    return scripting::createNil();
}

scripting::Value *Int4_setXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setXZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setXZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setXZ(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setXZ."));
    return scripting::createNil();
}

scripting::Value *Int4_getWYZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getWYZX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getWYZX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getWYZX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getWYZX."));
    return scripting::createNil();
}

scripting::Value *Int4_setXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setXW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setXW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setXW(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setXW."));
    return scripting::createNil();
}

scripting::Value *Int4_getWXZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getWXZY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getWXZY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getWXZY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getWXZY."));
    return scripting::createNil();
}

scripting::Value *Int4_getXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getXY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getXY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getXY."));
    return scripting::createNil();
}

scripting::Value *Int4_setZXWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setZXWY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setZXWY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setZXWY(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setZXWY."));
    return scripting::createNil();
}

scripting::Value *Int4_setXYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setXYW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setXYW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXYW(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setXYW."));
    return scripting::createNil();
}

scripting::Value *Int4_getXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getXZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getXZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getXZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getXZ."));
    return scripting::createNil();
}

scripting::Value *Int4_setWZXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setWZXY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setWZXY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setWZXY(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setWZXY."));
    return scripting::createNil();
}

scripting::Value *Int4___grtr__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::__grtr__ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::__grtr__ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self > val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::__grtr__."));
    return scripting::createNil();
}

scripting::Value *Int4_setZWXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setZWXY expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setZWXY expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setZWXY(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setZWXY."));
    return scripting::createNil();
}

scripting::Value *Int4_getXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::getXW expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::getXW expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getXW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::getXW."));
    return scripting::createNil();
}

scripting::Value *Int4_setXYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setXYZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setXYZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXYZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setXYZ."));
    return scripting::createNil();
}

scripting::Value *Int4___div__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::__div__ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::__div__ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self / val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self / val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::__div__."));
    return scripting::createNil();
}

scripting::Value *Int4_setWYZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setWYZX expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setWYZX expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setWYZX(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setWYZX."));
    return scripting::createNil();
}

scripting::Value *Int4_setYWXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::setYWXZ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::setYWXZ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setYWXZ(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::setYWXZ."));
    return scripting::createNil();
}

scripting::Value *Int4___geq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::__geq__ expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::__geq__ expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self >= val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::__geq__."));
    return scripting::createNil();
}

scripting::Value *Int4_dot(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::dot expects at least one argument."));
    T4<int32_t>*self;
    if(!type_same<T4<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4::dot expects Int4 as first argument."));
    else
         self=(T4<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->dot(val_to_c<const T4<float> &>::f(ctx,args[1])));
            ;
        }
    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->dot());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int4::dot."));
    return scripting::createNil();
}

scripting::Value *Float3_copy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(Float3_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(Float3_funcs,NEW(T3<float>,*((T3<float>*)self->data)),self->typeID);
}

void Float3_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<T3<float>>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::__del__ expects Float3 as first argument."));

    DELETE(T3<float>,(T3<float> *)self->data);
}scripting::Value *Float3_new(scripting::Context*ctx,const List<scripting::Value *>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3's constructor expects at least one argument."));
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3's constructor expects Float3 as first argument."));
    if(args.getCount()==1)
        if(true)
            return scripting::createNativeObject(Float3_funcs,NEW(Float3),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float3_typeID);
    if(args.getCount()==2)
        if(true&&type_same<float>::f(ctx,args[1]))
            return scripting::createNativeObject(Float3_funcs,NEW(Float3,val_to_c<float>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float3_typeID);
    if(args.getCount()==4)
        if(true&&type_same<float>::f(ctx,args[1])&&type_same<float>::f(ctx,args[2])&&type_same<float>::f(ctx,args[3]))
            return scripting::createNativeObject(Float3_funcs,NEW(Float3,val_to_c<float>::f(ctx,args[1]),val_to_c<float>::f(ctx,args[2]),val_to_c<float>::f(ctx,args[3])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float3_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T3<float> &>::f(ctx,args[1]))
            return scripting::createNativeObject(Float3_funcs,NEW(Float3,val_to_c<const T3<float> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float3_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T3<int32_t> &>::f(ctx,args[1]))
            return scripting::createNativeObject(Float3_funcs,NEW(Float3,val_to_c<const T3<int32_t> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float3_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T3<uint32_t> &>::f(ctx,args[1]))
            return scripting::createNativeObject(Float3_funcs,NEW(Float3,val_to_c<const T3<uint32_t> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float3_typeID);
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3's constructor."));
    return scripting::createNil();
}

scripting::Value *Float3_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
            if(keyStr=="__typeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__name__")
                return scripting::createString("Float3");
            else if(keyStr=="__new__")
                return scripting::createNativeFunction(Float3_new);
            else if(keyStr=="__call__")
                return scripting::createNativeFunction(Float3_new);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
            if(keyStr=="__classTypeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__init__")
                return scripting::createNativeFunction(Float3_new);
             else if (keyStr == "__add__")
                return scripting::createNativeFunction(Float3___add__);
             else if (keyStr == "__sub__")
                return scripting::createNativeFunction(Float3___sub__);
             else if (keyStr == "__mul__")
                return scripting::createNativeFunction(Float3___mul__);
             else if (keyStr == "__div__")
                return scripting::createNativeFunction(Float3___div__);
             else if (keyStr == "__eq__")
                return scripting::createNativeFunction(Float3___eq__);
             else if (keyStr == "__neq__")
                return scripting::createNativeFunction(Float3___neq__);
             else if (keyStr == "__less__")
                return scripting::createNativeFunction(Float3___less__);
             else if (keyStr == "__grtr__")
                return scripting::createNativeFunction(Float3___grtr__);
             else if (keyStr == "__leq__")
                return scripting::createNativeFunction(Float3___leq__);
             else if (keyStr == "__geq__")
                return scripting::createNativeFunction(Float3___geq__);
             else if (keyStr == "sum")
                return scripting::createNativeFunction(Float3_sum);
             else if (keyStr == "length")
                return scripting::createNativeFunction(Float3_length);
             else if (keyStr == "lengthSquared")
                return scripting::createNativeFunction(Float3_lengthSquared);
             else if (keyStr == "dot")
                return scripting::createNativeFunction(Float3_dot);
             else if (keyStr == "distance")
                return scripting::createNativeFunction(Float3_distance);
             else if (keyStr == "distanceSquared")
                return scripting::createNativeFunction(Float3_distanceSquared);
             else if (keyStr == "normalize")
                return scripting::createNativeFunction(Float3_normalize);
             else if (keyStr == "cross")
                return scripting::createNativeFunction(Float3_cross);
             else if (keyStr == "getXY")
                return scripting::createNativeFunction(Float3_getXY);
             else if (keyStr == "setXY")
                return scripting::createNativeFunction(Float3_setXY);
             else if (keyStr == "getXZ")
                return scripting::createNativeFunction(Float3_getXZ);
             else if (keyStr == "setXZ")
                return scripting::createNativeFunction(Float3_setXZ);
             else if (keyStr == "getYX")
                return scripting::createNativeFunction(Float3_getYX);
             else if (keyStr == "setYX")
                return scripting::createNativeFunction(Float3_setYX);
             else if (keyStr == "getYZ")
                return scripting::createNativeFunction(Float3_getYZ);
             else if (keyStr == "setYZ")
                return scripting::createNativeFunction(Float3_setYZ);
             else if (keyStr == "getZX")
                return scripting::createNativeFunction(Float3_getZX);
             else if (keyStr == "setZX")
                return scripting::createNativeFunction(Float3_setZX);
             else if (keyStr == "getZY")
                return scripting::createNativeFunction(Float3_getZY);
             else if (keyStr == "setZY")
                return scripting::createNativeFunction(Float3_setZY);
             else if (keyStr == "getXYZ")
                return scripting::createNativeFunction(Float3_getXYZ);
             else if (keyStr == "setXYZ")
                return scripting::createNativeFunction(Float3_setXYZ);
             else if (keyStr == "getXZY")
                return scripting::createNativeFunction(Float3_getXZY);
             else if (keyStr == "setXZY")
                return scripting::createNativeFunction(Float3_setXZY);
             else if (keyStr == "getYXZ")
                return scripting::createNativeFunction(Float3_getYXZ);
             else if (keyStr == "setYXZ")
                return scripting::createNativeFunction(Float3_setYXZ);
             else if (keyStr == "getYZX")
                return scripting::createNativeFunction(Float3_getYZX);
             else if (keyStr == "setYZX")
                return scripting::createNativeFunction(Float3_setYZX);
             else if (keyStr == "getZXY")
                return scripting::createNativeFunction(Float3_getZXY);
             else if (keyStr == "setZXY")
                return scripting::createNativeFunction(Float3_setZXY);
             else if (keyStr == "getZYX")
                return scripting::createNativeFunction(Float3_getZYX);
             else if (keyStr == "setZYX")
                return scripting::createNativeFunction(Float3_setZYX);
             else if(keyStr=="x")
            {
                T3<float>*obj=(T3<float>*)self->data;
                return create_val<decltype(obj->x)>::f(ctx,obj->x);
            } else if(keyStr=="y")
            {
                T3<float>*obj=(T3<float>*)self->data;
                return create_val<decltype(obj->y)>::f(ctx,obj->y);
            } else if(keyStr=="z")
            {
                T3<float>*obj=(T3<float>*)self->data;
                return create_val<decltype(obj->z)>::f(ctx,obj->z);
            } else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        }
    }
    return scripting::createNil();
}

void Float3_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue*)key)->value;
        if(self->data==NULL)
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Native classes are read-only."));
        else
        {
            if(0) {} else if(keyStr=="x")
            {
                T3<float>*obj=(T3<float>*)self->data;
                obj->x=val_to_c<decltype(obj->x)>::f(ctx,value);
            } else if(keyStr=="y")
            {
                T3<float>*obj=(T3<float>*)self->data;
                obj->y=val_to_c<decltype(obj->y)>::f(ctx,value);
            } else if(keyStr=="z")
            {
                T3<float>*obj=(T3<float>*)self->data;
                obj->z=val_to_c<decltype(obj->z)>::f(ctx,value);
            } else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member or member if read-only."));
        }
    }
}

scripting::Value *Float3_setYZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::setYZX expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::setYZX expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYZX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::setYZX."));
    return scripting::createNil();
}

scripting::Value *Float3_getZXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::getZXY expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::getZXY expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::getZXY."));
    return scripting::createNil();
}

scripting::Value *Float3_setYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::setYZ expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::setYZ expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setYZ(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::setYZ."));
    return scripting::createNil();
}

scripting::Value *Float3_setYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::setYX expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::setYX expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setYX(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::setYX."));
    return scripting::createNil();
}

scripting::Value *Float3_setZYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::setZYX expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::setZYX expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZYX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::setZYX."));
    return scripting::createNil();
}

scripting::Value *Float3_getZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::getZY expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::getZY expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getZY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::getZY."));
    return scripting::createNil();
}

scripting::Value *Float3_distanceSquared(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::distanceSquared expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::distanceSquared expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->distanceSquared(val_to_c<const T3<float> &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::distanceSquared."));
    return scripting::createNil();
}

scripting::Value *Float3_normalize(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::normalize expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::normalize expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->normalize());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::normalize."));
    return scripting::createNil();
}

scripting::Value *Float3_getYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::getYX expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::getYX expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::getYX."));
    return scripting::createNil();
}

scripting::Value *Float3___leq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::__leq__ expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::__leq__ expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self <= val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::__leq__."));
    return scripting::createNil();
}

scripting::Value *Float3_setXZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::setXZY expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::setXZY expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXZY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::setXZY."));
    return scripting::createNil();
}

scripting::Value *Float3_sum(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::sum expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::sum expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->sum());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::sum."));
    return scripting::createNil();
}

scripting::Value *Float3_cross(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::cross expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::cross expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx,  self->cross(val_to_c<const T3<float> &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::cross."));
    return scripting::createNil();
}

scripting::Value *Float3_getXYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::getXYZ expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::getXYZ expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXYZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::getXYZ."));
    return scripting::createNil();
}

scripting::Value *Float3___less__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::__less__ expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::__less__ expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self < val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::__less__."));
    return scripting::createNil();
}

scripting::Value *Float3___neq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::__neq__ expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::__neq__ expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self != val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::__neq__."));
    return scripting::createNil();
}

scripting::Value *Float3_getYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::getYZ expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::getYZ expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getYZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::getYZ."));
    return scripting::createNil();
}

scripting::Value *Float3_lengthSquared(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::lengthSquared expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::lengthSquared expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->lengthSquared());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::lengthSquared."));
    return scripting::createNil();
}

scripting::Value *Float3_getZYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::getZYX expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::getZYX expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::getZYX."));
    return scripting::createNil();
}

scripting::Value *Float3___div__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::__div__ expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::__div__ expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self / val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self / val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::__div__."));
    return scripting::createNil();
}

scripting::Value *Float3_setZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::setZY expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::setZY expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setZY(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::setZY."));
    return scripting::createNil();
}

scripting::Value *Float3_setZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::setZX expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::setZX expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setZX(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::setZX."));
    return scripting::createNil();
}

scripting::Value *Float3_setXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::setXY expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::setXY expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setXY(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::setXY."));
    return scripting::createNil();
}

scripting::Value *Float3___add__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::__add__ expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::__add__ expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self + val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self + val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::__add__."));
    return scripting::createNil();
}

scripting::Value *Float3_setXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::setXZ expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::setXZ expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setXZ(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::setXZ."));
    return scripting::createNil();
}

scripting::Value *Float3___eq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::__eq__ expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::__eq__ expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self == val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::__eq__."));
    return scripting::createNil();
}

scripting::Value *Float3_setZXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::setZXY expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::setZXY expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZXY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::setZXY."));
    return scripting::createNil();
}

scripting::Value *Float3_setYXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::setYXZ expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::setYXZ expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYXZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::setYXZ."));
    return scripting::createNil();
}

scripting::Value *Float3_getXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::getXY expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::getXY expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::getXY."));
    return scripting::createNil();
}

scripting::Value *Float3_distance(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::distance expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::distance expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->distance(val_to_c<const T3<float> &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::distance."));
    return scripting::createNil();
}

scripting::Value *Float3_getXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::getXZ expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::getXZ expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getXZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::getXZ."));
    return scripting::createNil();
}

scripting::Value *Float3___grtr__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::__grtr__ expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::__grtr__ expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self > val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::__grtr__."));
    return scripting::createNil();
}

scripting::Value *Float3_getXZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::getXZY expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::getXZY expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXZY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::getXZY."));
    return scripting::createNil();
}

scripting::Value *Float3_setXYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::setXYZ expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::setXYZ expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXYZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::setXYZ."));
    return scripting::createNil();
}

scripting::Value *Float3_getYZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::getYZX expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::getYZX expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYZX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::getYZX."));
    return scripting::createNil();
}

scripting::Value *Float3_length(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::length expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::length expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->length());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::length."));
    return scripting::createNil();
}

scripting::Value *Float3___mul__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::__mul__ expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::__mul__ expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self * val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self * val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::__mul__."));
    return scripting::createNil();
}

scripting::Value *Float3_getYXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::getYXZ expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::getYXZ expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYXZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::getYXZ."));
    return scripting::createNil();
}

scripting::Value *Float3_getZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::getZX expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::getZX expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getZX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::getZX."));
    return scripting::createNil();
}

scripting::Value *Float3___sub__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::__sub__ expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::__sub__ expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self - val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T3<float>>::f(ctx, *self - val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::__sub__."));
    return scripting::createNil();
}

scripting::Value *Float3___geq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::__geq__ expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::__geq__ expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self >= val_to_c<const T3<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::__geq__."));
    return scripting::createNil();
}

scripting::Value *Float3_dot(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::dot expects at least one argument."));
    T3<float>*self;
    if(!type_same<T3<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3::dot expects Float3 as first argument."));
    else
         self=(T3<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->dot(val_to_c<const T3<float> &>::f(ctx,args[1])));
            ;
        }
    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->dot());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float3::dot."));
    return scripting::createNil();
}

scripting::Value *Int2_copy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(Int2_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(Int2_funcs,NEW(T2<int32_t>,*((T2<int32_t>*)self->data)),self->typeID);
}

void Int2_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<T2<int32_t>>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::__del__ expects Int2 as first argument."));

    DELETE(T2<int32_t>,(T2<int32_t> *)self->data);
}scripting::Value *Int2_new(scripting::Context*ctx,const List<scripting::Value *>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2's constructor expects at least one argument."));
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2's constructor expects Int2 as first argument."));
    if(args.getCount()==1)
        if(true)
            return scripting::createNativeObject(Int2_funcs,NEW(Int2),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int2_typeID);
    if(args.getCount()==2)
        if(true&&type_same<float>::f(ctx,args[1]))
            return scripting::createNativeObject(Int2_funcs,NEW(Int2,val_to_c<float>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int2_typeID);
    if(args.getCount()==3)
        if(true&&type_same<float>::f(ctx,args[1])&&type_same<float>::f(ctx,args[2]))
            return scripting::createNativeObject(Int2_funcs,NEW(Int2,val_to_c<float>::f(ctx,args[1]),val_to_c<float>::f(ctx,args[2])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int2_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T2<float> &>::f(ctx,args[1]))
            return scripting::createNativeObject(Int2_funcs,NEW(Int2,val_to_c<const T2<float> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int2_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T2<int32_t> &>::f(ctx,args[1]))
            return scripting::createNativeObject(Int2_funcs,NEW(Int2,val_to_c<const T2<int32_t> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int2_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T2<uint32_t> &>::f(ctx,args[1]))
            return scripting::createNativeObject(Int2_funcs,NEW(Int2,val_to_c<const T2<uint32_t> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int2_typeID);
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2's constructor."));
    return scripting::createNil();
}

scripting::Value *Int2_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
            if(keyStr=="__typeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__name__")
                return scripting::createString("Int2");
            else if(keyStr=="__new__")
                return scripting::createNativeFunction(Int2_new);
            else if(keyStr=="__call__")
                return scripting::createNativeFunction(Int2_new);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
            if(keyStr=="__classTypeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__init__")
                return scripting::createNativeFunction(Int2_new);
             else if (keyStr == "__add__")
                return scripting::createNativeFunction(Int2___add__);
             else if (keyStr == "__sub__")
                return scripting::createNativeFunction(Int2___sub__);
             else if (keyStr == "__mul__")
                return scripting::createNativeFunction(Int2___mul__);
             else if (keyStr == "__div__")
                return scripting::createNativeFunction(Int2___div__);
             else if (keyStr == "__eq__")
                return scripting::createNativeFunction(Int2___eq__);
             else if (keyStr == "__neq__")
                return scripting::createNativeFunction(Int2___neq__);
             else if (keyStr == "__less__")
                return scripting::createNativeFunction(Int2___less__);
             else if (keyStr == "__grtr__")
                return scripting::createNativeFunction(Int2___grtr__);
             else if (keyStr == "__leq__")
                return scripting::createNativeFunction(Int2___leq__);
             else if (keyStr == "__geq__")
                return scripting::createNativeFunction(Int2___geq__);
             else if (keyStr == "sum")
                return scripting::createNativeFunction(Int2_sum);
             else if (keyStr == "length")
                return scripting::createNativeFunction(Int2_length);
             else if (keyStr == "lengthSquared")
                return scripting::createNativeFunction(Int2_lengthSquared);
             else if (keyStr == "dot")
                return scripting::createNativeFunction(Int2_dot);
             else if (keyStr == "distance")
                return scripting::createNativeFunction(Int2_distance);
             else if (keyStr == "distanceSquared")
                return scripting::createNativeFunction(Int2_distanceSquared);
             else if (keyStr == "normalize")
                return scripting::createNativeFunction(Int2_normalize);
             else if (keyStr == "getXY")
                return scripting::createNativeFunction(Int2_getXY);
             else if (keyStr == "setXY")
                return scripting::createNativeFunction(Int2_setXY);
             else if (keyStr == "getYX")
                return scripting::createNativeFunction(Int2_getYX);
             else if (keyStr == "setYX")
                return scripting::createNativeFunction(Int2_setYX);
             else if(keyStr=="x")
            {
                T2<int32_t>*obj=(T2<int32_t>*)self->data;
                return create_val<decltype(obj->x)>::f(ctx,obj->x);
            } else if(keyStr=="y")
            {
                T2<int32_t>*obj=(T2<int32_t>*)self->data;
                return create_val<decltype(obj->y)>::f(ctx,obj->y);
            } else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        }
    }
    return scripting::createNil();
}

void Int2_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue*)key)->value;
        if(self->data==NULL)
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Native classes are read-only."));
        else
        {
            if(0) {} else if(keyStr=="x")
            {
                T2<int32_t>*obj=(T2<int32_t>*)self->data;
                obj->x=val_to_c<decltype(obj->x)>::f(ctx,value);
            } else if(keyStr=="y")
            {
                T2<int32_t>*obj=(T2<int32_t>*)self->data;
                obj->y=val_to_c<decltype(obj->y)>::f(ctx,value);
            } else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member or member if read-only."));
        }
    }
}

scripting::Value *Int2_normalize(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::normalize expects at least one argument."));
    T2<int32_t>*self;
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::normalize expects Int2 as first argument."));
    else
         self=(T2<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->normalize());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2::normalize."));
    return scripting::createNil();
}

scripting::Value *Int2_distance(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::distance expects at least one argument."));
    T2<int32_t>*self;
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::distance expects Int2 as first argument."));
    else
         self=(T2<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->distance(val_to_c<const T2<float> &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2::distance."));
    return scripting::createNil();
}

scripting::Value *Int2_lengthSquared(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::lengthSquared expects at least one argument."));
    T2<int32_t>*self;
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::lengthSquared expects Int2 as first argument."));
    else
         self=(T2<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->lengthSquared());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2::lengthSquared."));
    return scripting::createNil();
}

scripting::Value *Int2___leq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::__leq__ expects at least one argument."));
    T2<int32_t>*self;
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::__leq__ expects Int2 as first argument."));
    else
         self=(T2<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self <= val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2::__leq__."));
    return scripting::createNil();
}

scripting::Value *Int2_setYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::setYX expects at least one argument."));
    T2<int32_t>*self;
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::setYX expects Int2 as first argument."));
    else
         self=(T2<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setYX(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2::setYX."));
    return scripting::createNil();
}

scripting::Value *Int2___grtr__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::__grtr__ expects at least one argument."));
    T2<int32_t>*self;
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::__grtr__ expects Int2 as first argument."));
    else
         self=(T2<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self > val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2::__grtr__."));
    return scripting::createNil();
}

scripting::Value *Int2_sum(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::sum expects at least one argument."));
    T2<int32_t>*self;
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::sum expects Int2 as first argument."));
    else
         self=(T2<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->sum());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2::sum."));
    return scripting::createNil();
}

scripting::Value *Int2_getXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::getXY expects at least one argument."));
    T2<int32_t>*self;
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::getXY expects Int2 as first argument."));
    else
         self=(T2<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2::getXY."));
    return scripting::createNil();
}

scripting::Value *Int2_length(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::length expects at least one argument."));
    T2<int32_t>*self;
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::length expects Int2 as first argument."));
    else
         self=(T2<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->length());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2::length."));
    return scripting::createNil();
}

scripting::Value *Int2_getYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::getYX expects at least one argument."));
    T2<int32_t>*self;
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::getYX expects Int2 as first argument."));
    else
         self=(T2<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2::getYX."));
    return scripting::createNil();
}

scripting::Value *Int2___div__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::__div__ expects at least one argument."));
    T2<int32_t>*self;
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::__div__ expects Int2 as first argument."));
    else
         self=(T2<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self / val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self / val_to_c<float>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2::__div__."));
    return scripting::createNil();
}

scripting::Value *Int2_setXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::setXY expects at least one argument."));
    T2<int32_t>*self;
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::setXY expects Int2 as first argument."));
    else
         self=(T2<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setXY(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2::setXY."));
    return scripting::createNil();
}

scripting::Value *Int2___mul__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::__mul__ expects at least one argument."));
    T2<int32_t>*self;
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::__mul__ expects Int2 as first argument."));
    else
         self=(T2<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self * val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self * val_to_c<float>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2::__mul__."));
    return scripting::createNil();
}

scripting::Value *Int2___add__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::__add__ expects at least one argument."));
    T2<int32_t>*self;
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::__add__ expects Int2 as first argument."));
    else
         self=(T2<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self + val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self + val_to_c<float>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2::__add__."));
    return scripting::createNil();
}

scripting::Value *Int2___less__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::__less__ expects at least one argument."));
    T2<int32_t>*self;
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::__less__ expects Int2 as first argument."));
    else
         self=(T2<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self < val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2::__less__."));
    return scripting::createNil();
}

scripting::Value *Int2___sub__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::__sub__ expects at least one argument."));
    T2<int32_t>*self;
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::__sub__ expects Int2 as first argument."));
    else
         self=(T2<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self - val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<T2<float>>::f(ctx, *self - val_to_c<float>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2::__sub__."));
    return scripting::createNil();
}

scripting::Value *Int2___geq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::__geq__ expects at least one argument."));
    T2<int32_t>*self;
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::__geq__ expects Int2 as first argument."));
    else
         self=(T2<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self >= val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2::__geq__."));
    return scripting::createNil();
}

scripting::Value *Int2_distanceSquared(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::distanceSquared expects at least one argument."));
    T2<int32_t>*self;
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::distanceSquared expects Int2 as first argument."));
    else
         self=(T2<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->distanceSquared(val_to_c<const T2<float> &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2::distanceSquared."));
    return scripting::createNil();
}

scripting::Value *Int2___eq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::__eq__ expects at least one argument."));
    T2<int32_t>*self;
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::__eq__ expects Int2 as first argument."));
    else
         self=(T2<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self == val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2::__eq__."));
    return scripting::createNil();
}

scripting::Value *Int2_dot(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::dot expects at least one argument."));
    T2<int32_t>*self;
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::dot expects Int2 as first argument."));
    else
         self=(T2<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->dot(val_to_c<const T2<float> &>::f(ctx,args[1])));
            ;
        }
    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->dot());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2::dot."));
    return scripting::createNil();
}

scripting::Value *Int2___neq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::__neq__ expects at least one argument."));
    T2<int32_t>*self;
    if(!type_same<T2<int32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2::__neq__ expects Int2 as first argument."));
    else
         self=(T2<int32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self != val_to_c<const T2<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Int2::__neq__."));
    return scripting::createNil();
}

scripting::Value *Float4_copy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(Float4_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(Float4_funcs,NEW(T4<float>,*((T4<float>*)self->data)),self->typeID);
}

void Float4_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<T4<float>>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::__del__ expects Float4 as first argument."));

    DELETE(T4<float>,(T4<float> *)self->data);
}scripting::Value *Float4_new(scripting::Context*ctx,const List<scripting::Value *>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4's constructor expects at least one argument."));
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4's constructor expects Float4 as first argument."));
    if(args.getCount()==1)
        if(true)
            return scripting::createNativeObject(Float4_funcs,NEW(Float4),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float4_typeID);
    if(args.getCount()==2)
        if(true&&type_same<float>::f(ctx,args[1]))
            return scripting::createNativeObject(Float4_funcs,NEW(Float4,val_to_c<float>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float4_typeID);
    if(args.getCount()==5)
        if(true&&type_same<float>::f(ctx,args[1])&&type_same<float>::f(ctx,args[2])&&type_same<float>::f(ctx,args[3])&&type_same<float>::f(ctx,args[4]))
            return scripting::createNativeObject(Float4_funcs,NEW(Float4,val_to_c<float>::f(ctx,args[1]),val_to_c<float>::f(ctx,args[2]),val_to_c<float>::f(ctx,args[3]),val_to_c<float>::f(ctx,args[4])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float4_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T4<float> &>::f(ctx,args[1]))
            return scripting::createNativeObject(Float4_funcs,NEW(Float4,val_to_c<const T4<float> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float4_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T4<int32_t> &>::f(ctx,args[1]))
            return scripting::createNativeObject(Float4_funcs,NEW(Float4,val_to_c<const T4<int32_t> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float4_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T4<uint32_t> &>::f(ctx,args[1]))
            return scripting::createNativeObject(Float4_funcs,NEW(Float4,val_to_c<const T4<uint32_t> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float4_typeID);
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4's constructor."));
    return scripting::createNil();
}

scripting::Value *Float4_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
            if(keyStr=="__typeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__name__")
                return scripting::createString("Float4");
            else if(keyStr=="__new__")
                return scripting::createNativeFunction(Float4_new);
            else if(keyStr=="__call__")
                return scripting::createNativeFunction(Float4_new);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
            if(keyStr=="__classTypeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__init__")
                return scripting::createNativeFunction(Float4_new);
             else if (keyStr == "__add__")
                return scripting::createNativeFunction(Float4___add__);
             else if (keyStr == "__sub__")
                return scripting::createNativeFunction(Float4___sub__);
             else if (keyStr == "__mul__")
                return scripting::createNativeFunction(Float4___mul__);
             else if (keyStr == "__div__")
                return scripting::createNativeFunction(Float4___div__);
             else if (keyStr == "__eq__")
                return scripting::createNativeFunction(Float4___eq__);
             else if (keyStr == "__neq__")
                return scripting::createNativeFunction(Float4___neq__);
             else if (keyStr == "__less__")
                return scripting::createNativeFunction(Float4___less__);
             else if (keyStr == "__grtr__")
                return scripting::createNativeFunction(Float4___grtr__);
             else if (keyStr == "__leq__")
                return scripting::createNativeFunction(Float4___leq__);
             else if (keyStr == "__geq__")
                return scripting::createNativeFunction(Float4___geq__);
             else if (keyStr == "sum")
                return scripting::createNativeFunction(Float4_sum);
             else if (keyStr == "length")
                return scripting::createNativeFunction(Float4_length);
             else if (keyStr == "lengthSquared")
                return scripting::createNativeFunction(Float4_lengthSquared);
             else if (keyStr == "dot")
                return scripting::createNativeFunction(Float4_dot);
             else if (keyStr == "distance")
                return scripting::createNativeFunction(Float4_distance);
             else if (keyStr == "distanceSquared")
                return scripting::createNativeFunction(Float4_distanceSquared);
             else if (keyStr == "normalize")
                return scripting::createNativeFunction(Float4_normalize);
             else if (keyStr == "getXY")
                return scripting::createNativeFunction(Float4_getXY);
             else if (keyStr == "setXY")
                return scripting::createNativeFunction(Float4_setXY);
             else if (keyStr == "getXZ")
                return scripting::createNativeFunction(Float4_getXZ);
             else if (keyStr == "setXZ")
                return scripting::createNativeFunction(Float4_setXZ);
             else if (keyStr == "getXW")
                return scripting::createNativeFunction(Float4_getXW);
             else if (keyStr == "setXW")
                return scripting::createNativeFunction(Float4_setXW);
             else if (keyStr == "getYX")
                return scripting::createNativeFunction(Float4_getYX);
             else if (keyStr == "setYX")
                return scripting::createNativeFunction(Float4_setYX);
             else if (keyStr == "getYZ")
                return scripting::createNativeFunction(Float4_getYZ);
             else if (keyStr == "setYZ")
                return scripting::createNativeFunction(Float4_setYZ);
             else if (keyStr == "getYW")
                return scripting::createNativeFunction(Float4_getYW);
             else if (keyStr == "setYW")
                return scripting::createNativeFunction(Float4_setYW);
             else if (keyStr == "getZX")
                return scripting::createNativeFunction(Float4_getZX);
             else if (keyStr == "setZX")
                return scripting::createNativeFunction(Float4_setZX);
             else if (keyStr == "getZY")
                return scripting::createNativeFunction(Float4_getZY);
             else if (keyStr == "setZY")
                return scripting::createNativeFunction(Float4_setZY);
             else if (keyStr == "getZW")
                return scripting::createNativeFunction(Float4_getZW);
             else if (keyStr == "setZW")
                return scripting::createNativeFunction(Float4_setZW);
             else if (keyStr == "getWX")
                return scripting::createNativeFunction(Float4_getWX);
             else if (keyStr == "setWX")
                return scripting::createNativeFunction(Float4_setWX);
             else if (keyStr == "getWY")
                return scripting::createNativeFunction(Float4_getWY);
             else if (keyStr == "setWY")
                return scripting::createNativeFunction(Float4_setWY);
             else if (keyStr == "getWZ")
                return scripting::createNativeFunction(Float4_getWZ);
             else if (keyStr == "setWZ")
                return scripting::createNativeFunction(Float4_setWZ);
             else if (keyStr == "getXYZ")
                return scripting::createNativeFunction(Float4_getXYZ);
             else if (keyStr == "setXYZ")
                return scripting::createNativeFunction(Float4_setXYZ);
             else if (keyStr == "getXYW")
                return scripting::createNativeFunction(Float4_getXYW);
             else if (keyStr == "setXYW")
                return scripting::createNativeFunction(Float4_setXYW);
             else if (keyStr == "getXZY")
                return scripting::createNativeFunction(Float4_getXZY);
             else if (keyStr == "setXZY")
                return scripting::createNativeFunction(Float4_setXZY);
             else if (keyStr == "getXZW")
                return scripting::createNativeFunction(Float4_getXZW);
             else if (keyStr == "setXZW")
                return scripting::createNativeFunction(Float4_setXZW);
             else if (keyStr == "getXWZ")
                return scripting::createNativeFunction(Float4_getXWZ);
             else if (keyStr == "setXWZ")
                return scripting::createNativeFunction(Float4_setXWZ);
             else if (keyStr == "getXWY")
                return scripting::createNativeFunction(Float4_getXWY);
             else if (keyStr == "setXWY")
                return scripting::createNativeFunction(Float4_setXWY);
             else if (keyStr == "getYXZ")
                return scripting::createNativeFunction(Float4_getYXZ);
             else if (keyStr == "setYXZ")
                return scripting::createNativeFunction(Float4_setYXZ);
             else if (keyStr == "getYXW")
                return scripting::createNativeFunction(Float4_getYXW);
             else if (keyStr == "setYXW")
                return scripting::createNativeFunction(Float4_setYXW);
             else if (keyStr == "getYZX")
                return scripting::createNativeFunction(Float4_getYZX);
             else if (keyStr == "setYZX")
                return scripting::createNativeFunction(Float4_setYZX);
             else if (keyStr == "getYZW")
                return scripting::createNativeFunction(Float4_getYZW);
             else if (keyStr == "setYZW")
                return scripting::createNativeFunction(Float4_setYZW);
             else if (keyStr == "getYWZ")
                return scripting::createNativeFunction(Float4_getYWZ);
             else if (keyStr == "setYWZ")
                return scripting::createNativeFunction(Float4_setYWZ);
             else if (keyStr == "getYWX")
                return scripting::createNativeFunction(Float4_getYWX);
             else if (keyStr == "setYWX")
                return scripting::createNativeFunction(Float4_setYWX);
             else if (keyStr == "getZXY")
                return scripting::createNativeFunction(Float4_getZXY);
             else if (keyStr == "setZXY")
                return scripting::createNativeFunction(Float4_setZXY);
             else if (keyStr == "getZXW")
                return scripting::createNativeFunction(Float4_getZXW);
             else if (keyStr == "setZXW")
                return scripting::createNativeFunction(Float4_setZXW);
             else if (keyStr == "getZYX")
                return scripting::createNativeFunction(Float4_getZYX);
             else if (keyStr == "setZYX")
                return scripting::createNativeFunction(Float4_setZYX);
             else if (keyStr == "getZYW")
                return scripting::createNativeFunction(Float4_getZYW);
             else if (keyStr == "setZYW")
                return scripting::createNativeFunction(Float4_setZYW);
             else if (keyStr == "getZWY")
                return scripting::createNativeFunction(Float4_getZWY);
             else if (keyStr == "setZWY")
                return scripting::createNativeFunction(Float4_setZWY);
             else if (keyStr == "getZWX")
                return scripting::createNativeFunction(Float4_getZWX);
             else if (keyStr == "setZWX")
                return scripting::createNativeFunction(Float4_setZWX);
             else if (keyStr == "getWXY")
                return scripting::createNativeFunction(Float4_getWXY);
             else if (keyStr == "setWXY")
                return scripting::createNativeFunction(Float4_setWXY);
             else if (keyStr == "getWXZ")
                return scripting::createNativeFunction(Float4_getWXZ);
             else if (keyStr == "setWXZ")
                return scripting::createNativeFunction(Float4_setWXZ);
             else if (keyStr == "getWYX")
                return scripting::createNativeFunction(Float4_getWYX);
             else if (keyStr == "setWYX")
                return scripting::createNativeFunction(Float4_setWYX);
             else if (keyStr == "getWYZ")
                return scripting::createNativeFunction(Float4_getWYZ);
             else if (keyStr == "setWYZ")
                return scripting::createNativeFunction(Float4_setWYZ);
             else if (keyStr == "getWZY")
                return scripting::createNativeFunction(Float4_getWZY);
             else if (keyStr == "setWZY")
                return scripting::createNativeFunction(Float4_setWZY);
             else if (keyStr == "getWZX")
                return scripting::createNativeFunction(Float4_getWZX);
             else if (keyStr == "setWZX")
                return scripting::createNativeFunction(Float4_setWZX);
             else if (keyStr == "getXYZW")
                return scripting::createNativeFunction(Float4_getXYZW);
             else if (keyStr == "setXYZW")
                return scripting::createNativeFunction(Float4_setXYZW);
             else if (keyStr == "getXYWZ")
                return scripting::createNativeFunction(Float4_getXYWZ);
             else if (keyStr == "setXYWZ")
                return scripting::createNativeFunction(Float4_setXYWZ);
             else if (keyStr == "getXZYW")
                return scripting::createNativeFunction(Float4_getXZYW);
             else if (keyStr == "setXZYW")
                return scripting::createNativeFunction(Float4_setXZYW);
             else if (keyStr == "getXZWY")
                return scripting::createNativeFunction(Float4_getXZWY);
             else if (keyStr == "setXZWY")
                return scripting::createNativeFunction(Float4_setXZWY);
             else if (keyStr == "getXWZY")
                return scripting::createNativeFunction(Float4_getXWZY);
             else if (keyStr == "setXWZY")
                return scripting::createNativeFunction(Float4_setXWZY);
             else if (keyStr == "getXWYZ")
                return scripting::createNativeFunction(Float4_getXWYZ);
             else if (keyStr == "setXWYZ")
                return scripting::createNativeFunction(Float4_setXWYZ);
             else if (keyStr == "getYXZW")
                return scripting::createNativeFunction(Float4_getYXZW);
             else if (keyStr == "setYXZW")
                return scripting::createNativeFunction(Float4_setYXZW);
             else if (keyStr == "getYXWZ")
                return scripting::createNativeFunction(Float4_getYXWZ);
             else if (keyStr == "setYXWZ")
                return scripting::createNativeFunction(Float4_setYXWZ);
             else if (keyStr == "getYZXW")
                return scripting::createNativeFunction(Float4_getYZXW);
             else if (keyStr == "setYZXW")
                return scripting::createNativeFunction(Float4_setYZXW);
             else if (keyStr == "getYZWX")
                return scripting::createNativeFunction(Float4_getYZWX);
             else if (keyStr == "setYZWX")
                return scripting::createNativeFunction(Float4_setYZWX);
             else if (keyStr == "getYWZX")
                return scripting::createNativeFunction(Float4_getYWZX);
             else if (keyStr == "setYWZX")
                return scripting::createNativeFunction(Float4_setYWZX);
             else if (keyStr == "getYWXZ")
                return scripting::createNativeFunction(Float4_getYWXZ);
             else if (keyStr == "setYWXZ")
                return scripting::createNativeFunction(Float4_setYWXZ);
             else if (keyStr == "getZYXW")
                return scripting::createNativeFunction(Float4_getZYXW);
             else if (keyStr == "setZYXW")
                return scripting::createNativeFunction(Float4_setZYXW);
             else if (keyStr == "getZYWX")
                return scripting::createNativeFunction(Float4_getZYWX);
             else if (keyStr == "setZYWX")
                return scripting::createNativeFunction(Float4_setZYWX);
             else if (keyStr == "getZXYW")
                return scripting::createNativeFunction(Float4_getZXYW);
             else if (keyStr == "setZXYW")
                return scripting::createNativeFunction(Float4_setZXYW);
             else if (keyStr == "getZXWY")
                return scripting::createNativeFunction(Float4_getZXWY);
             else if (keyStr == "setZXWY")
                return scripting::createNativeFunction(Float4_setZXWY);
             else if (keyStr == "getZWXY")
                return scripting::createNativeFunction(Float4_getZWXY);
             else if (keyStr == "setZWXY")
                return scripting::createNativeFunction(Float4_setZWXY);
             else if (keyStr == "getZWYX")
                return scripting::createNativeFunction(Float4_getZWYX);
             else if (keyStr == "setZWYX")
                return scripting::createNativeFunction(Float4_setZWYX);
             else if (keyStr == "getWYZX")
                return scripting::createNativeFunction(Float4_getWYZX);
             else if (keyStr == "setWYZX")
                return scripting::createNativeFunction(Float4_setWYZX);
             else if (keyStr == "getWYXZ")
                return scripting::createNativeFunction(Float4_getWYXZ);
             else if (keyStr == "setWYXZ")
                return scripting::createNativeFunction(Float4_setWYXZ);
             else if (keyStr == "getWZYX")
                return scripting::createNativeFunction(Float4_getWZYX);
             else if (keyStr == "setWZYX")
                return scripting::createNativeFunction(Float4_setWZYX);
             else if (keyStr == "getWZXY")
                return scripting::createNativeFunction(Float4_getWZXY);
             else if (keyStr == "setWZXY")
                return scripting::createNativeFunction(Float4_setWZXY);
             else if (keyStr == "getWXZY")
                return scripting::createNativeFunction(Float4_getWXZY);
             else if (keyStr == "setWXZY")
                return scripting::createNativeFunction(Float4_setWXZY);
             else if (keyStr == "getWXYZ")
                return scripting::createNativeFunction(Float4_getWXYZ);
             else if (keyStr == "setWXYZ")
                return scripting::createNativeFunction(Float4_setWXYZ);
             else if(keyStr=="x")
            {
                T4<float>*obj=(T4<float>*)self->data;
                return create_val<decltype(obj->x)>::f(ctx,obj->x);
            } else if(keyStr=="y")
            {
                T4<float>*obj=(T4<float>*)self->data;
                return create_val<decltype(obj->y)>::f(ctx,obj->y);
            } else if(keyStr=="z")
            {
                T4<float>*obj=(T4<float>*)self->data;
                return create_val<decltype(obj->z)>::f(ctx,obj->z);
            } else if(keyStr=="w")
            {
                T4<float>*obj=(T4<float>*)self->data;
                return create_val<decltype(obj->w)>::f(ctx,obj->w);
            } else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        }
    }
    return scripting::createNil();
}

void Float4_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue*)key)->value;
        if(self->data==NULL)
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Native classes are read-only."));
        else
        {
            if(0) {} else if(keyStr=="x")
            {
                T4<float>*obj=(T4<float>*)self->data;
                obj->x=val_to_c<decltype(obj->x)>::f(ctx,value);
            } else if(keyStr=="y")
            {
                T4<float>*obj=(T4<float>*)self->data;
                obj->y=val_to_c<decltype(obj->y)>::f(ctx,value);
            } else if(keyStr=="z")
            {
                T4<float>*obj=(T4<float>*)self->data;
                obj->z=val_to_c<decltype(obj->z)>::f(ctx,value);
            } else if(keyStr=="w")
            {
                T4<float>*obj=(T4<float>*)self->data;
                obj->w=val_to_c<decltype(obj->w)>::f(ctx,value);
            } else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member or member if read-only."));
        }
    }
}

scripting::Value *Float4_setZXYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setZXYW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setZXYW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setZXYW(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setZXYW."));
    return scripting::createNil();
}

scripting::Value *Float4_setWYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setWYZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setWYZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setWYZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setWYZ."));
    return scripting::createNil();
}

scripting::Value *Float4_setWYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setWYX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setWYX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setWYX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setWYX."));
    return scripting::createNil();
}

scripting::Value *Float4_getZWYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getZWYX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getZWYX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getZWYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getZWYX."));
    return scripting::createNil();
}

scripting::Value *Float4_getZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getZW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getZW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getZW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getZW."));
    return scripting::createNil();
}

scripting::Value *Float4_getZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getZY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getZY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getZY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getZY."));
    return scripting::createNil();
}

scripting::Value *Float4_distanceSquared(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::distanceSquared expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::distanceSquared expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->distanceSquared(val_to_c<const T4<float> &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::distanceSquared."));
    return scripting::createNil();
}

scripting::Value *Float4_getYXZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getYXZW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getYXZW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getYXZW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getYXZW."));
    return scripting::createNil();
}

scripting::Value *Float4_setYZWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setYZWX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setYZWX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setYZWX(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setYZWX."));
    return scripting::createNil();
}

scripting::Value *Float4_getYWZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getYWZX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getYWZX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getYWZX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getYWZX."));
    return scripting::createNil();
}

scripting::Value *Float4_getWZXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getWZXY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getWZXY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getWZXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getWZXY."));
    return scripting::createNil();
}

scripting::Value *Float4_getZYXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getZYXW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getZYXW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getZYXW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getZYXW."));
    return scripting::createNil();
}

scripting::Value *Float4_setXWYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setXWYZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setXWYZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setXWYZ(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setXWYZ."));
    return scripting::createNil();
}

scripting::Value *Float4_setZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setZY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setZY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setZY(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setZY."));
    return scripting::createNil();
}

scripting::Value *Float4_setZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setZX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setZX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setZX(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setZX."));
    return scripting::createNil();
}

scripting::Value *Float4_getZXWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getZXWY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getZXWY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getZXWY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getZXWY."));
    return scripting::createNil();
}

scripting::Value *Float4_getXWZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getXWZY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getXWZY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getXWZY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getXWZY."));
    return scripting::createNil();
}

scripting::Value *Float4_setZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setZW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setZW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setZW(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setZW."));
    return scripting::createNil();
}

scripting::Value *Float4_setZYWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setZYWX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setZYWX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setZYWX(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setZYWX."));
    return scripting::createNil();
}

scripting::Value *Float4_getYZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getYZX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getYZX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYZX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getYZX."));
    return scripting::createNil();
}

scripting::Value *Float4_getXYWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getXYWZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getXYWZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getXYWZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getXYWZ."));
    return scripting::createNil();
}

scripting::Value *Float4_setYXZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setYXZW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setYXZW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setYXZW(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setYXZW."));
    return scripting::createNil();
}

scripting::Value *Float4_getWZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getWZY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getWZY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getWZY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getWZY."));
    return scripting::createNil();
}

scripting::Value *Float4_getWZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getWZX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getWZX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getWZX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getWZX."));
    return scripting::createNil();
}

scripting::Value *Float4_getWZYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getWZYX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getWZYX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getWZYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getWZYX."));
    return scripting::createNil();
}

scripting::Value *Float4_setXWZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setXWZY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setXWZY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setXWZY(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setXWZY."));
    return scripting::createNil();
}

scripting::Value *Float4_getZXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getZXY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getZXY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getZXY."));
    return scripting::createNil();
}

scripting::Value *Float4_setWZYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setWZYX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setWZYX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setWZYX(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setWZYX."));
    return scripting::createNil();
}

scripting::Value *Float4_setZYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setZYW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setZYW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZYW(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setZYW."));
    return scripting::createNil();
}

scripting::Value *Float4_setZYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setZYX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setZYX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZYX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setZYX."));
    return scripting::createNil();
}

scripting::Value *Float4_setXZYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setXZYW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setXZYW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setXZYW(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setXZYW."));
    return scripting::createNil();
}

scripting::Value *Float4_getZXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getZXW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getZXW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZXW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getZXW."));
    return scripting::createNil();
}

scripting::Value *Float4_setYZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setYZW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setYZW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYZW(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setYZW."));
    return scripting::createNil();
}

scripting::Value *Float4_getYWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getYWZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getYWZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYWZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getYWZ."));
    return scripting::createNil();
}

scripting::Value *Float4___leq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::__leq__ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::__leq__ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self <= val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::__leq__."));
    return scripting::createNil();
}

scripting::Value *Float4_getYWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getYWX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getYWX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYWX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getYWX."));
    return scripting::createNil();
}

scripting::Value *Float4_sum(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::sum expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::sum expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->sum());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::sum."));
    return scripting::createNil();
}

scripting::Value *Float4_setYZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setYZX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setYZX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYZX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setYZX."));
    return scripting::createNil();
}

scripting::Value *Float4_getXYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getXYZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getXYZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXYZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getXYZ."));
    return scripting::createNil();
}

scripting::Value *Float4_getZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getZX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getZX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getZX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getZX."));
    return scripting::createNil();
}

scripting::Value *Float4_getXYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getXYW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getXYW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXYW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getXYW."));
    return scripting::createNil();
}

scripting::Value *Float4_setYWZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setYWZX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setYWZX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setYWZX(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setYWZX."));
    return scripting::createNil();
}

scripting::Value *Float4_setWXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setWXY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setWXY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setWXY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setWXY."));
    return scripting::createNil();
}

scripting::Value *Float4_setWXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setWXZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setWXZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setWXZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setWXZ."));
    return scripting::createNil();
}

scripting::Value *Float4_setZXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setZXW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setZXW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZXW(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setZXW."));
    return scripting::createNil();
}

scripting::Value *Float4_getXWYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getXWYZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getXWYZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getXWYZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getXWYZ."));
    return scripting::createNil();
}

scripting::Value *Float4_setWYXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setWYXZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setWYXZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setWYXZ(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setWYXZ."));
    return scripting::createNil();
}

scripting::Value *Float4_setZXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setZXY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setZXY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZXY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setZXY."));
    return scripting::createNil();
}

scripting::Value *Float4_getXWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getXWY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getXWY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXWY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getXWY."));
    return scripting::createNil();
}

scripting::Value *Float4_getYXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getYXW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getYXW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYXW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getYXW."));
    return scripting::createNil();
}

scripting::Value *Float4_getYXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getYXZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getYXZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYXZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getYXZ."));
    return scripting::createNil();
}

scripting::Value *Float4_setXYWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setXYWZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setXYWZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setXYWZ(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setXYWZ."));
    return scripting::createNil();
}

scripting::Value *Float4_length(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::length expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::length expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->length());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::length."));
    return scripting::createNil();
}

scripting::Value *Float4_setWXZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setWXZY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setWXZY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setWXZY(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setWXZY."));
    return scripting::createNil();
}

scripting::Value *Float4_getYZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getYZW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getYZW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYZW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getYZW."));
    return scripting::createNil();
}

scripting::Value *Float4_setXWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setXWZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setXWZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXWZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setXWZ."));
    return scripting::createNil();
}

scripting::Value *Float4_setXWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setXWY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setXWY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXWY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setXWY."));
    return scripting::createNil();
}

scripting::Value *Float4_getWYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getWYZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getWYZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getWYZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getWYZ."));
    return scripting::createNil();
}

scripting::Value *Float4_getWYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getWYX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getWYX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getWYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getWYX."));
    return scripting::createNil();
}

scripting::Value *Float4_getZYWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getZYWX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getZYWX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getZYWX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getZYWX."));
    return scripting::createNil();
}

scripting::Value *Float4_getXYZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getXYZW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getXYZW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getXYZW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getXYZW."));
    return scripting::createNil();
}

scripting::Value *Float4_setZWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setZWY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setZWY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZWY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setZWY."));
    return scripting::createNil();
}

scripting::Value *Float4_setZWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setZWX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setZWX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZWX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setZWX."));
    return scripting::createNil();
}

scripting::Value *Float4_setWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setWX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setWX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setWX(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setWX."));
    return scripting::createNil();
}

scripting::Value *Float4_setWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setWY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setWY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setWY(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setWY."));
    return scripting::createNil();
}

scripting::Value *Float4_setWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setWZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setWZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setWZ(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setWZ."));
    return scripting::createNil();
}

scripting::Value *Float4_getZWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getZWY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getZWY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZWY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getZWY."));
    return scripting::createNil();
}

scripting::Value *Float4_getZWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getZWX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getZWX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZWX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getZWX."));
    return scripting::createNil();
}

scripting::Value *Float4_setYXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setYXZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setYXZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYXZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setYXZ."));
    return scripting::createNil();
}

scripting::Value *Float4_setYXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setYXW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setYXW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYXW(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setYXW."));
    return scripting::createNil();
}

scripting::Value *Float4_getXWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getXWZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getXWZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXWZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getXWZ."));
    return scripting::createNil();
}

scripting::Value *Float4_getXZWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getXZWY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getXZWY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getXZWY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getXZWY."));
    return scripting::createNil();
}

scripting::Value *Float4___less__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::__less__ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::__less__ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self < val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::__less__."));
    return scripting::createNil();
}

scripting::Value *Float4_getZYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getZYW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getZYW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZYW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getZYW."));
    return scripting::createNil();
}

scripting::Value *Float4_setWZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setWZY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setWZY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setWZY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setWZY."));
    return scripting::createNil();
}

scripting::Value *Float4_setWZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setWZX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setWZX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setWZX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setWZX."));
    return scripting::createNil();
}

scripting::Value *Float4_setZYXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setZYXW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setZYXW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setZYXW(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setZYXW."));
    return scripting::createNil();
}

scripting::Value *Float4_getYZWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getYZWX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getYZWX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getYZWX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getYZWX."));
    return scripting::createNil();
}

scripting::Value *Float4_getZYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getZYX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getZYX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getZYX."));
    return scripting::createNil();
}

scripting::Value *Float4_getXZYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getXZYW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getXZYW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getXZYW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getXZYW."));
    return scripting::createNil();
}

scripting::Value *Float4_setYXWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setYXWZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setYXWZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setYXWZ(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setYXWZ."));
    return scripting::createNil();
}

scripting::Value *Float4___eq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::__eq__ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::__eq__ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self == val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::__eq__."));
    return scripting::createNil();
}

scripting::Value *Float4_getWYXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getWYXZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getWYXZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getWYXZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getWYXZ."));
    return scripting::createNil();
}

scripting::Value *Float4_distance(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::distance expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::distance expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->distance(val_to_c<const T4<float> &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::distance."));
    return scripting::createNil();
}

scripting::Value *Float4_getXZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getXZW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getXZW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXZW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getXZW."));
    return scripting::createNil();
}

scripting::Value *Float4_setYZXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setYZXW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setYZXW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setYZXW(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setYZXW."));
    return scripting::createNil();
}

scripting::Value *Float4_getZWXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getZWXY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getZWXY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getZWXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getZWXY."));
    return scripting::createNil();
}

scripting::Value *Float4_getXZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getXZY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getXZY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXZY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getXZY."));
    return scripting::createNil();
}

scripting::Value *Float4_getYZXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getYZXW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getYZXW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getYZXW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getYZXW."));
    return scripting::createNil();
}

scripting::Value *Float4_setZWYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setZWYX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setZWYX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setZWYX(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setZWYX."));
    return scripting::createNil();
}

scripting::Value *Float4___sub__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::__sub__ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::__sub__ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self - val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self - val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::__sub__."));
    return scripting::createNil();
}

scripting::Value *Float4_getYXWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getYXWZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getYXWZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getYXWZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getYXWZ."));
    return scripting::createNil();
}

scripting::Value *Float4_setXZWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setXZWY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setXZWY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setXZWY(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setXZWY."));
    return scripting::createNil();
}

scripting::Value *Float4_setYWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setYWZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setYWZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYWZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setYWZ."));
    return scripting::createNil();
}

scripting::Value *Float4_setYWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setYWX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setYWX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYWX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setYWX."));
    return scripting::createNil();
}

scripting::Value *Float4_setYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setYZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setYZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setYZ(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setYZ."));
    return scripting::createNil();
}

scripting::Value *Float4_setYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setYX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setYX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setYX(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setYX."));
    return scripting::createNil();
}

scripting::Value *Float4_setYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setYW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setYW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setYW(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setYW."));
    return scripting::createNil();
}

scripting::Value *Float4_getWXYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getWXYZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getWXYZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getWXYZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getWXYZ."));
    return scripting::createNil();
}

scripting::Value *Float4___neq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::__neq__ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::__neq__ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self != val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::__neq__."));
    return scripting::createNil();
}

scripting::Value *Float4_normalize(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::normalize expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::normalize expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->normalize());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::normalize."));
    return scripting::createNil();
}

scripting::Value *Float4_getYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getYX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getYX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getYX."));
    return scripting::createNil();
}

scripting::Value *Float4_setXZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setXZW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setXZW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXZW(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setXZW."));
    return scripting::createNil();
}

scripting::Value *Float4_setXZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setXZY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setXZY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXZY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setXZY."));
    return scripting::createNil();
}

scripting::Value *Float4_setXYZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setXYZW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setXYZW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setXYZW(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setXYZW."));
    return scripting::createNil();
}

scripting::Value *Float4_getYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getYW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getYW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getYW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getYW."));
    return scripting::createNil();
}

scripting::Value *Float4_setWXYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setWXYZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setWXYZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setWXYZ(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setWXYZ."));
    return scripting::createNil();
}

scripting::Value *Float4_getYWXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getYWXZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getYWXZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getYWXZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getYWXZ."));
    return scripting::createNil();
}

scripting::Value *Float4___mul__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::__mul__ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::__mul__ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self * val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self * val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::__mul__."));
    return scripting::createNil();
}

scripting::Value *Float4_getYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getYZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getYZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getYZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getYZ."));
    return scripting::createNil();
}

scripting::Value *Float4_lengthSquared(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::lengthSquared expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::lengthSquared expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->lengthSquared());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::lengthSquared."));
    return scripting::createNil();
}

scripting::Value *Float4_getWXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getWXY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getWXY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getWXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getWXY."));
    return scripting::createNil();
}

scripting::Value *Float4_getWXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getWXZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getWXZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getWXZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getWXZ."));
    return scripting::createNil();
}

scripting::Value *Float4_getWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getWX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getWX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getWX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getWX."));
    return scripting::createNil();
}

scripting::Value *Float4_getWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getWY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getWY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getWY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getWY."));
    return scripting::createNil();
}

scripting::Value *Float4_getWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getWZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getWZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getWZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getWZ."));
    return scripting::createNil();
}

scripting::Value *Float4_setXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setXY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setXY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setXY(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setXY."));
    return scripting::createNil();
}

scripting::Value *Float4_getZXYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getZXYW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getZXYW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getZXYW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getZXYW."));
    return scripting::createNil();
}

scripting::Value *Float4___add__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::__add__ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::__add__ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self + val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self + val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::__add__."));
    return scripting::createNil();
}

scripting::Value *Float4_setXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setXZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setXZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setXZ(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setXZ."));
    return scripting::createNil();
}

scripting::Value *Float4_getWYZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getWYZX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getWYZX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getWYZX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getWYZX."));
    return scripting::createNil();
}

scripting::Value *Float4_setXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setXW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setXW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setXW(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setXW."));
    return scripting::createNil();
}

scripting::Value *Float4_getWXZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getWXZY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getWXZY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getWXZY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getWXZY."));
    return scripting::createNil();
}

scripting::Value *Float4_getXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getXY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getXY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getXY."));
    return scripting::createNil();
}

scripting::Value *Float4_setZXWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setZXWY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setZXWY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setZXWY(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setZXWY."));
    return scripting::createNil();
}

scripting::Value *Float4_setXYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setXYW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setXYW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXYW(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setXYW."));
    return scripting::createNil();
}

scripting::Value *Float4_getXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getXZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getXZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getXZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getXZ."));
    return scripting::createNil();
}

scripting::Value *Float4_setWZXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setWZXY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setWZXY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setWZXY(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setWZXY."));
    return scripting::createNil();
}

scripting::Value *Float4___grtr__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::__grtr__ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::__grtr__ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self > val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::__grtr__."));
    return scripting::createNil();
}

scripting::Value *Float4_setZWXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setZWXY expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setZWXY expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setZWXY(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setZWXY."));
    return scripting::createNil();
}

scripting::Value *Float4_getXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::getXW expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::getXW expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getXW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::getXW."));
    return scripting::createNil();
}

scripting::Value *Float4_setXYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setXYZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setXYZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXYZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setXYZ."));
    return scripting::createNil();
}

scripting::Value *Float4___div__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::__div__ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::__div__ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self / val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self / val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::__div__."));
    return scripting::createNil();
}

scripting::Value *Float4_setWYZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setWYZX expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setWYZX expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setWYZX(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setWYZX."));
    return scripting::createNil();
}

scripting::Value *Float4_setYWXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::setYWXZ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::setYWXZ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setYWXZ(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::setYWXZ."));
    return scripting::createNil();
}

scripting::Value *Float4___geq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::__geq__ expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::__geq__ expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self >= val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::__geq__."));
    return scripting::createNil();
}

scripting::Value *Float4_dot(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::dot expects at least one argument."));
    T4<float>*self;
    if(!type_same<T4<float>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4::dot expects Float4 as first argument."));
    else
         self=(T4<float>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->dot(val_to_c<const T4<float> &>::f(ctx,args[1])));
            ;
        }
    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->dot());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Float4::dot."));
    return scripting::createNil();
}

scripting::Value *Matrix4x4_copy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(Matrix4x4_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(Matrix4x4_funcs,NEW(Matrix4x4,*((Matrix4x4*)self->data)),self->typeID);
}

void Matrix4x4_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<Matrix4x4>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4::__del__ expects Matrix4x4 as first argument."));

    DELETE(Matrix4x4,(Matrix4x4 *)self->data);
}scripting::Value *Matrix4x4_new(scripting::Context*ctx,const List<scripting::Value *>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix4x4's constructor expects at least one argument."));
    if(!type_same<Matrix4x4>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4's constructor expects Matrix4x4 as first argument."));
    if(args.getCount()==1)
        if(true)
            return scripting::createNativeObject(Matrix4x4_funcs,NEW(Matrix4x4),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix4x4_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const Matrix3x3 &>::f(ctx,args[1]))
            return scripting::createNativeObject(Matrix4x4_funcs,NEW(Matrix4x4,val_to_c<const Matrix3x3 &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix4x4_typeID);
    if(args.getCount()==5)
        if(true&&type_same<const Float4 &>::f(ctx,args[1])&&type_same<const Float4 &>::f(ctx,args[2])&&type_same<const Float4 &>::f(ctx,args[3])&&type_same<const Float4 &>::f(ctx,args[4]))
            return scripting::createNativeObject(Matrix4x4_funcs,NEW(Matrix4x4,val_to_c<const Float4 &>::f(ctx,args[1]),val_to_c<const Float4 &>::f(ctx,args[2]),val_to_c<const Float4 &>::f(ctx,args[3]),val_to_c<const Float4 &>::f(ctx,args[4])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix4x4_typeID);
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix4x4's constructor."));
    return scripting::createNil();
}

scripting::Value *Matrix4x4_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
            if(keyStr=="__typeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__name__")
                return scripting::createString("Matrix4x4");
            else if(keyStr=="__new__")
                return scripting::createNativeFunction(Matrix4x4_new);
            else if(keyStr=="__call__")
                return scripting::createNativeFunction(Matrix4x4_new);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
            if(keyStr=="__classTypeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__init__")
                return scripting::createNativeFunction(Matrix4x4_new);
             else if (keyStr == "__mul__")
                return scripting::createNativeFunction(Matrix4x4___mul__);
             else if (keyStr == "__div__")
                return scripting::createNativeFunction(Matrix4x4___div__);
             else if (keyStr == "__eq__")
                return scripting::createNativeFunction(Matrix4x4___eq__);
             else if (keyStr == "transpose")
                return scripting::createNativeFunction(Matrix4x4_transpose);
             else if (keyStr == "inverse")
                return scripting::createNativeFunction(Matrix4x4_inverse);
             else if (keyStr == "translate")
                return scripting::createNativeFunction(Matrix4x4_translate);
             else if (keyStr == "scale")
                return scripting::createNativeFunction(Matrix4x4_scale);
             else if (keyStr == "rotate")
                return scripting::createNativeFunction(Matrix4x4_rotate);
             else if (keyStr == "rotatex")
                return scripting::createNativeFunction(Matrix4x4_rotatex);
             else if (keyStr == "rotatey")
                return scripting::createNativeFunction(Matrix4x4_rotatey);
             else if (keyStr == "rotatez")
                return scripting::createNativeFunction(Matrix4x4_rotatez);
             else if (keyStr == "perspective")
                return scripting::createNativeFunction(Matrix4x4_perspective);
             else if (keyStr == "orthographic")
                return scripting::createNativeFunction(Matrix4x4_orthographic);
             else if (keyStr == "lookAt")
                return scripting::createNativeFunction(Matrix4x4_lookAt);
             else if (keyStr == "lookAtDir")
                return scripting::createNativeFunction(Matrix4x4_lookAtDir);
             else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        }
    }
    return scripting::createNil();
}

void Matrix4x4_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue*)key)->value;
        if(self->data==NULL)
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Native classes are read-only."));
        else
        {
            if(0) {} else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member or member if read-only."));
        }
    }
}

scripting::Value *Matrix4x4_inverse(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix4x4::inverse expects at least one argument."));
    Matrix4x4*self;
    if(!type_same<Matrix4x4>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4::inverse expects Matrix4x4 as first argument."));
    else
         self=(Matrix4x4*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<Matrix4x4>::f(ctx,  self->inverse());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix4x4::inverse."));
    return scripting::createNil();
}

scripting::Value *Matrix4x4_lookAtDir(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix4x4::lookAtDir expects at least one argument."));
    Matrix4x4*self;
    if(!type_same<Matrix4x4>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4::lookAtDir expects Matrix4x4 as first argument."));
    else
         self=(Matrix4x4*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==4)
        if(1&&type_same<const Position3D &>::f(ctx,args[1])&&type_same<const Direction3D &>::f(ctx,args[2])&&type_same<const Direction3D &>::f(ctx,args[3]))
        {
            return create_val<Matrix4x4>::f(ctx,  self->lookAtDir(val_to_c<const Position3D &>::f(ctx,args[1]), val_to_c<const Direction3D &>::f(ctx,args[2]), val_to_c<const Direction3D &>::f(ctx,args[3])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix4x4::lookAtDir."));
    return scripting::createNil();
}

scripting::Value *Matrix4x4_transpose(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix4x4::transpose expects at least one argument."));
    Matrix4x4*self;
    if(!type_same<Matrix4x4>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4::transpose expects Matrix4x4 as first argument."));
    else
         self=(Matrix4x4*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<Matrix4x4>::f(ctx,  self->transpose());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix4x4::transpose."));
    return scripting::createNil();
}

scripting::Value *Matrix4x4_rotatez(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix4x4::rotatez expects at least one argument."));
    Matrix4x4*self;
    if(!type_same<Matrix4x4>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4::rotatez expects Matrix4x4 as first argument."));
    else
         self=(Matrix4x4*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<Matrix4x4>::f(ctx,  self->rotatez(val_to_c<float>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix4x4::rotatez."));
    return scripting::createNil();
}

scripting::Value *Matrix4x4_rotatex(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix4x4::rotatex expects at least one argument."));
    Matrix4x4*self;
    if(!type_same<Matrix4x4>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4::rotatex expects Matrix4x4 as first argument."));
    else
         self=(Matrix4x4*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<Matrix4x4>::f(ctx,  self->rotatex(val_to_c<float>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix4x4::rotatex."));
    return scripting::createNil();
}

scripting::Value *Matrix4x4_rotatey(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix4x4::rotatey expects at least one argument."));
    Matrix4x4*self;
    if(!type_same<Matrix4x4>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4::rotatey expects Matrix4x4 as first argument."));
    else
         self=(Matrix4x4*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<Matrix4x4>::f(ctx,  self->rotatey(val_to_c<float>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix4x4::rotatey."));
    return scripting::createNil();
}

scripting::Value *Matrix4x4___div__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix4x4::__div__ expects at least one argument."));
    Matrix4x4*self;
    if(!type_same<Matrix4x4>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4::__div__ expects Matrix4x4 as first argument."));
    else
         self=(Matrix4x4*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<Matrix4x4>::f(ctx, *self / val_to_c<float>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix4x4::__div__."));
    return scripting::createNil();
}

scripting::Value *Matrix4x4_scale(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix4x4::scale expects at least one argument."));
    Matrix4x4*self;
    if(!type_same<Matrix4x4>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4::scale expects Matrix4x4 as first argument."));
    else
         self=(Matrix4x4*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const Float3 &>::f(ctx,args[1]))
        {
            return create_val<Matrix4x4>::f(ctx,  self->scale(val_to_c<const Float3 &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix4x4::scale."));
    return scripting::createNil();
}

scripting::Value *Matrix4x4_lookAt(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix4x4::lookAt expects at least one argument."));
    Matrix4x4*self;
    if(!type_same<Matrix4x4>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4::lookAt expects Matrix4x4 as first argument."));
    else
         self=(Matrix4x4*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==4)
        if(1&&type_same<const Position3D &>::f(ctx,args[1])&&type_same<const Position3D &>::f(ctx,args[2])&&type_same<const Direction3D &>::f(ctx,args[3]))
        {
            return create_val<Matrix4x4>::f(ctx,  self->lookAt(val_to_c<const Position3D &>::f(ctx,args[1]), val_to_c<const Position3D &>::f(ctx,args[2]), val_to_c<const Direction3D &>::f(ctx,args[3])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix4x4::lookAt."));
    return scripting::createNil();
}

scripting::Value *Matrix4x4___mul__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix4x4::__mul__ expects at least one argument."));
    Matrix4x4*self;
    if(!type_same<Matrix4x4>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4::__mul__ expects Matrix4x4 as first argument."));
    else
         self=(Matrix4x4*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const Matrix4x4 &>::f(ctx,args[1]))
        {
            return create_val<Matrix4x4>::f(ctx, *self * val_to_c<const Matrix4x4 &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const Float4 &>::f(ctx,args[1]))
        {
            return create_val<Float4>::f(ctx, *self * val_to_c<const Float4 &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix4x4::__mul__."));
    return scripting::createNil();
}

scripting::Value *Matrix4x4_orthographic(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix4x4::orthographic expects at least one argument."));
    Matrix4x4*self;
    if(!type_same<Matrix4x4>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4::orthographic expects Matrix4x4 as first argument."));
    else
         self=(Matrix4x4*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==7)
        if(1&&type_same<float>::f(ctx,args[1])&&type_same<float>::f(ctx,args[2])&&type_same<float>::f(ctx,args[3])&&type_same<float>::f(ctx,args[4])&&type_same<float>::f(ctx,args[5])&&type_same<float>::f(ctx,args[6]))
        {
            return create_val<Matrix4x4>::f(ctx,  self->orthographic(val_to_c<float>::f(ctx,args[1]), val_to_c<float>::f(ctx,args[2]), val_to_c<float>::f(ctx,args[3]), val_to_c<float>::f(ctx,args[4]), val_to_c<float>::f(ctx,args[5]), val_to_c<float>::f(ctx,args[6])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix4x4::orthographic."));
    return scripting::createNil();
}

scripting::Value *Matrix4x4_translate(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix4x4::translate expects at least one argument."));
    Matrix4x4*self;
    if(!type_same<Matrix4x4>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4::translate expects Matrix4x4 as first argument."));
    else
         self=(Matrix4x4*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const Float3 &>::f(ctx,args[1]))
        {
            return create_val<Matrix4x4>::f(ctx,  self->translate(val_to_c<const Float3 &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix4x4::translate."));
    return scripting::createNil();
}

scripting::Value *Matrix4x4___eq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix4x4::__eq__ expects at least one argument."));
    Matrix4x4*self;
    if(!type_same<Matrix4x4>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4::__eq__ expects Matrix4x4 as first argument."));
    else
         self=(Matrix4x4*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const Matrix4x4 &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self == val_to_c<const Matrix4x4 &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix4x4::__eq__."));
    return scripting::createNil();
}

scripting::Value *Matrix4x4_rotate(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix4x4::rotate expects at least one argument."));
    Matrix4x4*self;
    if(!type_same<Matrix4x4>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4::rotate expects Matrix4x4 as first argument."));
    else
         self=(Matrix4x4*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<Matrix4x4>::f(ctx,  self->rotate(val_to_c<float>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix4x4::rotate."));
    return scripting::createNil();
}

scripting::Value *Matrix4x4_perspective(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix4x4::perspective expects at least one argument."));
    Matrix4x4*self;
    if(!type_same<Matrix4x4>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4::perspective expects Matrix4x4 as first argument."));
    else
         self=(Matrix4x4*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==5)
        if(1&&type_same<float>::f(ctx,args[1])&&type_same<float>::f(ctx,args[2])&&type_same<float>::f(ctx,args[3])&&type_same<float>::f(ctx,args[4]))
        {
            return create_val<Matrix4x4>::f(ctx,  self->perspective(val_to_c<float>::f(ctx,args[1]), val_to_c<float>::f(ctx,args[2]), val_to_c<float>::f(ctx,args[3]), val_to_c<float>::f(ctx,args[4])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix4x4::perspective."));
    return scripting::createNil();
}

scripting::Value *UInt4_copy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(UInt4_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(UInt4_funcs,NEW(T4<uint32_t>,*((T4<uint32_t>*)self->data)),self->typeID);
}

void UInt4_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<T4<uint32_t>>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::__del__ expects UInt4 as first argument."));

    DELETE(T4<uint32_t>,(T4<uint32_t> *)self->data);
}scripting::Value *UInt4_new(scripting::Context*ctx,const List<scripting::Value *>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4's constructor expects at least one argument."));
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4's constructor expects UInt4 as first argument."));
    if(args.getCount()==1)
        if(true)
            return scripting::createNativeObject(UInt4_funcs,NEW(UInt4),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt4_typeID);
    if(args.getCount()==2)
        if(true&&type_same<float>::f(ctx,args[1]))
            return scripting::createNativeObject(UInt4_funcs,NEW(UInt4,val_to_c<float>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt4_typeID);
    if(args.getCount()==5)
        if(true&&type_same<float>::f(ctx,args[1])&&type_same<float>::f(ctx,args[2])&&type_same<float>::f(ctx,args[3])&&type_same<float>::f(ctx,args[4]))
            return scripting::createNativeObject(UInt4_funcs,NEW(UInt4,val_to_c<float>::f(ctx,args[1]),val_to_c<float>::f(ctx,args[2]),val_to_c<float>::f(ctx,args[3]),val_to_c<float>::f(ctx,args[4])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt4_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T4<float> &>::f(ctx,args[1]))
            return scripting::createNativeObject(UInt4_funcs,NEW(UInt4,val_to_c<const T4<float> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt4_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T4<int32_t> &>::f(ctx,args[1]))
            return scripting::createNativeObject(UInt4_funcs,NEW(UInt4,val_to_c<const T4<int32_t> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt4_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const T4<uint32_t> &>::f(ctx,args[1]))
            return scripting::createNativeObject(UInt4_funcs,NEW(UInt4,val_to_c<const T4<uint32_t> &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt4_typeID);
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4's constructor."));
    return scripting::createNil();
}

scripting::Value *UInt4_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
            if(keyStr=="__typeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__name__")
                return scripting::createString("UInt4");
            else if(keyStr=="__new__")
                return scripting::createNativeFunction(UInt4_new);
            else if(keyStr=="__call__")
                return scripting::createNativeFunction(UInt4_new);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
            if(keyStr=="__classTypeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__init__")
                return scripting::createNativeFunction(UInt4_new);
             else if (keyStr == "__add__")
                return scripting::createNativeFunction(UInt4___add__);
             else if (keyStr == "__sub__")
                return scripting::createNativeFunction(UInt4___sub__);
             else if (keyStr == "__mul__")
                return scripting::createNativeFunction(UInt4___mul__);
             else if (keyStr == "__div__")
                return scripting::createNativeFunction(UInt4___div__);
             else if (keyStr == "__eq__")
                return scripting::createNativeFunction(UInt4___eq__);
             else if (keyStr == "__neq__")
                return scripting::createNativeFunction(UInt4___neq__);
             else if (keyStr == "__less__")
                return scripting::createNativeFunction(UInt4___less__);
             else if (keyStr == "__grtr__")
                return scripting::createNativeFunction(UInt4___grtr__);
             else if (keyStr == "__leq__")
                return scripting::createNativeFunction(UInt4___leq__);
             else if (keyStr == "__geq__")
                return scripting::createNativeFunction(UInt4___geq__);
             else if (keyStr == "sum")
                return scripting::createNativeFunction(UInt4_sum);
             else if (keyStr == "length")
                return scripting::createNativeFunction(UInt4_length);
             else if (keyStr == "lengthSquared")
                return scripting::createNativeFunction(UInt4_lengthSquared);
             else if (keyStr == "dot")
                return scripting::createNativeFunction(UInt4_dot);
             else if (keyStr == "distance")
                return scripting::createNativeFunction(UInt4_distance);
             else if (keyStr == "distanceSquared")
                return scripting::createNativeFunction(UInt4_distanceSquared);
             else if (keyStr == "normalize")
                return scripting::createNativeFunction(UInt4_normalize);
             else if (keyStr == "getXY")
                return scripting::createNativeFunction(UInt4_getXY);
             else if (keyStr == "setXY")
                return scripting::createNativeFunction(UInt4_setXY);
             else if (keyStr == "getXZ")
                return scripting::createNativeFunction(UInt4_getXZ);
             else if (keyStr == "setXZ")
                return scripting::createNativeFunction(UInt4_setXZ);
             else if (keyStr == "getXW")
                return scripting::createNativeFunction(UInt4_getXW);
             else if (keyStr == "setXW")
                return scripting::createNativeFunction(UInt4_setXW);
             else if (keyStr == "getYX")
                return scripting::createNativeFunction(UInt4_getYX);
             else if (keyStr == "setYX")
                return scripting::createNativeFunction(UInt4_setYX);
             else if (keyStr == "getYZ")
                return scripting::createNativeFunction(UInt4_getYZ);
             else if (keyStr == "setYZ")
                return scripting::createNativeFunction(UInt4_setYZ);
             else if (keyStr == "getYW")
                return scripting::createNativeFunction(UInt4_getYW);
             else if (keyStr == "setYW")
                return scripting::createNativeFunction(UInt4_setYW);
             else if (keyStr == "getZX")
                return scripting::createNativeFunction(UInt4_getZX);
             else if (keyStr == "setZX")
                return scripting::createNativeFunction(UInt4_setZX);
             else if (keyStr == "getZY")
                return scripting::createNativeFunction(UInt4_getZY);
             else if (keyStr == "setZY")
                return scripting::createNativeFunction(UInt4_setZY);
             else if (keyStr == "getZW")
                return scripting::createNativeFunction(UInt4_getZW);
             else if (keyStr == "setZW")
                return scripting::createNativeFunction(UInt4_setZW);
             else if (keyStr == "getWX")
                return scripting::createNativeFunction(UInt4_getWX);
             else if (keyStr == "setWX")
                return scripting::createNativeFunction(UInt4_setWX);
             else if (keyStr == "getWY")
                return scripting::createNativeFunction(UInt4_getWY);
             else if (keyStr == "setWY")
                return scripting::createNativeFunction(UInt4_setWY);
             else if (keyStr == "getWZ")
                return scripting::createNativeFunction(UInt4_getWZ);
             else if (keyStr == "setWZ")
                return scripting::createNativeFunction(UInt4_setWZ);
             else if (keyStr == "getXYZ")
                return scripting::createNativeFunction(UInt4_getXYZ);
             else if (keyStr == "setXYZ")
                return scripting::createNativeFunction(UInt4_setXYZ);
             else if (keyStr == "getXYW")
                return scripting::createNativeFunction(UInt4_getXYW);
             else if (keyStr == "setXYW")
                return scripting::createNativeFunction(UInt4_setXYW);
             else if (keyStr == "getXZY")
                return scripting::createNativeFunction(UInt4_getXZY);
             else if (keyStr == "setXZY")
                return scripting::createNativeFunction(UInt4_setXZY);
             else if (keyStr == "getXZW")
                return scripting::createNativeFunction(UInt4_getXZW);
             else if (keyStr == "setXZW")
                return scripting::createNativeFunction(UInt4_setXZW);
             else if (keyStr == "getXWZ")
                return scripting::createNativeFunction(UInt4_getXWZ);
             else if (keyStr == "setXWZ")
                return scripting::createNativeFunction(UInt4_setXWZ);
             else if (keyStr == "getXWY")
                return scripting::createNativeFunction(UInt4_getXWY);
             else if (keyStr == "setXWY")
                return scripting::createNativeFunction(UInt4_setXWY);
             else if (keyStr == "getYXZ")
                return scripting::createNativeFunction(UInt4_getYXZ);
             else if (keyStr == "setYXZ")
                return scripting::createNativeFunction(UInt4_setYXZ);
             else if (keyStr == "getYXW")
                return scripting::createNativeFunction(UInt4_getYXW);
             else if (keyStr == "setYXW")
                return scripting::createNativeFunction(UInt4_setYXW);
             else if (keyStr == "getYZX")
                return scripting::createNativeFunction(UInt4_getYZX);
             else if (keyStr == "setYZX")
                return scripting::createNativeFunction(UInt4_setYZX);
             else if (keyStr == "getYZW")
                return scripting::createNativeFunction(UInt4_getYZW);
             else if (keyStr == "setYZW")
                return scripting::createNativeFunction(UInt4_setYZW);
             else if (keyStr == "getYWZ")
                return scripting::createNativeFunction(UInt4_getYWZ);
             else if (keyStr == "setYWZ")
                return scripting::createNativeFunction(UInt4_setYWZ);
             else if (keyStr == "getYWX")
                return scripting::createNativeFunction(UInt4_getYWX);
             else if (keyStr == "setYWX")
                return scripting::createNativeFunction(UInt4_setYWX);
             else if (keyStr == "getZXY")
                return scripting::createNativeFunction(UInt4_getZXY);
             else if (keyStr == "setZXY")
                return scripting::createNativeFunction(UInt4_setZXY);
             else if (keyStr == "getZXW")
                return scripting::createNativeFunction(UInt4_getZXW);
             else if (keyStr == "setZXW")
                return scripting::createNativeFunction(UInt4_setZXW);
             else if (keyStr == "getZYX")
                return scripting::createNativeFunction(UInt4_getZYX);
             else if (keyStr == "setZYX")
                return scripting::createNativeFunction(UInt4_setZYX);
             else if (keyStr == "getZYW")
                return scripting::createNativeFunction(UInt4_getZYW);
             else if (keyStr == "setZYW")
                return scripting::createNativeFunction(UInt4_setZYW);
             else if (keyStr == "getZWY")
                return scripting::createNativeFunction(UInt4_getZWY);
             else if (keyStr == "setZWY")
                return scripting::createNativeFunction(UInt4_setZWY);
             else if (keyStr == "getZWX")
                return scripting::createNativeFunction(UInt4_getZWX);
             else if (keyStr == "setZWX")
                return scripting::createNativeFunction(UInt4_setZWX);
             else if (keyStr == "getWXY")
                return scripting::createNativeFunction(UInt4_getWXY);
             else if (keyStr == "setWXY")
                return scripting::createNativeFunction(UInt4_setWXY);
             else if (keyStr == "getWXZ")
                return scripting::createNativeFunction(UInt4_getWXZ);
             else if (keyStr == "setWXZ")
                return scripting::createNativeFunction(UInt4_setWXZ);
             else if (keyStr == "getWYX")
                return scripting::createNativeFunction(UInt4_getWYX);
             else if (keyStr == "setWYX")
                return scripting::createNativeFunction(UInt4_setWYX);
             else if (keyStr == "getWYZ")
                return scripting::createNativeFunction(UInt4_getWYZ);
             else if (keyStr == "setWYZ")
                return scripting::createNativeFunction(UInt4_setWYZ);
             else if (keyStr == "getWZY")
                return scripting::createNativeFunction(UInt4_getWZY);
             else if (keyStr == "setWZY")
                return scripting::createNativeFunction(UInt4_setWZY);
             else if (keyStr == "getWZX")
                return scripting::createNativeFunction(UInt4_getWZX);
             else if (keyStr == "setWZX")
                return scripting::createNativeFunction(UInt4_setWZX);
             else if (keyStr == "getXYZW")
                return scripting::createNativeFunction(UInt4_getXYZW);
             else if (keyStr == "setXYZW")
                return scripting::createNativeFunction(UInt4_setXYZW);
             else if (keyStr == "getXYWZ")
                return scripting::createNativeFunction(UInt4_getXYWZ);
             else if (keyStr == "setXYWZ")
                return scripting::createNativeFunction(UInt4_setXYWZ);
             else if (keyStr == "getXZYW")
                return scripting::createNativeFunction(UInt4_getXZYW);
             else if (keyStr == "setXZYW")
                return scripting::createNativeFunction(UInt4_setXZYW);
             else if (keyStr == "getXZWY")
                return scripting::createNativeFunction(UInt4_getXZWY);
             else if (keyStr == "setXZWY")
                return scripting::createNativeFunction(UInt4_setXZWY);
             else if (keyStr == "getXWZY")
                return scripting::createNativeFunction(UInt4_getXWZY);
             else if (keyStr == "setXWZY")
                return scripting::createNativeFunction(UInt4_setXWZY);
             else if (keyStr == "getXWYZ")
                return scripting::createNativeFunction(UInt4_getXWYZ);
             else if (keyStr == "setXWYZ")
                return scripting::createNativeFunction(UInt4_setXWYZ);
             else if (keyStr == "getYXZW")
                return scripting::createNativeFunction(UInt4_getYXZW);
             else if (keyStr == "setYXZW")
                return scripting::createNativeFunction(UInt4_setYXZW);
             else if (keyStr == "getYXWZ")
                return scripting::createNativeFunction(UInt4_getYXWZ);
             else if (keyStr == "setYXWZ")
                return scripting::createNativeFunction(UInt4_setYXWZ);
             else if (keyStr == "getYZXW")
                return scripting::createNativeFunction(UInt4_getYZXW);
             else if (keyStr == "setYZXW")
                return scripting::createNativeFunction(UInt4_setYZXW);
             else if (keyStr == "getYZWX")
                return scripting::createNativeFunction(UInt4_getYZWX);
             else if (keyStr == "setYZWX")
                return scripting::createNativeFunction(UInt4_setYZWX);
             else if (keyStr == "getYWZX")
                return scripting::createNativeFunction(UInt4_getYWZX);
             else if (keyStr == "setYWZX")
                return scripting::createNativeFunction(UInt4_setYWZX);
             else if (keyStr == "getYWXZ")
                return scripting::createNativeFunction(UInt4_getYWXZ);
             else if (keyStr == "setYWXZ")
                return scripting::createNativeFunction(UInt4_setYWXZ);
             else if (keyStr == "getZYXW")
                return scripting::createNativeFunction(UInt4_getZYXW);
             else if (keyStr == "setZYXW")
                return scripting::createNativeFunction(UInt4_setZYXW);
             else if (keyStr == "getZYWX")
                return scripting::createNativeFunction(UInt4_getZYWX);
             else if (keyStr == "setZYWX")
                return scripting::createNativeFunction(UInt4_setZYWX);
             else if (keyStr == "getZXYW")
                return scripting::createNativeFunction(UInt4_getZXYW);
             else if (keyStr == "setZXYW")
                return scripting::createNativeFunction(UInt4_setZXYW);
             else if (keyStr == "getZXWY")
                return scripting::createNativeFunction(UInt4_getZXWY);
             else if (keyStr == "setZXWY")
                return scripting::createNativeFunction(UInt4_setZXWY);
             else if (keyStr == "getZWXY")
                return scripting::createNativeFunction(UInt4_getZWXY);
             else if (keyStr == "setZWXY")
                return scripting::createNativeFunction(UInt4_setZWXY);
             else if (keyStr == "getZWYX")
                return scripting::createNativeFunction(UInt4_getZWYX);
             else if (keyStr == "setZWYX")
                return scripting::createNativeFunction(UInt4_setZWYX);
             else if (keyStr == "getWYZX")
                return scripting::createNativeFunction(UInt4_getWYZX);
             else if (keyStr == "setWYZX")
                return scripting::createNativeFunction(UInt4_setWYZX);
             else if (keyStr == "getWYXZ")
                return scripting::createNativeFunction(UInt4_getWYXZ);
             else if (keyStr == "setWYXZ")
                return scripting::createNativeFunction(UInt4_setWYXZ);
             else if (keyStr == "getWZYX")
                return scripting::createNativeFunction(UInt4_getWZYX);
             else if (keyStr == "setWZYX")
                return scripting::createNativeFunction(UInt4_setWZYX);
             else if (keyStr == "getWZXY")
                return scripting::createNativeFunction(UInt4_getWZXY);
             else if (keyStr == "setWZXY")
                return scripting::createNativeFunction(UInt4_setWZXY);
             else if (keyStr == "getWXZY")
                return scripting::createNativeFunction(UInt4_getWXZY);
             else if (keyStr == "setWXZY")
                return scripting::createNativeFunction(UInt4_setWXZY);
             else if (keyStr == "getWXYZ")
                return scripting::createNativeFunction(UInt4_getWXYZ);
             else if (keyStr == "setWXYZ")
                return scripting::createNativeFunction(UInt4_setWXYZ);
             else if(keyStr=="x")
            {
                T4<uint32_t>*obj=(T4<uint32_t>*)self->data;
                return create_val<decltype(obj->x)>::f(ctx,obj->x);
            } else if(keyStr=="y")
            {
                T4<uint32_t>*obj=(T4<uint32_t>*)self->data;
                return create_val<decltype(obj->y)>::f(ctx,obj->y);
            } else if(keyStr=="z")
            {
                T4<uint32_t>*obj=(T4<uint32_t>*)self->data;
                return create_val<decltype(obj->z)>::f(ctx,obj->z);
            } else if(keyStr=="w")
            {
                T4<uint32_t>*obj=(T4<uint32_t>*)self->data;
                return create_val<decltype(obj->w)>::f(ctx,obj->w);
            } else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        }
    }
    return scripting::createNil();
}

void UInt4_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue*)key)->value;
        if(self->data==NULL)
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Native classes are read-only."));
        else
        {
            if(0) {} else if(keyStr=="x")
            {
                T4<uint32_t>*obj=(T4<uint32_t>*)self->data;
                obj->x=val_to_c<decltype(obj->x)>::f(ctx,value);
            } else if(keyStr=="y")
            {
                T4<uint32_t>*obj=(T4<uint32_t>*)self->data;
                obj->y=val_to_c<decltype(obj->y)>::f(ctx,value);
            } else if(keyStr=="z")
            {
                T4<uint32_t>*obj=(T4<uint32_t>*)self->data;
                obj->z=val_to_c<decltype(obj->z)>::f(ctx,value);
            } else if(keyStr=="w")
            {
                T4<uint32_t>*obj=(T4<uint32_t>*)self->data;
                obj->w=val_to_c<decltype(obj->w)>::f(ctx,value);
            } else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member or member if read-only."));
        }
    }
}

scripting::Value *UInt4_setZXYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setZXYW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setZXYW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setZXYW(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setZXYW."));
    return scripting::createNil();
}

scripting::Value *UInt4_setWYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setWYZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setWYZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setWYZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setWYZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_setWYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setWYX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setWYX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setWYX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setWYX."));
    return scripting::createNil();
}

scripting::Value *UInt4_getZWYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getZWYX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getZWYX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getZWYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getZWYX."));
    return scripting::createNil();
}

scripting::Value *UInt4_getZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getZW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getZW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getZW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getZW."));
    return scripting::createNil();
}

scripting::Value *UInt4_getZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getZY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getZY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getZY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getZY."));
    return scripting::createNil();
}

scripting::Value *UInt4_distanceSquared(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::distanceSquared expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::distanceSquared expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->distanceSquared(val_to_c<const T4<float> &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::distanceSquared."));
    return scripting::createNil();
}

scripting::Value *UInt4_getYXZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getYXZW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getYXZW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getYXZW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getYXZW."));
    return scripting::createNil();
}

scripting::Value *UInt4_setYZWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setYZWX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setYZWX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setYZWX(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setYZWX."));
    return scripting::createNil();
}

scripting::Value *UInt4_getYWZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getYWZX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getYWZX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getYWZX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getYWZX."));
    return scripting::createNil();
}

scripting::Value *UInt4_getWZXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getWZXY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getWZXY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getWZXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getWZXY."));
    return scripting::createNil();
}

scripting::Value *UInt4_getZYXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getZYXW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getZYXW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getZYXW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getZYXW."));
    return scripting::createNil();
}

scripting::Value *UInt4_setXWYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setXWYZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setXWYZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setXWYZ(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setXWYZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_setZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setZY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setZY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setZY(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setZY."));
    return scripting::createNil();
}

scripting::Value *UInt4_setZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setZX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setZX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setZX(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setZX."));
    return scripting::createNil();
}

scripting::Value *UInt4_getZXWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getZXWY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getZXWY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getZXWY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getZXWY."));
    return scripting::createNil();
}

scripting::Value *UInt4_getXWZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getXWZY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getXWZY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getXWZY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getXWZY."));
    return scripting::createNil();
}

scripting::Value *UInt4_setZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setZW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setZW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setZW(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setZW."));
    return scripting::createNil();
}

scripting::Value *UInt4_setZYWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setZYWX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setZYWX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setZYWX(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setZYWX."));
    return scripting::createNil();
}

scripting::Value *UInt4_getYZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getYZX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getYZX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYZX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getYZX."));
    return scripting::createNil();
}

scripting::Value *UInt4_getXYWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getXYWZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getXYWZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getXYWZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getXYWZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_setYXZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setYXZW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setYXZW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setYXZW(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setYXZW."));
    return scripting::createNil();
}

scripting::Value *UInt4_getWZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getWZY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getWZY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getWZY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getWZY."));
    return scripting::createNil();
}

scripting::Value *UInt4_getWZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getWZX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getWZX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getWZX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getWZX."));
    return scripting::createNil();
}

scripting::Value *UInt4_getWZYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getWZYX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getWZYX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getWZYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getWZYX."));
    return scripting::createNil();
}

scripting::Value *UInt4_setXWZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setXWZY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setXWZY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setXWZY(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setXWZY."));
    return scripting::createNil();
}

scripting::Value *UInt4_getZXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getZXY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getZXY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getZXY."));
    return scripting::createNil();
}

scripting::Value *UInt4_setWZYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setWZYX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setWZYX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setWZYX(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setWZYX."));
    return scripting::createNil();
}

scripting::Value *UInt4_setZYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setZYW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setZYW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZYW(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setZYW."));
    return scripting::createNil();
}

scripting::Value *UInt4_setZYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setZYX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setZYX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZYX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setZYX."));
    return scripting::createNil();
}

scripting::Value *UInt4_setXZYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setXZYW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setXZYW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setXZYW(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setXZYW."));
    return scripting::createNil();
}

scripting::Value *UInt4_getZXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getZXW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getZXW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZXW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getZXW."));
    return scripting::createNil();
}

scripting::Value *UInt4_setYZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setYZW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setYZW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYZW(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setYZW."));
    return scripting::createNil();
}

scripting::Value *UInt4_getYWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getYWZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getYWZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYWZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getYWZ."));
    return scripting::createNil();
}

scripting::Value *UInt4___leq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::__leq__ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::__leq__ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self <= val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::__leq__."));
    return scripting::createNil();
}

scripting::Value *UInt4_getYWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getYWX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getYWX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYWX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getYWX."));
    return scripting::createNil();
}

scripting::Value *UInt4_sum(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::sum expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::sum expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->sum());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::sum."));
    return scripting::createNil();
}

scripting::Value *UInt4_setYZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setYZX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setYZX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYZX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setYZX."));
    return scripting::createNil();
}

scripting::Value *UInt4_getXYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getXYZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getXYZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXYZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getXYZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_getZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getZX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getZX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getZX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getZX."));
    return scripting::createNil();
}

scripting::Value *UInt4_getXYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getXYW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getXYW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXYW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getXYW."));
    return scripting::createNil();
}

scripting::Value *UInt4_setYWZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setYWZX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setYWZX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setYWZX(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setYWZX."));
    return scripting::createNil();
}

scripting::Value *UInt4_setWXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setWXY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setWXY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setWXY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setWXY."));
    return scripting::createNil();
}

scripting::Value *UInt4_setWXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setWXZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setWXZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setWXZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setWXZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_setZXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setZXW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setZXW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZXW(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setZXW."));
    return scripting::createNil();
}

scripting::Value *UInt4_getXWYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getXWYZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getXWYZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getXWYZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getXWYZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_setWYXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setWYXZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setWYXZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setWYXZ(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setWYXZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_setZXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setZXY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setZXY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZXY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setZXY."));
    return scripting::createNil();
}

scripting::Value *UInt4_getXWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getXWY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getXWY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXWY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getXWY."));
    return scripting::createNil();
}

scripting::Value *UInt4_getYXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getYXW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getYXW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYXW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getYXW."));
    return scripting::createNil();
}

scripting::Value *UInt4_getYXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getYXZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getYXZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYXZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getYXZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_setXYWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setXYWZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setXYWZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setXYWZ(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setXYWZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_length(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::length expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::length expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->length());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::length."));
    return scripting::createNil();
}

scripting::Value *UInt4_setWXZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setWXZY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setWXZY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setWXZY(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setWXZY."));
    return scripting::createNil();
}

scripting::Value *UInt4_getYZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getYZW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getYZW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getYZW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getYZW."));
    return scripting::createNil();
}

scripting::Value *UInt4_setXWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setXWZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setXWZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXWZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setXWZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_setXWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setXWY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setXWY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXWY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setXWY."));
    return scripting::createNil();
}

scripting::Value *UInt4_getWYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getWYZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getWYZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getWYZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getWYZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_getWYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getWYX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getWYX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getWYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getWYX."));
    return scripting::createNil();
}

scripting::Value *UInt4_getZYWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getZYWX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getZYWX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getZYWX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getZYWX."));
    return scripting::createNil();
}

scripting::Value *UInt4_getXYZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getXYZW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getXYZW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getXYZW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getXYZW."));
    return scripting::createNil();
}

scripting::Value *UInt4_setZWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setZWY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setZWY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZWY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setZWY."));
    return scripting::createNil();
}

scripting::Value *UInt4_setZWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setZWX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setZWX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setZWX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setZWX."));
    return scripting::createNil();
}

scripting::Value *UInt4_setWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setWX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setWX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setWX(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setWX."));
    return scripting::createNil();
}

scripting::Value *UInt4_setWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setWY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setWY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setWY(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setWY."));
    return scripting::createNil();
}

scripting::Value *UInt4_setWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setWZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setWZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setWZ(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setWZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_getZWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getZWY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getZWY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZWY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getZWY."));
    return scripting::createNil();
}

scripting::Value *UInt4_getZWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getZWX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getZWX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZWX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getZWX."));
    return scripting::createNil();
}

scripting::Value *UInt4_setYXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setYXZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setYXZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYXZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setYXZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_setYXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setYXW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setYXW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYXW(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setYXW."));
    return scripting::createNil();
}

scripting::Value *UInt4_getXWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getXWZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getXWZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXWZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getXWZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_getXZWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getXZWY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getXZWY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getXZWY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getXZWY."));
    return scripting::createNil();
}

scripting::Value *UInt4___less__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::__less__ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::__less__ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self < val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::__less__."));
    return scripting::createNil();
}

scripting::Value *UInt4_getZYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getZYW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getZYW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZYW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getZYW."));
    return scripting::createNil();
}

scripting::Value *UInt4_setWZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setWZY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setWZY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setWZY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setWZY."));
    return scripting::createNil();
}

scripting::Value *UInt4_setWZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setWZX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setWZX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setWZX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setWZX."));
    return scripting::createNil();
}

scripting::Value *UInt4_setZYXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setZYXW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setZYXW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setZYXW(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setZYXW."));
    return scripting::createNil();
}

scripting::Value *UInt4_getYZWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getYZWX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getYZWX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getYZWX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getYZWX."));
    return scripting::createNil();
}

scripting::Value *UInt4_getZYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getZYX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getZYX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getZYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getZYX."));
    return scripting::createNil();
}

scripting::Value *UInt4_getXZYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getXZYW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getXZYW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getXZYW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getXZYW."));
    return scripting::createNil();
}

scripting::Value *UInt4_setYXWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setYXWZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setYXWZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setYXWZ(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setYXWZ."));
    return scripting::createNil();
}

scripting::Value *UInt4___eq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::__eq__ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::__eq__ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self == val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::__eq__."));
    return scripting::createNil();
}

scripting::Value *UInt4_getWYXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getWYXZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getWYXZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getWYXZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getWYXZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_distance(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::distance expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::distance expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->distance(val_to_c<const T4<float> &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::distance."));
    return scripting::createNil();
}

scripting::Value *UInt4_getXZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getXZW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getXZW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXZW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getXZW."));
    return scripting::createNil();
}

scripting::Value *UInt4_setYZXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setYZXW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setYZXW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setYZXW(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setYZXW."));
    return scripting::createNil();
}

scripting::Value *UInt4_getZWXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getZWXY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getZWXY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getZWXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getZWXY."));
    return scripting::createNil();
}

scripting::Value *UInt4_getXZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getXZY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getXZY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getXZY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getXZY."));
    return scripting::createNil();
}

scripting::Value *UInt4_getYZXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getYZXW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getYZXW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getYZXW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getYZXW."));
    return scripting::createNil();
}

scripting::Value *UInt4_setZWYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setZWYX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setZWYX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setZWYX(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setZWYX."));
    return scripting::createNil();
}

scripting::Value *UInt4___sub__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::__sub__ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::__sub__ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self - val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self - val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::__sub__."));
    return scripting::createNil();
}

scripting::Value *UInt4_getYXWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getYXWZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getYXWZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getYXWZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getYXWZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_setXZWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setXZWY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setXZWY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setXZWY(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setXZWY."));
    return scripting::createNil();
}

scripting::Value *UInt4_setYWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setYWZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setYWZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYWZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setYWZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_setYWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setYWX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setYWX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setYWX(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setYWX."));
    return scripting::createNil();
}

scripting::Value *UInt4_setYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setYZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setYZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setYZ(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setYZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_setYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setYX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setYX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setYX(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setYX."));
    return scripting::createNil();
}

scripting::Value *UInt4_setYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setYW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setYW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setYW(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setYW."));
    return scripting::createNil();
}

scripting::Value *UInt4_getWXYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getWXYZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getWXYZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getWXYZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getWXYZ."));
    return scripting::createNil();
}

scripting::Value *UInt4___neq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::__neq__ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::__neq__ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self != val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::__neq__."));
    return scripting::createNil();
}

scripting::Value *UInt4_normalize(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::normalize expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::normalize expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->normalize());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::normalize."));
    return scripting::createNil();
}

scripting::Value *UInt4_getYX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getYX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getYX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getYX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getYX."));
    return scripting::createNil();
}

scripting::Value *UInt4_setXZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setXZW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setXZW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXZW(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setXZW."));
    return scripting::createNil();
}

scripting::Value *UInt4_setXZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setXZY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setXZY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXZY(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setXZY."));
    return scripting::createNil();
}

scripting::Value *UInt4_setXYZW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setXYZW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setXYZW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setXYZW(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setXYZW."));
    return scripting::createNil();
}

scripting::Value *UInt4_getYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getYW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getYW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getYW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getYW."));
    return scripting::createNil();
}

scripting::Value *UInt4_setWXYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setWXYZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setWXYZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setWXYZ(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setWXYZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_getYWXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getYWXZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getYWXZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getYWXZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getYWXZ."));
    return scripting::createNil();
}

scripting::Value *UInt4___mul__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::__mul__ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::__mul__ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self * val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self * val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::__mul__."));
    return scripting::createNil();
}

scripting::Value *UInt4_getYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getYZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getYZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getYZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getYZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_lengthSquared(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::lengthSquared expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::lengthSquared expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->lengthSquared());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::lengthSquared."));
    return scripting::createNil();
}

scripting::Value *UInt4_getWXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getWXY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getWXY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getWXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getWXY."));
    return scripting::createNil();
}

scripting::Value *UInt4_getWXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getWXZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getWXZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T3<float>>::f(ctx,  self->getWXZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getWXZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_getWX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getWX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getWX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getWX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getWX."));
    return scripting::createNil();
}

scripting::Value *UInt4_getWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getWY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getWY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getWY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getWY."));
    return scripting::createNil();
}

scripting::Value *UInt4_getWZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getWZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getWZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getWZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getWZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_setXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setXY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setXY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setXY(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setXY."));
    return scripting::createNil();
}

scripting::Value *UInt4_getZXYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getZXYW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getZXYW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getZXYW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getZXYW."));
    return scripting::createNil();
}

scripting::Value *UInt4___add__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::__add__ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::__add__ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self + val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self + val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::__add__."));
    return scripting::createNil();
}

scripting::Value *UInt4_setXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setXZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setXZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setXZ(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setXZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_getWYZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getWYZX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getWYZX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getWYZX());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getWYZX."));
    return scripting::createNil();
}

scripting::Value *UInt4_setXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setXW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setXW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T2<float> &>::f(ctx,args[1]))
        {
            ( self->setXW(val_to_c<const T2<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setXW."));
    return scripting::createNil();
}

scripting::Value *UInt4_getWXZY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getWXZY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getWXZY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T4<float>>::f(ctx,  self->getWXZY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getWXZY."));
    return scripting::createNil();
}

scripting::Value *UInt4_getXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getXY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getXY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getXY());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getXY."));
    return scripting::createNil();
}

scripting::Value *UInt4_setZXWY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setZXWY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setZXWY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setZXWY(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setZXWY."));
    return scripting::createNil();
}

scripting::Value *UInt4_setXYW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setXYW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setXYW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXYW(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setXYW."));
    return scripting::createNil();
}

scripting::Value *UInt4_getXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getXZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getXZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getXZ());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getXZ."));
    return scripting::createNil();
}

scripting::Value *UInt4_setWZXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setWZXY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setWZXY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setWZXY(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setWZXY."));
    return scripting::createNil();
}

scripting::Value *UInt4___grtr__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::__grtr__ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::__grtr__ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self > val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::__grtr__."));
    return scripting::createNil();
}

scripting::Value *UInt4_setZWXY(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setZWXY expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setZWXY expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setZWXY(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setZWXY."));
    return scripting::createNil();
}

scripting::Value *UInt4_getXW(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::getXW expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::getXW expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<T2<float>>::f(ctx,  self->getXW());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::getXW."));
    return scripting::createNil();
}

scripting::Value *UInt4_setXYZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setXYZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setXYZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T3<float> &>::f(ctx,args[1]))
        {
            ( self->setXYZ(val_to_c<const T3<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setXYZ."));
    return scripting::createNil();
}

scripting::Value *UInt4___div__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::__div__ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::__div__ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self / val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const float&>::f(ctx,args[1]))
        {
            return create_val<T4<float>>::f(ctx, *self / val_to_c<const float&>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::__div__."));
    return scripting::createNil();
}

scripting::Value *UInt4_setWYZX(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setWYZX expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setWYZX expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setWYZX(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setWYZX."));
    return scripting::createNil();
}

scripting::Value *UInt4_setYWXZ(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::setYWXZ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::setYWXZ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            ( self->setYWXZ(val_to_c<const T4<float> &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::setYWXZ."));
    return scripting::createNil();
}

scripting::Value *UInt4___geq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::__geq__ expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::__geq__ expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self >= val_to_c<const T4<float> &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::__geq__."));
    return scripting::createNil();
}

scripting::Value *UInt4_dot(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::dot expects at least one argument."));
    T4<uint32_t>*self;
    if(!type_same<T4<uint32_t>>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4::dot expects UInt4 as first argument."));
    else
         self=(T4<uint32_t>*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const T4<float> &>::f(ctx,args[1]))
        {
            return create_val<float>::f(ctx,  self->dot(val_to_c<const T4<float> &>::f(ctx,args[1])));
            ;
        }
    if(args.getCount()==1)
        if(1)
        {
            return create_val<float>::f(ctx,  self->dot());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for UInt4::dot."));
    return scripting::createNil();
}

scripting::Value *AABB_copy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(AABB_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(AABB_funcs,NEW(AABB,*((AABB*)self->data)),self->typeID);
}

void AABB_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<AABB>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"AABB::__del__ expects AABB as first argument."));

    DELETE(AABB,(AABB *)self->data);
}scripting::Value *AABB_new(scripting::Context*ctx,const List<scripting::Value *>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"AABB's constructor expects at least one argument."));
    if(!type_same<AABB>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"AABB's constructor expects AABB as first argument."));
    if(args.getCount()==1)
        if(true)
            return scripting::createNativeObject(AABB_funcs,NEW(AABB),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->AABB_typeID);
    if(args.getCount()==3)
        if(true&&type_same<const Position3D &>::f(ctx,args[1])&&type_same<const Position3D &>::f(ctx,args[2]))
            return scripting::createNativeObject(AABB_funcs,NEW(AABB,val_to_c<const Position3D &>::f(ctx,args[1]),val_to_c<const Position3D &>::f(ctx,args[2])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->AABB_typeID);
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for AABB's constructor."));
    return scripting::createNil();
}

scripting::Value *AABB_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
            if(keyStr=="__typeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__name__")
                return scripting::createString("AABB");
            else if(keyStr=="__new__")
                return scripting::createNativeFunction(AABB_new);
            else if(keyStr=="__call__")
                return scripting::createNativeFunction(AABB_new);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
            if(keyStr=="__classTypeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__init__")
                return scripting::createNativeFunction(AABB_new);
             else if (keyStr == "transform")
                return scripting::createNativeFunction(AABB_transform);
             else if (keyStr == "extend")
                return scripting::createNativeFunction(AABB_extend);
             else if (keyStr == "grow")
                return scripting::createNativeFunction(AABB_grow);
             else if(keyStr=="min")
            {
                AABB*obj=(AABB*)self->data;
                return create_val<decltype(obj->min)>::f(ctx,obj->min);
            } else if(keyStr=="max")
            {
                AABB*obj=(AABB*)self->data;
                return create_val<decltype(obj->max)>::f(ctx,obj->max);
            } else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        }
    }
    return scripting::createNil();
}

void AABB_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue*)key)->value;
        if(self->data==NULL)
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Native classes are read-only."));
        else
        {
            if(0) {} else if(keyStr=="min")
            {
                AABB*obj=(AABB*)self->data;
                obj->min=val_to_c<decltype(obj->min)>::f(ctx,value);
            } else if(keyStr=="max")
            {
                AABB*obj=(AABB*)self->data;
                obj->max=val_to_c<decltype(obj->max)>::f(ctx,value);
            } else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member or member if read-only."));
        }
    }
}

scripting::Value *AABB_transform(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"AABB::transform expects at least one argument."));
    AABB*self;
    if(!type_same<AABB>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"AABB::transform expects AABB as first argument."));
    else
         self=(AABB*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const Matrix4x4 &>::f(ctx,args[1]))
        {
            return create_val<AABB>::f(ctx,  self->transform(val_to_c<const Matrix4x4 &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for AABB::transform."));
    return scripting::createNil();
}

scripting::Value *AABB_extend(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"AABB::extend expects at least one argument."));
    AABB*self;
    if(!type_same<AABB>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"AABB::extend expects AABB as first argument."));
    else
         self=(AABB*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const Position3D &>::f(ctx,args[1]))
        {
            ( self->extend(val_to_c<const Position3D &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    if(args.getCount()==2)
        if(1&&type_same<const AABB &>::f(ctx,args[1]))
        {
            ( self->extend(val_to_c<const AABB &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for AABB::extend."));
    return scripting::createNil();
}

scripting::Value *AABB_grow(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"AABB::grow expects at least one argument."));
    AABB*self;
    if(!type_same<AABB>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"AABB::grow expects AABB as first argument."));
    else
         self=(AABB*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const Vector3D &>::f(ctx,args[1]))
        {
            ( self->grow(val_to_c<const Vector3D &>::f(ctx,args[1])));
            return scripting::createNil();
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for AABB::grow."));
    return scripting::createNil();
}

scripting::Value *Matrix3x3_copy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(Matrix3x3_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(Matrix3x3_funcs,NEW(Matrix3x3,*((Matrix3x3*)self->data)),self->typeID);
}

void Matrix3x3_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<Matrix3x3>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix3x3::__del__ expects Matrix3x3 as first argument."));

    DELETE(Matrix3x3,(Matrix3x3 *)self->data);
}scripting::Value *Matrix3x3_new(scripting::Context*ctx,const List<scripting::Value *>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix3x3's constructor expects at least one argument."));
    if(!type_same<Matrix3x3>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix3x3's constructor expects Matrix3x3 as first argument."));
    if(args.getCount()==1)
        if(true)
            return scripting::createNativeObject(Matrix3x3_funcs,NEW(Matrix3x3),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix3x3_typeID);
    if(args.getCount()==2)
        if(true&&type_same<const Matrix4x4 &>::f(ctx,args[1]))
            return scripting::createNativeObject(Matrix3x3_funcs,NEW(Matrix3x3,val_to_c<const Matrix4x4 &>::f(ctx,args[1])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix3x3_typeID);
    if(args.getCount()==4)
        if(true&&type_same<const Float3 &>::f(ctx,args[1])&&type_same<const Float3 &>::f(ctx,args[2])&&type_same<const Float3 &>::f(ctx,args[3]))
            return scripting::createNativeObject(Matrix3x3_funcs,NEW(Matrix3x3,val_to_c<const Float3 &>::f(ctx,args[1]),val_to_c<const Float3 &>::f(ctx,args[2]),val_to_c<const Float3 &>::f(ctx,args[3])),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix3x3_typeID);
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix3x3's constructor."));
    return scripting::createNil();
}

scripting::Value *Matrix3x3_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
            if(keyStr=="__typeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__name__")
                return scripting::createString("Matrix3x3");
            else if(keyStr=="__new__")
                return scripting::createNativeFunction(Matrix3x3_new);
            else if(keyStr=="__call__")
                return scripting::createNativeFunction(Matrix3x3_new);
            else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
            if(keyStr=="__classTypeID__")
                return scripting::createInt(self->typeID);
            else if(keyStr=="__init__")
                return scripting::createNativeFunction(Matrix3x3_new);
             else if (keyStr == "__mul__")
                return scripting::createNativeFunction(Matrix3x3___mul__);
             else if (keyStr == "__div__")
                return scripting::createNativeFunction(Matrix3x3___div__);
             else if (keyStr == "__eq__")
                return scripting::createNativeFunction(Matrix3x3___eq__);
             else if (keyStr == "transpose")
                return scripting::createNativeFunction(Matrix3x3_transpose);
             else if (keyStr == "inverse")
                return scripting::createNativeFunction(Matrix3x3_inverse);
             else if (keyStr == "translate")
                return scripting::createNativeFunction(Matrix3x3_translate);
             else if (keyStr == "scale")
                return scripting::createNativeFunction(Matrix3x3_scale);
             else if (keyStr == "rotate")
                return scripting::createNativeFunction(Matrix3x3_rotate);
             else if (keyStr == "rotatex")
                return scripting::createNativeFunction(Matrix3x3_rotatex);
             else if (keyStr == "rotatey")
                return scripting::createNativeFunction(Matrix3x3_rotatey);
             else if (keyStr == "rotatez")
                return scripting::createNativeFunction(Matrix3x3_rotatez);
             else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        }
    }
    return scripting::createNil();
}

void Matrix3x3_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue*)key)->value;
        if(self->data==NULL)
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Native classes are read-only."));
        else
        {
            if(0) {} else
                 ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member or member if read-only."));
        }
    }
}

scripting::Value *Matrix3x3_inverse(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix3x3::inverse expects at least one argument."));
    Matrix3x3*self;
    if(!type_same<Matrix3x3>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix3x3::inverse expects Matrix3x3 as first argument."));
    else
         self=(Matrix3x3*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<Matrix3x3>::f(ctx,  self->inverse());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix3x3::inverse."));
    return scripting::createNil();
}

scripting::Value *Matrix3x3_transpose(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix3x3::transpose expects at least one argument."));
    Matrix3x3*self;
    if(!type_same<Matrix3x3>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix3x3::transpose expects Matrix3x3 as first argument."));
    else
         self=(Matrix3x3*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==1)
        if(1)
        {
            return create_val<Matrix3x3>::f(ctx,  self->transpose());
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix3x3::transpose."));
    return scripting::createNil();
}

scripting::Value *Matrix3x3_rotatez(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix3x3::rotatez expects at least one argument."));
    Matrix3x3*self;
    if(!type_same<Matrix3x3>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix3x3::rotatez expects Matrix3x3 as first argument."));
    else
         self=(Matrix3x3*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<Matrix3x3>::f(ctx,  self->rotatez(val_to_c<float>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix3x3::rotatez."));
    return scripting::createNil();
}

scripting::Value *Matrix3x3_rotatex(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix3x3::rotatex expects at least one argument."));
    Matrix3x3*self;
    if(!type_same<Matrix3x3>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix3x3::rotatex expects Matrix3x3 as first argument."));
    else
         self=(Matrix3x3*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<Matrix3x3>::f(ctx,  self->rotatex(val_to_c<float>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix3x3::rotatex."));
    return scripting::createNil();
}

scripting::Value *Matrix3x3_rotatey(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix3x3::rotatey expects at least one argument."));
    Matrix3x3*self;
    if(!type_same<Matrix3x3>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix3x3::rotatey expects Matrix3x3 as first argument."));
    else
         self=(Matrix3x3*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<Matrix3x3>::f(ctx,  self->rotatey(val_to_c<float>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix3x3::rotatey."));
    return scripting::createNil();
}

scripting::Value *Matrix3x3___div__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix3x3::__div__ expects at least one argument."));
    Matrix3x3*self;
    if(!type_same<Matrix3x3>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix3x3::__div__ expects Matrix3x3 as first argument."));
    else
         self=(Matrix3x3*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<Matrix3x3>::f(ctx, *self / val_to_c<float>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix3x3::__div__."));
    return scripting::createNil();
}

scripting::Value *Matrix3x3_scale(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix3x3::scale expects at least one argument."));
    Matrix3x3*self;
    if(!type_same<Matrix3x3>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix3x3::scale expects Matrix3x3 as first argument."));
    else
         self=(Matrix3x3*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const Float3 &>::f(ctx,args[1]))
        {
            return create_val<Matrix3x3>::f(ctx,  self->scale(val_to_c<const Float3 &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix3x3::scale."));
    return scripting::createNil();
}

scripting::Value *Matrix3x3___mul__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix3x3::__mul__ expects at least one argument."));
    Matrix3x3*self;
    if(!type_same<Matrix3x3>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix3x3::__mul__ expects Matrix3x3 as first argument."));
    else
         self=(Matrix3x3*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const Matrix3x3 &>::f(ctx,args[1]))
        {
            return create_val<Matrix3x3>::f(ctx, *self * val_to_c<const Matrix3x3 &>::f(ctx,args[1]));
        }
    if(args.getCount()==2)
        if(1&&type_same<const Float3 &>::f(ctx,args[1]))
        {
            return create_val<Float3>::f(ctx, *self * val_to_c<const Float3 &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix3x3::__mul__."));
    return scripting::createNil();
}

scripting::Value *Matrix3x3_translate(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix3x3::translate expects at least one argument."));
    Matrix3x3*self;
    if(!type_same<Matrix3x3>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix3x3::translate expects Matrix3x3 as first argument."));
    else
         self=(Matrix3x3*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const Float2 &>::f(ctx,args[1]))
        {
            return create_val<Matrix3x3>::f(ctx,  self->translate(val_to_c<const Float2 &>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix3x3::translate."));
    return scripting::createNil();
}

scripting::Value *Matrix3x3___eq__(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix3x3::__eq__ expects at least one argument."));
    Matrix3x3*self;
    if(!type_same<Matrix3x3>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix3x3::__eq__ expects Matrix3x3 as first argument."));
    else
         self=(Matrix3x3*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<const Matrix3x3 &>::f(ctx,args[1]))
        {
            return create_val<bool>::f(ctx, *self == val_to_c<const Matrix3x3 &>::f(ctx,args[1]));
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix3x3::__eq__."));
    return scripting::createNil();
}

scripting::Value *Matrix3x3_rotate(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix3x3::rotate expects at least one argument."));
    Matrix3x3*self;
    if(!type_same<Matrix3x3>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix3x3::rotate expects Matrix3x3 as first argument."));
    else
         self=(Matrix3x3*)((scripting::NativeObject*)args[0])->data;

    if(args.getCount()==2)
        if(1&&type_same<float>::f(ctx,args[1]))
        {
            return create_val<Matrix3x3>::f(ctx,  self->rotate(val_to_c<float>::f(ctx,args[1])));
            ;
        }
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for Matrix3x3::rotate."));
    return scripting::createNil();
}

scripting::Value *UInt3_ptr_new(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    List<scripting::Value *> args2 = args.copy();
    args2[0]=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt3;
    scripting::NativeObject *obj=(scripting::NativeObject*)UInt3_new(ctx, args2);
    obj->funcs=UInt3_ptr_funcs;
    obj->typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt3_ptr_typeID;
    setAllocInfo(obj->data, AllocInfo(true, false));
    return (scripting::Value*)obj;
}
scripting::Value *UInt3_ptr_deref(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3Ref::deref expects one argument."));
    scripting::Value*self=args[0];
    if(!type_same<T3<uint32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3Ref::deref expects UInt3Ref as first argument."));
    return create_val<T3<uint32_t>>::f(ctx, *(T3<uint32_t> *)((scripting::NativeObject *)self)->data);
}
scripting::Value *UInt3_ptr_set(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=2)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt3::refset expects two arguments."));
    scripting::Value*self=args[0];
    if(!type_same<T3<uint32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3Ref::refset expects UInt3Ref as first argument."));
    *((T3<uint32_t> *)((scripting::NativeObject *)self)->data) = val_to_c<T3<uint32_t>>::f(ctx,args[1]);
    return scripting::createNil();
}
scripting::Value *UInt3_ptr_copy(scripting::Context*, scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(UInt3_ptr_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(UInt3_ptr_funcs,self->data,self->typeID);
}
void UInt3_ptr_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<T3<uint32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3Ref::__del__ expects UInt3Ref as first argument."));
    SCRIPT_DELETE(T3<uint32_t>, (T3<uint32_t> *)self->data);
}
scripting::Value *UInt3_ptr_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if(!type_same<T3<uint32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3Ref's get method expects UInt3Ref as first argument."));
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
        if(keyStr=="__typeID__")
            return scripting::createInt(self->typeID);
        else if(keyStr=="__name__")
            return scripting::createString("UInt3Ptr");
        else if(keyStr=="__new__")
            return scripting::createNativeFunction(UInt3_ptr_new);
        else if(keyStr=="__call__")
            return scripting::createNativeFunction(UInt3_ptr_new);
        else
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
        if(keyStr=="deref") return scripting::createNativeFunction(UInt3_ptr_deref);
        if(keyStr=="refset") return scripting::createNativeFunction(UInt3_ptr_set);
        }
    }
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=UInt3_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt3_typeID;
    obj.refCount=1;
    obj.data=self->data;
    return UInt3_get_member(ctx, &obj, key);
}
void UInt3_ptr_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if(!type_same<T3<uint32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt3Ref's get method expects UInt3Ref as first argument."));
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=UInt3_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt3_typeID;
    obj.refCount=1;
    obj.data=self->data;
    UInt3_set_member(ctx, &obj, key, value);
}
scripting::Value *UInt2_ptr_new(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    List<scripting::Value *> args2 = args.copy();
    args2[0]=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt2;
    scripting::NativeObject *obj=(scripting::NativeObject*)UInt2_new(ctx, args2);
    obj->funcs=UInt2_ptr_funcs;
    obj->typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt2_ptr_typeID;
    setAllocInfo(obj->data, AllocInfo(true, false));
    return (scripting::Value*)obj;
}
scripting::Value *UInt2_ptr_deref(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2Ref::deref expects one argument."));
    scripting::Value*self=args[0];
    if(!type_same<T2<uint32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2Ref::deref expects UInt2Ref as first argument."));
    return create_val<T2<uint32_t>>::f(ctx, *(T2<uint32_t> *)((scripting::NativeObject *)self)->data);
}
scripting::Value *UInt2_ptr_set(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=2)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt2::refset expects two arguments."));
    scripting::Value*self=args[0];
    if(!type_same<T2<uint32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2Ref::refset expects UInt2Ref as first argument."));
    *((T2<uint32_t> *)((scripting::NativeObject *)self)->data) = val_to_c<T2<uint32_t>>::f(ctx,args[1]);
    return scripting::createNil();
}
scripting::Value *UInt2_ptr_copy(scripting::Context*, scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(UInt2_ptr_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(UInt2_ptr_funcs,self->data,self->typeID);
}
void UInt2_ptr_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<T2<uint32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2Ref::__del__ expects UInt2Ref as first argument."));
    SCRIPT_DELETE(T2<uint32_t>, (T2<uint32_t> *)self->data);
}
scripting::Value *UInt2_ptr_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if(!type_same<T2<uint32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2Ref's get method expects UInt2Ref as first argument."));
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
        if(keyStr=="__typeID__")
            return scripting::createInt(self->typeID);
        else if(keyStr=="__name__")
            return scripting::createString("UInt2Ptr");
        else if(keyStr=="__new__")
            return scripting::createNativeFunction(UInt2_ptr_new);
        else if(keyStr=="__call__")
            return scripting::createNativeFunction(UInt2_ptr_new);
        else
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
        if(keyStr=="deref") return scripting::createNativeFunction(UInt2_ptr_deref);
        if(keyStr=="refset") return scripting::createNativeFunction(UInt2_ptr_set);
        }
    }
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=UInt2_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt2_typeID;
    obj.refCount=1;
    obj.data=self->data;
    return UInt2_get_member(ctx, &obj, key);
}
void UInt2_ptr_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if(!type_same<T2<uint32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt2Ref's get method expects UInt2Ref as first argument."));
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=UInt2_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt2_typeID;
    obj.refCount=1;
    obj.data=self->data;
    UInt2_set_member(ctx, &obj, key, value);
}
scripting::Value *RigidBody_ptr_new(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    List<scripting::Value *> args2 = args.copy();
    args2[0]=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->RigidBody;
    scripting::NativeObject *obj=(scripting::NativeObject*)RigidBody_new(ctx, args2);
    obj->funcs=RigidBody_ptr_funcs;
    obj->typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->RigidBody_ptr_typeID;
    setAllocInfo(obj->data, AllocInfo(true, false));
    return (scripting::Value*)obj;
}
scripting::Value *RigidBody_ptr_deref(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBodyRef::deref expects one argument."));
    scripting::Value*self=args[0];
    if(!type_same<RigidBody *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBodyRef::deref expects RigidBodyRef as first argument."));
    return create_val<RigidBody>::f(ctx, *(RigidBody *)((scripting::NativeObject *)self)->data);
}
scripting::Value *RigidBody_ptr_set(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=2)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"RigidBody::refset expects two arguments."));
    scripting::Value*self=args[0];
    if(!type_same<RigidBody *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBodyRef::refset expects RigidBodyRef as first argument."));
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBody objects are not copyable."));
    return scripting::createNil();
}
scripting::Value *RigidBody_ptr_copy(scripting::Context*, scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(RigidBody_ptr_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(RigidBody_ptr_funcs,self->data,self->typeID);
}
void RigidBody_ptr_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<RigidBody *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBodyRef::__del__ expects RigidBodyRef as first argument."));
}
scripting::Value *RigidBody_ptr_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if(!type_same<RigidBody *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBodyRef's get method expects RigidBodyRef as first argument."));
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
        if(keyStr=="__typeID__")
            return scripting::createInt(self->typeID);
        else if(keyStr=="__name__")
            return scripting::createString("RigidBodyPtr");
        else if(keyStr=="__new__")
            return scripting::createNativeFunction(RigidBody_ptr_new);
        else if(keyStr=="__call__")
            return scripting::createNativeFunction(RigidBody_ptr_new);
        else
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
        if(keyStr=="deref") return scripting::createNativeFunction(RigidBody_ptr_deref);
        if(keyStr=="refset") return scripting::createNativeFunction(RigidBody_ptr_set);
        }
    }
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=RigidBody_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->RigidBody_typeID;
    obj.refCount=1;
    obj.data=self->data;
    return RigidBody_get_member(ctx, &obj, key);
}
void RigidBody_ptr_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if(!type_same<RigidBody *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"RigidBodyRef's get method expects RigidBodyRef as first argument."));
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=RigidBody_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->RigidBody_typeID;
    obj.refCount=1;
    obj.data=self->data;
    RigidBody_set_member(ctx, &obj, key, value);
}
scripting::Value *Int3_ptr_new(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    List<scripting::Value *> args2 = args.copy();
    args2[0]=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int3;
    scripting::NativeObject *obj=(scripting::NativeObject*)Int3_new(ctx, args2);
    obj->funcs=Int3_ptr_funcs;
    obj->typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int3_ptr_typeID;
    setAllocInfo(obj->data, AllocInfo(true, false));
    return (scripting::Value*)obj;
}
scripting::Value *Int3_ptr_deref(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3Ref::deref expects one argument."));
    scripting::Value*self=args[0];
    if(!type_same<T3<int32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3Ref::deref expects Int3Ref as first argument."));
    return create_val<T3<int32_t>>::f(ctx, *(T3<int32_t> *)((scripting::NativeObject *)self)->data);
}
scripting::Value *Int3_ptr_set(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=2)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int3::refset expects two arguments."));
    scripting::Value*self=args[0];
    if(!type_same<T3<int32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3Ref::refset expects Int3Ref as first argument."));
    *((T3<int32_t> *)((scripting::NativeObject *)self)->data) = val_to_c<T3<int32_t>>::f(ctx,args[1]);
    return scripting::createNil();
}
scripting::Value *Int3_ptr_copy(scripting::Context*, scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(Int3_ptr_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(Int3_ptr_funcs,self->data,self->typeID);
}
void Int3_ptr_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<T3<int32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3Ref::__del__ expects Int3Ref as first argument."));
    SCRIPT_DELETE(T3<int32_t>, (T3<int32_t> *)self->data);
}
scripting::Value *Int3_ptr_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if(!type_same<T3<int32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3Ref's get method expects Int3Ref as first argument."));
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
        if(keyStr=="__typeID__")
            return scripting::createInt(self->typeID);
        else if(keyStr=="__name__")
            return scripting::createString("Int3Ptr");
        else if(keyStr=="__new__")
            return scripting::createNativeFunction(Int3_ptr_new);
        else if(keyStr=="__call__")
            return scripting::createNativeFunction(Int3_ptr_new);
        else
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
        if(keyStr=="deref") return scripting::createNativeFunction(Int3_ptr_deref);
        if(keyStr=="refset") return scripting::createNativeFunction(Int3_ptr_set);
        }
    }
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=Int3_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int3_typeID;
    obj.refCount=1;
    obj.data=self->data;
    return Int3_get_member(ctx, &obj, key);
}
void Int3_ptr_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if(!type_same<T3<int32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int3Ref's get method expects Int3Ref as first argument."));
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=Int3_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int3_typeID;
    obj.refCount=1;
    obj.data=self->data;
    Int3_set_member(ctx, &obj, key, value);
}
scripting::Value *Float2_ptr_new(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    List<scripting::Value *> args2 = args.copy();
    args2[0]=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float2;
    scripting::NativeObject *obj=(scripting::NativeObject*)Float2_new(ctx, args2);
    obj->funcs=Float2_ptr_funcs;
    obj->typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float2_ptr_typeID;
    setAllocInfo(obj->data, AllocInfo(true, false));
    return (scripting::Value*)obj;
}
scripting::Value *Float2_ptr_deref(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2Ref::deref expects one argument."));
    scripting::Value*self=args[0];
    if(!type_same<T2<float> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2Ref::deref expects Float2Ref as first argument."));
    return create_val<T2<float>>::f(ctx, *(T2<float> *)((scripting::NativeObject *)self)->data);
}
scripting::Value *Float2_ptr_set(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=2)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float2::refset expects two arguments."));
    scripting::Value*self=args[0];
    if(!type_same<T2<float> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2Ref::refset expects Float2Ref as first argument."));
    *((T2<float> *)((scripting::NativeObject *)self)->data) = val_to_c<T2<float>>::f(ctx,args[1]);
    return scripting::createNil();
}
scripting::Value *Float2_ptr_copy(scripting::Context*, scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(Float2_ptr_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(Float2_ptr_funcs,self->data,self->typeID);
}
void Float2_ptr_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<T2<float> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2Ref::__del__ expects Float2Ref as first argument."));
    SCRIPT_DELETE(T2<float>, (T2<float> *)self->data);
}
scripting::Value *Float2_ptr_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if(!type_same<T2<float> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2Ref's get method expects Float2Ref as first argument."));
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
        if(keyStr=="__typeID__")
            return scripting::createInt(self->typeID);
        else if(keyStr=="__name__")
            return scripting::createString("Float2Ptr");
        else if(keyStr=="__new__")
            return scripting::createNativeFunction(Float2_ptr_new);
        else if(keyStr=="__call__")
            return scripting::createNativeFunction(Float2_ptr_new);
        else
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
        if(keyStr=="deref") return scripting::createNativeFunction(Float2_ptr_deref);
        if(keyStr=="refset") return scripting::createNativeFunction(Float2_ptr_set);
        }
    }
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=Float2_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float2_typeID;
    obj.refCount=1;
    obj.data=self->data;
    return Float2_get_member(ctx, &obj, key);
}
void Float2_ptr_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if(!type_same<T2<float> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float2Ref's get method expects Float2Ref as first argument."));
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=Float2_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float2_typeID;
    obj.refCount=1;
    obj.data=self->data;
    Float2_set_member(ctx, &obj, key, value);
}
scripting::Value *Int4_ptr_new(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    List<scripting::Value *> args2 = args.copy();
    args2[0]=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int4;
    scripting::NativeObject *obj=(scripting::NativeObject*)Int4_new(ctx, args2);
    obj->funcs=Int4_ptr_funcs;
    obj->typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int4_ptr_typeID;
    setAllocInfo(obj->data, AllocInfo(true, false));
    return (scripting::Value*)obj;
}
scripting::Value *Int4_ptr_deref(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4Ref::deref expects one argument."));
    scripting::Value*self=args[0];
    if(!type_same<T4<int32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4Ref::deref expects Int4Ref as first argument."));
    return create_val<T4<int32_t>>::f(ctx, *(T4<int32_t> *)((scripting::NativeObject *)self)->data);
}
scripting::Value *Int4_ptr_set(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=2)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int4::refset expects two arguments."));
    scripting::Value*self=args[0];
    if(!type_same<T4<int32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4Ref::refset expects Int4Ref as first argument."));
    *((T4<int32_t> *)((scripting::NativeObject *)self)->data) = val_to_c<T4<int32_t>>::f(ctx,args[1]);
    return scripting::createNil();
}
scripting::Value *Int4_ptr_copy(scripting::Context*, scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(Int4_ptr_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(Int4_ptr_funcs,self->data,self->typeID);
}
void Int4_ptr_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<T4<int32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4Ref::__del__ expects Int4Ref as first argument."));
    SCRIPT_DELETE(T4<int32_t>, (T4<int32_t> *)self->data);
}
scripting::Value *Int4_ptr_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if(!type_same<T4<int32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4Ref's get method expects Int4Ref as first argument."));
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
        if(keyStr=="__typeID__")
            return scripting::createInt(self->typeID);
        else if(keyStr=="__name__")
            return scripting::createString("Int4Ptr");
        else if(keyStr=="__new__")
            return scripting::createNativeFunction(Int4_ptr_new);
        else if(keyStr=="__call__")
            return scripting::createNativeFunction(Int4_ptr_new);
        else
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
        if(keyStr=="deref") return scripting::createNativeFunction(Int4_ptr_deref);
        if(keyStr=="refset") return scripting::createNativeFunction(Int4_ptr_set);
        }
    }
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=Int4_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int4_typeID;
    obj.refCount=1;
    obj.data=self->data;
    return Int4_get_member(ctx, &obj, key);
}
void Int4_ptr_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if(!type_same<T4<int32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int4Ref's get method expects Int4Ref as first argument."));
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=Int4_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int4_typeID;
    obj.refCount=1;
    obj.data=self->data;
    Int4_set_member(ctx, &obj, key, value);
}
scripting::Value *Float3_ptr_new(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    List<scripting::Value *> args2 = args.copy();
    args2[0]=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float3;
    scripting::NativeObject *obj=(scripting::NativeObject*)Float3_new(ctx, args2);
    obj->funcs=Float3_ptr_funcs;
    obj->typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float3_ptr_typeID;
    setAllocInfo(obj->data, AllocInfo(true, false));
    return (scripting::Value*)obj;
}
scripting::Value *Float3_ptr_deref(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3Ref::deref expects one argument."));
    scripting::Value*self=args[0];
    if(!type_same<T3<float> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3Ref::deref expects Float3Ref as first argument."));
    return create_val<T3<float>>::f(ctx, *(T3<float> *)((scripting::NativeObject *)self)->data);
}
scripting::Value *Float3_ptr_set(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=2)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float3::refset expects two arguments."));
    scripting::Value*self=args[0];
    if(!type_same<T3<float> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3Ref::refset expects Float3Ref as first argument."));
    *((T3<float> *)((scripting::NativeObject *)self)->data) = val_to_c<T3<float>>::f(ctx,args[1]);
    return scripting::createNil();
}
scripting::Value *Float3_ptr_copy(scripting::Context*, scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(Float3_ptr_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(Float3_ptr_funcs,self->data,self->typeID);
}
void Float3_ptr_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<T3<float> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3Ref::__del__ expects Float3Ref as first argument."));
    SCRIPT_DELETE(T3<float>, (T3<float> *)self->data);
}
scripting::Value *Float3_ptr_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if(!type_same<T3<float> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3Ref's get method expects Float3Ref as first argument."));
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
        if(keyStr=="__typeID__")
            return scripting::createInt(self->typeID);
        else if(keyStr=="__name__")
            return scripting::createString("Float3Ptr");
        else if(keyStr=="__new__")
            return scripting::createNativeFunction(Float3_ptr_new);
        else if(keyStr=="__call__")
            return scripting::createNativeFunction(Float3_ptr_new);
        else
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
        if(keyStr=="deref") return scripting::createNativeFunction(Float3_ptr_deref);
        if(keyStr=="refset") return scripting::createNativeFunction(Float3_ptr_set);
        }
    }
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=Float3_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float3_typeID;
    obj.refCount=1;
    obj.data=self->data;
    return Float3_get_member(ctx, &obj, key);
}
void Float3_ptr_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if(!type_same<T3<float> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float3Ref's get method expects Float3Ref as first argument."));
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=Float3_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float3_typeID;
    obj.refCount=1;
    obj.data=self->data;
    Float3_set_member(ctx, &obj, key, value);
}
scripting::Value *Int2_ptr_new(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    List<scripting::Value *> args2 = args.copy();
    args2[0]=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int2;
    scripting::NativeObject *obj=(scripting::NativeObject*)Int2_new(ctx, args2);
    obj->funcs=Int2_ptr_funcs;
    obj->typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int2_ptr_typeID;
    setAllocInfo(obj->data, AllocInfo(true, false));
    return (scripting::Value*)obj;
}
scripting::Value *Int2_ptr_deref(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2Ref::deref expects one argument."));
    scripting::Value*self=args[0];
    if(!type_same<T2<int32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2Ref::deref expects Int2Ref as first argument."));
    return create_val<T2<int32_t>>::f(ctx, *(T2<int32_t> *)((scripting::NativeObject *)self)->data);
}
scripting::Value *Int2_ptr_set(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=2)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Int2::refset expects two arguments."));
    scripting::Value*self=args[0];
    if(!type_same<T2<int32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2Ref::refset expects Int2Ref as first argument."));
    *((T2<int32_t> *)((scripting::NativeObject *)self)->data) = val_to_c<T2<int32_t>>::f(ctx,args[1]);
    return scripting::createNil();
}
scripting::Value *Int2_ptr_copy(scripting::Context*, scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(Int2_ptr_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(Int2_ptr_funcs,self->data,self->typeID);
}
void Int2_ptr_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<T2<int32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2Ref::__del__ expects Int2Ref as first argument."));
    SCRIPT_DELETE(T2<int32_t>, (T2<int32_t> *)self->data);
}
scripting::Value *Int2_ptr_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if(!type_same<T2<int32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2Ref's get method expects Int2Ref as first argument."));
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
        if(keyStr=="__typeID__")
            return scripting::createInt(self->typeID);
        else if(keyStr=="__name__")
            return scripting::createString("Int2Ptr");
        else if(keyStr=="__new__")
            return scripting::createNativeFunction(Int2_ptr_new);
        else if(keyStr=="__call__")
            return scripting::createNativeFunction(Int2_ptr_new);
        else
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
        if(keyStr=="deref") return scripting::createNativeFunction(Int2_ptr_deref);
        if(keyStr=="refset") return scripting::createNativeFunction(Int2_ptr_set);
        }
    }
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=Int2_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int2_typeID;
    obj.refCount=1;
    obj.data=self->data;
    return Int2_get_member(ctx, &obj, key);
}
void Int2_ptr_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if(!type_same<T2<int32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Int2Ref's get method expects Int2Ref as first argument."));
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=Int2_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Int2_typeID;
    obj.refCount=1;
    obj.data=self->data;
    Int2_set_member(ctx, &obj, key, value);
}
scripting::Value *Float4_ptr_new(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    List<scripting::Value *> args2 = args.copy();
    args2[0]=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float4;
    scripting::NativeObject *obj=(scripting::NativeObject*)Float4_new(ctx, args2);
    obj->funcs=Float4_ptr_funcs;
    obj->typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float4_ptr_typeID;
    setAllocInfo(obj->data, AllocInfo(true, false));
    return (scripting::Value*)obj;
}
scripting::Value *Float4_ptr_deref(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4Ref::deref expects one argument."));
    scripting::Value*self=args[0];
    if(!type_same<T4<float> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4Ref::deref expects Float4Ref as first argument."));
    return create_val<T4<float>>::f(ctx, *(T4<float> *)((scripting::NativeObject *)self)->data);
}
scripting::Value *Float4_ptr_set(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=2)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Float4::refset expects two arguments."));
    scripting::Value*self=args[0];
    if(!type_same<T4<float> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4Ref::refset expects Float4Ref as first argument."));
    *((T4<float> *)((scripting::NativeObject *)self)->data) = val_to_c<T4<float>>::f(ctx,args[1]);
    return scripting::createNil();
}
scripting::Value *Float4_ptr_copy(scripting::Context*, scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(Float4_ptr_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(Float4_ptr_funcs,self->data,self->typeID);
}
void Float4_ptr_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<T4<float> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4Ref::__del__ expects Float4Ref as first argument."));
    SCRIPT_DELETE(T4<float>, (T4<float> *)self->data);
}
scripting::Value *Float4_ptr_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if(!type_same<T4<float> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4Ref's get method expects Float4Ref as first argument."));
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
        if(keyStr=="__typeID__")
            return scripting::createInt(self->typeID);
        else if(keyStr=="__name__")
            return scripting::createString("Float4Ptr");
        else if(keyStr=="__new__")
            return scripting::createNativeFunction(Float4_ptr_new);
        else if(keyStr=="__call__")
            return scripting::createNativeFunction(Float4_ptr_new);
        else
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
        if(keyStr=="deref") return scripting::createNativeFunction(Float4_ptr_deref);
        if(keyStr=="refset") return scripting::createNativeFunction(Float4_ptr_set);
        }
    }
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=Float4_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float4_typeID;
    obj.refCount=1;
    obj.data=self->data;
    return Float4_get_member(ctx, &obj, key);
}
void Float4_ptr_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if(!type_same<T4<float> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Float4Ref's get method expects Float4Ref as first argument."));
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=Float4_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Float4_typeID;
    obj.refCount=1;
    obj.data=self->data;
    Float4_set_member(ctx, &obj, key, value);
}
scripting::Value *Matrix4x4_ptr_new(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    List<scripting::Value *> args2 = args.copy();
    args2[0]=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix4x4;
    scripting::NativeObject *obj=(scripting::NativeObject*)Matrix4x4_new(ctx, args2);
    obj->funcs=Matrix4x4_ptr_funcs;
    obj->typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix4x4_ptr_typeID;
    setAllocInfo(obj->data, AllocInfo(true, false));
    return (scripting::Value*)obj;
}
scripting::Value *Matrix4x4_ptr_deref(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix4x4Ref::deref expects one argument."));
    scripting::Value*self=args[0];
    if(!type_same<Matrix4x4 *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4Ref::deref expects Matrix4x4Ref as first argument."));
    return create_val<Matrix4x4>::f(ctx, *(Matrix4x4 *)((scripting::NativeObject *)self)->data);
}
scripting::Value *Matrix4x4_ptr_set(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=2)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix4x4::refset expects two arguments."));
    scripting::Value*self=args[0];
    if(!type_same<Matrix4x4 *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4Ref::refset expects Matrix4x4Ref as first argument."));
    *((Matrix4x4 *)((scripting::NativeObject *)self)->data) = val_to_c<Matrix4x4>::f(ctx,args[1]);
    return scripting::createNil();
}
scripting::Value *Matrix4x4_ptr_copy(scripting::Context*, scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(Matrix4x4_ptr_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(Matrix4x4_ptr_funcs,self->data,self->typeID);
}
void Matrix4x4_ptr_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<Matrix4x4 *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4Ref::__del__ expects Matrix4x4Ref as first argument."));
    SCRIPT_DELETE(Matrix4x4, (Matrix4x4 *)self->data);
}
scripting::Value *Matrix4x4_ptr_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if(!type_same<Matrix4x4 *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4Ref's get method expects Matrix4x4Ref as first argument."));
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
        if(keyStr=="__typeID__")
            return scripting::createInt(self->typeID);
        else if(keyStr=="__name__")
            return scripting::createString("Matrix4x4Ptr");
        else if(keyStr=="__new__")
            return scripting::createNativeFunction(Matrix4x4_ptr_new);
        else if(keyStr=="__call__")
            return scripting::createNativeFunction(Matrix4x4_ptr_new);
        else
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
        if(keyStr=="deref") return scripting::createNativeFunction(Matrix4x4_ptr_deref);
        if(keyStr=="refset") return scripting::createNativeFunction(Matrix4x4_ptr_set);
        }
    }
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=Matrix4x4_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix4x4_typeID;
    obj.refCount=1;
    obj.data=self->data;
    return Matrix4x4_get_member(ctx, &obj, key);
}
void Matrix4x4_ptr_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if(!type_same<Matrix4x4 *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix4x4Ref's get method expects Matrix4x4Ref as first argument."));
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=Matrix4x4_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix4x4_typeID;
    obj.refCount=1;
    obj.data=self->data;
    Matrix4x4_set_member(ctx, &obj, key, value);
}
scripting::Value *UInt4_ptr_new(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    List<scripting::Value *> args2 = args.copy();
    args2[0]=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt4;
    scripting::NativeObject *obj=(scripting::NativeObject*)UInt4_new(ctx, args2);
    obj->funcs=UInt4_ptr_funcs;
    obj->typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt4_ptr_typeID;
    setAllocInfo(obj->data, AllocInfo(true, false));
    return (scripting::Value*)obj;
}
scripting::Value *UInt4_ptr_deref(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4Ref::deref expects one argument."));
    scripting::Value*self=args[0];
    if(!type_same<T4<uint32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4Ref::deref expects UInt4Ref as first argument."));
    return create_val<T4<uint32_t>>::f(ctx, *(T4<uint32_t> *)((scripting::NativeObject *)self)->data);
}
scripting::Value *UInt4_ptr_set(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=2)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"UInt4::refset expects two arguments."));
    scripting::Value*self=args[0];
    if(!type_same<T4<uint32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4Ref::refset expects UInt4Ref as first argument."));
    *((T4<uint32_t> *)((scripting::NativeObject *)self)->data) = val_to_c<T4<uint32_t>>::f(ctx,args[1]);
    return scripting::createNil();
}
scripting::Value *UInt4_ptr_copy(scripting::Context*, scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(UInt4_ptr_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(UInt4_ptr_funcs,self->data,self->typeID);
}
void UInt4_ptr_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<T4<uint32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4Ref::__del__ expects UInt4Ref as first argument."));
    SCRIPT_DELETE(T4<uint32_t>, (T4<uint32_t> *)self->data);
}
scripting::Value *UInt4_ptr_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if(!type_same<T4<uint32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4Ref's get method expects UInt4Ref as first argument."));
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
        if(keyStr=="__typeID__")
            return scripting::createInt(self->typeID);
        else if(keyStr=="__name__")
            return scripting::createString("UInt4Ptr");
        else if(keyStr=="__new__")
            return scripting::createNativeFunction(UInt4_ptr_new);
        else if(keyStr=="__call__")
            return scripting::createNativeFunction(UInt4_ptr_new);
        else
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
        if(keyStr=="deref") return scripting::createNativeFunction(UInt4_ptr_deref);
        if(keyStr=="refset") return scripting::createNativeFunction(UInt4_ptr_set);
        }
    }
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=UInt4_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt4_typeID;
    obj.refCount=1;
    obj.data=self->data;
    return UInt4_get_member(ctx, &obj, key);
}
void UInt4_ptr_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if(!type_same<T4<uint32_t> *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"UInt4Ref's get method expects UInt4Ref as first argument."));
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=UInt4_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->UInt4_typeID;
    obj.refCount=1;
    obj.data=self->data;
    UInt4_set_member(ctx, &obj, key, value);
}
scripting::Value *AABB_ptr_new(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    List<scripting::Value *> args2 = args.copy();
    args2[0]=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->AABB;
    scripting::NativeObject *obj=(scripting::NativeObject*)AABB_new(ctx, args2);
    obj->funcs=AABB_ptr_funcs;
    obj->typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->AABB_ptr_typeID;
    setAllocInfo(obj->data, AllocInfo(true, false));
    return (scripting::Value*)obj;
}
scripting::Value *AABB_ptr_deref(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"AABBRef::deref expects one argument."));
    scripting::Value*self=args[0];
    if(!type_same<AABB *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"AABBRef::deref expects AABBRef as first argument."));
    return create_val<AABB>::f(ctx, *(AABB *)((scripting::NativeObject *)self)->data);
}
scripting::Value *AABB_ptr_set(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=2)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"AABB::refset expects two arguments."));
    scripting::Value*self=args[0];
    if(!type_same<AABB *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"AABBRef::refset expects AABBRef as first argument."));
    *((AABB *)((scripting::NativeObject *)self)->data) = val_to_c<AABB>::f(ctx,args[1]);
    return scripting::createNil();
}
scripting::Value *AABB_ptr_copy(scripting::Context*, scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(AABB_ptr_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(AABB_ptr_funcs,self->data,self->typeID);
}
void AABB_ptr_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<AABB *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"AABBRef::__del__ expects AABBRef as first argument."));
    SCRIPT_DELETE(AABB, (AABB *)self->data);
}
scripting::Value *AABB_ptr_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if(!type_same<AABB *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"AABBRef's get method expects AABBRef as first argument."));
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
        if(keyStr=="__typeID__")
            return scripting::createInt(self->typeID);
        else if(keyStr=="__name__")
            return scripting::createString("AABBPtr");
        else if(keyStr=="__new__")
            return scripting::createNativeFunction(AABB_ptr_new);
        else if(keyStr=="__call__")
            return scripting::createNativeFunction(AABB_ptr_new);
        else
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
        if(keyStr=="deref") return scripting::createNativeFunction(AABB_ptr_deref);
        if(keyStr=="refset") return scripting::createNativeFunction(AABB_ptr_set);
        }
    }
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=AABB_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->AABB_typeID;
    obj.refCount=1;
    obj.data=self->data;
    return AABB_get_member(ctx, &obj, key);
}
void AABB_ptr_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if(!type_same<AABB *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"AABBRef's get method expects AABBRef as first argument."));
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=AABB_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->AABB_typeID;
    obj.refCount=1;
    obj.data=self->data;
    AABB_set_member(ctx, &obj, key, value);
}
scripting::Value *Matrix3x3_ptr_new(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    List<scripting::Value *> args2 = args.copy();
    args2[0]=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix3x3;
    scripting::NativeObject *obj=(scripting::NativeObject*)Matrix3x3_new(ctx, args2);
    obj->funcs=Matrix3x3_ptr_funcs;
    obj->typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix3x3_ptr_typeID;
    setAllocInfo(obj->data, AllocInfo(true, false));
    return (scripting::Value*)obj;
}
scripting::Value *Matrix3x3_ptr_deref(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix3x3Ref::deref expects one argument."));
    scripting::Value*self=args[0];
    if(!type_same<Matrix3x3 *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix3x3Ref::deref expects Matrix3x3Ref as first argument."));
    return create_val<Matrix3x3>::f(ctx, *(Matrix3x3 *)((scripting::NativeObject *)self)->data);
}
scripting::Value *Matrix3x3_ptr_set(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()!=2)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"Matrix3x3::refset expects two arguments."));
    scripting::Value*self=args[0];
    if(!type_same<Matrix3x3 *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix3x3Ref::refset expects Matrix3x3Ref as first argument."));
    *((Matrix3x3 *)((scripting::NativeObject *)self)->data) = val_to_c<Matrix3x3>::f(ctx,args[1]);
    return scripting::createNil();
}
scripting::Value *Matrix3x3_ptr_copy(scripting::Context*, scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(Matrix3x3_ptr_funcs,NULL,self->typeID);
    else
         return scripting::createNativeObject(Matrix3x3_ptr_funcs,self->data,self->typeID);
}
void Matrix3x3_ptr_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(!type_same<Matrix3x3 *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix3x3Ref::__del__ expects Matrix3x3Ref as first argument."));
    SCRIPT_DELETE(Matrix3x3, (Matrix3x3 *)self->data);
}
scripting::Value *Matrix3x3_ptr_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if(!type_same<Matrix3x3 *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix3x3Ref's get method expects Matrix3x3Ref as first argument."));
    if (key->type==scripting::ValueType::StringType)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
        if(keyStr=="__typeID__")
            return scripting::createInt(self->typeID);
        else if(keyStr=="__name__")
            return scripting::createString("Matrix3x3Ptr");
        else if(keyStr=="__new__")
            return scripting::createNativeFunction(Matrix3x3_ptr_new);
        else if(keyStr=="__call__")
            return scripting::createNativeFunction(Matrix3x3_ptr_new);
        else
            ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
        if(keyStr=="deref") return scripting::createNativeFunction(Matrix3x3_ptr_deref);
        if(keyStr=="refset") return scripting::createNativeFunction(Matrix3x3_ptr_set);
        }
    }
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=Matrix3x3_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix3x3_typeID;
    obj.refCount=1;
    obj.data=self->data;
    return Matrix3x3_get_member(ctx, &obj, key);
}
void Matrix3x3_ptr_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if(!type_same<Matrix3x3 *>::f(ctx, (scripting::Value *)self))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Matrix3x3Ref's get method expects Matrix3x3Ref as first argument."));
    scripting::NativeObject obj;
    obj.head.type=scripting::ValueType::NativeObject;
    obj.funcs=Matrix3x3_funcs;
    obj.typeID=((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->Matrix3x3_typeID;
    obj.refCount=1;
    obj.data=self->data;
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
    ext->Int3_typeID = typeID;
    ext->Int3 = scripting::createNativeObject(Int3_funcs, NULL, typeID);
    engine->getGlobalVars().set("Int3", ext->Int3);
    
    typeID = engine->createNewTypeID();
    ext->Int3_ptr_typeID = typeID;
    ext->Int3_ptr = scripting::createNativeObject(Int3_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("Int3Ref", ext->Int3_ptr);
    
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

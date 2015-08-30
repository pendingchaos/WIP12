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


struct BindingsExt
{
    int64_t AABB_typeID;
};

#include <stdint.h>

#include "scripting/vm/engine.h"
#include "scripting/vm/context.h"
#include "scripting/vm/bytecode.h"
#include "scripting/vm/types.h"
#include "scripting/parser.h"
#include "scripting/bytecodegen.h"

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
        if (head->type == scripting::ValueType::String)
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
TYPE_SAME_HELPER(String, String)

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
scripting::Value *AABB_copy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(self->data==NULL)
        return scripting::createNativeObject(AABB_funcs,NULL,self->typeID);
    else
        return scripting::createNativeObject(AABB_funcs,NEW(AABB,*((AABB*)self->data)),self->typeID);
}

void AABB_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    DELETE(AABB,self->data);
}

scripting::Value *AABB_new(scripting::Context*ctx,const List<scripting::Value *>&args)
{
    if(args.getCount()!=1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"AABB's constructor expects one argument."));
    if(!type_same<AABB>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"AABB's constructor expects AABB as first argument."));
    if(args.getCount()==1)
        if(true)
            return scripting::createNativeObject(AABB_funcs,NEW(AABB),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->AABB_typeID);
    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for AABB's constructor."));
    return scripting::createNil();
}

scripting::Value *AABB_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    if (key->type==scripting::ValueType::String)
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
             else
                ctx->throwException(scripting::createException(scripting::ExcType::KeyError,"Unknown member."));
        }
    }
    return scripting::createNil();
}

void AABB_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    if (key->type==scripting::ValueType::String)
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

scripting::Value *AABB_transform(scripting::Context*ctx,const List<scripting::Value*>&args)
{
    if(args.getCount()<1)
        ctx->throwException(scripting::createException(scripting::ExcType::ValueError,"AABB::transform expects at least one argument."));
    AABB*self;
    if(!type_same<AABB>::f(ctx, args[0]))
        ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"AABB::transform expects AABB as first argument."));
    else
        self=(AABB*)((scripting::NativeObject*)args[0])->data;

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

    ctx->throwException(scripting::createException(scripting::ExcType::TypeError,"Unable to find overload for AABB::grow."));
    return scripting::createNil();
}

void *initBindings(scripting::Engine *engine, void *data)
{
    BindingsExt *ext = NEW(BindingsExt);

    int64_t typeID;
    
    typeID = engine->createNewTypeID();
    ext->AABB_typeID = typeID;
    engine->getGlobalVars().set("AABB", scripting::createNativeObject(AABB_funcs, NULL, typeID));
    
    return ext;
}

void deinitBindings(scripting::Engine *engine, void *data)
{
    DELETE(BindingsExt, data);
}

void registerBindings(scripting::Engine *engine)
{
    scripting::Extension ext;

    ext.init = initBindings;
    ext.deinit = deinitBindings;

    engine->addExtension("bindings", ext);
}

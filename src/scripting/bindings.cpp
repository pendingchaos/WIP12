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
struct ref_to_c {};

#define REF_TO_C_INT(T, T2, min, max) template <>struct ref_to_c<T2>{    static T f(scripting::Context *ctx, const scripting::Ref& ref)    {        scripting::RefManager *refMgr = ctx->getEngine()->getRefMgr();        scripting::Value *head = refMgr->translate(ref);                int64_t v;                if (head->type == scripting::ValueType::Int)        {            v = ((scripting::IntValue *)head)->value;        } else if (head->type == scripting::ValueType::Float)        {            v = ((scripting::FloatValue *)head)->value;        } else        {            ctx->throwException(refMgr->createException(scripting::ExcType::TypeError, "Value can not be converted to int."));        }                if (v < min or v > max)        {            ctx->throwException(refMgr->createException(scripting::ExcType::TypeError, "Value out of bounds."));        }                return v;    }};

REF_TO_C_INT(uint8_t, uint8_t, 0, UINT8_MAX)
REF_TO_C_INT(int8_t, int8_t, INT8_MIN, INT8_MAX)
REF_TO_C_INT(uint16_t, uint16_t, 0, UINT16_MAX)
REF_TO_C_INT(int16_t, int16_t, INT16_MIN, INT16_MAX)
REF_TO_C_INT(uint32_t, uint32_t, 0, UINT32_MAX)
REF_TO_C_INT(int32_t, int32_t, INT32_MIN, INT32_MAX)
REF_TO_C_INT(uint64_t, uint64_t, 0, UINT64_MAX)
REF_TO_C_INT(int64_t, int64_t, INT64_MIN, INT64_MAX)
REF_TO_C_INT(uint8_t, const uint8_t&, 0, UINT8_MAX)
REF_TO_C_INT(int8_t, const int8_t&, INT8_MIN, INT8_MAX)
REF_TO_C_INT(uint16_t, const uint16_t&, 0, UINT16_MAX)
REF_TO_C_INT(int16_t, const int16_t&, INT16_MIN, INT16_MAX)
REF_TO_C_INT(uint32_t, const uint32_t&, 0, UINT32_MAX)
REF_TO_C_INT(int32_t, const int32_t&, INT32_MIN, INT32_MAX)
REF_TO_C_INT(uint64_t, const uint64_t&, 0, UINT64_MAX)
REF_TO_C_INT(int64_t, const int64_t&, INT64_MIN, INT64_MAX)

template <>
struct ref_to_c<float>
{
    static float f(scripting::Context *ctx, const scripting::Ref& ref)
    {
        scripting::RefManager *refMgr = ctx->getEngine()->getRefMgr();
        scripting::Value *head = refMgr->translate(ref);
        
        float v;
        
        if (head->type == scripting::ValueType::Int)
        {
            v = ((scripting::IntValue *)head)->value;
        } else if (head->type == scripting::ValueType::Float)
        {
            v = ((scripting::FloatValue *)head)->value;
        } else
        {
            ctx->throwException(refMgr->createException(scripting::ExcType::TypeError, "Value can not be converted to float."));
        }
        
        return v;
    }
};

template <>
struct ref_to_c<double>
{
    static double f(scripting::Context *ctx, const scripting::Ref& ref)
    {
        scripting::RefManager *refMgr = ctx->getEngine()->getRefMgr();
        scripting::Value *head = refMgr->translate(ref);
        
        double v;
        
        if (head->type == scripting::ValueType::Int)
        {
            v = ((scripting::IntValue *)head)->value;
        } else if (head->type == scripting::ValueType::Float)
        {
            v = ((scripting::FloatValue *)head)->value;
        } else
        {
            ctx->throwException(refMgr->createException(scripting::ExcType::TypeError, "Value can not be converted to float."));
        }
        
        return v;
    }
};

template <>
struct ref_to_c<bool>
{
    static bool f(scripting::Context *ctx, const scripting::Ref& ref)
    {
        scripting::RefManager *refMgr = ctx->getEngine()->getRefMgr();
        scripting::Value *head = refMgr->translate(ref);
        
        if (head->type == scripting::ValueType::Boolean)
        {
            return ((scripting::BooleanValue *)head)->value;
        } else
        {
            ctx->throwException(refMgr->createException(scripting::ExcType::TypeError, "Value can not be converted to bool."));
        }
    }
};

template <>
struct ref_to_c<String>
{
    static String f(scripting::Context *ctx, const scripting::Ref& ref)
    {
        scripting::RefManager *refMgr = ctx->getEngine()->getRefMgr();
        scripting::Value *head = refMgr->translate(ref);
        
        if (head->type == scripting::ValueType::String)
        {
            return ((scripting::StringValue *)head)->value;
        } else
        {
            ctx->throwException(refMgr->createException(scripting::ExcType::TypeError, "Value can not be converted to string."));
        }
    }
};

template <>
struct ref_to_c<scripting::Ref>
{
    static scripting::Ref f(scripting::Context *ctx, const scripting::Ref& ref)
    {
        return ctx->getEngine()->getRefMgr()->createCopy(ctx, ref);
    }
};

template <typename T>
struct ref_to_c<T&> {};

template <typename T>
struct ref_to_c<const T&> {
    static T f(scripting::Context *ctx, const scripting::Ref& ref)
    {
        return ref_to_c<T>::f(ctx, ref);
    }
};

template <typename T>
struct ref_to_c<T *> {};

template <typename T>
struct create_ref {};

#define CREATE_REF(T, func) template <>struct create_ref<T>{    static scripting::Ref f(scripting::Context *ctx, const T& v)    {        return ctx->getEngine()->getRefMgr()->func(v);    }};

template <>
struct create_ref<scripting::Ref>
{
    static scripting::Ref f(scripting::Context *ctx, const scripting::Ref& ref)
    {
        return ctx->getEngine()->getRefMgr()->createCopy(ctx, ref);
    }
};

CREATE_REF(uint8_t, createInt)
CREATE_REF(int8_t, createInt)
CREATE_REF(uint16_t, createInt)
CREATE_REF(int16_t, createInt)
CREATE_REF(uint32_t, createInt)
CREATE_REF(int32_t, createInt)
CREATE_REF(uint64_t, createInt)
CREATE_REF(int64_t, createInt)
CREATE_REF(float, createFloat)
CREATE_REF(double, createFloat)
CREATE_REF(bool, createBoolean)
CREATE_REF(String, createString)

template <typename T>
struct type_same;

template <typename T>
struct type_same<const T&>
{
    static bool f(scripting::Context *ctx, const scripting::Ref& ref)
    {
        return type_same<T>::f(ctx, ref);
    }
};

template <>
struct type_same<scripting::Ref>
{
    static bool f(scripting::Context *ctx, const scripting::Ref& ref)
    {
        return true;
    }
};

#define TYPE_SAME_HELPER(T, enumValue) template <>struct type_same<T>{    static bool f(scripting::Context *ctx, const scripting::Ref& ref)    {        scripting::RefManager *refMgr = ctx->getEngine()->getRefMgr();        scripting::Value *head = refMgr->translate(ref);        return head->type == scripting::ValueType::enumValue;    }};

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

scripting::Ref AABB_copy(scripting::Context*, scripting::NativeObject*);
void AABB_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Ref AABB_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void AABB_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs AABB_funcs={
    .copy = AABB_copy,
    .destroy = AABB_destroy,
    .getMember = AABB_get_member,
    .setMember = AABB_set_member
};
template <>
struct create_ref<AABB>
{
    static scripting::Ref f(scripting::Context*ctx,const AABB&obj)
    {
        return ctx->getEngine()->getRefMgr()->createNativeObject(AABB_funcs,NEW(AABB, obj),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->AABB_typeID);
    }
};
template <>
struct ref_to_c<AABB>
{
    static AABB f(scripting::Context*ctx,const scripting::Ref&ref)
    {
        scripting::RefManager*refMgr=ctx->getEngine()->getRefMgr();
        scripting::Value*head=refMgr->translate(ref);
        if(head->type==scripting::ValueType::NativeObject)
        {
            scripting::NativeObject*obj=(scripting::NativeObject*)head;
            if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->AABB_typeID)
                return *((AABB*)obj->data);
            else
                ctx->throwException(refMgr->createException(scripting::ExcType::TypeError,"Value can not be converted to AABB."));
        } else
            ctx->throwException(refMgr->createException(scripting::ExcType::TypeError,"Value can not be converted to AABB."));
    }
};
template <>
struct type_same<AABB>
{
    static bool f(scripting::Context *ctx,const scripting::Ref& ref)
    {
        scripting::RefManager*refMgr=ctx->getEngine()->getRefMgr();
        scripting::Value*head=refMgr->translate(ref);
        if(head->type==scripting::ValueType::NativeObject)
            return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->AABB_typeID;
        else
            return false;
    }
};

scripting::Ref AABB_transform(scripting::Context *ctx, const List<scripting::Ref>& args);
scripting::Ref AABB_extend(scripting::Context *ctx, const List<scripting::Ref>& args);
scripting::Ref AABB_grow(scripting::Context *ctx, const List<scripting::Ref>& args);
scripting::Ref AABB_copy(scripting::Context*ctx,scripting::NativeObject*self)
{
    if(self->data==NULL)
        return ctx->getEngine()->getRefMgr()->createNativeObject(AABB_funcs,NULL,self->typeID);
    else
        return ctx->getEngine()->getRefMgr()->createNativeObject(AABB_funcs,NEW(AABB,*((AABB*)self->data)),self->typeID);
}

void AABB_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
    DELETE(AABB,self->data);
}

scripting::Ref AABB_new(scripting::Context*ctx, const List<scripting::Ref>&args)
{
    scripting::RefManager *refMgr = ctx->getEngine()->getRefMgr();
    if(args.getCount()!=1)
        ctx->throwException(refMgr->createException(scripting::ExcType::ValueError,"AABB's constructor expects one argument."));
    if(!type_same<AABB>::f(ctx, args[0]))
        ctx->throwException(refMgr->createException(scripting::ExcType::TypeError,"AABB's constructor expects AABB as first argument."));
    if(args.getCount()==1)
        if(true)
            return refMgr->createNativeObject(AABB_funcs,NEW(AABB),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->AABB_typeID);
    ctx->throwException(refMgr->createException(scripting::ExcType::TypeError,"Unable to find overload for AABB's constructor."));
    return refMgr->createNil();
}

scripting::Ref AABB_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
    scripting::RefManager*refMgr=ctx->getEngine()->getRefMgr();
    if (key->type==scripting::ValueType::String)
    {
        String keyStr=((scripting::StringValue *)key)->value;
        if(self->data==NULL)
        {
            if(keyStr=="__typeID__")
                return refMgr->createInt(self->typeID);
            else if(keyStr=="__name__")
                return refMgr->createString("AABB");
            else if(keyStr=="__new__")
                return refMgr->createNativeFunction(AABB_new);
            else if(keyStr=="__call__")
                return refMgr->createNativeFunction(AABB_new);
            else
                ctx->throwException(refMgr->createException(scripting::ExcType::KeyError,"Unknown member."));
        } else
        {
            if(keyStr=="__classTypeID__")
                return refMgr->createInt(self->typeID);
            else if(keyStr=="__init__")
                return refMgr->createNativeFunction(AABB_new);
             else if (keyStr == "transform")
                return refMgr->createNativeFunction(AABB_transform);
             else if (keyStr == "extend")
                return refMgr->createNativeFunction(AABB_extend);
             else if (keyStr == "grow")
                return refMgr->createNativeFunction(AABB_grow);
             else
                ctx->throwException(refMgr->createException(scripting::ExcType::KeyError,"Unknown member."));
        }
    }
    return refMgr->createNil();
}

void AABB_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
    scripting::RefManager*refMgr=ctx->getEngine()->getRefMgr();
    if (key->type==scripting::ValueType::String)
    {
        String keyStr=((scripting::StringValue*)key)->value;
        if(self->data==NULL)
            ctx->throwException(refMgr->createException(scripting::ExcType::KeyError,"Native classes are read-only."));
        else
        {
            if(0) {} else
                ctx->throwException(refMgr->createException(scripting::ExcType::KeyError,"Unknown member or member if read-only."));
        }
    }
}

scripting::Ref AABB_transform(scripting::Context*ctx,const List<scripting::Ref>&args)
{
    scripting::RefManager*refMgr=ctx->getEngine()->getRefMgr();
    if(args.getCount()<1)
        ctx->throwException(refMgr->createException(scripting::ExcType::ValueError,"AABB::transform expects at least one argument."));
    AABB*self;
    if(!type_same<AABB>::f(ctx, args[0]))
        ctx->throwException(refMgr->createException(scripting::ExcType::TypeError,"AABB::transform expects AABB as first argument."));
    else
        self=(AABB*)((scripting::NativeObject*)refMgr->translate(args[0]))->data;

    ctx->throwException(refMgr->createException(scripting::ExcType::TypeError,"Unable to find overload for AABB::transform."));
    return refMgr->createNil();
}

scripting::Ref AABB_extend(scripting::Context*ctx,const List<scripting::Ref>&args)
{
    scripting::RefManager*refMgr=ctx->getEngine()->getRefMgr();
    if(args.getCount()<1)
        ctx->throwException(refMgr->createException(scripting::ExcType::ValueError,"AABB::extend expects at least one argument."));
    AABB*self;
    if(!type_same<AABB>::f(ctx, args[0]))
        ctx->throwException(refMgr->createException(scripting::ExcType::TypeError,"AABB::extend expects AABB as first argument."));
    else
        self=(AABB*)((scripting::NativeObject*)refMgr->translate(args[0]))->data;

    if(args.getCount()==2)
        if(1&&type_same<const AABB &>::f(ctx,args[1]))
        {
            ( self->extend(ref_to_c<const AABB &>::f(ctx,args[1])));
            return refMgr->createNil();
        }
    ctx->throwException(refMgr->createException(scripting::ExcType::TypeError,"Unable to find overload for AABB::extend."));
    return refMgr->createNil();
}

scripting::Ref AABB_grow(scripting::Context*ctx,const List<scripting::Ref>&args)
{
    scripting::RefManager*refMgr=ctx->getEngine()->getRefMgr();
    if(args.getCount()<1)
        ctx->throwException(refMgr->createException(scripting::ExcType::ValueError,"AABB::grow expects at least one argument."));
    AABB*self;
    if(!type_same<AABB>::f(ctx, args[0]))
        ctx->throwException(refMgr->createException(scripting::ExcType::TypeError,"AABB::grow expects AABB as first argument."));
    else
        self=(AABB*)((scripting::NativeObject*)refMgr->translate(args[0]))->data;

    ctx->throwException(refMgr->createException(scripting::ExcType::TypeError,"Unable to find overload for AABB::grow."));
    return refMgr->createNil();
}

void *initBindings(scripting::Engine *engine, void *data)
{
    scripting::RefManager *refMgr = engine->getRefMgr();

    BindingsExt *ext = NEW(BindingsExt);

    int64_t typeID;
    
    typeID = engine->createNewTypeID();
    ext->AABB_typeID = typeID;
    engine->getGlobalVars().set("AABB", refMgr->createNativeObject(AABB_funcs, NULL, typeID));
    
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

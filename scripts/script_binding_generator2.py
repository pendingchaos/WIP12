import clang.cindex
import os
import copy

minimize = False

def s(v):
    if minimize:
        return v.replace("?", "").replace("\n", "")
    else:
        return v.replace("?", " ")

files = [
"../include/file.h",
"../include/error.h",
"../include/memory.h",
"../include/globals.h",
"../include/logging.h",
"../include/backtrace.h",
"../include/filesystem.h",
"../include/application.h",
"../include/misc_macros.h",
"../include/endian_utils.h",
"../include/scene/scene.h",
"../include/scene/entity.h",
"../include/scene/transform.h",
"../include/graphics/gfxapi.h",
"../include/graphics/gfxmesh.h",
"../include/graphics/gfxmodel.h",
"../include/graphics/gfxshader.h",
"../include/graphics/gfxtexture.h",
"../include/graphics/gfxmaterial.h",
"../include/graphics/gfxbuffer.h",
"../include/graphics/gfxdefs.h",
"../include/graphics/gfxrenderer.h",
"../include/graphics/camera.h",
"../include/graphics/gfxdebugdrawer.h",
"../include/graphics/font.h",
"../include/graphics/gputimer.h",
"../include/scripting/script.h",
"../include/resource/resource.h",
"../include/resource/resourcemanager.h",
"../include/math/t2.h",
"../include/math/t3.h",
"../include/math/t4.h",
"../include/math/matrix3x3.h",
"../include/math/matrix4x4.h",
"../include/math/quaternion.h",
"../include/math/aabb.h",
"../include/containers/list.h",
"../include/containers/string.h",
"../include/containers/hashmap.h",
"../include/containers/resizabledata.h",
"../include/physics/physicsworld.h",
"../include/physics/rigidbody.h",
"../include/physics/physicsshape.h",
"../include/physics/physicsdebugdrawer.h",
"../include/platform.h",
"../include/audio/audio.h",
"../include/audio/audioworld.h",
"../include/audio/audiodevice.h"]

print "Running preprocessor"

pipe = os.popen("g++ -E -o.script_includes.h -I../include `sdl2-config --cflags` `pkg-config bullet --cflags` `freetype-config --cflags` -std=gnu++11 -xc++ -", "w")
pipe.write("#define SCRIPT_BINDING_GENERATOR\n")
pipe.write("\n".join("#include \"%s\"" % file_ for file_ in files))
pipe.close()

class Type(object):
    def __init__(self, type_):
        self.pod = type_.is_pod()
        self.const = type_.is_const_qualified()
        self.type_ = type_.spelling
    
    def to_string(self):
        return ("const" if self.const else "") + self.type_

class Argument(object):
    def __init__(self, cursor, index):
        self.index = index
        self.type_ = Type(cursor.type)
        self.doc = ""

        if len(cursor.spelling) == 0:
            self.name = "_param%d" % index
        else:
            self.name = cursor.spelling

class Function(object):
    def __init__(self, cursor):
        self.name = cursor.spelling
        self.return_type = Type(cursor.type.get_result())
        self.variadic = clang.cindex.conf.lib.clang_isFunctionTypeVariadic(cursor.type)
        self.definition = cursor.is_definition()
        self.args = []
        self.doc = ""
        self.exceptions = {}
        self.getter = False
        self.setter = False
        self.template_types = {}
        self.script_public = False
        self.arg_convs = {}

        i = 0

        for arg in cursor.get_arguments():
            self.args.append(Argument(arg, i))

            i += 1
        
        for c in cursor.get_children():
            if c.kind == clang.cindex.CursorKind.ANNOTATE_ATTR:
                if c.displayname.startswith("argdoc"):
                    argname = c.displayname[6:].split(" ")[0]
                    doc = c.displayname[6+len(argname)+1:]
                    
                    for arg in self.args:
                        if arg.name == argname:
                            arg.doc = doc
                elif c.displayname.startswith("descdoc"):
                    self.doc = c.displayname[7:]
                elif c.displayname.startswith("excdoc"):
                    exc_type = c.displayname[6:].split(" ")[0]
                    reason = c.displayname[6+len(exc_type)+1:]
                    
                    self.exceptions[exc_type] = reason
                elif c.displayname.startswith("getter"):
                    self.getter = True
                elif c.displayname.startswith("setter"):
                    self.setter = True
                elif c.displayname.startswith("templatetypes"):
                    for type_, name in [tuple(v.split(":")) for v in c.displayname[13:].split(" ")]:
                        self.template_types[type_] = name
                elif c.displayname == "bind":
                    self.script_public = True
                elif c.displayname.startswith("argconv"):
                    parts = c.displayname[7:].split(":")
                    
                    index = int(parts[0])
                    func = parts[1]
                    
                    self.arg_convs[index] = func

class Method(Function):
    def __init__(self, class_, cursor):
        Function.__init__(self, cursor)

        self.class_ = class_
        self.static = cursor.is_static_method()
        self.const = clang.cindex.conf.lib.clang_CXXMethod_isConst(cursor) != 0
        self.virtual = clang.cindex.conf.lib.clang_CXXMethod_isVirtual(cursor) != 0
        self.pure_virtual = clang.cindex.conf.lib.clang_CXXMethod_isPureVirtual(cursor) != 0

        self.constructor = self.name == self.class_.name
        self.destructor = self.name == "~"+self.class_.name
        
        self.script_public = True
        
        for c in cursor.get_children():
            if c.kind == clang.cindex.CursorKind.ANNOTATE_ATTR:
                if c.displayname == "nobind":
                    self.script_public = False

class Property(object):
    def __init__(self, class_, cursor):
        self.class_ = class_
        
        self.type = Type(cursor.type)
        self.name = cursor.spelling
        self.script_public = True
        
        for c in cursor.get_children():
            if c.kind == clang.cindex.CursorKind.ANNOTATE_ATTR:
                if c.displayname == "nobind":
                    self.script_public = False

class Class(object):
    def __init__(self, cursor):
        self.name = cursor.spelling
        self.code_name = cursor.spelling

        self.methods = []
        self.classes = []
        self.constructors = []
        self.destructors = []
        self.doc = ""
        self.script_public = False
        self.properties = []
        
        for child in cursor.get_children():
            if not child.access_specifier in [clang.cindex.AccessSpecifier.PUBLIC,
                                              clang.cindex.AccessSpecifier.INVALID]:
                continue

            if child.kind == clang.cindex.CursorKind.CXX_METHOD:
                self.methods.append(Method(self, child))
            elif child.kind == clang.cindex.CursorKind.FUNCTION_TEMPLATE:
                if Function(child).script_public:
                    print "Warning: Ignoring %s::%s" % (self.name, child.spelling)
            elif child.kind == clang.cindex.CursorKind.CONSTRUCTOR:
                self.constructors.append(Method(self, child))
            elif child.kind == clang.cindex.CursorKind.DESTRUCTOR:
                self.destructors.append(Method(self, child))
            elif child.kind == clang.cindex.CursorKind.FIELD_DECL:
                self.properties.append(Property(self, child))
            elif child.kind == clang.cindex.CursorKind.CLASS_DECL and\
                 child.is_definition():
                self.classes.append(Class(child))

        for c in cursor.get_children():
            if c.kind == clang.cindex.CursorKind.ANNOTATE_ATTR:
                if c.displayname.startswith("argdoc"):
                    argname = c.displayname[6:].split(" ")[0]
                    doc = c.displayname[6+len(argname)+1:]
                    
                    for arg in self.args:
                        if arg.name == argname:
                            arg.doc = doc
                elif c.displayname.startswith("descdoc"):
                    self.doc = c.displayname[7:]
                elif c.displayname == "bind":
                    self.script_public = True

def _get_classes(class_, classes):
    for class2 in class_.classes:
        classes["%s_%s" % (class_.name, class2.name)] = class2

def get_classes(cursor):
    classes = {}
    template_classes = {}

    for child in cursor.get_children():
        if child.kind == clang.cindex.CursorKind.CLASS_DECL:
            if child.is_definition() and\
               child.access_specifier in [clang.cindex.AccessSpecifier.PUBLIC,
                                          clang.cindex.AccessSpecifier.INVALID]:
                c = Class(child)
                
                classes[child.spelling] = c
                
                _get_classes(c, classes)
        elif child.kind == clang.cindex.CursorKind.CLASS_TEMPLATE:
            if child.is_definition() and\
               child.access_specifier in [clang.cindex.AccessSpecifier.PUBLIC,
                                          clang.cindex.AccessSpecifier.INVALID]:
                c = Class(child)
                
                template_classes[child.spelling] = c
                
                _get_classes(c, classes)
    
    for child in cursor.get_children():
        if child.kind == clang.cindex.CursorKind.VAR_DECL:
            for c in child.get_children():
                if c.kind == clang.cindex.CursorKind.ANNOTATE_ATTR:
                    if c.displayname.startswith("templatetypes"):
                        a, b = c.displayname[13:].split(";")
                        for type_, name in [tuple(v.split(":")) for v in b.split(" ")]:
                            c = copy.copy(template_classes[a])
                            
                            c.name = name
                            c.code_name = a + type_
                            
                            classes[name] = c
                    elif c.displayname.startswith("classbind"):
                        name = c.displayname[9:]
                        
                        try:
                            classes[name].script_public = True
                        except KeyError:
                            template_classes[name].script_public = True

    return classes

def get_functions(cursor):
    functions = {}

    for child in cursor.get_children():
        if child.kind == clang.cindex.CursorKind.FUNCTION_DECL:
            if clang.cindex.conf.lib.clang_isFunctionTypeVariadic(child.type):
                if Function(child).script_public:
                    print "Warning: Ignoring %s" % (child.spelling)
                    continue
            
            f = Function(child)
            
            if f.name in functions:
                functions[f.name].append(f)
            else:
                functions[f.name] = [f]

    return functions

print "Parsing preprocessed file."

index = clang.cindex.Index.create()

trans_unit = index.parse(".script_includes.h", ["-x", "c++", "-std=c++11"])

os.remove(".script_includes.h")

print "Generating the bindings."

classes = get_classes(trans_unit.cursor)
functions = get_functions(trans_unit.cursor)

bindings = open("../src/scripting/bindings.cpp", "w")

bindings.write("//Generated from script_binding_generator2.py. Do not edit. Edit script_binding_generator2.py instead.\n")

for file_ in files:
    bindings.write("#include \"%s\"\n" % (file_[11:]))

bindings.write("""

struct BindingsExt
{
    int64_t """)

names = []

for class_ in classes.keys():
    if classes[class_].script_public:
        names.append(class_+"_typeID")

bindings.write(", ".join(names))

bindings.write(";\n};\n\n")

bindings.write("""#include <stdint.h>

#include "scripting/vm/engine.h"
#include "scripting/vm/context.h"
#include "scripting/vm/bytecode.h"
#include "scripting/vm/types.h"
#include "scripting/parser.h"
#include "scripting/bytecodegen.h"

template <typename T>
struct ref_to_c {};

#define REF_TO_C_INT(T, T2, min, max) template <>\
struct ref_to_c<T2>\
{\
    static T f(scripting::Context *ctx, const scripting::Ref& ref)\
    {\
        scripting::RefManager *refMgr = ctx->getEngine()->getRefMgr();\
        scripting::Value *head = refMgr->translate(ref);\
        \
        int64_t v;\
        \
        if (head->type == scripting::ValueType::Int)\
        {\
            v = ((scripting::IntValue *)head)->value;\
        } else if (head->type == scripting::ValueType::Float)\
        {\
            v = ((scripting::FloatValue *)head)->value;\
        } else\
        {\
            ctx->throwException(refMgr->createException(scripting::ExcType::TypeError, "Value can not be converted to int."));\
        }\
        \
        if (v < min or v > max)\
        {\
            ctx->throwException(refMgr->createException(scripting::ExcType::TypeError, "Value out of bounds."));\
        }\
        \
        return v;\
    }\
};

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

#define CREATE_REF(T, func) template <>\
struct create_ref<T>\
{\
    static scripting::Ref f(scripting::Context *ctx, const T& v)\
    {\
        return ctx->getEngine()->getRefMgr()->func(v);\
    }\
};

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

#define TYPE_SAME_HELPER(T, enumValue) template <>\
struct type_same<T>\
{\
    static bool f(scripting::Context *ctx, const scripting::Ref& ref)\
    {\
        scripting::RefManager *refMgr = ctx->getEngine()->getRefMgr();\
        scripting::Value *head = refMgr->translate(ref);\
        return head->type == scripting::ValueType::enumValue;\
    }\
};

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

""")

#TODO: Inheritance
for class_ in classes.values():
    if not class_.script_public:
        continue

    print "Bindings will be generated for %s" % class_.name

    bindings.write(s("""scripting::Ref %s_copy(scripting::Context*,?scripting::NativeObject*);
void %s_destroy(scripting::Context*,scripting::NativeObject*);
scripting::Ref %s_get_member(scripting::Context*,scripting::NativeObject*,scripting::Value *);
void %s_set_member(scripting::Context*,scripting::NativeObject*,scripting::Value*,scripting::Value*);
static const scripting::NativeObjectFuncs %s_funcs={
????.copy = %s_copy,
????.destroy = %s_destroy,
????.getMember = %s_get_member,
????.setMember = %s_set_member
};
template <>
struct create_ref<%s>
{
????static scripting::Ref f(scripting::Context*ctx,const %s&obj)
????{
????????return ctx->getEngine()->getRefMgr()->createNativeObject(%s_funcs,NEW(%s, obj),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->%s_typeID);
????}
};
template <>
struct ref_to_c<%s>
{
????static %s f(scripting::Context*ctx,const scripting::Ref&ref)
????{
????????scripting::RefManager*refMgr=ctx->getEngine()->getRefMgr();
????????scripting::Value*head=refMgr->translate(ref);
????????if(head->type==scripting::ValueType::NativeObject)
????????{
????????????scripting::NativeObject*obj=(scripting::NativeObject*)head;
????????????if(obj->typeID==((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->%s_typeID)
????????????????return *((%s*)obj->data);
????????????else
????????????????ctx->throwException(refMgr->createException(scripting::ExcType::TypeError,"Value can not be converted to %s."));
????????} else
????????????ctx->throwException(refMgr->createException(scripting::ExcType::TypeError,"Value can not be converted to %s."));
????}
};
template <>
struct type_same<%s>
{
????static bool f(scripting::Context *ctx,const scripting::Ref& ref)
????{
????????scripting::RefManager*refMgr=ctx->getEngine()->getRefMgr();
????????scripting::Value*head=refMgr->translate(ref);
????????if(head->type==scripting::ValueType::NativeObject)
????????????return((scripting::NativeObject*)head)->typeID==((BindingsExt*)ctx->getEngine()->getExtension("bindings").data)->%s_typeID;
????????else
????????????return false;
????}
};

""") % (class_.name, class_.name, class_.name, class_.name, class_.name,
       class_.name, class_.name, class_.name, class_.name, class_.code_name,
       class_.code_name, class_.name, class_.code_name, class_.name, class_.code_name,
       class_.code_name, class_.name, class_.code_name, class_.name, class_.name,
       class_.code_name, class_.name))

    methods_ = {}

    for method in class_.methods:
        if method.name in methods_:
            continue
        methods_[method.name] = None

        bindings.write("scripting::Ref %s_%s(scripting::Context *ctx, const List<scripting::Ref>& args);\n" % (class_.name, method.name))

for class_ in classes.values():
    if not class_.script_public:
        continue

    bindings.write(s("""scripting::Ref %s_copy(scripting::Context*ctx,scripting::NativeObject*self)
{
????if(self->data==NULL)
????????return ctx->getEngine()->getRefMgr()->createNativeObject(%s_funcs,NULL,self->typeID);
????else
????????return ctx->getEngine()->getRefMgr()->createNativeObject(%s_funcs,NEW(%s,*((%s*)self->data)),self->typeID);
}

void %s_destroy(scripting::Context*ctx,scripting::NativeObject*self)
{
????DELETE(%s,self->data);
}

""") % (class_.name, class_.name, class_.name, class_.code_name, class_.code_name,
       class_.name, class_.code_name))

    if len(class_.constructors) == 0:
        bindings.write(s("""scripting::Ref %s_new(scripting::Context*ctx,const List<scripting::Ref>&args)
{
????if(args.getCount()!=1)
????????ctx->throwException(refMgr->createException(scripting::ExcType::ValueError,"%s's constructor expects one argument."));
????if(!type_same<%s>::f(ctx, args[0]))
????????ctx->throwException(refMgr->createException(scripting::ExcType::TypeError,"%s's constructor expects %s as first argument."));
????return ctx->getEngine()->getRefMgr()->createNativeObject(%s_funcs,NEW(%s),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->%s_typeID);
}

""") % (class_.name, class_.code_name, class_.name, class_.name, class_.name, class_.name, class_.code_name, class_.name))
    else:
        bindings.write(s("""scripting::Ref %s_new(scripting::Context*ctx, const List<scripting::Ref>&args)
{
????scripting::RefManager *refMgr = ctx->getEngine()->getRefMgr();
????if(args.getCount()!=1)
????????ctx->throwException(refMgr->createException(scripting::ExcType::ValueError,"%s's constructor expects one argument."));
????if(!type_same<%s>::f(ctx, args[0]))
????????ctx->throwException(refMgr->createException(scripting::ExcType::TypeError,"%s's constructor expects %s as first argument."));
""") % (class_.name, class_.name, class_.code_name, class_.name, class_.name))

        for constructor in class_.constructors:
            if not constructor.script_public:
                continue
            
            args = ["ref_to_c<%s>::f(ctx,args[%d])" % (constructor.args[j].type_.to_string(), j) for j in xrange(len(constructor.args))]

            for i in xrange(len(constructor.args)):
                if i in constructor.arg_convs:
                    args[i] = "%s(ctx,args[%d])" % (constructor.arg_convs[i], i)

            constStr = ",".join([class_.name] + args)
            
            args = ["type_same<%s>::f(ctx,args[%d])" % (constructor.args[j].type_.to_string(), j) for j in xrange(len(constructor.args))]
            
            testStr = "&&".join(["true"] + args)

            bindings.write(s("""????if(args.getCount()==%d)
????????if(%s)
????????????return refMgr->createNativeObject(%s_funcs,NEW(%s),((BindingsExt *)ctx->getEngine()->getExtension("bindings").data)->%s_typeID);
""") % (len(constructor.args)+1, testStr, class_.name, constStr, class_.name))

        bindings.write(s("""????ctx->throwException(refMgr->createException(scripting::ExcType::TypeError,"Unable to find overload for %s's constructor."));
????return refMgr->createNil();
}

""") % class_.name)

    bindings.write(s("""scripting::Ref %s_get_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key)
{
????scripting::RefManager*refMgr=ctx->getEngine()->getRefMgr();
????if (key->type==scripting::ValueType::String)
????{
????????String keyStr=((scripting::StringValue *)key)->value;
????????if(self->data==NULL)
????????{
????????????if(keyStr=="__typeID__")
????????????????return refMgr->createInt(self->typeID);
????????????else if(keyStr=="__name__")
????????????????return refMgr->createString("%s");
????????????else if(keyStr=="__new__")
????????????????return refMgr->createNativeFunction(%s_new);
????????????else if(keyStr=="__call__")
????????????????return refMgr->createNativeFunction(%s_new);
????????????else
????????????????ctx->throwException(refMgr->createException(scripting::ExcType::KeyError,"Unknown member."));
????????} else
????????{
????????????if(keyStr=="__classTypeID__")
????????????????return refMgr->createInt(self->typeID);
????????????else if(keyStr=="__init__")
????????????????return refMgr->createNativeFunction(%s_new);
????????????""") % (class_.name, class_.name, class_.name, class_.name, class_.name))

    methods_ = {}

    for method in class_.methods:
        if method.name in methods_:
            continue
        methods_[method.name] = None

        bindings.write(s(""" else if (keyStr == "%s")
????????????????return refMgr->createNativeFunction(%s_%s);
????????????""") % (method.name, class_.name, method.name))

    for property_ in class_.properties:
        if not property_.script_public:
            continue
        
        bindings.write(s(""" else if(keyStr=="%s")
????????????{
????????????????%s*obj=(%s*)self->data;
????????????????return create_ref<decltype(obj->%s)>::f(obj->%s);
????????????}""") % (property_.name, class_.code_name, class_.code_name, property_.name, property_.name))
    
    bindings.write(s(""" else
????????????????ctx->throwException(refMgr->createException(scripting::ExcType::KeyError,"Unknown member."));
????????}
????}
????return refMgr->createNil();
}

"""))

    bindings.write(s("""void %s_set_member(scripting::Context*ctx,scripting::NativeObject*self,scripting::Value*key,scripting::Value*value)
{
????scripting::RefManager*refMgr=ctx->getEngine()->getRefMgr();
????if (key->type==scripting::ValueType::String)
????{
????????String keyStr=((scripting::StringValue*)key)->value;
????????if(self->data==NULL)
????????????ctx->throwException(refMgr->createException(scripting::ExcType::KeyError,"Native classes are read-only."));
????????else
????????{
????????????if(0) {}""") % (class_.name))

    for property_ in class_.properties:
        if not property_.script_public:
            continue
        
        bindings.write(s(""" else if(keyStr=="%s")
????????????{
????????????????%s*obj=(%s*)self->data;
????????????????obj->%s=ref_to_c<decltype(obj->%s)>::f(value->ref);
????????????}""") % (property_.name, class_.code_name, class_.code_name, property_.name, property_.name))
    
    bindings.write(s(""" else
????????????????ctx->throwException(refMgr->createException(scripting::ExcType::KeyError,"Unknown member or member if read-only."));
????????}
????}
}

"""))

    methods = {}

    for method in class_.methods:
        if method.name in methods:
            methods[method.name].append(method)
        else:
            methods[method.name] = [method]
    
    for methods_ in methods.values():
        bindings.write(s("""scripting::Ref %s_%s(scripting::Context*ctx,const List<scripting::Ref>&args)
{
????scripting::RefManager*refMgr=ctx->getEngine()->getRefMgr();
????if(args.getCount()<1)
????????ctx->throwException(refMgr->createException(scripting::ExcType::ValueError,"%s::%s expects at least one argument."));
????%s*self;
????if(!type_same<%s>::f(ctx, args[0]))
????????ctx->throwException(refMgr->createException(scripting::ExcType::TypeError,"%s::%s expects %s as first argument."));
????else
????????self=(%s*)((scripting::NativeObject*)refMgr->translate(args[0]))->data;

""") % (class_.name, methods_[0].name, class_.name, methods_[0].name, class_.code_name, class_.code_name, class_.name, methods_[0].name, class_.name, class_.code_name))

        for method in methods_:
            if method.script_public:
                args = ["ref_to_c<%s>::f(ctx,args[%d])" % (method.args[j].type_.to_string(), j+1) for j in xrange(len(method.args))]

                for i in xrange(len(method.args)):
                    if i in method.arg_convs:
                        args[i] = "%s(ctx,args[%d])" % (method.arg_convs[i], i+1)

                argsStr = ", ".join(args)

                args = ["type_same<%s>::f(ctx,args[%d])" % (method.args[j].type_.to_string(), j+1) for j in xrange(len(method.args))]

                testStr = "&&".join(["1"] + args)

                bindings.write(s("""????if(args.getCount()==%d)
????????if(%s)
????????{
????????????%s self->%s(%s));
????????????%s;
????????}
""") % (len(method.args)+1,
        testStr,
        "(" if method.return_type.to_string() == "void" else "return create_ref<%s>::f(ctx, " % method.return_type.to_string(),
        method.name,
        argsStr,
        "return refMgr->createNil()" if method.return_type.to_string() == "void" else ""))

        bindings.write(s("""????ctx->throwException(refMgr->createException(scripting::ExcType::TypeError,"Unable to find overload for %s::%s."));
????return refMgr->createNil();
}

""") % (class_.name, methods_[0].name))

for functions_ in functions.values():
    public = False

    for function in functions_:
        public = public or function.script_public

    if public:
        print "Bindings will be generated for %s" % functions_[0].name
    else:
        continue

    bindings.write(s("""Ref %s_binding(scripting::Context*ctx,const List<scripting::Ref>&args)
{
????scripting::RefManager*refMgr=ctx->getEngine()->getRefMgr();
""") % (functions_[0].name))

    for function in functions_:
        if function.script_public:
            args = ["ref_to_c<%s>::f(ctx,args[%d])" % (function.args[j].type_.to_string(), j) for j in xrange(len(function.args))]

            for i in xrange(len(function.args)):
                if i in function.arg_convs:
                    args[i] = "%s(ctx,args[%d])" % (function.arg_convs[i], i)

            argsStr = ", ".join(args)

            args = ["type_same<%s>::f(ctx,args[%d])" % (function.args[j].type_.to_string(), j) for j in xrange(len(function.args))]

            testStr = "&&".join(["1"] + args)

            bindings.write(s("""????if(args.getCount()==%d)
????????if(%s)
????????{
????????????%s %s(%s));
????????????%s;
????????}
""") % (len(function.args),
       testStr,
       "(" if function.return_type.to_string() == "void" else "return create_ref<%s>::f(ctx," % function.return_type.to_string(),
       function.name,
       argsStr,
       "return refMgr->createNil()" if function.return_type.to_string() == "void" else ""))

    bindings.write(s("""????ctx->throwException(refMgr->createException(scripting::ExcType::TypeError,"Unable to find overload for %s."));
????return refMgr->createNil();
}

""") % (function.name))

bindings.write("""void *initBindings(scripting::Engine *engine, void *data)
{
    scripting::RefManager *refMgr = engine->getRefMgr();

    BindingsExt *ext = NEW(BindingsExt);

    int64_t typeID;
    
""")

for class_ in classes.values():
    if not class_.script_public:
        continue
    
    bindings.write("""    typeID = engine->createNewTypeID();
    ext->%s_typeID = typeID;
    engine->getGlobalVars().set("%s", refMgr->createNativeObject(%s_funcs, NULL, typeID));
    
""" % (class_.name, class_.name, class_.name))

for functions_ in functions.values():
    for function in functions_:
        if not function.script_public:
            continue
        
        bindings.write("""    engine->getGlobalVars().set("%s", refMgr->createNativeFunction(%s_binding));
        """ % (function.name, function.name))

bindings.write("""    return ext;
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
""")

bindings.close()
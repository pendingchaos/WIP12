import clang.cindex
import os
import fnmatch
import copy

minimize = True

def s(v):
    if minimize:
        return v.replace("?", "") #.replace("\n", "") #Seems to freeze GCC for a bit
    else:
        return v.replace("?", " ")

files = []

for root, dirnames, filenames in os.walk("../include"):
    for filename in fnmatch.filter(filenames, "*.h"):
        files.append(os.path.join(root, filename))

files.remove("../include/scripting/scriptsidebindings.h")
files.remove("../include/scripting/scriptinclude.h")

operators = {"operator+": "__add__",
             "operator-": "__sub__",
             "operator*": "__mul__",
             "operator/": "__div__",
             "operator%": "__mod__",
             "operator&&": "__bland__",
             "operator||": "__bor__",
             "operator!": "__blnot__",
             "operator&": "__btand__",
             "operator|": "__btor__",
             "operator^": "__btxor__",
             "operator<<": "__shl__",
             "operator>>": "__shr__",
             "operator~": "__btnot__",
             "operator<": "__less__",
             "operator>": "__grtr__",
             "operator==": "__eq__",
             "operator!=": "__neq__",
             "operator<=": "__leq__",
             "operator>=": "__geq__",
             "operator()": "__call__"}
             #TODO: operator[]

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
        
        if self.type_.startswith("const"):
            self.type_ = self.type_[5:]
            self.type_ = self.type_.lstrip()
            self.const = True
    
    def to_string(self, template_types={}):
        offsets = []
        offset = 0
        
        parts = []
        
        if self.type_.find("<") != -1:
            parts.append(self.type_[:self.type_.find("<")])
        
        while True:
            start = self.type_.find("<", offset+1)
            
            if start != -1:
                offset = self.type_.find(">", start+1)+1
                
                parts.append(self.type_[start:offset])
            else:
                parts.append(self.type_[offset:])
                break
        
        s = ""
        
        for part in parts:
            if part.startswith("<"):
                s2 = part
                
                for k, v in template_types.iteritems():
                    s2 = s2.replace(k, v[1:-1])
                
                s += s2
            else:
                s += part
        
        #Awful hack
        if s.replace(" ", "") in template_types:
            s = template_types[s.replace(" ", "")][1:-1]
        if s.replace("&", "").replace(" ", "") in template_types:
            s = template_types[s.replace("&", "").replace(" ", "")][1:-1] + "&"
        
        return ("const " if self.const else "") + s

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
        self.ret_ptr_no_cpp_ref = False

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
                elif c.displayname == "retptrnocppref":
                    self.ret_ptr_no_cpp_ref = True

class Method(Function):
    def __init__(self, class_, cursor):
        Function.__init__(self, cursor)

        if self.name in operators:
            self.name = operators[self.name]

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
        self.ret_ptr_no_cpp_ref = False
        
        for c in cursor.get_children():
            if c.kind == clang.cindex.CursorKind.ANNOTATE_ATTR:
                if c.displayname == "nobind":
                    self.script_public = False
                elif c.displayname == "retptrnocppref":
                    self.ret_ptr_no_cpp_ref = True

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
        self.template_types = {}
        self.copyable = True
        self.destructable = True
        self.constructable = True
        self.parent = None
        self.destroy_code = None
        self.subclasses = []

        num_private_cons = 0

        for child in cursor.get_children():
            if child.kind == clang.cindex.CursorKind.CXX_BASE_SPECIFIER:
                if len(child.spelling.split(" ")) == 2:
                    self.parent = child.spelling.split(" ")[1]

            if not child.access_specifier in [clang.cindex.AccessSpecifier.PUBLIC,
                                              clang.cindex.AccessSpecifier.INVALID]:
                if child.kind == clang.cindex.CursorKind.DESTRUCTOR:
                    self.destructable = False
                elif child.kind == clang.cindex.CursorKind.CONSTRUCTOR:
                    num_private_cons += 1

                continue

            if child.kind == clang.cindex.CursorKind.CXX_METHOD:
                if child.spelling.startswith("operator") and not child.spelling in operators:
                    continue
                
                if child.spelling.startswith("operator") and len([v for v in child.get_arguments()]) != 1:
                    continue
                
                m = Method(self, child)
                self.methods.append(m)
                if m.pure_virtual:
                    self.constructable = False
                
                if m.virtual or m.pure_virtual:
                    self.copyable = False
            elif child.kind == clang.cindex.CursorKind.FUNCTION_TEMPLATE:
                if Function(child).script_public:
                    print "Warning: Ignoring %s::%s" % (self.name, child.spelling)
            elif child.kind == clang.cindex.CursorKind.CONSTRUCTOR:
                self.constructors.append(Method(self, child))
            elif child.kind == clang.cindex.CursorKind.DESTRUCTOR:
                m = Method(self, child)
                
                self.destructors.append(m)
                
                if m.virtual or m.pure_virtual:
                    self.copyable = False
            elif child.kind == clang.cindex.CursorKind.FIELD_DECL:
                self.properties.append(Property(self, child))
            elif child.kind == clang.cindex.CursorKind.CLASS_DECL and\
                 child.is_definition():
                self.classes.append(Class(child))

        if num_private_cons != 0 and len(self.constructors) == 0:
            self.constructable = False

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
                elif c.displayname == "nocopy":
                    self.copyable = False
                elif c.displayname.startswith("destroy"):
                    self.destroy_code = c.displayname[7:]

    def add_parent(self, parent):
        self.methods += parent.methods
        self.properties += parent.properties
        self.copyable = self.copyable and parent.copyable
        self.destructable = self.destructable and parent.destructable
        self.constructable = self.constructable and parent.constructable

class Enum(object):
    def __init__(self, cursor):
        self.name = cursor.spelling
        
        self.values = {}
        self.enum_class = False
        self.script_public = False
        
        for c in cursor.get_children():
            if c.kind == clang.cindex.CursorKind.ENUM_CONSTANT_DECL:
                self.values[c.spelling] = c.enum_value
            elif c.kind == clang.cindex.CursorKind.ANNOTATE_ATTR:
                if c.displayname == "enumclass":
                    self.enum_class = True
                elif c.displayname == "bind":
                    self.script_public = True

def _get_classes(class_, classes):
    for class2 in class_.classes:
        classes["%s_%s" % (class_.name, class2.name)] = class2

def get_classes(cursor):
    classes = {}
    template_classes = {}

    for child in cursor.get_children():
        if child.kind == clang.cindex.CursorKind.CLASS_DECL or\
           child.kind == clang.cindex.CursorKind.STRUCT_DECL:
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
                        class_ = a.split(":")[0]
                        
                        types = [v.split(":")[0] for v in b.split(" ")]
                        
                        for type_, name in [tuple(v.split(":")) for v in b.split(" ")]:
                            c = copy.copy(template_classes[class_])
                            
                            c.name = name
                            c.code_name = class_ + type_
                            
                            classes[name] = c
                            
                            i = 0
                            for name in a.split(":")[1:]:
                                c.template_types[name] = types[i]
                                i += 1
                    elif c.displayname.startswith("classbind"):
                        name = c.displayname[9:]
                        
                        try:
                            classes[name].script_public = True
                        except KeyError:
                            template_classes[name].script_public = True

    for class_ in classes.values():
        if class_.parent != None:
            try:
                class_.add_parent(classes[class_.parent])
                classes[class_.parent].subclasses.append(class_)
            except KeyError:
                pass

        del class_.parent

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

def get_enums(cursor):
    enums = []

    for child in cursor.get_children():
        if child.kind == clang.cindex.CursorKind.ENUM_DECL and child.spelling != "":
            enums.append(Enum(child))

    return enums

print "Parsing preprocessed file."

index = clang.cindex.Index.create()

trans_unit = index.parse(".script_includes.h", ["-x", "c++", "-std=c++11"])

os.remove(".script_includes.h")

print "Generating the bindings."

classes = get_classes(trans_unit.cursor)
functions = get_functions(trans_unit.cursor)
enums = get_enums(trans_unit.cursor)

bindings = open("../src/scripting/bindings.cpp", "w")

bindings.write("//Generated from script_binding_generator2.py. Do not edit. Edit script_binding_generator2.py instead.\n")

for file_ in files:
    bindings.write("#include \"%s\"\n" % (file_[11:]))

bindings.write("""#include <stdint.h>

#include "scripting/vm/engine.h"
#include "scripting/vm/context.h"
#include "scripting/vm/bytecode.h"
#include "scripting/vm/types.h"
#include "scripting/parser.h"
#include "scripting/bytecodegen.h"
#include <type_traits>

struct BindingsExt
{
    int64_t """)

names = []

for class_ in classes.keys():
    if classes[class_].script_public:
        names.append(class_+"_typeID")
        names.append(class_+"_ptr"+"_typeID")

for enum in enums:
    if enum.script_public:
        names.append(enum.name + "_typeID")

bindings.write(", ".join(names))

bindings.write(";\n    scripting::Value ")

names = []

for class_ in classes.keys():
    if classes[class_].script_public:
        names.append("*"+class_)
        names.append("*"+class_+"_ptr")

for enum in enums:
    if enum.script_public:
        names.append("*"+enum.name)

bindings.write(", ".join(names))

bindings.write(";\n};\n\n")

bindings.write("""
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

#define VAL_TO_C_INT(T, T2, min, max) template <>\
struct val_to_c<T2>\
{\
    static T f(scripting::Context *ctx, const SV head)\
    {\
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
            CATE(scripting::ExcType::TypeError, "Value can not be converted to int."));\
        }\
        \
        if (v < min or v > max)\
        {\
            CATE(scripting::ExcType::TypeError, "Value out of bounds."));\
        }\
        \
        return v;\
    }\
};

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

#define CREATE_VAL(T, func) template <>\
struct create_val<T>\
{\
    static SV f(scripting::Context *ctx, const T& v)\
    {\
        return scripting::func(v);\
    }\
};

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

#define TYPE_SAME_HELPER(T, enumValue) template <>\
struct type_same<T>\
{\
    static bool f(scripting::Context *ctx, const SV head)\
    {\
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
""")

for enum in enums:
    if not enum.script_public:
        continue
    
    print "Bindings will be generated for %s" % enum.name
    
    bindings.write(s("""void %s_destroy(CTX,NO) {}
SV %s_get_member(CTX,NO,SV);
void %s_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs %s_funcs={
????.destroy = %s_destroy,
????.getMember = %s_get_member,
????.setMember = %s_set_member
};""" % (enum.name, enum.name, enum.name, enum.name, enum.name, enum.name, enum.name)))

    bindings.write(s("""
template <>
struct create_val<%s>
{
????static SV f(CTX ctx,%s v)
????{
????????R S::createNativeObject(%s_funcs,(void *)v,EXT->%s_typeID);
????}
};""" % (enum.name, enum.name, enum.name, enum.name)))

    bindings.write(s("""
template <>
struct val_to_c<%s>
{
????static %s f(CTX ctx,const SV head)
????{
????????if(head->type!=S::ValueType::NativeObject)
????????????CATE(TE,"Value can not be converted to %s."));
????????
????????NO obj=(NO)head;
????????if(obj->typeID!=EXT->%s_typeID)
????????????CATE(TE,"Value can not be converted to %s."));
????????????size_t v=size_t(obj->data);
""" % (enum.name, enum.name, enum.name, enum.name, enum.name)))

    if enum.enum_class:
        for k,v in enum.values.iteritems():
            bindings.write(s("????????if(v==%d)return %s::%s;\n" % (v, enum.name, k)))
    else:
        for k,v in enum.values.iteritems():
            bindings.write(s("????????if(v==%d)return %s;\n" % (v, k)))
    
    bindings.write(s("????}\n};\n"))
    
    bindings.write(s("""template <>
struct type_same<%s>
{
????static bool f(CTX ctx,const SV head)
????{
????????if(head->type==S::ValueType::NativeObject)
????????????R((NO)head)->typeID==EXT->%s_typeID;
????????else
???????????? R false;
????}
};""" % (enum.name, enum.name)))

for class_ in classes.values():
    if not class_.script_public:
        continue

    print "Bindings will be generated for %s" % class_.name

    bindings.write(s("""void %s_destroy(CTX,NO);
SV %s_get_member(CTX,NO,SV);
void %s_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs %s_funcs={
????.destroy = %s_destroy,
????.getMember = %s_get_member,
????.setMember = %s_set_member
};""" % (class_.name, class_.name, class_.name, class_.name, class_.name, class_.name, class_.name)))

    if class_.copyable:
        bindings.write(s("""
template <>
struct create_val<%s>
{
????static SV f(CTX ctx,const %s&obj)
????{
????????R S::createNativeObject(%s_funcs,NEW(%s, obj),EXT->%s_typeID);
????}
};
template <>
struct val_to_c<%s>
{
????static %s f(CTX ctx,const SV head)
????{
????????if(head->type==S::ValueType::NativeObject)
????????{
????????????NO obj=(NO)head;
????????????if(obj->typeID==EXT->%s_typeID)
????????????????R*((%s*)obj->data);
????????????else
???????????????? CATE(TE,"Value can not be converted to %s."));
????????} else
???????????? CATE(TE,"Value can not be converted to %s."));
????}
};""" % (class_.code_name, class_.code_name, class_.name, class_.code_name,
         class_.name, class_.code_name, class_.code_name, class_.name,
         class_.code_name, class_.name, class_.name, )))

    bindings.write(s("""
template <>
struct type_same<%s>
{
????static bool f(CTX ctx,const SV head)
????{
????????if(head->type==S::ValueType::NativeObject)
????????????R((NO)head)->typeID==EXT->%s_typeID;
????????else
???????????? R false;
????}
};

""") % (class_.code_name, class_.name))

    methods_ = {}

    for method in class_.methods:
        if method.name in methods_:
            continue
        methods_[method.name] = None

        bindings.write("SV %s_%s(CTX ctx,const List<SV>&a);\n" % (class_.name, method.name))

for class_ in classes.values():
    if not class_.script_public:
        continue

    name = class_.name + "_ptr"

    bindings.write(s("""SV %s_copy(CTX,?NO);
void %s_destroy(CTX,NO);
SV %s_get_member(CTX,NO,SV);
void %s_set_member(CTX,NO,SV,SV);
static const S::NativeObjectFuncs %s_funcs={
????.destroy = %s_destroy,
????.getMember = %s_get_member,
????.setMember = %s_set_member
};
""" % (name, name, name, name, name, name, name, name)))

    bindings.write(s("""template <>
struct create_val<%s *>
{
????static SV f(CTX ctx,%s*obj)
????{
????????AllocInfo i=getAllocInfo((void*)obj);
????????i.scriptRef = true;
????????setAllocInfo((void *)obj, i);
????????R S::createNativeObject(%s_funcs,obj,EXT->%s_ptr_typeID);
????}
};
template <>
struct val_to_c<%s *>
{
????static %s *f(CTX ctx,const SV head)
????{
????????if(head->type==S::ValueType::NativeObject)
????????{
????????????NO obj=(NO)head;
????????????if(obj->typeID==EXT->%s_ptr_typeID)
????????????????R(%s*)obj->data;
????????????else
???????????????? CATE(TE,"Value is not a %sRef."));
????????} else
???????????? CATE(TE,"Value is not a %sRef."));
????}
};
template <>
struct type_same<%s *>
{
????static bool f(CTX ctx,const SV head)
????{
????????if(head->type==S::ValueType::NativeObject)
????????????R((NO)head)->typeID==EXT->%s_ptr_typeID;
????????else
???????????? R false;
????}
};

""") % (class_.code_name, class_.code_name, name, class_.name, class_.code_name, class_.code_name, class_.name, class_.code_name, class_.name, class_.name, class_.code_name, class_.name))

for enum in enums:
    if not enum.script_public:
        continue
    
    ev = ""
    
    for k,v in enum.values.iteritems():
        ev += "EI(keyStr==\"%s\")R S::createNativeObject(%s_funcs,(void *)%d,EXT->%s_typeID);\n" % (k, enum.name, v, enum.name)

    bindings.write(s("""SV %s___eq__(CTX ctx,const List<SV>&a)
{
????if(a.getCount()!=2)
????????CATE(VE,UFOF("%s::__eq__")));
????size_t F;
????if(!TS(%s,a[0]))
????????CATE(TE,FAE("%s::%s","%s")));
????else
???????? F=(size_t)((NO)a[0])->data;
????size_t other;
????if(!TS(%s,a[1]))
????????CATE(VE,UFOF("%s::__eq__")));
????else
???????? other=(size_t)((NO)a[1])->data;
????return S::createBoolean(F == other);
}""") % (enum.name, enum.name, enum.name, enum.name, enum.name, enum.name, enum.name, enum.name))

    bindings.write(s("""SV %s_get_member(CTX ctx,NO F,SV key)
{
????if (key->type==S::ValueType::StringType)
????{
????????String keyStr=((S::StringValue *)key)->value;
????????if(F->data==NULL)
????????{
????????????if(keyStr=="__typeID__")
????????????????R S::createInt(F->typeID);
????????????EI(keyStr=="__name__")
????????????????R S::createString("%s");
????????????EI(keyStr=="__eq__")
????????????????R CNF(%s___eq__);
%s
????????????else
???????????????? CATE(KE,"Unknown member."));
????????} else
????????{
????????????if(keyStr=="__classTypeID__")
????????????????R S::createInt(F->typeID);
????????????EI(keyStr=="__name__")
????????????????R S::createString("%s");
????????????EI(keyStr=="__eq__")
????????????????R CNF(%s___eq__);
%s
????????????else
???????????????? CATE(KE,"Unknown member."));
????????}
????}
}
""" % (enum.name, enum.name, enum.name, ev, enum.name, enum.name, ev)))

    bindings.write(s("""void %s_set_member(CTX ctx,NO,SV,SV){CATE(KE,"Enums are read-only."));}\n""" % (enum.name)))

for class_ in classes.values():
    if not class_.script_public:
        continue

    bindings.write(s("""void %s_destroy(CTX ctx,NO F)
{
????if(!TS(%s, (SV)F))
????????CATE(TE,"%s::__del__ expects %s as first argument."));

""") % (class_.name, class_.code_name, class_.name, class_.name))

    if class_.destroy_code != None:
        bindings.write("%s*obj=(%s*)F->data;\n" % (class_.code_name, class_.code_name))
        bindings.write(class_.destroy_code+";\n}")
    elif class_.destructable:
        bindings.write(s("""????DELETE(%s,(%s*)F->data);
}""") % (class_.code_name, class_.code_name))
    else:
        bindings.write("}")

    if not class_.constructable:
        bindings.write(s("""SV %s_new(CTX ctx,const List<SV>&a)
{
????if(a.getCount()!=1)
????????CATE(VE,"%s's constructor" EAOE));
????if(!TS(%s,a[0]))
????????CATE(TE,"%s's constructor expects %s as first argument."));
????CATE(TE,UFOF("%s's constructor.")));
}

""" % (class_.name, class_.name, class_.code_name, class_.name, class_.name, class_.name)))
    elif len(class_.constructors) == 0:
        bindings.write(s("""SV %s_new(CTX ctx,const List<SV>&a)
{
????if(a.getCount()!=1)
????????CATE(VE,"%s's constructor" EAOE));
????if(!TS(%s,a[0]))
????????CATE(TE,"%s's constructor expects %s as first argument."));
????R S::createNativeObject(%s_funcs,NEW(%s),EXT->%s_typeID);
}

""") % (class_.name, class_.code_name, class_.name, class_.name, class_.name, class_.name, class_.code_name, class_.name))
    else:
        bindings.write(s("""SV %s_new(CTX ctx,const List<SV>&a)
{
????if(a.getCount()<1)
????????CATE(VE,"%s's constructor" EAOE));
????if(!TS(%s,a[0]))
????????CATE(TE,"%s's constructor expects %s as first argument."));
""") % (class_.name, class_.name, class_.code_name, class_.name, class_.name))

        for constructor in class_.constructors:
            if not constructor.script_public:
                continue
            
            args = ["val_to_c<%s>::f(ctx,a[%d])" % (constructor.args[j].type_.to_string(class_.template_types), j+1) for j in xrange(len(constructor.args))]

            for i in xrange(len(constructor.args)):
                if i in constructor.arg_convs:
                    args[i] = "%s(ctx,a[%d])" % (constructor.arg_convs[i], i+1)

            constStr = ",".join([class_.name] + args)
            
            args = ["TS(%s,a[%d])" % (constructor.args[j].type_.to_string(class_.template_types), j+1) for j in xrange(len(constructor.args))]
            
            testStr = "&&".join(["true"] + args)

            bindings.write(s("""????if(a.getCount()==%d)
????????if(%s)
????????????R S::createNativeObject(%s_funcs,NEW(%s),EXT->%s_typeID);
""") % (len(constructor.args)+1, testStr, class_.name, constStr, class_.name))

        bindings.write(s("""????CATE(TE,UFOF("%s's constructor.")));
????R CN;
}

""") % class_.name)

    bindings.write(s("""SV %s_get_member(CTX ctx,NO F,SV key)
{
????if (key->type==S::ValueType::StringType)
????{
????????String keyStr=((S::StringValue *)key)->value;
????????if(F->data==NULL)
????????{
????????????if(keyStr=="__typeID__")
????????????????R S::createInt(F->typeID);
????????????EI(keyStr=="__name__")
????????????????R S::createString("%s");
????????????EI(keyStr=="__new__")
????????????????R CNF(%s_new);
????????????EI(keyStr=="__call__")
????????????????R CNF(%s_new);
????????????else
???????????????? CATE(KE,"Unknown member."));
????????} else
????????{
????????????if(keyStr=="__classTypeID__")
????????????????R S::createInt(F->typeID);
????????????EI(keyStr=="__init__")
????????????????R CNF(%s_new);
????????????""") % (class_.name, class_.name, class_.name, class_.name, class_.name))

    methods_ = {}

    for method in class_.methods:
        if method.name in methods_:
            continue
        methods_[method.name] = None

        bindings.write(s(""" EI(keyStr == "%s")
????????????????R CNF(%s_%s);
????????????""") % (method.name, class_.name, method.name))

    for property_ in class_.properties:
        if not property_.script_public:
            continue
        
        if property_.ret_ptr_no_cpp_ref:
            bindings.write(s(""" EI(keyStr=="%s")
????????????{
????????????????%s*obj=(%s*)F->data;
????????????????%s r=obj->%s;
????????????????allocInfo((void*)r,AllocInfo(true,false));
????????????????R CV(r);
????????????}""") % (property_.name, class_.code_name, class_.code_name, property_.type_.to_string(class_.template_types), property_.name))
        else:
            bindings.write(s(""" EI(keyStr=="%s")
????????????{
????????????????%s*obj=(%s*)F->data;
????????????????R CV(obj->%s);
????????????}""") % (property_.name, class_.code_name, class_.code_name, property_.name))
    
    bindings.write(s(""" else
???????????????? CATE(KE,"Unknown member."));
????????}
????}
????R CN;
}

"""))

    bindings.write(s("""void %s_set_member(CTX ctx,NO F,SV key,SV value)
{
????if (key->type==S::ValueType::StringType)
????{
????????String keyStr=((S::StringValue*)key)->value;
????????if(F->data==NULL)
????????????CATE(KE,"Native classes are read-only."));
????????else
????????{
????????????if(0) {}""") % (class_.name))

    for property_ in class_.properties:
        if not property_.script_public:
            continue
        
        bindings.write(s(""" EI(keyStr=="%s")
????????????{
????????????????%s*obj=(%s*)F->data;
????????????????obj->%s=val_to_c<decltype(obj->%s)>::f(ctx,value);
????????????}""") % (property_.name, class_.code_name, class_.code_name, property_.name, property_.name))
    
    bindings.write(s(""" else
???????????????? CATE(KE,"Unknown member or member if read-only."));
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
        bindings.write(s("""SV %s_%s(CTX ctx,const List<SV>&a)
{
????if(a.getCount()<1)
????????CATE(VE,"%s::%s" EAOE));
????%s*F;
????if(!TS(%s,a[0]))
????????CATE(TE,FAE("%s::%s","%s")));
????else
???????? F=(%s*)((NO)a[0])->data;

""") % (class_.name, methods_[0].name, class_.name, methods_[0].name, class_.code_name, class_.code_name, class_.name, methods_[0].name, class_.name, class_.code_name))

        for method in methods_:
            if method.script_public:
                args = ["val_to_c<%s>::f(ctx,a[%d])" % (method.args[j].type_.to_string(class_.template_types), j+1) for j in xrange(len(method.args))]

                for i in xrange(len(method.args)):
                    if i in method.arg_convs:
                        args[i] = "%s(ctx,a[%d])" % (method.arg_convs[i], i+1)

                argsStr = ", ".join(args)

                args = ["TS(%s,a[%d])" % (method.args[j].type_.to_string(class_.template_types), j+1) for j in xrange(len(method.args))]

                testStr = "&&".join(["1"] + args)

                if method.name in operators.values():
                    for k, v in operators.iteritems():
                        if v == method.name:
                            operator = k[len("operator"):]
                    
                    if method.ret_ptr_no_cpp_ref:
                        bindings.write(s("""????if(a.getCount()==%d)
????????if(%s)
????????{
????????????%s r=*F %s %s;
????????????setAllocInfo((void*)r,AllocInfo(true,false));
????????????R CV(r);
????????}
""") % (len(method.args)+1,
        testStr,
        method.return_type.to_string(class_.template_types),
        operator,
        argsStr))
                    else:
                        bindings.write(s("""????if(a.getCount()==%d)
????????if(%s)
????????{
????????????R CV(*F %s %s);
????????}
""") % (len(method.args)+1,
        testStr,
        operator,
        argsStr))

                else:
                    if method.ret_ptr_no_cpp_ref:
                        bindings.write(s("""????if(a.getCount()==%d)
????????if(%s)
????????{
????????????%s r=F->%s(%s);
????????????R CV(r);
????????}
""") % (len(method.args)+1,
        testStr,
        method.return_type.to_string(class_.template_types),
        method.name,
        argsStr))
                    else:
                        bindings.write(s("""????if(a.getCount()==%d)
????????if(%s)
????????{
????????????%s F->%s(%s));
????????????%s;
????????}
""") % (len(method.args)+1,
            testStr,
            "(" if method.return_type.to_string(class_.template_types) == "void" else "R CV(",
            method.name,
            argsStr,
            "R CN" if method.return_type.to_string(class_.template_types) == "void" else ""))

        bindings.write(s("""????CATE(TE,UFOF("%s::%s.")));
????R CN;
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

    bindings.write(s("""SV %s_binding(CTX ctx,const List<SV>&a)
{
""") % (functions_[0].name))

    for function in functions_:
        if function.script_public:
            args = ["val_to_c<%s>::f(ctx,a[%d])" % (function.args[j].type_.to_string(), j) for j in xrange(len(function.args))]

            for i in xrange(len(function.args)):
                if i in function.arg_convs:
                    args[i] = "%s(ctx,a[%d])" % (function.arg_convs[i], i)

            argsStr = ", ".join(args)

            args = ["TS(%s,a[%d])" % (function.args[j].type_.to_string(), j) for j in xrange(len(function.args))]

            testStr = "&&".join(["1"] + args)

            if function.ret_ptr_no_cpp_ref:
                bindings.write(s("""????if(a.getCount()==%d)
????????if(%s)
????????{
????????????%s o=%s(%s);
????????????setAllocInfo((void*)o,AllocInfo(true,false));
????????????R CV(o);
????????}
""" % (len(function.args),
       testStr,
       function.return_type.to_string(),
       function.name,
       argsStr)))
            else:
                bindings.write(s("""????if(a.getCount()==%d)
????????if(%s)
????????{
????????????%s %s(%s));
????????????%s;
????????}
""") % (len(function.args),
       testStr,
       "(" if function.return_type.to_string() == "void" else "R CV(" % function.return_type.to_string(),
       function.name,
       argsStr,
       "R CN" if function.return_type.to_string() == "void" else ""))

    bindings.write(s("""????CATE(TE,UFOF("%s")));
????R CN;
}

""") % (function.name))

for class_ in classes.values():
    if not class_.script_public:
        continue
    
    name = class_.name + "_ptr"
    
    bindings.write(s("""SV %s_ptr_new(CTX ctx,const List<SV>&a)
{
????List<SV> args2 = a.copy();
????args2[0]=EXT->%s;
????NO obj=(NO)%s_new(ctx, args2);
????obj->funcs=%s_ptr_funcs;
????obj->typeID=EXT->%s_ptr_typeID;
????setAllocInfo(obj->data, AllocInfo(true, false));
????R(SV)obj;
}
""" % (class_.name, class_.name, class_.name, class_.name, class_.name)))

    if class_.copyable:
        bindings.write(s("""SV %s_ptr_deref(CTX ctx,const List<SV>&a)
{
????if(a.getCount()!=1)
????????CATE(VE,"%sRef::deref" EAOE));
????SV F=a[0];
????if(!TS(%s*,(SV)F))
????????CATE(TE,"%sRef::deref expects %sRef as first argument."));
????R CV(*(%s *)((NO)F)->data);
}
""" % (class_.name, class_.name, class_.code_name, class_.name, class_.name, class_.code_name)))

        bindings.write(s("""SV %s_ptr_set(CTX ctx,const List<SV>&a)
{
????if(a.getCount()!=2)
????????CATE(VE,"%s::refset expects two arguments."));
????SV F=a[0];
????if(!TS(%s*,(SV)F))
????????CATE(TE,"%sRef::refset expects %sRef as first argument."));
????*((%s *)((NO)F)->data) = val_to_c<%s>::f(ctx,a[1]);
????R CN;
}
""" % (class_.name, class_.name, class_.code_name, class_.name, class_.name, class_.code_name, class_.code_name)))
    else:
        bindings.write(s("""SV %s_ptr_deref(CTX ctx,const List<SV>&a)
{
????if(a.getCount()!=1)
????????CATE(VE,"%sRef::deref" EAOE));
????SV F=a[0];
????if(!TS(%s*,(SV)F))
????????CATE(TE,"%sRef::deref expects %sRef as first argument."));
????????CATE(TE,"%s objects are not copyable."));
}
""" % (class_.name, class_.name, class_.code_name, class_.name, class_.name, class_.name)))

        bindings.write(s("""SV %s_ptr_set(CTX ctx,const List<SV>&a)
{
????if(a.getCount()!=2)
????????CATE(VE,"%s::refset expects two arguments."));
????SV F=a[0];
????if(!TS(%s*,(SV)F))
????????CATE(TE,"%sRef::refset expects %sRef as first argument."));
????????CATE(TE,"%s objects are not copyable."));
????R CN;
}
""" % (class_.name, class_.name, class_.code_name, class_.name, class_.name, class_.name)))

    if class_.destroy_code != None:
        bindings.write(s("""
void %s_destroy(CTX ctx,NO F)
{
????if(!TS(%s*,(SV)F))
????????CATE(TE,"%sRef::__del__ expects %sRef as first argument."));
????%s*obj=(%s*)F->data;
????if(shouldScriptDelete(F->data)) {%s;}
}""" % (name, class_.code_name, class_.name, class_.name, class_.code_name, class_.code_name, class_.destroy_code)))
    elif not class_.destructable:
        #Let's hope it is freed.
        bindings.write(s("""
void %s_destroy(CTX ctx,NO F)
{
????if(!TS(%s*,(SV)F))
????????CATE(TE,"%sRef::__del__ expects %sRef as first argument."));
}""" % (name, class_.code_name, class_.name, class_.name)))
    else:
        bindings.write(s("""
void %s_destroy(CTX ctx,NO F)
{
????if(!TS(%s*,(SV)F))
????????CATE(TE,"%sRef::__del__ expects %sRef as first argument."));
????SCRIPT_DELETE(%s, (%s *)F->data);
}""" % (name, class_.code_name, class_.name, class_.name,
        class_.code_name, class_.code_name)))

    bindings.write(s("""
SV %s_get_member(CTX ctx,NO F,SV key)
{
????if(!TS(%s*,(SV)F))
????????CATE(TE,FAE("%sRef's get method","%sRef")));
????if (key->type==S::ValueType::StringType)
????{
????????String keyStr=((S::StringValue *)key)->value;
????????if(F->data==NULL)
????????{
????????if(keyStr=="__typeID__")
????????????R S::createInt(F->typeID);
????????EI(keyStr=="__name__")
????????????R S::createString("%sPtr");
????????EI(keyStr=="__new__")
????????????R CNF(%s_ptr_new);
????????EI(keyStr=="__call__")
????????????R CNF(%s_ptr_new);
????????else
????????????CATE(KE,"Unknown member."));
????????} else
????????{
????????if(keyStr=="deref")R CNF(%s_ptr_deref);
????????if(keyStr=="refset")R CNF(%s_ptr_set);
????????}
????}
????S::NativeObject obj;
????obj.head.type=S::ValueType::NativeObject;
????obj.funcs=%s_funcs;
????obj.typeID=EXT->%s_typeID;
????obj.refCount=1;
????obj.data=F->data;
????R %s_get_member(ctx, &obj, key);
}
void %s_set_member(CTX ctx,NO F,SV key,SV value)
{
????if(!TS(%s*,(SV)F))
????????CATE(TE,FAE("%sRef's set method","%sRef")));
????S::NativeObject obj;
????obj.head.type=S::ValueType::NativeObject;
????obj.funcs=%s_funcs;
????obj.typeID=EXT->%s_typeID;
????obj.refCount=1;
????obj.data=F->data;
????%s_set_member(ctx, &obj, key, value);
}
""") % (name, class_.code_name, class_.name,
        class_.name, class_.name, class_.name, class_.name,
        class_.name, class_.name, class_.name, class_.name, class_.name, name, class_.code_name,
        class_.name, class_.name, class_.name, class_.name, class_.name))

bindings.write("""void *initBindings(scripting::Engine *engine, void *data)
{
    BindingsExt *ext = NEW(BindingsExt);

    int64_t typeID;
    
""")

for class_ in classes.values():
    if not class_.script_public:
        continue
    
    bindings.write("""    typeID = engine->createNewTypeID();
    ext->%s_typeID = typeID;
    ext->%s = scripting::createNativeObject(%s_funcs, NULL, typeID);
    engine->getGlobalVars().set("%s", ext->%s);
    
""" % (class_.name, class_.name, class_.name, class_.name, class_.name))

    bindings.write("""    typeID = engine->createNewTypeID();
    ext->%s_ptr_typeID = typeID;
    ext->%s_ptr = scripting::createNativeObject(%s_ptr_funcs, NULL, typeID);
    engine->getGlobalVars().set("%sRef", ext->%s_ptr);
    
""" % (class_.name, class_.name, class_.name, class_.name, class_.name))

for functions_ in functions.values():
    for function in functions_:
        if not function.script_public:
            continue
        
        bindings.write("""    engine->getGlobalVars().set("%s", scripting::createNativeFunction(%s_binding));
        """ % (function.name, function.name))

for enum in enums:
    if not enum.script_public:
        continue
    
    bindings.write("""    typeID = engine->createNewTypeID();
    ext->%s_typeID = typeID;
    ext->%s = scripting::createNativeObject(%s_funcs, NULL, typeID);
    engine->getGlobalVars().set("%s", ext->%s);
    
""" % (enum.name, enum.name, enum.name, enum.name, enum.name))

bindings.write("""    return ext;
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
""")

bindings.close()

import clang.cindex
import os

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
"../include/containers/pair.h",
"../include/containers/string.h",
"../include/containers/hashmap.h",
"../include/containers/resizabledata.h",
"../include/physics/physicsworld.h",
"../include/physics/rigidbody.h",
"../include/physics/physicsshape.h",
"../include/physics/physicsdebugdrawer.h",
"../include/platform/platform.h"]

print "Running preprocessor"

pipe = os.popen("g++ -E -o.script_includes.h -I../include `sdl2-config --cflags` `pkg-config bullet --cflags` `freetype-config --cflags` -std=gnu++11 -xc++ -", "w")
pipe.write("\n".join("#include \"%s\"" % file_ for file_ in files))
pipe.close()

class_names = ["File",  "Filesystem", "Application", "Scene", "Entity",
"Transform", "GfxApi", "GfxMesh", "GfxModel", "GfxShader", "GfxTexture",
"GfxMaterial", "GfxBuffer", "GfxRenderer", "GfxMeshImpl", "GfxShaderImpl",
"GfxTextureImpl", "GfxDebugDrawer", "Camera", "Script", "Resource",
"ResourceManager", "Matrix3x3", "Matrix4x4", "Quaternion", "PhysicsWorld",
"RigidBody", "PhysicsShape", "PhysicsDebugDrawer", "Platform",
"GfxShaderCombination", "Exception", "ShaderCompileException", "FileException",
"LookupException", "ResourceIOException", "LogEntry", "PhysicsShapeImpl",
"Framebuffer", "Light", "Font", "GPUTimer", "Overlay", "AABB", "ScriptFunction",
"UserData", "GhostObject"]

function_names = ["getBacktrace", "log",
"setApplication", "listFiles", "doesFileExist", "getLastModification",
"getHash", "swapEndianU16", "swapEndianS16", "swapEndianU32", "swapEndianS32",
"swapEndianU64", "swapEndianS64"]

class Type(object):
    def __init__(self, type_):
        self.pos = type_.is_pod()
        self.const = type_.is_const_qualified()
        self.type_ = type_.spelling

class Argument(object):
    def __init__(self, cursor, index):
        self.index = index
        self.type_ = Type(cursor.type)

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

        i = 0

        for arg in cursor.get_arguments():
            self.args.append(Argument(arg, i))

            i += 1

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

class Class(object):
    def __init__(self, cursor):
        self.name = cursor.spelling

        self.methods = []
        self.classes = []
        self.constructors = []
        self.destructors = []
        self.has_virtual_methods = False
        self.has_pure_virtual_methods = False

        for child in cursor.get_children():
            if child.kind == clang.cindex.CursorKind.CXX_METHOD:
                if clang.cindex.conf.lib.clang_CXXMethod_isVirtual(child):
                    self.has_virtual_methods = True

                if clang.cindex.conf.lib.clang_CXXMethod_isPureVirtual(child):
                    self.has_pure_virtual_methods = True

            if not child.access_specifier in [clang.cindex.AccessSpecifier.PUBLIC,
                                              clang.cindex.AccessSpecifier.INVALID]:
                continue

            if child.kind == clang.cindex.CursorKind.CXX_METHOD:
                method = Method(self, child)

                self.methods.append(method)
            elif child.kind == clang.cindex.CursorKind.CONSTRUCTOR:
                self.constructors.append(Method(self, child))
            elif child.kind == clang.cindex.CursorKind.DESTRUCTOR :
                self.destructors.append(Method(self, child))
            elif child.kind == clang.cindex.CursorKind.CLASS_DECL and\
                 child.spelling in class_names:
                self.classes.append(Class(child))

def get_classes(cursor):
    classes = {}

    for child in cursor.get_children():
        if child.kind == clang.cindex.CursorKind.CLASS_DECL:
            if child.spelling in class_names and \
               child.access_specifier in [clang.cindex.AccessSpecifier.PUBLIC,
                                          clang.cindex.AccessSpecifier.INVALID]:
                classes[child.spelling] = Class(child)

    return classes

def get_functions(cursor):
    functions = []

    for child in cursor.get_children():
        if child.kind == clang.cindex.CursorKind.FUNCTION_DECL and\
           child.spelling in function_names and\
           not clang.cindex.conf.lib.clang_isFunctionTypeVariadic(child.type):
            functions.append(Function(child))

    return functions

def get_methods(class_):
    methods = [method for method in class_.methods]
    methods += [method for method in class_.constructors]
    methods += [method for method in class_.destructors]

    for class2 in class_.classes:
        methods += get_methods(class2)

    result = []

    for method in methods:
        if not method.virtual and not method.variadic:
            result.append(method)

    return result

print "Parsing preprocesing file."

index = clang.cindex.Index.create()

trans_unit = index.parse(".script_includes.h", ["-x", "c++", "-std=c++11"])

os.remove(".script_includes.h")

print "Generating the bindings."

classes = get_classes(trans_unit.cursor)
functions = get_functions(trans_unit.cursor)

methods = []

for class_ in classes.values():
    methods += get_methods(class_)

function_struct = "struct _functionStruct\n{\n"

i = 0

for function in functions:
    if function.definition:
        continue

    args = ["%s arg%d" % (function.args[j].type_.type_, j) for j in xrange(len(function.args))]
    argStr = ", ".join(args)

    function_struct += "    %s (*f%d)(%s);\n" % (function.return_type.type_,
                                                 i,
                                                 argStr)

    i += 1

for method in methods:
    if method.definition:
        continue

    if method.constructor and method.class_.has_virtual_methods:
        continue

    args = ["%s arg%d" % (method.args[j].type_.type_, j) for j in xrange(len(method.args))]

    if not method.static:
        args = ["%s %s *obj" % ("const" if method.const else "", method.class_.name)] + args

    argStr = ", ".join(args)

    function_struct += "    %s (*f%d)(%s);\n" % (method.return_type.type_,
                                                 i,
                                                 argStr)

    i += 1

for method in methods:
    if not method.constructor:
        continue

    if method.class_.has_pure_virtual_methods:
        continue

    args = ["%s arg%d" % (method.args[j].type_.type_, j) for j in xrange(len(method.args))]
    argStr = ", ".join(args)

    function_struct += "    %s *(*f%d)(%s);\n" % (method.class_.name,
                                                  i,
                                                  argStr);

    i += 1

    if len(method.args) == 0:
        function_struct += "    %s *(*f%d)(size_t count);\n" % (method.class_.name,
                                                                i);

        i += 1

function_struct += "};\n"

script_side = open("../include/scripting/scriptsidebindings.h", "w")

i = 0

script_side.write("#ifdef _SCRIPT_SIDE_IMPLS\n")

script_side.write(function_struct)

script_side.write("const _functionStruct *_functions;\n")

for function in functions:
    if function.definition:
        continue

    args = ["%s arg%d" % (function.args[j].type_.type_, j) for j in xrange(len(function.args))]
    argDeclStr = ", ".join(args)

    args = ["arg%d" % j for j in xrange(len(function.args))]
    argStr = ", ".join(args)

    script_side.write("%s %s(%s) {%s _functions->f%d(%s);}\n" % (function.return_type.type_,
                                                                 function.name,
                                                                 argDeclStr,
                                                                 "" if function.return_type.type_ == "void" else "return",
                                                                 i,
                                                                 argStr))

    i += 1

for method in methods:
    if method.definition:
        continue

    if method.constructor and method.class_.has_virtual_methods:
        continue

    args = ["%s arg%d" % (method.args[j].type_.type_, j) for j in xrange(len(method.args))]

    argDeclStr = ", ".join(args)

    args = ["arg%d" % j for j in xrange(len(method.args))]

    if not method.static:
        args = ["this"] + args

    argStr = ", ".join(args)

    script_side.write("%s %s::%s(%s) %s {%s _functions->f%d(%s);}\n" % ("" if method.constructor or method.destructor else method.return_type.type_,
                                                                        method.class_.name,
                                                                        method.name,
                                                                        argDeclStr,
                                                                        "const" if method.const else "",
                                                                        "" if method.return_type.type_ == "void" else "return",
                                                                        i,
                                                                        argStr))

    i += 1

for method in methods:
    if method.class_.has_pure_virtual_methods:
        continue

    if not method.constructor:
        continue

    argDecls = ["%s arg%d" % (method.args[j].type_.type_, j) for j in xrange(len(method.args))]
    argDeclStr = ", ".join(argDecls)

    args = ["arg%d" % (j) for j in xrange(len(method.args))]
    argStr = ", ".join(args)

    script_side.write("%s *_new%s(%s) {return _functions->f%d(%s);}\n" % (method.class_.name,
                                                                          method.class_.name,
                                                                          argDeclStr,
                                                                          i,
                                                                          argStr))

    i += 1

    if len(method.args) == 0:
        script_side.write("%s *_newArray%s(size_t count) {return _functions->f%d(count);}\n" % (method.class_.name,
                                                                                                method.class_.name,
                                                                                                i))

        i += 1

for class_ in classes.values():
    if class_.has_pure_virtual_methods:
        continue

    for constructor in class_.constructors:
        argDecls = ["T%d arg%d" % (j, j) for j in xrange(len(constructor.args))]
        argDeclStr = ", ".join(argDecls)

        args = ["arg%d" % (j) for j in xrange(len(constructor.args))]
        argStr = ", ".join(args)

        if len(constructor.args) != 0:
            script_side.write("template <%s>\n" % ", ".join(["typename T%d" % i for i in xrange(len(constructor.args))]))
        script_side.write("%s *%s::f(%s) {return _new%s(%s);}\n\n" % (class_.name,
                                                                      "_new<%s>" % (class_.name),
                                                                      argDeclStr,
                                                                      class_.name,
                                                                      argStr))

for class_ in classes.values():
    if class_.has_pure_virtual_methods:
        continue

    for constructor in class_.constructors:
        if len(constructor.args) == 0:
            script_side.write("%s *%s::f(size_t count) {return _newArray%s(count);}\n\n" % (class_.name,
                                                                                            "_newArray<%s>" % (class_.name),
                                                                                            class_.name))

script_side.write("extern \"C\" void _initFunctions(const _functionStruct *functions) {_functions = functions;}\n")
script_side.write("#else\n")

script_side.write("""template <typename T>
struct _new {};

template <typename T>
struct _newArray {};

""")

for class_ in classes.values():
    if class_.has_pure_virtual_methods:
        continue

    script_side.write("class %s;\n" % (class_.name))

    script_side.write("template <>\nstruct _new<%s>\n{\n" % (class_.name))

    for constructor in class_.constructors:
        argDecls = ["T%d arg%d" % (j, j) for j in xrange(len(constructor.args))]
        argDeclStr = ", ".join(argDecls)

        if len(constructor.args) != 0:
            script_side.write("    template <%s>\n" % ", ".join(["typename T%d" % i for i in xrange(len(constructor.args))]))
        script_side.write("    static %s *f(%s);\n" % (class_.name, argDeclStr))

    script_side.write("};\n\n")

for class_ in classes.values():
    if class_.has_pure_virtual_methods:
        continue

    script_side.write("class %s;\n" % (class_.name))

    script_side.write("template <>\nstruct _newArray<%s>\n{\n" % (class_.name))

    for constructor in class_.constructors:
        if len(constructor.args) == 0:
            script_side.write("    static %s *f(size_t count);\n" % (class_.name))

    script_side.write("};\n\n")

script_side.write("#endif")

script_side.close()

app_side = open("../src/scripting/appsidebindings.cpp", "w")

for file_ in files:
    app_side.write("#include \"%s\"\n" % (file_[11:]))

app_side.write(function_struct)

i = 0

for function in functions:
    if function.definition:
        continue

    args = ["%s arg%d" % (function.args[j].type_.type_, j) for j in xrange(len(function.args))]
    argDeclStr = ", ".join(args)

    args = ["arg%d" % j for j in xrange(len(function.args))]
    argStr = ", ".join(args)

    app_side.write("%s f%d(%s) {%s %s(%s);}\n" % (function.return_type.type_,
                                                  i,
                                                  argDeclStr,
                                                  "" if function.return_type.type_ == "void" else "return",
                                                  function.name,
                                                  argStr))

    i += 1

for method in methods:
    if method.definition:
        continue

    if method.constructor and method.class_.has_virtual_methods:
        continue

    args = ["%s arg%d" % (method.args[j].type_.type_, j) for j in xrange(len(method.args))]

    if not method.static:
        args = ["%s %s *obj" % ("const" if method.const else "", method.class_.name)] + args

    argDeclStr = ", ".join(args)

    args = ["arg%d" % j for j in xrange(len(method.args))]

    argStr = ", ".join(args)

    if method.constructor:
        app_side.write("void f%d(%s) {new (%s) %s(%s);}\n" % (i,
                                                              argDeclStr,
                                                              "obj",
                                                              method.class_.name,
                                                              argStr))
    else:
        app_side.write("%s f%d(%s) {%s %s(%s);}\n" % (method.return_type.type_,
                                                      i,
                                                      argDeclStr,
                                                      "" if method.return_type.type_ == "void" else "return",
                                                      "%s::%s" % (method.class_.name, method.name) if method.static else "obj->%s" % (method.name),
                                                      argStr))

    i += 1

for method in methods:
    if not method.constructor:
        continue

    if method.class_.has_pure_virtual_methods:
        continue

    argDecls = ["%s arg%d" % (method.args[j].type_.type_, j) for j in xrange(len(method.args))]
    argDeclStr = ", ".join(argDecls)

    args = ["arg%d" % (j) for j in xrange(len(method.args))]
    argStr = ", ".join([method.class_.name]+args)

    app_side.write("%s *f%d(%s) {return NEW(%s);}\n" % (method.class_.name,
                                                        i,
                                                        argDeclStr,
                                                        argStr))

    i += 1

    if len(method.args) == 0:
        argDeclStr = ", ".join(["size_t count"]+argDecls)

        app_side.write("%s *f%d(%s) {return NEW_ARRAY(%s, count);}\n" % (method.class_.name,
                                                                   i,
                                                                   argDeclStr,
                                                                   method.class_.name))

        i += 1

app_side.write("static const _functionStruct functions = {%s};\n"\
% ", ".join(["f%d" % j for j in xrange(i)]))

app_side.write("const void *getScriptFunctionStruct() {return &functions;}")

app_side.close()

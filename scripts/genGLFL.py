import xml.etree.ElementTree as ET
import urllib2
import os

try:
    print "Retreiving gl.xml from khronos.org."
    
    url = "https://cvs.khronos.org/svn/repos/ogl/trunk/doc/registry/public/api/gl.xml"
    data = urllib2.urlopen(url).read()
    
    print "Writing to gl.xml on this computer."
    
    with open("gl.xml", "w") as glXML:
        glXML.write(data)
except urllib2.URLError:
    print "Failed to retrieve gl.xml from khronos.org. Using gl.xml file on this computer."

tree = ET.parse("gl.xml")

root = tree.getroot()

types = root.find("types")

if not os.path.isdir("../include/glfl"):
    os.mkdir("../include/glfl")

if not os.path.isdir("../src/glfl"):
    os.mkdir("../src/glfl")

def generate(api):
    resenums = {}
    rescommands = {}
    commandnames = []
    
    outFile = open("../include/graphics/GL/glfl.h", "w")
    
    outFile.write("//This file was generated by genGLFL.py. Do not edit.\n\n#ifndef GLFL_%s_H\n#define GLFL_%s_H 1\n\n#define __gl_h_ 1\n\n" % (api.upper(), api.upper()));
    
    for type in root.find("types").findall("type"):
        if (type.text == None):
            continue
        
        res = type.text
        name = ""
        
        for thing in type:
            if thing.tag == "name":
                name = thing.text
            
            if thing.tag == "apientry":
                res += "" + thing.tail
            else:
                res += thing.text + thing.tail
        
        if "name" in type.attrib:
            name = type.attrib["name"]
        
        if "name" in type.attrib:
            if (type.attrib["name"] in ["stddef", "khrplatform", "inttypes"]):
                outFile.write(res+"\n\n")
                continue
        
        outFile.write("#ifndef %s_DEFINED\n" % (name))
        outFile.write("#define %s_DEFINED\n" % (name))
        outFile.write(res+"\n")
        outFile.write("#endif\n\n")

    for enums in root.findall("enums"):
        for enum in enums.findall("enum"):
            resenums[enum.attrib["name"]] = """#ifndef %s
#define %s %s
#endif

""" % (enum.attrib["name"], enum.attrib["name"], enum.attrib["value"])
    
    for command in root.find("commands").findall("command"):
        proto = command.find("proto")
        
        params = []
        
        for param in command.findall("param"):
            type = param.find("ptype")
            name = param.find("name")
            
            if type == None:
                type = param.text
            else:
                type = type.text
            
            if param.text != None:
                type = param.text + type
            
            params.append("".join([t for t in param.itertext()]))
        
        if len(params) == 0:
            params = ["void"]
        
        rettype = proto.text if proto.text != None else ""
        
        rettype += "".join([elem.text + elem.tail if elem.tag != "name" else "" for elem in proto])
        
        rescommands[proto.find("name").text] = """#ifdef %s
#undef %s
#endif
#ifdef PFN%sPROC
#undef PFN%sPROC
#endif
typedef %s (*PFN%sPROC)(%s);

""" % (proto.find("name").text, proto.find("name").text, 
           proto.find("name").text.upper(), proto.find("name").text.upper(), rettype, proto.find("name").text.upper(), ", ".join(params))
        
        extensionnames = []
    
    for feature in root.findall("feature") + root.find("extensions").findall("extension"):
        if "api" in feature.attrib:
            if not api in feature.attrib["api"]:
                continue;
        
        if "supported" in feature.attrib:
            if not api in feature.attrib["supported"]:
                continue;
        
        if feature.tag == "extension":
            extensionnames.append(feature.attrib["name"])
        
        outFile.write("#ifndef %s\n" % (feature.attrib["name"]))
        outFile.write("#define %s 1\n" % (feature.attrib["name"]))
        outFile.write("#endif\n\n")
        
        for require in feature.findall("require"):
            for command in require.findall("command"):
                commandnames.append(command.attrib["name"])
                
                outFile.write(rescommands[command.attrib["name"]])
            
            for enum in require.findall("enum"):
                outFile.write(resenums[enum.attrib["name"]])
    
    commandnames = list(set(commandnames))
    
    for extension in root.find("extensions").findall("extension"):
        outFile.write("extern bool GLFL_%s;\n" % (extension.attrib["name"]))
    
    outFile.write("\n")
    
    for commandname in commandnames:
        outFile.write("extern PFN%sPROC glfl%s;\n" % (commandname.upper(), commandname))
        outFile.write("#define %s glfl%s\n" % (commandname, commandname))
    
    outFile.write("bool glflIsExtensionSupported(const char *name);\nint glflInit();\n#endif")
    
    outFile.close()
    
    print "Generated glfl.h"
    
    outFile = open("../src/graphics/GL/glfl.cpp", "w")
    
    outFile.write("""//This file was generated by genGLFL.py. Do not edit.

#include "graphics/GL/glfl.h"

#ifdef GLFL_USE_GLX
#include <GL/glx.h>

#define glflGetProcAddress(name) glXGetProcAddress((const GLubyte *)(name))
#elif defined(GLFL_USE_SDL2)
#include <SDL2/SDL.h>

#define glflGetProcAddress(name) SDL_GL_GetProcAddress(name)
#endif

#include <string.h>

%s

%s

bool glflIsExtensionSupported(const char *name)
{
    unsigned int numExtensions;

    glGetIntegerv(GL_NUM_EXTENSIONS, (GLint *)&numExtensions);

    for (unsigned int i=0; i<numExtensions; ++i)
    {
        if (strcmp(name, (const char *)glGetStringi(GL_EXTENSIONS, i)) == 0)
        {
            return true;
        }
    }

    return false;
}

int glflInit()
{
%s

%s

    return 1;
}""" % ("\n".join(("PFN%sPROC glfl%s;" % (name.upper(), name)) for name in commandnames),
        "\n".join(("bool GLFL_%s;" % (ext)) for ext in extensionnames),
        "\n".join(("    glfl%s = (PFN%sPROC)glflGetProcAddress(\"%s\");" % (name, name.upper(), name)) for name in commandnames),
        "\n".join(("    GLFL_%s = glflIsExtensionSupported(\"%s\");" % (ext, ext)) for ext in extensionnames)))

    outFile.close()

    print "Generated glfl.cpp"

generate("gl")

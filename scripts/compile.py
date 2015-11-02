import os
import shutil
import xml.etree.ElementTree as ET

os.system("python update_extensions.py")

target = "debug" #Change to "release" for a release target.
process_count = 3

options = "-Wall -fexceptions `sdl2-config --cflags` `pkg-config bullet --cflags` `freetype-config --cflags` `pkg-config vorbisfile --cflags` -std=gnu++11 -DUSE_SDL2 -DGLFL_USE_SDL2 -DGLFL_USE_GL -I../include -D_REENTRANT -fno-strict-aliasing"

if target == "debug":
    options += " -g -DDEBUG"
elif target == "release":
    options += "-O3 -DNDEBUG"

tree = ET.parse("../WIP12.cbp")
root = tree.getroot()

project = [p for p in root.iter("Project")][0]

objs = []

pipes = []

num_compiled = 0
num_to_compile = 0

for unit in project.iter("Unit"):
    filename = unit.attrib["filename"]

    if filename.startswith("src"):
        num_to_compile += 1

for unit in project.iter("Unit"):
    filename = unit.attrib["filename"]

    if filename.startswith("src"):
        try:
            os.makedirs(".obj/%s" % (os.path.split(filename)[0]))
        except:
            pass
        
        command = "g++ -c ../%s -o \".obj/%s.o\" %s" % (filename, filename, options)
        
        pipes.append(os.popen(command))
        
        objs.append(".obj/%s.o" % (filename))
    
    if len(pipes) == process_count:
        for pipe in pipes:
            pipe.close()
            
            num_compiled += 1

for pipe in pipes:
    pipe.close()

os.system("g++ %s -o \"../bin/WIP12\" -rdynamic `sdl2-config --libs` `pkg-config bullet --libs` `freetype-config --libs` `pkg-config vorbisfile --libs` -lGL -lBulletDynamics -lBulletCollision -lLinearMath -ldl" %
          " ".join(objs))

shutil.rmtree(".obj")

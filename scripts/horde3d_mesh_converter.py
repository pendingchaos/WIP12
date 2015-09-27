#!/usr/bin/env python
# -*- coding: utf-8 -*-
# Running: python horde3d_mesh_converter.py <blah>.scene.xml <blah>.geo <blah>.anim
import sys
import struct
import xml.etree.ElementTree
import os.path
import euclid
import math

scene = sys.argv[1]
mesh = open(sys.argv[2], "rb")
animation = open(sys.argv[3], "rb")

numJoints = 0
joints = [] # [[[0.0,0.0,0.0,0.0],
            #   [0.0,0.0,0.0,0.0],
            #   [0.0,0.0,0.0,0.0],
            #   [0.0,0.0,0.0,0.0]]]
bones = {} # {bone_name: (joint_index, joints[joint_index], parent_name_or_none, [child_name1...], (rx,ry,rz, tx,ty,tz))}
positions = [] # [(0.0, 0.0, 0.0)...]
normals = [] # [(0.0, 0.0, 0.0)...]
tangents = [] # [(0.0, 0.0, 0.0)...]
boneIndices = [] # [(0, 0, 0, 0)...]
boneWeights = [] # [(0.0, 0.0, 0.0, 0.0)...]
texCoords = [] # [(0.0, 0.0)...]
indices = [] # [0...]
numIndices = 0
numVertices = 0
frames = [] # [[(rx,ry,rz,rw, tx,ty,tz, sx,sy,sz)]]

# Mesh
mesh.read(8) # Magic and version

numJoints = struct.unpack("<L", mesh.read(4))[0]

for i in xrange(0, numJoints):
    matrix = [[struct.unpack("f", mesh.read(4))[0] for j in xrange(4)] for i in xrange(4)]
    new_matrix = [[0,0,0,0],
                  [0,0,0,0],
                  [0,0,0,0],
                  [0,0,0,0]]
    
    for i in xrange(4):
        for j in xrange(4):
            new_matrix[i][j] = matrix[j][i]
    
    joints.append(new_matrix)

numStreams, numVertices = struct.unpack("<LL", mesh.read(8))

for i in xrange(numStreams):
    streamType = struct.unpack("<L", mesh.read(4))[0]
    
    elemSize = struct.unpack("<L", mesh.read(4))[0]
    
    if streamType == 0:
        for j in xrange(numVertices):
            positions.append(struct.unpack("fff", mesh.read(12)))
    elif streamType == 1:
        for j in xrange(numVertices):
            normals.append(tuple([v / 32767.0 for v in list(struct.unpack("<hhh", mesh.read(6)))]))
    elif streamType == 2:
        for j in xrange(numVertices):
            tangents.append(tuple([v / 32767.0 for v in list(struct.unpack("<hhh", mesh.read(6)))]))
    elif streamType == 4:
        for j in xrange(numVertices):
            boneIndices.append(struct.unpack("<BBBB", mesh.read(4)))
    elif streamType == 5:
        for j in xrange(numVertices):
            boneWeights.append(tuple([v / 255.0 for v in list(struct.unpack("<BBBB", mesh.read(4)))]))
    elif streamType == 6:
        for j in xrange(numVertices):
            texCoords.append(struct.unpack("<ff", mesh.read(8)))
    else:
        mesh.read(elemSize * numVertices)

numIndices = struct.unpack("<L", mesh.read(4))[0]
indices = [struct.unpack("<L", mesh.read(4))[0] for i in xrange(numIndices)]

positions = positions[:numVertices]
normals = normals[:numVertices]
tangents = tangents[:numVertices]
boneIndices = boneIndices[:numVertices]
boneWeights = boneWeights[:numVertices]
texCoords = texCoords[:numVertices]

"""# For the head and sword removal hack
positions = [positions[index] for index in indices]
normals = [normals[index] for index in indices]
tangents = [tangents[index] for index in indices]
boneIndices = [boneIndices[index] for index in indices]
boneWeights = [boneWeights[index] for index in indices]
texCoords = [texCoords[index] for index in indices]
indices = range(numIndices)
numVertices = numIndices"""

print "numBones:", numJoints
print "numIndices:", numIndices
print "numVertices:", numVertices

# Scene (for the bones)
elem = xml.etree.ElementTree.ElementTree().parse(scene)

done = {}

def process_joint(joint, bones, parent, transform):
    name = joint.attrib["name"]
    
    index = int(joint.attrib["jointIndex"])
    
    transform = (euclid.Matrix4.new_translate(-float(joint.attrib.get("tx", 0.0)),
                                              -float(joint.attrib.get("ty", 0.0)),
                                              -float(joint.attrib.get("tz", 0.0))) * \
                 euclid.Matrix4.new_rotate_euler(-math.radians(float(joint.attrib.get("rx", 0.0))),
                                                 -math.radians(float(joint.attrib.get("ry", 0.0))),
                                                 -math.radians(float(joint.attrib.get("rz", 0.0)))))
    
    bones[name] = (index,
                   joints[index],
                   parent,
                   [process_joint(child, bones, name, transform) for child in joint if child.tag == "Joint"],
                   (float(joint.attrib.get("rx", 0.0)),
                    float(joint.attrib.get("ry", 0.0)),
                    float(joint.attrib.get("rz", 0.0)),
                    float(joint.attrib.get("tx", 0.0)),
                    float(joint.attrib.get("ty", 0.0)),
                    float(joint.attrib.get("tz", 0.0))))
    """
    # A hack to get rid of the sword and the helmet.
    for child in [child for child in joint if child.tag == "Mesh"]:
        print child.attrib["name"]
        for i in xrange(int(child.attrib["batchStart"]), int(child.attrib["batchStart"])+int(child.attrib["batchCount"])):
            positions[i] = (0.0, 0.0, 0.0)
    """
    return name

names = []
bones["_root"] = (0, joints[0], None, names, (0.0, 0.0, 0.0, 0.0, 0.0, 0.0))

for joint in [j for j in elem if j.tag == "Joint"]:
    process_joint(joint, bones, "_root", euclid.Matrix4())
    
    names.append(joint.attrib["name"])

# Animation
# Note: Runs at 24 FPS
animation.read(8)

numNodes, numFrames = struct.unpack("<LL", animation.read(8))

frames = [[(0.0,0.0,0.0,1.0, 0.0,0.0,0.0, 1.0,1.0,1.0) for i in xrange(len(joints))] for i in xrange(numFrames)]

for i in xrange(numNodes):
    nodeName = animation.read(256)
    nodeName = nodeName[:nodeName.find("\x00")]
    
    compressed = struct.unpack("?", animation.read(1))[0]
    
    if not nodeName in bones:
        animation.read(40 if compressed else (40 * numFrames))
        continue
    
    if compressed:
        frame = struct.unpack("ffffffffff", animation.read(40))
        
        for j in xrange(numFrames):
            frames[j][bones[nodeName][0]] = frame
    else:
        for j in xrange(numFrames):
            frames[j][bones[nodeName][0]] = struct.unpack("ffffffffff", animation.read(40))

print "numFrames:", numFrames

# Output the new mesh
aabb = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]

for pos in positions:
    aabb[0] = min(pos[0], aabb[0])
    aabb[1] = min(pos[1], aabb[1])
    aabb[2] = min(pos[2], aabb[2])
    aabb[3] = max(pos[0], aabb[3])
    aabb[4] = max(pos[1], aabb[4])
    aabb[5] = max(pos[2], aabb[5])

output = open("../bin/programs/main/resources/meshes/soldier.bin", "wb")
output.write("mesh\x00\x00")
output.write(struct.pack("<L", len(indices)))
output.write("\x01") # Indexed
output.write("\x06") # Primitive
output.write("\x00") # Cull mode
output.write("\x01") # Winding
output.write(struct.pack("<ffffff", *aabb))
output.write(struct.pack("<L", 6)) # Attribute count

# Positions
output.write(struct.pack("<BBL", 0, 6, numVertices*12)) # Type, data type, size
output.write("".join([struct.pack("fff", *pos) for pos in positions]))

# Normal
output.write(struct.pack("<BBL", 1, 22, numVertices*6)) # Type, data type, size
output.write("".join([struct.pack("<hhh", int(norm[0] * 32767), int(norm[1] * 32767), int(norm[2] * 32767)) for norm in normals]))

# Tangent
output.write(struct.pack("<BBL", 2, 22, numVertices*6)) # Type, data type, size
output.write("".join([struct.pack("<hhh", int(tang[0] * 32767), int(tang[1] * 32767), int(tang[2] * 32767)) for tang in tangents]))

# Tex coords
output.write(struct.pack("<BBL", 4, 17, numVertices*4)) # Type, data type, size
output.write("".join([struct.pack("<HH", min(int(coord[0] * 65535), 65535), min(int(coord[1] * 65535), 65535)) for coord in texCoords]))

# Bone indices
output.write(struct.pack("<BBL", 5, 11, numVertices*4)) # Type, data type, size
output.write("".join([struct.pack("BBBB", *ind) for ind in boneIndices]))

# Bone weights
output.write(struct.pack("<BBL", 6, 35, numVertices*4)) # Type, data type, size
output.write("".join([struct.pack("BBBB", int(weight[0] * 255), int(weight[1] * 255), int(weight[2] * 255), int(weight[3] * 255)) for weight in boneWeights]))

output.write(struct.pack("<B", 2)) # Index type

for index in indices:
    output.write(struct.pack("<L", index))

output.write(struct.pack("<L", len(bones)))

for i in xrange(numJoints):
    bone = None
    
    for bone in bones.values():
        if bone[0] == i:
            break
    
    output.write(struct.pack("ffff", *(bone[1][0])))
    output.write(struct.pack("ffff", *(bone[1][1])))
    output.write(struct.pack("ffff", *(bone[1][2])))
    output.write(struct.pack("ffff", *(bone[1][3])))
    
    output.write(struct.pack("<L", len(bone[3])))

    for child in bone[3]:
        output.write(struct.pack("<B", bones[child][0]))

output.write(struct.pack("<L", 1)) # Animation count

animName = os.path.splitext(os.path.split(sys.argv[3])[1])[0]

print "Animation name: \"%s\"" % (animName)

output.write(struct.pack("<L", len(animName)))
output.write(animName)

output.write(struct.pack("<L", 24)) # FPS
output.write(struct.pack("<L", len(frames)))

i = 0

for frame in frames:
    boneIndex = 0
    for transform in frame:
        bone = None
        
        for bone in bones.values():
            if bone[0] == boneIndex:
                break
        
        output.write(struct.pack("ffffffffff",
                                 transform[0],
                                 transform[1],
                                 transform[2],
                                 transform[3],
                                 transform[7],
                                 transform[8],
                                 transform[9],
                                 transform[4],
                                 transform[5],
                                 transform[6]))
        
        boneIndex += 1
    
    i += 1

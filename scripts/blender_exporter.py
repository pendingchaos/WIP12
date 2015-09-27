bl_info = {"name":"WIP12 Mesh",
           "author":"",
           "blender":(2, 7, 2),
           "version":(1, 0, 0),
           "location":"File > Export",
           "description":"Export WIP12 mesh.",
           "category":"Import-Export"}

import bpy
import struct
from mathutils import *
from bpy_extras.io_utils import ExportHelper

def mesh_triangulate(me):
    import bmesh
    bm = bmesh.new()
    bm.from_mesh(me)
    bmesh.ops.triangulate(bm, faces=bm.faces)
    bm.to_mesh(me)
    bm.free()

def clamp(v, min_, max_):
    return min(max(v, min_), max_)

class ExportWIP12(bpy.types.Operator, ExportHelper):
    bl_idname = "export_mesh.bin"
    bl_label = "WIP12 Mesh Exporter"
    bl_optionas = {"PRESET"}
    
    filename_ext = ".bin"
    
    def execute(self, context):
        scene = context.scene
        objects = scene.objects
        
        obj = context.object
        
        if obj == None:
            raise Exception("No object selected.")
        
        me = obj.to_mesh(scene, True, 'PREVIEW', calc_tessface=False)
        armObj = obj.find_armature()
        
        arm = armObj.data if armObj != None else None
        
        mesh_triangulate(me)
        
        uv_layer = me.uv_layers.active
        
        if uv_layer == None:
            raise Exception("No active uv layer.")
        
        me.calc_tangents();
        
        positions = []
        normals = []
        tangents = []
        boneIndices = []
        boneWeights = []
        texCoords = []
        numVertices = 0
        numIndices = 0
        
        boneToIndex = {}
        indexToBone = {}
        boneNameToBone = {}
        indexToBoneMatrix = {}
        numBones = 0
        
        if arm != None:
            for bone in arm.bones:
                boneToIndex[bone] = numBones
                indexToBone[numBones] = bone
                boneNameToBone[bone.name] = bone
                indexToBoneMatrix[numBones] = Matrix(obj.matrix_world) * Matrix(bone.matrix_local)
                numBones += 1
        
        warned = False
        
        for poly in me.polygons:
            for loop_index in range(poly.loop_start, poly.loop_start + poly.loop_total):
                numVertices += 1
                numIndices += 1
                
                loop = me.loops[loop_index]
                
                vertex = me.vertices[loop.vertex_index]
                
                uv = uv_layer.data[loop_index].uv
                
                positions.append(vertex.co[0])
                positions.append(vertex.co[1])
                positions.append(vertex.co[2])
                normals.append(vertex.normal[0])
                normals.append(vertex.normal[1])
                normals.append(vertex.normal[2])
                tangents.append(loop.tangent[0])
                tangents.append(loop.tangent[1])
                tangents.append(loop.tangent[2])
                
                if arm != None:
                    indices = []
                    weights = []
                    
                    for group in vertex.groups:
                        bone_name = obj.vertex_groups[group.group].name
                        indices.append(boneToIndex[boneNameToBone[bone_name]])
                        weights.append(int(group.weight * 255))
                    
                    while len(weights) > 4:
                        if not warned:
                            print("Warning: Maximum bone influences per vertex (4) has been exceeded.")
                            warned = True
                        
                        minIdx = 0
                        
                        for i in range(len(weights)):
                            if weights[i] < weights[minIdx]:
                                minIdx = i
                        
                        del indices[minIdx]
                        del weights[minIdx]
                    
                    divide = sum([w/255.0 for w in weights])
                    
                    weights = [int(weight / divide) for weight in weights]
                    
                    boneIndices.append(tuple(indices + [0]*(4-len(indices))))
                    boneWeights.append(tuple(weights + [0]*(4-len(weights))))
                
                texCoords.append(uv[0])
                texCoords.append(uv[1])
        
        f = open(self.filepath, "wb")
        
        f.write(b"mesh\x00\x00")
        f.write(struct.pack("<L", numVertices))
        f.write(b"\x00") # Indexed
        f.write(b"\x06") # Primitve
        f.write(b"\x00") # Cull mode
        f.write(b"\x01") # Winding
        
        aabb = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
        
        if arm != None:
            frame_begin, frame_end = armObj.animation_data.action.frame_range
            
            last_frame = scene.frame_current
            
            for i in range(int(frame_begin), int(frame_end)):
                scene.frame_set(i)
                
                bb = obj.bound_box
                
                aabb[0] = min(aabb[0], *tuple([v[0] for v in bb]))
                aabb[1] = min(aabb[1], *tuple([v[1] for v in bb]))
                aabb[2] = min(aabb[2], *tuple([v[2] for v in bb]))
                aabb[3] = max(aabb[3], *tuple([v[0] for v in bb]))
                aabb[4] = max(aabb[4], *tuple([v[1] for v in bb]))
                aabb[5] = max(aabb[5], *tuple([v[2] for v in bb]))
            
            scene.frame_set(last_frame)
        else:
            bb = obj.bound_box
            
            aabb[0] = min(*tuple([v[0] for v in bb]))
            aabb[1] = min(*tuple([v[1] for v in bb]))
            aabb[2] = min(*tuple([v[2] for v in bb]))
            aabb[3] = max(*tuple([v[0] for v in bb]))
            aabb[4] = max(*tuple([v[1] for v in bb]))
            aabb[5] = max(*tuple([v[2] for v in bb]))
        
        f.write(struct.pack("ffffff", *tuple(aabb))) # AABB
        
        f.write(struct.pack("<L", 6 if arm != None else 4)) # Attribute count
        
        # Positions
        f.write(struct.pack("<BBL", 0, 6, numVertices*12)) # Type, data type, size
        f.write(struct.pack("%df" % (numVertices*3), *tuple(positions)))
        
        # Normals
        f.write(struct.pack("<BBL", 1, 22, numVertices*6)) # Type, data type, size
        f.write(struct.pack("<%dh" % (numVertices*3), *tuple([clamp(int(v * 32767), -32767, 32767) for v in normals])))
        
        # Tangents
        f.write(struct.pack("<BBL", 2, 22, numVertices*6)) # Type, data type, size
        f.write(struct.pack("<%dh" % (numVertices*3), *tuple([clamp(int(v * 32767), -32767, 32767) for v in tangents])))
        
        # Tex coords
        f.write(struct.pack("<BBL", 4, 17, numVertices*4)) # Type, data type, size
        f.write(struct.pack("<%dH" % (numVertices*2), *tuple([clamp(int(v * 65535), 0, 65535) for v in texCoords])))
        
        if arm != None:
            # Bone indices
            f.write(struct.pack("<BBL", 5, 11, numVertices*4)) # Type, data type, size
            
            f.write(b"".join([struct.pack("BBBB", *v) for v in boneIndices]))
            
            # Bone weights
            f.write(struct.pack("<BBL", 6, 35, numVertices*4)) # Type, data type, size
            f.write(b"".join([struct.pack("BBBB", *v) for v in boneWeights]))
        
        f.write(b"\x00") # Index type
        
        f.write(struct.pack("<L", numBones)) # Num bones
        
        for i in range(numBones):
            matrix = indexToBoneMatrix[i]
            matrix = matrix.row[:]
            matrix = matrix[0][:] + matrix[1][:] + matrix[2][:] + matrix[3][:]
            
            f.write(struct.pack("16f", *tuple(matrix)))
            
            f.write(struct.pack("<L", len(indexToBone[i].children)))
            
            for child in indexToBone[i].children:
                f.write(struct.pack("B", boneToIndex[child]))
        
        f.write(struct.pack("<L", 1 if arm != None else 0)) # Num animations
        
        if arm != None:
            action = armObj.animation_data.action
            
            f.write(struct.pack("<L", len(action.name)))
            f.write(action.name.encode("ascii"))
            
            print("Animation name:", action.name)
            
            frame_begin, frame_end = action.frame_range
            frame_begin = int(frame_begin)
            frame_end = int(frame_end)
            
            f.write(struct.pack("<LL", 24, frame_end - frame_begin))
            
            last_frame = scene.frame_current
            
            for i in range(frame_begin, frame_end):
                scene.frame_set(i)
                
                pose = armObj.pose
                
                for j in range(numBones):
                    def get_mat(bone):
                        return Matrix(pose.bones[bone.name].matrix_basis)
                        matrix = Matrix(pose.bones[bone.name].matrix)
                        
                        if bone.parent != None:
                            return get_mat(bone.parent).inverted_safe() * matrix
                        else:
                            return armObj.matrix_world * matrix
                    
                    matrix = get_mat(indexToBone[j])
                    
                    quat = matrix.to_quaternion().normalized()
                    scale = matrix.to_scale()
                    translation = matrix.to_translation()
                    
                    f.write(struct.pack("ffffffffff",
                                        quat.x, quat.y, quat.z, quat.w,
                                        scale.x, scale.y, scale.z,
                                        translation.x, translation.y, translation.z))
            
            scene.frame_set(last_frame)
        
        return {'FINISHED'}

def menu_func(self, context):
    self.layout.operator(ExportWIP12.bl_idname, text="WIP12 (.bin)")

def register():
    bpy.utils.register_class(ExportWIP12)
    bpy.types.INFO_MT_file_export.append(menu_func)

def unregister():
    bpy.types.INFO_MT_file_export.remove(menu_func)
    bpy.utils.unregister_class(ExportWIP12)

if __name__ == "__main__":
    register()

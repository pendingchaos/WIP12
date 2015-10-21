bl_info = {"name":"WIP12 Mesh",
           "author":"",
           "blender":(2, 7, 2),
           "version":(1, 0, 0),
           "location":"File > Export",
           "description":"Export WIP12 mesh.",
           "category":"Import-Export"}

import bpy
import struct
from bpy_extras.io_utils import ExportHelper

def mesh_triangulate(me):
    import bmesh
    bm = bmesh.new()
    bm.from_mesh(me)
    bmesh.ops.triangulate(bm, faces=bm.faces)
    bm.to_mesh(me)
    bm.free()

class ExportWIP(bpy.types.Operator, ExportHelper):
    bl_idname = "export_mesh.bin"
    bl_label = "WIP12 Mesh Exporter"
    bl_optionas = {"PRESET"}
    
    filename_ext = ".bin"
    
    def execute(self, context):
        objects = context.scene.objects

        for obj in objects:
            if obj.type == 'MESH':
                try:
                    me = obj.to_mesh(context.scene, True, 'PREVIEW', calc_tessface=False)
                except RuntimeError:
                    continue
                
                mesh_triangulate(me)
                
                me.calc_tangents();
                
                indices = []
                positions = []
                normals = []
                tangents = []
                boneIndices = []
                boneWeights = []
                texCoords = []
                
                for poly in me.polygons:
                    for loop_index in range(poly.loop_start, poly.loop_start + poly.loop_total):
                        indices.append(len(indices))
                        indices.append(len(indices))
                        indices.append(len(indices))
                        
                        loop = me.loops[loop_index]
                        
                        vertex = me.vertices[loop.vertex_index]
                        
                        uv = me.uv_layers.active.data
                        
                        positions.append(vertex.co[0])
                        positions.append(vertex.co[1])
                        positions.append(vertex.co[2])
                        normals.append(vertex.normal[0])
                        normals.append(vertex.normal[1])
                        normals.append(vertex.normal[2])
                        tangents.append(loop.tangent[0])
                        tangents.append(loop.tangent[1])
                        tangents.append(loop.tangent[2])
                        #TODO: boneIndices and boneWeights
                        texCoords.append(uv[0])
                        texCoords.append(uv[1])
            elif obj.type == 'ARMATURE':
                pass
        
        return {'FINISHED'}

def menu_func(self, context):
    self.layout.operator(ExportWIP12.bl_idname, text="WIP12 (.bin)")

def register():
    bpy.utils.register_module(__name__)
    bpy.types.INFO_MT_file_export.append(menu_func)

def unregister():
    bpy.utils.unregister_module(__name__)
    bpy.types.INFO_MT_file_export.remove(menu_func)

if __name__ == "__main__":
    register()

import os
import os.path
import json
import struct
from PIL import Image
import ctypes

class Resource(object):
    def __init__(self, type_, src_filenames, dest_filename):
        self.type_ = type_
        self.src_filenames = src_filenames
        self.dest_filename = dest_filename
    
    def load(self, json_data):
        pass
    
    def save(self):
        return {}
    
    def convert(self):
        pass

if __name__ == "__main__":
    def get_dest_filename(obj, type_, allowNone=False):
        if obj == None and allowNone:
            return None
        
        return obj.dest_filename if isinstance(obj, type_) else str(obj)
    
    meshConverter = ctypes.CDLL("./libMeshConverter.so")
    
    class Texture(Resource):
        class Filter:
            Nearest = "nearest"
            Bilinear = "bilinear"
        
        class MipmapMode:
            None_ = "none"
            Nearest = "nearest"
            Linear = "linear"
        
        class WrapMode:
            Stretch = "stretch"
            Repeat = "repeat"
            Mirror = "mirror"
        
        class Purpose:
            Color = "color"
            Normal = "normal"
            Other = "other"
        
        def __init__(self, src_filenames, dest_filename):
            Resource.__init__(self, "texture", src_filenames, dest_filename)
            
            self.compress = False
            self.compression_quality = 1.0
            self.max_anisotropy = 4.0
            self.min_filter = Texture.Filter.Bilinear
            self.mag_filter = Texture.Filter.Bilinear
            self.mipmap_mode = Texture.MipmapMode.Linear
            self.wrap_mode = Texture.WrapMode.Repeat
            self.purpose = Texture.Purpose.Color
        
        def convert(self):
            out = open(self.dest_filename+".temp", "wb")
            
            if not (len(self.src_filenames) in [1, 6]):
                print "Error: %d face textures are not supported." % (len(self.src_filenames))
                
                return
            
            faces = [Image.open(src_filename) for src_filename in self.src_filenames]
            
            sizes = [face.size for face in faces]
            
            for size in sizes:
                if size != sizes[0]:
                    print "Error: All faces must be the same size."
                    
                    return
            
            [face.transpose(Image.FLIP_TOP_BOTTOM) for face in faces]
            
            for i in xrange(len(faces)):
                if faces[i].mode in ["1", "P", "CMYK", "YCbCr", "LAB", "HSV","I", "F", "RGBX"]:
                    faces[i] = faces[i].convert("RGBA")
            
            numChannels = 0
            
            for face in faces:
                numChannels = max(numChannels, len(faces[i].mode))
            
            for i in xrange(len(faces)):
                faces[i] = faces[i].convert(["L", "RGBA", "RGB", "RGBA"][numChannels-1])
            
            srgb = self.purpose == Texture.Purpose.Color
            
            try:
                srgb = srgb and (faces[0].info["gamma"] == 2.2)
            except KeyError:
                pass
            
            if srgb:
                for i in xrange(len(faces)):
                    if faces[i].mode == "L":
                        faces[i] = faces[i].convert("RGB")
            
            num_mipmaps = self.get_num_mipmaps(faces[0])
            
            out.write("texr\x01\x00")
            out.write(struct.pack("<?BBBfBBBBBLLLL",
                                  self.compress,
                                  int(self.compression_quality*255.0),
                                  {Texture.Filter.Nearest:0,
                                   Texture.Filter.Bilinear:1}[self.min_filter],
                                  {Texture.Filter.Nearest:0,
                                   Texture.Filter.Bilinear:1}[self.mag_filter],
                                  self.max_anisotropy,
                                  {Texture.MipmapMode.None_:0,
                                   Texture.MipmapMode.Nearest:1,
                                   Texture.MipmapMode.Linear:2}[self.mipmap_mode],
                                  {Texture.WrapMode.Stretch:0,
                                   Texture.WrapMode.Repeat:1,
                                   Texture.WrapMode.Mirror:2}[self.wrap_mode],
                                  {Texture.Purpose.Color:0,
                                   Texture.Purpose.Normal:1,
                                   Texture.Purpose.Other:2}[self.purpose],
                                  {"RGB": 54,
                                   "RGBA": 55}[faces[0].mode] if srgb else \
                                  {"L": 6,
                                   "RGB": 18,
                                   "RGBA": 24}[faces[0].mode],
                                  0 if len(faces) == 1 else 1,
                                  num_mipmaps,
                                  faces[0].size[0],
                                  faces[0].size[1],
                                  1))
            
            for face in faces:
                for j in xrange(num_mipmaps):
                    data = face.tobytes()
                    
                    out.write(struct.pack("<L", len(data)))
                    
                    out.write(data)
                    
                    face = face.resize((face.size[0]/2, face.size[1]/2), Image.ANTIALIAS)
            
            out.close()
            
            os.rename(self.dest_filename+".temp", self.dest_filename)
        
        def get_num_mipmaps(self, img):
            width, height = img.size
            num_mipmaps = 1
            
            while width != 1 and height != 1:
                width /= 2
                height /= 2
                
                num_mipmaps += 1
            
            return num_mipmaps

    class Shader(Resource):
        class Stage:
            Vertex = "vertex"
            TessControl = "tessControl"
            TessEval = "tessEval"
            Geometry = "geometry"
            Fragment = "fragment"
            Compute = "compute"

        def __init__(self, src_filenames, dest_filename):
            Resource.__init__(self, "shader", src_filenames, dest_filename)
            
            self.stage_ = Shader.Stage.Vertex
        
        def include_files(self, glsl_filename, glsl):
            lines = glsl.split("\n")
            
            result = ""
            
            linenum = 0
            
            for line in lines:
                if line.startswith("#include"):
                    filename = line.split("\"")[1]
                    
                    filename = os.path.normpath(os.path.join(os.path.split(glsl_filename)[0], filename))
                    
                    included = self.include_files(filename, open(filename, "r").read())
                    
                    result += "#line 0 \"%s\"\n%s\n#line %d \"%s\"\n" % (filename,
                                                                         included,
                                                                         linenum+1,
                                                                         glsl_filename)
                    
                    linenum += 1
                else:
                    result += line + "\n"
                
                linenum += 1
            
            return result
        
        def convert(self):
            out = open(self.dest_filename+".temp", "wb")
            
            glsl = self.include_files(self.src_filenames[0],
                                      open(self.src_filenames[0], "r").read())
            
            out.write("shdr\x01\x00")
            out.write(struct.pack("<B",
                                  {Shader.Stage.Vertex:0,
                                   Shader.Stage.TessControl:1,
                                   Shader.Stage.TessEval:2,
                                   Shader.Stage.Geometry:3,
                                   Shader.Stage.Fragment:4,
                                   Shader.Stage.Compute:5}[self.stage_]))
                
            out.write(glsl)
            
            out.close()
            
            os.rename(self.dest_filename+".temp", self.dest_filename)
    
    class Mesh(Resource):
        def __init__(self, src_filenames, dest_filename):
            Resource.__init__(self, "mesh", src_filenames, dest_filename)
        
        def convert(self):
            src = self.src_filenames[0].encode("ascii")
            dest = (self.dest_filename+".temp").encode("ascii")
            
            meshConverter.convert(src, dest)
            
            os.rename(self.dest_filename+".temp", self.dest_filename)
    
    class Material(Resource):
        def __init__(self, src_filenames, dest_filename):
            Resource.__init__(self, "material", src_filenames, dest_filename)
            
            self.forward = True
            self.albedo = [1.0, 1.0, 1.0, 1.0]
            self.smoothness = 0.6
            self.metalMask = 0.0
            self.parallaxStrength = 0.0
            self.albedoMap = None
            self.smoothnessMap = None
            self.metalMaskMap = None
            self.normalMap = None
            self.parallaxHeightMap = None
            self.pomHeightMap = None
            self.parallaxEdgeDiscard = True
            self.pomMinLayers = 8
            self.pomMaxLayers = 32
        
        def convert(self):
            output = open(self.dest_filename+".temp", "wb")
            
            output.write("mtrl\x01\x00")
            
            s = struct.pack("<bfffffffbbb",
                            self.forward,
                            self.albedo[0],
                            self.albedo[1],
                            self.albedo[2],
                            self.albedo[3],
                            self.smoothness,
                            self.metalMask,
                            self.parallaxStrength,
                            self.parallaxEdgeDiscard,
                            self.pomMinLayers,
                            self.pomMaxLayers)
            
            if self.albedoMap != None:
                s += struct.pack("<L", len(get_dest_filename(self.albedoMap, Texture)))
                s += get_dest_filename(self.albedoMap, Texture)
            else:
                s += struct.pack("<L", 0)
            
            if self.smoothnessMap != None:
                s += struct.pack("<L", len(get_dest_filename(self.smoothnessMap, Texture)))
                s += get_dest_filename(self.smoothnessMap, Texture)
            else:
                s += struct.pack("<L", 0)
            
            if self.metalMaskMap != None:
                s += struct.pack("<L", len(get_dest_filename(self.metalMaskMap, Texture)))
                s += get_dest_filename(self.metalMaskMap, Texture)
            else:
                s += struct.pack("<L", 0)
            
            if self.normalMap != None:
                s += struct.pack("<L", len(get_dest_filename(self.normalMap, Texture)))
                s += get_dest_filename(self.normalMap, Texture)
            else:
                s += struct.pack("<L", 0)
            
            if self.parallaxHeightMap != None:
                s += struct.pack("<L", len(get_dest_filename(self.parallaxHeightMap, Texture)))
                s += get_dest_filename(self.parallaxHeightMap, Texture)
            else:
                s += struct.pack("<L", 0)
            
            if self.pomHeightMap != None:
                s += struct.pack("<L", len(get_dest_filename(self.pomHeightMap, Texture)))
                s += get_dest_filename(self.pomHeightMap, Texture)
            else:
                s += struct.pack("<L", 0)
            
            output.write(s)
            
            output.close()
            
            os.rename(self.dest_filename+".temp", self.dest_filename)
    
    class Model(Resource):
        class LOD(object):
            def __init__(self, mesh, material, min_distance, max_distance):
                self.mesh = mesh
                self.material = material
                self.min_distance = min_distance
                self.max_distance = max_distance
                self.worldMatrix = [[1.0, 0.0, 0.0, 0.0],
                                    [0.0, 1.0, 0.0, 0.0],
                                    [0.0, 0.0, 1.0, 0.0],
                                    [0.0, 0.0, 0.0, 1.0]]
        
        def __init__(self, src_filenames, dest_filename):
            Resource.__init__(self, "model", src_filenames, dest_filename)
            
            self.sub_models = []
        
        def convert(self):
            output = open(self.dest_filename+".temp", "wb")
            
            output.write("modl\x01\x00")
            
            output.write(struct.pack("<L", len(self.sub_models)))
            
            for lods in self.sub_models:
                output.write(struct.pack("<L", len(lods)))
                
                for lod in lods:
                    mesh_file = get_dest_filename(lod.mesh, Mesh)
                    material_file = get_dest_filename(lod.material, Material)
                    
                    output.write(struct.pack("ff", lod.min_distance, lod.max_distance))
                    
                    output.write(struct.pack("ffffffffffffffff",
                                             lod.worldMatrix[0][0],
                                             lod.worldMatrix[0][1],
                                             lod.worldMatrix[0][2],
                                             lod.worldMatrix[0][3],
                                             lod.worldMatrix[1][0],
                                             lod.worldMatrix[1][1],
                                             lod.worldMatrix[1][2],
                                             lod.worldMatrix[1][3],
                                             lod.worldMatrix[2][0],
                                             lod.worldMatrix[2][1],
                                             lod.worldMatrix[2][2],
                                             lod.worldMatrix[2][3],
                                             lod.worldMatrix[3][0],
                                             lod.worldMatrix[3][1],
                                             lod.worldMatrix[3][2],
                                             lod.worldMatrix[3][3]))
                    
                    output.write(struct.pack("<L", len(mesh_file)))
                    output.write(mesh_file)
                    
                    output.write(struct.pack("<L", len(material_file)))
                    output.write(material_file)
            
            output.close()
            
            os.rename(self.dest_filename+".temp", self.dest_filename)
    
    class PhysicsShape(Resource):
        class Shape(object):
            def convert(self):
                return ""
        
        class Sphere(Shape):
            def __init__(self, radius=1.0):
                self.radius = radius
            
            def convert(self):
                return "\x00"+struct.pack("<f", self.radius)
        
        class Box(Shape):
            def __init__(self, halfExtents=[1.0, 1.0, 1.0]):
                self.halfExtents = [halfExtents[0], halfExtents[1], halfExtents[2]]
            
            def convert(self):
                return "\x01"+struct.pack("<fff", self.halfExtents[0], self.halfExtents[1], self.halfExtents[2])
        
        class Cylinder(Shape):
            def __init__(self, axis="x", height=1.0, radius=1.0):
                self.axis = axis
                self.height = height
                self.radius = radius
            
            def convert(self):
                return "\x02"+struct.pack("<ff", self.height, self.radius) +\
                       {"x": "\x00", "y": "\x01", "z": "\x02"}[self.axis]
        
        class Capsule(Shape):
            def __init__(self, axis="x", height=1.0, radius=1.0):
                self.axis = axis
                self.height = height
                self.radius = radius
            
            def convert(self):
                return "\x03"+struct.pack("<ff", self.height, self.radius) +\
                       {"x": "\x00", "y": "\x01", "z": "\x02"}[self.axis]
        
        class Cone(Shape):
            def __init__(self, axis="x", height=1.0, radius=1.0):
                self.axis = axis
                self.height = height
                self.radius = radius
            
            def convert(self):
                return "\x04"+struct.pack("<ff", self.height, self.radius) +\
                       {"x": "\x00", "y": "\x01", "z": "\x02"}[self.axis]
        
        class ConvexHull(Shape):
            def __init__(self):
                self.points = []
            
            def convert(self):
                return "\x05"+struct.pack("<L", len(self.points))+"".join([struct.pack("<fff", *point) for point in self.points])
        
        class StaticTriangleMesh(Shape):
            def __init__(self):
                self.vertices = []
            
            def convert(self):
                return "\x06"+struct.pack("<L", len(self.vertices)/3)+"".join([struct.pack("<fff", *vertex) for vertex in self.vertices])
        
        class Heightfield(Shape):
            def __init__(self):
                self.width = 0
                self.heights = []
            
            def convert(self):
                return "\x07"+struct.pack("<LL", self.width, len(self.heights)/self.width)+"".join([struct.pack("<f", height) for height in self.heights])
        
        class Plane(Shape):
            def __init__(self, distance=0.0, normal=[0.0, 1.0, 0.0]):
                self.distance = distance
                self.normal = [normal[0], normal[1], normal[2]]
            
            def convert(self):
                return "\x08"+struct.pack("<ffff",
                                          self.distance,
                                          self.normal[0],
                                          self.normal[1],
                                          self.normal[2])
        
        class Compound(Shape):
            def __init__(self):
                self.children = []
            
            def convert(self):
                return "\x09"+struct.pack("<L", len(self.children))+"".join([struct.pack("<fffffff", 0, 0, 0, 1, 0, 0, 0)+child.convert() for child in self.children])
        
        class Empty(Shape):
            def load(self, json_data):
                pass
            
            def save(self):
                return {}
            
            def convert(self):
                return "\x0A"
        
        class ResourceShape(Shape):
            def load(self, json_data):
                self.shape = json_data["shape"]
            
            def save(self):
                return {"shape": get_dest_filename(self.shape, PhysicsShape)}
            
            def convert(self):
                shape = get_dest_filename(self.shape, PhysicsShape)
                
                return "\x0B"+struct.pack("<L", len(shape))+shape
        
        def __init__(self, src_filenames, dest_filename):
            Resource.__init__(self, "physicsShape", src_filenames, dest_filename)
            
            self.shape = PhysicsShape.Empty()
        
        def convert(self):
            output = open(self.dest_filename+".temp", "wb")
            
            output.write("shpe\x01\x00")
            
            output.write(self.shape.convert())
            
            output.close()
            
            os.rename(self.dest_filename+".temp", self.dest_filename)
    
    class Scene(Resource):
        class Light:
            class Type:
                Directional = "directional"
                Spot = "spot"
                Point = "point"
            
            class ShadowmapPrecision:
                Low = "low"
                Medium = "medium"
                High = "high"
            
            def __init__(self, type_):
                self.type_ = type_
                self.power = 1.0
                self.color = [1.0, 1.0, 1.0]
                
                if type_ == Scene.Light.Type.Directional:
                    self.direction = [0.0, -1.0, 0.0]
                elif type_ == Scene.Light.Type.Spot:
                    self.position = [0.0, 0.0, 0.0]
                    self.direction = [0.0, -1.0, 0.0]
                    self.inner_cutoff = 18.0
                    self.outer_cutoff = 20.0
                    self.radius = 1.0
                elif type_ == Scene.Light.Type.Point:
                    self.position = [0.0, 0.0, 0.0]
                    self.radius = 1.0
                
                self.ambient_strength = 0.05
                
                self.shadowmap = False
            
            def convert(self):
                s = {Scene.Light.Type.Directional: "\x00",
                     Scene.Light.Type.Spot: "\x01",
                     Scene.Light.Type.Point: "\x02"}[self.type_]
                
                s += struct.pack("<fffff",
                                 self.power,
                                 self.color[0],
                                 self.color[1],
                                 self.color[2],
                                 self.ambient_strength)
                
                if self.type_ == Scene.Light.Type.Directional:
                    s += struct.pack("<fff", 
                                     self.direction[0],
                                     self.direction[1],
                                     self.direction[2])
                elif self.type_ == Scene.Light.Type.Spot:
                    s += struct.pack("<fffffffff", 
                                     self.position[0],
                                     self.position[1],
                                     self.position[2],
                                     self.direction[0],
                                     self.direction[1],
                                     self.direction[2],
                                     self.inner_cutoff,
                                     self.outer_cutoff,
                                     self.radius)
                elif self.type_ == Scene.Light.Type.Point:
                    s += struct.pack("<ffff", 
                                     self.position[0],
                                     self.position[1],
                                     self.position[2],
                                     self.radius)
                
                if self.shadowmap:
                    s += "\x01"
                    
                    s += struct.pack("<fffffH",
                                     self.shadowmap_near,
                                     self.shadowmap_far,
                                     self.shadow_min_bias,
                                     self.shadow_bias_scale,
                                     self.shadow_auto_bias_scale,
                                     self.shadowmap_resolution)
                    
                    s += {Scene.Light.ShadowmapPrecision.Low: "\x00",
                          Scene.Light.ShadowmapPrecision.Medium: "\x01",
                          Scene.Light.ShadowmapPrecision.High: "\x02"}[self.shadowmap_precision]
                else:
                    s += "\x00"
                
                return s
        
        class Transform(object):
            def __init__(self, pos=[0.0, 0.0, 0.0], scale=[1.0, 1.0, 1.0], orientation=[0.0, 0.0, 0.0]):
                self.position = [pos[0], pos[1], pos[2]]
                self.scale = [scale[0], scale[1], scale[2]]
                self.orientation = [orientation[0], orientation[1], orientation[2]]
            
            def convert(self):
                return struct.pack("<fffffffff",
                                   self.position[0],
                                   self.position[1],
                                   self.position[2],
                                   self.scale[0],
                                   self.scale[1],
                                   self.scale[2],
                                   self.orientation[0],
                                   self.orientation[1],
                                   self.orientation[2])
        
        class RigidBody(object):
            class Type(object):
                Static = "static"
                Dynamic = "dynamic"
                Kinematic = "kinematic"
            
            def __init__(self):
                self.type_ = Scene.RigidBody.Type.Static
                self.mass = 1.0
                self.linearDamping = 0.04
                self.angularDamping = 0.1
                self.friction = 0.5
                self.rollingFriction = 0.0
                self.restitution = 0.0
                self.linearSleepingThreshold = 0.8
                self.angularSleepingThreshold = 1.0
                self.collisionMask = 0xFFFF
                self.shape = None
            
            def convert(self):
                s = {Scene.RigidBody.Type.Static: "\x00",
                     Scene.RigidBody.Type.Dynamic: "\x01",
                     Scene.RigidBody.Type.Kinematic: "\x02"}[self.type_]
                
                s += struct.pack("<ffffffffH",
                                 self.mass,
                                 self.linearDamping,
                                 self.angularDamping,
                                 self.friction,
                                 self.rollingFriction,
                                 self.restitution,
                                 self.linearSleepingThreshold,
                                 self.angularSleepingThreshold,
                                 self.collisionMask)
                
                shape = get_dest_filename(self.shape, PhysicsShape)
                
                s += struct.pack("<L", len(shape))
                s += shape
                
                return s
        
        class Entity(object):
            def __init__(self, name=""):
                self.name = name
                self.transform = Scene.Transform()
                self.scripts = []
                self.rigidBody = None
                
                self.model = None
                self.shadow_caster = True
                
                self.overlayTexture = None
                self.overlayColor = [1.0, 1.0, 1.0]
            
            def convert(self):
                s = struct.pack("<L", len(self.name))
                s += self.name
                
                s += self.transform.convert()
                
                s += struct.pack("<???", self.model != None, self.overlayTexture != None, self.rigidBody != None)
                
                if self.model != None:
                    s += struct.pack("<L", len(get_dest_filename(self.model, Model)))
                    s += get_dest_filename(self.model, Model)
                    
                    s += struct.pack("<?", self.shadow_caster)
                elif self.overlayTexture != None:
                    s += struct.pack("<L", len(get_dest_filename(self.overlayTexture, Texture)))
                    s += get_dest_filename(self.overlayTexture, Texture)
                    
                    s += struct.pack("<fff", self.overlayColor[0], self.overlayColor[1], self.overlayColor[2]);
                
                s += self.rigidBody.convert() if self.rigidBody != None else ""
                
                s += struct.pack("<L", len(self.scripts))
                
                for script in self.scripts:
                    s += struct.pack("<L", len(script))
                    s += script
                
                return s
        
        class Camera(object):
            class Type:
                Perspective = "perspective"
                Orthographic = "orthographic"
            
            def __init__(self):
                self.position = [0.0, 0.0, 0.0]
                self.direction = [1.0, 0.0, 0.0]
                self.up = [0.0, 1.0, 0.0]
                self.type_ = Scene.Camera.Type.Perspective
                self.near = 0.1
                self.far = 100.0
                
                self.fov = 50
                self.width = 1.0
                self.height = 1.0
            
            def convert(self):
                s = {Scene.Camera.Type.Perspective: "\x00",
                     Scene.Camera.Type.Orthographic: "\x01"}[self.type_] +\
                    struct.pack("fffffffffff",
                                self.position[0],
                                self.position[1],
                                self.position[2],
                                self.direction[0],
                                self.direction[1],
                                self.direction[2],
                                self.up[0],
                                self.up[1],
                                self.up[2],
                                self.near,
                                self.far)
                
                if self.type_ == Scene.Camera.Type.Perspective:
                    s += struct.pack("fff", self.fov, self.width, self.height)
                elif self.type_ == Scene.Camera.Type.Orthographic:
                    s += struct.pack("ffff", self.left, self.right, self.top, self.bottom)
                
                return s
        
        def __init__(self, src_filenames, dest_filename):
            Resource.__init__(self, "scene", src_filenames, dest_filename)
            
            self.entities = []
            self.camera = Scene.Camera()
            self.skybox = None
            self.lights = []
        
        def convert(self):
            output = open(self.dest_filename+".temp", "wb")
            
            output.write("scen\x01\x00")
            
            output.write(self.camera.convert())
            
            output.write(struct.pack("<L", len(get_dest_filename(self.skybox, Texture, True))))
            output.write(get_dest_filename(self.skybox, Texture, True) if self.skybox != None else "")
            
            output.write(struct.pack("<L", len(self.entities)))
            
            for entity in self.entities:
                output.write(entity.convert())
            
            output.write(struct.pack("<L", len(self.lights)))
            
            for light in self.lights:
                output.write(light.convert())
            
            output.close()
            
            os.rename(self.dest_filename+".temp", self.dest_filename)
    
    conv = {}
    
    conv["texture.png"] = Texture(["source/texture.png"], "resources/textures/texture.bin")
    conv["texture2.png"] = Texture(["source/texture2.png"], "resources/textures/texture2.bin")
    conv["normal.png"] = Texture(["source/normal.png"], "resources/textures/normal.bin")
    conv["normal.png"].purpose = Texture.Purpose.Normal
    conv["floor.png"] = Texture(["source/floor.png"], "resources/textures/floor.bin")
    conv["floor.png"].mag_filter = Texture.Filter.Nearest
    conv["Yokohama3"] = Texture(["source/Yokohama3/posx.jpg",
                                 "source/Yokohama3/negx.jpg",
                                 "source/Yokohama3/posy.jpg",
                                 "source/Yokohama3/negy.jpg",
                                 "source/Yokohama3/posz.jpg",
                                 "source/Yokohama3/negz.jpg"],
                                 "resources/textures/Yokohama3.bin")
    conv["bricks2.jpg"] = Texture(["source/bricks2.jpg"], "resources/textures/bricks2.bin")
    conv["bricks2_disp.jpg"] = Texture(["source/bricks2_disp.jpg"], "resources/textures/bricks2_disp.bin")
    conv["bricks2_normal.jpg"] = Texture(["source/bricks2_normal.jpg"], "resources/textures/bricks2_normal.bin")
    
    conv["debugDraw.vs"] = Shader(["source/shaders/debugDraw.vs"], "../../resources/shaders/debugDrawVertex.bin")
    conv["debugDraw.fs"] = Shader(["source/shaders/debugDraw.fs"], "../../resources/shaders/debugDrawFragment.bin")
    conv["debugDraw.fs"].stage_ = Shader.Stage.Fragment
    
    conv["skyboxVertex.vs"] = Shader(["source/shaders/skyboxVertex.vs"], "../../resources/shaders/skyboxVertex.bin")
    conv["skyboxFragment.fs"] = Shader(["source/shaders/skyboxFragment.fs"], "../../resources/shaders/skyboxFragment.bin")
    conv["skyboxFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["forwardFragment.fs"] = Shader(["source/shaders/forwardFragment.fs"], "../../resources/shaders/forwardFragment.bin")
    conv["forwardFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["objectVertex.vs"] = Shader(["source/shaders/objectVertex.vs"], "../../resources/shaders/objectVertex.bin")
    conv["gbufferFragment.fs"] = Shader(["source/shaders/gbufferFragment.fs"], "../../resources/shaders/gbufferFragment.bin")
    conv["gbufferFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["toSRGBFragment.fs"] = Shader(["source/shaders/toSRGBFragment.fs"], "../../resources/shaders/toSRGBFragment.bin")
    conv["toSRGBFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["vignetteFragment.fs"] = Shader(["source/shaders/vignetteFragment.fs"], "../../resources/shaders/vignetteFragment.bin")
    conv["vignetteFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["fxaaFragment.fs"] = Shader(["source/shaders/fxaaFragment.fs"], "../../resources/shaders/fxaaFragment.bin")
    conv["fxaaFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["lightingDirectional.fs"] = Shader(["source/shaders/lightingDirectional.fs"], "../../resources/shaders/lightingDirectional.bin")
    conv["lightingDirectional.fs"].stage_ = Shader.Stage.Fragment
    
    conv["lightingPoint.fs"] = Shader(["source/shaders/lightingPoint.fs"], "../../resources/shaders/lightingPoint.bin")
    conv["lightingPoint.fs"].stage_ = Shader.Stage.Fragment
    
    conv["lightingSpot.fs"] = Shader(["source/shaders/lightingSpot.fs"], "../../resources/shaders/lightingSpot.bin")
    conv["lightingSpot.fs"].stage_ = Shader.Stage.Fragment
    
    conv["ssaoFragment.fs"] = Shader(["source/shaders/ssaoFragment.fs"], "../../resources/shaders/ssaoFragment.bin")
    conv["ssaoFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["ssaoBlurXFragment.fs"] = Shader(["source/shaders/ssaoBlurXFragment.fs"], "../../resources/shaders/ssaoBlurXFragment.bin")
    conv["ssaoBlurXFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["ssaoBlurYFragment.fs"] = Shader(["source/shaders/ssaoBlurYFragment.fs"], "../../resources/shaders/ssaoBlurYFragment.bin")
    conv["ssaoBlurYFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["bloomBlurXFragment.fs"] = Shader(["source/shaders/bloomBlurXFragment.fs"], "../../resources/shaders/bloomBlurXFragment.bin")
    conv["bloomBlurXFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["bloomBlurYFragment.fs"] = Shader(["source/shaders/bloomBlurYFragment.fs"], "../../resources/shaders/bloomBlurYFragment.bin")
    conv["bloomBlurYFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["lumCalcFragment.fs"] = Shader(["source/shaders/lumCalcFragment.fs"], "../../resources/shaders/lumCalcFragment.bin")
    conv["lumCalcFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["tonemapFragment.fs"] = Shader(["source/shaders/tonemapFragment.fs"], "../../resources/shaders/tonemapFragment.bin")
    conv["tonemapFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["postEffectVertex.vs"] = Shader(["source/shaders/postEffectVertex.vs"], "../../resources/shaders/postEffectVertex.bin")
    
    conv["shadowmapVertex.vs"] = Shader(["source/shaders/shadowmapVertex.vs"], "../../resources/shaders/shadowmapVertex.bin")
    
    conv["pointShadowmapGeometry.gs"] = Shader(["source/shaders/pointShadowmapGeometry.gs"], "../../resources/shaders/pointShadowmapGeometry.bin")
    conv["pointShadowmapGeometry.gs"].stage_ = Shader.Stage.Geometry
    
    conv["shadowmapFragment.fs"] = Shader(["source/shaders/shadowmapFragment.fs"], "../../resources/shaders/shadowmapFragment.bin")
    conv["shadowmapFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["pointShadowmapFragment.fs"] = Shader(["source/shaders/pointShadowmapFragment.fs"], "../../resources/shaders/pointShadowmapFragment.bin")
    conv["pointShadowmapFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["fontFragment.fs"] = Shader(["source/shaders/fontFragment.fs"], "../../resources/shaders/fontFragment.bin")
    conv["fontFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["fontGeometry.gs"] = Shader(["source/shaders/fontGeometry.gs"], "../../resources/shaders/fontGeometry.bin")
    conv["fontGeometry.gs"].stage_ = Shader.Stage.Geometry
    
    conv["fontVertex.vs"] = Shader(["source/shaders/fontVertex.vs"], "../../resources/shaders/fontVertex.bin")
    
    conv["overlayVertex.vs"] = Shader(["source/shaders/overlayVertex.vs"], "../../resources/shaders/overlayVertex.bin")
    
    conv["overlayFragment.fs"] = Shader(["source/shaders/overlayFragment.fs"], "../../resources/shaders/overlayFragment.bin")
    conv["overlayFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["cube.obj"] = Mesh(["source/cube.obj"], "../../resources/meshes/cube.bin")
    conv["material test.obj"] = Mesh(["source/material test.obj"], "resources/meshes/material test.bin")
    conv["material test 2.obj"] = Mesh(["source/material test 2.obj"], "resources/meshes/material test 2.bin")
    conv["sphere.obj"] = Mesh(["source/sphere.obj"], "resources/meshes/sphere.bin")
    conv["teapot.obj"] = Mesh(["source/teapot.obj"], "resources/meshes/teapot.bin")
    conv["floor.obj"] = Mesh(["source/floor.obj"], "resources/meshes/floor.bin")
    conv["fence.obj"] = Mesh(["source/fence.obj"], "resources/meshes/fence.bin")
    conv["aotest.obj"] = Mesh(["source/ao test.obj"], "resources/meshes/aotest.bin")
    
    mat = Material([], "resources/materials/material.bin")
    mat.forward = False
    mat.smoothness = 0.6
    mat.metalMask = 0.0
    mat.albedoMap = conv["texture2.png"]
    mat.normalMap = conv["normal.png"]
    conv["material"] = mat
    
    mat = Material([], "resources/materials/clay.bin")
    mat.forward = False
    mat.smoothness = 0.6
    mat.metalMask = 0.0
    mat.albedo = [1.0, 0.403921569, 0.0, 1.0]
    conv["clay"] = mat
    
    mat = Material([], "resources/materials/gold.bin")
    mat.forward = False
    mat.smoothness = 0.5
    mat.metalMask = 1.0
    mat.albedo = [1.0, 0.403921569, 0.0, 1.0]
    conv["gold"] = mat
    
    mat = Material([], "resources/materials/plastic.bin")
    mat.forward = False
    mat.smoothness = 0.875
    mat.metalMask = 0.0
    mat.albedo = [1.0, 0.403921569, 0.0, 1.0]
    conv["plastic"] = mat
    
    mat = Material([], "resources/materials/floor.bin")
    mat.forward = False
    mat.smoothness = 0.6
    mat.metalMask = 0.0
    mat.albedoMap = conv["floor.png"]
    conv["floor"] = mat
    
    mat = Material([], "resources/materials/fence.bin")
    mat.forward = False
    mat.smoothness = 0.65
    mat.metalMask = 1.0
    conv["fence"] = mat

    mat = Material([], "resources/materials/ao test material.bin")
    mat.forward = False
    mat.smoothness = 0.6
    mat.metalMask = 0.0
    mat.albedo = [1.0, 0.403921569, 0.0, 1.0]
    conv["ao test material"] = mat
    
    mat = Material([], "resources/materials/parallax test material.bin")
    mat.forward = False
    mat.smoothness = 0.875
    mat.metalMask = 0.0
    mat.albedoMap = conv["bricks2.jpg"]
    mat.pomHeightMap = conv["bricks2_disp.jpg"]
    mat.normalMap = conv["bricks2_normal.jpg"]
    mat.parallaxStrength = 0.1
    mat.pomMinLayers = 30
    mat.pomMaxLayers = 70
    conv["parallax test material"] = mat
    
    model = Model([], "resources/models/model.bin")
    model.sub_models = [[Model.LOD(conv["cube.obj"], conv["material"], 0.0, 9999.0)]]
    conv["model"] = model
    
    model = Model([], "resources/models/clay.bin")
    model.sub_models = [[Model.LOD(conv["material test 2.obj"], conv["clay"], 0.0, 9999.0)]]
    conv["clay model"] = model
    
    model = Model([], "resources/models/gold.bin")
    model.sub_models = [[Model.LOD(conv["material test 2.obj"], conv["gold"], 0.0, 9999.0)]]
    conv["gold model"] = model
    
    model = Model([], "resources/models/plastic.bin")
    model.sub_models = [[Model.LOD(conv["material test 2.obj"], conv["plastic"], 0.0, 9999.0)]]
    conv["plastic model"] = model
    
    model = Model([], "resources/models/floor.bin")
    model.sub_models = [[Model.LOD(conv["floor.obj"], conv["floor"], 0.0, 9999.0)]]
    conv["floor model"] = model
    
    model = Model([], "resources/models/fence.bin")
    model.sub_models = [[Model.LOD(conv["fence.obj"], conv["fence"], 0.0, 9999.0)]]
    conv["fence model"] = model
    
    model = Model([], "resources/models/aotest.bin")
    model.sub_models = [[Model.LOD(conv["aotest.obj"], conv["ao test material"], 0.0, 9999.0)]]
    conv["ao test model"] = model
    
    model = Model([], "resources/models/parallaxTest.bin")
    model.sub_models = [[Model.LOD(conv["floor.obj"], conv["parallax test material"], 0.0, 9999.0)]]
    conv["parallax test model"] = model
    
    floorShape = PhysicsShape([], "resources/shapes/floor.bin")
    floorShape.shape = PhysicsShape.Box([8.0, 1.0, 8.0])
    conv["floor shape"] = floorShape
    
    boxShape = PhysicsShape([], "resources/shapes/box.bin")
    boxShape.shape = PhysicsShape.Cylinder("y", 4.0, 1.0)
    conv["box shape"] = boxShape
    
    someShape = PhysicsShape([], "resources/shapes/someShape.bin")
    someShape.shape = PhysicsShape.Box([3.01, 3.0, 3.01])
    conv["some shape"] = someShape
    
    fenceShape = PhysicsShape([], "resources/shapes/fence.bin")
    fenceShape.shape = PhysicsShape.Box([0.1, 0.55, 8.0])
    conv["fence shape"] = fenceShape
    
    scene = Scene([], "resources/scenes/scene.bin")
    conv["scene"] = scene
    scene.skybox = conv["Yokohama3"]
    scene.camera.position = [-4.0, 4.0, 4.0]
    scene.camera.direction = [4.0, -2.0, -4.0]
    scene.camera.up = [0.0, 1.0, 0.0]
    
    cubeEnt = Scene.Entity("Cube")
    cubeEnt.transform.position = [0.0, 2.0, 0.0]
    cubeEnt.transform.scale = [1.0, 1.0, 1.0]
    cubeEnt.transform.orientation = [0.0, 0.0, 0.0]
    cubeEnt.rigidBody = Scene.RigidBody()
    cubeEnt.rigidBody.type_ = Scene.RigidBody.Type.Dynamic
    cubeEnt.rigidBody.shape = boxShape
    cubeEnt.rigidBody.linearSleepingThreshold = 0.0
    cubeEnt.rigidBody.angularSleepingThreshold = 0.0
    cubeEnt.rigidBody.linearDamping = 0.8
    cubeEnt.scripts.append("resources/scripts/entityscript.cpp")
    scene.entities.append(cubeEnt)
    
    clayEnt = Scene.Entity("Clay")
    clayEnt.transform.position = [11.0, 3.0, -6.0]
    clayEnt.model = conv["clay model"]
    clayEnt.rigidBody = Scene.RigidBody()
    clayEnt.rigidBody.shape = someShape
    scene.entities.append(clayEnt)
    
    plasticEnt = Scene.Entity("Plastic")
    plasticEnt.transform.position = [11.0, 3.0, 0.0]
    plasticEnt.model = conv["plastic model"]
    plasticEnt.rigidBody = Scene.RigidBody()
    plasticEnt.rigidBody.shape = someShape
    scene.entities.append(plasticEnt)
    
    goldEnt = Scene.Entity("Gold")
    goldEnt.transform.position = [11.0, 3.0, 6.0]
    goldEnt.model = conv["gold model"]
    goldEnt.rigidBody = Scene.RigidBody()
    goldEnt.rigidBody.shape = someShape
    scene.entities.append(goldEnt)
    
    floorEnt = Scene.Entity("Floor")
    floorEnt.transform.position = [0.0, -1.0, 0.0]
    floorEnt.model = conv["floor model"]
    floorEnt.rigidBody = Scene.RigidBody()
    floorEnt.rigidBody.shape = floorShape
    scene.entities.append(floorEnt)
    
    fenceEnt = Scene.Entity("Fence1")
    fenceEnt.transform.position = [-8.0, 1.55, 0.0]
    fenceEnt.model = conv["fence model"]
    fenceEnt.rigidBody = Scene.RigidBody()
    fenceEnt.rigidBody.shape = fenceShape
    scene.entities.append(fenceEnt)
    
    fenceEnt = Scene.Entity("Fence3")
    fenceEnt.transform.position = [0.0, 1.55, 8.0]
    fenceEnt.transform.orientation = [0.0, 90.0, 0.0]
    fenceEnt.model = conv["fence model"]
    fenceEnt.rigidBody = Scene.RigidBody()
    fenceEnt.rigidBody.shape = fenceShape
    scene.entities.append(fenceEnt)
    
    fenceEnt = Scene.Entity("Fence4")
    fenceEnt.transform.position = [0.0, 1.55, -8.0]
    fenceEnt.transform.orientation = [0.0, -90.0, 0.0]
    fenceEnt.model = conv["fence model"]
    fenceEnt.rigidBody = Scene.RigidBody()
    fenceEnt.rigidBody.shape = fenceShape
    scene.entities.append(fenceEnt)
    
    ent = Scene.Entity("AO test")
    ent.transform.position = [-5.0, 0.0, 0.0]
    ent.transform.orientation = [0.0, 100.0, 0.0]
    ent.model = conv["ao test model"]
    scene.entities.append(ent)
    
    ent = Scene.Entity("Parallax test test")
    ent.transform.position = [0.0, 1.0, 0.0]
    ent.transform.scale = [0.1, 1.0, 0.1]
    ent.transform.orientation = [0.0, 45.0, 0.0]
    ent.model = conv["parallax test model"]
    scene.entities.append(ent)
    
    """light = Scene.Light(Scene.Light.Type.Point)
    light.position = [8.0, 2.5, 10.0]
    light.radius = 0.33
    light.color = [1.0, 0.0, 0.0]
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [10.0, 2.5, 10.0]
    light.radius = 0.33
    light.color = [0.0, 1.0, 0.0]
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [9.0, 2.5, 9.0]
    light.radius = 0.33
    light.color = [0.0, 0.0, 1.0]
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [9.0, 2.5, 11.0]
    light.radius = 0.33
    light.color = [1.0, 1.0, 0.0]
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [8.0, 2.5, 17.0]
    light.radius = 0.33
    light.color = [1.0, 0.0, 0.0]
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [10.0, 2.5, 17.0]
    light.radius = 0.33
    light.color = [0.0, 1.0, 0.0]
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [9.0, 2.5, 16.0]
    light.radius = 0.33
    light.color = [0.0, 0.0, 1.0]
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [9.0, 2.5, 18.0]
    light.radius = 0.33
    light.color = [1.0, 1.0, 0.0]
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [8.0, 2.5, 24.0]
    light.radius = 0.33
    light.color = [1.0, 0.0, 0.0]
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [10.0, 2.5, 24.0]
    light.radius = 0.33
    light.color = [0.0, 1.0, 0.0]
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [9.0, 2.5, 23.0]
    light.radius = 0.33
    light.color = [0.0, 0.0, 1.0]
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [9.0, 2.5, 25.0]
    light.radius = 0.33
    light.color = [1.0, 1.0, 0.0]
    scene.lights.append(light)"""
    
    light = Scene.Light(Scene.Light.Type.Directional)
    light.direction = [0.4, -1.0, 0.0]
    light.color = [1.0, 1.0, 0.8]
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadowmap_far = 100.0
    light.shadow_min_bias = 0.01
    light.shadow_bias_scale = 0.1
    light.shadow_auto_bias_scale = 1.0
    light.shadowmap_resolution = 2048
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    scene.lights.append(light)
    
    """light = Scene.Light(Scene.Light.Type.Point)
    light.position = [0.0, 1.0, 0.0]
    light.radius = 10.0
    light.color = [1.0, 1.0, 1.0]
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadowmap_far = 100.0
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 0.65
    light.shadowmap_resolution = 1024
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    scene.lights.append(light)"""
    
    """light = Scene.Light(Scene.Light.Type.Spot)
    light.position = [8.0, 2.5, 0.0]
    light.direction = [1.0, -0.75, 0.0]
    light.color = [1.0, 1.0, 1.0]
    light.power = 5.0
    light.inner_cutoff = 28.0
    light.outer_cutoff = 30.0
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadowmap_far = 100.0
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 1.0
    light.shadowmap_resolution = 512
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Spot)
    light.position = [8.0, 2.5, -6.0]
    light.direction = [1.0, -0.75, 0.0]
    light.color = [1.0, 1.0, 1.0]
    light.power = 5.0
    light.inner_cutoff = 28.0
    light.outer_cutoff = 30.0
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadowmap_far = 100.0
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 1.0
    light.shadowmap_resolution = 512
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    scene.lights.append(light)
    
    conv["scene"] = scene
    light = Scene.Light(Scene.Light.Type.Spot)
    light.position = [8.0, 2.5, 6.0]
    light.direction = [1.0, -0.75, 0.0]
    light.color = [1.0, 1.0, 1.0]
    light.power = 5.0
    light.inner_cutoff = 28.0
    light.outer_cutoff = 30.0
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadowmap_far = 100.0
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 1.0
    light.shadowmap_resolution = 512
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    scene.lights.append(light)"""
    
    for res in conv.values():
        res.convert()

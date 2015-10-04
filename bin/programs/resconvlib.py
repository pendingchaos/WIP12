#!/usr/bin/env python
# -*- coding: utf-8 -*-
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

#It seems resources/textures folder is not on Github.
try:
    os.makedirs("../main/resources/textures")
except OSError:
    pass

try:
    os.makedirs("../main2/resources/textures")
except OSError:
    pass

def get_dest_filename(obj, type_, allowNone=False):
    if obj == None and allowNone:
        return None
    
    return obj.dest_filename if isinstance(obj, type_) else str(obj)

try:
    meshConverter = ctypes.CDLL("../main/libMeshConverter.so")
except:
    print "Warning: libMeshConverter.so can not be loaded. Meshes will not be converted."
    
    meshConverter = None

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
        
        self.max_anisotropy = 4.0
        self.min_filter = Texture.Filter.Bilinear
        self.mag_filter = Texture.Filter.Bilinear
        self.mipmap_mode = Texture.MipmapMode.Linear
        self.wrap_mode = Texture.WrapMode.Repeat
        self.srgb = True
    
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
        
        srgb = self.srgb
        
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
        out.write(struct.pack("<?BfBBBBLLLL",
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
                
                result += "#line 1\n%s\n#line %d\n" % (included,
                                                       linenum+1)
                
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
        
        self.animated = False
    
    def convert(self):
        if meshConverter != None:
            src = self.src_filenames[0].encode("ascii")
            dest = (self.dest_filename+".temp").encode("ascii")
            
            meshConverter.convert(src, dest, self.animated)
            
            os.rename(self.dest_filename+".temp", self.dest_filename)

class Material(Resource):
    def __init__(self, src_filenames, dest_filename):
        Resource.__init__(self, "material", src_filenames, dest_filename)
        
        self.forward = True
        self.albedo = [1.0, 1.0, 1.0, 1.0]
        self.smoothness = 0.6
        self.metalMask = 0.0
        self.albedoMap = None
        self.materialMap = None
        self.normalMap = None
        
        self.parallaxStrength = 0.0
        self.parallaxEdgeDiscard = True
        
        self.parallaxHeightMap = None
        
        self.pomHeightMap = None
        self.pomMinLayers = 8
        self.pomMaxLayers = 32
        
        self.displacementMap = None
        self.minTessLevel = 1.0
        self.maxTessLevel = 10.0
        self.tessMinDistance = 0.0
        self.tessMaxDistance = 10.0
        self.displacementStrength = 0.1
        self.displacementMidlevel = 0.5
        self.shadowTesselation = False
        self.shadowMinTessLevel = 1.0
        self.shadowMaxTessLevel = 5.0
    
    def convert(self):
        output = open(self.dest_filename+".temp", "wb")
        
        output.write("mtrl\x01\x00")
        
        s = struct.pack("<bfffffffbbbffffffbff",
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
                        self.pomMaxLayers,
                        self.minTessLevel,
                        self.maxTessLevel,
                        self.tessMinDistance,
                        self.tessMaxDistance,
                        self.displacementStrength,
                        self.displacementMidlevel,
                        self.shadowTesselation,
                        self.shadowMinTessLevel,
                        self.shadowMaxTessLevel)
        
        if self.albedoMap != None:
            s += struct.pack("<L", len(get_dest_filename(self.albedoMap, Texture)))
            s += get_dest_filename(self.albedoMap, Texture)
        else:
            s += struct.pack("<L", 0)
        
        if self.materialMap != None:
            s += struct.pack("<L", len(get_dest_filename(self.materialMap, Texture)))
            s += get_dest_filename(self.materialMap, Texture)
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
        
        if self.displacementMap != None:
            s += struct.pack("<L", len(get_dest_filename(self.displacementMap, Texture)))
            s += get_dest_filename(self.displacementMap, Texture)
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
            return "\x09"+struct.pack("<L", len(self.children))+"".join([struct.pack("<fffffff", *child[1:8])+child[0].convert() for child in self.children])
    
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
            self.shadow_radius = 4.0
            self.shadow_fixed_bias = 0.0
            
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
                
                s += struct.pack("<ffffffH",
                                 self.shadowmap_near,
                                 self.shadow_min_bias,
                                 self.shadow_bias_scale,
                                 self.shadow_auto_bias_scale,
                                 self.shadow_fixed_bias,
                                 self.shadow_radius,
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
            self.animation = None
            
            self.overlayTexture = None
            self.overlayColor = [1.0, 1.0, 1.0]
            
            self.entities = []
        
        def convert(self):
            s = struct.pack("<L", len(self.name))
            s += self.name
            
            s += self.transform.convert()
            
            s += struct.pack("<???", self.model != None, self.overlayTexture != None, self.rigidBody != None)
            
            if self.model != None:
                s += struct.pack("<L", len(get_dest_filename(self.model, Model)))
                s += get_dest_filename(self.model, Model)
                
                s += struct.pack("<?", self.shadow_caster)
                
                s += struct.pack("<?", self.animation != None)
                
                if self.animation != None:
                    s += struct.pack("<L", len(self.animation))
                    s += self.animation
            elif self.overlayTexture != None:
                s += struct.pack("<L", len(get_dest_filename(self.overlayTexture, Texture)))
                s += get_dest_filename(self.overlayTexture, Texture)
                
                s += struct.pack("<fff", self.overlayColor[0], self.overlayColor[1], self.overlayColor[2]);
            
            s += self.rigidBody.convert() if self.rigidBody != None else ""
            
            s += struct.pack("<L", len(self.scripts))
            
            for script in self.scripts:
                s += struct.pack("<L", len(script))
                s += script
            
            s += struct.pack("<L", len(self.entities))
            
            for child in self.entities:
                s += child.convert();
            
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
    
    class ColorModifier(object):
        class Type:
            ReinhardTonemap = "reinhard tonemap"
            Vignette = "vignette"
            HueShift = "hue shift"
            SaturationShift = "saturation shift"
            BrightnessShift = "brightness shift"
            Contrast = "contrast"
            Multiply = "multiply"
            HueReplace = "hue replace"
            SaturationReplace = "saturation replace"
            BrightnessReplace = "brightness replace"
        
        def __init__(self):
            self.type_ = Scene.ColorModifier.Type.Contrast
            self.contrast = 1.0
        
        def convert(self):
            s = struct.pack("<B", {Scene.ColorModifier.Type.ReinhardTonemap: 0,
                                   Scene.ColorModifier.Type.Vignette: 1,
                                   Scene.ColorModifier.Type.HueShift: 2,
                                   Scene.ColorModifier.Type.SaturationShift: 3,
                                   Scene.ColorModifier.Type.BrightnessShift: 4,
                                   Scene.ColorModifier.Type.Contrast: 5,
                                   Scene.ColorModifier.Type.Multiply: 6,
                                   Scene.ColorModifier.Type.HueReplace: 7,
                                   Scene.ColorModifier.Type.SaturationReplace: 8,
                                   Scene.ColorModifier.Type.BrightnessReplace: 9}[self.type_])
            
            if self.type_ == Scene.ColorModifier.Type.ReinhardTonemap:
                s += struct.pack("<B", self.brightnessOnly)
            elif self.type_ == Scene.ColorModifier.Type.Vignette:
                s += struct.pack("<fff", self.radius, self.softness, self.intensity)
            elif self.type_ == Scene.ColorModifier.Type.HueShift:
                s += struct.pack("<f", self.hue)
            elif self.type_ == Scene.ColorModifier.Type.SaturationShift:
                s += struct.pack("<f", self.saturation)
            elif self.type_ == Scene.ColorModifier.Type.BrightnessShift:
                s += struct.pack("<f", self.brightness)
            elif self.type_ == Scene.ColorModifier.Type.Contrast:
                s += struct.pack("<f", self.contrast)
            elif self.type_ == Scene.ColorModifier.Type.Multiply:
                s += struct.pack("<fff", self.color[0], self.color[1], self.color[2])
            elif self.type_ == Scene.ColorModifier.Type.HueReplace:
                s += struct.pack("<f", self.hue)
            elif self.type_ == Scene.ColorModifier.Type.SaturationReplace:
                s += struct.pack("<f", self.saturation)
            elif self.type_ == Scene.ColorModifier.Type.BrightnessReplace:
                s += struct.pack("<f", self.brightness)
            
            return s
    
    def __init__(self, src_filenames, dest_filename):
        Resource.__init__(self, "scene", src_filenames, dest_filename)
        
        self.entities = []
        self.camera = Scene.Camera()
        self.skybox = None
        self.lights = []
        self.bloomThreshold = 1.0
        self.bloom1Radius = 0.1
        self.bloom2Radius = 0.05
        self.bloom3Radius = 0.025
        self.bloom4Radius = 0.0125
        self.bloom1Strength = 1.0
        self.bloom2Strength = 1.0
        self.bloom3Strength = 1.0
        self.bloom4Strength = 1.0
        self.bloomEnabled = True
        self.ssaoRadius = 0.25
        self.colorModifiers = []
        self.scripts = []
    
    def convert(self):
        output = open(self.dest_filename+".temp", "wb")
        
        output.write("scen\x01\x00")
        
        output.write(self.camera.convert())
        
        output.write(struct.pack("<L", len(get_dest_filename(self.skybox, Texture, True))))
        output.write(get_dest_filename(self.skybox, Texture, True) if self.skybox != None else "")
        
        output.write(struct.pack("<ffffffffffBL",
                                 self.bloomThreshold,
                                 self.bloom1Radius,
                                 self.bloom2Radius,
                                 self.bloom3Radius,
                                 self.bloom4Radius,
                                 self.bloom1Strength,
                                 self.bloom2Strength,
                                 self.bloom3Strength,
                                 self.bloom4Strength,
                                 self.ssaoRadius,
                                 self.bloomEnabled,
                                 len(self.colorModifiers)))

        for modifier in self.colorModifiers:
            output.write(modifier.convert())
        
        output.write(struct.pack("<L", len(self.entities)))
        
        for entity in self.entities:
            output.write(entity.convert())
        
        output.write(struct.pack("<L", len(self.lights)))
        
        for light in self.lights:
            output.write(light.convert())
        
        s = ""
        
        s += struct.pack("<L", len(self.scripts))
        
        for script in self.scripts:
            s += struct.pack("<L", len(script))
            s += script
        
        output.write(s)
        
        output.close()
        
        os.rename(self.dest_filename+".temp", self.dest_filename)

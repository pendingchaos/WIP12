import sys
import random
sys.path.append("../")
from resconvlib import *

worldSize = 10
numDecors = 1000

if __name__ == "__main__":
    conv = {}
    
    # Textures
    conv["skybox"] = Texture(["source/skybox/posx.png",
                              "source/skybox/negx.png",
                              "source/skybox/posy.png",
                              "source/skybox/negy.png",
                              "source/skybox/posz.png",
                              "source/skybox/negz.png"],
                              "resources/textures/skybox.bin")
    
    # Meshes
    conv["sphere.obj"] = Mesh(["source/sphere.obj"], "resources/meshes/sphere.bin")
    conv["floor.obj"] = Mesh(["source/floor.obj"], "resources/meshes/floor.bin")
    conv["decor.obj"] = Mesh(["source/decor.obj"], "resources/meshes/decor.bin")
    
    # Materials
    mat = Material([], "resources/materials/player.bin")
    mat.forward = False
    mat.smoothness = 0.6
    mat.metalMask = 0.0
    mat.albedo = [1.0, 0.403921569, 0.0, 1.0]
    conv["player"] = mat
    
    mat = Material([], "resources/materials/floor.bin")
    mat.forward = False
    mat.smoothness = 0.875
    mat.metalMask = 0.0
    mat.albedo = [1.0, 1.0, 1.0, 1.0]
    conv["floor"] = mat
    
    mat = Material([], "resources/materials/decor.bin")
    mat.forward = False
    mat.smoothness = 0.9
    mat.metalMask = 0.0
    mat.albedo = [1.0, 0.1, 0.0, 1.0]
    conv["decor"] = mat
    
    # Models
    model = Model([], "resources/models/player.bin")
    model.sub_models = [[Model.LOD(conv["sphere.obj"], conv["player"], 0.0, 9999.0)]]
    conv["player model"] = model
    
    model = Model([], "resources/models/floor.bin")
    model.sub_models = [[Model.LOD(conv["floor.obj"], conv["floor"], 0.0, 9999.0)]]
    conv["floor model"] = model
    
    model = Model([], "resources/models/decor.bin")
    model.sub_models = [[Model.LOD(conv["decor.obj"], conv["decor"], 0.0, 9999.0)]]
    conv["decor model"] = model
    
    # Shapes
    floorShape = PhysicsShape([], "resources/shapes/floor.bin")
    floorShape.shape = PhysicsShape.Box([8.0, 1.0, 8.0])
    conv["floor shape"] = floorShape
    
    playerShape = PhysicsShape([], "resources/shapes/player.bin")
    playerShape.shape = PhysicsShape.Sphere(1.0)
    conv["player shape"] = playerShape
    
    decorShape = PhysicsShape([], "resources/shapes/decor.bin")
    decorShape.shape = PhysicsShape.Cylinder("y", 11.6, 2.0)
    """decorShape.shape.children.append((PhysicsShape.Box([0.983, 1.024, 1.973]), 0, 0, 0, 1, 0, 0.9529, 0.3591))
    decorShape.shape.children.append((PhysicsShape.Box([0.331, 1.0, 1.994]), 0, 0, 0, 1, -1.38, 0.9529, -0.674))
    decorShape.shape.children.append((PhysicsShape.Box([0.377, 1.0, 0.944]), 0, 0, 0, 1, 1.31, 0.9529, -0.674))
    decorShape.shape.children.append((PhysicsShape.Box([0.711, 0.532, 1.723]), 0, 0, 0, 1, 0.0, 2.508, 0.35910))
    decorShape.shape.children.append((PhysicsShape.Box([0.657, 1.012, 0.736]), 0, 0, 0, 1, -0.8684, 2.98209, -0.7068))
    decorShape.shape.children.append((PhysicsShape.Box([0.684, 2.021, 0.736]), 0, 0, 0, 1, 0.684, 2.021, 0.736))"""
    conv["decor shape"] = decorShape
    
    # Scene
    scene = Scene([], "resources/scenes/main.bin")
    conv["scene"] = scene
    scene.skybox = conv["skybox"]
    scene.camera.position = [32.5, 20.0, 32.5]
    scene.camera.direction = [-1.0, -1.0, -1.0]
    scene.camera.up = [0.0, 1.0, 0.0]
    scene.camera.far = 5.0
    scene.camera.far = 100.0
    
    modifier = Scene.ColorModifier()
    modifier.type_ = Scene.ColorModifier.Type.ReinhardTonemap
    modifier.brightnessOnly = True
    scene.colorModifiers.append(modifier)
    
    # Floor
    for x in range(-worldSize, worldSize+1):
        for z in range(-worldSize, worldSize+1):
            floorEnt = Scene.Entity("Floor%d_%d" % (x, z))
            floorEnt.transform.position = [x*8.0, -1.0, z*8.0]
            floorEnt.model = conv["floor model"]
            floorEnt.rigidBody = Scene.RigidBody()
            floorEnt.rigidBody.shape = floorShape
            scene.entities.append(floorEnt)
    
    # Player
    cubeEnt = Scene.Entity("Player")
    cubeEnt.transform.position = [0.0, 2.0, 0.0]
    cubeEnt.transform.scale = [1.0, 1.0, 1.0]
    cubeEnt.transform.orientation = [0.0, 0.0, 0.0]
    cubeEnt.rigidBody = Scene.RigidBody()
    cubeEnt.rigidBody.type_ = Scene.RigidBody.Type.Dynamic
    cubeEnt.rigidBody.shape = playerShape
    cubeEnt.rigidBody.linearSleepingThreshold = 0.0
    cubeEnt.rigidBody.angularSleepingThreshold = 0.0
    cubeEnt.rigidBody.linearDamping = 0.8
    cubeEnt.rigidBody.mass = 100.0
    cubeEnt.scripts.append(("resources/scripts/player.rkt", "Player"))
    cubeEnt.model = conv["player model"]
    scene.entities.append(cubeEnt)
    
    # Decor
    for i in range(numDecors):
        x = 0.0
        z = 0.0
        
        while abs(x) < 3.0 and abs(z) < 3.0:
            x = random.randint(-worldSize*800, worldSize*800) / 100.0
            z = random.randint(-worldSize*800, worldSize*800) / 100.0
        
        decorent = Scene.Entity("Decor%d" % (i))
        decorent.transform.position = [x, 0.0, z]
        decorent.transform.orientation = [0.0, random.randint(0, 36000)/100.0, 0.0]
        decorent.model = conv["decor model"]
        decorent.rigidBody = Scene.RigidBody()
        decorent.rigidBody.shape = decorShape
        scene.entities.append(decorent)
    
    # Sun
    light = Scene.Light(Scene.Light.Type.Directional)
    light.direction = [1.0, -1.0, -1.0]
    light.color = [1.0, 1.0, 0.8]
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadowmap_far = 100.0
    light.shadow_min_bias = 0.0
    light.shadow_bias_scale = 0.0
    light.shadow_auto_bias_scale = 0.9
    light.shadowmap_resolution = 2048
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    light.shadow_radius = 32
    scene.lights.append(light)
    
    for res in conv.values():
        if len(res.src_filenames) == 1:
            print res.src_filenames[0], "->", res.dest_filename
        else:
            print res.src_filenames, "->", res.dest_filename
        
        res.convert()

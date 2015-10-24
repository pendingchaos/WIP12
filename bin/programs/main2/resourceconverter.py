#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import random
sys.path.append("../")
from resconvlib import *

worldSize = 4
numDecors = 25
numCoins = 50
numMonkeys = 10

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
    conv["coin.obj"] = Mesh(["source/coin.obj"], "resources/meshes/coin.bin")
    conv["monkey_lod0.obj"] = Mesh(["source/monkey_lod0.obj"], "resources/meshes/monkey_lod0.bin")
    conv["monkey_lod1.obj"] = Mesh(["source/monkey_lod1.obj"], "resources/meshes/monkey_lod1.bin")
    
    # Materials
    mat = Material([], "resources/materials/player.bin")
    mat.smoothness = 0.6
    mat.metalMask = 0.0
    mat.albedo = [1.0, 0.403921569, 0.0, 1.0]
    conv["player"] = mat
    
    mat = Material([], "resources/materials/floor.bin")
    mat.smoothness = 0.875
    mat.metalMask = 0.0
    mat.albedo = [1.0, 1.0, 1.0, 1.0]
    conv["floor"] = mat
    
    mat = Material([], "resources/materials/decor.bin")
    mat.smoothness = 0.9
    mat.metalMask = 0.0
    mat.albedo = [1.0, 0.1, 0.0, 1.0]
    conv["decor"] = mat
    
    mat = Material([], "resources/materials/monkey.bin")
    mat.smoothness = 0.3
    mat.metalMask = 1.0
    mat.albedo = [1.0, 1.0, 1.0, 1.0]
    conv["monkey"] = mat
    
    colors = [[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 1.0], [1.0, 1.0, 0.0], [0.0, 1.0, 1.0], [1.0, 1.0, 1.0]]
    
    i = 0
    for color in colors:
        mat = Material([], "resources/materials/coin%d.bin" % (i))
        mat.smoothness = random.randint(0, 100)/100.0 * 0.1 + 0.55
        mat.metalMask = 1.0
        mat.albedo = color+[1.0]
        conv["coin%d" % (i)] = mat
        i += 1
    
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
    
    model = Model([], "resources/models/monkey.bin")
    model.sub_models = [[Model.LOD(conv["monkey_lod0.obj"], conv["monkey"], 0.0, 20.0),
                         Model.LOD(conv["monkey_lod1.obj"], conv["monkey"], 20.0, 9999.0)]]
    conv["monkey model"] = model
    
    for i in range(len(colors)):
        model = Model([], "resources/models/coin%d.bin" % (i))
        model.sub_models = [[Model.LOD(conv["coin.obj"], conv["coin%d" % (i)], 0.0, 9999.0)]]
        conv["coin model %d" % (i)] = model
    
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
    
    coinShape = PhysicsShape([], "resources/shapes/coin.bin")
    coinShape.shape = PhysicsShape.Cylinder("y", 0.2, 1.0)
    conv["coin shape"] = coinShape
    
    monkeyShape = PhysicsShape([], "resources/shapes/monkey.bin")
    monkeyShape.shape = PhysicsShape.Cylinder("y", 4.0, 2.0)
    conv["monkey shape"] = monkeyShape
    
    # Scene
    scene = Scene([], "resources/scenes/main.bin")
    conv["scene"] = scene
    scene.skybox = conv["skybox"]
    scene.camera.position = [32.5, 20.0, 32.5]
    scene.camera.direction = [-1.0, -1.0, -1.0]
    scene.camera.up = [0.0, 1.0, 0.0]
    scene.camera.far = 5.0
    scene.camera.far = 100.0
    
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
    playerEnt = Scene.Entity("Player")
    playerEnt.transform.position = [0.0, 2.0, 0.0]
    playerEnt.transform.scale = [1.0, 1.0, 1.0]
    playerEnt.transform.orientation = [0.0, 0.0, 0.0]
    playerEnt.rigidBody = Scene.RigidBody()
    playerEnt.rigidBody.type_ = Scene.RigidBody.Type.Dynamic
    playerEnt.rigidBody.shape = playerShape
    playerEnt.rigidBody.linearSleepingThreshold = 0.0
    playerEnt.rigidBody.angularSleepingThreshold = 0.0
    playerEnt.rigidBody.linearDamping = 0.8
    playerEnt.rigidBody.mass = 100.0
    playerEnt.scripts.append("resources/scripts/player.rkt")
    playerEnt.model = conv["player model"]
    scene.entities.append(playerEnt)
    
    # Coins
    for i in range(numCoins):
        x = 0.0
        z = 0.0
        
        while abs(x) < 3.0 and abs(z) < 3.0:
            x = random.randint(-worldSize*800, worldSize*800) / 100.0
            z = random.randint(-worldSize*800, worldSize*800) / 100.0
        
        coinEnt = Scene.Entity("Coin")
        coinEnt.transform.position = [x, random.randint(100, 300) / 100.0, z]
        coinEnt.transform.scale = [1.0, 1.0, 1.0]
        coinEnt.transform.orientation = [random.randint(-20, 20), random.randint(-20, 20), random.randint(-20, 20)]
        coinEnt.model = conv["coin model %d" % (random.randint(0, len(colors)-1))]
        coinEnt.rigidBody = Scene.RigidBody()
        coinEnt.rigidBody.type_ = Scene.RigidBody.Type.Dynamic
        coinEnt.rigidBody.shape = coinShape
        coinEnt.rigidBody.mass = float("inf")
        coinEnt.scripts.append("resources/scripts/coin.rkt")
        scene.entities.append(coinEnt)
    
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
    
    # Monkeys
    for i in range(numMonkeys):
        x = 0.0
        z = 0.0
        
        while abs(x) < 6.0 and abs(z) < 6.0:
            x = random.randint(-worldSize*800, worldSize*800) / 100.0
            z = random.randint(-worldSize*800, worldSize*800) / 100.0
        
        monkeyEnt = Scene.Entity("Monkey%d" % (i))
        monkeyEnt.transform.position = [x, 2.0, z]
        monkeyEnt.transform.scale = [2.0, 2.0, 2.0]
        monkeyEnt.transform.orientation = [0.0, random.randint(0, 36000)/100.0, 0.0]
        monkeyEnt.model = conv["monkey model"]
        monkeyEnt.rigidBody = Scene.RigidBody()
        monkeyEnt.rigidBody.type_ = Scene.RigidBody.Type.Dynamic
        monkeyEnt.rigidBody.shape = monkeyShape
        monkeyEnt.rigidBody.linearSleepingThreshold = 0.0
        monkeyEnt.rigidBody.angularSleepingThreshold = 0.0
        monkeyEnt.rigidBody.linearDamping = 0.8
        monkeyEnt.rigidBody.mass = 100.0
        monkeyEnt.scripts.append("resources/scripts/monkey.rkt")
        scene.entities.append(monkeyEnt)
    
    # Sun
    light = Scene.Light(Scene.Light.Type.Directional)
    light.direction = [1.0, -1.0, -1.0]
    light.color = [1.0, 1.0, 0.8]
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadowmap_far = 100.0
    light.shadow_min_bias = 0.001
    light.shadow_bias_scale = 0.01
    light.shadow_auto_bias_scale = 0.75
    light.shadowmap_resolution = 1024
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    light.shadow_radius = 64
    scene.lights.append(light)
    
    for res in conv.values():
        if len(res.src_filenames) == 1:
            print res.src_filenames[0], "->", res.dest_filename
        else:
            print res.src_filenames, "->", res.dest_filename
        
        res.convert()

#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import random
import math
import noise
sys.path.append("../")
from resconvlib import *

if __name__ == "__main__":
    conv = {}
    
    random.seed(42)
    
    # Textures
    conv["skybox"] = Texture(["source/skybox/posx.png",
                              "source/skybox/negx.png",
                              "source/skybox/posy.png",
                              "source/skybox/negy.png",
                              "source/skybox/posz.png",
                              "source/skybox/negz.png"],
                              "resources/textures/skybox.bin")
    conv["grass.png"] = Texture(["source/grass.png"], "resources/textures/grass.bin")
    conv["grass.png"].mag_filter = Texture.Filter.Nearest
    conv["dirt.png"] = Texture(["source/dirt.png"], "resources/textures/dirt.bin")
    conv["dirt.png"].mag_filter = Texture.Filter.Nearest
    conv["stone.png"] = Texture(["source/stone.png"], "resources/textures/stone.bin")
    conv["stone.png"].mag_filter = Texture.Filter.Nearest
    conv["bricks.png"] = Texture(["source/bricks.png"], "resources/textures/bricks.bin")
    conv["bricks.png"].mag_filter = Texture.Filter.Nearest
    
    # Meshes
    conv["block.obj"] = Mesh(["source/block.obj"], "resources/meshes/block.bin")
    
    # Materials
    mat = Material([], "resources/materials/grass.bin")
    mat.smoothness = 0.0
    mat.metalMask = 0.0
    mat.albedoMap = conv["grass.png"]
    conv["grass"] = mat
    
    mat = Material([], "resources/materials/dirt.bin")
    mat.smoothness = 0.0
    mat.metalMask = 0.0
    mat.albedoMap = conv["dirt.png"]
    conv["dirt"] = mat
    
    mat = Material([], "resources/materials/stone.bin")
    mat.smoothness = 0.0
    mat.metalMask = 0.0
    mat.albedoMap = conv["stone.png"]
    conv["stone"] = mat
    
    mat = Material([], "resources/materials/bricks.bin")
    mat.smoothness = 0.0
    mat.metalMask = 0.0
    mat.albedoMap = conv["bricks.png"]
    conv["bricks"] = mat
    
    # Models
    model = Model([], "resources/models/grass.bin")
    model.sub_models = [[Model.LOD(conv["block.obj"], conv["grass"], 0.0, 9999.0)]]
    conv["grass model"] = model
    
    model = Model([], "resources/models/dirt.bin")
    model.sub_models = [[Model.LOD(conv["block.obj"], conv["dirt"], 0.0, 9999.0)]]
    conv["dirt model"] = model
    
    model = Model([], "resources/models/stone.bin")
    model.sub_models = [[Model.LOD(conv["block.obj"], conv["stone"], 0.0, 9999.0)]]
    conv["stone model"] = model
    
    # Shapes
    blockShape = PhysicsShape([], "resources/shapes/block.bin")
    blockShape.shape = PhysicsShape.Box([0.5, 0.5, 0.5])
    conv["block shape"] = blockShape
    
    playerShape = PhysicsShape([], "resources/shapes/player.bin")
    playerShape.shape = PhysicsShape.Cylinder("y", 1.85, 0.45)
    conv["player shape"] = playerShape
    
    # Scene
    scene = Scene([], "resources/scenes/main.bin")
    conv["scene"] = scene
    scene.skybox = conv["skybox"]
    scene.camera.position = [150.0, 150.0, 150.0]
    scene.camera.direction = [-1.0, -1.0, -1.0]
    scene.camera.up = [0.0, 1.0, 0.0]
    scene.camera.near = 0.1
    scene.camera.far = 500.0
    
    # Blocks
    numBlocks = 0
    
    avgY = random.randint(-4, 4)
    
    def block_exists(avgY, x, y, z):
        return noise.snoise3(x/8.0, y/8.0, z/8.0, 10) > 0.05
        thresh = math.sin(x / 8.0 * 3.1415 + 3.1415/2)*1.5
        thresh += math.sin(z / 8.0 * 3.1415 + 3.1415/2)*1.5
        thresh = thresh / 2 + avgY
        return random.randint(0, 100) > 75
        return y < thresh
    
    """for x in xrange(-8, 9):
        for y in xrange(-64, 65):
            for z in xrange(-8, 9):
                if not block_exists(avgY, x, y, z):
                    continue
                
                if block_exists(avgY, x-1, y, z) and \
                   block_exists(avgY, x+1, y, z) and \
                   block_exists(avgY, x, y-1, z) and \
                   block_exists(avgY, x, y+1, z) and \
                   block_exists(avgY, x, y, z-1) and \
                   block_exists(avgY, x, y, z+1):
                    continue
                
                numBlocks += 1
                
                ent = Scene.Entity("block")
                ent.transform.position = [x, y, z]
                ent.transform.scale = [0.5, 0.5, 0.5]
                
                if y >= 60:
                    if random.randint(0, 100) > 50:
                        ent.model = conv["dirt model"]
                    else:
                        ent.model = conv["grass model"]
                else:
                    ent.model = conv["stone model"]
                
                ent.rigidBody = Scene.RigidBody()
                ent.rigidBody.shape = blockShape
                scene.entities.append(ent)
    
    print numBlocks, "blocks." """
    
    ent = Scene.Entity("Player")
    ent.transform.position = [0.0, 20.0, 0.0]
    ent.transform.scale = [1.0, 1.0, 1.0]
    ent.transform.orientation = [0.0, 0.0, 0.0]
    ent.rigidBody = Scene.RigidBody()
    ent.rigidBody.type_ = Scene.RigidBody.Type.Dynamic
    ent.rigidBody.shape = playerShape
    ent.rigidBody.linearSleepingThreshold = 0.0
    ent.rigidBody.angularSleepingThreshold = 0.0
    ent.rigidBody.linearDamping = 0.8
    ent.rigidBody.mass = 100.0
    ent.scripts.append("resources/scripts/player.rkt")
    scene.entities.append(ent)
    
    # Sun
    light = Scene.Light(Scene.Light.Type.Directional)
    light.direction = [-1.0, -1.0, 0.5]
    light.color = [3.0, 3.0, 3.0]
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadowmap_far = 100.0
    light.shadow_min_bias = 0.0001
    light.shadow_bias_scale = 0.001
    light.shadow_auto_bias_scale = 0.5
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

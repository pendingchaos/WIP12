#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
sys.path.append("../")
from resconvlib import *

if __name__ == "__main__":
    conv = {}
    
    conv["texture.png"] = Texture(["source/texture.png"], "resources/textures/texture.bin")
    conv["texture2.png"] = Texture(["source/texture2.png"], "resources/textures/texture2.bin")
    conv["normal.png"] = Texture(["source/normal.png"], "resources/textures/normal.bin")
    conv["normal.png"].srgb = False
    conv["floor.png"] = Texture(["source/floor.png"], "resources/textures/floor.bin")
    conv["floor.png"].mag_filter = Texture.Filter.Nearest
    conv["skybox"] = Texture(["source/skybox/posx.png",
                              "source/skybox/negx.png",
                              "source/skybox/posy.png",
                              "source/skybox/negy.png",
                              "source/skybox/posz.png",
                              "source/skybox/negz.png"],
                              "resources/textures/skybox.bin")
    conv["bricks2.jpg"] = Texture(["source/bricks2.jpg"], "resources/textures/bricks2.bin")
    conv["bricks2_disp.jpg"] = Texture(["source/bricks2_disp.jpg"], "resources/textures/bricks2_disp.bin")
    conv["bricks2_disp.jpg"].max_anisotropy = 1.0
    conv["bricks2_normal.png"] = Texture(["source/bricks2_normal.png"], "resources/textures/bricks2_normal.bin")
    conv["bricks2_normal.png"].srgb = False
    conv["terrain.png"] = Texture(["source/terrain.png"], "resources/textures/terrain.bin")
    conv["terrain.png"].wrap_mode = Texture.WrapMode.Stretch
    conv["terrainWeight.png"] = Texture(["source/terrainWeight.png"], "resources/textures/terrainWeight.bin")
    conv["terrainWeight.png"].wrap_mode = Texture.WrapMode.Stretch
    conv["terrainWeight.png"].srgb = False
    conv["terrainWeight2.png"] = Texture(["source/terrainWeight2.png"], "resources/textures/terrainWeight2.bin")
    conv["terrainWeight2.png"].wrap_mode = Texture.WrapMode.Stretch
    conv["terrainWeight2.png"].srgb = False
    conv["grassAlbedo.png"] = Texture(["source/grass/diffuse.tga"], "resources/textures/grassAlbedo.bin")
    conv["grassNormal.png"] = Texture(["source/grass/normal.tga"], "resources/textures/grassNormal.bin")
    conv["grassNormal.png"].srgb = False
    conv["rockAlbedo.png"] = Texture(["source/rock/diffuse.tga"], "resources/textures/rockAlbedo.bin")
    conv["rockNormal.png"] = Texture(["source/rock/normal.tga"], "resources/textures/rockNormal.bin")
    conv["rockNormal.png"].srgb = False
    
    conv["debugDraw.vs"] = Shader(["source/shaders/debugDraw.vs"], "../../resources/shaders/debugDraw.vs.bin")
    conv["debugDraw.fs"] = Shader(["source/shaders/debugDraw.fs"], "../../resources/shaders/debugDraw.fs.bin")
    conv["debugDraw.fs"].stage_ = Shader.Stage.Fragment
    
    conv["skybox.vs"] = Shader(["source/shaders/skybox.vs"], "../../resources/shaders/skybox.vs.bin")
    conv["skybox.fs"] = Shader(["source/shaders/skybox.fs"], "../../resources/shaders/skybox.fs.bin")
    conv["skybox.fs"].stage_ = Shader.Stage.Fragment
    
    conv["forward.fs"] = Shader(["source/shaders/forward.fs"], "../../resources/shaders/forward.fs.bin")
    conv["forward.fs"].stage_ = Shader.Stage.Fragment
    
    conv["object.vs"] = Shader(["source/shaders/object.vs"], "../../resources/shaders/object.vs.bin")
    
    conv["gbuffer.fs"] = Shader(["source/shaders/gbuffer.fs"], "../../resources/shaders/gbuffer.fs.bin")
    conv["gbuffer.fs"].stage_ = Shader.Stage.Fragment
    
    conv["object.tcs"] = Shader(["source/shaders/object.tcs"], "../../resources/shaders/object.tcs.bin")
    conv["object.tcs"].stage_ = Shader.Stage.TessControl
    
    conv["object.tes"] = Shader(["source/shaders/object.tes"], "../../resources/shaders/object.tes.bin")
    conv["object.tes"].stage_ = Shader.Stage.TessEval
    
    conv["fxaa.fs"] = Shader(["source/shaders/fxaa.fs"], "../../resources/shaders/fxaa.fs.bin")
    conv["fxaa.fs"].stage_ = Shader.Stage.Fragment
    
    conv["lightingDirectional.fs"] = Shader(["source/shaders/lightingDirectional.fs"], "../../resources/shaders/lightingDirectional.fs.bin")
    conv["lightingDirectional.fs"].stage_ = Shader.Stage.Fragment
    
    conv["lightingPoint.fs"] = Shader(["source/shaders/lightingPoint.fs"], "../../resources/shaders/lightingPoint.fs.bin")
    conv["lightingPoint.fs"].stage_ = Shader.Stage.Fragment
    
    conv["lightingSpot.fs"] = Shader(["source/shaders/lightingSpot.fs"], "../../resources/shaders/lightingSpot.fs.bin")
    conv["lightingSpot.fs"].stage_ = Shader.Stage.Fragment
    
    conv["ssao.fs"] = Shader(["source/shaders/ssao.fs"], "../../resources/shaders/ssao.fs.bin")
    conv["ssao.fs"].stage_ = Shader.Stage.Fragment
    
    conv["ssaoBlurX.fs"] = Shader(["source/shaders/ssaoBlurX.fs"], "../../resources/shaders/ssaoBlurX.fs.bin")
    conv["ssaoBlurX.fs"].stage_ = Shader.Stage.Fragment
    
    conv["ssaoBlurY.fs"] = Shader(["source/shaders/ssaoBlurY.fs"], "../../resources/shaders/ssaoBlurY.fs.bin")
    conv["ssaoBlurY.fs"].stage_ = Shader.Stage.Fragment
    
    conv["bloomBlurX.fs"] = Shader(["source/shaders/bloomBlurX.fs"], "../../resources/shaders/bloomBlurX.fs.bin")
    conv["bloomBlurX.fs"].stage_ = Shader.Stage.Fragment
    
    conv["bloomBlurY.fs"] = Shader(["source/shaders/bloomBlurY.fs"], "../../resources/shaders/bloomBlurY.fs.bin")
    conv["bloomBlurY.fs"].stage_ = Shader.Stage.Fragment
    
    conv["postEffect.vs"] = Shader(["source/shaders/postEffect.vs"], "../../resources/shaders/postEffect.vs.bin")
    
    conv["shadowmap.vs"] = Shader(["source/shaders/shadowmap.vs"], "../../resources/shaders/shadowmap.vs.bin")
    
    conv["pointShadowmap.gs"] = Shader(["source/shaders/pointShadowmap.gs"], "../../resources/shaders/pointShadowmap.gs.bin")
    conv["pointShadowmap.gs"].stage_ = Shader.Stage.Geometry
    
    conv["shadowmap.fs"] = Shader(["source/shaders/shadowmap.fs"], "../../resources/shaders/shadowmap.fs.bin")
    conv["shadowmap.fs"].stage_ = Shader.Stage.Fragment
    
    conv["pointShadowmap.fs"] = Shader(["source/shaders/pointShadowmap.fs"], "../../resources/shaders/pointShadowmap.fs.bin")
    conv["pointShadowmap.fs"].stage_ = Shader.Stage.Fragment
    
    conv["font.fs"] = Shader(["source/shaders/font.fs"], "../../resources/shaders/font.fs.bin")
    conv["font.fs"].stage_ = Shader.Stage.Fragment
    
    conv["font.gs"] = Shader(["source/shaders/font.gs"], "../../resources/shaders/font.gs.bin")
    conv["font.gs"].stage_ = Shader.Stage.Geometry
    
    conv["fontVertex.vs"] = Shader(["source/shaders/font.vs"], "../../resources/shaders/font.vs.bin")
    
    conv["overlayVertex.vs"] = Shader(["source/shaders/overlay.vs"], "../../resources/shaders/overlay.vs.bin")
    
    conv["overlayFragment.fs"] = Shader(["source/shaders/overlay.fs"], "../../resources/shaders/overlay.fs.bin")
    conv["overlayFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["gammaCorrection.fs"] = Shader(["source/shaders/gammaCorrection.fs"], "../../resources/shaders/gammaCorrection.fs.bin")
    conv["gammaCorrection.fs"].stage_ = Shader.Stage.Fragment
    
    conv["applyBloom.fs"] = Shader(["source/shaders/applyBloom.fs"], "../../resources/shaders/applyBloom.fs.bin")
    conv["applyBloom.fs"].stage_ = Shader.Stage.Fragment
    
    conv["bloomDownsample.fs"] = Shader(["source/shaders/bloomDownsample.fs"], "../../resources/shaders/bloomDownsample.fs.bin")
    conv["bloomDownsample.fs"].stage_ = Shader.Stage.Fragment
    
    conv["tonemap.fs"] = Shader(["source/shaders/tonemap.fs"], "../../resources/shaders/tonemap.fs.bin")
    conv["tonemap.fs"].stage_ = Shader.Stage.Fragment
    
    conv["terrain.vs"] = Shader(["source/shaders/terrain.vs"], "../../resources/shaders/terrain.vs.bin")
    
    conv["terrain.tcs"] = Shader(["source/shaders/terrain.tcs"], "../../resources/shaders/terrain.tcs.bin")
    conv["terrain.tcs"].stage_ = Shader.Stage.TessControl
    
    conv["terrain.tes"] = Shader(["source/shaders/terrain.tes"], "../../resources/shaders/terrain.tes.bin")
    conv["terrain.tes"].stage_ = Shader.Stage.TessEval
    
    conv["terrain.fs"] = Shader(["source/shaders/terrain.fs"], "../../resources/shaders/terrain.fs.bin")
    conv["terrain.fs"].stage_ = Shader.Stage.Fragment
    
    conv["gui.vs"] = Shader(["source/shaders/gui.vs"], "../../resources/shaders/gui.vs.bin")
    
    conv["gui.fs"] = Shader(["source/shaders/gui.fs"], "../../resources/shaders/gui.fs.bin")
    conv["gui.fs"].stage_ = Shader.Stage.Fragment
    
    conv["cube.obj"] = Mesh(["source/cube.obj"], "../../resources/meshes/cube.bin")
    conv["mitsuba.obj"] = Mesh(["source/mitsuba.obj"], "resources/meshes/mitsuba.bin")
    conv["tesselation test.obj"] = Mesh(["source/tesselation test.obj"], "resources/meshes/tesselation test.bin")
    conv["sphere.obj"] = Mesh(["source/sphere.obj"], "resources/meshes/sphere.bin")
    conv["floor.obj"] = Mesh(["source/floor.obj"], "resources/meshes/floor.bin")
    #conv["aotest.obj"] = Mesh(["source/hairball.obj"], "resources/meshes/aotest.bin")
    conv["platform.obj"] = Mesh(["source/platform.obj"], "resources/meshes/platform.bin")
    #conv["soldier1"] = Mesh(["source/Cube.mesh.xml"], "resources/meshes/soldier.bin")
    #conv["soldier1"].animated = True
    
    mat = Material([], "resources/materials/material.bin")
    mat.smoothness = 0.6
    mat.metalMask = 0.0
    mat.albedoMap = conv["texture2.png"]
    mat.normalMap = conv["normal.png"]
    conv["material"] = mat
    
    materials = []
    
    i = 0
    for roughness in range(0, 5):
        row = []
        for metallic in range(0, 5):
            mat = Material([], "resources/materials/mat%d" % (i))
            mat.smoothness = 1.0 - roughness/4.0
            mat.metalMask = metallic/4.0
            mat.albedo = [1.0, 0.403921569, 0.0, 1.0]
            conv["mat%d" % (i)] = mat
            i += 1
            row.append(mat)
        materials.append(row)
    
    mat = Material([], "resources/materials/floor.bin")
    mat.smoothness = 0.6
    mat.metalMask = 0.0
    mat.albedoMap = conv["floor.png"]
    conv["floor"] = mat
    
    mat = Material([], "resources/materials/ao test material.bin")
    mat.smoothness = 1.0
    mat.metalMask = 0.0
    mat.albedo = [0.403921569, 1.0, 0.0, 1.0]
    conv["ao test material"] = mat
    
    mat = Material([], "resources/materials/parallax test material.bin")
    mat.smoothness = 0.875
    mat.metalMask = 0.0
    mat.albedoMap = conv["bricks2.jpg"]
    mat.pomHeightMap = conv["bricks2_disp.jpg"]
    mat.normalMap = conv["bricks2_normal.png"]
    mat.parallaxStrength = 0.1
    mat.pomMinLayers = 30
    mat.pomMaxLayers = 50
    conv["parallax test material"] = mat
    
    mat = Material([], "resources/materials/tesselation test material.bin")
    mat.smoothness = 0.5
    mat.albedoMap = conv["bricks2.jpg"]
    mat.normalMap = conv["bricks2_normal.png"]
    mat.displacementMap = conv["bricks2_disp.jpg"]
    mat.minTessLevel = 1.0
    mat.maxTessLevel = 15.0
    mat.tessMinDistance = 0.0
    mat.tessMaxDistance = 30.0
    mat.displacementStrength = 0.1
    mat.displacementMidlevel = 0.0
    mat.shadowTesselation = True
    mat.shadowMaxTessLevel = 15.0
    conv["tesselation test material"] = mat
    
    mat = Material([], "resources/materials/platform material.bin")
    mat.smoothness = 0.1
    mat.albedo = [0.9, 0.9, 1.0, 1.0]
    conv["platform material"] = mat
    
    mat = Material([], "resources/materials/grass.bin")
    mat.smoothness = 0.1
    mat.albedoMap = conv["grassAlbedo.png"]
    mat.normalMap = conv["grassNormal.png"]
    conv["grass material"] = mat
    
    mat = Material([], "resources/materials/rock.bin")
    mat.smoothness = 0.1
    mat.albedoMap = conv["rockAlbedo.png"]
    mat.normalMap = conv["rockNormal.png"]
    conv["rock material"] = mat
    
    mat = Material([], "resources/materials/soldier.bin")
    mat.smoothness = 0.5
    mat.metalMask = 1.0
    mat.albedo = [1.0, 0.403921569, 0.0, 1.0]
    conv["Soldier material"] = mat
    
    model = Model([], "resources/models/model.bin")
    model.sub_models = [[Model.LOD(conv["cube.obj"], conv["material"], 0.0, 9999.0)]]
    conv["model"] = model
    
    i = 0
    for row in materials:
        for mat in row:
            model = Model([], "resources/models/mitsuba%d.bin" % (i))
            model.sub_models = [[Model.LOD(conv["mitsuba.obj"], conv["mat%d" % (i)], 0.0, 9999.0)]]
            conv["mitsuba%d" % (i)] = model
            i += 1
    
    model = Model([], "resources/models/tesstest.bin")
    model.sub_models = [[Model.LOD(conv["tesselation test.obj"], conv["tesselation test material"], 0.0, 9999.0)]]
    conv["tesstest"] = model
    
    model = Model([], "resources/models/floor.bin")
    model.sub_models = [[Model.LOD(conv["floor.obj"], conv["floor"], 0.0, 9999.0)]]
    conv["floor model"] = model
    
    model = Model([], "resources/models/aotest.bin")
    model.sub_models = [[Model.LOD("resources/meshes/aotest.bin", conv["ao test material"], 0.0, 9999.0)]]
    conv["ao test model"] = model
    
    model = Model([], "resources/models/parallaxTest.bin")
    model.sub_models = [[Model.LOD(conv["floor.obj"], conv["parallax test material"], 0.0, 9999.0)]]
    conv["parallax test model"] = model
    
    model = Model([], "resources/models/platform.bin")
    model.sub_models = [[Model.LOD(conv["platform.obj"], conv["platform material"], 0.0, 9999.0)]]
    conv["platform"] = model
    
    model = Model([], "resources/models/solider.bin")
    model.sub_models = [[Model.LOD("resources/meshes/soldier1.bin", conv["Soldier material"], 0.0, 9999.0)]]
    conv["Soldier model"] = model
    
    floorShape = PhysicsShape([], "resources/shapes/floor.bin")
    floorShape.shape = PhysicsShape.Box([16.0, 1.0, 16.0])
    conv["floor shape"] = floorShape
    
    boxShape = PhysicsShape([], "resources/shapes/box.bin")
    boxShape.shape = PhysicsShape.Cylinder("y", 4.0, 1.0)
    conv["box shape"] = boxShape
    
    someShape = PhysicsShape([], "resources/shapes/someShape.bin")
    someShape.shape = PhysicsShape.Sphere(1.1)
    conv["some shape"] = someShape
    
    fenceShape = PhysicsShape([], "resources/shapes/fence.bin")
    fenceShape.shape = PhysicsShape.Box([0.1, 0.55, 8.0])
    conv["fence shape"] = fenceShape
    
    tessTestShape = PhysicsShape([], "resources/shapes/tessTest.bin")
    tessTestShape.shape = PhysicsShape.Box([2.0, 1.15, 2.0])
    conv["tess test shape"] = tessTestShape
    
    platformShape = PhysicsShape([], "resources/shapes/platform.bin")
    platformShape.shape = PhysicsShape.Cylinder("y", 0.1, 4.0)
    conv["platform shape"] = platformShape
    
    scene = Scene([], "resources/scenes/scene.bin")
    conv["scene"] = scene
    scene.skybox = conv["skybox"]
    scene.camera.position = [-4.0, 4.0, 4.0]
    scene.camera.direction = [4.0, -2.0, -4.0]
    scene.camera.up = [0.0, 1.0, 0.0]
    
    modifier = Scene.ColorModifier()
    modifier.type_ = Scene.ColorModifier.Type.SaturationShift
    modifier.saturation = 0.05
    scene.colorModifiers.append(modifier)
    
    modifier = Scene.ColorModifier()
    modifier.type_ = Scene.ColorModifier.Type.Vignette
    modifier.radius = 1.5
    modifier.softness = 1.0
    modifier.intensity = 1.0
    scene.colorModifiers.append(modifier)
    
    cubeEnt = Scene.Entity("PLayer")
    cubeEnt.transform.position = [4.0, 2.0, 0.0]
    cubeEnt.transform.scale = [1.0, 1.0, 1.0]
    cubeEnt.transform.orientation = [0.0, 0.0, 0.0]
    cubeEnt.rigidBody = Scene.RigidBody()
    cubeEnt.rigidBody.type_ = Scene.RigidBody.Type.Dynamic
    cubeEnt.rigidBody.shape = boxShape
    cubeEnt.rigidBody.linearSleepingThreshold = 0.0
    cubeEnt.rigidBody.angularSleepingThreshold = 0.0
    cubeEnt.rigidBody.linearDamping = 0.8
    cubeEnt.rigidBody.mass = 100.0
    #cubeEnt.scripts.append("resources/scripts/entityscript.cpp")
    cubeEnt.scripts.append("resources/scripts/player.rkt")
    #cubeEnt.scripts.append("resources/scripts/lightscript.cpp")
    scene.entities.append(cubeEnt)
    
    i = 0
    for x in range(-2, 3):
        for z in range(-2, 3):
            ent = Scene.Entity("Mitsuba%d" % (i))
            ent.transform.position = [x*5+20, 1.15, z*5]
            ent.transform.orientation = [0.0, -90.0, 0.0]
            ent.model = conv["mitsuba%d" % (i)]
            ent.rigidBody = Scene.RigidBody()
            ent.rigidBody.shape = someShape
            scene.entities.append(ent)
            i += 1
    
    floorEnt = Scene.Entity("Floor")
    floorEnt.transform.position = [20.0, -1.0, 0.0]
    floorEnt.transform.scale = [2.0, 1.0, 2.0]
    floorEnt.model = conv["floor model"]
    floorEnt.rigidBody = Scene.RigidBody()
    floorEnt.rigidBody.shape = floorShape
    scene.entities.append(floorEnt)
    
    """floorEnt = Scene.Entity("Floor2")
    floorEnt.transform.position = [20.0, -10.0, 0.0]
    floorEnt.transform.scale = [2.0, 1.0, 2.0]
    floorEnt.model = conv["floor model"]
    floorEnt.shadow_caster = False
    floorEnt.rigidBody = Scene.RigidBody()
    floorEnt.rigidBody.shape = floorShape
    scene.entities.append(floorEnt)
    
    ent = Scene.Entity("AO test")
    ent.transform.position = [20.0, -5.5, 0.0]
    ent.transform.orientation = [0.0, 100.0, 0.0]
    ent.transform.scale = [0.5, 0.5, 0.5]
    ent.model = conv["ao test model"]
    scene.entities.append(ent)
    
    light = Scene.Light(Scene.Light.Type.Spot)
    light.position = [10.0, 0.25, 0.0]
    light.direction = [1.0, -0.6, 0.0]
    light.color = [1.0, 1.0, 1.0]
    light.power = 10.0
    light.radius = 10.0
    light.inner_cutoff = 10.0
    light.outer_cutoff = 12.0
    light.ambient_strength = 0.0
    light.shadowmap = False
    light.shadowmap_near = 0.1
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 1.0
    light.shadowmap_resolution = 512
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    scene.lights.append(light)"""
    
    """ent = Scene.Entity("Parallax test")
    ent.transform.position = [0.0, 1.0, 0.0]
    ent.transform.scale = [0.1, 1.0, 0.1]
    ent.model = conv["parallax test model"]
    scene.entities.append(ent)"""
    
    """ent = Scene.Entity("Soldier")
    #ent.transform.position = [0.0, 3.25, -3.0]
    #ent.transform.position = [0.0, 0.0, -3.0]
    ent.transform.position = [0.0, 2.4, -3.0]
    #ent.transform.position = [11.0, 6.0, 6.0]
    #ent.transform.scale = [0.75, 0.75, 0.75]
    #ent.transform.scale = [0.055, 0.055, 0.055]
    #ent.transform.scale = [3.0, 3.0, 3.0]
    #ent.transform.scale = [0.2, 0.2, 0.2]
    #ent.transform.scale = [1.2, 1.2, 1.2]
    ent.transform.orientation = [0.0, 225.0, 0.0]
    ent.model = conv["Soldier model"]
    #ent.animation = "man"
    #ent.animation = "knight_attack"
    #ent.animation = "kngcalvn_fbx_test"
    #ent.animation = "Octaminator_lowpoly_final"
    #ent.animation = "riggedHorse"
    ent.animation = "ArmatureAction"
    ent.scripts.append("resources/scripts/animated.rkt")
    scene.entities.append(ent)"""
    
    """ent = Scene.Entity("TessTest")
    ent.transform.position = [0.0, 1.15, 5.0]
    ent.transform.orientation = [0.0, 90.0, 0.0]
    ent.model = conv["tesstest"]
    ent.rigidBody = Scene.RigidBody()
    ent.rigidBody.shape = tessTestShape
    scene.entities.append(ent)"""
    
    """platforms = Scene.Entity("Platfoms")
    platforms.transform.position = [0.0, 0.0, 25.0]
    platforms.transform.orientation = [0.0, 90.0, 0.0]
    scene.entities.append(platforms)
    
    ent = Scene.Entity("Platform1")
    ent.transform.position = [0.0, 0.1, 0.0]
    ent.model = conv["platform"]
    ent.rigidBody = Scene.RigidBody()
    ent.rigidBody.shape = platformShape
    ent.rigidBody.friction = 0.1
    platforms.entities.append(ent)
    
    ent = Scene.Entity("Platform2")
    ent.transform.position = [4.0, 6.1, -3.0]
    ent.model = conv["platform"]
    ent.rigidBody = Scene.RigidBody()
    ent.rigidBody.shape = platformShape
    ent.rigidBody.friction = 0.1
    platforms.entities.append(ent)
    
    ent = Scene.Entity("Platform3")
    ent.transform.position = [-7.0, 4.1, 5.0]
    ent.model = conv["platform"]
    ent.rigidBody = Scene.RigidBody()
    ent.rigidBody.shape = platformShape
    ent.rigidBody.friction = 0.1
    platforms.entities.append(ent)
    
    ent = Scene.Entity("Platform4")
    ent.transform.position = [-7.0, 1.1, -5.0]
    ent.model = conv["platform"]
    ent.rigidBody = Scene.RigidBody()
    ent.rigidBody.shape = platformShape
    ent.rigidBody.friction = 0.1
    platforms.entities.append(ent)
    
    ent = Scene.Entity("Platform5")
    ent.transform.position = [4.0, 1.1, 4.0]
    ent.model = conv["platform"]
    ent.rigidBody = Scene.RigidBody()
    ent.rigidBody.shape = platformShape
    ent.rigidBody.friction = 0.1
    platforms.entities.append(ent)
    
    ent = Scene.Entity("Platform6")
    ent.transform.position = [4.0, 7.1, 10.0]
    ent.transform.orientation = [15.0, -5.0, -2.0]
    ent.model = conv["platform"]
    ent.rigidBody = Scene.RigidBody()
    ent.rigidBody.shape = platformShape
    ent.rigidBody.friction = 0.1
    platforms.entities.append(ent)
    
    ent = Scene.Entity("Platform7")
    ent.transform.position = [-2.0, 9.1, -13.0]
    ent.transform.orientation = [15.0, 124.0, -2.0]
    ent.model = conv["platform"]
    ent.rigidBody = Scene.RigidBody()
    ent.rigidBody.shape = platformShape
    ent.rigidBody.friction = 0.1
    platforms.entities.append(ent)
    
    ent = Scene.Entity("Platform8")
    ent.transform.position = [-13.0, 11.1, -3.0]
    ent.model = conv["platform"]
    ent.rigidBody = Scene.RigidBody()
    ent.rigidBody.shape = platformShape
    ent.rigidBody.friction = 0.1
    platforms.entities.append(ent)"""
    
    """# Point light benchmark
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [9.0, 2.5, -6.0]
    light.radius = 0.33
    light.color = [1.0, 0.0, 0.0]
    light.power = 2.0
    light.ambient_strength = 0.005
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 0.65
    light.shadowmap_resolution = 1024
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [11.0, 2.5, -6.0]
    light.radius = 0.33
    light.color = [0.0, 1.0, 0.0]
    light.power = 2.0
    light.ambient_strength = 0.005
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 0.65
    light.shadowmap_resolution = 1024
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [10.0, 2.5, -7.0]
    light.radius = 0.33
    light.color = [0.0, 0.0, 1.0]
    light.power = 2.0
    light.ambient_strength = 0.005
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 0.65
    light.shadowmap_resolution = 1024
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [10.0, 2.5, -5.0]
    light.radius = 0.33
    light.color = [1.0, 1.0, 0.0]
    light.power = 2.0
    light.ambient_strength = 0.005
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 0.65
    light.shadowmap_resolution = 1024
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [9.0, 2.5, 0.0]
    light.radius = 0.33
    light.color = [1.0, 0.0, 0.0]
    light.power = 2.0
    light.ambient_strength = 0.005
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 0.65
    light.shadowmap_resolution = 1024
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [11.0, 2.5, 0.0]
    light.radius = 0.33
    light.color = [0.0, 1.0, 0.0]
    light.power = 2.0
    light.ambient_strength = 0.005
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 0.65
    light.shadowmap_resolution = 1024
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [10.0, 2.5, -1.0]
    light.radius = 0.33
    light.color = [0.0, 0.0, 1.0]
    light.power = 2.0
    light.ambient_strength = 0.005
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 0.65
    light.shadowmap_resolution = 1024
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [10.0, 2.5, 1.0]
    light.radius = 0.33
    light.color = [1.0, 1.0, 0.0]
    light.power = 2.0
    light.ambient_strength = 0.005
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 0.65
    light.shadowmap_resolution = 1024
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [9.0, 2.5, 6.0]
    light.radius = 0.33
    light.color = [1.0, 0.0, 0.0]
    light.power = 2.0
    light.ambient_strength = 0.005
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 0.65
    light.shadowmap_resolution = 1024
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [11.0, 2.5, 6.0]
    light.radius = 0.33
    light.color = [0.0, 1.0, 0.0]
    light.power = 2.0
    light.ambient_strength = 0.005
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 0.65
    light.shadowmap_resolution = 1024
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [10.0, 2.5, 5.0]
    light.radius = 0.33
    light.color = [0.0, 0.0, 1.0]
    light.power = 2.0
    light.ambient_strength = 0.005
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 0.65
    light.shadowmap_resolution = 1024
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    scene.lights.append(light)
    
    light = Scene.Light(Scene.Light.Type.Point)
    light.position = [10.0, 2.5, 7.0]
    light.radius = 0.33
    light.color = [1.0, 1.0, 0.0]
    light.power = 2.0
    light.ambient_strength = 0.005
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 0.65
    light.shadowmap_resolution = 1024
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    scene.lights.append(light)"""
    
    # Directional light test
    light = Scene.Light(Scene.Light.Type.Directional)
    light.direction = [0.4, -1.0, 0.0]
    light.color = [1.0, 1.0, 0.8]
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadowmap_far = 100.0
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 1.0
    light.shadowmap_resolution = 1024
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    light.shadow_radius = 32
    scene.lights.append(light)
    
    # Point light test
    """light = Scene.Light(Scene.Light.Type.Point)
    light.position = [0.0, 1.0, 0.0]
    light.radius = 10.0
    light.power = 2.0
    light.ambient_strength = 0.004
    light.color = [1.0, 1.0, 1.0]
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 0.65
    light.shadowmap_resolution = 1024
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    scene.lights.append(light)"""
    
    # Spot light test
    """light = Scene.Light(Scene.Light.Type.Spot)
    light.position = [8.0, 2.5, 0.0]
    light.direction = [1.0, -0.75, 0.0]
    light.color = [1.0, 1.0, 1.0]
    light.power = 5.0
    light.inner_cutoff = 28.0
    light.outer_cutoff = 30.0
    light.shadowmap = True
    light.shadowmap_near = 0.1
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 1.0
    light.shadowmap_resolution = 512
    light.ambient_strength = 0.015
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
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 1.0
    light.shadowmap_resolution = 512
    light.ambient_strength = 0.015
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
    light.shadow_min_bias = 0.005
    light.shadow_bias_scale = 0.05
    light.shadow_auto_bias_scale = 1.0
    light.shadowmap_resolution = 512
    light.ambient_strength = 0.015
    light.shadowmap_precision = Scene.Light.ShadowmapPrecision.Low
    scene.lights.append(light)"""
    
    for res in conv.values():
        if len(res.src_filenames) == 1:
            print res.src_filenames[0], "->", res.dest_filename
        else:
            print res.src_filenames, "->", res.dest_filename
        
        #if isinstance(res, Shader):
        res.convert()

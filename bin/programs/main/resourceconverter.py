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
    
    conv["objectTessControl.tcs"] = Shader(["source/shaders/objectTessControl.tcs"], "../../resources/shaders/objectTessControl.bin")
    conv["objectTessControl.tcs"].stage_ = Shader.Stage.TessControl
    
    conv["objectTessEval.tes"] = Shader(["source/shaders/objectTessEval.tes"], "../../resources/shaders/objectTessEval.bin")
    conv["objectTessEval.tes"].stage_ = Shader.Stage.TessEval
    
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
    
    conv["shadowmapControl.tcs"] = Shader(["source/shaders/shadowmapControl.tcs"], "../../resources/shaders/shadowmapControl.bin")
    conv["shadowmapControl.tcs"].stage_ = Shader.Stage.TessControl
    
    conv["shadowmapEval.tes"] = Shader(["source/shaders/shadowmapEval.tes"], "../../resources/shaders/shadowmapEval.bin")
    conv["shadowmapEval.tes"].stage_ = Shader.Stage.TessEval
    
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
    
    conv["gammaCorrectionFragment.fs"] = Shader(["source/shaders/gammaCorrectionFragment.fs"], "../../resources/shaders/gammaCorrectionFragment.bin")
    conv["gammaCorrectionFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["applyBloomFragment.fs"] = Shader(["source/shaders/applyBloomFragment.fs"], "../../resources/shaders/applyBloomFragment.bin")
    conv["applyBloomFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["applyBloomFragment.fs"] = Shader(["source/shaders/applyBloomFragment.fs"], "../../resources/shaders/applyBloomFragment.bin")
    conv["applyBloomFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["bloomDownsampleFragment.fs"] = Shader(["source/shaders/bloomDownsampleFragment.fs"], "../../resources/shaders/bloomDownsampleFragment.bin")
    conv["bloomDownsampleFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["terrainVertex.vs"] = Shader(["source/shaders/terrainVertex.vs"], "../../resources/shaders/terrainVertex.bin")
    
    conv["terrainTessControl.tcs"] = Shader(["source/shaders/terrainTessControl.tcs"], "../../resources/shaders/terrainTessControl.bin")
    conv["terrainTessControl.tcs"].stage_ = Shader.Stage.TessControl
    
    conv["terrainTessEval.tes"] = Shader(["source/shaders/terrainTessEval.tes"], "../../resources/shaders/terrainTessEval.bin")
    conv["terrainTessEval.tes"].stage_ = Shader.Stage.TessEval
    
    conv["terrainFragment.fs"] = Shader(["source/shaders/terrainFragment.fs"], "../../resources/shaders/terrainFragment.bin")
    conv["terrainFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["guiVertex.vs"] = Shader(["source/shaders/guiVertex.vs"], "../../resources/shaders/guiVertex.bin")
    
    conv["guiFragment.fs"] = Shader(["source/shaders/guiFragment.fs"], "../../resources/shaders/guiFragment.bin")
    conv["guiFragment.fs"].stage_ = Shader.Stage.Fragment
    
    conv["cube.obj"] = Mesh(["source/cube.obj"], "../../resources/meshes/cube.bin")
    conv["material test.obj"] = Mesh(["source/material test.obj"], "resources/meshes/material test.bin")
    conv["material test 2.obj"] = Mesh(["source/material test 2.obj"], "resources/meshes/material test 2.bin")
    conv["tesselation test.obj"] = Mesh(["source/tesselation test.obj"], "resources/meshes/tesselation test.bin")
    conv["sphere.obj"] = Mesh(["source/sphere.obj"], "resources/meshes/sphere.bin")
    conv["floor.obj"] = Mesh(["source/floor.obj"], "resources/meshes/floor.bin")
    conv["fence.obj"] = Mesh(["source/fence.obj"], "resources/meshes/fence.bin")
    conv["aotest.obj"] = Mesh(["source/ao test.obj"], "resources/meshes/aotest.bin")
    conv["platform.obj"] = Mesh(["source/platform.obj"], "resources/meshes/platform.bin")
    #conv["soldier1"] = Mesh(["source/Cube.mesh.xml"], "resources/meshes/soldier.bin")
    #conv["soldier1"].animated = True
    
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
    
    mat = Material([], "resources/materials/projectile.bin")
    mat.forward = False
    mat.smoothness = 0.5
    mat.metalMask = 1.0
    mat.albedo = [0.95349481, 0.806474433, 0.374256055, 1.0]
    mat.normalMap = conv["normal.png"]
    conv["projectile material"] = mat
    
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
    mat.normalMap = conv["bricks2_normal.png"]
    mat.parallaxStrength = 0.1
    mat.pomMinLayers = 30
    mat.pomMaxLayers = 50
    conv["parallax test material"] = mat
    
    mat = Material([], "resources/materials/tesselation test material.bin")
    mat.forward = False
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
    mat.forward = False
    mat.smoothness = 0.1
    mat.albedo = [0.9, 0.9, 1.0, 1.0]
    conv["platform material"] = mat
    
    mat = Material([], "resources/materials/grass.bin")
    mat.forward = False
    mat.smoothness = 0.1
    mat.albedoMap = conv["grassAlbedo.png"]
    mat.normalMap = conv["grassNormal.png"]
    conv["grass material"] = mat
    
    mat = Material([], "resources/materials/rock.bin")
    mat.forward = False
    mat.smoothness = 0.1
    mat.albedoMap = conv["rockAlbedo.png"]
    mat.normalMap = conv["rockNormal.png"]
    conv["rock material"] = mat
    
    mat = Material([], "resources/materials/soldier.bin")
    mat.forward = False
    mat.smoothness = 0.5
    mat.metalMask = 1.0
    mat.albedo = [1.0, 0.403921569, 0.0, 1.0]
    conv["Soldier material"] = mat
    
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
    
    model = Model([], "resources/models/tesstest.bin")
    model.sub_models = [[Model.LOD(conv["tesselation test.obj"], conv["tesselation test material"], 0.0, 9999.0)]]
    conv["tesstest"] = model
    
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
    
    model = Model([], "resources/models/platform.bin")
    model.sub_models = [[Model.LOD(conv["platform.obj"], conv["platform material"], 0.0, 9999.0)]]
    conv["platform"] = model
    
    model = Model([], "resources/models/projectile.bin")
    model.sub_models = [[Model.LOD(conv["sphere.obj"], conv["projectile material"], 0.0, 9999.0)]]
    conv["projectile"] = model
    
    model = Model([], "resources/models/solider.bin")
    model.sub_models = [[Model.LOD("resources/meshes/soldier1.bin", conv["Soldier material"], 0.0, 9999.0)]]
    conv["Soldier model"] = model
    
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
    
    tessTestShape = PhysicsShape([], "resources/shapes/tessTest.bin")
    tessTestShape.shape = PhysicsShape.Box([2.0, 1.15, 2.0])
    conv["tess test shape"] = tessTestShape
    
    platformShape = PhysicsShape([], "resources/shapes/platform.bin")
    platformShape.shape = PhysicsShape.Cylinder("y", 0.1, 4.0)
    conv["platform shape"] = platformShape
    
    projectileShape = PhysicsShape([], "resources/shapes/projectile.bin")
    projectileShape.shape = PhysicsShape.Sphere(1.0)
    conv["projectile shape"] = projectileShape
    
    scene = Scene([], "resources/scenes/scene.bin")
    conv["scene"] = scene
    scene.skybox = conv["skybox"]
    scene.camera.position = [-4.0, 4.0, 4.0]
    scene.camera.direction = [4.0, -2.0, -4.0]
    scene.camera.up = [0.0, 1.0, 0.0]
    
    modifier = Scene.ColorModifier()
    modifier.type_ = Scene.ColorModifier.Type.ReinhardTonemap
    modifier.brightnessOnly = True
    scene.colorModifiers.append(modifier)
    
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
    cubeEnt.rigidBody.mass = 100.0
    #cubeEnt.scripts.append("resources/scripts/entityscript.cpp")
    cubeEnt.scripts.append("resources/scripts/player.rkt")
    #cubeEnt.scripts.append("resources/scripts/lightscript.cpp")
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
    
    ent = Scene.Entity("Parallax test")
    ent.transform.position = [0.0, 1.0, 0.0]
    ent.transform.scale = [0.1, 1.0, 0.1]
    ent.model = conv["parallax test model"]
    scene.entities.append(ent)
    
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
    ent.scripts.append(("resources/scripts/animated.cpp", "Animated"))
    scene.entities.append(ent)"""
    
    ent = Scene.Entity("TessTest")
    ent.transform.position = [0.0, 1.15, 5.0]
    ent.transform.orientation = [0.0, 90.0, 0.0]
    ent.model = conv["tesstest"]
    ent.rigidBody = Scene.RigidBody()
    ent.rigidBody.shape = tessTestShape
    scene.entities.append(ent)
    
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

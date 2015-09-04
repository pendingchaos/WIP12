## Features
- [ ] Forward shadow mapping.
- [ ] Skeletal animation.
- [ ] Serialize and deserialize script instances when saving and loading a scene.
- [ ] Transformation for a PhysicsShape.
- [ ] Make physics shapes more lightweight.
- [ ] Virtual Shadow mapping: http://advances.realtimerendering.com/s2015/aaltonenhaar_siggraph2015_combined_final_footer_220dpi.pdf
    - Low priority
    - Claims to be faster than SDSM in complex scenes.
    - Needs recent hardware.
- [ ] Finish the script binding generator.
    - [ ] Cast for things like Audio -> Resource for arguments.
    - [ ] Cast for things like Resource -> Audio.

    - [ ] NULL <-> nil conversion
    - [ ] Templated Functions
    - [ ] Namespaces
    - [ ] Getters and Setters
    - [ ] C++ exceptions -> script exceptions
    - [ ] Bind lots of stuff
    - [ ] Static methods and properties
    - [ ] Finish binding Matrix3x3, Matrix4x4, RigidBody, File, GfxBuffer, GfxDebugDrawer, Light, Resource and Audio.
- [ ] Make functions for builtin functions like + and *.
- [ ] === function (scripting).

## Bugs
- [ ] Lines 48 and 53 in src/graphics/GL/glgputimer.cpp don't work with Mesa3d:
    - GL_INVALID_OPERATION in glQueryCounter(id has an invalid target)
        - Might now be fixed.
- [ ] Forward rendering does not work.
- [ ] The doppler effect (disabled) causes popping noise.
- [ ] More tests should be created.
- [ ] The tesselation test's normals seem incorrect.
- [ ] Circular references will cause memory leaks (scripting).
- [ ] TODOs in src/scripting.
- [ ] Transform::lookAt does not work.
- [ ] Fix black borders around normal mapped metallic objects (http://marmosetco.tumblr.com/post/81245981087 ?):
![screenshot](https://raw.githubusercontent.com/pendingchaos/WIP12/master/metallic border bug.png)

## Other
- [ ] Texture types should be immutable.
- [ ] Benchmarks.
    - [ ] Draw call
    - [ ] AudioWorld
    - [ ] ???
- [ ] Fix banding in darkly lit areas, on metallic surfaces and point light lit areas.
    - [ ] Dithering? https://en.wikipedia.org/wiki/Floyd-Steinberg_dithering?
- [ ] Ambient occlusion looks very bad on spheres.
- [ ] Improve error and exception handling.
- [ ] Get WIP12 running on OpenGL 3.3.

## Performance Improvements
- [ ] Instancing
    - [ ] Implicit
        - [x] G-Buffer
        - [x] Forward
        - [ ] Shadowmap
    - [ ] Explicit
- [ ] SSAO performance should be improved.
- [ ] Fix performance warnings in shaders (Mesa3D):
    - [ ] lightingDirectional.bin:
        - [ ] fragment shader triggered register spilling.  Try reducing the number of live scalar values to improve performance.
        - [ ] SIMD16 shader failed to compile, falling back to SIMD8 at a 10-20% performance cost: FS compile failed: Failure to register allocate.  Reduce number of live scalar values to avoid this.
    - [ ] lightingPoint.bin:
        - [ ] SIMD16 shader failed to compile, falling back to SIMD8 at a 10-20% performance cost: FS compile failed: Failure to register allocate.  Reduce number of live scalar values to avoid this.
    - [ ] lightingSpot.bin:
        - [ ] SIMD16 shader failed to compile, falling back to SIMD8 at a 10-20% performance cost: FS compile failed: Failure to register allocate.  Reduce number of live scalar values to avoid this.
    - [ ] ssaoFragment.bin:
        - [ ] SIMD16 shader failed to compile, falling back to SIMD8 at a 10-20% performance cost: FS compile failed: Failure to register allocate.  Reduce number of live scalar values to avoid this.

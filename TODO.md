## Next
- [ ] Resource copy() function.
    - [ ] Material
    - [ ] Model
    - [ ] Scene
    - [ ] PhysicsShape
    - [ ] Font

## Features
- [ ] Shadow mapping.
    - [ ] Directional
        - [x] Deferred
        - [ ] Forward
    - [ ] Point
        - [x] Deferred
        - [ ] Forward
    - [ ] Spot
        - [x] Deferred
        - [ ] Forward
- [ ] Use a subdivided cube instead of a sphere for the displacement mapping test.
- [ ] Skeletal animation.

## Bugs
- [ ] The doppler effect (disabled) causes popping noise.
- [ ] More tests should be created.
- [ ] Parallax occlusion mapping seems to be incorrect(?).
- [ ] The tesselation test's normals seem incorrect.
- [ ] The program crashes when the script fails to compile on startup.
- [ ] When a script is reloaded, the scripts that #include it will not be recompiled.
- [ ] Displacement mapping should contribute to the scene AABB.

## Other
- [ ] Benchmarks.
    - [ ] Draw call
    - [ ] AudioWorld
    - [ ] ???
- [ ] Fix banding in darkly lit areas, on metallic surfaces and point light lit areas.
    - [ ] Dithering? https://en.wikipedia.org/wiki/Floyd-Steinberg_dithering?
- [ ] Ambient occlusion looks very bad on spheres.
- [ ] Improve error and exception handling.
- [ ] Get WIP12 running on OpenGL 3.3.
- [ ] Get rid of ResPtr.

## Performance Improvements
- [ ] Instancing (explicit and implicit).
- [ ] SSAO performance should be improved.

Next Generation Post Processing in Call of Duty Advanced Warfare slide 120 (for point light filtering) (advances.realtimerendering.com).

## HBAO
    - https://gist.github.com/fisch0920/6770346
    - https://github.com/nvpro-samples/gl_ssao/blob/master/hbao.frag.glsl
    - https://a248.e.akamai.net/f/862/5658/3/developer.download.nvidia.com/presentations/2008/SIGGRAPH/HBAO_SIG08b.pdf
    - Fix false occlusion at the borders.
    - Interleaving is incorrect or HBAO is.

## Fixing sphere and box corner ao
- Reconstruct normals using dFdx and dFdy.
    - Normal mapping won't increase detail.
    - Creates artifacts around borders
        - https://github.com/nvpro-samples/gl_ssao/blob/master/hbao.frag.glsl#L123

## IBL
- blog.selfshadow.com/publications/s2013-shading-course/karis/s2013_pbs_epic_notes_v2.pdf
- https://github.com/jMonkeyEngine/jmonkeyengine/compare/PBRisComing#diff-507f20304921a2bc77fb399401c5a7b8R138
- https://github.com/jMonkeyEngine/jmonkeyengine/compare/PBRisComing#diff-507f20304921a2bc77fb399401c5a7b8R138
- https://github.com/jMonkeyEngine/jmonkeyengine/blob/af35f27b938ca8ec7e2e6d2b479ea6e452cee835/jme3-core/src/main/resources/Common/ShaderLib/PBR.glsllib
- jmonkeyengine.org/301308/physically-based-rendering-part-3/
- https://github.com/jMonkeyEngine/jmonkeyengine/blob/af35f27b938ca8ec7e2e6d2b479ea6e452cee835/jme3-core/src/main/resources/Common/MatDefs/Light/PBRLighting.frag
- https://github.com/jMonkeyEngine/jmonkeyengine/compare/PBRisComing#diff-a76e40d1405edd3626e52286d1f179dfR441
- https://github.com/jMonkeyEngine/jmonkeyengine/compare/PBRisComing#diff-a76e40d1405edd3626e52286d1f179dfR476
- https://github.com/jMonkeyEngine/jmonkeyengine/tree/af35f27b938ca8ec7e2e6d2b479ea6e452cee835/jme3-core/src/main/java/com/jme3/texture/pbr


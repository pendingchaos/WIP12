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
- [ ] The doppler effect (disabled) causes popping noise.
- [ ] Use a subdivided cube instead of a sphere for the displacement mapping test.
- [ ] Resource copy() function.
- [ ] Make it possible for an object to rotate around another.

## Bugs
- [ ] More tests should be created.
- [ ] The computer freezes when the window is too small.
- [ ] Parallax occlusion mapping seems to be incorrect.
- [ ] The tesselation test's normals seem incorrect.
- [ ] The program crashes when the script fails to compile on startup.

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

## Performance Improvements
- [ ] Instancing (explicit and implicit).
- [ ] SSAO performance should be improved.
- [ ] Bloom performance should be improved.
    - http://kalogirou.net/2006/05/20/how-to-do-good-bloom-for-hdr-rendering/
    - http://rastergrid.com/blog/2010/09/efficient-gaussian-blur-with-linear-sampling/

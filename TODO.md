## Features
- [ ] Shapes should be mutable eg. from a radius of 5 to a radius of 10.
    * It seems Bullet's api does not allow this for many shapes.
    * PhysicsCompoundShape should be resizable.
- [ ] Post processing effects.
    - [ ] Color grading (using a 3d texture)
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

## Bugs
- [ ] More tests should be created.
- [ ] The computer freezes when the window is too small.

## Other
- [ ] Benchmarks.
    - [ ] Draw call
    - [ ] AudioWorld
    - [ ] ???
- [ ] Fix banding in darkly lit areas, on metallic surfaces and point light lit areas.
    - [ ] https://en.wikipedia.org/wiki/Floyd-Steinberg_dithering
- [ ] Ambient occlusion looks very bad on spheres.
- [ ] Improve error and exception handling.

## Performance Improvements
- [ ] Instancing (explicit and implicit).
- [ ] SSAO performance should be improved.

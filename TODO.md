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
- [ ] Audio
- [ ] Ghost objects (btGhostObject).
- [ ] Saving the state of scripts when they are reloaded.
- [ ] Raycasting.
- [ ] Collision callbacks.

## Bugs
- [ ] More tests should be created.
- [ ] When a shape is changed from a type to another, rigid bodies using that shape will have invalid shapes.
- [ ] Sometimes when a script fails to compile, a segmentation fault happens.
- [ ] The matrix 4x4 inverse function is incorrect(?).
- [ ] The computer freezes when the window is too small.

## Other
- [ ] Benchmarks.
    - [ ] Draw call
    - [ ] ???
- [ ] The matrix inversion functions need improvement.
- [ ] Fix banding in darkly lit areas and on metallic surfaces.
- [ ] Ambient occlusion looks very bad on spheres.
- [ ] Improve error and exception handling.

## Performance Improvements
- [ ] Script compilation is very slow.
- [ ] Instancing (explicit and implicit).

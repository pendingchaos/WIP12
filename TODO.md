## Features
- [ ] Shapes should be mutable eg. from a radius of 5 to a radius of 10.
    * It seems Bullet's api does not allow this for many shapes.
    * PhysicsCompoundShape should be resizable.
- [ ] 3D textures.
- [ ] Text rendering.
- [ ] Overlay rendering.
- [ ] Post processing effects.
    - [ ] Color grading (using a 3d texture)
    - [ ] Tomemapping
    - [ ] Eye adaptation
- [ ] Shadow mapping.
    - [ ] Directional
    - [ ] Point
    - [ ] Spot
- [ ] Audio
- [ ] Make scripts less independent. (eg. calling a function in a script from another script should work).
- [ ] Ghost objects (btGhostObject).
- [ ] Saving the state of scripts when they are reloaded.
- [ ] Raycasting.
- [ ] Collision callbacks.

## Bugs
- [ ] More tests should be created.
- [ ] When a shape is changed from a type to another, rigid bodies using that shape will have invalid shapes.
- [ ] Sometimes when a script fails to compile, a segmentation fault happens.
- [ ] The matrix 4x4 inverse function is incorrect(?).

## Other
- [ ] Benchmarks.
- [ ] The matrix inversion functions need improvement.
- [ ] Fix banding in darkly lit areas and on metallic surfaces.

## Performance Improvements
- [ ] Script compilation is very slow.
- [ ] Instancing (explicit and implicit).

#WIP12

![screenshot](https://raw.githubusercontent.com/pendingchaos/WIP12/master/screenshot.png)

A work in progress using [OpenGL](https://opengl.org) and [Bullet](bulletphysics.org) in C++.

The program has only been tested on a Linux based operating system.
The program requires g++, SDL2, Bullet, libdl, a c standard library implementation, a c++ standard library implementation, and an OpenGL implementation supporting OpenGL 4.3 or higher.

```
yum install SDL2-devel bullet-devel gcc-c++
```

The rest should already be installed (with the exception of the OpenGL implementation, Mesa does not support OpenGL 4.3).

The scripts require Python 2.7 but they might work with a different version.

To run, go to the directory named "bin" (in a shell) and run "./run_main".

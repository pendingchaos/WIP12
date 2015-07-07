#WIP12

![screenshot](https://raw.githubusercontent.com/pendingchaos/WIP12/master/screenshot.png)

A work in progress using [OpenGL](https://opengl.org) and [Bullet](bulletphysics.org) in C++.

The program has only been tested on a Linux based operating system.
The program requires g++, SDL2, Bullet, FreeType, libdl, a c standard library implementation, a c++ standard library implementation, and an OpenGL implementation supporting OpenGL 4.3 or higher.

They can be installed by running:
```shell
yum install SDL2-devel bullet-devel gcc-c++ freetype-devel
```

The rest should already be installed (with the exception of the OpenGL implementation, Mesa does not support OpenGL 4.3).

The scripts have only been tested with Python 2.7 but they might work with a different version.

To compile, run compile.py in the scripts directory or use the Code::Blocks project with an IDE that supports it.
You might want to change process_count (on line 6) in compile.py to the number of cores on your CPU (and possibly plus one or two).

To run, go to the directory named "bin" (in a shell) and run
```shell
./run_main.
```

You should also run resourceconverter.py to convert the textures to the format WIP12 uses before running.

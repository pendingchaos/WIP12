#WIP12

![screenshot](https://raw.githubusercontent.com/pendingchaos/WIP12/master/screenshot.png)

A work in progress using [OpenGL](https://opengl.org) and [Bullet Physics](bulletphysics.org) in C++.
Please do not submit any pull requests. This is my own project that I am making for fun and knowledge.

The program has only been tested on a Linux based operating system.

## Dependencies
The program requires g++, SDL2, Bullet, FreeType, libdl, a c standard library implementation, a c++ standard library implementation, and an OpenGL implementation supporting OpenGL 3.3 or higher, GL_ARB_tesselation_shader and GL_ARB_separate_shader_objects.

They can be installed by running or something similar:
```shell
yum install SDL2-devel bullet-devel gcc-c++ freetype-devel
```

resourceconverter.py depends on Pillow. It can be installed with
```shell
pip2 install Pillow
```

If you have yum and pip(2) you can run
```shell
make install_deps
```

The rest should already be installed.

The scripts have only been tested with Python 2.7 but they might work with a different version.

## Compiling
To compile, run compile.py in the scripts directory or use the Code::Blocks project with an IDE that supports it.
You might want to change [process_count](https://github.com/pendingchaos/WIP12/blob/master/scripts/compile.py#L6) in compile.py to the number of cores on your CPU (and possibly plus one or two).
You can also run compile.py like this:
```shell
make compile
```

## Running
Before you run, run resourceconverter.py or run this:
```
make resource_convert
```

Then run
```shell
make run_main
```
or bin/run_main.

## Compiling and running the lazy way
```shell
make lazy
```

## Attribution
The Soldier 1.0 model (http://opengameart.org/content/soldier-10) was created by killyoverdrive and released under the Creative Commons Attribution ShareAlike 3.0 Unported license.

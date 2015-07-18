#WIP12

![screenshot](https://raw.githubusercontent.com/pendingchaos/WIP12/master/screenshot.png)

A work in progress using [OpenGL](https://opengl.org) and [Bullet Physics](bulletphysics.org) in C++.

The program has only been tested on a Linux based operating system.

## Dependencies
The program requires g++, SDL2, Bullet, FreeType, libdl, a c standard library implementation, a c++ standard library implementation, and an OpenGL implementation supporting OpenGL 3.3 or higher.

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

## Running
Run resourceconverter.py to convert the textures to the format WIP12 uses, go to the directory named "bin" (in a shell) and run
```shell
./run_main.
```

## Compiling and running the lazy way
```shell
make lazy
```

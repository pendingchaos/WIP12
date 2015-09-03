compile:
	cd scripts; python2 compile.py

run_main:
	cd bin; ./run_main

run_tests:
	cd bin; ./run_tests

resource_convert:
	cd bin/programs/main; python2 resourceconverter.py

lazy:
	cd scripts; python2 compile.py
	cd bin/programs/main; python2 resourceconverter.py
	cd bin; ./run_main

install_deps:
	yum install SDL2-devel bullet-devel gcc-c++ freetype-devel
	pip2 install Pillow

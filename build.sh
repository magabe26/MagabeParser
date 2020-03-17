 rm -r build
 mkdir build
 cd core;
 cmake -G "MinGW Makefiles" -C "../config.cmake" -B "../build/core"
 cd ../build/core
 make
 cd ../../parsers;
 cmake -G "MinGW Makefiles" -C "../config.cmake" -B "../build/parsers"
 cd ../build/parsers
 make 
 cd ../../
 cmake -G "MinGW Makefiles" -B "build"
 cd build
 make
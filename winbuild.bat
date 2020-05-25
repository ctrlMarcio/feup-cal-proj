mkdir winbuild > nul
cd winbuild

cmake ../src -G "MinGW Makefiles"
cmake --build .
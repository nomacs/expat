# expat
_for nomacs_

You will need expat to build exiv which is _required_ for building nomacs. 
Usually nomacs ships with pre-compiled exiv library for new Visual Studio versions.
So you could check first if you need to build expat at all.

## Build
1. Open CMake GUI
2. Point `where is the source` to this directory
3. Choose a build folder
4. Hit `Configure` then `Generate`
5. Uncheck `BUILD_examples` and `BUILD_tests`
6. Batch build all projects (2 failed and 8 succeeded is fine)
7. In exiv set the `expat_DIR` to your build folder

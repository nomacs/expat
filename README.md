# Building expat for nomacs

You will need expat to build exiv2 which is _required_ for building nomacs.

1. Open CMake GUI
2. Point `where is the source` to this directory
3. Choose a build folder (e.g. expat/build2017-x64)
4. Hit `Configure` then `Generate`
5. Uncheck `BUILD_examples` and `BUILD_tests`
6. Batch build all projects (2 failed and 8 succeeded is fine)
7. In the `CMakeUserPaths.cmake` of your [exiv2](https://github.com/nomacs/exiv2) project, add these paths:

```cmake
SET(EXPAT_INCLUDE_DIR "$EXPAT_PATH$/lib")
SET(EXPAT_BUILD_PATH "$EXPAT_BUILD_PATH$")
```
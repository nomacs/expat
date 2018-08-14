# Building expat for nomacs

You will need expat to build exiv2 which is _required_ for building nomacs.

- Open CMake GUI
- Point `where is the source` to this directory
- Choose a build folder (e.g. expat/build2017-x64)
- Hit `Configure` then `Generate`
- Uncheck `BUILD_examples` and `BUILD_tests`
- Batch build all projects (2 failed and 8 succeeded is fine)
- You should now have an `expat.dll` in $YOUR_EXPAT_BUILD_PATH$/Release
- In the `CMakeUserPaths.cmake` of your [exiv2](https://github.com/nomacs/exiv2) project, add these paths:

```cmake
SET(EXPAT_INCLUDE_DIR "$EXPAT_PATH$/lib")
SET(EXPAT_BUILD_PATH "$EXPAT_BUILD_PATH$")
```
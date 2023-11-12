# Usage:
# cmake -B build -G Ninja -D CMAKE_TOOLCHAIN_FILE=./cmake/x86_64-windows-mingw.cmake
# cmake --build build

SET(CMAKE_SYSTEM_NAME Windows)
SET(CMAKE_SYSTEM_PROCESSOR x86_64)
SET(CMAKE_C_COMPILER "/usr/local/llvm-mingw/bin/x86_64-w64-mingw32-clang")
SET(CMAKE_C_COMPILER_TARGET x86_64-w64-windows-gnu)

set_property(TARGET ${BUILD_TARGET} APPEND_STRING PROPERTY LINK_FLAGS " -fuse-ld=/usr/bin/ld.lld")

# Usage:
# cmake -B build -G Ninja -D CMAKE_TOOLCHAIN_FILE=./cmake/aarch64-linux-clang.cmake
# cmake --build build

SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_PROCESSOR aarch64)
SET(CMAKE_C_COMPILER "/usr/bin/clang")
SET(CMAKE_C_COMPILER_TARGET aarch64-linux-gnu)

set_property(TARGET ${BUILD_TARGET} APPEND_STRING PROPERTY LINK_FLAGS " -fuse-ld=/usr/bin/ld.lld")

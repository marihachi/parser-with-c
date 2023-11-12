# Parser with C
Experimental parser with C.

## ツール
- CMake
- Ninja
- Clang or llvm-mingw(for Windows binary)
- lld

## デバッグツール
- lldb
- lldb-mi

## コンパイル (コマンド)
Compile a Linux binary:
```sh
cmake -B build -G Ninja -D CMAKE_TOOLCHAIN_FILE=./cmake/x86_64-linux-clang.cmake
cmake --build build
```

Compile a Windows binary on Linux:
```sh
cmake -B build -G Ninja -D CMAKE_TOOLCHAIN_FILE=./cmake/x86_64-windows-mingw.cmake
cmake --build build
```

## License
MIT License

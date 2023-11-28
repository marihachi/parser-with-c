# Parser with C
Experimental parser with C.

## ツール
- CMake
- Ninja
- Clang
- lld

## デバッグツール
- lldb
- lldb-mi

## ビルド (Linux)
```sh
cmake -B build -G Ninja -D CMAKE_TOOLCHAIN_FILE=./cmake/x86_64-linux-clang.cmake
cmake --build build
```

## ビルド (Windowsバイナリのクロスコンパイル)
Clangの代わりにllvm-mingwを導入するとLinux上でWindowsバイナリをビルドできます。
```sh
cmake -B build -G Ninja -D CMAKE_TOOLCHAIN_FILE=./cmake/x86_64-windows-mingw.cmake
cmake --build build
```

## License
MIT License

# Parser with C
Experimental parser with C.

## ビルド (Linux)
**ツールチェーン**
- CMake
- Ninja
- Clang
- lld

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

## デバッグツール
- lldb
- lldb-mi

## License
MIT License

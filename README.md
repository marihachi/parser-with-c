# Parser with C
Experimental parser with C.

## vscode拡張
- ms-vscode.cpptools
- ms-vscode.cmake-tools

## コンパイル (vscode拡張)
GUIでやっていってください  
vscode拡張の機能でプロジェクトにkitを定義できる`.vscode/cmake-kits.json`  
コンパイラが認識されない場合などに使えそう

## コンパイル (コマンド)
Compile with the Make, default compiler:
```sh
cmake -S src -B build
cmake --build build
```

Compile with the Ninja, specified compiler:
```sh
cmake -S src -B build -G Ninja -D CMAKE_C_COMPILER=clang
cmake --build build
```

Cross-compile with llvm-mingw(Windows):
```sh
cmake -S src -B build -G Ninja -D CMAKE_C_COMPILER=x86_64-w64-mingw32-clang
cmake --build build
```

## License
MIT License

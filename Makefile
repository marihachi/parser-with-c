build: bin obj bin/parser

# executable

bin/parser: obj/main.o obj/parser.o obj/scanner.o obj/node.o
	clang -o bin/parser obj/parser.o obj/main.o obj/scanner.o obj/node.o

# objects

obj/main.o: src/main.c
	clang -c -o obj/main.o src/main.c

obj/parser.o: src/parser.c
	clang -c -o obj/parser.o src/parser.c

obj/scanner.o: src/scanner.c
	clang -c -o obj/scanner.o src/scanner.c

obj/node.o: src/node.c
	clang -c -o obj/node.o src/node.c

# directories

bin:
	mkdir bin

obj:
	mkdir obj

build: bin/parser

# executable

bin/parser: bin obj/main.o obj/node.o
	clang -o bin/parser obj/main.o obj/node.o

# objects

obj/main.o: obj src/main.c
	clang -c -o obj/main.o src/main.c

obj/node.o: obj src/node.c
	clang -c -o obj/node.o src/node.c

# directories

bin:
	mkdir bin

obj:
	mkdir obj

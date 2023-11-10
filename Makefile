build: bin/parser

# executable

bin/parser: bin obj/main.o obj/node.o obj/iter.o
	clang -o bin/parser obj/main.o obj/node.o obj/iter.o

# objects

obj/main.o: obj src/main.c
	clang -c -o obj/main.o src/main.c

obj/node.o: obj src/node.c
	clang -c -o obj/node.o src/node.c

obj/iter.o: obj src/iter.c
	clang -c -o obj/iter.o src/iter.c

# directories

bin:
	mkdir bin

obj:
	mkdir obj

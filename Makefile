tools: ./build/stack.o

./build/stack.o: ./tools/stack.h ./tools/stack.c
	gcc -c ./tools/stack.c -o $@

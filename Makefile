tools: ./build/stack.o

objs: ./build/backtracker.o

MazeGen: tools objs

./build/stack.o: ./tools/stack.h ./tools/stack.c
	gcc -c ./tools/stack.c -o $@

./build/backtracker.o: ./include/backtracker.h ./src/backtracker.c
	gcc -c ./src/backtracker.c -o $@

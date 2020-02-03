
tools = ./build/stack.o ./build/fileHandler.o

objs = ./build/main.o ./build/backtracker.o

MazeGen: $(objs) $(tools) 
	gcc $^ -Wall -o MazeGen

./build/stack.o: ./tools/stack.h ./tools/stack.c
	gcc -c ./tools/stack.c -o $@

./build/main.o: ./src/main.c
	gcc -c ./src/main.c -o $@

./build/fileHandler.o: ./tools/fileHandler.h ./tools/fileHandler.c
	gcc -c ./tools/fileHandler.c -o $@

./build/backtracker.o: ./include/backtracker.h ./src/backtracker.c
	gcc -c ./src/backtracker.c -o $@

clean:
	rm ./build/*.o

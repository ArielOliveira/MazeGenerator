
tools = ./build/fileHandler.o

objs = ./build/main.o ./build/backtracker.o ./build/stack.o ./build/drawer.o

MazeGen: $(objs) $(tools) 
	gcc $^ -Wall -o MazeGen -g

./build/main.o: ./src/main.c
	gcc -c ./src/main.c -o $@

./build/stack.o: ./src/stack.c ./include/stack.h
	gcc -c ./src/stack.c -o $@

./build/fileHandler.o: ./tools/fileHandler.c ./tools/fileHandler.h
	gcc -c ./tools/fileHandler.c -o $@

./build/backtracker.o: ./src/backtracker.c ./include/backtracker.h
	gcc -c ./src/backtracker.c -o $@

./build/drawer.o: ./src/drawer.c ./include/drawer.h
	gcc -c ./src/drawer.c -o $@

clean:
	rm ./build/*.o

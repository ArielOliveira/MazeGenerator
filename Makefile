
tools = ./build/fileHandler.o

objs = ./build/main.o ./build/backtracker.o ./build/stack.o

MazeGen: $(objs) $(tools) 
	gcc $^ -Wall -o MazeGen -g

./build/stack.o: ./include/stack.h ./src/stack.c
	gcc -c ./src/stack.c -o $@

./build/main.o: ./src/main.c ./include/backtracker.h
	gcc -c ./src/main.c -o $@

./build/fileHandler.o: ./tools/fileHandler.h ./tools/fileHandler.c
	gcc -c ./tools/fileHandler.c -o $@

./build/backtracker.o: ./include/backtracker.h ./src/backtracker.c
	gcc -c ./src/backtracker.c -o $@

clean:
	rm ./build/*.o

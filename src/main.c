#include <stdio.h>
#include <stdlib.h>

#include "../tools/fileHandler.h"
#include "../include/backtracker.h"
#include "../include/stack.h"
#include "../include/drawer.h"

int main(int argc, char **argv) {
	if (argc >= 2) 	MAP_SIZE = atoi(argv[1]);
	else MAP_SIZE = 32;

	if (argc >= 3)	CELL_SIZE = atoi(argv[2]);	
	else CELL_SIZE = 32;
	

	Cell **map = (Cell**)malloc(sizeof(Cell*) * MAP_SIZE);
	int i;
	for (i = 0; i < MAP_SIZE; i++) {
		map[i] = (Cell*)malloc(sizeof(Cell) * MAP_SIZE);
	}

	create_map(map);

	int **pixel_map = get_pixel_map(map);
	int pixel_map_size = MAP_SIZE*CELL_SIZE;
	char *arquivo = (char*)malloc(sizeof(char) * 10);
	arquivo = "map.ppm";

	createFile(pixel_map_size, pixel_map_size, arquivo);
	saveImage(pixel_map_size, pixel_map_size, pixel_map, arquivo);

	return 0;
}

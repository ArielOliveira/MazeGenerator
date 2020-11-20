#include <stdlib.h>
#include "../include/drawer.h"

int** get_pixel_map(Cell** cell) {
	int pixel_map_size = MAP_SIZE*CELL_SIZE;
	int** pixel_map	= (int**)malloc(sizeof(int*) * pixel_map_size);
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < pixel_map_size; i++) {
		pixel_map[i] = (int*)malloc(sizeof(int) * pixel_map_size);
	}

	int l = 0, m = 0, n = 0;
	for (i = 0; i < MAP_SIZE; i++) {
		m++;
		for (j = 0; j < MAP_SIZE; j++) {
			n++;
			if (n > MAP_SIZE) n = 1;
			for (k = (CELL_SIZE*i); k < CELL_SIZE*m; k++) {
				for (l = (CELL_SIZE*j); l < CELL_SIZE*n; l++) {
					pixel_map[k][l] = cell[i][j].status;
				}
			}
		}
	}
	return pixel_map;
}

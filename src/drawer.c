#include "../include/drawer.h"



int **draw(Cell **cell) {
	int pixel_map_size = ((MAP_SIZE*MAP_SIZE)*CELL_SIZE);
	int **pixel_map	= (int**)malloc(sizeof(int*) * pixel_map_size);
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < pixel_map_size; i++) {
		pixel_map[i] = (int*)malloc(sizeof(int) * pixel_map_size);
	}
	int l = 0;
        int m = 0;
	int n = 0;
	for (i = 0; i < map_size; i++) {
		for (j = 0; j < map_size; j++) {
			for (k = 0; k < CELL_SIZE; k++) {
				for (l = 0; l < CELL_SIZE; l++) {
					pixel_map[m][n] = cell[i][j].status;
					m++;		
				}
				n++;
			}
		}
	}
}

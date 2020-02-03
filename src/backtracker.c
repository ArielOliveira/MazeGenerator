#include "../include/backtracker.h"
#include "../tools/stack.h"
#include <stdlib.h>
#include <time.h>

int randomizeInt(int max) {
	int randomN;
	randomN = ((int)rand()/(int)(RAND_MAX) * max);
	return randomN;
}

void carve(int **map, int x, int y) {
	int i, j;
	for (i = x; i < x+CELL_SIZE-1; i++) {
	       for (j = y; j < y+CELL_SIZE-1; j++) {
		       map[i][j] = 1;
	       }	       
	}

}

void create_map(int **map) {
	if (!map) {
		exit(1);
	} else {
		srand(time(NULL));
		int i,j;
		for (i = 0; i < MAP_SIZE; i++) {
			for (j = 0; j < MAP_SIZE; j++) {
				map[i][j] = 0;
			}
		}

		int first_x = randomizeInt(MAP_SIZE-1);
		int first_y = randomizeInt(MAP_SIZE-1);

		push(first_x, first_y);
		carve(map, first_x, first_y);
	}
}


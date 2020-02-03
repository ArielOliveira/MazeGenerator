#include "../include/backtracker.h"
#include "../tools/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
       	UNVISITED,
	VISITED,
} Status;	

int randomizeInt(int max) {
	int randomN = 0;
	while(!randomN) randomN = rand() % max;
	return randomN;
}

void carve_cell(int **map, int x, int y) {
	int i, j;
	int nextCellX = x*CELL_SIZE;
	int nextCellY = y*CELL_SIZE;
	for (i = nextCellX-CELL_SIZE; i < nextCellX-1; i++) {
	       for (j = nextCellY-CELL_SIZE; j < nextCellY-1; j++) {
		       map[i][j] = VISITED;
	       }	       
	}
}

void sort_cell(int **map, int x, int y) {
	int limX = x*(CELL_SIZE)-1;
	int limY = y*(CELL_SIZE)-1;
	if (map[limX][limY] == VISITED) {}
}

void generate() {
	while (!isEmpty()) {
		
	}
}

void create_map(int **map) {
	srand(time(NULL));
	if (!map) {
		exit(1);
	} else {
		int i,j;
		for (i = 0; i < MAP_SIZE; i++) {
			for (j = 0; j < MAP_SIZE; j++) {
				map[i][j] = UNVISITED;
			}
		}

		int first_x = randomizeInt(MAP_SIZE/CELL_SIZE);
		int first_y = randomizeInt(MAP_SIZE/CELL_SIZE);

		printf("/n %i %i/n", first_x, first_y); 

		push(first_x, first_y);
		carve_cell(map, first_x, first_y);
	}
}


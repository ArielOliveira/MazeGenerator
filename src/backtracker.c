#include "../include/backtracker.h"
#include "../include/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomizeInt(int max) {
	int randomN = 0;
	randomN = rand() % max;
	return randomN;
}

void carve_cell(int **map, Cell cell) {
	int i, j;
	cell.x *= CELL_SIZE;
	cell.y *= CELL_SIZE;
	printf("%i %i", cell.x, cell.y);
	for (i = cell.x-CELL_SIZE; i < cell.x-1; i++) {
	       for (j = cell.y-CELL_SIZE; j < cell.y-1; j++) {
		       map[i][j] = VISITED;
	       }	       
	}
}

void free_cell(Cell *cell_list) {
	int value = cell_list->array;
	for (value; value >= 0; value--) {
		Cell *temp = cell_list;
		cell_list = cell_list->next;
		free(temp);
	}
}

Cell* sort_cell(int **map, int x, int y) {
	int i = 0;
	
	Cell nav[4];
	nav[0].x = ((x+2)*CELL_SIZE);
	nav[0].y = (y*CELL_SIZE);

	nav[1].x = ((x-2)*CELL_SIZE);
	nav[1].y = (y*CELL_SIZE);

	nav[2].x = (x*CELL_SIZE);
	nav[2].y = ((y+2)*CELL_SIZE);

	nav[3].x = (x*CELL_SIZE);
	nav[3].y = ((y-2)*CELL_SIZE);
	printf(" %i %i ", x, y);

	Cell *valid_nav = (Cell*)malloc(sizeof(Cell));
	valid_nav->array = 0;
	for (i = 0; i < 4; i++) {
		printf(" ======########%i %i======####### ", nav[i].x, nav[i].y);
		if ((nav[i].x > 16 && nav[i].y > 16) &&
			       	(nav[i].x < MAP_SIZE-16 && nav[i].y < MAP_SIZE-16)) {
			if (map[nav[i].x][nav[i].y] == UNVISITED) {
				Cell *new_valid = (Cell*)malloc(sizeof(Cell));
				new_valid->x = nav[i].x/CELL_SIZE;
				new_valid->y = nav[i].y/CELL_SIZE;
				new_valid->array = valid_nav->array+1;
				new_valid->next = valid_nav;
				valid_nav = new_valid;
			}
		}	
	}

	if (valid_nav->next) {
		int value = randomizeInt(valid_nav->array)+1;
		Cell *temp;
		for (value; value > 0; value--) {
			temp = valid_nav;
			valid_nav = valid_nav->next;
			free(temp);
		}
	} else {
		return NULL;
	}
	return valid_nav;
}

void generate(int **map) {
	int count = 0;
	Cell *cell;
	while (!isEmpty() && count < 8) {
		cell = sort_cell(map, top().x, top().y);
		if (cell) {
			//carve_cell(map, *cell);
			push(cell);
		} else {
			pop();
		}
		count++;
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
		Cell *first_cell = (Cell*)malloc(sizeof(Cell));

		int max = MAP_SIZE/CELL_SIZE;
		
		first_cell->x = rand()%(max-1);
		first_cell->y = rand()%(max-1);

		push(first_cell);
		
		carve_cell(map, *first_cell);
		//generate(map);
		
	}
}


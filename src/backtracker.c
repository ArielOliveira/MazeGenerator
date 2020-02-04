#include "../include/backtracker.h"
#include "../tools/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
       	UNVISITED,
	VISITED,
} Status;

typedef struct Node {
	int x;
	int y;
	int array;
	struct Node *next;	
} Cell;

int randomizeInt(int max) {
	int randomN = 0;
	randomN = rand() % max;
	return randomN;
}

void carve_cell(int **map, Cell cell) {
	int i, j;
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
	
	Cell direction_list[4];
	Cell nav[4];
	nav[0].x = ((x+1)*CELL_SIZE);
	nav[0].y = (y*CELL_SIZE);

	nav[1].x = ((x-1)*CELL_SIZE);
	nav[1].y = (y*CELL_SIZE);

	nav[2].x = (x*CELL_SIZE);
	nav[2].y = ((y+1)*CELL_SIZE);

	nav[3].x = (x*CELL_SIZE);
	nav[3].y = ((y-1)*CELL_SIZE);
	

	Cell *valid_nav = (Cell*)malloc(sizeof(Cell));
	valid_nav->array = 0;
	for (i = 0; i < 4; i++) {
		if (nav[i].x > 1 && nav[i].y > 1 
		 	&& (nav[i].x < MAP_SIZE && nav[i].y < MAP_SIZE)) {
			if (map[nav[i].x-1][nav[i].y-1] == UNVISITED) {
				Cell *new_valid = (Cell*)malloc(sizeof(Cell));
				new_valid->x = nav[i].x;
				new_valid->y = nav[i].y;
				new_valid->array = valid_nav->array+1;
				new_valid->next = valid_nav;
				valid_nav = new_valid;
			}
		}	
	}

	printf(" %i ", valid_nav->array);

	if (valid_nav->next) {
		int value = randomizeInt(valid_nav->array);
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
	while (count < 32) {
		cell = sort_cell(map, top().x, top().y);
		if (cell) {
			carve_cell(map, *cell);
		//	printf("  %i %i  ", cell->x, cell->y);
		//	push(cell->x, cell->y);
		//	free_cell(cell);
		} else {
		//	pop();
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


		first_cell->x = randomizeInt(MAP_SIZE/CELL_SIZE);
		first_cell->y = randomizeInt(MAP_SIZE/CELL_SIZE);

		push(first_cell->x, first_cell->y);
		
		first_cell->x = first_cell->x*CELL_SIZE;
		first_cell->y = first_cell->y*CELL_SIZE;
		carve_cell(map, *first_cell);
		
		free(first_cell);
		generate(map);
		
	}
}


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
	for (i = cell.x-CELL_SIZE; i < cell.x-1; i++) {
	       for (j = cell.y-CELL_SIZE; j < cell.y-1; j++) {
		       map[i][j] = VISITED;
	       }	       
	}
}

Cell sort_cell(int **map, int x, int y) {
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


	

	Cell *valid_nav_list = (Cell*)malloc(sizeof(Cell));
	valid_nav_list->next = NULL;
	Cell valid_nav;
	valid_nav.array = 0;
	valid_nav_list->array = 0;
	int j = 0;
	for (i = 0; i < 4; i++) {
		printf(" Possible Candidates ");
		printf(" %i %i ", nav[i].x, nav[i].y);
		getchar();
		if ((nav[i].x > CELL_SIZE && nav[i].y > CELL_SIZE) &&
			       	(nav[i].x < MAP_SIZE-CELL_SIZE && nav[i].y < MAP_SIZE-CELL_SIZE)) {
			if (map[nav[i].x][nav[i].y] == UNVISITED) {

				printf(" Valid Candidates ");
				printf(" %i %i ", nav[i].x, nav[i].y);
				getchar();
				Cell *new_valid = (Cell*)malloc(sizeof(Cell));
				new_valid->x = nav[i].x/CELL_SIZE;
				new_valid->y = nav[i].y/CELL_SIZE;
				new_valid->array = ++j;
				new_valid->next = valid_nav_list;
				valid_nav_list = new_valid;
			}
		}	
	}
	printf("Possible valid navs: %i for %i %i pos", valid_nav_list->array, x, y);
	getchar();
	if (valid_nav_list->next != NULL) {
		int value = randomizeInt(valid_nav_list->array)+1;
		Cell *temp;
		int i = valid_nav_list->array;
		for (i; i >= value ; i--) {
			temp = valid_nav_list->next;
		}

		valid_nav.x = temp->x;
		valid_nav.y = temp->y;
		valid_nav.array = temp->array;
		valid_nav.next = NULL;

		while (valid_nav_list->next != NULL) {
			temp = valid_nav_list;
			valid_nav_list = valid_nav_list->next;
			free(temp);
		}
	} else {
		free(valid_nav_list);
	}
	return valid_nav;
}

void generate(int **map) {
	int count = 0;
	Cell cell;
	while (!isEmpty()) {
		cell = sort_cell(map, top().x, top().y);
		if (cell.array > 0) {
			carve_cell(map, cell);
			push(&cell);
		} else {
			printf(" popping something ");
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
		
		first_cell->x = (rand()+1)%(max-1);
		first_cell->y = (rand()+1)%(max-1);

		push(first_cell);
		
		carve_cell(map, top());
		generate(map);
		
	}
}


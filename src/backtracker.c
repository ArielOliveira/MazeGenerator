#include "../include/backtracker.h"
#include "../include/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define get_name(var) #var

int randomizeInt(int max) {
	int randomN = 0;
	randomN = rand() % max;
	return randomN;
}

void carve_wall(int **map, Cell cell) {
	int wall_x = 0;
	int wall_y = 0;

	switch(cell.path) {
		case NORTH: wall_x = cell.x;
			    wall_y = cell.y+1;
		     	break;
		case SOUTH: wall_x = cell.x;
			    wall_y = cell.y-1;
			break;
		case EAST:  wall_x = cell.x-1;
			    wall_y = cell.y;
			break;
		case WEST:  wall_x = cell.x+1;
			    wall_y = cell.y;
			break;
	}
	//printf(" cell %i %i cell_pos %i %i ", cell.x, cell.y, cell.x*CELL_SIZE, cell.y*CELL_SIZE);
	//getchar();

	wall_x *= CELL_SIZE;
	wall_y *= CELL_SIZE;

	int i = 0;
       	int j = 0;
	//printf("wall from %i %i to %i %i cell number %i %i wall side %i", wall_x-CELL_SIZE, wall_y-CELL_SIZE, wall_x, wall_y, wall_x/CELL_SIZE, wall_y/CELL_SIZE, cell.path);
	//getchar();
	for (i = wall_x-CELL_SIZE; i < wall_x; i++) {
		for (j = wall_y-CELL_SIZE; j < wall_y; j++) {
			map[i][j] = VISITED;
		}
	}
}

void carve_cell(int **map, Cell cell) {
	int i=0, j=0;
	cell.x *= CELL_SIZE;
	cell.y *= CELL_SIZE;
	for (i = cell.x-CELL_SIZE; i < cell.x; i++) {
	       for (j = cell.y-CELL_SIZE; j < cell.y; j++) {
		       map[i][j] = VISITED;
	       }	       
	}
}

Cell sort_cell(int **map, int x, int y) {
	Cell nav[4];

	nav[0].x = ((x+2)*CELL_SIZE);
	nav[0].y = (y*CELL_SIZE);
	nav[0].path = EAST;

	nav[1].x = ((x-2)*CELL_SIZE);
	nav[1].y = (y*CELL_SIZE);
	nav[1].path = WEST;

	nav[2].x = (x*CELL_SIZE);
	nav[2].y = ((y+2)*CELL_SIZE);
	nav[2].path = SOUTH;

	nav[3].x = (x*CELL_SIZE);
	nav[3].y = ((y-2)*CELL_SIZE);
	nav[3].path = NORTH;

	Cell *valid_nav_list = (Cell*)malloc(sizeof(Cell));
	valid_nav_list->next = NULL;
	Cell valid_nav;
	valid_nav.array = 0;
	valid_nav_list->array = 0;

	int i = 0;
	for (i = 0; i < 4; i++) {
		if ((nav[i].x > CELL_SIZE && nav[i].y > CELL_SIZE) &&
			       	(nav[i].x < MAP_SIZE-CELL_SIZE && nav[i].y < MAP_SIZE-CELL_SIZE)) {
			if (map[nav[i].x-CELL_SIZE][nav[i].y-CELL_SIZE] == UNVISITED) {
				Cell *new_valid = (Cell*)malloc(sizeof(Cell));
				new_valid->x = nav[i].x/CELL_SIZE;
				new_valid->y = nav[i].y/CELL_SIZE;
				new_valid->path = nav[i].path;
				new_valid->array = valid_nav_list->array+1;
				new_valid->next = valid_nav_list;
				valid_nav_list = new_valid;
			}
		}	
	}
	if (valid_nav_list->next != NULL) {
		Cell *temp;
		if (valid_nav_list->array > 1) {
			int value = randomizeInt(valid_nav_list->array)+1;
			int i = valid_nav_list->array;
			for (i; i >= value ; i--) {
				temp = valid_nav_list->next;
			}
		} else {
			temp = valid_nav_list;
		}

		valid_nav.x = temp->x;
		valid_nav.y = temp->y;
		valid_nav.array = temp->array;
		valid_nav.path = temp->path;
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
			carve_wall(map, cell);
			push(&cell);
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
		do {
			first_cell->x = ((rand()+1)%(max-1));
			first_cell->y = ((rand()+1)%(max-1));
		} while ((first_cell->x < CELL_SIZE && first_cell->y < CELL_SIZE) 
				&& (first_cell->x > MAP_SIZE-CELL_SIZE 
					&& first_cell->y > MAP_SIZE-CELL_SIZE));
		push(first_cell);
		
		carve_cell(map, top());
		generate(map);
		
	}
}


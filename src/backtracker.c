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

void carve_cell(Cell **map, Cell cell) {
	map[cell.x][cell.y].status = VISITED;
	map[cell.x][cell.y].path = cell.path;
	map[cell.x][cell.y].display = ' ';
	switch(cell.path) {
		case NORTH: map[cell.x][cell.y].bot_wall = 0;
			    map[cell.x][cell.y+1].status = VISITED;
			    map[cell.x][cell.y+1].path = NORTH;
			    map[cell.x][cell.y+1].top_wall = 0;
			    map[cell.x][cell.y+1].display = ' ';
			break;
		case SOUTH: map[cell.x][cell.y].top_wall = 0;
			    map[cell.x][cell.y-1].status = VISITED;
			    map[cell.x][cell.y-1].path = SOUTH;
			    map[cell.x][cell.y-1].bot_wall = 0;
			    map[cell.x][cell.y-1].display = ' ';
			break;
		case EAST:  map[cell.x][cell.y].left_wall = 0;
			    map[cell.x-1][cell.y].status = VISITED;
			    map[cell.x-1][cell.y].path = EAST;
			    map[cell.x-1][cell.y].right_wall = 0;
			    map[cell.x-1][cell.y].display = ' ';
			break;
		case WEST:  map[cell.x][cell.y].right_wall = 0;
			    map[cell.x+1][cell.y].status = VISITED;
			    map[cell.x+1][cell.y].path = WEST;
			    map[cell.x+1][cell.y].left_wall = 0;
			    map[cell.x+1][cell.y].display = ' ';
			break;
	}
}

Cell sort_cell(Cell **map, int x, int y) {

	Cell *valid_nav_list = (Cell*)malloc(sizeof(Cell));
	valid_nav_list->next = NULL;
	valid_nav_list->array = 0;

	Cell valid_nav;
	valid_nav.array = 0;
	if (x+2 < MAP_SIZE) {
		if ((map[x+2][y].status == UNVISITED) 
				&& (map[x][y].right_wall == 1)
				&& (map[x+2][y].left_wall == 1)) {
			Cell nav;
			nav.x = x+2;
			nav.y = y;
			nav.path = EAST;

			Cell *new_valid = (Cell*)malloc(sizeof(Cell));
			new_valid->x = nav.x;
			new_valid->y = nav.y;
			new_valid->path = nav.path;
			new_valid->array = valid_nav_list->array+1;
			new_valid->next = valid_nav_list;
			valid_nav_list = new_valid;
		}
	}
	if (x-2 > MAP_SIZE) {
		if ((map[x-2][y].status == UNVISITED)
				&& (map[x][y].left_wall == 1)
				&& (map[x-2][y].right_wall == 1)) {
			Cell nav;
			nav.x = x-2;
			nav.y = y;
			nav.path = WEST;

			Cell *new_valid = (Cell*)malloc(sizeof(Cell));
			new_valid->x = nav.x;
			new_valid->y = nav.y;
			new_valid->path = nav.path;
			new_valid->array = valid_nav_list->array+1;
			new_valid->next = valid_nav_list;
			valid_nav_list = new_valid;
		}
	}
	if (y+2 < MAP_SIZE) {
		if ((map[x][y+2].status == UNVISITED)
				&& (map[x][y].bot_wall == 1)
				&& (map[x][y+2].top_wall == 1)) {
		
			Cell nav;
			nav.x = x;
			nav.y = y+2;
			nav.path = SOUTH;

			Cell *new_valid = (Cell*)malloc(sizeof(Cell));
			new_valid->x = nav.x;
			new_valid->y = nav.y;
			new_valid->path = nav.path;
			new_valid->array = valid_nav_list->array+1;
			new_valid->next = valid_nav_list;
			valid_nav_list = new_valid;
		}

	}
	if (y-2 > MAP_SIZE) {
		if ((map[x][y-2].status == UNVISITED)
				&& (map[x][y].top_wall == 1)
				&& (map[x][y-2].bot_wall == 1)) {
			Cell nav;
			nav.x = x;
			nav.y = y-2;
			nav.path = NORTH;

			Cell *new_valid = (Cell*)malloc(sizeof(Cell));
			new_valid->x = nav.x;
			new_valid->y = nav.y;
			new_valid->path = nav.path;
			new_valid->array = valid_nav_list->array+1;
			new_valid->next = valid_nav_list;
			valid_nav_list = new_valid;
		}
	}
	printf("valid navs %i ", valid_nav_list->array);
	getchar();

	int i = 0;
	for (i = valid_nav_list->array; i >= 0; i--) {
		Cell *temp;
		temp = valid_nav_list->next;
		printf("testing nav list %i %i", temp->array, temp->path);
		getchar();
		
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

void generate(Cell **map) {
	int count = 0;
	Cell cell;
	while (!isEmpty()) {
		cell = sort_cell(map, top().x, top().y);
		if (cell.array > 0) {
			carve_cell(map, cell);
			push(&cell);
		} else {
			pop();
		}
		count++;
	}
}

void create_map(Cell **map) {
	srand(time(NULL));
	if (!map) {
		exit(1);
	} else {
		int i,j;
		for (i = 0; i < MAP_SIZE; i++) {
			for (j = 0; j < MAP_SIZE; j++) {
				map[i][j].x = i;
				map[i][j].y = j;
				map[i][j].array = i;
				map[i][j].status = UNVISITED;
				map[i][j].top_wall = 1;
				map[i][j].bot_wall = 1;
				map[i][j].left_wall = 1;
				map[i][j].right_wall = 1;
				map[i][j].path = -1;
				map[i][j].next = NULL;
				map[i][j].display = '*';
			}
		}

		for (i = 1; i < MAP_SIZE-1; i++) {
			for (j = 1; j < MAP_SIZE-1; j++) {
				map[i][1].top_wall = 0;
				map[MAP_SIZE-2][j].bot_wall = 0;
				map[i][1].left_wall = 0;
				map[i][MAP_SIZE-2].right_wall = 0;
			}
		}
		Cell *first_cell = (Cell*)malloc(sizeof(Cell));

		do {
			first_cell->x = ((rand())%(MAP_SIZE));
			first_cell->y = ((rand())%(MAP_SIZE));
		}	while((first_cell->x <= 1) && (first_cell->y <= 1));
		push(first_cell);

		carve_cell(map, top());
		generate(map);
		
	}
}


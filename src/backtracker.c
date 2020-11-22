#include "../include/backtracker.h"
#include "../include/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define get_name(var) #var

int randomizeInt(int max) {
	int randomN = 0;
	randomN = rand() % max;
	return randomN;
}

void carve_cell(Cell **map, Cell cell) {
	map[cell.y][cell.x].status = VISITED;
	map[cell.y][cell.x].display = ' ';
	switch(cell.path) {
		case NORTH: map[cell.y][cell.x].bot_wall = 0;
			    map[cell.y+1][cell.x].status = VISITED;
			    map[cell.y+1][cell.x].top_wall = 0;
			    map[cell.y+1][cell.x].display = ' ';
			break;
		case SOUTH: map[cell.y][cell.x].top_wall = 0;
			    map[cell.y-1][cell.x].status = VISITED;
			    map[cell.y-1][cell.x].bot_wall = 0;
			    map[cell.y-1][cell.x].display = ' ';
			break;
		case EAST:  map[cell.y][cell.x].left_wall = 0;
			    map[cell.y][cell.x-1].status = VISITED;
			    map[cell.y][cell.x-1].path = EAST;
			    map[cell.y][cell.x-1].right_wall = 0;
			    map[cell.y][cell.x-1].display = ' ';
			break;
		case WEST:  map[cell.y][cell.x].right_wall = 0;
			    map[cell.y][cell.x+1].status = VISITED;
			    map[cell.y][cell.x+1].path = WEST;
			    map[cell.y][cell.x+1].left_wall = 0;
			    map[cell.y][cell.x+1].display = ' ';
			break;
		default:
			break;
	}
}

Cell sort_cell(Cell **map, int x, int y) {
	Cell valid_nav;
	valid_nav.array = 0;
	int there_is_a_way = 0;
	int random_nav;
	do {
	random_nav = (rand()%4)+1;
		if (x+2 < MAP_SIZE-1) {
			if ((map[y][x+2].status == UNVISITED) 
					&& (map[y][x].right_wall == 1)
					&& (map[y][x+2].left_wall == 1)) {
				if (random_nav == 1) {
					valid_nav.x = x+2;
					valid_nav.y = y;
					valid_nav.path = EAST;
					valid_nav.array = random_nav;
				}
				there_is_a_way = 1;
			}
		}
		if (x-2 > 0) {
			if ((map[y][x-2].status == UNVISITED)
					&& (map[y][x].left_wall == 1)
					&& (map[y][x-2].right_wall == 1)) {
				if (random_nav == 2) {
					valid_nav.x = x-2;
					valid_nav.y = y;
					valid_nav.path = WEST;
					valid_nav.array = random_nav;
				}
				there_is_a_way = 1;
			}
		}
		if (y+2 < MAP_SIZE-1) {
			if ((map[y+2][x].status == UNVISITED)
					&& (map[y][x].bot_wall == 1)
					&& (map[y+2][x].top_wall == 1)) {
				if (random_nav == 3) {
					valid_nav.x = x;
					valid_nav.y = y+2;
					valid_nav.path = SOUTH;
					valid_nav.array = random_nav;
				}
				there_is_a_way = 1;
			}

		}
		if (y-2 > 0) {
			if ((map[y-2][x].status == UNVISITED)
					&& (map[y][x].top_wall == 1)
					&& (map[y-2][x].bot_wall == 1)) {
				Cell nav;
				if (random_nav == 4) {
					valid_nav.x = x;
					valid_nav.y = y-2;
					valid_nav.path = NORTH;
					valid_nav.array = random_nav;
				}
				there_is_a_way = 1;
			}
		}
	} while (there_is_a_way && (valid_nav.array == 0));
	
	if (there_is_a_way) {
		assert(valid_nav.x < MAP_SIZE-1 
			      && valid_nav.y < MAP_SIZE-1
			      && valid_nav.x > 0 
			      && valid_nav.y > 0);
	}
	return valid_nav;
}

void generate(Cell **map) {
	int count = 0;
	Cell cell;
	while (!isEmpty()) {
		cell = sort_cell(map, ((Cell*)top())->x, ((Cell*)top())->y);
		if (cell.array > 0) {
			carve_cell(map, cell);
			push(&cell, sizeof(Cell));
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

		for (i = 0; i < MAP_SIZE; i++) {
			for (j = 0; j < MAP_SIZE; j++) {
				map[i][0].right_wall = 0;
				map[i][MAP_SIZE-1].left_wall = 0;
				map[0][j].bot_wall = 0;
				map[MAP_SIZE-1][j].top_wall = 0;
			}
		}
		Cell first_cell;
		first_cell.path = -1;

		do {
			first_cell.x = ((rand())%(MAP_SIZE-2))+1;
			first_cell.y = ((rand())%(MAP_SIZE-2))+1;
		} while((first_cell.x < 1) && (first_cell.y < 1));
		assert(first_cell.x < MAP_SIZE-1 && first_cell.y < MAP_SIZE-1
			&& first_cell.x > 0 && first_cell.y > 0);
		push(&first_cell, sizeof(Cell));

		carve_cell(map, *((Cell*)top()));
		generate(map);
		
	}
}


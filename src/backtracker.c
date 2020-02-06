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
	map[cell.x][cell.y].display = ' ';
	switch(cell.path) {
		case NORTH: map[cell.x][cell.y].bot_wall = 0;
			    map[cell.x][cell.y+1].status = VISITED;
			    map[cell.x][cell.y+1].top_wall = 0;
			    map[cell.x][cell.y+1].display = ' ';
			break;
		case SOUTH: map[cell.x][cell.y].top_wall = 0;
			    map[cell.x][cell.y-1].status = VISITED;
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
		if (x+2 < MAP_SIZE) {
			if ((map[x+2][y].status == UNVISITED) 
					&& (map[x][y].right_wall == 1)
					&& (map[x+2][y].left_wall == 1)) {
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
			if ((map[x-2][y].status == UNVISITED)
					&& (map[x][y].left_wall == 1)
					&& (map[x-2][y].right_wall == 1)) {
				if (random_nav == 2) {
					valid_nav.x = x-2;
					valid_nav.y = y;
					valid_nav.path = WEST;
					valid_nav.array = random_nav;
				}
				there_is_a_way = 1;
			}
		}
		if (y+2 < MAP_SIZE) {
			if ((map[x][y+2].status == UNVISITED)
					&& (map[x][y].bot_wall == 1)
					&& (map[x][y+2].top_wall == 1)) {
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
			if ((map[x][y-2].status == UNVISITED)
					&& (map[x][y].top_wall == 1)
					&& (map[x][y-2].bot_wall == 1)) {
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
			for (j = 1; j < MAP_SIZE-2; j++) {
				map[i][0].top_wall = 0;
				map[i][MAP_SIZE-1].bot_wall = 0;
				map[0][j].left_wall = 0;
				map[MAP_SIZE-1][j].right_wall = 0;
			}
		}
		Cell *first_cell = (Cell*)malloc(sizeof(Cell));
		first_cell->path = -1;

		do {
			first_cell->x = ((rand())%(MAP_SIZE-2))+1;
			first_cell->y = ((rand())%(MAP_SIZE-2))+1;
		} while((first_cell->x < 1) && (first_cell->y < 1));
		push(first_cell);
		carve_cell(map, top());
		generate(map);
		
	}
}


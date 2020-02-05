#ifndef BACKTRACKER_H
#define BACKTRACKER_H

#define CELL_SIZE 16
#define MAP_SIZE 129

typedef enum {
       	UNVISITED,
	VISITED,
	WALL
} Status;

typedef enum {
	NORTH,
	SOUTH,
	EAST,
	WEST
} Direction;

typedef struct Node {
	int x;
	int y;
	int array;
	Direction path;
	struct Node *next;	
} Cell;


void create_map(int **map);

#endif

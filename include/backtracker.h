#ifndef BACKTRACKER_H
#define BACKTRACKER_H

#define CELL_SIZE 16
#define MAP_SIZE 5

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
	int status;
	int top_wall;
	int bot_wall;
	int left_wall;
	int right_wall;
	Direction path;
	struct Node *next;	
} Cell;


void create_map(Cell **map);

#endif

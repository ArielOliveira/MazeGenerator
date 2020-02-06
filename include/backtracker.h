#ifndef BACKTRACKER_H
#define BACKTRACKER_H

#define CELL_SIZE 32
#define MAP_SIZE 13

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
	int path;
	char display;
	int array;
	int status;
	int top_wall;
	int bot_wall;
	int left_wall;
	int right_wall;
	struct Node *next;	
} Cell;


void create_map(Cell **map);

#endif

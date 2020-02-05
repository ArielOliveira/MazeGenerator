#include "../include/stack.h"
#include <stdio.h>
#include <stdlib.h>

int isEmpty()  {
	return !root;
}

void push(Cell *new_cell) {
	Cell *another = (Cell*)malloc(sizeof(Cell));
	if (!new_cell) {
		printf("Could not allocate");
		exit(1);
	}

	*another = *new_cell;
	another->next = root;
	root = another;
}

void pop() {
	Cell *temp;

	if (!isEmpty()) {
		temp = root;
		root = root->next;
		free(temp);
	}
}

Cell top() {
	if (!isEmpty()) {
		return *root;
	}
}


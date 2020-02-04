#include "../include/stack.h"
#include <stdio.h>
#include <stdlib.h>

int isEmpty()  {
	return !root;
}

void push(Cell *new_cell) {
	if (!new_cell) {
		printf("Could not allocate");
		exit(1);
	}
	new_cell->next = root;
	root = new_cell;
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


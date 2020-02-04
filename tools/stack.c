#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int isEmpty()  {
	return !root;
}

void push(int _x, int _y) {
	Stack *newNode = (Stack*)malloc(sizeof(Stack));

	if (!newNode) {
		printf("Could not allocate");
		exit(1);
	}

	newNode->x = _x;
	newNode->y = _y;
	newNode->link = root;

	root = newNode;
}

void pop() {
	Stack *temp;

	if (!isEmpty()) {
		temp = root;
		root = root->link;
		free(temp);
	}
}

Stack top() {
	if (!isEmpty()) {
		return *root;
	}
}


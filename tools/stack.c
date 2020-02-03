#include "stack.h"

int isEmpty()  {
	return !top;
}

void push(int _x, int _y) {
	StackNode *newNode = (StackNode*)malloc(sizeof(StackNode));

	if (!newNode) {
		exit(1);
	}

	newNode->x = _x;
	newNode->y = _y;
	newNode->link = top;

	top = newNode;
}

void pop(StackNode *node) {
	StackNode *temp;

	if (!isEmpty()) {
		temp = top;
		top = top->link;
		free(temp);
	}
}

StackNode top() {
	if (!isEmpty()) {
		return *top;
	}
}


#ifndef STACK_H
#define STACK_H

typedef struct StackNode {
	int x;
	int y;
	struct StackNode *link;
} Stack;

Stack *root;

int isEmpty();

void push(int _x, int _y);

void pop();

Stack top();

#endif

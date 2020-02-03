#ifndef STACK_H
#define STACK_H

typedef struct StackNode {
	int x;
	int y;
	StackNode *link;
};

StackNode *top;

int isEmpty();

void push(int _x, int _y);

void pop(StackNode *node);

StackNode top(StackNode *node);

#endif
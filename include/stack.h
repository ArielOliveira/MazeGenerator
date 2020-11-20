#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    void* data;
    struct Stack* next;
} Element;

Element *first;

void init_stack(int elementSize);

int isEmpty();

void push(const void* data, int elementSize);

void pop();

void* top();

#endif

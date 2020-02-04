#ifndef STACK_H
#define STACK_H

#include "../include/backtracker.h"

Cell *root;

int isEmpty();

void push(Cell *new_cell);

void pop();

Cell top();

#endif

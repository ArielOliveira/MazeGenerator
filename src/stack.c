#include "../include/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isEmpty()  {
	return !first;
}

void push(const void* data, int elementSize) {
	Element *another = (Element*)malloc(sizeof(Element));
	if (!another) {
		printf("Could not allocate");
		exit(-1);
	}
	another->data = malloc(elementSize);
	memcpy(another->data, data, elementSize);
	another->next = first;
	first = another;
}

void pop() {
	Element *temp;

	if (!isEmpty()) {
		temp = first;
		first = first->next;
		free(temp);
	}
}

void* top() {
	if (!isEmpty()) {
		return first->data;
	}
}


#include <stdio.h>
#include <stdlib.h>

typedef enum{FALSE=0,TRUE=1} Boolean;
typedef enum{E,S,W,N} DIRECTION;

typedef struct {
	int size;
	int top;
	int* stack;	
}stack;

typedef struct {
    int row;
    int columns;
    DIRECTION dir;
}move;

//Create a stack
stack* createS(int size) {
	stack* s = (stack*)malloc(sizeof(stack));
	s->size = size;
	s->top = -1;
	s->stack = (int*)malloc(sizeof(int)*size);
	return s;
}

Boolean isFull(stack* s) {
	return (s->top == s->size-1)? TRUE:FALSE;
}

Boolean isEmpty(stack* s) {
	return (s->top == -1)? TRUE:FALSE;
}


int top(stack* s) {
    return (s->top >= 0) ? s->stack[s->top] : -1;
}

void push(stack* s, int e) {
	if (isFull(s)) {
		fprintf(stderr,"[Push Err] Full\n");
		return;
	}
	s->top++;
	s->stack[s->top] = e;
}

int pop(stack* s) {
	if (isEmpty(s)) {
		fprintf(stderr,"[Pop Err] Empty\n");
		return -1;
	}
	return s->stack[s->top--];
}


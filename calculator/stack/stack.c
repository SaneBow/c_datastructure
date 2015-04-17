#include <stdio.h>
#include <stdlib.h>

typedef enum{TRUE=1,FALSE=0} Boolean;
typedef struct {
	int size;
	int top;
	int* stack;	
}Stack;

//Create a Stack
Stack* createS(int size) {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->size = size;
	s->top = -1;
	s->stack = (int*)malloc(sizeof(int)*size);
	return s;
}

void deleteS(Stack *s) {
    free(s->stack);
    free(s);
}

Boolean isFull(Stack* s) {
	return (s->top == s->size-1)? TRUE:FALSE;
}

Boolean isEmpty(Stack* s) {
	return (s->top == -1)? TRUE:FALSE;
}


int top(Stack* s) {
    return s->stack[s->top] ;
}

void push(Stack* s, int e) {
	if (isFull(s)) {
		fprintf(stderr,"[Push Err] Full\n");
		return;
	}
	s->top++;
	s->stack[s->top] = e;
}

int pop(Stack* s) {
	if (isEmpty(s)) {
		fprintf(stderr,"[Pop Err] Empty\n");
        exit(1);
	}
	return s->stack[s->top--];
}


#include <stdio.h>
#include <stdlib.h>

typedef enum{TRUE=1,FALSE=0} Boolean;
typedef enum{E,S,W,N} DIRECTION;
typedef struct {
    int row;
    int col;
    DIRECTION dir;
}Move;
typedef struct {
	int size;
	int top;
	Move* stack;	
}Stack;

//Create a Stack
Stack* createS(int size) {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->size = size;
	s->top = -1;
	s->stack = (Move*)malloc(sizeof(Move)*size);
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


Move top(Stack* s) {
    return s->stack[s->top] ;
}

void push(Stack* s, Move e) {
	if (isFull(s)) {
		fprintf(stderr,"[Push Err] Full\n");
		return;
	}
	s->top++;
	s->stack[s->top] = e;
}

Move pop(Stack* s) {
	if (isEmpty(s)) {
		fprintf(stderr,"[Pop Err] Empty\n");
        exit(1);
	}
	return s->stack[s->top--];
}


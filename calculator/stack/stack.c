#include <stdio.h>
#include <stdlib.h>

typedef enum{FALSE=0,TRUE=1} Boolean;

typedef struct {
	int size;
	int top;
	int* stack;
}Stack;

//Create a stack
Stack* createS(int size) {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	s->size = size;
	s->top = -1;
	s->stack = (int*)malloc(sizeof(int)*size);
	return s;
}

/* Free memories */
void deleteS(Stack* s) {
    free(s->stack);
    free(s);
}

int stack_used(Stack* s) {
	return s->top + 1;
}

int stack_unused(Stack* s) {
	return s->size - s->top -1;
}

Boolean isFull(Stack* s) {
	return (s->top == s->size-1)? TRUE:FALSE;
}

Boolean isEmpty(Stack* s) {
	return (s->top == -1)? TRUE:FALSE;
}


int top(Stack* s) {
    return (s->top >= 0) ? s->stack[s->top] : -1;
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

//Empty a stack
void clearS(Stack* s) {
	while(!isEmpty(s)) {
		pop(s);
	}
}

//Load a int array into stack.
//The first elements of the array is at the bottom of the stack.
void loadS(Stack* s, int* elements, int length) {
	clearS(s);
	if (s->size < length) {
		fprintf(stderr,"[Load Err] Array larger than stack\n");
	}
	int i=0;
	while (i<length) {
		push(s,elements[i]);
		i++;
	}
}

//Pour one stack into another
void pourS(Stack* from,Stack* to) {
	if (stack_unused(to) < stack_used(from)) {
		fprintf(stderr,"[Pour Err] Space not enough");
		return;
	}
	while (!isEmpty(from)) {
		push(to,pop(from));
	}
}

//Return a copy of a stack
Stack* copyS(Stack* s) {
	Stack* newstack = createS(s->size);
	Stack* tmpstack = createS(s->size);
	pourS(s, tmpstack);
	while (!isEmpty(tmpstack)) {
		int e = pop(tmpstack);
		push(s,e);
		push(newstack,e);
	}
    deleteS(tmpstack);
	return newstack;
}

//Print out the graph representation of a stack
void printS(Stack* s) {
	Stack* tmp = copyS(s);
	printf("    \n");
	int i = 0;
	while (i < stack_unused(tmp)) {
		printf("|   |\n");
		i++;
	}
	while (!isEmpty(tmp)) {
		printf("|%3d|\n",pop(tmp));
	}
	printf(" ---\n");
	deleteS(tmp);
}



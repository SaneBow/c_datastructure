#ifndef DUPLICATION_GUARD
#define DUPLICATION_GUARD
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
#endif

stack* createS(int size); 
int stack_used(stack* s);
int stack_unused(stack* s);
Boolean isFull(stack* s);
Boolean isEmpty(stack* s);
int top(stack*s);
void push(stack* s, int e);
int pop(stack* s);
void clearS(stack* s);
void loadS(stack* s, int* elements, int length);
void pourS(stack* from,stack* to);
stack* copyS(stack* s);
void printS(stack* s);

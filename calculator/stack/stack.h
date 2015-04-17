#ifndef DUPLICATION_GUARD
#define DUPLICATION_GUARD
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

Stack* createS(int size); 
void deleteS(Stack* s);
int Stack_used(Stack* s);
int Stack_unused(Stack* s);
Boolean isFull(Stack* s);
Boolean isEmpty(Stack* s);
Move top(Stack*s);
void push(Stack* s, Move e);
Move pop(Stack* s);

#endif

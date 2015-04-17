#ifndef DUPLICATION_GUARD
#define DUPLICATION_GUARD
typedef enum{TRUE=1,FALSE=0} Boolean;

typedef struct {
	int size;
	int top;
	int* stack;	
}Stack;

Stack* createS(int size); 
void deleteS(Stack* s);
int Stack_used(Stack* s);
int Stack_unused(Stack* s);
Boolean isFull(Stack* s);
Boolean isEmpty(Stack* s);
int top(Stack*s);
void push(Stack* s, int e);
int pop(Stack* s);

#endif

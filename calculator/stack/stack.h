typedef enum{FALSE=0,TRUE=1} Boolean;

typedef struct {
	int size;
	int top;
	int* stack;
}Stack;

Stack* createS(int size);
void deleteS(Stack* s);
int stack_used(Stack* s);
int stack_unused(Stack* s);
Boolean isFull(Stack* s);
Boolean isEmpty(Stack* s);
int top(Stack*s);
void push(Stack* s, int e);
int pop(Stack* s);
void clearS(Stack* s);
void loadS(Stack* s, int* elements, int length);
void pourS(Stack* from,Stack* to);
Stack* copyS(Stack* s);
void printS(Stack* s);

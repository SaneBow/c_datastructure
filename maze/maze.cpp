#include <stdio.h>
#include "stack/stack.h"

typedef enum{TRUE=1,FALSE=0} Boolean;

typedef struct{
	int x;
	int y;
	DIRECTION dir;
}position;

int main() {
	const int MAZE[3][3]={{0,1,1},{0,1,1},{0,0,0}};
	stack *s;
	position* pos = {0,0,E};
	s = createS(3*3);
	push(s,pos);
	while(!isEmpty) {
		pos = pop(s);
		mark[0][0]=1;
		Boolean MV_POSSIBLE = TRUE;	
		while(MV_POSSIBLE) {
			int nextX,nextY;
			DIRECTION nextDir;
			switch pos.dir {
				case E: 
					nextX = pos.x + 1;
				case S: 
					nextX = x;
			}	
		}
	}	
}


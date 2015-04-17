#include <stdio.h>
#include <stdlib.h>
#include "stack/stack.h"
#define DIM 10

void printPath(Stack *s, int MAZE[DIM][DIM], int mark[DIM][DIM]);
void printMatrix(int M[DIM][DIM]);

int main() {
    int MAZE[DIM][DIM]={
                                {0,0,0,0,0,0,0,1,1,1},
                                {1,0,1,0,1,1,1,1,1,1},
                                {1,0,1,0,0,0,0,0,1,1},
                                {1,0,1,0,1,1,1,0,1,1},
                                {1,0,1,0,0,0,0,0,1,1},
                                {1,0,1,1,1,0,1,1,1,1},
                                {1,0,1,1,1,0,1,0,0,0},
                                {0,0,1,1,1,1,1,0,1,0},
                                {0,1,1,0,0,0,0,0,1,0},
                                {0,0,0,0,1,1,1,1,1,0},
    };
    const int EXIT_X = DIM-1;
    const int EXIT_Y = DIM-1;
    int mark[DIM][DIM] = {0};

	Stack *s;
	Move pos = {0,0,E};
	s = createS(DIM*DIM);
	push(s,pos);
	while(!isEmpty(s)) {
        //Pop up current position
		pos = pop(s);
        int x = pos.row;
        int y = pos.col;
        DIRECTION dir = pos.dir;
        //Mark that we have visited it 
		mark[x][y]=1;
		while(dir < 4) {
			int nextX = x;
            int nextY = y;
            
            //For debug
            //printf("<%d,%d,%d>\n",x,y,dir);

            //Set next move depends on direction
			switch (dir) {
				case E: 
					nextY = y + 1; break;
                case W:
                    nextY = y - 1; break;
				case S: 
					nextX = x + 1; break;
                case N:
                    nextX = x - 1; break;
			}	
            // Boundary check
            if (nextX >= DIM || nextY >= DIM ||
                    nextX < 0 || nextY < 0) {
                dir++;
                continue;
            }
            // If next move goes to exit, print path
            if ((nextX==EXIT_X) && (nextY==EXIT_Y)) {
                //Mark exit step
                mark[nextX][nextY] = 1;
                //Record this step and exit step
                Move finalmove1 = {x,y,dir};
                Move finalmove2 = {nextX,nextY,dir};
                push(s,finalmove1);
                push(s,finalmove2);
                printPath(s,MAZE,mark);
                exit(0);
            }
            // If next move is available (not wall and not visited)
            else if (MAZE[nextX][nextY] == 0 && mark[nextX][nextY] == 0) {
                mark[nextX][nextY] = 1;
                Move thismove = {x,y,dir};
                push(s,thismove); 
                // Set current location
                x = nextX;
                y = nextY;
                dir = E;
            }
            else {
                dir++;
            }
		}
	}	
    printf("No path found\n");
    
    //For debug
    //printPath(s,MAZE,mark);
}

void printPath(Stack *s, int MAZE[DIM][DIM], int mark[DIM][DIM]) {
    Move e;
    printf("Path FOUND:\n\n");

    printf("MAZE:\n");
    printMatrix(MAZE);
    printf("\n");

    printf("Visit History:\n");
    printMatrix(mark);
    printf("\n");

    printf("Solution:\n");
    int sol[DIM][DIM] = {0};
    while (!isEmpty(s)) {
        e = pop(s);
        sol[e.row][e.col] = 1;
    }
    printMatrix(sol);
    
}

void printMatrix(int M[DIM][DIM]) {
    int i,j;
    for(i=0;i<DIM;i++) {
        for(j=0;j<DIM;j++) {
            printf("%2d",M[i][j]);
        }
        printf("\n");
    }
}


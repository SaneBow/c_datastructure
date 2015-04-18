#include <stdio.h>
#include <stdlib.h>
#include "stack/stack.h"

typedef enum {lparen,rparen,plus,minus,times,divide,eos,operand} precedence;
char* expr;
char infix[1000] = "1+2";
char postfix[1000];

precedence getToken(char*, int*);
int eval(void);
void toPostfix(void);
void printToken(precedence);

int main() {
    int result;

    //Get user input, save into infix[]

    //Convert infix expression to postfix
    expr = infix;
    toPostfix();
    //Eval postfix expression
    expr = postfix;
    result = eval();
    printf("%s = %d\n",infix,result);

    return 0;
}

precedence getToken(char *symbol, int *n) {
    printf("getToken\n");
    *symbol = expr[(*n)++];
    switch (*symbol) {
        case '+': return plus;
        case '-': return minus;
        case '/': return divide;
        case '*': return times;
        case '(': return lparen;
        case ')': return rparen;
        case '\0': return eos;
        default: return operand;
    }
}

int eval(void) {
    printf("eval\n");
    precedence token;
    char symbol;
    Stack *s;
    int op1,op2;
    int n=0;
    s = createS(100);
    token = getToken(&symbol,&n);
    while (token != eos) {
        if (token==operand) {
            op1 = symbol - '0';
            push(s,op1);
        }
        else {
            op2 = pop(s);
            op1 = pop(s);
            switch (token) {
                case plus: push(s,op1+op2); break;
                case minus: push(s,op1-op2); break;
                case times: push(s,op1*op2); break;
                case divide: push(s,op1/op2); break;
            }
        }
        token = getToken(&symbol,&n);
    }
    return pop(s);
}

void toPostfix() {
    printf("toPost\n");
    int isp[] = {0,19,12,12,13,13,13,0};
    int icp[] = {20,19,12,12,13,13,13,0};
    char symbol;
    precedence token;
    int n=0;
    Stack *s;
    s = createS(100);

    push(s,eos);
    for (token = getToken(&symbol,&n); token!=eos; token = getToken(&symbol,&n)) {
        if (token == operand)
            printf("%d",symbol-'0');
        else if (token == rparen) {
            while(top(s) != lparen) printToken(pop(s));
            pop(s); //Discard left parenthesis
        }
        else {
            while(isp[top(s)]>=icp[token]) printToken(pop(s));
            push(s,token);
        }
    }
    while ((token=pop(s)) != eos) printToken(token);
}

void printToken(precedence token) {
    switch (token) {
        case plus: printf("+"); break;
        case minus: printf("-"); break;
        case times: printf("*"); break;
        case divide: printf("/"); break;
    }
}

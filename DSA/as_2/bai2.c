#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100

typedef struct {
    double data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, double value) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = value;
    }
}

double pop(Stack *s) {
    if (s->top >= 0) {
        return s->data[(s->top)--];
    }
    return 0;
}

double evaluatePostfix(char *expr) {
    Stack stack;
    initStack(&stack);
    
    char *token = strtok(expr, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            push(&stack, atof(token));
        } else {
            double val2 = pop(&stack);
            double val1 = pop(&stack);
            
            switch (token[0]) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': push(&stack, val1 / val2); break;
                case '^': push(&stack, pow(val1, val2)); break;
            }
        }
        token = strtok(NULL, " ");
    }
    return pop(&stack);
}

int main() {
    char input[MAX];
    printf("Nhap bieu thuc hau to: ");
    fgets(input, MAX, stdin);
    
    printf("Ket qua: %.2f\n", evaluatePostfix(input));
    return 0;
}

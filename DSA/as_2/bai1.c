#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char c) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = c;
    }
}

char pop(Stack *s) {
    if (s->top >= 0) {
        return s->data[(s->top)--];
    }
    return '\0';
}

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

bool isValid(char *s) {
    Stack stack;
    initStack(&stack);
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(&stack, s[i]);
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (stack.top == -1 || !isMatchingPair(pop(&stack), s[i])) {
                return false;
            }
        }
    }
    return stack.top == -1;
}

int main() {
    char input[MAX];
    printf("Nhap chuoi can kiem tra: ");
    scanf("%s", input);
    
    if (isValid(input)) {
        printf("Chuoi hop le!\n");
    } else {
        printf("Chuoi khong hop le!\n");
    }
    return 0;
}

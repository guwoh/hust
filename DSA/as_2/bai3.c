#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char value) {
    if (s->top < MAX - 1) {
        s->data[++(s->top)] = value;
    }
}

char pop(Stack *s) {
    if (s->top >= 0) {
        return s->data[(s->top)--];
    }
    return '\0';
}

bool isPalindrome(char *str) {
    Stack stack;
    initStack(&stack);
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        push(&stack, str[i]);
    }
    
    for (int i = 0; i < len; i++) {
        if (pop(&stack) != str[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    char input[MAX];
    printf("Nhap chuoi can kem tra: ");
    scanf("%s", input);
    
    if (isPalindrome(input)) {
        printf("Chuoi doi xung!\n");
    } else {
        printf("Chuoi khong doi xung!\n");
    }
    return 0;
}
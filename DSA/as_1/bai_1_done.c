#include<stdio.h>
#include<stdlib.h>
#include<string.h>

# define MAX 100 // define the number max 

// define object
typedef struct 
{
  int maSo;
  char tenSach[100];
  long donGia;
} Sach;  // name of the struct

// define stack 
typedef struct
{
  Sach data[MAX];  // a list of book, it will have 100 slots 
  int top;
} Stack;

// init stack
void initStack(Stack *s)
{
  s->top = -1; // because  the first is 0
}
// check if the Stack is empty
int isEmpty( Stack *s)
{
  //printf("Stack is empty!");
  return s->top == -1;
}

// check if the Stack is full 
int isFull(Stack *s)
{
  //printf("Stack is Full!");
  return s->top == MAX -1; // top == 99 
}

// add a element to the Stack 
void push(Stack *s, Sach book)
{
  if (isFull(s))
  {
    printf("Stack is Full!");
    return;
  }
  s->data[++s->top] = book ;
}

// pop a element out of the Stack
Sach pop(Stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack is empty");
    exit(1);
  }
  return s->data[s->top--];
}

// tinh don gia trung binh

double tinhDonGiaTrungBinh(Stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack is empty!)\n");
    return 0;
  }
  long tongGia = 0;
  int count = s->top + 1; // count number of books
  for (int i = 0; i <= s->top; i++)
  {
    tongGia += s->data[i].donGia;
  }
  return (double)tongGia / count;
}

int main()
{
  Stack stack;
  initStack(&stack);
  
  // add book to the Stack
  
  Sach book1 = {1,"tag 1 ",50000};
  Sach book2 = {2,"tag 2 ",60000};
  Sach book3 = {3,"tag 3 ",670000};
  Sach book4 = {4,"tag 4",860000};
  
  push(&stack, book1);
  push(&stack, book2);
  push(&stack, book3);
  push(&stack, book4);

  // Hiển thị đơn giá trung bình
  printf("\nĐơn giá trung bình của các cuốn sách: %.2f\n", tinhDonGiaTrungBinh(&stack));
  

  return 0;
}























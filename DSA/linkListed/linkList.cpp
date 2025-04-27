/**
 * @file linkList.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<stdio.h>


struct Node
{
    int info;
    Node* next;
};
typedef Node* pNode;  // kieu con tro nut
typedef Node* linkedList; // kieu con tro danh sach lien ket noi don

void initList(linkedList & H) // khoi tao danh sach rong, gan con tro H = NULL
{
    H = NULL;
}

bool isEmpty(linkedlist H)  // kiem tra danh sach rong
{
    return (H == NULL);
}

// thao tac bo sung mot phan tu moi K vao dau danh sach H
void insertBegin(linkedList & H, int K)
{
    // tao mot nut moi Q de chua K
    Q -> next = H;
    H = Q;
}

int main()
{

    return 0;
}
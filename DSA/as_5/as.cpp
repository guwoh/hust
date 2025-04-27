/**
 * @file as.cpp
 * @author vu hoang hiep (hiep.vh234005@sis.hust.edu.vn)
 * @brief 
 * @version 0.1
 * @date 2025-03-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <stdio.h>
#include <stdlib.h>

// Node structure and typedefs
struct Node {
    int info;
    struct Node* next;
};
typedef struct Node* PNode;
typedef struct Node* LinkedList;

// Create a new node with given value
PNode createNode(int value) {
    PNode newNode = (PNode)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->info = value;
    newNode->next = NULL;
    return newNode;
}

// 1
void insertSorted(LinkedList *list, int value) {
    PNode newNode = createNode(value);
    if (*list == NULL || (*list)->info >= value) {
        newNode->next = *list;
        *list = newNode;
    } else {
        PNode current = *list;
        while (current->next != NULL && current->next->info < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// 2
void sortList(LinkedList *list) {
    if (*list == NULL) return;
    for (PNode i = *list; i->next != NULL; i = i->next) {
        PNode minNode = i;
        for (PNode j = i->next; j != NULL; j = j->next) {
            if (j->info < minNode->info) {
                minNode = j;
            }
        }
        if (minNode != i) {
            int temp = i->info;
            i->info = minNode->info;
            minNode->info = temp;
        }
    }
}

// 3
void appendList(LinkedList *list1, LinkedList list2) {
    if (*list1 == NULL) {
        *list1 = list2;
    } else {
        PNode current = *list1;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = list2;
    }
}

// 4
void insertListAt(LinkedList *list1, LinkedList list2, int pos) {
    if (list2 == NULL) return;  
    if (pos <= 0 || *list1 == NULL) {
        PNode tail2 = list2;
        while (tail2->next != NULL) {
            tail2 = tail2->next;
        }
        tail2->next = *list1;
        *list1 = list2;
    } else {
        PNode current = *list1;
        int index = 0;
        while (current->next != NULL && index < pos - 1) {
            current = current->next;
            index++;
        }
        PNode tail2 = list2;
        while (tail2->next != NULL) {
            tail2 = tail2->next;
        }
        tail2->next = current->next;
        current->next = list2;
    }
}

// 5
void reverseList(LinkedList *list) {
    PNode prev = NULL;
    PNode curr = *list;
    PNode next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *list = prev;
}


void printList(LinkedList list) {
    PNode p = list;
    printf("[");
    while (p != NULL) {
        printf("%d", p->info);
        p = p->next;
        if (p != NULL) printf(", ");
    }
    printf("]\n");
}

int main() {
    // 1
    LinkedList list1 = NULL;
    int values1[] = {30, 10, 20, 5, 15};
    int n1 = sizeof(values1) / sizeof(values1[0]);
    printf("Priority Queue Insertion (Sorted Insert):\n");
    printf("Inserting values: ");
    for (int i = 0; i < n1; ++i) {
        printf("%d ", values1[i]);
    }
    printf("\n");
    for (int i = 0; i < n1; ++i) {
        insertSorted(&list1, values1[i]);
        printf("List after inserting %d: ", values1[i]);
        printList(list1);
    }
    printf("Final sorted list (ascending): ");
    printList(list1);
    printf("\n");

    // 2
    LinkedList list2 = NULL;
    int values2[] = {3, 5, 2, 4, 1};
    int n2 = sizeof(values2) / sizeof(values2[0]);
    for (int i = 0; i < n2; ++i) {
        PNode node = createNode(values2[i]);
        node->next = list2;
        list2 = node;
    }
    printf("Sorting a linked list:\n");
    printf("Original unsorted list: ");
    printList(list2);
    sortList(&list2);
    printf("List after sorting ascending: ");
    printList(list2);
    printf("\n");

    // 3
    printf("Appending list2 to the end of list1:\n");
    printf("List1 before append: ");
    printList(list1);
    printf("List2 to append: ");
    printList(list2);
    appendList(&list1, list2);
    printf("List1 after appending list2: ");
    printList(list1);
    printf("\n");

    // 4
    LinkedList list3 = NULL;
    LinkedList list4 = NULL;
    for (int i = 1; i <= 4; ++i) {
        insertSorted(&list3, i);
    }
    insertSorted(&list4, 100);
    insertSorted(&list4, 200);
    printf("Inserting list4 into list3 at position 2:\n");
    printf("List3 before insertion: ");
    printList(list3);
    printf("List4 to insert: ");
    printList(list4);
    insertListAt(&list3, list4, 2);
    printf("List3 after inserting list4 at pos 2: ");
    printList(list3);
    printf("\n");

    // 5
    printf("Reversing list3:\n");
    printf("List3 before reverse: ");
    printList(list3);
    reverseList(&list3);
    printf("List3 after reverse: ");
    printList(list3);
    printf("\n");

    LinkedList temp;
    while (list1 != NULL) {
        temp = list1;
        list1 = list1->next;
        free(temp);
    }
    while (list3 != NULL) {
        temp = list3;
        list3 = list3->next;
        free(temp);
    }

    return 0;
}

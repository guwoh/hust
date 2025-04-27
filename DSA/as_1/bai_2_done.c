#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

typedef struct {
    float *data;
    int size;
    int capacity;
} GeneralizedList;

GeneralizedList* createList() {
    GeneralizedList *list = (GeneralizedList *)malloc(sizeof(GeneralizedList));
    if (list == NULL) {
        printf("Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }
    list->data = (float *)malloc(INITIAL_CAPACITY * sizeof(float));
    if (list->data == NULL) {
        printf("Memory allocation error!\n");
        free(list);
        exit(EXIT_FAILURE);
    }
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    return list;
}

void freeList(GeneralizedList *list) {
    if (list) {
        free(list->data);
        free(list);
    }
}

void expandCapacity(GeneralizedList *list) {
    list->capacity *= 2;
    float *newData = (float *)realloc(list->data, list->capacity * sizeof(float));
    if (newData == NULL) {
        printf("Memory allocation error during expansion!\n");
        freeList(list);
        exit(EXIT_FAILURE);
    }
    list->data = newData;
}

void insert(GeneralizedList *list, float value, int pos) {
    if (pos < 0 || pos > list->size) {
        printf("Invalid position for insert!\n");
        return;
    }
    if (list->size == list->capacity) {
        expandCapacity(list);
    }
    for (int i = list->size; i > pos; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[pos] = value;
    list->size++;
}

void removeElement(GeneralizedList *list, int pos) {
    if (pos < 0 || pos >= list->size) {
        printf("Invalid position for removal!\n");
        return;
    }
    for (int i = pos; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
}

float get(GeneralizedList *list, int pos) {
    if (pos < 0 || pos >= list->size) {
        printf("Invalid position for get!\n");
        return -1;
    }
    return list->data[pos];
}

void printList(GeneralizedList *list) {
    printf("List: ");
    for (int i = 0; i < list->size; i++) {
        printf("%.2f ", list->data[i]);
    }
    printf("\n");
}

int main(void) {
    GeneralizedList *list = createList();
    
    insert(list, 1.0, 0);
    insert(list, 2.0, 1);
    insert(list, 3.0, 2);
    printList(list);
    
    insert(list, 4.5, 1);
    printList(list);
    
    removeElement(list, 2);
    printList(list);
    
    float value = get(list, 1);
    printf("Element at index 1: %.2f\n", value);
    
    freeList(list);
    
    return 0;
}


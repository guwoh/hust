#include <stdio.h>
#include <stdlib.h>

typedef struct PriorityNode {
    int data;
    int priority;
    struct PriorityNode* next;
} PriorityNode;

typedef PriorityNode* PriorityQueue;

// Khởi tạo hàng đợi ưu tiên rỗng
void initPQ(PriorityQueue *pq) {
    *pq = NULL;
}

// Kiểm tra hàng đợi ưu tiên có rỗng không
int isPQEmpty(PriorityQueue pq) {
    return (pq == NULL);
}

// Thêm phần tử vào hàng đợi ưu tiên theo thứ tự ưu tiên (cao -> thấp)
void enqueuePQ(PriorityQueue *pq, int data, int priority) {
    PriorityNode* newNode = (PriorityNode*)malloc(sizeof(PriorityNode));
    if(newNode == NULL) {
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    
    // Nếu hàng đợi rỗng hoặc độ ưu tiên của newNode cao hơn phần tử đầu
    if(*pq == NULL || priority > (*pq)->priority) {
        newNode->next = *pq;
        *pq = newNode;
    } else {
        PriorityNode* current = *pq;
        while(current->next != NULL && current->next->priority >= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Lấy phần tử có độ ưu tiên cao nhất ra khỏi hàng đợi
int dequeuePQ(PriorityQueue *pq) {
    if(isPQEmpty(*pq)) {
        printf("Hàng đợi ưu tiên rỗng.\n");
        return -1;
    }
    PriorityNode* temp = *pq;
    int data = temp->data;
    *pq = (*pq)->next;
    free(temp);
    return data;
}

// Hiển thị các phần tử trong hàng đợi ưu tiên
void displayPQ(PriorityQueue pq) {
    if(isPQEmpty(pq)) {
        printf("Hàng đợi ưu tiên rỗng.\n");
        return;
    }
    printf("Hàng đợi ưu tiên: ");
    PriorityNode* current = pq;
    while(current != NULL) {
        printf("(%d, p=%d) ", current->data, current->priority);
        current = current->next;
    }
    printf("\n");
}

int main() {
    PriorityQueue pq;
    initPQ(&pq);
    
    // Thêm các phần tử với độ ưu tiên khác nhau
    enqueuePQ(&pq, 100, 2);
    enqueuePQ(&pq, 200, 4);
    enqueuePQ(&pq, 300, 1);
    enqueuePQ(&pq, 400, 3);
    
    displayPQ(pq);
    
    // Lấy ra phần tử có độ ưu tiên cao nhất
    printf("Lấy ra: %d\n", dequeuePQ(&pq));
    displayPQ(pq);
    
    return 0;
}

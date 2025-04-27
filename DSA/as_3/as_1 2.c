#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Kích thước tối đa của hàng đợi

typedef struct {
    int data[MAX];
    int front;
    int rear;
} CircularQueue;

// Khởi tạo hàng đợi rỗng
void initQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Kiểm tra hàng đợi rỗng
int isEmpty(CircularQueue *q) {
    return (q->front == -1);
}

// Kiểm tra hàng đợi đầy
int isFull(CircularQueue *q) {
    return ((q->rear + 1) % MAX == q->front);
}

// Thêm phần tử vào hàng đợi
void enqueue(CircularQueue *q, int value) {
    if(isFull(q)) {
        printf("Hàng đợi đầy. Không thể thêm %d.\n", value);
        return;
    }
    if(isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
}

// Lấy phần tử ra khỏi hàng đợi
int dequeue(CircularQueue *q) {
    if(isEmpty(q)) {
        printf("Hàng đợi rỗng. Không thể lấy phần tử.\n");
        return -1; // giá trị báo lỗi
    }
    int value = q->data[q->front];
    if(q->front == q->rear) {
        // Chỉ có một phần tử trong hàng đợi
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}

// Hiển thị các phần tử trong hàng đợi
void displayQueue(CircularQueue *q) {
    if(isEmpty(q)) {
        printf("Hàng đợi rỗng.\n");
        return;
    }
    printf("Hàng đợi: ");
    int i = q->front;
    while(1) {
        printf("%d ", q->data[i]);
        if(i == q->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initQueue(&q);
    
    // Thêm các phần tử vào hàng đợi
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50); // Khi thêm phần tử này, hàng đợi đạt giới hạn MAX
    
    displayQueue(&q);
    
    // Thử thêm phần tử khi hàng đợi đầy
    enqueue(&q, 60);
    
    // Lấy ra hai phần tử
    printf("Lấy ra: %d\n", dequeue(&q));
    printf("Lấy ra: %d\n", dequeue(&q));
    
    displayQueue(&q);
    
    // Thêm phần tử để kiểm tra tính chất vòng của hàng đợi
    enqueue(&q, 60);
    enqueue(&q, 70);
    
    displayQueue(&q);
    
    return 0;
}

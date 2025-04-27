#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node* next;
} Node;

typedef Node* LinkedList;

// Tạo danh sách rỗng
void initList(LinkedList *list) {
    *list = NULL;
}

// Kiểm tra danh sách có rỗng không
int isEmpty(LinkedList list) {
    return (list == NULL);
}

// Bổ sung phần tử K vào đầu danh sách
void insertBegin(LinkedList *list, int K) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }
    newNode->info = K;
    newNode->next = *list;
    *list = newNode;
}

// Tìm kiếm phần tử có giá trị bằng K
Node* search(LinkedList list, int K) {
    Node* ptr = list;
    while(ptr != NULL && ptr->info != K)
        ptr = ptr->next;
    return ptr;  // Trả về NULL nếu không tìm thấy
}

// Bổ sung phần tử K vào sau phần tử được trỏ bởi p
void insertAfter(LinkedList *list, int K, Node* p) {
    if(p == NULL)
        return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }
    newNode->info = K;
    newNode->next = p->next;
    p->next = newNode;
}

// Cách 1: Bổ sung phần tử K vào trước phần tử được trỏ bởi p bằng cách duyệt tìm nút trước đó
void insertBefore1(LinkedList *list, int K, Node* p) {
    if(p == NULL) return;
    // Nếu p là nút đầu, thì chèn vào đầu danh sách
    if(*list == p) {
        insertBegin(list, K);
        return;
    }
    Node* current = *list;
    while(current != NULL && current->next != p)
        current = current->next;
    if(current == NULL) {
        printf("Nút p không có trong danh sách.\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }
    newNode->info = K;
    newNode->next = p;
    current->next = newNode;
}

// Cách 2: Bổ sung phần tử K vào trước phần tử được trỏ bởi p bằng cách hoán đổi dữ liệu (O(1))
void insertBefore2(LinkedList *list, int K, Node* p) {
    if(p == NULL)
        return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }
    // Hoán đổi dữ liệu: lưu dữ liệu của p vào newNode, gán K cho p, và chèn newNode sau p
    newNode->info = p->info;
    p->info = K;
    newNode->next = p->next;
    p->next = newNode;
}

// Hiển thị danh sách
void displayList(LinkedList list) {
    if(isEmpty(list)) {
        printf("Danh sách rỗng.\n");
        return;
    }
    printf("Danh sách: ");
    Node* ptr = list;
    while(ptr != NULL) {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

// Tính giá trị trung bình của danh sách
double average(LinkedList list) {
    if(isEmpty(list))
        return 0.0;
    int sum = 0, count = 0;
    Node* ptr = list;
    while(ptr != NULL) {
        sum += ptr->info;
        count++;
        ptr = ptr->next;
    }
    return (double)sum / count;
}

int main() {
    LinkedList list;
    initList(&list);
    
    // Bổ sung các phần tử vào đầu danh sách: 11, 22, 33, 44, 55
    insertBegin(&list, 11);
    insertBegin(&list, 22);
    insertBegin(&list, 33);
    insertBegin(&list, 44);
    insertBegin(&list, 55);
    displayList(list);  // Kết quả: 55 44 33 22 11
    
    // Tìm kiếm nút chứa giá trị 44
    Node* p = search(list, 44);
    if(p != NULL) {
        // Bổ sung 77 vào sau nút chứa 44
        insertAfter(&list, 77, p);
        displayList(list);
        
        // Bổ sung 88 vào trước nút p bằng cách 1 (duyệt tìm nút trước)
        insertBefore1(&list, 88, p);
        displayList(list);
        
        // Bổ sung 99 vào trước nút p bằng cách 2 (hoán đổi)
        insertBefore2(&list, 99, p);
        displayList(list);
    } else {
        printf("Không tìm thấy phần tử 44.\n");
    }
    
    printf("Giá trị trung bình của danh sách: %.2lf\n", average(list));
    
    return 0;
}

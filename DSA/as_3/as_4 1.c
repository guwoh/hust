#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node* next;
} Node;

typedef Node* LinkedList;

// Tạo danh sách rỗng: trả về NULL
LinkedList initList() {
    return NULL;
}

// Kiểm tra danh sách rỗng
int isEmpty(LinkedList list) {
    return (list == NULL);
}

// Bổ sung phần tử K vào đầu danh sách – trả về head mới
LinkedList insertBegin(LinkedList list, int K) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }
    newNode->info = K;
    newNode->next = list;
    return newNode;  // newNode trở thành head mới
}

// Tìm kiếm phần tử có giá trị bằng K
Node* search(LinkedList list, int K) {
    Node* ptr = list;
    while(ptr != NULL && ptr->info != K)
        ptr = ptr->next;
    return ptr;
}

// Bổ sung phần tử K vào sau nút được trỏ bởi p (không cần cập nhật head)
void insertAfter(LinkedList list, int K, Node* p) {
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

// Cách 1: Bổ sung phần tử K vào trước nút p (duyệt tìm nút trước đó); nếu p là head thì trả về head mới
LinkedList insertBefore1(LinkedList list, int K, Node* p) {
    if(p == NULL)
        return list;
    // Nếu p là head
    if(list == p) {
        return insertBegin(list, K);
    }
    Node* current = list;
    while(current != NULL && current->next != p)
        current = current->next;
    if(current == NULL) {
        printf("Nút p không có trong danh sách.\n");
        return list;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }
    newNode->info = K;
    newNode->next = p;
    current->next = newNode;
    return list;
}

// Cách 2: Bổ sung phần tử K vào trước nút p bằng cách hoán đổi dữ liệu (không cần cập nhật head)
void insertBefore2(LinkedList list, int K, Node* p) {
    if(p == NULL)
        return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }
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
    // Khởi tạo danh sách
    LinkedList list = initList();
    
    // Bổ sung phần tử vào đầu danh sách
    list = insertBegin(list, 11);
    list = insertBegin(list, 22);
    list = insertBegin(list, 33);
    list = insertBegin(list, 44);
    list = insertBegin(list, 55);
    displayList(list);  // Kết quả: 55 44 33 22 11
    
    // Tìm nút chứa giá trị 44
    Node* p = search(list, 44);
    if(p != NULL) {
        // Bổ sung 77 vào sau nút p
        insertAfter(list, 77, p);
        displayList(list);
        
        // Bổ sung 88 vào trước nút p bằng cách 1
        list = insertBefore1(list, 88, p);
        displayList(list);
        
        // Bổ sung 99 vào trước nút p bằng cách 2
        insertBefore2(list, 99, p);
        displayList(list);
    } else {
        printf("Không tìm thấy phần tử 44.\n");
    }
    
    printf("Giá trị trung bình của danh sách: %.2lf\n", average(list));
    
    return 0;
}

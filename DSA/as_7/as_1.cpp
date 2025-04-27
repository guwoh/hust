
#include <stdio.h>
#include <stdlib.h>  // quan ly bo nho dong 
#include <string.h>

// Dinh nghia cac trang thai tien trinh
typedef enum {
    READY,
    RUNNING,
    WAITING,
    TERMINATED
} Status;

// Cau truc de luu thong tin mot tien trinh
typedef struct {
    int id;                // Ma dinh danh tien trinh
    char name[50];         // Ten tien trinh
    Status status;         // Trang thai: READY, RUNNING, WAITING, TERMINATED
    int priority;          // Do uu tien (so cang lon, uu tien cang cao)
} Process;

// Node cua danh sach lien ket don
typedef struct Node {
    Process data;
    struct Node* next;
} Node;

// Cau truc danh sach lien ket don
typedef struct {
    Node* head;  // Con tro den node dau tien cua danh sach
} LinkedList;

// ======= Khoi tao danh sach lien ket don ======= //
void initList(LinkedList* list) {
    list->head = NULL;
}

// ======= a) Them moi tien trinh ======= //
void insertProcess(LinkedList* list, int id, const char* name, Status status, int priority) {
    // Tao node moi
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data.id = id;
    strcpy(newNode->data.name, name);
    newNode->data.status = status;
    newNode->data.priority = priority;
    newNode->next = NULL;
    
    // Neu danh sach rong, node moi la head
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        // Them node vao cuoi danh sach
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Them tien trinh thanh cong.\n");
}

// ======= b) Tim tien trinh READY co uu tien cao nhat ======= //
Node* findReadyHighestPriority(LinkedList* list) {
    Node* result = NULL;
    Node* temp = list->head;
    int highestPriority = -1; // Gia su priority khong am

    while (temp != NULL) {
        if (temp->data.status == READY) {
            if (result == NULL || temp->data.priority > highestPriority) {
                result = temp;
                highestPriority = temp->data.priority;
            }
        }
        temp = temp->next;
    }
    return result;
}

// ======= c) Xoa mot tien trinh tai vi tri cho truoc ======= //
// index: 0 la node dau tien, 1 la node thu 2, ...
void removeAtIndex(LinkedList* list, int index) {
    if (list->head == NULL || index < 0) {
        printf("Danh sach rong hoac index khong hop le.\n");
        return;
    }
    
    Node* temp = list->head;
    // Truong hop xoa node dau
    if (index == 0) {
        list->head = temp->next;
        free(temp);
        printf("Xoa node tai index 0 thanh cong.\n");
        return;
    }
    
    // Tim node truoc node can xoa
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("Index khong ton tai.\n");
        return;
    }
    
    Node* nodeToRemove = temp->next;
    temp->next = nodeToRemove->next;
    free(nodeToRemove);
    printf("Xoa node tai index %d thanh cong.\n", index);
}

// ======= d) Xoa tat ca tien trinh co trang thai TERMINATED ======= //
void removeAllTerminated(LinkedList* list) {
    // Xoa cac node TERMINATED o dau danh sach
    while (list->head != NULL && list->head->data.status == TERMINATED) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    
    // Xoa cac node TERMINATED o giua/cuoi
    Node* current = list->head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data.status == TERMINATED) {
            Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    printf("Xoa tat ca tien trinh TERMINATED thanh cong.\n");
}

// ======= e) In tat ca cac tien trinh trong danh sach ======= //
void printList(LinkedList* list) {
    Node* temp = list->head;
    int index = 0;
    
    if (temp == NULL) {
        printf("Danh sach trong.\n");
        return;
    }
    
    printf("Danh sach tien trinh:\n");
    while (temp != NULL) {
        printf("Index %d: ID=%d, Name=%s, ", index, temp->data.id, temp->data.name);
        // In trang thai
        switch (temp->data.status) {
            case READY:     printf("Status=READY, "); break;
            case RUNNING:   printf("Status=RUNNING, "); break;
            case WAITING:   printf("Status=WAITING, "); break;
            case TERMINATED:printf("Status=TERMINATED, "); break;
        }
        printf("Priority=%d\n", temp->data.priority);
        temp = temp->next;
        index++;
    }
    printf("\n");
}

// ======= Ham chuyen doi gia tri nhap vao thanh Status ======= //
Status convertToStatus(int code) {
    // Nhap code: 0-READY, 1-RUNNING, 2-WAITING, 3-TERMINATED
    switch(code) {
        case 0: return READY;
        case 1: return RUNNING;
        case 2: return WAITING;
        case 3: return TERMINATED;
        default: return READY; // Mac dinh la READY neu code khong hop le
    }
}

// ======= Ham hien thi menu ======= //
void printMenu() {
    printf("============== MENU ==============\n");
    printf("1. Them moi tien trinh\n");
    printf("2. Tim tien trinh READY co uu tien cao nhat\n");
    printf("3. Xoa mot tien trinh tai vi tri cho truoc\n");
    printf("4. Xoa tat ca tien trinh TERMINATED\n");
    printf("5. In danh sach tien trinh\n");
    printf("0. Thoat chuong trinh\n");
    printf("Nhap lua chon cua ban: ");
}

// ======= Ham main ======= //
int main() {
    LinkedList list;
    initList(&list);
    int choice;
    
    do {
        printMenu();
        if (scanf("%d", &choice) != 1) {
            // Neu nhap khong hop le, xoa bo nhap sai
            while(getchar() != '\n');
            printf("Nhap khong hop le, vui long thu lai.\n");
            continue;
        }
        
        switch(choice) {
            case 1: {
                // Them moi tien trinh
                int id, priority, statusCode;
                char name[50];
                
                printf("Nhap ID: ");
                scanf("%d", &id);
                printf("Nhap ten tien trinh: ");
                scanf("%s", name);
                printf("Nhap trang thai (0-READY, 1-RUNNING, 2-WAITING, 3-TERMINATED): ");
                scanf("%d", &statusCode);
                printf("Nhap do uu tien (priority): ");
                scanf("%d", &priority);
                
                insertProcess(&list, id, name, convertToStatus(statusCode), priority);
                break;
            }
            case 2: {
                // Tim tien trinh READY co uu tien cao nhat
                Node* highest = findReadyHighestPriority(&list);
                if (highest != NULL) {
                    printf("Tien trinh READY co uu tien cao nhat la: ID=%d, Name=%s, Priority=%d\n",
                           highest->data.id, highest->data.name, highest->data.priority);
                } else {
                    printf("Khong tim thay tien trinh READY nao.\n");
                }
                break;
            }
            case 3: {
                // Xoa mot tien trinh tai vi tri cho truoc
                int index;
                printf("Nhap index can xoa: ");
                scanf("%d", &index);
                removeAtIndex(&list, index);
                break;
            }
            case 4: {
                // Xoa tat ca tien trinh TERMINATED
                removeAllTerminated(&list);
                break;
            }
            case 5: {
                // In danh sach tien trinh
                printList(&list);
                break;
            }
            case 0: {
                printf("Thoat chuong trinh.\n");
                break;
            }
            default:
                printf("Lua chon khong hop le, vui long thu lai.\n");
                break;
        }
        printf("\n");
    } while(choice != 0);
    
    // Giai phong bo nho danh sach (neu can)
    Node* current = list.head;
    while(current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}

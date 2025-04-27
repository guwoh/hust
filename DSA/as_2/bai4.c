#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int size;
} TaiLieu;

typedef struct {
    TaiLieu data[MAX];
    int front, rear;
} HangDoi;

void khoiTaoHangDoi(HangDoi *q) {
    q->front = q->rear = -1;
}

int hangDoiRong(HangDoi *q) {
    return q->front == -1;
}

int hangDoiDay(HangDoi *q) {
    return (q->rear + 1) % MAX == q->front;
}

void themTaiLieu(HangDoi *q, TaiLieu tl) {
    if (hangDoiDay(q)) {
        printf("Hang doi day! Khong the them tai lieu.\n");
        return;
    }
    if (hangDoiRong(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }
    q->data[q->rear] = tl;
    printf("Da them tai lieu: %s, Kich thuoc: %dKB\n", tl.name, tl.size);
}

void inTaiLieu(HangDoi *q) {
    if (hangDoiRong(q)) {
        printf("Hang doi trong! Khong co tai lieu de in.\n");
        return;
    }
    printf("Dang in tai lieu: %s, Kich thuoc: %dKB\n", q->data[q->front].name, q->data[q->front].size);
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
}

void hienThiHangDoi(HangDoi *q) {
    if (hangDoiRong(q)) {
        printf("Hang doi trong!\n");
        return;
    }
    printf("Danh sach tai lieu cho in:\n");
    int i = q->front;
    while (1) {
        printf("- %s, Kich thuoc: %dKB\n", q->data[i].name, q->data[i].size);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    HangDoi hangDoiMayIn;
    khoiTaoHangDoi(&hangDoiMayIn);
    int luaChon;
    TaiLieu tl;
    
    do {
        printf("\n1. Them tai lieu vao hang doi\n");
        printf("2. In tai lieu\n");
        printf("3. Hien thi danh sach cho in\n");
        printf("4. Thoat\n");
        printf("Chon thao tac: ");
        scanf("%d", &luaChon);
        getchar();
        
        switch (luaChon) {
            case 1:
                printf("Nhap ten tai lieu: ");
                fgets(tl.name, 50, stdin);
                tl.name[strcspn(tl.name, "\n")] = 0;
                printf("Nhap kich thuoc (KB): ");
                scanf("%d", &tl.size);
                themTaiLieu(&hangDoiMayIn, tl);
                break;
            case 2:
                inTaiLieu(&hangDoiMayIn);
                break;
            case 3:
                hienThiHangDoi(&hangDoiMayIn);
                break;
            case 4:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (luaChon != 4);
    
    return 0;
}

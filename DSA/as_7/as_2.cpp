#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_MAHP_LENGTH 20

// Cau truc MonHoc
typedef struct MonHoc {
    char maHocPhan[MAX_MAHP_LENGTH];
    char tenHocPhan[MAX_NAME_LENGTH];
    int soTinChi;
    int hocKy;
    float diem;
    struct MonHoc* next; // tro den mon hoc tiep theo
} MonHoc;

// Cau truc SinhVien
typedef struct {
    long mssv;
    char hoTen[MAX_NAME_LENGTH];
    MonHoc* dsMonHoc; // tro den danh sach mon hoc (lien ket don)
} SinhVien;

// Node danh sach sinh vien (mang thong tin 1 SinhVien)
typedef struct NodeSV {
    SinhVien data;
    struct NodeSV* next;
} NodeSV;

// Danh sach sinh vien: con tro tro den node dau
typedef struct {
    NodeSV* head;
} DanhSachSV;

// ====================== Khoi tao danh sach sinh vien ====================== //
void initDanhSachSV(DanhSachSV* dssv) {
    dssv->head = NULL;
}

// ====================== Tao mot sinh vien moi va them vao danh sach ====================== //
void themSinhVien(DanhSachSV* dssv, long mssv, const char* hoTen) {
    // Tao node moi
    NodeSV* newNode = (NodeSV*)malloc(sizeof(NodeSV));
    newNode->data.mssv = mssv;
    strcpy(newNode->data.hoTen, hoTen);
    newNode->data.dsMonHoc = NULL; // Chua co mon hoc nao
    newNode->next = NULL;
    
    // Neu danh sach rong, newNode la head
    if (dssv->head == NULL) {
        dssv->head = newNode;
    } else {
        // Duyet den cuoi danh sach
        NodeSV* temp = dssv->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Da them sinh vien MSSV=%ld, Ten=%s\n", mssv, hoTen);
}

// ====================== Tim sinh vien theo MSSV (tra ve con tro den nodeSV) ====================== //
NodeSV* timSinhVien(DanhSachSV* dssv, long mssv) {
    NodeSV* temp = dssv->head;
    while (temp != NULL) {
        if (temp->data.mssv == mssv) {
            return temp; // tim thay
        }
        temp = temp->next;
    }
    return NULL; // khong tim thay
}

// ====================== Them mon hoc cho mot sinh vien ====================== //
void themMonHoc(NodeSV* svNode, const char* maHP, const char* tenHP, int soTinChi, int hocKy, float diem) {
    if (svNode == NULL) {
        printf("Khong the them mon hoc. svNode=NULL\n");
        return;
    }
    
    // Tao mon hoc moi
    MonHoc* newMon = (MonHoc*)malloc(sizeof(MonHoc));
    strcpy(newMon->maHocPhan, maHP);
    strcpy(newMon->tenHocPhan, tenHP);
    newMon->soTinChi = soTinChi;
    newMon->hocKy = hocKy;
    newMon->diem = diem;
    newMon->next = NULL;
    
    // Chen vao danh sach mon hoc (dsMonHoc)
    MonHoc* ds = svNode->data.dsMonHoc;
    if (ds == NULL) {
        // Sinh vien chua co mon nao
        svNode->data.dsMonHoc = newMon;
    } else {
        // Di chuyen den cuoi dsMonHoc
        while (ds->next != NULL) {
            ds = ds->next;
        }
        ds->next = newMon;
    }
    printf("Da them mon hoc %s cho sinh vien MSSV=%ld\n", tenHP, svNode->data.mssv);
}

// ====================== In danh sach mon hoc cua mot sinh vien ====================== //
void inDanhSachMonHoc(MonHoc* dsMonHoc) {
    if (dsMonHoc == NULL) {
        printf("    Khong co mon hoc nao.\n");
        return;
    }
    int index = 1;
    while (dsMonHoc != NULL) {
        printf("    Mon %d: MaHP=%s, TenHP=%s, SoTinChi=%d, HocKy=%d, Diem=%.2f\n",
               index, dsMonHoc->maHocPhan, dsMonHoc->tenHocPhan,
               dsMonHoc->soTinChi, dsMonHoc->hocKy, dsMonHoc->diem);
        dsMonHoc = dsMonHoc->next;
        index++;
    }
}

// ====================== In tat ca sinh vien va cac mon hoc cua ho ====================== //
void inDanhSachSV(DanhSachSV* dssv) {
    if (dssv->head == NULL) {
        printf("Danh sach sinh vien trong.\n");
        return;
    }
    
    NodeSV* temp = dssv->head;
    while (temp != NULL) {
        printf("\n---------------------------\n");
        printf("MSSV: %ld\n", temp->data.mssv);
        printf("Ho ten: %s\n", temp->data.hoTen);
        printf("Danh sach mon hoc:\n");
        inDanhSachMonHoc(temp->data.dsMonHoc);
        
        temp = temp->next;
    }
    printf("\n");
}

// ====================== Giai phong danh sach mon hoc ====================== //
void giaiPhongMonHoc(MonHoc* dsMonHoc) {
    while (dsMonHoc != NULL) {
        MonHoc* temp = dsMonHoc;
        dsMonHoc = dsMonHoc->next;
        free(temp);
    }
}

// ====================== Xoa mot sinh vien trong danh sach theo MSSV ====================== //
void xoaSinhVien(DanhSachSV* dssv, long mssv) {
    if (dssv->head == NULL) {
        printf("Danh sach sinh vien trong.\n");
        return;
    }
    
    NodeSV* temp = dssv->head;
    NodeSV* prev = NULL;
    
    // Neu sinh vien can xoa o dau danh sach
    if (temp != NULL && temp->data.mssv == mssv) {
        dssv->head = temp->next;
        
        // Giai phong dsMonHoc cua temp
        giaiPhongMonHoc(temp->data.dsMonHoc);
        free(temp);
        printf("Da xoa sinh vien MSSV=%ld\n", mssv);
        return;
    }
    
    // Tim sinh vien can xoa
    while (temp != NULL && temp->data.mssv != mssv) {
        prev = temp;
        temp = temp->next;
    }
    
    // Neu khong tim thay
    if (temp == NULL) {
        printf("Khong tim thay sinh vien MSSV=%ld\n", mssv);
        return;
    }
    
    // Loai bo node temp khoi danh sach
    prev->next = temp->next;
    // Giai phong dsMonHoc cua temp
    giaiPhongMonHoc(temp->data.dsMonHoc);
    free(temp);
    printf("Da xoa sinh vien MSSV=%ld\n", mssv);
}

// ====================== Menu cho phep tuong tac tren terminal ====================== //
void printMenu() {
    printf("=============== MENU ===============\n");
    printf("1. Them sinh vien\n");
    printf("2. Them mon hoc cho sinh vien\n");
    printf("3. In danh sach sinh vien\n");
    printf("4. Xoa sinh vien\n");
    printf("0. Thoat\n");
    printf("Nhap lua chon cua ban: ");
}

int main() {
    DanhSachSV dssv;
    initDanhSachSV(&dssv);
    
    int choice;
    do {
        printMenu();
        if (scanf("%d", &choice) != 1) {
            // Neu nhap khong hop le, xoa bo dem
            while (getchar() != '\n');
            printf("Nhap khong hop le. Vui long thu lai.\n");
            continue;
        }
        
        switch (choice) {
            case 1: {
                // Them sinh vien
                long mssv;
                char hoTen[MAX_NAME_LENGTH];
                printf("Nhap MSSV: ");
                scanf("%ld", &mssv);
                printf("Nhap ho ten: ");
                scanf("%*c%[^\n]", hoTen); 
                // %*c bo qua ki tu xuong dong truoc do (neu co),
                // %[^\n] doc den ki tu xuong dong
                
                themSinhVien(&dssv, mssv, hoTen);
                break;
            }
            case 2: {
                // Them mon hoc cho 1 sinh vien
                long mssv;
                char maHP[MAX_MAHP_LENGTH], tenHP[MAX_NAME_LENGTH];
                int soTinChi, hocKy;
                float diem;
                
                printf("Nhap MSSV cua sinh vien can them mon hoc: ");
                scanf("%ld", &mssv);
                
                NodeSV* svNode = timSinhVien(&dssv, mssv);
                if (svNode == NULL) {
                    printf("Khong tim thay sinh vien MSSV=%ld\n", mssv);
                    break;
                }
                
                printf("Nhap ma hoc phan: ");
                scanf("%s", maHP);
                printf("Nhap ten hoc phan: ");
                scanf("%*c%[^\n]", tenHP);
                printf("Nhap so tin chi: ");
                scanf("%d", &soTinChi);
                printf("Nhap hoc ky: ");
                scanf("%d", &hocKy);
                printf("Nhap diem mon hoc: ");
                scanf("%f", &diem);
                
                themMonHoc(svNode, maHP, tenHP, soTinChi, hocKy, diem);
                break;
            }
            case 3: {
                // In danh sach sinh vien
                inDanhSachSV(&dssv);
                break;
            }
            case 4: {
                // Xoa sinh vien
                long mssv;
                printf("Nhap MSSV cua sinh vien can xoa: ");
                scanf("%ld", &mssv);
                xoaSinhVien(&dssv, mssv);
                break;
            }
            case 0: {
                printf("Thoat chuong trinh.\n");
                break;
            }
            default: {
                printf("Lua chon khong hop le. Vui long thu lai.\n");
                break;
            }
        }
        
        printf("\n");
    } while (choice != 0);
    
    // Giai phong danh sach truoc khi ket thuc chuong trinh
    NodeSV* current = dssv.head;
    while (current != NULL) {
        NodeSV* temp = current;
        current = current->next;
        giaiPhongMonHoc(temp->data.dsMonHoc);
        free(temp);
    }
    
    return 0;
}

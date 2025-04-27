#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//------------------------------
// Ngan xep luu tru so nguyen bang danh sach lien ket don
//------------------------------
typedef struct NodeStack {
    int duLieu;
    struct NodeStack* tiep;
} NodeStack;

typedef struct {
    NodeStack* dau;
} NganXep;

void khoiTaoNganXep(NganXep *nx) {
    nx->dau = NULL;
}

int laNganXepRong(NganXep *nx) {
    return (nx->dau == NULL);
}

void duaVaoNganXep(NganXep *nx, int giaTri) {
    NodeStack *nodeMoi = (NodeStack*)malloc(sizeof(NodeStack));
    if(nodeMoi == NULL) {
        printf("Khong du bo nho de dua vao ngan xep!\n");
        return;
    }
    nodeMoi->duLieu = giaTri;
    nodeMoi->tiep = nx->dau;
    nx->dau = nodeMoi;
}

int layRaNganXep(NganXep *nx) {
    if(laNganXepRong(nx)) {
        printf("Ngan xep rong. Khong the lay ra!\n");
        return -1;
    }
    NodeStack *nodeTam = nx->dau;
    int giaTri = nodeTam->duLieu;
    nx->dau = nodeTam->tiep;
    free(nodeTam);
    return giaTri;
}

void hienThiNganXep(NganXep *nx) {
    printf("Cac phan tu trong ngan xep: ");
    NodeStack *nodeTam = nx->dau;
    while(nodeTam != NULL) {
        printf("%d ", nodeTam->duLieu);
        nodeTam = nodeTam->tiep;
    }
    printf("\n");
}

//------------------------------
// Hang doi luu tru so nguyen bang danh sach lien ket don
//------------------------------
typedef struct NodeQueue {
    int duLieu;
    struct NodeQueue *tiep;
} NodeQueue;

typedef struct {
    NodeQueue *dau, *cuoi;
} HangDoi;

void khoiTaoHangDoi(HangDoi *hd) {
    hd->dau = hd->cuoi = NULL;
}

int laHangDoiRong(HangDoi *hd) {
    return (hd->dau == NULL);
}

void themVaoHangDoi(HangDoi *hd, int giaTri) {
    NodeQueue *nodeMoi = (NodeQueue*)malloc(sizeof(NodeQueue));
    if(nodeMoi == NULL) {
        printf("Khong du bo nho de them vao hang doi!\n");
        return;
    }
    nodeMoi->duLieu = giaTri;
    nodeMoi->tiep = NULL;
    if(hd->cuoi == NULL) {
        hd->dau = hd->cuoi = nodeMoi;
    } else {
        hd->cuoi->tiep = nodeMoi;
        hd->cuoi = nodeMoi;
    }
}

int loaiKhoiHangDoi(HangDoi *hd) {
    if(laHangDoiRong(hd)) {
        printf("Hang doi rong. Khong the loai khoi hang doi!\n");
        return -1;
    }
    NodeQueue *nodeTam = hd->dau;
    int giaTri = nodeTam->duLieu;
    hd->dau = nodeTam->tiep;
    if(hd->dau == NULL)
        hd->cuoi = NULL;
    free(nodeTam);
    return giaTri;
}

void hienThiHangDoi(HangDoi *hd) {
    printf("Cac phan tu trong hang doi: ");
    NodeQueue *nodeTam = hd->dau;
    while(nodeTam != NULL) {
        printf("%d ", nodeTam->duLieu);
        nodeTam = nodeTam->tiep;
    }
    printf("\n");
}

//------------------------------
// Danh sach lien ket don luu tru sinh vien
// Thong tin sinh vien: mssv (long), ho ten (string), khoa (string)
//------------------------------
typedef struct {
    long mssv;
    char hoTen[50];
    char khoa[20];
} SinhVien;

typedef struct NodeSV {
    SinhVien duLieu;
    struct NodeSV *tiep;
} NodeSV;

typedef struct {
    NodeSV *dau;
} DanhSachSV;

void khoiTaoDanhSachSV(DanhSachSV *ds) {
    ds->dau = NULL;
}

void themSinhVien(DanhSachSV *ds, SinhVien sv) {
    NodeSV *nodeMoi = (NodeSV*)malloc(sizeof(NodeSV));
    if(nodeMoi == NULL) {
        printf("Khong du bo nho de them sinh vien!\n");
        return;
    }
    nodeMoi->duLieu = sv;
    nodeMoi->tiep = NULL;
    if(ds->dau == NULL) {
        ds->dau = nodeMoi;
    } else {
        NodeSV *nodeTam = ds->dau;
        while(nodeTam->tiep != NULL)
            nodeTam = nodeTam->tiep;
        nodeTam->tiep = nodeMoi;
    }
}

void hienThiDanhSachSV(DanhSachSV *ds) {
    printf("Danh sach sinh vien:\n");
    NodeSV *nodeTam = ds->dau;
    while(nodeTam != NULL) {
        printf("MSSV: %ld, Ho ten: %s, Khoa: %s\n", 
            nodeTam->duLieu.mssv, nodeTam->duLieu.hoTen, nodeTam->duLieu.khoa);
        nodeTam = nodeTam->tiep;
    }
}

NodeSV* timKiemSinhVien(DanhSachSV *ds, long mssv) {
    NodeSV *nodeTam = ds->dau;
    while(nodeTam != NULL) {
        if(nodeTam->duLieu.mssv == mssv)
            return nodeTam;
        nodeTam = nodeTam->tiep;
    }
    return NULL;
}

int main() {
    // Demo Ngan xep
    NganXep nx;
    khoiTaoNganXep(&nx);
    printf("=== NGAN XEP ===\n");
    duaVaoNganXep(&nx, 10);
    duaVaoNganXep(&nx, 20);
    duaVaoNganXep(&nx, 30);
    hienThiNganXep(&nx);
    printf("Lay ra phan tu: %d\n", layRaNganXep(&nx));
    hienThiNganXep(&nx);
    
    // Demo Hang doi
    HangDoi hd;
    khoiTaoHangDoi(&hd);
    printf("\n=== HANG DOI ===\n");
    themVaoHangDoi(&hd, 100);
    themVaoHangDoi(&hd, 200);
    themVaoHangDoi(&hd, 300);
    hienThiHangDoi(&hd);
    printf("Loai khoi hang doi: %d\n", loaiKhoiHangDoi(&hd));
    hienThiHangDoi(&hd);
    
    // Demo Danh sach sinh vien
    DanhSachSV ds;
    khoiTaoDanhSachSV(&ds);
    printf("\n=== DANH SACH SINH VIEN ===\n");
    
    // Tao mot so sinh vien mau
    SinhVien sv1 = {2018001, "Nguyen Van A", "CNTT"};
    SinhVien sv2 = {2018002, "Tran Thi B", "Dien tu"};
    SinhVien sv3 = {2018003, "Le Van C", "Kinh te"};
    
    themSinhVien(&ds, sv1);
    themSinhVien(&ds, sv2);
    themSinhVien(&ds, sv3);
    
    hienThiDanhSachSV(&ds);
    
    long timMssv;
    printf("\nNhap MSSV can tim: ");
    scanf("%ld", &timMssv);
    
    NodeSV *svTim = timKiemSinhVien(&ds, timMssv);
    if(svTim != NULL) {
        printf("Tim thay sinh vien: MSSV: %ld, Ho ten: %s, Khoa: %s\n", 
            svTim->duLieu.mssv, svTim->duLieu.hoTen, svTim->duLieu.khoa);
    } else {
        printf("Khong tim thay sinh vien voi MSSV %ld\n", timMssv);
    }
    
    return 0;
}

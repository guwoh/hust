#include <iostream>
using namespace std;

// Cấu trúc node của cây
struct treeNode {
    int infor;
    treeNode* rightPoint;
    treeNode* leftPoint;
};

// Tạo node mới
treeNode* createTreeNode(int data) {
    treeNode* newTreeNode = new treeNode;
    newTreeNode->infor = data;
    newTreeNode->rightPoint = NULL;
    newTreeNode->leftPoint = NULL;
    return newTreeNode;
}

// Cấu trúc queue node
struct queueNode {
    
    treeNode* tn;
    queueNode* next;
};

struct queue {
    queueNode* front;
    queueNode* rear;
};

void initQueue(queue& q) {
    q.front = NULL;
    q.rear = NULL;
}

void enqueue(queue& q, treeNode* node) {
    queueNode* newNode = new queueNode;
    newNode->tn = node;
    newNode->next = NULL;
    if (q.front == NULL)
        q.front = q.rear = newNode;
    else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

treeNode* dequeue(queue& q) {
    if (q.front == NULL) return NULL;
    queueNode* temp = q.front;
    q.front = q.front->next;
    treeNode* result = temp->tn;
    delete temp;
    return result;
}

void buildTreeFromArray(treeNode*& root, int arr[], int size) {
    if (size == 0) return;
    root = createTreeNode(arr[0]);
    queue q;
    initQueue(q);
    enqueue(q, root);
    int i = 1;
    while (i < size) {
        treeNode* current = dequeue(q);
        if (i < size) {
            current->leftPoint = createTreeNode(arr[i++]);
            enqueue(q, current->leftPoint);
        }
        if (i < size) {
            current->rightPoint = createTreeNode(arr[i++]);
            enqueue(q, current->rightPoint);
        }
    }
}

void hienThi(treeNode* node) {
    if (node != NULL) {
        cout << node->infor << " ";
        hienThi(node->leftPoint);
        hienThi(node->rightPoint);
    }
}

// Tính tổng các node
int tinhTong(treeNode* root) {
    if (root == NULL) return 0;
    return root->infor + tinhTong(root->leftPoint) + tinhTong(root->rightPoint);
}

// Tìm kiếm node
treeNode* searchTreeNode(treeNode* root, int data) {
    if (root == NULL) return NULL;
    if (root->infor == data) return root;

    treeNode* temp = searchTreeNode(root->leftPoint, data);
    if (temp != NULL) return temp;

    return searchTreeNode(root->rightPoint, data);
}

int tinhChieuCao(treeNode* root) {
    if (root == NULL)
        return -1;
    int chieuCaoTrai = tinhChieuCao(root->leftPoint);
    int chieuCaoPhai = tinhChieuCao(root->rightPoint);
    return max(chieuCaoTrai, chieuCaoPhai) + 1;
}

int main() {
    treeNode* root = NULL;
    int a[10] = {1,2,3,4,5,6,7,8,9,10};r
    
    cout << "Duyet cay: ";
    hienThi(root);

    int tong = tinhTong(root);
    cout << "\nTong cac node: " << tong;

    int target = 7;
    treeNode* found = searchTreeNode(root, target);
    if (found != NULL)
        cout << "\nTim thay node co gia tri: " << found->infor;
    else
        cout << "\nKhong tim thay node co gia tri: " << target;
    cout<<"\nchieu cao cua cay la:"<< tinhChieuCao(root)<<"\n";
    return 0;
}

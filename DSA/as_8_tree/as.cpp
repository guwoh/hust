#include <iostream>
using namespace std;

// Định nghĩa cấu trúc cây nhị phân
struct treeNode {
    int infor;
    treeNode* leftPoint;
    treeNode* rightPoint;
};

treeNode* createTreeNode(int data) {
    treeNode* newTreeNode = new treeNode;
    newTreeNode->infor = data;
    newTreeNode->leftPoint = NULL;
    newTreeNode->rightPoint = NULL;
    return newTreeNode;
}

// --------------------- BÀI 1: ĐỆ QUY ---------------------
treeNode* buildTreeRecursive(int arr[], int index, int size) {
    if (index >= size) return NULL;
    treeNode* node = createTreeNode(arr[index]);
    node->leftPoint = buildTreeRecursive(arr, 2 * index + 1, size);
    node->rightPoint = buildTreeRecursive(arr, 2 * index + 2, size);
    return node;
}

void preOrderRecursive(treeNode* root) {
    if (root) {
        cout << root->infor << " ";
        preOrderRecursive(root->leftPoint);
        preOrderRecursive(root->rightPoint);
    }
}

void inOrderRecursive(treeNode* root) {
    if (root) {
        inOrderRecursive(root->leftPoint);
        cout << root->infor << " ";
        inOrderRecursive(root->rightPoint);
    }
}

void postOrderRecursive(treeNode* root) {
    if (root) {
        postOrderRecursive(root->leftPoint);
        postOrderRecursive(root->rightPoint);
        cout << root->infor << " ";
    }
}

int heightRecursive(treeNode* root) {
    if (root == NULL) return -1;
    int l = heightRecursive(root->leftPoint);
    int r = heightRecursive(root->rightPoint);
    return (l > r ? l : r) + 1;
}

int sumRecursive(treeNode* root) {
    if (root == NULL) return 0;
    return root->infor + sumRecursive(root->leftPoint) + sumRecursive(root->rightPoint);
}

// --------------------- BÀI 2: KHỬ ĐỆ QUY ---------------------

const int MAX = 100;
struct Stack {
    treeNode* items[MAX];
    int top;
};

void initStack(Stack& s) { s.top = -1; }
int isEmpty(Stack& s) { return s.top == -1; }
void push(Stack& s, treeNode* node) { if (s.top < MAX-1) s.items[++s.top] = node; }
treeNode* pop(Stack& s) { return isEmpty(s) ? NULL : s.items[s.top--]; }
treeNode* peek(Stack& s) { return isEmpty(s) ? NULL : s.items[s.top]; }

struct Queue {
    treeNode* items[MAX];
    int front, rear;
};

void initQueue(Queue& q) { q.front = q.rear = -1; }
int isQEmpty(Queue& q) { return q.front == -1 || q.front > q.rear; }
void enqueue(Queue& q, treeNode* node) {
    if (q.rear < MAX - 1) {
        if (q.front == -1) q.front = 0;
        q.items[++q.rear] = node;
    }
}
treeNode* dequeue(Queue& q) {
    return isQEmpty(q) ? NULL : q.items[q.front++];
}

treeNode* buildTreeIterative(int arr[], int size) {
    if (size == 0) return NULL;
    treeNode* root = createTreeNode(arr[0]);
    Queue q; initQueue(q); enqueue(q, root);
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
    return root;
}

void preOrderIterative(treeNode* root) {
    Stack s; initStack(s);
    push(s, root);
    while (!isEmpty(s)) {
        treeNode* curr = pop(s);
        cout << curr->infor << " ";
        if (curr->rightPoint) push(s, curr->rightPoint);
        if (curr->leftPoint) push(s, curr->leftPoint);
    }
}

void inOrderIterative(treeNode* root) {
    Stack s; initStack(s);
    treeNode* current = root;
    while (current || !isEmpty(s)) {
        while (current) {
            push(s, current);
            current = current->leftPoint;
        }
        current = pop(s);
        cout << current->infor << " ";
        current = current->rightPoint;
    }
}

void postOrderIterative(treeNode* root) {
    Stack s1, s2; initStack(s1); initStack(s2);
    push(s1, root);
    while (!isEmpty(s1)) {
        treeNode* curr = pop(s1);
        push(s2, curr);
        if (curr->leftPoint) push(s1, curr->leftPoint);
        if (curr->rightPoint) push(s1, curr->rightPoint);
    }
    while (!isEmpty(s2)) {
        cout << pop(s2)->infor << " ";
    }
}

int heightIterative(treeNode* root) {
    if (!root) return -1;
    Queue q; initQueue(q);
    enqueue(q, root);
    int height = -1;
    while (!isQEmpty(q)) {
        int count = q.rear - q.front + 1;
        height++;
        for (int i = 0; i < count; ++i) {
            treeNode* curr = dequeue(q);
            if (curr->leftPoint) enqueue(q, curr->leftPoint);
            if (curr->rightPoint) enqueue(q, curr->rightPoint);
        }
    }
    return height;
}

int sumIterative(treeNode* root) {
    Stack s; initStack(s);
    push(s, root);
    int total = 0;
    while (!isEmpty(s)) {
        treeNode* curr = pop(s);
        total += curr->infor;
        if (curr->rightPoint) push(s, curr->rightPoint);
        if (curr->leftPoint) push(s, curr->leftPoint);
    }
    return total;
}

// ------------------- MAIN -------------------
int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << "\n--- BAI 1: DE QUY ---\n";
    treeNode* root1 = buildTreeRecursive(arr, 0, size);
    cout << "Duyet tien tu: "; preOrderRecursive(root1); cout << endl;
    cout << "Duyet trung tu: "; inOrderRecursive(root1); cout << endl;
    cout << "Duyet hau tu: "; postOrderRecursive(root1); cout << endl;
    cout << "Chieu cao: " << heightRecursive(root1) << endl;
    cout << "Tong gia tri: " << sumRecursive(root1) << endl;

    cout << "\n--- BAI 2: KHU DE QUY ---\n";
    treeNode* root2 = buildTreeIterative(arr, size);
    cout << "Duyet tien tu: "; preOrderIterative(root2); cout << endl;
    cout << "Duyet trung tu: "; inOrderIterative(root2); cout << endl;
    cout << "Duyet hau tu: "; postOrderIterative(root2); cout << endl;
    cout << "Chieu cao: " << heightIterative(root2) << endl;
    cout << "Tong gia tri: " << sumIterative(root2) << endl;

    return 0;
}
// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
 
#include <iostream>
using namespace std;
/*
Hãy cài đặt cây nhị phân tìm kiếm, các khóa trên cây là các số nguyên với các thao tác (hàm):
khởi tạo cây rỗng
bổ sung phần tử vào cây
xóa phần tử khỏi cây
tìm kiếm phần tử trên cây
tính tổng giá trị các khóa trên cây
đếm tổng số lượng các nút trên cây
hiển thị giá trị tất cả các khóa trên cây.
Viết chương trình chính sử dụng cây trên
*/
struct  Node {
	int  key; 	
	Node* LP, * RP;
};
 
void initialBST (Node*& Root){
	Root = NULL;
}
// tim kiem phan tu x tren cay
Node* searchBST(Node* Root, int  x) {
	if (Root == NULL)  return  NULL;
	if (x == Root->key) return  Root;
	else   if (x < Root->key)  return  searchBST(Root->LP, x);
	else  return  searchBST(Root->RP, x);
}
 
//bo sung phan tu vao cay
void  insertBST(Node*& Root, int  x) {
	Node*  Q;
	if (Root == NULL) {		//khi cây rỗng
		Q = new Node; 		//tạo ra đỉnh mới
		Q->key = x;
		Q->LP = Q->RP = NULL;
		Root = Q;
	}
	else {
		if (x < Root->key)  insertBST(Root->LP, x);
		else if (x > Root->key)  insertBST(Root->RP, x);
		else return;
	}
}
 
//Xoa mot nut va sap lai cay
void  deleteNode(Node*& P) {	//Xóa nút P & sắp lại cây
	Node* Q;
	Node* R;
	if (P->LP == NULL) {	//Xóa nút chỉ có cây con phải
		Q = P;
		P = P->RP;
	}
	else	if (P->RP == NULL) 	//Xóa nút chỉ có cây con trái
	{
		Q = P;
		P = P->LP;
	}
	else {		 	//Xóa nút có 2 cây con
		Q = P->LP;
		if (Q->RP == NULL) {
			P->key = Q->key;
			P->LP = Q->LP;
		}
		else {
			do {		//Dùng R để lưu parent của Q
				R = Q;
				Q = Q->RP;
			} while (Q->RP != NULL);
			P->key = Q->key; 	//Lấy giá trị ở Q đưa lên
			R->RP = Q->LP;	//Chuyển con của Q lên vị trí Q
		}
	}
	delete  Q;			//Xoá Q
}
 
// Xoa nut tren cay
void  deleteBST(Node*& Root, int  x) {
	if (Root != NULL) {
		if (x < Root->key)  deleteBST(Root->LP, x);
		else  if (x > Root->key)  deleteBST(Root->RP, x);
		else  deleteNode(Root);		//Xoá gốc của cây
	}
}
 
//tinh tong khoa tren cay - duyet cay theo thu tu sau
int  sumBST(Node* Root) {
 
	if (Root == NULL) return 0;
	int sumLeftBST = sumBST(Root->LP);
	int sumRightBST = sumBST(Root->RP);
	return sumLeftBST + sumRightBST + Root->key;
	//return sumBST(Root->LP) + Root->key + sumBST(Root->RP);
}
 
 
//Dem so phan tu tren cay - Duyet cay theo thu tu giua
int countTree(Node* Root) { 
	if (Root == NULL)
		return 0;
	else 
		return countTree(Root->LP) + 1 + countTree(Root->RP);
}
 
//Hien thi cac nut tren cay - duyet cay theo thu tu truoc
void  displayBST(Node* Root) {
	if (Root == NULL) return;
	cout << Root->key << "\t";
	displayBST(Root->LP);
	displayBST(Root->RP);
	}
 
//check cay nhi phan suy bien lech trai
bool checkLeftDegenerateBTree(Node* Root)
{
	// check if node is NULL or is a leaf node
	if (Root == NULL || (Root->LP == NULL &&
		Root->RP == NULL))
		return true;
 
	// check if node has two children if
	// yes, return false
	if (Root->LP && Root->RP)
		return false;
	else if (Root->LP)
		return checkLeftDegenerateBTree(Root->LP);
	return false;
}
 
//check cay nhi phan suy bien lech phai
bool checkRightDegenerateBTree(Node* Root)
{
	// check if node is NULL or is a leaf node
	if (Root == NULL || (Root->LP == NULL &&
		Root->RP == NULL))
		return true;
 
	// check if node has two children if
	// yes, return false
	if (Root->LP && Root->RP)
		return false;
	else if (Root->RP)
		return checkRightDegenerateBTree(Root->RP);
	return false;
}

struct GTNode {
    int data;
    GTNode* firstChild;
    GTNode* nextSibling;
};
 
struct BinaryNode {
    int data;
    BinaryNode* left;
    BinaryNode* right;
};
 
BinaryNode* convertToBinaryTree(GTNode* root) {
    if (root == NULL) return NULL;
 
    BinaryNode* bNode = new BinaryNode;
    bNode->data = root->data;
    bNode->left = convertToBinaryTree(root->firstChild);   // Con đầu thành nhánh trái
    bNode->right = convertToBinaryTree(root->nextSibling); // Anh em kế thành nhánh phải
 
    return bNode;
}
 
int main()
{
	Node* root;
	initialBST(root);
	insertBST(root, 31);
	insertBST(root, 15);
	insertBST(root, 10);
	insertBST(root, 12);
	insertBST(root, 48);
	insertBST(root, 35);
	insertBST(root, 60);
	insertBST(root, 32);
	insertBST(root, 40);
	insertBST(root, 55);
	insertBST(root, 49);
	insertBST(root, 53);
	insertBST(root, 56);
	insertBST(root, 59);
	insertBST(root, 70);
	insertBST(root, 66);
	insertBST(root, 90);
	insertBST(root, 6);
	displayBST(root);
	cout << "\n";
	cout << " xoa 6\n";
	deleteBST(root, 6);
	displayBST(root);
}
 
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
 
// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
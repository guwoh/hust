#include <iostream>
using namespace std;

template <typename _T> 
class Matrix{
	_T **data;	// con trỏ cấp 2 
	int nbRow, nbCol;	// số hàng và số cột 
	void createData(){
		data = new _T*[nbRow];	// cấp phát động hàng 
		for (int i = 0; i < nbRow; i++){
			data[i] = new _T[nbCol];	// cấp phát động cột
		}
	}
	void createData(int m, int n){	// sử dụng hàm để chuyền tham số m và n tương ứng với nbRow và nbCol
		nbRow = m;
		nbCol = n;
		createData();
		// vì mặc định sẽ là private nên cần một hàm để truyền giá trị cho các biến private 
	}
	void deleteData(){
		for (int i = 0; i < nbRow; i++)
			delete[] data[i];	// xóa hết hàng
		delete[] data;	// xóa biến data 
	}
public:
	initMatrix(int m, int n = 0){
		if (n != 0) // ma trận mxn
			createData(m, n); 
		else createData(m, m);	// ma trận vuông 
	}
	insertMatrix(int m, int n, const _T *input){
		createData(m, n);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				data[i][j] = input[j + n*i];
	}
	void print(){	// display the matrix
		for (int i = 0; i < nbRow; i++){
			for (int j = 0; j < nbCol; j++)
				cout << data[i][j] << "\t";
			cout << "\n";
		}
	}
	_T getElement(int i, int j){	// getElement i j 
		return data[i][j];
	}
	void setElement(int i, int j, _T value){	// setElement i j with input 
		data[i][j] = value;
	}
	Matrix operator+(Matrix x){	// truyen mot ma tran x can tinh toan 
		Matrix result(nbRow, nbCol); 	// intit 1 ma tran la ma tran ket qua
		for (int i = 0; i < nbRow; i++)
			for (int j = 0; j < nbCol; j++)
				result.setElement(i, j, data[i][j] + x.getElement(i, j));	// set cac phan tu trong ma tran result bang tong cua data va matrix x  
		return result;
	}
	Matrix operator*(Matrix x){
		Matrix result(nbRow, nbRow);
		for (int i = 0; i < nbRow; i++)
			for (int j = 0; j < nbRow; j++){
				_T sum = 0;
				for (int k = 0; k < nbCol; k++)
					sum = sum + data[i][k] * x.getElement(k, j);
				result.setElement(i, j, sum);
 			}
 		return result;
	}
	Matrix operator-(Matrix x)
	{

	}
};

int main(){
	int input[6] {1,2,3,4,5,6};
	int input2[6] {7, 8, 9, 10, 11, 12};
	Matrix<int> m1(2, 3, input);
	Matrix<int> m2(3, 2, input2);
	Matrix<int> m3 = m1 * m2;
	m1.print();
	m2.print();
	m3.print();
}

//Viết hàm tính tổng bình phương của các số từ 1 đến N bằng đệ quy
//Viết hàm tính a mũ b bằng đệ quy
//Viết hàm đếm số chữ số của một số nguyên dương bằng đệ quy
//Viết hàm kiểm tra xem 1 chuỗi có đối xứng hay không bằng đệ quy
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

//Viết hàm tính tổng bình phương của các số từ 1 đến N bằng đệ quy
 int s(int n)
 {
 	if ( n == 1 ) return 1;
 	return n*n + s((n - 1));
 }
 //Viết hàm tính a mũ b bằng đệ quy
int tinhSoMu(int a, int b)
{
 	if( b == 0) return 1;
 	return a*tinhSoMu(a, b - 1);
}
//Viết hàm đếm số chữ số của một số nguyên dương bằng đệ quy
int demChuSo(int n) {
    if (n == 0) return 0;  // Điều kiện dừng, không đếm nữa
    return 1 + demChuSo(n / 10);
}
//Viết hàm kiểm tra xem 1 chuỗi có đối xứng hay không bằng đệ quy
bool kiemTraDoiXung(char *chuoi, int left, int right)
{
	if( left >= right) return true; // da kiem tra xong, dieu kien dung ham
	if( chuoi[left] != chuoi[right]) return false; // chuoi khong trung khop
	return kiemTraDoiXung(chuoi, left + 1, right - 1);
}

int main()
{

/*   y 1 */
//	int n; 
//	printf("Nhap so n: ");
//	scanf("%d", &n);
//	printf(" Tong binh phuong cac so tu 1 den n la: %d", s(n));
	
/*   y 2 */
//	int a,b; 
//	printf("Nhap 2 so a va b: ");
//	scanf("%d %d", &a, &b);
//	printf(" a mu b la: %d", tinhSoMu(a,b));

/*   y 3 */
//    int n;
//    printf("Nhap so nguyen n: ");
//    scanf("%d", &n);
//    
//    if (n == 0) 
//        printf("So chu so: 1\n");  // Trường hợp đặc biệt, 0 có 1 chữ số
//    else
//        printf("So chu so: %d\n", demChuSo(n < 0 ? -n : n));  // Xử lý số âm
//     
   
/*   y 4 */
	char s[1000];
	printf("Nhap chuoi: ");
	scanf("%s", s);
	
	int doDai = strlen(s);
	
	int temp = kiemTraDoiXung(s, 0, doDai - 1);
	
	if(temp == 1) printf("Chuoi doi xung!");
	else if (temp == 0) printf("Chuoi khong doi xung!");

	return 0;	
}







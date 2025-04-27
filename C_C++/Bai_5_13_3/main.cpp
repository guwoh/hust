#include <iostream>

/* Bài 5: Hàm và bài tập về hàm */

/* Cấp phát bộ nhớ động
       Sử dụng toán tử new và dùng xong phải dùng toán tử delete để giải phóng bộ nhớ */

/* Hàm: - có hai kiểu: hàm trả về và hàm không trả về
        - Prototype của hàm: kiểu + tên hàm + (danh sách biến)
        - Tham số mặc định của hàm
        - Quy tắc truyền đối số: truyền con trỏ, truyền tham chiếu, truyền giá trị
            + Ví dụ: void change1(int a){a++ ; } // Truyền giá trị
                     void change2(int *p){(*p)++ ; } // Truyền con trỏ
                     void change3(int &r){r++ ; } // Truyền tham chiếu
        - Hàm inline: tiết kiệm bộ nhớ và không nên chứa các vòng lặp thường dùng trong bộ nhớ eo hẹp về dung lượng bộ nhớ
        - Con trỏ hàm: dùng con trỏ trỏ đến hàm
        - Tham chiếu hàm: Không nên dùng
        - Xếp chồng hàm: có thể có nhiều hàm cùng tên và chương trình phân biệt bằng kiểu và đầu vào và từ gọi hàm phù hợp
        - Hàm mẫu: thường dùng trong viết thư viện */

// vd về prototype của hàm (Mục lục của hàm)
int factorial(int ) ;
double power(double, int ) ;
extern void foo(int) ;
extern void goo(int , int) ; // extern để tìm tìm trong các file khác không trong file main cùng tên

// Ví dụ về tham số mặc định
int I(int x, int n=2) ; // Nếu chạy I(x) ; vẫn đúng
// Ví dụ truyền dối số trong hàm
void change1(int a){a++ ; } // Truyền giá trị
void change2(int *p){(*p)++ ; } // Truyền con trỏ
void change3(int &r){r++ ; } // Truyền tham chiếu

// ví dụ về con trỏ hàm
int a1(int x)
{
    return (x + 1 ) ;
}

int a3(float x)
{
    return (x + 1 ) ;
}

int a2(double x)
{
    return (x + 1 ) ;
}

int xuly(int x, int (*f)(int)) // Nếu không có tham số trong hàm thì vẫn phải để () ;
{
    return f(x) ;
}

// Ví dụ về tham chiếu hàm
// Giải thích: x -> &a = x -> &MAX = a hoặc b
int &MAX(int &a, int &b)
{
    return (a>b?a:b) ;
}

// Ví dụ về hàm mẫu
template <class T>
T ABS(T x)
{
    return (x<0?-x:x) ;
}

int main()
{
    int x = 10 ;
    float y = -5.0 ;

    /* Ví dụ của tham chiếu của biến số
    int a = 25 ;
    int &r = a ; // r là tham chiếu của a  */

    /* Cấp phát bộ nhớ động
    int *p ;
    p = new int ; // Cấp phát vùng nhớ 4 byte cho p
    delete p ; // Giải phóng vùng nhớ

    p = new int [10] // Khai báo một vùng nhớ mới cho con trỏ p
    delete []p */

    /* Ví dụ của truyền đối số trong hàm
    change1(x) ;
    std::cout<<x<<"\n" ;
    change2(&x) ;
    std::cout<<x<<"\n" ;
    change3(x) ;
    std::cout<<x<<"\n" ; */

    // std::cout<<xuly(x, &a1) ;

    /* Ví dụ của tham chiếu hàm
    int Max1 = MAX(x, y) ;
    std::cout<<Max1<<"\n" ;
    MAX(x,y) = 1 ;
    std::cout<<x<<" "<<y ; // Giải thích như trên */

    /* Ví dụ về hàm mẫu
    std::cout<<ABS(x)<<"\n" ;
    std::cout<<ABS(y) ; */

    return 0;
}

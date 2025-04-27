#include <iostream>

/* Bài 1*/
// Hệ thập lục phân(Hexa) thường dùng
// Kí tự \0 là một kí tự đặc biệt null(giá trị bằng 0) dùng để kết thúc chuỗi

int main()
{
    std::cout<<"Hello 'world'\n" ;
    std::cout<<"Hello \"world\" \n" ;
    std::cout << "Hello world!" << std::endl;

    int x = 10 ;
    int y = 5 ;

    {
        int x = 5 ;
        y = y + x ;
        x++ ;
    }

    std::cout<<x<<" "<<y<<"\n" ;
    return 0;
}

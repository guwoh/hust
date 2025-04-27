#include <iostream>
#include <cstdlib>
#include <string.h>

/* Bài 4: mảng và con trỏ */
// Mảng: các dữ liệu của mảng sẽ được lưu trữ liên tiếp nhau trong bộ nhớ
      // Dùng vị trí của ô nhớ đầu để lưu trữ mảng
      // Các byte nhỏ lưu trước, byte lớn lưu sau
// Con trỏ: Nếu mà biến x có kiểu int mà con trỏ z kiểu char trỏ đến x thì z là một mảng có 4 phần tử 1 byte
         // Có thể dùng con trỏ để thao tác với mảng
         // Nếu A là một biến kiểu mảng  thì  (A + i) chính là địa chỉ của A[i]
         // '*' vừa dùng để khai báo con trỏ và cũng là toán tử truy cập nội dung
         // Trong hệ hexa thì 1 byte gồm 2 kí tự: 0x00, 0x31, ...
int main()
{
    /*Các kiểu khởi tạo một mảng*/
    // int a[3] ;
    // int b[3] = {1,2,3} ;
    // int c[] = {1,2,3} ;

    /*Khai báo một số ngẫu nhiên từ 1 đến 1000*/
    // int x = rand() ;
    // x = (x % 1000) + 1 ;

    /* MỘT SỐ BÀI TOÁN LIÊN QUAN ĐẾN MẢNG KÍ TỰ
    char s[50] ;
    gets(s) ;
    for(int i=0; i<strlen(s); i++)
    {
        if((s[i] >= 65) && (s[i] <= 90))
        {
            s[i] += 32 ;
        }

        std::cout<<s[i] ;
    }

    int res = 0 ;
    for(int i=0; i<strlen(s); i++)
    {
        if((s[i] >= '0') && (s[i] <= '9'))
        {
            res = res*10 + (s[i]-'0') ;
        }
    }

    std::cout<<"\n"<<res ;
    */

    /*
    char s[100] = "1234567890" ;
    short *p = (short *)s ; // "12", "34", "56", "78", "90"
                            // 0x3132, 0x3334, 0x3536, 0x3738, 0x3940
    std::cout<<p[0] ;
    *(p += 2) = 0x0041 ; // Trong bộ nhớ: 0x4100
    std::cout<<"\n"<<s ; // "12", "34", "A" sau A là byte kết thúc chuỗi nên chuỗi dừng ngay
    */

    int x[1] = {123456} ; // 0x0001E240
    char *y = (char *)x ; // y sẽ có các phần tử 0x40, 0xE2, 0x01, 0x00
    std::cout<<y[1] ; // 0xE2
    return 0;
}

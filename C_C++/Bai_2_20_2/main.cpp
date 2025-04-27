#include <iostream>
#include <math.h>

/*Bài 2: Thực hành*/

// Giải phương trình bậc hai
void PT_bac_2()
{
    double a,b,c, delta ;
    std::cout<<"Nhap ba so a,b,c theo thu tu do: " ;
    std::cin>>a>>b>>c ;

    delta = b*b - 4*a*c ;
    if(a == 0)
        std::cout<<"Phuong trinh khong phai la phuong trinh bac 2!\n" ;
    else
    {
        if(delta < 0)
            std::cout<<"Phuong trinh vo nghiem!\n" ;
        else if(delta == 0)
            std::cout<<"Phuong trinh co mot nghiem duy nhat la: x = "<<-(b)/2*a ;
        else
            std::cout<<"Phuong trinh co hai nghiem phan biet: x1 = "<<(-(b)+sqrt(delta))/2*a<<"\tx2 = "<<(-(b)-sqrt(delta))/2*a ;
    }
}

// In ra các số nguyên tố từ 2 đến n nhập từ bàn phím
bool NT(int n)
{
    for(int i=2; i<=n/2; i++)
    {
        if(n%i == 0)
            return false ;
    }

    return true ;
}

void soNT()
{
    int n ;
    std::cout<<"Nhap mot so n: " ;
    std::cin>>n ;

    if(n <= 1)
        std::cout<<"So khong hop le!\n" ;
    else
    {
        for(int i=2; i<=n; i++)
        {
            if(NT(i))
                std::cout<<i<<" " ;
        }
    }
}

// In ra màn hình lịch mẫu năm 2025: dùng thuật toán Zeller
int isLeapYear(int year)
{
    return (!(year % 4) && (year % 100) || !(year % 400)) ;
}

int Zeller(int date, int month, int year)
{
    if(month == 1)
    {
        month = 13 ;
        year-- ;
    }
    if(month == 2)
    {
        month = 14 ;
        year-- ;
    }

    int k = year % 100 ; // k là năm của thế kỉ
    int j = year / 100 ; // j là thế kỉ
    int h = date + (13*(month + 1))/5+k+k/4+j/4+5+j ;
    h = h % 7 ;

    return (h == 0?6:h-1) ;
}

void Lich()
{
    int year, top, zeller ;
    std::cout<<"Hay nhap thang, nam theo thu tu do: " ;
    std::cin>>year ;
    char months[12][10] = {
        "January", "February", "March", "April", "May",
        "June", "July", "August", "September", "October", "November", "December"
    } ;
    char daysow[7][4] = {'S', 'M', 'T', 'W', 'T', 'F', 'S'} ;
    putchar('\n') ;

    for(int m=1; m<=12; m++, printf("\n"))
    {
        printf("%3s\n", months[m-1]) ;

        switch(m){
            case 2:
                top = isLeapYear(year)?29:28 ;
                break ;
            case 4: case 6: case 9: case 11:
                top = 30 ;
                break ;
            default :
                top = 31 ;
                break ;
        }

        zeller = Zeller(1,m,year) ;
        int days[6][7] = {0} ;
        int *d = days[0] ;
        for(int i=0; i<zeller; i++)
            d++ ;
        for(int i=0; i<top; i++)
            *(d++) = i + 1 ;
        for(int i=0; i<7; i++)
            printf("%3s", daysow[i]);

        std::cout<<std::endl ;
        int row = (zeller + top)>35?6:5 ;
        for(int i=0; i<row; i++, putchar('\n'))
        {
            for(int j=0; j<7; j++)
            days[i][j] == 0?(printf("%3s", " ")):(printf("%3d", days[i][j])) ;
        }
    }
}

int main()
{
    Lich() ;

    return 0;
}

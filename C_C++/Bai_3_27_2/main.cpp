#include <iostream>
#include <math.h>

/* Bài 3: Luyện tập */

// Bài 1: Nhập một số nguyên dương và in ra dãy số fibo đến x
// Bài 2: Tính căn bậc hai của một số thực dương

// Bài 1:
int fibo(int n)
{
    if((n == 1) || (n == 2))
        return 1 ;
    else
        return (fibo(n-1) + fibo(n-2)) ;
}

// Bài 2:
float SQRT(float &n)
{
    float epsilon = 0.000001 ;
    float low = 0 ;
    float high = n ;
    float tb = (high + low)/2 ;
    float result = 0 ;
    float temp = 0 ;

    if(n < 0)
        return 0 ;
    else
    {
        while((high - low) > epsilon)
        {
            temp = tb*tb ;
            if(temp < n)
            {
                low = tb ;
            }
            else if(temp > n)
            {
                high = tb ;
            }
            else
                break ;

            tb = (low + high)/2 ;
        }

        result = tb ;
    }

    return result ;
}

int main()
{
    float n,i ;
    std::cout<<"Nhap mot so nguyen duong n: " ;
    std::cin>>n ;

    /* Bài 1:
    i = 1 ;
    while(fibo(i)<= n)
    {
        std::cout<<fibo(i)<<" " ;
        i++ ;
    }
    */

    std::cout<<SQRT(n) ;
    return 0;
}

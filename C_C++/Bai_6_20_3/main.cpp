#include <iostream>

/*Bài 6: Bài tập về hàm */

// Bài 1:
bool IsSorted(int a[], int n, bool &t)
{
    for(int i=0; i<n; i++)
    {
        if((t == 1) && (a[i] > a[i+1]))
        {
            return 0 ;
        }

        if((t == 0) && (a[i] < a[i+1]))
            return 0 ;
    }

    return 1 ;
}

// Bài 2: Giải thuật bubble sort
void BubbleSort(int a[], int &n)
{
    int temp ;
    for(int i=n-1; i>=1; i--)
    {
        for(int j=0; j<i; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j] ;
                a[j] = a[j+1] ;
                a[j+1] = temp ;
            }
        }
    }
}

int main()
{
    int a[5] = {0, 3, 4, 2, 5} ;
    int n = 5 ;
    //bool t = 0 ;

    BubbleSort(a,n) ;
    //std::cout<<IsSorted(a,5,t)<<"\n" ;

    for(int i=0; i<n; i++)
    {
        std::cout<<a[i]<<" " ;
    }

    return 0;
}

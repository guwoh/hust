#include <iostream>
#include <bits/stdc++.h>

/*Bài 7: Hướng đối tượng*/
/* Struct trong c */
/* Class trong c++
    - Hàm khởi tạo: được gọi khi gọi một đối tượng, có nhiều hàm khởi tạo miễn là nó không nhầm lẫn với nhau
    - Hàm hủy: dùng khi hủy một đối tượng
    - Public: nếu không có public thì mặc định là private, có thể dùng các thành phần bên trong class ở bên ngoài class
    - Private: nếu một đối tượng ở trạng thái private thì không thể truy cập được khi ở ngoài class
    - Hàm toán tử: */

// Ví dụ
class SinhVien
{
    private:
        int mssv ;
        char *name ;
    public:
        SinhVien(int masoSV)
        {
            mssv = masoSV ;
        }

        void nhapName(char *ht)
        {
            name = ht ;
        }

        int getMssv()
        {
            return mssv ;
        }

        void setMssv(int masosv)
        {
            if((masosv >= 2000) && (masosv <= 40000000))
                mssv = masosv ;
            else
                std::cout<<"Error\n" ;
        }

        int operator>(SinhVien x)
        {
            return mssv > x.getMssv() ;
        }
};

// Bài tập về phân số
class PhanSo
{
    private:
        int tuso ;
        int mauso ;
        void RutGon()
        {
            if(mauso == 0)
                std::cout<<"Error\n" ;

            if(mauso < 0)
            {
                tuso = -tuso ;
                mauso = -mauso ;
            }

            int rutgon = std::__gcd(tuso, mauso) ;
            if(rutgon != 0)
            {
                tuso = tuso/rutgon ;
                mauso = mauso/rutgon ;
            }
        }
    public:
        PhanSo(int tu=0, int mau=1)
        {
            tuso = tu ;
            mauso = mau ;
            RutGon() ;
        }

        int get_tuso()
        {
            return tuso ;
        }

        int get_mauso()
        {
            return mauso ;
        }

        void set_tuso(int TuSo)
        {
            tuso = TuSo ;
        }

        void set_mauso(int MauSo)
        {
            mauso = MauSo ;
        }

        PhanSo operator+(const PhanSo &phanso2)
        {
            int tuso_cong = tuso*phanso2.mauso + mauso*phanso2.tuso ;
            int mauso_cong = mauso*phanso2.mauso ;

            return PhanSo(tuso_cong, mauso_cong) ;
        }

        PhanSo operator-(PhanSo phanso2)
        {
            int tuso_tru = tuso*phanso2.get_mauso() - phanso2.get_tuso()*mauso ;
            int mauso_tru = mauso*phanso2.get_mauso() ;

            return PhanSo(tuso_tru, mauso_tru) ;
        }

        PhanSo operator*(PhanSo phanso2)
        {
            int tuso_nhan = tuso*phanso2.get_tuso() ;
            int mauso_nhan = mauso*phanso2.get_mauso() ;

            return PhanSo(tuso_nhan, mauso_nhan) ;
        }

        friend std::ostream& operator<<(std::ostream& os, const PhanSo &ps) ;
};

std::ostream& operator<<(std::ostream &os, const PhanSo &ps)
{
    os << ps.tuso ;
    if (ps.mauso != 1)
        os << "/" << ps.mauso ;
    return os;
}

int main()
{
    PhanSo A(2,3) ;

    PhanSo B(5,4) ;

    std::cout<<A*B<<"\n" ;
    std::cout<<A - B<<"\n" ;
    std::cout<<A + B<<"\n" ;


    /*SinhVien A(200000) ;
    A.setMssv(20001000)
    SinhVien B(300000) ;
    B.setMssv(3000010) ;

    if(A > B)
        std::cout<<"Mssv A > Mssv B" ;
    else
        std::cout<<"Mssv A <= Mssv B" ;*/

    return 0;
}

#include<iostream>
using namespace std;

template <typename t> class test
{
	t so;
public:
	void getSo(t a)
	{
		so = a;
	}
	t hienThi()
	{
		return so;
	}
};

int main()
{
	test<int> a;
	a.getSo(1000);
	cout<< "\n" << a.hienThi() << endl;

	return 0;


}
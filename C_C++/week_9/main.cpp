/**
 * đọc ghi file 
 *
 * 
 * 
*/
#include<iostream>
#include<fstream>

using namespace std;

/**
 * tim xem item co trung ten hay khong, neu co thi + them vao so luong
 * print tat ca cac item trong list
*/
class Item
{
	int id;
	int price;
	int number;
public:
	Item(int i, int p, int n)
	{
		id = i;
		price = p;
		number = n;
	}
	void print()
	{
		cout << "id:" << id << "price:" << price << "number:" << number;
	}
	int getId()
	{
		return id;
	}
	void changePrice(int newPrice)
	{
		price += nb;

	}
	void addNumber()
	{

	}

};
class food : public newItem{
	double weight;
	char expireDate[10];
public:
	food(int j, int p, int n, double w, char *eD):Item(i, p, n)
	{
		weight = w;
		expireDate = eD;
	}
	void print()
	{
		Item::price(); // goi ham o class me bang dau ::
		cout << "weight:" << weight << ",expireDate:" << expireDate << "\n";

	}
}

int main()
{
	// //prototype ofstream f1("link to file") 
	// ofstream f1("text.txt");	//open file
	// f1 << "Hello\ndsadsadsa\nfdfds\nfdfds";
	// f1.close();
	// ifstream f2("text.txt");	// read file 
	// char line[100];	//  buffer
	// while(f2.getline(line, 100, '\n'))
	// 	cout << line << "\n";
	// // f2.getline(line, 100, '\n');
	// // cout<< line;
	// f2.close();
	Item* listItem[100];
	int totalItem = 0;
	cout << "welcome\n";
	cout << "1\n";
	cout << "2\n";
	// cout << "3\n";
	// cout << "4\n";
	// cout << "5\n";
	cout << "choice:\n";
	int choice;
	cin >> choice;
	while(choice != 9){
		if( choice == 1)
		{
			cout << "Input id, price and number";
			int i, p, n;
			cin >> i >> p >> n;
			Item *newItem = new Item(i, p, n);
			listItem[totalItem] = newItem;
			listItem[totalItem]->print();// con tro thi dung ->, bien binh thuong thi dung dau .
			totalItem++;
			}
		else if(choice == 2);
		else break;
	}

	return 0;

}
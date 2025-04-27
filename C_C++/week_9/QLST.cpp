#include <iostream>

using namespace std;

class Item{
	int id;
	int price;
	int number;
public:
	Item(int i, int p, int n){
		id = i;
		price = p;
		number = n;
	}
	virtual void print(){
		cout << "id:" << id << ",price:" << price << ",nb:" << number << "\n";
	}
	int getId(){
		return id;
	}
	void changePrice(int newPrice){
		price = newPrice;
	}
	void addNumber(int nb){
		number += nb;
	}
};


class Food : public Item{ // lớp food kế thừa lớp Item 
	double weight;
	char *expireDate;
public:
	Food(int i, int p, int n, double w, char *eD):Item(i,p,n){
		weight = w;
		expireDate = eD;
	}
	void print(){
		Item::print();
		cout << "weight:" << weight << ",expire:" <<expireDate << "\n";
	}
};

int main(){
	Item *listItem[100];
	int totalItem = 0;
	cout << "Welcome to supermarket management\n";
	while (1){
		cout << "1. Add item\n";
		cout << "2. Display all items\n";
		cout << "3. Exit\n";
		cout << "Your choice:";
		int choice;
		cin >> choice;
		if (choice == 1){
			cout << "Item type (1. Food, 2. Item):";
			int type;
			cin >> type;
			if (type == 1){
				cout << "Input id, price, weight and expire date:";
				int i, p;
				double w;
				char eD[10];
				cin >> i >> p >> w >> eD;
				Food *f = new Food(i, p, 1, w, eD);
				listItem[totalItem] = f;
				totalItem++;
			}
			else {
				cout << "Input id, price and number:";
				int i, p, n;
				cin >> i >> p >> n;
				int idExist = 0;
				for (int j = 0; j < totalItem; j++)
					if (listItem[j]->getId() == i){
						listItem[j]->changePrice(p);
						listItem[j]->addNumber(n);
						idExist = 1;
						break;
					}				
				if (!idExist){
					Item *newItem = new Item(i, p, n);
					listItem[totalItem] = newItem;
					listItem[totalItem]->print();
					totalItem++;
				}
			}
		}
		else if (choice == 2){
			//print tat ca item trong list
			for (int i = 0; i < totalItem; i++)
				listItem[i]->print();
		}
		else
			break;
	}
}
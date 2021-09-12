#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Order {
	int id;
	string description;
	string status;
	void print() {
		cout << "ID: " << id <<
			"\nDescription: " << description <<
			"\nStatus: " << status << endl;
	}
};

void orderAdd(vector<Order>& vect);

void orderPrintAll(const vector<Order>& vect);

void orderFind(const vector<Order>& vect, const int& orderid);

int main() {
	int a;
	vector<Order> orders;
	bool key = true;
	while(key) {
		system("cls");
		
		cout << "Order handling\n" <<
			"\t1) Add an order\n" <<
			"\t2) Print all orders\n" <<
			"\t3) Find the order\n" <<
			"\t4) Exit\n";
		cin >> a;
		
		switch(a) {
			case 1: {
				orderAdd(orders);
				break;
			}
			case 2: {
				orderPrintAll(orders);
				break;
			}
			case 3: {
				int orderid;
				cout << "What is ID of this order? ";
				cin >> orderid;
				orderFind(orders, orderid);
				break;
			}
			case 4: {
				key = false;
				break;
			}
			default: {
				cout << "Repeat input." << endl;	
				system("pause");
			}
		};
	}
}


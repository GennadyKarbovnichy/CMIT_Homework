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

void orderAdd(vector<Order>& vect) {
	system("cls");
	Order neworder;
	neworder.id = vect.size() + 1;
	cout << "Write order description: ";
	cin >> neworder.description;
	cout << "Write order status: ";
	cin >> neworder.status;
	vect.push_back(neworder);
}

void orderPrintAll(const vector<Order>& vect) {
	system("cls");
	for(auto x : vect) {
		x.print();
		cout << "\n";
	}
	system("pause");
}

void orderFind(const vector<Order>& vect, const int& orderid) {
	system("cls");
	cout << "Trying to find your order...\n";
	for(auto x : vect) {
		if(x.id == orderid) {
			cout << "We found it! Look:\n";
			x.print();
			system("pause");
			return;
		}
	}
	cout << "The order was not found. Please try again.\n";
	system("pause");
}

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

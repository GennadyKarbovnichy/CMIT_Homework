#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Order {
	int id;
	string description;
	string status;
};

void orderPrint(const Order& ord);

void orderAdd(vector<Order>& vect, int ordersDeleted);

void orderPrintAll(const vector<Order>& vect);

int orderFind(const vector<Order>& vect, const int& orderid);

void orderEdit(vector<Order>& vect, const int& orderid);

void orderDelete(vector<Order>& vect, const int& orderid, int& ordersDeleted);

int main() {
	int a;
	int ordersDeleted = 0;
	vector<Order> orders;
	bool key = true;
	while(key) {
		system("cls");
		
		cout << "Order handling\n" <<
			"\t1) Add an order\n" <<
			"\t2) Print all orders\n" <<
			"\t3) Find the order\n" <<
			"\t4) Edit the order\n" <<
			"\t5) Delete the order\n" <<
			"\t6) Exit\n";
		cin >> a;
		
		switch(a) {
			case 1: {
				orderAdd(orders, ordersDeleted);
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
				orderid = orderFind(orders, orderid);
				if (orderid != 0) {
					cout << "We found it! Look:\n";
					orderPrint(orders[orderid - ordersDeleted - 1]);
					system("pause");
				}
				else {
					cout << "Order isn't found. Please try again.\n";
					system("pause");
				}
				break;
			}
			case 4: {
				int orderid;
				cout << "What is ID of this order? ";
				cin >> orderid;
				orderid = orderFind(orders, orderid);
				if (orderid != 0) {
					orderEdit(orders, orderid);
					system("pause");
				}
				else {
					cout << "Order isn't found. Please try again.\n";
					system("pause");
				}
				break;
			}
			case 5: {
				int orderid;
				cout << "What is ID of this order? ";
				cin >> orderid;
				orderid = orderFind(orders, orderid);
				if (orderid != 0) {
					orderDelete(orders, orderid, ordersDeleted);
					system("pause");
				}
				else {
					cout << "Order isn't found. Please try again.\n";
					system("pause");
				}
				break;
			}
			case 6: {
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


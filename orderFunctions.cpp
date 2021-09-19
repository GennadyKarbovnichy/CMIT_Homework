#include "order.h"

using namespace std;

struct Order;

void orderPrint(const Order& ord) {
	cout << "ID: " << ord.id <<
		"\nDescription: " << ord.description <<
		"\nStatus: " << ord.status << endl;
}

void orderAdd(vector<Order>& vect, int ordersDeleted) {
	system("cls");
	Order neworder;
	neworder.id = vect.size() + ordersDeleted + 1;
	cout << "Write order description: ";
	cin.ignore(32767, '\n');
	getline(cin, neworder.description);
	cout << "Write order status: ";
	getline(cin, neworder.status);
	vect.push_back(neworder);
}

void orderPrintAll(const vector<Order>& vect) {
	system("cls");
	for(auto x : vect) {
		orderPrint(x);
		cout << "\n";
	};
	system("pause");
	return;
}

int orderFind(const vector<Order>& vect, const int& orderid) {
	system("cls");
	cout << "Trying to find your order...\n";
	for(auto x : vect) {
		if(x.id == orderid) {
			return orderid;
		}
	}
	return 0;
}

void orderEdit(vector<Order>& vect, const int& orderid) {
	cin.ignore(32767, '\n');
	cout << "Write order description: ";
	getline(cin, vect[orderid - 1].description);
	cout << "Write order status: ";
	getline(cin, vect[orderid - 1].status);
}

void orderDelete(vector<Order>& vect, const int& orderid, int& ordersDeleted) {
	vect.erase(vect.begin() + orderid - ordersDeleted - 1);
	ordersDeleted += 1;
}

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

void orderPrintAll(const vector<Order>& vect) {
	system("cls");
	for(auto x : vect) {
		orderPrint(x);
		cout << "\n";
	};
	system("pause");
	return;
}


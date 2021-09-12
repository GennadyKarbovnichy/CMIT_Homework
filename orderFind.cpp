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
//	cout << "The order was not found. Please try again.\n";
//	system("pause");
}

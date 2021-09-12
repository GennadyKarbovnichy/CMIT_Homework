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

void orderPrintAll(const vector<Order>& vect) {
	system("cls");
	for(auto x : vect) {
		x.print();
		cout << "\n";
	};
	system("pause");
	return;
}


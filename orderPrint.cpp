#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Order {
	int id;
	string description;
	string status;
};

void orderPrint(const Order& ord) {
	cout << "ID: " << ord.id <<
		"\nDescription: " << ord.description <<
		"\nStatus: " << ord.status << endl;
}
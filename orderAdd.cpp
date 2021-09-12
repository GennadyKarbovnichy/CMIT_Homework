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

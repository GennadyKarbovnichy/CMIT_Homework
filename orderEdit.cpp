#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Order {
	int id;
	string description;
	string status;
};

void orderEdit(vector<Order>& vect, const int& orderid) {
	cin.ignore(32767, '\n');
	cout << "Write order description: ";
	getline(cin, vect[orderid].description);
	cout << "Write order status: ";
	getline(cin, vect[orderid].status);
}
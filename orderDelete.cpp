#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Order {
	int id;
	string description;
	string status;
};

void orderDelete(vector<Order>& vect, const int& orderid, int& ordersDeleted) {
	vect.erase(vect.begin() + orderid - ordersDeleted - 1);
	ordersDeleted += 1;
}
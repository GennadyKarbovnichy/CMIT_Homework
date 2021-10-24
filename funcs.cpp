#include "order.h"

using namespace std;

struct Order;

void orderPrint(const Order &ord) {
	cout << "ID: " << ord.id << "\nDescription: " << ord.description << "\nStatus: " << ord.status << endl;
}

void orderSave(const Order &ord) {
	ofstream orderSaver;
	orderSaver.open("Orders.csv", ios::app);
	if (!orderSaver) {
		cout << "Oh sorry, this order will be saved only for now!";
		return;
	}
	orderSaver << ord.id << ";"
	           << ord.description << ";"
	           << ord.status << "\n";
	orderSaver.close();
}

Order orderAdd(const vector<Order> &vect) {
	Order orderNew;
	system("cls");

	orderNew.id = vect.size() + 1;
	cout << "Write order description: ";
	cin.ignore(32767, '\n');
	getline(cin, orderNew.description);
	cout << "Write order status: ";
	getline(cin, orderNew.status);
	cout << "Saving your order...";
	orderSave(orderNew);
	return orderNew;
}

void orderPrintAll(const vector<Order> &vect) {
	system("cls");
	for (int i = 0; i < vect.size(); i++) {
		if (not vect[i].isDeleted)
			orderPrint(vect[i]);
	}
	system("pause");
}

Order orderFind(const vector<Order> &vect) {
	int orderId;
	cout << "What is the ID of this order?";
	cin >> orderId;
	system("cls");
	cout << "Trying to find your order...\n";
	for (int i = 0; i < vect.size(); i++) {
		if (vect[i].id == orderId and not vect[i].isDeleted) {
			cout << "We found it!" << endl;
			return vect[i];
		}
	}
	cout << "We didn't find it..." << endl;
	Order orderEmpty;
	return orderEmpty;
}

Order orderEdit(Order ord) {
	system("cls");
	Order orderNew;
	orderNew.id = ord.id;
	cout << "Enter new order description: ";
	cin >> ord.description;
	cout << "Enter new order status: ";
	cin >> ord.status;
	return orderNew;
}

vector<Order> orderReplace(vector<Order> &vect, Order &ord) {
	vect[ord.id - 1] = ord;
	return vect;
}

Order orderDelete(Order ord) {
	ord.isDeleted = true;
	return ord;
}

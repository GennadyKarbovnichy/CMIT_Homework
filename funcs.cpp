#include "order.h"

using namespace std;

struct Order;

void orderPrint(const Order &ord) {
	cout << "ID: " << ord.id << "\nDescription: " << ord.description << "\nStatus: " << ord.status << endl;
}

//void orderSave(const Order &ord, const string filename) {
//	ofstream orderSaver;
//	orderSaver.open(filename, ios::app);
//	if (!orderSaver) {
//		cout << "Oh sorry, this order will be saved only for now!";
//		return;
//	}
//	orderSaver << ord.id << ";"
//	           << ord.description << ";"
//	           << ord.status << "\n";
//	orderSaver.close();
//}

Order orderAdd(const vector<Order> &vect) {
	Order orderNew;
	system("cls");

	orderNew.id = vect.size() + 1;
	orderNew.isDeleted = false;
	cout << "Write order description: ";
	cin.ignore(32767, '\n');
	getline(cin, orderNew.description);
	cout << "Write order status: ";
	getline(cin, orderNew.status);
//	cout << "Saving your order...";
//	orderSave(orderNew, "Orders.csv");
	return orderNew;
}

void orderPrintAll(const vector<Order> &vect) {
	system("cls");
	for (int i = 0; i < vect.size(); i++) {
		if (not vect[i].isDeleted) {
			orderPrint(vect[i]);
			cout << endl;
		}
	}
	system("pause");
}

Order orderFind(const vector<Order> &vect) {
	int orderId;
	cout << "What is the ID of this order?\n >> ";
	cin >> orderId;
	system("cls");
	cout << "Trying to find your order...\n";
	for (int i = 0; i < vect.size(); i++) {
		if (vect[i].id == orderId and not vect[i].isDeleted) {
			cout << "We found it!\n" << endl;
			return vect[i];
		}
	}
	cout << "We didn't find it..." << endl;
	Order orderEmpty;
	return orderEmpty;
}

Order orderEdit(Order ord) {
	system("cls");
	if (ord.description != "") {
		Order orderNew;
		orderNew.id = ord.id;
		cout << "Enter new order description: ";
		cin.ignore(32767, '\n');
		getline(cin, orderNew.description);
		cout << "Enter new order status: ";
		getline(cin, orderNew.status);
		return orderNew; //returns edited order
	}
	return ord; //returns empty order
}

vector<Order> orderReplace(vector<Order> &vect, Order &ord) {
	if (ord.id - 1 <= vect.size() and ord.description != "") {
		vect[ord.id - 1] = ord;
		cout << "Done!\n";
	} else { //replacing orders which ids are bigger than the max id of vector's order
		cout << "Oh no, you're trying to edit\n" <<
				"an order that doesn't exist!" << endl;
	}
	system("pause");
	return vect;
}

Order orderDelete(Order ord) {
	cout << "Deleting your order..." << endl;
	if (not ord.isDeleted)
		ord.isDeleted = true;
	return ord;
}

//vector<Order> ordersLoad(const string filename) {
//	vector<Order> vect;
//	ifstream orderLoader(filename);
//	if(!orderLoader) {
//		cout << "Oh no, I can't load your saved orders!";
//	} else {
//		
//	}
//	orderLoader.close();
//	orderLoader.open(filename, ios::trunc);
//	orderLoader.close();
//}

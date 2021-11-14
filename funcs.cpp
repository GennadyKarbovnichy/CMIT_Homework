#include "order.h"
#include <sstream>
#include <iterator>

using namespace std;

struct Order;

template <typename Out>
void split(const string &s, char delim, Out result) {
   	istringstream iss(s);
   	string item;
   	while (getline(iss, item, delim)) {
   	    *result++ = item;
   	}
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    if(s != "") {
	    split(s, delim, back_inserter(elems));
    } else {
    	elems.push_back("end");
	}
	return elems;
}

void orderPrint(const Order &ord) {
	cout << "ID: " << ord.id << "\nDescription: " << ord.description << "\nStatus: " << ord.status << endl;
}

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
	if(orderNew.description == "" && orderNew.status == "") orderNew.isDeleted = true;
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

Order orderEdit(Order &ord) {
	system("cls");
	if (ord.description != "") {
		cout << "Enter new order description: ";
		cin.ignore(32767, '\n');
		getline(cin, ord.description);
		cout << "Enter new order status: ";	
		getline(cin, ord.status);
		ord.isDeleted = false;
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

vector<Order> ordersLoad(const string filename) {
	vector<Order> vect;
	ifstream orderLoader(filename.c_str());
	if(!orderLoader) {
		cout << "Oh no, I can't load your saved orders!";
	} else {
		while(orderLoader) {
			string input;
			Order orderNew;
			getline(orderLoader, input);
			vector<string> x = split(input, ';');
			if(x[0] != "end") {
				orderNew.id = stoi(x[0]);
				orderNew.description = x[1];
				orderNew.status = x[2];
				orderNew.isDeleted = (stoi(x[3]) == 1);
				vect.push_back(orderNew);
			} else {
				break;
			}
		}
		orderLoader.close();
	}
	return vect;
}

void ordersSave(vector<Order> &vect, const string filename) {
	ofstream orderSaver(filename);
	if(!orderSaver) {
		cout << "Sorry, your orders won't be saved.\n";
		system("pause");
		return;
	}
	for(int i = 0; i < vect.size(); i++) {
		Order ord = vect[i];
		orderSaver << ord.id << ";"
				   << ord.description << ";"
				   << ord.status << ";"
				   << ord.isDeleted << "\n";
	}
	orderSaver.close();
}

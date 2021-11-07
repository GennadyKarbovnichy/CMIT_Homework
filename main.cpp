#include "order.h"

using namespace std;

struct Order;

void orderPrint(const Order &ord);

Order orderAdd(const vector<Order> &vect);

void orderPrintAll(const vector<Order> &vect);

Order orderFind(const vector<Order> &vect);

Order orderEdit(Order &ord);

vector<Order> orderReplace(vector<Order> &vect, Order &ord);

Order orderDelete(Order ord);

vector<Order> ordersLoad(const string filename);

void ordersSave(vector<Order> &vect, const string filename);

int main() {
	int input;
	vector<Order> orders;
	orders = ordersLoad("Orders.csv");
	bool key = true;
	while(key) {
		system("cls");

		cout << "\tOrder handling\n" <<
		    	"1) Add an order.\n" <<
		    	"2) Print all orders.\n" <<
		    	"3) Find an order and print it.\n" <<
		    	"4) Edit an existing order.\n" <<
		    	"5) Delete an existing order.\n" <<
		    	"\nEvery other input will cause exit." <<
				"\n\n >> ";
		cin >> input;

		switch(input) {
			case 1: {
				Order ord = orderAdd(orders);
				if(!ord.isDeleted)
					orders.push_back(ord);
				break;
			}
			case 2: {
				orderPrintAll(orders);
				break;
			}
			case 3: {
				Order ord = orderFind(orders);
				if (ord.description != "" and not ord.isDeleted) {
					orderPrint(ord);
				}
				cout << endl;
				system("pause");
				break;
			}
			case 4: {
				Order ord = orderFind(orders);
				ord = orderEdit(ord);
				orders = orderReplace(orders, ord);
				break;
			}
			case 5: {
				Order ord = orderDelete(orderFind(orders));
				orders = orderReplace(orders, ord);
				break;
			}
			default: {
				key = false;
			}
		}
	}
	cout << "Saving your orders...\n";
	ordersSave(orders, "Orders.csv");
	return 0;
}

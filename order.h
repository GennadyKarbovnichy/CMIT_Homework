#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Order {
	int id;
	std::string description;
	std::string status;
	bool isDeleted;
};

#endif

#ifndef ORDER_MANAGER_H_
#define ORDER_MANAGER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Order.h"

class OrderManager
{
	std::vector<Order> orders;
	void addOrder(std::vector<std::string> fields, int line);

public:
	OrderManager(std::string& file, char delim);
	void readCSV(std::string& file, char delim);
	void display(std::ostream& os);
	void graph(std::string file);
	bool validate();

	std::vector<Order> getOrders();
};

#endif
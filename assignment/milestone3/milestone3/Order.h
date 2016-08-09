#ifndef ORDER_H_
#define ORDER_H_

#include <string>
#include <vector>

class Order
{
	std::string custName, prodName;
	std::vector<std::string> itemList;

public:
	Order(std::string custName, std::string prodName, std::vector<std::string> itemList);
	void display(std::ostream& os);
	void graph(std::ostream& os);
	
	std::string getCustName();
	std::string getProdName();
	std::vector<std::string> getItemList();
};

#endif
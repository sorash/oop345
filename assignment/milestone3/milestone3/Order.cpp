#include "Order.h"
#include <iomanip>

Order::Order(std::string custName, std::string prodName, std::vector<std::string> itemList)
	: custName(custName), prodName(prodName), itemList(itemList) { }

void Order::display(std::ostream& os)
{
	// display the order information
	os << std::setw(20) << std::left << custName << ": "
		<< prodName << std::endl;

	for (int i = 0; i < itemList.size(); i++)
		os << " - " << '[' << std::setw(5) << std::setfill('0') << '0' << "] " << itemList[i] << std::endl << std::setfill(' ');
}

void Order::graph(std::ostream& os)
{
	for (auto i : itemList)
		os << '"' << i << '"' << "->" << '"' << custName << '\n' << prodName << '"' << ";" << std::endl;
}

std::string Order::getCustName()
{
	return custName;
}

std::string Order::getProdName()
{
	return prodName;
}

std::vector<std::string> Order::getItemList()
{
	return itemList;
}
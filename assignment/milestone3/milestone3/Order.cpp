#include "Order.h"

Order::Order(std::string custName, std::string prodName, std::vector<std::string> itemList)
	: custName(custName), prodName(prodName), itemList(itemList) { }

void Order::display(std::ostream& os)
{
	// display the order information
	os << "Customer Name: " << '"' << custName << '"'
		<< ", Product Name: " << '"' << prodName << '"'
		<< ", Item List: ";

	for (int i = 0; i < itemList.size(); i++)
	{
		if (i != itemList.size() - 1)
			os << '"' << itemList[i] << '"' << ", ";
		else
			os << '"' << itemList[i] << '"' << std::endl;
	}
}
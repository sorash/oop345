#include "OrderManager.h"
#include <sstream>
#include <algorithm>

OrderManager::OrderManager(std::string& file, char delim)
{
	readCSV(file, delim);
}

void OrderManager::readCSV(std::string& file, char delim)
{
	std::ifstream is;
	std::vector<std::string> fields;

	try
	{
		is.open(file);

		// check if file opened successfully
		if (is.good())
		{
			std::string buf, buf2;
			std::stringstream ss;

			int line = 0;

			while (std::getline(is, buf))
			{
				line++;

				ss << buf;
				while (std::getline(ss, buf2, delim))
				{
					// remove leading and trailing white spaces
					buf2.erase(0, buf2.find_first_not_of(' '));
					buf2.erase(buf2.find_last_not_of(' ') + 1);

					// make sure it isn't an empty line and add it to fields
					if (!buf2.empty())
						fields.push_back(buf2);
				}

				// add to order
				addOrder(fields, line);
				fields.clear();

				ss.clear();
			}

			is.close();
		}
		else
			throw "Failed to open file: " + std::string(file);
	}
	catch (std::string err)
	{
		std::cout << err << std::endl;
	}
}

void OrderManager::addOrder(std::vector<std::string> fields, int line)
{
	int count = fields.size();
	std::string custName = "", prodName = "";
	std::vector<std::string> itemList;

	if (count < 3)
		std::cerr << "Line " << line << ": expected 3 or more fields for an order, found " << count << std::endl;
	else
	{
		custName = fields[0];
		prodName = fields[1];

		for (int i = 2; i < count; i++)
			itemList.push_back(fields[i]);
	}

	// add to orders if name isn't blank
	if (!custName.empty())
		orders.push_back(Order(custName, prodName, itemList));
}

void OrderManager::display(std::ostream& os)
{
	for (auto order : orders)
		order.display(os);
}
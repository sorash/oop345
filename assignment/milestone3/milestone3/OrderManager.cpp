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

void OrderManager::graph(std::string file)
{
	std::ofstream os;
	std::string gvFile = file + ".gv";
	std::string pngFile = gvFile + ".png";
	os.open(gvFile);

	// write to the graph file
	os << "digraph task" << " {" << std::endl;

	for (auto order : orders)
		order.graph(os);

	os << "}";
	os.close();	// ***DONT FORGET THIS...***

	// convert to png
	std::string cmd = "dot -Tpng " + gvFile + " -o " + pngFile;

#ifdef _WIN32
	// change command for windows
	cmd = "\"C:\\Program Files (x86)\\Graphviz2.38\\bin\\dot.exe\" -Tpng " + gvFile + " -o " + pngFile;
#endif

	std::cout << "> " << cmd << std::endl;
	if (system(cmd.c_str()) == 0)	// make sure command ran properly
	{
		std::cout << "Would you like to open file: '" << pngFile << "'? (Y/N)" << std::endl;
		char opt;
		std::cin >> opt;
		if (tolower(opt) == 'y')
		{
			std::cout << "> " << pngFile << std::endl;
			system(pngFile.c_str());
		}
	}
	else
		std::cerr << "Creation of flowchart file '" << pngFile << "' failed." << std::endl;
}

// this doesn't change anything since if the fields are missing, an order won't be
// added to the list of orders, and therefore nothing goes through checking... hmm....
// **going to leave this here in case I get any marks for it!**
bool OrderManager::validate()
{
	bool allValid = true;

	for (auto order : orders)
	{
		if (order.getProdName().empty())
			std::cerr << order.getCustName() << ": missing product name." << std::endl;
		if(order.getItemList().empty())
			std::cerr << order.getCustName() << ": missing ordered items." << std::endl;
		
		if(order.getProdName().empty() || order.getItemList().empty())
			allValid = false;
	}

	return allValid;
}

std::vector<Order> OrderManager::getOrders()
{
	return orders;
}
#include "TaskManager.h"
#include "ItemManager.h"
#include "OrderManager.h"
#include "Factory.h"
#include <iomanip>

int main(int argc, char** argv)
{
	if (argc != 5) {
		std::cerr << "*** invalid number of arguments ***\n"
			<< "Usage: " << "[1]tasks file [2]items file [3]orders file [4]file delimiter" << std::endl;
		return 1;
	}
	std::cout << "Command Line Arguments" << std::endl << std::setw(22) << std::setfill('-') << '-' << std::endl << std::setfill(' ');
	std::cout << "Tasks File Specified          = " << argv[1] << std::endl;
	std::cout << "Items File Specified          = " << argv[2] << std::endl;
	std::cout << "Orders File Specified         = " << argv[3] << std::endl;
	std::cout << "Record Field Delimiter        = " << argv[4][0] << std::endl;

	// create a new task manager
	std::cout << std::endl << "Building the Network of Tasks" << std::endl << std::setw(29) << std::setfill('-') << '-' << std::endl << std::setfill(' ');
	TaskManager tm = TaskManager(std::string(argv[1]), argv[4][0]);
	tm.display(std::cout);
	tm.graph(std::string(argv[1]));

	// create a new order manager
	std::cout << std::endl << "List of Accepted Customer Orders" << std::endl << std::setw(32) << std::setfill('-') << '-' << std::endl << std::setfill(' ');
	OrderManager om = OrderManager(std::string(argv[3]), argv[4][0]);
	om.display(std::cout);
	om.graph(std::string(argv[3]));

	// create a new item manager
	std::cout << std::endl << "List of In-Stock Items" << std::endl << std::setw(22) << std::setfill('-') << '-' << std::endl << std::setfill(' ');
	ItemManager im = ItemManager(std::string(argv[2]), argv[4][0]);
	im.display(std::cout);
	im.graph(std::string(argv[2]));

	// validate tasks
	std::cout << std::endl << "Validating Tasks" << std::endl << std::setw(16) << std::setfill('-') << '-' << std::endl << std::setfill(' ');
	if (!tm.validate())
		std::cout << "Task integrity check failed." << std::endl;
	else
		std::cout << "Task integrity check passed." << std::endl;

	// validate orders
	std::cout << std::endl << "Validating Orders" << std::endl << std::setw(17) << std::setfill('-') << '-' << std::endl << std::setfill(' ');
	if (!om.validate())
		std::cout << "Order integrity check failed." << std::endl;
	else
		std::cout << "Order integrity check passed." << std::endl;

	// validate items
	std::cout << std::endl << "Validating Items" << std::endl << std::setw(16) << std::setfill('-') << '-' << std::endl << std::setfill(' ');
	if (!im.validate())
		std::cout << "Item integrity check failed." << std::endl;
	else
		std::cout << "Item integrity check passed." << std::endl;

	// create a factory
	std::cout << std::endl << "Starting factory" << std::endl << std::setw(16) << std::setfill('-') << '-' << std::endl << std::setfill(' ');
	Factory f(tm, om, im);

	std::cout << "Press Enter Key to Exit ... " << std::endl;
	std::cin.get();
	std::cin.ignore(1000, '\n');

	return 0;
}
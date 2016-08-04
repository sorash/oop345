#include "TaskManager.h"
#include "ItemManager.h"
#include "OrderManager.h"
#include <iomanip>

int main(int argc, char** argv)
{
	if (argc != 7) {
		std::cerr << "*** invalid number of arguments ***\n"
			<< "Usage: " << "[1]tasks file [2]tasks delimiter [3]items file [4]items delimiter [5]orders file [6]orders delimiter" << std::endl;
		return 1;
	}
	std::cout << "Command Line Arguments" << std::endl << std::setw(22) << std::setfill('-') << '-' << std::endl << std::setfill(' ');
	std::cout << "Tasks File Specified          = " << argv[1] << std::endl;
	std::cout << "Task Record Field Delimiter   = " << argv[2][0] << std::endl;
	std::cout << "Items File Specified          = " << argv[3] << std::endl;
	std::cout << "Items Record Field Delimiter  = " << argv[4][0] << std::endl;
	std::cout << "Orders File Specified         = " << argv[5] << std::endl;
	std::cout << "Orders Record Field Delimiter = " << argv[6][0] << std::endl;

	// create a new task manager
	std::cout << std::endl << "Building the Network of Tasks" << std::endl << std::setw(29) << std::setfill('-') << '-' << std::endl << std::setfill(' ');
	TaskManager tm = TaskManager(std::string(argv[1]), argv[2][0]);
	tm.display(std::cout);
	tm.graph(std::string(argv[1]));

	// create a new order manager
	std::cout << std::endl << "List of Accepted Customer Orders" << std::endl << std::setw(32) << std::setfill('-') << '-' << std::endl << std::setfill(' ');
	OrderManager om = OrderManager(std::string(argv[5]), argv[6][0]);
	om.display(std::cout);

	// create a new item manager
	std::cout << std::endl << "List of In-Stock Items" << std::endl << std::setw(22) << std::setfill('-') << '-' << std::endl << std::setfill(' ');
	ItemManager im = ItemManager(std::string(argv[3]), argv[4][0]);
	im.display(std::cout);
	im.graph(std::string(argv[3]));

	std::cout << "Press Enter Key to Exit ... " << std::endl;
	std::cin.get();
	std::cin.ignore(1000, '\n');

	return 0;
}
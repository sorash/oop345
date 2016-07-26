#include "TaskManager.h"
#include "ItemManager.h"

int main(int argc, char** argv)
{
	if (argc != 7) {
		std::cerr << "*** invalid number of arguments ***\n"
			<< "Usage: " << "[1]tasks file [2]tasks delimiter [3]items file [4]items delimiter [5]orders file [6]orders delimiter" << std::endl;
		return 1;
	}
	std::cout << "Command Line Arguments" << std::endl << "----------------------" << std::endl;
	std::cout << "Tasks File Specified          = " << argv[1] << std::endl;
	std::cout << "Task Record Field Delimiter   = " << argv[2][0] << std::endl << std::endl;
	std::cout << "Items File Specified          = " << argv[3] << std::endl;
	std::cout << "Items Record Field Delimiter   = " << argv[4][0] << std::endl << std::endl;
	std::cout << "Orders File Specified          = " << argv[5] << std::endl;
	std::cout << "Orders Record Field Delimiter   = " << argv[6][0] << std::endl << std::endl;

	// create a new task manager
	TaskManager tm = TaskManager(std::string(argv[1]), argv[2][0]);
	tm.display(std::cout);
	tm.graph(std::string(argv[1]));

	// create a new item manager
	ItemManager im = ItemManager(std::string(argv[3]), argv[4][0]);
	im.display(std::cout);
	im.graph(std::string(argv[1]));

	std::cout << "Press Enter Key to Exit ... " << std::endl;
	char c;
	std::cin.get(c);

	return 0;
}
#include "TaskManager.h"

int main(int argc, char** argv) 
{
	if (argc != 3) {
		std::cerr << "*** invalid number of arguments ***\n"
			<< "Usage: " << "[1]tasks file [2]delimiter" << std::endl;
		return 1;
	}
	std::cout << "Command Line Arguments" << std::endl << "----------------------" << std::endl;
	std::cout << "Tasks File Specified          = " << argv[1] << std::endl;
	std::cout << "File Record Field Delimiter   = " << argv[2][0] << std::endl << std::endl;

	// create a new task manager
	TaskManager tm = TaskManager(std::string(argv[1]), argv[2][0]);
	tm.display(std::cout);
	tm.graph(argv[1]);

	std::cout << "Press Enter Key to Exit ... " << std::endl;
	char c;
	std::cin.get(c);

	return 0;
}
#include "Factory.h"

Factory::Factory(TaskManager & tm) : machines(nullptr)
{
	findSource(tm);
}

Factory::~Factory()
{
	if(machines != nullptr)
		delete [] machines;

	machines = nullptr;
}

void Factory::findSource(TaskManager& tm)
{
	Task* source = nullptr;
	std::vector<Task> tasks = tm.getTasks();



	if(source != nullptr)
		std::cout << source->getName() << std::endl;
}
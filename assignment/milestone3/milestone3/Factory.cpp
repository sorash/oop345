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

	for (auto task : tasks)
	{
		if (source == nullptr)
		{
			// check if task has an accept but not a reject
			if (task.hasAccept() && !task.hasReject())
			{
				// check if task name is not any other task's accept or reject slot
				int i = 0;
				for (; i < tasks.size(); i++)
				{
					if (task.getName() == tasks[i].getAccept() || task.getName() == tasks[i].getReject())
						break;
				}

				// if task is not any other task's accept or reject slot, make it the source node
				if (i == tasks.size())
					source = &task;
			}
		}
		else
			std::cerr << "Multiple source nodes found." << std::endl;
	}
}
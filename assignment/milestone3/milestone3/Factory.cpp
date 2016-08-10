#include "Factory.h"

Factory::Factory(TaskManager & tm)
{
	findSource(tm);
}

void Factory::findSource(TaskManager& tm)
{
	Task* source = nullptr;
	std::vector<Task> tasks = tm.getTasks();

	for (auto task : tasks)
	{
		// make sure there is only one source node
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

	// if a source node was found, initiate the machine
	if (source != nullptr)
	{
		// TODO
		// ** FIGURE OUT WHY SOURCE GETS RESET TO BLANK **

		//std::cout << source->getName() << std::endl;
		//int index = 0;
		//for (; index < tasks.size(); index++)
		//{
		//	if (tasks[index].getName() == source->getName())
		//		break;
		//}

		//machines.push_back(Machine(index, source));
	}
	else
		std::cerr << "No source nodes found." << std::endl;
}
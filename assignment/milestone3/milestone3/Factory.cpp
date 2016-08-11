#include "Factory.h"

Factory::Factory(TaskManager & tm, OrderManager& om)
{
	findSource(tm);
	findAllJobs(om);
}

void Factory::findSource(TaskManager& tm)
{
	std::vector<Task> tasks = tm.getTasks();

	for (auto &task : tasks)	// pass as reference or source pointer loses value...
	{
		// make sure there is only one source node
		if (sourceNode == nullptr)
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
					sourceNode = &task;
			}
		}
		else
			std::cerr << "Multiple source nodes found." << std::endl;
	}

	// make sure a source node was found
	if (sourceNode != nullptr)
	{
		std::cout << "Source node found: '" << sourceNode->getName() << "'" << std::endl;

		// get index of source task in tasks list
		int index = 0;
		for (; index < tasks.size(); index++)
		{
			if (tasks[index].getName() == sourceNode->getName())
				break;
		}

		// initialize a machine with that index and task
		Machine srcMach = Machine(index, sourceNode, true);
		srcMach.display(std::cout);
		machines.push_back(srcMach);
	}
	else
		std::cerr << "No source nodes found." << std::endl;
}

void Factory::findAllJobs(OrderManager& om)
{
	for (auto order : om.getOrders())
		jobs.push_back(order);
}
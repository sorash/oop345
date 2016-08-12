#include "Factory.h"

Factory::Factory(TaskManager & tm, OrderManager& om)
{
	findSource(tm);
	findAllJobs(om);
	createAllMachines(tm);
	timeLoop();
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

void Factory::createAllMachines(TaskManager& tm)
{
	std::vector<Task> tasks = tm.getTasks();
	for (int i = 0; i < tasks.size(); i++)
	{
		// add machines if the task found is not the source node previously found
		if (tasks[i].getName() != sourceNode->getName())
			machines.push_back(Machine(i, &tasks[i], false));
	}
}

void Factory::timeLoop()
{
	int time = 0;

	// loop until there are no jobs left
	while (jobs.size() > 0)
	{
		std::cout << "Time loop time: " << time + 1 << std::endl;
		
		// print out job information
		std::cout << "Jobs to process:" << std::endl
			<< '\t' << "Customer: " << jobs[time].getCustName() << std::endl
			<< '\t' << "Product: " << jobs[time].getProdName() << std::endl
			<< '\t' << "Items: " << std::endl;
		for (auto item : jobs[time].getItemList())
			std::cout << "\t\t" << item << std::endl;

		// remove job
		// TODO only remove if machine finished processing
		jobs.pop_front();

		// increment time
		time++;
	}

	std::cout << std::endl 
		<< "No jobs left to process." << std::endl
		<< "Factory simulation completed." << std::endl;
}
#include "Factory.h"
#include <iomanip>

Factory::Factory(TaskManager & tm, OrderManager& om, ItemManager& im)
{
	findSource(tm);
	findAllJobs(om);
	createAllMachines(tm);
	timeLoop(im);
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
		machines.push_back(Machine(index, *sourceNode, true));
		machines[0].display(std::cout);
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
			machines.push_back(Machine(i, tasks[i], false));
	}
}

void Factory::timeLoop(ItemManager& im)
{
	int time = 0, jobIndex = 0;

	// set current machine to source node
	for (auto &mach : machines)	// again, pass as reference or pointer loses value
	{
		if (mach.isSource())
		{
			curMach = &mach;
			
			// loop through machine to find next machine
			for (auto &next : machines)
			{
				// next machine should be the accept slot of current machine's task
				if (mach.getTask().getAccept() == next.getTask().getName())
					nextMach = &next;
			}

			break;
		}
	}

	// make sure a source machine was created
	if (curMach != nullptr)
	{
		// loop until there are no jobs left
		while (jobs.size() > 0)
		{
			std::cout << std::endl << "Time loop time: " << time + 1 << std::endl;
			std::cout << "Current machine: " << curMach->getTask().getName() << std::endl;

			// if reached a sink node
			if(!curMach->getTask().hasAccept() && !curMach->getTask().hasReject())
			{
				// clear that job
				jobs.erase(jobs.begin() + jobIndex);
				jobIndex++;
			}

			if (jobs.size() > 0)
			{
				// print out job information
				std::cout << "Jobs to process:" << std::endl
					<< '\t' << "Customer: " << jobs[jobIndex].getCustName() << std::endl
					<< '\t' << "Product: " << jobs[jobIndex].getProdName() << std::endl
					<< '\t' << "Items: " << std::endl;
				for (auto item : jobs[jobIndex].getItemList())
					std::cout << "\t\t" << item << std::endl;

				// process job
				int result = curMach->process(jobs[jobIndex], im);
				if (result == 1)
				{
					// loop through machine to find next machine
					for (auto &next : machines)
					{
						// next machine should be the accept slot of current machine's task
						if (curMach->getTask().getAccept() == next.getTask().getName())
							nextMach = &next;
					}

					std::cout << "Coin flip passed!" << std::endl;

					// move to next machine
					moveToNextMachine();
				}
				else if (result == 0)
				{
					// loop through machine to find next machine
					for (auto &next : machines)
					{
						// next machine should be the reject slot of current machine's task
						if (curMach->getTask().getReject() == next.getTask().getName())
							nextMach = &next;
					}

					std::cout << "Coin flip failed!" << std::endl;

					// move to next machine
					moveToNextMachine();
				}
				else
				{
					// move to next machine
					moveToNextMachine();
				}
			}

			// increment time
			time++;
		}

		std::cout << std::endl
			<< std::setw(29) << std::setfill('-') << '-' << std::endl
			<< "No jobs left to process." << std::endl
			<< "Factory simulation completed." << std::endl
			<< std::setw(29) << std::setfill('-') << '-' << std::setfill(' ')
			<< std::endl << std::endl;
	}
	else
		std::cout << "No source machine found, exiting simulation." << std::endl;
}

void Factory::moveToNextMachine()
{
	if (nextMach != nullptr)
	{
		std::cout << "Moving from machine " << curMach->getTask().getName() << " to " << nextMach->getTask().getName() << std::endl;
		curMach = nextMach;
		nextMach = nullptr;
	}
}
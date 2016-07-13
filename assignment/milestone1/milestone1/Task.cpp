#include "Task.h"

const std::string& Task::getName() const
{
	return name;
}

unsigned int Task::getSlots() const
{
	// convert from string to integer
	return atoi(slots.c_str());
}

bool Task::validate(const Task& task)
{
	//std::cout << sizeof(nextTask) / sizeof(nextTask[0]) << std::endl;
	
	// return true if both next task names are empty
	if (nextTask[0].empty() && nextTask[1].empty())
		return true;
	else
	{
		// go through next tasks
		int size = sizeof(nextTask) / sizeof(nextTask[0]);
		int i;
		for (i = 0; i < size; i++)
		{
			// if next task is not empty and is the same as task passed
			if (!nextTask[i].empty() && nextTask[i] == task)
			{
				// store the address
				pNextTask[i] = &task;
			}

			// break if the there is a next task and the pointer to it is not resolved
			if (!nextTask[i].empty() && pNextTask[i] == nullptr)
				break;
		}

		// check if all pointers have been resolved
		if (i == size - 1)
			return true;
		else
			return false;
	}
}

void Task::display(std::ostream& os) const
{
	//os << "Task Name    : "
}
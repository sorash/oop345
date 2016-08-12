#include "Machine.h"
#include <cstdlib> // std::rand()

Machine::Machine(int n, Task t, bool s) : index(n), task(t), source(s) { }

void Machine::display(std::ostream& os)
{
	if (source)
		os << "Source machine ";
	else
		os << "Machine ";

	os << index << ":" << std::endl
		<< "\t" << "Task name: '" << task.getName() << "'" << std::endl
		<< "\t" << "Task slots: '" << task.getSlots() << "'" << std::endl;
	
	if(task.hasAccept())
		os << "\t" << "Accept slot: '" << task.getAccept() << "'" << std::endl;
	if (task.hasReject())
		os << "\t" << "Reject slot: '" << task.getReject() << "'" << std::endl;
}

Task Machine::getTask()
{
	return task;
}

int Machine::getIndex()
{
	return index;
}

bool Machine::isSource()
{
	return source;
}

int Machine::process(Order ord, ItemManager& im)
{
	for (auto item : ord.getItemList())
	{
		for (auto it : im.getItems())
		{
			if (item == it.getName())
			{
				if (it.getInstaller() == task.getName() || it.getRemover() == task.getName())
				{
					// nowhere to go if the task has no reject slot
					// so might as well skip the coin flip and process it
					if (task.hasReject())
					{
						// do a coin flip
						int rand = std::rand() % 2;	// 0-1
						return rand;
					}
					return 1;
				}
			}
		}
	}

	return -1;
}
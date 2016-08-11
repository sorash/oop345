#include "Task.h"
#include <iomanip>

Task::Task(std::string name, std::string slots, std::string accept, std::string reject)
	: name(name), slots(slots), accept(accept), reject(reject)
{

}

void Task::display(std::ostream& os)
{
	// display the task information
	os << std::setw(13) << std::left << "Task Name" << ": " << std::setw(16) << '[' + name + ']' << '[' << slots << ']';

	if (!accept.empty())
	{
		os << std::endl << std::setw(13) << std::left << " Continue to" << ": " << '[' << accept << ']';

		if (!reject.empty())
		{
			os << std::endl << std::setw(13) << std::left << " Redirect to" << ": " << '[' << reject << ']' << std::endl;
		}
		else
			os << std::endl;
	}
	else
		os << std::endl;
}

void Task::graph(std::ostream& os)
{
	// if there is an accept/reject slot, write it to the graph file
	if (!accept.empty())
		os << '"' << name << '"' << "->" << '"' << accept << '"' << " [color=green];" << std::endl;
	if (!reject.empty())
		os << '"' << name << '"' << "->" << '"' << reject << '"' << " [color=red];" << std::endl;
	
	// if both accept/reject are empty, change the shape to be standalone
	if (accept.empty() && reject.empty())
		os << '"' << name << '"' << " [shape=box];" << std::endl;
}

bool Task::hasAccept()
{
	return !accept.empty();
}

bool Task::hasReject()
{
	return !reject.empty();
}

std::string Task::getName()
{
	return name;
}

std::string Task::getSlots()
{
	return slots;
}

std::string Task::getAccept()
{
	return accept;
}

std::string Task::getReject()
{
	return reject;
}
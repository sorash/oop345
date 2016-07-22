#include "Task.h"

Task::Task(std::string name, std::string slots, std::string accept, std::string reject)
	: name(name), slots(slots), accept(accept), reject(reject)
{

}

void Task::display(std::ostream& os)
{
	// display the task information
	os << "Name: " << '"' << name << '"';

	if (slots != "0")
	{
		os << ", Slots: " << '"' << slots << '"';

		if (!accept.empty())
		{
			os << ", Accept: " << '"' << accept << '"';

			if (!reject.empty())
			{
				os << ", Reject: " << '"' << reject << '"' << std::endl;
			}
			else
				os << std::endl;
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
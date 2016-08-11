#include "Machine.h"

Machine::Machine(int n, Task* t) : index(n), task(t) { }

void Machine::display(std::ostream& os, bool source)
{
	if (source)
		os << "machine ";
	else
		os << "Machine ";

	os << index << ":" << std::endl
		<< "\t" << "Task name: '" << task->getName() << "'" << std::endl
		<< "\t" << "Task slots: '" << task->getSlots() << "'" << std::endl;
	
	if(task->hasAccept())
		os << "\t" << "Accept slot: '" << task->getAccept() << "'" << std::endl;
	if (task->hasReject())
		os << "\t" << "Reject slot: '" << task->getReject() << "'" << std::endl;
}
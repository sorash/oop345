#include "Task.h"

Task::Task(std::string name, std::string slots, std::string accept, std::string reject)
	: name(name), slots(slots), accept(accept), reject(reject)
{

}

void Task::display(std::ostream& os)
{
	os << "Name: " << name << std::endl;

	if(slots != "0")
		os << "Slots: " << slots << std::endl;

	if (accept != "")
		os << "Accept: " << accept << std::endl;

	if (reject != "")
		os << "Reject: " << reject << std::endl;
}
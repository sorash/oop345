#include "Task.h"

Task::Task(std::string name, std::string slots, std::string accept, std::string reject)
	: name(name), slots(slots), accept(accept), reject(reject)
{

}

void Task::display(std::ostream& os)
{
	os << "Name: " << name
		<< (slots != "0" ? ", " + slots : "\n")
		<< (!accept.empty() ? ", " + accept : "\n")
		<< (!reject.empty() ? ", " + reject + "\n" : "\n");
}
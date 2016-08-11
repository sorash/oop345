#ifndef MACHINE_H_
#define MACHINE_H_

#include "TaskManager.h"

class Machine
{
	int index;
	Task* task;

public:
	Machine(int n, Task* t);

	void display(std::ostream& os, bool source);
};

#endif
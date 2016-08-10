#ifndef MACHINE_H_
#define MACHINE_H_

#include "TaskManager.h"

class Machine
{
	int num;
	Task* task;

public:
	Machine();
	Machine(int n, Task* t);
	~Machine();
};

#endif
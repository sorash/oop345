#ifndef MACHINE_H_
#define MACHINE_H_

#include "TaskManager.h"
#include "Order.h"
#include "ItemManager.h"

class Machine
{
	int index;
	Task task;
	bool source;

public:
	Machine(int n, Task t, bool s);

	void display(std::ostream& os);

	int getIndex();
	Task getTask();
	bool isSource();

	int process(Order order, ItemManager& im);
};

#endif
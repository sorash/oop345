#ifndef FACTORY_H_
#define FACTORY_H_

#include "TaskManager.h"
#include "Machine.h"

class Factory
{
	std::vector<Machine> machines;

public:
	Factory(TaskManager& tm);

	void findSource(TaskManager& tm);
};

#endif
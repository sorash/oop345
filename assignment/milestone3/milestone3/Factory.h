#ifndef FACTORY_H_
#define FACTORY_H_

#include "TaskManager.h"
#include "Machine.h"

class Factory
{
	Machine* machines;

public:
	Factory(TaskManager& tm);
	~Factory();

	void findSource(TaskManager& tm);
};

#endif
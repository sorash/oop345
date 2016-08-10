#include "Machine.h"

Machine::Machine(int n, Task* t) : num(n), task(t) { }

Machine::~Machine()
{
	delete[] task;
	task = nullptr;
}
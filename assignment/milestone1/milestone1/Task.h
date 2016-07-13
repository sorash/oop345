#ifndef TASK_H_
#define TASK_H_

#include <string>
#include <iostream>

class Task
{
	// name of task
	std::string name;
	
	// number of slots
	std::string slots;

	// names of next tasks
	std::string nextTask[2];
	
	// pointers to next tasks
	const Task* pNextTask[2];

	// maximum field width
	static size_t fieldWidth;

public:
	// quality of task
	enum Quality
	{
		passed,
		redirect
	};

	Task(const std::string&);

	// validates the next task(s)
	bool validate(const Task&);

	// returns the name of task
	const std::string& getName() const;

	// returns number of product slots in the task
	unsigned int getSlots() const;

	// 
	const Task* getNextTask(Quality) const;
	void display(std::ostream&) const;
	static size_t getFieldWidth();
};

bool operator==(const Task&, const Task&);

#endif
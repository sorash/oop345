#ifndef TASK_MANAGER_H_
#define TASK_MANAGER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Task.h"

class TaskManager
{
	std::vector<Task> tasks;
	void addTask(std::vector<std::string> fields, int line);

public:
	TaskManager(std::string& file, char delim);
	void readCSV(std::string& file, char delim);
	void display(std::ostream& os);
	void graph(std::string file);
	bool validate();

	std::vector<Task> getTasks();
};

#endif
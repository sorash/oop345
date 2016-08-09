#ifndef TASK_H_
#define TASK_H_

#include <string>
#include <iostream>

class Task
{
	std::string name, slots, accept, reject;

public:
	Task(std::string name, std::string slots, std::string accept, std::string reject);
	void display(std::ostream& os);
	void graph(std::ostream& os);

	bool hasAccept();
	bool hasReject();
	std::string getName();
	std::string getAccept();
	std::string getReject();
};

#endif
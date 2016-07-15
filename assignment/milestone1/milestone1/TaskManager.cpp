#include "TaskManager.h"
#include <sstream>

TaskManager::TaskManager(std::string& file, char delim)
{
	readCSV(file, delim);
}

void TaskManager::readCSV(std::string& file, char delim)
{
	std::ifstream is;
	std::vector<std::string> fields;

	try
	{
		is.open(file);

		// check if file opened successfully
		if (is.good())
		{
			std::string buf, buf2;
			std::stringstream ss;
			int count = 0;
			while (std::getline(is, buf))
			{
				count++;
				ss << buf;
				while (std::getline(ss, buf2, delim))
				{
					// remove leading and trailing white spaces
					buf2.erase(0, buf2.find_first_not_of(' '));
					buf2.erase(buf2.find_last_not_of(' ') + 1);

					// add to tasks
					fields.push_back(buf2);
				}

				addTask(fields);
				fields.clear();

				ss.clear();
			}
			
			is.close();
		}
		else
			throw "Failed to open file: " + std::string(file);
	}
	catch (std::string err)
	{
		std::cout << err << std::endl;
	}
}

void TaskManager::addTask(std::vector<std::string> fields)
{
	int count = fields.size();
	std::string name, slots = "0", accept = "", reject = "";
	
	switch (count)
	{
	case 4:
		reject = fields[3];
	case 3:
		accept = fields[2];
	case 2:
		slots = fields[1];
	case 1:
		name = fields[0];
		break;
	default:
		std::cerr << "Expected 1-4 fields for a task, found " << count << std::endl;
		break;
	}

	if(name != "")
		tasks.push_back(Task(name, slots, accept, reject));
}

void TaskManager::display(std::ostream& os)
{
	for (auto task : tasks)
		task.display(os);
}
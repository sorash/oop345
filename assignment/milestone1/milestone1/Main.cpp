#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

/// <summary>Reads tasks from the task file.</summary>
/// <param name="fileName">File to read from</param>
/// <param name="delim">Character to delimit the tasks by</param>
/// <returns>True if successfully read from file.</returns>
bool ReadFromFile(char* fileName, char delim);

int main(int argc, char* argv[])
{
	// check if correct number of command line arguments have been entered
	if (argc != 3)
	{
		std::cout << "Incorrect number of command line arguments." << std::endl <<
			"Usage: [1]task file name, [2]task file delimiter." << std::endl;

		return 1;
	}

	// show the command line arguments
	std::cout << "Task file name: " << argv[1] << std::endl <<
		"Task file delimiter: " << argv[2][0] << std::endl << std::endl;

	// read from task file and exit if failed
	if (!(ReadFromFile(argv[1], argv[2][0]))) return 2;
	
	std::cout << "Press enter to exit..." << std::endl;
	std::getchar();

	return 0;
}

bool ReadFromFile(char* fileName, char delim)
{
	std::vector<std::string> tasks;

	std::cout << "Attempting to read from file '" << fileName << "', delimiting tasks by '" << delim << "'." << std::endl;

	std::ifstream is;

	// attempt to open the file
	try
	{
		is.open(fileName);

		// check if file opened successfully
		if (is.good())
		{
			std::string buf, buf2;
			std::stringstream ss;

			// read all lines
			while (is.good())
			{
				while (std::getline(is, buf))
				{
					ss << buf;
					while (std::getline(ss, buf2, delim))
					{
						// remove leading and trailing white spaces
						buf2.erase(0, buf2.find_first_not_of(' '));
						buf2.erase(buf2.find_last_not_of(' ') + 1);

						// add to tasks
						tasks.push_back(buf2);
					}
					ss.clear();
				}
			}

			is.close();
		}
		else
			throw "Failed to open file: " + std::string(fileName);
	}
	catch (std::string err)
	{
		std::cout << err << std::endl;
	}

	return true;
}
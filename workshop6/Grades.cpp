#include "Grades.h"
#include <string>
#include <iostream>

Grades::Grades(const char* filePath)
{
	std::ifstream is;

	// attempt to open file	
	try
	{
		is.open(filePath);

		// throw if file failed to open
		if (is.fail())
			throw "Failed to open file: " + std::string(filePath);

		char buf[10];
		char studNo[10];
		double grade;

		// read grades
		is.getline(buf, ' ');
		strcpy(studNo, buf);

		std::cout << studNo << std::endl;

		is.getline(buf, '\r\n');
		grade = atof(buf);

		std::cout << grade << std::endl;
	}
	catch (std::string err)
	{
		// show error message
		std::cout << err << std::endl;
	}
}
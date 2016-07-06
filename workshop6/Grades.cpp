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

		std::string buf;
		char studNo[10];
		double grade;

		// read all lines
		while (is.good())
		{
			// read student number
			std::getline(is, buf, ' ');
			strcpy(studNo, buf.c_str());
			students.push_back(studNo);

			// read grade
			std::getline(is, buf, '\n');
			grade = atof(buf.c_str());
			grades.push_back(grade);
		}
	}
	catch (std::string err)
	{
		// show error message
		std::cout << err << std::endl;
	}
}

template<typename func>
void Grades::displayGrades(std::ostream &os, func exp)
{
	auto letter = exp;

	for (auto const value : students)
	{
		os << 
	}
}
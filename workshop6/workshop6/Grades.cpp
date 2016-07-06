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
		double grade;

		// get count of lines...
		while (is.good())
		{
			std::getline(is, buf, '\n');
			count++;
		}

		// reset file stream
		is.clear();
		is.seekg(0, std::ios::beg);

		// allocate memory
		students = new std::string[count];
		grades = new double[count];

		// read all lines
		int i = 0;
		while (is.good())
		{
			// read student number
			std::getline(is, students[i], ' ');

			// read grade
			std::getline(is, buf, '\n');
			grade = atof(buf.c_str());
			grades[i] = grade;

			i++;
		}
	}
	catch (std::string err)
	{
		// show error message
		std::cout << err << std::endl;
	}
}
#ifndef GRADES_H_
#define GRADES_H_

#include <fstream>
#include <vector>

class Grades
{
	std::vector<double> grades;

public:
	Grades(const char* filePath);

	template<typename func>
	void displayGrades(std::ostream &os, func exp) const;
};

#endif
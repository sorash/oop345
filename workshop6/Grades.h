#ifndef GRADES_H_
#define GRADES_H_

#include <fstream>
#include <vector>

class Grades
{
	std::vector<char*> students;
	std::vector<double> grades;
	std::vector<char*> letters;

public:
	Grades(const char* filePath);

	template<typename func>
	void displayGrades(std::ostream &os, func exp) const;

	// disable copying, moving, and assignment
	Grades(const Grades& other) = delete;
	Grades(Grades&& other) = delete;
	Grades& operator=(const Grades& other) = delete;
	Grades&& operator=(Grades&& other) = delete;
};

#endif
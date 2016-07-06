#ifndef GRADES_H_
#define GRADES_H_

#include <fstream>

class Grades
{
	std::string* students;
	double* grades;
	std::string* letters;
	int count = 0;

public:
	Grades(const char* filePath);

	template<typename func>
	void displayGrades(std::ostream &os, func exp) const
	{
		for (int i = 0; i < count; i++)
		{
			auto letter = exp(grades[i]);
			os << students[i].c_str() << " " << grades[i] << " " << letter << std::endl;
		}
	}

	// disable copying, moving, and assignment
	Grades(const Grades& other) = delete;
	Grades(Grades&& other) = delete;
	Grades& operator=(const Grades& other) = delete;
	Grades&& operator=(Grades&& other) = delete;
};

#endif
#ifndef DATA_TABLE_H
#define DATA_TABLE_H

#include <fstream>
#include <vector>
#include <utility>
#include <sstream>

namespace w8
{
	template<class T>
	class DataTable
	{
		std::vector<std::pair<T, T>> points;

	public:
		DataTable(std::ifstream& is, int width, int decimals)
		{
			// read line
			std::string line;
			std::getline(is, line);

			// insert the line into a stringstream
			std::stringstream ss;

			// if line is not blank, return a respective product, else return nullptr
			if (!line.empty())
			{
				ss.str(line);
				T first, second;
				ss >> first >> second;
				std::pair<T, T> temp;
				temp.first = first;
				temp.second = second;

				// add to points
				points.push_back(temp);
			}
		}

		T mean() const
		{
			return 0;
		}

		T sigma() const
		{
			return 1;
		}

		T median() const
		{
			return 2;
		}

		void regression(T& slope, T& y_intercept) const
		{

		}

		void display(std::ostream& os) const
		{

		}
	};

	template<class T>
	std::ostream& operator<<(std::ostream& os, const DataTable<T>& dt)
	{
		dt.display(os);
		return os;
	}
}

#endif
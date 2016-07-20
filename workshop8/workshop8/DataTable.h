#ifndef DATA_TABLE_H
#define DATA_TABLE_H

#include <fstream>
#include <vector>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>

namespace w8
{
	template<class T>
	class DataTable
	{
		std::vector<std::pair<T, T>> points;
		int width, decimals;

	public:
		DataTable(std::ifstream& is, int width, int decimals) : width(width), decimals(decimals)
		{
			// read lines
			while (is.good())
			{
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
			os << std::setw(width) << "x"
				<< std::setw(width) << "y" << std::endl;

			for (const auto& p : points)
			{
				os << std::setw(width) << std::fixed << std::setprecision(decimals) << p.first 
					<< std::setw(width) << std::fixed << std::setprecision(decimals) << p.second << std::endl;
			}
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
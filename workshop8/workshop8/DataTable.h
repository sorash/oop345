#ifndef DATA_TABLE_H
#define DATA_TABLE_H

#include <fstream>
#include <vector>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <algorithm>

namespace w8
{
	template<class T>
	class DataTable
	{
		std::vector<T> x, y;
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

					T fx, fy;
					ss >> fx >> fy;

					// add to points
					x.push_back(fx);
					y.push_back(fy);
				}
			}
		}

		T mean() const
		{
			T yTot = std::accumulate(y.begin(), y.end(), 0);
			return yTot / y.size();
		}

		T sigma() const
		{
			std::vector<T> diff(y.size());
			T meanVal = mean();
			T stdDev = std::transform(y.begin(), y.end(), diff.begin(), [meanVal](T x) { return x - meanVal; });
			return stdDev;
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

			for (int i = 0; i < x.size(); i++)
			{
				os << std::setw(width) << std::fixed << std::setprecision(decimals) << x[i]
					<< std::setw(width) << std::fixed << std::setprecision(decimals) << y[i] << std::endl;
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
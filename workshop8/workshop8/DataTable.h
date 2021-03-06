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
			T yTot = std::accumulate(y.begin(), y.end(), 0.0);
			return yTot / y.size();
		}

		T sigma() const
		{
			T meanVal = mean(), sumDeviation = 0.0;

			for (int i = 0; i < y.size(); ++i)
				sumDeviation += (y[i] - meanVal) * (y[i] - meanVal);

			return std::sqrt(sumDeviation / y.size());
		}

		T median() const
		{
			std::vector<T> copy = y;

			// sort a copy of the y values and get the middle of it
			std::sort(copy.begin(), copy.end());
			T median = copy[copy.size() / 2];

			return median;
		}

		void regression(T& slope, T& y_intercept) const
		{
			// average of values
			T avgX = std::accumulate(x.begin(), x.end(), 0.0) / x.size();
			T avgY = std::accumulate(y.begin(), y.end(), 0.0) / y.size();

			// numerator and denominator of slope
			T numer = 0.0, denom = 0.0;
			for (int i = 0; i < x.size(); ++i)
			{
				numer += (x[i] - avgX) * (y[i] - avgY);
				denom += (x[i] - avgX) * (x[i] - avgX);
			}

			slope = numer / denom;
			y_intercept = avgY - (slope * avgX);	// y=mx+b --> b=y-(mx);
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
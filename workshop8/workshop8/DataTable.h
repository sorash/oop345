#ifndef DATA_TABLE_H
#define DATA_TABLE_H

#include <fstream>
#include <vector>
#include <utility>

namespace w8
{
	template<typename T>
	class DataTable
	{
		std::vector<std::pair<T, T>> points;

	public:
		DataTable(std::ifstream& is, int width, int decimals);
		T mean() const;
		T sigma() const;
		T median() const;
		void regression(T& slope, T& y_intercept) const;
		void display(std::ostream& os) const;
	};

	template<class T>
	std::ostream& operator<<(std::ostream& os, const DataTable<T>& dt);
}

#endif
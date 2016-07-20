#include "Sale.h"
#include "TaxableProduct.h"
#include <string>
#include <sstream>
#include <vector>

using namespace w7;

Sale::Sale(const char* fileName)
{

}

void Sale::display(std::ostream& os) const
{

}

std::ostream& w7::operator<<(std::ostream& os, const iProduct& prod)
{
	prod.display(os);
	return os;
}

iProduct* w7::readProduct(std::ifstream& is)
{
	// read line
	std::string line;
	std::getline(is, line);

	// insert the line into a stringstream
	std::stringstream ss(line);

	// vector to hold the fields in the line
	std::vector<std::string> fields;

	// split the line by space (by default)
	std::string buf;
	while (ss >> buf)
		fields.push_back(buf);

	// check if there were three fields and make a product respectively
	iProduct* prod;
	if (fields.size() == 3)
		prod = new TaxableProduct(std::stol(fields[0]), std::stod(fields[1]), fields[2].c_str()[0]);
	else
		prod = new Product(std::stol(fields[0]), std::stod(fields[1]));

	return prod;
}
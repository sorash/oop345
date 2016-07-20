#include "Sale.h"
#include "TaxableProduct.h"
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

using namespace w7;

Sale::Sale(const char* fileName)
{
	std::ifstream ifs(fileName);
	iProduct* prod;

	// while not end of file, and the product returned is not an empty one
	// add to the list of products
	while (ifs.good() && (prod = w7::readProduct(ifs)) != nullptr)
		products.push_back(prod);
}

void Sale::display(std::ostream& os) const
{
	os << std::setw(10) << "Product No"
		<< std::setw(10) << "Cost"
		<< " Taxable" << std::endl;

	double total = 0;

	for (auto prod : products)
	{
		prod->display(os);
		total += prod->getCharge();
	}

	os << std::setw(10) << "Total"
		<< std::fixed << std::setprecision(2) << std::setw(10) << total << std::endl;
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
	std::stringstream ss;

	// if line is not blank, return a respective product, else return nullptr
	if (!line.empty())
	{
		ss.str(line);

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
	else return nullptr;
}
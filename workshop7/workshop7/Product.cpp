#include "Product.h"
#include <iomanip>

Product::Product(long number, double cost) : number(number), cost(cost) { }

double Product::getCharge() const
{
	return cost;
}

void Product::display(std::ostream & os) const
{
	os << std::setw(10) << number << std::setw(10) << cost << std::endl;
}

std::ostream& w7::operator<<(std::ostream& os, const iProduct& prod)
{
	prod.display(os);
	return os;
}
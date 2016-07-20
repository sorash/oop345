#include "TaxableProduct.h"
#include <iomanip>

TaxableProduct::TaxableProduct(long number, double cost, char tax)
	: Product(number, cost), tax(tax) { }

double TaxableProduct::getCharge() const
{
	return cost * (tax == 'H' ? taxes[0] : taxes[1]);
}

void TaxableProduct::display(std::ostream& os) const
{
	os << std::setw(10) << number 
		<< std::setw(10) << std::fixed << std::setprecision(2) << cost 
		<< ' ' << (tax == 'H' ? "HST" : "PST") << std::endl;
}
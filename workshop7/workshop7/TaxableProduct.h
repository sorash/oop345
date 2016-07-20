#ifndef TAXABLE_PRODUCT_H_
#define TAXABLE_PRODUCT_H_

#include "Product.h"

class TaxableProduct : public Product
{
	double taxes[2] = { 1.13, 1.08 };
	char tax;

public:
	TaxableProduct(long number, double cost, char tax);
	double getCharge() const;
	void display(std::ostream& os) const;
};

#endif
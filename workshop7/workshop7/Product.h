#ifndef PRODUCT_H_
#define PRODUCT_H_

#include "iProduct.h"

class Product : public w7::iProduct
{
protected:
	long number;
	double cost;

public:
	Product(long number, double cost);
	double getCharge() const;
	void display(std::ostream& os) const;
};

#endif
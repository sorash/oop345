#ifndef SALE_H_
#define SALE_H_

#include <vector>
#include "iProduct.h"

namespace w7
{
	class Sale
	{
		std::vector<w7::iProduct*> products;

	public:
		Sale(const char* fileName);
		void display(std::ostream& os) const;
	};
}

#endif
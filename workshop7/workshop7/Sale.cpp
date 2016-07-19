#include "Sale.h"
#include <string>

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

//iProduct* readProduct(std::ifstream& is)
//{
//	char* line;
//	is >> line;
//
//	char* fields = strtok(line, " ");
//	while (fields != NULL)
//		std::cout << fields;
//
//	return NULL;
//}
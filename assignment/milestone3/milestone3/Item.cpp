#include "Item.h"

Item::Item(std::string name, std::string installer, std::string remover, std::string code, std::string desc)
	: name(name), installer(installer), remover(remover), code(code), desc(desc) { }

void Item::display(std::ostream& os)
{
	// display the item information
	os << "Name: " << '"' << name << '"'
		<< ", Installer: " << '"' << installer << '"'
		<< ", Remover: " << '"' << remover << '"'
		<< ", Sequential Code: " << '"' << code << '"';

	if (!desc.empty())
		os << ", Description: " << '"' << desc << '"' << std::endl;
	else
		os << std::endl;
}

void Item::graph(std::ostream& os)
{
	os << '"' << name << '"' << "->" << '"' << installer << '"' << " [color=green];" << std::endl;
	os << '"' << name << '"' << "->" << '"' << remover << '"' << " [color=red];" << std::endl;
}
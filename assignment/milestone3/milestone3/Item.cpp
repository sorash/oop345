#include "Item.h"
#include <iomanip>

Item::Item(std::string name, std::string installer, std::string remover, std::string code, std::string desc)
	: name(name), installer(installer), remover(remover), code(code), desc(desc) { }

void Item::display(std::ostream& os)
{
	// display the item information
	os << std::setw(13) << std::left << name
		<< '[' << std::setw(5) << std::setfill('0') << std::right << code << ']' << std::setfill(' ')
		<< " From " << std::setw(13) << std::left << installer
		<< " To " << remover << std::endl;

	if (!desc.empty())
		os << std::setw(19) << std::setfill(' ') << ' ' << ": " << desc << std::endl;
	else
		os << std::setw(19) << std::setfill(' ') << ' ' << ": " << "no detailed description" << std::endl;
}

void Item::graph(std::ostream& os)
{
	os << '"' << name << '"' << "->" << '"' << installer << '"' << " [color=green];" << std::endl;
	os << '"' << name << '"' << "->" << '"' << remover << '"' << " [color=red];" << std::endl;
}
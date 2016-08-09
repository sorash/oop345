#include "Item.h"
#include <iomanip>
#include <locale>	// std::locale, std::isalpha
#include <algorithm>	// std::remove_if

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

bool Item::hasInstaller()
{
	return !installer.empty() && isAlpha(installer);
}

bool Item::hasRemover()
{
	return !remover.empty() && isAlpha(remover);
}

// checks if a string is all alphabetic
bool Item::isAlpha(std::string str)
{
	std::locale loc;

	// remove whitespace since it interferes with std::isalpha
	str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());

	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
	{
		if (!isalpha(*it, loc))
			return false;
	}
	
	return true;
}

std::string Item::getName()
{
	return name;
}

std::string Item::getInstaller()
{
	return installer;
}

std::string Item::getRemover()
{
	return remover;
}
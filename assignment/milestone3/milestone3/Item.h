#ifndef ITEM_H_
#define ITEM_H_

#include <string>

class Item
{
	std::string name, installer, remover, code, desc;

public:
	Item(std::string name, std::string installer, std::string remover, std::string code, std::string desc);
	void display(std::ostream& os);
	void graph(std::ostream& os);

	bool hasInstaller();
	bool hasRemover();

	bool isAlpha(std::string str);

	std::string getName();
	std::string getInstaller();
	std::string getRemover();
};

#endif
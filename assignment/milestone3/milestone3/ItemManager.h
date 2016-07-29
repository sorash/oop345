#ifndef ITEM_MANAGER_H_
#define ITEM_MANAGER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Item.h"

class ItemManager
{
	std::vector<Item> items;
	void addItem(std::vector<std::string> fields, int line);

public:
	ItemManager(std::string& file, char delim);
	void readCSV(std::string& file, char delim);
	void display(std::ostream& os);
	void graph(std::string file);
};

#endif
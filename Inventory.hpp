/****************************************
 * Project filename: Inventory.hpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Inventory class interface
****************************************/

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "Item.hpp"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Inventory
{

	private:
		vector<Item*> items;
		int limit;
		bool validateInput(char);

	public:
		Inventory();
		void add(Item*);
		bool remove(ItemID);
		Item* check();
};

#endif

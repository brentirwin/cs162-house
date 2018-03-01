/****************************************
 * Project filename: Item.hpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Item class interface
****************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include "enum.hpp"

#include <string>
using namespace std;

//enum ItemID { KEY };

class Item
{

	private:
		string name;
		ItemID id;

	public:
		Item(){};
		Item(string, ItemID);
		string getName();
		ItemID getID();

};

#endif

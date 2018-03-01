/****************************************
 * Project filename: Item.cpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Item class implementation
****************************************/

#include "Item.hpp"
using namespace std;

// constructor
Item::Item(string name, ItemID id)
{
	this->name = name;
	this->id = id;
}

// getters
string Item::getName()
{
	return this->name;
}

ItemID Item::getID()
{
	return this->id;
}

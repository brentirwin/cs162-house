/****************************************
 * Project filename: Inventory.cpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Inventory class implementation
****************************************/

#include "Inventory.hpp"
using namespace std;

// constructor
Inventory::Inventory()
{
	this->limit = 2;
}

/****************************************
 * Function: add(Item*)
 * Descriptioin: Adds a pointer to an item to items
 * Parameters: A pointer to an item
 * Pre-conditions: none
 * Post-conditions: items contains one more Item
 * Return: void
****************************************/
void Inventory::add(Item *item)
{
	if (this->items.size() == this->limit)
		cout << "Your bag is full!" << endl << endl;
	else if (item != NULL)
	{	
		this->items.push_back(item);
		cout << "You put the " << item->getName() << " in your bag." << endl
			  << endl;
	}
}

/****************************************
 * Function: remove(itemID)
 * Description: removes an item from the inventory
 * Parameters: ID of item to be removed
 * Pre-conditions: none
 * Post-conditions: one fewer item will be in the inventory
 * Return: true if successful, false if not
****************************************/
bool Inventory::remove(ItemID id)
{
	bool success = false;

	for (int i=0; i<this->items.size(); i++)
	{
		if (success == false)
		{
			if (id == this->items.at(i)->getID())
			{
				this->items.erase(this->items.begin()+i);
				success = true;
			}
		}
	}

	if (success == false)
		cout << "That item wasn't in here." << endl;

	return success;
}

/****************************************
 * Function: check()
 * Description: check the inventory and allows you to select an item
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: none
 * Returns: A pointer to an item
****************************************/
Item* Inventory::check()
{
	Item *chosenItem;

	// case empty bag
	if (this->items.size() == 0)
	{
		cout << "Your bag is empty." << endl;
		chosenItem = NULL;
	}

	// case stuff in bag
	else
	{
		// display options
		cout << "Inventory:" << endl;
		for (int i=0; i<this->items.size(); i++)
			cout << i+1 << ". " << this->items.at(i)->getName() << endl;
		cout << "0. Close" << endl;
		
		// get choice
		int choice;
		cout << "What do you want to get? ";
		cin >> choice;
		if (choice > 0 && choice <= this->items.size())
			chosenItem = this->items.at(choice-1);
		else chosenItem = NULL;
	}

	cout << endl;

	return chosenItem;
}

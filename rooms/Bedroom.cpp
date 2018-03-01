/****************************************
 * Project filename: Bedroom.cpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Bedroom class implementation
****************************************/

#include "Bedroom.hpp"

// constructor
Bedroom::Bedroom(Player *player) : Room(player)
{
	this->name = "Bedroom";
}

/****************************************
 * getInstruction()
****************************************/
void Bedroom::getInstructions()
{
	// Flavor text
	cout << "In the master bedroom stands a massive four-poster bed." << endl
		  << endl;

	// Choices
	cout << "W. Back to the foyer" << endl
		  << "1. Inspect the bed" << endl
		  << endl;
}

/****************************************
 * takeAnswer()
****************************************/
bool Bedroom::takeAnswer(char choice)
{
	bool valid = true;

	// Rooms
	if (choice == 'W')
		player->setRoom(west);

	// Bed
	else if (choice == '1')
	{
		cout << "The bed is unmade, covered in decades of dust." << endl
			  << "Blood splatters from the white sheets to the "
			  << player->getRandomizer()->getWood() << " headboard." << endl
			  << endl;
	}

	// Invalid
	else
		valid = false;
	return valid;
}

/****************************************
 * use(Item*)
****************************************/
bool Bedroom::use(Item* item)
{
	cout << "You can't use that here!" << endl;
	return false;
}


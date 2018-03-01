/****************************************
 * Project filename: Landing.cpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Landing class implementation
****************************************/

#include "Landing.hpp"

// constructor
Landing::Landing(Player *player) : Room(player)
{
	this->hasEnteredBabyRoom = false;
	this->name = "Landing";
}

/****************************************
 * getInstruction()
****************************************/
void Landing::getInstructions()
{
	// Flavortext
	cout << "On the second floor hallway." << endl;

	// Special text if you haven't been in the baby room yet
	if (!hasEnteredBabyRoom)
		cout << "You hear a baby crying behind the door on the south wall." << endl;

	// Choices
	cout << "N. Door to the north" << endl
		  << "W. Staircase down to the west" << endl
		  << "E. Starcase up to the east" << endl
		  << "S. Door to the south" << endl
		  << endl;
}

/****************************************
 * takeAnswer()
****************************************/
bool Landing::takeAnswer(char choice)
{
	bool valid = true;

	// Rooms
	if (choice == 'N')
		player->setRoom(north);
	else if (choice == 'W')
	{
		cout << "The metal steps clang under your feet as you walk down." << endl;
		player->setRoom(west);
	}
	else if (choice == 'E')
		player->setRoom(east);
	else if (choice == 'S')
	{
		player->setRoom(south);
		hasEnteredBabyRoom = true;
	}

	// Invalid
	else
		valid = false;
	return valid;
}

/****************************************
 * use(Item*)
****************************************/
bool Landing::use(Item* item)
{
	cout << "You can't use that here!" << endl;
	return false;
}


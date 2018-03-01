/****************************************
 * Project filename: Foyer.cpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Foyer class implementation
****************************************/

#include "Foyer.hpp"

// constructor
Foyer::Foyer(Player *player) : Room(player)
{
	this->name = "Foyer";
	this->firstTime = true;
}

/****************************************
 * getInstruction()
****************************************/
void Foyer::getInstructions()
{
	// First time text
	if (firstTime)
	{	
		cout << "You pass through the wrought iron gate and stare up at" << endl
			  << "the tall house leaning over you. The door is already open." << endl
			  << "You walk inside and the heavy door slams behind you. You" << endl
			  << "try to get back out, but it is locked. You are trapped." << endl
			  << "Inside you see a tall grandfather clock. It chimes eleven times." << endl
			  << "To the west is a staircase." << endl
			  << "To the north and to the east are two closed doors." << endl
			  << endl;
		firstTime = false;
	}

	// Subsequent times text
	else
	{
		cout << "Back in the grand foyer." << endl;
	}

	// Choices
	cout << "N. Door to the north" << endl
		  << "W. Staircase to the west" << endl
		  << "E. Door to the east" << endl
		  << "1. Inspect the clock" << endl
		  << endl;
}

/****************************************
 * takeAnswer()
****************************************/
bool Foyer::takeAnswer(char choice)
{
	bool valid = true;

	// Rooms
	if (choice == 'N')
		player->setRoom(north);
	else if (choice == 'W')
	{
		cout << "You traverse the hollow, spiral staircase to the second floor." << endl;
		player->setRoom(west);
	}
	else if (choice == 'E')
		player->setRoom(east);

	// Clock
	else if (choice == '1')
	{
		cout << "The clock seems to be watching you." << endl
			  << "It dongs aggressively as you approach." << endl
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
bool Foyer::use(Item* item)
{
	cout << "You can't use that here!" << endl;
	return false;
}


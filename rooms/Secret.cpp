/****************************************
 * Project filename: Secret.cpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Secret class implementation
****************************************/

#include "Secret.hpp"

// constructor
Secret::Secret(Player *player, Item *sword) : Room(player)
{
	swordHere = true;
	this->sword = sword;
	this->name = "Secret Room";
}

/****************************************
 * getInstruction()
****************************************/
void Secret::getInstructions()
{
	// Flavor text
	cout << "You pull back the bookcase and walk into the small secret room." << endl
		  << "Inside lies a chest." << endl
		  << endl
	// Options
		  << "W. Back to the library" << endl
		  << "1. Open the chest" << endl
		  << endl;
}

/****************************************
 * takeAnswer()
****************************************/
bool Secret::takeAnswer(char choice)
{
	bool valid = true;

	// Rooms
	if (choice == 'W')
		player->setRoom(west);
	
	// Chest
	else if (choice == '1' && swordHere)
	{
		cout << "You open the chest. Inside you find the sword." << endl
			  << "Do you take it? (y/n)" << endl;
		char takeSword;
		cin  >> takeSword;
		takeSword = toupper(takeSword);
		while (takeSword != 'Y' && takeSword != 'N')
		{
			cout << "Please enter y or n: ";
			cin  >> takeSword;
			takeSword = toupper(takeSword);
		}
		if (takeSword == 'Y')
		{
			cout << "You take the sword." << endl;
			player->addInventory(sword);
			swordHere = false;
		}
		else if (takeSword == 'N')
			cout << "You do not take the sword." << endl;
	}
	else if (choice == '1' && !swordHere)
	{
		cout << "The chest is just as empty as you left it." << endl;
	}
	
	// Invald
	else
		valid = false;
	return valid;
}

/****************************************
 * use(Item*)
****************************************/
bool Secret::use(Item* item)
{
	cout << "You can't use that here!" << endl;
	return false;
}


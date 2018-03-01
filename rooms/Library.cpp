/****************************************
 * Project filename: Library.cpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Library class implementation
****************************************/

#include "Library.hpp"

// constructor
Library::Library(Player *player) : Room(player)
{
	this->secretDoorFound = false;
	this->name = "Library";
}

/****************************************
 * getInstruction()
****************************************/
void Library::getInstructions()
{ 
	// Flavor text
		cout << "You enter an old library. The walls are covered with" << endl
			  << "shelves reaching the 10-foot ceilings. A desk sits in the center." << endl
			  << endl;

	// Choices
	cout << "S. Door to the south" << endl
		  << "1. Inspect the desk" << endl;
	
	// If secret door is not yet open
	if (!secretDoorFound)	  
		cout << "2. Inspect the books" << endl;
	
	// If secret door is open
	if (secretDoorFound)
		cout << "E. Move through secret door" << endl;
		 
	cout  << endl;
}

/****************************************
 * takeAnswer()
****************************************/
bool Library::takeAnswer(char choice)
{
	bool valid = true;

	// Rooms
	if (choice == 'S')
		player->setRoom(south);
	else if (choice == 'E' && secretDoorFound)
		player->setRoom(east);

	// Desk
	else if (choice == '1')
	{
		cout << "On the desk you see a sheet of paper titled \"SACRIFICES, "
			  << player->getRandomizer()->getYear() << "\"" << endl
			  << "A list of names runs down the page next to dates hundred of years old." << endl
			  << endl;
	}

	// Bookshelf
	else if (choice == '2' && !secretDoorFound)
	{
		cout << "As you search through the books, one stands out." << endl
			  << "Nearly 6 inches thick, it is titled \"Magick and Grimories\"" << endl
			  << "When you pull it out, a secret door opens to the east." << endl
			  << endl
			  << "E. Go through the secret door." << endl
			  << endl;
		secretDoorFound = true;
	}

	// Invalid
	else
		valid = false;
	return valid;
}

/****************************************
 * use(Item*)
****************************************/
bool Library::use(Item* item)
{
	cout << "You can't use that here!" << endl;
	return false;
}


/****************************************
 * Project filename: Dining.cpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Dining class implementation
****************************************/

#include "Dining.hpp"

// constructor
Dining::Dining(Player *player, Item *garlic) : Room(player)
{
	garlicHere = true;
	this->garlic = garlic;
	this->name = "Dining";
}

/****************************************
 * getInstruction()
****************************************/
void Dining::getInstructions()
{
	// Flavor text
	cout << "You enter into a grand dining room. The table is set with fine" << endl
		  << "crystal glasses and corroded silver plates and silverware." << endl
		  << "A thick layer of dust covers everything." << endl
		  << "An eerie painting is displayed prominently on the wall." << endl
		  << endl
	// Options
		  << "S. Door to the south" << endl
		  << "1. Inspect the painting" << endl
		  << "2. Inspect the table" << endl
		  << endl;
}

/****************************************
 * takeAnswer()
****************************************/
bool Dining::takeAnswer(char choice)
{
	bool valid = true;

	// Rooms
	if (choice == 'S')
		player->setRoom(south);
	
	// Painting
	else if (choice == '1')
	{
		cout << "The painting, 7 feet across, depicts a man, woman, and baby." << endl
			  << "The man is holding the baby. The woman wears a "
			  << player->getRandomizer()->getDress() << " dress" << endl
			  << "and looks displeased." << endl
			  << endl;
	}

	// Dining table
	else if (choice == '2')
	{
		cout << "On the table you find an old, rotten clove of garlic." << endl
			  << "Do you take it with you? (y/n)" << endl;
		char takeGarlic;
		cin  >> takeGarlic;
		takeGarlic = toupper(takeGarlic);
		while (takeGarlic != 'Y' && takeGarlic != 'N')
		{
			cout << "Please enter y or n: ";
			cin  >> takeGarlic;
		}
		if (takeGarlic == 'Y')
		{
			cout << "You take the garlic." << endl;
			player->addInventory(garlic);
			garlicHere = false;
		}
		else if (takeGarlic == 'N')
		{
			cout << "You leave the garlic." << endl;
		}
	}
	
	// Invaldi	
	else
		valid = false;
	return valid;
}

/****************************************
 * use(Item*)
****************************************/
bool Dining::use(Item* item)
{
	cout << "You can't use that here!" << endl;
	return false;
}


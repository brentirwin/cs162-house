/****************************************
 * Project filename: Baby.cpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Baby class implementation
****************************************/

#include "Baby.hpp"

// constructor
Baby::Baby(Player *player) : Room(player)
{
	this->name = "Nursery";
	this->ghoulAlive = true;
	this->firstTime = true;
	this->firstEscape = true;
}

/****************************************
 * getInstruction()
****************************************/
void Baby::getInstructions()
{
	// Ghoul is alive first time text
	if (ghoulAlive && firstTime)
	{	
		cout << "As soon as you open the door, the baby's screams stop." << endl
			  << "You approach the crib where you see a small swaddled mass." << endl
			  << "As you bend over to look inside, you feel a presence." << endl
			  << "There before you is a ghastly nursemaid, semitransparent" << endl
			  << "and rotting to pieces." << endl
			  << endl
			  << "N. RUUUUUUUUUN!" << endl
			  << endl;
		firstTime = false;
	}

	// Back in but ghoul is still there text
	else if (ghoulAlive && !firstTime)
	{
		cout << "The scary floating ghoul is still there. She reaches out for you." << endl
			  << endl
		  	  << "N. RUUUUUUUUN!" << endl
			  << endl;
	}

	// The ghoul is gone.
	else if (!ghoulAlive)
	{
		cout << "In the baby's bedroom, you hear nothing but your own breath." << endl
			  << endl
			  << "N. Return to hallway" << endl
			  << "1. Inspect the crib" << endl
			  << endl;
	}
}

/****************************************
 * takeAnswer()
****************************************/
bool Baby::takeAnswer(char choice)
{
	bool valid = true;

	// Rooms
	if (choice == 'N' && ghoulAlive && firstEscape)
	{
		cout << "You narrowly escaped the ghoul's grasp." << endl;
		player->setRoom(north);
		this->firstEscape = false;
	}
	else if (choice == 'N' && ghoulAlive && !firstEscape)
	{
		cout << "You thought you could outrun her twice? Wrong." << endl
			  << "The ghould grabs you by the throat. You feel her icy" << endl
			  << "cold fingers squeezing tight. You smell rotting flesh" << endl
			  << "and struggle for breath as the nursemaid opens her mouth" << endl
			  << "and chews into your face." << endl
			  << endl;
		player->kill();
	}
	else if (choice == 'N' && !ghoulAlive)
		player->setRoom(north);	

	// Crib
	else if (choice == '1')
	{
		cout << "You once again approach the baby's crib." << endl
			  << "A nameplate above it says \""
			  << player->getRandomizer()->getName() << "\". "
			  << "As you pick" << endl
			  << "up the small child, you see that it is nothing but a skelton" << endl
			  << "inside, left to decay for centuries." << endl
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
bool Baby::use(Item* item)
{
	bool valid = false;

	// Use garlic
	if (item->getID() == GARLIC)
	{
		cout << "You pull out the garlic and throw it at the ghoul." << endl
			  << "It releases a blood-curtling scream as the garlic" << endl
			  << "burns through its ectoplasmic face. It dissitegrates" << endl
			  << "into steam that dissipates into the air." << endl
			  << endl
			  << "1. Inspect the crib" << endl
			  << endl;
		valid = true;
		ghoulAlive = false;
	}

	// Use sword
	else if (item->getID() == SWORD)
	{
		cout << "You attempt to stab the ghoul with the sword, but it" << endl
			  << "passes through it. You lean foward into the hideous" << endl
			  << "creature. It grabs the sword itself and stabs you in" << endl
			  << "in the stomach. You fall on the ground bleeding as the" << endl
			  << "nursemaid eats away at your flesh." << endl
			  << endl;
		player->kill();
	}

	// Invalid
	else
		cout << "You can't use that here!" << endl;

	return valid;
}


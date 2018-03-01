/****************************************
 * Project filename: Outside.cpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Outside class implementation
****************************************/

#include "Outside.hpp"

// constructor
Outside::Outside(Player *player) : Room(player)
{
	this->name = "Outside";
}

/****************************************
 * getInstruction()
****************************************/
void Outside::getInstructions()
{
	cout << "You find yourself in an eerie old town." << endl
		  << "The cobblestone streets are narrow and the tall buildings" << endl
		  << "seem to cave in above you." << endl
		  << endl
		  << "You hear a whimpering coming from a dark alley." << endl
		  << "You go to inspect and find a small boy and girl crying" << endl
		  << "outside of a dilapidated house with boarded windows." << endl
		  << "You ask what is wrong." << endl
		  << endl
		  << "The boy is too frightened to talk. The girl speaks up." << endl
		  << "\"We cannot go back inside,\" she says. \"Our parents" << endl
		  << "keep a monster in the basement, and they're not here" << endl
		  << "Please, our baby brother is trapped inside his room." << endl
		  << endl
		  << "\"Tell about midnight, Rose,\" the small boy says." << endl
		  << endl
		  << "\"Thorn is talking about the voices,\" she explains." << endl
		  << "We keep hearing an eerie voice say, 'Get out before" << endl
		  << "midnight, and neither of us can tell where it's coming" << endl
		  << "from. That's why we left the house. Please, save our brother" << endl
		  << "and stop the monster!" << endl
		  << endl
		  << "1. Enter the house" << endl
		  << endl;
}

/****************************************
 * takeAnswer()
****************************************/
bool Outside::takeAnswer(char choice)
{
	bool valid = true;
	if (choice == '1')
		player->setRoom(north);
	else
		valid = false;
	return valid;
}

/****************************************
 * use(Item*)
****************************************/
bool Outside::use(Item* item)
{
	return true;
}



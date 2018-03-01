/****************************************
 * Project filename: Attic.cpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Attic class implementation
****************************************/

#include "Attic.hpp"

// constructor
Attic::Attic(Player *player) : Room(player)
{
	this->name = "Attic";
	this->secretOpen = false;
}

/****************************************
 * getInstruction()
****************************************/
void Attic::getInstructions()
{
	// Before talking to the children
	if (!secretOpen)
	{	
		cout << "You enter an old unfinished attic. The floorboards creak," << endl
			  << "and a small trickle of water falls from a spot in the roof." << endl
			  << "With improper insulation, this attic is colder than the" << endl
			  << "rest of the house. You see rain fall in the darkness beyond" << endl
			  << "the cast iron bars on the window. A dollhouse sits on the floor." << endl
			  << "On the bed are two small skeletons, dressed just like the." << endl
			  << "children you met outside." << endl
			  << endl
			  << "E. Stairs going back down" << endl
			  << "1. Inspect the dollhouse" << endl
			  << "2. Inspect the skeletons" << endl
			  << endl;
	}

	// After talking to the children
	else
	{
		cout << "The dollhouse sits on the floor. The childrens' corpses lie still." << endl
			  << endl
			  << "E. Stairs going back down" << endl
			  << "S. Secret chute to the basement" << endl
			  << "1. Inspect the dollhouse" << endl
			  << "2. Inspect the skeletons" << endl
			  << endl;
	}

}

/****************************************
 * takeAnswer()
****************************************/
bool Attic::takeAnswer(char choice)
{
	bool valid = true;

	// Rooms
	if (choice == 'E')
		player->setRoom(east);
	else if (choice == 'S' && secretOpen)
	{
		cout << "You hold tightly to the center bar as you're squeezed down" << endl
			  << "the extremely steep spiral staircase crammed into this chimney." << endl
			  << endl;
		player->setRoom(south);
	}

	// Dollhouse
	else if (choice == '1')
	{
		cout << "Upon closer inspection, the dollhouse appears to be eerily" << endl
			  << "similar to the house you are in. The rooms are laid out the" << endl
			  << "same, painted the same, and contain the same furniture as" << endl
			  << "their counterparts in the room you are in now. It even" << endl
			  << "the same thick layer of dust you have seen everywhere." << endl;
		if (secretOpen)
			cout << "You see the small chimney running down to the basement." << endl;
		cout << endl;
	}

	// Skeletons
	else if (choice == '2')
	{
		if (!secretOpen)
		{
			cout << "Leaning over the skeletons, you find that they are indeed" << endl
				  << "wearing the same clothes as the children you met outside." << endl
				  << "They are the same sizes, too."
				  << endl
				  << "\"You found us.\" You hear a voice from behind. You turn" << endl
				  << "around to see the ghosts of Rose and Thorn." << endl
				  << endl
				  << "Rose begins to speak. \"Our parents sometimes lock us in our" << endl
				  << "room to protect us from the monster. They say they have to" << endl
				  << "keep it in the basement so that it won't escape and eat us." << endl
				  << "One day they locked us up here, and they never let us out." << endl
				  << "We heard the screams coming from the cellar every day," << endl
				  << "but we were left in here to starve. You have to slay the" << endl
				  << "monster to free our souls from this curse, so that we may" << endl
				  << "move on.\"" << endl
				  << endl
				  << "Thorn walks over to the dollhouse and speaks for the first time." << endl
				  << "\"The fireplace in here conceals a secret path to the cellar." << endl
				  << "Please go down and save us.\" He reveals in the dollhouse that" << endl
				  << "the chimneyway running the entire height of the house is indeed" << endl
				  << "a narrow staircase. As he does so, the fireplace in the room" << endl
				  << "slides open and reveals a dark passage downward." << endl
				  << endl
				  << "With this, the children disappear before your eyes." << endl
				  << endl
				  << "S. Secret chute to basement" << endl
				  << endl;
			secretOpen = true;
		}
		else
		{
			cout << "The skeletons lie there just as before as a reminder of their" << endl
				  << "souls trapped inside the house. Resolutely, you know you must" << endl
				  << "face the greatest danger that lies in this cursed house." << endl
				  << endl;
		}
	}

	// Invalid
	else
		valid = false;
	return valid;
}

/****************************************
 * use(Item*)
****************************************/
bool Attic::use(Item* item)
{
	cout << "You can't use that here!" << endl;
	return false;
}


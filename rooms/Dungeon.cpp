/****************************************
 * Project filename: Dungeon.cpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Dungeon class implementation
****************************************/

#include "Dungeon.hpp"

// constructor
Dungeon::Dungeon(Player *player) : Room(player)
{
	this->name = "Dungeon";
}

/****************************************
 * getInstruction()
****************************************/
void Dungeon::getInstructions()
{
	// Flavortext
	cout << "As you cross through the doorway, a narrow path steeply leads" << endl
		  << "you down into the belly of a huge cavern situated below the town." << endl
		  << "You hear drops of water echoing in the distance. In the middle" << endl
		  << "of the massive floor sits a single barely-lit brazier in the" << endl
		  << "darkness. You make your way to it with nowhere else to turn." << endl
		  << endl
		  << "You stare into the flames and feel the heat against the cold" << endl
		  << "dampness you've grown accustomed to. Behind you, you hear a" << endl
		  << "creature smack its lips exactly once. You turn around to see" << endl
		  << "a hideous meat monster. Gross and deformed. Long and gangly" << endl
		  << "like a lizard with arms, legs, and eyes of all different shapes" << endl
		  << "and sizes protruding in every direction. At the top sits a" << endl
		  << "large open hole with rows of shark-like teeth. This hole moves" << endl
		  << "as the monster speaks to you. Its voice raises chills you." << endl
		  << endl
		  << "\"For decades this family served me greatly. They found me poor" << endl
		  << "and decrepit. I was on the brink of death. I promised them if" << endl
		  << "they would feed me the joy in a human soul that I would grant" << endl
		  << "them powers beyond their wildest dreams. Myrna loved this idea." << endl
		  << "She gladly drew in visitors to the town into her private 'wine" << endl
		  << "cellar' so that I could devour their happiness and gain" << endl
		  << "strength. I have her the ability to control the minds of others." << endl
		  << "She could just as easily lure victims into my lair as she could" << endl
		  << "influence the governors of the town or the barons sitting on" << endl
		  << "their piles of gold." << endl
		  << endl
		  << "\"However, Ronald seemed to have a weakness." << endl
		  << "He cared too much for the children. He pretended to go along" << endl
		  << "with it, but I knew. I always know. He was planning to slay me" << endl
		  << "in an attempt to protect his pathetic children. So I gave Myrna" << endl
		  << "a task. She was to use her powers to convince Ronald to feed" << endl
		  << "himself to me. Her power was so great that it was no problem" << endl
		  << "for her. But it turns out she was weak too. After all she had" << endl
		  << "done for me, a part of her broke when she saw she had killed" << endl
		  << "her lover. I saw this weakness, and I ate her as well." << endl
		  << endl
		  << "\"This was foolish on my part, for now I have not eaten in" << endl
		  << "centuries. Don't worry, puny human. It won't be painful. But I" << endl
		  << "will not hesitate. You will be mine. I am starving.\"" << endl
		  << endl;

	// Choices
	cout << "1. Run" << endl
		  << "2. Scream" << endl
		  << "3. Hadouken" << endl
		  << endl;
}

/****************************************
 * takeAnswer()
****************************************/
bool Dungeon::takeAnswer(char choice)
{
	bool valid = true;
	
	// Run
	if (choice == '1')
	{
		cout << "You run back to the door you came in. As you viciously pull on" << endl
			  << "the handle, the door does not move one bit. It seems to have" << endl
			  << "been magically sealed shut. You claw at the door until the" << endl
			  << "monster opens its gaping maw and swallows your head." << endl
			  << endl;
		player->kill();
	}

	// Scream
	else if (choice == '2')
	{
		cout << "You stand paralyzed in fear as the monster approaches you. It" << endl
			  << "opens its gaping maw and swallows your head." << endl
			  << endl;
		player->kill();
	}

	// Hadouken
	else if (choice == '3')
	{
		cout << "You place your wrists together, palms facing the beast." << endl
			  << "You squeeze your eyes shut and focus all your energy." << endl
			  << "\"HADOUKEN!\" you scream. You open your eyes and realize" << endl
			  << "nothing happened. The monster is right on top of you. It" << endl
			  << "opens its gaping maw and swallows your head." << endl
			  << endl;
		player->kill();
	}

	// Invalid
	else
		valid = false;
	return valid;
}

/****************************************
 * use(Item*)
****************************************/
bool Dungeon::use(Item* item)
{
	bool valid = false;

	// use sword
	if (item->getID() == SWORD)
	{
		player->win();
		valid = true;
	}

	// garlic
	else if (item->getID() == GARLIC)
	{
		cout << "You throw the garlic at the monster, and it eats it." << endl
			  << "Next it opens its gaping maw and swallows your head too." << endl
			  << endl;
		player->kill();
	}

	// invalid
	else
		cout << "You can't use that here!" << endl;

	return valid;
}


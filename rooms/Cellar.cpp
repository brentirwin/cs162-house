/****************************************
 * Project filename: Cellar.cpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Cellar class implementation
****************************************/

#include "Cellar.hpp"

// constructor
Cellar::Cellar(Player *player) : Room(player)
{
	this->ghoulVanquished = false;
	this->ghoulAppeared = false;
	this->name = "Cellar";
}

/****************************************
 * getInstruction()
****************************************/
void Cellar::getInstructions()
{
	// Flavortext
	cout << "The cellar is completely made of dank, moldy flagstone." << endl
		  << "A door is on the south side of the room." << endl;
	if (ghoulAppeared && !ghoulVanquished)
		cout << "The ghoul stands in your way to the south door." << endl;
	cout << endl
		  << "N. Back up the chimney" << endl;
	if (!ghoulAppeared || (ghoulAppeared && ghoulVanquished))
		cout << "S. Go through south door" << endl;
	if (ghoulAppeared && !ghoulVanquished)
		cout << "S. Approach the ghoul." << endl;
	cout << endl;
}

/****************************************
 * takeAnswer()
****************************************/
bool Cellar::takeAnswer(char choice)
{
	bool valid = true;

	// Rooms
	if (choice == 'N')
		player->setRoom(north);
	else if (choice == 'S')
	{
		// First time
		if (!ghoulAppeared)
		{
			cout << "As you approach the south door, you hear a deadly cackle." << endl
				  << "A fiendish appirition swoops down before you, blocking" << endl
				  << "the way. \"So you wish to pass?\" it asks. \"I represent" << endl
				  << "the souls of all those sacrificed by the owners of this" << endl
				  << "house. If you think you have what it takes to face the" << endl
				  << "monster inside, you must first prove your worth. If you" << endl
				  << "cannot pass my trial,\" it chuckles, \"then too bad for" << endl
				  << "you. Are you ready to begin? Once you start, there is no" << endl
				  << "turning back." << endl
				  << endl
				  << "Y. Let's do it!" << endl
				  << "N. I need more time." << endl;
			ghoulQuiz();
		}

		// Returning
		else if (ghoulAppeared && !ghoulVanquished)
		{
			cout << "\"So you have returned,\" the appirition grins." << endl
				  << "\"Are you ready now?\"" << endl
				  << endl
				  << "Y. I guess so..." << endl
				  << "N. I still need more time." << endl;
			ghoulQuiz();
		}

		// He's gone
		// I don't think this one ie necessary
		else if (ghoulAppeared && ghoulVanquished)
		{
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
bool Cellar::use(Item* item)
{
	cout << "You can't use that here!" << endl;
	return false;
}

/****************************************
 * Function: ghoulQuiz()
 * Description: Holds the ghoul quiz
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: Player returns to attic, moves on to dungeon,
 * 	or is killed
 * Returns: void
****************************************/
void Cellar::ghoulQuiz()
{
	char decision;
	cin  >> decision;
	decision = toupper(decision);
	while (decision != 'Y' && decision != 'N')
	{
		cout << "Please enter y or n: ";
		cin  >> decision;
		decision = toupper(decision);
	}
	
	// Not ready
	if (decision == 'N')
	{
		cout << "The ghoul watches peacefully as you return to the attic." << endl;
		player->setRoom(north);
	}

	// Let's go
	else if (decision == 'Y')
	{
		cout << "\"Let the quiz begin!\" the ghoul cackles." << endl << endl;
		bool answer1 = player->getRandomizer()->getQuestion1();
		if (!answer1)
		{
			cout << endl
				  << "The appirition stares you in the eyes. You are paralyzed." << endl
				  << "You try to move, but its gaze has you transfixed. You feel" << endl
				  << "an evil cold rush through your body as it swoops inside you" << endl
				  << "and takes over. You feel it twisting your neck from the" << endl
				  << "inside until you fall dead to the cold, stone floor." << endl
				  << endl;
			player->kill();
		}
		else if (answer1)
		{
			bool answer2 = player->getRandomizer()->getQuestion2();
			if (!answer2)
			{
				cout << endl
					  << "The appirition stares you in the eyes. You are paralyzed." << endl
					  << "You try to move, but its gaze has you transfixed. You feel" << endl
					  << "an evil cold rush through your body as it swoops inside you" << endl
					  << "and takes over. You feel it twisting your neck from the" << endl
					  << "inside until you fall dead to the cold, stone floor." << endl
					  << endl;
				player->kill();
			}
			else if (answer2)
			{
				cout << "\"Impressive,\" the appirition says. \"Good luck," << endl
					  << "traveller. You'll need it.\" With that, it swooped" << endl
					  << "up into the ceiling and out of sight." << endl
					  << endl;
				player->setRoom(south);
			}
		}
	}
}


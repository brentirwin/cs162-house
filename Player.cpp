/****************************************
 * Project filename: Player.cpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Descripton: Player class implmenation
****************************************/

#include "Player.hpp"
#include "rooms/Room.hpp"
using namespace std;

// constructor
Player::Player(Randomizer *randomizer)
{
	this->randomizer = randomizer;
	this->winner = false;
	this->midnight = false;
	this->alive = true;	
}

// getter
Randomizer* Player::getRandomizer()
{
	return this->randomizer;
}

// play() plays the game
void Player:: play()
{
	cout << "-------------------------" << endl
		  << "|  House of Sacrifices  |" << endl
		  << "|      Brent Irwin      |" << endl
		  << "| CS162 - Final Project |" << endl
		  << "-------------------------" << endl
		  << endl;

	coreLoop();
	endGame();
}

/****************************************
 * Function: coreLoop()
 * Description: the core loop of the game. It's a hefty one.
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: none
 * Returns: void
****************************************/
void Player::coreLoop()
{
	do {
		// Display room-specific instructions
		if (newRoom)
		{
			cout << "************************" << endl
				  << "    " << this->room->getName() << endl
				  << "************************" << endl
				  << endl;
		
			// Show clock
			this->clock.showTime();

			// Room instructions
			this->room->getInstructions();
			cout << "I. Inventory" << endl
				  << "C. Check clock" << endl
				  << endl;
		}

		// Reset new room bool
		this->newRoom = false;

		// Get user choice
		char choice;
		cout << "What do you do? ";
		cin >> choice;
		choice = toupper(choice);
		cout << endl;

		// Do it
		// Open the inventory
		if (choice == 'I')
		{
			// Look inside
			Item *item;
			item = inventory.check();
			// If an item is returned
			if (item != NULL)
			{
				// Use it on a room. If it is used, remove it from inventory
				if (room->use(item))
					inventory.remove(item->getID());
			}
		}	
		// Check the clock		
		else if (choice == 'C')
			clock.check();
		// Otherwise send the value to Room
		else
		{
			bool validChoice = true;
			validChoice = room->takeAnswer(choice);
			while (!validChoice)
			{
				cout << "That was an invalid choice. Try again: ";
				cin >> choice;
				choice = toupper(choice);
				validChoice = room->takeAnswer(choice);
			}
		}
	
		// If a new room has been set in this loop, advance the clock
		if (newRoom)
			midnight = clock.tick();
	}
	// Tick the clock and go again as long as it isn't midnight
	while (!midnight && alive && !winner);
}

/****************************************
 * Function: addInventory(Item*)
 * Descriptioin: Adds an item to the inventory
 * Parameters: pointer to an item to be added
 * Pre-conditions: none
 * Post-conditions: one more item in the inventory
 * Return: void
****************************************/
void Player::addInventory(Item *item)
{
	inventory.add(item);
}

/****************************************
 * Function: setRoom(Room*)
 * Description: sets the room to a new room
 * Parameters: a pointer to a room
 * Pre-conditions: none
 * Post-conditions: newRoom is changed to true
 * Return: void
****************************************/
void Player::setRoom(Room *room)
{
	this->room = room;
	this->newRoom = true;
}

/****************************************
 * Function: endGame()
 * Description: The end of the game, after coreLoop is over
 * Parameters: none
 * Pre-conditions: The player has won or died
 * Post-conditions: none
 * Return: void
****************************************/
void Player::endGame()
{
	// midnight
	if (midnight)
	{
		cout << "As the great grandfather clock hits its twelfth chime," << endl
			  << "the ground below you begins to shake. Suddenly fire" << endl
			  << "erupts from the walls around you and begins to consume" << endl
			  << "you alive. You hear a deep, menacing chuckle as you" << endl
			  << "quickly burn to death." << endl
			  << endl;
	}

	// winner
	if (winner)
	{
		cout << "You pull the sword out, and it takes the beast by surprise." << endl
			  << "It tries to escape, but you use the blade to pierce the" << endl
			  << "odd eyes and remove the grotesque appendages. You hack and" << endl
			  << "slash as the monstrosity squeals in pain. You do not stop" << endl
			  << "until you are absolutely certain it has perished." << endl
			  << endl
			  << "At this point, you see dozens or even hundreds of souls" << endl
			  << "rise from the ground and head toward the heavens. Before" << endl
			  << "you float the souls of Rose, Thorn, and baby "
			  << randomizer->getName() << "." << endl
			  << "They smile at you graciously. Thorn runs forward to hug" << endl
			  << "you, but he only passes through you. His sister chuckles," << endl
			  << "and as they reunite, the ascend through the cavern ceiling" << endl
			  << "with the rest of the spirits." << endl
			  << endl
			  << "You win." << endl
			  << endl;
	}

	// game over
	cout << "GAME OVER" << endl
		  << endl;
}

/****************************************
 * Function: kill()
 * Description: Kills the player
 * Parameters: none
 * Pre-conditions: The player died
 * Post-conditions: alive is set to false
 * Return: void
****************************************/
void Player::kill()
{
	this->alive = false;
}

/****************************************
 * Function: win()
 * Description: Ends the game if you win
 * Parameters: none
 * Pre-conditions: The player won
 * Post-conditions: winner is set to true
 * Return: void
****************************************/
void Player::win()
{
	this->winner = true;
}

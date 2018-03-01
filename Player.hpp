/****************************************
 * Project filename: Player.hpp
 * Author: Brent Irwin
 * Date: 1 December 2016
 * Description: Player class interface
****************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Clock.hpp"
#include "Inventory.hpp"
#include "Randomizer.hpp"
#include <string>
#include <iostream>
using namespace std;

class Room;

class Player
{ 

	private:
		Clock clock;
		Room *room;
		Randomizer *randomizer;
		Inventory inventory;
		bool newRoom;
		bool alive;
		bool midnight;
		bool winner;
		void coreLoop();
		void endGame();

	public:		
		Player(Randomizer*);
		void play();
		void addInventory(Item*);
		void setRoom(Room*);
		void kill();
		Randomizer* getRandomizer();
		void win();

};

#endif

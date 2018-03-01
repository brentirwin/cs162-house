/****************************************
 * Project filename: rooms/Room.hpp
 * Author: Brent Irwin
 * Date: 28 November 2016
 * Description: abstract Room class interface
****************************************/

#ifndef ROOM_HPP
#define ROOM_HPP

#include "../Item.hpp"
#include <iostream>
#include <string>
#include "../Player.hpp"
using namespace std;


class Room
{

	protected:
		Room *north;
		Room *east;
		Room *south;
		Room *west;
		Player *player;
		//bool validateInput(char);
		string name;
	
	public:
		Room(Player*);
		Room(Player*, Item*);
		void setDoors(Room*, Room*, Room*, Room*);
		virtual void getInstructions() = 0;
		virtual bool takeAnswer(char) = 0;
		virtual bool use(Item*) = 0 ;
		string getName();
};

#endif

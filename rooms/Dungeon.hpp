/****************************************
 * Project filename: Dungeon.hpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Dungeon class interface
****************************************/

#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include "Room.hpp"
using namespace std;

class Dungeon : public Room
{

	private:

	public:
		Dungeon(Player*);
		void getInstructions();
		bool takeAnswer(char);
		bool use(Item*);

};

#endif

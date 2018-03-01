/****************************************
 * Project filename: Landing.hpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Landing class interface
****************************************/

#ifndef LANDING_HPP
#define LANDING_HPP

#include "Room.hpp"
using namespace std;

class Landing : public Room
{

	private:
		bool hasEnteredBabyRoom;

	public:
		Landing(Player*);
		void getInstructions();
		bool takeAnswer(char);
		bool use(Item*);

};

#endif

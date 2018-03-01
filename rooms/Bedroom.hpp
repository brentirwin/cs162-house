/****************************************
 * Project filename: Bedroom.hpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Bedroom class interface
****************************************/

#ifndef BEDROOM_HPP
#define BEDROOM_HPP

#include "Room.hpp"
using namespace std;

class Bedroom : public Room
{

	private:
		bool firstTime;

	public:
		Bedroom(Player*);
		void getInstructions();
		bool takeAnswer(char);
		bool use(Item*);

};

#endif

/****************************************
 * Project filename: Foyer.hpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Foyer class interface
****************************************/

#ifndef FOYER_HPP
#define FOYER_HPP

#include "Room.hpp"
using namespace std;

class Foyer : public Room
{

	private:
		bool firstTime;

	public:
		Foyer(Player*);
		void getInstructions();
		bool takeAnswer(char);
		bool use(Item*);

};

#endif

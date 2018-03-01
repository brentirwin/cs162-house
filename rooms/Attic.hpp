/****************************************
 * Project filename: Attic.hpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Attic class interface
****************************************/

#ifndef ATTIC_HPP
#define ATTIC_HPP

#include "Room.hpp"
using namespace std;

class Attic : public Room
{

	private:
		bool secretOpen;

	public:
		Attic(Player*);
		void getInstructions();
		bool takeAnswer(char);
		bool use(Item*);

};

#endif

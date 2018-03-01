/****************************************
 * Project filename: Outside.hpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Outside class interface
****************************************/

#ifndef OUTSIDE_HPP
#define OUTSIDE_HPP

#include "Room.hpp"
using namespace std;

class Outside : public Room
{

	private:

	public:
		Outside(Player*);
		void getInstructions();
		bool takeAnswer(char);
		bool use(Item*);

};

#endif

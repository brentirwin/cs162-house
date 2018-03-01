/****************************************
 * Project filename: Baby.hpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Baby class interface
****************************************/

#ifndef BABY_HPP
#define BABY_HPP

#include "Room.hpp"
using namespace std;

class Baby : public Room
{

	private:
		bool ghoulAlive;
		bool firstTime;
		bool firstEscape;

	public:
		Baby(Player*);
		void getInstructions();
		bool takeAnswer(char);
		bool use(Item*);

};

#endif

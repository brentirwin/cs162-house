/****************************************
 * Project filename: Secret.hpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Secret class interface
****************************************/

#ifndef SECRET_HPP
#define SECRET_HPP

#include "Room.hpp"
using namespace std;

class Secret : public Room
{

	private:
		Item *sword;
		bool swordHere;

	public:
		Secret(Player*, Item*);
		void getInstructions();
		bool takeAnswer(char);
		bool use(Item*);

};

#endif

/****************************************
 * Project filename: Dining.hpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Dining class interface
****************************************/

#ifndef DINING_HPP
#define DINING_HPP

#include "Room.hpp"
using namespace std;

class Dining : public Room
{

	private:
		Item *garlic;
		bool garlicHere;

	public:
		Dining(Player*, Item*);
		void getInstructions();
		bool takeAnswer(char);
		bool use(Item*);

};

#endif

/****************************************
 * Project filename: Library.hpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Library class interface
****************************************/

#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "Room.hpp"
using namespace std;

class Library : public Room
{

	private:
		bool secretDoorFound;

	public:
		Library(Player*);
		void getInstructions();
		bool takeAnswer(char);
		bool use(Item*);

};

#endif

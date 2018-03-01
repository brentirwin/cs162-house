/****************************************
 * Project filename: Cellar.hpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: Cellar class interface
****************************************/

#ifndef CELLAR_HPP
#define CELLAR_HPP

#include "Room.hpp"
using namespace std;

class Cellar : public Room
{

	private:
		bool ghoulAppeared;
		bool ghoulVanquished;
		void ghoulQuiz();

	public:
		Cellar(Player*);
		void getInstructions();
		bool takeAnswer(char);
		bool use(Item*);

};

#endif

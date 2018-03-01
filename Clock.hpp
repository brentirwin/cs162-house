/****************************************
 * Project filename: Clock.hpp
 * Author: Brent Irwin
 * Date: 1 December 2016
 * Description: Clock class interface
****************************************/

#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <string>
#include <iostream>
using namespace std;

class Clock
{

	private:
		string timeCode[31];
		int time;
	
	public:
		Clock();
		bool tick();
		void check();
		void showTime();

};

#endif

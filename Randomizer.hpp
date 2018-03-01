/****************************************
 * Project filename: Randomizer.hpp
 * Author: Brent Irwin
 * Date: 4 December 2016
 * Description: Randomizer class interface
****************************************/

#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include <string>
using namespace std;

class Randomizer
{

	private:
		string dresses[4];
		string woods[4];
		string names[4];
		string years[4];
		int dress;
		int wood;
		int name;
		int year;
		int question1;
		int question2;
		int random();
		bool getQuestion(int);

	public:
		Randomizer();
		string getDress();
		string getWood();
		string getName();
		string getYear();
		bool getQuestion1();
		bool getQuestion2();
		
};

#endif

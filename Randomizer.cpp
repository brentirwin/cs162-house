/****************************************
 * Project filename: Randomizer.cpp
 * Author: Brent Irwin
 * Date: 4 December 2016
 * Description: Randomizer class implementation
****************************************/

#include "Randomizer.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// constructor
Randomizer::Randomizer()
{
	// initalize randomizer
	unsigned seed;
	seed = time(0);
	srand(seed);

	// dress colors
	dresses[0] = "blue";
	dresses[1] = "pink";
	dresses[2] = "black";
	dresses[3] = "red";

	// wood types
	woods[0] = "oak";
	woods[1] = "ash";
	woods[2] = "ebony";
	woods[3] = "pine";

	// years
	years[0] = "1750";
	years[1] = "1723";
	years[2] = "1801";
	years[3] = "1783";

	// baby names
	names[0] = "Mavis";
	names[1] = "Brent";
	names[2] = "Shirley";
	names[3] = "Merle";

	// set random values
	dress = random();
	wood = random();
	name = random();
	year = random();

	// set random questions to ask
	question1 = random();
	do {
		question2 = random();
	} while (question2 == question1);
}

// getters
string Randomizer::getDress()
{
	return dresses[dress];
}

string Randomizer::getWood()
{
	return woods[wood];
}

string Randomizer::getName()
{
	return names[name];
}

string Randomizer::getYear()
{
	return years[year];
}

/****************************************
 * Function: random()
 * Decription: returns a random int 0-3
 * Parameters: none
 * Returns: int
****************************************/
int Randomizer::random()
{
	return rand() % 4;
}

/****************************************
 * Function: getQuestion1()
 * Description: Presents first question
 * Parameters: none
 * Returns: true if answered correctly, false if incorrect
****************************************/
bool Randomizer::getQuestion1()
{
	return getQuestion(question1);
}

/****************************************
 * Function: getQuestion2()
 * Description: Presents second question
 * Parameters: none
 * Returns: true if answered correctly, false if incorrect
****************************************/
bool Randomizer::getQuestion2()
{
	cout << "\"Very good. Let's see if you can get one more,\" it says with" << endl
		  << "determination in its eyes." << endl
		  << endl;
	return getQuestion(question2);
}

/****************************************
 * Function: getQuestion(int)
 * Description: Asks the user one of 4 questions
 * Parameters: int determining which question to ask
 * Returns: true if answered correct, false if incorrect
****************************************/
bool Randomizer::getQuestion(int x)
{
	bool result = false;
	int answer;

	// Dresses
	if (x == 0)
	{
		cout << "What color dress does the woman of the house wear?" << endl
			  << "1. " << dresses[0] << endl
			  << "2. " << dresses[1] << endl
			  << "3. " << dresses[2] << endl
			  << "4. " << dresses[3] << endl
			  << "Your answer: ";
		cin  >> answer;
		while (answer < 1 || answer > 4)
		{
			cout << "Please enter 1-4: ";
			cin  >> answer;
		}
		if ((answer-1) == dress)
		{
			cout << endl;
			result = true;
		}
		else
		{
			cout << endl << "\"Not even close!\" it squeals. \"Her dress is " << dresses[dress] << ".\"" << endl;
		}
	}
	
	// Wood
	else if (x == 1)
	{
		cout << "The master bedframe is made of what type of wood?" << endl
			  << "1. " << woods[0] << endl
			  << "2. " << woods[1] << endl
			  << "3. " << woods[2] << endl
			  << "4. " << woods[3] << endl
			  << "Your answer: ";
		cin  >> answer;
		while (answer < 1 || answer > 4)
		{
			cout << "Please enter 1-4: ";
			cin  >> answer;
		}
		if ((answer-1) == wood)
		{
			cout << endl;
			result = true;
		}
		else
		{
			cout << endl << "\"Nope!\" it squeals. \"The wood is " << woods[wood] << ".\"" << endl;
		}
	}

	// Name
	else if (x == 2)
	{
		cout << "What is the baby's name?" << endl
			  << "1. " << names[0] << endl
			  << "2. " << names[1] << endl
			  << "3. " << names[2] << endl
			  << "4. " << names[3] << endl
			  << "Your answer: ";
		cin  >> answer;
		while (answer < 1 || answer > 4)
		{
			cout << "Please enter 1-4: ";
			cin  >> answer;
		}
		if ((answer-1) == name)
		{
			cout << endl;
			result = true;
		}
		else
		{
			cout << endl << "\"Tough luck,\" it squeals. \"The baby's name is " << names[name] << ".\"" << endl;
		}
	}

	// Year
	else if (x == 3)
	{
		cout << "In what year were the last sacrifices made?" << endl
			  << "1. " << years[0] << endl
			  << "2. " << years[1] << endl
			  << "3. " << years[2] << endl
			  << "4. " << years[3] << endl
			  << "Your answer: ";
		cin  >> answer;
		while (answer < 1 || answer > 4)
		{
			cout << "Please enter 1-4: ";
			cin  >> answer;
		}
		if ((answer-1) == year)
		{
			cout << endl;
			result = true;
		}
		else
		{
			cout << endl << "\"WRONG!\" it squeals. \"The year was " << years[year] << ".\"" << endl;
		}
	}

	// Return
	return result;
}

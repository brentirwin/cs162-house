/****************************************
 * Project Filename: Clock.cpp
 * Author: Brent Irwin
 * Date: 1 December 2016
 * Description: Clock class implmentation
****************************************/

#include "Clock.hpp"

// Constructor
Clock::Clock()
{
	this->time = -1;
	timeCode[0] = "11:00";
	timeCode[1] = "11:02";
	timeCode[2] = "11:04";
	timeCode[3] = "11:06";
	timeCode[4] = "11:08";
	timeCode[5] = "11:10";
	timeCode[6] = "11:12";
	timeCode[7] = "11:14";
	timeCode[8] = "11:16";
	timeCode[9] = "11:18";
	timeCode[10] = "11:20";
	timeCode[11] = "11:22";
	timeCode[12] = "11:24";
	timeCode[13] = "11:26";
	timeCode[14] = "11:28";
	timeCode[15] = "11:30";
	timeCode[16] = "11:32";
	timeCode[17] = "11:34";
	timeCode[18] = "11:36";
	timeCode[19] = "11:38";
	timeCode[20] = "11:40";
	timeCode[21] = "11:42";
	timeCode[22] = "11:44";
	timeCode[23] = "11:46";
	timeCode[24] = "11:48";
	timeCode[25] = "11:50";
	timeCode[26] = "11:52";
	timeCode[27] = "11:54";
	timeCode[28] = "11:56";
	timeCode[29] = "11:58";
	timeCode[30] = "midnight";
//	timeCode = { "9:00", "9:15", "9:30", "9:45",
//					 "10:00", "10:15", "10:30", "10:45",
//					 "11:00", "11:15", "11:30", "11:45", "midnight" };
}

/****************************************
 * Function: tick()
 * Description: advances the clock and displays text
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: the clock is advanced and the console says so
 * Return: true if midnight, false otherwise
****************************************/
bool Clock::tick()
{
	bool midnight = false;
	if (this->time == 29)
		{
			cout << "The clock strikes midnight." << endl << endl;
			midnight = true;
		}
	this->time++;
	return midnight;
}

/****************************************
 * Function: showTime()
 * Description: shows the time every 10 minutes
 * Parameters: none
 * pre-conditions: none
 * post-conditions: none
 * Return: void
****************************************/
void Clock::showTime()
{

	if ((this->time % 5) == 0)
	{
		cout << "The clock strikes " << this->timeCode[this->time]
			  << "." << endl
			  << "An eerie voice rings from the walls: "
			  << "\"GET OUT BEFORE MIDNIGHT!\"" << endl
			  << endl;
	}
}

/****************************************
 * Function: checkTime()
 * Description: Displays the time
 * Parameters: None
 * Pre-conditions: none
 * Post-conditions: none
 * Return: void
****************************************/
void Clock::check()
{
	cout << "It is " << this->timeCode[this->time] << "." << endl << endl;
}

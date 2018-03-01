/****************************************
 * Project filename: Room.cpp
 * Author: Brent Irwin
 * Date: 1 December 2016
 * Description: Room class implementation
****************************************/

#include "Room.hpp"

// constructor
Room::Room(Player *player)
{
	this->player = player;
}

Room::Room(Player *player, Item *item)
{
	this->player = player;
}

// getter
string Room::getName()
{
	return this->name;	
}

/****************************************
 * Function: setDoors(Room*, Room*, Room*, Room*)
 * Description: Links room to other rooms
 * Parameters: 4 pointers to rooms
 * Pre-conditions: none
 * Post-conditions: The room is linked to others
 * Return: void
****************************************/
void Room::setDoors(Room *n, Room *e, Room *s, Room *w)
{
	this->north = n;
	this->east = e;
	this->south = s;
	this->west = w;
}


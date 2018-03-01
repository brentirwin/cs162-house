/****************************************
 * Project filename: main.cpp
 * Author: Brent Irwin
 * Date: 3 December 2016
 * Description: main file for the final project
****************************************/

#include "rooms/Outside.hpp"
#include "rooms/Foyer.hpp"
#include "rooms/Dining.hpp"
#include "rooms/Bedroom.hpp"
#include "rooms/Landing.hpp"
#include "rooms/Library.hpp"
#include "rooms/Secret.hpp"
#include "rooms/Baby.hpp"
#include "rooms/Attic.hpp"
#include "rooms/Cellar.hpp"
#include "rooms/Dungeon.hpp"
#include "Player.hpp"
#include "Item.hpp"
#include "enum.hpp"
#include "Randomizer.hpp"
#include <cstdlib>
using namespace std;

int main()
{
	// Initialize randomizer
	Randomizer randomizer;

	// Initialize player
	Player player(&randomizer);

	// Initialize items
	Item garlic("Garlic", GARLIC);
	Item sword("Sword", SWORD);

	// Initialize rooms
	Outside outside(&player);
	Foyer foyer(&player);
	Dining dining(&player, &garlic);
	Bedroom bedroom(&player);
	Landing landing(&player);
	Library library(&player);
	Secret secret(&player, &sword);
	Baby baby(&player);
	Attic attic(&player);
	Cellar cellar(&player);
	Dungeon dungeon(&player);

	// Set doors
	outside.setDoors(&foyer, NULL, NULL, NULL);
	foyer.setDoors(&dining, &bedroom, NULL, &landing);
	dining.setDoors(NULL, NULL, &foyer, NULL);
	bedroom.setDoors(NULL, NULL, NULL, &foyer);
	landing.setDoors(&library, &attic, &baby, &foyer);
	library.setDoors(NULL, &secret, &landing, NULL);
	secret.setDoors(NULL, NULL, NULL, &library);
	baby.setDoors(&landing, NULL, NULL, NULL);
	attic.setDoors(NULL, &landing, &cellar, NULL);
	cellar.setDoors(&attic, NULL, &dungeon, NULL);
	dungeon.setDoors(&cellar, NULL, NULL, NULL);

	// Set starting room
	player.setRoom(&outside);

	// Play game
	player.play();

	return 0;
}

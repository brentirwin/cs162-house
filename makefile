all:
	g++ main.cpp Player.cpp Randomizer.cpp Clock.cpp Inventory.cpp Item.cpp rooms/Room.cpp rooms/Outside.cpp rooms/Foyer.cpp rooms/Dining.cpp rooms/Bedroom.cpp rooms/Landing.cpp rooms/Library.cpp rooms/Secret.cpp rooms/Baby.cpp rooms/Attic.cpp rooms/Cellar.cpp rooms/Dungeon.cpp -g -o house

clean:
	rm *o finalgame

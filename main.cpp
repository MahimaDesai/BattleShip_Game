// Standard (system) header files
#include <iostream>
#include <cstdlib>

using namespace std;

#include "test_files.h"

// Main program
int main()
{
	//Part 2.1 testing
	part1tests();

	//Part 2.2 testing
	part2tests();

	//Part 2.3 testing
	part3tests();

	//Print board
	Board board(10, 10);
	ConsoleView display(&board);
	OwnGrid &testOwn = board.getOwnGrid();

	testOwn.placeShip(Ship
	{ GridPosition("B2"), GridPosition("B4") });
	testOwn.placeShip(Ship
	{ GridPosition("D4"), GridPosition("G4") });
	testOwn.placeShip(Ship
	{ GridPosition("F6"), GridPosition("F9") });

	testOwn.takeBlow(Shot
	{ GridPosition("B3") });
	testOwn.takeBlow(Shot
	{ GridPosition("B4") });
	testOwn.takeBlow(Shot
	{ GridPosition("B5") });

	OpponentGrid &testOpponent = board.getOpponentGrid();

	testOpponent.shotResult(Shot
	{ GridPosition
	{ "G4" } }, Shot::Impact::NONE);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "F5" } }, Shot::Impact::NONE);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "I5" } }, Shot::Impact::NONE);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "C3" } }, Shot::Impact::HIT);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "C5" } }, Shot::Impact::HIT);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "C4" } }, Shot::Impact::SUNKEN);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "C2" } }, Shot::Impact::NONE);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "G5" } }, Shot::Impact::HIT);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "G6" } }, Shot::Impact::HIT);

	display.print();

	return 0;
}


#include "test_files.h"

using namespace std;

void part3tests()
{
	//Test Own Grid
	Board board(10, 10);
	ConsoleView display(&board);
	OwnGrid &testOwn = board.getOwnGrid();

	assertTrue(testOwn.placeShip(Ship
	{ GridPosition("B2"), GridPosition("B4") }),
			"1st Ship of length 3 not placed");
	assertTrue(testOwn.placeShip(Ship
	{ GridPosition("D4"), GridPosition("G4") }),
			"1st Ship of length 4 not placed");
	assertTrue(testOwn.placeShip(Ship
	{ GridPosition("F6"), GridPosition("F9") }),
			"2nd Ship of length 4 not placed");


	//Test takeBlow
	assertTrue(!(testOwn.takeBlow(Shot
	{ GridPosition("B3") }) != Shot::Impact::HIT), "Ship not hit");
	assertTrue(!(testOwn.takeBlow(Shot
	{ GridPosition("B4") }) != Shot::Impact::HIT), "Ship not hit");
	assertTrue(!(testOwn.takeBlow(Shot
	{ GridPosition("B5") }) != Shot::Impact::NONE),
			"Expected miss hit but ship detected and hit");


	//Test takeBlow with invalid grid position values
	assertTrue(!(testOwn.takeBlow(Shot
	{ GridPosition("B2") }) != Shot::Impact::SUNKEN), "Ship not sunk");
	assertTrue(!(testOwn.takeBlow(Shot
	{ GridPosition("M4") }) != Shot::Impact::NONE),
			"Shot considered for invalid grid values");
	assertTrue(!(testOwn.takeBlow(Shot
	{ GridPosition("@5") }) != Shot::Impact::NONE),
			"Shot considered for invalid grid values");
	assertTrue(!(testOwn.takeBlow(Shot
	{ GridPosition("FF") }) != Shot::Impact::NONE),
			"Shot considered for invalid grid values");


	//Test Opponent Grid
	OpponentGrid &testOpponent = board.getOpponentGrid();

	map<GridPosition, Shot::Impact> testMap;

	testOpponent.shotResult(Shot
	{ GridPosition
	{ "C3" } }, Shot::Impact::HIT);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "C4" } }, Shot::Impact::HIT);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "C5" } }, Shot::Impact::SUNKEN);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "C2" } }, Shot::Impact::NONE);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "G5" } }, Shot::Impact::HIT);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "G6" } }, Shot::Impact::HIT);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "G4" } }, Shot::Impact::NONE);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "F5" } }, Shot::Impact::NONE);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "I5" } }, Shot::Impact::NONE);

	testMap = testOpponent.getShotsAt();

	assertTrue(!(testMap[GridPosition("C3")] != Shot::Impact::SUNKEN),
			"C3 is SUNKEN, but not detected");
	assertTrue(!(testMap[GridPosition("C4")] != Shot::Impact::SUNKEN),
			"C4 is SUNKEN, but not detected");
	assertTrue(!(testMap[GridPosition("C5")] != Shot::Impact::SUNKEN),
			"C5 is SUNKEN, but not detected");
	assertTrue(!(testMap[GridPosition("C2")] != Shot::Impact::NONE),
			"C2 is NONE, but not detected");
	assertTrue(!(testMap[GridPosition("G5")] != Shot::Impact::HIT),
			"G5 is HIT, but not detected");
	assertTrue(!(testMap[GridPosition("G6")] != Shot::Impact::HIT),
			"G6 is HIT, but not detected");
	assertTrue(!(testMap[GridPosition("G4")] != Shot::Impact::NONE),
			"G4 is NONE, but not detected");
	assertTrue(!(testMap[GridPosition("F5")] != Shot::Impact::NONE),
			"F5 is NONE, but not detected");
	assertTrue(!(testMap[GridPosition("I5")] != Shot::Impact::NONE),
			"I5 is NONE, but not detected");


	//Check if more than 1 ship of length 5 can be sunk
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "E10" } }, Shot::Impact::HIT);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "E9" } }, Shot::Impact::HIT);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "E8" } }, Shot::Impact::HIT);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "E7" } }, Shot::Impact::HIT);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "E6" } }, Shot::Impact::SUNKEN);

	testMap = testOpponent.getShotsAt();

	assertTrue(!(testMap[GridPosition("E7")] != Shot::Impact::SUNKEN),
			"E7 is SUNKEN, but not detected");
	assertTrue(!(testMap[GridPosition("E8")] != Shot::Impact::SUNKEN),
			"E8 is SUNKEN, but not detected");
	assertTrue(!(testMap[GridPosition("E9")] != Shot::Impact::SUNKEN),
			"E9 is SUNKEN, but not detected");
	assertTrue(!(testMap[GridPosition("E10")] != Shot::Impact::SUNKEN),
			"E10 is SUNKEN, but not detected");
	assertTrue(!(testMap[GridPosition("E6")] != Shot::Impact::SUNKEN),
			"E6 is SUNKEN, but not detected");


	//Ship 2 of length 5 should not sink
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "A6" } }, Shot::Impact::HIT);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "A7" } }, Shot::Impact::HIT);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "A8" } }, Shot::Impact::HIT);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "A9" } }, Shot::Impact::HIT);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "A10" } }, Shot::Impact::SUNKEN);

	testMap = testOpponent.getShotsAt();

	assertTrue(!(testMap[GridPosition("A6")] == Shot::Impact::SUNKEN),
			"A6 is not SUNKEN, but detected");
	assertTrue(!(testMap[GridPosition("A7")] == Shot::Impact::SUNKEN),
			"A7 is not SUNKEN, but detected");
	assertTrue(!(testMap[GridPosition("A8")] == Shot::Impact::SUNKEN),
			"A8 is not SUNKEN, but detected");
	assertTrue(!(testMap[GridPosition("A9")] == Shot::Impact::SUNKEN),
			"A9 is not SUNKEN, but detected");
	assertTrue(!(testMap[GridPosition("A10")] == Shot::Impact::HIT),
			"A10 is not SUNKEN, but detected");


	//Length 3 ship is sunk
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "J8" } }, Shot::Impact::HIT);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "J9" } }, Shot::Impact::HIT);
	testOpponent.shotResult(Shot
	{ GridPosition
	{ "J10" } }, Shot::Impact::SUNKEN);

	testMap = testOpponent.getShotsAt();

	assertTrue(!(testMap[GridPosition("J8")] != Shot::Impact::SUNKEN),
			"J8 is SUNKEN, but not detected");
	assertTrue(!(testMap[GridPosition("J9")] != Shot::Impact::SUNKEN),
			"J9 is SUNKEN, but not detected");
	assertTrue(!(testMap[GridPosition("J10")] != Shot::Impact::SUNKEN),
			"J10 is SUNKEN, but not detected");


}

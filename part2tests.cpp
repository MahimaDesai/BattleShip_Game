#include "test_files.h"

using namespace std;

void part2tests()
{
	Board board(10, 10);
	ConsoleView display(&board);
	OwnGrid &test = board.getOwnGrid();

	//Test placing 3 ships (B2/B4, D4/G4, F6/F9)
	assertTrue(test.placeShip(Ship
	{ GridPosition("B2"), GridPosition("B4") }),
			"1st Ship of length 3 not placed");
	assertTrue(test.placeShip(Ship
	{ GridPosition("D4"), GridPosition("G4") }),
			"1st Ship of length 4 not placed");
	assertTrue(test.placeShip(Ship
	{ GridPosition("F6"), GridPosition("F9") }),
			"2nd Ship of length 4 not placed");


	//Test placing ships with invalid bow and stern grid positions
	assertTrue(!(test.placeShip(Ship
	{ GridPosition("@1"), GridPosition("@4") })),
			"Ship with invalid bow and stern grid positions can be placed");
	assertTrue(!(test.placeShip(Ship
	{ GridPosition("D0"), GridPosition("D3") })),
			"Ship with invalid bow and stern grid positions can be placed");
	assertTrue(!test.placeShip(Ship
	{ GridPosition("K1"), GridPosition("K5") }),
			"Ship with invalid bow and stern grid positions can be placed");


	//Test placing ships with invalid length
	assertTrue(!(test.placeShip(Ship
	{ GridPosition("A1"), GridPosition("A1") })),
			"Ship of invalid length 1 can be placed");
	assertTrue(!(test.placeShip(Ship
	{ GridPosition("F1"), GridPosition("F6") })),
			"Ship of invalid length 6 can be placed");


	//Test placing ships not as straight line
	assertTrue(!(test.placeShip(Ship
	{ GridPosition("H1"), GridPosition("J3") })),
			"Ship can be placed not as straight line");


	//Test placing ship touching the existing placed ships
	assertTrue(!(test.placeShip(Ship
	{ GridPosition("A1"), GridPosition("A3") })),
			"Ship touching existing placed ship can be placed");
	assertTrue(!(test.placeShip(Ship
	{ GridPosition("D5"), GridPosition("D8") })),
			"Ship touching existing placed ship can be placed");


	//Test placing 4 ships of length 2(max only 4 can be placed)
	assertTrue(test.placeShip(Ship
	{ GridPosition("A7"), GridPosition("A8") }),
			"1st Ship of length 2 not placed");
	assertTrue(test.placeShip(Ship
	{ GridPosition("C7"), GridPosition("D7") }),
			"2nd Ship of length 2 not placed");
	assertTrue(test.placeShip(Ship
	{ GridPosition("H8"), GridPosition("I8") }),
			"3rd Ship of length 2 not placed");
	assertTrue(test.placeShip(Ship
	{ GridPosition("D9"), GridPosition("D10") }),
			"4th Ship of length 2 not placed");
	assertTrue(!(test.placeShip(Ship
	{ GridPosition("H1"), GridPosition("H2") })),
			"5th Ship of length 2 can be placed");


	//Test placing 3 ships of length 3(max only 3 can be placed)
	assertTrue(test.placeShip(Ship
	{ GridPosition("D1"), GridPosition("F1") }),
			"2nd Ship of length 3 not placed");
	assertTrue(test.placeShip(Ship
	{ GridPosition("H10"), GridPosition("J10") }),
			"3rd Ship of length 3 not placed");
	assertTrue(!(test.placeShip(Ship
	{ GridPosition("H6"), GridPosition("J6") })),
			"4th Ship of length 3 can be placed");


	//Test placing 2 ships with length 4(max only 2 can be placed)
	assertTrue(!test.placeShip(Ship
	{ GridPosition("J1"), GridPosition("J4") }),
			"3rd Ship of length 4 can be placed");


	//Test placing 1 ship with length 5(max only 1 can be placed)
	assertTrue(test.placeShip(Ship
	{ GridPosition("J1"), GridPosition("J5") }),
			"1st Ship of length 5 not placed");
	assertTrue(!test.placeShip(Ship
	{ GridPosition("H1"), GridPosition("H5") }),
			"2nd Ship of length 5 can be placed");


}

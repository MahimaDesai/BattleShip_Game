#include "ConsoleView.h"

using namespace std;

ConsoleView::~ConsoleView()
{
}

ConsoleView::ConsoleView(Board *board) :
		board(board)
{
}

void ConsoleView::print()
{
	// Print column index
	cout << "  ";
	for (int grid = 1; grid <= 2; ++grid)
	{
		int count = 0;
		for (int col = 1; col <= board->getColumns(); ++col)
		{
			if (col >= 10)
			{
				if (col % 10 == 0)
					count = count + 1;
				cout << count << " ";
			}
			else
				cout << "  ";
		}
		cout << "    ";
	}
	cout << endl;
	cout << "  ";
	for (int grid = 1; grid <= 2; ++grid)
	{
		for (int col = 1; col <= board->getColumns(); ++col)
		{
			cout << col % 10 << " ";
		}
		cout << "    ";
	}
	cout << endl;

	// Print row index and grid values
	for (int i = 'A'; i < board->getRows() + 'A'; ++i)
	{
		for (int grid = 1; grid <= 2; ++grid)
		{
			cout << static_cast<char>(i) << " ";
			for (int j = 1; j <= board->getColumns(); ++j)
			{
				if (grid == 1)
					cout << printOwnGrid(i, j) << " ";
				// if grid is 1 then print own grid
				else if (grid == 2)
					cout << printOpponentGrid(i, j) << " ";
				// if grid is 2 then print opponent grid
			}
			cout << "  ";
		}
		cout << endl;
	}
}

char ConsoleView::printOwnGrid(char row, int col)
{
	char tilde = '~';
	char ship = '#';
	char shipHit = '0';
	char missHit = '^';

	GridPosition position(row, col);

	for (const auto &placedShip : board->getOwnGrid().getShips())
	{
		if ((board->getOwnGrid().getShotAt().count(position) > 0)
				&& (placedShip.occupiedArea().count(position) > 0))
		{
			return shipHit;
		}
		else if (placedShip.occupiedArea().count(position) > 0)
		{
			return ship;
		}
	}

	if (board->getOwnGrid().getShotAt().count(position) > 0)
	{
		return missHit;
	}
	return tilde;
}

char ConsoleView::printOpponentGrid(char row, int col)
{
	char tilde = '~';
	char sunkenShip = '#';
	char shipHit = '0';
	char missHit = '^';

	GridPosition position(row, col);

	map<GridPosition, Shot::Impact> showMap =
			board->getOpponentGrid().getShotsAt();

	if (showMap.count(position) > 0)
	{
		if (showMap[position] == Shot::Impact::SUNKEN)
		{
			return sunkenShip;
		}
		else if (showMap[position] == Shot::Impact::HIT)
		{
			return shipHit;
		}
		else if (showMap[position] == Shot::Impact::NONE)
		{
			return missHit;
		}
	}
	return tilde;
}

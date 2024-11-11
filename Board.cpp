#include "Board.h"

using namespace std;

Board::~Board()
{
}

Board::Board(int rows, int columns) :
		ownGrid(rows, columns), opponentGrid(rows, columns)
{
}

int Board::getRows() const
{
	return this->ownGrid.getRows();
}

int Board::getColumns() const
{
	return this->ownGrid.getColumns();
}

OwnGrid& Board::getOwnGrid()
{
	return this->ownGrid;
}

OpponentGrid& Board::getOpponentGrid()
{
	return this->opponentGrid;
}


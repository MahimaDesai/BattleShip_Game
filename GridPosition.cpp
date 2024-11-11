#include "GridPosition.h"

GridPosition::GridPosition(char row, int col)
{
	this->row = row;
	this->column = col;
}

GridPosition::GridPosition(std::string position)
{
	this->row = position[0];

	if (isdigit(position[1]))
	{
		this->column = stoi(position.substr(1));
	}
	else
	{
		this->column = 0;
	}
}

GridPosition::~GridPosition()
{
}

bool GridPosition::isValid() const
{
	if ((getRow() >= 'A' && getRow() <= 'Z') && getColumn() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

char GridPosition::getRow() const
{
	return this->row;
}

int GridPosition::getColumn() const
{
	return this->column;
}

GridPosition::operator std::string() const
{
	return getRow() + std::to_string(getColumn());
}

bool GridPosition::operator ==(const GridPosition &other) const
{
	if (isValid())
	{
		return (getRow() == other.getRow() && getColumn() == other.getColumn());
	}
	else
	{
		return false;
	}
}

bool GridPosition::operator <(const GridPosition &other) const
{
	if (isValid())
	{
		return ((getRow() < other.getRow())
				|| (getRow() == other.getRow()
						&& getColumn() < other.getColumn()));
	}
	else
	{
		return false;
	}
}

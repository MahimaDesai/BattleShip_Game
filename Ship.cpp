#include "Ship.h"

using namespace std;

Ship::Ship(const GridPosition &bow, const GridPosition &stern) :
		bow(bow), stern(stern)
{
}

Ship::~Ship()
{
}

bool Ship::isValid() const
{
	if (getBow().isValid() && getStern().isValid())
	{
		if (length() >= 2 && length() <= 5)
		{
			if ((getStern().getRow() == getBow().getRow())
					|| (getStern().getColumn() == getBow().getColumn()))
				return true;
			else
				return false;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

GridPosition Ship::getBow() const
{
	return this->bow;
}

GridPosition Ship::getStern() const
{
	return this->stern;
}

int Ship::length() const
{
	if (getBow().isValid() && getStern().isValid())
	{
		return abs(
				abs(getStern().getRow() - getBow().getRow())
						+ abs(getStern().getColumn() - getBow().getColumn())
						+ 1);
	}
	else
	{
		return 0;
	}
}

const std::set<GridPosition> Ship::occupiedArea() const
{
	std::set<GridPosition> occupied;

	if (isValid())
	{
		if (getStern().getRow() == getBow().getRow())
		{
			for(int i = getBow().getColumn();i <= getStern().getColumn();++i)
			{
				occupied.insert(GridPosition(getBow().getRow(), i));
			}
		}
		else if (getStern().getColumn() == getBow().getColumn())
		{
			for(char i = getBow().getRow(); i <= getStern().getRow(); ++i)
			{
				occupied.insert(GridPosition(i, getBow().getColumn()));
			}
		}
	}
	return occupied;
}

const std::set<GridPosition> Ship::blockedArea() const
{
	set<GridPosition> occupied = occupiedArea();
	set<GridPosition> blocked;

	int area_rows[8] =
	{ -1, -1, 0, +1, +1, +1, 0, -1 };
	int area_cols[8] =
	{ 0, -1, -1, -1, 0, +1, +1, +1 };

	if (isValid())
	{
		for (auto itr = occupied.begin(); itr != occupied.end(); itr++)
		{
			for (int j = 0; j < 8; ++j)
			{
				GridPosition position((GridPosition(
						(itr->getRow() + area_rows[j]),
						(itr->getColumn() + area_cols[j]))));
				if (position.isValid())
				{
					blocked.insert(GridPosition(position));
				}
			}
		}
	}
	return blocked;
}

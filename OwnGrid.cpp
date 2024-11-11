#include "OwnGrid.h"

using namespace std;

OwnGrid::~OwnGrid()
{
}

OwnGrid::OwnGrid(int rows, int columns) :
		rows(rows), columns(columns)
{
	ownShips =
	{
	{ 5, 1 },
	{ 4, 2 },
	{ 3, 3 },
	{ 2, 4 } };
}

int OwnGrid::getRows() const
{
	return this->rows;
}

int OwnGrid::getColumns() const
{
	return this->columns;
}

bool OwnGrid::placeShip(const Ship &ship)
{
	char maxRow = static_cast<char>('A' + getRows() - 1);

	if (ship.isValid())
	{
		//! Edge placement
		if ((ship.getBow().getRow() >= 'A')
				&& (ship.getBow().getRow() <= maxRow)
				&& (ship.getStern().getRow() >= 'A')
				&& (ship.getStern().getRow() <= maxRow)
				&& (ship.getBow().getColumn() >= 1)
				&& (ship.getBow().getColumn() <= getColumns())
				&& (ship.getStern().getColumn() >= 1)
				&& (ship.getStern().getColumn() <= getColumns()))
		{

			//! Intersection
			std::set<GridPosition> placedBlocked;
			std::set<GridPosition> currentOccupied;

			currentOccupied = ship.occupiedArea();

			for (const auto &placedShip : getShips())
			{

				placedBlocked = placedShip.blockedArea();

				//! set to store intersection
				std::set<GridPosition> intersection;

				//! find the intersection
				std::set_intersection(currentOccupied.begin(),
						currentOccupied.end(), placedBlocked.begin(),
						placedBlocked.end(),
						std::inserter(intersection, intersection.begin()));

				if (!intersection.empty())
				{
					return false;
				}
			}
			if (ownShips[ship.length()] > 0)
			{
				//! Place the ship, update ship count, and return true
				ships.push_back(ship);
				ownShips[ship.length()]--;
				return true;
			}
		}
	}
	return false;
}

const std::vector<Ship> OwnGrid::getShips() const
{
	return this->ships;
}

const std::set<GridPosition> OwnGrid::getShotAt() const
{
	return this->ShotAt;
}

Shot::Impact OwnGrid::takeBlow(const Shot &shot)
{
	char maxRow = static_cast<char>('A' + getRows() - 1);
	GridPosition shotPosition(shot.getTargetPosition());

	if ((shotPosition.getRow() >= 'A') && (shotPosition.getRow() <= maxRow)
			&& (shotPosition.getColumn() >= 1)
			&& (shotPosition.getColumn() <= getColumns()))
	{
		ShotAt.insert(GridPosition(shotPosition));

		for (const Ship &ship : getShips())
		{
			//! set to store intersection
			set<GridPosition> intersection_hit;

			const set<GridPosition> shipPosition = ship.occupiedArea();

			if ((shipPosition.count(shotPosition) > 0))
			{
				set_intersection(shipPosition.begin(), shipPosition.end(),
						ShotAt.begin(), ShotAt.end(),
						inserter(intersection_hit, intersection_hit.begin()));

				if (intersection_hit.size() == ship.occupiedArea().size())
				{
					return Shot::Impact::SUNKEN;
				}
				else
				{
					return Shot::Impact::HIT;
				}
			}
		}
	}
	return Shot::Impact::NONE;
}

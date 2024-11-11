#include "OpponentGrid.h"

using namespace std;

OpponentGrid::~OpponentGrid()
{
}

OpponentGrid::OpponentGrid(int rows, int columns) :
		rows(rows), columns(columns)
{
	opponentShips =
	{
	{ 2, 4 },
	{ 3, 3 },
	{ 4, 2 },
	{ 5, 1 } };
}

int OpponentGrid::getRows() const
{
	return this->rows;
}

int OpponentGrid::getColumns() const
{
	return this->columns;
}

const std::map<GridPosition, Shot::Impact>& OpponentGrid::getShotsAt() const
{
	return this->shots;
}

void OpponentGrid::shotResult(const Shot &shot, Shot::Impact impact)
{
	GridPosition shotPosition(shot.getTargetPosition());
	set<GridPosition> shipPositions;

	if ((shotPosition.getRow() >= 'A')
			&& (shotPosition.getRow() <= ('A' + getRows() - 1))
			&& (shotPosition.getColumn() >= 1)
			&& (shotPosition.getColumn() <= getColumns()))
	{
		shots[shotPosition] = impact;

		if (impact == Shot::Impact::SUNKEN)
		{
			shipPositions = checkShips(shotPosition);
		}
	}

	if (!shipPositions.empty())
	{
		GridPosition bow = *shipPositions.begin();
		GridPosition stern = *std::prev(shipPositions.end());

		Ship sunkenShip(bow, stern);

		if (opponentShips[sunkenShip.length()] > 0)
		{
			sunkenShips.push_back(sunkenShip);
			opponentShips[sunkenShip.length()]--;

			for (const auto &pos : shipPositions)
			{
				this->shots[pos] = Shot::Impact::SUNKEN;
			}
		}
	}
}

const std::set<GridPosition> OpponentGrid::checkShips(
		const GridPosition &shotPosition)
{
	char row = shotPosition.getRow();
	int column = shotPosition.getColumn();

	set<GridPosition> shipPositions;

	int grid_dir_row[5] =
	{ 0, 0, +1, 0, -1 };
	int grid_dir_col[5] =
	{ 0, -1, 0, +1, 0 };

	for (int dir = 0; dir < 5; dir++)
	{
		for (int i = 1; i <= 5; i++)
		{
			char row_temp = row + ((i) * grid_dir_row[dir]);
			int col_temp = column + ((i) * grid_dir_col[dir]);

			GridPosition posRef(GridPosition
			{ row_temp, col_temp });

			if ((posRef.getRow() >= 'A')
					&& (posRef.getRow() <= ('A' + getRows() - 1))
					&& (posRef.getColumn() >= 1)
					&& (posRef.getColumn() <= getColumns()))
			{
				auto itr = shots.find(posRef);

				if (itr != shots.end()
						&& (itr->second == Shot::Impact::HIT
								|| itr->second == Shot::Impact::SUNKEN))
				{
					shipPositions.insert(posRef);
					continue;

				}
				else
				{
					break;
				}
			}
		}
	}

	return shipPositions;
}

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

#include "Ship.h"
#include "Shot.h"
#include <vector>
#include <map>

/**
 * @class OpponentGrid
 * @brief Class OpponentGrid
 **/
class OpponentGrid
{
private:
	int rows; /**Opponent grid row value**/
	int columns; /**Opponent grid column value**/
	std::map<GridPosition, Shot::Impact> shots;
		/**Map to store the shots and their impact value**/
	std::map<int, int> opponentShips;
		/**Map to store count for opponent ships**/
	std::vector<Ship> sunkenShips; /**Vector to store sunken ships**/

public:
	/**
	 *  @brief : Default destructor
	 *
	 *  @return :   virtual
	 *
	 *
	 **/
	virtual ~OpponentGrid();

	/**
	 *  @brief : Parameterized constructor
	 *
	 *  @return :   None
	 *
	 *  @param[in] rows	: Opponent grid row value
	 *  @param[in] columns	: Opponent grid column value
	 *
	 **/
	OpponentGrid(int rows, int columns);

	/**
	 *  @brief : To get opponent grid row value
	 *
	 *  @return :   int Opponent grid Row value
	 *
	 *
	 **/
	int getRows() const;

	/**
	 *  @brief :	To get opponent grid column value
	 *
	 *  @return :   int Opponent grid Column value
	 *
	 *
	 **/
	int getColumns() const;

	/**
	 *  @brief :	To get the shots taken by opponent grid and their impact
	 *
	 *  @return :	map<GridPosition,Shot::Impact> Grid position and impact
	 *
	 *
	 **/
	const std::map<GridPosition, Shot::Impact>& getShotsAt() const;

	/**
	 *  @brief :	Method to calculate shot result to check sunken ship
	 *
	 *  @return :   void
	 *
	 *  @param[in] shot	: Shot position grid value
	 *  @param[in] impact	: Impact of the taken shot
	 *
	 **/
	void shotResult(const Shot &shot, Shot::Impact impact);

	/**
	 *  @brief :	Method to calculate sunken ship grid positions
	 *
	 *  @return :   set<GridPosition> Sunken ship grid positions
	 *
	 *  @param[in] shotPosition	: Shot position grid value
	 *
	 **/
	const std::set<GridPosition> checkShips(const GridPosition &shotPosition);
};

#endif /* OPPONENTGRID_H_ */

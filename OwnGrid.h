#ifndef OWNGRID_H_
#define OWNGRID_H_

#include "Ship.h"
#include "Shot.h"
#include <vector>
#include <map>
#include <algorithm>

/**
 * @class OwnGrid
 * @brief Class OwnGrid
 **/
class OwnGrid
{
private:
	int rows; /**Own grid row value**/
	int columns; /**Own grid column value**/
	std::vector<Ship> ships; /**Vector to store placed ships**/
	std::map<int, int> ownShips; /**Map to store count for own ships**/
	std::set<GridPosition> ShotAt; /**Set to store positions that take blow**/

public:
	/**
	 *  @brief : Default destructor
	 *
	 *  @return :   virtual
	 *
	 *
	 **/
	virtual ~OwnGrid();

	/**
	 *  @brief :	Parameterized constructor
	 *
	 *  @return :   None
	 *
	 *  @param[in] rows	: Own grid row value
	 *  @param[in] columns	: Own grid column value
	 *
	 **/
	OwnGrid(int rows, int columns);

	/**
	 *  @brief :	To get the own grid row value
	 *
	 *  @return :   int Own grid Row value
	 *
	 *
	 **/
	int getRows() const;

	/**
	 *  @brief :	To get the own grid column value
	 *
	 *  @return :   int Own grid Column value
	 *
	 *
	 **/
	int getColumns() const;

	/**
	 *  @brief :	Method to place ship on the own grid
	 *
	 *  @return :   bool True if it is possible to place the ship
	 *
	 *  @param[in] ship	: Ship value with bow and stern grid position
	 *
	 **/
	bool placeShip(const Ship &ship);

	/**
	 *  @brief :	To get the placed ships
	 *
	 *  @return :   const std::vector<Ship> Placed ships
	 *
	 *
	 **/
	const std::vector<Ship> getShips() const;

	/**
	 *  @brief :	To get the grid positions that take blow
	 *
	 *  @return :   const std::set<GridPosition> Shot positions
	 *
	 *
	 **/
	const std::set<GridPosition> getShotAt() const;

	/**
	 *  @brief :	Method to consider the shot take on own grid
	 *
	 *  @return :   Shot::Impact Impact of the taken shot
	 *
	 *  @param[in] shot	: Grid position value that is shot
	 *
	 **/
	Shot::Impact takeBlow(const Shot &shot);
};

#endif /* OWNGRID_H_ */

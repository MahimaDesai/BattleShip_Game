#ifndef SHIP_H_
#define SHIP_H_

#include "GridPosition.h"
#include <set>

/**
 * @class Ship
 * @brief Class Ship
 **/
class Ship
{
private:
	GridPosition bow; /**Ship bow value on the grid**/
	GridPosition stern; /**Ship stern value on the grid**/

public:
	/**
	 *  @brief :	Parameterized constructor with bow and stern values
	 *
	 *  @return :   None
	 *
	 *  @param[in] bow	: Ship bow value
	 *  @param[in] stern	: Ship stern value
	 *
	 **/
	Ship(const GridPosition &bow, const GridPosition &stern);

	/**
	 *  @brief :	Default destructor
	 *
	 *  @return :   virtual
	 *
	 *
	 **/
	virtual ~Ship();

	/**
	 *  @brief :	Checks validity of the bow and stern grid values
	 *
	 *  @return :   bool True if the bow and stern values are valid
	 *
	 *
	 **/
	bool isValid() const;

	/**
	 *  @brief :	To get the ship's bow as grid value
	 *
	 *  @return :   GridPosition Bow value
	 *
	 *
	 **/
	GridPosition getBow() const;

	/**
	 *  @brief :	To get the ship's stern as grid value
	 *
	 *  @return :   GridPosition Stern value
	 *
	 *
	 **/
	GridPosition getStern() const;

	/**
	 *  @brief :	To calculate the length of ship
	 *
	 *  @return :   int Length of ship
	 *
	 *
	 **/
	int length() const;

	/**
	 *  @brief :	To calculate occupied area of the ship
	 *
	 *  @return :   const std::set<GridPosition>
	 *
	 *
	 **/
	const std::set<GridPosition> occupiedArea() const;

	/**
	 *  @brief :	To calculate blocked area of the ship
	 *
	 *  @return :   const std::set<GridPosition>
	 *
	 *
	 **/
	const std::set<GridPosition> blockedArea() const;
};

#endif /* SHIP_H_ */

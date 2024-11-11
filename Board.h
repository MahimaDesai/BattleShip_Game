#ifndef BOARD_H_
#define BOARD_H_

#include "OwnGrid.h"
#include "OpponentGrid.h"

/**
 * @class Board
 * @brief Class Board
 **/
class Board
{
private:
	OwnGrid ownGrid; /**Own grid**/
	OpponentGrid opponentGrid; /**Opponent grid**/

public:
	/**
	 *  @brief :	Default destructor
	 *
	 *  @return :   virtual
	 *
	 *
	 **/
	virtual ~Board();

	/**
	 *  @brief :	Parameterized constructor
	 *
	 *  @return :   None
	 *
	 *  @param[in] rows	: Board row value
	 *  @param[in] columns	: Board column value
	 *
	 **/
	Board(int rows, int columns);

	/**
	 *  @brief :	To get row value of the board
	 *
	 *  @return :   int Row value of the board
	 *
	 *
	 **/
	int getRows() const;

	/**
	 *  @brief :	To get column value of the board
	 *
	 *  @return :   int Column value of the board
	 *
	 *
	 **/
	int getColumns() const;

	/**
	 *  @brief : 	To get own grid
	 *
	 *  @return :   OwnGrid& Own grid state
	 *
	 *
	 **/
	OwnGrid& getOwnGrid();

	/**
	 *  @brief :	To get opponent grid
	 *
	 *  @return :   OpponentGrid& Opponent grid state
	 *
	 *
	 **/
	OpponentGrid& getOpponentGrid();
};

#endif /* BOARD_H_ */

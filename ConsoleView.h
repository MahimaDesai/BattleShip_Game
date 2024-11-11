#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_

#include "Board.h"

/**
 * @class ConsoleView
 * @brief Class ConsoleView
 **/
class ConsoleView
{
private:
	Board *board; /**Board to display**/

public:
	/**
	 *  @brief : Default destructor
	 *
	 *  @return :   virtual
	 *
	 *
	 **/
	virtual ~ConsoleView();

	/**
	 *  @brief :	Parameterized constructor
	 *
	 *  @return :   None
	 *
	 *  @param[in] board	: board state
	 *
	 **/
	ConsoleView(Board *board);

	/**
	 *  @brief :	To print the board
	 *
	 *  @return :   void
	 *
	 *
	 **/
	void print();

	/**
	 *  @brief : To print the own grid
	 *
	 *  @return :   char Character to be shown on board
	 *
	 *  @param[in] row	: Grid position row value
	 *  @param[in] col	: Grid position column value
	 *
	 **/
	char printOwnGrid(char row, int col);

	/**
	 *  @brief :	To print opponent grid
	 *
	 *  @return :   char Character to be shown on board
	 *
	 *  @param[in] row	: Grid position row value
	 *  @param[in] col	: Grid position column value
	 *
	 **/
	char printOpponentGrid(char row, int col);
};

#endif /* CONSOLEVIEW_H_ */

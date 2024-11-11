#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

#include <iostream>
#include <string>

/**
 * @class GridPosition
 * @brief Class GridPosition
 **/
class GridPosition
{

private:
	char row; /**Row value on the grid**/
	int column; /**Column value on the grid**/

public:
	/**
	 *  @brief : Parameterized constructor with row and column value
	 *
	 *  @return :  None
	 *
	 *  @param[in] row	: Grid position row value
	 *  @param[in] col	: Grid position column value
	 *
	 **/
	GridPosition(char row, int col);

	/**
	 *  @brief : Parameterized constructor with string value
	 *
	 *  @return :   None
	 *
	 *  @param[in] position	: Grid position as string
	 *
	 **/
	GridPosition(std::string position);

	/**
	 *  @brief :	Default Destructor
	 *
	 *  @return :   virtual
	 *
	 *
	 **/
	virtual ~GridPosition();

	/**
	 *  @brief :	Checks the validity of the given grid position
	 *
	 *  @return :   bool True if the grid value is valid
	 *
	 *
	 **/
	bool isValid() const;

	/**
	 *  @brief :	To get the row value
	 *
	 *  @return :   char Grid position row value
	 *
	 *
	 **/
	char getRow() const;

	/**
	 *  @brief :	To get the column value
	 *
	 *  @return :   int Grid position column value
	 *
	 *
	 **/
	int getColumn() const;

	/**
	 *  @brief :	Operator overloading for string concatenation
	 *
	 *  @return :   Grid position as a string
	 *
	 *
	 **/
	operator std::string() const;

	/**
	 *  @brief :	Operator overloading for equal comparison
	 *
	 *  @return :   bool True if the both values are equal
	 *
	 *  @param[in] other	: Grid position value
	 *
	 **/
	bool operator==(const GridPosition &other) const;

	/**
	 *  @brief :	Operator overloading for less than comparison
	 *
	 *  @return :   bool True if the value is less than another value
	 *
	 *  @param[in] other 	    : Grid position value
	 *
	 **/
	bool operator<(const GridPosition &other) const;

};

#endif /* GRIDPOSITION_H_ */

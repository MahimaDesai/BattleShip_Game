#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"

/**
 * @class Shot
 * @brief Class Shot
 **/
class Shot
{
private:
	GridPosition targetPosition; /**Shot position**/

public:
	enum Impact
	{
		NONE, HIT, SUNKEN
	}; /**Impact on the grid**/

	/**
	 *  @brief :	Parameterized constructor
	 *
	 *  @return :   None
	 *
	 *  @param[in] targetPosition: target position value
	 *
	 **/
	Shot(GridPosition targetPosition);

	/**
	 *  @brief : Default destructor
	 *
	 *  @return :   virtual
	 *
	 *
	 **/
	virtual ~Shot();

	/**
	 *  @brief :	To get the target position grid value
	 *
	 *  @return :   GridPosition Target position
	 *
	 *
	 **/
	GridPosition getTargetPosition() const;
};

#endif /* SHOT_H_ */

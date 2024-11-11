#include "Shot.h"

Shot::Shot(GridPosition targetPosition) :
		targetPosition(targetPosition)
{
}

Shot::~Shot()
{
}

GridPosition Shot::getTargetPosition() const
{
	return this->targetPosition;
}

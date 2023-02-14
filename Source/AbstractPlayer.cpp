#include "AbstractPlayer.h"

void AbstractPlayer::increasePoints(const int points)
{
	this->points += points;
}

int AbstractPlayer::getPoints() const
{
	return points;
}

#include "AbstractPlayer.h"

void AbstractPlayer::increasePoints(const int points)
{
	this->points += points;
}

int AbstractPlayer::getPoints() const
{
	return points;
}

bool AbstractPlayer::isStand() const
{
	return bStand;
}

void AbstractPlayer::setStand(const bool bStand)
{
	this->bStand = bStand;
}

void AbstractPlayer::resetPoints()
{
	points = 0;
}

void AbstractPlayer::resetStand()
{
	bStand = false;
}

void AbstractPlayer::resetBet()
{
	bet = 0;
}

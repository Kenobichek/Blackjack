#include "Dealer.h"

bool Dealer::playAgain() const
{
	return true;
}

bool Dealer::hit() const
{
	return getPoints() < 17;
}

bool Dealer::shouldStand() const
{
	return getPoints() >= 17;
}

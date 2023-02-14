#include "Dealer.h"

bool Dealer::playAgain() const
{
	return true;
}

bool Dealer::hit() const
{
	return points < 17;
}

bool Dealer::stand() const
{
	return points >= 17;
}

#include "Player.h"

bool Player::playAgain() const
{
	return cash > 0 && bet > 0 ? true : false;
}

bool Player::hit() const
{
	return true;
}

bool Player::shouldStand() const
{
	return true;
}

void Player::increaseBet(const int bet)
{
	this->bet += bet;
}

int Player::getBet() const
{
	return this->bet;
}

int Player::getCash() const
{
	return this->cash;
}

void Player::getMoneyFromBet()
{
	cash += this->bet * 2;
}

void Player::placeBet()
{
	cash -= this->bet;
}

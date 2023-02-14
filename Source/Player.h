#pragma once
#include "AbstractPlayer.h"

class Player : public AbstractPlayer
{
public:
	bool playAgain() const override;
	bool hit() const override;
	bool stand() const override;
	void increaseBet(const int bet);
	int getBet() const;
	int getCash() const;
	void resetBet();

private:
	int cash = 500;
	int bet = 0;
};
#pragma once
#include "AbstractPlayer.h"

class Player : public AbstractPlayer
{
public:
	bool playAgain() const override;
	bool hit() const override;
	bool stand() const override;

	int getBet() const;
	int getCash() const;
	void getMoneyFromBet();
	void placeBet();

	void increaseBet(const int bet);

private:
	int cash = 500;
};
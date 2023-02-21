#pragma once
#include "AbstractPlayer.h"

class Dealer : public AbstractPlayer
{
public:
	~Dealer() {}

	bool playAgain() const override;
	bool hit() const override;
	bool shouldStand() const override;
};
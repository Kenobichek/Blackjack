#pragma once
#include "AbstractPlayer.h"

class Dealer : public AbstractPlayer
{
public:
	bool playAgain() const override;
	bool hit() const override;
	bool stand() const override;

private:

};
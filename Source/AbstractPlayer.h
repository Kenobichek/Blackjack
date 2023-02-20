#pragma once

class AbstractPlayer
{
public:
	//virtual ~AbstractPlayer() = 0;
	void increasePoints(const int points);
	int getPoints() const;
	bool isStand() const;
	void setStand(const bool bStand);
	void resetPoints();
	void resetStand();
	void resetBet();

	virtual bool playAgain() const = 0;
	virtual bool hit() const = 0;
	virtual bool stand() const = 0;

protected:
	int points = 0;
	int bet = 0;
	bool bStand = false;
};
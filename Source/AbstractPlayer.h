#pragma once
#include <vector>

class AbstractPlayer
{
public:
	virtual ~AbstractPlayer() {}

	void increasePoints(const int point);
	int getPoints() const;
	bool isStand() const;
	void setStand(const bool bStand);
	void resetPoints();
	void resetStand();
	void resetBet();

	virtual bool playAgain() const = 0;
	virtual bool hit() const = 0;
	virtual bool shouldStand() const = 0;

protected:
	std::vector<int> points;
	int bet = 0;
	bool bStand = false;

private:
	void addAceInToPoints();
	void addPointInToPoints(const int point);
};
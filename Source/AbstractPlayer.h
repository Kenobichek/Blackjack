#pragma once

class AbstractPlayer
{
public:
	//virtual ~AbstractPlayer() = 0;
	void increasePoints(const int points);
	int getPoints() const;

protected:
	virtual bool playAgain() const = 0;
	virtual bool hit() const = 0;
	virtual bool stand() const = 0;
	int points = 0;
	//bool hit = false;
};
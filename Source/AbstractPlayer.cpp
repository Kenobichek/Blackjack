#include "AbstractPlayer.h"

void AbstractPlayer::increasePoints(const int point)
{
	if (point == 1)
	{
		addAceInToPoints();
	}
	else
	{
		addPointInToPoints(point);
	}
}

int AbstractPlayer::getPoints() const
{
	if (points.size() == 0) return 0;

	int maxPoints = points[0];
	for (int i = 0; i < points.size(); i++)
	{
		if (points[i] <= 21 && points[i] > maxPoints)
		{
			maxPoints = points[i];
		}
	}
	return maxPoints;
}

bool AbstractPlayer::isStand() const
{
	return bStand;
}

void AbstractPlayer::setStand(const bool bStand)
{
	this->bStand = bStand;
}

void AbstractPlayer::resetPoints()
{
	points.clear();
}

void AbstractPlayer::resetStand()
{
	bStand = false;
}

void AbstractPlayer::resetBet()
{
	bet = 0;
}

void AbstractPlayer::addAceInToPoints()
{
	int aceValueOption1 = 1;
	int aceValueOption2 = 11;

	if (points.size() == 0)
	{
		points.push_back(aceValueOption1);
		points.push_back(aceValueOption2);
	}
	else {
		int pointSize = points.size();
		for (int i = 0; i < pointSize; i++)
		{
			points.push_back(points[i] + aceValueOption2);
			points[i] += aceValueOption1;
		}
	}
}

void AbstractPlayer::addPointInToPoints(const int point)
{
	if (points.size() == 0)
	{
		points.push_back(point);
	}
	else
	{
		for (int i = 0; i < points.size(); i++)
		{
			points[i] += point;
		}
	}
}

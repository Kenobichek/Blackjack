#pragma once
#include <memory>

#include "Card.h"

class Deck
{
public:
	explicit Deck();
	void shuffler();
	std::shared_ptr<Card> getCard();
	bool isEmpty();

protected:
	void mousePressEvent(QMouseEvent* event);

private:

	std::vector<std::shared_ptr<Card>> deck;
};
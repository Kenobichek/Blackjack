#pragma once
#include <memory>

#include "Card.h"

class Deck
{
public:
	explicit Deck();
	void shuffle();
	void reshuffle();
	bool isEmpty() const;
	std::shared_ptr<Card> getCard();

private:
	std::shared_ptr<Card> createNewCard(const int, const Suit&);
	std::vector<std::shared_ptr<Card>> deck;
};
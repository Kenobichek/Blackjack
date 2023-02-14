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

private:
	std::shared_ptr<Card> createNewCard(const int, const Suit&);
	std::vector<std::shared_ptr<Card>> deck;
};
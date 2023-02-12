#include "Deck.h"

Deck::Deck()
{
	std::vector<Suit> suits = { Spades,	Hearts, Diamonds, Clubs };

	for (int i = 2; i <= 10; i++)
	{
		for (int j = 0; j < suits.size(); j++)
		{
			deck.push_back(std::make_shared<Card>(i, suits[j]));
		}
	}

	std::vector<PictureСard> pictureСards = { Ace, J, Q, K };

	for (int i = 0; i < pictureСards.size(); i++)
	{
		for (int j = 0; j < suits.size(); j++)
		{
			deck.push_back(std::make_shared<Card>(pictureСards[j], suits[j]));
		}
	}
}

void Deck::shuffler()
{
	srand(time(NULL));
	for (int i = 0; i < deck.size(); i++)
	{
		std::swap(deck[i], deck[rand() % deck.size()]);
	}
}

std::shared_ptr<Card> Deck::getCard()
{
	auto card = deck.front();
	deck.erase(deck.begin());
	return card;
}

bool Deck::isEmpty()
{
	return deck.empty();
}

void Deck::mousePressEvent(QMouseEvent* event)
{
	//emit clicked();
}

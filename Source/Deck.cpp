#include "Deck.h"

Deck::Deck()
{
	std::vector<Suit> suits = { Spades,	Hearts, Diamonds, Clubs };

	for (int i = 1; i <= 13; i++)
	{
		for (int j = 0; j < suits.size(); j++)
		{
			deck.push_back(createNewCard(i, suits[j]));
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

std::shared_ptr<Card> Deck::createNewCard(const int value,const Suit& suit)
{
	std::shared_ptr<Card> newCard = std::make_shared<Card>(value, suit);
	return newCard;
}

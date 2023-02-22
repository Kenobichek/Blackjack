#include "Deck.h"
#include <algorithm>
#include <random>

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

void Deck::shuffle()
{
	static auto rd = std::random_device{};
	static auto rng = std::default_random_engine{ rd() };

	std::shuffle(std::begin(deck), std::end(deck), rng);
}

void Deck::reshuffle()
{
	std::vector<Suit> suits = { Spades,	Hearts, Diamonds, Clubs };

	for (int i = 1; i <= 13; i++)
	{
		for (int j = 0; j < suits.size(); j++)
		{
			deck.push_back(createNewCard(i, suits[j]));
		}
	}

	shuffle();
}

std::shared_ptr<Card> Deck::getCard()
{
	auto card = deck.front();
	deck.erase(deck.begin());
	return card;
}

bool Deck::isEmpty() const
{
	return deck.empty();
}

std::shared_ptr<Card> Deck::createNewCard(const int value,const Suit& suit)
{
	std::shared_ptr<Card> newCard = std::make_shared<Card>(value, suit);
	return newCard;
}

#pragma once
#include <QLabel>

enum Suit
{
	Spades, 
	Hearts, 
	Diamonds,
	Clubs,
};

enum PictureСard
{
	Ace = 1,
	J = 10,
	Q = 10,
	K = 10,
};

class Card
{
public:
	explicit Card(int, Suit);

protected:

private:
	int value;
	Suit suit;
};
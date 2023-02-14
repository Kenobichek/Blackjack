#pragma once
#include <QLabel>
#include <QPixmap>

enum Suit
{
	Clubs,
	Diamonds,
	Hearts, 
	Spades, 
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
	int getValue() const;
	std::shared_ptr<QRectF> getBoundingRect() const;
	void setBoundingRect(const Suit& suit, const int pictureСard);

	static void setOption(const std::string& option);
	static void setQPixmap();

private:
	int value;
	Suit suit;
	std::shared_ptr<QRectF> boundingRect;
	static std::shared_ptr<QPixmap> spriteImage;
	static std::string option;
	static QString path;
};

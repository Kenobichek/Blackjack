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
	bool getIsHide() const;
	void setPlayer(const bool bPlayer);
	void setHide();
	void setShow();

	QString getPath() const;
	QString getPathBackSide() const;

	bool getIsPlayer() const;

	static int getWidth();
	static int getHeight();
	static QPoint getEndPointPlayer();
	static QPoint getEndPointDealer();
	static void changeEndPointPlayer();
	static void changeEndPointDealer();
	static void setBackSideCategory(const QString&);
	static void setFrontSideCategory(const QString&);
	static bool isMoreThanOneCardFromDealer();
	static void setMoreThanOneCardFromDealer(const bool);
	static void resetEndPoints();

private:
	int value;
	Suit suit;
	QString path;
	QString file;

	bool bPlayer = false;
	bool bHide = false;
	
	static int width;
	static int height;
	static int shift;
	static QPoint endPointPlayer;
	static QPoint endPointDealer;
	static QString backSideCategory;
	static QString frontSideCategory;
	static bool moreThanOneCardFromDealer;
};

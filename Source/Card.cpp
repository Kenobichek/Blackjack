#include "Card.h"

QString Card::backSideCategory = "Blue";
QString Card::frontSideCategory = "Classical";

int Card::width = 100;
int Card::height = 130;
int Card::shift = 30;

QPoint Card::endPointPlayer = QPoint(shift, 100);
QPoint Card::endPointDealer = QPoint(800 - Card::width - shift, 100);

bool Card::moreThanOneCardFromDealer = false;

Card::Card(int value, Suit suit)
{
	std::vector<PictureСard> pictureСards = { J, Q, K, Ace };
	std::vector<std::string> suits = {	"Clubs", "Diamonds", "Hearts", "Spades"};

	this->value = (value <= 10 ? value : pictureСards[value - 11]);
	this->suit = suit;

	file = QString::fromUtf8(std::to_string(value) + suits[(int)suit]);
	path = QString("Content/Images/Card/FrontSide/%1/%2.png").arg(frontSideCategory).arg(file);
}

int Card::getValue() const
{
	return value;
}

bool Card::getIsHide() const
{
	return bHide;
}

void Card::setPlayer(const bool bPlayer)
{
	this->bPlayer = bPlayer;
}

void Card::setHide()
{
	this->bHide = true;
}

void Card::setShow()
{
	this->bHide = false;
}

QString Card::getPath() const
{
	return 	QString("Content/Images/Card/FrontSide/%1/%2.png").arg(frontSideCategory).arg(file);
}

QString Card::getPathBackSide() const
{
	return QString("Content/Images/Card/BackSide/%1/backside.jpg").arg(backSideCategory);
}

bool Card::getIsPlayer() const
{
	return bPlayer;
}

int Card::getWidth()
{
	return width;
}

int Card::getHeight()
{
	return height;
}

QPoint Card::getEndPointPlayer()
{
	return endPointPlayer;
}

QPoint Card::getEndPointDealer()
{
	return endPointDealer;
}

void Card::changeEndPointPlayer()
{
	endPointPlayer.setX(endPointPlayer.x() + shift);
}

void Card::changeEndPointDealer()
{
	endPointDealer.setX(endPointDealer.x() - shift);
}

void Card::setBackSideCategory(const QString& newBackSideCategory)
{
	backSideCategory = newBackSideCategory;
}

void Card::setFrontSideCategory(const QString& newFrontSideCategory)
{
	frontSideCategory = newFrontSideCategory;
}

bool Card::isMoreThanOneCardFromDealer()
{
	return moreThanOneCardFromDealer;
}

void Card::setMoreThanOneCardFromDealer(const bool bMoreThanOneCardFromDealer)
{
	moreThanOneCardFromDealer = bMoreThanOneCardFromDealer;
}

void Card::resetEndPoints()
{
	endPointPlayer = QPoint(shift, 100);
	endPointDealer = QPoint(800 - Card::width - shift, 100);
}

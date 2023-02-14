#include "Card.h"

std::string Card::option = "Option1";
QString Card::path = QString::fromUtf8(std::format("border-image:url(Content/Images/Card/FrontSide/{}/frontside.jpg);", option).c_str());
std::shared_ptr<QPixmap> Card::spriteImage;

Card::Card(int value, Suit suit)
{
	std::vector<PictureСard> pictureСards = { J, Q, K, Ace };

	this->value = (value <= 10 ? value : pictureСards[value - 11]);
	this->suit = suit;
}

int Card::getValue() const
{
	return value;
}

std::shared_ptr<QRectF> Card::getBoundingRect() const
{
	return boundingRect;
}

void Card::setBoundingRect(const Suit& suit, const int pictureСard)
{
	int cardWidth = spriteImage->width() / 13;
	int cardHeight = spriteImage->height() / 4;

	boundingRect = std::make_shared<QRectF>();
	boundingRect->setRect(pictureСard * cardWidth, suit * cardHeight, cardWidth, cardHeight);
}

void Card::setOption(const std::string& newOption)
{
	option = newOption;
}

void Card::setQPixmap()
{
	spriteImage = std::make_shared<QPixmap>(path);
}


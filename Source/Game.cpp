#include "Game.h"
#include <format>

Game::Game(QWidget* parent)	: QMainWindow(parent)
{
	gameWindow.setupUi(this);

	deck = std::make_shared<Deck>();
    card->setGeometry(0, 0, 75, 100);
    std::string path = std::format("border-image:url(Content/Images/Card/BackSide/{}/backside.jpg);", "Option2");
    card->setStyleSheet(path.c_str());
    animation = new QPropertyAnimation(card, "geometry");
    animation->setDuration(10000);
    animation->setStartValue(card->geometry());
    animation->setEndValue(QRect(200, 200, 75, 100));
    animation->start();

}
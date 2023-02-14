#include "PlayerInterface.h"
#include <format>

PlayerInterface::PlayerInterface(QWidget* parent) : QMainWindow(parent)
{
	gameWindow.setupUi(this);

    this->show();
    /*card->setGeometry(0, 0, 75, 100);
    std::string path = std::format("border-image:url(Content/Images/Card/BackSide/{}/backside.jpg);", "Option2");
    card->setStyleSheet(path.c_str());
    animation = new QPropertyAnimation(card, "geometry");
    animation->setDuration(10000);
    animation->setStartValue(card->geometry());
    animation->setEndValue(QRect(200, 200, 75, 100));
    animation->start();*/

    showButton(gameWindow.buttonPlayAgain, false);
    showButton(gameWindow.buttonHit, false);
    showButton(gameWindow.buttonStand, false);
    showButton(gameWindow.buttonDeal, false);
    showButton(gameWindow.buttonReset, false);

    connect(gameWindow.buttonPlayAgain, SIGNAL(released()), this, SLOT(playAgain()));
    connect(gameWindow.buttonHit, SIGNAL(released()), this, SLOT(hit()));
    connect(gameWindow.buttonStand, SIGNAL(released()), this, SLOT(stand()));
    connect(gameWindow.buttonDeal, SIGNAL(released()), this, SLOT(deal()));
    connect(gameWindow.buttonReset, SIGNAL(released()), this, SLOT(reset()));

    connect(gameWindow.buttonChip1, SIGNAL(released()), this, SLOT(pushButtonChip1()));
    connect(gameWindow.buttonChip2, SIGNAL(released()), this, SLOT(pushButtonChip2()));
    connect(gameWindow.buttonChip5, SIGNAL(released()), this, SLOT(pushButtonChip5()));
    connect(gameWindow.buttonChip10, SIGNAL(released()), this, SLOT(pushButtonChip10()));
    connect(gameWindow.buttonChip25, SIGNAL(released()), this, SLOT(pushButtonChip25()));
}

void PlayerInterface::setPlayer(const std::shared_ptr<Player> player)
{
    this->player = player;
    changeTextLabelCash();
}

void PlayerInterface::setGame(Game* game)
{
    this->game = game;
}

void PlayerInterface::playAgain()
{
}

void PlayerInterface::hit()
{
    //player->hit();
}

void PlayerInterface::stand()
{
}

void PlayerInterface::deal()
{
    showButton(gameWindow.buttonDeal, false);
    showButton(gameWindow.buttonReset, false);

    game->cardsDistribution(2);
}

void PlayerInterface::reset()
{
    player->resetBet();
    changeTextLabelBet();
    showButton(gameWindow.buttonDeal, false);
    showButton(gameWindow.buttonReset, false);
}

void PlayerInterface::pushButtonChip1()
{
    if(!checkLimit(1)) return;

    player->increaseBet(1);
    changeTextLabelBet();
    showButton(gameWindow.buttonDeal, true);
    showButton(gameWindow.buttonReset, true);
}

void PlayerInterface::pushButtonChip2()
{
    if (!checkLimit(2)) return;

    player->increaseBet(2);
    changeTextLabelBet();
    showButton(gameWindow.buttonDeal, true);
    showButton(gameWindow.buttonReset, true);
}

void PlayerInterface::pushButtonChip5()
{
    if (!checkLimit(5)) return;

    player->increaseBet(5);
    changeTextLabelBet();
    showButton(gameWindow.buttonDeal, true);
    showButton(gameWindow.buttonReset, true);
}

void PlayerInterface::pushButtonChip10()
{
    if (!checkLimit(10)) return;

    player->increaseBet(10);
    changeTextLabelBet();
    showButton(gameWindow.buttonDeal, true);
    showButton(gameWindow.buttonReset, true);
}

void PlayerInterface::pushButtonChip25()
{
    if (!checkLimit(25)) return;

    player->increaseBet(25);
    changeTextLabelBet();
    showButton(gameWindow.buttonDeal, true);
    showButton(gameWindow.buttonReset, true);
}

void PlayerInterface::changeTextLabelBet()
{
    int bet = player->getBet();
    gameWindow.labelBet->setText(std::format("Bet: {}", bet).c_str());
}

void PlayerInterface::changeTextLabelCash()
{
    gameWindow.labelBalance->setText(std::format("Cash: {}", player->getCash()).c_str());
}

void PlayerInterface::showButton(QPushButton* button, bool bShow)
{
    return bShow ? button->show() : button->hide();
}

bool PlayerInterface::checkLimit(const int additionalBet) const
{
    return player->getBet() + additionalBet <= player->getCash();
}

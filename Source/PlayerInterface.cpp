#include "PlayerInterface.h"
#include <QRect>
#include <QTimer>

PlayerInterface::PlayerInterface(QWidget* parent) : QMainWindow(parent)
{
	gameWindow.setupUi(this);
    setting = std::make_shared<Setting>();
    this->show();

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

    connect(gameWindow.buttonSetting, SIGNAL(released()), this, SLOT(pushButtonSetting()));

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

void PlayerInterface::displayCard(const std::shared_ptr<Card> card, const int delay)
{
    labelCard = createLabelCard(card);
    labelCard->isVisible();
    labelCard->show();

    endPoint = card->getIsPlayer() ? card->getEndPointPlayer() : card->getEndPointDealer();
    addAnimation(labelCard, QRect(endPoint.x(), endPoint.y(), Card::getWidth(), Card::getHeight()));

    cardsOnTheScreen.insert({ card, labelCard });

    if(player->isStand()) 
        game->cardsDistribution(1);
}

void PlayerInterface::finishMove(const bool bWin)
{
    if (bWin)
    {
        changeTextLabel("You Win !!!");
        player->getMoneyFromBet();
    }
    else
    {
        changeTextLabel("You Lose !!!");
    }

    showAllCards();
    showButton(gameWindow.buttonPlayAgain, true);
    Card::resetEndPoints();
}

void PlayerInterface::changeCardsInteface()
{
    std::map<std::shared_ptr<Card>, std::shared_ptr<QLabel>>::iterator it;
    for (it = cardsOnTheScreen.begin(); it != cardsOnTheScreen.end(); it++)
    {
        std::shared_ptr<Card> card = it->first;
        std::shared_ptr<QLabel> label = it->second;
        
        QString path = card->getIsHide() ? card->getPathBackSide() : card->getPath();

        QPixmap pixmap(path);
        pixmap = pixmap.scaled(labelCard->size(), Qt::KeepAspectRatio);
        label->setPixmap(pixmap);

        label->setStyleSheet(path);
    }
}

std::shared_ptr<QLabel> PlayerInterface::createLabelCard(const std::shared_ptr<Card> card)
{
    std::shared_ptr<QLabel> labelCard = std::make_shared<QLabel>(this);

    labelCard->setGeometry(this->width() / 2, -100, Card::getWidth(), Card::getHeight());
    
    QString path = card->getIsHide() ? card->getPathBackSide() : card->getPath();
    
    QPixmap pixmap(path);
    pixmap = pixmap.scaled(labelCard->size(), Qt::KeepAspectRatio);
    labelCard->setPixmap(pixmap);

    return labelCard;
}

void PlayerInterface::addAnimation(const std::shared_ptr<QLabel> label, const QRect& endVale)
{
    animation = new QPropertyAnimation(label.get(), "geometry");
    animation->setDuration(400);
    animation->setStartValue(label->geometry());
    animation->setEndValue(endVale);
    animation->start();
}

void PlayerInterface::playAgain()
{
    showButton(gameWindow.buttonPlayAgain, false);

    showButton(gameWindow.buttonDeal, true);
    showButton(gameWindow.buttonReset, true);

    showButton(gameWindow.buttonChip1, true);
    showButton(gameWindow.buttonChip2, true);
    showButton(gameWindow.buttonChip5, true);
    showButton(gameWindow.buttonChip10, true);
    showButton(gameWindow.buttonChip25, true);

    clearTheCardTable();
    changeTextLabelCash();
    changeTextLabelBet();
    changeTextLabel("Place Your Bets...");
}

void PlayerInterface::hit()
{
    game->cardsDistribution(1);
}

void PlayerInterface::stand()
{
    showButton(gameWindow.buttonHit, false);
    showButton(gameWindow.buttonStand, false);

    player->setStand(true);

    game->cardsDistribution(1);
}

void PlayerInterface::deal()
{
    if (player->getBet() == 0) return;

    showButton(gameWindow.buttonDeal, false);
    showButton(gameWindow.buttonReset, false);

    showButton(gameWindow.buttonHit, true);
    showButton(gameWindow.buttonStand, true);

    showButton(gameWindow.buttonChip1, false);
    showButton(gameWindow.buttonChip2, false);
    showButton(gameWindow.buttonChip5, false);
    showButton(gameWindow.buttonChip10, false);
    showButton(gameWindow.buttonChip25, false);

    player->placeBet();
    changeTextLabelCash();
    changeTextLabelBet();
    changeTextLabel("");

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

void PlayerInterface::pushButtonSetting()
{
    setting->setPlayerInterface(this);
    setting->show();
}

void PlayerInterface::changeTextLabelBet()
{
    int bet = player->getBet();
    gameWindow.labelBet->setText(QString("Bet: %1").arg(bet));
}

void PlayerInterface::changeTextLabelCash()
{
    gameWindow.labelBalance->setText(QString("Cash: %1").arg(player->getCash()));
}

void PlayerInterface::changeTextLabel(const QString text = "")
{
    gameWindow.labelText->setText(text);
}

void PlayerInterface::showAllCards()
{
    std::map<std::shared_ptr<Card>, std::shared_ptr<QLabel>>::iterator it;
    for (it = cardsOnTheScreen.begin(); it != cardsOnTheScreen.end(); it++)
    {
        std::shared_ptr<Card> card = it->first;
        std::shared_ptr<QLabel> label = it->second;
        card->setShow();

        QPixmap pixmap(card->getPath());
        pixmap = pixmap.scaled(labelCard->size(), Qt::KeepAspectRatio);
        label->setPixmap(pixmap);
    }
}

void PlayerInterface::clearTheCardTable()
{
    std::map<std::shared_ptr<Card>, std::shared_ptr<QLabel>>::iterator it;
    for (it = cardsOnTheScreen.begin(); it != cardsOnTheScreen.end(); it++)
    {
        std::shared_ptr<QLabel> label = it->second;
        label->hide();
    }
    cardsOnTheScreen.clear();
}

void PlayerInterface::showButton(QPushButton* button, bool bShow)
{
    return bShow ? button->show() : button->hide();
}

bool PlayerInterface::checkLimit(const int additionalBet) const
{
    return player->getBet() + additionalBet <= player->getCash();
}

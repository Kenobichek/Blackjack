#pragma once
#include <QMainWindow>
#include <QPropertyAnimation>
#include <QVBoxLayout>
#include <memory>
#include <map>

#include "ui_playerinterface.h"
#include "Player.h"
#include "Card.h"
#include "Audio.h"

class PlayerInterface;

#include "Game.h"
#include "Setting.h"

class PlayerInterface : public QMainWindow {
	Q_OBJECT

public:
	PlayerInterface(QWidget* parent = Q_NULLPTR);
	void setPlayer(const std::shared_ptr<Player> player);
	void setGame(Game* game);
	void displayCard(const std::shared_ptr<Card> card, const int delay = 0);
	void finishMove(const bool bWin);
	void changeCardsInteface();

public slots:
	void playAgain();
	void hit();
	void stand();
	void deal();
	void reset();
	void pushButtonChip1();
	void pushButtonChip2();
	void pushButtonChip5();
	void pushButtonChip10();
	void pushButtonChip25();
	void pushButtonSetting();

private:
	void showButton(QPushButton* button, bool bShow);
	bool checkLimit(const int additionalBet) const;
	bool checkExcess21() const;
	bool checkGameOver() const;
	void addAnimation(const std::shared_ptr<QLabel>, const QRect& endVale);
	void changeTextLabelBet();
	void changeTextLabelCash();
	void changeTextLabel(const QString);
	void showAllCards();
	void clearTheCardTable();
	std::shared_ptr<QLabel> createLabelCard(const std::shared_ptr<Card> card);

	QPoint endPoint;
	std::shared_ptr<Player> player;		
	std::shared_ptr<Setting> setting;
	std::shared_ptr<Audio> audio;
	std::shared_ptr<QLabel> labelCard;
	std::map<std::shared_ptr<Card>, std::shared_ptr<QLabel>> cardsOnTheScreen;

	QLabel* card;
	QPropertyAnimation* animation;
	Game* game;
	Ui::MainWindow gameWindow;
};
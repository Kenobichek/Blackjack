#pragma once
#include <QMainWindow>
#include <QPropertyAnimation>
#include <memory>

#include "ui_playerinterface.h"
#include "Deck.h"
#include "Player.h"

class PlayerInterface;

#include "Game.h"

class PlayerInterface : public QMainWindow {
	Q_OBJECT

public:
	PlayerInterface(QWidget* parent = Q_NULLPTR);
	void setPlayer(const std::shared_ptr<Player> player);
	void setGame(Game* game);

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
	void changeTextLabelBet();
	void changeTextLabelCash();

	void showButton(QPushButton* button, bool bShow);
	bool checkLimit(const int additionalBet) const;

private:
	std::shared_ptr<Player> player;	
	Game* game;

	//QLabel* card = new QLabel(this);
	//QPropertyAnimation* animation;

	Ui::MainWindow gameWindow;
};
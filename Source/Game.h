#pragma once
#include <QMainWindow>
#include <QPropertyAnimation>
#include <memory>

#include "ui_game.h"
#include "Deck.h"

class Game : public QMainWindow {
	Q_OBJECT

public:
	Game(QWidget* parent = Q_NULLPTR);

public slots:
	//void playAgain();
	//void hit();
	//void stand();

private:
	std::shared_ptr<Deck> deck;

	QLabel* card = new QLabel(this);
	QPropertyAnimation* animation;

	Ui::MainWindow gameWindow;
};
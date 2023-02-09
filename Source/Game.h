#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_game.h"

class Game : public QMainWindow {
	Q_OBJECT

public:
	Game(QWidget* parent = Q_NULLPTR);

private:
	Ui::MainWindow gameWindow;

};
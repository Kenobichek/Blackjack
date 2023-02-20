#pragma once

#include <QMainWindow>
#include "ui_setting.h"

class Setting;

#include "PlayerInterface.h"

class Setting : public QMainWindow {
	Q_OBJECT

public:
	Setting(QWidget* parent = Q_NULLPTR);
	void setPlayerInterface(PlayerInterface*);

public slots:
	void pushComboBoxBackSide(int index);
	void pushComboBoxFrontSide(int index);

private:
	PlayerInterface* playerInterface;
	Ui::SettingWindow settingWindow;
};
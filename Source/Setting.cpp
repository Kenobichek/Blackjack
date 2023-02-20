#include "Setting.h"
#include "Card.h"

Setting::Setting(QWidget* parent) : QMainWindow(parent)
{
	settingWindow.setupUi(this);

	connect(settingWindow.comboBoxBackSide, QOverload<int>::of(&QComboBox::activated), this, &Setting::pushComboBoxBackSide);
	connect(settingWindow.comboBoxFrontSide, QOverload<int>::of(&QComboBox::activated), this, &Setting::pushComboBoxFrontSide);
}

void Setting::setPlayerInterface(PlayerInterface* playerInterface)
{
	this->playerInterface = playerInterface;
}

void Setting::pushComboBoxBackSide(int index)
{
	Card::setBackSideCategory(settingWindow.comboBoxBackSide->itemText(index));
	playerInterface->changeCardsInteface();
}

void Setting::pushComboBoxFrontSide(int index)
{
	Card::setFrontSideCategory(settingWindow.comboBoxFrontSide->itemText(index));
	playerInterface->changeCardsInteface();
}

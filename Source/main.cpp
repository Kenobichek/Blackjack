#include <QtWidgets/QApplication>

#include "Game.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    std::shared_ptr<Game> game = std::make_shared<Game>();
    return a.exec();
}
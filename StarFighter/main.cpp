#include <QApplication>
#include "cgame.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    CGame* game = new CGame();
    game->show();

    return a.exec();
}


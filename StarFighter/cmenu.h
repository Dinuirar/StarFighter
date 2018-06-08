#ifndef CMENU_H
#define CMENU_H

#include "common.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

// Player 1:
// arrow keys - movement, 0 - shot
// Player 2:
// WASD - movement, spacebar - shot
// ESC - exit game

class CMenu : public QGraphicsScene {
private:
    CSettings Fsettings;
    QGraphicsPixmapItem* coordinates;
public:
    CMenu();
    CMenu(CSettings&);
};

#endif // CMENU_H

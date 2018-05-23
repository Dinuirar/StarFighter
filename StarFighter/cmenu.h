#ifndef CMENU_H
#define CMENU_H

#include "common.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

class CMenu : public QGraphicsScene {
private:
    CSettings Fsettings;
    QGraphicsPixmapItem* coordinates;
public:
    CMenu();
    CMenu(CSettings&);
};

#endif // CMENU_H

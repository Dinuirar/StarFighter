#ifndef CGAME_H
#define CGAME_H

#include "common.h"
#include "cship.h"
#include "cmenu.h"
#include "cspace.h"
#include "casteroid.h"
#include "ggraphics.h"
#include <QGraphicsView>
#include <QKeyEvent>

class CGame : public QGraphicsView {
private:
    CMenu* menu;
    CSpace* space;
    CSettings settings;
    CShip* player;
    CShip* enemy;
public:
    CGame();
    void keyPressEvent(QKeyEvent*);
};

#endif // CGAME_H

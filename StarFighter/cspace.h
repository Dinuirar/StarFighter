#ifndef CSPACE_H
#define CSPACE_H

#include "ggraphics.h"
#include "cobject.h"
#include "common.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <deque>
//#include <QKeyEvent>

class CSpace : public QGraphicsScene {
//    Q_OBJECT
public:
    CSpace();
    std::deque<CObject*> FListObj;
    std::deque<GGraphics*> FListGraphics;
//    void keyPressEvent( QKeyEvent* );
};

#endif // CSPACE_H

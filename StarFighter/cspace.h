#ifndef CSPACE_H
#define CSPACE_H

#include "ggraphics.h"
#include "cobject.h"
#include "common.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <deque>
//#include <QKeyEvent>

class CObject;
class GGraphics;

class CSpace : public QGraphicsScene {
//    Q_OBJECT
public:
    CSpace();
    std::deque<CObject*> getObjInRange(CObject*, qreal);
    void addObject( CObject*, GGraphics* );
    void produceBullet();
public slots:
    void updateObjs();
private:
    std::deque<CObject*> FListObj;
    std::deque<GGraphics*> FListGraphics;
};

#endif // CSPACE_H

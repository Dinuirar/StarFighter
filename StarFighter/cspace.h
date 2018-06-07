#ifndef CSPACE_H
#define CSPACE_H

#include "ggraphics.h"
#include "cship.h"
#include "cobject.h"
#include "common.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <deque>

class CSpace : public QGraphicsScene {
public:
    CSpace();
    std::deque<CObject*> getObjInRange(CObject*, qreal);
    void addObject( CObject*, GGraphics* );
    void removeObject( u_int index );
public slots:
    void updateObjs();
private:
    CShip* player, * enemy;
    QString playerHP, enemyHP;
    QGraphicsSimpleTextItem* hp_indicator, * enemy_hp_indicator;
    std::deque<CObject*> FListObj;
    std::deque<GGraphics*> FListGraphics;
};

#endif // CSPACE_H

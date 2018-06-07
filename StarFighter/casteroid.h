#ifndef CASTEROID_H
#define CASTEROID_H

#include "common.h"
#include "cobject.h"
#include "cspace.h"

class CAsteroid : public CObject {
public:
    CAsteroid();
    CAsteroid(int ID,
              qreal X, qreal Y, qreal ANGLE,
              qreal LINEAR_SPEEDX = 0, qreal LINEAR_SPEEDY = 0, qreal ANGULAR_SPEED = 0,
              int HP = 100);
    CAsteroid(qreal SIZE, CSpace * SPACE,
              qreal X, qreal Y, qreal ANGLE,
              qreal LINEAR_SPEEDX = 0, qreal LINEAR_SPEEDY = 0, qreal ANGULAR_SPEED = 0,
              int HP = 100);
    ~CAsteroid() {}
    void setModel(QString arg);
    bool takeAHit(int dmg);
    void update();
    void move();
protected:
    int id;
};

#endif // CASTEROID_H

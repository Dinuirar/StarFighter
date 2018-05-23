#ifndef CASTEROID_H
#define CASTEROID_H

#include "common.h"
#include "cobject.h"

class CAsteroid : public CObject {
public:
    CAsteroid();
    CAsteroid(int ID,
              qreal X, qreal Y, qreal ANGLE,
              qreal LINEAR_SPEEDX = 0, qreal LINEAR_SPEEDY = 0, qreal ANGULAR_SPEED = 0,
              int HP = 100);
    void setModel(QString arg);
    bool takeAHit(int dmg);
    void update();
    void move();
protected:
    int hp, id;
};

#endif // CASTEROID_H

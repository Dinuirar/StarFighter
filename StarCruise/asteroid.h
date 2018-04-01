#ifndef ASTEROID_H
#define ASTEROID_H

#include "common.h"
#include "cinertion.h"

#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class CAsteroid : public CInertion {
public:
    CAsteroid();
    CAsteroid(QString MODEL, int ID,
             qreal X, qreal Y, qreal ANGLE,
             qreal LINEAR_SPEED = 0, qreal ANGULAR_SPEED = 0,
             int HP = 100);
    void setModel(QString arg);
    virtual bool takeAHit(int dmg);
protected:
    int hp, id;
    QString modelName;
};

class SmallAsteroid : public CAsteroid {
public:
    SmallAsteroid();
    bool takeAHit(int);
};

class MediumAsteroid : CAsteroid {
public:
    MediumAsteroid();
    bool takeAHit(int);
};

class BigAsteroid : CAsteroid {
public:
    BigAsteroid();
    bool takeAHit(int);
};

#endif // ASTEROID_H

#ifndef ASTEROID_H
#define ASTEROID_H

#include "common.h"
#include "cinertion.h"

#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Asteroid : public CInertion {
public:
    Asteroid();
    explicit Asteroid(QString arg, int X, int Y);
    Asteroid(QString MODEL, int ID,
             qreal X, qreal Y, qreal ANGLE,
             qreal LINEAR_SPEED = 0, qreal ANGULAR_SPEED = 0,
             int HP = 100);
    void setModel(QString arg);
    virtual bool takeAHit(int dmg);
protected:
    int hp, id;
    QString modelName;
};

class SmallAsteroid : public Asteroid {
public:
    SmallAsteroid();
    bool takeAHit(int);
};

class MediumAsteroid : Asteroid {
public:
    MediumAsteroid();
    bool takeAHit(int);
};

class BigAsteroid : Asteroid {
public:
    BigAsteroid();
    bool takeAHit(int);
};

#endif // ASTEROID_H

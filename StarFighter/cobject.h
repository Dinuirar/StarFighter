#ifndef COBJECT_H_
#define COBJECT_H_

#include "common.h"
#include <QPointF>

class CSpace;

class CObject {
public:
    CObject();
    CObject(qreal X, qreal Y, qreal ANGLE,
            qreal LINEAR_SPEEDX = 0, qreal LINEAR_SPEEDY = 0,
            qreal ANGULAR_SPEED = 0);
    virtual void move() = 0;
    qreal calcDistance(CObject* );
    void setAngularSpeed(qreal _v);
    void setPosition(QPointF _p);
    void setAngle(qreal _a);
    void setLinearSpeed(QPointF _l);
    qreal getAngularSpeed();
    QPointF getLinearSpeed();
    QPointF getPosition();
    qreal getAngle();
    void setSpace(CSpace* _s);
    CSpace* getSpace();
    int getLifetime();
    void removeObject();
    bool isToDestroy();
    void unremoveObject();
    void reduceHP(int dmg);
    int getHP();
    void update();
protected:
    void setHP( int hp );
    bool destroy;
    QString modelName;
    int cnt_lifetime;
    qreal angular_speed;
    QPointF position;
    qreal angle;
    QPointF linear_speed;
private:
    u_int hitpoints;
    CSpace* FSpace;
};

#endif // COBJECT_H

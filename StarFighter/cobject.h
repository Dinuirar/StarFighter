#ifndef COBJECT_H_
#define COBJECT_H_

#include "common.h"
#include <QPointF>
#include <deque>

class CSpace;

class CObject {
public:
    CObject();
    CObject(qreal X, qreal Y, qreal ANGLE,
            qreal LINEAR_SPEEDX = 0, qreal LINEAR_SPEEDY = 0,
            qreal ANGULAR_SPEED = 0);
    virtual ~CObject();
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
    int getSize() { return size; }
    void update();
protected:
    void setHP( int hp );
    void setSize( qreal _s ) {size = _s; }
    virtual void collide( CObject* ) = 0;
    QString modelName;
    int cnt_lifetime;
    qreal angular_speed;
    QPointF linear_speed;
private:
    bool colliding;
    qreal size;
    bool destroy;
    int hitpoints;
    QPointF position;
    qreal angle;
    CSpace* FSpace;
    std::deque<CObject*> objs;
};

#endif // COBJECT_H

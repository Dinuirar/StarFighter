#ifndef COBJECT_H
#define COBJECT_H

#include "common.h"
#include "cspace.h"
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
    void setAngularSpeed(qreal _v) { angular_speed = _v; }
    void setPosition(QPointF _p) { position = _p; }
    void setAngle(qreal _a) { angle = _a; }
    void setLinearSpeed(QPointF _l) { linear_speed = _l; }
    qreal getAngularSpeed() { return angular_speed; }
    QPointF getLinearSpeed() { return linear_speed; }
    QPointF getPosition() { return position; }
    qreal getAngle() { return angle; }
    CSpace* getSpace() { return FSpace; }
    void update();
protected:
    QString modelName;
    int cnt_lifetime;
    qreal angular_speed;
    QPointF position;
    qreal angle;
    QPointF linear_speed;
private:
    CSpace* FSpace;
};

#endif // COBJECT_H

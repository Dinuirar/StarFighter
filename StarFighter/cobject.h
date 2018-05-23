#ifndef COBJECT_H
#define COBJECT_H

#include "common.h"
#include <QPointF>

class CObject {
public:
    CObject();
    CObject(qreal X, qreal Y, qreal ANGLE,
            qreal LINEAR_SPEEDX = 0, qreal LINEAR_SPEEDY = 0, qreal ANGULAR_SPEED = 0);
    virtual void move() = 0;

    QPointF position;
    qreal angle;
    QPointF linear_speed;
    qreal angular_speed;
protected:
    QString modelName;
    int cnt_lifetime;
};

#endif // COBJECT_H

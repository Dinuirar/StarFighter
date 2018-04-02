#ifndef CINERTION_H
#define CINERTION_H

#include "common.h"
#include <QPointF>
#include <QTimer>
#include <QObject>
#include <QGraphicsPixmapItem>

class CInertion : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    CInertion();
    CInertion(qreal X, qreal Y, qreal ANGLE,
              qreal LINEAR_SPEED = 0, qreal ANGULAR_SPEED = 0);
    void changeLinearSpeed(qreal value);
    void changeLinearSpeed(QPointF DELTA_LINEAR_SPEED);
    void changeAngularSpeed(qreal value);
public slots:
    virtual void update();
protected:
    QPointF position;
    qreal angle;
    QPointF linear_speed2;
    qreal linear_speed,
          angular_speed;
    int inertionCounter;
};

#endif // CINERTION_H

#ifndef CINERTION_H
#define CINERTION_H

#include <QPointF>
#include <QTimer>
#include <QObject>
#include <QGraphicsPixmapItem>

class CInertion : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    CInertion();
    CInertion(qreal X, qreal Y, qreal ANGLE,
              qreal LINEAR_SPEED, qreal ANGULAR_SPEED);
    void changeLinearSpeed(qreal value);
    void changeAngularSpeed(qreal value);
    void timerEvent(QTimerEvent *);
public slots:
    void update();
protected:
    QPointF position;
    qreal angle;
    qreal linear_speed,
          angular_speed;
};

#endif // CINERTION_H

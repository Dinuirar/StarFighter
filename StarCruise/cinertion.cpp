#include "cinertion.h"
#include <cmath>
#include <iostream>

CInertion::CInertion() { }

void CInertion::update() {
    qreal step = linear_speed * dt;
    qreal dx = step * std::cos( 3.14/2 - angle * 0.01744 );
    qreal dy = step * std::sin( 3.14/2 - angle * 0.01744 );
    position.rx() -= dx;
    position.ry() += dy;
    setPos(position.x(), position.y());
    qreal radstep = angular_speed * dt;
    angle += radstep;
    setRotation(angle);
}

CInertion::CInertion(qreal X, qreal Y, qreal ANGLE, qreal LINEAR_SPEED, qreal ANGULAR_SPEED)
    : position(QPoint(X, Y)), angle(ANGLE), linear_speed(LINEAR_SPEED), angular_speed(ANGULAR_SPEED)
{
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT( update() ));
    timer->start(dt);
}

void CInertion::changeAngularSpeed(qreal value) {
    angular_speed += value;
    if (angular_speed < -0.1)
        angular_speed = -0.1;
    if (angular_speed > 0.1)
        angular_speed = 0.1;
}

void CInertion::changeLinearSpeed(qreal value) {
    linear_speed -= value;
    if (linear_speed < -0.2)
        linear_speed = -0.2;
    if (linear_speed > 0.1)
        linear_speed = 0.1;
}

void CInertion::changeLinearSpeed(QPointF DELTA_LINEAR_SPEED) {
    linear_speed2.rx() += DELTA_LINEAR_SPEED.x();
    linear_speed2.ry() -= DELTA_LINEAR_SPEED.y();
}

//void CInertion::update() {
//    qreal step = linear_speed;
//    qreal radstep = angular_speed;
//    qreal dx = step * std::cos( 3.14/2 - angle * 0.01744 );
//    qreal dy = step * std::sin( 3.14/2 - angle * 0.01744 );
//    position.rx() -= dx;
//    position.ry() += dy;
//    angle += radstep;
//    setPos(position.x(), position.y());
//    setRotation(angle);
//}
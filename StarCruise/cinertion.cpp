#include "cinertion.h"
#include <cmath>
#include <iostream>

CInertion::CInertion() {
}

void CInertion::update() {
    std::cout << "update\n";
    qreal step = linear_speed;
    qreal radstep = angular_speed;
    qreal dx = step * std::cos( 3.14/2 - angle * 0.01744 );
    qreal dy = step * std::sin( 3.14/2 - angle * 0.01744 );
    position.rx() += dx;
    position.ry() += dy;
    angle += radstep;
    setPos(position.x(), position.y());
    setRotation(angle);
}

CInertion::CInertion(qreal X, qreal Y, qreal ANGLE, qreal LINEAR_SPEED, qreal ANGULAR_SPEED)
    : position(QPoint(X, Y)), angle(ANGLE), linear_speed(LINEAR_SPEED), angular_speed(ANGULAR_SPEED) {
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT( update() ));
    timer->start(10);
}

void CInertion::timerEvent(QTimerEvent *) { }

void CInertion::changeAngularSpeed(qreal value) {
    angular_speed += value;
}

void CInertion::changeLinearSpeed(qreal value) {
    linear_speed -= value;
}

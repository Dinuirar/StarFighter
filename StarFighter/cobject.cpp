#include "cobject.h"

CObject::CObject() {
}

CObject::CObject(qreal X, qreal Y, qreal ANGLE,
                 qreal LINEAR_SPEEDX, qreal LINEAR_SPEEDY, qreal ANGULAR_SPEED)
    : position( QPoint(X, Y) ), angle(ANGLE),
      linear_speed( QPointF(LINEAR_SPEEDX, LINEAR_SPEEDY) ),
      angular_speed(ANGULAR_SPEED),
      cnt_lifetime(0) {
    FSpace = NULL;
}

qreal CObject::calcDistance(CObject * _obj) {
    QPointF tmp = this->getPosition() - _obj->getPosition();
    return sqrt( tmp.x() * tmp.x() + tmp.y() * tmp.y() );
}

void CObject::update() {
    if ( position.x() < 0 ) {
        position.rx() = WINDOW_WIDTH;
    }
    else if ( position.x() > WINDOW_WIDTH ) {
        position.rx() = 0;
    }
    if ( position.y() < 0 ) {
        position.ry() = WINDOW_HEIGHT;
    }
    else if ( position.y() > WINDOW_HEIGHT ) {
        position.ry() = 0;
    }
    position.rx() += dt * linear_speed.x();
    position.ry() += dt * linear_speed.y();
    angle += dt * angular_speed;
    cnt_lifetime++;
}

// TODO: error control
//void setAngularSpeed(qreal _v) {
//    angular_speed = _v;
//}

//void setPosition(QPointF _p) {
//    position = _p;
//}

//void setAngle(qreal _a) {
//    angle = _a;
//}

//void setLinearSpeed(QPointF _l) {
//    linear_speed = _l;
//}

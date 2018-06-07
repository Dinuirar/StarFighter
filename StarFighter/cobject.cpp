#include "cobject.h"
#include "cspace.h"
#include "cbullet.h"

CObject::CObject() {
}

CObject::CObject(qreal X, qreal Y, qreal ANGLE,
                 qreal LINEAR_SPEEDX, qreal LINEAR_SPEEDY, qreal ANGULAR_SPEED)
    : position( QPoint(X, Y) ), angle(ANGLE),
      linear_speed( QPointF(LINEAR_SPEEDX, LINEAR_SPEEDY) ),
      angular_speed(ANGULAR_SPEED),
      cnt_lifetime(0) {
    hitpoints = 30;
    FSpace = NULL;
    destroy = false;
    size = 10;
}

CObject::~CObject() {
}

qreal CObject::calcDistance(CObject * _obj) {
    QPointF tmp = this->getPosition() - _obj->getPosition();
    return sqrt( tmp.x() * tmp.x() + tmp.y() * tmp.y() );
}

void CObject::update() {
    if ( this->getHP() <= 0 ) {
        this->removeObject();
    }
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

    objs = getSpace()->getObjInRange(this, size);
    if ( objs.size() == 1 || dynamic_cast<CBullet*>(this) ) {
        position.rx() += dt * linear_speed.x();
        position.ry() += dt * linear_speed.y();
        angle += dt * angular_speed;
    }
    else { // collision?
//        this->linear_speed = -linear_speed;
        return;
//        for ( u_int i = 0; i < objs.size(); i++ ) {
//            if( this != objs[i] ) {
////                this->reduceHP(1);
////                objs[i]->reduceHP(1);
//                this->linear_speed = -linear_speed;
//                return;
//            }
//        }
    }

    cnt_lifetime++;
}

void CObject::setAngularSpeed(qreal _v) {
    angular_speed = _v;
}

void CObject::setPosition(QPointF _p) {
    position = _p;
}

void CObject::setAngle(qreal _a) {
    angle = _a;
}

void CObject::setLinearSpeed(QPointF _l) {
    linear_speed = _l;
}

qreal CObject::getAngularSpeed() {
    return angular_speed;
}

QPointF CObject::getLinearSpeed() {
    return linear_speed;
}

QPointF CObject::getPosition() {
    return position;
}

qreal CObject::getAngle() {
    return angle;
}

void CObject::setSpace(CSpace* _s) {
    FSpace = _s;
}

CSpace* CObject::getSpace() {
    return FSpace;
}

int CObject::getLifetime() {
    return cnt_lifetime;
}

void CObject::removeObject() {
    destroy = true;
}

bool CObject::isToDestroy() {
    return destroy;
}

void CObject::unremoveObject() {
    destroy = false;
}

void CObject::reduceHP( int dmg ) {
    hitpoints -= dmg;
}

int CObject::getHP() {
    return hitpoints;
}

void CObject::setHP( int hp) {
    hitpoints = hp;
}
